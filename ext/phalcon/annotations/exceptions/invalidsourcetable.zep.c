
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/operators.h"
#include "kernel/variables.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/concat.h"
#include "kernel/object.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */
ZEPHIR_INIT_CLASS(Phalcon_Annotations_Exceptions_InvalidSourceTable)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Annotations\\Exceptions, InvalidSourceTable, phalcon, annotations_exceptions_invalidsourcetable, phalcon_annotations_exception_ce, phalcon_annotations_exceptions_invalidsourcetable_method_entry, 0);

	return SUCCESS;
}

PHP_METHOD(Phalcon_Annotations_Exceptions_InvalidSourceTable, __construct)
{
	zend_bool _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *table, table_sub, value, _1;

	ZVAL_UNDEF(&table_sub);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_1);
	ZEND_TLS zephir_method_cache _zephir_call_cache[1];
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(table)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &table);
	_0 = zephir_is_scalar(table);
	if (!(_0)) {
		_0 = Z_TYPE_P(table) == IS_NULL;
	}
	if (_0) {
		ZEPHIR_INIT_VAR(&value);
		zephir_var_export_ex(&value, table);
	} else {
		ZEPHIR_CALL_FUNCTION(&value, "get_debug_type", NULL, 110, table);
		zephir_check_call_status();
	}
	ZEPHIR_INIT_VAR(&_1);
	ZEPHIR_CONCAT_SV(&_1, "Source table name must be a non-empty string; received: ", &value);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CALL_PARENT_CACHED(NULL, phalcon_annotations_exceptions_invalidsourcetable_ce, getThis(), "__construct", &_zephir_call_cache[0], &_1);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
}

