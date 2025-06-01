/*
NAMA : MUHAMMAD DIMAS SETIAJI NIM: 123240240 KELAS IF-L
NAMA : LINTANG CAHAYA EKA PUTRA NIM: 123240245 KELAS IF-L
*/

/*
CATATAN
Cara menampilkan dan serach data setelah keluar program,
harus pilih menu muat data terlebih dahulu agar data kembali.
pilih menu simpan file setiap tambah, update, hapus pemain.
*/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;


struct pemain{
    string nama;
    string posisi;
    int nopunggung;
    int umur;
    int tinggi;
};
pemain pmn[20];
int jumlahPemain = 0;


struct Kepelatihan{
    string nama;
    string jabatan;
    int umur;
};
Kepelatihan plth[15];
int jumlahpelatih = 0;

//buble sort nama pelatih
void sortingNamaPelatih() {
    if(jumlahpelatih <= 1)return;
    for (int i = 0; i < jumlahpelatih - 1; i++) {
        for (int j = 0; j < jumlahpelatih - i - 1; j++) {
            if (plth[j].nama > plth[j + 1].nama) {
                swap(plth[j], plth[j + 1]);
            }
        }
    }
}

//buble sort jabatan pelatih
void sortingJabatanPelatih() {
    if(jumlahpelatih <= 1)return;
    for (int i = 0; i < jumlahpelatih - 1; i++) {
        for (int j = 0; j < jumlahpelatih - i - 1; j++) {
            if (plth[j].jabatan > plth[j + 1].jabatan) {
                swap(plth[j], plth[j + 1]);
            }
        }
    }
}

//buble sort usia pelatih
void sortingUmurPelatih(){
    if(jumlahpelatih <= 1)return;
    for(int i = 0; i < jumlahpelatih; i++){
        for(int j = 0; j < jumlahpelatih - i - 1; j++) {
            if (plth[j].umur > plth[j + 1].umur) {
                swap(plth[j], plth[j + 1]);
            }
        }
    }
}


//fungsi untuk menambah pelatih
void tambahPelatih() {
    if( jumlahpelatih >= 15){
        cout<<"Kapasitas pelatih sudah penuh!"<<endl;
        return;
    }

    Kepelatihan pl;
    cout << "\n====================="<<endl;
        cout << "|TAMBAH PELATIH KE-"<<jumlahpelatih + 1<<" |"<<endl;
        cout << "====================="<<endl;
        cin.ignore();

        cout << "Masukkan Nama     : ";
        getline(cin, pl.nama);

        cout << "Masukkan jabatan  : ";
        getline(cin, pl.jabatan);

        cout << "Masukkan Umur     : ";
        cin >> pl.umur;

        plth[jumlahpelatih++] = pl;
        cout<<"Pelatih berhasil ditambahkan!"<<endl<<endl;

};

// Fungsi untuk menyimpan data pelatih ke file
void simpanPelatihKeFile() {
    ofstream file("data_pelatih.txt");
    if (!file) {
        cout << "Gagal membuka file untuk menulis.\n";
        return;
    }

    for (int i = 0; i < jumlahpelatih; i++) {
        file << plth[i].nama << endl;
        file << plth[i].jabatan << endl;
        file << plth[i].umur << endl;
    }

    file.close();
    cout << "Data pelatih berhasil disimpan ke file.\n";
}

// Fungsi untuk memuat data pelatih dari file
void muatPelatihDariFile() {
    ifstream file("data_pelatih.txt");
    if (!file) {
        cout << "File tidak ditemukan atau gagal dibuka.\n";
        return;
    }

    jumlahpelatih = 0;
    while (jumlahpelatih < 15) {
        Kepelatihan pl;
        if (!getline(file, pl.nama)) break;
        if (!getline(file, pl.jabatan)) break;
        if (!(file >> pl.umur)) break;
        file.ignore(); // Buang newline sisa input baris angka

        plth[jumlahpelatih] = pl;
        jumlahpelatih++;
    }

    file.close();
    cout << "Data pelatih berhasil dimuat dari file.\n";
}


//tampilkan pelatih sebelum sorting dengan rekursif
void tampilkanPelatihSebelumSorting(int index){
    if(index == jumlahpelatih) return;

    cout << "----------------------------"<<endl;
    cout << "|       PELATIH KE- " << index + 1<<"       |"<<endl;
    cout << "----------------------------"<<endl;
    cout << "Nama        : "<<plth[index].nama <<endl;
    cout << "Jabatan     : "<<plth[index].jabatan <<endl;
    cout << "Umur        : "<<plth[index].umur <<endl<<endl;
  
    tampilkanPelatihSebelumSorting(index + 1);

};

//tampilkan pelatih setelah sorting umur dengan rekursif
void tampilkanPelatihSetelahSort(int index = 0, bool sort = false){

    if (!sort) {
        sortingUmurPelatih(); 
    }

    if(index == jumlahpelatih) return;

    cout << "----------------------------"<<endl;
    cout << "|       PELATIH KE- " << index + 1<<"       |"<<endl;
    cout << "----------------------------"<<endl;
    cout << "Nama        : "<<plth[index].nama <<endl;
    cout << "Jabatan     : "<<plth[index].jabatan <<endl;
    cout << "Umur        : "<<plth[index].umur <<endl<<endl;
  
    tampilkanPelatihSetelahSort(index + 1, true);

};

void MenuTampilkanPelatih(){
    int pilih;
    if(jumlahpelatih == 0){
        cout<<"belum ada pelatih yang ditambahkan!"<<endl;
    }

    do{
        cout<<"===Menu Tampilkan Pelatih==="<<endl;
        cout<<"1. Sebelum di sorting"<<endl;
        cout<<"2. Setelah di sorting (umur)"<<endl;
        cout<<"3. kembali"<<endl;
        cout<<"input pilihan : ";
        cin>>pilih;
        cout<<endl;

        switch (pilih){
            case 1:{
                tampilkanPelatihSebelumSorting(0);
                break;}
            case 2:{
                tampilkanPelatihSetelahSort();
                break;}
            case 3:
                return;
            default: cout<<"pilihan tidak valid"<<endl;
                break;
    }
    } while (pilih != 3);
    return;
}

