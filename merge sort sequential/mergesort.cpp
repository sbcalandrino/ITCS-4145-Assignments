#include <iostream>
#include <vector>
#include <string>

void mergeSort(std::vector<int>& input)
{

}

std::vector<int> generateRandomValues(int sizeLimit, int valueLimit)
{
    std::vector<int> values = std::vector<int>();

    int size = std::rand() % sizeLimit;
    for (int i = 0; i < size; i++)
    {
        int value = std::rand() % valueLimit;

        values.push_back(value);
    }

    return values;
}

void printValues(const std::vector<int>& values)
{
    std::string finalOutput = "[ ";

    for (int val : values)
    {
        finalOutput += std::to_string(val) + ' ';
    }

    std::cout << finalOutput << ']' << '\n';
}

int main()
{
    std::vector<int> values = generateRandomValues(25, 100);

    printValues(values);

    mergeSort(values);

    return 0;
}