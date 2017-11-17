#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct apskr
{
    string aps;
    int sk;
    int kiek;
};

apskr A[60], B[60];

void nuskaitymas();
void atrinkti();
int yra(apskr C[], int ka, string pav);
void isvedimas();


int k, m=0;


int main()
{
    int kiek2;
    nuskaitymas();
    atrinkti();
    for(int i=0; i<m; i++)
        if (B[i].sk == B[0].sk) kiek2++;
    return 0;
}

void nuskaitymas()
{
    char eil[20];
    ifstream fd("U2.txt");
    fd >> k;
    fd.ignore();
    for(int i=0; i<k; i++)
    {
        fd.get(eil,13);
        fd >> eil;
        A[i].aps = eil;  //???
        fd >> A[i].sk;
        fd.ignore();
        A[i].kiek = 1;
    }
    fd.close();
}

void atrinkti()
{
    int n;
    for(int i=0; i<k; i++)
    {
        n = yra(B, m, A[i].aps);
        if(n >= 0)
        {
            B[n].kiek++;
            if(A[i].sk > B[n].sk) B[n].sk = A[i].sk;
        }
        else
        {
            B[m] = A[i];
            m++;
        }
    }

}

int yra(apskr C[], int ka, string pav)
{
    for(int i=0; i<ka; i++)
        if(C[i].aps == pav) return i;
    return -1;
}

void isvedimas()
{
    ofstream fr("U2rez.txt");
    for(int i=0; i<m; i++)
        fr << B[i].aps << B[i].kiek << " " << B[i].sk << endl;
}
