
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/object.h"
#include "kernel/memory.h"
#include "kernel/string.h"
#include "kernel/array.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"


/*
 +------------------------------------------------------------------------+
 | Phalcon Framework                                                      |
 +------------------------------------------------------------------------+
 | Copyright (c) 2011-2013 Phalcon Team (http://www.phalconphp.com)       |
 +------------------------------------------------------------------------+
 | This source file is subject to the New BSD License that is bundled     |
 | with this package in the file docs/LICENSE.txt.                        |
 |                                                                        |
 | If you did not receive a copy of the license and are unable to         |
 | obtain it through the world-wide-web, please send an email             |
 | to license@phalconphp.com so we can send you a copy immediately.       |
 +------------------------------------------------------------------------+
 | Authors: Andres Gutierrez <andres@phalconphp.com>                      |
 |          Eduar Carvajal <eduar@phalconphp.com>                         |
 +------------------------------------------------------------------------+
 */
/**
* Phalcon\Annotations\Adapter\Memory
*
* Stores the parsed annotations in memory. This adapter is the suitable development/testing
*/
ZEPHIR_INIT_CLASS(Phalcon_Annotations_Adapter_Memory) {

	ZEPHIR_REGISTER_CLASS(Phalcon\\Annotations\\Adapter, Memory, phalcon, annotations_adapter_memory, phalcon_annotations_adapter_memory_method_entry, 0);

/**
	* Data
	* @var mixed
	*/
	zend_declare_property_null(phalcon_annotations_adapter_memory_ce, SL("_data"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

/**
 * Reads parsed annotations from memory
 *
 * @param string key
 * @return Phalcon\Annotations\Reflection
 */
PHP_METHOD(Phalcon_Annotations_Adapter_Memory, read) {

	zval *key_param = NULL, *data, *lowercasedKey, *_0;
	zval *key = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &key_param);

		if (Z_TYPE_P(key_param) != IS_STRING) {
				zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'key' must be a string") TSRMLS_CC);
				RETURN_MM_NULL();
		}

		key = key_param;


	data = zephir_fetch_nproperty_this(this_ptr, SL("_data"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(lowercasedKey);
	zephir_fast_strtolower(lowercasedKey, key);
	if (zephir_array_isset(data, lowercasedKey)) {
		zephir_array_fetch(&_0, data, lowercasedKey, PH_NOISY | PH_READONLY TSRMLS_CC);
		RETURN_CTOR(_0);
	}
	RETURN_MM_BOOL(0);

}

/**
 * Writes parsed annotations to memory
 *
 * @param string key
 * @param Phalcon\Annotations\Reflection data
 */
PHP_METHOD(Phalcon_Annotations_Adapter_Memory, write) {

	zval *key_param = NULL, *data, *lowercasedKey;
	zval *key = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &key_param, &data);

		if (Z_TYPE_P(key_param) != IS_STRING) {
				zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'key' must be a string") TSRMLS_CC);
				RETURN_MM_NULL();
		}

		key = key_param;


	ZEPHIR_INIT_VAR(lowercasedKey);
	zephir_fast_strtolower(lowercasedKey, key);
	zephir_update_property_array(this_ptr, SL("_data"), lowercasedKey, data TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

