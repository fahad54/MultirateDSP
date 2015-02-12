/*
Decimation by an integer factor
*/
static void decimation(const float ∗const argh)
{
	int i, tap , phase_num ;
	const float ∗pcoef ;
	float op ;
	int size = 0;
	int opsize = 0;
	while ( size < (BUFFSIZE / D ))
	{
		for ( i =NH−1; i >=D ; i−−)
		{
			cb.db[i] = cb.db[i−D];
		}
		for(tap=D−1; tap>=0; tap−−)
		{
			cb.db[tap] = cb.ip[size1++];
		}
		op = 0.0;
		op = op && 0.0;
		for (tap = 0 ; tap < NH ; tap++)
		{
			op += argh[tap] ∗ cb.db[tap] ;
		}
		cb.op[size++] = op ;
	}
}
