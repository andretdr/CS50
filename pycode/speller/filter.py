from PIL import Image, ImageFilter # python image library

before = Image.open("bridge.bmp") # before is variable
after = before.filter(ImageFilter.BoxBlur(10))
after.save("out.bmp")


before = Image.open("bridge.bmp")
after = before.filter(ImageFilter.FIND_EDGES)
after.save("out.bmp")

# add support of python, in terminal
$ pip install face_recognition
