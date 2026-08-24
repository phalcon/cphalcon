
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
#include "kernel/array.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/object.h"


ZEPHIR_INIT_CLASS(phalcon_89__closure)
{
	ZEPHIR_REGISTER_CLASS(phalcon, 89__closure, phalcon, 89__closure, phalcon_89__closure_method_entry, ZEND_ACC_FINAL_CLASS);

	return SUCCESS;
}

PHP_METHOD(phalcon_89__closure, __invoke)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *matches, matches_sub, _0, _1, _2;

	ZVAL_UNDEF(&matches_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(matches)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &matches);
	zephir_array_fetch_long(&_0, matches, 0, PH_NOISY | PH_READONLY, "phalcon/Logger/Formatter/Line.zep", 75);
	ZEPHIR_CALL_FUNCTION(&_1, "ord", NULL, 0, &_0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "\\x%02X");
	ZEPHIR_RETURN_CALL_FUNCTION("sprintf", NULL, 146, &_2, &_1);
	zephir_check_call_status();
	RETURN_MM();
}

