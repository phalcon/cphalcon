
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

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_phalcon.h"
#include "phalcon.h"

#include "Zend/zend_operators.h"
#include "Zend/zend_exceptions.h"
#include "Zend/zend_interfaces.h"

#include "kernel/main.h"
#include "kernel/memory.h"

#include "kernel/exception.h"
#include "kernel/array.h"
#include "kernel/fcall.h"

/**
 * Phalcon\Db
 *
 * Phalcon\Db and its related classes provide a simple SQL database interface for Phalcon Framework.
 * The Phalcon\Db is the basic class you use to connect your PHP application to an RDBMS.
 * There is a different adapter class for each brand of RDBMS.
 *
 * This component is intended to lower level database operations. If you want to interact with databases using
 * higher level of abstraction use Phalcon\Mvc\Model.
 *
 * Phalcon\Db is an abstract class. You only can use it with a database adapter like Phalcon\Db\Adapter\Pdo
 *
 * <code>
 *
 *try {
 *
 *  $connection = new Phalcon\Db\Adapter\Pdo\Mysql(array(
 *     'host' => '192.168.0.11',
 *     'username' => 'sigma',
 *     'password' => 'secret',
 *     'dbname' => 'blog',
 *     'port' => '3306',
 *  ));
 *
 *  $result = $connection->query("SELECT * FROM robots LIMIT 5");
 *  $result->setFetchMode(Phalcon\Db::FETCH_NUM);
 *  while ($robot = $result->fetch()) {
 *    print_r($robot);
 *  }
 *
 *} catch (Phalcon\Db\Exception $e) {
 *	echo $e->getMessage(), PHP_EOL;
 *}
 *
 * </code>
 */


/**
 * Phalcon\Db initializer
 */
PHALCON_INIT_CLASS(Phalcon_Db){

	PHALCON_REGISTER_CLASS(Phalcon, Db, db, phalcon_db_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	zend_declare_class_constant_long(phalcon_db_ce, SL("FETCH_ASSOC"), 1 TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_db_ce, SL("FETCH_BOTH"), 2 TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_db_ce, SL("FETCH_NUM"), 3 TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_db_ce, SL("FETCH_OBJ"), 4 TSRMLS_CC);

	return SUCCESS;
}

/**
 * Enables/disables options in the Database component
 *
 * @param array $options
 */
PHP_METHOD(Phalcon_Db, setup){

	zval *options, *escape_identifiers;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &options);
	
	if (Z_TYPE_P(options) != IS_ARRAY) { 
		PHALCON_THROW_EXCEPTION_STR(phalcon_db_exception_ce, "Options must be an array");
		return;
	}
	
	/** 
	 * Enables/Disables globally the escaping of SQL identifiers
	 */
	if (phalcon_array_isset_string(options, SS("escapeSqlIdentifiers"))) {
		PHALCON_OBS_VAR(escape_identifiers);
		phalcon_array_fetch_string(&escape_identifiers, options, SL("escapeSqlIdentifiers"), PH_NOISY);
		PHALCON_GLOBAL(db).escape_identifiers = zend_is_true(escape_identifiers);
	}
	
	PHALCON_MM_RESTORE();
}

