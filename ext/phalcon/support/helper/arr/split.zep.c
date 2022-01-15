
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
#include "kernel/array.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
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
 * Returns a new array with keys of the collection as one element and values
 * as another
 */
ZEPHIR_INIT_CLASS(Phalcon_Support_Helper_Arr_Split)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\Support\\Helper\\Arr, Split, phalcon, support_helper_arr_split, phalcon_support_helper_arr_split_method_entry, 0);

	return SUCCESS;
}

/**
 * @param array $collection
 *
 * @return array
 */
PHP_METHOD(Phalcon_Support_Helper_Arr_Split, __invoke)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *collection_param = NULL, _0, _1;
	zval collection;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&collection);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ARRAY(collection)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &collection_param);
	zephir_get_arrval(&collection, collection_param);


	zephir_create_array(return_value, 2, 0);
	ZEPHIR_INIT_VAR(&_0);
	zephir_array_keys(&_0, &collection);
	zephir_array_fast_append(return_value, &_0);
	ZEPHIR_CALL_FUNCTION(&_1, "array_values", NULL, 14, &collection);
	zephir_check_call_status();
	zephir_array_fast_append(return_value, &_1);
	RETURN_MM();
}

