import re

#def





def main():
    text = input("Text: ")

    sentences = re.findall('[.!?]', text) # (r'\.', text)
    words = re.findall('[ ]', text)
    letters = re.findall('[a-zA-Z]', text)
#    for i in space:
#        print(f"{i}")
    print(f"{len(sentences)}")
    print(f"{len(words)}")
    print(f"{len(letters)}")



main()


