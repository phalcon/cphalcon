
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
#include "kernel/object.h"
#include "kernel/memory.h"


ZEPHIR_INIT_CLASS(phalcon_0__closure) {

	ZEPHIR_REGISTER_CLASS(phalcon, 0__closure, phalcon, 0__closure, phalcon_0__closure_method_entry, ZEND_ACC_FINAL_CLASS);

	return SUCCESS;

}

PHP_METHOD(phalcon_0__closure, __invoke) {

	zval *error, error_sub, __$true, __$false;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&error_sub);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);

	zephir_fetch_params_without_memory_grow(1, 0, &error);



	if (1) {
		zephir_update_property_zval(this_ptr, SL("warning"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, SL("warning"), &__$false);
	}

}

