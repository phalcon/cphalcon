
#ifdef HAVE_CONFIG_H
#include "../../../../../ext_config.h"
#endif

#include <php.h>
#include "../../../../../php_ext.h"
#include "../../../../../ext.h"

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
ZEPHIR_INIT_CLASS(Phalcon_Mvc_Model_Query_Exceptions_AmbiguousJoinRelation)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Mvc\\Model\\Query\\Exceptions, AmbiguousJoinRelation, phalcon, mvc_model_query_exceptions_ambiguousjoinrelation, phalcon_mvc_model_exception_ce, phalcon_mvc_model_query_exceptions_ambiguousjoinrelation_method_entry, 0);

	return SUCCESS;
}

PHP_METHOD(Phalcon_Mvc_Model_Query_Exceptions_AmbiguousJoinRelation, __construct)
{
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval from_zv, join_zv, phql_zv;
	zend_string *from = NULL, *join = NULL, *phql = NULL;

	ZVAL_UNDEF(&from_zv);
	ZVAL_UNDEF(&join_zv);
	ZVAL_UNDEF(&phql_zv);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_STR(from)
		Z_PARAM_STR(join)
		Z_PARAM_STR(phql)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&from_zv);
	ZVAL_STR_COPY(&from_zv, from);
	zephir_memory_observe(&join_zv);
	ZVAL_STR_COPY(&join_zv, join);
	zephir_memory_observe(&phql_zv);
	ZVAL_STR_COPY(&phql_zv, phql);
	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_CONCAT_SVSVSV(&_0, "There is more than one relation between models '", &from_zv, "' and '", &join_zv, "', the join must be done using an alias, when preparing: ", &phql_zv);
	ZEPHIR_CALL_PARENT(NULL, phalcon_mvc_model_query_exceptions_ambiguousjoinrelation_ce, getThis(), "__construct", NULL, 0, &_0);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
}

