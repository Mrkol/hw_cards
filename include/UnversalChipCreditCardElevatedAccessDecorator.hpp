#pragma once

#include "UniversalChipDecorator.hpp"
#include "UniversalChipCreditCardElevatedAccessGranter.hpp"
#include "ICreditCardElevatedAccess.hpp"
#include <memory>

/**
 * \brief Chip decorator for credit cards.
 */
class UniversalChipCreditCardElevatedAccessDecorator final 
	: public UniversalChipDecorator, public ICreditCardElevatedAccess
{
public:
	virtual size_t GetFreeSpace() override;
	virtual uint8_t* AddDataSection(std::string flag, size_t size) override;
	virtual uint8_t* GetData(std::string flag) override;

	virtual void Widthdraw(uint64_t amount) override;
	virtual void Deposit(uint64_t amount) override;
	virtual const std::string& GetHolderName() override;
	virtual uint64_t Query() override;

private:
	friend class UniversalChipCreditCardElevatedAccessGranter;

	explicit UniversalChipCreditCardElevatedAccessDecorator(
		std::shared_ptr<IUniversalChip> controlled);
};
