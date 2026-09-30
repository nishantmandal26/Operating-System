#!/bin/bash
echo "Enter a Year: "
read n
if [ $((n%400)) -eq 0 ] || [ $((n%100)) -ne 0 ] && [ $((n%4)) -eq 0 ]; then
echo "Leap year"
else
echo "Not Leap year"
fi
