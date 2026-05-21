
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
#include "kernel/fcall.h"
#include "kernel/concat.h"
#include "kernel/memory.h"
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
ZEPHIR_INIT_CLASS(Phalcon_Forms_Exceptions_SchemaEntryNotArray)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Forms\\Exceptions, SchemaEntryNotArray, phalcon, forms_exceptions_schemaentrynotarray, phalcon_forms_exception_ce, phalcon_forms_exceptions_schemaentrynotarray_method_entry, 0);

	return SUCCESS;
}

PHP_METHOD(Phalcon_Forms_Exceptions_SchemaEntryNotArray, __construct)
{
	zval _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *index_param = NULL, _0;
	zend_long index, ZEPHIR_LAST_CALL_STATUS;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(index)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &index_param);
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_LONG(&_0, index);
	ZEPHIR_INIT_VAR(&_1);
	ZEPHIR_CONCAT_SVS(&_1, "Form schema definition at index ", &_0, " must be an array");
	ZEPHIR_CALL_PARENT(NULL, phalcon_forms_exceptions_schemaentrynotarray_ce, getThis(), "__construct", NULL, 0, &_1);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
}

