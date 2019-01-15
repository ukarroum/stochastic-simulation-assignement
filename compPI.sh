#!/bin/sh

rm res_pi
touch res_pi

for ind in {0..7}
do
	file="statut_$ind.mt"
	./compPI $file 1000000000 >> res_pi & 
done
