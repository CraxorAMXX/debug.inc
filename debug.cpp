#if defined _debug_included
  #endinput
#endif
#define _debug_included

#include <amxxce>

new const DBG_INFO[] = "+++	[ Map: %s ] Debug Log Message [ Current Time: %i:%i:%i ]	+++";

#define DEBUG_FAIL(%1)		( set_fail_state(%1) )

/* if you get this error: "AMX_ERR_STACKERR" change 0 to 1 */
#define DEBUG_INCREASE_MEMORY 0

#if DEBUG_INCREASE_MEMORY > 0
	#pragma dynamic 32768
#endif

/* Write all information with formatex() to add all the data you wanne */
/* The Message will be sended to all players from server and also to the server console, somebdoy should notify the error. */

stock DEBUG_LOG( Message[] )
{
	new szMap[30];	
	get_mapname( szMap, cm(szMap) );

	new iHour, iMinutes, iSeconds;
	time( iHour, iMinutes, iSeconds );

	client_print( 0, print_console, DBG_INFO , szMap, iHour, iMinutes, iSeconds );
	client_print( 0, print_console, Message );

	server_print( DBG_INFO , szMap, iHour, iMinutes, iSeconds );
	server_print( Message );

}
