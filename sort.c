#include<stdio.h>
#include<stdlib.h>
#include<time.h>

/* Print */
void print(int* ref, int size) {
    for (int i = 0; i < size; i++) {
        printf(" %i", ref[i]);
    }
    printf("\n");
}

/* Insert Sort */
void insertSort(int* Ref) {
    for ( int j = 1; j < sizeof(Ref); j++) {
        int aux = Ref[j];
        int i = j-1;
        while (i>= 1 && Ref[i] >= aux)
        {
            Ref[i+1] = Ref[i];
            i = i-1;
        }
        Ref[i+1] = aux;
    }
}

/* Select Sort */
void selectSort(int* Ref) {
    for (int j = 0; j < sizeof(Ref) - 1; j++) {
        int m = j;
        for (int i = j + 1; i < sizeof(Ref); i++) {
            if(Ref[i] < Ref[m]) {
                m = i;
            }
        }
        int temp = Ref[j];
        Ref[j] = Ref[m];
        Ref[m] = temp;
    }
}

/* Merge Sort */
void interchange(int* Ref, int p, int q, int r) {
    int i = q-p+1;
    printf("interchange01\n");
    int j = r-q;
    int* L = malloc(sizeof(int)*(i));
    int* R = malloc(sizeof(int)*(j));
    printf("interchange_FOR_L\n");
    for ( i = 1; i < (q-p+1); i++) {
        L[i] = Ref[p+i-1];
    }
    printf("interchange_FOR_R\n");
    for ( j = 0; j < r-q; j++) {
        R[j] = Ref[q+j];
    }
    print(L,(i));
    print(R,(j));
/*
    i = 0;
    j = 0;
    printf("interchange_FOR_K\n");
    for (int k = 0; k < r; k++) {
        if (L[i] <= R[j]) {
            Ref[k] = L[i];
            i = i++;
        } else {
            Ref[k] = R[j];
            j = j++;
        }
    }*/
    free(L);
    free(R);
}

void mergeSort(int* Ref, int p, int r) {
    if (p < r) {
        int q = (p + r)/2;
        mergeSort(Ref, p, q);
        mergeSort(Ref, q+1, r);
        interchange(Ref, p, q, r);
    }    
}

/* Heap Sort */
void heapmaxffy(int *Ref, int m ,int i) {
    int maior;
    int l = 2*i;
    int r = 2*i +1;
    if (l < m && Ref[l] > Ref[i]) {
        maior = l;
    } else {
        maior = i;
    }
    if (r <= m && Ref[r] > Ref[maior]) {
        maior = r;
    }
    if (maior != i) {
        int aux = Ref[i];
        Ref[i] = Ref[maior];
        Ref[maior] = aux;
        heapmaxffy(Ref, m, maior);
    }
}

void heapmaxbuild(int *Ref, int n) {
    int i;
    for ( i = n/2; i >= 0; i--) {
        heapmaxffy(Ref, n , i);
    }
}

void heapsort(int *Ref, int n) {
    int m, i, aux;
    m = n-1;
    heapmaxbuild(Ref, m);
    for ( i = n-1; i >= 1; i--)
    {
        aux = Ref[0];
        Ref[0] = Ref[i];
        Ref[i] = aux;
        m = m-1;
        heapmaxffy(Ref, m, 0);
    }
}

int main(int argc, char const *argv[]) {
    int size = 1000;
    int* vect;

    clock_t start, end;
    double cpu_time_used;
/*
// Teste por Insertion
    start = clock();    
    vect = malloc(sizeof(int)*size);
    for (int i = 0; i < size; i++) {
        vect[i] = size - i;
    }
   
    printf("Ordenando por insertion...\n");
    insertSort(vect);
    end = clock();
    cpu_time_used = ((double)(end-start))/CLOCKS_PER_SEC;
    printf("Insertion Sort:\tTempo consumido: %d\n", cpu_time_used);
    free(vect);
    start = end = 0;

// Teste por Selection
    start = clock();    
    vect = malloc(sizeof(int)*size);
    for (int i = 0; i < size; i++) {
        vect[i] = size - i;
    }

    printf("Ordenando por selection...\n");
    selectSort(vect);
    end = clock();
    cpu_time_used = ((double)(end-start))/CLOCKS_PER_SEC;
    printf("Select Sort:\tTempo consumido: %d\n", cpu_time_used);
    free(vect);
    start = end = 0;*/

// Teste por Mergesort
    start = clock();    
    vect = malloc(sizeof(int)*size);
    for (int i = 0; i < size; i++) {
        vect[i] = size - i;
    }

    printf("Ordenando por mergesort...\n");
    mergeSort(vect, 0, size);
    end = clock();
    cpu_time_used = ((double)(end-start))/CLOCKS_PER_SEC;
    printf("Merge Sort:\tTempo consumido: %d\n", cpu_time_used);
    free(vect);
    start = end = 0;
/*
// Teste por Heapsort
    start = clock();    
    vect = malloc(sizeof(int)*size);
    for (int i = 0; i < size; i++) {
        vect[i] = size - i;
    }
    
    printf("Ordenando por heapsort...\n");
    heapsort(vect, size);
    end = clock();
    cpu_time_used = ((double)(end-start))/CLOCKS_PER_SEC;
    printf("Heap Sort:\tTempo consumido: %d\n", cpu_time_used);
    free(vect);
    start = end = 0;
*/

    return 0;
}
