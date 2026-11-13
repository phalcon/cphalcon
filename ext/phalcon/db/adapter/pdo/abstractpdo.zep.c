
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
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "kernel/object.h"
#include "kernel/exception.h"
#include "kernel/main.h"
#include "kernel/array.h"
#include "kernel/string.h"
#include "kernel/concat.h"
#include "ext/pdo/php_pdo_driver.h"


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
 *
 * @phpstan-import-type db_bind_params from DbTypes
 * @phpstan-import-type db_bind_types from DbTypes
 * @phpstan-import-type db_descriptor from DbTypes
 * @phpstan-import-type db_dsn_defaults from DbTypes
 * @phpstan-import-type db_error_info from DbTypes
 * @phpstan-import-type db_pdo_options from DbTypes
 */
ZEPHIR_INIT_CLASS(Phalcon_Db_Adapter_Pdo_AbstractPdo)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Db\\Adapter\\Pdo, AbstractPdo, phalcon, db_adapter_pdo_abstractpdo, phalcon_db_adapter_abstractadapter_ce, phalcon_db_adapter_pdo_abstractpdo_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	/**
	 * Last affected rows
	 */
	{
		zval _zc0;
		ZVAL_LONG(&_zc0, 0);
		zephir_declare_typed_property(phalcon_db_adapter_pdo_abstractpdo_ce, SL("affectedRows"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_LONG, NULL, 0);
	}

	/**
	 * Whether to transparently reconnect and retry once when a query fails
	 * because the connection was lost. Opt-in; off by default.
	 */
	{
		zval _zc0;
		ZVAL_BOOL(&_zc0, 0);
		zephir_declare_typed_property(phalcon_db_adapter_pdo_abstractpdo_ce, SL("autoReconnect"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_BOOL, NULL, 0);
	}

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
 *
 * @phpstan-param db_descriptor $descriptor
 */
PHP_METHOD(Phalcon_Db_Adapter_Pdo_AbstractPdo, __construct)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *descriptor_param = NULL;
	zval descriptor;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&descriptor);
	ZEND_TLS zephir_method_cache _zephir_call_cache[2];
	ZEND_PARSE_PARAMETERS_START(1, 1)
		ZEPHIR_Z_PARAM_ARRAY(descriptor, descriptor_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &descriptor_param);
	zephir_get_arrval(&descriptor, descriptor_param);
	ZEPHIR_CALL_METHOD_CACHED(NULL, this_ptr, "connect", &_zephir_call_cache[0], &descriptor);
	zephir_check_call_status();
	ZEPHIR_CALL_PARENT_CACHED(NULL, phalcon_db_adapter_pdo_abstractpdo_ce, getThis(), "__construct", &_zephir_call_cache[1], &descriptor);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
}

