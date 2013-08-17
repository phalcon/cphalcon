
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

#include "kernel/fcall.h"

/**
 * Phalcon\Flash\Direct
 *
 * This is a variant of the Phalcon\Flash that inmediately outputs any message passed to it
 */


/**
 * Phalcon\Flash\Direct initializer
 */
PHALCON_INIT_CLASS(Phalcon_Flash_Direct){

	PHALCON_REGISTER_CLASS_EX(Phalcon\\Flash, Direct, flash_direct, phalcon_flash_ce, phalcon_flash_direct_method_entry, 0);

	zend_class_implements(phalcon_flash_direct_ce TSRMLS_CC, 1, phalcon_flashinterface_ce);

	return SUCCESS;
}

/**
 * Outputs a message
 *
 * @param  string $type
 * @param  string $message
 * @return string
 */
PHP_METHOD(Phalcon_Flash_Direct, message){

	zval *type, *message;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 2, 0, &type, &message);
	
	phalcon_call_method_p2(return_value, this_ptr, "outputmessage", type, message);
	RETURN_MM();
}

