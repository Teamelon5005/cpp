#include <iostream>
#include <string_view>
#include <cassert>

size_t findFirstSpace(std::string_view string)
{
    for(size_t i = 0; i < string.length(); i++)
    {
        if (string[i] == ' ')
        {
            return i;
        }
    }
    return size_t(-1);
}

std::string_view secondWord(std::string_view str)
{
    {
        size_t index = findFirstSpace(str);
        if(index == size_t(-1))
            return "";
        str = str.substr(index + 1);
    }

    {
        size_t index = findFirstSpace(str);
        if(index == size_t(-1))
            return "";
        str = {&str[0], index};
    }

    return str;
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
