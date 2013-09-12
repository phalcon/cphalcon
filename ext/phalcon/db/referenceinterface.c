
#ifdef HAVE_CONFIG_H
#include "ext_config.h"
#endif

#include "php.h"
#include "../php_ext.h"
#include "../ext.h"

#include "kernel/main.h"


/*
 +------------------------------------------------------------------------+
 | Phalcon Framework                                                      |
 +------------------------------------------------------------------------+
 | Copyright (c) 2011-2013 Phalcon Team (http://www.phalconphp.com)       |
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
/**
 * Phalcon\Db\Reference
 *
 * Interface for Phalcon\Db\Reference
 */
ZEPHIR_INIT_CLASS(Phalcon_Db_ReferenceInterface) {

	ZEPHIR_REGISTER_INTERFACE(Phalcon\\Db, ReferenceInterface, phalcon, db_referenceinterface, phalcon_db_referenceinterface_method_entry);


	return SUCCESS;

}

/**
 * Phalcon\Db\ReferenceInterface constructor
 *
 * @param string referenceName
 * @param array definition
 */
ZEPHIR_DOC_METHOD(Phalcon_Db_ReferenceInterface, __construct);

/**
 * Gets the index name
 *
 * @return string
 */
ZEPHIR_DOC_METHOD(Phalcon_Db_ReferenceInterface, getName);

/**
 * Gets the schema where referenced table is
 *
 * @return string
 */
ZEPHIR_DOC_METHOD(Phalcon_Db_ReferenceInterface, getSchemaName);

/**
 * Gets the schema where referenced table is
 *
 * @return string
 */
ZEPHIR_DOC_METHOD(Phalcon_Db_ReferenceInterface, getReferencedSchema);

/**
 * Gets local columns which reference is based
 *
 * @return array
 */
ZEPHIR_DOC_METHOD(Phalcon_Db_ReferenceInterface, getColumns);

/**
 * Gets the referenced table
 *
 * @return string
 */
ZEPHIR_DOC_METHOD(Phalcon_Db_ReferenceInterface, getReferencedTable);

/**
 * Gets referenced columns
 *
 * @return array
 */
ZEPHIR_DOC_METHOD(Phalcon_Db_ReferenceInterface, getReferencedColumns);

/**
 * Restore a Phalcon\Db\Reference object from export
 *
 * @param array data
 * @return Phalcon\Db\ReferenceInterface
 */
ZEPHIR_DOC_METHOD(Phalcon_Db_ReferenceInterface, __set_state);

