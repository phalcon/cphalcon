
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

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
 * Interface for Phalcon\Db dialects
 */
ZEPHIR_INIT_CLASS(Phalcon_Db_DialectInterface) {

	ZEPHIR_REGISTER_INTERFACE(Phalcon\\Db, DialectInterface, phalcon, db_dialectinterface, phalcon_db_dialectinterface_method_entry);

	return SUCCESS;

}

/**
 * Generates SQL to add a column to a table
 */
ZEPHIR_DOC_METHOD(Phalcon_Db_DialectInterface, addColumn);
/**
 * Generates SQL to add an index to a table
 */
ZEPHIR_DOC_METHOD(Phalcon_Db_DialectInterface, addForeignKey);
/**
 * Generates SQL to add an index to a table
 */
ZEPHIR_DOC_METHOD(Phalcon_Db_DialectInterface, addIndex);
/**
 * Generates SQL to add the primary key to a table
 */
ZEPHIR_DOC_METHOD(Phalcon_Db_DialectInterface, addPrimaryKey);
/**
 * Generate SQL to create a new savepoint
 */
ZEPHIR_DOC_METHOD(Phalcon_Db_DialectInterface, createSavepoint);
/**
 * Generates SQL to create a table
 */
ZEPHIR_DOC_METHOD(Phalcon_Db_DialectInterface, createTable);
/**
 * Generates SQL to create a view
 */
ZEPHIR_DOC_METHOD(Phalcon_Db_DialectInterface, createView);
/**
 * Generates SQL to describe a table
 */
ZEPHIR_DOC_METHOD(Phalcon_Db_DialectInterface, describeColumns);
/**
 * Generates SQL to query indexes on a table
 */
ZEPHIR_DOC_METHOD(Phalcon_Db_DialectInterface, describeIndexes);
/**
 * Generates SQL to query foreign keys on a table
 */
ZEPHIR_DOC_METHOD(Phalcon_Db_DialectInterface, describeReferences);
/**
 * Generates SQL to delete a column from a table
 */
ZEPHIR_DOC_METHOD(Phalcon_Db_DialectInterface, dropColumn);
/**
 * Generates SQL to delete a foreign key from a table
 */
ZEPHIR_DOC_METHOD(Phalcon_Db_DialectInterface, dropForeignKey);
/**
 * Generates SQL to delete an index from a table
 */
ZEPHIR_DOC_METHOD(Phalcon_Db_DialectInterface, dropIndex);
/**
 * Generates SQL to delete primary key from a table
 */
ZEPHIR_DOC_METHOD(Phalcon_Db_DialectInterface, dropPrimaryKey);
/**
 * Generates SQL to drop a table
 */
ZEPHIR_DOC_METHOD(Phalcon_Db_DialectInterface, dropTable);
/**
 * Generates SQL to drop a view
 */
ZEPHIR_DOC_METHOD(Phalcon_Db_DialectInterface, dropView);
/**
 * Returns a SQL modified with a FOR UPDATE clause
 */
ZEPHIR_DOC_METHOD(Phalcon_Db_DialectInterface, forUpdate);
/**
 * Gets the column name in RDBMS
 */
ZEPHIR_DOC_METHOD(Phalcon_Db_DialectInterface, getColumnDefinition);
/**
 * Gets a list of columns
 */
ZEPHIR_DOC_METHOD(Phalcon_Db_DialectInterface, getColumnList);
/**
 * Returns registered functions
 */
ZEPHIR_DOC_METHOD(Phalcon_Db_DialectInterface, getCustomFunctions);
/**
 * Transforms an intermediate representation for an expression into a
 * database system valid expression
 */
ZEPHIR_DOC_METHOD(Phalcon_Db_DialectInterface, getSqlExpression);
/**
 * Generates the SQL for LIMIT clause
 */
ZEPHIR_DOC_METHOD(Phalcon_Db_DialectInterface, limit);
/**
 * List all tables in database
 */
ZEPHIR_DOC_METHOD(Phalcon_Db_DialectInterface, listTables);
/**
 * Generates SQL to modify a column in a table
 */
ZEPHIR_DOC_METHOD(Phalcon_Db_DialectInterface, modifyColumn);
/**
 * Registers custom SQL functions
 */
ZEPHIR_DOC_METHOD(Phalcon_Db_DialectInterface, registerCustomFunction);
/**
 * Generate SQL to release a savepoint
 */
ZEPHIR_DOC_METHOD(Phalcon_Db_DialectInterface, releaseSavepoint);
/**
 * Generate SQL to rollback a savepoint
 */
ZEPHIR_DOC_METHOD(Phalcon_Db_DialectInterface, rollbackSavepoint);
/**
 * Builds a SELECT statement
 */
ZEPHIR_DOC_METHOD(Phalcon_Db_DialectInterface, select);
/**
 * Returns a SQL modified with a LOCK IN SHARE MODE clause
 */
ZEPHIR_DOC_METHOD(Phalcon_Db_DialectInterface, sharedLock);
/**
 * Checks whether the platform supports releasing savepoints.
 */
ZEPHIR_DOC_METHOD(Phalcon_Db_DialectInterface, supportsReleaseSavepoints);
/**
 * Checks whether the platform supports savepoints
 */
ZEPHIR_DOC_METHOD(Phalcon_Db_DialectInterface, supportsSavepoints);
/**
 * Generates SQL checking for the existence of a schema.table
 */
ZEPHIR_DOC_METHOD(Phalcon_Db_DialectInterface, tableExists);
/**
 * Generates the SQL to describe the table creation options
 */
ZEPHIR_DOC_METHOD(Phalcon_Db_DialectInterface, tableOptions);
/**
 * Generates SQL checking for the existence of a schema.view
 */
ZEPHIR_DOC_METHOD(Phalcon_Db_DialectInterface, viewExists);
