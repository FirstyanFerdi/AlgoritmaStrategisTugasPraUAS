#include <iostream>
#include <algorithm> // untuk sort
using namespace std;

// Fungsi untuk menghitung dan menampilkan urutan optimal & Minimum Retrieval Time
void findOrderMRT(int L[], int n) {
    // Urutkan berdasarkan panjang program secara menaik
    sort(L, L + n);

    cout << "Urutan optimal penyimpanan program di tape adalah:\n";
    for (int i = 0; i < n; i++)
        cout << "Program " << i + 1 << " (waktu: " << L[i] << ")\n";

    // Hitung MRT (Minimum Retrieval Time)
    double MRT = 0;
    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = 0; j <= i; j++)
            sum += L[j];
        MRT += sum;
    }

    MRT /= n;

    cout << "\nMinimum Retrieval Time (MRT) adalah: " << MRT << endl;
}

int main() {
    int n;

    cout << "\n================= Algoritma Minimasi Waktu =================\n";
    cout << "NAMA  : FIRSTYAN FERDI FIRDAUS\n";
    cout << "NIM   : 23533781\n";
    cout << "KELAS : 4A\n";
    cout << "PRODI : Teknik Informatika\n";
    cout << "=============================================================\n\n";

    cout << "Masukkan jumlah program yang ingin disimpan di tape: ";
    cin >> n;

    while (n <= 0) {
        cout << "Jumlah program harus lebih dari 0. Masukkan lagi: ";
        cin >> n;
    }

    int* L = new int[n]; // alokasi dinamis agar bisa fleksibel

    cout << "Masukkan waktu eksekusi tiap program:\n";
    for (int i = 0; i < n; i++) {
        cout << "Program " << i + 1 << ": ";
        cin >> L[i];
        while (L[i] <= 0) {
            cout << "Waktu harus positif. Masukkan ulang Program " << i + 1 << ": ";
            cin >> L[i];
        }
    }

    // Panggil fungsi untuk proses dan output
    findOrderMRT(L, n);

    delete[] L; // bebaskan memori
    return 0;
}
