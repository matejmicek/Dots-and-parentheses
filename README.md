# Dots-and-parentheses - school assignment

The following task has two parts. First you must figure out the principle behind the following encoding of natural numbers. The table below displays the encoding of the numbers from 0 to 11.

Number  	Code
0	.
1	()
2	(())
3	(.())
4	((()))
5	(..())
6	(()())
7	(...())
8	((.()))
9	(.(()))
10(().())
11(....())

Once you understand how the numbers are encoded, write a program which encodes a given series of natural numbers. The application will receive an input file cisla.in containing the natural numbers (in decimal representation with one number per line). Your task is to encode each number and write the results to a file cisla.out (again with one number per line). Each input number will fit into a 32-bit integer and the length of the string encoding each number is less than 400,000 characters.
