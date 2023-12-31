#ifndef _EX_ERRORS_H
#define _EX_ERRORS_H

typedef enum 
{
    EX_SUCCESS = 0,

    EX_DRIVER_PWM_TEST = 5,

 
    /*EX_PWM_DRIVER*/
    EX_DRIVER_PWM_MAX_INSTANCES = 9,
    /*EX_PWM_DRIVER*/

    /*EX_KEYPAD*/
    EX_ERROR_KEYPAD_ALREADY_INIT, //10
    EX_ERROR_KEYPAD_NULL_HANDLER,
    EX_ERROR_KEYPAD_CALLBACK_MAX,
    EX_ERROR_KEYPAD_LIGHT_NO_ACTION,
    /*EX_KEYPAD*/

   
    /*EX_OTP*/
    EX_ERROR_OTP_PW_ERROR_NULL, //14
    EX_ERROR_OTP_PW_ERROR_CRC,
    EX_ERROR_OTP_PW_ERROR_PARAMETER_PERMANENT,
    /*EX_OTP*/

    /* dskajfkdsf
    fasfhkahklf
    fdsklafjlkdsf
    */


    /*EX_APP_FINGERPRINT*/
    EX_APP_FINGERPRINT_OK, //17
    EX_APP_FINGERPRINT_HANDSHAKE_OK,
    EX_APP_FINGERPRINT_PACKETRECIEVEERR,
    EX_APP_FINGERPRINT_NOFINGER, //20
    EX_APP_FINGERPRINT_ADDRCODE,
    EX_APP_FINGERPRINT_PASSVERIFY,
    EX_APP_FINGERPRINT_TIMEOUT,  //23      /* returned whenever we time out while reading */
    EX_APP_FINGERPRINT_READ_ERROR,          /* returned whenever we get an unexpected PID or length */
    EX_APP_FINGERPRINT_NOFREEINDEX,         /* returned whenever there's no free ID */
    EX_APP_FINGERPRINT_READ_PARAMS_FAIL,
    EX_APP_FINGERPRINT_REPLY_ADDR,
    EX_APP_FINGERPRINT_REPLY_PACK_TOO_LONG,
    /*EX_APP_FINGERPRINT*/

    /*asfasg
    agfs*/

    /*afsklfgjas*/

    /*EX_OTP*/
    EX_ERROR_OTP_PW_ERROR_DATA_OVERFLOW, //29
    EX_ERROR_OTP_PW_ERROR_NUMBER_DIGITS_MAX,
    EX_ERROR_OTP_PW_ERROR_NUMBER_DIGITS_MIN,
    EX_ERROR_OTP_ERROR_PARAMETER_OTU,
    /*EX_OTP*/


    /*EX_APP_REKEY*/
    EX_ERROR_APP_REKEY_LAST_NOT_FINISHED, //33
    EX_ERROR_APP_REKEY_DATA_INVALID,
    EX_ERROR_APP_REKEY_ANOTHER_REKEY_ON_GOING,
    /*EX_APP_REKEY*/

    /*EX_LOG*/
    EX_ERROR_LOG_CALLBACK_NULL, //36
    /*EX_LOG*/


}ex_errors_t;

#endif /* _EX_ERRORS_H */
