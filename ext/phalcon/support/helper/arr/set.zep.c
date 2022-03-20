
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
#include "kernel/array.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */
/**
 * Sets an array element. Using a key is optional
 */
ZEPHIR_INIT_CLASS(Phalcon_Support_Helper_Arr_Set)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\Support\\Helper\\Arr, Set, phalcon, support_helper_arr_set, phalcon_support_helper_arr_set_method_entry, 0);

	return SUCCESS;
}

/**
 * @param array $collection
 * @param mixed $value
 * @param mixed $index
 *
 * @return array
 */
PHP_METHOD(Phalcon_Support_Helper_Arr_Set, __invoke)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *collection_param = NULL, *value, value_sub, *index = NULL, index_sub, __$null, source;
	zval collection;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&collection);
	ZVAL_UNDEF(&value_sub);
	ZVAL_UNDEF(&index_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&source);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 3)
		Z_PARAM_ARRAY(collection)
		Z_PARAM_ZVAL(value)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(index)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &collection_param, &value, &index);
	zephir_get_arrval(&collection, collection_param);
	if (!index) {
		index = &index_sub;
		index = &__$null;
	}


	ZEPHIR_CALL_METHOD(&source, this_ptr, "checknull", NULL, 0, &collection, value, index);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "checknotnull", NULL, 0, &source, value, index);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * @param array $collection
 * @param mixed $value
 * @param mixed $index
 *
 * @return array
 */
PHP_METHOD(Phalcon_Support_Helper_Arr_Set, checkNull)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *collection_param = NULL, *value, value_sub, *index, index_sub;
	zval collection;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&collection);
	ZVAL_UNDEF(&value_sub);
	ZVAL_UNDEF(&index_sub);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_ARRAY(collection)
		Z_PARAM_ZVAL(value)
		Z_PARAM_ZVAL(index)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &collection_param, &value, &index);
	zephir_get_arrval(&collection, collection_param);


	if (Z_TYPE_P(index) == IS_NULL) {
		zephir_array_append(&collection, value, PH_SEPARATE, "phalcon/Support/Helper/Arr/Set.zep", 47);
	}
	RETURN_CTOR(&collection);
}

/**
 * @param array $collection
 * @param mixed $value
 * @param mixed $index
 *
 * @return array<int|string,mixed>
 */
PHP_METHOD(Phalcon_Support_Helper_Arr_Set, checkNotNull)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *collection_param = NULL, *value, value_sub, *index, index_sub;
	zval collection;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&collection);
	ZVAL_UNDEF(&value_sub);
	ZVAL_UNDEF(&index_sub);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_ARRAY(collection)
		Z_PARAM_ZVAL(value)
		Z_PARAM_ZVAL(index)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &collection_param, &value, &index);
	zephir_get_arrval(&collection, collection_param);


	if (Z_TYPE_P(index) != IS_NULL) {
		zephir_array_update_zval(&collection, index, value, PH_COPY | PH_SEPARATE);
	}
	RETURN_CTOR(&collection);
}

