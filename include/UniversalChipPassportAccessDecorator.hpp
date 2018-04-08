#pragma once

#include "UniversalChipDecorator.hpp"
#include "IPassportAccess.hpp"
#include <memory>

/**
 * \brief Chip decorator for digital passports.
 */
class UniversalChipPassportAccessDecorator final 
	: public UniversalChipDecorator, public IPassportAccess
{
public:
	explicit UniversalChipPassportAccessDecorator(
		std::shared_ptr<IUniversalChip> controlled);

	virtual std::string GetHolderName() override;
	virtual std::string GetHolderSurname() override;
	virtual uint64_t GetHolderUUID() override;

private:
	static const std::string NAME_FLAG;
	static const std::string SURNAME_FLAG;
	static const std::string UUID_FLAG;
};
