////블랙잭
////카드 3장 컴퓨터3장, 사람 3장
////총합 21 넘으면 짐
////21보다 작으면 비교하고 큰쪽 이김
////같으면 플레이어 승리
////1~9까지는 숫자, J,Q,K 는 10으로 계산
////rand()로 난수 발생시켜서 하기
//
#include <iostream>
#include <string>
//#include <string>
//#include <cstdlib> 
//#include <ctime>
#define CARDSIZE 52
//
//
using namespace std;
//
////카드 변환
//
//int CardChange(int CardNum)
//{
//	int rank = CardNum % 13;
//	if (rank == 0) //첫번쨰 카드
//	{
//		return 1;
//	}
//	if (rank >= 10)//나머지 J,Q,R
//	{
//		return 10;
//	}
//	return rank + 1; //1~9숫자 1부터 되도록
//
//}
//
//string CardName(int CardNum)
//{
//	int rank = CardNum % 13;
//	if (rank == 0) return "A";
//	if (rank == 10) return "J";
//	if (rank == 11) return "Q";
//	if (rank == 12) return "K";
//	return to_string(rank + 1);
//
//}
//
//
//int main()
//{
//	srand(time(NULL));
//
//
//
//	int PlayerSum = 0; //플레이어 합계
//	int ComputerSum = 0; //컴퓨터 합계
//
//	cout << "게임시작" << endl;
//
//	cout << "플레이어 카드:";
//
//	//플레이어 3장
//	//이중for문은 복잡해서 사용하지 말기
//	for (int i = 0; i < 3; ++i)
//	{
//		int card = rand() % 52;
//		PlayerSum += CardChange(card);
//		cout << CardChange(card) << " ";
//	}
//	cout << " 총합: " << PlayerSum << endl;
//
//	cout << "컴퓨터 카드: " << endl;
//
//	for (int i = 0; i < 3; ++i)
//	{
//		int card = rand() % 52;
//		ComputerSum += CardChange(card);
//		cout << CardChange(card) << " ";
//	}
//	cout << " 총합: " << ComputerSum << endl;
//
//	//승패 판정
//	if (PlayerSum > 21)
//	{
//		cout << "플레이어 초과! 컴퓨터 승리!";
//	}
//	else if (ComputerSum > 21)
//	{
//		cout << "컴퓨처 초과 플레이어 승리!";
//	}
//	else
//	{
//		if (PlayerSum >= ComputerSum)
//		{
//			cout << "플레이어 승리!";
//		}
//		else
//		{
//			cout << " 컴퓨터 승리!";
//		}
//	}
//
//	return 0;
//}
//----------------------------------------------
//#include <vector> //이게 동적배열 만드는 것.
//자료가 들어오면 탐색하고 정렬 등등을 해야함. search, sort....-> algotithm!!
//#include <algorithm>

//int main()
//{
//	//동적배열
//	//정적배열
//	//자료구조(Data Structure)
//
//	//int Players[10] = { 0, };//-> 플레이어가 몇명이 들어오는지 모른다.
//	//
//	//for (int i = 0; i < 10; i++)
//	//{
//	//	Players[i] = 10;
//	//}
//	
//
//
//	return 0;
//}

//별찍ㄱ기
//int main()
//{
//
//	int N;
//	cin >> N;
//	for (int i = 0; i <= N; i++)
//	{
//		for (int j = 0; j < i; j++)
//		{
//			cout << "*";
//
//		}
//		cout << endl;
//		
//	}
//
//	return 0;
//}

//---------------------------------
//똑같은 카드가 나오면 안된다. !

//함수 만들기=========================
string DrawShape(int CardNumber)
{
	int Shape = (CardNumber % 13 + 1);

	if (Shape == 11)
	{
		return "J";
	}
	else if (Shape == 12)
	{
		return "Q";
	}
	else if (Shape == 13)
	{
		return "K";
	}

	return to_string(Shape);
	{
		return "A";
	}
}

