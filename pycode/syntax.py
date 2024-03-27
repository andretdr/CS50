# librarys
import cs50 # whole library

from cs50 import get_string, get_int, get_float # just the one function

# functions
answer = input("What's your name? ") # dont have to declare type of variable
print("hello, " + answer) # joining strings together
or
print("hello,",answer) # gives free space inbetween
or
print(f"hello, {answer}")

# variables
counter = 0
counter = counter + 1
counter += 1
counter++ # NO HAVE

bool, float, int, str, range, list, tuple, dict or hashtables, set ...

#calculator example

x = int(input("x: ")) # input uses strings, not int
y = int(input("y: ")) # int() will convert string to int
print(x + y);


