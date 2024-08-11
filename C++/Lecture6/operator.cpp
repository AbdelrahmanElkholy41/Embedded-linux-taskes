#include <iostream>
#include <vector>
#include <algorithm>

class Data {
public:
    std::string n;
    int count = 0;

    void display() const {
        std::cout << n << std::endl;
    }

    Data& operator+=(const std::string& ma) {
        this->n += ma;
        return *this;
    }

    bool operator<(const Data &a) const {
        return this->n < a.n;
    }

    void operator++() {
        this->count++; 
    } 
    
    int operator++(int) {
        int temp = this->count;
        this->count++;
        return temp;
    }

    Data& operator<<(int shift) {
        this->count <<= shift;
        return *this;
    }

    Data& operator>>(int shift) {
        this->count >>= shift;
        return *this;
    }

    
    Data& operator^(int value) {
        this->count ^= value;
        return *this;
    }

    Data operator~() const {
        Data result = *this;
        result.count = ~this->count;
        return result;
    }
};

std::string operator+(const Data& data, const std::string& message) {
    return data.n + message;
}

std::ostream& operator<<(std::ostream& os, const Data& data) {
    os << data.n;
    return os;
}

int main() {
    Data d{"hello "};
    Data d1{"hello world!"}; 

    std::string message = " Abdelrahman";
    d += message;
    d.display();
    std::string result = d + message;
    std::cout << result << std::endl;
    
    if (d < d1) {
        std::cout << "d is less than d1" << std::endl;
    } else {
        std::cout << "d is not less than d1" << std::endl;
    }

    ++d; // Pre-increment
    d++; // Post-increment
    std::cout << "Count before shifting: " << d.count << std::endl;

    d << 2; // Left shift by 2 bits
    std::cout << "Count after left shift: " << d.count << std::endl;

    d >> 1; // Right shift by 1 bit
    std::cout << "Count after right shift: " << d.count << std::endl;
     
    d ^ 3; // XOR with 3
    std::cout << "Count after XOR with 3: " << d.count << std::endl;

    Data d_not = ~d; // Bitwise NOT
    std::cout << "Count after bitwise NOT: " << d_not.count << std::endl;
    return 0;
}
