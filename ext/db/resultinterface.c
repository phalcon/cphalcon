
/*
  +------------------------------------------------------------------------+
  | Phalcon Framework                                                      |
  +------------------------------------------------------------------------+
  | Copyright (c) 2011-2012 Phalcon Team (http://www.phalconphp.com)       |
  +------------------------------------------------------------------------+
  | This source file is subject to the New BSD License that is bundled     |
  | with this package in the file docs/LICENSE.txt.                        |
  |                                                                        |
  | If you did not receive a copy of the license and are unable to         |
  | obtain it through the world-wide-web, please send an email             |
  | to license@phalconphp.com so we can send you a copy immediately.       |
  +------------------------------------------------------------------------+
  | Authors: Andres Gutierrez <andres@phalconphp.com>                      |
  |          Eduar Carvajal <eduar@phalconphp.com>                         |
  +------------------------------------------------------------------------+
*/

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_phalcon.h"
#include "phalcon.h"

#include "kernel/main.h"

/**
 * Phalcon\Db\ResultInterface initializer
 */
PHALCON_INIT_CLASS(Phalcon_Db_ResultInterface){

	PHALCON_REGISTER_INTERFACE(Phalcon\\Db, ResultInterface, db_resultinterface, phalcon_db_resultinterface_method_entry);

	return SUCCESS;
}

/**
 * Phalcon\Db\Result\Pdo constructor
 *
 * @param Phalcon\Db\AdapterInterface $connection
 * @param string $sqlStatement
 * @param array $bindParams
 * @param array $bindTypes
 * @param \PDOStatement $result
 */
PHALCON_DOC_METHOD(Phalcon_Db_ResultInterface, __construct);

/**
 * Allows to executes the statement again. Some database systems don't support scrollable cursors,
 * So, as cursors are forward only, we need to execute the cursor again to fetch rows from the begining
 *
 * @return boolean
 */
PHALCON_DOC_METHOD(Phalcon_Db_ResultInterface, execute);

/**
 * Fetches an array/object of strings that corresponds to the fetched row, or FALSE if there are no more rows.
 * This method is affected by the active fetch flag set using Phalcon\Db\Result\Pdo::setFetchMode
 *
 * @return mixed
 */
PHALCON_DOC_METHOD(Phalcon_Db_ResultInterface, fetch);

/**
 * Returns an array of strings that corresponds to the fetched row, or FALSE if there are no more rows.
 * This method is affected by the active fetch flag set using Phalcon\Db\Result\Pdo::setFetchMode
 *
 * @return mixed
 */
PHALCON_DOC_METHOD(Phalcon_Db_ResultInterface, fetchArray);

/**
 * Returns an array of arrays containing all the records in the result
 * This method is affected by the active fetch flag set using Phalcon\Db\Result\Pdo::setFetchMode
 *
 * @return array
 */
PHALCON_DOC_METHOD(Phalcon_Db_ResultInterface, fetchAll);

/**
 * Gets number of rows returned by a resulset
 *
 * @return int
 */
PHALCON_DOC_METHOD(Phalcon_Db_ResultInterface, numRows);

/**
 * Moves internal resulset cursor to another position letting us to fetch a certain row
 *
 * @param int $number
 */
PHALCON_DOC_METHOD(Phalcon_Db_ResultInterface, dataSeek);

/**
 * Changes the fetching mode affecting Phalcon\Db\Result\Pdo::fetch()
 *
 * @param int $fetchMode
 */
PHALCON_DOC_METHOD(Phalcon_Db_ResultInterface, setFetchMode);

/**
 * Gets the internal PDO result object
 *
 * @return \PDOStatement
 */
PHALCON_DOC_METHOD(Phalcon_Db_ResultInterface, getInternalResult);

