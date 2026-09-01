
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
#include "kernel/array.h"
#include "kernel/string.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/object.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
ZEPHIR_INIT_CLASS(Phalcon_Mvc_Model_Hydration_CaseInsensitiveColumnMap)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\Mvc\\Model\\Hydration, CaseInsensitiveColumnMap, phalcon, mvc_model_hydration_caseinsensitivecolumnmap, phalcon_mvc_model_hydration_caseinsensitivecolumnmap_method_entry, 0);

	return SUCCESS;
}

/**
 * Attempts to find key case-insensitively
 */
PHP_METHOD(Phalcon_Mvc_Model_Hydration_CaseInsensitiveColumnMap, caseInsensitiveColumnMap)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *columnMap, columnMap_sub, *key, key_sub, cmKey, _0, *_1, _2, *_3, _4$$3, _5$$3;

	ZVAL_UNDEF(&columnMap_sub);
	ZVAL_UNDEF(&key_sub);
	ZVAL_UNDEF(&cmKey);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$3);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_ZVAL(columnMap)
		Z_PARAM_ZVAL(key)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 2, 0, &columnMap, &key);
	ZEPHIR_INIT_VAR(&_0);
	zephir_array_keys(&_0, columnMap);
	if (Z_TYPE_P(&_0) == IS_STRING) {
		ZEPHIR_INIT_VAR(&_2);
		zephir_string_to_char_array(&_2, &_0);
		_1 = &_2;
	} else {
		_1 = &_0;
	}
	zephir_is_iterable(_1, 0, "phalcon/Mvc/Model/Hydration/CaseInsensitiveColumnMap.zep", 28);
	ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_1), _3)
	{
		ZEPHIR_INIT_NVAR(&cmKey);
		ZVAL_COPY(&cmKey, _3);
		ZEPHIR_INIT_NVAR(&_4$$3);
		zephir_fast_strtolower(&_4$$3, &cmKey);
		ZEPHIR_INIT_NVAR(&_5$$3);
		zephir_fast_strtolower(&_5$$3, key);
		if (ZEPHIR_IS_EQUAL(&_4$$3, &_5$$3)) {
			RETURN_CCTOR(&cmKey);
		}
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&cmKey);
	RETVAL_ZVAL(key, 1, 0);
	RETURN_MM();
}

