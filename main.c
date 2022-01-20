#include <stdio.h>
#include <stdlib.h>

FILE* log;
char status[5];
int Change_Num;

int main() {
	Change_Num=0;
	system("curl https://raw.githubusercontent.com/HXHGTS/WARP-WatchDog/main/autocheck.sh > ./autocheck.sh");
	UnlockTest:if (TestOutBound() == 1) {
		Change_Num=Change_Num+1;
		ChangeIP();
		goto UnlockTest;
	}
	else {
		CheckOutBound();
		return 0;
	}
}

int ChangeIP() {
	printf("Changing Outbound ip (%d tries). . .\n",Change_Num);
	system("systemctl restart wg-quick@wgcf");
	return 0;
}

int TestOutBound() {
	printf("Testing Outbound ip . . .\n");
	system("echo 1 | bash autocheck.sh -M 4 > /dev/null");
	log = fopen("./unlock.log", "r");
	fread(status,1,1,log);
	fclose(log);
	if (status[0] == '1') {
		printf("Tested Successful!(%d tries)\n\n",Change_Num);
		return 0;
	}
	else {
		printf("Tested Failed!\n\n");
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
