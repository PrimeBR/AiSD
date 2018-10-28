#!/bin/bash
echo -n > results.txt
echo "Examples of incorrect input: "
echo "Test 1: a+b*(c--d)"
echo "Test 1: a+b*(c--d)" >> results.txt
./lab3 < Tests/test1.txt >> results.txt
echo "Test 2: m-n*i/kk"
echo "Test 2: m-n*i/kk" >> results.txt
./lab3 < Tests/test2.txt >> results.txt
echo "Test 3: a%c"
echo "Test 3: a%c" >> results.txt
./lab3 < Tests/test3.txt >> results.txt
echo "Test 4: (((((d+9)+e)-8)/3)"
echo "Test 4: (((((d+9)+e)-8)/3)" >> results.txt
./lab3 < Tests/test4.txt >> results.txt
echo "Test 5: )d+x)"
echo "Test 5: )d+x)" >> results.txt
./lab3 < Tests/test5.txt >> results.txt
echo "Test 6: "
echo "Test 6: " >> results.txt
./lab3 < Tests/test6.txt >> results.txt
echo "Test 7: a+b+c/"
echo "Test 7: a+b+c/" >> results.txt
./lab3 < Tests/test7.txt >> results.txt
echo "Examples of correct input: "
echo "Test 8: q/w*e-r+t/r*e-3+4*5+3-2"
echo "Test 8: q/w*e-r+t/r*e-3+4*5+3-2" >> results.txt
./lab3 < Tests/test8.txt >> results.txt
echo "Test 9: (q*(w/(e-(r+(2)))))"
echo "Test 9: (q*(w/(e-(r+(2)))))" >> results.txt
./lab3 < Tests/test9.txt >> results.txt
echo "Test 10: ((a*2)/(f-5))/((a/2)+(f*5))"
echo "Test 10: ((a*2)/(f-5))/((a/2)+(f*5))" >> results.txt
./lab3 < Tests/test10.txt >> results.txt
echo "Results of test saved in results.txt"