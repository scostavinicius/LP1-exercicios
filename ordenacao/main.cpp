#include <iostream>
#include <string>

#include "include/ordenacao.hpp"

// String para a impressão das listagens no terminal
std::string line(60, '-');

const std::vector<int> backupNumeros = {5, 3, 8,  4,  2,  4, 9, 0,
                                        1, 2, 10, 42, 21, 6, 7};
const std::vector<double> backupDecimais = {5.1, 3.3, 8.8, 4.4, 2.2,
                                            2.4, 6.7, 0.1, 9.6};

void backupListas(std::vector<int>& numeros, std::vector<double>& decimais) {
  numeros = backupNumeros;
  decimais = backupDecimais;
}

void listar(const std::vector<int>& nums) {
  for (int num : nums) {
    std::cout << num << " ";
  }
  std::cout << std::endl;
}

void listar(const std::vector<double>& nums) {
  for (double num : nums) {
    std::cout << num << " ";
  }
  std::cout << std::endl;
}

void decoration(std::string str, std::vector<int>& numeros,
                std::vector<double>& decimais) {
  std::cout << std::endl;
  std::cout << line << "\n" << std::endl;
  std::cout << "Listas antes do " << str << " Sort: " << std::endl;
  listar(numeros);
  listar(decimais);
  std::cout << std::endl;
}

int main() {
  std::vector<int> numeros = backupNumeros;
  std::vector<double> decimais = backupDecimais;

  std::cout << std::endl;
  std::cout << line << "\n" << std::endl;

  std::cout << "Lista de numeros inteiros: ";
  listar(numeros);

  std::cout << "Lista de numeros decimais: ";
  listar(decimais);

  //--------------------------------------------------------
  // Listagem do Bubble Sort
  //--------------------------------------------------------

  decoration("Bubble", numeros, decimais);

  std::cout << "Bubble Sort em inteiros:\n";
  bubbleSort(numeros);
  listar(numeros);

  std::cout << "Bubble Sort em doubles:\n";
  bubbleSort(decimais);
  listar(decimais);

  backupListas(numeros, decimais);

  //--------------------------------------------------------
  // Listagem do Selection Sort
  //--------------------------------------------------------

  decoration("Selection", numeros, decimais);

  std::cout << "Selection Sort em inteiros:\n";
  selectionSort(numeros);
  listar(numeros);

  std::cout << "Selection Sort em doubles:\n";
  selectionSort(decimais);
  listar(decimais);

  backupListas(numeros, decimais);

  //--------------------------------------------------------
  // Listagem do Insertion Sort
  //--------------------------------------------------------

  decoration("Insertion", numeros, decimais);

  std::cout << "Insertion Sort em inteiros:\n";
  insertionSort(numeros);
  listar(numeros);

  std::cout << "Insertion Sort em doubles:\n";
  insertionSort(decimais);
  listar(decimais);

  backupListas(numeros, decimais);

  //--------------------------------------------------------
  // Listagem do Quick Sort
  //--------------------------------------------------------

  decoration("Quick", numeros, decimais);

  std::cout << "Quick Sort em inteiros:\n";
  quickSort(numeros, 0, numeros.size() - 1);
  listar(numeros);

  std::cout << "Quick Sort em doubles:\n";
  quickSort(decimais, 0, decimais.size() - 1);
  listar(decimais);

  backupListas(numeros, decimais);

  //--------------------------------------------------------
  // Listagem do Merge Sort
  //--------------------------------------------------------

  decoration("Merge", numeros, decimais);

  std::cout << "Merge Sort em inteiros:\n";
  mergeSort(numeros, 0, numeros.size() - 1);
  listar(numeros);

  std::cout << "Merge Sort em doubles:\n";
  mergeSort(decimais, 0, decimais.size() - 1);
  listar(decimais);

  backupListas(numeros, decimais);

  return 0;
}
