#include <fstream>

int main() {
    std::ofstream file("output.md");

    file << "<span style='color:red;'>Это красный текст</span>\n";

    file.close();
    return 0;
}
