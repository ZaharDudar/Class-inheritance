from random import random
import os

max_shift = 0.1
fails_count = 0
max_fails_count = 5

time_scale = 30
window_width = 1200
window_height = 1200
animals_count = 100

start_bush_count = 1000

animal_data = [["Boar",[200, 300], 0],
               ["Cow",[400, 300], 0],
               ["Fox",[600, 300], 0],
               ["Goose",[1000, 300], 0],
               ["Fox",[200, 700], 0],
               ["Wolf",[400, 700], 0],
               ["Sheep",[600, 700], 0],
               ["Pig",[1000, 700], 0]]

rand_sum = 0
for i in range(len(animal_data)):
    animal_data[i][2] = random()
    rand_sum += animal_data[i][2]

for i in range(len(animal_data)):
    animal_data[i][2] = round(animal_data[i][2] * animals_count / rand_sum)

with open("config_by_count.cfg", 'w') as f:
    f.write("test1 " + str(time_scale) + "\n")
    for i in range(start_bush_count):
        f.write("Bush " + str(window_width * random()) + " " + str(window_height * random()) + " 1\n")
    for i in range(len(animal_data)):
        f.write(animal_data[i][0] + " " + str(animal_data[i][1][0]) + " " + str(animal_data[i][1][1]) + " " + str(animal_data[i][2]) +  "\n")

result = 0
go_on = True
new_animal_data = animal_data.copy()
while go_on:
    os.system("export LD_LIBRARY_PATH=./SFML-2.6.1/lib && ./zoo config_by_count.cfg")  # реализация
    with open("/mnt/c/Users/n/Desktop/oop_repo/Class-inheritance/logs/test1.log", 'r') as f:
        new_result = len(f.readlines())
        print('New result', new_result)
    if new_result > result:
        result = new_result
        animal_data = new_animal_data
        fails_count = 0
        with open("config_by_count.cfg", 'w') as f:
            f.write("test1 " + str(time_scale) + "\n")
            for i in range(start_bush_count):
                f.write("Bush " + str(window_width * random()) + " " + str(window_height * random()) + " 1\n")
            for i in range(len(animal_data)):
                f.write(animal_data[i][0] + " " + str(animal_data[i][1][0]) + " " + str(animal_data[i][1][1]) + " " + str(animal_data[i][2]) +  "\n")
    else:
        fails_count += 1

    if fails_count >= max_fails_count:
        go_on = False
    
    rand_sum = 0
    for i in range(len(animal_data)):
        animal_data[i][2] += random() * max_shift * animals_count
        rand_sum += animal_data[i][2]
    for i in range(len(animal_data)):
        animal_data[i][2] = round(animal_data[i][2] * animals_count / rand_sum)

print("best position", animal_data, result)

#запись в файл конфига
# когда-то сделаю))))))
