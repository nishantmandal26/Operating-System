#!/bin/bash
echo "Enter Three Numbers: "
read n
read p
read q
if [ $n -ge $p ] && [ $p -ge $q ]; then
echo "$n is Largest Number"
elif  [ $p -ge $n ] && [ $n -ge $q ]; then
echo "$p is Largest Number"
else
echo "$q is Largest Number"
fi
