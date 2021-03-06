#include <sys/times.h>
#include <limits.h>

#include <cmath>

#include <iostream>

using std::cout;
using std::endl;

#include "TTimer.hh"


double
TTimer::system_time ()
{
    double  sec, usec;
    
    switch ( _type )
    {
    case REAL_TIME :
	gettimeofday( & _timeval_data, NULL );

	sec  = _timeval_data.tv_sec;
	usec = _timeval_data.tv_usec;

	break;

    case CPU_TIME :

	getrusage( RUSAGE_SELF, & _rusage_data );
	sec  = _rusage_data.ru_utime.tv_sec  + _rusage_data.ru_stime.tv_sec;
	usec = _rusage_data.ru_utime.tv_usec + _rusage_data.ru_stime.tv_usec;
	break;

    case USER_TIME :
	
	getrusage( RUSAGE_SELF, & _rusage_data );
	sec  = _rusage_data.ru_utime.tv_sec;
	usec = _rusage_data.ru_utime.tv_usec;
	break;
                
    case SYSTEM_TIME :

	getrusage( RUSAGE_SELF, & _rusage_data );
	sec  = _rusage_data.ru_stime.tv_sec;
	usec = _rusage_data.ru_stime.tv_usec;

	break;

    default :
	cout << "TTimer::system_time : unsupported type of time" << std::endl;
	sec = usec = 0.0;
    }

    return sec + (usec * 1e-6);
}


std::ostream & 
operator << ( std::ostream & os, const TTimer & timer )
{
    double  time;
    long    seconds, mseconds;

    time     = 0 > timer.diff() ? 0 : timer.diff();
    seconds  = long( floor( time ) );
    mseconds = long(floor( (time - double(seconds)) * 1000.0 + 0.5 ));
        
    os << seconds << ',';
    
    if (mseconds < 10)        os << "00";
    else if (mseconds < 100)  os << "0";

    os << mseconds << "s";

    return os;
}