// sequential search berdasarkan nama pelatih
void CariPelatihNamaSequential(string targetNamaPelatih){
    bool found = false;
    for(int i = 0; i < jumlahpelatih; i++){
        if(plth[i].nama == targetNamaPelatih){
            cout<<"Pelatih ditemukan!"<<endl;
            cout<<"Nama        : "<<plth[i].nama<<endl;
            cout<<"Jabatan     : "<<plth[i].jabatan<<endl;
            cout<<"Umur        : "<<plth[i].umur<<endl<<endl;
            found = true;
            break;
        }
    }
    if(!found){
        cout<<"Pelatih dengan nama "<<targetNamaPelatih<<" tidak ditemukan!"<<endl;
    }
}

// sequential search berdasarkan jabatan pelatih
void CariPelatihJabatanSequential(string targetJabatanPelatih){
    bool found = false;
    for(int i = 0; i < jumlahpelatih; i++){
        if(plth[i].jabatan == targetJabatanPelatih){
            cout<<"Pelatih ditemukan!"<<endl;
            cout<<"Nama        : "<<plth[i].nama<<endl;
            cout<<"Jabatan     : "<<plth[i].jabatan<<endl;
            cout<<"Umur        : "<<plth[i].umur<<endl<<endl;
            found = true;
            break;
        }
    }
    if(!found){
        cout<<"Pelatih dengan jabatan "<<targetJabatanPelatih<<" tidak ditemukan!"<<endl;
    }
}

// sequential search berdasarkan umur pelatih
void CariPelatihUmurSequential(int targetUmurPelatih){
    bool found = false;
    for(int i = 0; i < jumlahpelatih; i++){
        if(plth[i].umur == targetUmurPelatih){
            cout<<"Pelatih ditemukan!"<<endl;
            cout<<"Nama        : "<<plth[i].nama<<endl;
            cout<<"Jabatan     : "<<plth[i].jabatan<<endl;
            cout<<"Umur        : "<<plth[i].umur<<endl<<endl;
            found = true;
            break;
        }
    }
    if(!found){
        cout<<"Pelatih dengan umur "<<targetUmurPelatih<<" tidak ditemukan!"<<endl;
    }
}

//Menu sequential search Pelatih
void MenuCariPelatihSequential(){
    if(jumlahpelatih == 0){
        cout<<"Belum ada pelatih yang ditambahkan!"<<endl;
        return; }
    int pilih;
    cout<<"Cari pelatih berdasarkan "<<endl;
    cout<<"1. Nama"<<endl;
    cout<<"2. Jabatan"<<endl;
    cout<<"3. Umur"<<endl;
    cout<<"4. kembali"<<endl;
    cout<<"Pilih Menu : ";
    cin>>pilih;
    cin.ignore();
    cout<<endl;
    switch (pilih){
        case 1:{
            string NamaPelatih;
            cout<<"Masukkan Nama Pelatih : ";
            getline(cin, NamaPelatih);
            CariPelatihNamaSequential(NamaPelatih);
            break;
        }
        case 2:{
            string JabatanPelatih;
            cout<<"Masukkan Jabatan Pelatih : ";
            getline(cin, JabatanPelatih);
            CariPelatihJabatanSequential(JabatanPelatih);
            break;
        }
        case 3:{
            int Umur;
            cout<<"Masukkan Umur Pelatih : ";
            cin>>Umur;
            CariPelatihUmurSequential(Umur);
            break;
        }

        case 4:{
            return;
        }

        default: cout << "Pilihan tidak valid!\n";
            break;
    }
}

//Binary search berdasarkan nama pelatih
void CariPelatihNamaBinary() {
    sortingNamaPelatih(); // Pastikan data terurut sebelum pencarian

    string CariNama;
    cout << "\nMasukkan nama yang ingin dicari : ";
    getline(cin, CariNama);

    int kiri = 0, kanan = jumlahpelatih - 1;
    while (kiri <= kanan) {
        int tengah = (kiri + kanan) / 2;

        if (plth[tengah].nama == CariNama) {
            cout << "Nama        : " << plth[tengah].nama<<endl;
            cout << "Jabatan     : " << plth[tengah].jabatan<<endl;
            cout << "Umur        : " << plth[tengah].umur<<endl<<endl;
            return;
        }
        if (plth[tengah].nama < CariNama)
            kiri = tengah + 1;
        else
            kanan = tengah - 1;
    }

    cout << "Pelatih tidak ditemukan.\n";
}

//Binary search berdasarkan jabatan pelatih
void CariPelatihJabatanBinary() {
    sortingJabatanPelatih(); // Pastikan data terurut sebelum pencarian

    string CariJabatan;
    cout << "\nMasukkan jabatan yang ingin dicari : ";
    getline(cin, CariJabatan);

    int kiri = 0, kanan = jumlahpelatih - 1;
    while (kiri <= kanan) {
        int tengah = (kiri + kanan) / 2;

        if (plth[tengah].jabatan == CariJabatan) {
            cout << "Nama        : " << plth[tengah].nama<<endl;
            cout << "Jabatan     : " << plth[tengah].jabatan<<endl;
            cout << "Umur        : " << plth[tengah].umur<<endl<<endl;
            return;
        }
        if (plth[tengah].jabatan < CariJabatan)
            kiri = tengah + 1;
        else
            kanan = tengah - 1;
    }

    cout << "Pelatih tidak ditemukan.\n";
}

