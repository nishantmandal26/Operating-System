#!/bin/bash
echo "Enter Two Numbers: "
read n
read p
if [ $n -ge $p ]; then
echo "$n is Largest Number"
else
echo "$p is Largest Number"
fi