//===================================
int main()
{
	//이렇게 하는 방법은 선호 X
	/*int Cards[4][13] =
	{
		{1,2,3,4,5,6,7,8,9,10,11,12,13},
		{1,2,3,4,5,6,7,8,9,10,11,12,13},
		{1,2,3,4,5,6,7,8,9,10,11,12,13},
		{1,2,3,4,5,6,7,8,9,10,11,12,13}
	};*/
	//--------
	/*int A = 0;
	A = NULL;*/ //둘다 0으로 값은 똑같은데 구분을 주기 위해 NULL이라고 하는것. 끝 NULL
	//---------

	//int A = 10;
	//int B = 30;
	//int Temp = A;
	//A = B;
	//B = Temp;
	int Player[CARDSIZE];

	//반복문활용 배열
	int Cards[CARDSIZE] = { 0, };
	string CardType[4] = { "Heart", "Spade", "Diamond", "Clover" };

	for (int i = 0; i < CARDSIZE; i++)
	{
		Cards[i] = i + 1;
	}

	srand((unsigned int)time(nullptr)); //nullptr에 0을넣어도 되지만 
	//보는 사람 입장에서 어떤 의미로 썼는지 모르므로 문자로 써주는 것임

	//Shuffle로 섞으면 되지 않을까?
	//전제 - 아무거나 두개 선택해서 교환.(임의의 - random) -> random 두개 선택해서 교환
	//rand()사용
	for (int i = 0; i < CARDSIZE; i++)
	{
		int FirstIndex = rand() % CARDSIZE;
		int SecondIndex = rand() % CARDSIZE;
		int temp = Cards[FirstIndex];

		Cards[FirstIndex] = Cards[SecondIndex];
		Cards[SecondIndex] = Cards[FirstIndex];


	}

	//주사위(100면체 주사위)
	//서버에서 실행
	//진짜로 난수(하드웨어)

	//int Percent = rand() % 5+ 1;//+해주면 1부터 5까지 라는 것.

	//Deal
	int ComputerCard[3];
	int PlayerCard[3];
	for (int i = 0; i < 3; i++)
	{
		ComputerCard[i] = Cards[i*2];
		PlayerCard[i] = Cards[(i*2)+1];
	}


	int ComputerScore[3] = { 0, };
	int PlayerScore[3] = { 0, };

	for (int i = 0; i < 3; i++)
	{
		
		
		ComputerScore[i] = (ComputerCard[i] % 13 + 1) > 10 ? 10 : (ComputerScore[i] % 13 + 1); //0부터 13까지의 랜덤값


		PlayerScore [i] += PlayerCard[i] % 13 + 1;
		PlayerScore[i] += PlayerCard[i] > 10 ? 10 : PlayerScore[i];
	} 

	int TotalComputerScore = ComputerScore[0] + ComputerScore[1] + ComputerScore[2];
	int TotalPlayerScore = PlayerScore[0] + PlayerScore[1] + PlayerScore[2];

	//draw
	if (TotalComputerScore > 21)
	{
		cout << "Player Win" << endl;
	}
	else if (TotalPlayerScore > 21)
	{
		cout << "Player Lose" << endl;
	}
	else if (TotalComputerScore > TotalPlayerScore)
	{
		cout << "Player Lose" << endl;
	}
	else 
	{
		cout << "Player Win" << endl;
	}
	cout << "==================" << endl;
	cout << "Computer Deck" << endl;

	for (int i = 0; i < 3; i++)
	{
		int CardTypeIndex = ComputerCard[i] / 13;
		
		cout << CardType[CardTypeIndex] << DrawShape(ComputerCard[i]) << endl;
	}

	cout << "Total : " << TotalComputerScore<<  endl;
	cout << "==================\n" << endl;


	cout << "==================" << endl;
	cout << "Player Deck" << endl;
	for (int i = 0; i < 3; i++)
	{
		int CardTypeIndex = PlayerCard[i] / 13;

		cout << CardType[CardTypeIndex] << DrawShape(PlayerScore[i]) << endl;
	}

	cout << "Total : " << TotalPlayerScore << endl;
	cout << "==================\n" << endl;

	

	return 0;
}

