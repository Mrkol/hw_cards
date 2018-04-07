#pragma once

#include "IUniversalChip.hpp"
#include <memory>


/**
 * \brief Base class for decorators of universal chips.
 */
class UniversalChipDecorator : public IUniversalChip
{
public:
	explicit UniversalChipDecorator(std::shared_ptr<IUniversalChip> controlled);

	virtual std::size_t GetFreeSpace() override;
	virtual uint8_t* AddDataSection(std::string flag, std::size_t size) override;
	virtual uint8_t* GetData(std::string flag) override;

	virtual ~UniversalChipDecorator() = 0;

private:
	std::shared_ptr<IUniversalChip> controlled_;
};
