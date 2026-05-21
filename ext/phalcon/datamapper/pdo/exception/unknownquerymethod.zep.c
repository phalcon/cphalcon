
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
#include "ext/spl/spl_exceptions.h"
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
ZEPHIR_INIT_CLASS(Phalcon_DataMapper_Pdo_Exception_UnknownQueryMethod)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\DataMapper\\Pdo\\Exception, UnknownQueryMethod, phalcon, datamapper_pdo_exception_unknownquerymethod, spl_ce_BadMethodCallException, phalcon_datamapper_pdo_exception_unknownquerymethod_method_entry, 0);

	return SUCCESS;
}

PHP_METHOD(Phalcon_DataMapper_Pdo_Exception_UnknownQueryMethod, __construct)
{
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval method_zv;
	zend_string *method = NULL;

	ZVAL_UNDEF(&method_zv);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(method)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&method_zv);
	ZVAL_STR_COPY(&method_zv, method);
	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_CONCAT_SVS(&_0, "Unknown method: [", &method_zv, "]");
	ZEPHIR_CALL_PARENT(NULL, phalcon_datamapper_pdo_exception_unknownquerymethod_ce, getThis(), "__construct", NULL, 0, &_0);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
}

