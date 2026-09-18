
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


ZEPHIR_INIT_CLASS(phalcon_59__closure)
{
	ZEPHIR_REGISTER_CLASS(phalcon, 59__closure, phalcon, 59__closure, phalcon_59__closure_method_entry, ZEND_ACC_FINAL_CLASS);

	zend_declare_property_null(phalcon_59__closure_ce, SL("escaper"), ZEND_ACC_PUBLIC);
	zend_declare_property_null(phalcon_59__closure_ce, SL("__$zephir_this"), ZEND_ACC_PUBLIC);
	return SUCCESS;
}

PHP_METHOD(phalcon_59__closure, __invoke)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval escaper, __$zephir_this, _0, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&escaper);
	ZVAL_UNDEF(&__$zephir_this);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_read_property(&__$zephir_this, this_ptr, SL("__$zephir_this"), PH_NOISY_CC | PH_READONLY);
	zephir_memory_observe(&escaper);
	zephir_read_property(&escaper, this_ptr, SL("escaper"), PH_NOISY_CC);
	this_ptr = &__$zephir_this;

	object_init_ex(return_value, phalcon_html_helper_input_generic_ce);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "doctype");
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "newinstance", NULL, 0, &_1);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 0, &escaper, &_0);
	zephir_check_call_status();
	RETURN_MM();
}

