#include <iostream>
#include <string>
#include "decision_tree.h"

using namespace std;

int main() {
    Node* root = NULL;
    int pilihan;
    string input;

    bangunTree(root);

    do {
        cout << endl;
        cout << "1. Pre-Order" << endl;
        cout << "2. In-Order" << endl;
        cout << "3. Post-Order" << endl;
        cout << "4. Cari Jurusan" << endl;
        cout << "5. Tambah Node" << endl;
        cout << "6. Konsultasi" << endl;
        cout << "0. Keluar" << endl;
        cout << "Pilihan: ";
        cin >> pilihan;

        if (pilihan == 1) {
            preOrder(root);
        }
        else if (pilihan == 2) {
            inOrder(root);
        }
        else if (pilihan == 3) {
            postOrder(root);
        }
        else if (pilihan == 4) {
            cout << "Nama Jurusan: ";
            cin.ignore();
            getline(cin, input);
            if (cariJurusan(root, input)) {
                cout << "Ditemukan" << endl;
            } else {
                cout << "Tidak Ditemukan" << endl;
            }
        }
        else if (pilihan == 5) {
            tambahDetail(root, "Teknik Informatika", "Suka Software?", "Software Engineering", "Cyber Security");
        }
        else if (pilihan == 6) {
            konsultasi(root);
        }

    } while (pilihan != 0);

    return 0;
}
