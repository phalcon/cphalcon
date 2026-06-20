
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
#include "kernel/fcall.h"
#include "kernel/memory.h"
#include "kernel/time.h"
#include "kernel/math.h"
#include "kernel/string.h"
#include "kernel/object.h"
#include "ext/date/php_date.h"
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
 * Generates a version 1 (time-based) UUID.
 *
 * The timestamp is the number of 100-nanosecond intervals since
 * October 15, 1582 00:00:00.00 UTC (the UUID epoch). The node is resolved
 * via SysNodeProvider (hardware MAC, APCu-cached) with RandomNodeProvider
 * as fallback.
 *
 * @link https://www.ietf.org/rfc/rfc4122.txt
 */
ZEPHIR_INIT_CLASS(Phalcon_Encryption_Security_Uuid_Version1)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Encryption\\Security\\Uuid, Version1, phalcon, encryption_security_uuid_version1, phalcon_encryption_security_uuid_abstractuuid_ce, phalcon_encryption_security_uuid_version1_method_entry, 0);

	zend_class_implements(phalcon_encryption_security_uuid_version1_ce, 1, phalcon_encryption_security_uuid_timebaseduuidinterface_ce);
	return SUCCESS;
}

PHP_METHOD(Phalcon_Encryption_Security_Uuid_Version1, __construct)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS, sec = 0, usec = 0, timestamp = 0;
	zval *dateTime = NULL, dateTime_sub, *node = NULL, node_sub, __$true, __$null, nowSec, nowUsec, dateTimestamp, dateUsec, timeLow, timeMid, timeHi, clockSeqBytes, clockSeqHiRes, clockSeqLow, nodeStr, _5, _6, _7, _8, _9, _10, _11, _13, _14, _0$$3, _1$$3, _2$$4, _3$$4, _4$$4, _12$$6;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&dateTime_sub);
	ZVAL_UNDEF(&node_sub);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&nowSec);
	ZVAL_UNDEF(&nowUsec);
	ZVAL_UNDEF(&dateTimestamp);
	ZVAL_UNDEF(&dateUsec);
	ZVAL_UNDEF(&timeLow);
	ZVAL_UNDEF(&timeMid);
	ZVAL_UNDEF(&timeHi);
	ZVAL_UNDEF(&clockSeqBytes);
	ZVAL_UNDEF(&clockSeqHiRes);
	ZVAL_UNDEF(&clockSeqLow);
	ZVAL_UNDEF(&nodeStr);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_11);
	ZVAL_UNDEF(&_13);
	ZVAL_UNDEF(&_14);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_12$$6);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 2)
		Z_PARAM_OPTIONAL
		Z_PARAM_OBJECT_OF_CLASS_OR_NULL(dateTime, php_date_get_interface_ce())
		Z_PARAM_ZVAL_OR_NULL(node)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 0, 2, &dateTime, &node);
	if (!dateTime) {
		dateTime = &dateTime_sub;
		dateTime = &__$null;
	}
	if (!node) {
		node = &node_sub;
		node = &__$null;
	}
	if (Z_TYPE_P(dateTime) != IS_NULL) {
		ZEPHIR_CALL_METHOD(&dateTimestamp, dateTime, "gettimestamp", NULL, 0);
		zephir_check_call_status();
		sec = zephir_get_numberval(&dateTimestamp);
		ZEPHIR_INIT_VAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "u");
		ZEPHIR_CALL_METHOD(&_0$$3, dateTime, "format", NULL, 0, &_1$$3);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&dateUsec);
		ZVAL_LONG(&dateUsec, (zephir_get_intval(&_0$$3) * 10));
		usec = zephir_get_numberval(&dateUsec);
	} else {
		ZEPHIR_INIT_VAR(&nowSec);
		zephir_time(&nowSec);
		sec = zephir_get_numberval(&nowSec);
		ZEPHIR_INIT_VAR(&_2$$4);
		ZEPHIR_INIT_VAR(&_3$$4);
		zephir_microtime(&_3$$4, &__$true);
		ZVAL_DOUBLE(&_4$$4, ((zephir_get_numberval(&_3$$4) - zephir_get_doubleval(&nowSec)) * 10000000.0));
		zephir_round(&_2$$4, &_4$$4, NULL, NULL);
		ZEPHIR_INIT_VAR(&nowUsec);
		ZVAL_LONG(&nowUsec, zephir_get_intval(&_2$$4));
		usec = zephir_get_numberval(&nowUsec);
	}
	timestamp = ((((sec + 12219292800)) * 10000000) + usec);
	ZEPHIR_INIT_VAR(&timeLow);
	ZVAL_LONG(&timeLow, (timestamp & 0xffffffff));
	ZEPHIR_INIT_VAR(&timeMid);
	ZVAL_LONG(&timeMid, (((timestamp >> 32)) & 0xffff));
	ZEPHIR_INIT_VAR(&timeHi);
	ZVAL_LONG(&timeHi, (((((timestamp >> 48)) & 0x0fff)) | 0x1000));
	ZVAL_LONG(&_5, 2);
	ZEPHIR_CALL_FUNCTION(&clockSeqBytes, "random_bytes", NULL, 310, &_5);
	zephir_check_call_status();
	ZVAL_LONG(&_5, 0);
	ZVAL_LONG(&_6, 1);
	ZEPHIR_INIT_VAR(&_7);
	zephir_substr(&_7, &clockSeqBytes, 0 , 1 , 0);
	ZEPHIR_CALL_FUNCTION(&_8, "ord", NULL, 0, &_7);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&clockSeqHiRes);
	ZVAL_LONG(&clockSeqHiRes, (((int) (zephir_get_numberval(&_8)) & 0x3f) | 0x80));
	ZVAL_LONG(&_9, 1);
	ZVAL_LONG(&_10, 1);
	ZEPHIR_INIT_VAR(&_11);
	zephir_substr(&_11, &clockSeqBytes, 1 , 1 , 0);
	ZEPHIR_CALL_FUNCTION(&clockSeqLow, "ord", NULL, 0, &_11);
	zephir_check_call_status();
	if (Z_TYPE_P(node) != IS_NULL) {
		ZEPHIR_CPY_WRT(&nodeStr, node);
	} else {
		ZEPHIR_CALL_METHOD(&_12$$6, this_ptr, "getnodeprovider", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&nodeStr, &_12$$6, "getnode", NULL, 0);
		zephir_check_call_status();
	}
	ZEPHIR_INIT_VAR(&_13);
	ZVAL_STRING(&_13, "%08x-%04x-%04x-%02x%02x-%s");
	ZEPHIR_CALL_FUNCTION(&_14, "sprintf", NULL, 132, &_13, &timeLow, &timeMid, &timeHi, &clockSeqHiRes, &clockSeqLow, &nodeStr);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, ZEND_STRL("uid"), &_14);
	ZEPHIR_MM_RESTORE();
}

