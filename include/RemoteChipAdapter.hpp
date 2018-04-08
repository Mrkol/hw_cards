#pragma once

#include "IUniversalChip.hpp"


/**
 * \brief Adapts a virtual remote chip to the provided API interface.
 * \details Each method call is forwarded to a server for further processing.
 *          this is just an example for this API's usage.
 */
class RemoteChipAdapter : public IUniversalChip
{
public:
	virtual size_t GetFreeSpace() = 0;
	virtual uint8_t* AddDataSection(std::string flag, size_t size) = 0;
	virtual uint8_t* GetData(std::string flag) = 0;

private:
	//std::shared_ptr<ServerConnection> connection_;
};