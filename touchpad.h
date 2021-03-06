#ifndef TOUCHPAD_H
#define TOUCHPAD_H

#include "ch.h"
#include "hal.h"
#include "glcd.h"
#include "ads7843_lld.h"
#include "xpt2046_lld.h"

#define CONVERSIONS 3

#define SET_CS(a)		(TP_PORT->BSRR = 1 << (TP_CS + (a ? 0 : 16)))

struct cal {
	float xm;
	float ym;
	float xn;
	float yn;
};

#ifdef __cplusplus
extern "C" {
#endif


/*
 * Description: initializes touchpad (SPI)
 *
 * param: SPI driver
 *
 * return: none
 */
void tpInit(SPIDriver *spip);

/*
 * Description: reads out PEN_IRQ from touchpad controller
 *
 * param: none
 *
 * return: 1 = touchpad pressed / 0 = touchpad not pressed
 */
uint8_t tpIRQ(void);

/*
 * Description: reads-out X coordinate, calibrated
 *
 * param: none
 *
 * return: X coordinate, relative to screen zero-point
 */
uint16_t tpReadX(void);

/*
 * Description: reads-out Y coordinate, calibrated
 *
 * param: none
 *
 * return: Y coordinate, relative to screen zero-point
 */
uint16_t tpReadY(void);

/*
 * Description: reads-out Z value / pressure
 *				only available when controller supports, returns
 *				zero otherwise.
 *
 * param:		none
 *
 * return:		pressure on the touchpad
 */
uint16_t tpReadZ(void);

/*
 * Description: calibration routine
 *
 * param: none
 *
 * return: none
 */
void tpCalibrate(void);

#ifdef __cplusplus
}
#endif

#endif

