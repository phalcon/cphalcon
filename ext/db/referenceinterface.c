
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

#include "db/referenceinterface.h"
#include "kernel/main.h"

zend_class_entry *phalcon_db_referenceinterface_ce;

static const zend_function_entry phalcon_db_referenceinterface_method_entry[] = {
	PHP_ABSTRACT_ME(Phalcon_Db_ReferenceInterface, getName, NULL)
	PHP_ABSTRACT_ME(Phalcon_Db_ReferenceInterface, getSchemaName, NULL)
	PHP_ABSTRACT_ME(Phalcon_Db_ReferenceInterface, getReferencedSchema, NULL)
	PHP_ABSTRACT_ME(Phalcon_Db_ReferenceInterface, getColumns, NULL)
	PHP_ABSTRACT_ME(Phalcon_Db_ReferenceInterface, getReferencedTable, NULL)
	PHP_ABSTRACT_ME(Phalcon_Db_ReferenceInterface, getReferencedColumns, NULL)
	PHP_FE_END
};

/**
 * Phalcon\Db\ReferenceInterface initializer
 */
PHALCON_INIT_CLASS(Phalcon_Db_ReferenceInterface){

	PHALCON_REGISTER_INTERFACE(Phalcon\\Db, ReferenceInterface, db_referenceinterface, phalcon_db_referenceinterface_method_entry);

	return SUCCESS;
}

/**
 * Gets the index name
 *
 * @return string
 */
PHALCON_DOC_METHOD(Phalcon_Db_ReferenceInterface, getName);

/**
 * Gets the schema where referenced table is
 *
 * @return string
 */
PHALCON_DOC_METHOD(Phalcon_Db_ReferenceInterface, getSchemaName);

/**
 * Gets the schema where referenced table is
 *
 * @return string
 */
PHALCON_DOC_METHOD(Phalcon_Db_ReferenceInterface, getReferencedSchema);

/**
 * Gets local columns which reference is based
 *
 * @return array
 */
PHALCON_DOC_METHOD(Phalcon_Db_ReferenceInterface, getColumns);

/**
 * Gets the referenced table
 *
 * @return string
 */
PHALCON_DOC_METHOD(Phalcon_Db_ReferenceInterface, getReferencedTable);

/**
 * Gets referenced columns
 *
 * @return array
 */
PHALCON_DOC_METHOD(Phalcon_Db_ReferenceInterface, getReferencedColumns);
