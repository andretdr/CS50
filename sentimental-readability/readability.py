import re

def main():

    text = input("Text: ")

    sentences = re.findall('[.!?]', text) # (r'\.', text)
    words = re.findall(r"\w+[. !?,\"]", text)
    letters = re.findall('[a-zA-Z]', text)

    L = len(letters)/len(words) * 100
    S = len(sentences)/len(words) * 100

    index = round(0.0588 * L - 0.296 * S - 15.8)

    if index < 1:
        print("Before Grade 1")
    elif (index >= 16):
        print("Grade 16+")
    else:
        print(f"Grade {index}")

main()


