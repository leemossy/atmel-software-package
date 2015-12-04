/* ----------------------------------------------------------------------------
 *         SAM Software Package License
 * ----------------------------------------------------------------------------
 * Copyright (c) 2015, Atmel Corporation
 *
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * - Redistributions of source code must retain the above copyright notice,
 * this list of conditions and the disclaimer below.
 *
 * Atmel's name may not be used to endorse or promote products derived from
 * this software without specific prior written permission.
 *
 * DISCLAIMER: THIS SOFTWARE IS PROVIDED BY ATMEL "AS IS" AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT ARE
 * DISCLAIMED. IN NO EVENT SHALL ATMEL BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA,
 * OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * ----------------------------------------------------------------------------
 */

/** \file
 *
 *  Definitions and classes for USB Audio class requests.
 *
 *  - For a USB %device:
 *     -# After receiving an Audio request from the host, use
 *        aud_generic_request_get_entity to determine the target Unit or Terminal.
 *     -# After receiving an Audio request from the host, use
 *        aud_generic_request_get_interface to know which interface is referenced.
 *     -# Use aud_feature_unit_request_get_control to determine which control
 *        shall be tweaked following a host request.
 *     -# Use aud_feature_unit_request_get_channel to identify the channel which
 *        will have its control altered.
 */

#ifndef _AUDREQUESTS_H_
#define _AUDREQUESTS_H_
/** \addtogroup usb_audio
 *@{
 */

/*----------------------------------------------------------------------------
 *         Includes
 *----------------------------------------------------------------------------*/

#include <usb_requests.h>

/*----------------------------------------------------------------------------
 *         Definitions
 *----------------------------------------------------------------------------*/

/** \addtogroup usb_audio_request USB Audio request codes
 *      @{
 * This section lists the codes of the existing Audio requests.
 * - \ref AUDGenericRequest_SETCUR
 * - \ref AUDGenericRequest_GETCUR
 */
/** SET_CUR request code.*/
#define AUDGenericRequest_SETCUR                0x01
/** GET_CUR request code.*/
#define AUDGenericRequest_GETCUR                0x81
/** GET_MIN request code.*/
#define AUDGenericRequest_GETMIN                0x82
/** GET_MAX request code.*/
#define AUDGenericRequest_GETMAX                0x83
/** GET_RES request code.*/
#define AUDGenericRequest_GETRES                0x84
/**     @}*/

/** \addtogroup usb_audio_ctrl_sel USB Audio Control selector values
 *      @{
 * This section lists the available control selectors for a Feature Unit request.
 * - \ref AUDFeatureUnitRequest_MUTE
 */
/** Mute control selector (MUTE_CONTROL). */
#define AUDFeatureUnitRequest_MUTE              0x01
/** Volume control selector (VOLUME_CONTROL). */
#define AUDFeatureUnitRequest_VOLUME            0x02
/**     @}*/

/*----------------------------------------------------------------------------
 *         Types
 *----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------
 *         Functions
 *----------------------------------------------------------------------------*/

extern uint8_t aud_generic_request_get_entity(
	const USBGenericRequest *request);

extern uint8_t aud_generic_request_get_interface(
	const USBGenericRequest *request);


extern uint8_t aud_feature_unit_request_get_control(
	const USBGenericRequest *request);

extern uint8_t aud_feature_unit_request_get_channel(
	const USBGenericRequest *request);

/**@}*/
#endif /* _AUDREQUESTS_H_ */