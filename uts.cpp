#include <iostream>
#include <string>
#include <ctime>
#include <fstream>
#include <limits>

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
    obatBaru->selanjutnya = nullptr;

    if (daftarObat == nullptr) {
        daftarObat = obatBaru;
    } else {
        Obat* terakhir = daftarObat;
        while (terakhir->selanjutnya != nullptr) {
            terakhir = terakhir->selanjutnya;
        }
        terakhir->selanjutnya = obatBaru;
    }
    
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
            cout << "Nomor Obat : "
            << sekarang->nomorObat
            << "\nNama : "
            << sekarang->nama
            << "\nStok: "
            << sekarang->stok
            << "\nHarga: "
            << sekarang->harga
            << "\n\n"
            << endl;
            
            sekarang = sekarang->selanjutnya;
        }
    }
    
    Obat* cariObat(int* _nomorObat) {
        Obat* obatSekarang = daftarObat;

        while (obatSekarang != nullptr) {
            if (obatSekarang->nomorObat == *_nomorObat) {
                return obatSekarang;
            }
            obatSekarang = obatSekarang->selanjutnya;
        }

        return nullptr;
    }
    
    void cetakLaporanInventaris() {
  
    ofstream laporanInventarisObat("Laporan Inventaris Obat.txt");
    
    if (laporanInventarisObat.is_open()){
       
        Obat* obatSekarang = daftarObat;
        
        while (obatSekarang != nullptr){
                laporanInventarisObat << "Nomor Obat : "
                << obatSekarang->nomorObat
                << "\nNama Obat : "
                << obatSekarang->nama
                << "\nStok : "
                << obatSekarang->stok
                << "\nHarga : "
                << obatSekarang->harga
                << "\n\n"
                << endl;
                
                obatSekarang = obatSekarang->selanjutnya;
                
        }
        
        laporanInventarisObat.close();
        
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

    if (daftarPelanggan == nullptr) {
        daftarPelanggan = pelangganBaru;
    } else {
        Pelanggan* pelangganTerakhir = daftarPelanggan;
        while (pelangganTerakhir->selanjutnya != nullptr) {
            pelangganTerakhir = pelangganTerakhir->selanjutnya;
        }
        pelangganTerakhir->selanjutnya = pelangganBaru;
    }

    pelangganBaru->nomorPelanggan = nomorPelanggan;
    nomorPelanggan++;
    }

    void tampilkanDataPelanggan() {
        Pelanggan* pelanggan = daftarPelanggan;

        cout << "Data Pelanggan:" << endl;
        while (pelanggan != nullptr) {
            cout << "Nomor Pelanggan : "
            << pelanggan->nomorPelanggan
            << "\nNama: "
            << pelanggan->nama
            << "\nAlamat: "
            << pelanggan->alamat
            << "\nNomor Kontak: "
            << pelanggan->nomorKontak
            << "\n\n"
            << endl;
            
            pelanggan = pelanggan->selanjutnya;
            
        }
    }
    
    Pelanggan* cariPelanggan(int* _nomorPelanggan) {
        Pelanggan* pelangganSekarang = daftarPelanggan;

        while (pelangganSekarang != nullptr) {
            if (pelangganSekarang->nomorPelanggan == *_nomorPelanggan) {
                return pelangganSekarang;
            }
            pelangganSekarang = pelangganSekarang->selanjutnya;
        }

        return nullptr;
    }
    
};

struct Resep {
    int nomorResep;
    Pelanggan* pelanggan;
    string tanggal;
    Obat* obatDiresepkan;
    Resep* selanjutnya;

