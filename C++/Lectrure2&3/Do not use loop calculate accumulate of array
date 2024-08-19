#include <iostream>
#include <numeric> 

int main() {
    const int size = 10000 - 10 + 1;
    int array[size];

    // ملء المصفوفة بالقيم من 10 إلى 10000
    std::iota(array, array + size, 10);

    // حساب المجموع التراكمي للمصفوفة بدون استخدام حلقة
    int sum = std::accumulate(array, array + size, 0);

    // عرض الناتج
    std::cout << "The sum of the array is: " << sum << std::endl;

    return 0;
}
