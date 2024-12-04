#include "Vector2.h"
#include <cassert>

int main() {
    Vector2 v1(3.0f, 4.0f), v2(1.0f, 2.0f);
    Vector2 v3;

    v3 = v1 * 2.0f;
    assert(v3.x == 6.0f && v3.y == 8.0f);

    v3 = 2.0f * v1;
    assert(v3.x == 6.0f && v3.y == 8.0f);

    v1 *= 2.0f;
    assert(v1.x == 6.0f && v1.y == 8.0f);

    v3 = v1 / 2.0f;
    assert(v3.x == 3.0f && v3.y == 4.0f);

    v1 /= 2.0f;
    assert(v1.x == 3.0f && v1.y == 4.0f);

    v3 = v1 + v2;
    assert(v3.x == 4.0f && v3.y == 6.0f);

    v3 = v1 - v2;
    assert(v3.x == 2.0f && v3.y == 2.0f);

    v1 += v2;
    assert(v1.x == 4.0f && v1.y == 6.0f);

    v1 = (v1 += v2) += v2;
    assert(v1.x == 6.0f && v1.y == 10.0f);

    v1 -= v2;
    assert(v1.x == 5.0f && v1.y == 8.0f);

    assert(v1[0] == 5.0f && v1[1] == 8.0f);
    v1[0] = 3.0f;
    v1[1] = 6.0f;
    assert(v1.x == 3.0f && v1.y == 6.0f);

    std::cout << "v1: " << v1 << std::endl;
    std::cout << "All tests passed!" << std::endl;

    return 0;
}