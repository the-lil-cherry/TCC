#include <bits/stdc++.h> 
#include "path.h"
#include "priorityQueue.h"
#include "shortestPath.h"
using namespace std;

int main(){
    cout << "oii" << endl;
    long long n,w ;
    vector < vector < long long > > weights;
    cin >> n;

    for(long long i = 0; i<n; i++){
        vector < long long>  aux;
        for(long long j = 0; j<n; j++){
            cin >> w;
            aux.push_back(w);
        }
        weights.push_back(aux);
    }
    int op;
    long long x, y;

    do{
        cin >> op;
        switch (op)
        {
        case 1:
            // Consulta do comprimento de x a y
            cin >> x; 
            cin >> y;
            break;
        
        case 2:
            // Consulta do menor caminho entre x e y
            cin >> x; 
            cin >> y;
            break;
        
        case 3:
            // Update de vertices
            cin >> x;
            break;
        
        case 4:
            // Imprime a matriz de pesos
            break;

        default:
            break;
        }

    }
    while(op!=0);


}