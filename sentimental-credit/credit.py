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


    if (re.searc("^34", number) or (re.searc("^37", number)) and len(number) == 15):
        print(f"AMEX")
    else:
        print("INVALID")


main()
