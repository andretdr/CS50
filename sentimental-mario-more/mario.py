def getheight(prompt):
    while True:
        try:
            height = int(input(prompt))
            if height > 0 and height < 9:
                return height
        except ValueError:
            print("Not an Integer")


def main():
    height = getheight("Height: ")
    for i in range(height):
        print(" " * (height-i-1) + "#" * (i+1) + "  " + "#" * (i+1))


main()
