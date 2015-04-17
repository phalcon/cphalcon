
#ifdef HAVE_CONFIG_H
#include "../ext_config.h"
#endif

#include <php.h>
#include "../php_ext.h"
#include "../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


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

/**
 * Outputs a message
 */
ZEPHIR_DOC_METHOD(Phalcon_FlashInterface, message);

