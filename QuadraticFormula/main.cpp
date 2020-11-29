// Eric Bollar
// September 3, 2020

#include <iostream>
#include <math.h>
#include <string>

using namespace std;

string quadraticFormula(float a, float b, float c) {
    float top = pow(b, 2) - 4*a*c;
    if (top >= 0) {
        float out1 = (-b + sqrt(top)) / (2*a);
        float out2 = (-b - sqrt(top)) / (2*a);
        return "" + to_string(out1) + " & " + to_string(out2);
    } else {
        top *= -1;
        float num = -b / (2*a);
        float imag = sqrt(top) / (2*a);
        return "x = " + to_string(num) + " + " + to_string(imag) + "i\nx = " + to_string(num) + " - " + to_string(imag) + "i";
    }
}

int main() {
    float a, b, c;
    cout << "Quadratic Formula Program" << endl;
    cout << "ax² + bx + c = 0" << endl;
    cout << "Enter value for a: ";
    cin >> a;
    cout << "Enter value for b: ";
    cin >> b;
    cout << "Enter value for c: ";
    cin >> c;
    cout << quadraticFormula(a, b, c);

    return 0;
}