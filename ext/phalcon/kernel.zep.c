
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
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/operators.h"
#include "kernel/memory.h"


/**
 * Phalcon\Kernel
 *
 * This class allows to change the internal behavior of the framework in runtime
 */
ZEPHIR_INIT_CLASS(Phalcon_Kernel) {

	ZEPHIR_REGISTER_CLASS(Phalcon, Kernel, phalcon, kernel, phalcon_kernel_method_entry, 0);

	return SUCCESS;

}

/**
 * Produces a pre-computed hash key based on a string. This function produces different numbers in 32bit/64bit processors
 *
 * @param string key
 * @return string
 */
PHP_METHOD(Phalcon_Kernel, preComputeHashKey) {

	zval *key_param = NULL;
	zval *key = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &key_param);

	if (unlikely(Z_TYPE_P(key_param) != IS_STRING && Z_TYPE_P(key_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'key' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(key_param) == IS_STRING)) {
		zephir_get_strval(key, key_param);
	} else {
		ZEPHIR_INIT_VAR(key);
		ZVAL_EMPTY_STRING(key);
	}


	

		{

		char *arKey = Z_STRVAL_P(key), *strKey;
		int nKeyLength = strlen(arKey);
		register ulong hash = 5381;

		nKeyLength++;

		/* variant with the hash unrolled eight times */
		for (; nKeyLength >= 8; nKeyLength -= 8) {
			hash = ((hash << 5) + hash) + *arKey++;
			hash = ((hash << 5) + hash) + *arKey++;
			hash = ((hash << 5) + hash) + *arKey++;
			hash = ((hash << 5) + hash) + *arKey++;
			hash = ((hash << 5) + hash) + *arKey++;
			hash = ((hash << 5) + hash) + *arKey++;
			hash = ((hash << 5) + hash) + *arKey++;
			hash = ((hash << 5) + hash) + *arKey++;
		}

		switch (nKeyLength) {
			case 7: hash = ((hash << 5) + hash) + *arKey++;
			/* no break */
			case 6: hash = ((hash << 5) + hash) + *arKey++;
			/* no break */
			case 5: hash = ((hash << 5) + hash) + *arKey++;
			/* no break */
			case 4: hash = ((hash << 5) + hash) + *arKey++;
			/* no break */
			case 3: hash = ((hash << 5) + hash) + *arKey++;
			/* no break */
			case 2: hash = ((hash << 5) + hash) + *arKey++;
			/* no break */
			case 1: hash = ((hash << 5) + hash) + *arKey++; break;
		}

		strKey = emalloc(24);
		snprintf(strKey, 24, "%lu", hash);

		RETURN_MM_STRING(strKey, 0);

		}

		
	ZEPHIR_MM_RESTORE();

}