/**
 * Returns a DateTimeImmutable built from the UUID's embedded timestamp.
 */
PHP_METHOD(Phalcon_Encryption_Security_Uuid_Version1, getDateTime)
{
	zval parts, hexTimeLow, hexTimeMid, hexTimeHi, _0, _1, _2, _3, _4, _5;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS, timeLow = 0, timeMid = 0, timeHi = 0, timestamp = 0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&parts);
	ZVAL_UNDEF(&hexTimeLow);
	ZVAL_UNDEF(&hexTimeMid);
	ZVAL_UNDEF(&hexTimeHi);
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
	zephir_array_fetch_long(&_1, &parts, 0, PH_NOISY | PH_READONLY, "phalcon/Encryption/Security/Uuid/Version1.zep", 81);
	ZEPHIR_CALL_FUNCTION(&hexTimeLow, "hexdec", NULL, 0, &_1);
	zephir_check_call_status();
	zephir_array_fetch_long(&_2, &parts, 1, PH_NOISY | PH_READONLY, "phalcon/Encryption/Security/Uuid/Version1.zep", 82);
	ZEPHIR_CALL_FUNCTION(&hexTimeMid, "hexdec", NULL, 0, &_2);
	zephir_check_call_status();
	zephir_array_fetch_long(&_3, &parts, 2, PH_NOISY | PH_READONLY, "phalcon/Encryption/Security/Uuid/Version1.zep", 83);
	ZEPHIR_CALL_FUNCTION(&_4, "hexdec", NULL, 0, &_3);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&hexTimeHi);
	ZVAL_LONG(&hexTimeHi, ((int) (zephir_get_numberval(&_4)) & 0x0fff));
	timeLow = zephir_get_numberval(&hexTimeLow);
	timeMid = zephir_get_numberval(&hexTimeMid);
	timeHi = zephir_get_numberval(&hexTimeHi);
	timestamp = ((((timeHi << 48)) | ((timeMid << 32))) | timeLow);
	ZVAL_LONG(&_5, timestamp);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "uuidtimestamptodatetime", NULL, 0, &_5);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Returns the 12-character hex node embedded in the UUID.
 */
PHP_METHOD(Phalcon_Encryption_Security_Uuid_Version1, getNode)
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

