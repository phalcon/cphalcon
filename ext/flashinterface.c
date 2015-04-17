
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

#include "flashinterface.h"
#include "kernel/main.h"

zend_class_entry *phalcon_flashinterface_ce;

static const zend_function_entry phalcon_flashinterface_method_entry[] = {
	PHP_ABSTRACT_ME(Phalcon_FlashInterface, error, arginfo_phalcon_flashinterface_error)
	PHP_ABSTRACT_ME(Phalcon_FlashInterface, notice, arginfo_phalcon_flashinterface_notice)
	PHP_ABSTRACT_ME(Phalcon_FlashInterface, success, arginfo_phalcon_flashinterface_success)
	PHP_ABSTRACT_ME(Phalcon_FlashInterface, warning, arginfo_phalcon_flashinterface_warning)
	PHP_ABSTRACT_ME(Phalcon_FlashInterface, message, arginfo_phalcon_flashinterface_message)
	PHP_FE_END
};

/**
 * Phalcon\FlashInterface initializer
 */
PHALCON_INIT_CLASS(Phalcon_FlashInterface){

	PHALCON_REGISTER_INTERFACE(Phalcon, FlashInterface, flashinterface, phalcon_flashinterface_method_entry);

	return SUCCESS;
}

/**
 * Shows a HTML error message
 *
 * @param string $message
 * @return string
 */
PHALCON_DOC_METHOD(Phalcon_FlashInterface, error);

/**
 * Shows a HTML notice/information message
 *
 * @param string $message
 * @return string
 */
PHALCON_DOC_METHOD(Phalcon_FlashInterface, notice);

/**
 * Shows a HTML success message
 *
 * @param string $message
 * @return string
 */
PHALCON_DOC_METHOD(Phalcon_FlashInterface, success);

/**
 * Shows a HTML warning message
 *
 * @param string $message
 * @return string
 */
PHALCON_DOC_METHOD(Phalcon_FlashInterface, warning);

/**
 * Outputs a message
 *
 * @param  string $type
 * @param  string $message
 * @return string
 */
PHALCON_DOC_METHOD(Phalcon_FlashInterface, message);
