
#ifdef HAVE_CONFIG_H
#include "../../../../ext_config.h"
#endif

#include <php.h>
#include "../../../../php_ext.h"
#include "../../../../ext.h"

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
 * Canonical contract for Phalcon\Logger formatters.
 */
ZEPHIR_INIT_CLASS(Phalcon_Contracts_Logger_Formatter_Formatter)
{
	ZEPHIR_REGISTER_INTERFACE(Phalcon\\Contracts\\Logger\\Formatter, Formatter, phalcon, contracts_logger_formatter_formatter, phalcon_contracts_logger_formatter_formatter_method_entry);

	return SUCCESS;
}

/**
 * Applies a format to an item
 *
 * @param Item $item
 *
 * @return string
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Logger_Formatter_Formatter, format);
