
/*
if (flash == 1){
			increment_time();
			LED_Toggle(PROJECT_LED);
}

void run(){

	LED_Init(PROJECT_LED);
	printf("Hello, World!\r\n");
	int index = 0;
	char command[16];
	uint8_t flash = 0;
	int count = 0;


	//uint8_t byte = USART_Read(USART2);
	//printf("%c", byte);

	//use local_echo to print out every typed character
	while(1){
		if (count == 1200000){
			printf("count reached");
			if (flash){
				LED_Toggle(PROJECT_LED);
				count = 0;
			}
		}
		uint8_t byte = USART_Read_NB(USART2);
		local_echo(byte);
		if (byte == 0){
			local_echo(byte);
		}

		if (byte == eol){
			command [index] = 0;
			if(strcmp(command, "on") == 0){
				printf("LED_ON\r\n");
				LED_On(PROJECT_LED);
				flash = 0;
			}
			else if(strcmp(command, "off") == 0){
				printf("LED_OFF\r\n");
				LED_Off(PROJECT_LED);
				flash = 0;
			}
			else if(strcmp(command, "flash") == 0){
				printf("LED_FLASH\r\n");
				flash = 1;
				if (flash){
					LED_Toggle(PROJECT_LED);
				}

			}
			index = 0;
		}
		else if (byte != 0){
			command[index] = byte;
			index++;
		}
	}
}



void flash_demo(){
	init_systick();
	LED_Init(PROJECT_LED);
	//make led flash at a one second interval using
	//the systick timer.
	while(1){
		increment_time();
		LED_Toggle(PROJECT_LED);
	}
}


void timer_demo(){
	printf("timer demo\r\n");
	//initialize the systick timer
	init_systick();
	printf("systick Initialized\n\r");

	int* current_time = (int*) get_count();
	uint8_t hours;
	uint8_t minutes;
	uint8_t seconds;

	while(1){
		//count for one second
		increment_time();

		//print the current time (clock format)
		seconds = *current_time % 60;
		minutes = (*current_time / 60) % 60;
		hours = *current_time / 3600;
		printf("%03d:%02d:%02d\r", hours, minutes, seconds);
	}
}
*/
