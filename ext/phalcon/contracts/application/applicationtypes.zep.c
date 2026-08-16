
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
 * Central registry of the array shapes used across the Application namespace.
 *
 * @phpstan-type application_module_definition array{
 *     className?: string,
 *     path?: string,
 * }
 * @phpstan-type application_modules array<string, Closure|application_module_definition>
 */
ZEPHIR_INIT_CLASS(Phalcon_Contracts_Application_ApplicationTypes)
{
	ZEPHIR_REGISTER_INTERFACE(Phalcon\\Contracts\\Application, ApplicationTypes, phalcon, contracts_application_applicationtypes, NULL);

	return SUCCESS;
}

