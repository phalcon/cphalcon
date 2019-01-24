
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


ZEPHIR_INIT_CLASS(phalcon_25__closure) {

	ZEPHIR_REGISTER_CLASS(phalcon, 25__closure, phalcon, 25__closure, phalcon_25__closure_method_entry, ZEND_ACC_FINAL_CLASS);

	return SUCCESS;

}

PHP_METHOD(phalcon_25__closure, __invoke) {

	zval *file, file_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&file_sub);

	zephir_fetch_params(0, 1, 0, &file);



	RETURN_BOOL(1);

}

