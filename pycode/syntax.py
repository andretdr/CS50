# docs.python.org


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

or
x = cs50.get_int("x: ") # if you want to use cs50's get_int specifically

# conditionals

if x < y: # colon is curly bracets, and indent
    print("x is less than y")
elif x > y:
    print("y is less than x")
else:
    print("equal")

# str in C, char* are pointers comparing memory. But in py you can compare strings

s = input("gimme s ")
t = input("gimme t ")

if s == t: # colon is curly bracets, and indent
    print("equal")
else:
    print("different")

# OOP has methods. method is a function that comes with a data type like string, has a tolower method built in

    # agree excercise

s = input("agree? ")

if s == "Y" or s == "y":
    print("Agreed")
elif s == "N" or s == "n":
    print("Not agreed")

    # next

s = input("agree? ").lower() # calling the method in the same line. same as s = s.lower()

if s in ["y", "yes"]: # checking against a list
    print("Agreed")
elif s in ["n", "no"]:
    print("Not agreed")

# loop

i = 0
while i < 3:
    print("meow")
    i += 1

for i in range(3): # or   for i in [0, 1, 2]:  or  for _ in range(3): same thing
    print("meow") # python is using i

# while True:     forever loop
#     print("meow")

    # uppercase excercise

before = input("Before: ")
print("After:    ", end="") # print will auto end="\n". so have to , end=""
for c in before: # c iterates over all characters in before
    print(c.upper())
print() # print will \n

    # or
before = input("Before: ")
print(f"After: {before.upper()}")

# functions


def main():
    meow(3)

def meow(n):
    for i in range(n):
        print("meow")

main()

# truncation

x = int(input("x: "))
y = int(input("y: "))

z = x / y # doesnt auto truncate. auto create float
print(f"{z:.50f}") # float, 50 dec points

# floating point precision still an issue

# int overflow?
int can keep growing forever


# exception

def get_int(prompt):
    while True: # loop forever
        try: # try this or else will exception
            return int(input(prompt)) # break out the loop
        except ValueError: #catch your exception. ValueError is what you see as traceback
            print("Not an integer") # you can also say     pass   to do nothing


def main():
    x = get_int("x: ")
    y = get_int("y: ")

    print(x + y)


main()

# Mario Loops

from cs50 import get_int

while True: # infinity loop to keep trying until you get what you want
    n = get_int("Height: ")
    if n > 0:
        break

for i in range(3):
    print("#")


    # next

for i in range(4):
    print("?", end="")
print()

    # or

print("?" * 4)
