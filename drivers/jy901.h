
#ifndef __JY901_H_
#define __JY901_H_

#include "../user/DataType.h"

#define JY901_UART_DEV "/dev/ttyS2" // JY901 使用的 UART 设备
#define JY901_UART_BAUD 9600        // JY901 UART 波特率

#define JY901_PACKET_LENGTH 11 // JY901 数据包长度

/* JY901 命令,暂不使用*/
#define JY901_CMDS 0
#if JY901_CMDS

#define SAVE 0x00
#define CALSW 0x01
#define RSW 0x02
#define RRATE 0x03
#define BAUD 0x04
#define AXOFFSET 0x05
#define AYOFFSET 0x06
#define AZOFFSET 0x07
#define GXOFFSET 0x08
#define GYOFFSET 0x09
#define GZOFFSET 0x0a
#define HXOFFSET 0x0b
#define HYOFFSET 0x0c
#define HZOFFSET 0x0d
#define D0MODE 0x0e
#define D1MODE 0x0f
#define D2MODE 0x10
#define D3MODE 0x11
#define D0PWMH 0x12
#define D1PWMH 0x13
#define D2PWMH 0x14
#define D3PWMH 0x15
#define D0PWMT 0x16
#define D1PWMT 0x17
#define D2PWMT 0x18
#define D3PWMT 0x19
#define IICADDR 0x1a
#define LEDOFF 0x1b
#define GPSBAUD 0x1c

#define YYMM 0x30
#define DDHH 0x31
#define MMSS 0x32
#define MS 0x33
#define AX 0x34
#define AY 0x35
#define AZ 0x36
#define GX 0x37
#define GY 0x38
#define GZ 0x39
#define HX 0x3a
#define HY 0x3b
#define HZ 0x3c
#define Roll 0x3d
#define Pitch 0x3e
#define Yaw 0x3f
#define TEMP 0x40
#define D0Status 0x41
#define D1Status 0x42
#define D2Status 0x43
#define D3Status 0x44
#define PressureL 0x45
#define PressureH 0x46
#define HeightL 0x47
#define HeightH 0x48
#define LonL 0x49
#define LonH 0x4a
#define LatL 0x4b
#define LatH 0x4c
#define GPSHeight 0x4d
#define GPSYAW 0x4e
#define GPSVL 0x4f
#define GPSVH 0x50
#define q0 0x51
#define q1 0x52
#define q2 0x53
#define q3 0x54

#define DIO_MODE_AIN 0
#define DIO_MODE_DIN 1
#define DIO_MODE_DOH 2
#define DIO_MODE_DOL 3
#define DIO_MODE_DOPWM 4
#define DIO_MODE_GPS 5

#endif /* JY901_CMDS */

struct STime
{
    unsigned char ucYear;
    unsigned char ucMonth;
    unsigned char ucDay;
    unsigned char ucHour;
    unsigned char ucMinute;
    unsigned char ucSecond;
    unsigned short usMiliSecond;
};

struct SAcc
{
    short a[3];
    short T;
};
struct SGyro
{
    short w[3];
    short T;
};
struct SAngle
{
    short angle[3];
    short T;
};
struct SMag
{
    short h[3];
    short T;
};

struct SDStatus
{
    short sDStatus[4];
};

struct SPress
{
    long lPressure;
    long lAltitude;
};

struct SLonLat
{
    long lLon;
    long lLat;
};

struct SGPSV
{
    short sGPSHeight;
    short sGPSYaw;
    long lGPSVelocity;
};
struct SQ
{
    short q[4];
};

typedef struct
{
    struct STime stcTime;
    struct SAcc stcAcc;
    struct SGyro stcGyro;
    struct SAngle stcAngle;
    struct SMag stcMag;
    struct SDStatus stcDStatus;
    struct SPress stcPress;
    struct SLonLat stcLonLat;
    struct SGPSV stcGPSV;
    struct SQ stcQ;

} jy901_raw_t; /* JY901原始数据结构体 */

typedef struct
{
    float x;
    float y;
    float z;
} Vector3f; //3轴向量 float型

typedef struct
{
    short x;
    short y;
    short z;
} Vector3s; //3轴向量 short型 16为短整型

/* --------------------------------------------------------------------------------------------------- */

typedef struct
{
    Vector3f acc;   //加速度
    Vector3f gyro;  //角速度
    Vector3f speed; //速度
    Vector3s mag;   //磁场

    /* 欧拉角 */
    float roll;        //x
    float pitch;       //y
    float yaw;         //z
    float temperature; //JY901温度

} jy901_t; /* JY901解算后数据结构体 */

int jy901Setup(void);

void copeJY901_data(uint8_t data, jy901_t *jy901);

#endif
