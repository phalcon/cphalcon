
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


ZEPHIR_INIT_CLASS(phalcon_91__closure)
{
	ZEPHIR_REGISTER_CLASS(phalcon, 91__closure, phalcon, 91__closure, phalcon_91__closure_method_entry, ZEND_ACC_FINAL_CLASS);

	zend_declare_property_null(phalcon_91__closure_ce, SL("rawValue"), ZEND_ACC_PUBLIC);
	return SUCCESS;
}

PHP_METHOD(phalcon_91__closure, __invoke)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval rawValue, *matches, matches_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&rawValue);
	ZVAL_UNDEF(&matches_sub);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(matches)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&rawValue);
	zephir_read_property(&rawValue, this_ptr, SL("rawValue"), PH_NOISY_CC);
	zephir_fetch_params(1, 1, 0, &matches);
	RETVAL_ZVAL(&rawValue, 1, 0);
	RETURN_MM();
}