    Resep(int _nomorResep, string _tanggal) {
        nomorResep = _nomorResep;
        pelanggan = nullptr;
        tanggal = _tanggal;
        obatDiresepkan = nullptr;
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

    void tambahResep(Pelanggan* pelanggan, string tanggal, Obat* obatDiresepkan) {
            
    Resep* resepBaru = new Resep(nomorResep, tanggal);

    resepBaru->pelanggan = pelanggan;
    resepBaru->obatDiresepkan = obatDiresepkan;
    resepBaru->selanjutnya = nullptr;
    
    if (daftarResep == nullptr) {
        daftarResep = resepBaru;
    } else {
        Resep* current = daftarResep;
        while (current->selanjutnya != nullptr) {
            current = current->selanjutnya;
        }
        current->selanjutnya = resepBaru;
    }
    nomorResep++;
}

    Resep* cariResep(int* nomor) {
    Resep* resepSekarang = daftarResep;

    while (resepSekarang != nullptr) {
        if (resepSekarang->nomorResep == *nomor) {
            return resepSekarang; 
        }
        resepSekarang = resepSekarang->selanjutnya;
    }

    return nullptr;
    }
    
    void tampilkanResep() {
    Resep* resep = daftarResep;

    cout << "Daftar Resep :" << endl;
    while (resep != nullptr) {
        cout << "Nomor Resep : "
        << resep->nomorResep
        << "\nTanggal : "
        << resep->tanggal
        << "\nNomor Pelanggan : "
        << resep->pelanggan->nomorPelanggan
        << "\nNama Pelanggan : "
        << resep->pelanggan->nama
        << "\nObat Yang Diresepkan : "
        << endl;

        Obat* _obatDiresepkan = resep->obatDiresepkan;

        while (_obatDiresepkan != nullptr) {
            cout << "\nNama Obat : "
            << _obatDiresepkan->nama
            << "\n"
            << endl;
            
            _obatDiresepkan = _obatDiresepkan->selanjutnya;
            
        }
        
        resep = resep->selanjutnya;
        
    }
}
    
    void cetakRiwayatResep(int* _nomorPelanggan) {
    ofstream riwayatResep("Riwayat Resep.txt");

    Resep* resepSekarang = daftarResep;
    Obat* obat;

    while (resepSekarang != nullptr) {
        if (resepSekarang->pelanggan->nomorPelanggan == *_nomorPelanggan) {
            if (riwayatResep.is_open()) {
                riwayatResep << "Riwayat Resep Untuk Pasien Bernama " << resepSekarang->pelanggan->nama << "\n\nTanggal : "
                            << resepSekarang->tanggal << "\n\nObat Yang Diresepkan :\n\n" << endl;

                obat = resepSekarang->obatDiresepkan;

                int i = 1;

                while (obat != nullptr) {
                    riwayatResep << i++ << ". Nama Obat : " << obat->nama << endl;
                    obat = obat->selanjutnya;
                }
            }
        }

        resepSekarang = resepSekarang->selanjutnya;
    }

    riwayatResep.close();
}

};

struct Transaksi {
    int nomorTransaksi;
    Resep* resep;
    double totalHarga;
    string tanggal;
    Transaksi* selanjutnya;

    Transaksi(double _totalHarga, string _tanggal) {
        totalHarga = _totalHarga;
        tanggal = _tanggal;
        selanjutnya = nullptr;
    }
};

class ManajemenPenjualan {
private:
    Transaksi* daftarTransaksi;
    int nomorTransaksi;

public:
    ManajemenPenjualan() {
        daftarTransaksi = nullptr;
        nomorTransaksi = 1;
    }

    void catatPenjualan(Resep* resep, double totalHarga, string tanggal) {

        Transaksi* transaksiBaru = new Transaksi(totalHarga, tanggal);
        
        transaksiBaru->nomorTransaksi = nomorTransaksi;
        
        transaksiBaru->resep = resep;
        
        transaksiBaru->selanjutnya = daftarTransaksi;
        
        daftarTransaksi = transaksiBaru;
        
        nomorTransaksi++;
    }

    void tampilkanTransaksi() {
            
        Transaksi* transaksi = daftarTransaksi;

        cout << "Daftar Transaksi Penjualan:" << endl;
        
        while (transaksi != nullptr) {
            cout << "Nomor Transaksi : "
            << transaksi->nomorTransaksi
            << "\nTanggal : "
            << transaksi->tanggal
            << "\nNomor Resep : "
            << transaksi->resep->nomorResep
            << "\nTotal Harga: "
            << transaksi->totalHarga
            << "\n\n"
            << endl;
            
            transaksi = transaksi->selanjutnya;
            
        }
    }
    
