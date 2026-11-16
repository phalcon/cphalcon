
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
#include "kernel/concat.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/string.h"
#include "kernel/operators.h"
#include "kernel/object.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 *
 * Implementation of this file has been influenced by sinbadxiii/cphalcon-uuid
 * @link    https://github.com/sinbadxiii/cphalcon-uuid
 */
/**
 * Generates a version 3 (name-based MD5) UUID.
 *
 * Given a namespace UUID and a name string, produces a deterministic UUID
 * by hashing namespace bytes + name with MD5, then stamping version/variant.
 *
 * @link https://www.ietf.org/rfc/rfc4122.txt
 */
ZEPHIR_INIT_CLASS(Phalcon_Encryption_Security_Uuid_Version3)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Encryption\\Security\\Uuid, Version3, phalcon, encryption_security_uuid_version3, phalcon_encryption_security_uuid_abstractuuid_ce, phalcon_encryption_security_uuid_version3_method_entry, 0);

	return SUCCESS;
}

PHP_METHOD(Phalcon_Encryption_Security_Uuid_Version3, __construct)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_6 = NULL, *_10 = NULL, *_14 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval namespaceName_zv, name_zv, __$true, hash, _0, _1, _2, _3, _4, _5, _7, _8, _9, _11, _12, _13, _15, _16, _17, _18, _19, _20;
	zend_string *namespaceName = NULL, *name = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&namespaceName_zv);
	ZVAL_UNDEF(&name_zv);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&hash);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_11);
	ZVAL_UNDEF(&_12);
	ZVAL_UNDEF(&_13);
	ZVAL_UNDEF(&_15);
	ZVAL_UNDEF(&_16);
	ZVAL_UNDEF(&_17);
	ZVAL_UNDEF(&_18);
	ZVAL_UNDEF(&_19);
	ZVAL_UNDEF(&_20);
	ZEND_TLS zephir_method_cache _zephir_call_cache[2];
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("uid", 3, 1);
	}

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR(namespaceName)
		Z_PARAM_STR(name)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&namespaceName_zv);
	ZVAL_STR_COPY(&namespaceName_zv, namespaceName);
	zephir_memory_observe(&name_zv);
	ZVAL_STR_COPY(&name_zv, name);
	ZEPHIR_CALL_METHOD_CACHED(&_0, this_ptr, "namespaceToBytes", &_zephir_call_cache[0], &namespaceName_zv);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_1);
	ZEPHIR_CONCAT_VV(&_1, &_0, &name_zv);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CALL_FUNCTION(&hash, "md5", NULL, 144, &_1, &__$true);
	zephir_check_call_status();
	ZVAL_LONG(&_2, 6);
	ZVAL_LONG(&_3, 1);
	ZEPHIR_INIT_VAR(&_4);
	zephir_substr(&_4, &hash, 6 , 1 , 0);
	ZEPHIR_CALL_FUNCTION(&_5, "ord", &_6, 133, &_4);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_7);
	ZVAL_LONG(&_7, 0x0f);
	ZEPHIR_INIT_VAR(&_8);
	zephir_bitwise_and_function(&_8, &_5, &_7);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_NVAR(&_7);
	ZVAL_LONG(&_7, 0x30);
	ZEPHIR_INIT_VAR(&_9);
	zephir_bitwise_or_function(&_9, &_8, &_7);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CALL_FUNCTION(&_5, "chr", &_10, 121, &_9);
	zephir_check_call_status();
	ZVAL_LONG(&_11, 6);
	ZVAL_LONG(&_12, 1);
	ZEPHIR_CALL_FUNCTION(&_13, "substr_replace", &_14, 145, &hash, &_5, &_11, &_12);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(&hash, &_13);
	ZVAL_LONG(&_11, 8);
	ZVAL_LONG(&_12, 1);
	ZEPHIR_INIT_VAR(&_15);
	zephir_substr(&_15, &hash, 8 , 1 , 0);
	ZEPHIR_CALL_FUNCTION(&_13, "ord", &_6, 133, &_15);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_7);
	ZVAL_LONG(&_7, 0x3f);
	ZEPHIR_INIT_NVAR(&_8);
	zephir_bitwise_and_function(&_8, &_13, &_7);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_NVAR(&_7);
	ZVAL_LONG(&_7, 0x80);
	ZEPHIR_INIT_VAR(&_16);
	zephir_bitwise_or_function(&_16, &_8, &_7);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CALL_FUNCTION(&_13, "chr", &_10, 121, &_16);
	zephir_check_call_status();
	ZVAL_LONG(&_17, 8);
	ZVAL_LONG(&_18, 1);
	ZEPHIR_CALL_FUNCTION(&_19, "substr_replace", &_14, 145, &hash, &_13, &_17, &_18);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(&hash, &_19);
	ZEPHIR_CALL_FUNCTION(&_20, "bin2hex", NULL, 69, &hash);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD_CACHED(&_19, this_ptr, "format", &_zephir_call_cache[1], &_20);
	zephir_check_call_status();
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 741, &_19);
	ZEPHIR_MM_RESTORE();
}