/**
 * Returns the number of affected rows by the latest INSERT/UPDATE/DELETE
 * executed in the database system
 *
 *```php
 * $connection->execute(
 *     "DELETE FROM co_invoices"
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
	zval *nesting_param = NULL, e, eventsManager, savepointName, _0, _5, _8, _9, _11, _1$$3, _4$$3, _2$$4, _3$$5, _10$$9;
	zend_bool nesting, _6, _7;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&e);
	ZVAL_UNDEF(&eventsManager);
	ZVAL_UNDEF(&savepointName);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_11);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_3$$5);
	ZVAL_UNDEF(&_10$$9);
	ZEND_TLS zephir_method_cache _zephir_call_cache[7];
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	static zend_string *_zephir_prop_2 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("transactionLevel", 16, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("eventsManager", 13, 1);
	}
	if (UNEXPECTED(!_zephir_prop_2)) {
		_zephir_prop_2 = zend_string_init("pdo", 3, 1);
	}

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
	ZEPHIR_CALL_METHOD_CACHED(NULL, this_ptr, "resetStaleTransactionLevel", &_zephir_call_cache[0]);
	zephir_check_call_status();
	RETURN_ON_FAILURE(zephir_property_incr(this_ptr, SL("transactionLevel")));
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 108, PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (ZEPHIR_IS_LONG_IDENTICAL(&_0, 1)) {
		zephir_read_property_cached(&_1$$3, this_ptr, _zephir_prop_1, 109, PH_NOISY_CC | PH_READONLY);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_CPY_WRT(&eventsManager, &_1$$3);
		if (Z_TYPE_P(&eventsManager) == IS_OBJECT) {
			ZEPHIR_INIT_VAR(&_2$$4);
			ZVAL_STRING(&_2$$4, "db:beginTransaction");
			ZEPHIR_CALL_METHOD_CACHED(NULL, &eventsManager, "fire", &_zephir_call_cache[1], &_2$$4, this_ptr);
			zephir_check_call_status();
		}

		/* try_start_1: */

			zephir_read_property_cached(&_3$$5, this_ptr, _zephir_prop_2, 110, PH_NOISY_CC | PH_READONLY);
			if (UNEXPECTED(EG(exception))) {
				goto try_end_1;
			}
			ZEPHIR_RETURN_CALL_METHOD_CACHED(&_3$$5, "beginTransaction", &_zephir_call_cache[2]);
			zephir_check_call_status_or_jump(try_end_1);
			RETURN_MM();

		try_end_1:

		if (EG(exception)) {
			ZEPHIR_INIT_VAR(&_4$$3);
			ZVAL_OBJ(&_4$$3, EG(exception));
			Z_ADDREF_P(&_4$$3);
			if (zephir_is_instance_of(&_4$$3, SL("Throwable"))) {
				zend_clear_exception();
				ZEPHIR_CPY_WRT(&e, &_4$$3);
				RETURN_ON_FAILURE(zephir_property_decr(this_ptr, SL("transactionLevel")));
				zephir_throw_exception_debug(&e, "phalcon/Db/Adapter/Pdo/AbstractPdo.zep", 151);
				ZEPHIR_MM_RESTORE();
				return;
			} else {
				ZEPHIR_MM_RESTORE();
				return;
			}
		}
	}
	zephir_read_property_cached(&_5, this_ptr, _zephir_prop_0, 108, PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	_6 = ZEPHIR_IS_LONG_IDENTICAL(&_5, 0);
	if (!(_6)) {
		_6 = !nesting;
	}
	_7 = _6;
	if (!(_7)) {
		ZEPHIR_CALL_METHOD_CACHED(&_8, this_ptr, "isNestedTransactionsWithSavepoints", &_zephir_call_cache[3]);
		zephir_check_call_status();
		_7 = !zephir_is_true(&_8);
	}
	if (_7) {
		RETURN_MM_BOOL(0);
	}
	zephir_read_property_cached(&_9, this_ptr, _zephir_prop_1, 109, PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CPY_WRT(&eventsManager, &_9);
	ZEPHIR_CALL_METHOD_CACHED(&savepointName, this_ptr, "getNestedTransactionSavepointName", &_zephir_call_cache[4]);
	zephir_check_call_status();
	if (Z_TYPE_P(&eventsManager) == IS_OBJECT) {
		ZEPHIR_INIT_VAR(&_10$$9);
		ZVAL_STRING(&_10$$9, "db:createSavepoint");
		ZEPHIR_CALL_METHOD_CACHED(NULL, &eventsManager, "fire", &_zephir_call_cache[5], &_10$$9, this_ptr, &savepointName);
		zephir_check_call_status();
	}

	/* try_start_2: */

		ZEPHIR_RETURN_CALL_METHOD_CACHED(this_ptr, "createSavepoint", &_zephir_call_cache[6], &savepointName);
		zephir_check_call_status_or_jump(try_end_2);
		RETURN_MM();

	try_end_2:

	if (EG(exception)) {
		ZEPHIR_INIT_VAR(&_11);
		ZVAL_OBJ(&_11, EG(exception));
		Z_ADDREF_P(&_11);
		if (zephir_is_instance_of(&_11, SL("Throwable"))) {
			zend_clear_exception();
			ZEPHIR_CPY_WRT(&e, &_11);
			RETURN_ON_FAILURE(zephir_property_decr(this_ptr, SL("transactionLevel")));
			zephir_throw_exception_debug(&e, "phalcon/Db/Adapter/Pdo/AbstractPdo.zep", 181);
			ZEPHIR_MM_RESTORE();
			return;
		} else {
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
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
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("pdo", 3, 1);
	}
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 110, &__$null);
}

/**
 * Commits the active transaction in the connection
 */
PHP_METHOD(Phalcon_Db_Adapter_Pdo_AbstractPdo, commit)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *nesting_param = NULL, e, eventsManager, savepointName, _0, _2, _8, _10, _12, _1$$3, _3$$4, _6$$4, _4$$5, _5$$6, _9$$9, _11$$11;
	zend_bool nesting, _7;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&e);
	ZVAL_UNDEF(&eventsManager);
	ZVAL_UNDEF(&savepointName);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_12);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_4$$5);
	ZVAL_UNDEF(&_5$$6);
	ZVAL_UNDEF(&_9$$9);
	ZVAL_UNDEF(&_11$$11);
	ZEND_TLS zephir_method_cache _zephir_call_cache[8];
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	static zend_string *_zephir_prop_2 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("transactionLevel", 16, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("eventsManager", 13, 1);
	}
	if (UNEXPECTED(!_zephir_prop_2)) {
		_zephir_prop_2 = zend_string_init("pdo", 3, 1);
	}

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
	ZEPHIR_CALL_METHOD_CACHED(NULL, this_ptr, "resetStaleTransactionLevel", &_zephir_call_cache[0]);
	zephir_check_call_status();
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 108, PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (ZEPHIR_IS_LONG_IDENTICAL(&_0, 0)) {
		ZEPHIR_INIT_VAR(&_1$$3);
		object_init_ex(&_1$$3, phalcon_db_exceptions_noactivetransaction_ce);
		ZEPHIR_CALL_METHOD_CACHED(NULL, &_1$$3, "__construct", &_zephir_call_cache[1]);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$3, "phalcon/Db/Adapter/Pdo/AbstractPdo.zep", 207);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_read_property_cached(&_2, this_ptr, _zephir_prop_0, 108, PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (ZEPHIR_IS_LONG_IDENTICAL(&_2, 1)) {
		zephir_read_property_cached(&_3$$4, this_ptr, _zephir_prop_1, 109, PH_NOISY_CC | PH_READONLY);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_CPY_WRT(&eventsManager, &_3$$4);
		if (Z_TYPE_P(&eventsManager) == IS_OBJECT) {
			ZEPHIR_INIT_VAR(&_4$$5);
			ZVAL_STRING(&_4$$5, "db:commitTransaction");
			ZEPHIR_CALL_METHOD_CACHED(NULL, &eventsManager, "fire", &_zephir_call_cache[2], &_4$$5, this_ptr);
			zephir_check_call_status();
		}
		RETURN_ON_FAILURE(zephir_property_decr(this_ptr, SL("transactionLevel")));

		/* try_start_1: */

			zephir_read_property_cached(&_5$$6, this_ptr, _zephir_prop_2, 110, PH_NOISY_CC | PH_READONLY);
			if (UNEXPECTED(EG(exception))) {
				goto try_end_1;
			}
			ZEPHIR_RETURN_CALL_METHOD_CACHED(&_5$$6, "commit", &_zephir_call_cache[3]);
			zephir_check_call_status_or_jump(try_end_1);
			RETURN_MM();

		try_end_1:

		if (EG(exception)) {
			ZEPHIR_INIT_VAR(&_6$$4);
			ZVAL_OBJ(&_6$$4, EG(exception));
			Z_ADDREF_P(&_6$$4);
			if (zephir_is_instance_of(&_6$$4, SL("Throwable"))) {
				zend_clear_exception();
				ZEPHIR_CPY_WRT(&e, &_6$$4);
				RETURN_ON_FAILURE(zephir_property_incr(this_ptr, SL("transactionLevel")));
				zephir_throw_exception_debug(&e, "phalcon/Db/Adapter/Pdo/AbstractPdo.zep", 233);
				ZEPHIR_MM_RESTORE();
				return;
			} else {
				ZEPHIR_MM_RESTORE();
				return;
			}
		}
	}
	_7 = !nesting;
	if (!(_7)) {
		ZEPHIR_CALL_METHOD_CACHED(&_8, this_ptr, "isNestedTransactionsWithSavepoints", &_zephir_call_cache[4]);
		zephir_check_call_status();
		_7 = !zephir_is_true(&_8);
	}
	if (_7) {
		zephir_read_property_cached(&_9$$9, this_ptr, _zephir_prop_0, 108, PH_NOISY_CC | PH_READONLY);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		if (ZEPHIR_GT_LONG(&_9$$9, 0)) {
			RETURN_ON_FAILURE(zephir_property_decr(this_ptr, SL("transactionLevel")));
		}
		RETURN_MM_BOOL(0);
	}
	zephir_read_property_cached(&_10, this_ptr, _zephir_prop_1, 109, PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CPY_WRT(&eventsManager, &_10);
	ZEPHIR_CALL_METHOD_CACHED(&savepointName, this_ptr, "getNestedTransactionSavepointName", &_zephir_call_cache[5]);
	zephir_check_call_status();
	if (Z_TYPE_P(&eventsManager) == IS_OBJECT) {
		ZEPHIR_INIT_VAR(&_11$$11);
		ZVAL_STRING(&_11$$11, "db:releaseSavepoint");
		ZEPHIR_CALL_METHOD_CACHED(NULL, &eventsManager, "fire", &_zephir_call_cache[6], &_11$$11, this_ptr, &savepointName);
		zephir_check_call_status();
	}
	RETURN_ON_FAILURE(zephir_property_decr(this_ptr, SL("transactionLevel")));

	/* try_start_2: */

		ZEPHIR_RETURN_CALL_METHOD_CACHED(this_ptr, "releaseSavepoint", &_zephir_call_cache[7], &savepointName);
		zephir_check_call_status_or_jump(try_end_2);
		RETURN_MM();

	try_end_2:

	if (EG(exception)) {
		ZEPHIR_INIT_VAR(&_12);
		ZVAL_OBJ(&_12, EG(exception));
		Z_ADDREF_P(&_12);
		if (zephir_is_instance_of(&_12, SL("Throwable"))) {
			zend_clear_exception();
			ZEPHIR_CPY_WRT(&e, &_12);
			RETURN_ON_FAILURE(zephir_property_incr(this_ptr, SL("transactionLevel")));
			zephir_throw_exception_debug(&e, "phalcon/Db/Adapter/Pdo/AbstractPdo.zep", 275);
			ZEPHIR_MM_RESTORE();
			return;
		} else {
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
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
 *
 * @phpstan-param db_descriptor $descriptor
 */
PHP_METHOD(Phalcon_Db_Adapter_Pdo_AbstractPdo, connect)
{
	zend_string *_17;
	zend_ulong _16;
	zend_bool _1, _2, _3, _4, _5, _7, _9, _11;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *descriptor_param = NULL, __$true, __$false, username, password, dsnAttributes, dsnAttributesCustomRaw, dsnAttributesMap, key, options, persistent, value, autoReconnect, _6, _10, _12, *_13, _14, *_15, _19, _20, _21, _0$$3, _8$$9, _18$$12;
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
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_12);
	ZVAL_UNDEF(&_14);
	ZVAL_UNDEF(&_19);
	ZVAL_UNDEF(&_20);
	ZVAL_UNDEF(&_21);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_8$$9);
	ZVAL_UNDEF(&_18$$12);
	ZEND_TLS zephir_method_cache _zephir_call_cache[2];
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	static zend_string *_zephir_prop_2 = NULL;
	static zend_string *_zephir_prop_3 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("descriptor", 10, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("autoReconnect", 13, 1);
	}
	if (UNEXPECTED(!_zephir_prop_2)) {
		_zephir_prop_2 = zend_string_init("type", 4, 1);
	}
	if (UNEXPECTED(!_zephir_prop_3)) {
		_zephir_prop_3 = zend_string_init("pdo", 3, 1);
	}

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
		zephir_get_arrval(&descriptor, descriptor_param);
	}
	ZEPHIR_INIT_VAR(&dsnParts);
	array_init(&dsnParts);
	if (ZEPHIR_IS_EMPTY(&descriptor)) {
		zephir_read_property_cached(&_0$$3, this_ptr, _zephir_prop_0, 111, PH_NOISY_CC | PH_READONLY);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		if (UNEXPECTED(Z_TYPE_P(&_0$$3) != IS_ARRAY)) {
			zephir_throw_variable_type_error(&_0$$3, "descriptor", "array");
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_CPY_WRT(&descriptor, &_0$$3);
	}
	zephir_memory_observe(&username);
	_1 = zephir_array_isset_string_fetch(&username, &descriptor, SL("username"), 0);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (_1) {
		zephir_array_unset_string(&descriptor, SL("username"), PH_SEPARATE);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	zephir_memory_observe(&password);
	_2 = zephir_array_isset_string_fetch(&password, &descriptor, SL("password"), 0);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (_2) {
		zephir_array_unset_string(&descriptor, SL("password"), PH_SEPARATE);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	_3 = zephir_array_isset_value_string(&descriptor, SL("dialectClass"));
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (_3) {
		zephir_array_unset_string(&descriptor, SL("dialectClass"), PH_SEPARATE);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	_4 = zephir_array_isset_value_string(&descriptor, SL("options"));
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	_5 = _4;
	if (_5) {
		zephir_memory_observe(&_6);
		zephir_array_fetch_string(&_6, &descriptor, SL("options"), PH_NOISY, "phalcon/Db/Adapter/Pdo/AbstractPdo.zep", 334);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		_5 = (Z_TYPE_P(&_6) == IS_ARRAY);
	}
	if (_5) {
		zephir_memory_observe(&options);
		zephir_array_fetch_string(&options, &descriptor, SL("options"), PH_NOISY, "phalcon/Db/Adapter/Pdo/AbstractPdo.zep", 335);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		zephir_array_unset_string(&descriptor, SL("options"), PH_SEPARATE);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
	} else {
		ZEPHIR_INIT_NVAR(&options);
		array_init(&options);
	}
	zephir_memory_observe(&persistent);
	_7 = zephir_array_isset_string_fetch(&persistent, &descriptor, SL("persistent"), 0);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (_7) {
		ZEPHIR_INIT_VAR(&_8$$9);
		ZVAL_BOOL(&_8$$9, zephir_get_boolval(&persistent));
		zephir_array_update_long(&options, 12, &_8$$9, PH_COPY | PH_SEPARATE ZEPHIR_DEBUG_PARAMS_DUMMY);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	zephir_memory_observe(&autoReconnect);
	_9 = zephir_array_isset_string_fetch(&autoReconnect, &descriptor, SL("autoReconnect"), 0);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (_9) {
		if (zephir_get_boolval(&autoReconnect)) {
			zephir_update_property_zval_cached(this_ptr, _zephir_prop_1, 112, &__$true);
		} else {
			zephir_update_property_zval_cached(this_ptr, _zephir_prop_1, 112, &__$false);
		}
		zephir_array_unset_string(&descriptor, SL("autoReconnect"), PH_SEPARATE);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	ZEPHIR_INIT_VAR(&_10);
	ZVAL_LONG(&_10, 2);
	zephir_array_update_long(&options, 3, &_10, PH_COPY | PH_SEPARATE ZEPHIR_DEBUG_PARAMS_DUMMY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_memory_observe(&dsnAttributesCustomRaw);
	_11 = zephir_array_isset_string_fetch(&dsnAttributesCustomRaw, &descriptor, SL("dsn"), 0);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (_11) {
		zephir_array_append(&dsnParts, &dsnAttributesCustomRaw, PH_SEPARATE, "phalcon/Db/Adapter/Pdo/AbstractPdo.zep", 358);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		zephir_array_unset_string(&descriptor, SL("dsn"), PH_SEPARATE);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	ZEPHIR_CALL_METHOD_CACHED(&_12, this_ptr, "getDsnDefaults", &_zephir_call_cache[0]);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&dsnAttributesMap);
	zephir_fast_array_merge(&dsnAttributesMap, &_12, &descriptor);
	if (Z_TYPE_P(&dsnAttributesMap) == IS_STRING) {
		ZEPHIR_INIT_VAR(&_14);
		zephir_string_to_char_array(&_14, &dsnAttributesMap);
		_13 = &_14;
	} else {
		_13 = &dsnAttributesMap;
	}
	zephir_is_iterable(_13, 0, "phalcon/Db/Adapter/Pdo/AbstractPdo.zep", 378);
	ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(_13), _16, _17, _15)
	{
		ZEPHIR_INIT_NVAR(&key);
		if (_17 != NULL) { 
			ZVAL_STR_COPY(&key, _17);
		} else {
			ZVAL_LONG(&key, _16);
		}
		ZEPHIR_INIT_NVAR(&value);
		ZVAL_COPY(&value, _15);
		ZEPHIR_INIT_NVAR(&_18$$12);
		ZEPHIR_CONCAT_VSV(&_18$$12, &key, "=", &value);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		zephir_array_append(&dsnParts, &_18$$12, PH_SEPARATE, "phalcon/Db/Adapter/Pdo/AbstractPdo.zep", 374);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&value);
	ZEPHIR_INIT_NVAR(&key);
	ZEPHIR_INIT_VAR(&dsnAttributes);
	zephir_fast_join_str(&dsnAttributes, SL(";"), &dsnParts);
	ZEPHIR_INIT_VAR(&_19);
	object_init_ex(&_19, php_pdo_get_dbh_ce());
	zephir_read_property_cached(&_20, this_ptr, _zephir_prop_2, 113, PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(&_21);
	ZEPHIR_CONCAT_VSV(&_21, &_20, ":", &dsnAttributes);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CALL_METHOD_CACHED(NULL, &_19, "__construct", &_zephir_call_cache[1], &_21, &username, &password, &options);
	zephir_check_call_status();
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_3, 110, &_19);
	ZEPHIR_MM_RESTORE();
}

/**
 * Converts bound parameters such as :name: or ?1 into PDO bind params ?
 *
 *```php
 * print_r(
 *     $connection->convertBoundParams(
 *         "SELECT * FROM co_invoices WHERE inv_title = :inv_title:",
 *         [
 *             "Test Invoice",
 *         ]
 *     )
 * );
 *```
 *
 * @phpstan-param db_bind_params $params
 *
 * @phpstan-return array{sql: string, params: list<mixed>}
 */
PHP_METHOD(Phalcon_Db_Adapter_Pdo_AbstractPdo, convertBoundParams)
{
	zend_bool _7$$4, _8$$5, _11$$5;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS, setOrder = 0;
	zval params;
	zval sql_zv, *params_param = NULL, boundSql, placeHolders, bindPattern, matches, placeMatch, value, _0, _1, _2, *_3$$3, _4$$3, *_5$$3, _13$$3, _6$$4, _10$$5, _9$$6, _12$$7;
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
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_13$$3);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_10$$5);
	ZVAL_UNDEF(&_9$$6);
	ZVAL_UNDEF(&_12$$7);
	ZVAL_UNDEF(&params);
	ZEND_TLS zephir_method_cache _zephir_call_cache[2];
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
		if (Z_TYPE_P(&matches) == IS_STRING) {
			ZEPHIR_INIT_VAR(&_4$$3);
			zephir_string_to_char_array(&_4$$3, &matches);
			_3$$3 = &_4$$3;
		} else {
			_3$$3 = &matches;
		}
		zephir_is_iterable(_3$$3, 0, "phalcon/Db/Adapter/Pdo/AbstractPdo.zep", 432);
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_3$$3), _5$$3)
		{
			ZEPHIR_INIT_NVAR(&placeMatch);
			ZVAL_COPY(&placeMatch, _5$$3);
			ZEPHIR_OBS_NVAR(&value);
			ZEPHIR_OBS_NVAR(&_6$$4);
			zephir_array_fetch_long(&_6$$4, &placeMatch, 1, 0, "phalcon/Db/Adapter/Pdo/AbstractPdo.zep", 419);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			_7$$4 = zephir_array_isset_fetch(&value, &params, &_6$$4, 0);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			if (!(_7$$4)) {
				_8$$5 = zephir_array_isset_value_long(&placeMatch, 2);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (UNEXPECTED(!(_8$$5))) {
					ZEPHIR_INIT_NVAR(&_9$$6);
					object_init_ex(&_9$$6, phalcon_db_exceptions_matchedparameternotfound_ce);
					ZEPHIR_CALL_METHOD_CACHED(NULL, &_9$$6, "__construct", &_zephir_call_cache[0]);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_9$$6, "phalcon/Db/Adapter/Pdo/AbstractPdo.zep", 421);
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_OBS_NVAR(&value);
				ZEPHIR_OBS_NVAR(&_10$$5);
				zephir_array_fetch_long(&_10$$5, &placeMatch, 2, 0, "phalcon/Db/Adapter/Pdo/AbstractPdo.zep", 424);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				_11$$5 = zephir_array_isset_fetch(&value, &params, &_10$$5, 0);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (UNEXPECTED(!(_11$$5))) {
					ZEPHIR_INIT_NVAR(&_12$$7);
					object_init_ex(&_12$$7, phalcon_db_exceptions_matchedparameternotfound_ce);
					ZEPHIR_CALL_METHOD_CACHED(NULL, &_12$$7, "__construct", &_zephir_call_cache[1]);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_12$$7, "phalcon/Db/Adapter/Pdo/AbstractPdo.zep", 425);
					ZEPHIR_MM_RESTORE();
					return;
				}
			}
			zephir_array_append(&placeHolders, &value, PH_SEPARATE, "phalcon/Db/Adapter/Pdo/AbstractPdo.zep", 429);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
		} ZEND_HASH_FOREACH_END();
		ZEPHIR_INIT_NVAR(&placeMatch);
		ZEPHIR_INIT_VAR(&_13$$3);
		ZVAL_STRING(&_13$$3, "?");
		ZEPHIR_CALL_FUNCTION(&boundSql, "preg_replace", NULL, 2, &bindPattern, &_13$$3, &sql_zv);
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
 * Ensures the connection is alive, reconnecting in place if it is not.
 */
PHP_METHOD(Phalcon_Db_Adapter_Pdo_AbstractPdo, ensureConnection)
{
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZEND_TLS zephir_method_cache _zephir_call_cache[2];
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	ZEPHIR_CALL_METHOD_CACHED(&_0, this_ptr, "ping", &_zephir_call_cache[0]);
	zephir_check_call_status();
	if (!(zephir_is_true(&_0))) {
		ZEPHIR_CALL_METHOD_CACHED(NULL, this_ptr, "connect", &_zephir_call_cache[1]);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();
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
	ZEND_TLS zephir_method_cache _zephir_call_cache[1];
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("pdo", 3, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(str)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&str_zv);
	ZVAL_STR_COPY(&str_zv, str);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 110, PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_RETURN_CALL_METHOD_CACHED(&_0, "quote", &_zephir_call_cache[0], &str_zv);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Sends SQL statements to the database server returning the success state.
 * Use this method only when the SQL statement sent to the server does not
 * return any rows
 *
 *```php
 * // Inserting data
 * $success = $connection->execute(
 *     "INSERT INTO co_invoices VALUES (1, 'Test Invoice')"
 * );
 *
 * $success = $connection->execute(
 *     "INSERT INTO co_invoices VALUES (?, ?)",
 *     [
 *         1,
 *         "Test Invoice",
 *     ]
 * );
 *```
 *
 * @phpstan-param db_bind_params $bindParams
 * @phpstan-param db_bind_types  $bindTypes
 */
PHP_METHOD(Phalcon_Db_Adapter_Pdo_AbstractPdo, execute)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval bindParams, bindTypes;
	zval sqlStatement_zv, *bindParams_param = NULL, *bindTypes_param = NULL, eventsManager, affectedRows, e, _0, _3, _1$$3, _2$$3, _4$$6, _5$$10;
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
	ZVAL_UNDEF(&_5$$10);
	ZVAL_UNDEF(&bindParams);
	ZVAL_UNDEF(&bindTypes);
	ZEND_TLS zephir_method_cache _zephir_call_cache[7];
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	static zend_string *_zephir_prop_2 = NULL;
	static zend_string *_zephir_prop_3 = NULL;
	static zend_string *_zephir_prop_4 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("eventsManager", 13, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("sqlStatement", 12, 1);
	}
	if (UNEXPECTED(!_zephir_prop_2)) {
		_zephir_prop_2 = zend_string_init("sqlVariables", 12, 1);
	}
	if (UNEXPECTED(!_zephir_prop_3)) {
		_zephir_prop_3 = zend_string_init("sqlBindTypes", 12, 1);
	}
	if (UNEXPECTED(!_zephir_prop_4)) {
		_zephir_prop_4 = zend_string_init("affectedRows", 12, 1);
	}

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
		zephir_get_arrval(&bindParams, bindParams_param);
	}
	if (!bindTypes_param) {
		ZEPHIR_INIT_VAR(&bindTypes);
		array_init(&bindTypes);
	} else {
		zephir_get_arrval(&bindTypes, bindTypes_param);
	}
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 109, PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CPY_WRT(&eventsManager, &_0);
	if (Z_TYPE_P(&eventsManager) == IS_OBJECT) {
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_1, 114, &sqlStatement_zv);
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_2, 115, &bindParams);
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_3, 116, &bindTypes);
		ZEPHIR_INIT_VAR(&_2$$3);
		ZVAL_STRING(&_2$$3, "db:beforeQuery");
		ZEPHIR_CALL_METHOD_CACHED(&_1$$3, &eventsManager, "fire", &_zephir_call_cache[0], &_2$$3, this_ptr);
		zephir_check_call_status();
		if (ZEPHIR_IS_FALSE_IDENTICAL(&_1$$3)) {
			RETURN_MM_BOOL(0);
		}
	}
	ZEPHIR_INIT_VAR(&affectedRows);
	ZVAL_LONG(&affectedRows, 0);
	ZEPHIR_CALL_METHOD_CACHED(NULL, this_ptr, "prepareRealSql", &_zephir_call_cache[1], &sqlStatement_zv, &bindParams);
	zephir_check_call_status();

	/* try_start_1: */

		ZEPHIR_CALL_METHOD_CACHED(&affectedRows, this_ptr, "executeStatement", &_zephir_call_cache[2], &sqlStatement_zv, &bindParams, &bindTypes);
		zephir_check_call_status_or_jump(try_end_1);

	try_end_1:

	if (EG(exception)) {
		ZEPHIR_INIT_VAR(&_3);
		ZVAL_OBJ(&_3, EG(exception));
		Z_ADDREF_P(&_3);
		if (zephir_is_instance_of(&_3, SL("PDOException"))) {
			zend_clear_exception();
			ZEPHIR_CPY_WRT(&e, &_3);
			ZEPHIR_CALL_METHOD_CACHED(&_4$$6, this_ptr, "canReconnect", &_zephir_call_cache[3], &e);
			zephir_check_call_status();
			if (!(zephir_is_true(&_4$$6))) {
				zephir_throw_exception_debug(&e, "phalcon/Db/Adapter/Pdo/AbstractPdo.zep", 518);
				ZEPHIR_MM_RESTORE();
				return;
			}
			ZEPHIR_CALL_METHOD_CACHED(NULL, this_ptr, "handleConnectionLost", &_zephir_call_cache[4]);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD_CACHED(&affectedRows, this_ptr, "executeStatement", &_zephir_call_cache[5], &sqlStatement_zv, &bindParams, &bindTypes);
			zephir_check_call_status();
		} else {
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	if (Z_TYPE_P(&affectedRows) == IS_LONG) {
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_4, 117, &affectedRows);
		if (Z_TYPE_P(&eventsManager) == IS_OBJECT) {
			ZEPHIR_INIT_VAR(&_5$$10);
			ZVAL_STRING(&_5$$10, "db:afterQuery");
			ZEPHIR_CALL_METHOD_CACHED(NULL, &eventsManager, "fire", &_zephir_call_cache[6], &_5$$10, this_ptr);
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
 *     "SELECT * FROM co_invoices WHERE inv_title = :inv_title"
 * );
 *
 * $result = $connection->executePrepared(
 *     $statement,
 *     [
 *         "inv_title" => "Test Invoice",
 *     ],
 *     [
 *         "inv_title" => Column::BIND_PARAM_STR,
 *     ]
 * );
 *```
 *
 * @phpstan-param db_bind_params $placeholders
 * @phpstan-param db_bind_types  $dataTypes
 */
PHP_METHOD(Phalcon_Db_Adapter_Pdo_AbstractPdo, executePrepared)
{
	zval _6$$8, _11$$13, _37$$39, _41$$44;
	zend_bool _33, _5$$3, _20$$22, _30$$31, _36$$34, _50$$53, _60$$62;
	zend_string *_2, *_16$$22, *_27$$31, *_46$$53, *_57$$62;
	zend_ulong _1, _15$$22, _26$$31, _45$$53, _56$$62;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_10 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval placeholders, dataTypes;
	zval *statement, statement_sub, *placeholders_param = NULL, *dataTypes_param = NULL, castValue, itemValue, position, type, value, wildcard, parameter, *_0, _32, _3$$4, _4$$6, _7$$9, _8$$9, _9$$12, *_12$$22, _13$$22, *_14$$22, _19$$22, _17$$24, _18$$25, _21$$27, _22$$28, *_23$$31, _24$$31, *_25$$31, _29$$31, _28$$32, _31$$33, _34$$35, _35$$37, _38$$40, _39$$40, _40$$43, *_42$$53, _43$$53, *_44$$53, _49$$53, _47$$55, _48$$56, _51$$58, _52$$59, *_53$$62, _54$$62, *_55$$62, _59$$62, _58$$63, _61$$64;

	ZVAL_UNDEF(&statement_sub);
	ZVAL_UNDEF(&castValue);
	ZVAL_UNDEF(&itemValue);
	ZVAL_UNDEF(&position);
	ZVAL_UNDEF(&type);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&wildcard);
	ZVAL_UNDEF(&parameter);
	ZVAL_UNDEF(&_32);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_4$$6);
	ZVAL_UNDEF(&_7$$9);
	ZVAL_UNDEF(&_8$$9);
	ZVAL_UNDEF(&_9$$12);
	ZVAL_UNDEF(&_13$$22);
	ZVAL_UNDEF(&_19$$22);
	ZVAL_UNDEF(&_17$$24);
	ZVAL_UNDEF(&_18$$25);
	ZVAL_UNDEF(&_21$$27);
	ZVAL_UNDEF(&_22$$28);
	ZVAL_UNDEF(&_24$$31);
	ZVAL_UNDEF(&_29$$31);
	ZVAL_UNDEF(&_28$$32);
	ZVAL_UNDEF(&_31$$33);
	ZVAL_UNDEF(&_34$$35);
	ZVAL_UNDEF(&_35$$37);
	ZVAL_UNDEF(&_38$$40);
	ZVAL_UNDEF(&_39$$40);
	ZVAL_UNDEF(&_40$$43);
	ZVAL_UNDEF(&_43$$53);
	ZVAL_UNDEF(&_49$$53);
	ZVAL_UNDEF(&_47$$55);
	ZVAL_UNDEF(&_48$$56);
	ZVAL_UNDEF(&_51$$58);
	ZVAL_UNDEF(&_52$$59);
	ZVAL_UNDEF(&_54$$62);
	ZVAL_UNDEF(&_59$$62);
	ZVAL_UNDEF(&_58$$63);
	ZVAL_UNDEF(&_61$$64);
	ZVAL_UNDEF(&placeholders);
	ZVAL_UNDEF(&dataTypes);
	ZVAL_UNDEF(&_6$$8);
	ZVAL_UNDEF(&_11$$13);
	ZVAL_UNDEF(&_37$$39);
	ZVAL_UNDEF(&_41$$44);
	ZEND_TLS zephir_method_cache _zephir_call_cache[48];
	ZEND_PARSE_PARAMETERS_START(2, 3)
		Z_PARAM_OBJECT_OF_CLASS(statement, zephir_get_internal_ce(SL("pdostatement")))
		ZEPHIR_Z_PARAM_ARRAY(placeholders, placeholders_param)
		Z_PARAM_OPTIONAL
		ZEPHIR_Z_PARAM_ARRAY(dataTypes, dataTypes_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 2, 1, &statement, &placeholders_param, &dataTypes_param);
	zephir_get_arrval(&placeholders, placeholders_param);
	if (!dataTypes_param) {
		ZEPHIR_INIT_VAR(&dataTypes);
		array_init(&dataTypes);
	} else {
		zephir_get_arrval(&dataTypes, dataTypes_param);
	}
	ZEPHIR_INIT_VAR(&parameter);
	ZVAL_NULL(&parameter);
	zephir_is_iterable(&placeholders, 0, "phalcon/Db/Adapter/Pdo/AbstractPdo.zep", 656);
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
				ZEPHIR_INIT_NVAR(&_3$$4);
				ZVAL_LONG(&_3$$4, 1);
				ZEPHIR_INIT_NVAR(&parameter);
				zephir_add_function(&parameter, &wildcard, &_3$$4);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
			} else if (Z_TYPE_P(&wildcard) == IS_STRING) {
				ZEPHIR_CPY_WRT(&parameter, &wildcard);
			} else {
				ZEPHIR_INIT_NVAR(&_4$$6);
				object_init_ex(&_4$$6, phalcon_db_exceptions_invalidbindparameter_ce);
				ZEPHIR_CALL_METHOD_CACHED(NULL, &_4$$6, "__construct", &_zephir_call_cache[0]);
				zephir_check_call_status();
				zephir_throw_exception_debug(&_4$$6, "phalcon/Db/Adapter/Pdo/AbstractPdo.zep", 576);
				ZEPHIR_MM_RESTORE();
				return;
			}
			ZEPHIR_OBS_NVAR(&type);
			_5$$3 = zephir_array_isset_fetch(&type, &dataTypes, &wildcard, 0);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			if (_5$$3) {
				if (ZEPHIR_IS_LONG(&type, 32)) {
					zephir_cast_to_string(&_6$$8, &value);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					ZEPHIR_CPY_WRT(&castValue, &_6$$8);
					ZEPHIR_INIT_NVAR(&type);
					ZVAL_LONG(&type, 1024);
				} else {
					ZEPHIR_INIT_NVAR(&_8$$9);
					ZVAL_STRING(&_8$$9, "db.force_casting");
					ZEPHIR_CALL_CE_STATIC_CACHED(&_7$$9, phalcon_support_settings_ce, "get", &_zephir_call_cache[1], &_8$$9);
					zephir_check_call_status();
					if (zephir_is_true(&_7$$9)) {
						if (Z_TYPE_P(&value) != IS_ARRAY) {
							if (ZEPHIR_IS_LONG(&type, 1)) { goto zephir_switch_0_clause_0; }
							if (ZEPHIR_IS_LONG(&type, 2)) { goto zephir_switch_0_clause_1; }
							if (ZEPHIR_IS_LONG(&type, 0)) { goto zephir_switch_0_clause_2; }
							if (ZEPHIR_IS_LONG(&type, 5)) { goto zephir_switch_0_clause_3; }
							goto zephir_switch_0_clause_4;
							zephir_switch_0_clause_0: ;
								ZVAL_LONG(&_9$$12, 10);
								ZEPHIR_CALL_FUNCTION(&castValue, "intval", &_10, 37, &value, &_9$$12);
								zephir_check_call_status();
								goto zephir_switch_0_end;
							zephir_switch_0_clause_1: ;
								zephir_cast_to_string(&_11$$13, &value);
								if (UNEXPECTED(EG(exception))) {
									ZEPHIR_MM_RESTORE();
									return;
								}
								ZEPHIR_CPY_WRT(&castValue, &_11$$13);
								goto zephir_switch_0_end;
							zephir_switch_0_clause_2: ;
								ZEPHIR_INIT_NVAR(&castValue);
								ZVAL_NULL(&castValue);
								goto zephir_switch_0_end;
							zephir_switch_0_clause_3: ;
								ZEPHIR_INIT_NVAR(&castValue);
								ZVAL_BOOL(&castValue, zephir_get_boolval(&value));
								goto zephir_switch_0_end;
							zephir_switch_0_clause_4: ;
								ZEPHIR_CPY_WRT(&castValue, &value);
								goto zephir_switch_0_end;
							zephir_switch_0_end: ;

						} else {
							ZEPHIR_CPY_WRT(&castValue, &value);
						}
					} else {
						ZEPHIR_CPY_WRT(&castValue, &value);
					}
				}
				if (Z_TYPE_P(&castValue) != IS_ARRAY) {
					if (ZEPHIR_IS_LONG(&type, 1024)) {
						ZEPHIR_CALL_METHOD_CACHED(NULL, statement, "bindValue", &_zephir_call_cache[2], &parameter, &castValue);
						zephir_check_call_status();
					} else {
						ZEPHIR_CALL_METHOD_CACHED(NULL, statement, "bindValue", &_zephir_call_cache[3], &parameter, &castValue, &type);
						zephir_check_call_status();
					}
				} else {
					if (Z_TYPE_P(&castValue) == IS_STRING) {
						ZEPHIR_INIT_NVAR(&_13$$22);
						zephir_string_to_char_array(&_13$$22, &castValue);
						_12$$22 = &_13$$22;
					} else {
						_12$$22 = &castValue;
					}
					zephir_is_iterable(_12$$22, 0, "phalcon/Db/Adapter/Pdo/AbstractPdo.zep", 644);
					if (Z_TYPE_P(_12$$22) == IS_ARRAY) {
						ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(_12$$22), _15$$22, _16$$22, _14$$22)
						{
							ZEPHIR_INIT_NVAR(&position);
							if (_16$$22 != NULL) { 
								ZVAL_STR_COPY(&position, _16$$22);
							} else {
								ZVAL_LONG(&position, _15$$22);
							}
							ZEPHIR_INIT_NVAR(&itemValue);
							ZVAL_COPY(&itemValue, _14$$22);
							if (ZEPHIR_IS_LONG(&type, 1024)) {
								ZEPHIR_INIT_NVAR(&_17$$24);
								ZEPHIR_CONCAT_VV(&_17$$24, &parameter, &position);
								if (UNEXPECTED(EG(exception))) {
									ZEPHIR_MM_RESTORE();
									return;
								}
								ZEPHIR_CALL_METHOD_CACHED(NULL, statement, "bindValue", &_zephir_call_cache[4], &_17$$24, &itemValue);
								zephir_check_call_status();
							} else {
								ZEPHIR_INIT_NVAR(&_18$$25);
								ZEPHIR_CONCAT_VV(&_18$$25, &parameter, &position);
								if (UNEXPECTED(EG(exception))) {
									ZEPHIR_MM_RESTORE();
									return;
								}
								ZEPHIR_CALL_METHOD_CACHED(NULL, statement, "bindValue", &_zephir_call_cache[5], &_18$$25, &itemValue, &type);
								zephir_check_call_status();
							}
						} ZEND_HASH_FOREACH_END();
					} else {
						ZEPHIR_CALL_METHOD_CACHED(NULL, _12$$22, "rewind", &_zephir_call_cache[6]);
						zephir_check_call_status();
						_20$$22 = 1;
						while (1) {
							if (_20$$22) {
								_20$$22 = 0;
							} else {
								ZEPHIR_CALL_METHOD_CACHED(NULL, _12$$22, "next", &_zephir_call_cache[7]);
								zephir_check_call_status();
							}
							ZEPHIR_CALL_METHOD_CACHED(&_19$$22, _12$$22, "valid", &_zephir_call_cache[8]);
							zephir_check_call_status();
							if (!zend_is_true(&_19$$22)) {
								break;
							}
							ZEPHIR_CALL_METHOD_CACHED(&position, _12$$22, "key", &_zephir_call_cache[9]);
							zephir_check_call_status();
							ZEPHIR_CALL_METHOD_CACHED(&itemValue, _12$$22, "current", &_zephir_call_cache[10]);
							zephir_check_call_status();
								if (ZEPHIR_IS_LONG(&type, 1024)) {
									ZEPHIR_INIT_NVAR(&_21$$27);
									ZEPHIR_CONCAT_VV(&_21$$27, &parameter, &position);
									if (UNEXPECTED(EG(exception))) {
										ZEPHIR_MM_RESTORE();
										return;
									}
									ZEPHIR_CALL_METHOD_CACHED(NULL, statement, "bindValue", &_zephir_call_cache[11], &_21$$27, &itemValue);
									zephir_check_call_status();
								} else {
									ZEPHIR_INIT_NVAR(&_22$$28);
									ZEPHIR_CONCAT_VV(&_22$$28, &parameter, &position);
									if (UNEXPECTED(EG(exception))) {
										ZEPHIR_MM_RESTORE();
										return;
									}
									ZEPHIR_CALL_METHOD_CACHED(NULL, statement, "bindValue", &_zephir_call_cache[12], &_22$$28, &itemValue, &type);
									zephir_check_call_status();
								}
						}
					}
					ZEPHIR_INIT_NVAR(&itemValue);
					ZEPHIR_INIT_NVAR(&position);
				}
			} else {
				if (Z_TYPE_P(&value) != IS_ARRAY) {
					ZEPHIR_CALL_METHOD_CACHED(NULL, statement, "bindValue", &_zephir_call_cache[13], &parameter, &value);
					zephir_check_call_status();
				} else {
					if (Z_TYPE_P(&value) == IS_STRING) {
						ZEPHIR_INIT_NVAR(&_24$$31);
						zephir_string_to_char_array(&_24$$31, &value);
						_23$$31 = &_24$$31;
					} else {
						_23$$31 = &value;
					}
					zephir_is_iterable(_23$$31, 0, "phalcon/Db/Adapter/Pdo/AbstractPdo.zep", 652);
					if (Z_TYPE_P(_23$$31) == IS_ARRAY) {
						ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(_23$$31), _26$$31, _27$$31, _25$$31)
						{
							ZEPHIR_INIT_NVAR(&position);
							if (_27$$31 != NULL) { 
								ZVAL_STR_COPY(&position, _27$$31);
							} else {
								ZVAL_LONG(&position, _26$$31);
							}
							ZEPHIR_INIT_NVAR(&itemValue);
							ZVAL_COPY(&itemValue, _25$$31);
							ZEPHIR_INIT_NVAR(&_28$$32);
							ZEPHIR_CONCAT_VV(&_28$$32, &parameter, &position);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
							ZEPHIR_CALL_METHOD_CACHED(NULL, statement, "bindValue", &_zephir_call_cache[14], &_28$$32, &itemValue);
							zephir_check_call_status();
						} ZEND_HASH_FOREACH_END();
					} else {
						ZEPHIR_CALL_METHOD_CACHED(NULL, _23$$31, "rewind", &_zephir_call_cache[15]);
						zephir_check_call_status();
						_30$$31 = 1;
						while (1) {
							if (_30$$31) {
								_30$$31 = 0;
							} else {
								ZEPHIR_CALL_METHOD_CACHED(NULL, _23$$31, "next", &_zephir_call_cache[16]);
								zephir_check_call_status();
							}
							ZEPHIR_CALL_METHOD_CACHED(&_29$$31, _23$$31, "valid", &_zephir_call_cache[17]);
							zephir_check_call_status();
							if (!zend_is_true(&_29$$31)) {
								break;
							}
							ZEPHIR_CALL_METHOD_CACHED(&position, _23$$31, "key", &_zephir_call_cache[18]);
							zephir_check_call_status();
							ZEPHIR_CALL_METHOD_CACHED(&itemValue, _23$$31, "current", &_zephir_call_cache[19]);
							zephir_check_call_status();
								ZEPHIR_INIT_NVAR(&_31$$33);
								ZEPHIR_CONCAT_VV(&_31$$33, &parameter, &position);
								if (UNEXPECTED(EG(exception))) {
									ZEPHIR_MM_RESTORE();
									return;
								}
								ZEPHIR_CALL_METHOD_CACHED(NULL, statement, "bindValue", &_zephir_call_cache[20], &_31$$33, &itemValue);
								zephir_check_call_status();
						}
					}
					ZEPHIR_INIT_NVAR(&itemValue);
					ZEPHIR_INIT_NVAR(&position);
				}
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD_CACHED(NULL, &placeholders, "rewind", &_zephir_call_cache[21]);
		zephir_check_call_status();
		_33 = 1;
		while (1) {
			if (_33) {
				_33 = 0;
			} else {
				ZEPHIR_CALL_METHOD_CACHED(NULL, &placeholders, "next", &_zephir_call_cache[22]);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD_CACHED(&_32, &placeholders, "valid", &_zephir_call_cache[23]);
			zephir_check_call_status();
			if (!zend_is_true(&_32)) {
				break;
			}
			ZEPHIR_CALL_METHOD_CACHED(&wildcard, &placeholders, "key", &_zephir_call_cache[24]);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD_CACHED(&value, &placeholders, "current", &_zephir_call_cache[25]);
			zephir_check_call_status();
				if (Z_TYPE_P(&wildcard) == IS_LONG) {
					ZEPHIR_INIT_NVAR(&_34$$35);
					ZVAL_LONG(&_34$$35, 1);
					ZEPHIR_INIT_NVAR(&parameter);
					zephir_add_function(&parameter, &wildcard, &_34$$35);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
				} else if (Z_TYPE_P(&wildcard) == IS_STRING) {
					ZEPHIR_CPY_WRT(&parameter, &wildcard);
				} else {
					ZEPHIR_INIT_NVAR(&_35$$37);
					object_init_ex(&_35$$37, phalcon_db_exceptions_invalidbindparameter_ce);
					ZEPHIR_CALL_METHOD_CACHED(NULL, &_35$$37, "__construct", &_zephir_call_cache[26]);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_35$$37, "phalcon/Db/Adapter/Pdo/AbstractPdo.zep", 576);
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_OBS_NVAR(&type);
				_36$$34 = zephir_array_isset_fetch(&type, &dataTypes, &wildcard, 0);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (_36$$34) {
					if (ZEPHIR_IS_LONG(&type, 32)) {
						zephir_cast_to_string(&_37$$39, &value);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						ZEPHIR_CPY_WRT(&castValue, &_37$$39);
						ZEPHIR_INIT_NVAR(&type);
						ZVAL_LONG(&type, 1024);
					} else {
						ZEPHIR_INIT_NVAR(&_39$$40);
						ZVAL_STRING(&_39$$40, "db.force_casting");
						ZEPHIR_CALL_CE_STATIC_CACHED(&_38$$40, phalcon_support_settings_ce, "get", &_zephir_call_cache[27], &_39$$40);
						zephir_check_call_status();
						if (zephir_is_true(&_38$$40)) {
							if (Z_TYPE_P(&value) != IS_ARRAY) {
								if (ZEPHIR_IS_LONG(&type, 1)) { goto zephir_switch_1_clause_0; }
								if (ZEPHIR_IS_LONG(&type, 2)) { goto zephir_switch_1_clause_1; }
								if (ZEPHIR_IS_LONG(&type, 0)) { goto zephir_switch_1_clause_2; }
								if (ZEPHIR_IS_LONG(&type, 5)) { goto zephir_switch_1_clause_3; }
								goto zephir_switch_1_clause_4;
								zephir_switch_1_clause_0: ;
									ZVAL_LONG(&_40$$43, 10);
									ZEPHIR_CALL_FUNCTION(&castValue, "intval", &_10, 37, &value, &_40$$43);
									zephir_check_call_status();
									goto zephir_switch_1_end;
								zephir_switch_1_clause_1: ;
									zephir_cast_to_string(&_41$$44, &value);
									if (UNEXPECTED(EG(exception))) {
										ZEPHIR_MM_RESTORE();
										return;
									}
									ZEPHIR_CPY_WRT(&castValue, &_41$$44);
									goto zephir_switch_1_end;
								zephir_switch_1_clause_2: ;
									ZEPHIR_INIT_NVAR(&castValue);
									ZVAL_NULL(&castValue);
									goto zephir_switch_1_end;
								zephir_switch_1_clause_3: ;
									ZEPHIR_INIT_NVAR(&castValue);
									ZVAL_BOOL(&castValue, zephir_get_boolval(&value));
									goto zephir_switch_1_end;
								zephir_switch_1_clause_4: ;
									ZEPHIR_CPY_WRT(&castValue, &value);
									goto zephir_switch_1_end;
								zephir_switch_1_end: ;

							} else {
								ZEPHIR_CPY_WRT(&castValue, &value);
							}
						} else {
							ZEPHIR_CPY_WRT(&castValue, &value);
						}
					}
					if (Z_TYPE_P(&castValue) != IS_ARRAY) {
						if (ZEPHIR_IS_LONG(&type, 1024)) {
							ZEPHIR_CALL_METHOD_CACHED(NULL, statement, "bindValue", &_zephir_call_cache[28], &parameter, &castValue);
							zephir_check_call_status();
						} else {
							ZEPHIR_CALL_METHOD_CACHED(NULL, statement, "bindValue", &_zephir_call_cache[29], &parameter, &castValue, &type);
							zephir_check_call_status();
						}
					} else {
						if (Z_TYPE_P(&castValue) == IS_STRING) {
							ZEPHIR_INIT_NVAR(&_43$$53);
							zephir_string_to_char_array(&_43$$53, &castValue);
							_42$$53 = &_43$$53;
						} else {
							_42$$53 = &castValue;
						}
						zephir_is_iterable(_42$$53, 0, "phalcon/Db/Adapter/Pdo/AbstractPdo.zep", 644);
						if (Z_TYPE_P(_42$$53) == IS_ARRAY) {
							ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(_42$$53), _45$$53, _46$$53, _44$$53)
							{
								ZEPHIR_INIT_NVAR(&position);
								if (_46$$53 != NULL) { 
									ZVAL_STR_COPY(&position, _46$$53);
								} else {
									ZVAL_LONG(&position, _45$$53);
								}
								ZEPHIR_INIT_NVAR(&itemValue);
								ZVAL_COPY(&itemValue, _44$$53);
								if (ZEPHIR_IS_LONG(&type, 1024)) {
									ZEPHIR_INIT_NVAR(&_47$$55);
									ZEPHIR_CONCAT_VV(&_47$$55, &parameter, &position);
									if (UNEXPECTED(EG(exception))) {
										ZEPHIR_MM_RESTORE();
										return;
									}
									ZEPHIR_CALL_METHOD_CACHED(NULL, statement, "bindValue", &_zephir_call_cache[30], &_47$$55, &itemValue);
									zephir_check_call_status();
								} else {
									ZEPHIR_INIT_NVAR(&_48$$56);
									ZEPHIR_CONCAT_VV(&_48$$56, &parameter, &position);
									if (UNEXPECTED(EG(exception))) {
										ZEPHIR_MM_RESTORE();
										return;
									}
									ZEPHIR_CALL_METHOD_CACHED(NULL, statement, "bindValue", &_zephir_call_cache[31], &_48$$56, &itemValue, &type);
									zephir_check_call_status();
								}
							} ZEND_HASH_FOREACH_END();
						} else {
							ZEPHIR_CALL_METHOD_CACHED(NULL, _42$$53, "rewind", &_zephir_call_cache[32]);
							zephir_check_call_status();
							_50$$53 = 1;
							while (1) {
								if (_50$$53) {
									_50$$53 = 0;
								} else {
									ZEPHIR_CALL_METHOD_CACHED(NULL, _42$$53, "next", &_zephir_call_cache[33]);
									zephir_check_call_status();
								}
								ZEPHIR_CALL_METHOD_CACHED(&_49$$53, _42$$53, "valid", &_zephir_call_cache[34]);
								zephir_check_call_status();
								if (!zend_is_true(&_49$$53)) {
									break;
								}
								ZEPHIR_CALL_METHOD_CACHED(&position, _42$$53, "key", &_zephir_call_cache[35]);
								zephir_check_call_status();
								ZEPHIR_CALL_METHOD_CACHED(&itemValue, _42$$53, "current", &_zephir_call_cache[36]);
								zephir_check_call_status();
									if (ZEPHIR_IS_LONG(&type, 1024)) {
										ZEPHIR_INIT_NVAR(&_51$$58);
										ZEPHIR_CONCAT_VV(&_51$$58, &parameter, &position);
										if (UNEXPECTED(EG(exception))) {
											ZEPHIR_MM_RESTORE();
											return;
										}
										ZEPHIR_CALL_METHOD_CACHED(NULL, statement, "bindValue", &_zephir_call_cache[37], &_51$$58, &itemValue);
										zephir_check_call_status();
									} else {
										ZEPHIR_INIT_NVAR(&_52$$59);
										ZEPHIR_CONCAT_VV(&_52$$59, &parameter, &position);
										if (UNEXPECTED(EG(exception))) {
											ZEPHIR_MM_RESTORE();
											return;
										}
										ZEPHIR_CALL_METHOD_CACHED(NULL, statement, "bindValue", &_zephir_call_cache[38], &_52$$59, &itemValue, &type);
										zephir_check_call_status();
									}
							}
						}
						ZEPHIR_INIT_NVAR(&itemValue);
						ZEPHIR_INIT_NVAR(&position);
					}
				} else {
					if (Z_TYPE_P(&value) != IS_ARRAY) {
						ZEPHIR_CALL_METHOD_CACHED(NULL, statement, "bindValue", &_zephir_call_cache[39], &parameter, &value);
						zephir_check_call_status();
					} else {
						if (Z_TYPE_P(&value) == IS_STRING) {
							ZEPHIR_INIT_NVAR(&_54$$62);
							zephir_string_to_char_array(&_54$$62, &value);
							_53$$62 = &_54$$62;
						} else {
							_53$$62 = &value;
						}
						zephir_is_iterable(_53$$62, 0, "phalcon/Db/Adapter/Pdo/AbstractPdo.zep", 652);
						if (Z_TYPE_P(_53$$62) == IS_ARRAY) {
							ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(_53$$62), _56$$62, _57$$62, _55$$62)
							{
								ZEPHIR_INIT_NVAR(&position);
								if (_57$$62 != NULL) { 
									ZVAL_STR_COPY(&position, _57$$62);
								} else {
									ZVAL_LONG(&position, _56$$62);
								}
								ZEPHIR_INIT_NVAR(&itemValue);
								ZVAL_COPY(&itemValue, _55$$62);
								ZEPHIR_INIT_NVAR(&_58$$63);
								ZEPHIR_CONCAT_VV(&_58$$63, &parameter, &position);
								if (UNEXPECTED(EG(exception))) {
									ZEPHIR_MM_RESTORE();
									return;
								}
								ZEPHIR_CALL_METHOD_CACHED(NULL, statement, "bindValue", &_zephir_call_cache[40], &_58$$63, &itemValue);
								zephir_check_call_status();
							} ZEND_HASH_FOREACH_END();
						} else {
							ZEPHIR_CALL_METHOD_CACHED(NULL, _53$$62, "rewind", &_zephir_call_cache[41]);
							zephir_check_call_status();
							_60$$62 = 1;
							while (1) {
								if (_60$$62) {
									_60$$62 = 0;
								} else {
									ZEPHIR_CALL_METHOD_CACHED(NULL, _53$$62, "next", &_zephir_call_cache[42]);
									zephir_check_call_status();
								}
								ZEPHIR_CALL_METHOD_CACHED(&_59$$62, _53$$62, "valid", &_zephir_call_cache[43]);
								zephir_check_call_status();
								if (!zend_is_true(&_59$$62)) {
									break;
								}
								ZEPHIR_CALL_METHOD_CACHED(&position, _53$$62, "key", &_zephir_call_cache[44]);
								zephir_check_call_status();
								ZEPHIR_CALL_METHOD_CACHED(&itemValue, _53$$62, "current", &_zephir_call_cache[45]);
								zephir_check_call_status();
									ZEPHIR_INIT_NVAR(&_61$$64);
									ZEPHIR_CONCAT_VV(&_61$$64, &parameter, &position);
									if (UNEXPECTED(EG(exception))) {
										ZEPHIR_MM_RESTORE();
										return;
									}
									ZEPHIR_CALL_METHOD_CACHED(NULL, statement, "bindValue", &_zephir_call_cache[46], &_61$$64, &itemValue);
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
	ZEPHIR_CALL_METHOD_CACHED(NULL, statement, "execute", &_zephir_call_cache[47]);
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
 *
 * @phpstan-return db_error_info
 */
PHP_METHOD(Phalcon_Db_Adapter_Pdo_AbstractPdo, getErrorInfo)
{
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZEND_TLS zephir_method_cache _zephir_call_cache[1];
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("pdo", 3, 1);
	}
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 110, PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_RETURN_CALL_METHOD_CACHED(&_0, "errorInfo", &_zephir_call_cache[0]);
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
	ZEND_TLS zephir_method_cache _zephir_call_cache[1];
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("pdo", 3, 1);
	}
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 110, PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_RETURN_CALL_METHOD_CACHED(&_0, "inTransaction", &_zephir_call_cache[0]);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Returns the insert id for the auto_increment/serial column inserted in
 * the latest executed SQL statement
 *
 *```php
 * // Inserting a new invoice
 * $success = $connection->insert(
 *     "co_invoices",
 *     [
 *         "Test Invoice",
 *         100,
 *     ],
 *     [
 *         "inv_title",
 *         "inv_total",
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
	ZEND_TLS zephir_method_cache _zephir_call_cache[1];
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("pdo", 3, 1);
	}

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
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 110, PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_RETURN_CALL_METHOD_CACHED(&_0, "lastInsertId", &_zephir_call_cache[0], &name_zv);
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
	ZEND_TLS zephir_method_cache _zephir_call_cache[1];
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("pdo", 3, 1);
	}
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 110, PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (!(zephir_is_true(&_0))) {
		RETURN_MM_BOOL(0);
	}

	/* try_start_1: */

		zephir_read_property_cached(&_1$$4, this_ptr, _zephir_prop_0, 110, PH_NOISY_CC | PH_READONLY);
		if (UNEXPECTED(EG(exception))) {
			goto try_end_1;
		}
		ZEPHIR_INIT_VAR(&_2$$4);
		ZVAL_STRING(&_2$$4, "SELECT 1");
		ZEPHIR_CALL_METHOD_CACHED(NULL, &_1$$4, "query", &_zephir_call_cache[0], &_2$$4);
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
		} else {
			ZEPHIR_MM_RESTORE();
			return;
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
 *     "SELECT * FROM co_invoices WHERE inv_title = :inv_title"
 * );
 *
 * $result = $connection->executePrepared(
 *     $statement,
 *     [
 *         "inv_title" => "Test Invoice",
 *     ],
 *     [
 *         "inv_title" => Column::BIND_PARAM_INT,
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
	ZEND_TLS zephir_method_cache _zephir_call_cache[1];
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("pdo", 3, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(sqlStatement)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&sqlStatement_zv);
	ZVAL_STR_COPY(&sqlStatement_zv, sqlStatement);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 110, PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_RETURN_CALL_METHOD_CACHED(&_0, "prepare", &_zephir_call_cache[0], &sqlStatement_zv);
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
 *     "SELECT * FROM co_invoices WHERE inv_status_flag = 1"
 * );
 *
 * $resultset = $connection->query(
 *     "SELECT * FROM co_invoices WHERE inv_status_flag = ?",
 *     [
 *         1,
 *     ]
 * );
 *```
 */
PHP_METHOD(Phalcon_Db_Adapter_Pdo_AbstractPdo, query)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval bindParams, bindTypes;
	zval sqlStatement_zv, *bindParams_param = NULL, *bindTypes_param = NULL, eventsManager, statement, params, types, e, _0, _3, _1$$3, _2$$3, _4$$8, _5$$12;
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
	ZVAL_UNDEF(&_5$$12);
	ZVAL_UNDEF(&bindParams);
	ZVAL_UNDEF(&bindTypes);
	ZEND_TLS zephir_method_cache _zephir_call_cache[8];
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	static zend_string *_zephir_prop_2 = NULL;
	static zend_string *_zephir_prop_3 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("eventsManager", 13, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("sqlStatement", 12, 1);
	}
	if (UNEXPECTED(!_zephir_prop_2)) {
		_zephir_prop_2 = zend_string_init("sqlVariables", 12, 1);
	}
	if (UNEXPECTED(!_zephir_prop_3)) {
		_zephir_prop_3 = zend_string_init("sqlBindTypes", 12, 1);
	}

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
		zephir_get_arrval(&bindParams, bindParams_param);
	}
	if (!bindTypes_param) {
		ZEPHIR_INIT_VAR(&bindTypes);
		array_init(&bindTypes);
	} else {
		zephir_get_arrval(&bindTypes, bindTypes_param);
	}
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 109, PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CPY_WRT(&eventsManager, &_0);
	if (Z_TYPE_P(&eventsManager) == IS_OBJECT) {
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_1, 114, &sqlStatement_zv);
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_2, 115, &bindParams);
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_3, 116, &bindTypes);
		ZEPHIR_INIT_VAR(&_2$$3);
		ZVAL_STRING(&_2$$3, "db:beforeQuery");
		ZEPHIR_CALL_METHOD_CACHED(&_1$$3, &eventsManager, "fire", &_zephir_call_cache[0], &_2$$3, this_ptr);
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
	ZEPHIR_CALL_METHOD_CACHED(NULL, this_ptr, "prepareRealSql", &_zephir_call_cache[1], &sqlStatement_zv, &bindParams);
	zephir_check_call_status();

	/* try_start_1: */

		ZEPHIR_CALL_METHOD_CACHED(&statement, this_ptr, "queryStatement", &_zephir_call_cache[2], &sqlStatement_zv, &params, &types);
		zephir_check_call_status_or_jump(try_end_1);

	try_end_1:

	if (EG(exception)) {
		ZEPHIR_INIT_VAR(&_3);
		ZVAL_OBJ(&_3, EG(exception));
		Z_ADDREF_P(&_3);
		if (zephir_is_instance_of(&_3, SL("PDOException"))) {
			zend_clear_exception();
			ZEPHIR_CPY_WRT(&e, &_3);
			ZEPHIR_CALL_METHOD_CACHED(&_4$$8, this_ptr, "canReconnect", &_zephir_call_cache[3], &e);
			zephir_check_call_status();
			if (!(zephir_is_true(&_4$$8))) {
				zephir_throw_exception_debug(&e, "phalcon/Db/Adapter/Pdo/AbstractPdo.zep", 839);
				ZEPHIR_MM_RESTORE();
				return;
			}
			ZEPHIR_CALL_METHOD_CACHED(NULL, this_ptr, "handleConnectionLost", &_zephir_call_cache[4]);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD_CACHED(&statement, this_ptr, "queryStatement", &_zephir_call_cache[5], &sqlStatement_zv, &params, &types);
			zephir_check_call_status();
		} else {
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	if (Z_TYPE_P(&statement) == IS_OBJECT) {
		if (Z_TYPE_P(&eventsManager) == IS_OBJECT) {
			ZEPHIR_INIT_VAR(&_5$$12);
			ZVAL_STRING(&_5$$12, "db:afterQuery");
			ZEPHIR_CALL_METHOD_CACHED(NULL, &eventsManager, "fire", &_zephir_call_cache[6], &_5$$12, this_ptr);
			zephir_check_call_status();
		}
		object_init_ex(return_value, phalcon_db_result_pdoresult_ce);
		ZEPHIR_CALL_METHOD_CACHED(NULL, return_value, "__construct", &_zephir_call_cache[7], this_ptr, &statement, &sqlStatement_zv, &bindParams, &bindTypes);
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
	zval *nesting_param = NULL, eventsManager, savepointName, _0, _2, _6, _8, _1$$3, _3$$4, _4$$5, _7$$6, _9$$8;
	zend_bool nesting, _5;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&eventsManager);
	ZVAL_UNDEF(&savepointName);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_4$$5);
	ZVAL_UNDEF(&_7$$6);
	ZVAL_UNDEF(&_9$$8);
	ZEND_TLS zephir_method_cache _zephir_call_cache[8];
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	static zend_string *_zephir_prop_2 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("transactionLevel", 16, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("eventsManager", 13, 1);
	}
	if (UNEXPECTED(!_zephir_prop_2)) {
		_zephir_prop_2 = zend_string_init("pdo", 3, 1);
	}

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
	ZEPHIR_CALL_METHOD_CACHED(NULL, this_ptr, "resetStaleTransactionLevel", &_zephir_call_cache[0]);
	zephir_check_call_status();
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 108, PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (ZEPHIR_IS_LONG_IDENTICAL(&_0, 0)) {
		ZEPHIR_INIT_VAR(&_1$$3);
		object_init_ex(&_1$$3, phalcon_db_exceptions_noactivetransaction_ce);
		ZEPHIR_CALL_METHOD_CACHED(NULL, &_1$$3, "__construct", &_zephir_call_cache[1]);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$3, "phalcon/Db/Adapter/Pdo/AbstractPdo.zep", 880);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_read_property_cached(&_2, this_ptr, _zephir_prop_0, 108, PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (ZEPHIR_IS_LONG_IDENTICAL(&_2, 1)) {
		zephir_read_property_cached(&_3$$4, this_ptr, _zephir_prop_1, 109, PH_NOISY_CC | PH_READONLY);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_CPY_WRT(&eventsManager, &_3$$4);
		if (Z_TYPE_P(&eventsManager) == IS_OBJECT) {
			ZEPHIR_INIT_VAR(&_4$$5);
			ZVAL_STRING(&_4$$5, "db:rollbackTransaction");
			ZEPHIR_CALL_METHOD_CACHED(NULL, &eventsManager, "fire", &_zephir_call_cache[2], &_4$$5, this_ptr);
			zephir_check_call_status();
		}
		RETURN_ON_FAILURE(zephir_property_decr(this_ptr, SL("transactionLevel")));
		zephir_read_property_cached(&_3$$4, this_ptr, _zephir_prop_2, 110, PH_NOISY_CC | PH_READONLY);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_RETURN_CALL_METHOD_CACHED(&_3$$4, "rollback", &_zephir_call_cache[3]);
		zephir_check_call_status();
		RETURN_MM();
	}
	_5 = !nesting;
	if (!(_5)) {
		ZEPHIR_CALL_METHOD_CACHED(&_6, this_ptr, "isNestedTransactionsWithSavepoints", &_zephir_call_cache[4]);
		zephir_check_call_status();
		_5 = !zephir_is_true(&_6);
	}
	if (_5) {
		zephir_read_property_cached(&_7$$6, this_ptr, _zephir_prop_0, 108, PH_NOISY_CC | PH_READONLY);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		if (ZEPHIR_GT_LONG(&_7$$6, 0)) {
			RETURN_ON_FAILURE(zephir_property_decr(this_ptr, SL("transactionLevel")));
		}
		RETURN_MM_BOOL(0);
	}
	ZEPHIR_CALL_METHOD_CACHED(&savepointName, this_ptr, "getNestedTransactionSavepointName", &_zephir_call_cache[5]);
	zephir_check_call_status();
	zephir_read_property_cached(&_8, this_ptr, _zephir_prop_1, 109, PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CPY_WRT(&eventsManager, &_8);
	if (Z_TYPE_P(&eventsManager) == IS_OBJECT) {
		ZEPHIR_INIT_VAR(&_9$$8);
		ZVAL_STRING(&_9$$8, "db:rollbackSavepoint");
		ZEPHIR_CALL_METHOD_CACHED(NULL, &eventsManager, "fire", &_zephir_call_cache[6], &_9$$8, this_ptr, &savepointName);
		zephir_check_call_status();
	}
	RETURN_ON_FAILURE(zephir_property_decr(this_ptr, SL("transactionLevel")));
	ZEPHIR_RETURN_CALL_METHOD_CACHED(this_ptr, "rollbackSavepoint", &_zephir_call_cache[7], &savepointName);
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
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("autoReconnect", 13, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_BOOL(autoReconnect)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &autoReconnect_param);
	if (autoReconnect) {
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 112, &__$true);
	} else {
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 112, &__$false);
	}
	RETURN_THISW();
}

/**
 * Returns PDO adapter DSN defaults as a key-value map.
 *
 * @phpstan-return db_dsn_defaults
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
 *
 * @phpstan-param db_bind_params $parameters
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
	ZEND_TLS zephir_method_cache _zephir_call_cache[5];
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("realSqlStatement", 16, 1);
	}

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
	if (UNEXPECTED(Z_TYPE_P(&parameters) != IS_ARRAY)) {
		zephir_throw_variable_type_error(&parameters, "values", "array");
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CPY_WRT(&values, &parameters);
	if (!(ZEPHIR_IS_EMPTY(&parameters))) {
		ZEPHIR_INIT_VAR(&keys);
		array_init(&keys);
		zephir_is_iterable(&parameters, 0, "phalcon/Db/Adapter/Pdo/AbstractPdo.zep", 995);
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
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					zephir_array_append(&keys, &_3$$5, PH_SEPARATE, "phalcon/Db/Adapter/Pdo/AbstractPdo.zep", 981);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
				} else {
					ZEPHIR_INIT_NVAR(&_4$$6);
					ZVAL_STRING(&_4$$6, "/[?]/");
					zephir_array_append(&keys, &_4$$6, PH_SEPARATE, "phalcon/Db/Adapter/Pdo/AbstractPdo.zep", 983);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
				}
				if (Z_TYPE_P(&value) == IS_STRING) {
					ZEPHIR_INIT_NVAR(&_5$$7);
					ZEPHIR_CONCAT_SVS(&_5$$7, "'", &value, "'");
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					zephir_array_update_zval(&values, &key, &_5$$7, PH_COPY | PH_SEPARATE);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
				} else if (Z_TYPE_P(&value) == IS_ARRAY) {
					ZEPHIR_INIT_NVAR(&_6$$8);
					zephir_fast_join_str(&_6$$8, SL("','"), &value);
					ZEPHIR_INIT_NVAR(&_7$$8);
					ZEPHIR_CONCAT_SVS(&_7$$8, "'", &_6$$8, "'");
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					zephir_array_update_zval(&values, &key, &_7$$8, PH_COPY | PH_SEPARATE);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
				} else if (Z_TYPE_P(&value) == IS_NULL) {
					ZEPHIR_INIT_NVAR(&_8$$9);
					ZVAL_STRING(&_8$$9, "NULL");
					zephir_array_update_zval(&values, &key, &_8$$9, PH_COPY | PH_SEPARATE);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
				}
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD_CACHED(NULL, &parameters, "rewind", &_zephir_call_cache[0]);
			zephir_check_call_status();
			_10$$3 = 1;
			while (1) {
				if (_10$$3) {
					_10$$3 = 0;
				} else {
					ZEPHIR_CALL_METHOD_CACHED(NULL, &parameters, "next", &_zephir_call_cache[1]);
					zephir_check_call_status();
				}
				ZEPHIR_CALL_METHOD_CACHED(&_9$$3, &parameters, "valid", &_zephir_call_cache[2]);
				zephir_check_call_status();
				if (!zend_is_true(&_9$$3)) {
					break;
				}
				ZEPHIR_CALL_METHOD_CACHED(&key, &parameters, "key", &_zephir_call_cache[3]);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD_CACHED(&value, &parameters, "current", &_zephir_call_cache[4]);
				zephir_check_call_status();
					if (Z_TYPE_P(&key) == IS_STRING) {
						ZEPHIR_INIT_NVAR(&_11$$11);
						ZEPHIR_CONCAT_SVS(&_11$$11, "/:", &key, "/");
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						zephir_array_append(&keys, &_11$$11, PH_SEPARATE, "phalcon/Db/Adapter/Pdo/AbstractPdo.zep", 981);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
					} else {
						ZEPHIR_INIT_NVAR(&_12$$12);
						ZVAL_STRING(&_12$$12, "/[?]/");
						zephir_array_append(&keys, &_12$$12, PH_SEPARATE, "phalcon/Db/Adapter/Pdo/AbstractPdo.zep", 983);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
					}
					if (Z_TYPE_P(&value) == IS_STRING) {
						ZEPHIR_INIT_NVAR(&_13$$13);
						ZEPHIR_CONCAT_SVS(&_13$$13, "'", &value, "'");
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						zephir_array_update_zval(&values, &key, &_13$$13, PH_COPY | PH_SEPARATE);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
					} else if (Z_TYPE_P(&value) == IS_ARRAY) {
						ZEPHIR_INIT_NVAR(&_14$$14);
						zephir_fast_join_str(&_14$$14, SL("','"), &value);
						ZEPHIR_INIT_NVAR(&_15$$14);
						ZEPHIR_CONCAT_SVS(&_15$$14, "'", &_14$$14, "'");
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						zephir_array_update_zval(&values, &key, &_15$$14, PH_COPY | PH_SEPARATE);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
					} else if (Z_TYPE_P(&value) == IS_NULL) {
						ZEPHIR_INIT_NVAR(&_16$$15);
						ZVAL_STRING(&_16$$15, "NULL");
						zephir_array_update_zval(&values, &key, &_16$$15, PH_COPY | PH_SEPARATE);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
					}
			}
		}
		ZEPHIR_INIT_NVAR(&value);
		ZEPHIR_INIT_NVAR(&key);
		ZVAL_LONG(&_17$$3, 1);
		ZEPHIR_CALL_FUNCTION(&result, "preg_replace", NULL, 2, &keys, &values, &statement_zv, &_17$$3);
		zephir_check_call_status();
	}
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 118, &result);
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
	ZEND_TLS zephir_method_cache _zephir_call_cache[1];
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("autoReconnect", 13, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("transactionLevel", 16, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(exception, zend_ce_throwable)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &exception);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 112, PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (!(zephir_is_true(&_0))) {
		RETURN_MM_BOOL(0);
	}
	zephir_read_property_cached(&_1, this_ptr, _zephir_prop_1, 108, PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (!ZEPHIR_IS_LONG_IDENTICAL(&_1, 0)) {
		RETURN_MM_BOOL(0);
	}
	ZEPHIR_RETURN_CALL_METHOD_CACHED(this_ptr, "isConnectionError", &_zephir_call_cache[0], exception);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Runs the actual write against PDO and returns the affected-rows count
 * (or the raw exec() return for unprepared statements).
 *
 * @phpstan-param db_bind_params $bindParams
 * @phpstan-param db_bind_types  $bindTypes
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
	ZEND_TLS zephir_method_cache _zephir_call_cache[4];
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("pdo", 3, 1);
	}

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
		zephir_read_property_cached(&_0$$3, this_ptr, _zephir_prop_0, 110, PH_NOISY_CC | PH_READONLY);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_CALL_METHOD_CACHED(&statement, &_0$$3, "prepare", &_zephir_call_cache[0], &sqlStatement_zv);
		zephir_check_call_status();
		if (Z_TYPE_P(&statement) == IS_OBJECT) {
			ZEPHIR_CALL_METHOD_CACHED(&newStatement, this_ptr, "executePrepared", &_zephir_call_cache[1], &statement, &bindParams, &bindTypes);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD_CACHED(&affectedRows, &newStatement, "rowCount", &_zephir_call_cache[2]);
			zephir_check_call_status();
		}
	} else {
		zephir_read_property_cached(&_1$$5, this_ptr, _zephir_prop_0, 110, PH_NOISY_CC | PH_READONLY);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_CALL_METHOD_CACHED(&affectedRows, &_1$$5, "exec", &_zephir_call_cache[3], &sqlStatement_zv);
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
	ZEND_TLS zephir_method_cache _zephir_call_cache[2];
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("eventsManager", 13, 1);
	}
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 109, PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CPY_WRT(&eventsManager, &_0);
	if (Z_TYPE_P(&eventsManager) == IS_OBJECT) {
		ZEPHIR_INIT_VAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "db:connectionLost");
		ZEPHIR_CALL_METHOD_CACHED(NULL, &eventsManager, "fire", &_zephir_call_cache[0], &_1$$3, this_ptr);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_METHOD_CACHED(NULL, this_ptr, "connect", &_zephir_call_cache[1]);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
}

/**
 * Prepares and executes a read statement, returning the live PDOStatement.
 *
 * @phpstan-param db_bind_params $params
 * @phpstan-param db_bind_types  $types
 *
 * @throws CannotPrepareStatement
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
	ZEND_TLS zephir_method_cache _zephir_call_cache[3];
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("pdo", 3, 1);
	}

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
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 110, PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CALL_METHOD_CACHED(&statement, &_0, "prepare", &_zephir_call_cache[0], &sqlStatement_zv);
	zephir_check_call_status();
	if (UNEXPECTED(Z_TYPE_P(&statement) != IS_OBJECT)) {
		ZEPHIR_INIT_VAR(&_1$$3);
		object_init_ex(&_1$$3, phalcon_db_exceptions_cannotpreparestatement_ce);
		ZEPHIR_CALL_METHOD_CACHED(NULL, &_1$$3, "__construct", &_zephir_call_cache[1]);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$3, "phalcon/Db/Adapter/Pdo/AbstractPdo.zep", 1080);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_RETURN_CALL_METHOD_CACHED(this_ptr, "executePrepared", &_zephir_call_cache[2], &statement, &params, &types);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Resets the transaction nesting level when the connection has no active
 * transaction. This occurs after an implicit commit, a reconnect or when
 * the transaction ends outside of the adapter.
 */
PHP_METHOD(Phalcon_Db_Adapter_Pdo_AbstractPdo, resetStaleTransactionLevel)
{
	zend_bool _1, _3;
	zval _0, _2, _4, _5, _6$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6$$3);
	ZEND_TLS zephir_method_cache _zephir_call_cache[1];
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("transactionLevel", 16, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("pdo", 3, 1);
	}
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 108, PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	_1 = ZEPHIR_GT_LONG(&_0, 0);
	if (_1) {
		zephir_memory_observe(&_2);
		zephir_read_property_cached(&_2, this_ptr, _zephir_prop_1, 110, PH_NOISY_CC);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		_1 = Z_TYPE_P(&_2) == IS_OBJECT;
	}
	_3 = _1;
	if (_3) {
		zephir_read_property_cached(&_4, this_ptr, _zephir_prop_1, 110, PH_NOISY_CC | PH_READONLY);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_CALL_METHOD_CACHED(&_5, &_4, "inTransaction", &_zephir_call_cache[0]);
		zephir_check_call_status();
		_3 = !zephir_is_true(&_5);
	}
	if (_3) {
		ZVAL_UNDEF(&_6$$3);
		ZVAL_LONG(&_6$$3, 0);
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 108, &_6$$3);
	}
	ZEPHIR_MM_RESTORE();
}

