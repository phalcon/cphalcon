
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
#include "kernel/operators.h"
#include "kernel/object.h"
#include "kernel/memory.h"


ZEPHIR_INIT_CLASS(phalcon_1__closure) {

	ZEPHIR_REGISTER_CLASS(phalcon, 1__closure, phalcon, 1__closure, phalcon_1__closure_method_entry, ZEND_ACC_FINAL_CLASS);

	return SUCCESS;

}

PHP_METHOD(phalcon_1__closure, __invoke) {

	zval *number, number_sub, *message, message_sub, *file, file_sub, *line, line_sub, *context, context_sub, __$true, __$false;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&number_sub);
	ZVAL_UNDEF(&message_sub);
	ZVAL_UNDEF(&file_sub);
	ZVAL_UNDEF(&line_sub);
	ZVAL_UNDEF(&context_sub);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);

	zephir_fetch_params_without_memory_grow(5, 0, &number, &message, &file, &line, &context);



	if (ZEPHIR_IS_LONG_IDENTICAL(number, 2)) {
		if (1) {
			zephir_update_property_zval(this_ptr, SL("warning"), &__$true);
		} else {
			zephir_update_property_zval(this_ptr, SL("warning"), &__$false);
		}
	}

}

