# version2.3
CBot_version2.3

Overview:

1. Achieve the configuration of front end and back end
2. Front-end web page is to present data and send user input to back end
3. Back end is to receive user input and conduct manipulation
4. Only can handle the limited question of Array Topic in C
5. Complete all database structure design, more detaill can be added in the future
6. Database can be set up automatically via function call
7. Capable of memory collection
8. Raw data need to be formatted as a form of file manually

Deployment:
1. Put array folder and topic folder in cgi-bin 
2. Put index.html, image folder, css folder in htdocs
3. Compile using command "g++ -std=c++11 Main.cpp function.cpp -o back_end.cgi", while compiling, ensure that abstractDataType.h, function.h, Main.cpp and function.cpp are in the same folder
4. Put back_end.cgi in cgi-bin
5. Only support Linux and MacOS
