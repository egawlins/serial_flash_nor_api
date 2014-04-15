/*****************************************************************************
* 
* Copyright © 2014 Edyta Zugaj
*
******************************************************************************/

/**
 * @file serialflash.h
 * @author $Author$
 * @date   $Date$
 * @brief API for Serial Flash Memory.
 *
 * @note API functions do not support input data validation and do not report
 * any error in case of operation failure. 
 *
 */

#ifndef SERIAL_FLASH_H
#define SERIAL_FLASH_H

#ifdef __cplusplus
extern "C" {
#endif

#include <spi.h>
#include <stdint.h>

/** @brief memory page size */
#define S_FLASH_PAGE_SIZE      (0x100)
/** @brief memory sector size */
#define S_FLASH_SECTOR_SIZE    (0x10000)
/** @brief the number of memory pages */
#define S_FLASH_PAGE_MAX_NUM   (0x1000)
/** @brief the number of memory sectors */
#define S_FLASH_SECTOR_MAX_NUM (0x10)


/**
 * @brief Function erases a given sector.
 *
 * @param[in] first the number of first sector to be erased,
 * range: 0x0 -- 0xF.
 * @param[in] last the number of last sector to be erased,
 * range: 0x0 -- 0xF
 * @return -
 */
void s_flash_sector_erase(const uint8_t first,
                          const uint8_t last);

/**
 * @brief Function erases the entire memory.
 *
 * @return -
 */
void s_flash_chip_erase(void);

/**
 * @brief Function checks whether memory is empty.
 *
 * @return true if memory is empty, false otherwise.
 */
_Bool s_flash_is_empty(void);

/**
 * @brief Function writes given page with the data.
 * @param[in] page_num the number of the page to be written,
 * range: 0x0 -- 0xFFF.
 * @param[in] data, start pointer to the load data,
 * range: any valid address.
 * @return -
 */
void s_flash_page_program(const uint16_t page_num,
                          const void* data);

/**
 * @brief Function writes entire memory with the given data.
 * @param[in] data, start pointer to the load data,
 * range: any valid address.
 * @return -
 */
void s_flash_program(const void* data);

/**
 * @brief Function reads memory.
 * @param[in] start_offset the address of first byte to be read,
 * range: 0x0 -- 0xFFFFF.
 * @param[in] end_offset the address of last byte to be read,
 * range: 0x0 -- 0xFFFFF.
 * @param[out] data the start pointer to the memory where read data is stored,
 * range: any valid address.
 * @return -
 */
void s_flash_read(const uint32_t start_offset,
                  const uint32_t end_offset,
                  void* data);

/**
 * @brief Function reads memory.
 * @param[in] start_offset the address of first byte to be read,
 * range: 0x0 -- 0xFFFFF.
 * @param[in] size the size in bytes to be read,
 * range: 0x0 -- 0xFFFFF.
 * @param[out] data the start pointer to the memory where read data is stored,
 * range: any valid address.
 * @return -
 */
void s_flash_read_s(const uint32_t start_offset,
                    const uint32_t size,
                    void* data);
/**
 * @brief Function reads  entire memory.
 * @param[out] data the start pointer to the memory where read data is stored,
 * range: any valid address.
 * @return -
 */
void s_flash_dump(char* data);

/**
 * @brief Function returns memory ID.
 * @return The ID number
 */
uint32_t s_flash_id();
#ifdef __cplusplus
}
#endif

#endif /* SERIAL_FLASH_H */

