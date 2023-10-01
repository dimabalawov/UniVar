

#include <iostream>
#include <string>
#include "var.h"
using namespace std;

int main()
{
    var a("nip");
    var b("i");
    var c = a + b;
    c.Show();
    cout << endl;
    var d(10);
    var e("10");
    (d + e).Show();
    cout << endl;
    (e + d).Show();
    cout << endl;
    (a * b).Show();
    cout << endl;
    (a / b).Show();
    cout << endl;
    int g = 20;
    cout << g + e << endl;
    cout << (g > e) << endl;
}
