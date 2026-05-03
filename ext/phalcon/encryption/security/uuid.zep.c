
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/fcall.h"
#include "kernel/object.h"
#include "kernel/memory.h"


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
 * Factory that generates UUIDs of versions 1 through 7.
 *
 * Each call creates a new immutable version object. Cast to string for the
 * UUID value; use the returned object for additional methods such as
 * getDateTime() or getNode().
 *
 * @method Version1 v1()
 * @method Version3 v3(string $namespaceName, string $name)
 * @method Version4 v4()
 * @method Version5 v5(string $namespaceName, string $name)
 * @method Version6 v6()
 * @method Version7 v7()
 */
ZEPHIR_INIT_CLASS(Phalcon_Encryption_Security_Uuid)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\Encryption\\Security, Uuid, phalcon, encryption_security_uuid, phalcon_encryption_security_uuid_method_entry, 0);

	return SUCCESS;
}

/**
 * Generates a version 1 (time-based) UUID.
 */
PHP_METHOD(Phalcon_Encryption_Security_Uuid, v1)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	object_init_ex(return_value, phalcon_encryption_security_uuid_version1_ce);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 276);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Generates a version 3 (name-based MD5) UUID.
 */
PHP_METHOD(Phalcon_Encryption_Security_Uuid, v3)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval namespaceName_zv, name_zv;
	zend_string *namespaceName = NULL, *name = NULL;

	ZVAL_UNDEF(&namespaceName_zv);
	ZVAL_UNDEF(&name_zv);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR(namespaceName)
		Z_PARAM_STR(name)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	ZVAL_STR_COPY(&namespaceName_zv, namespaceName);
	ZVAL_STR_COPY(&name_zv, name);
	object_init_ex(return_value, phalcon_encryption_security_uuid_version3_ce);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 277, &namespaceName_zv, &name_zv);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Generates a version 4 (random) UUID.
 */
PHP_METHOD(Phalcon_Encryption_Security_Uuid, v4)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	object_init_ex(return_value, phalcon_encryption_security_uuid_version4_ce);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 278);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Generates a version 5 (name-based SHA-1) UUID.
 */
PHP_METHOD(Phalcon_Encryption_Security_Uuid, v5)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval namespaceName_zv, name_zv;
	zend_string *namespaceName = NULL, *name = NULL;

	ZVAL_UNDEF(&namespaceName_zv);
	ZVAL_UNDEF(&name_zv);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR(namespaceName)
		Z_PARAM_STR(name)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	ZVAL_STR_COPY(&namespaceName_zv, namespaceName);
	ZVAL_STR_COPY(&name_zv, name);
	object_init_ex(return_value, phalcon_encryption_security_uuid_version5_ce);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 279, &namespaceName_zv, &name_zv);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Generates a version 6 (reordered time-based) UUID.
 */
PHP_METHOD(Phalcon_Encryption_Security_Uuid, v6)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	object_init_ex(return_value, phalcon_encryption_security_uuid_version6_ce);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 280);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Generates a version 7 (Unix timestamp) UUID.
 */
PHP_METHOD(Phalcon_Encryption_Security_Uuid, v7)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	object_init_ex(return_value, phalcon_encryption_security_uuid_version7_ce);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 281);
	zephir_check_call_status();
	RETURN_MM();
}

