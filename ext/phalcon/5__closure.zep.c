
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
#include "kernel/fcall.h"
#include "kernel/memory.h"
#include "kernel/object.h"


ZEPHIR_INIT_CLASS(phalcon_5__closure)
{
	ZEPHIR_REGISTER_CLASS(phalcon, 5__closure, phalcon, 5__closure, phalcon_5__closure_method_entry, ZEND_ACC_FINAL_CLASS);

	zend_declare_property_null(phalcon_5__closure_ce, SL("dispatcher"), ZEND_ACC_PUBLIC|ZEND_ACC_STATIC);
	return SUCCESS;
}

PHP_METHOD(phalcon_5__closure, __invoke)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval dispatcher, *target, target_sub;

	ZVAL_UNDEF(&dispatcher);
	ZVAL_UNDEF(&target_sub);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(target)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_read_static_property_ce(&dispatcher, phalcon_5__closure_ce, SL("dispatcher"), PH_NOISY_CC);
	zephir_fetch_params(1, 1, 0, &target);
	ZEPHIR_CALL_METHOD(NULL, &dispatcher, "forward", NULL, 0, target);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
}

