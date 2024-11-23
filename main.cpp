#include "Voca.hpp"

int main()
{
	Voca	obj;
	string	date_s;
	string	command;
	int		date = 0;

	obj.parse();
	while (date < 1 || date > 30)
	{
		cout<<"(ʕᵔᴥᵔʔ) 테스트할 날짜를 선택해주세요(1이상 30이하) : ";
		getline(std::cin, date_s); //cin>>으로 받으면 내부 버퍼에 뭔가 개행이나 널문자 이런게 남아있다. -> 개행으로 확인 아마 원래 개행을 내부에 저장해두는 듯
		date = atoi(date_s.c_str());
		if (date < 1 || date > 30)
			cout<<"(ʕ;︵;ʔ) 잘못된 입력입니다. 1일부터 30일까지 숫자만 입력해주세요"<<endl;
	}
	while (1)
	{
		cout<<"시험 종류를 선택해주세요 [1. 순서대로 전체 단어 시험 보기, 2. 무작위 순서로 전체 단어 시험보기, 3. 단어 하나씩 외우기, 4. 프로그램 종료] : ";
		getline(std::cin, command);
		obj.ClearCin();
		if (command == "1")
			obj.inOrderTest(date);
		else if (command == "2")
			obj.randomTest(date);
		else if (command == "3")
			obj.oneByOneTest(date);
		else if (command == "4")
		{
			cout<<"시험보기4 ~"<<endl;
			break;		
		}
		else
			cout<<"잘못된 값을 입력하셨습니다."<<command<<endl;
	}
	return (0);
}
