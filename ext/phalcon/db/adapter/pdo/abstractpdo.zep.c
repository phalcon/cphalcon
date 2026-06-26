
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
	 * Whether to transparently reconnect and retry once when a query fails
	 * because the connection was lost. Opt-in; off by default.
	 *
	 * @var bool
	 */
	zend_declare_property_bool(phalcon_db_adapter_pdo_abstractpdo_ce, SL("autoReconnect"), 0, ZEND_ACC_PROTECTED);
	/**
	 * PDO Handler
	 *
	 * @var \PDO
	 */
	zend_declare_property_null(phalcon_db_adapter_pdo_abstractpdo_ce, SL("pdo"), ZEND_ACC_PROTECTED);
	/**
	 * @var string
	 */
	zephir_declare_class_constant_string(phalcon_db_adapter_pdo_abstractpdo_ce, SL("BIND_PATTERN"), "/\\?([0-9]+)|:([a-zA-Z0-9_]+):/");

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
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *descriptor_param = NULL;
	zval descriptor;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&descriptor);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		ZEPHIR_Z_PARAM_ARRAY(descriptor, descriptor_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &descriptor_param);
	ZEPHIR_OBS_COPY_OR_DUP(&descriptor, descriptor_param);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "connect", NULL, 0, &descriptor);
	zephir_check_call_status();
	ZEPHIR_CALL_PARENT(NULL, phalcon_db_adapter_pdo_abstractpdo_ce, getThis(), "__construct", NULL, 0, &descriptor);
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

	RETURN_MEMBER_TYPED(getThis(), "affectedRows", IS_LONG);
}

/**
 * Starts a transaction in the connection
 */
