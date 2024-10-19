#include <iostream>
#include "date.h"

using namespace std;

int main(void){

    Date data = Date(17, 03, 2006);
    const Date data2 = Date(18, 07, 2006);
    data.set_day(23).set_month(03).set_year(2001);
    cout << Date::get_howmany() << endl;

    return 0;
}
/*
#include <iostream>

using namespace std;

typedef int DataType;

struct Package {
    DataType ID;
    DataType WEI;
    
    Package(DataType ID, DataType WEI) : ID(ID), WEI(WEI) {}
};

struct Node {
    Package package;
    Node* Left;
    Node* Right;
    int Height;
    
    Node(Package p) : package(p), Left(nullptr), Right(nullptr), Height(1) {}
};

class treeAVL {
public:
    Node* root;

    treeAVL() : root(nullptr) {}

    int GetHeight(Node* node) {
        return node ? node->Height : 0;
    }

    int GetCoefficientB(Node* node) {
        return node ? (GetHeight(node->Left) - GetHeight(node->Right)) : 0;
    }
    int max(int a, int b){
        return (a > b) ? a : b;
    }
    Node* rotateRight(Node* y) {
        Node* x = y->Left;
        Node* T2 = x->Right;

        x->Right = y;
        y->Left = T2;

        y->Height = max(GetHeight(y->Left), GetHeight(y->Right)) + 1;
        x->Height = max(GetHeight(x->Left), GetHeight(x->Right)) + 1;

        return x;  // x now becomes the new root
    }

    Node* rotateLeft(Node* y) {
        Node* x = y->Right;
        Node* T2 = x->Left;

        x->Left = y;
        y->Right = T2;

        y->Height = max(GetHeight(y->Left), GetHeight(y->Right)) + 1;
        x->Height = max(GetHeight(x->Left), GetHeight(x->Right)) + 1;

        return x;  // x now becomes the new root
    }

    Node* insert(Node* node, Package package) {
        if (!node)
            return new Node(package);

        if (package.ID < node->package.ID) {
            node->Left = insert(node->Left, package);
        } else if (package.ID > node->package.ID) {
            node->Right = insert(node->Right, package);
        } else {
            return node;
        }

        node->Height = 1 + max(GetHeight(node->Left), GetHeight(node->Right));

        int balance = GetCoefficientB(node);

        if (balance > 1 && package.ID < node->Left->package.ID)
            return rotateRight(node);

        if (balance < -1 && package.ID > node->Right->package.ID)
            return rotateLeft(node);

        if (balance > 1 && package.ID > node->Left->package.ID) {
            node->Left = rotateLeft(node->Left);
            return rotateRight(node);
        }

        if (balance < -1 && package.ID < node->Right->package.ID) {
            node->Right = rotateRight(node->Right);
            return rotateLeft(node);
        }

        return node;
    }

    Node* search(Node* node, DataType item) {
        while (node != nullptr) {
            if (node->package.ID == item) {
                return node;
            } else if (node->package.ID < item) {
                node = node->Right;
            } else {
                node = node->Left;
            }
        }
        return nullptr;
    }

    void preOrder(Node* node) {
        if (node) {
            cout << node->package.ID << " ";
            preOrder(node->Left);
            preOrder(node->Right);
        }
    }
    int getRelativeHeight(Node* node, DataType item) {
        
        int count = 0;
        while (node != nullptr) {
            if (node->package.ID == item) {
                return count;
            } else if (node->package.ID < item) {
                node = node->Right;
            } else {
                node = node->Left;
            }
            count++;
        }
        return 0;
    }
};

int main(void) {
    treeAVL tree;
    long long int sum = 0;
    string Input = "";

    while (Input != "END") {
        getline(cin, Input);
        size_t spacePos = Input.find(' ');
        string command = Input.substr(0, spacePos);

        if (command == "ADD") {
            string rest = Input.substr(spacePos + 1);
            size_t spacePos2 = rest.find(' ');
            string strID = rest.substr(0, spacePos2);
            int ID = stoi(strID);
            int Bytes = stoi(rest.substr(spacePos2 + 1));

            Node* found2 = tree.search(tree.root, ID);
            if(found2 == nullptr){
                Package pack(ID, Bytes);
                tree.root = tree.insert(tree.root, pack);
            }else{
                found2->package.WEI+= Bytes;
            }
            
            sum = sum + Bytes;
            cout << sum << endl;

            //cout << "Pre-order traversal of the constructed AVL tree is: \n";
            //tree.preOrder(tree.root);
            //cout << endl;

        } else if (command == "WEI") {
            int ID = stoi(Input.substr(spacePos + 1));
            Node* found = tree.search(tree.root, ID);
            int height = tree.getRelativeHeight(tree.root, ID);
            if (found) {
                //cout << "Weight of package with ID " << ID << " is " << found->package.WEI << endl;
                cout << found->package.WEI << " " << height << endl;
            } else {
                cout << "Package not found." << endl;
            }
        } else if (command == "RNK") {
            int ID = stoi(Input.substr(spacePos + 1));
            // Implement ranking logic here if needed
        }
    }

    return 0;
}
*/
#include <iostream>
using namespace std;

