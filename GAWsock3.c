/* ------------------------------------------------------------------------- *
 * Name   : GAWsock3
 * Author : Gerard Wassink
 * Date   : December 2022
 * Purpose: Send and receive data to and from the connected server
 * Versions:
 *   0.1  : Initial code base
 *   
 * ------------------------------------------------------------------------- */
#define VERSION "0.1"
/* ------------------------------------------------------------------------- *
 *             GNU LICENSE CONDITIONS
 * ------------------------------------------------------------------------- *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 *
 * ------------------------------------------------------------------------- *
 *       Copyright (C) December 2022 Gerard Wassink
 * ------------------------------------------------------------------------- */

#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>


/* ------------------------------------------------------------------------- *
 *                                                     Function declarations
 * ------------------------------------------------------------------------- */
void Initialize();
char inputCharacter();
void clearScreen();


/* ------------------------------------------------------------------------- *
 *                                                              Main routine
 * ------------------------------------------------------------------------- */
int main(int argc , char *argv[])
{
    
    int socket_desc;
	struct sockaddr_in server;
    char *message, server_reply[2000];
	
    Initialize();
    
									// Instantiate socket
	socket_desc = socket(AF_INET , SOCK_STREAM , 0);
	if (socket_desc != -1) 		    // check result
    {
		puts("Socket created");

									// Populate server struct
        server.sin_addr.s_addr = inet_addr("142.250.179.142");
        server.sin_family = AF_INET;
        server.sin_port = htons( 80 );

                                    //Connect to remote server
        if (connect(socket_desc , (struct sockaddr *)&server , sizeof(server)) >= 0) 
        {
            puts("Connected");
            
                                    //Send some data
            message = "GET / HTTP/1.1\r\n\r\n";
            if( send(socket_desc , message , strlen(message) , 0) >= 0) 
            {
                puts("Data Send");
                
                                    //Receive a reply from the server
                if( recv(socket_desc, server_reply , 2000 , 0) >= 0)
                {
                    puts("Reply received");
                    puts(server_reply);
                    
                } else {
                    puts("recv failed");
                }
            } else {
                puts("Send failed");
                return 1;
            }
        
        } else {
            puts("Connect error");
            return 1;
        }
        
    } else {
		puts("Could not create socket");
	
    }
    
	return 0;
}


/* ------------------------------------------------------------------------- *
 *                                                       Input one character
 * ------------------------------------------------------------------------- */
char inputCharacter() {    
    char c;
    scanf("%c", &c);
    return c;
}


void Initialize() {
    clearScreen();
    printf("%s%s\n", "GAWsock1 version", VERSION);
    puts("Test opening a socket, press a key");

    inputCharacter();
}


/* ------------------------------------------------------------------------- *
 *                                                           Clear Screen
 * ------------------------------------------------------------------------- */
void clearScreen() {
    printf("%c%s%c%s%c%s", 27, "[2J", 27, "[0m", 27, "[00;00H");
}

