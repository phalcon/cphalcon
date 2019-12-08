
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

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &interpolator, &services_param);

	if (!services_param) {
		ZEPHIR_INIT_VAR(&services);
		array_init(&services);
	} else {
	ZEPHIR_OBS_COPY_OR_DUP(&services, services_param);
	}


	zephir_update_property_zval(this_ptr, SL("interpolator"), interpolator);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "init", NULL, 0, &services);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Factory to create an instace from a Config object
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

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &config);

	ZEPHIR_SEPARATE_PARAM(config);


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "checkconfig", NULL, 0, config);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(config, &_0);
	ZEPHIR_OBS_VAR(&name);
	zephir_array_fetch_string(&name, config, SL("adapter"), PH_NOISY, "phalcon/Translate/TranslateFactory.zep", 43);
	ZEPHIR_INIT_VAR(&_2);
	array_init(&_2);
	ZEPHIR_INIT_VAR(&_3);
	ZVAL_STRING(&_3, "options");
	ZEPHIR_CALL_CE_STATIC(&options, phalcon_helper_arr_ce, "get", &_1, 15, config, &_3, &_2);
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
	zval options, _3$$3;
	zval *name_param = NULL, *options_param = NULL, definition, _0, _5, _6, _1$$3, _2$$3, _4$$3;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&definition);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&options);
	ZVAL_UNDEF(&_3$$3);

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


	ZEPHIR_CALL_METHOD(NULL, this_ptr, "checkservice", NULL, 0, &name);
	zephir_check_call_status();
	zephir_read_property(&_0, this_ptr, SL("services"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_array_isset(&_0, &name))) {
		zephir_read_property(&_1$$3, this_ptr, SL("mapper"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_OBS_VAR(&definition);
		zephir_array_fetch(&definition, &_1$$3, &name, PH_NOISY, "phalcon/Translate/TranslateFactory.zep", 59);
		ZEPHIR_INIT_VAR(&_2$$3);
		ZEPHIR_INIT_VAR(&_3$$3);
		zephir_create_array(&_3$$3, 2, 0);
		ZEPHIR_OBS_VAR(&_4$$3);
		zephir_read_property(&_4$$3, this_ptr, SL("interpolator"), PH_NOISY_CC);
		zephir_array_fast_append(&_3$$3, &_4$$3);
		zephir_array_fast_append(&_3$$3, &options);
		ZEPHIR_LAST_CALL_STATUS = zephir_create_instance_params(&_2$$3, &definition, &_3$$3);
		zephir_check_call_status();
		zephir_update_property_array(this_ptr, SL("services"), &name, &_2$$3);
	}
	zephir_read_property(&_5, this_ptr, SL("services"), PH_NOISY_CC | PH_READONLY);
	zephir_array_fetch(&_6, &_5, &name, PH_NOISY | PH_READONLY, "phalcon/Translate/TranslateFactory.zep", 69);
	RETURN_CTOR(&_6);

}

PHP_METHOD(Phalcon_Translate_TranslateFactory, getAdapters) {

	zval *this_ptr = getThis();


	zephir_create_array(return_value, 3, 0);
	add_assoc_stringl_ex(return_value, SL("csv"), SL("Phalcon\\Translate\\Adapter\\Csv"));
	add_assoc_stringl_ex(return_value, SL("gettext"), SL("Phalcon\\Translate\\Adapter\\Gettext"));
	add_assoc_stringl_ex(return_value, SL("array"), SL("Phalcon\\Translate\\Adapter\\NativeArray"));
	return;

}

