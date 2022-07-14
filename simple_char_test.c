
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

#define OPEN	'o'
#define CLOSE	'c'
#define READ	'r'
#define WRITE	'w'
#define EXIT	'e'
#define ENTER   '\0'

#define BUFFER_SIZE 1024

void getInput();
void openDevice(){
	open("/dev/simple_char_device", O_RDWR | O_APPEND);
	getInput();
}

void readDevice(){
	printf("\nData read from the device:\n");
	(void)system("cat /dev/simple_char_device");
	getInput();
}

void writeDevice(){
	printf("\nEnter data you want to write to the device:\n");
	char buffer[BUFFER_SIZE];
	char data[BUFFER_SIZE];
	if (fgets(data, BUFFER_SIZE, stdin) != NULL){
		char * strippedData;
		if ((strippedData=strchr(data, '\n')) != NULL){
    		*strippedData = '\0';
		}
		char cmd[BUFFER_SIZE + 40]= {0x0};
		sprintf(cmd,"echo \"%s\" >> /dev/simple_char_device", data);
		system(cmd);
	}
	getInput();	
}

void getInput(){

	char inputBuffer[BUFFER_SIZE];

	printf("\nPlease enter a command (o,r,w,e): ");
	if (fgets(inputBuffer, BUFFER_SIZE, stdin) != NULL){
		if (inputBuffer[0] == OPEN){
			openDevice();
		}
		else if (inputBuffer[0] == READ){
			readDevice();
		}
		else if (inputBuffer[0] == WRITE){
			writeDevice();
		}
		else if (inputBuffer[0] == EXIT){
		}
		else{
			printf("You have given incorrect input");
			getInput();
		}
	}
}

void main(){
	getInput();
}