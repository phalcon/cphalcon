
#ifdef HAVE_CONFIG_H
#include "../ext_config.h"
#endif

#include <php.h>
#include "../php_ext.h"
#include "../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * Phalcon\FlashInterface
 *
 * Interface for Phalcon\Flash
 */
ZEPHIR_INIT_CLASS(Phalcon_FlashInterface) {

	ZEPHIR_REGISTER_INTERFACE(Phalcon, FlashInterface, phalcon, flashinterface, phalcon_flashinterface_method_entry);

	return SUCCESS;

}

/**
 * Shows a HTML error message
 */
ZEPHIR_DOC_METHOD(Phalcon_FlashInterface, error);

/**
 * Outputs a message
 */
ZEPHIR_DOC_METHOD(Phalcon_FlashInterface, message);

/**
 * Shows a HTML notice/information message
 */
ZEPHIR_DOC_METHOD(Phalcon_FlashInterface, notice);

/**
 * Shows a HTML success message
 */
ZEPHIR_DOC_METHOD(Phalcon_FlashInterface, success);

/**
 * Shows a HTML warning message
 */
ZEPHIR_DOC_METHOD(Phalcon_FlashInterface, warning);