struct client {
    int timeStamp;
    long long enderecoIP;
    client *prox;
};
int functionHash(int timeStamp, int tam) {
    return timeStamp % tam;
}

void rehash(client**& hash, int& tamInicial, int& numClients) {
    int tamNovo = 2 * tamInicial + 1;
    
    client **novaTabela = new client*[tamNovo];
    for (int i = 0; i < tamNovo; ++i) {
        novaTabela[i] = nullptr;
    }
    
    for (int i = 0; i < tamInicial; ++i) {
        client* ptr = hash[i];
        while (ptr != nullptr) {
            int novoHash = functionHash(ptr->timeStamp, tamNovo);
            
            client* newClient = new client{ptr->timeStamp, ptr->enderecoIP, novaTabela[novoHash]};
            novaTabela[novoHash] = newClient;
            
            client* oldPtr = ptr;
            ptr = ptr->prox;
            delete oldPtr;
        }
    }
    delete[] hash;
    hash = novaTabela;
    tamInicial = tamNovo;
}
int buscaElemento(client** tabelaHash, int tamInicial, int timeStamp, int& value) {
    int hash = functionHash(timeStamp, tamInicial);
    client *ptr = tabelaHash[hash];
    client *newPtr = nullptr;
    int count = 0;
    
    while (ptr != nullptr) {
        if (ptr->timeStamp == timeStamp) {
            newPtr = ptr;
        }
        ptr = ptr->prox;
        count++;
    }
    value = count;
    return newPtr != nullptr ? hash : -1;
}

client* buscarCliente(client** tabelaHash, int tamInicial, int timeStamp) {

    int hash = functionHash(timeStamp, tamInicial);


    client* ptr = tabelaHash[hash];
    while (ptr != nullptr) {
        if (ptr->timeStamp == timeStamp) {
            return ptr;
        }
        ptr = ptr->prox;
    }
    return nullptr;
}

int main() {
    int tamInicial, fatorCarga, numClients = 0;
    
    cin >> tamInicial >> fatorCarga;
    
    client **tabelaHash = new client*[tamInicial];
    for (int i = 0; i < tamInicial; ++i) {
        tabelaHash[i] = nullptr;
    }
    
    cin.ignore();

    string input;
    while (getline(cin, input)) {
        if (input == "END") break;

        size_t spacePos = input.find(' ');
        string command = input.substr(0, spacePos);

        if (command == "NEW") {
            string strResto = input.substr(spacePos + 1);
            size_t spacePosNew = strResto.find(' ');
            int timeStamp = stoi(strResto.substr(0, spacePosNew));
            long long cliente = stoll(strResto.substr(spacePosNew + 1));

            int hash = functionHash(timeStamp, tamInicial);
            client *newClient = new client{timeStamp, cliente, tabelaHash[hash]};
            tabelaHash[hash] = newClient;
            numClients++;

            if (numClients >= tamInicial * fatorCarga) {
                rehash(tabelaHash, tamInicial, numClients);
            }
            
            int tamVetor = 0;
            int result = buscaElemento(tabelaHash, tamInicial, timeStamp, tamVetor);
            cout << result << " " << tamVetor << endl;
            
        } else if (command == "QRY") {
            int timeQry = stoi(input.substr(spacePos + 1));
            
            client* result = buscarCliente(tabelaHash, tamInicial, timeQry);
            
            if (result != nullptr) {
                cout << result->enderecoIP << " " << functionHash(result->timeStamp, tamInicial) << endl;
            } else {
                cout << -1 << " " << -1 << endl;
            }
        }
    }
    for (int i = 0; i < tamInicial; ++i) {
        client* ptr = tabelaHash[i];
        while (ptr != nullptr) {
            client* oldPtr = ptr;
            ptr = ptr->prox;
            delete oldPtr;
        }
    }
    delete[] tabelaHash;
    
    return 0;
}
