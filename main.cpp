#include <iostream>

using namespace std;

// 이건 오류

int main()
{
    enum EColor
    {
        red,
        orange = 4,
    };
    int num1 = 1;
    int num2 = 1;
    float A = 5.5f;
    int B = (int)A;
    EColor Ered(orange);
    cout << Ered << endl;

    return 0;
}