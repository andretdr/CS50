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
    print(f"{number}")



main()
