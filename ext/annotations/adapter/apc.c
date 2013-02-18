
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

/**
 * Phalcon\Annotations\Adapter\Files
 *
 * Stores the parsed annotations in APC. This adapter is the suitable for production
 *
 *<code>
 * $annotations = new \Phalcon\Annotations\Adapter\Apc();
 *</code>
 */


/**
 * Phalcon\Annotations\Adapter\Apc initializer
 */
PHALCON_INIT_CLASS(Phalcon_Annotations_Adapter_Apc){

	PHALCON_REGISTER_CLASS_EX(Phalcon\\Annotations\\Adapter, Apc, annotations_adapter_apc, "phalcon\\annotations\\adapter", phalcon_annotations_adapter_apc_method_entry, 0);

	zend_class_implements(phalcon_annotations_adapter_apc_ce TSRMLS_CC, 1, phalcon_annotations_adapterinterface_ce);

	return SUCCESS;
}

/**
 * Reads parsed annotations from Apc
 *
 * @param string $key
 * @return array
 */
PHP_METHOD(Phalcon_Annotations_Adapter_Apc, read){

	zval *key, *prefixed_key, *data;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &key) == FAILURE) {
		RETURN_MM_NULL();
	}

	PHALCON_INIT_VAR(prefixed_key);
	PHALCON_CONCAT_SV(prefixed_key, "_PHAN", key);
	
	PHALCON_INIT_VAR(data);
	PHALCON_CALL_FUNC_PARAMS_1(data, "apc_fetch", prefixed_key);
	RETURN_CCTOR(data);
}

/**
 * Writes parsed annotations to APC
 *
 * @param string $key
 * @param array $data
 */
PHP_METHOD(Phalcon_Annotations_Adapter_Apc, write){

	zval *key, *data, *prefixed_key;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &key, &data) == FAILURE) {
		RETURN_MM_NULL();
	}

	PHALCON_INIT_VAR(prefixed_key);
	PHALCON_CONCAT_SV(prefixed_key, "_PHAN", key);
	PHALCON_CALL_FUNC_PARAMS_2_NORETURN("apc_store", prefixed_key, data);
	
	PHALCON_MM_RESTORE();
}

