#include <iostream>
#include <vector>
#include <chrono>

// putting function prototypes so gcc doesnt yell at me :(
void mergeSort(std::vector<int>&);
void mergeSort(std::vector<int>&, size_t, size_t);
void merge(std::vector<int>&, size_t, size_t, size_t);
std::vector<int> generateRandomValues(size_t);

void mergeSort(std::vector<int>& input)
{
    mergeSort(input, 0, input.size() - 1);
}

void mergeSort(std::vector<int>& input, size_t left, size_t right)
{
    if (left < right)
    {
        // calculates midpoint between the left and right points
        size_t mid = left + (right - left) / 2;

        // merge sort each side
        mergeSort(input, left, mid);
        mergeSort(input, mid + 1, right);

        // merge the 2 sides
        merge(input, left, mid, right);
    }
}

void merge(std::vector<int>& input, size_t left, size_t mid, size_t right)
{
    // num elements from left to mid
    size_t numLeft = mid - left + 1;

    // num elements from mid + 1 to right
    size_t numRight = right - mid;

    // make temp left and right vectors and populate them with the left and right side elements
    std::vector<int> leftSide(numLeft), rightSide(numRight);
    for (int i = 0; i < numLeft; i++)
        leftSide[i] = input[left + i];
    for (int i = 0; i < numRight; i++)
        rightSide[i] = input[mid + i + 1];

    // merge algorithm
    size_t i = 0, j = 0, k = left;
    while (i < numLeft && j < numRight)
    {
        // if the current element on the left side is smaller than the current element on the right side,
        // set the current element in the input vector to the left side's element
        if (leftSide[i] <= rightSide[j])
        {
            input[k] = leftSide[i];
            i++;
        }
        // else do the opposite
        else
        {
            input[k] = rightSide[j];
            j++;
        }

        k++;
    }

    // put the rest of the left and right side elements into the input vector
    while (i < numLeft) {
        input[k] = leftSide[i];
        i++;
        k++;
    }
    while (j < numRight) {
        input[k] = rightSide[j];
        j++;
        k++;
    }
}

std::vector<int> generateRandomValues(size_t size)
{
    // makes a vector of values of the given size
    std::vector<int> values = std::vector<int>(size);

    // loops over the amount of values that should be in the vector and sets each element to a random value
    for (int i = 0; i < size; i++)
    {
        int value = std::rand();

        values[i] = value;
    }

    return values;
}

int main(int argc, char* argv[])
{
    // get the size from arguments and make a random vector of that length
    size_t size = std::atol(argv[1]);
    std::vector<int> values = generateRandomValues(size);

    // merge sort and get the current time before and after
    auto before = std::chrono::high_resolution_clock::now();
    mergeSort(values);
    auto after = std::chrono::high_resolution_clock::now();

    // calculate how long it took in nanoseconds (using a double to calculate seconds so it doesnt have that float issue we talked about)
    // or at least im hoping it wont be an issue
    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(after - before);

    // 1 second is 1000000000 nanoseconds so dividing the number of nanoseconds by 1000000000 gets seconds
    std::cout << (double)duration.count() / 1000000000 << '\n';

    return 0;
}