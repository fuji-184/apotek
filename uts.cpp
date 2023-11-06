#include <iostream>
#include <string>
#include <vector>
#include <ctime>

using namespace std;

struct Obat {
    int nomorObat;
    string nama;
    int stok;
    double harga;
    Obat* selanjutnya;

    Obat(string _nama, int _stok, double _harga) {
        nama = _nama;
        stok = _stok;
        harga = _harga;
        selanjutnya = nullptr;
    }
};

class Apotek {
private:
    Obat* daftarObat;
    int nomorObat;

public:
    Apotek() {
        daftarObat = nullptr;
        nomorObat = 1;
    }

    void tambahObat(string nama, int stok, double harga) {
        Obat* obatBaru = new Obat(nama, stok, harga);
        obatBaru->selanjutnya = daftarObat;
        daftarObat = obatBaru;
        
        obatBaru->nomorObat = nomorObat;
        nomorObat++;
    }

    void hapusObat(int _nomorObat) {
        Obat* sekarang = daftarObat;
        Obat* sebelumnya = nullptr;

        while (sekarang != nullptr) {
            if (sekarang->nomorObat == _nomorObat) {
                if (sebelumnya == nullptr) {
                    daftarObat = sekarang->selanjutnya;
                } else {
                    sebelumnya->selanjutnya = sekarang->selanjutnya;
                }
                delete sekarang;
                return;
            }
            sebelumnya = sekarang;
            sekarang = sekarang->selanjutnya;
        }

        cout << "Obat dengan nomor " << _nomorObat << " tidak ditemukan." << endl;
    }

    void tampilkanObatTersedia() {
        Obat* sekarang = daftarObat;

        cout << "Daftar Obat Tersedia:" << endl;
        while (sekarang != nullptr) {
            cout << "Nomor Obat : " << sekarang->nomorObat << " | Nama: " << sekarang->nama << " | Stok: " <<
            sekarang->stok << " | Harga: " << sekarang->harga << endl;
            sekarang = sekarang->selanjutnya;
        }
    }
    
    Obat* cariObat(string nama) {
        Obat* obatSekarang = daftarObat;

        while (obatSekarang != nullptr) {
            if (obatSekarang->nama == nama) {
                return obatSekarang;
            }
            obatSekarang = obatSekarang->selanjutnya;
        }

        return nullptr;
    }
    
    Obat* cariObat(int nomor) {
        Obat* obatSekarang = daftarObat;

        while (obatSekarang != nullptr) {
            if (obatSekarang->nomorObat == nomor) {
                return obatSekarang;
            }
            obatSekarang = obatSekarang->selanjutnya;
        }

        return nullptr;
    }
    
    void cetakLaporanInventaris() {
    Obat* obatSekarang = daftarObat;

    cout << "Laporan Inventaris Obat:" << endl;
    while (obatSekarang != nullptr) {

        cout << "Nama: " << obatSekarang->nama << endl;
        cout << "Stok: " << obatSekarang->stok << endl;
        cout << "Harga: " << obatSekarang->harga << endl;

        obatSekarang = obatSekarang->selanjutnya;
    }
}
};

struct ObatDiresepkan {
        string nama;
        double harga;
        
        ObatDiresepkan(string _nama, double _harga){
                nama = _nama;
                harga = _harga;
        };
};

struct Resep {
    int nomorResep;
    int nomorPelanggan;
    string namaPelanggan;
    string tanggal;
    vector <ObatDiresepkan> obatDiresepkan;
    Resep* selanjutnya;

    Resep(int _nomorResep, int _nomorPelanggan, string _namaPelanggan, string _tanggal) {
        nomorResep = _nomorResep;
        nomorPelanggan = _nomorPelanggan;
        namaPelanggan = _nomorPelanggan;
        tanggal = _tanggal;
        selanjutnya = nullptr;
    }
};

class ManajemenResep {
private:
    Resep* daftarResep;
    int nomorResep;

public:
    ManajemenResep() {
        daftarResep = nullptr;
        nomorResep = 1;
    }

    void tambahResep(int _nomorPelanggan, string _namaPelanggan, string tanggal, Obat* obat) {
        Resep* resepBaru = new Resep(nomorResep, _nomorPelanggan,
        _namaPelanggan, tanggal);
        
        if (daftarResep != nullptr) {
            ObatDiresepkan obatDiresepkan(obat->nama, obat->harga);
            resepBaru->obatDiresepkan.push_back(obatDiresepkan);
        }
        
        resepBaru->selanjutnya = daftarResep;
        daftarResep = resepBaru;
        
        resepBaru->nomorResep = nomorResep;
        nomorResep++;
    }

