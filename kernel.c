#include "include/screen.h"
#include "include/types.h"
#include "include/kb.h"
#include "include/string.h"
//#include "include/fcfs.h"
//intarr result;
void kmain()
{	
	clearScreen(); 
	print("Welcome Ihis is our Hospital resource management system\n");      
	while (1) {
		print("\nNIDOS> ");
                
                string ch = readStr();
                if(strEql(ch,"general"))
                {
                	print("\n");
                        print("\nEnter the total number of resources: ");
			int resource_count = readInt();
			//int resource_count=*result;
			print("\nEnter the number of processes: ");
			int num_processes=readInt();
			//int num_processes=*result;
			print("\n");
			int available_resources = resource_count;
    			int allocation[num_processes];
    			for (int i = 0; i < num_processes; i++) {
    			
        			allocation[i] = 0;
    			}
    			for (int i = 0; i < num_processes; i++) {
        			intStr("\nEnter resource request for Process ",i+1);
				if (i+1==10 || i+1==20 || i+1==30)
					print("0");
        			print(" : ");
        			int resource_request=readInt();
        			//int resource_request=*result;
        			if (resource_request <= available_resources) {
            				allocation[i] = resource_request;
            				available_resources -= resource_request;
            				intStr("\nProcess ",i+1);
            				if (i+1==10 || i+1==20 || i+1==30)
						print("0");
            				intStr(" allocated ",allocation[i]);
            				print(" resources");
            				print("\n");
        			}
        			 else {
            				intStr("\nProcess ",i+1);
            				if (i+1==10 || i+1==20 || i+1==30)
						print("0");
            				print(" waiting for process");
            				print("\n");
        			}
			}
                }
                else if(strEql(ch,"clear")){
                	clearScreen();
                	print("Welcome Ihis is our Hospital resource management system\n");
                }
                else if(strEql(ch,"emergency")){
                	print("\n");
                	int resource_count;
                	int num_processes;
    			print("\nEnter the total number of resources: ");
    			resource_count= readInt();
    			print("\nEnter the number of processes: ");
    			print("\n");
    			num_processes=readInt();
    			int available_resources = resource_count;
    			int priorities[num_processes];
    			int allocation[num_processes];

    			for (int i = 0; i < num_processes; i++) {
        			allocation[i] = 0;
    			}
    			for (int i = 0; i < num_processes; i++) {
        			intStr("\nEnter priority for process ",i+1);
        			if (i+1==10 || i+1==20 || i+1==30)
					print("0");
        			print(" : ");
        			priorities[i]=readInt();
        			print("\n");
    			}

    			for (int i = 0; i < num_processes; i++) {
        			int highest_priority = -1;
        			int highest_priority_index = -1;

       
        		for (int j = 0; j < num_processes; j++) {
            			if (allocation[j] == 0 && priorities[j] > highest_priority) {
                			highest_priority = priorities[j];
                			highest_priority_index = j;
            			}
        		}

        		if (highest_priority_index != -1) {
            			int resource_request;
            			intStr("\nEnter resource request for Process ",highest_priority_index+1);
            			if (highest_priority_index+1==10 || highest_priority_index+1==20 || highest_priority_index+1==30)
					print("0");
            			print(" : ");
            			resource_request=readInt();

            			if (resource_request <= available_resources) {
                
                			allocation[highest_priority_index] = resource_request;
                			available_resources -= resource_request;
                			intStr("\nProcess ",highest_priority_index+1);
                			if (highest_priority_index+1==10 || highest_priority_index+1==20 || highest_priority_index+1==30)
						print("0");
                			intStr(" allocated ",allocation[highest_priority_index]);
                			print(" resources");
                			print("\n");
            			}
            			else {
                			intStr("\nProcess ",highest_priority_index+1);
                			if (highest_priority_index+1==10 || highest_priority_index+1==20 || highest_priority_index+1==30)
						print("0");
                			print(" waiting for resources\n");
            			}
        		}
    			}
                }
                else{
                	print("\nbad command");
                }       
	}
}
