
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
 * Phalcon\Db\IndexInterface initializer
 */
PHALCON_INIT_CLASS(Phalcon_Db_IndexInterface){

	PHALCON_REGISTER_INTERFACE(Phalcon\\Db, IndexInterface, db_indexinterface, phalcon_db_indexinterface_method_entry);

	return SUCCESS;
}

/**
 * Phalcon\Db\Index constructor
 *
 * @param string $indexName
 * @param array $columns
 */
PHALCON_DOC_METHOD(Phalcon_Db_IndexInterface, __construct);
/**
 * Gets the index name
 *
 * @return string
 */
PHALCON_DOC_METHOD(Phalcon_Db_IndexInterface, getName);
/**
 * Gets the columns that comprends the index
 *
 * @return array
 */
PHALCON_DOC_METHOD(Phalcon_Db_IndexInterface, getColumns);
/**
 * Restore a Phalcon\Db\Index object from export
 *
 * @param array $data
 * @return Phalcon\Db\IndexInterface
 */
PHALCON_DOC_METHOD(Phalcon_Db_IndexInterface, __set_state);
