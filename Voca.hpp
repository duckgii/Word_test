#ifndef VOCA_HPP
# define VOCA_HPP

# include <iomanip>
# include <iostream>
# include <vector>
# include <string>
# include <cstdio>
# include <fstream>
# include <sstream>

using namespace std;

class Voca 
{
	private:
		vector<vector<vector<string> > > voca;

	public:
		void	ClearCin();
		void	parse(void);
		void	inOrderTest(int test);
		void	randomTest(int test);
		void	oneByOneTest(int test);
};

#endif