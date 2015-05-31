
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


/**
 * Phalcon\Db\ResultInterface
 *
 * Interface for Phalcon\Db\Result objects
 */
ZEPHIR_INIT_CLASS(Phalcon_Db_ResultInterface) {

	ZEPHIR_REGISTER_INTERFACE(Phalcon\\Db, ResultInterface, phalcon, db_resultinterface, phalcon_db_resultinterface_method_entry);

	return SUCCESS;

}

/**
 * Phalcon\Db\Result\Pdo constructor
 *
 * @param Phalcon\Db\AdapterInterface connection
 * @param \PDOStatement result
 * @param string sqlStatement
 * @param array bindParams
 * @param array bindTypes
 */
ZEPHIR_DOC_METHOD(Phalcon_Db_ResultInterface, __construct);

/**
 * Allows to executes the statement again. Some database systems don't support scrollable cursors,
 * So, as cursors are forward only, we need to execute the cursor again to fetch rows from the begining
 *
 * @return boolean
 */
ZEPHIR_DOC_METHOD(Phalcon_Db_ResultInterface, execute);

/**
 * Fetches an array/object of strings that corresponds to the fetched row, or FALSE if there are no more rows.
 * This method is affected by the active fetch flag set using Phalcon\Db\Result\Pdo::setFetchMode
 *
 * @return mixed
 */
ZEPHIR_DOC_METHOD(Phalcon_Db_ResultInterface, fetch);

/**
 * Returns an array of strings that corresponds to the fetched row, or FALSE if there are no more rows.
 * This method is affected by the active fetch flag set using Phalcon\Db\Result\Pdo::setFetchMode
 *
 * @return mixed
 */
ZEPHIR_DOC_METHOD(Phalcon_Db_ResultInterface, fetchArray);

/**
 * Returns an array of arrays containing all the records in the result
 * This method is affected by the active fetch flag set using Phalcon\Db\Result\Pdo::setFetchMode
 *
 * @return array
 */
ZEPHIR_DOC_METHOD(Phalcon_Db_ResultInterface, fetchAll);

/**
 * Gets number of rows returned by a resultset
 *
 * @return int
 */
ZEPHIR_DOC_METHOD(Phalcon_Db_ResultInterface, numRows);

/**
 * Moves internal resultset cursor to another position letting us to fetch a certain row
 *
 * @param int number
 */
ZEPHIR_DOC_METHOD(Phalcon_Db_ResultInterface, dataSeek);

/**
 * Changes the fetching mode affecting Phalcon\Db\Result\Pdo::fetch()
 *
 * @param int fetchMode
 */
ZEPHIR_DOC_METHOD(Phalcon_Db_ResultInterface, setFetchMode);

/**
 * Gets the internal PDO result object
 *
 * @return \PDOStatement
 */
ZEPHIR_DOC_METHOD(Phalcon_Db_ResultInterface, getInternalResult);

