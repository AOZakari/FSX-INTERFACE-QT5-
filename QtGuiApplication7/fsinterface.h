#ifndef FSINTERFACE_H
#define FSINTERFACE_H
#include "Types.h"

// FS offsets
#define HOUR_OFFSET         0x0238
#define MINUTE_OFFSET       0x0239
#define SECONDE_OFFSET      0x023A
#define TAS_OFFSET			0x02B8
#define IAS_OFFSET			0x02BC
#define VS_OFFSET			0x0842
#define LAT_OFFSET			0x0560
#define LON_OFFSET			0x0568
#define ALT_OFFSET			0x0570
#define PITCH_OFFSET		0x0578
#define BANK_OFFSET			0x057C
#define HEAD_OFFSET			0x0580
#define SLEWFLAG_OFFSET		0x05DC
#define ROLLRATE_OFFSET		0x05E4
#define YAWRATE_OFFSET		0x05E6
#define SLEWMODE_OFFSET		0x05F4


// FS data structure types
typedef struct
{
        SInt32 Lo;
        SInt32 Hi;
} SFSVarType;

typedef struct
{
        UInt32 Lo;
        SInt32 Hi;
} UFSVarType;

typedef struct
{
        UChar Hour;
        UChar Minute;
        UChar Seconde;
} FSTimeType;

typedef struct
{
        UFSVarType Lat;
        UFSVarType Lon;
        UFSVarType Alt;
} FSPositionType;

typedef struct
{
        SInt32 Pitch;
        SInt32 Bank;
        UInt32 Heading; // ****** Normalement c'est "non signé"
} FSAttitudeType;


// Function prototypes

// Convert Time from FS to simulation application
void TimeFSToSim(int *Time, FSTimeType *FSTime);

// Convert Time from simulation application to FS
void TimeSimToFS(FSTimeType *FSTime, int *Time);

// Convert position from FS to simulation application
void PositionFSToSim(double *Pos, FSPositionType *FSPos);

// Convert position from simulation application to FS
void PositionSimToFS(FSPositionType *FSPos, double *Pos);

// Convert attitude from FS to simulation application
void AttitudeFSToSim(double *Att, FSAttitudeType FSAtt);

// Convert attitude from simulation application to FS
void AttitudeSimToFS(FSAttitudeType* FSAtt, double *Att);

// Convert airspeed from FS to simulation application
void AirspeedFSToSim(double *Airsp, SInt32 FSAirsp);

// Convert airspeed from simulation application to FS
void AirspeedSimToFS(SInt32 *FSAirsp, double Airsp);

// Convert vertical speed from FS to simulation application
void VertSpeedFSToSim(double *VS, SInt16 FSVS);

// Convert vertical speed from simulation application to FS
void VertSpeedSimToFS(SInt16 *FSVS, double VS);

#endif // FSINTERFACE_H
