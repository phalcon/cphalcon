
#ifdef HAVE_CONFIG_H
#include "../../../../ext_config.h"
#endif

#include <php.h>
#include "../../../../php_ext.h"
#include "../../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/fcall.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/memory.h"
#include "kernel/object.h"
#include "kernel/operators.h"
#include "kernel/array.h"
#include "kernel/concat.h"
#include "kernel/string.h"
#include "ext/pdo/php_pdo_driver.h"
#include "kernel/main.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */
/**
 * Phalcon\Db\Adapter\Pdo is the Phalcon\Db that internally uses PDO to connect
 * to a database
 *
 * ```php
 * use Phalcon\Db\Adapter\Pdo\Mysql;
 *
 * $config = [
 *     "host"     => "localhost",
 *     "dbname"   => "blog",
 *     "port"     => 3306,
 *     "username" => "sigma",
 *     "password" => "secret",
 * ];
 *
 * $connection = new Mysql($config);
 *```
 */
ZEPHIR_INIT_CLASS(Phalcon_Db_Adapter_Pdo_AbstractPdo)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Db\\Adapter\\Pdo, AbstractPdo, phalcon, db_adapter_pdo_abstractpdo, phalcon_db_adapter_abstractadapter_ce, phalcon_db_adapter_pdo_abstractpdo_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	/**
	 * Last affected rows
	 *
	 * @var int
	 */
	zend_declare_property_long(phalcon_db_adapter_pdo_abstractpdo_ce, SL("affectedRows"), 0, ZEND_ACC_PROTECTED);
	/**
	 * PDO Handler
	 *
	 * @var \PDO
	 */
	zend_declare_property_null(phalcon_db_adapter_pdo_abstractpdo_ce, SL("pdo"), ZEND_ACC_PROTECTED);
	return SUCCESS;
}

/**
 * Constructor for Phalcon\Db\Adapter\Pdo
 *
 * @param array descriptor = [
 *     'host' => 'localhost',
 *     'port' => '3306',
 *     'dbname' => 'blog',
 *     'username' => 'sigma'
 *     'password' => 'secret'
 *     'dialectClass' => null,
 *     'options' => [],
 *     'dsn' => null,
 *     'charset' => 'utf8mb4'
 * ]
 */
PHP_METHOD(Phalcon_Db_Adapter_Pdo_AbstractPdo, __construct)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_0 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *descriptor_param = NULL;
	zval descriptor;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&descriptor);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ARRAY(descriptor)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &descriptor_param);
	ZEPHIR_OBS_COPY_OR_DUP(&descriptor, descriptor_param);


	ZEPHIR_CALL_METHOD(NULL, this_ptr, "connect", NULL, 0, &descriptor);
	zephir_check_call_status();
	ZEPHIR_CALL_PARENT(NULL, phalcon_db_adapter_pdo_abstractpdo_ce, getThis(), "__construct", &_0, 0, &descriptor);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
}

/**
 * Returns the number of affected rows by the latest INSERT/UPDATE/DELETE
 * executed in the database system
 *
 *```php
 * $connection->execute(
 *     "DELETE FROM robots"
 * );
 *
 * echo $connection->affectedRows(), " were deleted";
 *```
 */
PHP_METHOD(Phalcon_Db_Adapter_Pdo_AbstractPdo, affectedRows)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "affectedRows");
}

/**
 * Starts a transaction in the connection
 */
