#include <iostream>
using namespace std;

const int MAX = 1000;
int q[MAX], frontIdx = -1, rearIdx = -1;

bool isEmpty() {
    return frontIdx == -1;
}

bool isFull() {
    return rearIdx == MAX - 1;
}

void enqueue() {
    if (isFull()) {
        cout << "Antrian penuh! Tidak dapat menambah tiket.\n";
        return;
    }

    int tiket;
    cout << "Masukkan nomor tiket: ";
    cin >> tiket;

    if (isEmpty()) frontIdx = 0;
    q[++rearIdx] = tiket;

    cout << "Tiket nomor " << tiket << " ditambahkan ke antrian.\n";
}

void dequeue() {
    if (isEmpty()) {
        cout << "Antrian kosong!\n";
        return;
    }

    cout << "Tiket nomor " << q[frontIdx++] << " telah dihapus.\n";

    if (frontIdx > rearIdx)
        frontIdx = rearIdx = -1;
}

void display() {
    if (isEmpty()) {
        cout << "Antrian kosong.\n";
        return;
    }

    cout << "Isi antrian: ";
    for (int i = frontIdx; i <= rearIdx; i++)
        cout << q[i] << " ";
    cout << endl;
}

void peek() {
    if (isEmpty())
        cout << "Antrian kosong.\n";
    else
        cout << "Tiket paling depan adalah nomor: " << q[frontIdx] << endl;
}

void clearQueue() {
    frontIdx = rearIdx = -1;
    cout << "Seluruh antrian telah dihapus.\n";
}

void checkFull() {
    if (isFull())
        cout << "Status: Antrian penuh.\n";
    else
        cout << "Status: Antrian belum penuh.\n";
}

int main() {
    cout << "=== SISTEM ANTRIAN TIKET KERETA ===";
    int pilih;
    do {
        cout << "\n\nPilih: 1.Tambah Tiket  2.Hapus Tiket  3.Lihat Antrian  4.Lihat Terdepan  5.Cek Penuh  6.Clear  7.Keluar\nMasukkan pilihan: ";
        cin >> pilih;

        switch (pilih) {
            case 1: enqueue(); break;
            case 2: dequeue(); break;
            case 3: display(); break;
            case 4: peek(); break;
            case 5: checkFull(); break;
            case 6: clearQueue(); break;
            case 7: clearQueue(); cout << "Terima kasih!\n"; break;
            default: cout << "Pilihan tidak valid!\n";
        }
    } while (pilih != 7);

    return 0;
}
