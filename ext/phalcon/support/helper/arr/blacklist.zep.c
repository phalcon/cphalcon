
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
 * This file is part of the Phalcon.
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
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Support\\Helper\\Arr, Blacklist, phalcon, support_helper_arr_blacklist, phalcon_support_helper_arr_abstractarr_ce, phalcon_support_helper_arr_blacklist_method_entry, 0);

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
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_ARRAY(collection)
		Z_PARAM_ARRAY(blackList)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &collection_param, &blackList_param);
	zephir_get_arrval(&collection, collection_param);
	zephir_get_arrval(&blackList, blackList_param);


	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_INIT_NVAR(&_0);
	zephir_create_closure_ex(&_0, NULL, phalcon_14__closure_ce, SL("__invoke"));
	ZEPHIR_CALL_METHOD(&blackListed, this_ptr, "tofilter", NULL, 0, &blackList, &_0);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&_1, "array_flip", NULL, 194, &blackListed);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_FUNCTION("array_diff_key", NULL, 458, &collection, &_1);
	zephir_check_call_status();
	RETURN_MM();
}