//Binary search berdasarkan umur pelatih
void CariPelatihUmurBinary() {
    sortingUmurPelatih(); // Pastikan data terurut sebelum pencarian

    int CariUmur;
    cout << "\nMasukkan umur yang ingin dicari : ";
    cin>>CariUmur;

    int kiri = 0, kanan = jumlahpelatih - 1;
    while (kiri <= kanan) {
        int tengah = (kiri + kanan) / 2;

        if (plth[tengah].umur == CariUmur) {
            cout << "Nama        : " << plth[tengah].nama<<endl;
            cout << "Jabatan     : " << plth[tengah].jabatan<<endl;
            cout << "Umur        : " << plth[tengah].umur<<endl<<endl;
            return;
        }
        if (plth[tengah].umur < CariUmur)
            kiri = tengah + 1;
        else
            kanan = tengah - 1;
    }

    cout << "Pelatih tidak ditemukan.\n";
}

//Menu Binary Search pelatih
void MenuCariPelatihBinary(){
    if(jumlahpelatih == 0){
        cout<<"Belum ada pelatih yang ditambahkan!"<<endl;
        return;
    }
    int pilih;
    cout<<"Cari pelatih berdasarkan "<<endl;
    cout<<"1. Nama"<<endl;
    cout<<"2. Jabatan"<<endl;
    cout<<"3. Umur"<<endl;
    cout<<"4. Kembali"<<endl;
    cout<<"Pilih Menu : ";
    cin>>pilih;
    cin.ignore();
     
    cout<<endl;
    switch (pilih){
        case 1: {CariPelatihNamaBinary();
            break;
        }
        case 2: {CariPelatihJabatanBinary();
            break;
        }
        case 3: {CariPelatihUmurBinary();
            break;
        }
        case 4: 
            return;
        default: cout << "Pilihan tidak valid!\n";
            break;
    }
}

void MenuCariPelatih(){
    if (jumlahpelatih == 0){
        cout<<"Belum ada pelatih yang ditambahkan!"<<endl;
        return;
    }

    int pil;
    do{
        cout<<"Cari Pelatih dengan metode "<<endl;
        cout<<"1. Sequential Search"<<endl;
        cout<<"2. Binary Search"<<endl;
        cout<<"3. Kembali"<<endl;
        cout<<"pilih menu : ";
        cin>>pil;
        cin.ignore();
        cout<<endl;

            switch (pil){

            case 1:{ MenuCariPelatihSequential();
                break;
            }
            case 2:{ MenuCariPelatihBinary();
                break;
            }    
            case 3: 
                return;
        
            default: cout << "Pilihan tidak valid!\n";
                break;
            }

    } while (pil != 3);
    return;
}

// fungsi untuk menghapus pelatih
void hapusPelatih() {
    if (jumlahpelatih == 0) {
        cout << "Belum ada pelatih yang ditambahkan!" << endl;
        return;
    }

    string namaHapus;
    cin.ignore();
    cout << "Masukkan nama pelatih yang ingin dihapus: ";
    getline(cin, namaHapus);

    bool ditemukan = false;

    for (int i = 0; i < jumlahpelatih; i++) {
        if (plth[i].nama == namaHapus) {
            ditemukan = true;
            // Geser elemen setelah pelatih yang dihapus
            for (int j = i; j < jumlahpelatih - 1; j++) {
                plth[j] = plth[j + 1];
            }
            jumlahpelatih--; // kurangi jumlah pelatih
            cout << "Pelatih \"" << namaHapus << "\" berhasil dihapus!" << endl;
            break;
        }
    }

    if (!ditemukan) {
        cout << "Pelatih dengan nama \"" << namaHapus << "\" tidak ditemukan!" << endl;
    }
}

//fungsi untuk memperbarui data pelatih
void updatePelatih() {
    string cariNama;
    cout<<"Masukkan nama pelatih yang ingin diupdate : ";
    cin.ignore();
    getline(cin, cariNama);

    bool ditemukan = false;
    
    for(int i = 0; i < jumlahpelatih; i++){
        Kepelatihan* p = &plth[i];

        if(p->nama == cariNama){
            cout<<"Data ditemukan. Masukkan data baru!"<<endl;
            cout<<"Nama baru     : ";
            getline(cin, p->nama);
            cout<<"Jabatan baru  : ";
            getline(cin, p->jabatan);
            cout<<"Umur baru     : ";
            cin>>p->umur;
            ditemukan = true;
            cout<<"Data pelatih berhasil diperbarui!"<<endl;
            break;
        }

    }
    if (!ditemukan){
        cout<<"Pelatih dengan nama tersebut tidak ditemukan!"<<endl;
    }
}


//========================================================================================

//no punggung tidak boleh sama
bool NoPunggungSudahAda(int no_punggung){
    for(int i = 0; i < jumlahPemain; i++){
        if(pmn[i].nopunggung == no_punggung){
            return true;
        }
    }
    return false;
}


//buble sort nama
void sortNama() {
    for (int i = 0; i < jumlahPemain - 1; i++) {
        for (int j = 0; j < jumlahPemain - i - 1; j++) {
            if (pmn[j].nama > pmn[j + 1].nama) {
                swap(pmn[j], pmn[j + 1]);
            }
        }
    }
}

//buble sort posisi
void sortPosisi() {
    for (int i = 0; i < jumlahPemain - 1; i++) {
        for (int j = 0; j < jumlahPemain - i - 1; j++) {
            if (pmn[j].posisi > pmn[j + 1].posisi) {
                swap(pmn[j], pmn[j + 1]);
            }
        }
    }
}


//buble sort no punggung pemain
void sortNoPunggung() {
    for (int i = 0; i < jumlahPemain - 1; i++) {
        for (int j = 0; j < jumlahPemain - i - 1; j++) {
            if (pmn[j].nopunggung > pmn[j + 1].nopunggung) {
                swap(pmn[j], pmn[j + 1]);
            }
        }
    }
}

//buble sort umur pemain
void sortUmur() {
    for (int i = 0; i < jumlahPemain - 1; i++) {
        for (int j = 0; j < jumlahPemain - i - 1; j++) {
            if (pmn[j].umur > pmn[j + 1].umur) {
                swap(pmn[j], pmn[j + 1]);
            }
        }
    }
}

