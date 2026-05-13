
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
#include "kernel/object.h"
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/concat.h"
#include "kernel/string.h"


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
 * Shared base for all UUID version objects.
 */
ZEPHIR_INIT_CLASS(Phalcon_Encryption_Security_Uuid_AbstractUuid)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\Encryption\\Security\\Uuid, AbstractUuid, phalcon, encryption_security_uuid_abstractuuid, phalcon_encryption_security_uuid_abstractuuid_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	/**
	 * Cached SysNodeProvider instance — shared within the request via static.
	 *
	 * @var NodeProviderInterface|null
	 */
	zend_declare_property_null(phalcon_encryption_security_uuid_abstractuuid_ce, SL("nodeProvider"), ZEND_ACC_PROTECTED|ZEND_ACC_STATIC);
	/**
	 * The generated UUID string.
	 *
	 * @var string
	 */
	zend_declare_property_string(phalcon_encryption_security_uuid_abstractuuid_ce, SL("uid"), "", ZEND_ACC_PROTECTED);
	/**
	 * @var string
	 */
	zephir_declare_class_constant_string(phalcon_encryption_security_uuid_abstractuuid_ce, SL("MAX"), "ffffffff-ffff-ffff-ffff-ffffffffffff");

	/**
	 * @var string
	 */
	zephir_declare_class_constant_string(phalcon_encryption_security_uuid_abstractuuid_ce, SL("NIL"), "00000000-0000-0000-0000-000000000000");

	/**
	 * 100-nanosecond intervals between UUID epoch (1582-10-15) and Unix epoch (1970-01-01).
	 *
	 * @var int
	 */
	zephir_declare_class_constant_long(phalcon_encryption_security_uuid_abstractuuid_ce, SL("TIME_OFFSET_INT"), 0x01B21DD213814000);

	zend_class_implements(phalcon_encryption_security_uuid_abstractuuid_ce, 1, phalcon_encryption_security_uuid_uuidinterface_ce);
	return SUCCESS;
}

/**
 * Returns the UUID string.
 */
PHP_METHOD(Phalcon_Encryption_Security_Uuid_AbstractUuid, __toString)
{

	RETURN_MEMBER(getThis(), "uid");
}

/**
 * Returns the UUID string for JSON serialisation.
 */
PHP_METHOD(Phalcon_Encryption_Security_Uuid_AbstractUuid, jsonSerialize)
{

	RETURN_MEMBER(getThis(), "uid");
}

/**
 * Returns the shared SysNodeProvider instance, creating it on first call.
 * The static property means one discovery per request regardless of how
 * many VersionN objects are constructed.
 */
PHP_METHOD(Phalcon_Encryption_Security_Uuid_AbstractUuid, getNodeProvider)
{
	zval _0, _2, _1$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_1$$3);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	zephir_read_static_property_ce(&_0, phalcon_encryption_security_uuid_abstractuuid_ce, SL("nodeProvider"), PH_NOISY_CC | PH_READONLY);
	if (Z_TYPE_P(&_0) == IS_NULL) {
		ZEPHIR_INIT_VAR(&_1$$3);
		object_init_ex(&_1$$3, phalcon_encryption_security_uuid_sysnodeprovider_ce);
		if (zephir_has_constructor(&_1$$3)) {
			ZEPHIR_CALL_METHOD(NULL, &_1$$3, "__construct", NULL, 0);
			zephir_check_call_status();
		}

		zephir_update_static_property_ce(phalcon_encryption_security_uuid_abstractuuid_ce, ZEND_STRL("nodeProvider"), &_1$$3);
	}
	zephir_read_static_property_ce(&_2, phalcon_encryption_security_uuid_abstractuuid_ce, SL("nodeProvider"), PH_NOISY_CC | PH_READONLY);
	RETURN_CTOR(&_2);
}

/**
 * Converts a 60-bit UUID timestamp (100-ns intervals since UUID epoch) to
 * a DateTimeImmutable. Used by Version1 and Version6.
 */
