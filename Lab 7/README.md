# CSE 3150 Lab 7 Cos-Distance

### This program reads in vectors of doubles in Rk where 𝑘 ≥ 2 is an integer. All the vectors in the file are the same size. It computes all pairwise cosine distances for all vectors. Output pairs of vectors – ordered by the cosine closeness of the vectors

To compile the program, run the command:
```bash
g++ double_vector.cpp main_double_vector.cpp 
```
then run the executable 
```bash
./a.out
```



To compile the program with doctest unit tests, run the command:
```bash
g++ distance_unittests.cpp double_vector.cpp -o my_tests
```
then run the executable 
```bash
./my_tests
```
