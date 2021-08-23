#include "cdf.h"

void cdf(bool data_vld_i, ap_uint<16> airtime_i, bool *cumsum_vld_o, dtype_o *cumsum_o)
{
	static ap_uint<16> index;

	static ap_uint<16> histarraylocal[NUM_BIN] = {0}; //we might need larger value because of dma transfer size
	static dtype_o prev_val = 0;

	static int counter_i = 0; //counter when to compare two histograms
	static int counter_o = 0;

	if (data_vld_i == 1)
	{
		counter_i++;
		HIST_LOOP: for (index = 0; index < NUM_BIN; index++)
		{
			if ((index * 200 <= airtime_i)
					&& (airtime_i < (index + 1) * 200))
			{
				histarraylocal[index]++;//divide by 8192 to get between 0 and 1 multiple by //164//410
			}
		}
		*cumsum_vld_o = 0;
		*cumsum_o = 0;
	}
	else
	{
		if (counter_o == NUM_BIN)
		{
			counter_i = 0;
			counter_o = 0;
			*cumsum_vld_o = 0;
			*cumsum_o = 0;
		}
		else if (counter_i == SAMPLE)
		{
			// Output data and reset hist array
			*cumsum_o = ((dtype_o) histarraylocal[counter_o] >> 13) + prev_val;
			*cumsum_vld_o = 1;

			prev_val = *cumsum_o;
			histarraylocal[counter_o] = 0;
			counter_o++;
		}
		else
		{
			// reset everything
			counter_o = 0;
			prev_val = 0;
			*cumsum_vld_o = 0;
			*cumsum_o = 0;
		}
	}
}
