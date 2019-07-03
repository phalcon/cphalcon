
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


ZEPHIR_INIT_CLASS(phalcon_1__closure) {

	ZEPHIR_REGISTER_CLASS(phalcon, 1__closure, phalcon, 1__closure, phalcon_1__closure_method_entry, ZEND_ACC_FINAL_CLASS);

	return SUCCESS;

}

PHP_METHOD(phalcon_1__closure, __invoke) {

	zend_bool _0;
	zval *element, element_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&element_sub);

	zephir_fetch_params(0, 1, 0, &element);



	_0 = Z_TYPE_P(element) == IS_LONG;
	if (!(_0)) {
		_0 = Z_TYPE_P(element) == IS_STRING;
	}
	RETURN_BOOL(_0);

}