//buble sort tinggi pemain
void sortTinggi() {
    for (int i = 0; i < jumlahPemain - 1; i++) {
        for (int j = 0; j < jumlahPemain - i - 1; j++) {
            if (pmn[j].tinggi > pmn[j + 1].tinggi) {
                swap(pmn[j], pmn[j + 1]);
            }
        }
    }
}


//nyimpen data ke array
void tambahPemain(){
    if(jumlahPemain >= 20){
        cout<<"kapasitas pemain sudah penuh!";
        return;
    }
    
        pemain p;
        cout << "\n====================="<<endl;
        cout << "|TAMBAH PEMAIN KE-"<<jumlahPemain + 1<<" |"<<endl;
        cout << "====================="<<endl;
        cin.ignore();

        cout << "Masukkan Nama        : ";
        getline(cin, p.nama);

        cout << "Masukkan Posisi      : ";
        getline(cin, p.posisi);

        int nomor;
        do{
            cout << "Masukkan No Punggung : ";
            cin >> nomor;
            if(NoPunggungSudahAda(nomor)){
                cout<<"Nomor punggung sudah digunakan! masukkan nomor lain!"<<endl;
            }
        }while(NoPunggungSudahAda(nomor));
        p.nopunggung = nomor;

        cout << "Masukkan Umur        : ";
        cin >> p.umur;

        cout << "Masukkan Tinggi(cm)  : ";
        cin >> p.tinggi;

        pmn[jumlahPemain++] = p;
        cout<<"Pemain berhasil ditambahkan!"<<endl<<endl;
    
};

// Fungsi untuk menyimpan data pemain ke file
void simpanPemainKeFile() {
    ofstream file("data_pemain.txt");
    if (!file) {
        cout << "Gagal membuka file untuk menulis.\n";
        return;
    }

    for (int i = 0; i < jumlahPemain; i++) {
        file << pmn[i].nama << endl;
        file << pmn[i].posisi << endl;
        file << pmn[i].nopunggung << endl;
        file << pmn[i].umur << endl;
        file << pmn[i].tinggi << endl;
    }

    file.close();
    cout << "Data pemain berhasil disimpan ke file.\n";
}

// Fungsi untuk memuat data pemain dari file
void muatPemainDariFile() {
    ifstream file("data_pemain.txt");
    if (!file) {
        cout << "File tidak ditemukan atau gagal dibuka.\n";
        return;
    }

    jumlahPemain = 0;
    while (jumlahPemain < 20) {
        pemain pm;
        if (!getline(file, pm.nama)) break;
        if (!getline(file, pm.posisi)) break;
        if (!(file >> pm.nopunggung)) break;
        if (!(file >> pm.umur)) break;
        if (!(file >> pm.tinggi)) break;
        file.ignore(); // Buang newline sisa input baris angka

        pmn[jumlahPemain] = pm;
        jumlahPemain++;
    }

    file.close();
    cout << "Data pemain berhasil dimuat dari file.\n";
}


//tampilkan pemain sebelum sorting dengan rekursif
void tampilkanPemainSebelumSorting(int index){
    if(index == jumlahPemain) return;

    cout << "----------------------------"<<endl;
    cout << "|       PEMAIN KE- " << index + 1<<"       |"<<endl;
    cout << "----------------------------"<<endl;
    cout << "Nama        : "<<pmn[index].nama <<endl;
    cout << "Posisi      : "<<pmn[index].posisi <<endl;
    cout << "No Punggung : "<<pmn[index].nopunggung <<endl;
    cout << "Umur        : "<<pmn[index].umur <<endl;
    cout << "Tinggi      : "<<pmn[index].tinggi<< " (cm)" <<endl<<endl;
  
    tampilkanPemainSebelumSorting(index + 1);

};

//tampilkan pemain setelah sorting no punggung  dengan rekursif
void tampilkanPemainSortNoPunggung(int index = 0, bool sort = false){

    if (!sort) {
        sortNoPunggung(); 
    }

    if(index == jumlahPemain) return;

    cout << "----------------------------"<<endl;
    cout << "|       PEMAIN KE- " << index + 1<<"       |"<<endl;
    cout << "----------------------------"<<endl;
    cout << "Nama        : "<<pmn[index].nama <<endl;
    cout << "Posisi      : "<<pmn[index].posisi <<endl;
    cout << "No Punggung : "<<pmn[index].nopunggung <<endl;
    cout << "Umur        : "<<pmn[index].umur <<endl;
    cout << "Tinggi      : "<<pmn[index].tinggi <<endl<<endl;
  
    tampilkanPemainSortNoPunggung(index + 1, true);

};

//tampilkan pemain setelah sorting umur  dengan rekursif
void tampilkanPemainSortUmur(int index = 0, bool sort = false){

    if (!sort) {
        sortUmur(); 
    }

    if(index == jumlahPemain) return;

    cout << "----------------------------"<<endl;
    cout << "|       PEMAIN KE- " << index + 1<<"       |"<<endl;
    cout << "----------------------------"<<endl;
    cout << "Nama        : "<<pmn[index].nama <<endl;
    cout << "Posisi      : "<<pmn[index].posisi <<endl;
    cout << "No Punggung : "<<pmn[index].nopunggung <<endl;
    cout << "Umur        : "<<pmn[index].umur <<endl;
    cout << "Tinggi      : "<<pmn[index].tinggi <<endl<<endl;
  
    tampilkanPemainSortUmur(index + 1, true);

};

