#g++ -o libEngine.so -std=c++17 -shared -fPIC *.cpp -I ./
g++ -std=c++17 -c ./GLTest/*.cpp -I ./GLTest/ 
g++ -std=c++17 -c ./WindowSystem/*.cpp -I ./WindowSystem/
g++ "./GLTest/*.o ./WindowSystem/*.o" -o ./prog  -lGL -lglfw3 -lpthread -lm -lz -lGL -lX11 -lXext -lXfixes -ldl
./prog
rm *.o
