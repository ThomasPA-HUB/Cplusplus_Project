#include <cstddef>
#include <functional>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

string b64 = "0123456789ABCDEFGH";
int base;

string convertFromDecimalToAnyBase(int n)
{
    string numbers = "";
    while (n != 0)
    {
        int reste = n % base;
        n = (n - reste) / base;
        numbers += b64[reste];
    }
    reverse(numbers.begin(), numbers.end());
    return numbers;
}

class Divider
{
  public:
    int nBase10;
    string nBase;
    Divider(int n)
    {
        nBase10 = n;
        nBase = convertFromDecimalToAnyBase(n);
    }
};

vector<Divider> dividers;


// Convert to Decimal
// If A => iof = 10,
int convertFromAnyBaseToDecimal(string n)
{
    int value = 0;
    reverse(n.begin(), n.end());
    for (int i = 0; i < n.size(); i++)
    {
        int iOf = b64.find(n[i]);
        value += iOf * pow(base, i);
    }
    return value;
}

bool Buzzle (int n)
{
string strValue = convertFromDecimalToAnyBase(n);
    for (Divider divider : dividers)
    {
        if (n % divider.nBase10 == 0)
        {
            return true;
        }
        if (strValue.back() == divider.nBase.back())
        {
            return true;
        }
    }
    if (strValue.size() != 1)
    {
        int _n = 0;
        for (int i = 0; i < strValue.size(); i++)
        {
            int index = b64.find(strValue[i]);
            _n += index;
        }
        return Buzzle(_n);
    }
    return false;
   /* bool result = false;
    int sum = 0;
    //int mult = 0;
    std::string s = std::to_string(std::abs(Test));

    for (char c : s)
    {   sum += c - '0'; // convertit le caractère en chiffre
    }
    if(Test == 572)
       cout<<mult<<endl;
    return Test % k == 0 || Test % 10 == k || sum % k == 0 || sum % 10 == k;*/// || mult % 10 == 0;
}

int main()
{
    int a;
    int b;
    cin >> base >> a >> b;
    cin.ignore();
    int k;
    cin >> k;
    cin.ignore();
    for (int i = 0; i < k; i++)
    {
        int num;
        cin >> num;
        cin.ignore();
        dividers.push_back({num});
    }

    for (int i = a; i <= b; i++)
    {
        if (Buzzle(i))
        {
            cout << "Buzzle\n";
        }
        else
        {
            cout << i << "\n";
        }
    }
}
