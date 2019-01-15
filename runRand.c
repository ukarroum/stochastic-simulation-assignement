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

   for(int i = 0; i < nb; i++)
   {
	f = s->flat();
	cout << f << endl;
   }

   delete s;

   return 0;
}
