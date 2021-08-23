#ifndef ABSDIFF_H
#define ABSDIFF_H

#include <ap_int.h>
#include <ap_fixed.h>

#define NUM_BIN 50

typedef ap_ufixed<32, 19, AP_TRN, AP_WRAP> dtype1;
typedef ap_ufixed<32,  1, AP_TRN, AP_WRAP> dtype2;

void absdiff(bool cumsumref_vld_i, dtype1 cumsumref_i, bool cumsumcur_vld_i, dtype2 cumsumcur_i,
		 bool *absdiff_vld_o, dtype2 *absdiff_o);

#endif
