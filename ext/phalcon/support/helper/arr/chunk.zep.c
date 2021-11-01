
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
 * Chunks an array into smaller arrays of a specified size.
 */
ZEPHIR_INIT_CLASS(Phalcon_Support_Helper_Arr_Chunk)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\Support\\Helper\\Arr, Chunk, phalcon, support_helper_arr_chunk, phalcon_support_helper_arr_chunk_method_entry, 0);

	return SUCCESS;
}

/**
 * @param array $collection
 * @param int   $size
 * @param bool  $preserveKeys
 *
 * @return array<int|string,mixed>
 */
PHP_METHOD(Phalcon_Support_Helper_Arr_Chunk, __invoke)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_bool preserveKeys;
	zend_long size, ZEPHIR_LAST_CALL_STATUS;
	zval *collection_param = NULL, *size_param = NULL, *preserveKeys_param = NULL, _0, _1;
	zval collection;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&collection);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 3)
		Z_PARAM_ARRAY(collection)
		Z_PARAM_LONG(size)
		Z_PARAM_OPTIONAL
		Z_PARAM_BOOL(preserveKeys)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &collection_param, &size_param, &preserveKeys_param);
	zephir_get_arrval(&collection, collection_param);
	size = zephir_get_intval(size_param);
	if (!preserveKeys_param) {
		preserveKeys = 0;
	} else {
		preserveKeys = zephir_get_boolval(preserveKeys_param);
	}


	ZVAL_LONG(&_0, size);
	ZVAL_BOOL(&_1, (preserveKeys ? 1 : 0));
	ZEPHIR_RETURN_CALL_FUNCTION("array_chunk", NULL, 286, &collection, &_0, &_1);
	zephir_check_call_status();
	RETURN_MM();
}

