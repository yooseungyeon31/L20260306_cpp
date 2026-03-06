#include <iostream>

using namespace std;


void Swap(int A, int B)//함수 이름은 동사로 쓰면 좋음
{
	int Temp = 0;

	Temp = A;
	A = B;
	B = Temp;

}


int main()
{
	int A = 10; //매인스택영역에 저장
	int B = 20;
	int Temp = 0;

	int* PA = nullptr;
	PA = &A;
	
	//포인터형 변수 *PA = A의 주소로 찾아가서 A의 값을 가져오셈
	//PA->깂 = A의 주소값
	cout << *PA << endl; //10이 출력된다.
	//cout << &A << endl; *///A의 주소값

	return 0;

	//Swap(A, B);

	//cout << A << endl;
	//cout << B << endl;


	
}
//int* 새로운 자료형. 주소값을 가짐. //특정자료형의 주소값을 저장할거야~ 
// 
//int* PA = nullptr; 의미-> 가리키는게 없어요. 즉 아무것도 아님. C++ 이므로 nullptr을 쓰자

//cout <<sizeof(PA) << endl; 이걸 물어보면 -> 8바이트
//->A의 사이즈 값은 8이기 때문에.

//------
//float F = 1.0f;
//float* PF = &F;

//cout << sizeof(PF) << endl;  //이것도 8바이트. 주소값이기때문/메모리 주소는 8바이트로 만들어져있기 떄문 
//---------


