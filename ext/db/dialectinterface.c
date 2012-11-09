
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
 * Phalcon\Db\DialectInterface initializer
 */
PHALCON_INIT_CLASS(Phalcon_Db_DialectInterface){

	PHALCON_REGISTER_CLASS(Phalcon\\Db, DialectInterface, db_dialectinterface, phalcon_db_dialectinterface_method_entry, ZEND_ACC_INTERFACE);

	return SUCCESS;
}

PHP_METHOD(Phalcon_Db_DialectInterface, limit){ }

PHP_METHOD(Phalcon_Db_DialectInterface, forUpdate){ }

PHP_METHOD(Phalcon_Db_DialectInterface, sharedLock){ }

PHP_METHOD(Phalcon_Db_DialectInterface, select){ }

PHP_METHOD(Phalcon_Db_DialectInterface, getColumnList){ }

PHP_METHOD(Phalcon_Db_DialectInterface, getColumnDefinition){ }

PHP_METHOD(Phalcon_Db_DialectInterface, addColumn){ }

PHP_METHOD(Phalcon_Db_DialectInterface, modifyColumn){ }

PHP_METHOD(Phalcon_Db_DialectInterface, dropColumn){ }

PHP_METHOD(Phalcon_Db_DialectInterface, addIndex){ }

PHP_METHOD(Phalcon_Db_DialectInterface, dropIndex){ }

PHP_METHOD(Phalcon_Db_DialectInterface, addPrimaryKey){ }

PHP_METHOD(Phalcon_Db_DialectInterface, dropPrimaryKey){ }

PHP_METHOD(Phalcon_Db_DialectInterface, addForeignKey){ }

PHP_METHOD(Phalcon_Db_DialectInterface, dropForeignKey){ }

PHP_METHOD(Phalcon_Db_DialectInterface, createTable){ }

PHP_METHOD(Phalcon_Db_DialectInterface, dropTable){ }

PHP_METHOD(Phalcon_Db_DialectInterface, tableExists){ }

PHP_METHOD(Phalcon_Db_DialectInterface, describeColumns){ }

PHP_METHOD(Phalcon_Db_DialectInterface, listTables){ }

PHP_METHOD(Phalcon_Db_DialectInterface, describeIndexes){ }

PHP_METHOD(Phalcon_Db_DialectInterface, describeReferences){ }

PHP_METHOD(Phalcon_Db_DialectInterface, tableOptions){ }

