
/*
  +------------------------------------------------------------------------+
  | Phalcon Framework                                                      |
  +------------------------------------------------------------------------+
  | Copyright (c) 2011-2014 Phalcon Team (http://www.phalconphp.com)       |
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

#include "annotations/adapter/memory.h"
#include "annotations/adapter.h"
#include "annotations/adapterinterface.h"

#include "kernel/main.h"
#include "kernel/memory.h"
#include "kernel/object.h"
#include "kernel/string.h"
#include "kernel/array.h"

/**
 * Phalcon\Annotations\Adapter\Memory
 *
 * Stores the parsed annotations in memory. This adapter is the suitable development/testing
 */
zend_class_entry *phalcon_annotations_adapter_memory_ce;

PHP_METHOD(Phalcon_Annotations_Adapter_Memory, read);
PHP_METHOD(Phalcon_Annotations_Adapter_Memory, write);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_annotations_adapter_memory_read, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_annotations_adapter_memory_write, 0, 0, 2)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

static const zend_function_entry phalcon_annotations_adapter_memory_method_entry[] = {
	PHP_ME(Phalcon_Annotations_Adapter_Memory, read, arginfo_phalcon_annotations_adapter_memory_read, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Annotations_Adapter_Memory, write, arginfo_phalcon_annotations_adapter_memory_write, ZEND_ACC_PUBLIC)
	PHP_FE_END
};


/**
 * Phalcon\Annotations\Adapter\Memory initializer
 */
PHALCON_INIT_CLASS(Phalcon_Annotations_Adapter_Memory){

	PHALCON_REGISTER_CLASS_EX(Phalcon\\Annotations\\Adapter, Memory, annotations_adapter_memory, phalcon_annotations_adapter_ce, phalcon_annotations_adapter_memory_method_entry, 0);

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
	
	data = phalcon_fetch_nproperty_this(this_ptr, SL("_data"), PH_NOISY TSRMLS_CC);
	
	PHALCON_INIT_VAR(lowercased_key);
	phalcon_fast_strtolower(lowercased_key, key);
	if (phalcon_array_isset_fetch(&annotations, data, lowercased_key)) {
		RETURN_CTOR(annotations);
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

	phalcon_fetch_params(0, 2, 0, &key, &data);
	
	MAKE_STD_ZVAL(lowercased_key);
	phalcon_fast_strtolower(lowercased_key, key);
	phalcon_update_property_array(this_ptr, SL("_data"), lowercased_key, data TSRMLS_CC);
	zval_ptr_dtor(&lowercased_key);
}
