
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
#include "kernel/fcall.h"
#include "kernel/object.h"
#include "kernel/memory.h"


ZEPHIR_INIT_CLASS(phalcon_39__closure)
{
	ZEPHIR_REGISTER_CLASS(phalcon, 39__closure, phalcon, 39__closure, phalcon_39__closure_method_entry, ZEND_ACC_FINAL_CLASS);

	zend_declare_property_null(phalcon_39__closure_ce, SL("escaper"), ZEND_ACC_PUBLIC);
	zend_declare_property_null(phalcon_39__closure_ce, SL("url"), ZEND_ACC_PUBLIC);
	return SUCCESS;
}

PHP_METHOD(phalcon_39__closure, __invoke)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval escaper, url;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&escaper);
	ZVAL_UNDEF(&url);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&url);
	zephir_read_property(&url, this_ptr, SL("url"), PH_NOISY_CC);
	zephir_memory_observe(&escaper);
	zephir_read_property(&escaper, this_ptr, SL("escaper"), PH_NOISY_CC);

	object_init_ex(return_value, phalcon_html_helper_breadcrumbs_ce);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 0, &escaper, &url);
	zephir_check_call_status();
	RETURN_MM();
}

