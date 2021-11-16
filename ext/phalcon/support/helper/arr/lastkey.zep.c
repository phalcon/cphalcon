
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
 * This file is part of the Phalcon.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */
/**
 * Returns the key of the last element of the collection. If a callable is
 * passed, the element returned is the first that validates true
 */
ZEPHIR_INIT_CLASS(Phalcon_Support_Helper_Arr_LastKey)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Support\\Helper\\Arr, LastKey, phalcon, support_helper_arr_lastkey, phalcon_support_helper_arr_abstractarr_ce, phalcon_support_helper_arr_lastkey_method_entry, 0);

	return SUCCESS;
}

/**
 * @param array         $collection
 * @param callable|null $method
 *
 * @return mixed
 */
PHP_METHOD(Phalcon_Support_Helper_Arr_LastKey, __invoke)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *collection_param = NULL, *method = NULL, method_sub, __$null, filtered;
	zval collection;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&collection);
	ZVAL_UNDEF(&method_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&filtered);
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


	ZEPHIR_CALL_METHOD(&filtered, this_ptr, "tofilter", NULL, 0, &collection, method);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_FUNCTION("array_key_last", NULL, 48, &filtered);
	zephir_check_call_status();
	RETURN_MM();
}

