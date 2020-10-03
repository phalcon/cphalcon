
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "kernel/object.h"
#include "kernel/fcall.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 *
 * Implementation of this file has been influenced by AtlasPHP
 *
 * @link    https://github.com/atlasphp/Atlas.Query
 * @license https://github.com/atlasphp/Atlas.Qyert/blob/1.x/LICENSE.md
 */
/**
 * Class QueryFactory
 *
 * @property string $class
 */
ZEPHIR_INIT_CLASS(Phalcon_DataMapper_Query_QueryFactory) {

	ZEPHIR_REGISTER_CLASS(Phalcon\\DataMapper\\Query, QueryFactory, phalcon, datamapper_query_queryfactory, phalcon_datamapper_query_queryfactory_method_entry, 0);

	/**
	 * @var string
	 */
	zend_declare_property_string(phalcon_datamapper_query_queryfactory_ce, SL("selectClass"), "", ZEND_ACC_PROTECTED);

	return SUCCESS;

}

/**
 * QueryFactory constructor.
 *
 * @param string $selectClass
 */
PHP_METHOD(Phalcon_DataMapper_Query_QueryFactory, __construct) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *selectClass_param = NULL;
	zval selectClass;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&selectClass);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &selectClass_param);

	if (!selectClass_param) {
		ZEPHIR_INIT_VAR(&selectClass);
		ZVAL_STRING(&selectClass, "");
	} else {
		zephir_get_strval(&selectClass, selectClass_param);
	}


	if (ZEPHIR_IS_EMPTY(&selectClass)) {
		ZEPHIR_INIT_NVAR(&selectClass);
		ZVAL_STRING(&selectClass, "Phalcon\\DataMapper\\Query\\Select");
	}
	zephir_update_property_zval(this_ptr, ZEND_STRL("selectClass"), &selectClass);
	ZEPHIR_MM_RESTORE();

}

/**
 * Create a new Bind object
 *
 * @return Bind
 */
PHP_METHOD(Phalcon_DataMapper_Query_QueryFactory, newBind) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();


	ZEPHIR_MM_GROW();

	object_init_ex(return_value, phalcon_datamapper_query_bind_ce);
	if (zephir_has_constructor(return_value)) {
		ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 0);
		zephir_check_call_status();
	}
	RETURN_MM();

}

/**
 * Create a new Delete object
 *
 * @param <Connection> connection
 *
 * @return Delete
 */
PHP_METHOD(Phalcon_DataMapper_Query_QueryFactory, newDelete) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *connection, connection_sub, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&connection_sub);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &connection);



	object_init_ex(return_value, phalcon_datamapper_query_delete_ce);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "newbind", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 204, connection, &_0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Create a new Insert object
 *
 * @param <Connection> connection
 *
 * @return Insert
 */
PHP_METHOD(Phalcon_DataMapper_Query_QueryFactory, newInsert) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *connection, connection_sub, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&connection_sub);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &connection);



	object_init_ex(return_value, phalcon_datamapper_query_insert_ce);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "newbind", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 205, connection, &_0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Create a new Select object
 *
 * @param <Connection> connection
 *
 * @return Select
 */
PHP_METHOD(Phalcon_DataMapper_Query_QueryFactory, newSelect) {

	zend_class_entry *_2;
	zval selectClass;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *connection, connection_sub, _0, _1, _3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&connection_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&selectClass);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &connection);



	zephir_read_property(&_0, this_ptr, ZEND_STRL("selectClass"), PH_NOISY_CC | PH_READONLY);
	zephir_get_strval(&selectClass, &_0);
	zephir_fetch_safe_class(&_1, &selectClass);
	_2 = zephir_fetch_class_str_ex(Z_STRVAL_P(&_1), Z_STRLEN_P(&_1), ZEND_FETCH_CLASS_AUTO);
	if(!_2) {
		RETURN_MM_NULL();
	}
	object_init_ex(return_value, _2);
	if (zephir_has_constructor(return_value)) {
		ZEPHIR_CALL_METHOD(&_3, this_ptr, "newbind", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 0, connection, &_3);
		zephir_check_call_status();
	}
	RETURN_MM();

}

/**
 * Create a new Update object
 *
 * @param <Connection> connection
 *
 * @return Update
 */
PHP_METHOD(Phalcon_DataMapper_Query_QueryFactory, newUpdate) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *connection, connection_sub, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&connection_sub);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &connection);



	object_init_ex(return_value, phalcon_datamapper_query_update_ce);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "newbind", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 206, connection, &_0);
	zephir_check_call_status();
	RETURN_MM();

}

