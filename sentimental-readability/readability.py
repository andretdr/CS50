import re

#def





def main():
    text = input("Text: ")

    space = re.findall("[.{1,} ]", text)
    print(f"{len(space)}")


main()


