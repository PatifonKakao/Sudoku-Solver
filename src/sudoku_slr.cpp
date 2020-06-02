#include "sudoku_slr.h"



Solver::Solver(const vect_vect &sdk)
{
	sudoku = sdk;
}

vect_vect Solver::solve()
{
	for (auto j = 0; j < N; ++j)
		for (auto i = 0; i < N; ++i)
			if (sudoku[j][i] == 0)
				places.push_front(std::make_pair(i, j));
			

	deqs.resize(places.size());

	brute_force(0);

	return ans;
}

void Solver::print(const vect_vect &sdk)
{
	for (auto i = 0; i < N; ++i)
	{
		for (auto j = 0; j < N; ++j)
			std::cout << (int)sdk[i][j] << " ";
		std::cout << std::endl;
	}
	std::cout << std::endl;
}



void Solver::brute_force(int n)
{
	if (n == places.size())
	{
		ans = sudoku;
		flag_one_solution = false;
	}
	if (n < places.size() && flag_one_solution)
	{
		if (set_possible_digs(places[n].first, places[n].second, deqs[n]))
		{
			for (auto &dq : deqs[n])
			{
				sudoku[places[n].second][places[n].first] = dq;
				brute_force(n + 1);
				sudoku[places[n].second][places[n].first] = 0;
			}
			deqs[n].clear();
		}
		else
		{
			return;
		}
	}
}

bool Solver::set_possible_digs(int x, int y, std::deque<int> &deq)
{
	std::vector<bool> contain(N + 1);
	for (auto i = 0; i < N; ++i)
	{
		contain[sudoku[i][x]] = true;
		contain[sudoku[y][i]] = true;
	}

	int x0 = x / M;
	x0 *= M;
	int y0 = y / M;
	y0 *= M;

	for (auto i = x0; i < x0 + M; ++i)
		for (auto j = y0; j < y0 + M; ++j)
			contain[sudoku[j][i]] = true;

	bool flag = false;
	for (auto k = 1; k <= N; ++k)
		if (!contain[k])
		{
			deq.push_front(k);
			flag = true;
		}

	return flag;
}