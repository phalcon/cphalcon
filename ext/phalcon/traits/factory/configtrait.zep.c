
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
#include "kernel/object.h"
#include "kernel/fcall.h"
#include "kernel/memory.h"
#include "kernel/array.h"
#include "kernel/exception.h"
#include "kernel/concat.h"
#include "kernel/operators.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
ZEPHIR_INIT_CLASS(Phalcon_Traits_Factory_ConfigTrait)
{
	ZEPHIR_REGISTER_TRAIT(Phalcon\\Traits\\Factory, ConfigTrait, phalcon, traits_factory_configtrait, phalcon_traits_factory_configtrait_method_entry);

	return SUCCESS;
}

/**
 * @param array<string, mixed>|ConfigInterface $config
 *
 * @return array<string, mixed>
 */
PHP_METHOD(Phalcon_Traits_Factory_ConfigTrait, checkConfig)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *config, config_sub;

	ZVAL_UNDEF(&config_sub);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(config)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &config);
	if (zephir_instance_of_ev(config, phalcon_config_configinterface_ce)) {
		ZEPHIR_RETURN_CALL_METHOD(config, "toarray", NULL, 0);
		zephir_check_call_status();
		RETURN_MM();
	}
	if (Z_TYPE_P(config) != IS_ARRAY) {
		array_init(return_value);
		RETURN_MM();
	}
	RETVAL_ZVAL(config, 1, 0);
	RETURN_MM();
}

/**
 * Checks if the config has a specific element
 *
 * @param array  $config
 * @param string $element
 *
 * @return array
 */
PHP_METHOD(Phalcon_Traits_Factory_ConfigTrait, checkConfigElement)
{
	zval _3$$4;
	zend_class_entry *_2$$4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_string *element = NULL;
	zval *config_param = NULL, element_zv, exceptionClass, _0$$4, _1$$4;
	zval config;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&config);
	ZVAL_UNDEF(&element_zv);
	ZVAL_UNDEF(&exceptionClass);
	ZVAL_UNDEF(&_0$$4);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&_3$$4);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		ZEPHIR_Z_PARAM_ARRAY(config, config_param)
		Z_PARAM_STR(element)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	config_param = ZEND_CALL_ARG(execute_data, 1);
	zephir_get_arrval(&config, config_param);
	zephir_memory_observe(&element_zv);
	ZVAL_STR_COPY(&element_zv, element);
	if (!(zephir_array_isset_value(&config, &element_zv))) {
		if ((zephir_method_exists_ex(this_ptr, ZEND_STRL("getexceptionclass")) == SUCCESS)) {
			ZEPHIR_CALL_METHOD(&exceptionClass, this_ptr, "getexceptionclass", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(&_0$$4);
			zephir_fetch_safe_class(&_1$$4, &exceptionClass);
			_2$$4 = zephir_fetch_class_str_ex(Z_STRVAL_P(&_1$$4), Z_STRLEN_P(&_1$$4), ZEND_FETCH_CLASS_AUTO);
			if(!_2$$4) {
				RETURN_MM_NULL();
			}
			object_init_ex(&_0$$4, _2$$4);
			ZEPHIR_LAST_CALL_STATUS = zephir_check_constructor_access(&_0$$4);
			zephir_check_call_status();
			if (zephir_has_constructor(&_0$$4)) {
				ZEPHIR_INIT_VAR(&_3$$4);
				ZEPHIR_CONCAT_SVS(&_3$$4, "You must provide the '", &element_zv, "' option in the factory config parameter.");
				ZEPHIR_CALL_METHOD(NULL, &_0$$4, "__construct", NULL, 0, &_3$$4);
				zephir_check_call_status();
			}

			zephir_throw_exception_debug(&_0$$4, "phalcon/Traits/Factory/ConfigTrait.zep", 52);
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	RETURN_CTOR(&config);
}

