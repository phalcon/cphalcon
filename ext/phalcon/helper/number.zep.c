
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
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "kernel/object.h"


/**
 * This file is part of the Phalcon.
 *
 * (c) Phalcon Team <team@phalcon.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */
/**
 * Phalcon\Helper\number
 *
 * This class offers numeric functions for the framework
 */
ZEPHIR_INIT_CLASS(Phalcon_Helper_Number)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\Helper, Number, phalcon, helper_number, phalcon_helper_number_method_entry, 0);

	return SUCCESS;
}

/**
 * Helper method to get an array element or a default
 */
PHP_METHOD(Phalcon_Helper_Number, between)
{
	zend_bool _0;
	zval *value_param = NULL, *from_param = NULL, *to_param = NULL;
	zend_long value, from, to;
	zval *this_ptr = getThis();

#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_LONG(value)
		Z_PARAM_LONG(from)
		Z_PARAM_LONG(to)
	ZEND_PARSE_PARAMETERS_END();
#endif


	zephir_fetch_params_without_memory_grow(3, 0, &value_param, &from_param, &to_param);
	value = zephir_get_intval(value_param);
	from = zephir_get_intval(from_param);
	to = zephir_get_intval(to_param);


	_0 = value >= from;
	if (_0) {
		_0 = value <= to;
	}
	RETURN_BOOL(_0);
}

