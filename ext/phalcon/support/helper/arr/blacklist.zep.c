
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
#include "kernel/object.h"
#include "kernel/memory.h"
#include "kernel/operators.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */
/**
 * Black list filter by key: exclude elements of an array
 * by the keys obtained from the elements of a blacklist
 */
ZEPHIR_INIT_CLASS(Phalcon_Support_Helper_Arr_Blacklist)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\Support\\Helper\\Arr, Blacklist, phalcon, support_helper_arr_blacklist, phalcon_support_helper_arr_blacklist_method_entry, 0);

	return SUCCESS;
}

/**
 * @param array $collection
 * @param array $blackList
 *
 * @return array
 */
PHP_METHOD(Phalcon_Support_Helper_Arr_Blacklist, __invoke)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *collection_param = NULL, *blackList_param = NULL, blackListed, _0, _1;
	zval collection, blackList;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&collection);
	ZVAL_UNDEF(&blackList);
	ZVAL_UNDEF(&blackListed);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		ZEPHIR_Z_PARAM_ARRAY(collection, collection_param)
		ZEPHIR_Z_PARAM_ARRAY(blackList, blackList_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 2, 0, &collection_param, &blackList_param);
	zephir_get_arrval(&collection, collection_param);
	zephir_get_arrval(&blackList, blackList_param);
	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_INIT_NVAR(&_0);
	zephir_create_closure_ex(&_0, NULL, phalcon_89__closure_ce, SL("__invoke"));
	ZEPHIR_CALL_METHOD(&blackListed, this_ptr, "tofilter", NULL, 0, &blackList, &_0);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&_1, "array_flip", NULL, 241, &blackListed);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_FUNCTION("array_diff_key", NULL, 237, &collection, &_1);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Helper method to filter the collection
 *
 * @param array         $collection
 * @param callable|null $method
 *
 * @return array
 */
PHP_METHOD(Phalcon_Support_Helper_Arr_Blacklist, toFilter)
{
	zend_bool _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *collection_param = NULL, *method = NULL, method_sub, __$null;
	zval collection;

	ZVAL_UNDEF(&collection);
	ZVAL_UNDEF(&method_sub);
	ZVAL_NULL(&__$null);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 2)
		ZEPHIR_Z_PARAM_ARRAY(collection, collection_param)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(method)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
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
	ZEPHIR_RETURN_CALL_FUNCTION("array_filter", NULL, 0, &collection, method);
	zephir_check_call_status();
	RETURN_MM();
}