//tampilkan pemain setelah sorting tinggi  dengan rekursif
void tampilkanPemainSortTinggi(int index = 0, bool sort = false){

    if (!sort) {
        sortTinggi(); 
    }

    if(index == jumlahPemain) return;

    cout << "----------------------------"<<endl;
    cout << "|       PEMAIN KE- " << index + 1<<"       |"<<endl;
    cout << "----------------------------"<<endl;
    cout << "Nama        : "<<pmn[index].nama <<endl;
    cout << "Posisi      : "<<pmn[index].posisi <<endl;
    cout << "No Punggung : "<<pmn[index].nopunggung <<endl;
    cout << "Umur        : "<<pmn[index].umur <<endl;
    cout << "Tinggi      : "<<pmn[index].tinggi <<endl<<endl;
  
    tampilkanPemainSortTinggi(index + 1, true);

};

//fungsi untuk memilih sorting berdasarkan apa
void setelahSortBerdasarkan(){
    int pilih;

    do{
        cout<<"=== BERDASARKAN ==="<<endl;
        cout<<"1. No Punggung"<<endl;
        cout<<"2. Umur"<<endl;
        cout<<"3. Tinggi"<<endl;
        cout<<"4. kembali"<<endl;
        cout<<"input pilihan : ";
        cin>>pilih;
        cout<<endl;

        switch (pilih){
            case 1:{
                tampilkanPemainSortNoPunggung();
                break;
            }    
            case 2:{
                tampilkanPemainSortUmur();
                break;
            }    
            case 3:{
                tampilkanPemainSortTinggi();
                break;
            }    
            case 4:
                return;
            default: cout<<"pilihan tidak valid"<<endl;
                break;
    }
    } while (pilih != 4);
    return;
}

//fungsi Menu tampilkan pemain
void MenuTampilkanPemain(){
    int pilih;
    if(jumlahPemain == 0){
        cout<<"belum ada pemain yang ditambahkan!"<<endl;
    }

    do{
        cout<<"===Menu Tampilkan Pemain==="<<endl;
        cout<<"1. Sebelum di sorting"<<endl;
        cout<<"2. Setelah di sorting"<<endl;
        cout<<"3. kembali"<<endl;
        cout<<"input pilihan : ";
        cin>>pilih;
        cout<<endl;

        switch (pilih){
            case 1:{
                tampilkanPemainSebelumSorting(0);
                break;
            }    
            case 2:{
                setelahSortBerdasarkan();
                break;
            }    
            case 3:
                return;
            default: cout<<"pilihan tidak valid"<<endl;
                break;
    }
    } while (pilih != 3);
    return;
}


// sequential search berdasarkan nama
void CariPemainNamaSequential(string targetNama){
    bool found = false;
    for(int i = 0; i < jumlahPemain; i++){
        if(pmn[i].nama == targetNama){
            cout<<"Pemain ditemukan!"<<endl;
            cout<<"Nama        : "<<pmn[i].nama<<endl;
            cout<<"Posisi      : "<<pmn[i].posisi<<endl;
            cout<<"No punggung : "<<pmn[i].nopunggung<<endl;
            cout<<"Umur        : "<<pmn[i].umur<<endl;
            cout<<"Tinggi      : "<<pmn[i].tinggi<<endl<<endl;
            found = true;
            break;
        }
    }
    if(!found){
        cout<<"Pemain dengan nama "<<targetNama<<" tidak ditemukan!"<<endl;
    }
}

//sequential search berdasarkan posisi
void CariPemainPosisiSequential(string targetPosisi){
    bool found = false;
    for(int i = 0; i < jumlahPemain; i++){
        if(pmn[i].posisi == targetPosisi){
            cout<<"Pemain ditemukan!"<<endl;
            cout<<"Nama        : "<<pmn[i].nama<<endl;
            cout<<"Posisi      : "<<pmn[i].posisi<<endl;
            cout<<"No punggung : "<<pmn[i].nopunggung<<endl;
            cout<<"Umur        : "<<pmn[i].umur<<endl;
            cout<<"Tinggi      : "<<pmn[i].tinggi<<endl<<endl;
            found = true;
        }
    }
    if(!found){
        cout<<"Pemain dengan nama "<<targetPosisi<<" tidak ditemukan!"<<endl;
    }

}
//sequential search berdasarkan no punggung
void CariPemainNoPunggungSequential(int targetNomor){
    bool found = false;
    for(int i = 0; i < jumlahPemain; i++){
        if(pmn[i].nopunggung == targetNomor){
            cout<<"Pemain ditemukan!"<<endl;
            cout<<"Nama        : "<<pmn[i].nama<<endl;
            cout<<"Posisi      : "<<pmn[i].posisi<<endl;
            cout<<"No punggung : "<<pmn[i].nopunggung<<endl;
            cout<<"Umur        : "<<pmn[i].umur<<endl;
            cout<<"Tinggi      : "<<pmn[i].tinggi<<endl<<endl;;
            found = true;
        }
    }
    if(!found){
        cout<<"Pemain dengan nama "<<targetNomor<<" tidak ditemukan!"<<endl;
    }

}
//sequential search berdasarkan umur
void CariPemainUmurSequential(int targetUmur){
    bool found = false;
    for(int i = 0; i < jumlahPemain; i++){
        if(pmn[i].umur == targetUmur){
            cout<<"Pemain ditemukan!"<<endl;
            cout<<"Nama        : "<<pmn[i].nama<<endl;
            cout<<"Posisi      : "<<pmn[i].posisi<<endl;
            cout<<"No punggung : "<<pmn[i].nopunggung<<endl;
            cout<<"Umur        : "<<pmn[i].umur<<endl;
            cout<<"Tinggi      : "<<pmn[i].tinggi<<endl<<endl;
            found = true;
        }
    }
    if(!found){
        cout<<"Pemain dengan nama "<<targetUmur<<" tidak ditemukan!"<<endl;
    }

}
//sequential search berdasarkan tinggi
void CariPemainTinggiSequential(int targetTinggi){
    bool found = false;
    for(int i = 0; i < jumlahPemain; i++){
        if(pmn[i].tinggi == targetTinggi){
            cout<<"Pemain ditemukan!"<<endl;
            cout<<"Nama        : "<<pmn[i].nama<<endl;
            cout<<"Posisi      : "<<pmn[i].posisi<<endl;
            cout<<"No punggung : "<<pmn[i].nopunggung<<endl;
            cout<<"Umur        : "<<pmn[i].umur<<endl;
            cout<<"Tinggi      : "<<pmn[i].tinggi<<endl<<endl;
            found = true;
        }
    }
    if(!found){
        cout<<"Pemain dengan nama "<<targetTinggi<<" tidak ditemukan!"<<endl;
    }

}

