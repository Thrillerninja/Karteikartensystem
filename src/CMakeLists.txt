set(BINARY ${CMAKE_PROJECT_NAME})

#add executabeles...
file(GLOB_RECURSE SOURCES LIST_DIRECTORIES true *.h *.c) #simplification

set(SOURCES ${SOURCES})

add_executable(${BINARY}_run ${SOURCES})

add_library(${BINARY}_lib STATIC ${SOURCES} hangman.c hangman.h)