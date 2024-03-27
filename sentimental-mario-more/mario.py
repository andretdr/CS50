def getheight(prompt):
    while True:
        try:
            height = int(input(prompt))
            if height > 0:
                return height
        except ValueError:
            print("Not an Integer")

def main():
    height = getheight("Height: ")
    print(f"{height}")

main()
