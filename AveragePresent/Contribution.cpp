#include "Contribution.h"

void optimal_solution(int persons, int price)
{
	bool affords = false;
	std::vector<int> budget,res;
	int sum = 0, average = price / persons;
	for (int i = 0; i < persons; i++)
	{
		int temp = 0;
		std::cin >> temp;
		sum += temp;
		budget.emplace_back(temp);
	}
	if (sum < price)
		std::cout << "IMPOSSIBLE\n";
	else 
	{
	std::sort(budget.begin(), budget.end());
		for(int i=0;i<budget.size();i++)
		{
			if (budget.at(i) < average) {
				res.emplace_back(budget.at(i));
				price -= budget.at(i);
				average = price / --persons ;
				affords = false;
			}
			else
			{
				if (price % persons != 0) {
					res.emplace_back(average);
					persons--;
					affords = true;
					price -= average;
				}
				else
					if(affords)
					res.emplace_back(average+1);
					else
					res.emplace_back(average);

			}
		}
	}
	for (int i = 0; i < res.size(); i++) { std::cout << res.at(i) << std::endl; }
}
