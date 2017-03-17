#include <iostream>

#define STEP 100


class BinFinder {
public:
    int find(int *array, size_t len);

private:
    void raw_finder();

    int *ptr_start;
    int *ptr_end;

    int *ptr_raw_interval_start;
    int *ptr_raw_interval_end;

    size_t array_len;
    size_t remain_array_len = 0;
};

void BinFinder::raw_finder() {
    this->ptr_raw_interval_end = this->ptr_end;
    this->ptr_raw_interval_start = this->ptr_start;
    this->remain_array_len = this->array_len;
    for (int *pointer = this->ptr_end - STEP; pointer > this->ptr_start; pointer -= STEP) {
        this->remain_array_len -= STEP;
        if (*pointer < *this->ptr_raw_interval_end) {
            this->ptr_raw_interval_start = pointer;
            break;
        }
        this->ptr_raw_interval_end = pointer;
    }

}

int BinFinder::find(int *array, size_t len) {
    this->ptr_start = array;
    this->ptr_end = (array + len - 1);
    this->array_len = len;
    this->raw_finder();
    int step = (int) (this->ptr_raw_interval_end - this->ptr_raw_interval_start);

    int *tmp_start = this->ptr_raw_interval_start;
    int *tmp_end = this->ptr_raw_interval_start + step / 2;

    while (tmp_start < tmp_end) {
        if (*(tmp_end - 1) > *tmp_end) {
            step = step / 2;
            tmp_end = tmp_start + step / 2;
        } else {
            tmp_start = tmp_end;
            tmp_end = tmp_start + step / 2 + 1;
        }
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

    std::cout << array[element_id];

    delete[] array;

    return 0;
}