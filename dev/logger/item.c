
/*
  +------------------------------------------------------------------------+
  | Phalcon Framework                                                      |
  +------------------------------------------------------------------------+
  | Copyright (c) 2011-2012 Phalcon Team (http://www.phalconphp.com)       |
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

/**
 * Phalcon\Logger\Item
 *
 * Represents each item in a logger transaction
 *
 */

/**
 * Phalcon\Logger\Item contructor
 *
 * @param string $message
 * @param integer $type
 * @param integer $time
 */
PHP_METHOD(Phalcon_Logger_Item, __construct){

	zval *message = NULL, *type = NULL, *time = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz|z", &message, &type, &time) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!time) {
		PHALCON_ALLOC_ZVAL_MM(time);
		ZVAL_LONG(time, 0);
	}
	
	phalcon_update_property_zval(this_ptr, SL("_message"), message TSRMLS_CC);
	phalcon_update_property_zval(this_ptr, SL("_type"), type TSRMLS_CC);
	phalcon_update_property_zval(this_ptr, SL("_time"), time TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

/**
 * Returns the message
 *
 * @return string
 */
PHP_METHOD(Phalcon_Logger_Item, getMessage){

	zval *t0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, SL("_message"), PH_NOISY_CC);
	
	RETURN_CCTOR(t0);
}

/**
 * Returns the log type
 *
 * @return integer
 */
PHP_METHOD(Phalcon_Logger_Item, getType){

	zval *t0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, SL("_type"), PH_NOISY_CC);
	
	RETURN_CCTOR(t0);
}

/**
 * Returns log timestamp
 *
 * @return integer
 */
PHP_METHOD(Phalcon_Logger_Item, getTime){

	zval *t0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, SL("_time"), PH_NOISY_CC);
	
	RETURN_CCTOR(t0);
}

