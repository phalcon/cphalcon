
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
ZEPHIR_INIT_CLASS(Phalcon_Mvc_Model_Exceptions_RelationAliasMustBeString)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Mvc\\Model\\Exceptions, RelationAliasMustBeString, phalcon, mvc_model_exceptions_relationaliasmustbestring, phalcon_mvc_model_exception_ce, phalcon_mvc_model_exceptions_relationaliasmustbestring_method_entry, 0);

	return SUCCESS;
}

PHP_METHOD(Phalcon_Mvc_Model_Exceptions_RelationAliasMustBeString, __construct)
{
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval relationType_zv, entityName_zv, referencedEntity_zv;
	zend_string *relationType = NULL, *entityName = NULL, *referencedEntity = NULL;

	ZVAL_UNDEF(&relationType_zv);
	ZVAL_UNDEF(&entityName_zv);
	ZVAL_UNDEF(&referencedEntity_zv);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_STR(relationType)
		Z_PARAM_STR(entityName)
		Z_PARAM_STR(referencedEntity)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&relationType_zv);
	ZVAL_STR_COPY(&relationType_zv, relationType);
	zephir_memory_observe(&entityName_zv);
	ZVAL_STR_COPY(&entityName_zv, entityName);
	zephir_memory_observe(&referencedEntity_zv);
	ZVAL_STR_COPY(&referencedEntity_zv, referencedEntity);
	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_CONCAT_SVSVSVS(&_0, "Relation alias must be a string in the ", &relationType_zv, " relation of model '", &entityName_zv, "' with Reference Model '", &referencedEntity_zv, "'");
	ZEPHIR_CALL_PARENT(NULL, phalcon_mvc_model_exceptions_relationaliasmustbestring_ce, getThis(), "__construct", NULL, 0, &_0);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
}

