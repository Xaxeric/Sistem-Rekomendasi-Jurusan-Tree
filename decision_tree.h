#ifndef DECISION_TREE_H
#define DECISION_TREE_H

#include <iostream>
#include <string>
using namespace std;

struct Node {
    string isi;
    bool isJurusan;
    Node *kiri;
    Node *kanan;
};

Node* buatNode(string teks, bool status);
void bangunTree(Node* &root);
void tambahDetail(Node* node, string target, string baru, string kiri, string kanan);
bool cariJurusan(Node* node, string dicari);
void preOrder(Node* node);
void inOrder(Node* node);
void postOrder(Node* node);
void konsultasi(Node* node);

#endif
