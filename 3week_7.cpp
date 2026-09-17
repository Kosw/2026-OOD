#include <iostream>

int main() {
    int num = 10;

    std::cout << "int num 주소 : 0x" << &num << std::endl
              << "int num 값 : " << num << std::endl
              << std::endl;

    int &ref = num;

    std::cout << "레퍼런스 주소 : 0x" << &ref << std::endl
              << "레퍼런스가 참조하는 값 : " << ref << std::endl
              << std::endl;

    int *ptr = &num;

    std::cout << "포인터 주소 : 0x" << &ptr << std::endl
              << "포인터가 참조하는 값 : " << *ptr << std::endl;

    return 0;
}

/*
[포인터와 레퍼런스(&)의 차이점]
16번줄을 보면 포인터와 다르게 레퍼런스는 주소값을 출력할 때 &ref를 사용하지 않고, 그냥 ref를
사용해도 된다. 이는 레퍼런스가 이미 변수의 별칭이기 때문에, 레퍼런스를 통해 변수에 접근할 때는
별도의 주소 연산자가 필요하지 않기 때문이다. 반면 포인터는 변수의 주소를 저장하는 변수이므로,
포인터를 통해 변수에 접근할 때는 반드시 * 연산자를 사용해야 한다. 또한, 레퍼런스는 한 번 초기화되면
다른 변수에 바인딩될 수 없지만, 포인터는 다른 변수의 주소를 가리킬 수 있다.
*/
