# Prime number scripts

The code in this folder contains different prime number related programs. 
This programs can be used to test how fast a CPU is and to put it under 
stress.

## Examples

The program "my_sieve" returns the number of prime numbers up to a certain value. 
For example, if I run:

time ./my_sieve --limit 10000000000

I get:

455052511

real	1m32,366s
user	1m31,975s
sys	0m0,300s

Meaning that there are 455.052.511 primes in the first 10.000.000.000 numbers. That uses
approximately 600 MB of RAM.
