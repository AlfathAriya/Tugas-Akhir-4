#include <iostream>
using namespace std;

const int MAX = 1000;
int q[MAX], frontIdx = -1, rearIdx = -1;

bool isEmpty() {
    return frontIdx == -1;
}

void enqueue() {
    int tiket;
    cout << "Masukkan nomor tiket: ";
    cin >> tiket;

    if (isEmpty()) frontIdx = 0;
    rearIdx++;
    q[rearIdx] = tiket;

    cout << "Tiket nomor " << tiket << " ditambahkan ke antrian.\n";
}

void dequeue() {
    if (isEmpty()) {
        cout << "Antrian kosong!\n";
        return;
    }
    cout << "Tiket nomor " << q[frontIdx++] << " telah dihapus.\n";
    if (frontIdx > rearIdx) frontIdx = rearIdx = -1;
}

void display() {
    if (isEmpty()) {
        cout << "Antrian kosong.\n";
        return;
    }
    cout << "Isi antrian: ";
    for (int i = frontIdx; i <= rearIdx; i++)
        cout << q[i] << " ";
    cout << "\n";
}

int main() {
    cout << "=== SISTEM ANTRIAN TIKET ===";

    int pilih;
    do {
        cout << "\n1. Tambah Tiket\n2. Hapus Tiket\n3. Lihat Antrian\n4. Keluar\nPilih: ";
        cin >> pilih;

        if (pilih == 1) enqueue();
        else if (pilih == 2) dequeue();
        else if (pilih == 3) display();
    } while (pilih != 4);

    cout << "Terima kasih\n";
}
