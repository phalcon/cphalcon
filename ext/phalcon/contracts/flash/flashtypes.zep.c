
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
 * Central registry of the array shapes used across the Flash namespace.
 *
 * @phpstan-type flash_css_classes array<string, list<string>|string>
 * @phpstan-type flash_messages list<string>
 * @phpstan-type flash_session_messages array<string, list<mixed>>
 */
ZEPHIR_INIT_CLASS(Phalcon_Contracts_Flash_FlashTypes)
{
	ZEPHIR_REGISTER_INTERFACE(Phalcon\\Contracts\\Flash, FlashTypes, phalcon, contracts_flash_flashtypes, NULL);

	return SUCCESS;
}

