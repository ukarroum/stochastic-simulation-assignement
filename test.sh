#!/bin/sh

rm tmp.mt
./runRand 10 > tmp.mt

for ind in {0..7}
do
	file="status/statut_$ind.mt"
	./runRand $file 10 >> tmp.mt
done

./runRand 90 > tmp2.mt	

diff tmp.mt tmp2.mt
