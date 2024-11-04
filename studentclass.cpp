#include <iostream>
using namespace std;

class Mahasiswa {
private:
    string nama;
    int umur;
    float nilai;

public:
    // Setter
    void setNama(string n) {
        nama = n;
    }

    void setUmur(int u) {
        umur = u;
    }

    void setNilai(float n) {
        nilai = n;
    }

    // Getter
    string getNama() {
        return nama;
    }

    int getUmur() {
        return umur;
    }

    float getNilai() {
        return nilai;
    }

    // Metode untuk menampilkan data
    void tampilkanInfo() {
        cout << "Nama: " << nama << "\nUmur: " << umur << "\nNilai: " << nilai << endl;
    }
};

int main() {
    Mahasiswa mhs1;
    mhs1.setNama("Joy");
    mhs1.setUmur(20);
    mhs1.setNilai(90.5);
    mhs1.tampilkanInfo();

    return 0;
}