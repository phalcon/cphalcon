
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
#include "kernel/memory.h"
#include "kernel/operators.h"
#include "kernel/object.h"
#include "kernel/array.h"
#include "kernel/exception.h"
#include "kernel/concat.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * Factory for creating pad classes
 */
ZEPHIR_INIT_CLASS(Phalcon_Encryption_Crypt_PadFactory)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Encryption\\Crypt, PadFactory, phalcon, encryption_crypt_padfactory, phalcon_factory_abstractfactory_ce, phalcon_encryption_crypt_padfactory_method_entry, 0);

	/**
	 * @var string
	 */
	zend_declare_property_string(phalcon_encryption_crypt_padfactory_ce, SL("exception"), "Phalcon\\Encryption\\Crypt\\Exception\\Exception", ZEND_ACC_PROTECTED);
	return SUCCESS;
}

/**
 * AdapterFactory constructor.
 */
PHP_METHOD(Phalcon_Encryption_Crypt_PadFactory, __construct)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *services_param = NULL;
	zval services;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&services);
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		ZEPHIR_Z_PARAM_ARRAY(services, services_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 0, 1, &services_param);
	if (!services_param) {
		ZEPHIR_INIT_VAR(&services);
		array_init(&services);
	} else {
		zephir_get_arrval(&services, services_param);
	}
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "init", NULL, 0, &services);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
}

/**
 * Create a new instance of the adapter
 */
PHP_METHOD(Phalcon_Encryption_Crypt_PadFactory, newInstance)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval name_zv, definition;
	zend_string *name = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_zv);
	ZVAL_UNDEF(&definition);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(name)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&name_zv);
	ZVAL_STR_COPY(&name_zv, name);
	ZEPHIR_CALL_METHOD(&definition, this_ptr, "getservice", NULL, 0, &name_zv);
	zephir_check_call_status();
	ZEPHIR_LAST_CALL_STATUS = zephir_create_instance(return_value, &definition);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Gets a Crypt pad constant and returns the unique service name for the
 * padding class
 *
 * @param int $number
 *
 * @return string
 */
PHP_METHOD(Phalcon_Encryption_Crypt_PadFactory, padNumberToService)
{
	zval _2$$3;
	zval map;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *number_param = NULL, _3, _0$$3, _1$$3;
	zend_long number, ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&map);
	ZVAL_UNDEF(&_2$$3);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(number)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &number_param);
	ZEPHIR_INIT_VAR(&map);
	zephir_create_array(&map, 7, 0);
	add_index_stringl(&map, 0, SL("noop"));
	add_index_stringl(&map, 1, SL("ansi"));
	add_index_stringl(&map, 3, SL("iso10126"));
	add_index_stringl(&map, 4, SL("isoiek"));
	add_index_stringl(&map, 2, SL("pjcs7"));
	add_index_stringl(&map, 6, SL("space"));
	add_index_stringl(&map, 5, SL("zero"));
	if (UNEXPECTED(!(zephir_array_isset_value_long(&map, number)))) {
		ZEPHIR_INIT_VAR(&_1$$3);
		ZVAL_LONG(&_1$$3, number);
		ZEPHIR_INIT_VAR(&_2$$3);
		ZEPHIR_CONCAT_SV(&_2$$3, "Unknown padding constant ", &_1$$3);
		ZEPHIR_CALL_METHOD(&_0$$3, this_ptr, "getexception", NULL, 0, &_2$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_0$$3, "phalcon/Encryption/Crypt/PadFactory.zep", 72);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_array_fetch_long(&_3, &map, number, PH_NOISY | PH_READONLY, "phalcon/Encryption/Crypt/PadFactory.zep", 75);
	RETURN_CTOR(&_3);
}

/**
 * @return string[]
 */
PHP_METHOD(Phalcon_Encryption_Crypt_PadFactory, getServices)
{

	zephir_create_array(return_value, 8, 0);
	add_assoc_stringl_ex(return_value, SL("ansi"), SL("Phalcon\\Encryption\\Crypt\\Padding\\Ansi"));
	add_assoc_stringl_ex(return_value, SL("iso10126"), SL("Phalcon\\Encryption\\Crypt\\Padding\\Iso10126"));
	add_assoc_stringl_ex(return_value, SL("isoiek"), SL("Phalcon\\Encryption\\Crypt\\Padding\\IsoIek"));
	add_assoc_stringl_ex(return_value, SL("noop"), SL("Phalcon\\Encryption\\Crypt\\Padding\\Noop"));
	add_assoc_stringl_ex(return_value, SL("pjcs7"), SL("Phalcon\\Encryption\\Crypt\\Padding\\Pkcs7"));
	add_assoc_stringl_ex(return_value, SL("pkcs7"), SL("Phalcon\\Encryption\\Crypt\\Padding\\Pkcs7"));
	add_assoc_stringl_ex(return_value, SL("space"), SL("Phalcon\\Encryption\\Crypt\\Padding\\Space"));
	add_assoc_stringl_ex(return_value, SL("zero"), SL("Phalcon\\Encryption\\Crypt\\Padding\\Zero"));
	return;
}

