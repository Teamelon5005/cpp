#include <iostream>
#include <cassert>
#include <string>

enum class Portrait { Lenin, Washington, Hitler };
enum class LightBulbColor { Blue, White, Red };
enum class Wire { Red, Yellow, Green };

struct Bomb { Portrait portrait; LightBulbColor lightBulbColor; bool switchState; int dialValue; };

int getColorValue(LightBulbColor color, Portrait portrait) {
    int totalColors = 3;
    if (portrait == Portrait::Hitler) {
        color = static_cast<LightBulbColor>((static_cast<int>(color) + 1 + totalColors) % totalColors);
    }

    switch (color) {
    case LightBulbColor::Blue:  return 11;
    case LightBulbColor::White: return 15;
    case LightBulbColor::Red:   return 35;
    }

    return -1;
}

Wire shiftWire(Wire wire, int shift) {
    int totalWires = 3;
    return static_cast<Wire>((static_cast<int>(wire) + shift + totalWires) % totalWires);
}

std::string wireToString(Wire wire) {
    switch (wire) {
    case Wire::Red:    return "Red";
    case Wire::Yellow: return "Yellow";
    case Wire::Green:  return "Green";
    }
    return "";
}

Wire determineWireToCut(Bomb bomb) {
    if (bomb.portrait == Portrait::Lenin) {
        return static_cast<Wire>(-1);
    }

    int colorValue = getColorValue(bomb.lightBulbColor, bomb.portrait);
    Wire wireToCut;

    if (bomb.dialValue < colorValue) {
        wireToCut = Wire::Red;
    }
    else if (bomb.dialValue == colorValue) {
        wireToCut = Wire::Green;
    }
    else {
        wireToCut = Wire::Yellow;
    }

    if (bomb.switchState) {
        wireToCut = shiftWire(wireToCut, -1);
    }

    if (bomb.dialValue % 4 == 0) {
        wireToCut = shiftWire(wireToCut, bomb.dialValue / 4);
    }

    return wireToCut;
}

int main() {
    assert(determineWireToCut(Bomb{ Portrait::Lenin, LightBulbColor::Blue, false, 10 }) == static_cast<Wire>(-1));
    assert(determineWireToCut(Bomb{ Portrait::Washington, LightBulbColor::Blue, false, 10 }) == Wire::Red);
    assert(determineWireToCut(Bomb{ Portrait::Hitler, LightBulbColor::White, false, 35 }) == Wire::Green);
    assert(determineWireToCut(Bomb{ Portrait::Hitler, LightBulbColor::Red, true, 28 }) == Wire::Yellow);
    assert(determineWireToCut(Bomb{ Portrait::Washington, LightBulbColor::Blue, false, 8 }) == Wire::Green);

    std::cout << "All test cases passed!" << std::endl;

    int portraitInput, bulbColorInput, switchInput, dialInput;
    std::cout << "Enter portrait (0: Lenin, 1: Washington, 2: Hitler): ";
    std::cin >> portraitInput;
    std::cout << "Enter light bulb color (0: Blue, 1: White, 2: Red): ";
    std::cin >> bulbColorInput;
    std::cout << "Enter switch state (0: Off, 1: On): ";
    std::cin >> switchInput;
    std::cout << "Enter dial value (1-100): ";
    std::cin >> dialInput;

    if (portraitInput == 0)
        std::cout << "Do not cut any wire" << std::endl;
    else
        std::cout << "Cut the " + wireToString(determineWireToCut(Bomb{ static_cast<Portrait>(portraitInput), static_cast<LightBulbColor>(bulbColorInput), static_cast<bool>(switchInput), dialInput })) + " wire" << std::endl;

    return 0;
}
