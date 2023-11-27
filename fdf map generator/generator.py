#!/usr/bin/python

import sys
from PIL import Image #pip install pillow

if (len(sys.argv) > 1):
    img = Image.open(sys.argv[1])
    width, height = img.size
    pixels = img.load()

    res = []
    for y in range(height):
        res.append([])
        for x in range(width):
            r, g, b = pixels[x, y]
            hex_color = '0x{:02x}{:02x}{:02x}'.format(r,g,b)
            res[-1].append(hex_color)

    row_count = 0
    with open('res.fdf', 'w') as f:
        for y, row in enumerate(res):
            for x, color in enumerate(row):
                f.write(str(1) + "," + str(color) + " ") #replace 1 with the desired height
            f.write("\n")
            row_count += 1
            if (row_count > 250):
                break
    print("Done")
else:
	print("Usage: python3 generator.py <image> [output file name]")