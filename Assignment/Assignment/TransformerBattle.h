#pragma once

#include <vector>
#include <string>

namespace transformers
{
	class Transformer
	{
	public:
		enum class Type
		{
			N,   // no winner
			A,
			D
		};

		int Rating() const
		{
			return strength + intelligence + speed + endurance + firepower;
		}

		Transformer() = delete;

		std::string name;
		int strength;
		int intelligence;
		int speed;
		int endurance;
		int rank;
		int courage;
		int firepower;
		int skill;
	};

	struct BattleResult
	{
		BattleResult() :
			winner(0), numberOfBattles(0)
		{
			;
		}

		// > 0 D wins
		// < 0 A wins
		// == 0 tie
		int winner;
		int numberOfBattles;
		std::vector<Transformer> survivingMembers;
	};

	class TransformerBattle
	{
	public:
		BattleResult Battle(const std::vector<Transformer>& decepticons, const std::vector<Transformer>& autobots) const;
		void DisplayResult(const BattleResult& result) const;

	private:
		BattleResult RealBattle(const std::vector<Transformer>& decepticons, const std::vector<Transformer>& autobots) const;
	};
}

