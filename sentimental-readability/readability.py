import re

#def





def main():
    text = input("Text: ")

    space = re.findall("[.]", text)
    print(f"{len(space)}")


main()


