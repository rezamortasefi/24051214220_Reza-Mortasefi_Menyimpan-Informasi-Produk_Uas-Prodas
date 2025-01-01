#include <iostream>
#include <string>
using namespace std;

struct Produk {
    int id;
    string nama;
    float harga;
    int stok;
};


void tambahProduk(Produk *&produk, int &jumlahProduk, int &kapasitas) {
    if (jumlahProduk >= kapasitas) {
        kapasitas *= 2;  
        Produk *produkBaru = new Produk[kapasitas];  

        
        for (int i = 0; i < jumlahProduk; i++) {
            produkBaru[i] = produk[i];
        }

        delete[] produk;  
        produk = produkBaru;  
    }

    cout << "\nMasukkan ID Produk: ";
    cin >> produk[jumlahProduk].id;
    cin.ignore();  
    cout << "Masukkan Nama Produk: ";
    getline(cin, produk[jumlahProduk].nama);
    cout << "Masukkan Harga Produk: ";
    cin >> produk[jumlahProduk].harga;
    cout << "Masukkan Stok Produk: ";
    cin >> produk[jumlahProduk].stok;

    jumlahProduk++;
    cout << "Produk berhasil ditambahkan.\n";
}


void tampilkanProduk(const Produk *produk, int jumlahProduk) {
    if (jumlahProduk == 0) {
        cout << "Tidak ada produk yang terdaftar.\n";
    } else {
        cout << "\nDaftar Produk:\n";
        for (int i = 0; i < jumlahProduk; i++) {
            cout << "ID: " << produk[i].id << ", Nama: " << produk[i].nama
                 << ", Harga: " << produk[i].harga << ", Stok: " << produk[i].stok << endl;
        }
    }
}


void cariProdukById(const Produk *produk, int jumlahProduk) {
    int idCari;
    cout << "Masukkan ID Produk yang ingin dicari: ";
    cin >> idCari;

    bool ditemukan = false;
    for (int i = 0; i < jumlahProduk; i++) {
        if (produk[i].id == idCari) {
            cout << "\nProduk ditemukan:\n";
            cout << "ID: " << produk[i].id << ", Nama: " << produk[i].nama
                 << ", Harga: " << produk[i].harga << ", Stok: " << produk[i].stok << endl;
            ditemukan = true;
            break;
        }
    }

    if (!ditemukan) {
        cout << "Produk dengan ID " << idCari << " tidak ditemukan.\n";
    }
}


void hapusProduk(Produk *&produk, int &jumlahProduk) {
    int idHapus;
    cout << "Masukkan ID Produk yang ingin dihapus: ";
    cin >> idHapus;

    bool ditemukan = false;
    for (int i = 0; i < jumlahProduk; i++) {
        if (produk[i].id == idHapus) {
            
            for (int j = i; j < jumlahProduk - 1; j++) {
                produk[j] = produk[j + 1];
            }
            jumlahProduk--;
            cout << "Produk dengan ID " << idHapus << " berhasil dihapus.\n";
            ditemukan = true;
            break;
        }
    }

    if (!ditemukan) {
        cout << "Produk dengan ID " << idHapus << " tidak ditemukan.\n";
    }
}

int main() {
    int kapasitas = 2;  
    int jumlahProduk = 0;  
    Produk *produk = new Produk[kapasitas];  
    int pilihan;  

    cout << "Selamat datang di Sistem Manajemen Produk PT Abadi\n";

    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Tambah Produk\n";
        cout << "2. Tampilkan Daftar Produk\n";
        cout << "3. Cari Produk berdasarkan ID\n";
        cout << "4. Hapus Produk\n";
        cout << "5. Keluar\n";
        cout << "Pilih opsi (1-5): ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                tambahProduk(produk, jumlahProduk, kapasitas);
                break;
            case 2:
                tampilkanProduk(produk, jumlahProduk);
                break;
            case 3:
                cariProdukById(produk, jumlahProduk);
                break;
            case 4:
                hapusProduk(produk, jumlahProduk);
                break;
            case 5:
                cout << "Terima kasih! Program selesai.\n";
                delete[] produk;  
                return 0;
            default:
                cout << "Pilihan tidak valid, coba lagi.\n";
        }
    }

    return 0;
}

