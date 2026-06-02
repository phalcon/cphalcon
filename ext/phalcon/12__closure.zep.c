
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


ZEPHIR_INIT_CLASS(phalcon_12__closure)
{
	ZEPHIR_REGISTER_CLASS(phalcon, 12__closure, phalcon, 12__closure, phalcon_12__closure_method_entry, ZEND_ACC_FINAL_CLASS);

	zend_declare_property_null(phalcon_12__closure_ce, SL("ioc"), ZEND_ACC_PUBLIC|ZEND_ACC_STATIC);
	return SUCCESS;
}

PHP_METHOD(phalcon_12__closure, __invoke)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval ioc, id, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&ioc);
	ZVAL_UNDEF(&id);
	ZVAL_UNDEF(&_0);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_read_static_property_ce(&ioc, phalcon_12__closure_ce, SL("ioc"), PH_NOISY_CC);

	zephir_read_property(&_0, this_ptr, ZEND_STRL("id"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&id, this_ptr, "resolveargument", NULL, 0, &ioc, &_0);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(&ioc, "new", NULL, 0, &id);
	zephir_check_call_status();
	RETURN_MM();
}

