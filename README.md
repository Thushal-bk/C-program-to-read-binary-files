# C-program-to-read-binary-files

This exercise was part of a coding assignment in my Master's degree. The task was to create a C program to read binary files of a specific struct format and sort the fields based on given specifications. 

The specific file struct format is:

Each record in the data files contains the following fields in the following order.


-The 'heart' field is an integer occupying 2 bytes

-The 'lizards' field is a Boolean occupying 2 bytes
The 'crime' field is a Boolean occupying 1 byte
The 'pancake' field is a Boolean occupying 4 bytes
The 'art' field is a character occupying 1 byte
The 'brothers' field is an unsigned integer occupying 8 bytes
The 'morning' field is a fixed-length string holding at most 9 characters (including terminating nulls)
The 'thumb' field is a Boolean occupying 4 bytes
The 'system' field is a Boolean occupying 2 bytes
The 'pain' field is an integer occupying 4 bytes
The 'girls' field is a floating point number occupying 8 bytes
The 'carpenter' field is a floating point number occupying 4 bytes
The 'scarecrow' field is an unsigned integer occupying 4 bytes
The 'driving' field is a character occupying 1 byte
The 'produce' field is a floating point number occupying 4 bytes
The 'flight' field is an unsigned integer occupying 8 bytes
The 'increase' field is an integer occupying 1 byte

The specific sort order of the fields are:

Sorting order (in order of precedence)-

driving in ascending order.
produce in ascending order.
flight in descending order.
thumb in ascending order.
pain in descending order.
art in ascending order.
pancake in ascending order.
lizards in descending order.
carpenter in descending order.
girls in descending order.
increase in ascending order.
brothers in ascending order.
morning in descending order.
system in descending order.
crime in ascending order.
heart in descending order.
scarecrow in descending order.

main.c accepts two arguments (1) The input binary file for fread (2) The output binary file for fwrite
The input binary files are named as input-1.bin, input-2.bin...etc
The output binary files is what my program generated.

You can verify the output of the binary files using verify.c, it accepts one argument, just the binary file you want to print the output for.


