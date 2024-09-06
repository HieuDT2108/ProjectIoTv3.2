#include "main.h"
#include "quadspi.h"

QSPI_HandleTypeDef hqspi;

void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_QUADSPI_Init(void);

int main(void)
{
  HAL_Init();
  SystemClock_Config();
  MX_GPIO_Init();
  MX_QUADSPI_Init();

  uint8_t txData[256] = {0x01, 0x02, 0x03, 0x04}; // Dữ liệu ghi vào QSPI
  uint8_t rxData[256] = {0}; // Bộ đệm để đọc dữ liệu từ QSPI

  // Ghi dữ liệu vào QSPI
  if (HAL_QSPI_Transmit(&hqspi, txData, HAL_MAX_DELAY) != HAL_OK)
  {
    Error_Handler();
  }

  // Đọc dữ liệu từ QSPI
  if (HAL_QSPI_Receive(&hqspi, rxData, HAL_MAX_DELAY) != HAL_OK)
  {
    Error_Handler();
  }

  while (1)
  {
  }
}

void SystemClock_Config(void)
{
  // Cấu hình clock hệ thống
}

static void MX_GPIO_Init(void)
{
  // Cấu hình GPIO
}

static void MX_QUADSPI_Init(void)
{
  hqspi.Instance = QUADSPI;
  hqspi.Init.ClockPrescaler = 1;
  hqspi.Init.FifoThreshold = 4;
  hqspi.Init.SampleShifting = QSPI_SAMPLE_SHIFTING_NONE;
  hqspi.Init.FlashSize = 23;
  hqspi.Init.ChipSelectHighTime = QSPI_CS_HIGH_TIME_1_CYCLE;
  hqspi.Init.ClockMode = QSPI_CLOCK_MODE_0;
  hqspi.Init.FlashID = QSPI_FLASH_ID_1;
  hqspi.Init.DualFlash = QSPI_DUALFLASH_DISABLE;
  if (HAL_QSPI_Init(&hqspi) != HAL_OK)
  {
    Error_Handler();
  }
}

void Error_Handler(void)
{
  while (1)
  {
  }
}
