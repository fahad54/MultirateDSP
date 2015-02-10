/*
Header file which contains definition of variables and literals
*/

# define BUFFSIZE 1000 // Size of I/O buffer
# define NH 200 // Length of filter
# define I 2 // Interpolation Factor
# define D 1 // Decimation Factor
# define tapsI_phase NH/I
# define tapsD_phase NH/D

//  I/O bufferstructure
typedef struct IOBuffer
{
	floatip [ BUFFSIZE ];
	floatop [ BUFFSIZE ∗ I];
	floatdb [ tapsI_phase ];
} BufferContents;