//Menu sequential search pemain
void MenuCariPemainSequential(){
    if(jumlahPemain == 0){
        cout<<"Belum ada pemain yang ditambahkan!"<<endl;
        return;
    }
    int pilih;
    cout<<"Cari pemain berdasarkan "<<endl;
    cout<<"1. Nama"<<endl;
    cout<<"2. Posisi"<<endl;
    cout<<"3. No Punggung"<<endl;
    cout<<"4. Umur"<<endl;
    cout<<"5. Tinggi"<<endl;
    cout<<"6. kembali"<<endl;
    cout<<"Pilih Menu : ";
    cin>>pilih;
    cin.ignore();
    cout<<endl;

    switch (pilih){
        case 1:{
            string NamaPemain;
            cout<<"Masukkan Nama Pemain : ";
            getline(cin, NamaPemain);
            CariPemainNamaSequential(NamaPemain);
            break;
        }

        case 2:{
            string PosisiPemain;
            cout<<"Masukkan Posisi Pemain : ";
            getline(cin, PosisiPemain);
            CariPemainPosisiSequential(PosisiPemain);
            break;
        }

        case 3:{
            int NoPunggung;
            cout<<"Masukkan No Punggung Pemain : ";
            cin>>NoPunggung;
            CariPemainNoPunggungSequential(NoPunggung);
            break;
        }

        case 4:{
            int Umur;
            cout<<"Masukkan Umur Pemain : ";
            cin>>Umur;
            CariPemainUmurSequential(Umur);
            break;
        }

        case 5:{
            int Tinggi;
            cout<<"Masukkan Tinggi Pemain : ";
            cin>>Tinggi;
            CariPemainTinggiSequential(Tinggi);
            break;
        }

        default: cout << "Pilihan tidak valid!\n";
            break;
    }
}


//Binary search berdasarkan nama
void CariPemainNamaBinary() {
    sortNama(); // Pastikan data terurut sebelum pencarian

    string CariNama;
    cout << "\nMasukkan nama yang ingin Dicari : ";
    getline(cin, CariNama);

    int kiri = 0, kanan = jumlahPemain - 1;
    while (kiri <= kanan) {
        int tengah = (kiri + kanan) / 2;

        if (pmn[tengah].nama == CariNama) {
            cout << "Nama        : " << pmn[tengah].nama<<endl;
            cout << "Posisi      : " << pmn[tengah].posisi<<endl;
            cout << "No punggung : " << pmn[tengah].nopunggung<<endl;
            cout << "Umur        : " << pmn[tengah].umur<<endl;
            cout << "Tinggi      : " << pmn[tengah].tinggi<<endl<<endl;
            return;
        }
        if (pmn[tengah].nama < CariNama)
            kiri = tengah + 1;
        else
            kanan = tengah - 1;
    }

    cout << "Pemain tidak ditemukan.\n";
}

//Binary search berdasarkan posisi
void CariPemainPosisiBinary() {
    sortPosisi(); // Pastikan data terurut sebelum pencarian

    string CariPosisi;
    cout << "\nMasukkan posisi yang ingin Dicari : ";
    getline(cin, CariPosisi);

    int kiri = 0, kanan = jumlahPemain - 1;
    while (kiri <= kanan) {
        int tengah = (kiri + kanan) / 2;

        if (pmn[tengah].posisi == CariPosisi) {
            cout << "Nama        : " << pmn[tengah].nama<<endl;
            cout << "Posisi      : " << pmn[tengah].posisi<<endl;
            cout << "No punggung : " << pmn[tengah].nopunggung<<endl;
            cout << "Umur        : " << pmn[tengah].umur<<endl;
            cout << "Tinggi      : " << pmn[tengah].tinggi<<endl<<endl;
            return;
        }
        if (pmn[tengah].posisi < CariPosisi)
            kiri = tengah + 1;
        else
            kanan = tengah - 1;
    }

    cout << "Pemain tidak ditemukan.\n";
}

//Binnary search berdasarkan no punggung
void CariPemainNoPunggungBinary() {
    sortNoPunggung(); // Pastikan data terurut sebelum pencarian

    int Carinomor;
    cout << "\nMasukkan Nomor Punggung yang ingin Dicari : ";
    cin >> Carinomor;

    int kiri = 0, kanan = jumlahPemain - 1;
    while (kiri <= kanan) {
        int tengah = (kiri + kanan) / 2;

        if (pmn[tengah].nopunggung == Carinomor) {
            cout << "Nama        : " << pmn[tengah].nama<<endl;
            cout << "Posisi      : " << pmn[tengah].posisi<<endl;
            cout << "No punggung : " << pmn[tengah].nopunggung<<endl;
            cout << "Umur        : " << pmn[tengah].umur<<endl;
            cout << "Tinggi      : " << pmn[tengah].tinggi<<endl<<endl;
            return;
        }
        if (pmn[tengah].nopunggung < Carinomor)
            kiri = tengah + 1;
        else
            kanan = tengah - 1;
    }

    cout << "Pemain tidak ditemukan.\n";
}

