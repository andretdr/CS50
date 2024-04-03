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

# next

for i in range(3):
    for j in range(3):
            print("#", end="")
    print()

    # or

for i in range(3):
    print("#" * 3)

# list, like a linked list
# docs.python.org/3/library/stdtypes.html#sequence-types-list-tuple-range

scores = [72, 73, 33]

average = sum(scores) / len(scores) # len of list
print(f"Average: {average}")

    # next

from cs50 import get_int

scores = [] # you can initialise in python without malloc. these are mostly lists, not arrays. arrays have to be declared sincde they are not built into python
for i in range(3):
    score = get_int("Score: ")
    scores.append(score) # scores = scores + [score]      to concatonate. add 2 lists together

average = sum(scores) / len(scores)
print(f"Average: {average}")

    # next

names = ["Carter", "David", "John"]

name = input("Name: ")

for n in names:
    if name == n:
        print("Found")
        break
else:   # else clause for for loop. if you went through the whole thing without breaking
    print("Not found")

    # or

names = ["Carter", "David", "John"]

name = input("Name: ")

if name in names:
    print("Found")
else:   # else clause for for loop. if you went through the whole thing without breaking
    print("Not found")


# dictionary , collection of value pairs, hashtable. name: david, number: 92893092
{"name": "Carter", "number": "+81518926"} # like a typedef struct

people = [ # a LIST of dictionary, or value pairs
    {"name": "Carter", "number": "+81518926", "address": "sdfsasd"}
    {"name": "David", "number": "+457218926", "address": "asaasd"}
    {"name": "John", "number": "+823418926", "address": "werfsasd"}
]

name = input("Name: ")

for person in people: # var person,
    if person["name"] == name: # person.name
#        number = person["number"]
        print(f"Found {person['number']}") # single on the inside, and double quotes on the outside. dont confuse python
        break
else:
    print("Not found")

    # or

people = { # not a list, but just a dictionary. you can direct index to access, dont need to iterate like a hashtable
    "Carter": "+81518926",
    "David": "+457218926",
    "John": "+823418926",
}

name = input("Name: ")

if name in people:
    number = people[name] # using the name as a hash index to get the number
    print(f"Found {number}")
else:
    print("Not found")

# File
    # Speller check

words = set() # sets are like lists, but all unique

def check(word):
    return word.lower in words

def load(dicionary):
    with open(dictionary) as file:
        words.update(file.read().splitlines())
    return True

def size():
    return len(words)

import csv

### file handling

file = open("favorites.csv", "r")
#do something
close(file)

### OR more commonly

with open("favorites.csv", "r") as file: # file closes automatically after quit
    # once outside of with block, file will close
    reader = csv.reader(file)
    next(reader) # skip the header
    for row in reader:
        print(row[1])

        




# docs.python.org/3/library/sys.html
# cmd line arg

from sys import argv

if len(argv) == 2: # doesnt take into account the python. just the cmd and the arg
    print(f"hello, {argv[1]}")
else:
    print("hello, world:)

    # or

import sys

if len(sys.argv) != 2:
    print("Missing comand-line arg")
    sys.exit()

print(f"hello, {sys.argv[1]}")
sys.exit(0) # can specify


# third party
pip install cowsay # instal library alled cowsay

import cowsay

name = input("gimme: ")
cowsay.cow(f"hello {name}")


pip install qrcode # instal library qrcode

import qrcode

img = qrcode.make("https://youtu.be/xvFZjo5PgG0")
img.save("qr.png", "PNG")



