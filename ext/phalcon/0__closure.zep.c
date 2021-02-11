
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
#include "kernel/object.h"


ZEPHIR_INIT_CLASS(phalcon_0__closure) {

	ZEPHIR_REGISTER_CLASS(phalcon, 0__closure, phalcon, 0__closure, phalcon_0__closure_method_entry, ZEND_ACC_FINAL_CLASS);

	return SUCCESS;

}

PHP_METHOD(phalcon_0__closure, __invoke) {

	zval *number, number_sub, *message, message_sub, *file, file_sub, *line, line_sub, __$true;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&number_sub);
	ZVAL_UNDEF(&message_sub);
	ZVAL_UNDEF(&file_sub);
	ZVAL_UNDEF(&line_sub);
	ZVAL_BOOL(&__$true, 1);

	zephir_fetch_params_without_memory_grow(4, 0, &number, &message, &file, &line);



	ZEPHIR_GLOBAL(warning).enable = zend_is_true(&__$true);

}

