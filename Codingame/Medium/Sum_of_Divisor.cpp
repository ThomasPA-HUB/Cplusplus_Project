#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


int main()
{
    vector<int> p ;
    long long  n;
    cin >> n; cin.ignore();

    long long result = 0;

    long long i = 1;
    while (i <= n) {
        long long q = n / i;  // la valeur du quotient
        long long last = n / q; // jusqu'où le quotient reste le même
        long long count = last - i + 1;
        result += q * (i + last) * count / 2; // somme arithmétique

        i = last + 1;
    }

     cout <<result<<endl;
}
