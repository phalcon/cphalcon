
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
 * Central registry of the array shapes used across the Autoload namespace.
 *
 * @phpstan-type autoload_strings array<string, string>
 * @phpstan-type autoload_namespaces array<string, autoload_strings>
 */
ZEPHIR_INIT_CLASS(Phalcon_Contracts_Autoload_AutoloadTypes)
{
	ZEPHIR_REGISTER_INTERFACE(Phalcon\\Contracts\\Autoload, AutoloadTypes, phalcon, contracts_autoload_autoloadtypes, NULL);

	return SUCCESS;
}

