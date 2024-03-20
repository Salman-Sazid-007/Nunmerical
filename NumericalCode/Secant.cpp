#include <bits/stdc++.h>

using namespace std;

class Secant {

    private:
        const double tolerence = 0.0001;

         double function(double x) {
            return x*x*x + x*x - 1;
        }
        /*double function(double x) {

            return (x*x*exp(-(x/2)) - 1);
        }*/

        double secant(double a, double b) {
            return ((b * function(a) - a * function(b)) / (function(a) - function(b)));
        }
    public:


        void solve() {

            double a, b;
            srand(time(0));
            while(true) {
                a = rand()%10 - 9;
                b = rand()%10;
                if(function(a) * function(b) < 0.0) {
                    break;
                }
            }

            double new_root = secant(a, b);
            double root;

            while(true) {
                cout << "\na = " << a << "   b = " << b << "   root = " << new_root << endl;
                if(function(new_root) == 0.0) {
                    root = new_root;
                    break;
                }

                if(abs(new_root - secant(new_root, a)) < tolerence) {
                    root = new_root;
                    break;
                }

                b = a;
                a = new_root;
                new_root = secant(a, b);
            }
            root = secant(root, a);
            // cout << "\na = " << a << "   b = " << b << "   root = " << root << endl;
            cout << "\n\nThe root is : " << root << endl;
        }

};

int main() {

    Secant secant;

    secant.solve();

    return 0;

}