//#define YELLOW 위에 이걸 쓰면 엘로우는 뭐다 이렇게 정해줌
//C++에선 enum class 사용





//===========강사님 코드=======//
#include <iostream>
#include <string>

#define CARDSIZE			52

using namespace std;

string DrawShape(int CardNumber)
{
	int Shape = (CardNumber % 13 + 1);

	if (Shape == 11)
	{
		return "J";
	}
	else if (Shape == 12)
	{
		return "Q";
	}
	else if (Shape == 13)
	{
		return "K";
	}
	else if (Shape == 1)
	{
		return "A";
	}

	return to_string(Shape);
}


int main() //entry point
{
	int Player[CARDSIZE];

	//Heart
	//0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12,
	//Spade
	//13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25,
	//Diamond
	//26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38,
	//Clover
	//39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51,

	//똑같은 카드가 나옴 안됨.

	//Init
	int Cards[CARDSIZE] = { 0, };
	string CardType[4] = { "Heart", "Spade", "Diamond", "Clover" };


	for (int i = 0; i < CARDSIZE; ++i)
	{
		Cards[i] = i;
	}

	srand((unsigned int)time(nullptr));


	//Shuffle
	//Random(난수) 두개 선택 해서 교환
	//카드 10장 교환
	for (int i = 0; i < CARDSIZE * 10; ++i)
	{
		int FirstIndex = rand() % CARDSIZE;
		int SecondIndex = rand() % CARDSIZE;
		int Temp = Cards[FirstIndex];

		Cards[FirstIndex] = Cards[SecondIndex];
		Cards[SecondIndex] = Temp;
	}

	//Deal
	int ComputerCard[3];
	int PlayerCard[3];
	//0, 1
	//2, 3
	//4, 5
	for (int i = 0; i < 3; ++i)
	{
		ComputerCard[i] = Cards[i * 2];
		PlayerCard[i] = Cards[(i * 2) + 1];
	}

	//PreProcess
	int ComputerScore[3] = { 0, };
	int PlayerScore[3] = { 0, };

	for (int i = 0; i < 3; ++i)
	{
		ComputerScore[i] = (ComputerCard[i] % 13 + 1) > 10 ? 10 : (ComputerCard[i] % 13 + 1);

		PlayerScore[i] = PlayerCard[i] % 13 + 1;

		PlayerScore[i] = PlayerScore[i] > 10 ? 10 : PlayerScore[i];
	}

	int TotalComputerScore = ComputerScore[0] + ComputerScore[1] + ComputerScore[2];
	int TotalPlayerScore = PlayerScore[0] + PlayerScore[1] + PlayerScore[2];


	//Draw
	if (TotalComputerScore > 21)
	{
		cout << "Player Win" << endl;
	}
	else if (TotalPlayerScore > 21)
	{
		cout << "Player Lose" << endl;
	}
	else if (TotalComputerScore > TotalPlayerScore)
	{
		cout << "Player Lose" << endl;
	}
	else
	{
		cout << "Player Win" << endl;
	}

	cout << "\n==========================" << endl;
	cout << "Computer Deck" << endl;
	for (int i = 0; i < 3; ++i)
	{
		int CardTypeIndex = ComputerCard[i] / 13;

		cout << CardType[CardTypeIndex] << " " << DrawShape(ComputerCard[i]) << endl;
	}
	cout << "Total : " << TotalComputerScore << endl;
	cout << "==========================\n" << endl;

	cout << "==========================" << endl;
	cout << "Player Deck" << endl;
	for (int i = 0; i < 3; ++i)
	{
		int CardTypeIndex = PlayerCard[i] / 13;

		cout << CardType[CardTypeIndex] << " " << DrawShape(PlayerCard[i]) << endl;
	}
	cout << "Total : " << TotalPlayerScore << endl;
	cout << "==========================" << endl;

	return 0;
}


