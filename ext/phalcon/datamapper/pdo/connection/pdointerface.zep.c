
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
 * An interface to the native PDO object.
 */
ZEPHIR_INIT_CLASS(Phalcon_DataMapper_Pdo_Connection_PdoInterface)
{
	ZEPHIR_REGISTER_INTERFACE(Phalcon\\DataMapper\\Pdo\\Connection, PdoInterface, phalcon, datamapper_pdo_connection_pdointerface, phalcon_datamapper_pdo_connection_pdointerface_method_entry);

	return SUCCESS;
}

/**
 * Return an array of available PDO drivers (empty array if none available)
 */
ZEPHIR_DOC_METHOD(Phalcon_DataMapper_Pdo_Connection_PdoInterface, getAvailableDrivers);
/**
 * Begins a transaction. If the profiler is enabled, the operation will
 * be recorded.
 */
ZEPHIR_DOC_METHOD(Phalcon_DataMapper_Pdo_Connection_PdoInterface, beginTransaction);
/**
 * Commits the existing transaction. If the profiler is enabled, the
 * operation will be recorded.
 */
ZEPHIR_DOC_METHOD(Phalcon_DataMapper_Pdo_Connection_PdoInterface, commit);
/**
 * Gets the most recent error code.
 */
ZEPHIR_DOC_METHOD(Phalcon_DataMapper_Pdo_Connection_PdoInterface, errorCode);
/**
 * Gets the most recent error info.
 */
ZEPHIR_DOC_METHOD(Phalcon_DataMapper_Pdo_Connection_PdoInterface, errorInfo);
/**
 * Executes an SQL statement and returns the number of affected rows. If
 * the profiler is enabled, the operation will be recorded.
 */
ZEPHIR_DOC_METHOD(Phalcon_DataMapper_Pdo_Connection_PdoInterface, exec);
/**
 * Retrieve a database connection attribute
 */
ZEPHIR_DOC_METHOD(Phalcon_DataMapper_Pdo_Connection_PdoInterface, getAttribute);
/**
 * Is a transaction currently active? If the profiler is enabled, the
 * operation will be recorded. If the profiler is enabled, the operation
 * will be recorded.
 */
ZEPHIR_DOC_METHOD(Phalcon_DataMapper_Pdo_Connection_PdoInterface, inTransaction);
/**
 * Returns the last inserted autoincrement sequence value. If the profiler
 * is enabled, the operation will be recorded.
 */
ZEPHIR_DOC_METHOD(Phalcon_DataMapper_Pdo_Connection_PdoInterface, lastInsertId);
/**
 * Prepares an SQL statement for execution.
 */
ZEPHIR_DOC_METHOD(Phalcon_DataMapper_Pdo_Connection_PdoInterface, prepare);
/**
 * Queries the database and returns a PDOStatement. If the profiler is
 * enabled, the operation will be recorded.
 */
ZEPHIR_DOC_METHOD(Phalcon_DataMapper_Pdo_Connection_PdoInterface, query);
/**
 * Quotes a value for use in an SQL statement. This differs from
 * `PDO::quote()` in that it will convert an array into a string of
 * comma-separated quoted values. The default type is `PDO::PARAM_STR`
 */
ZEPHIR_DOC_METHOD(Phalcon_DataMapper_Pdo_Connection_PdoInterface, quote);
/**
 * Rolls back the current transaction, and restores autocommit mode. If the
 * profiler is enabled, the operation will be recorded.
 */
ZEPHIR_DOC_METHOD(Phalcon_DataMapper_Pdo_Connection_PdoInterface, rollBack);
/**
 * Set a database connection attribute
 */
ZEPHIR_DOC_METHOD(Phalcon_DataMapper_Pdo_Connection_PdoInterface, setAttribute);
