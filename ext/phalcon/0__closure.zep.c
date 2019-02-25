
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
#include "kernel/memory.h"


ZEPHIR_INIT_CLASS(phalcon_0__closure) {

	ZEPHIR_REGISTER_CLASS(phalcon, 0__closure, phalcon, 0__closure, phalcon_0__closure_method_entry, ZEND_ACC_FINAL_CLASS);

	return SUCCESS;

}

PHP_METHOD(phalcon_0__closure, __invoke) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *escaper, escaper_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&escaper_sub);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &escaper);



	object_init_ex(return_value, phalcon_html_helper_anchor_ce);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 459, escaper);
	zephir_check_call_status();
	RETURN_MM();

}

