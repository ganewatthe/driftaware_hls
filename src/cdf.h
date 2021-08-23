#ifndef CDF_H
#define CDF_H

#include <ap_int.h>
#include <ap_fixed.h>

#define NUM_BIN  50
#define SAMPLE   8192

typedef ap_ufixed<32, 19, AP_TRN, AP_WRAP> dtype_o;

void cdf(bool data_vld_i, ap_uint<16> airtime_i, bool *cumsum_vld_o, dtype_o *cumsum_o);

#endif
