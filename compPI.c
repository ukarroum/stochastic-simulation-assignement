#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <limits.h>
#include <unistd.h>

#include <iostream>
#include <cstdio>
#include <cstdlib>

#include "Random/CLHEP/Random/SobolQRNGB.h"
#include "Random/CLHEP/Random/MTwistEngine.h"
#include "Random/CLHEP/Random/SobolQRNG.h"

using namespace std;

int main(int argc, char *argv[])
{
   CLHEP::MTwistEngine * s = new CLHEP::MTwistEngine();

   double f;
   unsigned int nbr;   
   char filename[100];

   long nb;

   if(argc == 3)
   {	
   	s->restoreStatus(argv[1]);

   	nb = atoi(argv[2]);
   }
   else
   {
	nb = atoi(argv[1]);
   }

	int nb_in = 0;
		
	for(int j = 0; j < nb; j++)
	{
		double x = s->flat();
		double y = s->flat();

		if(x*x + y*y <= 1.0)
			nb_in++;
	}

	double pi = (nb_in/(float)nb)*4;

	printf("%s - PI = %f\n", argv[1], pi);	

   delete s;

   return 0;
}
