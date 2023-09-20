import math

from PIL import Image

def find_coprime(n):
    i = 2
    while True:
        if math.gcd(n, i) == 1:
            return i
        i += 1

def multiplicative_inverse(e, phi):
    d = 0
    x1 = 0
    x2 = 1
    y1 = 1
    temp_phi = phi

    while e > 0:
        temp1 = temp_phi // e
        temp2 = temp_phi - temp1 * e
        temp_phi = e
        e = temp2

        x = x2 - temp1 * x1
        y = d - temp1 * y1

        x2 = x1
        x1 = x
        d = y1
        y1 = y

    if temp_phi == 1:
        return d + phi

def phi(x, y):
    return (x - 1) * (y - 1)

image_path = "persona1.jpg"
encrypted_output_path = "encrypted_image.txt"
key_output_path = "keys.txt"

image = Image.open(image_path)

pixels = image.load() 
width, height = image.size

# x and y are prime numbers of 8 bits, so the generated keys have a size of 16 bits
x = 173
y = 251

phi_x_y = phi(x, y)

n = x * y
e = find_coprime(phi_x_y)
d = multiplicative_inverse(e, phi_x_y)


with open(key_output_path, "w") as file:
    file.write(f"Public Key (n, e): ({n}, {e})\n")
    file.write(f"Private Key (n, d): ({n}, {d})")
    file.close()


with open(encrypted_output_path, "w") as file:
    file.write(f"{pow(width, e, n)},{pow(height, e, n)},")

    for i in range(width):
        for j in range(height):
            r, g, b = pixels[i, j]
            gray_pixel = int(0.2989 * r + 0.5870 * g + 0.1140 * b)
            encrypted_pixel = pow(gray_pixel, e, n)
            
            if(j == (height - 1) and i == (width - 1)):
                file.write(f"{encrypted_pixel}")
            else:
                file.write(f"{encrypted_pixel},")
    
    file.close()