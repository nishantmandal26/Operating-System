#!/bin/bash
echo "Enter A Number: "
read n
if [ $n -gt 0 ]; then
echo "Number is Positive"
elif [ $n -lt 0 ]; then
echo "Number is Negative"
else
echo "Number is Zero"
fi
