#include "stdafx.h"
#include <vector>
#include <algorithm>
#include <iterator>
#include <iostream>

#include "TransformerBattle.h"

using namespace std;
using namespace transformers;

// The statement says that the transormers are sorted by rank.
// DOes this mean that they are not sorted by type A vs D?
// What if I have the case of D A A D D ?
// Does this mean D vs A and then A vs D 
// I decided to split the input into 2, Ds and As
// Another question, do the surviving members fight again  or
// does the battle has one 1 iteration?
// I decided to have only 1 iteration which seems to be as described in the problem

BattleResult TransformerBattle::Battle(const vector<Transformer>& decepticons, const vector<Transformer>& autobots) const
{
	if ((autobots.size() == 0) && (decepticons.size() == 0))
	{
		return BattleResult();
	}

	if (decepticons.size() == 0)
	{
		BattleResult result;

		result.winner = -1;
		result.survivingMembers = vector<Transformer>(autobots);

		return result;
	}

	if (autobots.size() == 0)
	{
		BattleResult result;

		result.winner = 1;
		result.survivingMembers = vector<Transformer>(decepticons);

		return result;
	}

	return RealBattle(decepticons, autobots);
};

BattleResult TransformerBattle::RealBattle(const vector<Transformer>& decepticons, const vector<Transformer>& autobots) const
{
	BattleResult result;

	int dLen = decepticons.size();
	int aLen = autobots.size();
	int i = 0;
	for (; ; ++i)
	{
		if (i >= dLen)
		{
			copy(autobots.begin() + i, autobots.end(), back_inserter(result.survivingMembers));

			break;
		}

		if (i >= aLen)
		{
			copy(decepticons.begin() + i, decepticons.end(), back_inserter(result.survivingMembers));

			break;
		}

		if (decepticons[i].name == "Predaking")
		{
			if (autobots[i].name == "Optimus Prime")
			{
				result.winner = 0;
				result.survivingMembers.clear();

				return result;
			}

			++result.winner;

			continue;
		}

		if (autobots[i].name == "Optimus Prime")
		{
			if (autobots[i].name == "Predaking")
			{
				result.winner = 0;
				result.survivingMembers.clear();

				return result;
			}

			--result.winner;

			continue;
		}

		int courageDiff = decepticons[i].courage - autobots[i].courage;
		int strengthDiff = decepticons[i].strength - autobots[i].strength;
		if ((courageDiff >= 4) && (strengthDiff >= 3))
		{
			++result.winner;
			result.survivingMembers.push_back(decepticons[i]);
			continue;
		}

		if ((courageDiff <= (-4)) && ((strengthDiff <= (-3))))
		{
			--result.winner;
			result.survivingMembers.push_back(autobots[i]);
			continue;
		}

		int skillDiff = decepticons[i].skill - autobots[i].skill;
		if (skillDiff >= 3)
		{
			++result.winner;
			result.survivingMembers.push_back(decepticons[i]);
			continue;
		}

		if (skillDiff <= (-3))
		{
			--result.winner;
			result.survivingMembers.push_back(autobots[i]);
			continue;
		}

		int dRating = decepticons[i].Rating();
		int aRating = autobots[i].Rating();

		if (dRating > aRating)
		{
			result.survivingMembers.push_back(decepticons[i]);
			++result.winner;
		}
		else if (dRating < aRating)
		{
			result.survivingMembers.push_back(autobots[i]);
			--result.winner;
		}
	}

	result.numberOfBattles = i;

	return result;
}

void TransformerBattle::DisplayResult(const BattleResult& result) const
{
	cout << "\n Winner: ";

	if (result.winner > 0)
	{
		cout << "Deceptions \n";
	}
	else if (result.winner < 0)
	{
		cout << "Autobots \n";
	}
	else
	{
		cout << "Tie\n";
	}

	cout << "Number of battles: " << result.numberOfBattles << "\n";

	cout << "Surviving members: ";
	for (auto& t : result.survivingMembers)
	{
		cout << t.name << "\n";
	}
	cout << "\n";
}
