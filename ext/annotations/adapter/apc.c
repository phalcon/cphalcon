
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
	
	if (unlikely(!return_value_ptr)) {
		return_value_ptr = &return_value;
	}

	phalcon_return_call_func_p1("apc_fetch", prefixed_key);
	if (Z_TYPE_PP(return_value_ptr) != IS_OBJECT) {
		zval_dtor(*return_value_ptr);
		ZVAL_NULL(*return_value_ptr);
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
	phalcon_call_func_p2_noret("apc_store", prefixed_key, data);
	
	PHALCON_MM_RESTORE();
}
