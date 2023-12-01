#!/usr/bin/python

import sys
from PIL import Image #pip install pillow

if (len(sys.argv) > 1):
    if (sys.argv[1].startswith("./")):
        img = Image.open(sys.argv[1])
    else:
        img = Image.open("./" + sys.argv[1])
    width, height = img.size
    pixels = img.load()

    res = []
    for y in range(height):
        res.append([])
        for x in range(width):
            r, g, b, *_ = pixels[x, y]
            hex_color = '0x{:02x}{:02x}{:02x}'.format(r,g,b)
            res[-1].append(hex_color)

    with open('res.fdf', 'w') as f:
        for y, row in enumerate(res):
            for x, color in enumerate(row):
                f.write(str(1) + "," + str(color) + " ") #replace 1 with the desired height
            f.write("\n")
    print("Done")
else:
	print("Usage: python3 generator.py <image> [output file name]")