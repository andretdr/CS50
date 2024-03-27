import re

def get_cc(prompt):
    while True:
        try:
            value = input(prompt)
            if int(value) > 0:
                return value # returning the string not the int
        except ValueError:
            print("INVALID")


def main():
    number = get_cc("Number: ")

    length = len(number)
    


    if (re.search("^34", number) or (re.search("^37", number)) and length == 15):
        print(f"AMEX")
    elif (re.search("^[5][1-5]", number) and length == 16):
        print(f"MC")
    elif (re.search("^4", number) and (length == 13 or (length == 16))):
        print(f"VISA")
    else:
        print("INVALID")


main()