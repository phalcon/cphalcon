
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


/**
 * Phalcon\Logger\FormatterInterface
 *
 * This interface must be implemented by formmaters in Phalcon\Logger
 */
ZEPHIR_INIT_CLASS(Phalcon_Logger_FormatterInterface) {

	ZEPHIR_REGISTER_INTERFACE(Phalcon\\Logger, FormatterInterface, phalcon, logger_formatterinterface, phalcon_logger_formatterinterface_method_entry);

	return SUCCESS;

}

/**
 * Applies a format to a message before sent it to the internal log
 *
 * @param string message
 * @param int type
 * @param int timestamp
 * @param array $context
 */
ZEPHIR_DOC_METHOD(Phalcon_Logger_FormatterInterface, format);

