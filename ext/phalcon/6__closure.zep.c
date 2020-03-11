
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
#include "kernel/string.h"
#include "kernel/memory.h"
#include "kernel/object.h"


ZEPHIR_INIT_CLASS(phalcon_6__closure) {

	ZEPHIR_REGISTER_CLASS(phalcon, 6__closure, phalcon, 6__closure, phalcon_6__closure_method_entry, ZEND_ACC_FINAL_CLASS);

	return SUCCESS;

}

PHP_METHOD(phalcon_6__closure, __invoke) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *action, action_sub, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&action_sub);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &action);



	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "-");
	zephir_uncamelize(return_value, action, &_0 );
	RETURN_MM();

}

