#!bin/bash

for ((i=1;i<=10;i++)) 
do
    ./tarea1_ag $[100*i] < input > Debug/SEED$[100*i]_CROSS09_MUT001.csv
done

exit 0
