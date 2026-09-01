
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


ZEPHIR_INIT_CLASS(phalcon_10__closure)
{
	ZEPHIR_REGISTER_CLASS(phalcon, 10__closure, phalcon, 10__closure, phalcon_10__closure_method_entry, ZEND_ACC_FINAL_CLASS);

	zend_declare_property_null(phalcon_10__closure_ce, SL("serviceName"), ZEND_ACC_PUBLIC);
	zend_declare_property_null(phalcon_10__closure_ce, SL("__$zephir_this"), ZEND_ACC_PUBLIC);
	return SUCCESS;
}

PHP_METHOD(phalcon_10__closure, __invoke)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval serviceName, __$zephir_this;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&serviceName);
	ZVAL_UNDEF(&__$zephir_this);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_read_property(&__$zephir_this, this_ptr, SL("__$zephir_this"), PH_NOISY_CC | PH_READONLY);
	zephir_memory_observe(&serviceName);
	zephir_read_property(&serviceName, this_ptr, SL("serviceName"), PH_NOISY_CC);
	this_ptr = &__$zephir_this;

	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "new", NULL, 0, &serviceName);
	zephir_check_call_status();
	RETURN_MM();
}

