//블랙잭
//카드 3장 컴퓨터3장, 사람 3장
//총합 21 넘으면 짐
//21보다 작으면 비교하고 큰쪽 이김
//같으면 플레이어 승리
//1~9까지는 숫자, J,Q,K 는 10으로 계산
//rand()로 난수 발생시켜서 하기

#include <iostream>
#include <string>
#include <cstdlib> 
#include <ctime>



using namespace std;

//카드 변환

int CardChange(int CardNum)
{
	int rank = CardNum % 13;
		if (rank == 0)
		{
			return 1;
		}
		if (rank >=10)
		{
			return 10;
		}
		return rank + 1;

}

string CardName(int CardNum)
{
	int rank = CardNum % 13;
	if (rank == 0) return "A";
	if (rank == 10) return "J";
	if (rank == 11) return "Q";
	if (rank == 12) return "K";
	return to_string(rank + 1);
	
}


int main()
{
	srand(time(NULL));


	
	int PlayerSum = 0; //플레이어 합계
	int ComputerSum = 0; //컴퓨터 합계

	cout << "게임시작" << endl;

	cout << "플레이어 카드: " << endl;

	//플레이어 3장
	//이중for문은 복잡해서 사용하지 말기
	for (int i = 0; i<3; ++i)
	{
		int card = rand() % 52;
		PlayerSum += CardChange(card);
		cout << CardChange(card) << " ";
	}
	cout << " 총합: " << PlayerSum << endl;

	cout << "컴퓨터 카드: " << endl;

	for (int i = 0; i < 3; ++i)
	{
		int card = rand() % 52;
		ComputerSum += CardChange(card);
		cout << CardChange(card) << " ";
	}
	cout << " 총합: " << ComputerSum << endl;

	//승패 판정
	if (PlayerSum > 21)
	{
		cout << "플레이어 초과! 컴퓨터 승리!";
	}
	else if (ComputerSum > 21)
	{
		cout << "컴퓨처 초과 플레이어 승리!";
	}
	else
	{
		if (PlayerSum >= ComputerSum)
		{
			cout << "플레이어 승리!";
		}
		else
		{
			cout << " 컴퓨터 승리!";
		}
	}

	return 0;
}