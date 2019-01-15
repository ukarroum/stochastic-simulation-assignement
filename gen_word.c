#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <limits.h>
#include <unistd.h>

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>

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

   char letters[5] = "acgt";
   char word[8] = "";

   long nb;
	
	int continu = 1;
	int cpt = 0;

	int win[40] = {0};
	int sum = 0;
	for(int j = 0; j < 40; j++)
	{
		for(int k = 0; k < 1000000; k++)
		{
			for(int i = 0; i < 7; i++)
				word[i] = letters[int(floor(s->flat()*4)) % 4];

			word[7] = '\0';
			if(!strcmp(word, "gattaca"))
				win[j]++;

			cpt++;
		}
		sum += win[j];
	}

	printf("Mean Probability : %f%%\n", sum/(40*10000.0));

	int mean =  sum/(40*10000.0);
	int sum_std = 0;

	for(int k = 0; k < 40; k++)
		sum_std += pow((win[k] - mean)/10000.0, 2);
	sum_std = sqrt(sum_std/(39));

	printf("Standard Deviation : %f\n", sum_std);

   delete s;

   return 0;
}
