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
	string	answer;
	for (int i = 0; i < static_cast<int>(voca[date].size()); i++)
	{
		bool flag = true;

		cout<<voca[date][i][1]<<" : ";
		getline(std::cin, answer);
		ClearCin();
		for (int j = 2; j <  static_cast<int>(voca[date][i].size()); j++)
		{
			if (answer == voca[date][i][j])
			{
				cout<<"맞았습니다 :)"<<endl;
				flag = false;
			}
		}
		if (flag)
		{
			cout<<"틀렸습니다. ㅜㅡㅜ "<<voca[date][i][1]<<"의 뜻은";
			for (int j = 1; j <  static_cast<int>(voca[date][i].size()); j++)
			{
				cout<<voca[date][i][j]<<" ";
			}
			cout<<"입니다."<<endl;
		}
	}
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
	char	date = '1';

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
			if (line[0] != date)
			{
				vector<vector<string> >	t;
				voca.push_back(one_day);
				one_day = t;
				date += 1;
			}
			ss.str(line);
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