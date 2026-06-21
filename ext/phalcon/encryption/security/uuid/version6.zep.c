
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
#include "kernel/time.h"
#include "kernel/memory.h"
#include "kernel/operators.h"
#include "kernel/math.h"
#include "kernel/fcall.h"
#include "kernel/string.h"
#include "kernel/object.h"
#include "kernel/array.h"


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
 * Generates a version 6 (reordered time-based) UUID.
 *
 * Uses the same 60-bit UUID timestamp as version 1 but rearranges the
 * fields so the most-significant time bits come first, producing UUIDs
 * that sort lexicographically in chronological order.
 *
 * @link https://www.rfc-editor.org/rfc/rfc9562
 */
ZEPHIR_INIT_CLASS(Phalcon_Encryption_Security_Uuid_Version6)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Encryption\\Security\\Uuid, Version6, phalcon, encryption_security_uuid_version6, phalcon_encryption_security_uuid_abstractuuid_ce, phalcon_encryption_security_uuid_version6_method_entry, 0);

	zend_class_implements(phalcon_encryption_security_uuid_version6_ce, 1, phalcon_encryption_security_uuid_timebaseduuidinterface_ce);
	return SUCCESS;
}

PHP_METHOD(Phalcon_Encryption_Security_Uuid_Version6, __construct)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS, sec = 0, usec = 0, timestamp = 0;
	zval __$true, nowSec, nowUsec, timeHigh32, timeMid16, timeLow12, clockSeqBytes, clockSeqHiRes, clockSeqLow, nodeStr, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&nowSec);
	ZVAL_UNDEF(&nowUsec);
	ZVAL_UNDEF(&timeHigh32);
	ZVAL_UNDEF(&timeMid16);
	ZVAL_UNDEF(&timeLow12);
	ZVAL_UNDEF(&clockSeqBytes);
	ZVAL_UNDEF(&clockSeqHiRes);
	ZVAL_UNDEF(&clockSeqLow);
	ZVAL_UNDEF(&nodeStr);
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
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	ZEPHIR_INIT_VAR(&nowSec);
	zephir_time(&nowSec);
	sec = zephir_get_numberval(&nowSec);
	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_INIT_VAR(&_1);
	zephir_microtime(&_1, &__$true);
	ZVAL_DOUBLE(&_2, ((zephir_get_numberval(&_1) - zephir_get_doubleval(&nowSec)) * 10000000.0));
	zephir_round(&_0, &_2, NULL, NULL);
	ZEPHIR_INIT_VAR(&nowUsec);
	ZVAL_LONG(&nowUsec, zephir_get_intval(&_0));
	usec = zephir_get_numberval(&nowUsec);
	timestamp = ((((sec + 12219292800)) * 10000000) + usec);
	ZEPHIR_INIT_VAR(&timeHigh32);
	ZVAL_LONG(&timeHigh32, (((timestamp >> 28)) & 0xffffffff));
	ZEPHIR_INIT_VAR(&timeMid16);
	ZVAL_LONG(&timeMid16, (((timestamp >> 12)) & 0xffff));
	ZEPHIR_INIT_VAR(&timeLow12);
	ZVAL_LONG(&timeLow12, (0x6000 | ((timestamp & 0x0fff))));
	ZVAL_LONG(&_3, 2);
	ZEPHIR_CALL_FUNCTION(&clockSeqBytes, "random_bytes", NULL, 319, &_3);
	zephir_check_call_status();
	ZVAL_LONG(&_3, 0);
	ZVAL_LONG(&_4, 1);
	ZEPHIR_INIT_VAR(&_5);
	zephir_substr(&_5, &clockSeqBytes, 0 , 1 , 0);
	ZEPHIR_CALL_FUNCTION(&_6, "ord", NULL, 0, &_5);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&clockSeqHiRes);
	ZVAL_LONG(&clockSeqHiRes, (((int) (zephir_get_numberval(&_6)) & 0x3f) | 0x80));
	ZVAL_LONG(&_7, 1);
	ZVAL_LONG(&_8, 1);
	ZEPHIR_INIT_VAR(&_9);
	zephir_substr(&_9, &clockSeqBytes, 1 , 1 , 0);
	ZEPHIR_CALL_FUNCTION(&clockSeqLow, "ord", NULL, 0, &_9);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_10, this_ptr, "getnodeprovider", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&nodeStr, &_10, "getnode", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_11);
	ZVAL_STRING(&_11, "%08x-%04x-%04x-%02x%02x-%s");
	ZEPHIR_CALL_FUNCTION(&_12, "sprintf", NULL, 139, &_11, &timeHigh32, &timeMid16, &timeLow12, &clockSeqHiRes, &clockSeqLow, &nodeStr);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, ZEND_STRL("uid"), &_12);
	ZEPHIR_MM_RESTORE();
}

/**
 * Returns a DateTimeImmutable built from the UUID's embedded timestamp.
 */
PHP_METHOD(Phalcon_Encryption_Security_Uuid_Version6, getDateTime)
{
	zval parts, hexHigh32, hexMid16, hexLow12, _0, _1, _2, _3, _4, _5;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS, timeHigh32 = 0, timeMid16 = 0, timeLow12 = 0, timestamp = 0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&parts);
	ZVAL_UNDEF(&hexHigh32);
	ZVAL_UNDEF(&hexMid16);
	ZVAL_UNDEF(&hexLow12);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	zephir_read_property(&_0, this_ptr, ZEND_STRL("uid"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&parts);
	zephir_fast_explode_str(&parts, SL("-"), &_0, LONG_MAX);
	zephir_array_fetch_long(&_1, &parts, 0, PH_NOISY | PH_READONLY, "phalcon/Encryption/Security/Uuid/Version6.zep", 69);
	ZEPHIR_CALL_FUNCTION(&hexHigh32, "hexdec", NULL, 0, &_1);
	zephir_check_call_status();
	zephir_array_fetch_long(&_2, &parts, 1, PH_NOISY | PH_READONLY, "phalcon/Encryption/Security/Uuid/Version6.zep", 70);
	ZEPHIR_CALL_FUNCTION(&hexMid16, "hexdec", NULL, 0, &_2);
	zephir_check_call_status();
	zephir_array_fetch_long(&_3, &parts, 2, PH_NOISY | PH_READONLY, "phalcon/Encryption/Security/Uuid/Version6.zep", 71);
	ZEPHIR_CALL_FUNCTION(&_4, "hexdec", NULL, 0, &_3);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&hexLow12);
	ZVAL_LONG(&hexLow12, ((int) (zephir_get_numberval(&_4)) & 0x0fff));
	timeHigh32 = zephir_get_numberval(&hexHigh32);
	timeMid16 = zephir_get_numberval(&hexMid16);
	timeLow12 = zephir_get_numberval(&hexLow12);
	timestamp = ((((timeHigh32 << 28)) | ((timeMid16 << 12))) | timeLow12);
	ZVAL_LONG(&_5, timestamp);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "uuidtimestamptodatetime", NULL, 0, &_5);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Returns the 12-character hex node embedded in the UUID.
 */
PHP_METHOD(Phalcon_Encryption_Security_Uuid_Version6, getNode)
{
	zval _0, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("uid"), PH_NOISY_CC | PH_READONLY);
	ZVAL_LONG(&_1, 24);
	zephir_substr(return_value, &_0, 24 , 0, ZEPHIR_SUBSTR_NO_LENGTH);
	return;
}

