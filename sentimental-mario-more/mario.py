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
    for i in range(height):
        print(" " * (height-i) + "*" * i + "  " + "*" * i + " " * (height-1))

main()
