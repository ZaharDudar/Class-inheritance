from random import random
import os

max_shift = 50
fails_count = 0
max_fails_count = 5

time_scale = 30
window_width = 1200
window_height = 1200
sheep_count = 50

# config = open('config.txt', 'r')

sheep_coords = []
for i in range(sheep_count):  # временная хрень потом с файла читать буду
    sheep_coords.append([random()*window_width, random()*window_height])
print(sheep_coords)

with open("config1.cfg", 'w') as f:
    f.write("test1 " + str(time_scale) + "\n")
    for i in range(sheep_count):
        f.write("Sheep " + str(sheep_coords[i][0]) + " " + str(sheep_coords[i][1]) + " 1\n")
    f.write("Fox 700 700 2")
os.system("export LD_LIBRARY_PATH=./SFML-2.6.1/lib && ./zoo config1.cfg")
with open("/mnt/c/Users/n/Desktop/oop_repo/Class-inheritance/logs/test1.log", 'r') as f:
    result = len(f.readlines())
    print('New result', result)
go_on = True
new_sheep_coords = sheep_coords.copy()
while go_on:
    for i in range(sheep_count):
        new_sheep_coords[i][0] = sheep_coords[i][0] + max_shift*(2*random() - 1)
        new_sheep_coords[i][1] = sheep_coords[i][1] + max_shift*(2*random() - 1)
    print(new_sheep_coords, '\n')
    with open("config1.cfg", 'w') as f:
        f.write("test1 " + str(time_scale) + "\n")
        for i in range(sheep_count):
            f.write("Sheep " + str(sheep_coords[i][0]) + " " + str(sheep_coords[i][1]) + " 1\n")
        f.write("Fox 700 700 1\n")
        f.write("Fox 300 300 1")
    os.system("export LD_LIBRARY_PATH=./SFML-2.6.1/lib && ./zoo config1.cfg")  # ещё реализация
    with open("/mnt/c/Users/n/Desktop/oop_repo/Class-inheritance/logs/test1.log", 'r') as f:
        new_result = len(f.readlines())
        print('New result', new_result)
    if new_result > result:
        result = new_result
        sheep_coords = new_sheep_coords
        fails_count = 0
    else:
        fails_count += 1

    if fails_count >= max_fails_count:
        go_on = False

print("best position", sheep_coords, result)

#запись в файл конфига
