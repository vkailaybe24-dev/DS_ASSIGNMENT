#include <iostream>
#include <cctype> 

using namespace std;

int main() {
    char c = 'A';
    char lower_c = tolower(c);
    cout << "'" << c << "' in lowercase is '" << lower_c << "'" << endl;
    return 0;
}
