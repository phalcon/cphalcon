
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


ZEPHIR_INIT_CLASS(phalcon_12__closure)
{
	ZEPHIR_REGISTER_CLASS(phalcon, 12__closure, phalcon, 12__closure, phalcon_12__closure_method_entry, ZEND_ACC_FINAL_CLASS);

	return SUCCESS;
}

PHP_METHOD(phalcon_12__closure, __invoke)
{
	zend_bool _0;
	zval *element, element_sub;

	ZVAL_UNDEF(&element_sub);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(element)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &element);
	_0 = Z_TYPE_P(element) == IS_LONG;
	if (!(_0)) {
		_0 = Z_TYPE_P(element) == IS_STRING;
	}
	RETURN_BOOL(_0);
}

