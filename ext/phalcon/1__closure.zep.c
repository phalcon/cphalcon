
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
#include "kernel/fcall.h"
#include "kernel/object.h"
#include "kernel/memory.h"


ZEPHIR_INIT_CLASS(phalcon_1__closure)
{
	ZEPHIR_REGISTER_CLASS(phalcon, 1__closure, phalcon, 1__closure, phalcon_1__closure_method_entry, ZEND_ACC_FINAL_CLASS);

	zend_declare_property_null(phalcon_1__closure_ce, SL("serializer"), ZEND_ACC_PUBLIC|ZEND_ACC_STATIC);
	zend_declare_property_null(phalcon_1__closure_ce, SL("defaultValue"), ZEND_ACC_PUBLIC|ZEND_ACC_STATIC);
	return SUCCESS;
}

PHP_METHOD(phalcon_1__closure, __invoke)
{
	zend_bool _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval serializer, defaultValue, *element, element_sub, _1;

	ZVAL_UNDEF(&serializer);
	ZVAL_UNDEF(&defaultValue);
	ZVAL_UNDEF(&element_sub);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(element)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_read_static_property_ce(&defaultValue, phalcon_1__closure_ce, SL("defaultValue"), PH_NOISY_CC);
	zephir_read_static_property_ce(&serializer, phalcon_1__closure_ce, SL("serializer"), PH_NOISY_CC);
	zephir_fetch_params(1, 1, 0, &element);
	if (ZEPHIR_IS_FALSE_IDENTICAL(element)) {
		RETVAL_ZVAL(&defaultValue, 1, 0);
		RETURN_MM();
	}
	ZEPHIR_CALL_METHOD(NULL, &serializer, "unserialize", NULL, 0, element);
	zephir_check_call_status();
	_0 = 1 == (zephir_method_exists_ex(&serializer, ZEND_STRL("issuccess")) == SUCCESS);
	if (_0) {
		ZEPHIR_CALL_METHOD(&_1, &serializer, "issuccess", NULL, 0);
		zephir_check_call_status();
		_0 = !ZEPHIR_IS_TRUE_IDENTICAL(&_1);
	}
	if (_0) {
		RETVAL_ZVAL(&defaultValue, 1, 0);
		RETURN_MM();
	}
	ZEPHIR_RETURN_CALL_METHOD(&serializer, "getdata", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();
}

