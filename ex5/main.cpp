#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class ReadClass {
    public:
        string line;
        int count;
        string class_name[10];
        void showClass() {
            ifstream file("./main.cpp");
            if (file.fail()) {
                cout << "Error opening a file" << endl;
                file.close();
            }
            while (getline(file, line)) {
                if (line.find("class") == 0){
                    class_name[count].assign(line, 0, line.size() - 1);
                    count++;
                }
            }
            cout << count << " class in main.cpp\n";
            cout << class_name[0] << endl;
        }
};

int main()
{
    ReadClass rfile;
    rfile.showClass();
    return 0;
}
