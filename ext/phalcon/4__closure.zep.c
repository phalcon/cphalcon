
#ifdef HAVE_CONFIG_H
#include "../ext_config.h"
#endif

#include <php.h>
#include "../php_ext.h"
#include "../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/array.h"
#include "kernel/object.h"


ZEPHIR_INIT_CLASS(phalcon_4__closure)
{
	ZEPHIR_REGISTER_CLASS(phalcon, 4__closure, phalcon, 4__closure, phalcon_4__closure_method_entry, ZEND_ACC_FINAL_CLASS);

	return SUCCESS;
}

PHP_METHOD(phalcon_4__closure, __invoke)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *container, container_sub, adapters, noop, _0;

	ZVAL_UNDEF(&container_sub);
	ZVAL_UNDEF(&adapters);
	ZVAL_UNDEF(&noop);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(container)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &container);
	ZEPHIR_INIT_VAR(&noop);
	object_init_ex(&noop, phalcon_logger_adapter_noop_ce);
	if (zephir_has_constructor(&noop)) {
		ZEPHIR_CALL_METHOD(NULL, &noop, "__construct", NULL, 0);
		zephir_check_call_status();
	}

	ZEPHIR_INIT_VAR(&adapters);
	zephir_create_array(&adapters, 1, 0);
	zephir_array_update_string(&adapters, SL("main"), &noop, PH_COPY | PH_SEPARATE);
	object_init_ex(return_value, phalcon_logger_logger_ce);
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "adr");
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 0, &_0, &adapters);
	zephir_check_call_status();
	RETURN_MM();
}

