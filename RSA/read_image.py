import os

from PIL import Image

image_path = "persona1.jpg"
out_path = "imagen.txt"


image = Image.open(image_path)

width, height = image.size

pixels = image.load()


if(os.path.exists(out_path)):
    os.remove(out_path)


for i in range(width):
    for j in range(height):
        r, g, b = pixels[i, j]
        gray = str(int(0.2989 * r + 0.5870 * g + 0.1140 * b))
        
        with open(out_path, "a") as file:
            if(j == (height - 1)):
                file.write(f"{gray}\n")
                continue
            
            file.write(f"{gray}, ")