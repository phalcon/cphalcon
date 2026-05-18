
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
#include "kernel/object.h"


ZEPHIR_INIT_CLASS(phalcon_22__closure)
{
	ZEPHIR_REGISTER_CLASS(phalcon, 22__closure, phalcon, 22__closure, phalcon_22__closure_method_entry, ZEND_ACC_FINAL_CLASS);

	zend_declare_property_null(phalcon_22__closure_ce, SL("schema"), ZEND_ACC_PUBLIC|ZEND_ACC_STATIC);
	zend_declare_property_null(phalcon_22__closure_ce, SL("locator"), ZEND_ACC_PUBLIC|ZEND_ACC_STATIC);
	return SUCCESS;
}

PHP_METHOD(phalcon_22__closure, __invoke)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval schema, locator, *e, e_sub, _0;

	ZVAL_UNDEF(&schema);
	ZVAL_UNDEF(&locator);
	ZVAL_UNDEF(&e_sub);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(e)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_read_static_property_ce(&locator, phalcon_22__closure_ce, SL("locator"), PH_NOISY_CC);
	zephir_read_static_property_ce(&schema, phalcon_22__closure_ce, SL("schema"), PH_NOISY_CC);
	zephir_fetch_params(1, 1, 0, &e);
	ZEPHIR_INIT_VAR(&_0);
	object_init_ex(&_0, phalcon_forms_form_ce);
	ZEPHIR_CALL_METHOD(NULL, &_0, "__construct", NULL, 364, e);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(&_0, "load", NULL, 365, &schema, &locator);
	zephir_check_call_status();
	RETURN_MM();
}

