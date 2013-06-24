
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
#include "kernel/fcall.h"
#include "kernel/string.h"
#include "kernel/array.h"

/**
 * Phalcon\Annotations\Adapter\Memory
 *
 * Stores the parsed annotations in memory. This adapter is suitable for development/testing
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
 * Reads parsed annotations from memory
 *
 * @param string $key
 * @return Phalcon\Annotations\Reflection
 */
PHP_METHOD(Phalcon_Annotations_Adapter_Memory, read){

	zval *key, *data, *lowercased_key, *annotations;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &key);
	
	PHALCON_OBS_VAR(data);
	phalcon_read_property_this(&data, this_ptr, SL("_data"), PH_NOISY_CC);
	
	PHALCON_INIT_VAR(lowercased_key);
	phalcon_fast_strtolower(lowercased_key, key);
	if (phalcon_array_isset(data, lowercased_key)) {
		PHALCON_OBS_VAR(annotations);
		phalcon_array_fetch(&annotations, data, lowercased_key, PH_NOISY_CC);
		RETURN_CCTOR(annotations);
	}
	
	RETURN_MM_NULL();
}

/**
 * Writes parsed annotations to memory
 *
 * @param string $key
 * @param Phalcon\Annotations\Reflection $data
 */
PHP_METHOD(Phalcon_Annotations_Adapter_Memory, write){

	zval *key, *data, *lowercased_key;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 2, 0, &key, &data);
	
	PHALCON_INIT_VAR(lowercased_key);
	phalcon_fast_strtolower(lowercased_key, key);
	phalcon_update_property_array(this_ptr, SL("_data"), lowercased_key, data TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

