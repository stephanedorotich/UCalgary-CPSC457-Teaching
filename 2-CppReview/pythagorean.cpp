// Author: Xining Chen, Stéphane Dorotich
// CPSC 457
// Use freely

// pass by reference using pointers and cmath
#include <iostream>
#include <cmath>

// pass by value
double pyth(double a, double b)
{
    double c = sqrt(pow(a, 2) + pow(b, 2));
    a = 0;
    b = 0;
    return c;
}

// pass by const reference
double pyth2(const double & a, const double & b)
{
    double c = sqrt(pow(a, 2) + pow(b, 2));
    a = 0;
    b = 0;
    return c;
}

// pass by reference
double pyth3(double & a, double & b)
{
    double c = sqrt(pow(a, 2) + pow(b, 2));
    a = 0;
    b = 0;
    return c;
}

void usage_error(char * progName)
{
    std::cout << "Usage:\n\t" << progName << " a b";
    std::cout << "\t\tWhere a and b are real numbers\n";
    exit(-1);
}

int main(int argc, char* argv[])
{
    if (argc != 3) usage_error(argv[0]);

    double v1, v2;

    try {
        v1 = std::stod(argv[1]);     // convert string to double
        v2 = std::stod(argv[2]);
    } catch (const std::invalid_argument & ex) {
        usage_error(argv[0]);
    }

    // pass by value
    double v3 = pyth(v1, v2);
    std::cout << "a = " << v1 << " ; b = " << v2 << " ; c = " << v3 << std::endl;

    // pass by const reference
    double v4 = pyth2(v1, v2);
    std::cout << "a = " << v1 << " ; b = " << v2 << " ; c = " << v4 << std::endl;

    // pass by reference
    double v5 = pyth3(v1, v2);
    std::cout << "a = " << v1 << " ; b = " << v2 << " ; c = " << v5 << std::endl;

    return 0;
}
