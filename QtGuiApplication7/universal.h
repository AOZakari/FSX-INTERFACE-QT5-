#ifndef UNIVERSAL_H
#define UNIVERSAL_H
#define 	PI 					 3.14159265359

#define 	RAD_TO_DEG	 		57.29577951308
#define		DEG_TO_RAD			 0.01745329252

#define		RAD_TO_RPM			 9.54929658551
#define		RPM_TO_RAD			 0.10471975512

#define		FT_TO_M				3.28084

#define		R_EARTH				6371000


// Useful indices

// TIME (HOUR MINUTE SECONDE) indices
enum
{
    HOUR,
    MINUTE,
    SECONDE,
    NCLOCK
};

// LLA (Latitude Longitude Altitude) position indices
enum
{
    LAT,
    LON,
    ALT,
    NPOS
};

// NED (North East Down) direction indices
enum
{
    NORTH,
    EAST,
    DOWN,
    NDIR
};

// 3-D Cartesian coordinates
enum
{
    X,
    Y,
    Z,
    N3D
};

// Rotations
enum
{
    ROLL,
    PITCH,
    YAW,
    NROT
};
#endif // UNIVERSAL_H
