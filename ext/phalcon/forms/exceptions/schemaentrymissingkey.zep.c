
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
ZEPHIR_INIT_CLASS(Phalcon_Forms_Exceptions_SchemaEntryMissingKey)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Forms\\Exceptions, SchemaEntryMissingKey, phalcon, forms_exceptions_schemaentrymissingkey, phalcon_forms_exception_ce, phalcon_forms_exceptions_schemaentrymissingkey_method_entry, 0);

	return SUCCESS;
}

PHP_METHOD(Phalcon_Forms_Exceptions_SchemaEntryMissingKey, __construct)
{
	zval _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_string *key = NULL;
	zval *index_param = NULL, key_zv, _0;
	zend_long index, ZEPHIR_LAST_CALL_STATUS;

	ZVAL_UNDEF(&key_zv);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(index)
		Z_PARAM_STR(key)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	index_param = ZEND_CALL_ARG(execute_data, 1);
	zephir_memory_observe(&key_zv);
	ZVAL_STR_COPY(&key_zv, key);
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_LONG(&_0, index);
	ZEPHIR_INIT_VAR(&_1);
	ZEPHIR_CONCAT_SVSVS(&_1, "Form schema definition at index ", &_0, " is missing required key \"", &key_zv, "\"");
	ZEPHIR_CALL_PARENT(NULL, phalcon_forms_exceptions_schemaentrymissingkey_ce, getThis(), "__construct", NULL, 0, &_1);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
}

