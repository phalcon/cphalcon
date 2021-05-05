
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


ZEPHIR_INIT_CLASS(phalcon_16__closure)
{
	ZEPHIR_REGISTER_CLASS(phalcon, 16__closure, phalcon, 16__closure, phalcon_16__closure_method_entry, ZEND_ACC_FINAL_CLASS);

	return SUCCESS;
}

PHP_METHOD(phalcon_16__closure, __invoke)
{
	zend_bool _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *element, element_sub, _0, _2;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&element_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(element)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &element);


	ZEPHIR_OBS_VAR(&_0);
	zephir_array_fetch_long(&_0, element, 0, PH_NOISY, "phalcon/Validation.zep", 80);
	_1 = Z_TYPE_P(&_0) != IS_ARRAY;
	if (!(_1)) {
		ZEPHIR_OBS_VAR(&_2);
		zephir_array_fetch_long(&_2, element, 1, PH_NOISY, "phalcon/Validation.zep", 80);
		_1 = !(zephir_instance_of_ev(&_2, phalcon_validation_abstractcombinedfieldsvalidator_ce));
	}
	RETURN_MM_BOOL(_1);
}

