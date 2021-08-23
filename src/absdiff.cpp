#include "absdiff.h"

void absdiff(bool cumsumref_vld_i, dtype1 cumsumref_i, bool cumsumcur_vld_i, dtype2 cumsumcur_i,
		 bool *absdiff_vld_o, dtype2 *absdiff_o) {
	static ap_uint<8> counter_ref = 0;
	static ap_uint<8> counter_cur = 0;
	static dtype2 cumsumref_local[NUM_BIN] = {0};
	static bool busy = 0;

	if (cumsumref_vld_i == 1 && busy == 0) {
		cumsumref_local[counter_ref] = (dtype2) cumsumref_i;
		counter_ref++;

		*absdiff_o = 0;
		*absdiff_vld_o = 0;
	}
	else if (cumsumcur_vld_i == 1) {
		busy = 1;
		if (cumsumref_local[counter_cur] > cumsumcur_i) {
			*absdiff_o = cumsumref_local[counter_cur] - cumsumcur_i;
			*absdiff_vld_o = 1;
			counter_cur++;
		}
		else {
			*absdiff_o = cumsumcur_i - cumsumref_local[counter_cur];
			*absdiff_vld_o = 1;
			counter_cur++;
		}
	}
	else {
		busy = 0;
		counter_ref = 0;
		counter_cur = 0;

		*absdiff_o = 0;
		*absdiff_vld_o = 0;
	}
}