    void tampilkanResep() {
        Resep* resep = daftarResep;

        cout << "Daftar Resep:" << endl;
        while (resep != nullptr) {
            cout << "Nama Pelanggan : " 
            << resep->namaPelanggan 
            << " | Nomor Resep: " << resep->nomorResep << " | Tanggal: " << resep->tanggal << " | Obat: " << endl;
            for (const ObatDiresepkan &obat : resep->obatDiresepkan) {
        std::cout << "Nama: " << obat.nama << ", Harga: " << obat.harga << std::endl;
    }
            resep = resep->selanjutnya;
        }
    }
    
    void cetakRiwayatResep() {
    Resep* resepSekarang = daftarResep;

    cout << "Riwayat Resep:" << endl;
    while (resepSekarang != nullptr) {
        cout << "Nomor Resep: " << resepSekarang->nomorResep << endl;
        cout << "Tanggal: " << resepSekarang->tanggal << endl;
        //looping obatDiresepkan

        resepSekarang = resepSekarang->selanjutnya;
    }
}
};

struct Pelanggan {
    int nomorPelanggan;
    string nama;
    string alamat;
    string nomorKontak;
    Pelanggan* selanjutnya;

    Pelanggan(string _nama, string _alamat, string _nomorKontak) {
        nama = _nama;
        alamat = _alamat;
        nomorKontak = _nomorKontak;
        selanjutnya = nullptr;
    }
};

class ManajemenPelanggan {
private:
    Pelanggan* daftarPelanggan;
    int nomorPelanggan;

public:
    ManajemenPelanggan() {
        daftarPelanggan = nullptr;
        nomorPelanggan = 1;
    }

    void tambahPelanggan(string nama, string alamat, string nomorKontak) {
        Pelanggan* pelangganBaru = new Pelanggan(nama, alamat, nomorKontak);
        pelangganBaru->selanjutnya = daftarPelanggan;
        daftarPelanggan = pelangganBaru;
        
        pelangganBaru->nomorPelanggan = nomorPelanggan;
        nomorPelanggan++;
    }

    void tampilkanDataPelanggan() {
        Pelanggan* pelanggan = daftarPelanggan;

        cout << "Data Pelanggan:" << endl;
        while (pelanggan != nullptr) {
            cout << "Nomor Pelanggan : " << pelanggan->nomorPelanggan << " | Nama: " << pelanggan->nama << " | Alamat: " << pelanggan->alamat << " | Nomor Kontak: " << pelanggan->nomorKontak << endl;
            pelanggan = pelanggan->selanjutnya;
        }
    }
    
    Pelanggan* cariPelanggan(int _nomorPelanggan) {
        Pelanggan* pelangganSekarang = daftarPelanggan;

        while (pelangganSekarang != nullptr) {
            if (pelangganSekarang->nomorPelanggan == _nomorPelanggan) {
                return pelangganSekarang;
            }
            pelangganSekarang = pelangganSekarang->selanjutnya;
        }

        return nullptr;
    }
    
    string cariNamaPelanggan(int _nomorPelanggan) {
        Pelanggan* pelangganSekarang = daftarPelanggan;

        while (pelangganSekarang != nullptr) {
            if (pelangganSekarang->nomorPelanggan == _nomorPelanggan) {
                return pelangganSekarang->namaPelanggan;
            }
            pelangganSekarang = pelangganSekarang->selanjutnya;
        }

        return NULL;
    }
};

struct Transaksi {
    int nomorTransaksi;
    string tanggal;
    string pelanggan;
    string obatDibeli;
    double totalHarga;
    Transaksi* selanjutnya;

    Transaksi(int _nomorTransaksi, string _tanggal, string _pelanggan, string _obatDibeli, double _totalHarga) {
        nomorTransaksi = _nomorTransaksi;
        tanggal = _tanggal;
        pelanggan = _pelanggan;
        obatDibeli = _obatDibeli;
        totalHarga = _totalHarga;
        selanjutnya = nullptr;
    }
};

class ManajemenPenjualan {
private:
    Transaksi* daftarTransaksi;

public:
    ManajemenPenjualan() {
        daftarTransaksi = nullptr;
    }

