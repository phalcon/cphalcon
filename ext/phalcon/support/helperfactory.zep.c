
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/fcall.h"
#include "kernel/memory.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/object.h"
#include "kernel/array.h"
#include "kernel/operators.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * ServiceLocator implementation for helpers
 */
ZEPHIR_INIT_CLASS(Phalcon_Support_HelperFactory)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Support, HelperFactory, phalcon, support_helperfactory, phalcon_factory_abstractfactory_ce, phalcon_support_helperfactory_method_entry, 0);

	zend_declare_property_string(phalcon_support_helperfactory_ce, SL("exception"), "Phalcon\\Support\\Exception", ZEND_ACC_PROTECTED);
	return SUCCESS;
}

/**
 * HelperFactory constructor.
 */
PHP_METHOD(Phalcon_Support_HelperFactory, __construct)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *services_param = NULL;
	zval services;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&services);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_ARRAY(services)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &services_param);
	if (!services_param) {
		ZEPHIR_INIT_VAR(&services);
		array_init(&services);
	} else {
	ZEPHIR_OBS_COPY_OR_DUP(&services, services_param);
	}


	ZEPHIR_CALL_METHOD(NULL, this_ptr, "init", NULL, 0, &services);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
}

/**
 * @param string $name
 * @param array  $arguments
 *
 * @return mixed
 * @throws Exception
 */
PHP_METHOD(Phalcon_Support_HelperFactory, __call)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval arguments, _0;
	zval *name_param = NULL, *arguments_param = NULL, helper, _1;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&helper);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&arguments);
	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR(name)
		Z_PARAM_ARRAY(arguments)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &name_param, &arguments_param);
	zephir_get_strval(&name, name_param);
	zephir_get_arrval(&arguments, arguments_param);


	ZEPHIR_CALL_METHOD(&helper, this_ptr, "newinstance", NULL, 0, &name);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_0);
	zephir_create_array(&_0, 2, 0);
	zephir_array_fast_append(&_0, &helper);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "__invoke");
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_CALL_USER_FUNC_ARRAY(return_value, &_0, &arguments);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * @param string $name
 *
 * @return mixed
 * @throws Exception
 */
PHP_METHOD(Phalcon_Support_HelperFactory, newInstance)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, _0;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(name)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);
	zephir_get_strval(&name, name_param);


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getservice", NULL, 0, &name);
	zephir_check_call_status();
	ZEPHIR_LAST_CALL_STATUS = zephir_create_instance(return_value, &_0);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * @return string[]
 */
PHP_METHOD(Phalcon_Support_HelperFactory, getAdapters)
{
	zval *this_ptr = getThis();



	zephir_create_array(return_value, 1, 0);
	add_assoc_stringl_ex(return_value, SL("interpolate"), SL("Phalcon\\Support\\Helper\\Str\\Interpolate"));
	return;
}

