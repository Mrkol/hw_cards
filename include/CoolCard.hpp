#pragma once

#include "IUniversalChip.hpp"

class CoolCard : public IUniversalChip
{
public:
	virtual size_t GetFreeSpace() override;
	virtual uint8_t* AddDataSection(std::string flag, size_t size) override;
	virtual uint8_t* GetData(std::string flag) override;
};
