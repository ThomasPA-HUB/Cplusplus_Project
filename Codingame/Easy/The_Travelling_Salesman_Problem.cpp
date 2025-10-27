#include <iostream>
#include <vector>
#include <cmath>
#include <cfloat>

using namespace std;

double DistanceCity(int x1, int y1, int x2, int y2)
{
    return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}

struct Coordonnate
{
    int x, y;
    Coordonnate() : x(0), y(0) {}
    Coordonnate(int _x, int _y) : x(_x), y(_y) {}
};

int main()
{
    int n;
    cin >> n; cin.ignore();

    if (n == 0) {
        cout << 0 << endl;
        return 0;
    }

    vector<Coordonnate> Cities;
    Cities.reserve(n);

    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y; cin.ignore();
        Cities.emplace_back(x, y);
    }

    // Prendre la première ville comme départ
    Coordonnate startVille = Cities.front();
    Cities.erase(Cities.begin());

    Coordonnate currentNode = startVille;
  double totalD = 0;

while (!Cities.empty())
{
    double minD = DBL_MAX;
    int minIndex = -1;

    for (int i = 0; i < (int)Cities.size(); i++)
    {
        double d = DistanceCity(Cities[i].x, Cities[i].y, currentNode.x, currentNode.y);

        if (d < minD)
        {
            minD = d;
            minIndex = i;
        }
    }

    totalD += minD;
    currentNode = Cities[minIndex];
    Cities.erase(Cities.begin() + minIndex);
}

totalD += DistanceCity(currentNode.x, currentNode.y, startVille.x, startVille.y);
cout << round(totalD) << endl; // <-- arrondi **final**
}