    void catatPenjualan(int nomorTransaksi, string tanggal, string pelanggan, string obatDibeli, double totalHarga) {
        Transaksi* transaksiBaru = new Transaksi(nomorTransaksi, tanggal, pelanggan, obatDibeli, totalHarga);
        transaksiBaru->selanjutnya = daftarTransaksi;
        daftarTransaksi = transaksiBaru;
    }

    void tampilkanTransaksi() {
        Transaksi* transaksi = daftarTransaksi;

        cout << "Daftar Transaksi Penjualan:" << endl;
        while (transaksi != nullptr) {
            cout << "Nomor Transaksi: " << transaksi->nomorTransaksi << " | Tanggal: " << transaksi->tanggal << " | Pelanggan: " << transaksi->pelanggan << " | Obat Dibeli: " << transaksi->obatDibeli << " | Total Harga: " << transaksi->totalHarga << endl;
            transaksi = transaksi->selanjutnya;
        }
    }
    
    void cetakLaporanPenjualanBulanan(string bulan, int tahun) {
        cout << "Laporan Penjualan Bulanan (" << bulan << " " << tahun << "):" << endl;

        double totalPenjualanBulanan = 0.0;
        Transaksi* transaksiSekarang = daftarTransaksi;

        while (transaksiSekarang != nullptr) {
            string tanggalTransaksi = transaksiSekarang->tanggal;
            string bulanTransaksi = tanggalTransaksi.substr(5, 2);
            string tahunTransaksi = tanggalTransaksi.substr(0, 4);

            if (bulanTransaksi == bulan && stoi(tahunTransaksi) == tahun) {
                totalPenjualanBulanan += transaksiSekarang->totalHarga;
            }

            transaksiSekarang = transaksiSekarang->selanjutnya;
        }

        cout << "Total Penjualan Bulan " << bulan << " " << tahun << ": " << totalPenjualanBulanan << endl;
    }
};

