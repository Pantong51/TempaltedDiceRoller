#pragma once
#include <cstdint>
#include <cstdlib>
#include <iostream>

#include "Utility.h"

using RollResult = int32_t;

//#TODO: Remove rand and prepare to move to constexpr

struct RollRulesStrategy : private NonCopyable<RollRulesStrategy>
{
	~RollRulesStrategy() override = default;
	[[nodiscard]] virtual RollResult roll() const = 0;
};

template<RollResult T = 0>
struct FlatRoll : public RollRulesStrategy
{
	FlatRoll() = default;
	~FlatRoll() override = default;

	[[nodiscard]] RollResult roll() const override
	{
		return (static_cast<RollResult>(rand()) % T) + 1;
	}
};

template<RollResult T = 0, RollResult U = T>
struct ExplodingRoll : public RollRulesStrategy
{
	ExplodingRoll() = default;
	~ExplodingRoll() override = default;

	[[nodiscard]] RollResult roll() const override
	{
		RollResult currentRoll = (static_cast<RollResult>(rand()) % T) + 1;
		RollResult totalAmt = currentRoll;
		while (currentRoll == U)
		{
			currentRoll = (static_cast<RollResult>(rand()) % T) + 1;
			totalAmt += currentRoll;
		}
		return totalAmt;
	}
};

template<std::derived_from<RollRulesStrategy> T>
struct Advantage : public RollRulesStrategy
{
	Advantage() = default;
	~Advantage() override = default;
	T m_roll;

	[[nodiscard]] RollResult roll() const override
	{
		const RollResult a = m_roll.roll();
		const RollResult b = m_roll.roll();
		return std::max(a, b);
	}
};

template<std::derived_from<RollRulesStrategy> T>
struct Disadvantage : public RollRulesStrategy
{
	Disadvantage() = default;
	~Disadvantage() override = default;
	T m_roll;

	[[nodiscard]] RollResult roll() const override
	{
		const RollResult a = m_roll.roll();
		const RollResult b = m_roll.roll();
		return std::min(a, b);
	}
};

template<std::derived_from<RollRulesStrategy>... Args>
struct Roll
{
	Roll() = default;
	const std::tuple<Args...> m_rules;

	[[nodiscard]] RollResult roll() const
	{
		RollResult rollAmt{ 0 };
		std::apply([&rollAmt](auto&&... args) {((rollAmt += args.roll()), ...); }, m_rules);
		return rollAmt;
	}
};

using D4 = Roll<FlatRoll<4>>;
using D6 = Roll<FlatRoll<6>>;
using D8 = Roll<FlatRoll<8>>;
using D10 = Roll<FlatRoll<10>>;
using D12 = Roll<FlatRoll<12>>;
using D20 = Roll<FlatRoll<20>>;
using D100 = Roll<FlatRoll<100>>;