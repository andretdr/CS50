import csv
import sys
import re

# from sys import argv

def main():

    input
    if cmdlineinput(): # Check for command-line usage
        csvfile = sys.argv[1]
        dnafile = sys.argv[2]
    else:
        return 1

    data = []

    with open(csvfile, newline='') as file: # Read database file into a variable
        dreader = csv.reader(file) # reader points to inside the open file

        for row in dreader:
            data.append(row)

        print(f"{data[0]}")

    with open(dnafile) as file: # Read DNA sequence file into a variable
        dnaseq = file.read()

    # create matcher, a list similar to data
    matcher = []
    i = 1
    matcher.append('whoisthis')
    while i < len(data[0]): # for all the different STR in header
#        print(f'longest sequence for {data[0][i]} is {longestcount}')
        matcher.append(str(longest_match(dnaseq, data[0][i])))
        i += 1
    print(matcher)

    found = []

    tempmatcher = matcher
    tempmatcher.pop(0)

    for row in data:
        temprow = row
        temprow.pop(0)

        print(f"{temprow} temprow")
        print(f"{tempmatcher} tempmatcher")
        print(row)

        if temprow == tempmatcher:
            found = row

    if len(found) > 0:
        print(found[0])
    else:
        print('No Match')


    return

def cmdlineinput():
    if len(sys.argv) != 3:
        print(f"Incorrect CMD line input. Requires 2 input files")
        return False
    else:
        return True

def longest_match(sequence, subsequence):

    myregex = '('+subsequence+'|\n)'
    setmatch = re.split(myregex, sequence) # if search STR is found at the head, currentcount++. else if found midway, current count = 1. STR == data[0][i]
        # fill in matcher
    currentcount = 0
    longestcount = 0

    for j in setmatch:
        if j == subsequence:
            currentcount += 1
        elif (j != '') or (j == '\n'): # end of STR sequence, check if its the longest sequence, if so update
            if currentcount > longestcount:
                longestcount = currentcount
            currentcount = 0

    return longestcount

main()
