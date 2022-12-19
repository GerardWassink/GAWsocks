/* ------------------------------------------------------------------------- *
 * Name   : GAWsock4
 * Author : Gerard Wassink
 * Date   : December 2022
 * Purpose: Resolve hostname to ip-address using TCP/IP sockets
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

#include <stdio.h>          // printf
#include <string.h>         // strcopy
#include <sys/socket.h>
#include <netdb.h>          // histent
#include <arpa/inet.h>


/* ------------------------------------------------------------------------- *
 *                                                     Function declarations
 * ------------------------------------------------------------------------- */
void Initialize();


/* ------------------------------------------------------------------------- *
 *                                                              Main routine
 * ------------------------------------------------------------------------- */
int main(int argc , char *argv[])
{
    
    char *hostname = "wikipedia.org";
    char ip[100];
    struct hostent *he;
    struct in_addr **addr_list;
    int i;
	
    Initialize();
    
									// Try to solve hostname
	if ((he = gethostbyname(hostname)) == NULL) // check result
    {
        herror("gethostbyname");
        return 1;
    }

                                // Cast the h_addr_list to in_addr , 
                                //   since h_addr_list also has the 
                                //     ip address in long format only
    addr_list = (struct in_addr **) he->h_addr_list;
    
    for (i=0; addr_list[i] != NULL; i++)
    {
                                // Return 1st one
        strcpy(ip, inet_ntoa(*addr_list[i]) );
    }
    
    printf("%s resolved to : %s\n" , hostname , ip);
    
	return 0;
}


void Initialize() {
    printf("%s%s\n", "GAWsock1 version ", VERSION);
}


