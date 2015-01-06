
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

#include "flash/direct.h"
#include "flash.h"
#include "flashinterface.h"

#include "kernel/main.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"

/**
 * Phalcon\Flash\Direct
 *
 * This is a variant of the Phalcon\Flash that inmediately outputs any message passed to it
 */
zend_class_entry *phalcon_flash_direct_ce;

PHP_METHOD(Phalcon_Flash_Direct, message);

static const zend_function_entry phalcon_flash_direct_method_entry[] = {
	PHP_ME(Phalcon_Flash_Direct, message, arginfo_phalcon_flashinterface_message, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

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
PHP_METHOD(Phalcon_Flash_Direct, message)
{
	zval *type, *message;

	phalcon_fetch_params(0, 2, 0, &type, &message);
	
	PHALCON_RETURN_CALL_METHODW(this_ptr, "outputmessage", type, message);
}
