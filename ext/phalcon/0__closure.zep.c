
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
#include "kernel/string.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"


ZEPHIR_INIT_CLASS(phalcon_0__closure) {

	ZEPHIR_REGISTER_CLASS(phalcon, 0__closure, phalcon, 0__closure, phalcon_0__closure_method_entry, ZEND_ACC_FINAL_CLASS);

	return SUCCESS;

}

PHP_METHOD(phalcon_0__closure, __invoke) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *matches, *words, *_0, *_1, *_2 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &matches);



	zephir_array_fetch_long(&_0, matches, 1, PH_NOISY | PH_READONLY, "phalcon/text.zep", 272 TSRMLS_CC);
	ZEPHIR_INIT_VAR(words);
	zephir_fast_explode_str(words, SL("|"), _0, LONG_MAX TSRMLS_CC);
	ZEPHIR_CALL_FUNCTION(&_2, "array_rand", NULL, 441, words);
	zephir_check_call_status();
	zephir_array_fetch(&_1, words, _2, PH_NOISY | PH_READONLY, "phalcon/text.zep", 273 TSRMLS_CC);
	RETURN_CTOR(_1);

}

