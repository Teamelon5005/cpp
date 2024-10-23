#include <iostream>
#include <string_view>
#include <cassert>

std::string_view secondWord(std::string_view str)
{
    size_t firstSpacePos = str.find(' ');

    if (firstSpacePos == std::string_view::npos)
        return "";

    size_t secondWordStart = str.find_first_not_of(' ', firstSpacePos);

    if (secondWordStart == std::string_view::npos)
        return "";

    size_t nextSpacePos = str.find(' ', secondWordStart);

    if (nextSpacePos == std::string_view::npos)
        return str.substr(secondWordStart);

    return str.substr(secondWordStart, nextSpacePos - secondWordStart);
}

int main()
{
    assert(secondWord("Hello world") == "world");

    assert(secondWord("Hello my dear") == "my");

    assert(secondWord("") == "");

    assert(secondWord(" ") == "");

    assert(secondWord(" a ") == "a");

    assert(secondWord("a  ") == "");

    assert(secondWord("a  b") == ""); // It looks like this example return false. I dunno if it was intended but from my humble perspective this string should return something like "b" | assert(secondWord("a  b") == "b")

    std::cout << "All tests passed successfully!" << std::endl;
    return 0;
}