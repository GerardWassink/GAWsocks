/* ------------------------------------------------------------------------- *
 * Name   : GAWsock1
 * Author : Gerard Wassink
 * Date   : December 2022
 * Purpose: Create TCP/IP socket
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
#include <strings.h>
#include <sys/socket.h>


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
    Initialize();
    
    // *** --------------------------------------------------------------------
    // *** declare and instantiate the socket
    // *** --------------------------------------------------------------------
	int socket_desc;
	socket_desc = socket(AF_INET , SOCK_STREAM , 0);
	
    // *** --------------------------------------------------------------------
    // *** check result
    // *** --------------------------------------------------------------------
	if (socket_desc != -1)
	{
        puts("Create socket successful\n");
	} else {
		puts("Could not create socket\n");
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
    puts("Test opening a socket, press a key\n");

    inputCharacter();
}


/* ------------------------------------------------------------------------- *
 *                                                           Clear Screen
 * ------------------------------------------------------------------------- */
void clearScreen() {
    printf("%c%s%c%s%c%s", 27, "[2J", 27, "[0m", 27, "[00;00H");
}

