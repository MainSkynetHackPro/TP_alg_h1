#include <iostream>

class BinFinder {
public:
    int find(int *array, size_t len);

private:

    int *ptr_start;
    int *ptr_end;

};

int BinFinder::find(int *array, size_t len) {
    this->ptr_start = array;
    this->ptr_end = (array + len - 1);
    int step = (int) (this->ptr_end - this->ptr_start);

    int *tmp_start = this->ptr_start;
    int *tmp_end = this->ptr_start + step / 2;

    if (len == 2) {
        return (*ptr_start > *ptr_end) ? 0 : 1;
    }

    while (tmp_start < tmp_end) {
        if (*(tmp_end - 1) > *tmp_end) {
            step = step / 2;
            tmp_end = tmp_start + step / 2;
        } else {
            tmp_start = tmp_end;
            tmp_end = tmp_start + step / 2;
        }
        if (tmp_end > ptr_end) {
            tmp_start = ptr_end;
            break;
        }
    }

    if (tmp_start > ptr_start and *tmp_start < *(tmp_start - 1)) {
        tmp_start = tmp_start - 1;
    }
    return (int) (tmp_start - this->ptr_start);
}

int main() {
    size_t len;

    std::cin >> len;
    BinFinder finder;

    int *array = new int[len];

    for (int i = 0; i < len; i++)
        std::cin >> array[i];

    int element_id = finder.find(array, len);

    std::cout << element_id;

    delete[] array;

    return 0;
}