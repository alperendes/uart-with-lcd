#define LCD_PORT P2OUT      /* LCD PORT */
#define CLOCK_PIN BIT0      /* 74LS595 CLOCK PORT */
#define DATAIO_PIN BIT1     /* 74LS595 DATA PORT */
#define ENABLE_PIN BIT2     /* 74LS595 ENABLE PORT */


/* COMMAND LIST */
#define ERASE 1             /* CLEANS SCREEN */
#define RETURN 2            /* CURSOR TO THE TOP LEFT CORNER */
#define WRITELEFT 4         /* CURSOR ADDRESS DECREMENTS */
#define WRITERIGHT 6        /* CURSOR ADDRESS INCREMENTS */
#define HIDE 12             /* HIDE CURSOR */
#define BELOW 14            /* BLINKING CURSOR */
#define SIDE 15             /* BLINKING ALL CURSOR */
#define BACK 16             /* CURSOR SHIFTS BACK */
#define SHIFTRIGHT 24       /* SHIFT CURSOR TO RIGHT */
#define SHIFTLEFT 28        /* SHIFT CURSOR TO LEFT */
#define CLOSESCREEN 8       /* CLOSE CURSOR */
#define FIRSTROW 128        /* FIRST ROW ADDRESS (DRAM) */
#define SECONDROW 192       /* SECOND ROW ADDRESS (DRAM) */
#define GENERATE 64         /* CHARACTER GENERATOR ADDRESS (CGRAM) */

/* FUNCTION LIST */
#define TWOROW8BIT 56
#define ONEROW8BIT 48
#define TWOROW4BIT 40
#define ONEROW4BIT 32
extern void three_wire_control(unsigned char temp);
extern void send_data(unsigned char);
extern void clearlcd(void);
extern void write(const char * s);
extern void gotoxy(unsigned char x, unsigned char y);
extern void initialize(void);
extern void enable(void);
extern void command(unsigned char c);
