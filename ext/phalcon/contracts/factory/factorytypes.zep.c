
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
 * Central registry of the array shapes used across the Factory namespace.
 *
 * @phpstan-type factory_config array<string, mixed>
 * @phpstan-type factory_services array<string, string>
 * @phpstan-type factory_instances array<string, mixed>
 */
ZEPHIR_INIT_CLASS(Phalcon_Contracts_Factory_FactoryTypes)
{
	ZEPHIR_REGISTER_INTERFACE(Phalcon\\Contracts\\Factory, FactoryTypes, phalcon, contracts_factory_factorytypes, NULL);

	return SUCCESS;
}

