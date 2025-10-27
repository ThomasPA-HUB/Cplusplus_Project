#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

int w, h;

struct Point
{
    int x, y;
};

// Directions : haut, bas, droite, gauche
vector<Point> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

// Convertit une profondeur en caractère (0–9, A–Z, etc.)
char depthToChar(int depth)
{
    if (depth < 10)
        return '0' + depth;
    return 'A' + depth - 10;
}

// Parcours BFS avec wrap-around
void bfs(int startX, int startY, vector<vector<char>> &MAP)
{
    queue<Point> q;
    queue<Point> tempQ;
    q.push({startX, startY});

    int depth = 0;

    while (!q.empty())
    {
        Point current = q.front();
        q.pop();

        if (MAP[current.y][current.x] == '.')
        {
            MAP[current.y][current.x] = depthToChar(depth);

            for (const Point &d : dir) // d peut avoir (1, 0)
            {
                int x = current.x + d.x; //ex : (3, 2) => (4, 2)
                int y = current.y + d.y;

                // Wrap-around (rebouclage sur les bords)
                if (x < 0)
                    x = w - 1; // si on sort à gauche, on revient a la dernière colonne
                else if (x >= w)
                    x = 0; // si x devient w, (on sort à droite), on revient à 0 
/*One line : 
*                x = x < 0 ? w - 1 : ( x >= w ? 0 : x);
*/ 
                if (y < 0)
                    y = h - 1;
                else if (y >= h)
                    y = 0;
/*
*               y = y : 0 ? h - 1 : ( y >= h ? 0 : y);
*/
                tempQ.push({x, y});
            }
        }

        // Si on a fini tous les points du niveau courant, on passe au suivant
        if (q.empty())
        {
            depth++;
            swap(q, tempQ);
        }
    }
}

int main()
{
    cin >> w >> h;
    cin.ignore();

    vector<vector<char>> MAP(h, vector<char>(w)); //solution idiomatique
    Point start;

    // Lecture de la carte
    for (int i = 0; i < h; i++)
    {
        string row;
        getline(cin, row);

        for (int j = 0; j < w; j++)
        {
            MAP[i][j] = row[j];
            if (row[j] == 'S')
            {
                start = {j, i};
                MAP[i][j] = '.'; // On remplace S par un point pour le BFS
            }
        }
    }

    bfs(start.x, start.y, MAP);

    // Affichage de la carte modifiée
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
            cout << MAP[i][j];
        cout << '\n';
    }

    return 0;
}
