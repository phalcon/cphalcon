
/*
  +------------------------------------------------------------------------+
  | Phalcon Framework                                                      |
  +------------------------------------------------------------------------+
  | Copyright (c) 2011-2014 Phalcon Team (http://www.phalconphp.com)       |
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

#include "db/resultinterface.h"
#include "kernel/main.h"

zend_class_entry *phalcon_db_resultinterface_ce;

static const zend_function_entry phalcon_db_resultinterface_method_entry[] = {
	PHP_ABSTRACT_ME(Phalcon_Db_ResultInterface, execute, arginfo_phalcon_db_resultinterface_execute)
	PHP_ABSTRACT_ME(Phalcon_Db_ResultInterface, fetch, arginfo_phalcon_db_resultinterface_fetch)
	PHP_ABSTRACT_ME(Phalcon_Db_ResultInterface, fetchArray, arginfo_phalcon_db_resultinterface_fetcharray)
	PHP_ABSTRACT_ME(Phalcon_Db_ResultInterface, fetchAll, arginfo_phalcon_db_resultinterface_fetchall)
	PHP_ABSTRACT_ME(Phalcon_Db_ResultInterface, numRows, arginfo_phalcon_db_resultinterface_numrows)
	PHP_ABSTRACT_ME(Phalcon_Db_ResultInterface, dataSeek, arginfo_phalcon_db_resultinterface_dataseek)
	PHP_ABSTRACT_ME(Phalcon_Db_ResultInterface, setFetchMode, arginfo_phalcon_db_resultinterface_setfetchmode)
	PHP_ABSTRACT_ME(Phalcon_Db_ResultInterface, getInternalResult, arginfo_phalcon_db_resultinterface_getinternalresult)
	PHP_FE_END
};

/**
 * Phalcon\Db\ResultInterface initializer
 */
PHALCON_INIT_CLASS(Phalcon_Db_ResultInterface){

	PHALCON_REGISTER_INTERFACE(Phalcon\\Db, ResultInterface, db_resultinterface, phalcon_db_resultinterface_method_entry);

	return SUCCESS;
}

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
