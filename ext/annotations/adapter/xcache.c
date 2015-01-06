
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
  |          Vladimir Kolesnikov <vladimir@extrememember.com>              |
  +------------------------------------------------------------------------+
*/

#include "annotations/adapter/xcache.h"
#include "annotations/adapter.h"
#include "annotations/adapterinterface.h"

#include "kernel/main.h"
#include "kernel/memory.h"
#include "kernel/concat.h"
#include "kernel/fcall.h"
#include "kernel/string.h"
#include "kernel/variables.h"

/**
 * Phalcon\Annotations\Adapter\Xcache
 *
 * Stores the parsed annotations to XCache. This adapter is suitable for production
 *
 *<code>
 * $annotations = new \Phalcon\Annotations\Adapter\Xcache();
 *</code>
 */
zend_class_entry *phalcon_annotations_adapter_xcache_ce;

PHP_METHOD(Phalcon_Annotations_Adapter_Xcache, read);
PHP_METHOD(Phalcon_Annotations_Adapter_Xcache, write);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_annotations_adapter_xcache_read, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_annotations_adapter_xcache_write, 0, 0, 2)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

static const zend_function_entry phalcon_annotations_adapter_xcache_method_entry[] = {
	PHP_ME(Phalcon_Annotations_Adapter_Xcache, read, arginfo_phalcon_annotations_adapter_xcache_read, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Annotations_Adapter_Xcache, write, arginfo_phalcon_annotations_adapter_xcache_write, ZEND_ACC_PUBLIC)
	PHP_FE_END
};


/**
 * Phalcon\Annotations\Adapter\Xcache initializer
 */
PHALCON_INIT_CLASS(Phalcon_Annotations_Adapter_Xcache){

	PHALCON_REGISTER_CLASS_EX(Phalcon\\Annotations\\Adapter, Xcache, annotations_adapter_xcache, phalcon_annotations_adapter_ce, phalcon_annotations_adapter_xcache_method_entry, 0);

	zend_class_implements(phalcon_annotations_adapter_xcache_ce TSRMLS_CC, 1, phalcon_annotations_adapterinterface_ce);

	return SUCCESS;
}

/**
 * Reads parsed annotations from XCache
 *
 * @param string $key
 * @return Phalcon\Annotations\Reflection
 */
PHP_METHOD(Phalcon_Annotations_Adapter_Xcache, read){

	zval *key, *prefixed_key, *serialized = NULL;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &key);
	
	PHALCON_INIT_VAR(prefixed_key);
	PHALCON_CONCAT_SV(prefixed_key, "_PHAN", key);
	
	phalcon_strtolower_inplace(prefixed_key);
	
	PHALCON_CALL_FUNCTION(&serialized, "xcache_get", prefixed_key);
	if (Z_TYPE_P(serialized) == IS_STRING) {
		phalcon_unserialize(return_value, serialized TSRMLS_CC);
		if (Z_TYPE_P(return_value) != IS_OBJECT) {
			zval_dtor(return_value);
			RETVAL_NULL();
		}
	}
	
	PHALCON_MM_RESTORE();
}

/**
 * Writes parsed annotations to XCache
 *
 * @param string $key
 * @param Phalcon\Annotations\Reflection $data
 */
PHP_METHOD(Phalcon_Annotations_Adapter_Xcache, write){

	zval *key, *data, *prefixed_key;
	zval *serialized;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 2, 0, &key, &data);
	
	PHALCON_INIT_VAR(prefixed_key);
	PHALCON_CONCAT_SV(prefixed_key, "_PHAN", key);
	
	phalcon_strtolower_inplace(prefixed_key);
	
	PHALCON_INIT_VAR(serialized);
	phalcon_serialize(serialized, &data TSRMLS_CC);
	PHALCON_CALL_FUNCTION(NULL, "xcache_set", prefixed_key, serialized);
	
	PHALCON_MM_RESTORE();
}
