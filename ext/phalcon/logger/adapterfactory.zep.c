
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
 * Factory used to create adapters used for Logging
 */
ZEPHIR_INIT_CLASS(Phalcon_Logger_AdapterFactory)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Logger, AdapterFactory, phalcon, logger_adapterfactory, phalcon_factory_abstractfactory_ce, phalcon_logger_adapterfactory_method_entry, 0);

	return SUCCESS;
}

/**
 * AdapterFactory constructor.
 *
 * @param array $services
 */
PHP_METHOD(Phalcon_Logger_AdapterFactory, __construct)
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
	ZEPHIR_OBS_COPY_OR_DUP(&services, services_param);
	}
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "init", NULL, 0, &services);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
}

/**
 * Create a new instance of the adapter
 *
 * @param string $name
 * @param string $fileName
 * @param array  $options
 *
 * @return AdapterInterface
 * @throws Exception
 */
PHP_METHOD(Phalcon_Logger_AdapterFactory, newInstance)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval options, _0;
	zval name_zv, fileName_zv, *options_param = NULL, definition;
	zend_string *name = NULL, *fileName = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_zv);
	ZVAL_UNDEF(&fileName_zv);
	ZVAL_UNDEF(&definition);
	ZVAL_UNDEF(&options);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(2, 3)
		Z_PARAM_STR(name)
		Z_PARAM_STR(fileName)
		Z_PARAM_OPTIONAL
		ZEPHIR_Z_PARAM_ARRAY(options, options_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	if (ZEND_NUM_ARGS() > 2) {
		options_param = ZEND_CALL_ARG(execute_data, 3);
	}
	zephir_memory_observe(&name_zv);
	ZVAL_STR_COPY(&name_zv, name);
	zephir_memory_observe(&fileName_zv);
	ZVAL_STR_COPY(&fileName_zv, fileName);
	if (!options_param) {
		ZEPHIR_INIT_VAR(&options);
		array_init(&options);
	} else {
		zephir_get_arrval(&options, options_param);
	}
	ZEPHIR_CALL_METHOD(&definition, this_ptr, "getservice", NULL, 0, &name_zv);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_0);
	zephir_create_array(&_0, 2, 0);
	zephir_array_fast_append(&_0, &fileName_zv);
	zephir_array_fast_append(&_0, &options);
	ZEPHIR_LAST_CALL_STATUS = zephir_create_instance_params(return_value, &definition, &_0);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * @return string
 */
PHP_METHOD(Phalcon_Logger_AdapterFactory, getExceptionClass)
{

	RETURN_STRING("Phalcon\\Logger\\Exception");
}

/**
 * Returns the available adapters
 *
 * @return string[]
 */
PHP_METHOD(Phalcon_Logger_AdapterFactory, getServices)
{

	zephir_create_array(return_value, 3, 0);
	add_assoc_stringl_ex(return_value, SL("noop"), SL("Phalcon\\Logger\\Adapter\\Noop"));
	add_assoc_stringl_ex(return_value, SL("stream"), SL("Phalcon\\Logger\\Adapter\\Stream"));
	add_assoc_stringl_ex(return_value, SL("syslog"), SL("Phalcon\\Logger\\Adapter\\Syslog"));
	return;
}

