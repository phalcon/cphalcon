
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
 * Provides array quoting, profiling, a new `perform()` method, new `fetch*()`
 * methods
 *
 * @property array             $args
 * @property PDO               $pdo
 * @property ProfilerInterface $profiler
 * @property array             $quote
 */
ZEPHIR_INIT_CLASS(Phalcon_DataMapper_Pdo_Connection_ConnectionInterface)
{
	ZEPHIR_REGISTER_INTERFACE(Phalcon\\DataMapper\\Pdo\\Connection, ConnectionInterface, phalcon, datamapper_pdo_connection_connectioninterface, phalcon_datamapper_pdo_connection_connectioninterface_method_entry);

	zend_class_implements(phalcon_datamapper_pdo_connection_connectioninterface_ce, 1, phalcon_datamapper_pdo_connection_pdointerface_ce);
	return SUCCESS;
}

/**
 * Connects to the database.
 */
ZEPHIR_DOC_METHOD(Phalcon_DataMapper_Pdo_Connection_ConnectionInterface, connect);
/**
 * Disconnects from the database.
 */
ZEPHIR_DOC_METHOD(Phalcon_DataMapper_Pdo_Connection_ConnectionInterface, disconnect);
/**
 * Performs a statement and returns the number of affected rows.
 *
 * @param string $statement
 * @param array  $values
 *
 * @return int
 */
ZEPHIR_DOC_METHOD(Phalcon_DataMapper_Pdo_Connection_ConnectionInterface, fetchAffected);
/**
 * Fetches a sequential array of rows from the database; the rows are
 * returned as associative arrays.
 *
 * @param string $statement
 * @param array  $values
 *
 * @return array
 */
ZEPHIR_DOC_METHOD(Phalcon_DataMapper_Pdo_Connection_ConnectionInterface, fetchAll);
/**
 * Fetches an associative array of rows from the database; the rows are
 * returned as associative arrays, and the array of rows is keyed on the
 * first column of each row.
 *
 * If multiple rows have the same first column value, the last row with
 * that value will overwrite earlier rows. This method is more resource
 * intensive and should be avoided if possible.
 *
 * @param string $statement
 * @param array  $values
 *
 * @return array
 */
ZEPHIR_DOC_METHOD(Phalcon_DataMapper_Pdo_Connection_ConnectionInterface, fetchAssoc);
/**
 * Fetches a column of rows as a sequential array (default first one).
 *
 * @param string $statement
 * @param array  $values
 * @param int    $column
 *
 * @return array
 */
ZEPHIR_DOC_METHOD(Phalcon_DataMapper_Pdo_Connection_ConnectionInterface, fetchColumn);
/**
 * Fetches multiple from the database as an associative array. The first
 * column will be the index key. The default flags are
 * PDO::FETCH_ASSOC | PDO::FETCH_GROUP
 *
 * @param string $statement
 * @param array  $values
 * @param int    $flags
 *
 * @return array
 */
ZEPHIR_DOC_METHOD(Phalcon_DataMapper_Pdo_Connection_ConnectionInterface, fetchGroup);
/**
 * Fetches one row from the database as an object where the column values
 * are mapped to object properties.
 *
 * Since PDO injects property values before invoking the constructor, any
 * initializations for defaults that you potentially have in your object's
 * constructor, will override the values that have been injected by
 * `fetchObject`. The default object returned is `\stdClass`
 *
 * @param string $statement
 * @param array  $values
 * @param string $class
 * @param array  $arguments
 *
 * @return object
 */
ZEPHIR_DOC_METHOD(Phalcon_DataMapper_Pdo_Connection_ConnectionInterface, fetchObject);
/**
 * Fetches a sequential array of rows from the database; the rows are
 * returned as objects where the column values are mapped to object
 * properties.
 *
 * Since PDO injects property values before invoking the constructor, any
 * initializations for defaults that you potentially have in your object's
 * constructor, will override the values that have been injected by
 * `fetchObject`. The default object returned is `\stdClass`
 *
 * @param string $statement
 * @param array  $values
 * @param string $class
 * @param array  $arguments
 *
 * @return array
 */
ZEPHIR_DOC_METHOD(Phalcon_DataMapper_Pdo_Connection_ConnectionInterface, fetchObjects);
/**
 * Fetches one row from the database as an associative array.
 *
 * @param string $statement
 * @param array  $values
 *
 * @return array
 */
ZEPHIR_DOC_METHOD(Phalcon_DataMapper_Pdo_Connection_ConnectionInterface, fetchOne);
/**
 * Fetches an associative array of rows as key-value pairs (first column is
 * the key, second column is the value).
 *
 * @param string $statement
 * @param array  $values
 *
 * @return array
 */
ZEPHIR_DOC_METHOD(Phalcon_DataMapper_Pdo_Connection_ConnectionInterface, fetchPairs);
/**
 * Fetches the very first value (i.e., first column of the first row).
 *
 * @param string $statement
 * @param array  $values
 *
 * @return mixed
 */
ZEPHIR_DOC_METHOD(Phalcon_DataMapper_Pdo_Connection_ConnectionInterface, fetchValue);
/**
 * Return the inner PDO (if any)
 *
 * @return \PDO
 */
ZEPHIR_DOC_METHOD(Phalcon_DataMapper_Pdo_Connection_ConnectionInterface, getAdapter);
/**
 * Returns the Profiler instance.
 *
 * @return ProfilerInterface
 */
ZEPHIR_DOC_METHOD(Phalcon_DataMapper_Pdo_Connection_ConnectionInterface, getProfiler);
/**
 * Is the PDO connection active?
 *
 * @return bool
 */
ZEPHIR_DOC_METHOD(Phalcon_DataMapper_Pdo_Connection_ConnectionInterface, isConnected);
/**
 * Performs a query with bound values and returns the resulting
 * PDOStatement; array values will be passed through `quote()` and their
 * respective placeholders will be replaced in the query string. If the
 * profiler is enabled, the operation will be recorded.
 *
 * @param string $statement
 * @param array  $values
 *
 * @return \PDOStatement
 */
ZEPHIR_DOC_METHOD(Phalcon_DataMapper_Pdo_Connection_ConnectionInterface, perform);
/**
 * Sets the Profiler instance.
 *
 * @param ProfilerInterface $profiler The Profiler instance.
 */
ZEPHIR_DOC_METHOD(Phalcon_DataMapper_Pdo_Connection_ConnectionInterface, setProfiler);
