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
#include <string.h>         // strcpy
#include <sys/socket.h>
#include <netdb.h>          // hostent
#include <arpa/inet.h>


/* ------------------------------------------------------------------------- *
 *                                                              Main routine
 * ------------------------------------------------------------------------- */
int main(int argc , char *argv[])
{
    
    char hostname[200];
    char ip[100];
    struct hostent *he;
    struct in_addr **addr_list;
    int i;

									// Tell'em who we are
    printf("%s%s\n", "GAWsock1 version ", VERSION);
    
	if (argc < 2)					// Check # args
	{
		puts("no URL given");
		return 1;
	}
	
	strcpy(hostname, argv[1]);		// Get hostname
	
									// Try to solve hostname
									//   and check result
	if ((he = gethostbyname(hostname)) == NULL)
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
    
									// Give back result
    printf("%s resolved to : %s\n" , hostname , ip);
    
	return 0;
}



