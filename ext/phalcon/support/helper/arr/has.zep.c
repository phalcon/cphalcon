
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
 * Checks an array if it has an element with a specific key and returns
 * `true`/`false` accordingly
 */
ZEPHIR_INIT_CLASS(Phalcon_Support_Helper_Arr_Has)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\Support\\Helper\\Arr, Has, phalcon, support_helper_arr_has, phalcon_support_helper_arr_has_method_entry, 0);

	return SUCCESS;
}

/**
 * @param array      $collection
 * @param string|int $index
 *
 * @return bool
 */
PHP_METHOD(Phalcon_Support_Helper_Arr_Has, __invoke)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *collection_param = NULL, *index, index_sub;
	zval collection;

	ZVAL_UNDEF(&collection);
	ZVAL_UNDEF(&index_sub);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_ARRAY(collection)
		Z_PARAM_ZVAL(index)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 2, 0, &collection_param, &index);
	zephir_get_arrval(&collection, collection_param);
	RETURN_MM_BOOL(zephir_array_key_exists(&collection, index));
}