PHP_METHOD(Phalcon_Db_Adapter_Pdo_AbstractPdo, begin)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS, transactionLevel = 0;
	zval *nesting_param = NULL, eventsManager, savepointName, _0, _5, _6, _1$$3, _2$$4, _7$$6;
	zend_bool nesting, _3, _4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&eventsManager);
	ZVAL_UNDEF(&savepointName);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_7$$6);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_BOOL(nesting)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &nesting_param);
	if (!nesting_param) {
		nesting = 1;
	} else {
		nesting = zephir_get_boolval(nesting_param);
	}


	RETURN_ON_FAILURE(zephir_property_incr(this_ptr, SL("transactionLevel")));
	ZEPHIR_OBS_VAR(&_0);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("transactionLevel"), PH_NOISY_CC);
	transactionLevel = zephir_get_intval(&_0);
	if (transactionLevel == 1) {
		zephir_read_property(&_1$$3, this_ptr, ZEND_STRL("eventsManager"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CPY_WRT(&eventsManager, &_1$$3);
		if (Z_TYPE_P(&eventsManager) == IS_OBJECT) {
			ZEPHIR_INIT_VAR(&_2$$4);
			ZVAL_STRING(&_2$$4, "db:beginTransaction");
			ZEPHIR_CALL_METHOD(NULL, &eventsManager, "fire", NULL, 0, &_2$$4, this_ptr);
			zephir_check_call_status();
		}
		zephir_read_property(&_1$$3, this_ptr, ZEND_STRL("pdo"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_RETURN_CALL_METHOD(&_1$$3, "begintransaction", NULL, 0);
		zephir_check_call_status();
		RETURN_MM();
	}
	_3 = !transactionLevel;
	if (!(_3)) {
		_3 = !nesting;
	}
	_4 = _3;
	if (!(_4)) {
		ZEPHIR_CALL_METHOD(&_5, this_ptr, "isnestedtransactionswithsavepoints", NULL, 0);
		zephir_check_call_status();
		_4 = !zephir_is_true(&_5);
	}
	if (_4) {
		RETURN_MM_BOOL(0);
	}
	zephir_read_property(&_6, this_ptr, ZEND_STRL("eventsManager"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&eventsManager, &_6);
	ZEPHIR_CALL_METHOD(&savepointName, this_ptr, "getnestedtransactionsavepointname", NULL, 0);
	zephir_check_call_status();
	if (Z_TYPE_P(&eventsManager) == IS_OBJECT) {
		ZEPHIR_INIT_VAR(&_7$$6);
		ZVAL_STRING(&_7$$6, "db:createSavepoint");
		ZEPHIR_CALL_METHOD(NULL, &eventsManager, "fire", NULL, 0, &_7$$6, this_ptr, &savepointName);
		zephir_check_call_status();
	}
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "createsavepoint", NULL, 0, &savepointName);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Commits the active transaction in the connection
 */
PHP_METHOD(Phalcon_Db_Adapter_Pdo_AbstractPdo, commit)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS, transactionLevel = 0;
	zval *nesting_param = NULL, eventsManager, savepointName, _0, _5, _6, _1$$4, _2$$5, _7$$8;
	zend_bool nesting, _3, _4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&eventsManager);
	ZVAL_UNDEF(&savepointName);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&_2$$5);
	ZVAL_UNDEF(&_7$$8);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_BOOL(nesting)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &nesting_param);
	if (!nesting_param) {
		nesting = 1;
	} else {
		nesting = zephir_get_boolval(nesting_param);
	}


	ZEPHIR_OBS_VAR(&_0);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("transactionLevel"), PH_NOISY_CC);
	transactionLevel = zephir_get_intval(&_0);
	if (UNEXPECTED(!transactionLevel)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_db_exception_ce, "There is no active transaction", "phalcon/Db/Adapter/Pdo/AbstractPdo.zep", 154);
		return;
	}
	if (transactionLevel == 1) {
		zephir_read_property(&_1$$4, this_ptr, ZEND_STRL("eventsManager"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CPY_WRT(&eventsManager, &_1$$4);
		if (Z_TYPE_P(&eventsManager) == IS_OBJECT) {
			ZEPHIR_INIT_VAR(&_2$$5);
			ZVAL_STRING(&_2$$5, "db:commitTransaction");
			ZEPHIR_CALL_METHOD(NULL, &eventsManager, "fire", NULL, 0, &_2$$5, this_ptr);
			zephir_check_call_status();
		}
		RETURN_ON_FAILURE(zephir_property_decr(this_ptr, SL("transactionLevel")));
		zephir_read_property(&_1$$4, this_ptr, ZEND_STRL("pdo"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_RETURN_CALL_METHOD(&_1$$4, "commit", NULL, 0);
		zephir_check_call_status();
		RETURN_MM();
	}
	_3 = !transactionLevel;
	if (!(_3)) {
		_3 = !nesting;
	}
	_4 = _3;
	if (!(_4)) {
		ZEPHIR_CALL_METHOD(&_5, this_ptr, "isnestedtransactionswithsavepoints", NULL, 0);
		zephir_check_call_status();
		_4 = !zephir_is_true(&_5);
	}
	if (_4) {
		if (transactionLevel > 0) {
			RETURN_ON_FAILURE(zephir_property_decr(this_ptr, SL("transactionLevel")));
		}
		RETURN_MM_BOOL(0);
	}
	zephir_read_property(&_6, this_ptr, ZEND_STRL("eventsManager"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&eventsManager, &_6);
	ZEPHIR_CALL_METHOD(&savepointName, this_ptr, "getnestedtransactionsavepointname", NULL, 0);
	zephir_check_call_status();
	if (Z_TYPE_P(&eventsManager) == IS_OBJECT) {
		ZEPHIR_INIT_VAR(&_7$$8);
		ZVAL_STRING(&_7$$8, "db:releaseSavepoint");
		ZEPHIR_CALL_METHOD(NULL, &eventsManager, "fire", NULL, 0, &_7$$8, this_ptr, &savepointName);
		zephir_check_call_status();
	}
	RETURN_ON_FAILURE(zephir_property_decr(this_ptr, SL("transactionLevel")));
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "releasesavepoint", NULL, 0, &savepointName);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Closes the active connection returning success. Phalcon automatically
 * closes and destroys active connections when the request ends
 */
PHP_METHOD(Phalcon_Db_Adapter_Pdo_AbstractPdo, close)
{
	zval __$null;
	zval *this_ptr = getThis();

	ZVAL_NULL(&__$null);



	zephir_update_property_zval(this_ptr, ZEND_STRL("pdo"), &__$null);
}

/**
 * This method is automatically called in \Phalcon\Db\Adapter\Pdo
 * constructor.
 *
 * Call it when you need to restore a database connection.
 *
 *```php
 * use Phalcon\Db\Adapter\Pdo\Mysql;
 *
 * // Make a connection
 * $connection = new Mysql(
 *     [
 *         "host"     => "localhost",
 *         "username" => "sigma",
 *         "password" => "secret",
 *         "dbname"   => "blog",
 *         "port"     => 3306,
 *     ]
 * );
 *
 * // Reconnect
 * $connection->connect();
 * ```
 */
PHP_METHOD(Phalcon_Db_Adapter_Pdo_AbstractPdo, connect)
{
	zend_string *_9;
	zend_ulong _8;
	zend_bool _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *descriptor_param = NULL, username, password, dsnAttributes, dsnAttributesCustomRaw, dsnAttributesMap, key, options, persistent, value, _2, _4, _5, *_6, _7, _12, _13, _14, _0$$3, _3$$9, _10$$11, _11$$12;
	zval descriptor, dsnParts;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&descriptor);
	ZVAL_UNDEF(&dsnParts);
	ZVAL_UNDEF(&username);
	ZVAL_UNDEF(&password);
	ZVAL_UNDEF(&dsnAttributes);
	ZVAL_UNDEF(&dsnAttributesCustomRaw);
	ZVAL_UNDEF(&dsnAttributesMap);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&options);
	ZVAL_UNDEF(&persistent);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_12);
	ZVAL_UNDEF(&_13);
	ZVAL_UNDEF(&_14);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_3$$9);
	ZVAL_UNDEF(&_10$$11);
	ZVAL_UNDEF(&_11$$12);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_ARRAY(descriptor)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &descriptor_param);
	if (!descriptor_param) {
		ZEPHIR_INIT_VAR(&descriptor);
		array_init(&descriptor);
	} else {
	ZEPHIR_OBS_COPY_OR_DUP(&descriptor, descriptor_param);
	}


	ZEPHIR_INIT_VAR(&dsnParts);
	array_init(&dsnParts);
	if (ZEPHIR_IS_EMPTY(&descriptor)) {
		zephir_read_property(&_0$$3, this_ptr, ZEND_STRL("descriptor"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CPY_WRT(&descriptor, &_0$$3);
	}
	ZEPHIR_OBS_VAR(&username);
	if (zephir_array_isset_string_fetch(&username, &descriptor, SL("username"), 0)) {
		zephir_array_unset_string(&descriptor, SL("username"), PH_SEPARATE);
	}
	ZEPHIR_OBS_VAR(&password);
	if (zephir_array_isset_string_fetch(&password, &descriptor, SL("password"), 0)) {
		zephir_array_unset_string(&descriptor, SL("password"), PH_SEPARATE);
	}
	if (zephir_array_isset_string(&descriptor, SL("dialectClass"))) {
		zephir_array_unset_string(&descriptor, SL("dialectClass"), PH_SEPARATE);
	}
	_1 = zephir_array_isset_string(&descriptor, SL("options"));
	if (_1) {
		zephir_array_fetch_string(&_2, &descriptor, SL("options"), PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/AbstractPdo.zep", 268);
		_1 = Z_TYPE_P(&_2) == IS_ARRAY;
	}
	if (_1) {
		ZEPHIR_OBS_VAR(&options);
		zephir_array_fetch_string(&options, &descriptor, SL("options"), PH_NOISY, "phalcon/Db/Adapter/Pdo/AbstractPdo.zep", 269);
		zephir_array_unset_string(&descriptor, SL("options"), PH_SEPARATE);
	} else {
		ZEPHIR_INIT_NVAR(&options);
		array_init(&options);
	}
	ZEPHIR_OBS_VAR(&persistent);
	if (zephir_array_isset_string_fetch(&persistent, &descriptor, SL("persistent"), 0)) {
		ZEPHIR_INIT_VAR(&_3$$9);
		ZVAL_BOOL(&_3$$9, zephir_get_boolval(&persistent));
		zephir_array_update_long(&options, 12, &_3$$9, PH_COPY | PH_SEPARATE ZEPHIR_DEBUG_PARAMS_DUMMY);
	}
	ZEPHIR_INIT_VAR(&_4);
	ZVAL_LONG(&_4, 2);
	zephir_array_update_long(&options, 3, &_4, PH_COPY | PH_SEPARATE ZEPHIR_DEBUG_PARAMS_DUMMY);
	ZEPHIR_OBS_VAR(&dsnAttributesCustomRaw);
	if (zephir_array_isset_string_fetch(&dsnAttributesCustomRaw, &descriptor, SL("dsn"), 0)) {
		zephir_array_append(&dsnParts, &dsnAttributesCustomRaw, PH_SEPARATE, "phalcon/Db/Adapter/Pdo/AbstractPdo.zep", 285);
		zephir_array_unset_string(&descriptor, SL("dsn"), PH_SEPARATE);
	}
	ZEPHIR_CALL_METHOD(&_5, this_ptr, "getdsndefaults", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&dsnAttributesMap);
	zephir_fast_array_merge(&dsnAttributesMap, &_5, &descriptor);
	zephir_is_iterable(&dsnAttributesMap, 0, "phalcon/Db/Adapter/Pdo/AbstractPdo.zep", 305);
	if (Z_TYPE_P(&dsnAttributesMap) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&dsnAttributesMap), _8, _9, _6)
		{
			ZEPHIR_INIT_NVAR(&key);
			if (_9 != NULL) { 
				ZVAL_STR_COPY(&key, _9);
			} else {
				ZVAL_LONG(&key, _8);
			}
			ZEPHIR_INIT_NVAR(&value);
			ZVAL_COPY(&value, _6);
			ZEPHIR_INIT_NVAR(&_10$$11);
			ZEPHIR_CONCAT_VSV(&_10$$11, &key, "=", &value);
			zephir_array_append(&dsnParts, &_10$$11, PH_SEPARATE, "phalcon/Db/Adapter/Pdo/AbstractPdo.zep", 301);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &dsnAttributesMap, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_7, &dsnAttributesMap, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_7)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&key, &dsnAttributesMap, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&value, &dsnAttributesMap, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_11$$12);
				ZEPHIR_CONCAT_VSV(&_11$$12, &key, "=", &value);
				zephir_array_append(&dsnParts, &_11$$12, PH_SEPARATE, "phalcon/Db/Adapter/Pdo/AbstractPdo.zep", 301);
			ZEPHIR_CALL_METHOD(NULL, &dsnAttributesMap, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&value);
	ZEPHIR_INIT_NVAR(&key);
	ZEPHIR_INIT_VAR(&dsnAttributes);
	zephir_fast_join_str(&dsnAttributes, SL(";"), &dsnParts);
	ZEPHIR_INIT_VAR(&_12);
	object_init_ex(&_12, php_pdo_get_dbh_ce());
	zephir_read_property(&_13, this_ptr, ZEND_STRL("type"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_14);
	ZEPHIR_CONCAT_VSV(&_14, &_13, ":", &dsnAttributes);
	ZEPHIR_CALL_METHOD(NULL, &_12, "__construct", NULL, 0, &_14, &username, &password, &options);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, ZEND_STRL("pdo"), &_12);
	ZEPHIR_MM_RESTORE();
}

