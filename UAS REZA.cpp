#include <iostream>
#include <vector>
#include <string>
#include <algorithm>  
#include <limits>     

using namespace std;


struct Produk {
    int id;
    string nama;
    float harga;
    int stok;
};


int idCounter = 1;


void tambahProduk(vector<Produk>& produkList) {
    Produk produkBaru;
    produkBaru.id = idCounter++; 

    cout << "\nMasukkan Nama Produk: ";
    cin.ignore(); 
    getline(cin, produkBaru.nama);

    cout << "Masukkan Harga Produk: ";
    cin >> produkBaru.harga;
    if (produkBaru.harga < 0) {
        cout << "Harga tidak boleh negatif.\n";
        return;
    }

    cout << "Masukkan Stok Produk: ";
    cin >> produkBaru.stok;
    if (produkBaru.stok < 0) {
        cout << "Stok tidak boleh negatif.\n";
        return;
    }

    produkList.push_back(produkBaru);
    cout << "Produk berhasil ditambahkan dengan ID " << produkBaru.id << ".\n";
}


void tampilkanProduk(const vector<Produk>& produkList) {
    if (produkList.empty()) {
        cout << "Tidak ada produk yang terdaftar.\n";
    } else {
        cout << "\nDaftar Produk:\n";
        for (const auto& produk : produkList) {
            cout << "ID: " << produk.id << ", Nama: " << produk.nama
                 << ", Harga: " << produk.harga << ", Stok: " << produk.stok << endl;
        }
    }
}


void cariProdukById(const vector<Produk>& produkList) {
    int idCari;
    cout << "Masukkan ID Produk yang ingin dicari: ";
    cin >> idCari;

    auto it = find_if(produkList.begin(), produkList.end(), [idCari](const Produk& p) {
        return p.id == idCari;
    });

    if (it != produkList.end()) {
        cout << "\nProduk ditemukan:\n";
        cout << "ID: " << it->id << ", Nama: " << it->nama
             << ", Harga: " << it->harga << ", Stok: " << it->stok << endl;
    } else {
        cout << "Produk dengan ID " << idCari << " tidak ditemukan.\n";
    }
}


void hapusProduk(vector<Produk>& produkList) {
    int idHapus;
    cout << "Masukkan ID Produk yang ingin dihapus: ";
    cin >> idHapus;

    auto it = find_if(produkList.begin(), produkList.end(), [idHapus](const Produk& p) {
        return p.id == idHapus;
    });

    if (it != produkList.end()) {
        produkList.erase(it);  
        cout << "Produk dengan ID " << idHapus << " berhasil dihapus.\n";
    } else {
        cout << "Produk dengan ID " << idHapus << " tidak ditemukan.\n";
    }
}


int main() {
    vector<Produk> produkList;
    int pilihan;
    cout << "Selamat datang di Sistem Manajemen Produk PT Reza Mortasefi\n";

    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Tambah Produk\n";
        cout << "2. Tampilkan Daftar Produk\n";
        cout << "3. Cari Produk berdasarkan ID\n";
        cout << "4. Hapus Produk\n";
        cout << "5. Keluar\n";
        cout << "Pilih opsi (1-5): ";
        cin >> pilihan;

       
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (pilihan) {
            case 1:
                tambahProduk(produkList);
                break;
            case 2:
                tampilkanProduk(produkList);
                break;
            case 3:
                cariProdukById(produkList);
                break;
            case 4:
                hapusProduk(produkList);
                break;
            case 5:
                cout << "Terima kasih! Program selesai.\n";
                return 0;
            default:
                cout << "Pilihan tidak valid, coba lagi.\n";
        }
    }
}
