#!/bin/bash

# time_2000.sh calculates the times with different optimizations for a 2000x2000
# matrix multiply

# mm_noreuse_2000.c
icc -O0 mm_noreuse_2000.c 
echo "icc-O0_noreuse_2000" >> result.txt
for i in {1..1}; do time ./a.out ; done 2>&1 | grep ^user >> result.txt
echo "==============" >> result.txt
echo

gcc -O0 mm_noreuse_2000.c
echo "gcc-O0_noreuse_2000" >> result.txt
for i in {1..1}; do time ./a.out ; done 2>&1 | grep ^user >> result.txt
echo "==============" >> result.txt
echo

icc mm_noreuse_2000.c
echo "icc_noreuse_2000" >> result.txt
for i in {1..1}; do time ./a.out ; done 2>&1 | grep ^user >> result.txt
echo "==============" >> result.txt
echo

gcc mm_noreuse_2000.c
echo "gcc_noreuse_2000" >> result.txt
for i in {1..1}; do time ./a.out ; done 2>&1 | grep ^user >> result.txt
echo "==============" >> result.txt
echo

icc -O3 mm_noreuse_2000.c 
echo "icc-O3_noreuse_2000" >> result.txt
for i in {1..1}; do time ./a.out ; done 2>&1 | grep ^user >> result.txt
echo "==============" >> result.txt
echo

gcc -O3 mm_noreuse_2000.c 
echo "gcc-O3_noreuse_2000" >> result.txt
for i in {1..1}; do time ./a.out ; done 2>&1 | grep ^user >> result.txt
echo "==============" >> result.txt
echo


# mm_reuse_2000.c
icc -O0 mm_reuse_2000.c 
echo "icc-O0_reuse_2000" >> result.txt
for i in {1..1}; do time ./a.out ; done 2>&1 | grep ^user >> result.txt
echo "==============" >> result.txt
echo

gcc -O0 mm_reuse_2000.c
echo "gcc-O0_reuse_2000" >> result.txt
for i in {1..1}; do time ./a.out ; done 2>&1 | grep ^user >> result.txt
echo "==============" >> result.txt
echo

icc mm_reuse_2000.c
echo "icc_reuse_2000" >> result.txt
for i in {1..1}; do time ./a.out ; done 2>&1 | grep ^user >> result.txt
echo "==============" >> result.txt
echo

gcc mm_reuse_2000.c
echo "gcc_reuse_2000" >> result.txt
for i in {1..1}; do time ./a.out ; done 2>&1 | grep ^user >> result.txt
echo "==============" >> result.txt
echo

icc -O3 mm_reuse_2000.c 
echo "icc-O3_reuse_2000" >> result.txt
for i in {1..1}; do time ./a.out ; done 2>&1 | grep ^user >> result.txt
echo "==============" >> result.txt
echo

gcc -O3 mm_reuse_2000.c 
echo "gcc-O3_reuse_2000" >> result.txt
for i in {1..1}; do time ./a.out ; done 2>&1 | grep ^user >> result.txt
echo "==============" >> result.txt
echo
echo
