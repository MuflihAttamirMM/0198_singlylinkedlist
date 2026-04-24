#include <iostream>
using namespace std;

class Node
{
public:
    int noMhs;
    Node *next;
};

class LinkedList
{
    Node *START;
public:
    LinkedList()
    {
        START = NULL;
    }

    void addNode()
    {
        int nim;
        cout << "\nMasukkan Nomor Induk Mahasiswa: ";
        cin >> nim;

        if (START == NULL || nim <= START ->noMhs)
        {
            if ((START != NULL) && (nim == START->noMhs))
            {
                cout << "\nDuplikasi noMhs tidak diizinkan\n" << endl;
                return;
            }

            nodeBaru->next = START;
            START = nodeBaru;
            return;
        }
        Node *previous = START;
        Node *current  = START;
        
        while ((current != NULL) && (nim >= current->noMhs))
        {
            if (nim == current->noMhs)
            {
                cout << "\nDuplikasi noMhs tidak diizinkan\n";
                return;
            }
            previous = current;
            current = current->next;
        }
        nodeBaru->next = current;   
        previous->next = nodeBaru;
    }

    bool listEmpty()
    {
        return START == NULL;
    }

    bool Search(int nim, Node **previous, Node **current)
    {
        *previous = START;
        *current = START;

        while ((*current != NULL) && (nim != (*current)->noMhs))
        {
            *previous = *current;
            *current = (*current)->next;
        }
        return (*current != NULL);
    }

    bool delNode(int nim)
    {
        Node *previous, *current;
        if (!Search(nim, &previous, &current))
            return false;
        else
            previous->next = current->next;

        delete current;
        return true;
    }
    
    void traverse()
    {
        if (listEmpty())
        {
            cout << "\nList Kosong\n";
        }
        else
        {
            cout << "\nData dalam list adalah: \n";
            Node *currentNode = START;
            while (currentNode != NULL)
            {
                cout << currentNode->noMhs << endl;
                currentNode = currentNode->next;
            }
            cout << endl;
        }
    }
int main()
{
    LinkedList mhs;
    int nim;
    char ch;
    do
    {
        cout << endl;
             << "Menu";
        cout << endl;
             << "1. Menambah data jedalam list" << endl;
        cout << "2 Menghapus data dari dalam list" << endl;
        cout << "3. Menampilkan semua data didalam list" << endl;
        cout << "4. Menampilkan semya data didalam list secara terbalik" << endl;
        cout << "5. Mencari data dalam list" << endl;
        cout << "6. Keluar" << endl;
        cout << "\nMasukkan pilihan (1-6): ";
        cin >> ch;
        switch (ch)
        {
                mhs.addNode();
        }
        break;

        case '2':
            if (mhs.listEmpty())
            {
                cout << endl;
                     << "List Kosong" << endl;
                break;
            }
            cout << endl;
                 << "Masukkan nomor induk mahasiswa yang akan dihapus: ";
            cin >> nim;
            if (mhs.delNode(nim) == false)
                cout << endl;
                     << "Data tidak ditemukan" << endl;
            else
                cout << endl;
                     << "Data dengan nomor induk mahasiswa " << nim << " berhasil dihapus" << endl;
      }
      break;
      case '3':
      {
        mhs.traverse();
      }
      break;
      case '4':
      {
        if (mhs.listEmpty()== true)
        {
            cout << "\nlist kosong\n";
        }
      }
}
}