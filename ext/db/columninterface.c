
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
 * Phalcon\Db\ColumnInterface initializer
 */
PHALCON_INIT_CLASS(Phalcon_Db_ColumnInterface){

	PHALCON_REGISTER_INTERFACE(Phalcon\\Db, ColumnInterface, db_columninterface, phalcon_db_columninterface_method_entry);

	return SUCCESS;
}

/**
 * Phalcon\Db\ColumnInterface constructor
 *
 * @param string $columnName
 * @param array $definition
 */
PHALCON_DOC_METHOD(Phalcon_Db_ColumnInterface, __construct);

/**
 * Returns schema's table related to column
 *
 * @return string
 */
PHALCON_DOC_METHOD(Phalcon_Db_ColumnInterface, getSchemaName);

/**
 * Returns column name
 *
 * @return string
 */
PHALCON_DOC_METHOD(Phalcon_Db_ColumnInterface, getName);

/**
 * Returns column type
 *
 * @return int
 */
PHALCON_DOC_METHOD(Phalcon_Db_ColumnInterface, getType);

/**
 * Returns column size
 *
 * @return int
 */
PHALCON_DOC_METHOD(Phalcon_Db_ColumnInterface, getSize);

/**
 * Returns column scale
 *
 * @return int
 */
PHALCON_DOC_METHOD(Phalcon_Db_ColumnInterface, getScale);

/**
 * Returns true if number column is unsigned
 *
 * @return boolean
 */
PHALCON_DOC_METHOD(Phalcon_Db_ColumnInterface, isUnsigned);

/**
 * Not null
 *
 * @return boolean
 */
PHALCON_DOC_METHOD(Phalcon_Db_ColumnInterface, isNotNull);

/**
 * Column is part of the primary key?
 *
 * @return boolean
 */
PHALCON_DOC_METHOD(Phalcon_Db_ColumnInterface, isPrimary);

/**
 * Auto-Increment
 *
 * @return boolean
 */
PHALCON_DOC_METHOD(Phalcon_Db_ColumnInterface, isAutoIncrement);

/**
 * Check whether column have an numeric type
 *
 * @return boolean
 */
PHALCON_DOC_METHOD(Phalcon_Db_ColumnInterface, isNumeric);

/**
 * Check whether column have first position in table
 *
 * @return boolean
 */
PHALCON_DOC_METHOD(Phalcon_Db_ColumnInterface, isFirst);

/**
 * Check whether field absolute to position in table
 *
 * @return string
 */
PHALCON_DOC_METHOD(Phalcon_Db_ColumnInterface, getAfterPosition);

/**
 * Returns the type of bind handling
 *
 * @return int
 */
PHALCON_DOC_METHOD(Phalcon_Db_ColumnInterface, getBindType);

/**
 * Restores the internal state of a Phalcon\Db\Column object
 *
 * @param array $data
 * @return \Phalcon\Db\ColumnInterface
 */
PHALCON_DOC_METHOD(Phalcon_Db_ColumnInterface, __set_state);

