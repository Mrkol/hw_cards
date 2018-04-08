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

	virtual size_t GetFreeSpace() override;
	virtual uint8_t* AddDataSection(std::string flag, size_t size) override;
	virtual uint8_t* GetData(std::string flag) override;

	virtual const std::string& GetHolderName() override;
	virtual uint64_t QueryBalance() override;
};
