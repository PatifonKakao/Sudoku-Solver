#pragma once

#include<vector>
#include <algorithm>
#include <deque>

#include<iostream>


typedef std::vector<std::vector<uint8_t>> vec_vec;


class Solver {
public:

	Solver(const vec_vec &mx);
	vec_vec solve();

	void print(const vec_vec &mx);

private:

	vec_vec m;
	vec_vec ans;

	std::deque<std::pair<int, int>> places;
	std::vector <std::deque<int>> deqs;

	const static uint8_t N = 9;
	const static uint8_t M = 3;

	bool flag_one_solution = true;


	void brute_force(int n);
	bool set_possible_digs(int x, int y, std::deque<int> &deq);

};

