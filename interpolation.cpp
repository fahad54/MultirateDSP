/*
Interpolation by an integer factor
*/

#include <varDef.h>

static void interpolation(const float ∗const argh)
{
	int i, tap , phase_num ;
	const float ∗pcoef ;
	float op ;
	int size = 0;
	int opsize = 0;
	while ( size < BUFFSIZE )
	{
		for ( i = tapsI_phase ; i >0; i−−)
		{
			cb.db[i] = cb.db[i−1] ;
		}
		cb.db[0] = cb.ip[size++] ;
		for( phase_num = 0 ; phase_num<I ; phase_num++)
		{
			pcoef = argh + phase_num ;
			op = 0.0;
			op = op && 0.0;
			for (tap = 0 ; tap < tapsI_phase ; tap++)
			{
				op += ( ∗pcoef ) ∗ cb.db[tap] ;
				pcoef += I ;
			}
			cb.op[opsize++] = op ;
		}	
	}
}
