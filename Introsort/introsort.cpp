#include <iostream>
#include <vector>

using namespace std;

// двоичный логарифм
int log2(int x) {
    int k;
    for (k = -1; x > 0; k++) {x >>= 1;}

    return k;
}

void insertionsort(vector<int> &vec, int first_index, int last_index) {
    for (int i = first_index+1; i <= last_index; i++) { // сортировка
        for (int j = i; j > first_index && vec[j-1] > vec[j]; j--) {
            swap(vec[j-1], vec[j]);
        }
    }
}

void sift_down(vector<int> &vec, int current, int length) { // функция просеивания вниз
    bool done = false;

    int largest = current;
    int left = 2*current + 1;   // левый сын
    int right = 2*current + 2; // правый сын
 
    if (left < length && vec[largest] < vec[left])
        largest = left;
 
    if (right < length && vec[largest] < vec[right])
        largest = right;
 
    if (largest != current) { // если какой-то из сыновей больше родителя
        swap(vec[largest], vec[current]);
        sift_down(vec, largest, length); // рекурсивная обработка затронутого поддерева
    }
}

void heapsort(vector<int> &vec) { // пирамидальная сортировка
    int length = vec.size();

    for (int i = length/2 - 1; i >= 0; i--) // построение кучи
        sift_down(vec, i, length);
 
    for (int i = length-1; i >= 0; i--) { // сортировка
        swap(vec[0], vec[i]);
        sift_down(vec, 0, i);
    }
}

int partition(vector<int> &vec, int first_index, int last_index) {
    int *first = &vec[first_index], *middle = &vec[(first_index+last_index)/2], *last = &vec[last_index];
    
    if (*first > *middle) swap(*first, *middle);
    if (*first > *last) swap(*first, *last);
    if (*middle < *last) swap(*middle, *last);

    int pivot = *last;
    int index = first_index;
    
    for (int i = first_index; i <= last_index; i++) if (vec[i] < pivot) swap(vec[i], vec[index++]);

    swap(vec[index], vec[last_index]);

    return index;
}

void introsort(vector<int> &vec, int first_index, int last_index, int max_depth) {
    if ((last_index-first_index+1) < 16) insertionsort(vec, first_index, last_index);
    else if (max_depth = 0) heapsort(vec);
    else {
        int border = partition(vec, first_index, last_index);
        introsort(vec, first_index, border-1, max_depth-1);
        introsort(vec, border+1, last_index, max_depth-1);
    }
}

// сортировка
void my_sort(vector<int> &vec) {
    int max_depth = 2 * log2(vec.size());
    introsort(vec, 0, vec.size()-1, max_depth);
}

bool is_sorted(vector<int> &vec) {
    for (int i = 0; i < (vec.size()-1); i++) if (vec[i] > vec[i+1]) return false;
    return true;
}

int main() {
    vector<int> vec = {7, 8, 13, 32, 5, 23, 29, 3, 20, 21, 10, 24, 19, 15, 30, 28, 22, 9, 12, 1, 17, 16, 25, 18, 14, 31, 26, 11, 4, 2, 6, 27};

    my_sort(vec);

    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i] << " ";
    }

    if (is_sorted(vec)) cout << endl << "OK" << endl;
    else cout << endl << "NEOK" << endl;

    return 0;
}