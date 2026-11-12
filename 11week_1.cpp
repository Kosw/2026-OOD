#include <iostream>
#include <vector>

int main() {
    std::vector<int> vec;
    for (int i = 0; i < 10; i++) {
        int n;
        std::cin >> n;
        vec.push_back(n);
    }

    int minVal = vec.front();
    int maxVal = vec.front();

    for (std::vector<int>::iterator itr = vec.begin(); itr != vec.end(); ++itr) {
        if (*itr < minVal)
            minVal = *itr;
        if (*itr > maxVal)
            maxVal = *itr;
    }

    std::cout << "최소: " << minVal << std::endl;
    std::cout << "최대: " << maxVal << std::endl;

    return 0;
}
