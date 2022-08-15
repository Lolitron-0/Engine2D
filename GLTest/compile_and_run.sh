g++ -std=c++17 -c *.cpp -I ./ -I ./Includes
g++ *.o -o prog  -lGL -lglfw3 -lpthread -lm -lz -lGL -lX11 -lXext -lXfixes -ldl
./prog
