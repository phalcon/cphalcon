
#ifdef HAVE_CONFIG_H
#include "../../../../ext_config.h"
#endif

#include <php.h>
#include "../../../../php_ext.h"
#include "../../../../ext.h"

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
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */
/**
 * Checks if a number is within a range
 */
ZEPHIR_INIT_CLASS(Phalcon_Support_Helper_Number_IsBetween)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\Support\\Helper\\Number, IsBetween, phalcon, support_helper_number_isbetween, phalcon_support_helper_number_isbetween_method_entry, 0);

	return SUCCESS;
}

/**
 * @param int $value
 * @param int $start
 * @param int $end
 *
 * @return bool
 */
PHP_METHOD(Phalcon_Support_Helper_Number_IsBetween, __invoke)
{
	zend_bool _0;
	zval *value_param = NULL, *start_param = NULL, *end_param = NULL;
	zend_long value, start, end;
	zval *this_ptr = getThis();

#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_LONG(value)
		Z_PARAM_LONG(start)
		Z_PARAM_LONG(end)
	ZEND_PARSE_PARAMETERS_END();
#endif


	zephir_fetch_params_without_memory_grow(3, 0, &value_param, &start_param, &end_param);
	value = zephir_get_intval(value_param);
	start = zephir_get_intval(start_param);
	end = zephir_get_intval(end_param);


	_0 = value >= start;
	if (_0) {
		_0 = value <= end;
	}
	RETURN_BOOL(_0);
}

