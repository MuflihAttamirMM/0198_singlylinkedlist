#include <iostream>
using namespace std;

class Node {
public:
    int noMhs;
    Node *next;
};

class LinkedList {
    Node *START;
public:
    LinkedList() {
        START = NULL;
    }

    void addNode() {
        int nim;
        cout << "\nMasukkan Nomor Induk Mahasiswa: ";
        cin >> nim;

        // Membuat node baru di memori
        Node *nodeBaru = new Node();
        nodeBaru->noMhs = nim;
        nodeBaru->next = NULL;

        // Jika list kosong atau NIM baru lebih kecil dari NIM pertama (Insert First)
        if (START == NULL || nim <= START->noMhs) {
            if ((START != NULL) && (nim == START->noMhs)) {
                cout << "\nDuplikasi noMhs tidak diizinkan\n" << endl;
                delete nodeBaru;
                return;
            }
            nodeBaru->next = START;
            START = nodeBaru;
            return;
        }

        // Mencari posisi yang tepat (Insert Middle/Last)
        Node *previous = START;
        Node *current = START;
        while ((current != NULL) && (nim >= current->noMhs)) {
            if (nim == current->noMhs) {
                cout << "\nDuplikasi noMhs tidak diizinkan\n";
                delete nodeBaru;
                return;
            }
            previous = current;
            current = current->next;
        }
        nodeBaru->next = current;
        previous->next = nodeBaru;
    }

    bool listEmpty() {
        return START == NULL;
    }

    bool Search(int nim, Node **previous, Node **current) {
        *previous = START;
        *current = START;
        while ((*current != NULL) && (nim != (*current)->noMhs)) {
            *previous = *current;
            *current = (*current)->next;
        }
        return (*current != NULL);
    }

    bool delNode(int nim) {
        Node *previous, *current;
        if (!Search(nim, &previous, &current)) {
            return false;
        }

        if (current == START) { 
            START = START->next;
        } else {
            previous->next = current->next;
        }

        delete current;
        return true;
    }

    void traverse() {
        if (listEmpty()) {
            cout << "\nList Kosong\n";
        } else {
            cout << "\nData dalam list adalah: \n";
            Node *currentNode = START;
            while (currentNode != NULL) {
                cout << currentNode->noMhs << " ";
                currentNode = currentNode->next;
            }
            cout << endl;
        }
    }
}; // Penutup class

int main() {
    LinkedList mhs;
    int nim;
    char ch;
    do {
        cout << "\nMenu" << endl;
        cout << "1. Menambah data kedalam list" << endl;
        cout << "2. Menghapus data dari dalam list" << endl;
        cout << "3. Menampilkan semua data didalam list" << endl;
        cout << "4. Mencari data dalam list" << endl;
        cout << "5. Keluar" << endl;
        cout << "\nMasukkan pilihan (1-5): ";
        cin >> ch;

        switch (ch) {
            case '1':
                mhs.addNode();
                break;
            case '2':
                if (mhs.listEmpty()) {
                    cout << "\nList Kosong" << endl;
                } else {
                    cout << "\nMasukkan nomor mahasiswa yang akan dihapus: ";
                    cin >> nim;
                    if (mhs.delNode(nim) == false)
                        cout << "\nData tidak ditemukan" << endl;
                    else
                        cout << "\nData dengan nomor mahasiswa " << nim << " berhasil dihapus" << endl;
                }
                break;
            case '3':
                mhs.traverse();
                break;
            case '4':
                if (mhs.listEmpty()) {
                    cout << "\nList Kosong\n";
                } else {
                    Node *prev, *curr;
                    cout << "\nMasukkan no mahasiswa yang dicari : ";
                    cin >> nim;
                    if (mhs.Search(nim, &prev, &curr) == false)
                        cout << "Data tidak ditemukan" << endl;
                    else {
                        cout << "Data ditemukan: " << curr->noMhs << endl;
                    }
                }
                break;
            case '5':
                cout << "Keluar..." << endl;
                break;
            default:
                cout << "Pilihan salah!" << endl;
                break;
        }
    } while (ch != '5');
}