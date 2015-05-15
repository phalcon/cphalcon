
#ifdef HAVE_CONFIG_H
#include "../ext_config.h"
#endif

#include <php.h>
#include "../php_ext.h"
#include "../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/array.h"
#include "kernel/memory.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"


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
 *  $connection = new \Phalcon\Db\Adapter\Pdo\Mysql(array(
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
ZEPHIR_INIT_CLASS(Phalcon_Db) {

	ZEPHIR_REGISTER_CLASS(Phalcon, Db, phalcon, db, phalcon_db_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	zend_declare_class_constant_long(phalcon_db_ce, SL("FETCH_LAZY"), 1 TSRMLS_CC);

	zend_declare_class_constant_long(phalcon_db_ce, SL("FETCH_ASSOC"), 2 TSRMLS_CC);

	zend_declare_class_constant_long(phalcon_db_ce, SL("FETCH_NAMED"), 11 TSRMLS_CC);

	zend_declare_class_constant_long(phalcon_db_ce, SL("FETCH_NUM"), 3 TSRMLS_CC);

	zend_declare_class_constant_long(phalcon_db_ce, SL("FETCH_BOTH"), 4 TSRMLS_CC);

	zend_declare_class_constant_long(phalcon_db_ce, SL("FETCH_OBJ"), 5 TSRMLS_CC);

	zend_declare_class_constant_long(phalcon_db_ce, SL("FETCH_BOUND"), 6 TSRMLS_CC);

	zend_declare_class_constant_long(phalcon_db_ce, SL("FETCH_COLUMN"), 7 TSRMLS_CC);

	zend_declare_class_constant_long(phalcon_db_ce, SL("FETCH_CLASS"), 8 TSRMLS_CC);

	zend_declare_class_constant_long(phalcon_db_ce, SL("FETCH_INTO"), 9 TSRMLS_CC);

	zend_declare_class_constant_long(phalcon_db_ce, SL("FETCH_FUNC"), 10 TSRMLS_CC);

	zend_declare_class_constant_long(phalcon_db_ce, SL("FETCH_GROUP"), 65536 TSRMLS_CC);

	zend_declare_class_constant_long(phalcon_db_ce, SL("FETCH_UNIQUE"), 196608 TSRMLS_CC);

	zend_declare_class_constant_long(phalcon_db_ce, SL("FETCH_KEY_PAIR"), 12 TSRMLS_CC);

	zend_declare_class_constant_long(phalcon_db_ce, SL("FETCH_CLASSTYPE"), 262144 TSRMLS_CC);

	zend_declare_class_constant_long(phalcon_db_ce, SL("FETCH_SERIALIZE"), 524288 TSRMLS_CC);

	zend_declare_class_constant_long(phalcon_db_ce, SL("FETCH_PROPS_LATE"), 1048576 TSRMLS_CC);

	return SUCCESS;

}

/**
 * Enables/disables options in the Database component
 */
PHP_METHOD(Phalcon_Db, setup) {

	zval *options_param = NULL, *escapeIdentifiers;
	zval *options = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &options_param);

	options = options_param;



	ZEPHIR_OBS_VAR(escapeIdentifiers);
	if (zephir_array_isset_string_fetch(&escapeIdentifiers, options, SS("escapeSqlIdentifiers"), 0 TSRMLS_CC)) {
		ZEPHIR_GLOBAL(db).escape_identifiers = zend_is_true(escapeIdentifiers);
	}
	ZEPHIR_MM_RESTORE();

}

