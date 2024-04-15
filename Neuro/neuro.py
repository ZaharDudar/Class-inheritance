from random import random

max_shift = 10
fails_count = 0
max_fails_count = 5

window_width = 1200
window_height = 600
sheep_count = 5

config = open('config.txt', 'r')

sheep_coords = []
for i in range(sheep_count):  # временная хрень потом с файла читать буду
    sheep_coords.append([random()*window_width, random()*window_height])
print(sheep_coords)

# реализация и стата

result = 100
go_on = True
new_sheep_coords = sheep_coords.copy()
test = 0
while go_on:
    for i in range(sheep_count):
        new_sheep_coords[i][0] = sheep_coords[i][0] + max_shift*(2*random() - 1)
        new_sheep_coords[i][1] = sheep_coords[i][1] + max_shift*(2*random() - 1)
    print(new_sheep_coords, '\n')
    # ещё реализация
    new_result = 110
    if new_result > result:
        result = new_result
        sheep_coords = new_sheep_coords
        fails_count = 0
    else:
        fails_count += 1

    if fails_count >= max_fails_count:
        go_on = False

print("best position", sheep_coords)

#запись в файл конфига
