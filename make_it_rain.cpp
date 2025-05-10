#include <iostream>

class SomeClass {
public:
    SomeClass() {
        std::cout << "SomeClass constructed\n";
    }

    ~SomeClass() {
        std::cout << "SomeClass destructed\n";
    }
};


int main(int argc, char **argv) {
  SomeClass s;
}
