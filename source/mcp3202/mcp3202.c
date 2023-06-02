#include <my_dspi.h>
#include "board.h"
#include "peripherals.h"
#include "pin_mux.h"
#include "clock_config.h"
#include "MK02F12810.h"
#include "mcp3202.h"


uint8_t sspreadbuf[2];

void CS_Init(void)
{
//	GPIO_PinWrite(BOARD_INITPINS_SPI_CS0_GPIO, BOARD_INITPINS_SPI_CS0_GPIO_PIN_MASK, 1);
}


void CS_Force(int32_t state)
{
//	GPIO_PinWrite(BOARD_INITPINS_SPI_CS0_GPIO, BOARD_INITPINS_SPI_CS0_GPIO_PIN_MASK, state);
}


void MCP3202_Config_Request(void)
{
	SPI_Config_Request(8, SSP_SLOW, CS_GPIO);
	CS_Init();
}


uint32_t MCP3202_Read_Reg(uint32_t addr)
{
  uint8_t tx_data[2];
  uint8_t chanBits;

  if (addr == 0) {
  	tx_data [0] = 0b11010000 ;
  } else {
  	tx_data [0] = 0b11110000 ;
  }
  tx_data [1] = 0;

  CS_Force(0);
  SPI_Tx_Rx_Data(tx_data, 2, sspreadbuf, 2);
  CS_Force(1);

  return ((sspreadbuf [0] << 7) | (sspreadbuf [1] >> 1)) & 0xFFF ;
}
