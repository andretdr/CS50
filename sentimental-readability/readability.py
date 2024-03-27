import re

#def





def main():
    text = input("Text: ")

    space = re.findall("[.{1,} ]", text)
    for i in space:
        print(f"{i}")


main()


