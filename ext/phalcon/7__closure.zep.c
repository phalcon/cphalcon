
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
#include "kernel/object.h"
#include "kernel/memory.h"


ZEPHIR_INIT_CLASS(phalcon_7__closure)
{
	ZEPHIR_REGISTER_CLASS(phalcon, 7__closure, phalcon, 7__closure, phalcon_7__closure_method_entry, ZEND_ACC_FINAL_CLASS);

	zend_declare_property_null(phalcon_7__closure_ce, SL("name"), ZEND_ACC_PUBLIC|ZEND_ACC_STATIC);
	return SUCCESS;
}

PHP_METHOD(phalcon_7__closure, __invoke)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_read_static_property_ce(&name, phalcon_7__closure_ce, SL("name"), PH_NOISY_CC);

	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "new", NULL, 0, &name);
	zephir_check_call_status();
	RETURN_MM();
}

