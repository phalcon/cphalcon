
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
#include "kernel/array.h"
#include "kernel/object.h"


ZEPHIR_INIT_CLASS(phalcon_27__closure) {

	ZEPHIR_REGISTER_CLASS(phalcon, 27__closure, phalcon, 27__closure, phalcon_27__closure_method_entry, ZEND_ACC_FINAL_CLASS);

	return SUCCESS;

}

PHP_METHOD(phalcon_27__closure, __invoke) {

	zend_bool _1;
	zval *element, element_sub, _0, _2;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&element_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &element);



	ZEPHIR_OBS_VAR(&_0);
	zephir_array_fetch_long(&_0, element, 0, PH_NOISY, "phalcon/validation.zep", 57 TSRMLS_CC);
	_1 = Z_TYPE_P(&_0) == IS_ARRAY;
	if (_1) {
		ZEPHIR_OBS_VAR(&_2);
		zephir_array_fetch_long(&_2, element, 1, PH_NOISY, "phalcon/validation.zep", 57 TSRMLS_CC);
		_1 = zephir_instance_of_ev(&_2, phalcon_validation_combinedfieldsvalidator_ce TSRMLS_CC);
	}
	RETURN_MM_BOOL(_1);

}

