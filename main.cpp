#include "Game.hpp"
#include <fstream>

using namespace std;

int main(int argc, char *argv[])
{
    fstream fs;
    fs.open("./test.txt", std::fstream::in | std::fstream::out | std::fstream::app);
    fs << " test content";
    fs.close();
    Game starwars;
    ifstream map = ifstream(argv[1]);
    starwars.initialize(map);
    starwars.intro();
    starwars.run(map);
    return 0;
}