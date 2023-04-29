#include <ctime>

string randomString( size_t length )
{
    auto randchar = []() -> char
    {
        const char charset[] =
                "0123456789"
                "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
                "abcdefghijklmnopqrstuvwxyz";
        const size_t max_index = (sizeof(charset) - 1);
        return charset[ rand() % max_index ];
    };
    string str(length,0);
    generate_n( str.begin(), length, randchar );
    return str;
}

int random(int min, int max) {
    static bool first = true;
    if (first) {
        srand( time(NULL) );
        first = false;
    }

    return min + rand() % (( max + 1 ) - min);
}

template<typename T> inline void mySwap(T& a, T& b) {
    T temp = b;
    b = a;
    a = temp;
}

template <typename T> int partition(T *arr, int start, int end, bool (*func)(T&, T&)) {
    T pivot = arr[start];

    int count = 0;
    for (int i = start + 1; i <= end; i++) {
        if (func(arr[i], pivot)){
            count++;
        }
    }

    int pivotIndex = start + count;
    mySwap<T>(arr[pivotIndex], arr[start]);

    int i = start, j = end;

    while (i < pivotIndex && j > pivotIndex) {
        while (func(arr[i], pivot)) {
            i++;
        }

        while (!func(arr[j], pivot)) {
            j--;
        }

        if (i < pivotIndex && j > pivotIndex) {
            mySwap<T>(arr[i++], arr[j--]);
        }
    }

    return pivotIndex;
}

template <typename T> void quickSort(T *arr, int start, int end, bool (*func)(T&, T&)) {
    if (start >= end){
        return;
    }

    int p = partition<T>(arr, start, end, func);

    quickSort<T>(arr, start, p - 1, func);

    quickSort<T>(arr, p + 1, end, func);
}