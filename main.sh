#! /bin/bash

rm -f datafile.csv #remove the dataset if it exists

./reaction >> datafile.csv

python plot.py