//===============강사님 함수로 바꾼 버전

#include <iostream>
#include <string>

#define CARDSIZE			52

using namespace std;

//Heart
//0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12,
//Spade
//13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25,
//Diamond
//26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38,
//Clover
//39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51,

//똑같은 카드가 나옴 안됨.

int Player[CARDSIZE];
int Cards[CARDSIZE] = { 0, };
string CardType[4] = { "Heart", "Spade", "Diamond", "Clover" };

int ComputerCard[3];
int PlayerCard[3];
//PreProcess
int ComputerScore[3] = { 0, };
int PlayerScore[3] = { 0, };

int TotalComputerScore;
int TotalPlayerScore;


string DrawShape(int CardNumber)
{
	int Shape = (CardNumber % 13 + 1);

	if (Shape == 11)
	{
		return "J";
	}
	else if (Shape == 12)
	{
		return "Q";
	}
	else if (Shape == 13)
	{
		return "K";
	}
	else if (Shape == 1)
	{
		return "A";
	}

	return to_string(Shape);
}


void Init()
{
	for (int i = 0; i < CARDSIZE; ++i)
	{
		Cards[i] = i;
	}

	srand((unsigned int)time(nullptr));
}

void Shuffle()
{
	//Random(난수) 두개 선택 해서 교환
	//카드 10장 교환
	for (int i = 0; i < CARDSIZE * 10; ++i)
	{
		int FirstIndex = rand() % CARDSIZE;
		int SecondIndex = rand() % CARDSIZE;
		int Temp = Cards[FirstIndex];

		Cards[FirstIndex] = Cards[SecondIndex];
		Cards[SecondIndex] = Temp;
	}
}

void Deal()
{
	//Deal
	//0, 1
	//2, 3
	//4, 5
	for (int i = 0; i < 3; ++i)
	{
		ComputerCard[i] = Cards[i * 2];
		PlayerCard[i] = Cards[(i * 2) + 1];
	}
}

void PreProcess()
{
	for (int i = 0; i < 3; ++i)
	{
		ComputerScore[i] = (ComputerCard[i] % 13 + 1) > 10 ? 10 : (ComputerCard[i] % 13 + 1);

		PlayerScore[i] = PlayerCard[i] % 13 + 1;

		PlayerScore[i] = PlayerScore[i] > 10 ? 10 : PlayerScore[i];
	}

	TotalComputerScore = ComputerScore[0] + ComputerScore[1] + ComputerScore[2];
	TotalPlayerScore = PlayerScore[0] + PlayerScore[1] + PlayerScore[2];
}

void Draw()
{
	//Draw
	if (TotalComputerScore > 21)
	{
		cout << "Player Win" << endl;
	}
	else if (TotalPlayerScore > 21)
	{
		cout << "Player Lose" << endl;
	}
	else if (TotalComputerScore > TotalPlayerScore)
	{
		cout << "Player Lose" << endl;
	}
	else
	{
		cout << "Player Win" << endl;
	}

	cout << "\n==========================" << endl;
	cout << "Computer Deck" << endl;
	for (int i = 0; i < 3; ++i)
	{
		int CardTypeIndex = ComputerCard[i] / 13;

		cout << CardType[CardTypeIndex] << " " << DrawShape(ComputerCard[i]) << endl;
	}
	cout << "Total : " << TotalComputerScore << endl;
	cout << "==========================\n" << endl;

	cout << "==========================" << endl;
	cout << "Player Deck" << endl;
	for (int i = 0; i < 3; ++i)
	{
		int CardTypeIndex = PlayerCard[i] / 13;

		cout << CardType[CardTypeIndex] << " " << DrawShape(PlayerCard[i]) << endl;
	}
	cout << "Total : " << TotalPlayerScore << endl;
	cout << "==========================" << endl;

}






int main() //entry point
{
	//절차 지향 프로그래밍
	Init();
	Shuffle();
	Deal();
	PreProcess();
	Draw();

	return 0;
}




