#pragma once

#include "UniversalChipDecorator.hpp"
#include "IPassport.hpp"
#include <memory>

/**
 * \brief Chip decorator for digital passports.
 */
class UniversalChipPassportDecorator final 
	: public UniversalChipDecorator, public IPassport
{
public:
	explicit UniversalChipPassportDecorator(std::shared_ptr<IUniversalChip> controlled);

	virtual size_t GetFreeSpace() override;
	virtual uint8_t* AddDataSection(std::string flag, size_t size) override;
	virtual uint8_t* GetData(std::string flag) override;

	virtual std::string GetHolderName() override;
	virtual std::string GetHolderSurname() override;
	virtual uint64_t GetHolderUUID() override;
};
