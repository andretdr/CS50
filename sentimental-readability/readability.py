import re

#def





def main():
    text = input("Text: ")

    space = re.findall(".", text)
    for i in space:
        print(f"{i}")
    print(f"{len(space)}")

main()


