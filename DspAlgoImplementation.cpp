/*
The implementation of several DSP algorithms
*/

#include <varDef.h>
using namespace std;

/*
The main() function is executed by DSP processor which calls other functions to perform data I/O and implement a specific DSP algorithm
*/
void main()
{
	int i;
	float h = 41.0;
	for ( i = 0; i <tapsI_phase; i++)
	{
		cb.db [i] = 0.0;
	}
	cout (”Main SRC processing Started ” ) ;
	while(TRUE)
	{
		dataIO();
		interpolation(h);
		decimation(h);
		sampleRateByRationalFactor(h);
	}
}

/*
Interpolation by an integer factor
*/
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

int dataIO() {
  streampos size;
  char * memblock;

  ifstream file ("test.wav", ios::in|ios::binary|ios::ate);
  if (file.is_open())
  {
    size = file.tellg();
    memblock = new char [size];
    file.seekg (0, ios::beg);
    file.read (memblock, size);
    file.close();

    cout << "the entire file content is in memory";

    delete[] memblock;
  }
  else cout << "Unable to open file";
  return 0;
}
