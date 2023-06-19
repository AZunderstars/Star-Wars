#include "Game.hpp"
#include <fstream>

using namespace std;

int main(int argc, char *argv[])
{
    Game starwars;
    ifstream map = ifstream(argv[1]);
    starwars.initialize(map);
    starwars.intro();
    starwars.run(map);
    return 0;
}