PHP_METHOD(Phalcon_Encryption_Security_Uuid_AbstractUuid, uuidTimestampToDateTime)
{
	zend_class_entry *_3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *timestamp, timestamp_sub, sec, usec, _0, _1, _2, _4, _5, _6;

	ZVAL_UNDEF(&timestamp_sub);
	ZVAL_UNDEF(&sec);
	ZVAL_UNDEF(&usec);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(timestamp)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &timestamp);
	ZVAL_LONG(&_0, 10000000);
	ZEPHIR_CALL_FUNCTION(&_1, "intdiv", NULL, 31, timestamp, &_0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&sec);
	ZVAL_LONG(&sec, (zephir_get_numberval(&_1) - 12219292800));
	ZVAL_DOUBLE(&_0, zephir_safe_mod_zval_long(timestamp, 10000000));
	ZVAL_LONG(&_2, 10);
	ZEPHIR_CALL_FUNCTION(&usec, "intdiv", NULL, 31, &_0, &_2);
	zephir_check_call_status();
	_3 = zephir_fetch_class_str_ex(SL("DateTimeImmutable"), ZEND_FETCH_CLASS_AUTO);
	ZVAL_LONG(&_0, 6);
	ZEPHIR_INIT_VAR(&_4);
	ZVAL_STRING(&_4, "0");
	ZVAL_LONG(&_2, 0);
	ZEPHIR_CALL_FUNCTION(&_5, "str_pad", NULL, 32, &usec, &_0, &_4, &_2);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_6);
	ZEPHIR_CONCAT_VSV(&_6, &sec, " ", &_5);
	ZEPHIR_INIT_NVAR(&_4);
	ZVAL_STRING(&_4, "U u");
	ZEPHIR_RETURN_CALL_CE_STATIC(_3, "createfromformat", NULL, 0, &_4, &_6);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Formats a 32-character hex string as a canonical UUID string.
 */
PHP_METHOD(Phalcon_Encryption_Security_Uuid_AbstractUuid, format)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval hex_zv, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14;
	zend_string *hex = NULL;

	ZVAL_UNDEF(&hex_zv);
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
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(hex)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&hex_zv);
	ZVAL_STR_COPY(&hex_zv, hex);
	ZVAL_LONG(&_0, 0);
	ZVAL_LONG(&_1, 8);
	ZEPHIR_INIT_VAR(&_2);
	zephir_substr(&_2, &hex_zv, 0 , 8 , 0);
	ZVAL_LONG(&_3, 8);
	ZVAL_LONG(&_4, 4);
	ZEPHIR_INIT_VAR(&_5);
	zephir_substr(&_5, &hex_zv, 8 , 4 , 0);
	ZVAL_LONG(&_6, 12);
	ZVAL_LONG(&_7, 4);
	ZEPHIR_INIT_VAR(&_8);
	zephir_substr(&_8, &hex_zv, 12 , 4 , 0);
	ZVAL_LONG(&_9, 16);
	ZVAL_LONG(&_10, 4);
	ZEPHIR_INIT_VAR(&_11);
	zephir_substr(&_11, &hex_zv, 16 , 4 , 0);
	ZVAL_LONG(&_12, 20);
	ZVAL_LONG(&_13, 12);
	ZEPHIR_INIT_VAR(&_14);
	zephir_substr(&_14, &hex_zv, 20 , 12 , 0);
	ZEPHIR_CONCAT_VSVSVSVSV(return_value, &_2, "-", &_5, "-", &_8, "-", &_11, "-", &_14);
	RETURN_MM();
}

/**
 * Converts a canonical UUID string to its 16-byte binary representation.
 */
PHP_METHOD(Phalcon_Encryption_Security_Uuid_AbstractUuid, namespaceToBytes)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval uuid_zv, _0, _1, _2;
	zend_string *uuid = NULL;

	ZVAL_UNDEF(&uuid_zv);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(uuid)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&uuid_zv);
	ZVAL_STR_COPY(&uuid_zv, uuid);
	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "-");
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "");
	zephir_fast_str_replace(&_0, &_1, &_2, &uuid_zv);
	ZEPHIR_RETURN_CALL_FUNCTION("hex2bin", NULL, 33, &_0);
	zephir_check_call_status();
	RETURN_MM();
}

