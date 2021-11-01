
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * Phalcon\Logger\FormatterInterface
 *
 * This interface must be implemented by formatters in Phalcon\Logger
 */
ZEPHIR_INIT_CLASS(Phalcon_Logger_Formatter_FormatterInterface)
{
	ZEPHIR_REGISTER_INTERFACE(Phalcon\\Logger\\Formatter, FormatterInterface, phalcon, logger_formatter_formatterinterface, phalcon_logger_formatter_formatterinterface_method_entry);

	return SUCCESS;
}

/**
 * Applies a format to an item
 *
 * @param Item $item
 *
 * @return string
 */
ZEPHIR_DOC_METHOD(Phalcon_Logger_Formatter_FormatterInterface, format);
