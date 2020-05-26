#include "engine/display.h"
#include "game/hook/GameEngine.h"

using namespace std;

int main() {
    Display::createDisplay(800, 600, "SpaceRPG", new GameEngine());
    return 0;
}
