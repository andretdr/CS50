import csv
import sys
# from sys import argv

def cmdlineinput():
    if len(sys.argv) != 3:
        print(f"Incorrect CMD line input. Requires 2 input files")
    else:
        return True

def main():

    input
    if cmdlineinput(): # Check for command-line usage
        csvfile = sys.argv[1]
        dnafile = sys.argv[2]

    database = set()

    with open(csvfile) as file: # Read database file into a variable
        database.update(file.read().splitlines())

    with open(dnafile) as file: # Read DNA sequence file into a variable
        dnaseq = file.read()

    for i in database:
        print(f"{i}")

    print(f"{dnaseq}")

    # Find longest match of each STR in DNA sequence
    if "Alice,2,8,3" in database:
        print("true")
    else:
        print("false")




    # TODO: Check database for matching profiles

    return


def longest_match(sequence, subsequence):
    """Returns length of longest run of subsequence in sequence."""

    # Initialize variables
    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    # Check each character in sequence for most consecutive runs of subsequence
    for i in range(sequence_length):

        # Initialize count of consecutive runs
        count = 0

        # Check for a subsequence match in a "substring" (a subset of characters) within sequence
        # If a match, move substring to next potential match in sequence
        # Continue moving substring and checking for matches until out of consecutive matches
        while True:

            # Adjust substring start and end
            start = i + count * subsequence_length
            end = start + subsequence_length

            # If there is a match in the substring
            if sequence[start:end] == subsequence:
                count += 1

            # If there is no match in the substring
            else:
                break

        # Update most consecutive matches found
        longest_run = max(longest_run, count)

    # After checking for runs at each character in seqeuence, return longest run found
    return longest_run

main()