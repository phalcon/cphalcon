
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
#include "kernel/fcall.h"
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
 * Abstract class offering methods to help with the Arr namespace. This can
 * be moved to a trait once Zephir supports it.
 *
 * @todo move to trait when there is support for it
 */
ZEPHIR_INIT_CLASS(Phalcon_Support_Helper_Arr_AbstractArr)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\Support\\Helper\\Arr, AbstractArr, phalcon, support_helper_arr_abstractarr, phalcon_support_helper_arr_abstractarr_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	return SUCCESS;
}

/**
 * Helper method to filter the collection
 *
 * @param array         $collection
 * @param callable|null $method
 *
 * @return array
 */
PHP_METHOD(Phalcon_Support_Helper_Arr_AbstractArr, toFilter)
{
	zend_bool _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *collection_param = NULL, *method = NULL, method_sub, __$null;
	zval collection;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&collection);
	ZVAL_UNDEF(&method_sub);
	ZVAL_NULL(&__$null);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_ARRAY(collection)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(method)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &collection_param, &method);
	zephir_get_arrval(&collection, collection_param);
	if (!method) {
		method = &method_sub;
		method = &__$null;
	}


	_0 = !zephir_is_true(method);
	if (!(_0)) {
		_0 = !(zephir_is_callable(method));
	}
	if (_0) {
		RETURN_CTOR(&collection);
	}
	ZEPHIR_RETURN_CALL_FUNCTION("array_filter", NULL, 18, &collection, method);
	zephir_check_call_status();
	RETURN_MM();
}

