# Sistem Rekomendasi Jurusan Tree

Sistem rekomendasi jurusan kuliah menggunakan struktur data Decision Tree (Pohon Keputusan) yang diimplementasikan dalam bahasa C++.

## Deskripsi

Program ini membantu pengguna mendapatkan rekomendasi jurusan kuliah berdasarkan minat dan preferensi mereka melalui serangkaian pertanyaan. Sistem menggunakan algoritma decision tree untuk melakukan traversal dan pencarian jurusan yang sesuai.

**TUBES STRUKTUR DATA TREE**

## Fitur

1. **Pre-Order Traversal** - Menampilkan struktur tree dalam urutan pre-order
2. **In-Order Traversal** - Menampilkan struktur tree dalam urutan in-order
3. **Post-Order Traversal** - Menampilkan struktur tree dalam urutan post-order
4. **Cari Jurusan** - Mencari jurusan tertentu dalam tree
5. **Tambah Node** - Menambahkan detail/node baru ke dalam tree
6. **Konsultasi** - Mendapatkan rekomendasi jurusan melalui serangkaian pertanyaan interaktif

## Teknologi

- **Bahasa**: C++ (Standard C++17)
- **Compiler**: g++
- **IDE**: Visual Studio Code dengan C/C++ Extension
- **Debugger**: GDB

## Struktur File

```
Sistem-Rekomendasi-Jurusan-Tree/
├── main.cpp              # File utama program
├── decision_tree.cpp     # Implementasi fungsi decision tree
├── decision_tree.h       # Header file untuk decision tree
├── app                   # Binary executable (hasil kompilasi)
├── .vscode/
│   ├── tasks.json       # Konfigurasi build task
│   └── launch.json      # Konfigurasi debug
├── .gitignore           # File yang diabaikan git
└── README.md            # Dokumentasi proyek
```

## Cara Menjalankan

### Metode 1: Menggunakan VS Code (Direkomendasikan)

1. Buka proyek di VS Code
2. Tekan **F5** atau klik tombol **Run and Debug**
3. Pilih konfigurasi **Debug app (gdb)**
4. Program akan otomatis di-build dan dijalankan dengan debugging

### Metode 2: Build Task + Terminal

1. Tekan **Ctrl+Shift+B** untuk build
2. Jalankan di terminal:
   ```bash
   ./app
   ```

### Metode 3: Compile Manual di Terminal

```bash
# Masuk ke direktori proyek
cd /this/project/

# Compile program
g++ -std=c++17 main.cpp decision_tree.cpp -o app

# Jalankan program
./app
```

## 📖 Cara Penggunaan

Setelah program dijalankan, akan muncul menu utama:

```
1. Pre-Order
2. In-Order
3. Post-Order
4. Cari Jurusan
5. Tambah Node
6. Konsultasi
0. Keluar
Pilihan: 
```

### Contoh Penggunaan Fitur Konsultasi

1. Pilih menu **6. Konsultasi**
2. Jawab pertanyaan-pertanyaan yang muncul dengan **Y** (Ya) atau **T** (Tidak)
3. Program akan memberikan rekomendasi jurusan berdasarkan jawaban Anda

Contoh tree keputusan:
- Suka Logika & Hitungan? → Ya
  - Suka Ngoding/Komputer? → Ya → **Teknik Informatika**
  - Suka Ngoding/Komputer? → Tidak → **Statistika**
- Suka Logika & Hitungan? → Tidak
  - Suka Menggambar/Seni? → Ya → **Desain Komunikasi Visual**
  - Suka Menggambar/Seni? → Tidak → **Ilmu Komunikasi**

## Pengembangan

### Menambah Jurusan Baru

Anda dapat menambahkan jurusan baru dengan:
1. Modifikasi fungsi `bangunTree()` di `decision_tree.cpp`
2. Gunakan fitur **Tambah Node** saat program berjalan

### Build dengan Flag Tambahan

```bash
# Build dengan warning dan optimasi debug
g++ -std=c++17 -g -O0 -Wall -Wextra main.cpp decision_tree.cpp -o app
```

### Debug dengan GDB

```bash
# Compile dengan debug symbols
g++ -std=c++17 -g main.cpp decision_tree.cpp -o app

# Jalankan dengan GDB
gdb ./app
```

## Struktur Data

Program menggunakan struktur `Node` untuk merepresentasikan decision tree:

```cpp
struct Node {
    string isi;        // Isi pertanyaan atau nama jurusan
    bool isJurusan;    // Status: true = jurusan, false = pertanyaan
    Node *kiri;        // Child kiri (jawaban "Ya")
    Node *kanan;       // Child kanan (jawaban "Tidak")
};
```