#ifndef VOCA_HPP
# define VOCA_HPP

# include <iomanip>
# include <iostream>
# include <vector>
# include <string>
# include <cstdio>
# include <fstream>
# include <sstream>
# include <cstdlib>

using namespace std;

class Voca 
{
	private:
		vector<vector<vector<string> > > voca;

	public:
		Voca();
		int date;
		void	ClearCin();
		void	parse(void);
		void	inOrderTest(int test);
		void	randomTest(int test);
		bool	checkWord(string input, int idx_i, int idx_j);
		void	printWrongWord(vector<int>	wrong, vector<string>	my_answer);
		void	oneByOneTest(int test);
};

#endif