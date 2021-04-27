cmake_minimum_required(VERSION 3.20.0)
project(AP)
set(src
        src/main.cpp
        src/func.cpp
        src/course.cpp
        src/exam.cpp
        src/question.cpp
        src/BlankFillingQuestion.cpp
        src/FourChoicesQuestion.cpp
        src/answersheet.cpp
        src/TextualQuestion.cpp

)


include_directories(./header)
set(CMAKE_CXX_STANDARD 11)
add_executable(app ${src})