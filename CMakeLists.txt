cmake_minimum_required(VERSION 3.11)
project(zoo)


add_executable(zoo
                Drawer/Drawer.cpp
                Field/Field.cpp

                Animals/Animals.cpp  
                Animals/Cow.cpp  
                Animals/Goose.cpp
                Animals/Pig.cpp    
                Animals/Wolf.cpp
                Animals/Boar.cpp     
                Animals/Fox.cpp  
                Animals/Gorilla.cpp  
                Animals/Sheep.cpp          

                main.cpp
)   

set(SFML_DIR ${CMAKE_CURRENT_SOURCE_DIR}/SFML-2.6.1/lib/cmake/SFML)
find_package(SFML 2.6 COMPONENTS graphics window system REQUIRED)
# set(SFML_LIBRARY sfml)

target_link_libraries(zoo sfml-graphics sfml-window sfml-system)
# cd ..; rm -r build; mkdir build; cd build