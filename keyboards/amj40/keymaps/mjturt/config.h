/*
 * AMJ40 mjturt config.h
 */

/*
 * USB Device descriptor parameter
 */
#define VENDOR_ID       0xFEED
#define PRODUCT_ID      0x6072
#define DEVICE_VER      0x0002
#define MANUFACTURER    Han Chen
#define PRODUCT         AMJ40
#define DESCRIPTION     qmk port of AMJ40 v2 PCB

/*
 * Features
 */
#define LEADER_TIMEOUT 300
//#define BACKLIGHT_BREATHING
//#define BREATHING_PERIOD 5ä

/* 
 * Custom layout
 */
#define KEYMAP( \
      K000, K001, K002, K003, K004, K005, K006, K007, K008, K009, K010, K011, \
      K100, K101, K102, K103, K104, K105, K106, K107, K108, K109, K110, K111, \
      K200, K201, K202, K203, K204, K205, K206, K207, K208, K209, K210, K211, \
      K300, K301, K302, K303, K304, K305,             K308, K309, K310, K311  \
) { \
      { K000,  K001,  K002,  K003,  K004,  K005,  K006,  K007,  K008,  K009,  K010,  K011 }, \
      { K100,  K101,  K102,  K103,  K104,  K105,  K106,  K107,  K108,  K109,  K110,  K111 }, \
      { K200,  K201,  K202,  K203,  K204,  K205,  K206,  K207,  K208,  K209,  K210,  K211 }, \
      { K300,  K301,  K302,  K303,  K304,  K305,  KC_NO, KC_NO, K308,  K309,  K310,  K311 }  \
}
