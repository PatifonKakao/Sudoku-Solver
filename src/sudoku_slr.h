#pragma once

#include<vector>
#include <algorithm>
#include <deque>

#include<iostream>


typedef std::vector<std::vector<uint8_t>> vect_vect;
typedef std::deque<std::pair<int, int>> deq_xy;


class Solver {
public:

	Solver(const vect_vect &mx);
	vect_vect solve();

	void print(const vect_vect &mx);

private:

	vect_vect sudoku;
	vect_vect ans;

	deq_xy places;
	std::vector <std::deque<int>> deqs;

	const static uint8_t N = 9;
	const static uint8_t M = 3;

	bool flag_one_solution = true;


	void brute_force(int n);
	bool set_possible_digs(int x, int y, std::deque<int> &deq);

};

