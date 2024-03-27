import re

#def





def main():
    text = input("Text: ")

    sentences = re.findall('[.!?]', text) # (r'\.', text)
    words = re.findall('[ .!?]', text)
    letters = re.findall('[a-z, A-Z]', text)
    for i in space:
        print(f"{i}")
    print(f"{len(space)}")

main()


