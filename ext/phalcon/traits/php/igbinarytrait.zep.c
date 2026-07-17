
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


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * Igbinary based wrapper methods
 */
ZEPHIR_INIT_CLASS(Phalcon_Traits_Php_IgbinaryTrait)
{
	ZEPHIR_REGISTER_TRAIT(Phalcon\\Traits\\Php, IgbinaryTrait, phalcon, traits_php_igbinarytrait, phalcon_traits_php_igbinarytrait_method_entry);

	return SUCCESS;
}

/**
 * @param mixed $value
 *
 * @return string|null
 *
 * @link https://php.net/manual/en/function.igbinary-serialize.php
 */
PHP_METHOD(Phalcon_Traits_Php_IgbinaryTrait, phpIgbinarySerialize)
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
	ZEPHIR_RETURN_CALL_FUNCTION("igbinary_serialize", NULL, 289, value);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * @param string $value
 *
 * @return mixed|false
 *
 * @link https://php.net/manual/en/function.igbinary-unserialize.php
 */
PHP_METHOD(Phalcon_Traits_Php_IgbinaryTrait, phpIgbinaryUnserialize)
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
	ZEPHIR_RETURN_CALL_FUNCTION("igbinary_unserialize", NULL, 290, value);
	zephir_check_call_status();
	RETURN_MM();
}

