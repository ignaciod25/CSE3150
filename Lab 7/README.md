# CSE 3150 Lab 4 Generate Well Balanced List

### This program reads in vectors of doubles in Rk where 𝑘 ≥ 2 is an integer. All the vectors in the file are the same size. It computes all pairwise cosine distances for all vectors. Output pairs of vectors – ordered by the cosine closeness of the vectors

To compile the program and get a well balanced list, run the command:
```bash
g++ -std=c++11 gen_permutations.cpp main.cpp -o gen_per
```
then run the executable 
```bash
./gen_per
```



To compile the program with doctest unit tests, run the command:
```bash
g++ -std=c++11 gen_permutations.cpp unittests.cpp -o unit_tests
```
then run the executable 
```bash
./unittests
```
