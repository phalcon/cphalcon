
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

#include "db.h"
#include "db/exception.h"

#include "ext/pdo/php_pdo_driver.h"

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
zend_class_entry *phalcon_db_ce;

PHP_METHOD(Phalcon_Db, setup);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_setup, 0, 0, 1)
	ZEND_ARG_INFO(0, options)
ZEND_END_ARG_INFO()

static const zend_function_entry phalcon_db_method_entry[] = {
	PHP_ME(Phalcon_Db, setup, arginfo_phalcon_db_setup, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};

/**
 * Phalcon\Db initializer
 */
PHALCON_INIT_CLASS(Phalcon_Db){

	PHALCON_REGISTER_CLASS(Phalcon, Db, db, phalcon_db_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	zend_declare_class_constant_long(phalcon_db_ce, SL("FETCH_USE_DEFAULT"), (long int)PDO_FETCH_USE_DEFAULT TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_db_ce, SL("FETCH_LAZY"),        (long int)PDO_FETCH_LAZY TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_db_ce, SL("FETCH_ASSOC"),       (long int)PDO_FETCH_ASSOC TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_db_ce, SL("FETCH_NUM"),         (long int)PDO_FETCH_NUM TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_db_ce, SL("FETCH_BOTH"),        (long int)PDO_FETCH_BOTH TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_db_ce, SL("FETCH_OBJ"),         (long int)PDO_FETCH_OBJ TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_db_ce, SL("FETCH_BOUND"),       (long int)PDO_FETCH_BOUND TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_db_ce, SL("FETCH_COLUMN"),      (long int)PDO_FETCH_COLUMN TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_db_ce, SL("FETCH_CLASS"),       (long int)PDO_FETCH_CLASS TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_db_ce, SL("FETCH_INTO"),        (long int)PDO_FETCH_INTO TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_db_ce, SL("FETCH_FUNC"),        (long int)PDO_FETCH_FUNC TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_db_ce, SL("FETCH_NAMED"),       (long int)PDO_FETCH_NAMED TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_db_ce, SL("FETCH_KEY_PAIR") ,   (long int)PDO_FETCH_KEY_PAIR TSRMLS_CC);

	zend_declare_class_constant_long(phalcon_db_ce, SL("FETCH_GROUP"),       (long int)PDO_FETCH_GROUP TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_db_ce, SL("FETCH_UNIQUE"),      (long int)PDO_FETCH_UNIQUE TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_db_ce, SL("FETCH_CLASSTYPE"),   (long int)PDO_FETCH_CLASSTYPE TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_db_ce, SL("FETCH_SERIALIZE"),   (long int)PDO_FETCH_SERIALIZE TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_db_ce, SL("FETCH_PROPS_LATE"),  (long int)PDO_FETCH_PROPS_LATE TSRMLS_CC);

	return SUCCESS;
}

/**
 * Enables/disables options in the Database component
 *
 * @param array $options
 */
PHP_METHOD(Phalcon_Db, setup){

	zval *options, *escape_identifiers;

	phalcon_fetch_params(0, 1, 0, &options);

	if (Z_TYPE_P(options) != IS_ARRAY) { 
		PHALCON_THROW_EXCEPTION_STRW(phalcon_db_exception_ce, "Options must be an array");
		return;
	}

	/**
	 * Enables/Disables globally the escaping of SQL identifiers
	 */
	if (phalcon_array_isset_string_fetch(&escape_identifiers, options, SS("escapeSqlIdentifiers"))) {
		PHALCON_GLOBAL(db).escape_identifiers = zend_is_true(escape_identifiers);
	}
}
