"""
Adonay Pichardo, adonaypichardo@gmail.com

@file
linkedList.py

@description
Python3 implementation of a linked list structure.

Example:
CLI
user@host#>python3 linkedList.py 10 4 2 6 5
10[10]
4[10, 4]
2[10, 4, 2]
6[10, 4, 2, 6]
5[10, 4, 2, 6, 5]
5[10, 4, 2, 6]
6[10, 4, 2]
2[10, 4]
4[10]
10[]

STDIN
user@host#>python3 linkedList.py < someFile
10[10]
4[10, 4]
2[10, 4, 2]
6[10, 4, 2, 6]
5[10, 4, 2, 6, 5]
5[10, 4, 2, 6]
6[10, 4, 2]
2[10, 4]
4[10]
10[]
"""

# Standard Imports Start
from sys import argv, stdin, stdout

# Functions Start
def main():
    all_numbers = []

#CLI#CLI#CLI#CLI#CLI#CLI#CLI#CLI#CLI#CLI#CLI#CLI#CLI#CLI#CLI#CLI#CLI#CLI#CLI#CLI#CLI#CLI#    
    if(len(argv) > 1):
        try:
            for every_input in argv[1:]:
                every_input = int(every_input)
                stdout.write(f'{every_input}')
                all_numbers.append(every_input)
                stdout.write(f'{all_numbers}\n')

        except:
            pass

        for every_element in argv[1:]:
            stdout.write(f'{all_numbers.pop()}{all_numbers}\n')

#STDIN#STDIN#STDIN#STDIN#STDIN#STDIN#STDIN#STDIN#STDIN#STDIN#STDIN#STDIN#STDIN#STDIN#STDI
    else:
        total = 0
        while True:
            try:
                read   = int(stdin.readline())
                total += 1

                stdout.write(f'{read}')
                all_numbers.append(read)
                stdout.write(f'{all_numbers}\n')

            except:
                break

        for every_element in range(total):
            stdout.write(f'{all_numbers.pop()}{all_numbers}\n')

if __name__ == "__main__":
    main()
