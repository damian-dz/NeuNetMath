#include <iostream>

#include "NeuNetMath.h"

using namespace std;

int main()
{
    nnm::Vector<float> v(10);

    v.fillWithRandom(-1, 1);


    cout << v;


    return 0;
}
