#include "Voca.hpp"

void Voca::ClearCin() // 시그널처리 -> 안해주면 버퍼에 에러코드 남아있어서 문제생긴다~
{
	if (cin.eof())
	{
		cin.clear();
		clearerr(stdin);
	}
}

void	Voca::inOrderTest(int date)
{
	int re;
	string	answer;
	vector<int>	wrong;
	vector<string>	my_answer;

	for (int i = 0; i < static_cast<int>(voca[date].size()); i++)
	{
		bool flag = true;

		cout<<voca[date][i][1]<<" : ";
		getline(std::cin, answer);
		Voca::ClearCin();
		for (int j = 2; j <  static_cast<int>(voca[date][i].size()); j++)
		{
			if (answer == voca[date][i][j])
			{
				cout<<"ʕ•̀ω•́ʔ✧ 맞았습니다."<<endl;
				flag = false;
			}
		}
		if (flag)
		{
			my_answer.push_back(answer);
			cout<<"ʕ;ᴥ;ʔ 틀렸습니다. "<<voca[date][i][1]<<"의 뜻은 ";
			for (int j = 2; j <  static_cast<int>(voca[date][i].size()) - 1; j++)
			{
				cout<<"\""<<voca[date][i][j]<<"\""<<", ";
			}
			cout<<"\""<<voca[date][i][static_cast<int>(voca[date][i].size()) - 1]<<"\""<<"입니다."<<endl;
			wrong.push_back(i);
		}
		cout<<endl<<endl;
	}
	cout<<"--------------------------------------------------------------------------------"<<endl;
	cout<<endl<<endl<<endl;
	cout<<"ʕ •ₒ• ʔ 시험이 종료되었습니다!!"<<std::endl;
	if (wrong.size() == 0)
		cout<<"ʕ≧ᴧ≦ʔ❀ 하나도 틀리지 않고 다 맞았습니다. 대단해요!!"<<endl;
	else
	{
		cout<<"ʕ•́︿•̀ʔ 아쉽게도 "<<wrong.size()<<"개 틀리셨습니다."<<endl;
		cout<<"ʕ´•ᴧ•`ʔ 틀린 내용은 다음과 같습니다."<<endl;
		cout<<endl<<endl<<endl;
		cout<<"--------------------------------------------------------------------------------"<<endl;
		for (int i = 0; i < static_cast<int>(wrong.size()); i++)
		{
			cout<<"ʕ•̀ᴥ•́ʔ "<<std::left<<std::setw(20)<<voca[date][wrong[i]][1]<<" : ";
			for (int j = 2; j <  static_cast<int>(voca[date][wrong[i]].size()) - 1; j++)
			{
				cout<<"\""<<voca[date][wrong[i]][j]<<"\""<<",   ";
			}
			cout<<"\""<<voca[date][wrong[i]][static_cast<int>(voca[date][wrong[i]].size()) - 1]<<"\""<<endl;
			cout<<"ʕ•̀ᴥ•́ʔ "<<std::left<<std::setw(25)<<"내 입력 내용"<<" : "<<"\""<<my_answer[i]<<"\""<<endl<<endl<<endl;
		}
		cout<<endl<<endl<<endl<<"ʕ◕ᴥ◕ʔ 틀린 부분만 다시 시험보시겠습니까?(1.예, 2.아니요) : ";
		getline(std::cin, answer);
		ClearCin();
		if (answer == "1")
		{
			for (int i = 0; i < static_cast<int>(wrong.size()); i++)
			{
				bool flag = true;
				cout<<voca[date][wrong[i]][1]<<" : ";
				getline(std::cin, answer);
				ClearCin();
				for (int j = 2; j <  static_cast<int>(voca[date][wrong[i]].size()); j++)
				{
					if (answer == voca[date][wrong[i]][j])
					{
						cout<<"ʕ•̀ω•́ʔ✧ 맞았습니다."<<endl;
						flag = false;
					}
				}
				if (flag)
				{
					cout<<"ʕ;ᴥ;ʔ 틀렸습니다. "<<voca[date][wrong[i]][1]<<"의 뜻은 ";
					for (int j = 2; j <  static_cast<int>(voca[date][wrong[i]].size()) - 1; j++)
					{
						cout<<"\""<<voca[date][wrong[i]][j]<<"\""<<", ";
					}
					cout<<"\""<<voca[date][wrong[i]][static_cast<int>(voca[date][wrong[i]].size()) - 1]<<"\""<<"입니다."<<endl;
				}
				cout<<endl<<endl;
			}
		}
	}
	cout<<endl<<endl<<"ʕ≧ᴥ≦ʔ 시험이 끝났습니다 :)"<<endl<<endl<<endl;
}

void	Voca::randomTest(int date)
{
	cout<<"아직 구현중입니다"<<endl;
}

void	Voca::oneByOneTest(int date)
{
	cout<<"아직 구현중입니다"<<endl;
}

void	Voca::parse(void)
{
	std::ifstream	readFile;
	std::string		filename;
	std::string		line;
	std::string		words;
	std::ofstream	outfile;
	
	
	vector<vector<string> >	one_day;
	int	date = 1;

	filename = "words.txt";
	voca.push_back(one_day);
	readFile.open(filename.c_str());
	if (readFile.is_open())
	{
		while (!readFile.eof())
		{
			std::istringstream	ss;
			vector<string>	one_word;

			getline(readFile, line);
			ss.str(line);
			getline(ss, words, ':');
			one_word.push_back(words);

			if (atoi(words.c_str()) != date)
			{
				vector<vector<string> >	t;
				voca.push_back(one_day);
				one_day = t;
				date += 1;
			}
			while (getline(ss, words, ':'))
			{
				one_word.push_back(words);
			}
			one_day.push_back(one_word);
		}
		voca.push_back(one_day);
		readFile.close();
	}
	else
	{
		std::cout<<"File open error"<<std::endl;
	}
}