#include <iostream>
using namespace std;

// Fungsi untuk menggabungkan dua subarray L dan M ke dalam arr
void merge(int arr[], int p, int q, int r) {
    int n1 = q - p + 1;
    int n2 = r - q;

    int L[n1], M[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[p + i];
    for (int j = 0; j < n2; j++)
        M[j] = arr[q + 1 + j];

    int i = 0, j = 0, k = p;

    while (i < n1 && j < n2) {
        if (L[i] <= M[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = M[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = M[j];
        j++;
        k++;
    }
}

// Fungsi untuk membagi dan mengurutkan array
void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}

// Fungsi untuk mencetak array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

// Fungsi utama
int main() {
    int size;

    cout << "==================== Algoritma Merge Sort ===================\n";
    cout << "NAMA  : FIRSTYAN FERDI FIRDAUS\n";
    cout << "NIM   : 23533781\n";
    cout << "KELAS : 4A\n";
    cout << "PRODI : Teknik Informatika\n";
    cout << "=============================================================\n\n";

    cout << "Masukkan jumlah elemen array: ";
    cin >> size;

    while (size <= 0) {
        cout << "Jumlah elemen harus lebih dari 0. Masukkan ulang: ";
        cin >> size;
    }

    int arr[size];
    cout << "Masukkan elemen-elemen array:\n";
    for (int i = 0; i < size; i++) {
        cout << "Elemen ke-" << i + 1 << ": ";
        cin >> arr[i];
    }

    mergeSort(arr, 0, size - 1);

    cout << "\nArray yang sudah diurutkan:\n";
    printArray(arr, size);

    return 0;
}