/**
 * Converts bound parameters such as :name: or ?1 into PDO bind params ?
 *
 *```php
 * print_r(
 *     $connection->convertBoundParams(
 *         "SELECT * FROM robots WHERE name = :name:",
 *         [
 *             "Bender",
 *         ]
 *     )
 * );
 *```
 */
PHP_METHOD(Phalcon_Db_Adapter_Pdo_AbstractPdo, convertBoundParams)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS, setOrder = 0;
	zval params;
	zval *sql_param = NULL, *params_param = NULL, boundSql, placeHolders, bindPattern, matches, placeMatch, value, _0, _1, _2, *_3$$3, _4$$3, _9$$3, _5$$4, _6$$5, _7$$8, _8$$9;
	zval sql;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&sql);
	ZVAL_UNDEF(&boundSql);
	ZVAL_UNDEF(&placeHolders);
	ZVAL_UNDEF(&bindPattern);
	ZVAL_UNDEF(&matches);
	ZVAL_UNDEF(&placeMatch);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_9$$3);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_6$$5);
	ZVAL_UNDEF(&_7$$8);
	ZVAL_UNDEF(&_8$$9);
	ZVAL_UNDEF(&params);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_STR(sql)
		Z_PARAM_OPTIONAL
		Z_PARAM_ARRAY(params)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &sql_param, &params_param);
	if (UNEXPECTED(Z_TYPE_P(sql_param) != IS_STRING && Z_TYPE_P(sql_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'sql' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(sql_param) == IS_STRING)) {
		zephir_get_strval(&sql, sql_param);
	} else {
		ZEPHIR_INIT_VAR(&sql);
	}
	if (!params_param) {
		ZEPHIR_INIT_VAR(&params);
		array_init(&params);
	} else {
		zephir_get_arrval(&params, params_param);
	}


	ZEPHIR_INIT_VAR(&placeHolders);
	array_init(&placeHolders);
	ZEPHIR_INIT_VAR(&bindPattern);
	ZVAL_STRING(&bindPattern, "/\\?([0-9]+)|:([a-zA-Z0-9_]+):/");
	ZEPHIR_INIT_VAR(&matches);
	ZVAL_NULL(&matches);
	setOrder = 2;
	ZVAL_LONG(&_0, setOrder);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_LONG(&_2, setOrder);
	zephir_preg_match(&_1, &bindPattern, &sql, &matches, 1, zephir_get_intval(&_0) , 0 );
	if (zephir_is_true(&_1)) {
		zephir_is_iterable(&matches, 0, "phalcon/Db/Adapter/Pdo/AbstractPdo.zep", 359);
		if (Z_TYPE_P(&matches) == IS_ARRAY) {
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&matches), _3$$3)
			{
				ZEPHIR_INIT_NVAR(&placeMatch);
				ZVAL_COPY(&placeMatch, _3$$3);
				ZEPHIR_OBS_NVAR(&value);
				zephir_array_fetch_long(&_5$$4, &placeMatch, 1, PH_READONLY, "phalcon/Db/Adapter/Pdo/AbstractPdo.zep", 342);
				if (!(zephir_array_isset_fetch(&value, &params, &_5$$4, 0))) {
					if (UNEXPECTED(!(zephir_array_isset_long(&placeMatch, 2)))) {
						ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_db_exception_ce, "Matched parameter was not found in parameters list", "phalcon/Db/Adapter/Pdo/AbstractPdo.zep", 346);
						return;
					}
					ZEPHIR_OBS_NVAR(&value);
					zephir_array_fetch_long(&_6$$5, &placeMatch, 2, PH_READONLY, "phalcon/Db/Adapter/Pdo/AbstractPdo.zep", 349);
					if (UNEXPECTED(!(zephir_array_isset_fetch(&value, &params, &_6$$5, 0)))) {
						ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_db_exception_ce, "Matched parameter was not found in parameters list", "phalcon/Db/Adapter/Pdo/AbstractPdo.zep", 352);
						return;
					}
				}
				zephir_array_append(&placeHolders, &value, PH_SEPARATE, "phalcon/Db/Adapter/Pdo/AbstractPdo.zep", 356);
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, &matches, "rewind", NULL, 0);
			zephir_check_call_status();
			while (1) {
				ZEPHIR_CALL_METHOD(&_4$$3, &matches, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_4$$3)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&placeMatch, &matches, "current", NULL, 0);
				zephir_check_call_status();
					ZEPHIR_OBS_NVAR(&value);
					zephir_array_fetch_long(&_7$$8, &placeMatch, 1, PH_READONLY, "phalcon/Db/Adapter/Pdo/AbstractPdo.zep", 342);
					if (!(zephir_array_isset_fetch(&value, &params, &_7$$8, 0))) {
						if (UNEXPECTED(!(zephir_array_isset_long(&placeMatch, 2)))) {
							ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_db_exception_ce, "Matched parameter was not found in parameters list", "phalcon/Db/Adapter/Pdo/AbstractPdo.zep", 346);
							return;
						}
						ZEPHIR_OBS_NVAR(&value);
						zephir_array_fetch_long(&_8$$9, &placeMatch, 2, PH_READONLY, "phalcon/Db/Adapter/Pdo/AbstractPdo.zep", 349);
						if (UNEXPECTED(!(zephir_array_isset_fetch(&value, &params, &_8$$9, 0)))) {
							ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_db_exception_ce, "Matched parameter was not found in parameters list", "phalcon/Db/Adapter/Pdo/AbstractPdo.zep", 352);
							return;
						}
					}
					zephir_array_append(&placeHolders, &value, PH_SEPARATE, "phalcon/Db/Adapter/Pdo/AbstractPdo.zep", 356);
				ZEPHIR_CALL_METHOD(NULL, &matches, "next", NULL, 0);
				zephir_check_call_status();
			}
		}
		ZEPHIR_INIT_NVAR(&placeMatch);
		ZEPHIR_INIT_VAR(&_9$$3);
		ZVAL_STRING(&_9$$3, "?");
		ZEPHIR_CALL_FUNCTION(&boundSql, "preg_replace", NULL, 37, &bindPattern, &_9$$3, &sql);
		zephir_check_call_status();
	} else {
		ZEPHIR_CPY_WRT(&boundSql, &sql);
	}
	zephir_create_array(return_value, 2, 0);
	zephir_array_update_string(return_value, SL("sql"), &boundSql, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(return_value, SL("params"), &placeHolders, PH_COPY | PH_SEPARATE);
	RETURN_MM();
}

/**
 * Escapes a value to avoid SQL injections according to the active charset
 * in the connection
 *
 *```php
 * $escapedStr = $connection->escapeString("some dangerous value");
 *```
 */
