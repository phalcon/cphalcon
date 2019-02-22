
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
#include "kernel/array.h"
#include "kernel/fcall.h"
#include "kernel/memory.h"


ZEPHIR_INIT_CLASS(phalcon_26__closure) {

	ZEPHIR_REGISTER_CLASS(phalcon, 26__closure, phalcon, 26__closure, phalcon_26__closure_method_entry, ZEND_ACC_FINAL_CLASS);

	return SUCCESS;

}

PHP_METHOD(phalcon_26__closure, __invoke) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *matches, matches_sub, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&matches_sub);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &matches);



	zephir_array_fetch_long(&_0, matches, 0, PH_NOISY | PH_READONLY, "phalcon/http/message/uri.zep", 689 TSRMLS_CC);
	ZEPHIR_RETURN_CALL_FUNCTION("urlencode", NULL, 511, &_0);
	zephir_check_call_status();
	RETURN_MM();

}

