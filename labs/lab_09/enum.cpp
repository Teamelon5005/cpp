#include <iostream>
#include <cassert>
#include <string>

enum class Portrait { Lenin, Washington, Hitler };
enum class LightBulbColor { Blue, White, Red };
enum class Wire { Red, Yellow, Green };
bool switchState = 1;

int getColorValue(LightBulbColor color, Portrait portrait) {
    switch (color) {
    case LightBulbColor::Blue:  return portrait == Portrait::Hitler ? 15 : 11;
    case LightBulbColor::White: return portrait == Portrait::Hitler ? 35 : 15;
    case LightBulbColor::Red:   return portrait == Portrait::Hitler ? 11 : 35;
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

std::string determineWireToCut(Portrait portrait, LightBulbColor bulbColor, bool toggleSwitch, int dialValue) {
    if (portrait == Portrait::Lenin) {
        return "Do not cut any wire";
    }

    int colorValue = getColorValue(bulbColor, portrait);
    Wire wireToCut;

    if (dialValue < colorValue) {
        wireToCut = Wire::Red;
    }
    else if (dialValue == colorValue) {
        wireToCut = Wire::Green;
    }
    else {
        wireToCut = Wire::Yellow;
    }

    if (toggleSwitch) {
        wireToCut = shiftWire(wireToCut, -1);
    }

    if (dialValue % 4 == 0) {
        wireToCut = shiftWire(wireToCut, dialValue / 4);
    }

    return "Cut the " + wireToString(wireToCut) + " wire";
}

int main() {
    assert(determineWireToCut(Portrait::Lenin, LightBulbColor::Blue, !switchState, 10) == "Do not cut any wire");
    assert(determineWireToCut(Portrait::Washington, LightBulbColor::Blue, !switchState, 10) == "Cut the Red wire");
    assert(determineWireToCut(Portrait::Hitler, LightBulbColor::White, !switchState, 35) == "Cut the Green wire");
    assert(determineWireToCut(Portrait::Hitler, LightBulbColor::Red, switchState, 28) == "Cut the Yellow wire");
    assert(determineWireToCut(Portrait::Washington, LightBulbColor::Blue, !switchState, 8) == "Cut the Green wire");

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

    std::cout << determineWireToCut(static_cast<Portrait>(portraitInput), static_cast<LightBulbColor>(bulbColorInput), static_cast<bool>(switchInput), dialInput) << std::endl;

    return 0;
}