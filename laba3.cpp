#include <iostream>
#include <stdlib.h> // для работы функции exit()
#include <cmath> // для работы фунции abs()

void BubbleSort(int list[], int Listlength) {
    while(Listlength--) {
        bool flag = false;
        for (int i = 0; i < Listlength; i++) {
            if (list[i] < list [i+1]) {
                std::swap(list[i], list[i+1]);
                flag = true;
            }
        }
        if (flag == false) {
            break;
        }
    }
}

int main() {
    int n;
    std::cin >> n;
    if (n < 1 || n > 32) {
        std::cout << "Допустимое n должно быть в диапазоне [1;32]!" << std::endl;
        exit(0);
    }

    std::cout << "Введите " << n << " значений граммовки";
    int *gramm = new int[n];
    for (int i = 0; i < n; i++) {
        std::cin >> gramm[i];
    }

    BubbleSort(gramm, n);

    /*std::cout << "Sorted array ..." << std::endl;
	for(int i = 0; i < n; i++)
		std::cout << gramm[i];
	std::cout << std::endl;*/

    int Mash = 0;
    int Pet = 0;
    int razn;

    for (int x = 0; x < n; x++) {
        if (Mash <= Pet) {
            Mash += gramm[x];
        }
        else {
            Pet += gramm[x];
        }
    }
    razn = abs(Mash - Pet);
    std::cout << razn << std::endl;    
}