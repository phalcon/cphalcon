
#ifdef HAVE_CONFIG_H
#include "../../../../ext_config.h"
#endif

#include <php.h>
#include "../../../../php_ext.h"
#include "../../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "kernel/time.h"
#include "kernel/fcall.h"
#include "kernel/string.h"
#include "kernel/object.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 *
 * Implementation of this file has been influenced by sinbadxiii/cphalcon-uuid
 * @link    https://github.com/sinbadxiii/cphalcon-uuid
 */
/**
 * Generates a version 7 (Unix timestamp) UUID per RFC 9562.
 *
 * Layout (128 bits):
 *   unix_ts_ms (48) | ver=7 (4) | rand_a (12) | var=10 (2) | rand_b (62)
 *
 * @link https://www.rfc-editor.org/rfc/rfc9562
 */
ZEPHIR_INIT_CLASS(Phalcon_Encryption_Security_Uuid_Version7)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Encryption\\Security\\Uuid, Version7, phalcon, encryption_security_uuid_version7, phalcon_encryption_security_uuid_abstractuuid_ce, phalcon_encryption_security_uuid_version7_method_entry, 0);

	return SUCCESS;
}

PHP_METHOD(Phalcon_Encryption_Security_Uuid_Version7, __construct)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS, msInt = 0;
	zval __$true, ms, timeHigh32, timeLow16, verRandA, varRandB, randBytes, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&ms);
	ZVAL_UNDEF(&timeHigh32);
	ZVAL_UNDEF(&timeLow16);
	ZVAL_UNDEF(&verRandA);
	ZVAL_UNDEF(&varRandB);
	ZVAL_UNDEF(&randBytes);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_11);
	ZVAL_UNDEF(&_12);
	ZVAL_UNDEF(&_13);
	ZVAL_UNDEF(&_14);
	ZVAL_UNDEF(&_15);
	ZVAL_UNDEF(&_16);
	ZVAL_UNDEF(&_17);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	ZEPHIR_INIT_VAR(&_0);
	zephir_microtime(&_0, &__$true);
	ZVAL_LONG(&_1, (zephir_get_numberval(&_0) * 1000));
	ZEPHIR_INIT_VAR(&ms);
	ZVAL_LONG(&ms, zephir_get_intval(&_1));
	msInt = zephir_get_numberval(&ms);
	ZEPHIR_INIT_VAR(&timeHigh32);
	ZVAL_LONG(&timeHigh32, (((msInt >> 16)) & 0xffffffff));
	ZEPHIR_INIT_VAR(&timeLow16);
	ZVAL_LONG(&timeLow16, (msInt & 0xffff));
	ZVAL_LONG(&_2, 10);
	ZEPHIR_CALL_FUNCTION(&randBytes, "random_bytes", NULL, 319, &_2);
	zephir_check_call_status();
	ZVAL_LONG(&_2, 0);
	ZVAL_LONG(&_3, 2);
	ZEPHIR_INIT_VAR(&_4);
	zephir_substr(&_4, &randBytes, 0 , 2 , 0);
	ZEPHIR_CALL_FUNCTION(&_5, "bin2hex", NULL, 320, &_4);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&_6, "hexdec", NULL, 0, &_5);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&verRandA);
	ZVAL_LONG(&verRandA, (0x7000 | ((int) (zephir_get_numberval(&_6)) & 0x0fff)));
	ZVAL_LONG(&_7, 2);
	ZVAL_LONG(&_8, 2);
	ZEPHIR_INIT_VAR(&_9);
	zephir_substr(&_9, &randBytes, 2 , 2 , 0);
	ZEPHIR_CALL_FUNCTION(&_10, "bin2hex", NULL, 320, &_9);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&_11, "hexdec", NULL, 0, &_10);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&varRandB);
	ZVAL_LONG(&varRandB, (0x8000 | ((int) (zephir_get_numberval(&_11)) & 0x3fff)));
	ZVAL_LONG(&_12, 4);
	ZVAL_LONG(&_13, 6);
	ZEPHIR_INIT_VAR(&_14);
	zephir_substr(&_14, &randBytes, 4 , 6 , 0);
	ZEPHIR_CALL_FUNCTION(&_15, "bin2hex", NULL, 320, &_14);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_16);
	ZVAL_STRING(&_16, "%08x-%04x-%04x-%04x-%s");
	ZEPHIR_CALL_FUNCTION(&_17, "sprintf", NULL, 139, &_16, &timeHigh32, &timeLow16, &verRandA, &varRandB, &_15);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, ZEND_STRL("uid"), &_17);
	ZEPHIR_MM_RESTORE();
}

