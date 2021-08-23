#ifndef PDIST_H
#define PDIST_H

#include <ap_fixed.h>
#include <ap_int.h>

#define NUM_BIN 50

typedef ap_ufixed<32,  1, AP_TRN, AP_WRAP> dtype1;
typedef ap_ufixed<32,  6, AP_TRN, AP_WRAP> dtype2;

void pdist(bool absdiff_vld_i, dtype1 absdiff_i, bool *pdist_vld_o, dtype2 *pdist_o);

#endif