    void cetakLaporanPenjualanHarian(string* tanggal ) {
            
        ofstream laporanPenjualanHarian("Laporan Penjualan Harian.txt");
        
        if (laporanPenjualanHarian.is_open()){
                
               Transaksi* transaksi = daftarTransaksi;
               
               while (transaksi != nullptr){
                       
                    if (transaksi->tanggal == *tanggal){
                      laporanPenjualanHarian << "Nomor Transaksi : "
                      << transaksi->nomorTransaksi
                      << "\nTanggal : "
                      << transaksi->tanggal
                      << "\n Total Harga : "
                      << transaksi->totalHarga
                      << "\n\n"
                      << endl;
                      
                    transaksi = transaksi->selanjutnya;
                    }
               }
               
               laporanPenjualanHarian.close();
               
        }
        
    }
};

int main() {
    Apotek apotek;
    ManajemenResep manajemenResep;
    ManajemenPelanggan manajemenPelanggan;
    ManajemenPenjualan manajemenPenjualan;
    
    time_t t = time(0);
tm* now = localtime(&t);
char date[11];
strftime(date, 11, "%Y-%m-%d", now);
string tanggal(date);

    apotek.tambahObat("Obat A", 100, 3000);
    apotek.tambahObat("Obat B", 50, 5000);
    apotek.tambahObat("Obat C", 75, 2000);
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
        
    cout << "Masukkan pilihan : \n1. Tambah Resep\n2. Tampilkan Resep \n\n: ";
    cin >> pilihan;
    
    if (pilihan == 1){
    int nomorPelanggan;
    int nomorObat = 1;

    manajemenPelanggan.tampilkanDataPelanggan();

    cout << "Masukkan nomor Pelanggan : ";
    cin >> nomorPelanggan;

    Pelanggan* pelanggan = manajemenPelanggan.cariPelanggan(&nomorPelanggan);

    if (pelanggan != nullptr) {
        Obat* obatDiresepkan = nullptr; 
        


        while (nomorObat != 0) {
    apotek.tampilkanObatTersedia();

    cout << "Masukkan nomor obat yang diresepkan (0 untuk selesai): ";
    cin >> nomorObat;

    if (nomorObat != 0) {
        Obat* _obat = apotek.cariObat(&nomorObat);

        if (_obat != nullptr) {
            // Tambahkan referensi obat ke dalam resep
            _obat->selanjutnya = obatDiresepkan;
            obatDiresepkan = _obat;
        } else {
            cout << "Obat dengan nomor tersebut tidak tersedia." << endl;
        }
    }
}


        manajemenResep.tambahResep(pelanggan, tanggal, obatDiresepkan);
    } else {
        cout << "Pelanggan tidak ditemukan." << endl;
    }
}
 else if (pilihan == 2){
            manajemenResep.tampilkanResep();
    } else {
            break;
    }
        
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
        
    cout << "Masukkan pilihan : \n1. Checkout Resep\n2. Tampilkan Data Transaksi" << endl;
    
    cin >> pilihan;
    
    if (pilihan == 1){
    int nomorResep;
        
    manajemenResep.tampilkanResep();
    
    cout << "Pilih resep yang ingin dibayar : ";
    
    cin >> nomorResep;
    
    Resep* resep = manajemenResep.cariResep(&nomorResep);
    
    if (resep != nullptr){
      
    Obat* perulanganObat = resep->obatDiresepkan;
    
    double totalHarga = 0;
    
    while (perulanganObat != nullptr){

            totalHarga = totalHarga + perulanganObat->harga;
            
            perulanganObat->stok = perulanganObat->stok - 1;
            
            perulanganObat = perulanganObat->selanjutnya;
            
    }
    
    manajemenPenjualan.catatPenjualan(resep, totalHarga, tanggal);
    
    ofstream struk("Struk.txt");
    
    if (struk.is_open()){
            
    struk << "Nama : "
    << resep->pelanggan->nama
    << endl;
            
    perulanganObat = resep->obatDiresepkan;
    
    struk << "\nObat : \n" << endl;
    
    while (perulanganObat != nullptr){

            struk << perulanganObat->nama
            << "  : "
            << perulanganObat->harga
            << "\n"
            << endl;
            
            perulanganObat = perulanganObat->selanjutnya;
            
    }
    
    struk << totalHarga;
     
    struk.close();
    }
    
    }
    } else if (pilihan == 2){
         manajemenPenjualan.tampilkanTransaksi(); 
    } else {
            break;
    }
    
} else if (pilihan == 5) {
        
    cout << "Masukan pilihan : \n1. Cetak Laporan Inventaris Obat\n2. Cetak Laporan Penjualan Harian\n3. Cetak Riwayat Resep\n\n: ";
    
    cin >> pilihan;
    
    if (pilihan == 1){
            apotek.cetakLaporanInventaris();
    } else if (pilihan == 2){
            manajemenPenjualan.cetakLaporanPenjualanHarian(&tanggal);
    } else if (pilihan == 3){
            
            manajemenPelanggan.tampilkanDataPelanggan();
            
            cout << "Masukkan Nomor Pelanggan Yang Ingin Dicetak Riwayat Resepnya : ";
            
            cin >> pilihan;
            
            manajemenResep.cetakRiwayatResep(&pilihan);
            
    } else {
            break;
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

