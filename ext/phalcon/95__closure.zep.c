
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
#include "kernel/array.h"
#include "kernel/string.h"
#include "kernel/operators.h"
#include "kernel/concat.h"
#include "kernel/object.h"


ZEPHIR_INIT_CLASS(phalcon_95__closure)
{
	ZEPHIR_REGISTER_CLASS(phalcon, 95__closure, phalcon, 95__closure, phalcon_95__closure_method_entry, ZEND_ACC_FINAL_CLASS);

	return SUCCESS;
}

PHP_METHOD(phalcon_95__closure, __invoke)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *matches, matches_sub, _0, _1, _2, _3, _4, _5;

	ZVAL_UNDEF(&matches_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(matches)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &matches);
	ZEPHIR_INIT_VAR(&_0);
	zephir_array_fetch_long(&_1, matches, 0, PH_NOISY | PH_READONLY, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 1581);
	ZVAL_LONG(&_2, 0);
	ZVAL_LONG(&_3, 1);
	ZEPHIR_INIT_NVAR(&_0);
	zephir_substr(&_0, &_1, 0 , 1 , 0);
	ZEPHIR_INIT_VAR(&_4);
	ZVAL_STRING(&_4, "\\");
	if (ZEPHIR_IS_IDENTICAL(&_4, &_0)) {
		ZEPHIR_OBS_NVAR(&_0);
		zephir_array_fetch_long(&_0, matches, 0, PH_NOISY, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 1583);
	} else {
		zephir_array_fetch_long(&_5, matches, 0, PH_NOISY | PH_READONLY, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 1583);
		ZEPHIR_INIT_NVAR(&_0);
		ZEPHIR_CONCAT_SV(&_0, "\\", &_5);
	}
	RETURN_CCTOR(&_0);
}

