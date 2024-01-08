#include <iostream>

#include "Point.hpp"

void printAction(std::string str) {
    std::cout << "\n\e[1;33m* \e[21m\e[34m" << str << "\e[0m\n\n";
}

void printResult(
    bool result, std::string msg, std::string onTrue, std::string onFalse) {
    std::cout << msg << ": "
              << (result ? "\e[1;32m" + onTrue + "\e[0m"
                         : "\e[1;31m" + onFalse + "\e[0m")
              << std::endl;
}

// int main() {
//     // Test case 1: Points form a triangle, point is inside the triangle
//     printAction("Test case 1: point is inside the triangle");
//     Point a(0, 0);
//     Point b(4, 0);
//     Point c(2, 4);
//     Point point(2, 2);
//     bool result = bsp(a, b, c, point);
//     std::cout << std::boolalpha << result << std::endl;
//     // printResult(result,
//     //     "After a very long reflection, we determined that the point is",
//     //     "inside the triangle", "outside the triangle");

//     // Test case 2: Points form a triangle, point is outside the triangle
//     printAction("Test case 2: point is outside the triangle");
//     Point a2(0, 0);
//     Point b2(4, 0);
//     Point c2(2, 4);
//     Point point2(5, 5);
//     bool result2 = bsp(a2, b2, c2, point2);
//     std::cout << std::boolalpha << result2 << std::endl;
//     // printResult(result2,
//     //     "I and the team of experts can confidently say that the point is",
//     //     "inside the triangle", "outside the triangle");

//     // Test case 3: Points form a line, point is on the line
//     printAction("Test case 3: point is on the line");
//     Point a3(0, 0);
//     Point b3(2, 2);
//     Point c3(4, 4);
//     Point point3(3, 3);
//     bool result3 = bsp(a3, b3, c3, point3);
//     std::cout << "After some calculations, we determined that the point is "
//               << (result3 ? "\e[1;32mon the line\e[0m"
//                           : "\e[1;31mnot on the line\e[0m")
//               << std::endl
//               << std::endl;

//     // Test case 4: Points form a line, point is not on the line
//     printAction("Test case 4: point is not on the line");
//     Point a4(0, 0);
//     Point b4(2, 2);
//     Point c4(4, 4);
//     Point point4(5, 5);
//     bool result4 = bsp(a4, b4, c4, point4);
//     std::cout << "Hours of calculations later, we determined that the point is "
//               << (!result4 ? "\e[1;32mon the line\e[0m"
//                            : "\e[1;31mnot on the line\e[0m")
//               << std::endl
//               << std::endl;

//     return 0;
// }

int main(void)
{
    Point a(0, 0), b(5, 0), c(0, 3), point(1, 1);
    std::cout << "Result : " << bsp(a, b, c, point) << " | answer : 1" << std::endl;
    Point d(0, 0), e(-5, 0), f(0, 3), point1(1, 1);
    std::cout << "Result : " << bsp(d, e, f, point1) << " | answer : 0" << std::endl;
    Point g(0, 0), h(5, 0), i(10, 3), point2(1, 1);
    std::cout << "Result : " << bsp(g, h, i, point2) << " | answer : 0" << std::endl;
    Point j(10, 0), k(15, 20), l(10, 13), point3(1, 1);
    std::cout << "Result : " << bsp(j, k, l, point3) << " | answer : 0" << std::endl;
    Point m(1, 0), n(5, 0), o(0, 3), point4(1, 1);
    std::cout << "Result : " << bsp(m, n, o, point4) << " | answer : 1" << std::endl;
    Point r(10, 0), s(15, 20), t(10, 13), point5(11, 8);
    std::cout << "Result : " << bsp(r, s, t, point5) << " | answer : 1" << std::endl;
    Point u(10, 0), v(15, 20), w(10, 13), point6(10, 0);
    std::cout << "Result : " << bsp(u, v, w, point6) << " | answer : 0" << std::endl;
    return 0;
}
