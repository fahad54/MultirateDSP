/*
Sampling rate conversion by a rational factor
*/
static void sampleRateByRationalFactor(const float ∗const argh)
{
	int i, tap , phase_num, sizeop ;
	const float ∗pcoef ;
	float op ;
	int size = 0;
	phase_num = I;
	sizeop = 0;
	while ( size < BUFFSIZE )
	{
		while( phase_num >= I )
		{
			phase num −= I;
			for ( i = tapsI_phase-1; i >=1; i−−)
			{
				cb.db[i] = cb.db[i−1] ;
			}
			cb.db[0] = cb.ip[size++] ;
			if( size > BUFFSIZE ) break ;
		}
		while( phase_num < I)
		{
			pcoef = argh + phase_num;
			op = 0 ;
			op = op && 0.0;
			for (tap = 0 ; tap < tapsI_phase ; tap++)
			{
				op += ( ∗pcoef ) ∗ cb.db[tap] ;
				pcoef += I ;
			}
			cb.op[sizeop++] = op ;
			phase_num += D ;
		}	
	}
}