PHP_METHOD(Phalcon_Db_Adapter_Pdo_AbstractPdo, begin)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *nesting_param = NULL, eventsManager, savepointName, _0, _3, _6, _7, _1$$3, _2$$4, _8$$6;
	zend_bool nesting, _4, _5;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&eventsManager);
	ZVAL_UNDEF(&savepointName);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_8$$6);
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_BOOL(nesting)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 0, 1, &nesting_param);
	if (!nesting_param) {
		nesting = 1;
	} else {
		}
	RETURN_ON_FAILURE(zephir_property_incr(this_ptr, SL("transactionLevel")));
	zephir_read_property(&_0, this_ptr, ZEND_STRL("transactionLevel"), PH_NOISY_CC | PH_READONLY);
	if (ZEPHIR_IS_LONG_IDENTICAL(&_0, 1)) {
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
	zephir_read_property(&_3, this_ptr, ZEND_STRL("transactionLevel"), PH_NOISY_CC | PH_READONLY);
	_4 = ZEPHIR_IS_LONG_IDENTICAL(&_3, 0);
	if (!(_4)) {
		_4 = !nesting;
	}
	_5 = _4;
	if (!(_5)) {
		ZEPHIR_CALL_METHOD(&_6, this_ptr, "isnestedtransactionswithsavepoints", NULL, 0);
		zephir_check_call_status();
		_5 = !zephir_is_true(&_6);
	}
	if (_5) {
		RETURN_MM_BOOL(0);
	}
	zephir_read_property(&_7, this_ptr, ZEND_STRL("eventsManager"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&eventsManager, &_7);
	ZEPHIR_CALL_METHOD(&savepointName, this_ptr, "getnestedtransactionsavepointname", NULL, 0);
	zephir_check_call_status();
	if (Z_TYPE_P(&eventsManager) == IS_OBJECT) {
		ZEPHIR_INIT_VAR(&_8$$6);
		ZVAL_STRING(&_8$$6, "db:createSavepoint");
		ZEPHIR_CALL_METHOD(NULL, &eventsManager, "fire", NULL, 0, &_8$$6, this_ptr, &savepointName);
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
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *nesting_param = NULL, eventsManager, savepointName, _0, _2, _5, _8, _10, _1$$3, _3$$4, _4$$5, _9$$6, _11$$8;
	zend_bool nesting, _6, _7;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&eventsManager);
	ZVAL_UNDEF(&savepointName);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_4$$5);
	ZVAL_UNDEF(&_9$$6);
	ZVAL_UNDEF(&_11$$8);
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_BOOL(nesting)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 0, 1, &nesting_param);
	if (!nesting_param) {
		nesting = 1;
	} else {
		}
	zephir_read_property(&_0, this_ptr, ZEND_STRL("transactionLevel"), PH_NOISY_CC | PH_READONLY);
	if (ZEPHIR_IS_LONG_IDENTICAL(&_0, 0)) {
		ZEPHIR_INIT_VAR(&_1$$3);
		object_init_ex(&_1$$3, phalcon_db_exceptions_noactivetransaction_ce);
		ZEPHIR_CALL_METHOD(NULL, &_1$$3, "__construct", NULL, 88);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$3, "phalcon/Db/Adapter/Pdo/AbstractPdo.zep", 169);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_read_property(&_2, this_ptr, ZEND_STRL("transactionLevel"), PH_NOISY_CC | PH_READONLY);
	if (ZEPHIR_IS_LONG_IDENTICAL(&_2, 1)) {
		zephir_read_property(&_3$$4, this_ptr, ZEND_STRL("eventsManager"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CPY_WRT(&eventsManager, &_3$$4);
		if (Z_TYPE_P(&eventsManager) == IS_OBJECT) {
			ZEPHIR_INIT_VAR(&_4$$5);
			ZVAL_STRING(&_4$$5, "db:commitTransaction");
			ZEPHIR_CALL_METHOD(NULL, &eventsManager, "fire", NULL, 0, &_4$$5, this_ptr);
			zephir_check_call_status();
		}
		RETURN_ON_FAILURE(zephir_property_decr(this_ptr, SL("transactionLevel")));
		zephir_read_property(&_3$$4, this_ptr, ZEND_STRL("pdo"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_RETURN_CALL_METHOD(&_3$$4, "commit", NULL, 0);
		zephir_check_call_status();
		RETURN_MM();
	}
	zephir_read_property(&_5, this_ptr, ZEND_STRL("transactionLevel"), PH_NOISY_CC | PH_READONLY);
	_6 = ZEPHIR_IS_LONG_IDENTICAL(&_5, 0);
	if (!(_6)) {
		_6 = !nesting;
	}
	_7 = _6;
	if (!(_7)) {
		ZEPHIR_CALL_METHOD(&_8, this_ptr, "isnestedtransactionswithsavepoints", NULL, 0);
		zephir_check_call_status();
		_7 = !zephir_is_true(&_8);
	}
	if (_7) {
		zephir_read_property(&_9$$6, this_ptr, ZEND_STRL("transactionLevel"), PH_NOISY_CC | PH_READONLY);
		if (ZEPHIR_GT_LONG(&_9$$6, 0)) {
			RETURN_ON_FAILURE(zephir_property_decr(this_ptr, SL("transactionLevel")));
		}
		RETURN_MM_BOOL(0);
	}
	zephir_read_property(&_10, this_ptr, ZEND_STRL("eventsManager"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&eventsManager, &_10);
	ZEPHIR_CALL_METHOD(&savepointName, this_ptr, "getnestedtransactionsavepointname", NULL, 0);
	zephir_check_call_status();
	if (Z_TYPE_P(&eventsManager) == IS_OBJECT) {
		ZEPHIR_INIT_VAR(&_11$$8);
		ZVAL_STRING(&_11$$8, "db:releaseSavepoint");
		ZEPHIR_CALL_METHOD(NULL, &eventsManager, "fire", NULL, 0, &_11$$8, this_ptr, &savepointName);
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
	zend_string *_8;
	zend_ulong _7;
	zend_bool _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *descriptor_param = NULL, __$true, __$false, username, password, dsnAttributes, dsnAttributesCustomRaw, dsnAttributesMap, key, options, persistent, value, autoReconnect, _2, _4, _5, *_6, _10, _11, _12, _0$$3, _3$$9, _9$$12;
	zval descriptor, dsnParts;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&descriptor);
	ZVAL_UNDEF(&dsnParts);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&username);
	ZVAL_UNDEF(&password);
	ZVAL_UNDEF(&dsnAttributes);
	ZVAL_UNDEF(&dsnAttributesCustomRaw);
	ZVAL_UNDEF(&dsnAttributesMap);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&options);
	ZVAL_UNDEF(&persistent);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&autoReconnect);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_11);
	ZVAL_UNDEF(&_12);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_3$$9);
	ZVAL_UNDEF(&_9$$12);
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		ZEPHIR_Z_PARAM_ARRAY(descriptor, descriptor_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
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
	zephir_memory_observe(&username);
	if (zephir_array_isset_string_fetch(&username, &descriptor, SL("username"), 0)) {
		zephir_array_unset_string(&descriptor, SL("username"), PH_SEPARATE);
	}
	zephir_memory_observe(&password);
	if (zephir_array_isset_string_fetch(&password, &descriptor, SL("password"), 0)) {
		zephir_array_unset_string(&descriptor, SL("password"), PH_SEPARATE);
	}
	if (zephir_array_isset_value_string(&descriptor, SL("dialectClass"))) {
		zephir_array_unset_string(&descriptor, SL("dialectClass"), PH_SEPARATE);
	}
	_1 = zephir_array_isset_value_string(&descriptor, SL("options"));
	if (_1) {
		zephir_array_fetch_string(&_2, &descriptor, SL("options"), PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/AbstractPdo.zep", 283);
		_1 = Z_TYPE_P(&_2) == IS_ARRAY;
	}
	if (_1) {
		zephir_memory_observe(&options);
		zephir_array_fetch_string(&options, &descriptor, SL("options"), PH_NOISY, "phalcon/Db/Adapter/Pdo/AbstractPdo.zep", 284);
		zephir_array_unset_string(&descriptor, SL("options"), PH_SEPARATE);
	} else {
		ZEPHIR_INIT_NVAR(&options);
		array_init(&options);
	}
	zephir_memory_observe(&persistent);
	if (zephir_array_isset_string_fetch(&persistent, &descriptor, SL("persistent"), 0)) {
		ZEPHIR_INIT_VAR(&_3$$9);
		ZVAL_BOOL(&_3$$9, zephir_get_boolval(&persistent));
		zephir_array_update_long(&options, 12, &_3$$9, PH_COPY | PH_SEPARATE ZEPHIR_DEBUG_PARAMS_DUMMY);
	}
	zephir_memory_observe(&autoReconnect);
	if (zephir_array_isset_string_fetch(&autoReconnect, &descriptor, SL("autoReconnect"), 0)) {
		if (zephir_get_boolval(&autoReconnect)) {
			zephir_update_property_zval(this_ptr, ZEND_STRL("autoReconnect"), &__$true);
		} else {
			zephir_update_property_zval(this_ptr, ZEND_STRL("autoReconnect"), &__$false);
		}
		zephir_array_unset_string(&descriptor, SL("autoReconnect"), PH_SEPARATE);
	}
	ZEPHIR_INIT_VAR(&_4);
	ZVAL_LONG(&_4, 2);
	zephir_array_update_long(&options, 3, &_4, PH_COPY | PH_SEPARATE ZEPHIR_DEBUG_PARAMS_DUMMY);
	zephir_memory_observe(&dsnAttributesCustomRaw);
	if (zephir_array_isset_string_fetch(&dsnAttributesCustomRaw, &descriptor, SL("dsn"), 0)) {
		zephir_array_append(&dsnParts, &dsnAttributesCustomRaw, PH_SEPARATE, "phalcon/Db/Adapter/Pdo/AbstractPdo.zep", 307);
		zephir_array_unset_string(&descriptor, SL("dsn"), PH_SEPARATE);
	}
	ZEPHIR_CALL_METHOD(&_5, this_ptr, "getdsndefaults", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&dsnAttributesMap);
	zephir_fast_array_merge(&dsnAttributesMap, &_5, &descriptor);
	zephir_is_iterable(&dsnAttributesMap, 0, "phalcon/Db/Adapter/Pdo/AbstractPdo.zep", 327);
	ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&dsnAttributesMap), _7, _8, _6)
	{
		ZEPHIR_INIT_NVAR(&key);
		if (_8 != NULL) { 
			ZVAL_STR_COPY(&key, _8);
		} else {
			ZVAL_LONG(&key, _7);
		}
		ZEPHIR_INIT_NVAR(&value);
		ZVAL_COPY(&value, _6);
		ZEPHIR_INIT_NVAR(&_9$$12);
		ZEPHIR_CONCAT_VSV(&_9$$12, &key, "=", &value);
		zephir_array_append(&dsnParts, &_9$$12, PH_SEPARATE, "phalcon/Db/Adapter/Pdo/AbstractPdo.zep", 323);
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&value);
	ZEPHIR_INIT_NVAR(&key);
	ZEPHIR_INIT_VAR(&dsnAttributes);
	zephir_fast_join_str(&dsnAttributes, SL(";"), &dsnParts);
	ZEPHIR_INIT_VAR(&_10);
	object_init_ex(&_10, php_pdo_get_dbh_ce());
	zephir_read_property(&_11, this_ptr, ZEND_STRL("type"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_12);
	ZEPHIR_CONCAT_VSV(&_12, &_11, ":", &dsnAttributes);
	ZEPHIR_CALL_METHOD(NULL, &_10, "__construct", NULL, 0, &_12, &username, &password, &options);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, ZEND_STRL("pdo"), &_10);
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
	zephir_fcall_cache_entry *_6 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS, setOrder = 0;
	zval params;
	zval sql_zv, *params_param = NULL, boundSql, placeHolders, bindPattern, matches, placeMatch, value, _0, _1, _2, *_3$$3, _9$$3, _4$$4, _5$$6, _7$$5, _8$$7;
	zend_string *sql = NULL;

	ZVAL_UNDEF(&sql_zv);
	ZVAL_UNDEF(&boundSql);
	ZVAL_UNDEF(&placeHolders);
	ZVAL_UNDEF(&bindPattern);
	ZVAL_UNDEF(&matches);
	ZVAL_UNDEF(&placeMatch);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_9$$3);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_5$$6);
	ZVAL_UNDEF(&_7$$5);
	ZVAL_UNDEF(&_8$$7);
	ZVAL_UNDEF(&params);
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_STR(sql)
		Z_PARAM_OPTIONAL
		ZEPHIR_Z_PARAM_ARRAY(params, params_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	if (ZEND_NUM_ARGS() > 1) {
		params_param = ZEND_CALL_ARG(execute_data, 2);
	}
	zephir_memory_observe(&sql_zv);
	ZVAL_STR_COPY(&sql_zv, sql);
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
	zephir_preg_match(&_1, &bindPattern, &sql_zv, &matches, 1, zephir_get_intval(&_0) , 0 );
	if (zephir_is_true(&_1)) {
		zephir_is_iterable(&matches, 0, "phalcon/Db/Adapter/Pdo/AbstractPdo.zep", 377);
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&matches), _3$$3)
		{
			ZEPHIR_INIT_NVAR(&placeMatch);
			ZVAL_COPY(&placeMatch, _3$$3);
			ZEPHIR_OBS_NVAR(&value);
			zephir_array_fetch_long(&_4$$4, &placeMatch, 1, PH_READONLY, "phalcon/Db/Adapter/Pdo/AbstractPdo.zep", 364);
			if (!(zephir_array_isset_fetch(&value, &params, &_4$$4, 0))) {
				if (UNEXPECTED(!(zephir_array_isset_value_long(&placeMatch, 2)))) {
					ZEPHIR_INIT_NVAR(&_5$$6);
					object_init_ex(&_5$$6, phalcon_db_exceptions_matchedparameternotfound_ce);
					ZEPHIR_CALL_METHOD(NULL, &_5$$6, "__construct", &_6, 89);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_5$$6, "phalcon/Db/Adapter/Pdo/AbstractPdo.zep", 366);
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_OBS_NVAR(&value);
				zephir_array_fetch_long(&_7$$5, &placeMatch, 2, PH_READONLY, "phalcon/Db/Adapter/Pdo/AbstractPdo.zep", 369);
				if (UNEXPECTED(!(zephir_array_isset_fetch(&value, &params, &_7$$5, 0)))) {
					ZEPHIR_INIT_NVAR(&_8$$7);
					object_init_ex(&_8$$7, phalcon_db_exceptions_matchedparameternotfound_ce);
					ZEPHIR_CALL_METHOD(NULL, &_8$$7, "__construct", &_6, 89);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_8$$7, "phalcon/Db/Adapter/Pdo/AbstractPdo.zep", 370);
					ZEPHIR_MM_RESTORE();
					return;
				}
			}
			zephir_array_append(&placeHolders, &value, PH_SEPARATE, "phalcon/Db/Adapter/Pdo/AbstractPdo.zep", 374);
		} ZEND_HASH_FOREACH_END();
		ZEPHIR_INIT_NVAR(&placeMatch);
		ZEPHIR_INIT_VAR(&_9$$3);
		ZVAL_STRING(&_9$$3, "?");
		ZEPHIR_CALL_FUNCTION(&boundSql, "preg_replace", NULL, 90, &bindPattern, &_9$$3, &sql_zv);
		zephir_check_call_status();
	} else {
		ZEPHIR_CPY_WRT(&boundSql, &sql_zv);
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
	zval str_zv, _0;
	zend_string *str = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&str_zv);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(str)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&str_zv);
	ZVAL_STR_COPY(&str_zv, str);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("pdo"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_0, "quote", NULL, 0, &str_zv);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Ensures the connection is alive, reconnecting in place if it is not.
 */
