
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
#include "kernel/object.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
ZEPHIR_INIT_CLASS(Phalcon_Acl_Exceptions_AccessRuleNotFound)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Acl\\Exceptions, AccessRuleNotFound, phalcon, acl_exceptions_accessrulenotfound, phalcon_acl_exception_ce, phalcon_acl_exceptions_accessrulenotfound_method_entry, 0);

	return SUCCESS;
}

PHP_METHOD(Phalcon_Acl_Exceptions_AccessRuleNotFound, __construct)
{
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval accessName_zv, componentName_zv;
	zend_string *accessName = NULL, *componentName = NULL;

	ZVAL_UNDEF(&accessName_zv);
	ZVAL_UNDEF(&componentName_zv);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR(accessName)
		Z_PARAM_STR(componentName)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&accessName_zv);
	ZVAL_STR_COPY(&accessName_zv, accessName);
	zephir_memory_observe(&componentName_zv);
	ZVAL_STR_COPY(&componentName_zv, componentName);
	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_CONCAT_SVSVS(&_0, "Access '", &accessName_zv, "' does not exist in component '", &componentName_zv, "'");
	ZEPHIR_CALL_PARENT(NULL, phalcon_acl_exceptions_accessrulenotfound_ce, getThis(), "__construct", NULL, 0, &_0);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
}

