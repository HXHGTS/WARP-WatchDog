#include <stdio.h>
#include <stdlib.h>

FILE* log;
char status[5];

int main() {
	system("curl https://raw.githubusercontent.com/HXHGTS/WARP-WatchDog/main/autocheck.sh > autocheck.sh");

	UnlockTest:if (TestOutBound() == 1) {
		ChangeIP();
		goto UnlockTest;
	}
	else {
		CheckOutBound();
		return 0;
	}
}

int ChangeIP() {
	system("systemctl restart wg-quick@wgcf");
	return 0;
}

int TestOutBound() {
	system("echo 1 | bash autocheck.sh -M 4");
	log = fopen("unlock.log", "r");
	fread(status,1,1,log);
	fclose(log);
	if (status[0] == '1') {
		return 0;
	}
	else {
		return 1;
	}
}

int CheckOutBound() {
	printf("WARP Outbound ip:\n");
	printf("---------------------------------------\n");
	system("curl --interface 172.16.0.2 ifconfig.me/ip");
	printf("\n---------------------------------------\n");
	printf("Finished!\n");
	return 0;
}
