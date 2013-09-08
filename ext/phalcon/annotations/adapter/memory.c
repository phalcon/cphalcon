
#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_test.h"
#include "test.h"

#include "Zend/zend_operators.h"
#include "Zend/zend_exceptions.h"
#include "Zend/zend_interfaces.h"

#include "kernel/main.h"
#include "kernel/memory.h"
#include "kernel/object.h"
#include "kernel/fcall.h"
#include "kernel/array.h"


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

	ZEPHIR_REGISTER_CLASS(Phalcon\\Annotations\\Adapter, Memory, annotations_adapter_memory, phalcon_annotations_adapter_memory_method_entry, 0);

/**
 * Data
 * @var mixed
 */
	zend_declare_property_null(phalcon_annotations_adapter_memory_ce, SL("_data"), ZEND_ACC_PUBLIC TSRMLS_CC);

	return SUCCESS;

}

/**
 * Reads parsed annotations from memory
 *
 * @param string $key
 * @return Phalcon\Annotations\Reflection
 */
PHP_METHOD(Phalcon_Annotations_Adapter_Memory, read) {

	zval *key, *data, *lowercasedKey;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &key);



	ZEPHIR_OBS_VAR(data);
	zephir_read_property_this(&data, this_ptr, SL("_data"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(lowercasedKey);
	zephir_call_func_p1(lowercasedKey, "strtolower", key);
	if (zephir_array_isset(data, lowercasedKey)) {
		zephir_array_fetch(&return_value, data, lowercasedKey, PH_NOISY);
		RETURN_MM();
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Writes parsed annotations to memory
 *
 * @param string $key
 * @param Phalcon\Annotations\Reflection $data
 */
PHP_METHOD(Phalcon_Annotations_Adapter_Memory, write) {

	zval *key, *data, *lowercasedKey;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &key, &data);



	ZEPHIR_INIT_VAR(lowercasedKey);
	zephir_call_func_p1(lowercasedKey, "strtolower", key);
	zephir_update_property_array(this_ptr, SL("_data"), lowercasedKey, data TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

