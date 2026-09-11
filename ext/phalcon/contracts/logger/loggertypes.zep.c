
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
 * Central registry of the array shapes used across the Logger namespace.
 *
 * @phpstan-type logger_context array<string, mixed>
 * @phpstan-type logger_adapters array<array-key, AdapterInterface>
 * @phpstan-type logger_excluded array<array-key, bool>
 * @phpstan-type logger_levels array<int, string>
 * @phpstan-type logger_queue array<int, Item>
 * @phpstan-type logger_adapter_options array<string, mixed>
 * @phpstan-type logger_stream_options array{
 *     mode?: string,
 * }
 * @phpstan-type logger_syslog_options array{
 *     option?: int,
 *     facility?: int,
 * }
 * @phpstan-type logger_adapter_config array{
 *     adapter: string,
 *     name: string,
 *     options?: logger_adapter_options,
 * }
 *
 * @phpstan-type logger_factory_config array{
 *     name: string,
 *     timezone?: DateTimeZone,
 *     options?: array{
 *         adapters?: array<array-key, logger_adapter_config>,
 *     },
 * }
 */
ZEPHIR_INIT_CLASS(Phalcon_Contracts_Logger_LoggerTypes)
{
	ZEPHIR_REGISTER_INTERFACE(Phalcon\\Contracts\\Logger, LoggerTypes, phalcon, contracts_logger_loggertypes, NULL);

	return SUCCESS;
}

