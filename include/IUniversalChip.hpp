#pragma once

#include <cstddef>
#include <string>


/**
 * \brief Holds the basic functionality of a chip.
 * \details This interface incapsulates the basic functionality of a
 *          universal chip. The interface is provided by the chip 
 *          manufacturer and therefore cannot be changed easily.
 */
class IUniversalChip
{
public:
	/**
	 * \brief Querries the amount of free space left on this chip.
	 */
	virtual size_t GetFreeSpace() = 0;

	/**
	 * \brief Creates a named data section with the specified size
	 *        and returns a pointer to the start of the data block.
	 */
	virtual uint8_t* AddDataSection(std::string flag, size_t size) = 0;

	/**
	 * \brief Returns a pointer to the specified data section. 
	 */
	virtual uint8_t* GetData(std::string flag) = 0;
};