PHP_METHOD(Phalcon_Db_Adapter_Pdo_AbstractPdo, escapeString)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *str_param = NULL, _0;
	zval str;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&str);
	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(str)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &str_param);
	zephir_get_strval(&str, str_param);


	zephir_read_property(&_0, this_ptr, ZEND_STRL("pdo"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_0, "quote", NULL, 0, &str);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Sends SQL statements to the database server returning the success state.
 * Use this method only when the SQL statement sent to the server doesn't
 * return any rows
 *
 *```php
 * // Inserting data
 * $success = $connection->execute(
 *     "INSERT INTO robots VALUES (1, 'Astro Boy')"
 * );
 *
 * $success = $connection->execute(
 *     "INSERT INTO robots VALUES (?, ?)",
 *     [
 *         1,
 *         "Astro Boy",
 *     ]
 * );
 *```
 */
PHP_METHOD(Phalcon_Db_Adapter_Pdo_AbstractPdo, execute)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval bindParams, bindTypes;
	zval *sqlStatement_param = NULL, *bindParams_param = NULL, *bindTypes_param = NULL, eventsManager, affectedRows, newStatement, statement, _0, _1$$3, _2$$3, _3$$5, _4$$7, _5$$9;
	zval sqlStatement;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&sqlStatement);
	ZVAL_UNDEF(&eventsManager);
	ZVAL_UNDEF(&affectedRows);
	ZVAL_UNDEF(&newStatement);
	ZVAL_UNDEF(&statement);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$5);
	ZVAL_UNDEF(&_4$$7);
	ZVAL_UNDEF(&_5$$9);
	ZVAL_UNDEF(&bindParams);
	ZVAL_UNDEF(&bindTypes);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 3)
		Z_PARAM_STR(sqlStatement)
		Z_PARAM_OPTIONAL
		Z_PARAM_ARRAY(bindParams)
		Z_PARAM_ARRAY(bindTypes)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &sqlStatement_param, &bindParams_param, &bindTypes_param);
	if (UNEXPECTED(Z_TYPE_P(sqlStatement_param) != IS_STRING && Z_TYPE_P(sqlStatement_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'sqlStatement' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(sqlStatement_param) == IS_STRING)) {
		zephir_get_strval(&sqlStatement, sqlStatement_param);
	} else {
		ZEPHIR_INIT_VAR(&sqlStatement);
	}
	if (!bindParams_param) {
		ZEPHIR_INIT_VAR(&bindParams);
		array_init(&bindParams);
	} else {
	ZEPHIR_OBS_COPY_OR_DUP(&bindParams, bindParams_param);
	}
	if (!bindTypes_param) {
		ZEPHIR_INIT_VAR(&bindTypes);
		array_init(&bindTypes);
	} else {
	ZEPHIR_OBS_COPY_OR_DUP(&bindTypes, bindTypes_param);
	}


	zephir_read_property(&_0, this_ptr, ZEND_STRL("eventsManager"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&eventsManager, &_0);
	if (Z_TYPE_P(&eventsManager) == IS_OBJECT) {
		zephir_update_property_zval(this_ptr, ZEND_STRL("sqlStatement"), &sqlStatement);
		zephir_update_property_zval(this_ptr, ZEND_STRL("sqlVariables"), &bindParams);
		zephir_update_property_zval(this_ptr, ZEND_STRL("sqlBindTypes"), &bindTypes);
		ZEPHIR_INIT_VAR(&_2$$3);
		ZVAL_STRING(&_2$$3, "db:beforeQuery");
		ZEPHIR_CALL_METHOD(&_1$$3, &eventsManager, "fire", NULL, 0, &_2$$3, this_ptr);
		zephir_check_call_status();
		if (ZEPHIR_IS_FALSE_IDENTICAL(&_1$$3)) {
			RETURN_MM_BOOL(0);
		}
	}
	ZEPHIR_INIT_VAR(&affectedRows);
	ZVAL_LONG(&affectedRows, 0);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "preparerealsql", NULL, 0, &sqlStatement, &bindParams);
	zephir_check_call_status();
	if (!(ZEPHIR_IS_EMPTY(&bindParams))) {
		zephir_read_property(&_3$$5, this_ptr, ZEND_STRL("pdo"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(&statement, &_3$$5, "prepare", NULL, 0, &sqlStatement);
		zephir_check_call_status();
		if (Z_TYPE_P(&statement) == IS_OBJECT) {
			ZEPHIR_CALL_METHOD(&newStatement, this_ptr, "executeprepared", NULL, 0, &statement, &bindParams, &bindTypes);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&affectedRows, &newStatement, "rowcount", NULL, 0);
			zephir_check_call_status();
		}
	} else {
		zephir_read_property(&_4$$7, this_ptr, ZEND_STRL("pdo"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(&affectedRows, &_4$$7, "exec", NULL, 0, &sqlStatement);
		zephir_check_call_status();
	}
	if (Z_TYPE_P(&affectedRows) == IS_LONG) {
		zephir_update_property_zval(this_ptr, ZEND_STRL("affectedRows"), &affectedRows);
		if (Z_TYPE_P(&eventsManager) == IS_OBJECT) {
			ZEPHIR_INIT_VAR(&_5$$9);
			ZVAL_STRING(&_5$$9, "db:afterQuery");
			ZEPHIR_CALL_METHOD(NULL, &eventsManager, "fire", NULL, 0, &_5$$9, this_ptr);
			zephir_check_call_status();
		}
	}
	RETURN_MM_BOOL(1);
}

/**
 * Executes a prepared statement binding. This function uses integer indexes
 * starting from zero
 *
 *```php
 * use Phalcon\Db\Column;
 *
 * $statement = $db->prepare(
 *     "SELECT * FROM robots WHERE name = :name"
 * );
 *
 * $result = $connection->executePrepared(
 *     $statement,
 *     [
 *         "name" => "Voltron",
 *     ],
 *     [
 *         "name" => Column::BIND_PARAM_STR,
 *     ]
 * );
 *```
 */
PHP_METHOD(Phalcon_Db_Adapter_Pdo_AbstractPdo, executePrepared)
{
	zval _5$$8, _8$$13, _25$$39, _27$$44;
	zend_bool _4$$3, _24$$34;
	zend_string *_3, *_13$$22, *_21$$31, *_31$$53, *_39$$62;
	zend_ulong _2, _12$$22, _20$$31, _30$$53, _38$$62;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_7 = NULL, *_9 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval placeholders;
	zval *statement, statement_sub, *placeholders_param = NULL, *dataTypes, dataTypes_sub, wildcard, value, type, castValue, parameter, position, itemValue, *_0, _1, _6$$12, *_10$$22, _11$$22, _14$$24, _15$$25, _16$$27, _17$$28, *_18$$31, _19$$31, _22$$32, _23$$33, _26$$43, *_28$$53, _29$$53, _32$$55, _33$$56, _34$$58, _35$$59, *_36$$62, _37$$62, _40$$63, _41$$64;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&statement_sub);
	ZVAL_UNDEF(&dataTypes_sub);
	ZVAL_UNDEF(&wildcard);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&type);
	ZVAL_UNDEF(&castValue);
	ZVAL_UNDEF(&parameter);
	ZVAL_UNDEF(&position);
	ZVAL_UNDEF(&itemValue);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_6$$12);
	ZVAL_UNDEF(&_11$$22);
	ZVAL_UNDEF(&_14$$24);
	ZVAL_UNDEF(&_15$$25);
	ZVAL_UNDEF(&_16$$27);
	ZVAL_UNDEF(&_17$$28);
	ZVAL_UNDEF(&_19$$31);
	ZVAL_UNDEF(&_22$$32);
	ZVAL_UNDEF(&_23$$33);
	ZVAL_UNDEF(&_26$$43);
	ZVAL_UNDEF(&_29$$53);
	ZVAL_UNDEF(&_32$$55);
	ZVAL_UNDEF(&_33$$56);
	ZVAL_UNDEF(&_34$$58);
	ZVAL_UNDEF(&_35$$59);
	ZVAL_UNDEF(&_37$$62);
	ZVAL_UNDEF(&_40$$63);
	ZVAL_UNDEF(&_41$$64);
	ZVAL_UNDEF(&placeholders);
	ZVAL_UNDEF(&_5$$8);
	ZVAL_UNDEF(&_8$$13);
	ZVAL_UNDEF(&_25$$39);
	ZVAL_UNDEF(&_27$$44);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_OBJECT_OF_CLASS(statement, zephir_get_internal_ce(SL("pdostatement")))
		Z_PARAM_ARRAY(placeholders)
		Z_PARAM_ZVAL(dataTypes)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &statement, &placeholders_param, &dataTypes);
	ZEPHIR_OBS_COPY_OR_DUP(&placeholders, placeholders_param);


	zephir_is_iterable(&placeholders, 0, "phalcon/Db/Adapter/Pdo/AbstractPdo.zep", 570);
	if (Z_TYPE_P(&placeholders) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&placeholders), _2, _3, _0)
		{
			ZEPHIR_INIT_NVAR(&wildcard);
			if (_3 != NULL) { 
				ZVAL_STR_COPY(&wildcard, _3);
			} else {
				ZVAL_LONG(&wildcard, _2);
			}
			ZEPHIR_INIT_NVAR(&value);
			ZVAL_COPY(&value, _0);
			if (Z_TYPE_P(&wildcard) == IS_LONG) {
				ZEPHIR_INIT_NVAR(&parameter);
				ZVAL_LONG(&parameter, (zephir_get_numberval(&wildcard) + 1));
			} else if (Z_TYPE_P(&wildcard) == IS_STRING) {
				ZEPHIR_CPY_WRT(&parameter, &wildcard);
			} else {
				ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_db_exception_ce, "Invalid bind parameter (1)", "phalcon/Db/Adapter/Pdo/AbstractPdo.zep", 490);
				return;
			}
			_4$$3 = Z_TYPE_P(dataTypes) == IS_ARRAY;
			if (_4$$3) {
				ZEPHIR_OBS_NVAR(&type);
				_4$$3 = zephir_array_isset_fetch(&type, dataTypes, &wildcard, 0);
			}
			if (_4$$3) {
				if (ZEPHIR_IS_LONG(&type, 32)) {
					zephir_cast_to_string(&_5$$8, &value);
					ZEPHIR_CPY_WRT(&castValue, &_5$$8);
					ZEPHIR_INIT_NVAR(&type);
					ZVAL_LONG(&type, 1024);
				} else {
					if (ZEPHIR_GLOBAL(db).force_casting) {
						if (Z_TYPE_P(&value) != IS_ARRAY) {
							do {
								if (ZEPHIR_IS_LONG(&type, 1)) {
									ZVAL_LONG(&_6$$12, 10);
									ZEPHIR_CALL_FUNCTION(&castValue, "intval", &_7, 38, &value, &_6$$12);
									zephir_check_call_status();
									break;
								}
								if (ZEPHIR_IS_LONG(&type, 2)) {
									zephir_cast_to_string(&_8$$13, &value);
									ZEPHIR_CPY_WRT(&castValue, &_8$$13);
									break;
								}
								if (ZEPHIR_IS_LONG(&type, 0)) {
									ZEPHIR_INIT_NVAR(&castValue);
									ZVAL_NULL(&castValue);
									break;
								}
								if (ZEPHIR_IS_LONG(&type, 5)) {
									ZEPHIR_INIT_NVAR(&castValue);
									ZVAL_BOOL(&castValue, zephir_get_boolval(&value));
									break;
								}
								ZEPHIR_CPY_WRT(&castValue, &value);
								break;
							} while(0);

						} else {
							ZEPHIR_CPY_WRT(&castValue, &value);
						}
					} else {
						ZEPHIR_CPY_WRT(&castValue, &value);
					}
				}
				if (Z_TYPE_P(&castValue) != IS_ARRAY) {
					if (ZEPHIR_IS_LONG(&type, 1024)) {
						ZEPHIR_CALL_METHOD(NULL, statement, "bindvalue", &_9, 0, &parameter, &castValue);
						zephir_check_call_status();
					} else {
						ZEPHIR_CALL_METHOD(NULL, statement, "bindvalue", &_9, 0, &parameter, &castValue, &type);
						zephir_check_call_status();
					}
				} else {
					zephir_is_iterable(&castValue, 0, "phalcon/Db/Adapter/Pdo/AbstractPdo.zep", 558);
					if (Z_TYPE_P(&castValue) == IS_ARRAY) {
						ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&castValue), _12$$22, _13$$22, _10$$22)
						{
							ZEPHIR_INIT_NVAR(&position);
							if (_13$$22 != NULL) { 
								ZVAL_STR_COPY(&position, _13$$22);
							} else {
								ZVAL_LONG(&position, _12$$22);
							}
							ZEPHIR_INIT_NVAR(&itemValue);
							ZVAL_COPY(&itemValue, _10$$22);
							if (ZEPHIR_IS_LONG(&type, 1024)) {
								ZEPHIR_INIT_NVAR(&_14$$24);
								ZEPHIR_CONCAT_VV(&_14$$24, &parameter, &position);
								ZEPHIR_CALL_METHOD(NULL, statement, "bindvalue", &_9, 0, &_14$$24, &itemValue);
								zephir_check_call_status();
							} else {
								ZEPHIR_INIT_NVAR(&_15$$25);
								ZEPHIR_CONCAT_VV(&_15$$25, &parameter, &position);
								ZEPHIR_CALL_METHOD(NULL, statement, "bindvalue", &_9, 0, &_15$$25, &itemValue, &type);
								zephir_check_call_status();
							}
						} ZEND_HASH_FOREACH_END();
					} else {
						ZEPHIR_CALL_METHOD(NULL, &castValue, "rewind", NULL, 0);
						zephir_check_call_status();
						while (1) {
							ZEPHIR_CALL_METHOD(&_11$$22, &castValue, "valid", NULL, 0);
							zephir_check_call_status();
							if (!zend_is_true(&_11$$22)) {
								break;
							}
							ZEPHIR_CALL_METHOD(&position, &castValue, "key", NULL, 0);
							zephir_check_call_status();
							ZEPHIR_CALL_METHOD(&itemValue, &castValue, "current", NULL, 0);
							zephir_check_call_status();
								if (ZEPHIR_IS_LONG(&type, 1024)) {
									ZEPHIR_INIT_NVAR(&_16$$27);
									ZEPHIR_CONCAT_VV(&_16$$27, &parameter, &position);
									ZEPHIR_CALL_METHOD(NULL, statement, "bindvalue", &_9, 0, &_16$$27, &itemValue);
									zephir_check_call_status();
								} else {
									ZEPHIR_INIT_NVAR(&_17$$28);
									ZEPHIR_CONCAT_VV(&_17$$28, &parameter, &position);
									ZEPHIR_CALL_METHOD(NULL, statement, "bindvalue", &_9, 0, &_17$$28, &itemValue, &type);
									zephir_check_call_status();
								}
							ZEPHIR_CALL_METHOD(NULL, &castValue, "next", NULL, 0);
							zephir_check_call_status();
						}
					}
					ZEPHIR_INIT_NVAR(&itemValue);
					ZEPHIR_INIT_NVAR(&position);
				}
			} else {
				if (Z_TYPE_P(&value) != IS_ARRAY) {
					ZEPHIR_CALL_METHOD(NULL, statement, "bindvalue", &_9, 0, &parameter, &value);
					zephir_check_call_status();
				} else {
					zephir_is_iterable(&value, 0, "phalcon/Db/Adapter/Pdo/AbstractPdo.zep", 566);
					if (Z_TYPE_P(&value) == IS_ARRAY) {
						ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&value), _20$$31, _21$$31, _18$$31)
						{
							ZEPHIR_INIT_NVAR(&position);
							if (_21$$31 != NULL) { 
								ZVAL_STR_COPY(&position, _21$$31);
							} else {
								ZVAL_LONG(&position, _20$$31);
							}
							ZEPHIR_INIT_NVAR(&itemValue);
							ZVAL_COPY(&itemValue, _18$$31);
							ZEPHIR_INIT_NVAR(&_22$$32);
							ZEPHIR_CONCAT_VV(&_22$$32, &parameter, &position);
							ZEPHIR_CALL_METHOD(NULL, statement, "bindvalue", &_9, 0, &_22$$32, &itemValue);
							zephir_check_call_status();
						} ZEND_HASH_FOREACH_END();
					} else {
						ZEPHIR_CALL_METHOD(NULL, &value, "rewind", NULL, 0);
						zephir_check_call_status();
						while (1) {
							ZEPHIR_CALL_METHOD(&_19$$31, &value, "valid", NULL, 0);
							zephir_check_call_status();
							if (!zend_is_true(&_19$$31)) {
								break;
							}
							ZEPHIR_CALL_METHOD(&position, &value, "key", NULL, 0);
							zephir_check_call_status();
							ZEPHIR_CALL_METHOD(&itemValue, &value, "current", NULL, 0);
							zephir_check_call_status();
								ZEPHIR_INIT_NVAR(&_23$$33);
								ZEPHIR_CONCAT_VV(&_23$$33, &parameter, &position);
								ZEPHIR_CALL_METHOD(NULL, statement, "bindvalue", &_9, 0, &_23$$33, &itemValue);
								zephir_check_call_status();
							ZEPHIR_CALL_METHOD(NULL, &value, "next", NULL, 0);
							zephir_check_call_status();
						}
					}
					ZEPHIR_INIT_NVAR(&itemValue);
					ZEPHIR_INIT_NVAR(&position);
				}
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &placeholders, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_1, &placeholders, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_1)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&wildcard, &placeholders, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&value, &placeholders, "current", NULL, 0);
			zephir_check_call_status();
				if (Z_TYPE_P(&wildcard) == IS_LONG) {
					ZEPHIR_INIT_NVAR(&parameter);
					ZVAL_LONG(&parameter, (zephir_get_numberval(&wildcard) + 1));
				} else if (Z_TYPE_P(&wildcard) == IS_STRING) {
					ZEPHIR_CPY_WRT(&parameter, &wildcard);
				} else {
					ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_db_exception_ce, "Invalid bind parameter (1)", "phalcon/Db/Adapter/Pdo/AbstractPdo.zep", 490);
					return;
				}
				_24$$34 = Z_TYPE_P(dataTypes) == IS_ARRAY;
				if (_24$$34) {
					ZEPHIR_OBS_NVAR(&type);
					_24$$34 = zephir_array_isset_fetch(&type, dataTypes, &wildcard, 0);
				}
				if (_24$$34) {
					if (ZEPHIR_IS_LONG(&type, 32)) {
						zephir_cast_to_string(&_25$$39, &value);
						ZEPHIR_CPY_WRT(&castValue, &_25$$39);
						ZEPHIR_INIT_NVAR(&type);
						ZVAL_LONG(&type, 1024);
					} else {
						if (ZEPHIR_GLOBAL(db).force_casting) {
							if (Z_TYPE_P(&value) != IS_ARRAY) {
								do {
									if (ZEPHIR_IS_LONG(&type, 1)) {
										ZVAL_LONG(&_26$$43, 10);
										ZEPHIR_CALL_FUNCTION(&castValue, "intval", &_7, 38, &value, &_26$$43);
										zephir_check_call_status();
										break;
									}
									if (ZEPHIR_IS_LONG(&type, 2)) {
										zephir_cast_to_string(&_27$$44, &value);
										ZEPHIR_CPY_WRT(&castValue, &_27$$44);
										break;
									}
									if (ZEPHIR_IS_LONG(&type, 0)) {
										ZEPHIR_INIT_NVAR(&castValue);
										ZVAL_NULL(&castValue);
										break;
									}
									if (ZEPHIR_IS_LONG(&type, 5)) {
										ZEPHIR_INIT_NVAR(&castValue);
										ZVAL_BOOL(&castValue, zephir_get_boolval(&value));
										break;
									}
									ZEPHIR_CPY_WRT(&castValue, &value);
									break;
								} while(0);

							} else {
								ZEPHIR_CPY_WRT(&castValue, &value);
							}
						} else {
							ZEPHIR_CPY_WRT(&castValue, &value);
						}
					}
					if (Z_TYPE_P(&castValue) != IS_ARRAY) {
						if (ZEPHIR_IS_LONG(&type, 1024)) {
							ZEPHIR_CALL_METHOD(NULL, statement, "bindvalue", &_9, 0, &parameter, &castValue);
							zephir_check_call_status();
						} else {
							ZEPHIR_CALL_METHOD(NULL, statement, "bindvalue", &_9, 0, &parameter, &castValue, &type);
							zephir_check_call_status();
						}
					} else {
						zephir_is_iterable(&castValue, 0, "phalcon/Db/Adapter/Pdo/AbstractPdo.zep", 558);
						if (Z_TYPE_P(&castValue) == IS_ARRAY) {
							ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&castValue), _30$$53, _31$$53, _28$$53)
							{
								ZEPHIR_INIT_NVAR(&position);
								if (_31$$53 != NULL) { 
									ZVAL_STR_COPY(&position, _31$$53);
								} else {
									ZVAL_LONG(&position, _30$$53);
								}
								ZEPHIR_INIT_NVAR(&itemValue);
								ZVAL_COPY(&itemValue, _28$$53);
								if (ZEPHIR_IS_LONG(&type, 1024)) {
									ZEPHIR_INIT_NVAR(&_32$$55);
									ZEPHIR_CONCAT_VV(&_32$$55, &parameter, &position);
									ZEPHIR_CALL_METHOD(NULL, statement, "bindvalue", &_9, 0, &_32$$55, &itemValue);
									zephir_check_call_status();
								} else {
									ZEPHIR_INIT_NVAR(&_33$$56);
									ZEPHIR_CONCAT_VV(&_33$$56, &parameter, &position);
									ZEPHIR_CALL_METHOD(NULL, statement, "bindvalue", &_9, 0, &_33$$56, &itemValue, &type);
									zephir_check_call_status();
								}
							} ZEND_HASH_FOREACH_END();
						} else {
							ZEPHIR_CALL_METHOD(NULL, &castValue, "rewind", NULL, 0);
							zephir_check_call_status();
							while (1) {
								ZEPHIR_CALL_METHOD(&_29$$53, &castValue, "valid", NULL, 0);
								zephir_check_call_status();
								if (!zend_is_true(&_29$$53)) {
									break;
								}
								ZEPHIR_CALL_METHOD(&position, &castValue, "key", NULL, 0);
								zephir_check_call_status();
								ZEPHIR_CALL_METHOD(&itemValue, &castValue, "current", NULL, 0);
								zephir_check_call_status();
									if (ZEPHIR_IS_LONG(&type, 1024)) {
										ZEPHIR_INIT_NVAR(&_34$$58);
										ZEPHIR_CONCAT_VV(&_34$$58, &parameter, &position);
										ZEPHIR_CALL_METHOD(NULL, statement, "bindvalue", &_9, 0, &_34$$58, &itemValue);
										zephir_check_call_status();
									} else {
										ZEPHIR_INIT_NVAR(&_35$$59);
										ZEPHIR_CONCAT_VV(&_35$$59, &parameter, &position);
										ZEPHIR_CALL_METHOD(NULL, statement, "bindvalue", &_9, 0, &_35$$59, &itemValue, &type);
										zephir_check_call_status();
									}
								ZEPHIR_CALL_METHOD(NULL, &castValue, "next", NULL, 0);
								zephir_check_call_status();
							}
						}
						ZEPHIR_INIT_NVAR(&itemValue);
						ZEPHIR_INIT_NVAR(&position);
					}
				} else {
					if (Z_TYPE_P(&value) != IS_ARRAY) {
						ZEPHIR_CALL_METHOD(NULL, statement, "bindvalue", &_9, 0, &parameter, &value);
						zephir_check_call_status();
					} else {
						zephir_is_iterable(&value, 0, "phalcon/Db/Adapter/Pdo/AbstractPdo.zep", 566);
						if (Z_TYPE_P(&value) == IS_ARRAY) {
							ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&value), _38$$62, _39$$62, _36$$62)
							{
								ZEPHIR_INIT_NVAR(&position);
								if (_39$$62 != NULL) { 
									ZVAL_STR_COPY(&position, _39$$62);
								} else {
									ZVAL_LONG(&position, _38$$62);
								}
								ZEPHIR_INIT_NVAR(&itemValue);
								ZVAL_COPY(&itemValue, _36$$62);
								ZEPHIR_INIT_NVAR(&_40$$63);
								ZEPHIR_CONCAT_VV(&_40$$63, &parameter, &position);
								ZEPHIR_CALL_METHOD(NULL, statement, "bindvalue", &_9, 0, &_40$$63, &itemValue);
								zephir_check_call_status();
							} ZEND_HASH_FOREACH_END();
						} else {
							ZEPHIR_CALL_METHOD(NULL, &value, "rewind", NULL, 0);
							zephir_check_call_status();
							while (1) {
								ZEPHIR_CALL_METHOD(&_37$$62, &value, "valid", NULL, 0);
								zephir_check_call_status();
								if (!zend_is_true(&_37$$62)) {
									break;
								}
								ZEPHIR_CALL_METHOD(&position, &value, "key", NULL, 0);
								zephir_check_call_status();
								ZEPHIR_CALL_METHOD(&itemValue, &value, "current", NULL, 0);
								zephir_check_call_status();
									ZEPHIR_INIT_NVAR(&_41$$64);
									ZEPHIR_CONCAT_VV(&_41$$64, &parameter, &position);
									ZEPHIR_CALL_METHOD(NULL, statement, "bindvalue", &_9, 0, &_41$$64, &itemValue);
									zephir_check_call_status();
								ZEPHIR_CALL_METHOD(NULL, &value, "next", NULL, 0);
								zephir_check_call_status();
							}
						}
						ZEPHIR_INIT_NVAR(&itemValue);
						ZEPHIR_INIT_NVAR(&position);
					}
				}
			ZEPHIR_CALL_METHOD(NULL, &placeholders, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&value);
	ZEPHIR_INIT_NVAR(&wildcard);
	ZEPHIR_CALL_METHOD(NULL, statement, "execute", NULL, 0);
	zephir_check_call_status();
	RETVAL_ZVAL(statement, 1, 0);
	RETURN_MM();
}

