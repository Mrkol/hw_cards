#pragma once

#include "UniversalChipDecorator.hpp"
#include "ICreditCard.hpp"
#include <memory>

/**
 * \brief Chip decorator for credit cards.
 */
class UniversalChipCreditCardDecorator final 
	: public UniversalChipDecorator, public ICreditCard
{
public:
	explicit UniversalChipCreditCardDecorator(std::shared_ptr<IUniversalChip> controlled);

	virtual size_t GetFreeSpace() override;
	virtual uint8_t* AddDataSection(std::string flag, size_t size) override;
	virtual uint8_t* GetData(std::string flag) override;

	virtual void Widthdraw(uint64_t amount) override;
	virtual void Deposit(uint64_t amount) override;
	virtual uint64_t Query() override;
};
