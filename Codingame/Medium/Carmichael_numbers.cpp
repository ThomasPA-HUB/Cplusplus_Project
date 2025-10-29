#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

 vector<int> primeFactor(int n)
 {
    vector<int> factors;
    int num = n;
    for(int i = 2; i <= num; i++)
    {
        //si facteur, on rentre
        if(num%i==0)
        {
            factors.push_back(i);
            int count = 0;

            //compter la puissance de i
            while(num%i==0)
            {
                num/=i;
                count++;
                if(count>1)
                    return{-1};
            }
        }
    }
    if(num>1)
    {
        factors.push_back(num);
    }
    return factors;
 }

 bool IsCarmichael(int n)
 {
    if(n<3) return false;

    //vérifier si premier
    for(int i = 2; i<=sqrt(n); ++i)
        if(n%i==0)
            goto composite;
    return false; // si aucune division -> premier -> not Carmichael

    composite:
        vector<int> p = primeFactor(n);

    if(p.size()==0 || p[0] == -1)
    {
        return false; //possède un facteur carré
    }
    int n_minus_1 = n - 1;
    for(int x : p)
    {    
        if((n_minus_1%( x - 1)) != 0)
            return false;
    }   
    return true;
 }

int main()
{
    int n;
    cin >> n; cin.ignore();
    if(IsCarmichael(n))
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;
}
