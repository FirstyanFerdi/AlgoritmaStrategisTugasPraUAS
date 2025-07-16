#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Struktur item dengan bobot, profit, dan rasio
struct Item {
    int weight;
    int profit;
    double ratio;
};

// Fungsi untuk membandingkan rasio profit per berat
bool compare(Item a, Item b) {
    return a.ratio > b.ratio;
}

int main() {
    int n = 8; // Jumlah item tetap 8
    vector<Item> items(n);
    int capacity;

    cout << "\n==================== Knapsack Problem =====================\n";
    cout << "NAMA  : FIRSTYAN FERDI FIRDAUS\n";
    cout << "NIM   : 23533781\n";
    cout << "KELAS : 4A\n";
    cout << "PRODI : Teknik Informatika\n";
    cout << "=============================================================\n\n";

    // Input bobot
    cout << "Masukkan bobot untuk " << n << " item:\n";
    for (int i = 0; i < n; i++) {
        cout << "Bobot item ke-" << i + 1 << ": ";
        cin >> items[i].weight;
    }

    // Input profit
    cout << "\nMasukkan profit untuk " << n << " item:\n";
    for (int i = 0; i < n; i++) {
        cout << "Profit item ke-" << i + 1 << ": ";
        cin >> items[i].profit;
        items[i].ratio = (double)items[i].profit / items[i].weight;
    }

    // Input kapasitas
    cout << "\nMasukkan kapasitas maksimum knapsack: ";
    cin >> capacity;

    // Urutkan berdasarkan rasio profit/weight
    sort(items.begin(), items.end(), compare);

    int totalProfit = 0;
    int totalWeight = 0;

    cout << "\nItem yang dimasukkan ke knapsack:\n";
    for (int i = 0; i < n && capacity > 0; i++) {
        if (items[i].weight <= capacity) {
            capacity -= items[i].weight;
            totalProfit += items[i].profit;
            totalWeight += items[i].weight;
            cout << "- Berat: " << items[i].weight << ", Profit: " << items[i].profit << " (100%)\n";
        }
    }

    cout << "\nTotal bobot: " << totalWeight << endl;
    cout << "Total profit maksimum (0/1 Greedy): " << totalProfit << endl;

    return 0;
}
