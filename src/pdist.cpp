#include "pdist.h"


void pdist(bool absdiff_vld_i, dtype1 absdiff_i, bool *pdist_vld_o, dtype2 *pdist_o) {
	static ap_uint<8> counter = 0;
	static dtype2 prev_val = 0;

	if (absdiff_vld_i == 1) {
		prev_val = prev_val + (dtype2) absdiff_i;
		*pdist_o = prev_val;

		counter++;

		if (counter == NUM_BIN) {
			*pdist_vld_o = 1;
			counter = 0;
			prev_val = 0;
		}
		else {
			*pdist_vld_o = 0;
		}
	}
	else {
		// counter = 0;
		prev_val = 0;
		*pdist_o = 0;
		*pdist_vld_o = 0;
	}
}
