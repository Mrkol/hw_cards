#pragma once

#include "UniversalChipDecorator.hpp"
#include "ICreditCardAccess.hpp"
#include <memory>

/**
 * \brief Chip decorator for credit cards.
 */
class UniversalChipCreditCardAccessDecorator final 
	: public UniversalChipDecorator, public ICreditCardAccess
{
public:
	explicit UniversalChipCreditCardAccessDecorator(
		std::shared_ptr<IUniversalChip> controlled);

	virtual std::string GetHolderName() override;
	virtual uint64_t QueryBalance() override;

private:
	static const std::string NAME_FLAG;
	static const std::string BALANCE_FLAG;
};
