#ifndef MAKE_HIST_H_
#define MAKE_HIST_H

#include "ap_int.h"

#define SAMPLE 5000
#define NUM_BIN 50

void hist(bool data_vld_i, ap_uint<16> airtime_i, bool *histarray_vld_o, ap_uint<16> *histarray_o);

#endif