PHP_METHOD(Phalcon_Db_Adapter_Pdo_AbstractPdo, ensureConnection)
{
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "ping", NULL, 0);
	zephir_check_call_status();
	if (!(zephir_is_true(&_0))) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "connect", NULL, 0);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();
}

/**
 * Sends SQL statements to the database server returning the success state.
 * Use this method only when the SQL statement sent to the server does not
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
	zval sqlStatement_zv, *bindParams_param = NULL, *bindTypes_param = NULL, eventsManager, affectedRows, e, _0, _3, _1$$3, _2$$3, _4$$6, _5$$9;
	zend_string *sqlStatement = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&sqlStatement_zv);
	ZVAL_UNDEF(&eventsManager);
	ZVAL_UNDEF(&affectedRows);
	ZVAL_UNDEF(&e);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_4$$6);
	ZVAL_UNDEF(&_5$$9);
	ZVAL_UNDEF(&bindParams);
	ZVAL_UNDEF(&bindTypes);
	ZEND_PARSE_PARAMETERS_START(1, 3)
		Z_PARAM_STR(sqlStatement)
		Z_PARAM_OPTIONAL
		ZEPHIR_Z_PARAM_ARRAY(bindParams, bindParams_param)
		ZEPHIR_Z_PARAM_ARRAY(bindTypes, bindTypes_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	if (ZEND_NUM_ARGS() > 1) {
		bindParams_param = ZEND_CALL_ARG(execute_data, 2);
	}
	if (ZEND_NUM_ARGS() > 2) {
		bindTypes_param = ZEND_CALL_ARG(execute_data, 3);
	}
	zephir_memory_observe(&sqlStatement_zv);
	ZVAL_STR_COPY(&sqlStatement_zv, sqlStatement);
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
		zephir_update_property_zval(this_ptr, ZEND_STRL("sqlStatement"), &sqlStatement_zv);
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
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "preparerealsql", NULL, 0, &sqlStatement_zv, &bindParams);
	zephir_check_call_status();

	/* try_start_1: */

		ZEPHIR_CALL_METHOD(&affectedRows, this_ptr, "executestatement", NULL, 91, &sqlStatement_zv, &bindParams, &bindTypes);
		zephir_check_call_status_or_jump(try_end_1);

	try_end_1:

	if (EG(exception)) {
		ZEPHIR_INIT_VAR(&_3);
		ZVAL_OBJ(&_3, EG(exception));
		Z_ADDREF_P(&_3);
		if (zephir_is_instance_of(&_3, SL("PDOException"))) {
			zend_clear_exception();
			ZEPHIR_CPY_WRT(&e, &_3);
			ZEPHIR_CALL_METHOD(&_4$$6, this_ptr, "canreconnect", NULL, 92, &e);
			zephir_check_call_status();
			if (!(zephir_is_true(&_4$$6))) {
				zephir_throw_exception_debug(&e, "phalcon/Db/Adapter/Pdo/AbstractPdo.zep", 460);
				ZEPHIR_MM_RESTORE();
				return;
			}
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "handleconnectionlost", NULL, 93);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&affectedRows, this_ptr, "executestatement", NULL, 91, &sqlStatement_zv, &bindParams, &bindTypes);
			zephir_check_call_status();
		}
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
	zval _5$$8, _11$$13, _32$$39, _36$$44;
	zend_bool _30, _19$$22, _27$$31, _43$$53, _51$$62;
	zend_string *_2, *_15$$22, *_24$$31, *_39$$53, *_48$$62;
	zend_ulong _1, _14$$22, _23$$31, _38$$53, _47$$62;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_4 = NULL, *_7 = NULL, *_10 = NULL, *_12 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval placeholders, dataTypes;
	zval *statement, statement_sub, *placeholders_param = NULL, *dataTypes_param = NULL, wildcard, value, type, castValue, parameter, position, itemValue, *_0, _29, _3$$6, _6$$9, _8$$9, _9$$12, *_13$$22, _18$$22, _16$$24, _17$$25, _20$$27, _21$$28, *_22$$31, _26$$31, _25$$32, _28$$33, _31$$37, _33$$40, _34$$40, _35$$43, *_37$$53, _42$$53, _40$$55, _41$$56, _44$$58, _45$$59, *_46$$62, _50$$62, _49$$63, _52$$64;

	ZVAL_UNDEF(&statement_sub);
	ZVAL_UNDEF(&wildcard);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&type);
	ZVAL_UNDEF(&castValue);
	ZVAL_UNDEF(&parameter);
	ZVAL_UNDEF(&position);
	ZVAL_UNDEF(&itemValue);
	ZVAL_UNDEF(&_29);
	ZVAL_UNDEF(&_3$$6);
	ZVAL_UNDEF(&_6$$9);
	ZVAL_UNDEF(&_8$$9);
	ZVAL_UNDEF(&_9$$12);
	ZVAL_UNDEF(&_18$$22);
	ZVAL_UNDEF(&_16$$24);
	ZVAL_UNDEF(&_17$$25);
	ZVAL_UNDEF(&_20$$27);
	ZVAL_UNDEF(&_21$$28);
	ZVAL_UNDEF(&_26$$31);
	ZVAL_UNDEF(&_25$$32);
	ZVAL_UNDEF(&_28$$33);
	ZVAL_UNDEF(&_31$$37);
	ZVAL_UNDEF(&_33$$40);
	ZVAL_UNDEF(&_34$$40);
	ZVAL_UNDEF(&_35$$43);
	ZVAL_UNDEF(&_42$$53);
	ZVAL_UNDEF(&_40$$55);
	ZVAL_UNDEF(&_41$$56);
	ZVAL_UNDEF(&_44$$58);
	ZVAL_UNDEF(&_45$$59);
	ZVAL_UNDEF(&_50$$62);
	ZVAL_UNDEF(&_49$$63);
	ZVAL_UNDEF(&_52$$64);
	ZVAL_UNDEF(&placeholders);
	ZVAL_UNDEF(&dataTypes);
	ZVAL_UNDEF(&_5$$8);
	ZVAL_UNDEF(&_11$$13);
	ZVAL_UNDEF(&_32$$39);
	ZVAL_UNDEF(&_36$$44);
	ZEND_PARSE_PARAMETERS_START(2, 3)
		Z_PARAM_OBJECT_OF_CLASS(statement, zephir_get_internal_ce(SL("pdostatement")))
		ZEPHIR_Z_PARAM_ARRAY(placeholders, placeholders_param)
		Z_PARAM_OPTIONAL
		ZEPHIR_Z_PARAM_ARRAY(dataTypes, dataTypes_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 2, 1, &statement, &placeholders_param, &dataTypes_param);
	ZEPHIR_OBS_COPY_OR_DUP(&placeholders, placeholders_param);
	if (!dataTypes_param) {
		ZEPHIR_INIT_VAR(&dataTypes);
		array_init(&dataTypes);
	} else {
		zephir_get_arrval(&dataTypes, dataTypes_param);
	}
	zephir_is_iterable(&placeholders, 0, "phalcon/Db/Adapter/Pdo/AbstractPdo.zep", 594);
	if (Z_TYPE_P(&placeholders) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&placeholders), _1, _2, _0)
		{
			ZEPHIR_INIT_NVAR(&wildcard);
			if (_2 != NULL) { 
				ZVAL_STR_COPY(&wildcard, _2);
			} else {
				ZVAL_LONG(&wildcard, _1);
			}
			ZEPHIR_INIT_NVAR(&value);
			ZVAL_COPY(&value, _0);
			if (Z_TYPE_P(&wildcard) == IS_LONG) {
				ZEPHIR_INIT_NVAR(&parameter);
				ZVAL_LONG(&parameter, (zephir_get_numberval(&wildcard) + 1));
			} else if (Z_TYPE_P(&wildcard) == IS_STRING) {
				ZEPHIR_CPY_WRT(&parameter, &wildcard);
			} else {
				ZEPHIR_INIT_NVAR(&_3$$6);
				object_init_ex(&_3$$6, phalcon_db_exceptions_invalidbindparameter_ce);
				ZEPHIR_CALL_METHOD(NULL, &_3$$6, "__construct", &_4, 94);
				zephir_check_call_status();
				zephir_throw_exception_debug(&_3$$6, "phalcon/Db/Adapter/Pdo/AbstractPdo.zep", 514);
				ZEPHIR_MM_RESTORE();
				return;
			}
			ZEPHIR_OBS_NVAR(&type);
			if (zephir_array_isset_fetch(&type, &dataTypes, &wildcard, 0)) {
				if (ZEPHIR_IS_LONG(&type, 32)) {
					zephir_cast_to_string(&_5$$8, &value);
					ZEPHIR_CPY_WRT(&castValue, &_5$$8);
					ZEPHIR_INIT_NVAR(&type);
					ZVAL_LONG(&type, 1024);
				} else {
					ZEPHIR_INIT_NVAR(&_8$$9);
					ZVAL_STRING(&_8$$9, "db.force_casting");
					ZEPHIR_CALL_CE_STATIC(&_6$$9, phalcon_support_settings_ce, "get", &_7, 0, &_8$$9);
					zephir_check_call_status();
					if (zephir_is_true(&_6$$9)) {
						if (Z_TYPE_P(&value) != IS_ARRAY) {
							do {
								if (ZEPHIR_IS_LONG(&type, 1)) {
									ZVAL_LONG(&_9$$12, 10);
									ZEPHIR_CALL_FUNCTION(&castValue, "intval", &_10, 95, &value, &_9$$12);
									zephir_check_call_status();
									break;
								}
								if (ZEPHIR_IS_LONG(&type, 2)) {
									zephir_cast_to_string(&_11$$13, &value);
									ZEPHIR_CPY_WRT(&castValue, &_11$$13);
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
						ZEPHIR_CALL_METHOD(NULL, statement, "bindvalue", &_12, 0, &parameter, &castValue);
						zephir_check_call_status();
					} else {
						ZEPHIR_CALL_METHOD(NULL, statement, "bindvalue", &_12, 0, &parameter, &castValue, &type);
						zephir_check_call_status();
					}
				} else {
					zephir_is_iterable(&castValue, 0, "phalcon/Db/Adapter/Pdo/AbstractPdo.zep", 582);
					if (Z_TYPE_P(&castValue) == IS_ARRAY) {
						ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&castValue), _14$$22, _15$$22, _13$$22)
						{
							ZEPHIR_INIT_NVAR(&position);
							if (_15$$22 != NULL) { 
								ZVAL_STR_COPY(&position, _15$$22);
							} else {
								ZVAL_LONG(&position, _14$$22);
							}
							ZEPHIR_INIT_NVAR(&itemValue);
							ZVAL_COPY(&itemValue, _13$$22);
							if (ZEPHIR_IS_LONG(&type, 1024)) {
								ZEPHIR_INIT_NVAR(&_16$$24);
								ZEPHIR_CONCAT_VV(&_16$$24, &parameter, &position);
								ZEPHIR_CALL_METHOD(NULL, statement, "bindvalue", &_12, 0, &_16$$24, &itemValue);
								zephir_check_call_status();
							} else {
								ZEPHIR_INIT_NVAR(&_17$$25);
								ZEPHIR_CONCAT_VV(&_17$$25, &parameter, &position);
								ZEPHIR_CALL_METHOD(NULL, statement, "bindvalue", &_12, 0, &_17$$25, &itemValue, &type);
								zephir_check_call_status();
							}
						} ZEND_HASH_FOREACH_END();
					} else {
						ZEPHIR_CALL_METHOD(NULL, &castValue, "rewind", NULL, 0);
						zephir_check_call_status();
						_19$$22 = 1;
						while (1) {
							if (_19$$22) {
								_19$$22 = 0;
							} else {
								ZEPHIR_CALL_METHOD(NULL, &castValue, "next", NULL, 0);
								zephir_check_call_status();
							}
							ZEPHIR_CALL_METHOD(&_18$$22, &castValue, "valid", NULL, 0);
							zephir_check_call_status();
							if (!zend_is_true(&_18$$22)) {
								break;
							}
							ZEPHIR_CALL_METHOD(&position, &castValue, "key", NULL, 0);
							zephir_check_call_status();
							ZEPHIR_CALL_METHOD(&itemValue, &castValue, "current", NULL, 0);
							zephir_check_call_status();
								if (ZEPHIR_IS_LONG(&type, 1024)) {
									ZEPHIR_INIT_NVAR(&_20$$27);
									ZEPHIR_CONCAT_VV(&_20$$27, &parameter, &position);
									ZEPHIR_CALL_METHOD(NULL, statement, "bindvalue", &_12, 0, &_20$$27, &itemValue);
									zephir_check_call_status();
								} else {
									ZEPHIR_INIT_NVAR(&_21$$28);
									ZEPHIR_CONCAT_VV(&_21$$28, &parameter, &position);
									ZEPHIR_CALL_METHOD(NULL, statement, "bindvalue", &_12, 0, &_21$$28, &itemValue, &type);
									zephir_check_call_status();
								}
						}
					}
					ZEPHIR_INIT_NVAR(&itemValue);
					ZEPHIR_INIT_NVAR(&position);
				}
			} else {
				if (Z_TYPE_P(&value) != IS_ARRAY) {
					ZEPHIR_CALL_METHOD(NULL, statement, "bindvalue", &_12, 0, &parameter, &value);
					zephir_check_call_status();
				} else {
					zephir_is_iterable(&value, 0, "phalcon/Db/Adapter/Pdo/AbstractPdo.zep", 590);
					if (Z_TYPE_P(&value) == IS_ARRAY) {
						ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&value), _23$$31, _24$$31, _22$$31)
						{
							ZEPHIR_INIT_NVAR(&position);
							if (_24$$31 != NULL) { 
								ZVAL_STR_COPY(&position, _24$$31);
							} else {
								ZVAL_LONG(&position, _23$$31);
							}
							ZEPHIR_INIT_NVAR(&itemValue);
							ZVAL_COPY(&itemValue, _22$$31);
							ZEPHIR_INIT_NVAR(&_25$$32);
							ZEPHIR_CONCAT_VV(&_25$$32, &parameter, &position);
							ZEPHIR_CALL_METHOD(NULL, statement, "bindvalue", &_12, 0, &_25$$32, &itemValue);
							zephir_check_call_status();
						} ZEND_HASH_FOREACH_END();
					} else {
						ZEPHIR_CALL_METHOD(NULL, &value, "rewind", NULL, 0);
						zephir_check_call_status();
						_27$$31 = 1;
						while (1) {
							if (_27$$31) {
								_27$$31 = 0;
							} else {
								ZEPHIR_CALL_METHOD(NULL, &value, "next", NULL, 0);
								zephir_check_call_status();
							}
							ZEPHIR_CALL_METHOD(&_26$$31, &value, "valid", NULL, 0);
							zephir_check_call_status();
							if (!zend_is_true(&_26$$31)) {
								break;
							}
							ZEPHIR_CALL_METHOD(&position, &value, "key", NULL, 0);
							zephir_check_call_status();
							ZEPHIR_CALL_METHOD(&itemValue, &value, "current", NULL, 0);
							zephir_check_call_status();
								ZEPHIR_INIT_NVAR(&_28$$33);
								ZEPHIR_CONCAT_VV(&_28$$33, &parameter, &position);
								ZEPHIR_CALL_METHOD(NULL, statement, "bindvalue", &_12, 0, &_28$$33, &itemValue);
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
		_30 = 1;
		while (1) {
			if (_30) {
				_30 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, &placeholders, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_29, &placeholders, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_29)) {
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
					ZEPHIR_INIT_NVAR(&_31$$37);
					object_init_ex(&_31$$37, phalcon_db_exceptions_invalidbindparameter_ce);
					ZEPHIR_CALL_METHOD(NULL, &_31$$37, "__construct", &_4, 94);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_31$$37, "phalcon/Db/Adapter/Pdo/AbstractPdo.zep", 514);
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_OBS_NVAR(&type);
				if (zephir_array_isset_fetch(&type, &dataTypes, &wildcard, 0)) {
					if (ZEPHIR_IS_LONG(&type, 32)) {
						zephir_cast_to_string(&_32$$39, &value);
						ZEPHIR_CPY_WRT(&castValue, &_32$$39);
						ZEPHIR_INIT_NVAR(&type);
						ZVAL_LONG(&type, 1024);
					} else {
						ZEPHIR_INIT_NVAR(&_34$$40);
						ZVAL_STRING(&_34$$40, "db.force_casting");
						ZEPHIR_CALL_CE_STATIC(&_33$$40, phalcon_support_settings_ce, "get", &_7, 0, &_34$$40);
						zephir_check_call_status();
						if (zephir_is_true(&_33$$40)) {
							if (Z_TYPE_P(&value) != IS_ARRAY) {
								do {
									if (ZEPHIR_IS_LONG(&type, 1)) {
										ZVAL_LONG(&_35$$43, 10);
										ZEPHIR_CALL_FUNCTION(&castValue, "intval", &_10, 95, &value, &_35$$43);
										zephir_check_call_status();
										break;
									}
									if (ZEPHIR_IS_LONG(&type, 2)) {
										zephir_cast_to_string(&_36$$44, &value);
										ZEPHIR_CPY_WRT(&castValue, &_36$$44);
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
							ZEPHIR_CALL_METHOD(NULL, statement, "bindvalue", &_12, 0, &parameter, &castValue);
							zephir_check_call_status();
						} else {
							ZEPHIR_CALL_METHOD(NULL, statement, "bindvalue", &_12, 0, &parameter, &castValue, &type);
							zephir_check_call_status();
						}
					} else {
						zephir_is_iterable(&castValue, 0, "phalcon/Db/Adapter/Pdo/AbstractPdo.zep", 582);
						if (Z_TYPE_P(&castValue) == IS_ARRAY) {
							ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&castValue), _38$$53, _39$$53, _37$$53)
							{
								ZEPHIR_INIT_NVAR(&position);
								if (_39$$53 != NULL) { 
									ZVAL_STR_COPY(&position, _39$$53);
								} else {
									ZVAL_LONG(&position, _38$$53);
								}
								ZEPHIR_INIT_NVAR(&itemValue);
								ZVAL_COPY(&itemValue, _37$$53);
								if (ZEPHIR_IS_LONG(&type, 1024)) {
									ZEPHIR_INIT_NVAR(&_40$$55);
									ZEPHIR_CONCAT_VV(&_40$$55, &parameter, &position);
									ZEPHIR_CALL_METHOD(NULL, statement, "bindvalue", &_12, 0, &_40$$55, &itemValue);
									zephir_check_call_status();
								} else {
									ZEPHIR_INIT_NVAR(&_41$$56);
									ZEPHIR_CONCAT_VV(&_41$$56, &parameter, &position);
									ZEPHIR_CALL_METHOD(NULL, statement, "bindvalue", &_12, 0, &_41$$56, &itemValue, &type);
									zephir_check_call_status();
								}
							} ZEND_HASH_FOREACH_END();
						} else {
							ZEPHIR_CALL_METHOD(NULL, &castValue, "rewind", NULL, 0);
							zephir_check_call_status();
							_43$$53 = 1;
							while (1) {
								if (_43$$53) {
									_43$$53 = 0;
								} else {
									ZEPHIR_CALL_METHOD(NULL, &castValue, "next", NULL, 0);
									zephir_check_call_status();
								}
								ZEPHIR_CALL_METHOD(&_42$$53, &castValue, "valid", NULL, 0);
								zephir_check_call_status();
								if (!zend_is_true(&_42$$53)) {
									break;
								}
								ZEPHIR_CALL_METHOD(&position, &castValue, "key", NULL, 0);
								zephir_check_call_status();
								ZEPHIR_CALL_METHOD(&itemValue, &castValue, "current", NULL, 0);
								zephir_check_call_status();
									if (ZEPHIR_IS_LONG(&type, 1024)) {
										ZEPHIR_INIT_NVAR(&_44$$58);
										ZEPHIR_CONCAT_VV(&_44$$58, &parameter, &position);
										ZEPHIR_CALL_METHOD(NULL, statement, "bindvalue", &_12, 0, &_44$$58, &itemValue);
										zephir_check_call_status();
									} else {
										ZEPHIR_INIT_NVAR(&_45$$59);
										ZEPHIR_CONCAT_VV(&_45$$59, &parameter, &position);
										ZEPHIR_CALL_METHOD(NULL, statement, "bindvalue", &_12, 0, &_45$$59, &itemValue, &type);
										zephir_check_call_status();
									}
							}
						}
						ZEPHIR_INIT_NVAR(&itemValue);
						ZEPHIR_INIT_NVAR(&position);
					}
				} else {
					if (Z_TYPE_P(&value) != IS_ARRAY) {
						ZEPHIR_CALL_METHOD(NULL, statement, "bindvalue", &_12, 0, &parameter, &value);
						zephir_check_call_status();
					} else {
						zephir_is_iterable(&value, 0, "phalcon/Db/Adapter/Pdo/AbstractPdo.zep", 590);
						if (Z_TYPE_P(&value) == IS_ARRAY) {
							ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&value), _47$$62, _48$$62, _46$$62)
							{
								ZEPHIR_INIT_NVAR(&position);
								if (_48$$62 != NULL) { 
									ZVAL_STR_COPY(&position, _48$$62);
								} else {
									ZVAL_LONG(&position, _47$$62);
								}
								ZEPHIR_INIT_NVAR(&itemValue);
								ZVAL_COPY(&itemValue, _46$$62);
								ZEPHIR_INIT_NVAR(&_49$$63);
								ZEPHIR_CONCAT_VV(&_49$$63, &parameter, &position);
								ZEPHIR_CALL_METHOD(NULL, statement, "bindvalue", &_12, 0, &_49$$63, &itemValue);
								zephir_check_call_status();
							} ZEND_HASH_FOREACH_END();
						} else {
							ZEPHIR_CALL_METHOD(NULL, &value, "rewind", NULL, 0);
							zephir_check_call_status();
							_51$$62 = 1;
							while (1) {
								if (_51$$62) {
									_51$$62 = 0;
								} else {
									ZEPHIR_CALL_METHOD(NULL, &value, "next", NULL, 0);
									zephir_check_call_status();
								}
								ZEPHIR_CALL_METHOD(&_50$$62, &value, "valid", NULL, 0);
								zephir_check_call_status();
								if (!zend_is_true(&_50$$62)) {
									break;
								}
								ZEPHIR_CALL_METHOD(&position, &value, "key", NULL, 0);
								zephir_check_call_status();
								ZEPHIR_CALL_METHOD(&itemValue, &value, "current", NULL, 0);
								zephir_check_call_status();
									ZEPHIR_INIT_NVAR(&_52$$64);
									ZEPHIR_CONCAT_VV(&_52$$64, &parameter, &position);
									ZEPHIR_CALL_METHOD(NULL, statement, "bindvalue", &_12, 0, &_52$$64, &itemValue);
									zephir_check_call_status();
							}
						}
						ZEPHIR_INIT_NVAR(&itemValue);
						ZEPHIR_INIT_NVAR(&position);
					}
				}
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
 * Returns whether transparent auto-reconnect is enabled.
 */
PHP_METHOD(Phalcon_Db_Adapter_Pdo_AbstractPdo, getAutoReconnect)
{

	RETURN_MEMBER(getThis(), "autoReconnect");
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
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

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

	RETURN_MEMBER(getThis(), "pdo");
}

/**
 * Returns the current transaction nesting level
 */
PHP_METHOD(Phalcon_Db_Adapter_Pdo_AbstractPdo, getTransactionLevel)
{

	RETURN_MEMBER_TYPED(getThis(), "transactionLevel", IS_LONG);
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
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

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
	zval name_zv, _0;
	zend_string *name = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_zv);
	ZVAL_UNDEF(&_0);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR_OR_NULL(name)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	if (!name) {
		ZEPHIR_INIT_VAR(&name_zv);
	} else {
	zephir_memory_observe(&name_zv);
	ZVAL_STR_COPY(&name_zv, name);
	}
	zephir_read_property(&_0, this_ptr, ZEND_STRL("pdo"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_0, "lastinsertid", NULL, 0, &name_zv);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Checks whether the underlying connection is still alive by issuing a
 * trivial query. Returns false if there is no handle or the probe fails.
 */
PHP_METHOD(Phalcon_Db_Adapter_Pdo_AbstractPdo, ping)
{
	zval _0, _3, _4, _1$$4, _2$$4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&_2$$4);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	zephir_read_property(&_0, this_ptr, ZEND_STRL("pdo"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_is_true(&_0))) {
		RETURN_MM_BOOL(0);
	}

	/* try_start_1: */

		zephir_read_property(&_1$$4, this_ptr, ZEND_STRL("pdo"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_VAR(&_2$$4);
		ZVAL_STRING(&_2$$4, "SELECT 1");
		ZEPHIR_CALL_METHOD(NULL, &_1$$4, "query", NULL, 0, &_2$$4);
		zephir_check_call_status_or_jump(try_end_1);

	try_end_1:

	if (EG(exception)) {
		ZEPHIR_INIT_VAR(&_3);
		ZVAL_OBJ(&_3, EG(exception));
		Z_ADDREF_P(&_3);
		ZEPHIR_INIT_VAR(&_4);
		if (zephir_is_instance_of(&_3, SL("Throwable"))) {
			zend_clear_exception();
			ZEPHIR_CPY_WRT(&_4, &_3);
			RETURN_MM_BOOL(0);
		}
	}
	RETURN_MM_BOOL(1);
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
	zval sqlStatement_zv, _0;
	zend_string *sqlStatement = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&sqlStatement_zv);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(sqlStatement)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&sqlStatement_zv);
	ZVAL_STR_COPY(&sqlStatement_zv, sqlStatement);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("pdo"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_0, "prepare", NULL, 0, &sqlStatement_zv);
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
	zval sqlStatement_zv, *bindParams_param = NULL, *bindTypes_param = NULL, eventsManager, statement, params, types, e, _0, _3, _1$$3, _2$$3, _4$$8, _5$$11;
	zend_string *sqlStatement = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&sqlStatement_zv);
	ZVAL_UNDEF(&eventsManager);
	ZVAL_UNDEF(&statement);
	ZVAL_UNDEF(&params);
	ZVAL_UNDEF(&types);
	ZVAL_UNDEF(&e);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_4$$8);
	ZVAL_UNDEF(&_5$$11);
	ZVAL_UNDEF(&bindParams);
	ZVAL_UNDEF(&bindTypes);
	ZEND_PARSE_PARAMETERS_START(1, 3)
		Z_PARAM_STR(sqlStatement)
		Z_PARAM_OPTIONAL
		ZEPHIR_Z_PARAM_ARRAY(bindParams, bindParams_param)
		ZEPHIR_Z_PARAM_ARRAY(bindTypes, bindTypes_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	if (ZEND_NUM_ARGS() > 1) {
		bindParams_param = ZEND_CALL_ARG(execute_data, 2);
	}
	if (ZEND_NUM_ARGS() > 2) {
		bindTypes_param = ZEND_CALL_ARG(execute_data, 3);
	}
	zephir_memory_observe(&sqlStatement_zv);
	ZVAL_STR_COPY(&sqlStatement_zv, sqlStatement);
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
		zephir_update_property_zval(this_ptr, ZEND_STRL("sqlStatement"), &sqlStatement_zv);
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
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "preparerealsql", NULL, 0, &sqlStatement_zv, &bindParams);
	zephir_check_call_status();

	/* try_start_1: */

		ZEPHIR_CALL_METHOD(&statement, this_ptr, "querystatement", NULL, 96, &sqlStatement_zv, &params, &types);
		zephir_check_call_status_or_jump(try_end_1);

	try_end_1:

	if (EG(exception)) {
		ZEPHIR_INIT_VAR(&_3);
		ZVAL_OBJ(&_3, EG(exception));
		Z_ADDREF_P(&_3);
		if (zephir_is_instance_of(&_3, SL("PDOException"))) {
			zend_clear_exception();
			ZEPHIR_CPY_WRT(&e, &_3);
			ZEPHIR_CALL_METHOD(&_4$$8, this_ptr, "canreconnect", NULL, 92, &e);
			zephir_check_call_status();
			if (!(zephir_is_true(&_4$$8))) {
				zephir_throw_exception_debug(&e, "phalcon/Db/Adapter/Pdo/AbstractPdo.zep", 775);
				ZEPHIR_MM_RESTORE();
				return;
			}
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "handleconnectionlost", NULL, 93);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&statement, this_ptr, "querystatement", NULL, 96, &sqlStatement_zv, &params, &types);
			zephir_check_call_status();
		}
	}
	if (Z_TYPE_P(&statement) == IS_OBJECT) {
		if (Z_TYPE_P(&eventsManager) == IS_OBJECT) {
			ZEPHIR_INIT_VAR(&_5$$11);
			ZVAL_STRING(&_5$$11, "db:afterQuery");
			ZEPHIR_CALL_METHOD(NULL, &eventsManager, "fire", NULL, 0, &_5$$11, this_ptr);
			zephir_check_call_status();
		}
		object_init_ex(return_value, phalcon_db_result_pdoresult_ce);
		ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 97, this_ptr, &statement, &sqlStatement_zv, &bindParams, &bindTypes);
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
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *nesting_param = NULL, eventsManager, savepointName, _0, _2, _5, _8, _10, _1$$3, _3$$4, _4$$5, _9$$6, _11$$8;
	zend_bool nesting, _6, _7;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&eventsManager);
	ZVAL_UNDEF(&savepointName);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_4$$5);
	ZVAL_UNDEF(&_9$$6);
	ZVAL_UNDEF(&_11$$8);
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_BOOL(nesting)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 0, 1, &nesting_param);
	if (!nesting_param) {
		nesting = 1;
	} else {
		}
	zephir_read_property(&_0, this_ptr, ZEND_STRL("transactionLevel"), PH_NOISY_CC | PH_READONLY);
	if (ZEPHIR_IS_LONG_IDENTICAL(&_0, 0)) {
		ZEPHIR_INIT_VAR(&_1$$3);
		object_init_ex(&_1$$3, phalcon_db_exceptions_noactivetransaction_ce);
		ZEPHIR_CALL_METHOD(NULL, &_1$$3, "__construct", NULL, 88);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$3, "phalcon/Db/Adapter/Pdo/AbstractPdo.zep", 814);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_read_property(&_2, this_ptr, ZEND_STRL("transactionLevel"), PH_NOISY_CC | PH_READONLY);
	if (ZEPHIR_IS_LONG_IDENTICAL(&_2, 1)) {
		zephir_read_property(&_3$$4, this_ptr, ZEND_STRL("eventsManager"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CPY_WRT(&eventsManager, &_3$$4);
		if (Z_TYPE_P(&eventsManager) == IS_OBJECT) {
			ZEPHIR_INIT_VAR(&_4$$5);
			ZVAL_STRING(&_4$$5, "db:rollbackTransaction");
			ZEPHIR_CALL_METHOD(NULL, &eventsManager, "fire", NULL, 0, &_4$$5, this_ptr);
			zephir_check_call_status();
		}
		RETURN_ON_FAILURE(zephir_property_decr(this_ptr, SL("transactionLevel")));
		zephir_read_property(&_3$$4, this_ptr, ZEND_STRL("pdo"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_RETURN_CALL_METHOD(&_3$$4, "rollback", NULL, 0);
		zephir_check_call_status();
		RETURN_MM();
	}
	zephir_read_property(&_5, this_ptr, ZEND_STRL("transactionLevel"), PH_NOISY_CC | PH_READONLY);
	_6 = ZEPHIR_IS_LONG_IDENTICAL(&_5, 0);
	if (!(_6)) {
		_6 = !nesting;
	}
	_7 = _6;
	if (!(_7)) {
		ZEPHIR_CALL_METHOD(&_8, this_ptr, "isnestedtransactionswithsavepoints", NULL, 0);
		zephir_check_call_status();
		_7 = !zephir_is_true(&_8);
	}
	if (_7) {
		zephir_read_property(&_9$$6, this_ptr, ZEND_STRL("transactionLevel"), PH_NOISY_CC | PH_READONLY);
		if (ZEPHIR_GT_LONG(&_9$$6, 0)) {
			RETURN_ON_FAILURE(zephir_property_decr(this_ptr, SL("transactionLevel")));
		}
		RETURN_MM_BOOL(0);
	}
	ZEPHIR_CALL_METHOD(&savepointName, this_ptr, "getnestedtransactionsavepointname", NULL, 0);
	zephir_check_call_status();
	zephir_read_property(&_10, this_ptr, ZEND_STRL("eventsManager"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&eventsManager, &_10);
	if (Z_TYPE_P(&eventsManager) == IS_OBJECT) {
		ZEPHIR_INIT_VAR(&_11$$8);
		ZVAL_STRING(&_11$$8, "db:rollbackSavepoint");
		ZEPHIR_CALL_METHOD(NULL, &eventsManager, "fire", NULL, 0, &_11$$8, this_ptr, &savepointName);
		zephir_check_call_status();
	}
	RETURN_ON_FAILURE(zephir_property_decr(this_ptr, SL("transactionLevel")));
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "rollbacksavepoint", NULL, 0, &savepointName);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Enables or disables transparent auto-reconnect on a lost connection.
 */
PHP_METHOD(Phalcon_Db_Adapter_Pdo_AbstractPdo, setAutoReconnect)
{
	zval *autoReconnect_param = NULL, __$true, __$false;
	zend_bool autoReconnect;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_BOOL(autoReconnect)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &autoReconnect_param);
	if (autoReconnect) {
		zephir_update_property_zval(this_ptr, ZEND_STRL("autoReconnect"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, ZEND_STRL("autoReconnect"), &__$false);
	}
	RETURN_THISW();
}

/**
 * Returns PDO adapter DSN defaults as a key-value map.
 */
PHP_METHOD(Phalcon_Db_Adapter_Pdo_AbstractPdo, getDsnDefaults)
{
}

/**
 * Recognizes whether an exception represents a lost ("gone away")
 * connection. The base adapter cannot know driver specifics, so it
 * returns false; concrete adapters override this.
 */
PHP_METHOD(Phalcon_Db_Adapter_Pdo_AbstractPdo, isConnectionError)
{
	zval *exception, exception_sub;

	ZVAL_UNDEF(&exception_sub);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(exception, zend_ce_throwable)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &exception);
	RETURN_BOOL(0);
}

/**
 * Constructs the SQL statement (with parameters)
 *
 * @see https://stackoverflow.com/a/8403150
 */
PHP_METHOD(Phalcon_Db_Adapter_Pdo_AbstractPdo, prepareRealSql)
{
	zend_bool _10$$3;
	zend_ulong _1$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval parameters, keys, values;
	zval statement_zv, *parameters_param = NULL, key, result, value, *_0$$3, _9$$3, _17$$3, _3$$5, _4$$6, _5$$7, _6$$8, _7$$8, _8$$9, _11$$11, _12$$12, _13$$13, _14$$14, _15$$14, _16$$15;
	zend_string *statement = NULL, *_2$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&statement_zv);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_9$$3);
	ZVAL_UNDEF(&_17$$3);
	ZVAL_UNDEF(&_3$$5);
	ZVAL_UNDEF(&_4$$6);
	ZVAL_UNDEF(&_5$$7);
	ZVAL_UNDEF(&_6$$8);
	ZVAL_UNDEF(&_7$$8);
	ZVAL_UNDEF(&_8$$9);
	ZVAL_UNDEF(&_11$$11);
	ZVAL_UNDEF(&_12$$12);
	ZVAL_UNDEF(&_13$$13);
	ZVAL_UNDEF(&_14$$14);
	ZVAL_UNDEF(&_15$$14);
	ZVAL_UNDEF(&_16$$15);
	ZVAL_UNDEF(&parameters);
	ZVAL_UNDEF(&keys);
	ZVAL_UNDEF(&values);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR(statement)
		ZEPHIR_Z_PARAM_ARRAY(parameters, parameters_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	parameters_param = ZEND_CALL_ARG(execute_data, 2);
	zephir_memory_observe(&statement_zv);
	ZVAL_STR_COPY(&statement_zv, statement);
	zephir_get_arrval(&parameters, parameters_param);
	ZEPHIR_CPY_WRT(&result, &statement_zv);
	ZEPHIR_CPY_WRT(&values, &parameters);
	if (!(ZEPHIR_IS_EMPTY(&parameters))) {
		ZEPHIR_INIT_VAR(&keys);
		array_init(&keys);
		zephir_is_iterable(&parameters, 0, "phalcon/Db/Adapter/Pdo/AbstractPdo.zep", 923);
		if (Z_TYPE_P(&parameters) == IS_ARRAY) {
			ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&parameters), _1$$3, _2$$3, _0$$3)
			{
				ZEPHIR_INIT_NVAR(&key);
				if (_2$$3 != NULL) { 
					ZVAL_STR_COPY(&key, _2$$3);
				} else {
					ZVAL_LONG(&key, _1$$3);
				}
				ZEPHIR_INIT_NVAR(&value);
				ZVAL_COPY(&value, _0$$3);
				if (Z_TYPE_P(&key) == IS_STRING) {
					ZEPHIR_INIT_NVAR(&_3$$5);
					ZEPHIR_CONCAT_SVS(&_3$$5, "/:", &key, "/");
					zephir_array_append(&keys, &_3$$5, PH_SEPARATE, "phalcon/Db/Adapter/Pdo/AbstractPdo.zep", 909);
				} else {
					ZEPHIR_INIT_NVAR(&_4$$6);
					ZVAL_STRING(&_4$$6, "/[?]/");
					zephir_array_append(&keys, &_4$$6, PH_SEPARATE, "phalcon/Db/Adapter/Pdo/AbstractPdo.zep", 911);
				}
				if (Z_TYPE_P(&value) == IS_STRING) {
					ZEPHIR_INIT_NVAR(&_5$$7);
					ZEPHIR_CONCAT_SVS(&_5$$7, "'", &value, "'");
					zephir_array_update_zval(&values, &key, &_5$$7, PH_COPY | PH_SEPARATE);
				} else if (Z_TYPE_P(&value) == IS_ARRAY) {
					ZEPHIR_INIT_NVAR(&_6$$8);
					zephir_fast_join_str(&_6$$8, SL("','"), &value);
					ZEPHIR_INIT_NVAR(&_7$$8);
					ZEPHIR_CONCAT_SVS(&_7$$8, "'", &_6$$8, "'");
					zephir_array_update_zval(&values, &key, &_7$$8, PH_COPY | PH_SEPARATE);
				} else if (Z_TYPE_P(&value) == IS_NULL) {
					ZEPHIR_INIT_NVAR(&_8$$9);
					ZVAL_STRING(&_8$$9, "NULL");
					zephir_array_update_zval(&values, &key, &_8$$9, PH_COPY | PH_SEPARATE);
				}
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, &parameters, "rewind", NULL, 0);
			zephir_check_call_status();
			_10$$3 = 1;
			while (1) {
				if (_10$$3) {
					_10$$3 = 0;
				} else {
					ZEPHIR_CALL_METHOD(NULL, &parameters, "next", NULL, 0);
					zephir_check_call_status();
				}
				ZEPHIR_CALL_METHOD(&_9$$3, &parameters, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_9$$3)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&key, &parameters, "key", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&value, &parameters, "current", NULL, 0);
				zephir_check_call_status();
					if (Z_TYPE_P(&key) == IS_STRING) {
						ZEPHIR_INIT_NVAR(&_11$$11);
						ZEPHIR_CONCAT_SVS(&_11$$11, "/:", &key, "/");
						zephir_array_append(&keys, &_11$$11, PH_SEPARATE, "phalcon/Db/Adapter/Pdo/AbstractPdo.zep", 909);
					} else {
						ZEPHIR_INIT_NVAR(&_12$$12);
						ZVAL_STRING(&_12$$12, "/[?]/");
						zephir_array_append(&keys, &_12$$12, PH_SEPARATE, "phalcon/Db/Adapter/Pdo/AbstractPdo.zep", 911);
					}
					if (Z_TYPE_P(&value) == IS_STRING) {
						ZEPHIR_INIT_NVAR(&_13$$13);
						ZEPHIR_CONCAT_SVS(&_13$$13, "'", &value, "'");
						zephir_array_update_zval(&values, &key, &_13$$13, PH_COPY | PH_SEPARATE);
					} else if (Z_TYPE_P(&value) == IS_ARRAY) {
						ZEPHIR_INIT_NVAR(&_14$$14);
						zephir_fast_join_str(&_14$$14, SL("','"), &value);
						ZEPHIR_INIT_NVAR(&_15$$14);
						ZEPHIR_CONCAT_SVS(&_15$$14, "'", &_14$$14, "'");
						zephir_array_update_zval(&values, &key, &_15$$14, PH_COPY | PH_SEPARATE);
					} else if (Z_TYPE_P(&value) == IS_NULL) {
						ZEPHIR_INIT_NVAR(&_16$$15);
						ZVAL_STRING(&_16$$15, "NULL");
						zephir_array_update_zval(&values, &key, &_16$$15, PH_COPY | PH_SEPARATE);
					}
			}
		}
		ZEPHIR_INIT_NVAR(&value);
		ZEPHIR_INIT_NVAR(&key);
		ZVAL_LONG(&_17$$3, 1);
		ZEPHIR_CALL_FUNCTION(&result, "preg_replace", NULL, 90, &keys, &values, &statement_zv, &_17$$3);
		zephir_check_call_status();
	}
	zephir_update_property_zval(this_ptr, ZEND_STRL("realSqlStatement"), &result);
	ZEPHIR_MM_RESTORE();
}

