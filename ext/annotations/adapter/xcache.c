
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
  |          Vladimir Kolesnikov <vladimir@extrememember.com>              |
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

	zval *key, *prefixed_key, *prefixed_lower, *serialized;
	zval *data;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &key);
	
	PHALCON_INIT_VAR(prefixed_key);
	PHALCON_CONCAT_SV(prefixed_key, "_PHAN", key);
	
	PHALCON_INIT_VAR(prefixed_lower);
	phalcon_fast_strtolower(prefixed_lower, prefixed_key);
	
	PHALCON_INIT_VAR(serialized);
	phalcon_call_func_p1(serialized, "xcache_get", prefixed_lower);
	if (Z_TYPE_P(serialized) == IS_STRING) {
	
		PHALCON_INIT_VAR(data);
		phalcon_unserialize(data, serialized TSRMLS_CC);
		if (Z_TYPE_P(data) == IS_OBJECT) {
			RETURN_CTOR(data);
		}
	}
	
	RETURN_MM_NULL();
}

/**
 * Writes parsed annotations to XCache
 *
 * @param string $key
 * @param Phalcon\Annotations\Reflection $data
 */
PHP_METHOD(Phalcon_Annotations_Adapter_Xcache, write){

	zval *key, *data, *prefixed_key, *prefixed_lower;
	zval *serialized;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 2, 0, &key, &data);
	
	PHALCON_INIT_VAR(prefixed_key);
	PHALCON_CONCAT_SV(prefixed_key, "_PHAN", key);
	
	PHALCON_INIT_VAR(prefixed_lower);
	phalcon_fast_strtolower(prefixed_lower, prefixed_key);
	
	PHALCON_INIT_VAR(serialized);
	phalcon_serialize(serialized, &data TSRMLS_CC);
	phalcon_call_func_p2_noret("xcache_set", prefixed_lower, serialized);
	
	PHALCON_MM_RESTORE();
}

