#ifndef ORDENACAO_HPP
#define ORDENACAO_HPP

#include <vector>

//--------------------------------------------------------------
// Bubble Sort
//--------------------------------------------------------------

template <typename Type>
void bubbleSort(std::vector<Type>& lista) {
  for (size_t i = 0; i < lista.size() - 1; ++i) {
    for (size_t j = 0; j < lista.size() - 1 - i; ++j) {
      if (lista[j] > lista[j + 1]) {
        std::swap(lista[j], lista[j + 1]);
      }
    }
  }
}

//--------------------------------------------------------------
// Selection Sort
//--------------------------------------------------------------

template <typename Type>
void selectionSort(std::vector<Type>& lista) {
  for (size_t i = 0; i < lista.size(); ++i) {
    int min = i;
    for (size_t j = i + 1; j < lista.size() - 1; ++j) {
      if (lista[j] < lista[min]) {
        min = j;
      }
    }

    std::swap(lista[i], lista[min]);
  }
}

//--------------------------------------------------------------
// Insertion Sort
//--------------------------------------------------------------

template <typename Type>
void insertionSort(std::vector<Type>& lista) {
  for (size_t i = 1; i < lista.size(); ++i) {
    for (size_t j = i; j > 0 && lista[j] < lista[j - 1]; --j) {
      std::swap(lista[j], lista[j - 1]);
    }
  }
}

//--------------------------------------------------------------
// Quick Sort
//--------------------------------------------------------------

template <typename Type>
int partition(std::vector<Type>& lista, int begin, int end) {
  int pivot = lista[end];
  int i = begin - 1;

  for (int j = begin; j < end; ++j) {
    if (lista[j] <= pivot) {
      ++i;
      std::swap(lista[j], lista[i]);
    }
  }

  std::swap(lista[i + 1], lista[end]);
  return i + 1;
}

template <typename Type>
void quickSort(std::vector<Type>& lista, int begin, int end) {
  if (end > begin) {
    int pivot = partition(lista, begin, end);
    quickSort(lista, begin, pivot - 1);
    quickSort(lista, pivot + 1, end);
  }
}

//--------------------------------------------------------------
// Merge Sort
//--------------------------------------------------------------

template <typename Type>
void merge(std::vector<Type>& lista, int begin, int mid, int end) {
  int tam_left = mid - begin + 1;
  int tam_right = end - mid;

  std::vector<Type> left(tam_left);
  std::vector<Type> right(tam_right);

  for (int i = 0; i < tam_left; ++i) {
    left[i] = lista[begin + i];
  }
  for (int i = 0; i < tam_right; ++i) {
    right[i] = lista[mid + 1 + i];
  }

  int l = 0;
  int r = 0;
  for (int i = begin; i <= end; ++i) {
    if (l == tam_left) {
      lista[i] = right[r];
      ++r;
    } else if (r == tam_right) {
      lista[i] = left[l];
      ++l;
    } else if (left[l] <= right[r]) {
      lista[i] = left[l];
      ++l;
    } else {
      lista[i] = right[r];
      ++r;
    }
  }
}

template <typename Type>
void mergeSort(std::vector<Type>& lista, int begin, int end) {
  if (begin < end) {
    int mid = (begin + end) / 2;
    mergeSort(lista, begin, mid);
    mergeSort(lista, mid + 1, end);
    merge(lista, begin, mid, end);
  }
}

#endif