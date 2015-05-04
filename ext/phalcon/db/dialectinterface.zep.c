
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


/**
 * Phalcon\Db\DialectInterface
 *
 * Interface for Phalcon\Db dialects
 */
ZEPHIR_INIT_CLASS(Phalcon_Db_DialectInterface) {

	ZEPHIR_REGISTER_INTERFACE(Phalcon\\Db, DialectInterface, phalcon, db_dialectinterface, phalcon_db_dialectinterface_method_entry);

	return SUCCESS;

}

/**
 * Generates the SQL for LIMIT clause
 */
ZEPHIR_DOC_METHOD(Phalcon_Db_DialectInterface, limit);

/**
 * Returns a SQL modified with a FOR UPDATE clause
 */
ZEPHIR_DOC_METHOD(Phalcon_Db_DialectInterface, forUpdate);

/**
 * Returns a SQL modified with a LOCK IN SHARE MODE clause
 */
ZEPHIR_DOC_METHOD(Phalcon_Db_DialectInterface, sharedLock);

/**
 * Builds a SELECT statement
 */
ZEPHIR_DOC_METHOD(Phalcon_Db_DialectInterface, select);

/**
 * Gets a list of columns
 */
ZEPHIR_DOC_METHOD(Phalcon_Db_DialectInterface, getColumnList);

/**
 * Gets the column name in RDBMS
 */
ZEPHIR_DOC_METHOD(Phalcon_Db_DialectInterface, getColumnDefinition);

/**
 * Generates SQL to add a column to a table
 */
ZEPHIR_DOC_METHOD(Phalcon_Db_DialectInterface, addColumn);

/**
 * Generates SQL to modify a column in a table
 */
ZEPHIR_DOC_METHOD(Phalcon_Db_DialectInterface, modifyColumn);

/**
 * Generates SQL to delete a column from a table
 */
ZEPHIR_DOC_METHOD(Phalcon_Db_DialectInterface, dropColumn);

/**
 * Generates SQL to add an index to a table
 */
ZEPHIR_DOC_METHOD(Phalcon_Db_DialectInterface, addIndex);

/**
 * Generates SQL to delete an index from a table
 */
ZEPHIR_DOC_METHOD(Phalcon_Db_DialectInterface, dropIndex);

/**
 * Generates SQL to add the primary key to a table
 */
ZEPHIR_DOC_METHOD(Phalcon_Db_DialectInterface, addPrimaryKey);

/**
 * Generates SQL to delete primary key from a table
 */
ZEPHIR_DOC_METHOD(Phalcon_Db_DialectInterface, dropPrimaryKey);

/**
 * Generates SQL to add an index to a table
 */
ZEPHIR_DOC_METHOD(Phalcon_Db_DialectInterface, addForeignKey);

/**
 * Generates SQL to delete a foreign key from a table
 */
ZEPHIR_DOC_METHOD(Phalcon_Db_DialectInterface, dropForeignKey);

/**
 * Generates SQL to create a table
 */
ZEPHIR_DOC_METHOD(Phalcon_Db_DialectInterface, createTable);

/**
 * Generates SQL to create a view
 */
ZEPHIR_DOC_METHOD(Phalcon_Db_DialectInterface, createView);

/**
 * Generates SQL to drop a table
 */
ZEPHIR_DOC_METHOD(Phalcon_Db_DialectInterface, dropTable);

/**
 * Generates SQL to drop a view
 */
ZEPHIR_DOC_METHOD(Phalcon_Db_DialectInterface, dropView);

/**
 * Generates SQL checking for the existence of a schema.table
 */
ZEPHIR_DOC_METHOD(Phalcon_Db_DialectInterface, tableExists);

/**
 * Generates SQL checking for the existence of a schema.view
 */
ZEPHIR_DOC_METHOD(Phalcon_Db_DialectInterface, viewExists);

/**
 * Generates SQL to describe a table
 */
ZEPHIR_DOC_METHOD(Phalcon_Db_DialectInterface, describeColumns);

/**
 * List all tables in database
 */
ZEPHIR_DOC_METHOD(Phalcon_Db_DialectInterface, listTables);

/**
 * Generates SQL to query indexes on a table
 */
ZEPHIR_DOC_METHOD(Phalcon_Db_DialectInterface, describeIndexes);

/**
 * Generates SQL to query foreign keys on a table
 */
ZEPHIR_DOC_METHOD(Phalcon_Db_DialectInterface, describeReferences);

/**
 * Generates the SQL to describe the table creation options
 */
ZEPHIR_DOC_METHOD(Phalcon_Db_DialectInterface, tableOptions);

/**
 * Checks whether the platform supports savepoints
 */
ZEPHIR_DOC_METHOD(Phalcon_Db_DialectInterface, supportsSavepoints);

/**
 * Checks whether the platform supports releasing savepoints.
 */
ZEPHIR_DOC_METHOD(Phalcon_Db_DialectInterface, supportsReleaseSavepoints);

/**
 * Generate SQL to create a new savepoint
 */
ZEPHIR_DOC_METHOD(Phalcon_Db_DialectInterface, createSavepoint);

/**
 * Generate SQL to release a savepoint
 */
ZEPHIR_DOC_METHOD(Phalcon_Db_DialectInterface, releaseSavepoint);

/**
 * Generate SQL to rollback a savepoint
 */
ZEPHIR_DOC_METHOD(Phalcon_Db_DialectInterface, rollbackSavepoint);

