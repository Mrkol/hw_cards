#pragma once

#include "IUniversalChip.hpp"
#include <memory>


/**
 * \brief Base class for decorators of universal chips.
 * \details Any class that wants to decorate a universal chip needs to inherit this one.
 *          This abstract class' methods already call the required ones for the universal chip,
 *          so derived classes should call this one's methods as the last thing they do in
 *          the respective overrides.
 */
class UniversalChipDecorator : public IUniversalChip
{
public:
	explicit UniversalChipDecorator(std::shared_ptr<IUniversalChip> controlled);

	virtual std::size_t GetFreeSpace() override;
	virtual uint8_t* AddDataSection(const std::string& flag, std::size_t size) override;
	virtual uint8_t* GetDataSection(const std::string& flag) override;

private:
	std::shared_ptr<IUniversalChip> controlled_;
};
