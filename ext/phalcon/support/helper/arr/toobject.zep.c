
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
 * Returns the passed array as an object.
 */
ZEPHIR_INIT_CLASS(Phalcon_Support_Helper_Arr_ToObject)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\Support\\Helper\\Arr, ToObject, phalcon, support_helper_arr_toobject, phalcon_support_helper_arr_toobject_method_entry, 0);

	return SUCCESS;
}

/**
 * @param array $collection
 *
 * @return object
 */
PHP_METHOD(Phalcon_Support_Helper_Arr_ToObject, __invoke)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *collection_param = NULL;
	zval collection;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&collection);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ARRAY(collection)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &collection_param);
	zephir_get_arrval(&collection, collection_param);


	zephir_convert_to_object(&collection);
	RETURN_CTOR(&collection);
}

