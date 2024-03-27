def get_cc(prompt):
    while True:
        try:
            value = int(input(prompt))
            if value > 0:
                return value
        except ValueError:
            print("INVALID")


def main():
    number = get_cc("Number: ")
    printf("{number}")



main()
