
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
 * This file is part of the Phalcon Framework.
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
 * @param array<array-key, mixed> $collection
 *
 * @return object
 */
PHP_METHOD(Phalcon_Support_Helper_Arr_ToObject, __invoke)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *collection_param = NULL, _0;
	zval collection;

	ZVAL_UNDEF(&collection);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		ZEPHIR_Z_PARAM_ARRAY(collection, collection_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &collection_param);
	zephir_get_arrval(&collection, collection_param);
	ZEPHIR_CPY_WRT(&_0, &collection);
	zephir_convert_to_object(&_0);
	RETURN_CCTOR(&_0);
}

