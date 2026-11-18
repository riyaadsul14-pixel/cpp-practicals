
#include <iostream>
#include <memory>
using namespace std;

int main() {

    // Example 1: Raw Pointer
    cout << "--- Raw Pointer ---" << endl;

    int* rawPtr = new int(100);
    cout << "Value: " << *rawPtr << endl;

    delete rawPtr;
    cout << "Memory released manually." << endl;


    // Example 2: Unique Pointer
    cout << "\n--- Unique Pointer ---" << endl;

    unique_ptr<int> ptr1 = make_unique<int>(200);

    cout << "Value: " << *ptr1 << endl;
    cout << "Unique pointer has one owner." << endl;


    // Example 3: Unique Pointer Array
    cout << "\n--- Unique Pointer Array ---" << endl;

    unique_ptr<int[]> arr = make_unique<int[]>(3);

    for (int i = 0; i < 3; i++) {
        arr[i] = (i + 1) * 10;
    }

    cout << "Array Elements: ";
    for (int i = 0; i < 3; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;


    // Example 4: Shared Pointer
    cout << "\n--- Shared Pointer ---" << endl;

    shared_ptr<int> sp1 = make_shared<int>(300);

    // Second owner shares the same resource
    shared_ptr<int> sp2 = sp1;

    cout << "Value: " << *sp1 << endl;
    cout << "Reference Count: " << sp1.use_count() << endl;

    sp2.reset();

    cout << "After releasing second owner:" << endl;
    cout << "Reference Count: " << sp1.use_count() << endl;


    // RAII automatically releases memory
    cout << "\nMemory is automatically managed." << endl;

    return 0;
}
