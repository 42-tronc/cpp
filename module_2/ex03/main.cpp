#include <iostream>

#include "Point.hpp"

void printAction(std::string str) {
    std::cout << "\n\e[1;33m* \e[21m\e[34m" << str << "\e[0m\n\n";
}

void printResult(bool result, std::string msg) {
    std::cout << msg
              << (result ? "\e[1;32m in the triangle\e[0m"
                         : "\e[1;31m outside the triangle\e[0m")
              << std::endl;
}

int main() {
    // Test case 1: Points form a triangle, point is inside the triangle
    printAction("Test case 1: point is inside the triangle");
    Point a(0, 0);
    Point b(4, 0);
    Point c(2, 4);
    Point point(2, 2);
    bool result = bsp(a, b, c, point);
    printResult(result,
        "After a very long reflection, we determined that the point is");

    // Test case 2: Points form a triangle, point is outside the triangle
    printAction("Test case 2: point is outside the triangle");
    Point a2(0, 0);
    Point b2(4, 0);
    Point c2(2, 4);
    Point point2(5, 5);
    bool result2 = bsp(a2, b2, c2, point2);
    // std::cout << std::boolalpha << result2 << std::endl;
    printResult(result2,
        "I and the team of experts can confidently say that the point is");

    // Test case 3: Points form a line, point is on the line
    printAction("Test case 3: point is on the line");
    Point a3(0, 0);
    Point b3(2, 2);
    Point c3(4, 4);
    Point point3(3, 3);
    bool result3 = bsp(a3, b3, c3, point3);
    printResult(
        result3, "After some calculations, we determined that the point is");

    // Test case 4: Points form a line, point is not on the line
    printAction("Test case 4: point is not on the line");
    Point a4(0, 0);
    Point b4(2, 2);
    Point c4(4, 4);
    Point point4(5, 5);
    bool result4 = bsp(a4, b4, c4, point4);
    printResult(result4,
        "Hours of calculations later, we determined that the point is");

    // Test case 5: Points form a triangle, point is on the line
    printAction("Test case 5: point is on the line of the triangle");
    Point a5(0, 0);
    Point b5(4, 0);
    Point c5(2, 4);
    Point point5(2, 0);
    bool result5 = bsp(a5, b5, c5, point5);
    printResult(result5, "You won't believe it, but the point is actually");

    // Test case 6: Points form a triangle, point is barely inside the triangle
    printAction("Test case 6: point is barely inside the triangle");
    Point a6(0, 0);
    Point b6(4, 0);
    Point c6(2, 4);
    Point point6(2, 0.01);
    bool result6 = bsp(a6, b6, c6, point6);
    printResult(result6, "We are 99% sure that the point is");

    return 0;
}
