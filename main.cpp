#include <stdio.h>
#include <conio.h>

#include "fsmsystem.h"
#include "logfile.h"
#include "autoexample.h"

static FSMSystem sys(1 , 1);

DWORD WINAPI SystemThread(void* data) {
	AutoExample automate[3];

	
	const uint8 buffClassNo = 4;
	uint32 buffsCount[buffClassNo] = { 50, 50, 50, 10 };
	uint32 buffsLength[buffClassNo] = { 128, 256, 512, 1024 };

	LogFile lf("log.log" /*log file name*/, "./log.ini" /* message translator file */);
	LogAutomateNew::SetLogInterface(&lf);

	printf("[*] Initializing system...\n");
	sys.InitKernel(buffClassNo, buffsCount, buffsLength, 5);

	sys.Add(&automate[0], AUTOEXAMPLE_FSM, 3 /* the number of automates that will be added */, true);
	for (int i = 1;i < 3;i++) {
		sys.Add(&automate[i], AUTOEXAMPLE_FSM);
	}
	
	printf("[*] Starting system...\n");
	sys.Start();

	return 0;
}

void main() {
	DWORD thread_id;
	HANDLE thread_handle;

	thread_handle = CreateThread(NULL, 0, SystemThread, NULL, 0, &thread_id);

	getch();

	printf("[*] Stopping system...\n");
	sys.StopSystem();

	CloseHandle(thread_handle);
}
