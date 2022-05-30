
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
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "kernel/object.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */
/**
 * Returns a new array with n elements removed from the left.
 */
ZEPHIR_INIT_CLASS(Phalcon_Support_Helper_Arr_SliceLeft)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\Support\\Helper\\Arr, SliceLeft, phalcon, support_helper_arr_sliceleft, phalcon_support_helper_arr_sliceleft_method_entry, 0);

	return SUCCESS;
}

/**
 * @param array $collection
 * @param int   $elements
 *
 * @return array
 */
PHP_METHOD(Phalcon_Support_Helper_Arr_SliceLeft, __invoke)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long elements, ZEPHIR_LAST_CALL_STATUS;
	zval *collection_param = NULL, *elements_param = NULL, _0, _1;
	zval collection;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&collection);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_ARRAY(collection)
		Z_PARAM_OPTIONAL
		Z_PARAM_LONG(elements)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &collection_param, &elements_param);
	zephir_get_arrval(&collection, collection_param);
	if (!elements_param) {
		elements = 1;
	} else {
		elements = zephir_get_intval(elements_param);
	}


	ZVAL_LONG(&_0, 0);
	ZVAL_LONG(&_1, elements);
	ZEPHIR_RETURN_CALL_FUNCTION("array_slice", NULL, 496, &collection, &_0, &_1);
	zephir_check_call_status();
	RETURN_MM();
}

