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



    if (re.search("^34", number) or (re.search("^37", number)) and len(number) == 15):
        print(f"AMEX")
    elif (re.search("^51", number) or (re.search("^37", number)) and len(number) == 15):
        print("INVALID")


main()
