#include <iostream>
#include <stack>
#include <vector>
#include <algorithm> // pour les fonctions reverse(), begin(), end()
using namespace std;

class SortedList {
private:
    stack<int> sorted; // pile

public:
    // Constructeur 
    SortedList(const vector<int>& values) {
        for (int v : values)
            sorted.push(v); 
    }

    // Algorithme de tri
    void sort() {
        stack<int> origStack = sorted;
        stack<int> ordStack;

        sorted = stack<int>(); // Initialisation

        while (!origStack.empty()) { // Pendant la pille d'origine n'est pas vide
            int in = origStack.top(); // On enregistre la valeur de top de pille d'origine dans la variable "in" pour comparer plus tard
            origStack.pop(); // Et on dépile (= supprime)

            // Comparaison
            while (!ordStack.empty() && ordStack.top() > in) { // Pendant la pille d'ordre n'est pas vide et la valeur de top de pille d'ordre
                                                               // est supérieur à "in" (le cas pas bien)
                origStack.push(ordStack.top()); // On déplace la valeur de top de pille d'ordre dans la pille d'origine
                ordStack.pop(); // Et on dépile
            }

            ordStack.push(in); // Si "in" est bien supérieur à la valeur de top de pille d'ordre (le cas bien), on empile "in" dans la pille d'ordre
        }

        sorted = ordStack;
    }

    void print() {
        stack<int> copy = sorted;
        vector<int> result;

        // copie colle la pille trié dans vector pour afficher en utilisant la boucle
        while (!copy.empty()) {
            result.push_back(copy.top());
            copy.pop();
        }

        // utilisation reverse pour afficher en remontant de la gauche
        reverse(result.begin(), result.end());

        cout << "ordStack = [ ";
        for (int v : result)
            cout << v << ", ";
        cout << "]\n";
    }
};


int main() {
    vector<int> values = {1, 11, 3, 7, 5};

    cout << "origStack = [ ";
    for (int v : values) cout << v << ", ";
    cout << "]\n";

    // On empile tous les valeurs de liste values dans la pile sorted
    SortedList s(values);

    s.sort();
    s.print();

    return 0;
}

// g++ -Wall -Wextra -std=c++17 Pile/ex2.cpp -Iheaders -o main