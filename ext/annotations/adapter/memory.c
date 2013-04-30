
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

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_phalcon.h"
#include "phalcon.h"

#include "Zend/zend_operators.h"
#include "Zend/zend_exceptions.h"
#include "Zend/zend_interfaces.h"

#include "kernel/main.h"
#include "kernel/memory.h"

#include "kernel/object.h"
#include "kernel/array.h"

/**
 * Phalcon\Annotations\Adapter\Memory
 *
 * Stores the parsed annotations in memory. This adapter is the suitable for development/testing
 */


/**
 * Phalcon\Annotations\Adapter\Memory initializer
 */
PHALCON_INIT_CLASS(Phalcon_Annotations_Adapter_Memory){

	PHALCON_REGISTER_CLASS_EX(Phalcon\\Annotations\\Adapter, Memory, annotations_adapter_memory, "phalcon\\annotations\\adapter", phalcon_annotations_adapter_memory_method_entry, 0);

	zend_declare_property_null(phalcon_annotations_adapter_memory_ce, SL("_data"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(phalcon_annotations_adapter_memory_ce TSRMLS_CC, 1, phalcon_annotations_adapterinterface_ce);

	return SUCCESS;
}

/**
 * Reads meta-data from memory
 *
 * @param string $key
 * @return array
 */
PHP_METHOD(Phalcon_Annotations_Adapter_Memory, read){

	zval *key, *data, *annotations;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &key) == FAILURE) {
		RETURN_MM_NULL();
	}

	PHALCON_OBS_VAR(data);
	phalcon_read_property_this(&data, this_ptr, SL("_data"), PH_NOISY_CC);
	if (phalcon_array_isset(data, key)) {
		PHALCON_OBS_VAR(annotations);
		phalcon_array_fetch(&annotations, data, key, PH_NOISY_CC);
		RETURN_CCTOR(annotations);
	}
	
	RETURN_MM_NULL();
}

/**
 * Writes the meta-data to files
 *
 * @param string $key
 * @param array $data
 */
PHP_METHOD(Phalcon_Annotations_Adapter_Memory, write){

	zval *key, *data;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &key, &data) == FAILURE) {
		RETURN_NULL();
	}

	phalcon_update_property_array(this_ptr, SL("_data"), key, data TSRMLS_CC);
	
}

