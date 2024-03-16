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
# SET(CMAKE_EXE_LINKER_FLAGS  "-Wl,--copy-dt-needed-entries")
# set(LDFLAGS "-Wl" "--copy-dt-needed-entries")
# set(SFML_STATIC_LIBRARIES TRUE)
# find_package(SFML 2 COMPONENTS graphics window system)
# include_directories(${SFML_INCLUDE_DIR})

# set(INCLUDE_DIRS "${CMAKE_CURRENT_SOURCE_DIR}/SFML-2.6.1/include/SFML"
#                  "${CMAKE_CURRENT_SOURCE_DIR}/SFML-2.6.1/include/SFML/System"
#                  "${CMAKE_CURRENT_SOURCE_DIR}/SFML-2.6.1/include/SFML/Window"
#                  "${CMAKE_CURRENT_SOURCE_DIR}/SFML-2.6.1/include/SFML/Graphics")
list(APPEND INCLUDE_DIRS "${CMAKE_CURRENT_SOURCE_DIR}/SFML-2.6.1/include/SFML")
list(APPEND INCLUDE_DIRS "${CMAKE_CURRENT_SOURCE_DIR}/SFML-2.6.1/include/SFML/System")
list(APPEND INCLUDE_DIRS "${CMAKE_CURRENT_SOURCE_DIR}/SFML-2.6.1/include/SFML/Window")
list(APPEND INCLUDE_DIRS "${CMAKE_CURRENT_SOURCE_DIR}/SFML-2.6.1/include/SFML/Graphics")

set(INCLUDE_SHARE "${CMAKE_CURRENT_SOURCE_DIR}/SFML-2.6.1/lib/libsfml-window-d.so.2.6.1"
                  "${CMAKE_CURRENT_SOURCE_DIR}/SFML-2.6.1/lib/libsfml-graphics-d.so.2.6.1"
                  "${CMAKE_CURRENT_SOURCE_DIR}/SFML-2.6.1/lib/libsfml-system-d.so.2.6.1")

add_library(sfml SHARED IMPORTED)
set_target_properties(sfml PROPERTIES
IMPORTED_LOCATION "${CMAKE_CURRENT_SOURCE_DIR}/SFML-2.6.1/lib/libsfml-window-d.so.2.6.1",
                  "${CMAKE_CURRENT_SOURCE_DIR}/SFML-2.6.1/lib/libsfml-graphics-d.so.2.6.1",
                  "${CMAKE_CURRENT_SOURCE_DIR}/SFML-2.6.1/lib/libsfml-system-d.so.2.6.1"
INTERFACE_INCLUDE_DIRECTORIES "${CMAKE_CURRENT_SOURCE_DIR}/SFML-2.6.1/include/SFML",
                 "${CMAKE_CURRENT_SOURCE_DIR}/SFML-2.6.1/include/SFML/System",
                 "${CMAKE_CURRENT_SOURCE_DIR}/SFML-2.6.1/include/SFML/Window",
                 "${CMAKE_CURRENT_SOURCE_DIR}/SFML-2.6.1/include/SFML/Graphics"
)
set(SFML_LIBRARY sfml)

target_link_libraries(zoo ${SFML_LIBRARY})
# cd ..; rm -r build; mkdir build; cd build