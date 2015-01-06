
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

#include "db/indexinterface.h"
#include "kernel/main.h"

zend_class_entry *phalcon_db_indexinterface_ce;

static const zend_function_entry phalcon_db_indexinterface_method_entry[] = {
	PHP_ABSTRACT_ME(Phalcon_Db_IndexInterface, getName, NULL)
	PHP_ABSTRACT_ME(Phalcon_Db_IndexInterface, getColumns, NULL)
	PHP_FE_END
};

/**
 * Phalcon\Db\IndexInterface initializer
 */
PHALCON_INIT_CLASS(Phalcon_Db_IndexInterface){

	PHALCON_REGISTER_INTERFACE(Phalcon\\Db, IndexInterface, db_indexinterface, phalcon_db_indexinterface_method_entry);

	return SUCCESS;
}

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
