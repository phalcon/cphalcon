
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
 * For the full copyright and license information, please view the LICENSE.txt
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
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval namespaceName_zv, name_zv, __$true, hash, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15;
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
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR(namespaceName)
		Z_PARAM_STR(name)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	ZVAL_STR_COPY(&namespaceName_zv, namespaceName);
	ZVAL_STR_COPY(&name_zv, name);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "namespacetobytes", NULL, 0, &namespaceName_zv);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_1);
	ZEPHIR_CONCAT_VV(&_1, &_0, &name_zv);
	ZEPHIR_CALL_FUNCTION(&hash, "md5", NULL, 291, &_1, &__$true);
	zephir_check_call_status();
	ZVAL_LONG(&_2, 6);
	ZVAL_LONG(&_3, 1);
	ZEPHIR_INIT_VAR(&_4);
	zephir_substr(&_4, &hash, 6 , 1 , 0);
	ZEPHIR_CALL_FUNCTION(&_5, "ord", NULL, 249, &_4);
	zephir_check_call_status();
	ZVAL_LONG(&_6, (((int) (zephir_get_numberval(&_5)) & 0x0f) | 0x30));
	ZEPHIR_CALL_FUNCTION(&_7, "chr", NULL, 248, &_6);
	zephir_check_call_status();
	ZVAL_LONG(&_6, 6);
	ZVAL_LONG(&_8, 1);
	ZEPHIR_CALL_FUNCTION(&_9, "substr_replace", NULL, 292, &hash, &_7, &_6, &_8);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(&hash, &_9);
	ZVAL_LONG(&_6, 8);
	ZVAL_LONG(&_8, 1);
	ZEPHIR_INIT_VAR(&_10);
	zephir_substr(&_10, &hash, 8 , 1 , 0);
	ZEPHIR_CALL_FUNCTION(&_9, "ord", NULL, 249, &_10);
	zephir_check_call_status();
	ZVAL_LONG(&_11, (((int) (zephir_get_numberval(&_9)) & 0x3f) | 0x80));
	ZEPHIR_CALL_FUNCTION(&_12, "chr", NULL, 248, &_11);
	zephir_check_call_status();
	ZVAL_LONG(&_11, 8);
	ZVAL_LONG(&_13, 1);
	ZEPHIR_CALL_FUNCTION(&_14, "substr_replace", NULL, 292, &hash, &_12, &_11, &_13);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(&hash, &_14);
	ZEPHIR_CALL_FUNCTION(&_15, "bin2hex", NULL, 282, &hash);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_14, this_ptr, "format", NULL, 0, &_15);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, ZEND_STRL("uid"), &_14);
	ZEPHIR_MM_RESTORE();
}

