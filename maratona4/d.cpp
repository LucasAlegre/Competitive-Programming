#include <iostream>

using namespace std;

long int total;

void merge(long *saida, long *auxiliar, int inicio, int meio, int fim){
    int i, j, k;
    i = inicio;
    j = meio + 1;
    k = inicio;
    while(i <= meio && j <= fim){
        if(auxiliar[i] < auxiliar[j]){
            saida[k] = auxiliar[i];
            i++;
        }
        else{
            saida[k] = auxiliar[j];
            j++;
            total += meio-i+1;
        }
        k++;
    }

    while(i <= meio){
        saida[k] = auxiliar[i];
        i++;
        k++;
    }

    while(j <= fim){
        saida[k] = auxiliar[j];
        j++;
        k++;
    }
    //Copia os elementos que foram ordenados para o auxiliar
    for(int p = inicio; p <= fim; p++)
        auxiliar[p] = saida[p];
}



void mergeSort(long *saida, long *auxiliar, int inicio, int fim){
    if(inicio < fim){
        int meio = (inicio + fim) / 2;
        mergeSort(saida, auxiliar, inicio, meio);
        mergeSort(saida, auxiliar, meio + 1, fim);
        merge(saida, auxiliar, inicio, meio, fim);
    }
}

int main(){
    int N;
    int num;
    while(cin >> N && N!=0){
        long lista[N];
        long lista2[N];
        for(int i = 0; i<N; i++){
            cin >> num;
            lista[i] = num;
        }
        total = 0;
        mergeSort(lista2, lista, 0, N-1);

        cout << total << endl;
    }

    return 0;
}
