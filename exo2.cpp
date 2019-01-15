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

int main ()
{
   CLHEP::MTwistEngine *\begin{lstlisting} s = new CLHEP::MTwistEngine();

   double f;
   unsigned int nbr;   
   char filename[100];

   for(int i = 0; i < 8; i++)
   {
	for(int j = 0; j < 1000000; j++)
		s->flat();
	
	sprintf(filename, "statut_%d.mt", i);
	s->saveStatus(filename);
   }

   delete s;

   return 0;
}


