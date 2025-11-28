/*
Dans une fonction, en dehors de toute classe, implémenter un tri par insertion reposant sur l’utilisation de std::vector. 
L’objectif est de simuler l’arrivée de nouveaux éléments dans un vecteur déjà trié. La validation de votre code sera assurée par 
l’insertion d’éléments dans un tableau trié. L’algorithme du tri par insertion est le suivant :
*/

#include <iostream>
#include <vector>

void tri_insertion(std::vector<int>& l) {
    int n = l.size(); // Taille de liste

    for (int i = 1; i < n; i++) {
        int v = l[i]; // 2 (valeur)
        int j = i; // 1 (indice)

        while (j > 0 && l[j - 1] > v) { // 5 > 2
            l[j] = l[j - 1]; // {5, 5, 9, 1, 7, 3}
            j--; // On continue à comparer jusqu'à au début (= indice 0)
        }

        // j = 0 après while
        l[j] = v; // {2, 5, 9, 1, 7, 3} // Fin de 1er tour
    }
}


int main() 
{
    // Définition de la liste
    std::vector<int> liste = {5, 2, 9, 1, 7, 3};

    std::cout << "Avant tri : ";
    for (int x : liste) std::cout << x << " ";
    std::cout << "\n";

    // Appel du tri
    tri_insertion(liste);

    std::cout << "Après tri : ";
    for (int x : liste) std::cout << x << " ";
    std::cout << "\n";

    return 0;
}

// g++ -Wall -Wextra -std=c++17 Tab_dynamiques/ex1.cpp -Iheaders -o main