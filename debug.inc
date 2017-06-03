/*
*
*		Craxor AlliedMods 2017.
*
*
*			This idea is copyed from adebug.io of emp' wich is an sourcemod inc file.
*
*			Use this debug system to solve problems or extract data to learn more.
*
*			Here if you want to learn about debugging: https://en.wikipedia.org/wiki/Debugging
*			Here is the official thread of debug.inc: https://forums.alliedmods.net/showthread.php?t=297725
*			AMX MOD X official website: www.amxmodx.org/
*
*
*/

#if defined _debug_included
  #endinput
#endif
#define _debug_included


/*
*
*
*
*	DEBUG_OFF is closing automatcly the debug system if the value is set to '1'.
*
*	If you leave '1' all the functions will be empty functions, so, you can leave the functiosns in the plugin and re-compile, they won't be called.	
*
*
*	
*/

#define DEBUG_OFF 0

/*
*
*
*
*
*	szDebugFileLocation is the location where the debug messages will be writed(wich file).
*
*
*/
static stock const szDebugFileLocation [] = "addons/amxmodx/data/Debugs.txt";


/*
*
*
*
*
*
*
*	here we check if DEBUG_OFF is bigger than 0 and defining all the functions as empty functions.
*	In that way you can re-compile the plugin and leave the functions, they will be empty functions so they won't eat memory.
*
*
*
*
*
*/

#if DEBUG_OFF > 0

	#define debug_log(%1)			debug_null()
	debug_null(){}				/* Empty function */

#else

/*
*
*
*
*	Log an debug message, the message will be printed in all players chat/console, on the server consone and writed in the Debugs.txt
*
*	@iDebugLevel: is the level of debugging from 0 to 5 for debug_log() function.
*
*		0 - print a simple message to all players console from server.
*		1 - print a message to server console and to all players console from server.
*		2 - same as 1 plus printing a message in the Debugs.txt
*		3 - Same as 2 but all the third messages are formated with get_systime() function
*		4 - same as 3 but also with the get_mapname() format.
*		5 - Same at 4 but with Players Count format.
*
*
*
*	@szMessage[] - the message to send
*	@any - any parameter to format Message[]
*
*
*
*
*
*/
stock debug_log( iDebugLevel=0, const szMessage[] , any:... )
{
	static Frm[128];
	vformat( Frm, charsmax(Frm), szMessage, 3 );
	
	switch( iDebugLevel )
	{
		case 1:
		{
			server_print( "[DEBUG] %s", Frm );
			client_print( 0, print_console, "[DEBUG] %s", Frm );
		}
		case 2:
		{
			server_print( "[DEBUG] %s", Frm );
			client_print( 0, print_console, "[DEBUG] %s", Frm );

			new buff[120]; formatex( buff, charsmax(buff), "[DEBUG] %s", Frm );
			write_file( szDebugFileLocation, buff );
		}

		case 3:
		{
			server_print( "[DEBUG, SysTime: %i] %s", get_systime(), Frm );
			client_print( 0, print_console, "[DEBUG, SysTime: %i] %s", get_systime(), Frm );

			new buff[120]; formatex( buff, charsmax(buff), "[DEBUG, SysTime: %i] %s", get_systime(), Frm );
			write_file( szDebugFileLocation, buff );
		}
		case 4:
		{
			new szMap[32];
			get_mapname( szMap, charsmax(szMap) );

			server_print( "[DEBUG, SysTime: %i, Map: %s] %s", get_systime(), szMap, Frm );
			client_print( 0, print_console, "[DEBUG, SysTime: %i, Map: %s] %s", get_systime(), szMap, Frm );			

			new buff[120]; formatex( buff, charsmax(buff), "[DEBUG, SysTime: %i, Map: %s] %s", get_systime(), szMap, Frm );
			write_file( szDebugFileLocation, buff );

		}

		case 5:
		{
			new szMap[32];
			get_mapname( szMap, charsmax(szMap) );
			
			new Players[32], Num;
			get_players( Players, Num );

			server_print( "[DEBUG, SysTime: %i, Map: %s, Players: %i] %s", get_systime(), szMap, Num, Frm );
			client_print( 0, print_console, "[DEBUG, SysTime: %i, Map: %s, Players: %i] %s", get_systime(), szMap, Num, Frm );


			new buff[120]; formatex( buff, charsmax(buff), "[DEBUG, SysTime: %i, Map: %s, Players: %i] %s", get_systime(), szMap, Num, Frm );
			write_file( szDebugFileLocation, buff );
		}

		default:
		{
			client_print( 0, print_console, Frm );	
		}
	}
}

#endif
