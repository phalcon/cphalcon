
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

#include "annotations/adapter/apc.h"
#include "annotations/adapter.h"
#include "annotations/adapterinterface.h"

#include "kernel/main.h"
#include "kernel/memory.h"
#include "kernel/concat.h"
#include "kernel/fcall.h"
#include "kernel/string.h"

/**
 * Phalcon\Annotations\Adapter\Apc
 *
 * Stores the parsed annotations in APC. This adapter is suitable for production
 *
 *<code>
 * $annotations = new \Phalcon\Annotations\Adapter\Apc();
 *</code>
 */
zend_class_entry *phalcon_annotations_adapter_apc_ce;

PHP_METHOD(Phalcon_Annotations_Adapter_Apc, read);
PHP_METHOD(Phalcon_Annotations_Adapter_Apc, write);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_annotations_adapter_apc_read, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_annotations_adapter_apc_write, 0, 0, 2)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

static const zend_function_entry phalcon_annotations_adapter_apc_method_entry[] = {
	PHP_ME(Phalcon_Annotations_Adapter_Apc, read, arginfo_phalcon_annotations_adapter_apc_read, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Annotations_Adapter_Apc, write, arginfo_phalcon_annotations_adapter_apc_write, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

/**
 * Phalcon\Annotations\Adapter\Apc initializer
 */
PHALCON_INIT_CLASS(Phalcon_Annotations_Adapter_Apc){

	PHALCON_REGISTER_CLASS_EX(Phalcon\\Annotations\\Adapter, Apc, annotations_adapter_apc, phalcon_annotations_adapter_ce, phalcon_annotations_adapter_apc_method_entry, 0);

	zend_class_implements(phalcon_annotations_adapter_apc_ce TSRMLS_CC, 1, phalcon_annotations_adapterinterface_ce);

	return SUCCESS;
}

/**
 * Reads parsed annotations from APC
 *
 * @param string $key
 * @return Phalcon\Annotations\Reflection
 */
PHP_METHOD(Phalcon_Annotations_Adapter_Apc, read){

	zval *key, *prefixed_key;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &key);
	
	PHALCON_INIT_VAR(prefixed_key);
	PHALCON_CONCAT_SV(prefixed_key, "_PHAN", key);
	
	phalcon_strtolower_inplace(prefixed_key);
	
	PHALCON_RETURN_CALL_FUNCTION("apc_fetch", prefixed_key);
	if (return_value_ptr) {
		return_value = *return_value_ptr;
	}

	if (Z_TYPE_P(return_value) != IS_OBJECT) {
		zval_dtor(return_value);
		ZVAL_NULL(return_value);
	}
	
	PHALCON_MM_RESTORE();
}

/**
 * Writes parsed annotations to APC
 *
 * @param string $key
 * @param Phalcon\Annotations\Reflection $data
 */
PHP_METHOD(Phalcon_Annotations_Adapter_Apc, write){

	zval *key, *data, *prefixed_key;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 2, 0, &key, &data);
	
	PHALCON_INIT_VAR(prefixed_key);
	PHALCON_CONCAT_SV(prefixed_key, "_PHAN", key);
	
	phalcon_strtolower_inplace(prefixed_key);
	PHALCON_CALL_FUNCTION(NULL, "apc_store", prefixed_key, data);
	
	PHALCON_MM_RESTORE();
}
