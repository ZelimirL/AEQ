// Assignment.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <algorithm>
#include <iterator>
#include <iostream>

#include "TransformerBattle.h"

using namespace std;
using namespace transformers;

int NumberOfCastles(const vector<int>& input)
{
	if (input.size() == 0)
	{
		return 0;
	}

	if (input.size() == 1)
	{
		return 1;
	}

	int numberOfCastles = 1;
	int currentHeight = input[0];

	for_each( ++input.begin(), input.end(),
		[&numberOfCastles, &currentHeight]
		(auto& elem)
		{
			if (elem != currentHeight)
			{
				++numberOfCastles;
				currentHeight = elem;
			}
		});

	return numberOfCastles;
}

void TestPart1()
{
	// test/
	{
		vector<int> v1;
		cout << "N(v1) = " << NumberOfCastles(v1) << "\n";
	}

	{
		vector<int>v2(5, 3);
		cout << "N(v2) = " << NumberOfCastles(v2) << "\n";
	}

	{
		vector<int> v3{ 1,2,3,4,5,5};
		cout << "N(v3) = " << NumberOfCastles(v3) << "\n";
	}

	{
		// For the [2,6,6,6,3] case  we
		// build a castle at 2, then we have a valley fo 6s = another castle
		// then we have a peak = another castle
		// for a total of 3

		vector<int> v4{ 2,6,6,6,3 };
		cout << "N(v4) = " << NumberOfCastles(v4) << "\n";
	}

	{
		// For the [6,1,4] case  we 
		// build a castle at 6, then we have a valley  = another castle
		// then we have a peak = another castle
		// for a total of 3

		vector<int> v5{ 6,1,4 };
		cout << "N(v5) = " << NumberOfCastles(v5) << "\n";
	}
}

void TestTransformers()
{
	{
		vector<Transformer> decepticons;

		vector<Transformer> autobots;

		TransformerBattle tBattle;

		BattleResult result = tBattle.Battle(decepticons, autobots);

		tBattle.DisplayResult(result);
	}


	{
		vector<Transformer> decepticons{
			 Transformer{ "Soundwave", 8, 9, 2, 6, 7, 5, 6, 10 }
		};

		vector<Transformer> autobots{
			Transformer {"Bluestreak", 6,6,7,9,5,2,9,7},
			Transformer { "Hubcap", 4,4,4,4,4,4,4,4}
		};

		TransformerBattle tBattle;

		BattleResult result = tBattle.Battle(decepticons, autobots);

		tBattle.DisplayResult(result);
	}

	{
		vector<Transformer> decepticons{
			Transformer{ "Soundwave", 8, 9, 2, 6, 7, 5, 6, 10 },
			Transformer{ "Predaking", 8, 9, 2, 6, 7, 5, 6, 10 }
		};

		vector<Transformer> autobots{
			Transformer{ "Bluestreak", 6,6,7,9,5,2,9,7 },
			Transformer{ "Hubcap", 4,4,4,4,4,4,4,4 }
		};

		TransformerBattle tBattle;

		BattleResult result = tBattle.Battle(decepticons, autobots);

		tBattle.DisplayResult(result);
	}

	{
		vector<Transformer> decepticons{
			Transformer{ "Soundwave", 8, 9, 2, 6, 7, 5, 6, 10 },
			Transformer{ "Predaking", 8, 9, 2, 6, 7, 5, 6, 10 }
		};

		vector<Transformer> autobots{
			Transformer{ "Bluestreak", 6,6,7,9,5,2,9,7 },
			Transformer{ "Optimus Prime", 4,4,4,4,4,4,4,4 }
		};

		TransformerBattle tBattle;

		BattleResult result = tBattle.Battle(decepticons, autobots);

		tBattle.DisplayResult(result);
	}
}

int main()
{
	//TestPart1();

	TestTransformers();
	
	char c;
	cin >> c;

    return 0;
}

