
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
#include "kernel/object.h"
#include "kernel/fcall.h"
#include "kernel/memory.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
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
ZEPHIR_INIT_CLASS(Phalcon_Translate_TranslateFactory) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Translate, TranslateFactory, phalcon, translate_translatefactory, phalcon_factory_abstractfactory_ce, phalcon_translate_translatefactory_method_entry, 0);

	/**
	 * @var InterpolatorFactory
	 */
	zend_declare_property_null(phalcon_translate_translatefactory_ce, SL("interpolator"), ZEND_ACC_PRIVATE);

	return SUCCESS;

}

/**
 * AdapterFactory constructor.
 */
PHP_METHOD(Phalcon_Translate_TranslateFactory, __construct) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval services;
	zval *interpolator, interpolator_sub, *services_param = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&interpolator_sub);
	ZVAL_UNDEF(&services);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_OBJECT_OF_CLASS(interpolator, phalcon_translate_interpolatorfactory_ce)
		Z_PARAM_OPTIONAL
		Z_PARAM_ARRAY(services)
	ZEND_PARSE_PARAMETERS_END();

#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &interpolator, &services_param);

	if (!services_param) {
		ZEPHIR_INIT_VAR(&services);
		array_init(&services);
	} else {
	ZEPHIR_OBS_COPY_OR_DUP(&services, services_param);
	}


	zephir_update_property_zval(this_ptr, ZEND_STRL("interpolator"), interpolator);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "init", NULL, 0, &services);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Factory to create an instance from a Config object
 *
 * @param array|\Phalcon\Config = [
 *     'adapter' => 'ini,
 *     'options' => [
 *         'content' => '',
 *         'delimiter' => ';',
 *         'enclosure' => '"',
 *         'locale' => '',
 *         'defaultDomain' => '',
 *         'directory' => '',
 *         'category' => ''
 *         'triggerError' => false
 *     ]
 * ]
 */
PHP_METHOD(Phalcon_Translate_TranslateFactory, load) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_1 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *config = NULL, config_sub, name, options, _0, _2, _3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&config_sub);
	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&options);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(config)
	ZEND_PARSE_PARAMETERS_END();

#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &config);

	ZEPHIR_SEPARATE_PARAM(config);


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "checkconfig", NULL, 0, config);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(config, &_0);
	ZEPHIR_OBS_VAR(&name);
	zephir_array_fetch_string(&name, config, SL("adapter"), PH_NOISY, "phalcon/Translate/TranslateFactory.zep", 57);
	ZEPHIR_INIT_VAR(&_2);
	array_init(&_2);
	ZEPHIR_INIT_VAR(&_3);
	ZVAL_STRING(&_3, "options");
	ZEPHIR_CALL_CE_STATIC(&options, phalcon_helper_arr_ce, "get", &_1, 16, config, &_3, &_2);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "newinstance", NULL, 0, &name, &options);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Create a new instance of the adapter
 */
PHP_METHOD(Phalcon_Translate_TranslateFactory, newInstance) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval options, _0;
	zval *name_param = NULL, *options_param = NULL, definition, _1;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&definition);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&options);
	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_STR(name)
		Z_PARAM_OPTIONAL
		Z_PARAM_ARRAY(options)
	ZEND_PARSE_PARAMETERS_END();

#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &name_param, &options_param);

	if (UNEXPECTED(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(name_param) == IS_STRING)) {
		zephir_get_strval(&name, name_param);
	} else {
		ZEPHIR_INIT_VAR(&name);
		ZVAL_EMPTY_STRING(&name);
	}
	if (!options_param) {
		ZEPHIR_INIT_VAR(&options);
		array_init(&options);
	} else {
	ZEPHIR_OBS_COPY_OR_DUP(&options, options_param);
	}


	ZEPHIR_CALL_METHOD(&definition, this_ptr, "getservice", NULL, 0, &name);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_0);
	zephir_create_array(&_0, 2, 0);
	ZEPHIR_OBS_VAR(&_1);
	zephir_read_property(&_1, this_ptr, ZEND_STRL("interpolator"), PH_NOISY_CC);
	zephir_array_fast_append(&_0, &_1);
	zephir_array_fast_append(&_0, &options);
	ZEPHIR_LAST_CALL_STATUS = zephir_create_instance_params(return_value, &definition, &_0);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Phalcon_Translate_TranslateFactory, getAdapters) {

	zval *this_ptr = getThis();



	zephir_create_array(return_value, 3, 0);
	add_assoc_stringl_ex(return_value, SL("csv"), SL("Phalcon\\Translate\\Adapter\\Csv"));
	add_assoc_stringl_ex(return_value, SL("gettext"), SL("Phalcon\\Translate\\Adapter\\Gettext"));
	add_assoc_stringl_ex(return_value, SL("array"), SL("Phalcon\\Translate\\Adapter\\NativeArray"));
	return;

}

