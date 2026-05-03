
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
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/array.h"
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
 * Generates a version 4 (random) UUID.
 *
 * All 122 non-fixed bits are random. Identical algorithm to
 * Phalcon\Encryption\Security\Random::uuid().
 *
 * @link https://www.ietf.org/rfc/rfc4122.txt
 */
ZEPHIR_INIT_CLASS(Phalcon_Encryption_Security_Uuid_Version4)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Encryption\\Security\\Uuid, Version4, phalcon, encryption_security_uuid_version4, phalcon_encryption_security_uuid_abstractuuid_ce, phalcon_encryption_security_uuid_version4_method_entry, 0);

	return SUCCESS;
}

PHP_METHOD(Phalcon_Encryption_Security_Uuid_Version4, __construct)
{
	zval ary, _0, _1, _2, _3, _4, _5, _6, _7, _8;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&ary);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	ZVAL_LONG(&_0, 16);
	ZEPHIR_CALL_FUNCTION(&_1, "random_bytes", NULL, 272, &_0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "N1a/n1b/n1c/n1d/n1e/N1f");
	ZEPHIR_CALL_FUNCTION(&_3, "unpack", NULL, 273, &_2, &_1);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&ary, "array_values", NULL, 13, &_3);
	zephir_check_call_status();
	zephir_array_fetch_long(&_4, &ary, 2, PH_NOISY | PH_READONLY, "phalcon/Encryption/Security/Uuid/Version4.zep", 34);
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_LONG(&_2, ((((int) (zephir_get_numberval(&_4)) & 0x0fff)) | 0x4000));
	zephir_array_update_long(&ary, 2, &_2, PH_COPY | PH_SEPARATE ZEPHIR_DEBUG_PARAMS_DUMMY);
	zephir_array_fetch_long(&_5, &ary, 3, PH_NOISY | PH_READONLY, "phalcon/Encryption/Security/Uuid/Version4.zep", 35);
	ZEPHIR_INIT_VAR(&_6);
	ZVAL_LONG(&_6, ((((int) (zephir_get_numberval(&_5)) & 0x3fff)) | 0x8000));
	zephir_array_update_long(&ary, 3, &_6, PH_COPY | PH_SEPARATE ZEPHIR_DEBUG_PARAMS_DUMMY);
	ZEPHIR_INIT_VAR(&_7);
	ZVAL_STRING(&_7, "%08x-%04x-%04x-%04x-%04x%08x");
	ZEPHIR_MAKE_REF(&ary);
	ZEPHIR_CALL_FUNCTION(NULL, "array_unshift", NULL, 293, &ary, &_7);
	ZEPHIR_UNREF(&ary);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_7);
	ZEPHIR_INIT_VAR(&_8);
	ZVAL_STRING(&_8, "sprintf");
	ZEPHIR_CALL_USER_FUNC_ARRAY(&_7, &_8, &ary);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, ZEND_STRL("uid"), &_7);
	ZEPHIR_MM_RESTORE();
}

