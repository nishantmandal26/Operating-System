#!/bin/bash
echo "Enter a number: "
read a
n=0
p=1
for (( i=0 ; i<$a; i++ ))
do
echo " $n "
q=$((n+p))
n=$p
p=$q

done
