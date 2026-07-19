
#ifdef HAVE_CONFIG_H
#include "../../../../../ext_config.h"
#endif

#include <php.h>
#include "../../../../../php_ext.h"
#include "../../../../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 *
 * Based on the Action Domain Responder pattern
 * @link    https://pmjones.io/adr/
 */
/**
 * Renders a payload into a string for a given content type.
 */
ZEPHIR_INIT_CLASS(Phalcon_Contracts_ADR_Responder_Formatter_Formatter)
{
	ZEPHIR_REGISTER_INTERFACE(Phalcon\\Contracts\\ADR\\Responder\\Formatter, Formatter, phalcon, contracts_adr_responder_formatter_formatter, phalcon_contracts_adr_responder_formatter_formatter_method_entry);

	return SUCCESS;
}

/**
 * Whether this formatter can satisfy the given `Accept` header.
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_ADR_Responder_Formatter_Formatter, accepts);
/**
 * The content type this formatter produces.
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_ADR_Responder_Formatter_Formatter, contentType);
/**
 * Renders the payload into a string.
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_ADR_Responder_Formatter_Formatter, format);
