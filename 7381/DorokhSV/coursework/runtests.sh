#!/bin/bash
echo -n > result.txt
echo "Examples of correct input: "
echo "Test 1: 54 354 86 3 354 0 3451 8 4762 86\n\t1\n\t777\n\t3"
echo "Test 1: 54 354 86 3 354 0 3451 8 4762 86\n\t1\n\t777\n\t3" >> result.txt
./cw < Tests/test1.txt >> result.txt
echo "Test 2: 23 17 41 42 77 97\n\t2\n\t97\n\t3"
echo "Test 2: 23 17 41 42 77 97\n\t2\n\t97\n\t3" >> result.txt
./cw < Tests/test2.txt >> result.txt
echo "Examples of incorrect input: "
echo "Test 3: 13 7 -7 0 43\n\t123\n\t3"
echo "Test 3: 13 7 -7 0 43\n\t123\n\t3" >> result.txt
./cw < Tests/test3.txt >> result.txt
echo "Test 4: 13 7 -7 qwe 777\n\t3"
echo "Test 4: 13 7 -7 qwe 777\n\t3" >> result.txt
./cw < Tests/test4.txt >> result.txt
echo "Test 5: 86 654 87 43 980 32 0\n\t1\n\tqwe"
echo "Test 5: 86 654 87 43 980 32 0\n\t1\n\tqwe" >> result.txt
./cw < Tests/test5.txt >> result.txt
echo "Results of tests saved in result.txt"