
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
 * Returns `true` if the provided function returns `true` for at least one
 * element of the collection, `false` otherwise.
 */
ZEPHIR_INIT_CLASS(Phalcon_Support_Helper_Arr_ValidateAny)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Support\\Helper\\Arr, ValidateAny, phalcon, support_helper_arr_validateany, phalcon_support_helper_arr_abstractarr_ce, phalcon_support_helper_arr_validateany_method_entry, 0);

	return SUCCESS;
}

/**
 * @param array    $collection
 * @param callable $method
 *
 * @return bool
 */
PHP_METHOD(Phalcon_Support_Helper_Arr_ValidateAny, __invoke)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *collection_param = NULL, *method, method_sub, _0;
	zval collection;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&collection);
	ZVAL_UNDEF(&method_sub);
	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_ARRAY(collection)
		Z_PARAM_ZVAL(method)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &collection_param, &method);
	zephir_get_arrval(&collection, collection_param);


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "tofilter", NULL, 0, &collection, method);
	zephir_check_call_status();
	RETURN_MM_BOOL(zephir_fast_count_int(&_0) > 0);
}

