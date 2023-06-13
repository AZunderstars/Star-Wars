CC := g++
FLAGS += -l SDL2 -l SDL2_image -l SDL2_ttf -l SDL2_mixer
BUILD += ./build
all: starwars.out

starwars.out: main.o Game.o Bullet.o Enemy.o Fixed_enemy.o Object.o Player.o Moving_enemy.o Hostage.o Power.o rsdl.o
	$(CC) $(BUILD)/main.o $(BUILD)/Game.o $(BUILD)/Bullet.o $(BUILD)/Enemy.o $(BUILD)/Fixed_enemy.o $(BUILD)/Object.o $(BUILD)/Player.o $(BUILD)/Moving_enemy.o $(BUILD)/Hostage.o $(BUILD)/Power.o $(BUILD)/rsdl.o $(FLAGS) -o starwars.out

main.o: main.cpp
	$(CC) -c main.cpp -o $(BUILD)/main.o

Bullet.o: Bullet.hpp Bullet.cpp Object.cpp Object.hpp consts.hpp
	$(CC) -c Bullet.cpp -o $(BUILD)/Bullet.o

Game.o: Game.hpp Game.cpp Player.cpp Player.hpp Bullet.cpp Bullet.hpp Fixed_enemy.cpp Fixed_enemy.hpp Power.cpp Power.hpp consts.hpp
	$(CC) -c Game.cpp -o $(BUILD)/Game.o

Enemy.o: Enemy.cpp Enemy.hpp Bullet.cpp Bullet.hpp Object.cpp Object.hpp consts.hpp
	$(CC) -c Enemy.cpp -o $(BUILD)/Enemy.o

Fixed_enemy.o: Fixed_enemy.hpp Fixed_enemy.cpp Enemy.hpp Enemy.cpp consts.hpp
	$(CC) -c Fixed_enemy.cpp -o $(BUILD)/Fixed_enemy.o

Moving_enemy.o: Moving_enemy.hpp Moving_enemy.cpp Enemy.hpp Enemy.cpp consts.hpp
	$(CC) -c Moving_enemy.cpp -o $(BUILD)/Moving_enemy.o

Object.o: Object.hpp Object.cpp 
	$(CC) -c Object.cpp -o $(BUILD)/Object.o

Player.o: Player.hpp Player.cpp Object.cpp Object.hpp Bullet.hpp Bullet.cpp consts.hpp
	$(CC) -c Player.cpp -o $(BUILD)/Player.o

Hostage.o: Hostage.hpp Hostage.cpp Object.hpp Object.cpp consts.hpp
	$(CC) -c Hostage.cpp -o $(BUILD)/Hostage.o

Power.o: Power.cpp Power.hpp Object.cpp Object.hpp consts.hpp
	$(CC) -c Power.cpp -o $(BUILD)/Power.o

rsdl.o: rsdl.cpp rsdl.hpp
	$(CC) -c rsdl.cpp -o $(BUILD)/rsdl.o
clean:
	rm $(BUILD)/*.o