#include <iostream>
#include <stack> // pour pile
using namespace std;

class ChangeBase {
private:
    stack<int> result;  // pile pour enregistrer le nombre transformé

public:

    // n(décimal) → Transformer en b base
    stack<int> toBase(int n, int b) {
        if (b > 0 && b <= 10) {
            while (n > 0) {
                int remainder = n % b;  // le reste divisé par b (ex.: 25 % 2 = 1)
                result.push(remainder); // Enregistrer dans pile 
                n /= b; // n = n / b → le quoitient divisé par b pour continuer le calcul jusqu'à n devient 0 (25 / 2 = 24)
                }
                return result;
        }
        cout << "Saisir la base entre 1 et 10" << endl;
        return result;
    }

    // Affichage
    void print() {
        cout << "Nombre converti : ";
        while (!result.empty()) { // Si la pile n'est pas vide
            cout << result.top(); // affichage de la valeur top (last in)
            result.pop(); // on supprime la valeur qui est déjà sorti pour la valeur suivant 
        }
        cout << endl;
    }
};

int main() {
    ChangeBase cb;
    cb.toBase(25, 11);  // Décimal 25 en binaire
    cb.print();

    return 0;
}

// g++ -Wall -Wextra -std=c++17 Pile/ex1.cpp -Iheaders -o main
