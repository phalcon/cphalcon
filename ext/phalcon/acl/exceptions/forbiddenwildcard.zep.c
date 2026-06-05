
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


ZEPHIR_INIT_CLASS(Phalcon_Acl_Exceptions_ForbiddenWildcard)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Acl\\Exceptions, ForbiddenWildcard, phalcon, acl_exceptions_forbiddenwildcard, phalcon_acl_exception_ce, phalcon_acl_exceptions_forbiddenwildcard_method_entry, 0);

	return SUCCESS;
}

PHP_METHOD(Phalcon_Acl_Exceptions_ForbiddenWildcard, __construct)
{
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval elementType_zv;
	zend_string *elementType = NULL;

	ZVAL_UNDEF(&elementType_zv);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(elementType)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&elementType_zv);
	ZVAL_STR_COPY(&elementType_zv, elementType);
	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_CONCAT_SVS(&_0, "The ", &elementType_zv, " name cannot be '*'");
	ZEPHIR_CALL_PARENT(NULL, phalcon_acl_exceptions_forbiddenwildcard_ce, getThis(), "__construct", NULL, 0, &_0);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
}

