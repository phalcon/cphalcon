
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
 *
 * Implementation of this file has been influenced by AtlasPHP
 *
 * @link    https://github.com/atlasphp/Atlas.Pdo
 * @license https://github.com/atlasphp/Atlas.Pdo/blob/1.x/LICENSE.md
 */
/**
 * Interface to send query profiles to a logger.
 */
ZEPHIR_INIT_CLASS(Phalcon_DataMapper_Pdo_Profiler_ProfilerInterface) {

	ZEPHIR_REGISTER_INTERFACE(Phalcon\\DataMapper\\Pdo\\Profiler, ProfilerInterface, phalcon, datamapper_pdo_profiler_profilerinterface, phalcon_datamapper_pdo_profiler_profilerinterface_method_entry);

	return SUCCESS;

}

/**
 * Finishes and logs a profile entry.
 *
 * @param string $statement
 * @param array  $values
 */
ZEPHIR_DOC_METHOD(Phalcon_DataMapper_Pdo_Profiler_ProfilerInterface, finish);
/**
 * Returns the underlying logger instance.
 *
 * @return LoggerInterface
 */
ZEPHIR_DOC_METHOD(Phalcon_DataMapper_Pdo_Profiler_ProfilerInterface, getLogger);
/**
 * Returns the log message format string, with placeholders.
 *
 * @return string
 */
ZEPHIR_DOC_METHOD(Phalcon_DataMapper_Pdo_Profiler_ProfilerInterface, getLogFormat);
/**
 * Returns the level at which to log profile messages.
 *
 * @return string
 */
ZEPHIR_DOC_METHOD(Phalcon_DataMapper_Pdo_Profiler_ProfilerInterface, getLogLevel);
/**
 * Returns true if logging is active.
 *
 * @return bool
 */
ZEPHIR_DOC_METHOD(Phalcon_DataMapper_Pdo_Profiler_ProfilerInterface, isActive);
/**
 * Enable or disable profiler logging.
 *
 * @param bool $active
 *
 * @return ProfilerInterface
 */
ZEPHIR_DOC_METHOD(Phalcon_DataMapper_Pdo_Profiler_ProfilerInterface, setActive);
/**
 * Sets the log message format string, with placeholders.
 *
 * @param string $logFormat
 *
 * @return ProfilerInterface
 */
ZEPHIR_DOC_METHOD(Phalcon_DataMapper_Pdo_Profiler_ProfilerInterface, setLogFormat);
/**
 * Level at which to log profile messages.
 *
 * @param string $logLevel
 *
 * @return ProfilerInterface
 *
 */
ZEPHIR_DOC_METHOD(Phalcon_DataMapper_Pdo_Profiler_ProfilerInterface, setLogLevel);
/**
 * Starts a profile entry.
 *
 * @param string $method
 */
ZEPHIR_DOC_METHOD(Phalcon_DataMapper_Pdo_Profiler_ProfilerInterface, start);
