#include "decision_tree.h"

Node* buatNode(string teks, bool status) {
    Node* baru = new Node;
    baru->isi = teks;
    baru->isJurusan = status;
    baru->kiri = NULL;
    baru->kanan = NULL;
    return baru;
}

void bangunTree(Node* &root) {
    root = buatNode("Suka Logika & Hitungan?", false);

    root->kiri = buatNode("Suka Ngoding/Komputer?", false);
    root->kanan = buatNode("Suka Menggambar/Seni?", false);

    root->kiri->kiri = buatNode("Teknik Informatika", true);
    root->kiri->kanan = buatNode("Statistika", true);

    root->kanan->kiri = buatNode("Desain Komunikasi Visual", true);
    root->kanan->kanan = buatNode("Ilmu Komunikasi", true);
}

void tambahDetail(Node* node, string target, string baru, string kiri, string kanan) {
    if (node == NULL) return;

    if (node->isi == target && node->isJurusan) {
        node->isi = baru;
        node->isJurusan = false;
        node->kiri = buatNode(kiri, true);
        node->kanan = buatNode(kanan, true);
    } else {
        tambahDetail(node->kiri, target, baru, kiri, kanan);
        tambahDetail(node->kanan, target, baru, kiri, kanan);
    }
}

bool cariJurusan(Node* node, string dicari) {
    if (node == NULL) return false;
    if (node->isi == dicari) return true;
    return cariJurusan(node->kiri, dicari) || cariJurusan(node->kanan, dicari);
}

void preOrder(Node* node) {
    if (node == NULL) return;
    if (node->isJurusan) cout << "[JURUSAN] ";
    else cout << "[TANYA] ";
    cout << node->isi << endl;
    preOrder(node->kiri);
    preOrder(node->kanan);
}

void inOrder(Node* node) {
    if (node == NULL) return;
    inOrder(node->kiri);
    cout << "- " << node->isi << endl;
    inOrder(node->kanan);
}

void postOrder(Node* node) {
    if (node == NULL) return;
    postOrder(node->kiri);
    postOrder(node->kanan);
    cout << "- " << node->isi << endl;
}

void konsultasi(Node* node) {
    if (node == NULL) return;

    if (node->isJurusan) {
        cout << "REKOMENDASI: " << node->isi << endl;
        return;
    }

    char jawab;
    cout << node->isi << " (y/n): ";
    cin >> jawab;

    if (jawab == 'y' || jawab == 'Y') {
        konsultasi(node->kiri);
    } else {
        konsultasi(node->kanan);
    }
}
