"""
Adonay Pichardo, adonaypichardo@gmail.com

@file
power.py

@description
Recursively compute the exponentiation of x to the power of y.

"""

# Standard Imports Start
from sys import argv, stdin, stdout

def power(x, y):
    """
    Computes x to the power of y, recursively.
    INPUT:  x - int, The base of the exponent.
            y - int, The power of the exponent.
    OUTPUT: x ^^ y
    """
    # We will not consider negative powers
    if(y <= 0):
        return 1;

    return x * power(x, (y - 1))

def main():
    #########################################################################################
    #CLI#CLI#CLI#CLI#CLI#CLI#CLI#CLI#CLI#CLI#CLI#CLI#CLI#CLI#CLI#CLI#CLI#CLI#CLI#CLI#CLI#CLI#
    #########################################################################################
        if(len(argv) > 1):
            stdout.write(f'{power(int(argv[1]), int(argv[2]))}\n')

    #########################################################################################
    #STDIN#STDIN#STDIN#STDIN#STDIN#STDIN#STDIN#STDIN#STDIN#STDIN#STDIN#STDIN#STDIN#STDIN#STDI
    #########################################################################################
        else:
            while True:
                read = stdin.readline().rstrip()
                if len(read) == 0: break

                x, y = read.split()

                stdout.write(f'{power(int(x), int(y))}\n')

if __name__ == "__main__":
    main()
