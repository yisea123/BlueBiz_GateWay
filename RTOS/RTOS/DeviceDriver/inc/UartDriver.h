﻿/*
 * UartDriver.h
 *
 * Created: 2016-12-02 오후 9:18:41
 *  Author: kimkisu
 */ 


#ifndef UARTDRIVER_H_
#define UARTDRIVER_H_
#include "FreeRTOS.h"
#include "task.h"
#include "DeviceDriverInterface.h"
#include "semphr.h"
#include "queue.h"
#define malloc(size) pvPortMalloc(size)
#define free(ptr) vPortFree(ptr)
#define F_CPU 16000000UL
#define UBRR_VALUE (((F_CPU / (USART_BAUDRATE * 16UL))) - 1)
#define USART_BAUDRATE 4800

class DeviceDriveInterFace;

class UartDriver : public DeviceDriveInterFace
{
	private:
	SemaphoreHandle_t char_Mutex;
	SemaphoreHandle_t Uart_Mutex;
	static UartDriver* inst;
	void UART_Putchar(const char data);
	void UART_PutString(const char *str);
	public:
	UartDriver();
	void Device_Init();
	void* operator new(size_t size);
	void operator delete(void* ptr);
	void Device_Writes(const char* data);
	void Device_Write(char data);
	static UartDriver* getInstance();
	
};


#endif /* UARTDRIVER_H_ */