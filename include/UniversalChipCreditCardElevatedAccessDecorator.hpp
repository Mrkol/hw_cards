#pragma once

#include "UniversalChipDecorator.hpp"
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
	virtual uint8_t* AddDataSection(const std::string& flag, size_t size) override;
	virtual uint8_t* GetDataSection(const std::string& flag) override;

	virtual void Widthdraw(uint64_t amount) override;
	virtual void Deposit(uint64_t amount) override;
	virtual std::string GetHolderName() override;
	virtual uint64_t QueryBalance() override;

private:
	friend class UniversalChipCreditCardElevatedAccessGranter;

	explicit UniversalChipCreditCardElevatedAccessDecorator(
		std::shared_ptr<IUniversalChip> controlled);
	
	static const std::string NAME_FLAG;
	static const std::string BALANCE_FLAG;
};
