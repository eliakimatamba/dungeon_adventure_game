#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <string>

class Room {
	public:
	char *description;
	int nr_number;
	int sr_number;
	int er_number;
	int wr_number;
	void adventure(void);
};

void Room::adventure(){

	char prompt_input[80];
	char *l_command;
	char *file_name;


	std::cout<<"$ ";
	fgets(prompt_input, 80, stdin);
	l_command = strtok(prompt_input, " ");
	while(strncmp(l_command,"loaddungeon", 11) != 0){
		std::cout<<"$ ";
		fgets(prompt_input, 80, stdin);
		l_command = strtok(prompt_input, " ");
	}
	file_name = strtok(NULL, " ");
	file_name[strlen(file_name) - 1] = 0; 

	FILE *fp;

	char *rm_number;
	char *rm_description;
	char *northRoom;
	char *southRoom;
	char *eastRoom;
	char *westRoom;
	char instructions[256];

    fp = fopen(file_name, "r");
	while (fp == NULL) {
		std::cout<<"$ ";
		fgets(prompt_input, 80, stdin);
		l_command = strtok(prompt_input, " ");
		while(strncmp(l_command,"loaddungeon", 11) != 0){
			std::cout<<"$ ";
			fgets(prompt_input, 80, stdin);
			l_command = strtok(prompt_input, " ");
		}
		file_name = strtok(NULL, " ");
		file_name[strlen(file_name) - 1] = 0;
		fp = fopen(file_name, "r");
	}

	int lines = 0;
	int ch = 0;
	while(!feof(fp)){
 		ch = fgetc(fp);
  		if(ch == '\n'){
    	lines++;
  		}
	}
	fclose(fp);

	struct Room adven[lines+2];

	fp = fopen(file_name, "r");
	fgets(instructions, 256, fp);

	int rNum;
	char temp[100];
	char tempDes[256];
	int n,s,e,w;

	strcpy(temp, instructions);
	while (sscanf(temp, "%d $%[^$]$ %d %d %d %d", &rNum, tempDes, &n,&s,&e,&w) != 6){
		std::cout<<tempDes<<std::endl;
		std::cout<<"$ ";
		fgets(prompt_input, 80, stdin);
		l_command = strtok(prompt_input, " ");
		while(strncmp(l_command,"loaddungeon", 11) != 0){
			
			std::cout<<"$ ";
			fgets(prompt_input, 80, stdin);
			l_command = strtok(prompt_input, " ");
		}
		file_name = strtok(NULL, " ");
		file_name[strlen(file_name) - 1] = 0;

		fp = fopen(file_name, "r");
		while (fp == NULL) {
			 
			std::cout<<"$ ";
			fgets(prompt_input, 80, stdin);
			l_command = strtok(prompt_input, " ");
			while(strncmp(l_command,"loaddungeon", 11) != 0){
				 
				std::cout<<"$ ";
				fgets(prompt_input, 80, stdin);
				l_command = strtok(prompt_input, " ");
			}
			file_name = strtok(NULL, " ");
			file_name[strlen(file_name) - 1] = 0;
			fp = fopen(file_name, "r");
		}

	
		lines = 0;
		ch = 0;
		while(!feof(fp)){
	 		ch = fgetc(fp);
	  		if(ch == '\n'){
	    	lines++;
	  		}
		}
		fclose(fp);

		fp = fopen(file_name, "r");
		fgets(instructions, 256, fp);
		strcpy(temp, instructions);
	}
    

    rm_number = strtok(instructions, " ");
    
    int rn = atoi(rm_number);

    rm_description = strtok(NULL, "$"); 
    adven[rn].description = (char*)malloc(sizeof(char)*strlen(rm_description));
    strcpy(adven[rn].description, rm_description);
    char * word = adven[rn].description;

    northRoom = strtok(NULL, " ");
    
    int nrm = atoi(northRoom);
    southRoom = strtok(NULL, " ");
    
    int srm = atoi(southRoom);
    eastRoom = strtok(NULL, " ");
    
    int erm = atoi(eastRoom);
    westRoom = strtok(NULL, " ");
    
    int wei = atoi(westRoom);

    adven[rn].nr_number = nrm;
    adven[rn].sr_number = srm;
    adven[rn].er_number = erm;
    adven[rn].wr_number = wei;

	std::cout<<adven[rn].description<<std::endl;
    while( !(feof(fp)) ){
    	fgets(instructions, 256, fp);

    	strcpy(temp, instructions);
		while (sscanf(temp, "%d $%[^$]$ %d %d %d %d", &rNum, tempDes, &n,&s,&e,&w) != 6){
			std::cout<<"$ ";
			fgets(prompt_input, 80, stdin);
			l_command = strtok(prompt_input, " ");
			while(strncmp(l_command,"loaddungeon", 11) != 0){
				 
				std::cout<<"$ ";
				fgets(prompt_input, 80, stdin);
				l_command = strtok(prompt_input, " ");
			}
			file_name = strtok(NULL, " ");
			file_name[strlen(file_name) - 1] = 0;

			fp = fopen(file_name, "r");
		    
			while (fp == NULL) {
				 
				std::cout<<"$ ";
				fgets(prompt_input, 80, stdin);
				l_command = strtok(prompt_input, " ");
				while(strncmp(l_command,"loaddungeon", 11) != 0){
					 
					std::cout<<"$ ";
					fgets(prompt_input, 80, stdin);
					l_command = strtok(prompt_input, " ");
				}
				file_name = strtok(NULL, " ");
				file_name[strlen(file_name) - 1] = 0;
				fp = fopen(file_name, "r");
			}

			lines = 0;
			ch = 0;
			while(!feof(fp)){
		 		ch = fgetc(fp);
		  		if(ch == '\n'){
		    	lines++;
		  		}
			}
			fclose(fp);

			fp = fopen(file_name, "r");
			fgets(instructions, 256, fp);
			strcpy(temp, instructions);
		}

        rm_number = strtok(instructions, " ");
    	rn = *rm_number - '0';

   	 	rm_description = strtok(NULL, "$");

   	 	adven[rn].description = (char*)malloc(sizeof(char)*strlen(rm_description));
    	strcpy(adven[rn].description, rm_description);

    	northRoom = strtok(NULL, " ");
    
    	nrm = atoi(northRoom);

    	southRoom = strtok(NULL, " ");

    	srm = atoi(southRoom);

    	eastRoom = strtok(NULL, " ");

    	erm = atoi(eastRoom);

    	westRoom = strtok(NULL, " ");

    	wei = atoi(westRoom);

    	adven[rn].nr_number = nrm;
   		adven[rn].sr_number = srm;
    	adven[rn].er_number = erm;
    	adven[rn].wr_number = wei;


    }

    fclose(fp);

    struct Room currentRoom = adven[1];
    char advCom[80];

    while ( strncmp(advCom,"quit",4) != 0){
    	std::cout<<"$ ";
		fgets(advCom, 80, stdin);

		if ( strncmp(advCom,"loaddungeon",11) == 0 ){
			
			for (int i = 1; i < lines+2; i++){
				adven[i].description[0] = 0;
				adven[i].nr_number = -1;
   				adven[i].sr_number = -1;
    			adven[i].er_number = -1;
    			adven[i].wr_number = -1;
			}
			l_command = strtok(advCom, " ");
			file_name = strtok(NULL, " ");
			file_name[strlen(file_name) - 1] = 0;
			fp = fopen(file_name, "r");
			while (fp == NULL) {
				
				std::cout<<"$ ";
				fgets(prompt_input, 80, stdin);
				l_command = strtok(prompt_input, " ");
				while(strncmp(l_command,"loaddungeon", 11) != 0){
					
					std::cout<<"$ ";
					fgets(prompt_input, 80, stdin);
					l_command = strtok(prompt_input, " ");
				}
				file_name = strtok(NULL, " ");
				file_name[strlen(file_name) - 1] = 0;
				fp = fopen(file_name, "r");
			}


			 lines = 0;
			 ch = 0;
			while(!feof(fp)){
		 		ch = fgetc(fp);
		  		if(ch == '\n'){
		    	lines++;
		  		}
			}
			fclose(fp);

			class Room newdungeon[lines+2];
			*adven = *newdungeon;

			fp = fopen(file_name, "r");
			fgets(instructions, 256, fp); 

		    rm_number = strtok(instructions, " ");

		     rn = atoi(rm_number);

		    rm_description = strtok(NULL, "$");
		    adven[rn].description = (char*)malloc(sizeof(char)*strlen(rm_description));
		    strcpy(adven[rn].description, rm_description);


		    northRoom = strtok(NULL, " ");

		     nrm = atoi(northRoom);
		    southRoom = strtok(NULL, " ");

		     srm = atoi(southRoom);
		    eastRoom = strtok(NULL, " ");

		     erm = atoi(eastRoom);
		    westRoom = strtok(NULL, " ");

		     wei = atoi(westRoom);

		    adven[rn].nr_number = nrm;
		    adven[rn].sr_number = srm;
		    adven[rn].er_number = erm;
		    adven[rn].wr_number = wei;

			std::cout<<adven[rn].description<<std::endl;
		    while( !(feof(fp)) ){
		    	fgets(instructions, 256, fp);

		        rm_number = strtok(instructions, " ");
		    	rn = *rm_number - '0';

		   	 	rm_description = strtok(NULL, "$");

		   	 	adven[rn].description = (char*)malloc(sizeof(char)*strlen(rm_description));
		    	strcpy(adven[rn].description, rm_description);

		    	northRoom = strtok(NULL, " ");

		    	nrm = atoi(northRoom);

		    	southRoom = strtok(NULL, " ");

		    	srm = atoi(southRoom);

		    	eastRoom = strtok(NULL, " ");

		    	erm = atoi(eastRoom);

		    	westRoom = strtok(NULL, " ");

		    	wei = atoi(westRoom);


		    	adven[rn].nr_number = (int)malloc(sizeof(int)*nrm);
		    	adven[rn].nr_number = nrm;

		   		adven[rn].sr_number = (int)malloc(sizeof(int)*(nrm));
		   		adven[rn].sr_number = srm;

		    	adven[rn].er_number = (int)malloc(sizeof(int)*(nrm));
		    	adven[rn].er_number = erm;

		    	adven[rn].wr_number = (int)malloc(sizeof(int)*(nrm));
		    	adven[rn].wr_number = wei;

		    	

		    }
		    	fclose(fp);
		}

		else if ( strncmp(advCom,"north",5) == 0 ){
			if (strlen(advCom) != 6)  ;
			else if (currentRoom.nr_number == -1) std::cout<<"You can't go there."<<std::endl;
			else {
				currentRoom = adven[currentRoom.nr_number];
				std::cout<<currentRoom.description<<std::endl;
			}
		}
		else if ( strncmp(advCom,"south",5) == 0){
			if (strlen(advCom) != 6)  ;
			else if (currentRoom.sr_number == -1) std::cout<<"You can't go there."<<std::endl;
			else {
				currentRoom = adven[currentRoom.sr_number];
				std::cout<<currentRoom.description<<std::endl;
			}
		}
		else if ( strncmp(advCom,"east",4) == 0){
			if (strlen(advCom) != 5)  ;
			else if (currentRoom.er_number == -1) std::cout<<"You can't go there."<<std::endl;
			else {
				currentRoom = adven[currentRoom.er_number];
				std::cout<<currentRoom.description<<std::endl;
			}
		}
		else if ( strncmp(advCom,"west",4) == 0){
			if (strlen(advCom) != 5)  ;
			else if (currentRoom.wr_number == -1) std::cout<<"You can't go there."<<std::endl;
			else {
				currentRoom = adven[currentRoom.wr_number];
				std::cout<<currentRoom.description<<std::endl;
			}
		}
		else if ( strncmp(advCom, "quit", 4) == 0) {
			break;
		}
		else  ;

    }
}


int main(){
	Room room;
	room.adventure();

	return 0;
}




