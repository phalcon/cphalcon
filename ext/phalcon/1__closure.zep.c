
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


ZEPHIR_INIT_CLASS(phalcon_1__closure) {

	ZEPHIR_REGISTER_CLASS(phalcon, 1__closure, phalcon, 1__closure, phalcon_1__closure_method_entry, ZEND_ACC_FINAL_CLASS);

	return SUCCESS;

}

PHP_METHOD(phalcon_1__closure, __invoke) {

	zend_bool _1;
	zval *element, *_0, *_2;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &element);



	ZEPHIR_OBS_VAR(_0);
	zephir_array_fetch_long(&_0, element, 0, PH_NOISY, "phalcon/validation.zep", 62 TSRMLS_CC);
	_1 = Z_TYPE_P(_0) != IS_ARRAY;
	if (!(_1)) {
		ZEPHIR_OBS_VAR(_2);
		zephir_array_fetch_long(&_2, element, 1, PH_NOISY, "phalcon/validation.zep", 62 TSRMLS_CC);
		_1 = !(zephir_is_instance_of(_2, SL("phalcon\\CombinedFieldsValidator") TSRMLS_CC));
	}
	RETURN_MM_BOOL(_1);

}

