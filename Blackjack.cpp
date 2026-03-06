#include <iostream>

using namespace std;


char Swap(int A, int B)//함수 이름은 동사로 쓰면 좋음
{
	int Temp = 0;

	Temp = A;
	A = B;
	B = Temp;

}


int main()
{
	int A = 10;
	int B = 20;
	int Temp = 0;

	Temp = A;
	A = B;
	B = Temp;

	cout << A << endl;
	cout << B << endl;


	return 0;
}