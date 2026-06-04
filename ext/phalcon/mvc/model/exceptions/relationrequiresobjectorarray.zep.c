
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
#include "kernel/concat.h"
#include "kernel/memory.h"
#include "kernel/object.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
ZEPHIR_INIT_CLASS(Phalcon_Mvc_Model_Exceptions_RelationRequiresObjectOrArray)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Mvc\\Model\\Exceptions, RelationRequiresObjectOrArray, phalcon, mvc_model_exceptions_relationrequiresobjectorarray, phalcon_mvc_model_exception_ce, phalcon_mvc_model_exceptions_relationrequiresobjectorarray_method_entry, 0);

	return SUCCESS;
}

PHP_METHOD(Phalcon_Mvc_Model_Exceptions_RelationRequiresObjectOrArray, __construct)
{
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval className_zv, relationName_zv;
	zend_string *className = NULL, *relationName = NULL;

	ZVAL_UNDEF(&className_zv);
	ZVAL_UNDEF(&relationName_zv);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR(className)
		Z_PARAM_STR(relationName)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&className_zv);
	ZVAL_STR_COPY(&className_zv, className);
	zephir_memory_observe(&relationName_zv);
	ZVAL_STR_COPY(&relationName_zv, relationName);
	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_CONCAT_SVSV(&_0, "Only objects/arrays can be stored as part of has-many/has-one/has-one-through/has-many-to-many relations on model ", &className_zv, " on Relation ", &relationName_zv);
	ZEPHIR_CALL_PARENT(NULL, phalcon_mvc_model_exceptions_relationrequiresobjectorarray_ce, getThis(), "__construct", NULL, 0, &_0);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
}

