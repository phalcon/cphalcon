
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
#include "kernel/concat.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"


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
 * Phalcon\Annotations\Adapter\Apc
 *
 * Stores the parsed annotations in APC. This adapter is suitable for production
 *
 *<code>
 * $annotations = new \Phalcon\Annotations\Adapter\Apc();
 *</code>
 */
ZEPHIR_INIT_CLASS(Phalcon_Annotations_Adapter_Apc) {

	ZEPHIR_REGISTER_CLASS(Phalcon\\Annotations\\Adapter, phalcon, Apc, annotations_adapter_apc, phalcon_annotations_adapter_apc_method_entry, 0);


	return SUCCESS;

}

/**
 * Reads parsed annotations from APC
 *
 * @param string $key
 * @return Phalcon\Annotations\Reflection
 */
PHP_METHOD(Phalcon_Annotations_Adapter_Apc, read) {

	zval *key, *_0, *_1;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &key);



	ZEPHIR_INIT_VAR(_0);
	ZEPHIR_CONCAT_SV(_0, "_PHAN", key);
	ZEPHIR_INIT_VAR(_1);
	zephir_call_func_p1(_1, "strtolower", _0);
	zephir_call_func_p1(return_value, "apc_fetch", _1);
	RETURN_MM();

}

/**
 * Writes parsed annotations to APC
 *
 * @param string $key
 * @param Phalcon\Annotations\Reflection $data
 */
PHP_METHOD(Phalcon_Annotations_Adapter_Apc, write) {

	zval *key, *data, *_0, *_1;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &key, &data);



	ZEPHIR_INIT_VAR(_0);
	ZEPHIR_CONCAT_SV(_0, "_PHAN", key);
	ZEPHIR_INIT_VAR(_1);
	zephir_call_func_p1(_1, "strtolower", _0);
	zephir_call_func_p2(return_value, "apc_store", _1, data);
	RETURN_MM();

}