/**
 * Return the error info, if any
 */
PHP_METHOD(Phalcon_Db_Adapter_Pdo_AbstractPdo, getErrorInfo)
{
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);


	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, ZEND_STRL("pdo"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_0, "errorinfo", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Return internal PDO handler
 */
PHP_METHOD(Phalcon_Db_Adapter_Pdo_AbstractPdo, getInternalHandler)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "pdo");
}

/**
 * Returns the current transaction nesting level
 */
PHP_METHOD(Phalcon_Db_Adapter_Pdo_AbstractPdo, getTransactionLevel)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "transactionLevel");
}

/**
 * Checks whether the connection is under a transaction
 *
 *```php
 * $connection->begin();
 *
 * // true
 * var_dump(
 *     $connection->isUnderTransaction()
 * );
 *```
 */
PHP_METHOD(Phalcon_Db_Adapter_Pdo_AbstractPdo, isUnderTransaction)
{
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);


	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, ZEND_STRL("pdo"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_0, "intransaction", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Returns the insert id for the auto_increment/serial column inserted in
 * the latest executed SQL statement
 *
 *```php
 * // Inserting a new robot
 * $success = $connection->insert(
 *     "robots",
 *     [
 *         "Astro Boy",
 *         1952,
 *     ],
 *     [
 *         "name",
 *         "year",
 *     ]
 * );
 *
 * // Getting the generated id
 * $id = $connection->lastInsertId();
 *```
 *
 * @param string|null $name
 * @return string|bool
 */
PHP_METHOD(Phalcon_Db_Adapter_Pdo_AbstractPdo, lastInsertId)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, _0;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR_OR_NULL(name)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &name_param);
	if (!name_param) {
		ZEPHIR_INIT_VAR(&name);
	} else {
	if (UNEXPECTED(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(name_param) == IS_STRING)) {
		zephir_get_strval(&name, name_param);
	} else {
		ZEPHIR_INIT_VAR(&name);
	}
	}


	zephir_read_property(&_0, this_ptr, ZEND_STRL("pdo"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_0, "lastinsertid", NULL, 0, &name);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Returns a PDO prepared statement to be executed with 'executePrepared'
 *
 *```php
 * use Phalcon\Db\Column;
 *
 * $statement = $db->prepare(
 *     "SELECT * FROM robots WHERE name = :name"
 * );
 *
 * $result = $connection->executePrepared(
 *     $statement,
 *     [
 *         "name" => "Voltron",
 *     ],
 *     [
 *         "name" => Column::BIND_PARAM_INT,
 *     ]
 * );
 *```
 */
PHP_METHOD(Phalcon_Db_Adapter_Pdo_AbstractPdo, prepare)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *sqlStatement_param = NULL, _0;
	zval sqlStatement;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&sqlStatement);
	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(sqlStatement)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &sqlStatement_param);
	if (UNEXPECTED(Z_TYPE_P(sqlStatement_param) != IS_STRING && Z_TYPE_P(sqlStatement_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'sqlStatement' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(sqlStatement_param) == IS_STRING)) {
		zephir_get_strval(&sqlStatement, sqlStatement_param);
	} else {
		ZEPHIR_INIT_VAR(&sqlStatement);
	}


	zephir_read_property(&_0, this_ptr, ZEND_STRL("pdo"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_0, "prepare", NULL, 0, &sqlStatement);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Sends SQL statements to the database server returning the success state.
 * Use this method only when the SQL statement sent to the server is
 * returning rows
 *
 *```php
 * // Querying data
 * $resultset = $connection->query(
 *     "SELECT * FROM robots WHERE type = 'mechanical'"
 * );
 *
 * $resultset = $connection->query(
 *     "SELECT * FROM robots WHERE type = ?",
 *     [
 *         "mechanical",
 *     ]
 * );
 *```
 */
PHP_METHOD(Phalcon_Db_Adapter_Pdo_AbstractPdo, query)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval bindParams, bindTypes;
	zval *sqlStatement_param = NULL, *bindParams_param = NULL, *bindTypes_param = NULL, eventsManager, statement, params, types, _0, _3, _1$$3, _2$$3, _4$$9;
	zval sqlStatement;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&sqlStatement);
	ZVAL_UNDEF(&eventsManager);
	ZVAL_UNDEF(&statement);
	ZVAL_UNDEF(&params);
	ZVAL_UNDEF(&types);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_4$$9);
	ZVAL_UNDEF(&bindParams);
	ZVAL_UNDEF(&bindTypes);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 3)
		Z_PARAM_STR(sqlStatement)
		Z_PARAM_OPTIONAL
		Z_PARAM_ARRAY(bindParams)
		Z_PARAM_ARRAY(bindTypes)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &sqlStatement_param, &bindParams_param, &bindTypes_param);
	if (UNEXPECTED(Z_TYPE_P(sqlStatement_param) != IS_STRING && Z_TYPE_P(sqlStatement_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'sqlStatement' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(sqlStatement_param) == IS_STRING)) {
		zephir_get_strval(&sqlStatement, sqlStatement_param);
	} else {
		ZEPHIR_INIT_VAR(&sqlStatement);
	}
	if (!bindParams_param) {
		ZEPHIR_INIT_VAR(&bindParams);
		array_init(&bindParams);
	} else {
	ZEPHIR_OBS_COPY_OR_DUP(&bindParams, bindParams_param);
	}
	if (!bindTypes_param) {
		ZEPHIR_INIT_VAR(&bindTypes);
		array_init(&bindTypes);
	} else {
	ZEPHIR_OBS_COPY_OR_DUP(&bindTypes, bindTypes_param);
	}


	zephir_read_property(&_0, this_ptr, ZEND_STRL("eventsManager"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&eventsManager, &_0);
	if (Z_TYPE_P(&eventsManager) == IS_OBJECT) {
		zephir_update_property_zval(this_ptr, ZEND_STRL("sqlStatement"), &sqlStatement);
		zephir_update_property_zval(this_ptr, ZEND_STRL("sqlVariables"), &bindParams);
		zephir_update_property_zval(this_ptr, ZEND_STRL("sqlBindTypes"), &bindTypes);
		ZEPHIR_INIT_VAR(&_2$$3);
		ZVAL_STRING(&_2$$3, "db:beforeQuery");
		ZEPHIR_CALL_METHOD(&_1$$3, &eventsManager, "fire", NULL, 0, &_2$$3, this_ptr);
		zephir_check_call_status();
		if (ZEPHIR_IS_FALSE_IDENTICAL(&_1$$3)) {
			RETURN_MM_BOOL(0);
		}
	}
	if (!(ZEPHIR_IS_EMPTY(&bindParams))) {
		ZEPHIR_CPY_WRT(&params, &bindParams);
		ZEPHIR_CPY_WRT(&types, &bindTypes);
	} else {
		ZEPHIR_INIT_NVAR(&params);
		array_init(&params);
		ZEPHIR_INIT_NVAR(&types);
		array_init(&types);
	}
	zephir_read_property(&_0, this_ptr, ZEND_STRL("pdo"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&statement, &_0, "prepare", NULL, 0, &sqlStatement);
	zephir_check_call_status();
	if (UNEXPECTED(Z_TYPE_P(&statement) != IS_OBJECT)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_db_exception_ce, "Cannot prepare statement", "phalcon/Db/Adapter/Pdo/AbstractPdo.zep", 720);
		return;
	}
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "preparerealsql", NULL, 0, &sqlStatement, &bindParams);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_3, this_ptr, "executeprepared", NULL, 0, &statement, &params, &types);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(&statement, &_3);
	if (Z_TYPE_P(&statement) == IS_OBJECT) {
		if (Z_TYPE_P(&eventsManager) == IS_OBJECT) {
			ZEPHIR_INIT_VAR(&_4$$9);
			ZVAL_STRING(&_4$$9, "db:afterQuery");
			ZEPHIR_CALL_METHOD(NULL, &eventsManager, "fire", NULL, 0, &_4$$9, this_ptr);
			zephir_check_call_status();
		}
		object_init_ex(return_value, phalcon_db_result_pdoresult_ce);
		ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 39, this_ptr, &statement, &sqlStatement, &bindParams, &bindTypes);
		zephir_check_call_status();
		RETURN_MM();
	}
	RETURN_CCTOR(&statement);
}

