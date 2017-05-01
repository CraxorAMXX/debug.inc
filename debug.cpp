#if defined _debug_included
  #endinput
#endif
#define _debug_included

#include <amxxce>

new const DBG_INFO[] = "| === |		Debug Log Called here		| === |";

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
	new szMap[22];	
	get_mapname( szMap, cm(szMap) );

	new iTimeleft = get_timeleft() / 60;

	new iHour, iMinutes, iSeconds;
	time( iHour, iMinutes, iSeconds );

	new Year, Month, Day;
	date( Year, Month, Day );

	client_print( 0, print_console, DBG_INFO );
	client_print( 0, print_console, "[Map: %s] [Timeleft: %iminutes] [Time: %i:%i:%i] [ Date: %i.%i.%i ]", szMap, iTimeleft, iHour, iMinutes, iSeconds, Year, Month, Day );
	client_print( 0, print_console, Message );

	server_print( DBG_INFO );
	server_print( "[Map: %s] [Timeleft: %iminutes] [Time: %i:%i:%i] [ Date: %i.%i.%i ]", szMap, iTimeleft, iHour, iMinutes, iSeconds, Year, Month, Day );
	server_print( Message );
