
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
 * Canonical contract for Phalcon\Flash messengers.
 *
 * Note: `output()` and `clear()` are part of the concrete `Direct` / `Session`
 * API and are not declared on this contract; they are scheduled to be added in
 * the next major version.
 */
ZEPHIR_INIT_CLASS(Phalcon_Contracts_Flash_Flash)
{
	ZEPHIR_REGISTER_INTERFACE(Phalcon\\Contracts\\Flash, Flash, phalcon, contracts_flash_flash, phalcon_contracts_flash_flash_method_entry);

	return SUCCESS;
}

/**
 * Shows a HTML error message
 *
 * @param string $message
 *
 * @return string|null
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Flash_Flash, error);
/**
 * Outputs a message
 *
 * Note: the shipped implementations (`Direct`, `Session`) accept
 * `string|array` for `$message`; this contract declares `string` and is
 * scheduled to be widened to `mixed` in the next major version. Delivery
 * semantics differ per implementation: `Direct::message()` renders and
 * emits the message immediately, while `Session::message()` stores the raw
 * message for output on a later request.
 *
 * @param string $type
 * @param string $message
 *
 * @return string|null
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Flash_Flash, message);
/**
 * Shows a HTML notice/information message
 *
 * @param string $message
 *
 * @return string|null
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Flash_Flash, notice);
/**
 * Shows a HTML success message
 *
 * @param string $message
 *
 * @return string|null
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Flash_Flash, success);
/**
 * Shows a HTML warning message
 *
 * @param string $message
 *
 * @return string|null
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Flash_Flash, warning);