int main() {
    Apotek apotek;
    ManajemenResep manajemenResep;
    ManajemenPelanggan manajemenPelanggan;
    ManajemenPenjualan manajemenPenjualan;
    
    time_t t = time(0);
tm* now = localtime(&t);
char date[11]; // 11 karakter untuk "YYYY-MM-DD\0"
strftime(date, 11, "%Y-%m-%d", now);
string tanggal(date);

    apotek.tambahObat("Obat A", 100, 10.5);
    apotek.tambahObat("Obat B", 50, 5.75);
    apotek.tambahObat("Obat C", 75, 7.2);
    apotek.tambahObat("Obat D", 30, 15.0);
    apotek.tambahObat("Obat E", 60, 8.75);
    apotek.tambahObat("Obat F", 25, 12.3);
    apotek.tambahObat("Obat G", 90, 9.0);
    apotek.tambahObat("Obat H", 40, 11.5);
    apotek.tambahObat("Obat I", 55, 6.9);
    apotek.tambahObat("Obat J", 70, 14.7);
    
    for (int i = 0; i < 10; i++) {
        string nama = "Pelanggan " + to_string(i + 1);
        string alamat = "Alamat Pelanggan " + to_string(i + 1);
        string nomorKontak = "Nomor Kontak " + to_string(i + 1);
        manajemenPelanggan.tambahPelanggan(nama, alamat, nomorKontak);
    }

    while (true) {
        cout << "Menu Navigasi:" << endl;
        cout << "1. Manajemen Inventaris Obat" << endl;
        cout << "2. Manajemen Resep" << endl;
        cout << "3. Manajemen Data Pelanggan" << endl;
        cout << "4. Transaksi Penjualan" << endl;
        cout << "5. Cetak Laporan" << endl;
        cout << "6. Keluar" << endl;
        cout << "Pilih menu (1-6): ";
        
        
        if (cin.peek() == ' ') {
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Masukan tidak valid. Harap masukkan angka (1-6)." << endl;
} else {
        int pilihan;
        cin >> pilihan;
        
        if (cin.fail() || pilihan < 1 || pilihan > 6) {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Masukan tidak valid. Harap masukkan angka (1-6)." << endl;
} else {
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
        
        if (pilihan == 1) {
        
        cout << "Masukkan menu : \n"
        << "1. Tambah Obat\n"
        << "2. Hapus Obat\n"
        << "3. Lihat Daftar Obat\n"
        << endl;
        
        cin >> pilihan;
        
        if (pilihan == 1){
    string namaObat;
    int stokObat;
    double hargaObat;
    
    cout << "Masukkan nama obat: ";
    cin >> namaObat;
    
    cout << "Masukkan stok obat: ";
    cin >> stokObat;
    
    cout << "Masukkan harga obat: ";
    cin >> hargaObat;
    
    apotek.tambahObat(namaObat, stokObat, hargaObat);
        }
    else if (pilihan == 2){
            int nomorObat;
            apotek.tampilkanObatTersedia();
            cout << "Masukkan Nomor Obat : " << endl;
            cin >> nomorObat;
            apotek.hapusObat(nomorObat);
            apotek.tampilkanObatTersedia();
    }
    else if (pilihan == 3){
            apotek.tampilkanObatTersedia();
    }
    else {
            break;
    }
} else if (pilihan == 2) {
    
    int nomorObat;
    
    apotek.tampilkanObatTersedia();
    
    cout << "Masukkan nomor obat yang diresepkan: ";
    cin >> nomorObat;
    
    Obat* obat = apotek.cariObat(nomorObat);
    
    manajemenResep.tambahResep(tanggal, obat);
} else if (pilihan == 3) {
        
    cout << "Masukkan Menu : \n"
    << "1. Tambah Pelanggan\n"
    << "2. Tampilkan Daftar Pelanggan\n"
    << endl;
    
    cin >> pilihan;
    
    if (pilihan == 1){
    string namaPelanggan;
    string alamatPelanggan;
    string nomorKontakPelanggan;
    
    cout << "Masukkan nama pelanggan: ";
    cin >> namaPelanggan;
    
    cout << "Masukkan alamat pelanggan: ";
    cin >> alamatPelanggan;
    
    cout << "Masukkan nomor kontak pelanggan: ";
    cin >> nomorKontakPelanggan;
    
    manajemenPelanggan.tambahPelanggan(namaPelanggan, alamatPelanggan, nomorKontakPelanggan);
    }
    else if (pilihan == 2){
           manajemenPelanggan.tampilkanDataPelanggan();
    }
    else {
            break;
    }
} else if (pilihan == 4) {

    int nomorTransaksi;
    string tanggalTransaksi;
    string namaPelanggan;
    string obatDibeli;
    double totalHarga;
    
    cout << "Masukkan nomor transaksi: ";
    cin >> nomorTransaksi;
    
    cout << "Masukkan tanggal transaksi (YYYY-MM-DD): ";
    cin >> tanggalTransaksi;
    
    cout << "Masukkan nama pelanggan: ";
    cin >> namaPelanggan;
    
    cout << "Masukkan obat yang dibeli: ";
    cin >> obatDibeli;
    
    cout << "Masukkan total harga: ";
    cin >> totalHarga;
    
    Obat* obatYangDibeli = apotek.cariObat(obatDibeli);
if (obatYangDibeli != nullptr) {
    if (obatYangDibeli->stok >= 1) {
        manajemenPenjualan.catatPenjualan(nomorTransaksi, tanggalTransaksi, namaPelanggan, obatDibeli, totalHarga);
        obatYangDibeli->stok--;
    } else {
        cout << "Stok obat " << obatDibeli << " sudah habis." << endl;
    }
} else {
    cout << "Obat " << obatDibeli << " tidak ditemukan." << endl;
}


} else if (pilihan == 5) {

    string jenisLaporan;
    cout << "Pilih jenis laporan (inventaris/penjualan/riwayat): ";
    cin >> jenisLaporan;
    
    if (jenisLaporan == "inventaris") {

        apotek.cetakLaporanInventaris();
    } else if (jenisLaporan == "penjualan") {

        string bulanLaporan;
        int tahunLaporan;
        
        cout << "Masukkan bulan laporan: ";
        cin >> bulanLaporan;
        
        cout << "Masukkan tahun laporan: ";
        cin >> tahunLaporan;
        
        manajemenPenjualan.cetakLaporanPenjualanBulanan(bulanLaporan, tahunLaporan);

    } else if (jenisLaporan == "riwayat") {
        manajemenResep.cetakRiwayatResep();
    } else {
        cout << "Jenis laporan tidak valid." << endl;
    }
}
else if (pilihan == 6) {
        std::cout << "Terima kasih telah menggunakan program ini! Program berhasil dihentikan." << std::endl;
        break;
    } 
    else {
        std::cout << "Pilihan tidak valid. Silakan pilih angka 1-6." << std::endl;
    }
    }
    }

        
    }

    return 0;
}

