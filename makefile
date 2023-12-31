CC := g++
FLAGS += -std=c++11 -l SDL2 -l SDL2_image -l SDL2_ttf -l SDL2_mixer
BUILD += build
SRC += src

all: starwars.out

starwars.out: $(BUILD)/main.o $(BUILD)/Game.o $(BUILD)/Bullet.o $(BUILD)/Enemy.o $(BUILD)/Fixed_enemy.o $(BUILD)/Object.o $(BUILD)/Player.o $(BUILD)/Moving_enemy.o $(BUILD)/Hostage.o $(BUILD)/Power.o $(BUILD)/rsdl.o
	$(CC) $(BUILD)/main.o $(BUILD)/Game.o $(BUILD)/Bullet.o $(BUILD)/Enemy.o $(BUILD)/Fixed_enemy.o $(BUILD)/Object.o $(BUILD)/Player.o $(BUILD)/Moving_enemy.o $(BUILD)/Hostage.o $(BUILD)/Power.o $(BUILD)/rsdl.o $(FLAGS) -o starwars.out

$(BUILD)/main.o: $(SRC)/main.cpp
	$(CC) -c $(SRC)/main.cpp -o $(BUILD)/main.o

$(BUILD)/Bullet.o: $(SRC)/Bullet.hpp $(SRC)/Bullet.cpp $(SRC)/Object.cpp $(SRC)/Object.hpp $(SRC)/consts.hpp
	$(CC) -c $(SRC)/Bullet.cpp -o $(BUILD)/Bullet.o

$(BUILD)/Game.o: $(SRC)/Game.hpp $(SRC)/Game.cpp $(SRC)/Player.cpp $(SRC)/Player.hpp $(SRC)/Bullet.cpp $(SRC)/Bullet.hpp $(SRC)/Fixed_enemy.cpp $(SRC)/Fixed_enemy.hpp $(SRC)/Power.cpp $(SRC)/Power.hpp $(SRC)/consts.hpp
	$(CC) -c $(SRC)/Game.cpp -o $(BUILD)/Game.o

$(BUILD)/Enemy.o: $(SRC)/Enemy.cpp $(SRC)/Enemy.hpp $(SRC)/Bullet.cpp $(SRC)/Bullet.hpp $(SRC)/Object.cpp $(SRC)/Object.hpp $(SRC)/consts.hpp
	$(CC) -c $(SRC)/Enemy.cpp -o $(BUILD)/Enemy.o

$(BUILD)/Fixed_enemy.o: $(SRC)/Fixed_enemy.hpp $(SRC)/Fixed_enemy.cpp $(SRC)/Enemy.hpp $(SRC)/Enemy.cpp $(SRC)/consts.hpp
	$(CC) -c $(SRC)/Fixed_enemy.cpp -o $(BUILD)/Fixed_enemy.o

$(BUILD)/Moving_enemy.o: $(SRC)/Moving_enemy.hpp $(SRC)/Moving_enemy.cpp $(SRC)/Enemy.hpp $(SRC)/Enemy.cpp $(SRC)/consts.hpp
	$(CC) -c $(SRC)/Moving_enemy.cpp -o $(BUILD)/Moving_enemy.o

$(BUILD)/Object.o: $(SRC)/Object.hpp $(SRC)/Object.cpp 
	$(CC) -c $(SRC)/Object.cpp -o $(BUILD)/Object.o

$(BUILD)/Player.o: $(SRC)/Player.hpp $(SRC)/Player.cpp $(SRC)/Object.cpp $(SRC)/Object.hpp $(SRC)/Bullet.hpp $(SRC)/Bullet.cpp $(SRC)/consts.hpp
	$(CC) -c $(SRC)/Player.cpp -o $(BUILD)/Player.o

$(BUILD)/Hostage.o: $(SRC)/Hostage.hpp $(SRC)/Hostage.cpp $(SRC)/Object.hpp $(SRC)/Object.cpp $(SRC)/consts.hpp
	$(CC) -c $(SRC)/Hostage.cpp -o $(BUILD)/Hostage.o

$(BUILD)/Power.o: $(SRC)/Power.cpp $(SRC)/Power.hpp $(SRC)/Object.cpp $(SRC)/Object.hpp $(SRC)/consts.hpp
	$(CC) -c $(SRC)/Power.cpp -o $(BUILD)/Power.o

$(BUILD)/rsdl.o: $(SRC)/rsdl.cpp $(SRC)/rsdl.hpp
	$(CC) -c $(SRC)/rsdl.cpp -o $(BUILD)/rsdl.o

clean:
	rm $(BUILD)/*.o