/**
 * Whether a failed query may be transparently retried after reconnecting.
 * Only when auto-reconnect is on, we are not in a transaction, and the
 * failure is a recognized connection loss.
 */
PHP_METHOD(Phalcon_Db_Adapter_Pdo_AbstractPdo, canReconnect)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *exception, exception_sub, _0, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&exception_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(exception, zend_ce_throwable)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &exception);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("autoReconnect"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_is_true(&_0))) {
		RETURN_MM_BOOL(0);
	}
	zephir_read_property(&_1, this_ptr, ZEND_STRL("transactionLevel"), PH_NOISY_CC | PH_READONLY);
	if (!ZEPHIR_IS_LONG_IDENTICAL(&_1, 0)) {
		RETURN_MM_BOOL(0);
	}
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "isconnectionerror", NULL, 0, exception);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Runs the actual write against PDO and returns the affected-rows count
 * (or the raw exec() return for unprepared statements).
 */
PHP_METHOD(Phalcon_Db_Adapter_Pdo_AbstractPdo, executeStatement)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval bindParams, bindTypes;
	zval sqlStatement_zv, *bindParams_param = NULL, *bindTypes_param = NULL, statement, newStatement, affectedRows, _0$$3, _1$$5;
	zend_string *sqlStatement = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&sqlStatement_zv);
	ZVAL_UNDEF(&statement);
	ZVAL_UNDEF(&newStatement);
	ZVAL_UNDEF(&affectedRows);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$5);
	ZVAL_UNDEF(&bindParams);
	ZVAL_UNDEF(&bindTypes);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_STR(sqlStatement)
		ZEPHIR_Z_PARAM_ARRAY(bindParams, bindParams_param)
		ZEPHIR_Z_PARAM_ARRAY(bindTypes, bindTypes_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	bindParams_param = ZEND_CALL_ARG(execute_data, 2);
	bindTypes_param = ZEND_CALL_ARG(execute_data, 3);
	zephir_memory_observe(&sqlStatement_zv);
	ZVAL_STR_COPY(&sqlStatement_zv, sqlStatement);
	zephir_get_arrval(&bindParams, bindParams_param);
	zephir_get_arrval(&bindTypes, bindTypes_param);
	ZEPHIR_INIT_VAR(&affectedRows);
	ZVAL_LONG(&affectedRows, 0);
	if (!(ZEPHIR_IS_EMPTY(&bindParams))) {
		zephir_read_property(&_0$$3, this_ptr, ZEND_STRL("pdo"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(&statement, &_0$$3, "prepare", NULL, 0, &sqlStatement_zv);
		zephir_check_call_status();
		if (Z_TYPE_P(&statement) == IS_OBJECT) {
			ZEPHIR_CALL_METHOD(&newStatement, this_ptr, "executeprepared", NULL, 0, &statement, &bindParams, &bindTypes);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&affectedRows, &newStatement, "rowcount", NULL, 0);
			zephir_check_call_status();
		}
	} else {
		zephir_read_property(&_1$$5, this_ptr, ZEND_STRL("pdo"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(&affectedRows, &_1$$5, "exec", NULL, 0, &sqlStatement_zv);
		zephir_check_call_status();
	}
	RETURN_CCTOR(&affectedRows);
}

/**
 * Notifies listeners that the connection was lost and re-establishes it.
 */
PHP_METHOD(Phalcon_Db_Adapter_Pdo_AbstractPdo, handleConnectionLost)
{
	zval eventsManager, _0, _1$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&eventsManager);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	zephir_read_property(&_0, this_ptr, ZEND_STRL("eventsManager"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&eventsManager, &_0);
	if (Z_TYPE_P(&eventsManager) == IS_OBJECT) {
		ZEPHIR_INIT_VAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "db:connectionLost");
		ZEPHIR_CALL_METHOD(NULL, &eventsManager, "fire", NULL, 0, &_1$$3, this_ptr);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "connect", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
}

/**
 * Prepares and executes a read statement, returning the live PDOStatement.
 */
PHP_METHOD(Phalcon_Db_Adapter_Pdo_AbstractPdo, queryStatement)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval params, types;
	zval sqlStatement_zv, *params_param = NULL, *types_param = NULL, statement, _0, _1$$3;
	zend_string *sqlStatement = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&sqlStatement_zv);
	ZVAL_UNDEF(&statement);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&params);
	ZVAL_UNDEF(&types);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_STR(sqlStatement)
		ZEPHIR_Z_PARAM_ARRAY(params, params_param)
		ZEPHIR_Z_PARAM_ARRAY(types, types_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	params_param = ZEND_CALL_ARG(execute_data, 2);
	types_param = ZEND_CALL_ARG(execute_data, 3);
	zephir_memory_observe(&sqlStatement_zv);
	ZVAL_STR_COPY(&sqlStatement_zv, sqlStatement);
	zephir_get_arrval(&params, params_param);
	zephir_get_arrval(&types, types_param);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("pdo"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&statement, &_0, "prepare", NULL, 0, &sqlStatement_zv);
	zephir_check_call_status();
	if (UNEXPECTED(Z_TYPE_P(&statement) != IS_OBJECT)) {
		ZEPHIR_INIT_VAR(&_1$$3);
		object_init_ex(&_1$$3, phalcon_db_exceptions_cannotpreparestatement_ce);
		ZEPHIR_CALL_METHOD(NULL, &_1$$3, "__construct", NULL, 98);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$3, "phalcon/Db/Adapter/Pdo/AbstractPdo.zep", 1000);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "executeprepared", NULL, 0, &statement, &params, &types);
	zephir_check_call_status();
	RETURN_MM();
}

