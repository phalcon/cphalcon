
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
#include "kernel/object.h"
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
 * PHP serialize/unserialize wrapper methods
 */
ZEPHIR_INIT_CLASS(Phalcon_Traits_Php_SerializeTrait)
{
	ZEPHIR_REGISTER_TRAIT(Phalcon\\Traits\\Php, SerializeTrait, phalcon, traits_php_serializetrait, phalcon_traits_php_serializetrait_method_entry);

	return SUCCESS;
}

/**
 * @param mixed $value
 *
 * @return string
 *
 * @link https://php.net/manual/en/function.serialize.php
 */
PHP_METHOD(Phalcon_Traits_Php_SerializeTrait, phpSerialize)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *value, value_sub;

	ZVAL_UNDEF(&value_sub);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(value)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &value);
	ZEPHIR_RETURN_CALL_FUNCTION("serialize", NULL, 22, value);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * @param string $data
 * @param array  $options
 *
 * @return mixed
 *
 * @link https://php.net/manual/en/function.unserialize.php
 */
PHP_METHOD(Phalcon_Traits_Php_SerializeTrait, phpUnserialize)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval options;
	zval data_zv, *options_param = NULL;
	zend_string *data = NULL;

	ZVAL_UNDEF(&data_zv);
	ZVAL_UNDEF(&options);
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_STR(data)
		Z_PARAM_OPTIONAL
		ZEPHIR_Z_PARAM_ARRAY(options, options_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	if (ZEND_NUM_ARGS() > 1) {
		options_param = ZEND_CALL_ARG(execute_data, 2);
	}
	zephir_memory_observe(&data_zv);
	ZVAL_STR_COPY(&data_zv, data);
	if (!options_param) {
		ZEPHIR_INIT_VAR(&options);
		array_init(&options);
	} else {
		zephir_get_arrval(&options, options_param);
	}
	ZEPHIR_RETURN_CALL_FUNCTION("unserialize", NULL, 27, &data_zv, &options);
	zephir_check_call_status();
	RETURN_MM();
}