//Binary search berdasarkan umur
void CariPemainUmurBinary() {
    sortUmur(); // Pastikan data terurut sebelum pencarian

    int CariUmur;
    cout << "\nMasukkan Umur yang ingin Dicari : ";
    cin >> CariUmur;

    int kiri = 0, kanan = jumlahPemain - 1;
    while (kiri <= kanan) {
        int tengah = (kiri + kanan) / 2;

        if (pmn[tengah].umur == CariUmur) {
            cout << "Nama        : " << pmn[tengah].nama<<endl;
            cout << "Posisi      : " << pmn[tengah].posisi<<endl;
            cout << "No punggung : " << pmn[tengah].nopunggung<<endl;
            cout << "Umur        : " << pmn[tengah].umur<<endl;
            cout << "Tinggi      : " << pmn[tengah].tinggi<<endl<<endl;
            return;
        }
        if (pmn[tengah].umur < CariUmur)
            kiri = tengah + 1;
        else
            kanan = tengah - 1;
    }

    cout << "Pemain tidak ditemukan.\n";
}

//Binary search berdasarkan tinggi
void CariPemainTinggiBinary() {
    sortTinggi(); // Pastikan data terurut sebelum pencarian

    int CariTinggi;
    cout << "\nMasukkan Tinggi yang ingin Dicari (cm) : ";
    cin >> CariTinggi;

    int kiri = 0, kanan = jumlahPemain - 1;
    while (kiri <= kanan) {
        int tengah = (kiri + kanan) / 2;

        if (pmn[tengah].tinggi == CariTinggi) {
            cout << "Nama        : " << pmn[tengah].nama<<endl;
            cout << "Posisi      : " << pmn[tengah].posisi<<endl;
            cout << "No punggung : " << pmn[tengah].nopunggung<<endl;
            cout << "Umur        : " << pmn[tengah].umur<<endl;
            cout << "Tinggi      : " << pmn[tengah].tinggi<<endl<<endl;
            return;
        }
        if (pmn[tengah].tinggi < CariTinggi)
            kiri = tengah + 1;
        else
            kanan = tengah - 1;
    }

    cout << "Pemain tidak ditemukan.\n";
}


//Menu Binary Search pemain
void MenuCariPemainBinary(){
    if(jumlahPemain == 0){
        cout<<"Belum ada pemain yang ditambahkan!"<<endl;
        return;
    }
    int pilih;
    cout<<"Cari pemain berdasarkan "<<endl;
    cout<<"1. Nama"<<endl;
    cout<<"2. Posisi"<<endl;
    cout<<"3. No Punggung"<<endl;
    cout<<"4. Umur"<<endl;
    cout<<"5. Tinggi"<<endl;
    cout<<"6. Kembali"<<endl;
    cout<<"Pilih Menu : ";
    cin>>pilih;
    cin.ignore();

    switch (pilih){
        case 1: {CariPemainNamaBinary();
            break;
        }    
        
        case 2: {
            CariPemainPosisiBinary();
            break;
        }    
        
        case 3: {
            CariPemainNoPunggungBinary();
            break;
        }    
        
        case 4: {
            CariPemainUmurBinary();
            break;
        }    

        case 5: {
            CariPemainTinggiBinary();
            break;
        }    
        case 6: 
            return;

        default:
             cout << "Pilihan tidak valid!\n";
            break;
    }
}

// fungsi untuk menu cari pemain berdasarkan metodenya
void MenuCariPemain(){
    if (jumlahPemain == 0){
        cout<<"Belum ada pemain yang ditambahkan!"<<endl;
        return;
    }

    int pil;
    do{
        cout<<"Cari Pemain dengan metode "<<endl;
        cout<<"1. Sequential Search"<<endl;
        cout<<"2. Binary Search"<<endl;
        cout<<"3. Kembali"<<endl;
        cout<<"pilih menu : ";
        cin>>pil;
        cin.ignore();
        cout<<endl;

            switch (pil){
            case 1: {MenuCariPemainSequential();
                break;
            }    
            case 2: {MenuCariPemainBinary();
                break;
            }    
            case 3: 
                return;
        
            default: cout << "Pilihan tidak valid!\n";
                break;
            }

    } while (pil != 3);
    return;
}

// fungsi untuk menghapus data pemain
void hapusPemain() {
    if (jumlahPemain == 0) {
        cout << "Belum ada pemain yang ditambahkan!" << endl;
        return;
    }

    string namaHapus;
    cin.ignore();
    cout << "Masukkan nama pemain yang ingin dihapus: ";
    getline(cin, namaHapus);

    bool ditemukan = false;

    for (int i = 0; i < jumlahPemain; i++) {
        if (pmn[i].nama == namaHapus) {
            ditemukan = true;
            // Geser elemen setelah pemain yang dihapus
            for (int j = i; j < jumlahPemain - 1; j++) {
                pmn[j] = pmn[j + 1];
            }
            jumlahPemain--; // kurangi jumlah pemain
            cout << "Pemain \"" << namaHapus << "\" berhasil dihapus!" << endl;
            break;
        }
    }

    if (!ditemukan) {
        cout << "Pemain dengan nama \"" << namaHapus << "\" tidak ditemukan!" << endl;
    }
}

//fungsi untuk memperbarui data pemain
void updatePemain() {
    string cariNama;
    cout<<"Masukkan nama pemain yang ingin diupdate : ";
    cin.ignore();
    getline(cin, cariNama);

    bool ditemukan = false;
    
    for(int i = 0; i < jumlahPemain; i++){
        pemain* p = &pmn[i];

        if(p->nama == cariNama){
            cout<<"Data ditemukan. Masukkan data baru!"<<endl;
            cout<<"Nama baru        : ";
            getline(cin, p->nama);
            cout<<"Posisi baru      : ";
            getline(cin, p->posisi);
            cout<<"No punggung baru : ";
            cin>>p->nopunggung;
            cout<<"Umur baru        : ";
            cin>>p->umur;
            cout<<"Tinggi baru(cm)  : ";
            cin>>p->tinggi;
            ditemukan = true;
            cout<<"Data pemain berhasil diperbarui!"<<endl;
            break;
        }

    }
    if (!ditemukan){
        cout<<"Pemain dengan nama tersebut tidak ditemukan!"<<endl;
    }
}
  

