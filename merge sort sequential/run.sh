#!/bin/bash
#SBATCH --partition=Centaurus
#SBATCH --time=01:00:00
#SBATCH --mem=16G

./mergesort 10
./mergesort 100
./mergesort 1000
./mergesort 10000
./mergesort 100000
./mergesort 1000000
./mergesort 10000000
./mergesort 100000000
./mergesort 1000000000