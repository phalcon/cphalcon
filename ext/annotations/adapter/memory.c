
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

/**
 * Phalcon\Annotations\Adapter\Memory initializer
 */
PHALCON_INIT_CLASS(Phalcon_Annotations_Adapter_Memory){

	PHALCON_REGISTER_CLASS_EX(Phalcon\\Annotations\\Adapter, Memory, annotations_adapter_memory, "phalcon\\annotations\\adapter", phalcon_annotations_adapter_memory_method_entry, 0);

	return SUCCESS;
}

PHP_METHOD(Phalcon_Annotations_Adapter_Memory, read){

	zval *key;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &key) == FAILURE) {
		RETURN_NULL();
	}

	RETURN_NULL();
}

PHP_METHOD(Phalcon_Annotations_Adapter_Memory, write){

	zval *key, *data;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &key, &data) == FAILURE) {
		RETURN_NULL();
	}

	RETURN_NULL();
}

