#include <iostream>
#include <vector>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <windows.h>

using namespace std;
void clearScreen();
void setColor(int color);

void inKetQua(const vector<int>& a) {

    cout << "==============================\n";
    cout << "KET QUA LA:\n\n";
    for (int i = 0; i < a.size(); i++)
        cout << setw(4) << a[i];
    cout << "\n==============================\n";
    system("pause");
}


void setColor(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void clearScreen() {
    system("cls");
}

void delay(int ms) {
    clock_t start = clock();
    while (clock() < start + ms);
}


void introduction() {
    cout << "=============================================\n";
    cout << "   MO PHONG MOT SO PHUONG PHAP SAP XEP\n";
    cout << "---------------------------------------------\n";
    cout << "1. Bubble Sort\n";
    cout << "2. Selection Sort\n";
    cout << "3. Insertion Sort\n";
    cout << "4. Interchange Sort\n";
    cout << "5. Quick Sort\n";
    cout << "---------------------------------------------\n";
    cout << "DO  : Dang so sanh\n";
    cout << "XANH: Vua hoan vi / da sap xep\n";
    cout << "=============================================\n\n";
    system("pause");
}


void inMang(const vector<int>& a, int h1=-1, int h2=-1, int done=-1, int step=0) {
	
    cout << "BUOC " << step << "\n\n";

    for (int i = 0; i < a.size(); i++) {
        if (i == h1 || i == h2) {
            setColor(12); // d?
            cout << "[" << setw(2) << a[i] << "]";
        }
        else if (i == done) {
            setColor(10); // xanh
            cout << "[" << setw(2) << a[i] << "]";
        }
        else {
            setColor(7);
            cout << " " << setw(2) << a[i] << " ";
        }
    }
    setColor(7);
    cout << endl;
    delay(700);
}

// ===== BUBBLE SORT =====
void bubbleSort(vector<int> a) {
    int step = 1;
    for (int i = 0; i < a.size()-1; i++) {
        for (int j = 0; j < a.size()-i-1; j++) {
            inMang(a, j, j+1, -1, step++);
            if (a[j] > a[j+1]) {
                swap(a[j], a[j+1]);
                inMang(a, -1, -1, j+1, step++);
                
            }
        }
    }
    inKetQua(a);

}

// ===== SELECTION SORT =====
void selectionSort(vector<int> a) {
    int step = 1;
    for (int i = 0; i < a.size()-1; i++) {
        int minIdx = i;
        for (int j = i+1; j < a.size(); j++) {
            inMang(a, minIdx, j, -1, step++);
            if (a[j] < a[minIdx])
                minIdx = j;
        }
        swap(a[i], a[minIdx]);
        inMang(a, -1, -1, i, step++);
    }
    inKetQua(a);

}

// ===== INSERTION SORT =====
void insertionSort(vector<int> a) {
    int step = 1;
    for (int i = 1; i < a.size(); i++) {
        int key = a[i], j = i-1;
        while (j >= 0 && a[j] > key) {
            inMang(a, j, j+1, -1, step++);
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = key;
        inMang(a, -1, -1, j+1, step++);
    }
    inKetQua(a);

}

// ===== INTERCHANGE SORT =====
void interchangeSort(vector<int> a) {
    int step = 1;
    for (int i = 0; i < a.size()-1; i++) {
        for (int j = i+1; j < a.size(); j++) {
            inMang(a, i, j, -1, step++);
            if (a[i] > a[j]) {
                swap(a[i], a[j]);
                inMang(a, -1, -1, i, step++);
            }
        }
    }
    inKetQua(a);

}

// ===== QUICK SORT =====
void quickSortRun(vector<int>& a, int l, int r, int& step) {
    if (l >= r) return;

    int pivot = a[r];
    int i = l - 1;

    for (int j = l; j < r; j++) {
        inMang(a, j, r, -1, step++);
        if (a[j] < pivot) {
            i++;
            swap(a[i], a[j]);
            inMang(a, -1, -1, i, step++);
        }
     

    }

    swap(a[i+1], a[r]);
    inMang(a, -1, -1, i+1, step++);

    quickSortRun(a, l, i, step);
    quickSortRun(a, i+2, r, step);
}

void quickSort(vector<int> a) {
    int step = 1;
    quickSortRun(a, 0, a.size()-1, step);
    inKetQua(a);
}

int main() {
    introduction();

    int n, choice;
    vector<int> a;

    cout << "Nhap so phan tu: ";
    cin >> n;
    a.resize(n);

    cout << "Nhap cac phan tu:\n";
    for (int i = 0; i < n; i++)
        cin >> a[i];

    cout << "\n===== MENU =====\n";
    cout << "1. Bubble Sort\n";
    cout << "2. Selection Sort\n";
    cout << "3. Insertion Sort\n";
    cout << "4. Interchange Sort\n";
    cout << "5. Quick Sort\n";
    cout << "Chon: ";
    cin >> choice;

    switch (choice) {
        case 1: bubbleSort(a); break;
        case 2: selectionSort(a); break;
        case 3: insertionSort(a); break;
        case 4: interchangeSort(a); break;
        case 5: quickSort(a); break;
        default: cout << "Lua chon khong hop le!\n";
    }

    system("pause");
    return 0;
}


