
#include <iostream>
#include "Contribution.h"

int main()
{
	int participants = 0, price = 0;
	std::cin >> participants >> price;
	optimal_solution(participants, price);
}