/**
 * Rollbacks the active transaction in the connection
 */
PHP_METHOD(Phalcon_Db_Adapter_Pdo_AbstractPdo, rollback)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS, transactionLevel = 0;
	zval *nesting_param = NULL, eventsManager, savepointName, _0, _5, _6, _1$$4, _2$$5, _7$$8;
	zend_bool nesting, _3, _4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&eventsManager);
	ZVAL_UNDEF(&savepointName);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&_2$$5);
	ZVAL_UNDEF(&_7$$8);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_BOOL(nesting)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &nesting_param);
	if (!nesting_param) {
		nesting = 1;
	} else {
		nesting = zephir_get_boolval(nesting_param);
	}


	ZEPHIR_OBS_VAR(&_0);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("transactionLevel"), PH_NOISY_CC);
	transactionLevel = zephir_get_intval(&_0);
	if (UNEXPECTED(!transactionLevel)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_db_exception_ce, "There is no active transaction", "phalcon/Db/Adapter/Pdo/AbstractPdo.zep", 759);
		return;
	}
	if (transactionLevel == 1) {
		zephir_read_property(&_1$$4, this_ptr, ZEND_STRL("eventsManager"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CPY_WRT(&eventsManager, &_1$$4);
		if (Z_TYPE_P(&eventsManager) == IS_OBJECT) {
			ZEPHIR_INIT_VAR(&_2$$5);
			ZVAL_STRING(&_2$$5, "db:rollbackTransaction");
			ZEPHIR_CALL_METHOD(NULL, &eventsManager, "fire", NULL, 0, &_2$$5, this_ptr);
			zephir_check_call_status();
		}
		RETURN_ON_FAILURE(zephir_property_decr(this_ptr, SL("transactionLevel")));
		zephir_read_property(&_1$$4, this_ptr, ZEND_STRL("pdo"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_RETURN_CALL_METHOD(&_1$$4, "rollback", NULL, 0);
		zephir_check_call_status();
		RETURN_MM();
	}
	_3 = !transactionLevel;
	if (!(_3)) {
		_3 = !nesting;
	}
	_4 = _3;
	if (!(_4)) {
		ZEPHIR_CALL_METHOD(&_5, this_ptr, "isnestedtransactionswithsavepoints", NULL, 0);
		zephir_check_call_status();
		_4 = !zephir_is_true(&_5);
	}
	if (_4) {
		if (transactionLevel > 0) {
			RETURN_ON_FAILURE(zephir_property_decr(this_ptr, SL("transactionLevel")));
		}
		RETURN_MM_BOOL(0);
	}
	ZEPHIR_CALL_METHOD(&savepointName, this_ptr, "getnestedtransactionsavepointname", NULL, 0);
	zephir_check_call_status();
	zephir_read_property(&_6, this_ptr, ZEND_STRL("eventsManager"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&eventsManager, &_6);
	if (Z_TYPE_P(&eventsManager) == IS_OBJECT) {
		ZEPHIR_INIT_VAR(&_7$$8);
		ZVAL_STRING(&_7$$8, "db:rollbackSavepoint");
		ZEPHIR_CALL_METHOD(NULL, &eventsManager, "fire", NULL, 0, &_7$$8, this_ptr, &savepointName);
		zephir_check_call_status();
	}
	RETURN_ON_FAILURE(zephir_property_decr(this_ptr, SL("transactionLevel")));
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "rollbacksavepoint", NULL, 0, &savepointName);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Returns PDO adapter DSN defaults as a key-value map.
 */
PHP_METHOD(Phalcon_Db_Adapter_Pdo_AbstractPdo, getDsnDefaults)
{
}

/**
 * Constructs the SQL statement (with parameters)
 *
 * @see https://stackoverflow.com/a/8403150
 */
PHP_METHOD(Phalcon_Db_Adapter_Pdo_AbstractPdo, prepareRealSql)
{
	zend_string *_3$$3;
	zend_ulong _2$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval parameters, keys, values;
	zval *statement_param = NULL, *parameters_param = NULL, key, result, value, *_0$$3, _1$$3, _16$$3, _4$$5, _5$$6, _6$$7, _7$$8, _8$$8, _9$$9, _10$$11, _11$$12, _12$$13, _13$$14, _14$$14, _15$$15;
	zval statement;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&statement);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_16$$3);
	ZVAL_UNDEF(&_4$$5);
	ZVAL_UNDEF(&_5$$6);
	ZVAL_UNDEF(&_6$$7);
	ZVAL_UNDEF(&_7$$8);
	ZVAL_UNDEF(&_8$$8);
	ZVAL_UNDEF(&_9$$9);
	ZVAL_UNDEF(&_10$$11);
	ZVAL_UNDEF(&_11$$12);
	ZVAL_UNDEF(&_12$$13);
	ZVAL_UNDEF(&_13$$14);
	ZVAL_UNDEF(&_14$$14);
	ZVAL_UNDEF(&_15$$15);
	ZVAL_UNDEF(&parameters);
	ZVAL_UNDEF(&keys);
	ZVAL_UNDEF(&values);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR(statement)
		Z_PARAM_ARRAY(parameters)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &statement_param, &parameters_param);
	zephir_get_strval(&statement, statement_param);
	zephir_get_arrval(&parameters, parameters_param);


	ZEPHIR_CPY_WRT(&result, &statement);
	ZEPHIR_CPY_WRT(&values, &parameters);
	if (!(ZEPHIR_IS_EMPTY(&parameters))) {
		ZEPHIR_INIT_VAR(&keys);
		array_init(&keys);
		zephir_is_iterable(&parameters, 0, "phalcon/Db/Adapter/Pdo/AbstractPdo.zep", 848);
		if (Z_TYPE_P(&parameters) == IS_ARRAY) {
			ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&parameters), _2$$3, _3$$3, _0$$3)
			{
				ZEPHIR_INIT_NVAR(&key);
				if (_3$$3 != NULL) { 
					ZVAL_STR_COPY(&key, _3$$3);
				} else {
					ZVAL_LONG(&key, _2$$3);
				}
				ZEPHIR_INIT_NVAR(&value);
				ZVAL_COPY(&value, _0$$3);
				if (Z_TYPE_P(&key) == IS_STRING) {
					ZEPHIR_INIT_NVAR(&_4$$5);
					ZEPHIR_CONCAT_SVS(&_4$$5, "/:", &key, "/");
					zephir_array_append(&keys, &_4$$5, PH_SEPARATE, "phalcon/Db/Adapter/Pdo/AbstractPdo.zep", 834);
				} else {
					ZEPHIR_INIT_NVAR(&_5$$6);
					ZVAL_STRING(&_5$$6, "/[?]/");
					zephir_array_append(&keys, &_5$$6, PH_SEPARATE, "phalcon/Db/Adapter/Pdo/AbstractPdo.zep", 836);
				}
				if (Z_TYPE_P(&value) == IS_STRING) {
					ZEPHIR_INIT_NVAR(&_6$$7);
					ZEPHIR_CONCAT_SVS(&_6$$7, "'", &value, "'");
					zephir_array_update_zval(&values, &key, &_6$$7, PH_COPY | PH_SEPARATE);
				} else if (Z_TYPE_P(&value) == IS_ARRAY) {
					ZEPHIR_INIT_NVAR(&_7$$8);
					zephir_fast_join_str(&_7$$8, SL("','"), &value);
					ZEPHIR_INIT_NVAR(&_8$$8);
					ZEPHIR_CONCAT_SVS(&_8$$8, "'", &_7$$8, "'");
					zephir_array_update_zval(&values, &key, &_8$$8, PH_COPY | PH_SEPARATE);
				} else if (Z_TYPE_P(&value) == IS_NULL) {
					ZEPHIR_INIT_NVAR(&_9$$9);
					ZVAL_STRING(&_9$$9, "NULL");
					zephir_array_update_zval(&values, &key, &_9$$9, PH_COPY | PH_SEPARATE);
				}
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, &parameters, "rewind", NULL, 0);
			zephir_check_call_status();
			while (1) {
				ZEPHIR_CALL_METHOD(&_1$$3, &parameters, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_1$$3)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&key, &parameters, "key", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&value, &parameters, "current", NULL, 0);
				zephir_check_call_status();
					if (Z_TYPE_P(&key) == IS_STRING) {
						ZEPHIR_INIT_NVAR(&_10$$11);
						ZEPHIR_CONCAT_SVS(&_10$$11, "/:", &key, "/");
						zephir_array_append(&keys, &_10$$11, PH_SEPARATE, "phalcon/Db/Adapter/Pdo/AbstractPdo.zep", 834);
					} else {
						ZEPHIR_INIT_NVAR(&_11$$12);
						ZVAL_STRING(&_11$$12, "/[?]/");
						zephir_array_append(&keys, &_11$$12, PH_SEPARATE, "phalcon/Db/Adapter/Pdo/AbstractPdo.zep", 836);
					}
					if (Z_TYPE_P(&value) == IS_STRING) {
						ZEPHIR_INIT_NVAR(&_12$$13);
						ZEPHIR_CONCAT_SVS(&_12$$13, "'", &value, "'");
						zephir_array_update_zval(&values, &key, &_12$$13, PH_COPY | PH_SEPARATE);
					} else if (Z_TYPE_P(&value) == IS_ARRAY) {
						ZEPHIR_INIT_NVAR(&_13$$14);
						zephir_fast_join_str(&_13$$14, SL("','"), &value);
						ZEPHIR_INIT_NVAR(&_14$$14);
						ZEPHIR_CONCAT_SVS(&_14$$14, "'", &_13$$14, "'");
						zephir_array_update_zval(&values, &key, &_14$$14, PH_COPY | PH_SEPARATE);
					} else if (Z_TYPE_P(&value) == IS_NULL) {
						ZEPHIR_INIT_NVAR(&_15$$15);
						ZVAL_STRING(&_15$$15, "NULL");
						zephir_array_update_zval(&values, &key, &_15$$15, PH_COPY | PH_SEPARATE);
					}
				ZEPHIR_CALL_METHOD(NULL, &parameters, "next", NULL, 0);
				zephir_check_call_status();
			}
		}
		ZEPHIR_INIT_NVAR(&value);
		ZEPHIR_INIT_NVAR(&key);
		ZVAL_LONG(&_16$$3, 1);
		ZEPHIR_CALL_FUNCTION(&result, "preg_replace", NULL, 37, &keys, &values, &statement, &_16$$3);
		zephir_check_call_status();
	}
	zephir_update_property_zval(this_ptr, ZEND_STRL("realSqlStatement"), &result);
	ZEPHIR_MM_RESTORE();
}