// fungsi untuk menu pemain
void MenuPemain(){
    int pilihan;
    do {
        cout<<"==========================="<<endl;
        cout<<"|       MENU PEMAIN       |"<<endl;
        cout<<"==========================="<<endl;
        cout << "1. Tambah Pemain (array)"<<endl;
        cout << "2. Simpan Perubahan Pemain ke File (ofstream)"<<endl;
        cout << "3. Muat Data Pemain dari File (iftream)"<<endl;
        cout << "4. Tampilkan Pemain (sort, rekursif)"<<endl;
        cout << "5. Cari Pemain (search)"<<endl;
        cout << "6. Hapus Pemain"<<endl;
        cout << "7. Update pemain (pointer)"<<endl;
        cout << "8. kembali"<<endl;
        cout << "Pilih menu : ";
        cin >> pilihan;
        cout<<endl;

        switch (pilihan) {
            case 1:{ tambahPemain(); 
                break;
            }    
            case 2:{ simpanPemainKeFile();
                break;
            }
            case 3:{ muatPemainDariFile();
                break;
            }
            case 4:{
                if (jumlahPemain == 0){
                    cout<<"Belum ada pemain yang ditambahkan!"<<endl;
                }
                else{
                    MenuTampilkanPemain();
                }
                break;
            }        
            case 5:{ MenuCariPemain();
                break;
            }    
            case 6:{ hapusPemain();
                break;
            }   
            case 7: { updatePemain();
                break;
            }
            case 8:
                return;

            default: cout << "Pilihan tidak valid!\n";
        }
    } while (pilihan != 8);

    return;

}

//fungsi untuk menu pelatih
void MenuPelatih(){
    int pilihan;
    do {
        cout<<"==========================="<<endl;
        cout<<"|       MENU PELATIH       |"<<endl;
        cout<<"==========================="<<endl;
        cout << "1. Tambah Pelatih (array)"<<endl;
        cout << "2. Simpan Perubahan Pelatih ke File (ofstream)"<<endl;
        cout << "3. Muat Data Pelatih dari File (ifstream)"<<endl;
        cout << "4. Tampilkan Pelatih (sort, rekursif)"<<endl;
        cout << "5. Cari Pelatih (search)"<<endl;
        cout << "6. Hapus Pelatih"<<endl;
        cout << "7. Update pelatih (pointer)"<<endl;
        cout << "8. kembali"<<endl;
        cout << "Pilih menu : ";
        cin >> pilihan;
        cout<<endl;

        switch (pilihan) {
            case 1:{ tambahPelatih(); 
                break;
            }    
            case 2:{ simpanPelatihKeFile();
                break;
            }
            case 3:{ muatPelatihDariFile();
                break;
            }
            case 4:{
                if (jumlahpelatih == 0){
                    cout<<"Belum ada pelatih yang ditambahkan!"<<endl;
                }
                else{
                    MenuTampilkanPelatih();
                }
                break;
            }    

            case 5:{ MenuCariPelatih();
                break;
            }    
            case 6:{ hapusPelatih();
                break;
            }    
            case 7:{ updatePelatih(); 
                break;
            }
            case 8:{
                return;
            }

            default: cout << "Pilihan tidak valid!\n";
        }
    } while (pilihan != 8);

    return;

}

void MenuUtama(){
    int pilihan;
    do {
        cout<<"==========================="<<endl;
        cout<<"|       MENU UTAMA        |"<<endl;
        cout<<"==========================="<<endl;
        cout << "1. Pemain"<<endl;
        cout << "2. Pelatih"<<endl;
        cout << "3. keluar"<<endl;
        cout << "Pilih menu : ";
        cin >> pilihan;
        cout<<endl;

        switch (pilihan) {
            case 1:{ MenuPemain(); 
                break;
            }    
            case 2:{ MenuPelatih();
                break;
            }    
            case 3:{ cout << "Keluar dari program...\n"; 
                return;
            }    

            default: cout << "Pilihan tidak valid!\n";
        }
    } while (pilihan != 3);

    return;

}

void registrasiAkun() {
    string username, password;
    cout << "\n=== REGISTRASI AKUN ===" << endl;
    cout << "Buat Username: ";
    cin >> username;
    cout << "Buat Password: ";
    cin >> password;

    ofstream file("akun.txt", ios::app); // simpan di akhir file
    if (!file) {
        cout << "Gagal menyimpan akun ke file.\n";
        return;
    }

    file << username << " " << password << endl;
    file.close();

    cout << "Akun berhasil dibuat!\n\n";
}

bool loginBerhasil() {
    string username, password, fileUser, filePass;
    cout << "\n=== LOGIN ===" << endl;
    cout << "Username: ";
    cin >> username;
    cout << "Password: ";
    cin >> password;

    ifstream file("akun.txt");
    if (!file) {
        cout << "Belum ada akun. Silakan registrasi terlebih dahulu.\n";
        return false;
    }

    while (file >> fileUser >> filePass) {
        if (username == fileUser && password == filePass) {
            cout << "Login berhasil!\n\n";
            return true;
        }
    }

    cout << "Login gagal! Username atau password salah.\n";
    return false;
}

int main() {
    int pilihan;

    do {
        cout << "============================" << endl;
        cout << "|     SELAMAT DATANG      |" << endl;
        cout << "============================" << endl;
        cout << "1. Login\n";
        cout << "2. Registrasi\n";
        cout << "3. Keluar\n";
        cout << "Pilih menu: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                if (loginBerhasil()) {
                    MenuUtama(); // ✅ Masuk ke menu utama jika login berhasil
                    return 0;
                } else {
                    cout << "Kembali ke menu utama...\n\n";
                }
                break;

            case 2:
                registrasiAkun();
                break;

            case 3:
                cout << "Keluar dari program.\n";
                return 0;

            default:
                cout << "Pilihan tidak valid!\n";
        }

    } while (true);

    return 0;
}
