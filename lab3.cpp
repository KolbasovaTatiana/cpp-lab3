#include <iostream>
#include <stdlib.h> // для работы функции exit()
#include <cmath> // для работы функции abs()

int recursion(int list[], int t_ch, int n, int Mash, int Pet) {
    if (t_ch == n) {
        return abs(Mash - Pet);
    }
    return std::min(recursion(list, t_ch+1, n, Mash + list[t_ch], Pet), recursion(list, t_ch+1, n, Mash, Pet + list[t_ch]));
}

int main() {
    int n; //количество чашек
    std::cin >> n;
    
    if (n < 1 || n > 32) {
        std::cout << "Значение n должно принадлежать отрезку [1;32]" << std::endl;
        exit(0);
    }
    std::cout << "Введите " << n << " значений граммовки";
    int *gramm = new int[n]; //массив, содержащий значения граммовок
    for (int i = 0; i < n; i++) {
        std::cin >> gramm[i];
    }
    /*for (int x = 0; x < n; x++) {     //вывод значений массива
        std::cout << gramm[x] << '\t';
    }*/
    std::cout << recursion(gramm, 0, n, 0, 0) << std::endl;
}