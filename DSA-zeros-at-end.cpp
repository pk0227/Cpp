#include <iostream>
#include <array>

//void print(const std::array<int, 7>& arr)
//void print(const int (&arr)[7])
template<std::size_t N>
void print(const int (&arr)[N])
{
    for(const int& elm : arr)
    {
        std::cout << elm << " ";
    }
    
    std::cout << std::endl;
}

//void move(std::array<int, 7>& arr, int start, int end)
//void move(int (&arr)[7], int start, int end)
template<std::size_t N>
void move(int (&arr)[N], int start, int end)
{
    for(int i=start; i<end; i++)
    {
        arr[i] = arr[i+1];
    }
}

int main() {
    //std::array<int, 7> arr = {1, 0, 50, 4, 0, 74, 92};
    //int arr[] = {1, 0, 50, 4, 0, 74, 92};
    int arr[] = {38, 0, 0, 39, 40, 0, 41, 42, 0, 43, 44, 0, 45, 46, 0, 47};
    int lastIndex{(sizeof(arr)/sizeof(int)) - 1};
    //int lastIndex{std::size(arr) - 1}; //int lastIndex{arr.size() - 1};
    int desiredValue{0};

    for(int i=0; i<lastIndex; i++)
    {
        if(arr[i] == desiredValue)
        {
            move(arr, i, lastIndex);
            arr[lastIndex] = desiredValue;
            lastIndex--;
            
            if(arr[i] == desiredValue)
                i--;
        }
    }
    
    print(arr);
    //std::cout << lastIndex << std::endl;
    return 0;
}