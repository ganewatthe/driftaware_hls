#include "hist.h"

void hist(bool data_vld_i, ap_uint<16> airtime_i, bool *histarray_vld_o, ap_uint<16> *histarray_o) {
    static ap_uint<16> index;

    static ap_uint<16> histarraylocal[NUM_BIN]={0};
    static int counter_i = 0;
    static int counter_o = 0;

    if (data_vld_i==1) {
    	counter_i++;
    	HIST_LOOP: for(index = 0; index < NUM_BIN; index++) {
    		if ((index*200 <= airtime_i) && (airtime_i < (index+1)*200)) {
				histarraylocal[index]++;
			}
		}
    	// Output is zero when histogram is being generated
    	*histarray_o = 0;
    	*histarray_vld_o = 0;
    }
    else {
		if (counter_o == NUM_BIN) {
			// reset everything
			counter_i = 0;
			counter_o = 0;
	    	*histarray_o = 0;
	    	*histarray_vld_o = 0;
		}
		else if (counter_i == SAMPLE) {
    		*histarray_o = histarraylocal[counter_o];
    		*histarray_vld_o = 1;
    		histarraylocal[counter_o] = 0;

    		counter_o++;
    	}
    	else {
    		counter_o = 0;
	    	*histarray_o = 0;
	    	*histarray_vld_o = 0;
    	}
    }
}
