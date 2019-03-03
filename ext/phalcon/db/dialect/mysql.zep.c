
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
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/concat.h"
#include "kernel/memory.h"
#include "kernel/exception.h"
#include "kernel/string.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/array.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * Phalcon\Db\Dialect\Mysql
 *
 * Generates database specific SQL for the MySQL RDBMS
 */
ZEPHIR_INIT_CLASS(Phalcon_Db_Dialect_Mysql) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Db\\Dialect, Mysql, phalcon, db_dialect_mysql, phalcon_db_dialect_ce, phalcon_db_dialect_mysql_method_entry, 0);

	zend_declare_property_string(phalcon_db_dialect_mysql_ce, SL("_escapeChar"), "`", ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

/**
 * Gets the column name in MySQL
 */
PHP_METHOD(Phalcon_Db_Dialect_Mysql, getColumnDefinition) {

	zephir_fcall_cache_entry *_35 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *column, column_sub, columnType, columnSql, typeValues, _0$$3, _1$$3, _2$$3, _3$$5, _4$$11, _5$$17, _6$$17, _7$$17, _8$$19, _9$$19, _10$$19, _11$$21, _12$$23, _13$$23, _14$$23, _15$$25, _16$$25, _17$$25, _18$$35, _19$$35, _20$$35, _21$$39, _22$$39, _23$$39, _24$$49, _25$$49, _26$$49, _27$$53, _28$$56, _29$$56, _30$$56, value$$58, valueSql$$58, *_31$$58, _32$$58, _40$$58, _41$$58, _42$$58, _43$$58, _33$$59, _34$$59, _36$$59, _37$$60, _38$$60, _39$$60, _44$$61, _45$$61, _46$$61;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&column_sub);
	ZVAL_UNDEF(&columnType);
	ZVAL_UNDEF(&columnSql);
	ZVAL_UNDEF(&typeValues);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$5);
	ZVAL_UNDEF(&_4$$11);
	ZVAL_UNDEF(&_5$$17);
	ZVAL_UNDEF(&_6$$17);
	ZVAL_UNDEF(&_7$$17);
	ZVAL_UNDEF(&_8$$19);
	ZVAL_UNDEF(&_9$$19);
	ZVAL_UNDEF(&_10$$19);
	ZVAL_UNDEF(&_11$$21);
	ZVAL_UNDEF(&_12$$23);
	ZVAL_UNDEF(&_13$$23);
	ZVAL_UNDEF(&_14$$23);
	ZVAL_UNDEF(&_15$$25);
	ZVAL_UNDEF(&_16$$25);
	ZVAL_UNDEF(&_17$$25);
	ZVAL_UNDEF(&_18$$35);
	ZVAL_UNDEF(&_19$$35);
	ZVAL_UNDEF(&_20$$35);
	ZVAL_UNDEF(&_21$$39);
	ZVAL_UNDEF(&_22$$39);
	ZVAL_UNDEF(&_23$$39);
	ZVAL_UNDEF(&_24$$49);
	ZVAL_UNDEF(&_25$$49);
	ZVAL_UNDEF(&_26$$49);
	ZVAL_UNDEF(&_27$$53);
	ZVAL_UNDEF(&_28$$56);
	ZVAL_UNDEF(&_29$$56);
	ZVAL_UNDEF(&_30$$56);
	ZVAL_UNDEF(&value$$58);
	ZVAL_UNDEF(&valueSql$$58);
	ZVAL_UNDEF(&_32$$58);
	ZVAL_UNDEF(&_40$$58);
	ZVAL_UNDEF(&_41$$58);
	ZVAL_UNDEF(&_42$$58);
	ZVAL_UNDEF(&_43$$58);
	ZVAL_UNDEF(&_33$$59);
	ZVAL_UNDEF(&_34$$59);
	ZVAL_UNDEF(&_36$$59);
	ZVAL_UNDEF(&_37$$60);
	ZVAL_UNDEF(&_38$$60);
	ZVAL_UNDEF(&_39$$60);
	ZVAL_UNDEF(&_44$$61);
	ZVAL_UNDEF(&_45$$61);
	ZVAL_UNDEF(&_46$$61);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &column);



	ZEPHIR_CALL_METHOD(&columnSql, this_ptr, "checkcolumntypesql", NULL, 0, column);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&columnType, this_ptr, "checkcolumntype", NULL, 0, column);
	zephir_check_call_status();
	do {
		if (ZEPHIR_IS_LONG(&columnType, 14)) {
			if (ZEPHIR_IS_EMPTY(&columnSql)) {
				zephir_concat_self_str(&columnSql, SL("BIGINT") TSRMLS_CC);
			}
			ZEPHIR_CALL_METHOD(&_0$$3, this_ptr, "getcolumnsize", NULL, 0, column);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&_1$$3, this_ptr, "checkcolumnunsigned", NULL, 143, column);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(&_2$$3);
			ZEPHIR_CONCAT_VV(&_2$$3, &_0$$3, &_1$$3);
			zephir_concat_self(&columnSql, &_2$$3 TSRMLS_CC);
			break;
		}
		if (ZEPHIR_IS_LONG(&columnType, 19)) {
			if (ZEPHIR_IS_EMPTY(&columnSql)) {
				zephir_concat_self_str(&columnSql, SL("BIT") TSRMLS_CC);
			}
			ZEPHIR_CALL_METHOD(&_3$$5, this_ptr, "getcolumnsize", NULL, 0, column);
			zephir_check_call_status();
			zephir_concat_self(&columnSql, &_3$$5 TSRMLS_CC);
			break;
		}
		if (ZEPHIR_IS_LONG(&columnType, 11)) {
			if (ZEPHIR_IS_EMPTY(&columnSql)) {
				zephir_concat_self_str(&columnSql, SL("BLOB") TSRMLS_CC);
			}
			break;
		}
		if (ZEPHIR_IS_LONG(&columnType, 8)) {
			if (ZEPHIR_IS_EMPTY(&columnSql)) {
				zephir_concat_self_str(&columnSql, SL("TINYINT(1)") TSRMLS_CC);
			}
			break;
		}
		if (ZEPHIR_IS_LONG(&columnType, 5)) {
			if (ZEPHIR_IS_EMPTY(&columnSql)) {
				zephir_concat_self_str(&columnSql, SL("CHAR") TSRMLS_CC);
			}
			ZEPHIR_CALL_METHOD(&_4$$11, this_ptr, "getcolumnsize", NULL, 0, column);
			zephir_check_call_status();
			zephir_concat_self(&columnSql, &_4$$11 TSRMLS_CC);
			break;
		}
		if (ZEPHIR_IS_LONG(&columnType, 1)) {
			if (ZEPHIR_IS_EMPTY(&columnSql)) {
				zephir_concat_self_str(&columnSql, SL("DATE") TSRMLS_CC);
			}
			break;
		}
		if (ZEPHIR_IS_LONG(&columnType, 4)) {
			if (ZEPHIR_IS_EMPTY(&columnSql)) {
				zephir_concat_self_str(&columnSql, SL("DATETIME") TSRMLS_CC);
			}
			break;
		}
		if (ZEPHIR_IS_LONG(&columnType, 3)) {
			if (ZEPHIR_IS_EMPTY(&columnSql)) {
				zephir_concat_self_str(&columnSql, SL("DECIMAL") TSRMLS_CC);
			}
			ZEPHIR_CALL_METHOD(&_5$$17, this_ptr, "getcolumnsizeandscale", NULL, 0, column);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&_6$$17, this_ptr, "checkcolumnunsigned", NULL, 143, column);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(&_7$$17);
			ZEPHIR_CONCAT_VV(&_7$$17, &_5$$17, &_6$$17);
			zephir_concat_self(&columnSql, &_7$$17 TSRMLS_CC);
			break;
		}
		if (ZEPHIR_IS_LONG(&columnType, 9)) {
			if (ZEPHIR_IS_EMPTY(&columnSql)) {
				zephir_concat_self_str(&columnSql, SL("DOUBLE") TSRMLS_CC);
			}
			ZEPHIR_CALL_METHOD(&_8$$19, this_ptr, "checkcolumnsizeandscale", NULL, 144, column);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&_9$$19, this_ptr, "checkcolumnunsigned", NULL, 143, column);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(&_10$$19);
			ZEPHIR_CONCAT_VV(&_10$$19, &_8$$19, &_9$$19);
			zephir_concat_self(&columnSql, &_10$$19 TSRMLS_CC);
			break;
		}
		if (ZEPHIR_IS_LONG(&columnType, 18)) {
			if (ZEPHIR_IS_EMPTY(&columnSql)) {
				zephir_concat_self_str(&columnSql, SL("ENUM") TSRMLS_CC);
			}
			ZEPHIR_CALL_METHOD(&_11$$21, this_ptr, "getcolumnsize", NULL, 0, column);
			zephir_check_call_status();
			zephir_concat_self(&columnSql, &_11$$21 TSRMLS_CC);
			break;
		}
		if (ZEPHIR_IS_LONG(&columnType, 7)) {
			if (ZEPHIR_IS_EMPTY(&columnSql)) {
				zephir_concat_self_str(&columnSql, SL("FLOAT") TSRMLS_CC);
			}
			ZEPHIR_CALL_METHOD(&_12$$23, this_ptr, "checkcolumnsizeandscale", NULL, 144, column);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&_13$$23, this_ptr, "checkcolumnunsigned", NULL, 143, column);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(&_14$$23);
			ZEPHIR_CONCAT_VV(&_14$$23, &_12$$23, &_13$$23);
			zephir_concat_self(&columnSql, &_14$$23 TSRMLS_CC);
			break;
		}
		if (ZEPHIR_IS_LONG(&columnType, 0)) {
			if (ZEPHIR_IS_EMPTY(&columnSql)) {
				zephir_concat_self_str(&columnSql, SL("INT") TSRMLS_CC);
			}
			ZEPHIR_CALL_METHOD(&_15$$25, this_ptr, "getcolumnsize", NULL, 0, column);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&_16$$25, this_ptr, "checkcolumnunsigned", NULL, 143, column);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(&_17$$25);
			ZEPHIR_CONCAT_VV(&_17$$25, &_15$$25, &_16$$25);
			zephir_concat_self(&columnSql, &_17$$25 TSRMLS_CC);
			break;
		}
		if (ZEPHIR_IS_LONG(&columnType, 15)) {
			if (ZEPHIR_IS_EMPTY(&columnSql)) {
				zephir_concat_self_str(&columnSql, SL("JSON") TSRMLS_CC);
			}
			break;
		}
		if (ZEPHIR_IS_LONG(&columnType, 13)) {
			if (ZEPHIR_IS_EMPTY(&columnSql)) {
				zephir_concat_self_str(&columnSql, SL("LONGBLOB") TSRMLS_CC);
			}
			break;
		}
		if (ZEPHIR_IS_LONG(&columnType, 24)) {
			if (ZEPHIR_IS_EMPTY(&columnSql)) {
				zephir_concat_self_str(&columnSql, SL("LONGTEXT") TSRMLS_CC);
			}
			break;
		}
		if (ZEPHIR_IS_LONG(&columnType, 12)) {
			if (ZEPHIR_IS_EMPTY(&columnSql)) {
				zephir_concat_self_str(&columnSql, SL("MEDIUMBLOB") TSRMLS_CC);
			}
			break;
		}
		if (ZEPHIR_IS_LONG(&columnType, 21)) {
			if (ZEPHIR_IS_EMPTY(&columnSql)) {
				zephir_concat_self_str(&columnSql, SL("MEDIUMINT") TSRMLS_CC);
			}
			ZEPHIR_CALL_METHOD(&_18$$35, this_ptr, "getcolumnsize", NULL, 0, column);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&_19$$35, this_ptr, "checkcolumnunsigned", NULL, 143, column);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(&_20$$35);
			ZEPHIR_CONCAT_VV(&_20$$35, &_18$$35, &_19$$35);
			zephir_concat_self(&columnSql, &_20$$35 TSRMLS_CC);
			break;
		}
		if (ZEPHIR_IS_LONG(&columnType, 23)) {
			if (ZEPHIR_IS_EMPTY(&columnSql)) {
				zephir_concat_self_str(&columnSql, SL("MEDIUMTEXT") TSRMLS_CC);
			}
			break;
		}
		if (ZEPHIR_IS_LONG(&columnType, 22)) {
			if (ZEPHIR_IS_EMPTY(&columnSql)) {
				zephir_concat_self_str(&columnSql, SL("SMALLINT") TSRMLS_CC);
			}
			ZEPHIR_CALL_METHOD(&_21$$39, this_ptr, "getcolumnsize", NULL, 0, column);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&_22$$39, this_ptr, "checkcolumnunsigned", NULL, 143, column);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(&_23$$39);
			ZEPHIR_CONCAT_VV(&_23$$39, &_21$$39, &_22$$39);
			zephir_concat_self(&columnSql, &_23$$39 TSRMLS_CC);
			break;
		}
		if (ZEPHIR_IS_LONG(&columnType, 6)) {
			if (ZEPHIR_IS_EMPTY(&columnSql)) {
				zephir_concat_self_str(&columnSql, SL("TEXT") TSRMLS_CC);
			}
			break;
		}
		if (ZEPHIR_IS_LONG(&columnType, 20)) {
			if (ZEPHIR_IS_EMPTY(&columnSql)) {
				zephir_concat_self_str(&columnSql, SL("TIME") TSRMLS_CC);
			}
			break;
		}
		if (ZEPHIR_IS_LONG(&columnType, 17)) {
			if (ZEPHIR_IS_EMPTY(&columnSql)) {
				zephir_concat_self_str(&columnSql, SL("TIMESTAMP") TSRMLS_CC);
			}
			break;
		}
		if (ZEPHIR_IS_LONG(&columnType, 10)) {
			if (ZEPHIR_IS_EMPTY(&columnSql)) {
				zephir_concat_self_str(&columnSql, SL("TINYBLOB") TSRMLS_CC);
			}
			break;
		}
		if (ZEPHIR_IS_LONG(&columnType, 26)) {
			if (ZEPHIR_IS_EMPTY(&columnSql)) {
				zephir_concat_self_str(&columnSql, SL("TINYINT") TSRMLS_CC);
			}
			ZEPHIR_CALL_METHOD(&_24$$49, this_ptr, "getcolumnsize", NULL, 0, column);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&_25$$49, this_ptr, "checkcolumnunsigned", NULL, 143, column);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(&_26$$49);
			ZEPHIR_CONCAT_VV(&_26$$49, &_24$$49, &_25$$49);
			zephir_concat_self(&columnSql, &_26$$49 TSRMLS_CC);
			break;
		}
		if (ZEPHIR_IS_LONG(&columnType, 25)) {
			if (ZEPHIR_IS_EMPTY(&columnSql)) {
				zephir_concat_self_str(&columnSql, SL("TINYTEXT") TSRMLS_CC);
			}
			break;
		}
		if (ZEPHIR_IS_LONG(&columnType, 2)) {
			if (ZEPHIR_IS_EMPTY(&columnSql)) {
				zephir_concat_self_str(&columnSql, SL("VARCHAR") TSRMLS_CC);
			}
			ZEPHIR_CALL_METHOD(&_27$$53, this_ptr, "getcolumnsize", NULL, 0, column);
			zephir_check_call_status();
			zephir_concat_self(&columnSql, &_27$$53 TSRMLS_CC);
			break;
		}
		if (ZEPHIR_IS_EMPTY(&columnSql)) {
			ZEPHIR_INIT_VAR(&_28$$56);
			object_init_ex(&_28$$56, phalcon_db_exception_ce);
			ZEPHIR_CALL_METHOD(&_29$$56, column, "getname", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(&_30$$56);
			ZEPHIR_CONCAT_SV(&_30$$56, "Unrecognized MySQL data type at column ", &_29$$56);
			ZEPHIR_CALL_METHOD(NULL, &_28$$56, "__construct", NULL, 4, &_30$$56);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_28$$56, "phalcon/db/dialect/mysql.zep", 213 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_CALL_METHOD(&typeValues, column, "gettypevalues", NULL, 0);
		zephir_check_call_status();
		if (!(ZEPHIR_IS_EMPTY(&typeValues))) {
			if (Z_TYPE_P(&typeValues) == IS_ARRAY) {
				ZEPHIR_INIT_VAR(&valueSql$$58);
				ZVAL_STRING(&valueSql$$58, "");
				zephir_is_iterable(&typeValues, 0, "phalcon/db/dialect/mysql.zep", 224);
				if (Z_TYPE_P(&typeValues) == IS_ARRAY) {
					ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&typeValues), _31$$58)
					{
						ZEPHIR_INIT_NVAR(&value$$58);
						ZVAL_COPY(&value$$58, _31$$58);
						ZEPHIR_INIT_NVAR(&_33$$59);
						ZVAL_STRING(&_33$$59, "\"");
						ZEPHIR_CALL_FUNCTION(&_34$$59, "addcslashes", &_35, 145, &value$$58, &_33$$59);
						zephir_check_call_status();
						ZEPHIR_INIT_LNVAR(_36$$59);
						ZEPHIR_CONCAT_SVS(&_36$$59, "\"", &_34$$59, "\", ");
						zephir_concat_self(&valueSql$$58, &_36$$59 TSRMLS_CC);
					} ZEND_HASH_FOREACH_END();
				} else {
					ZEPHIR_CALL_METHOD(NULL, &typeValues, "rewind", NULL, 0);
					zephir_check_call_status();
					while (1) {
						ZEPHIR_CALL_METHOD(&_32$$58, &typeValues, "valid", NULL, 0);
						zephir_check_call_status();
						if (!zend_is_true(&_32$$58)) {
							break;
						}
						ZEPHIR_CALL_METHOD(&value$$58, &typeValues, "current", NULL, 0);
						zephir_check_call_status();
							ZEPHIR_INIT_NVAR(&_37$$60);
							ZVAL_STRING(&_37$$60, "\"");
							ZEPHIR_CALL_FUNCTION(&_38$$60, "addcslashes", &_35, 145, &value$$58, &_37$$60);
							zephir_check_call_status();
							ZEPHIR_INIT_LNVAR(_39$$60);
							ZEPHIR_CONCAT_SVS(&_39$$60, "\"", &_38$$60, "\", ");
							zephir_concat_self(&valueSql$$58, &_39$$60 TSRMLS_CC);
						ZEPHIR_CALL_METHOD(NULL, &typeValues, "next", NULL, 0);
						zephir_check_call_status();
					}
				}
				ZEPHIR_INIT_NVAR(&value$$58);
				ZVAL_LONG(&_40$$58, 0);
				ZVAL_LONG(&_41$$58, -2);
				ZEPHIR_INIT_VAR(&_42$$58);
				zephir_substr(&_42$$58, &valueSql$$58, 0 , -2 , 0);
				ZEPHIR_INIT_VAR(&_43$$58);
				ZEPHIR_CONCAT_SVS(&_43$$58, "(", &_42$$58, ")");
				zephir_concat_self(&columnSql, &_43$$58 TSRMLS_CC);
			} else {
				ZEPHIR_INIT_VAR(&_44$$61);
				ZVAL_STRING(&_44$$61, "\"");
				ZEPHIR_CALL_FUNCTION(&_45$$61, "addcslashes", &_35, 145, &typeValues, &_44$$61);
				zephir_check_call_status();
				ZEPHIR_INIT_VAR(&_46$$61);
				ZEPHIR_CONCAT_SVS(&_46$$61, "(\"", &_45$$61, "\")");
				zephir_concat_self(&columnSql, &_46$$61 TSRMLS_CC);
			}
		}
	} while(0);

	RETURN_CCTOR(&columnSql);

}

/**
 * Generates SQL to add a column to a table
 */
PHP_METHOD(Phalcon_Db_Dialect_Mysql, addColumn) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *tableName_param = NULL, *schemaName_param = NULL, *column, column_sub, afterPosition, sql, defaultValue, _0, _1, _2, _3, _8, _9, _10, _4$$3, _5$$5, _6$$5, _7$$5, _11$$10;
	zval tableName, schemaName;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&tableName);
	ZVAL_UNDEF(&schemaName);
	ZVAL_UNDEF(&column_sub);
	ZVAL_UNDEF(&afterPosition);
	ZVAL_UNDEF(&sql);
	ZVAL_UNDEF(&defaultValue);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&_6$$5);
	ZVAL_UNDEF(&_7$$5);
	ZVAL_UNDEF(&_11$$10);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &tableName_param, &schemaName_param, &column);

	if (UNEXPECTED(Z_TYPE_P(tableName_param) != IS_STRING && Z_TYPE_P(tableName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'tableName' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(tableName_param) == IS_STRING)) {
		zephir_get_strval(&tableName, tableName_param);
	} else {
		ZEPHIR_INIT_VAR(&tableName);
		ZVAL_EMPTY_STRING(&tableName);
	}
	if (UNEXPECTED(Z_TYPE_P(schemaName_param) != IS_STRING && Z_TYPE_P(schemaName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'schemaName' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(schemaName_param) == IS_STRING)) {
		zephir_get_strval(&schemaName, schemaName_param);
	} else {
		ZEPHIR_INIT_VAR(&schemaName);
		ZVAL_EMPTY_STRING(&schemaName);
	}


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "preparetable", NULL, 0, &tableName, &schemaName);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_1, column, "getname", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_2, this_ptr, "getcolumndefinition", NULL, 0, column);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&sql);
	ZEPHIR_CONCAT_SVSVSV(&sql, "ALTER TABLE ", &_0, " ADD `", &_1, "` ", &_2);
	ZEPHIR_CALL_METHOD(&_3, column, "hasdefault", NULL, 0);
	zephir_check_call_status();
	if (zephir_is_true(&_3)) {
		ZEPHIR_CALL_METHOD(&defaultValue, column, "getdefault", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_4$$3);
		zephir_fast_strtoupper(&_4$$3, &defaultValue);
		if (zephir_memnstr_str(&_4$$3, SL("CURRENT_TIMESTAMP"), "phalcon/db/dialect/mysql.zep", 245)) {
			zephir_concat_self_str(&sql, SL(" DEFAULT CURRENT_TIMESTAMP") TSRMLS_CC);
		} else {
			ZEPHIR_INIT_VAR(&_5$$5);
			ZVAL_STRING(&_5$$5, "\"");
			ZEPHIR_CALL_FUNCTION(&_6$$5, "addcslashes", NULL, 145, &defaultValue, &_5$$5);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(&_7$$5);
			ZEPHIR_CONCAT_SVS(&_7$$5, " DEFAULT \"", &_6$$5, "\"");
			zephir_concat_self(&sql, &_7$$5 TSRMLS_CC);
		}
	}
	ZEPHIR_CALL_METHOD(&_8, column, "isnotnull", NULL, 0);
	zephir_check_call_status();
	if (zephir_is_true(&_8)) {
		zephir_concat_self_str(&sql, SL(" NOT NULL") TSRMLS_CC);
	}
	ZEPHIR_CALL_METHOD(&_9, column, "isautoincrement", NULL, 0);
	zephir_check_call_status();
	if (zephir_is_true(&_9)) {
		zephir_concat_self_str(&sql, SL(" AUTO_INCREMENT") TSRMLS_CC);
	}
	ZEPHIR_CALL_METHOD(&_10, column, "isfirst", NULL, 0);
	zephir_check_call_status();
	if (zephir_is_true(&_10)) {
		zephir_concat_self_str(&sql, SL(" FIRST") TSRMLS_CC);
	} else {
		ZEPHIR_CALL_METHOD(&afterPosition, column, "getafterposition", NULL, 0);
		zephir_check_call_status();
		if (zephir_is_true(&afterPosition)) {
			ZEPHIR_INIT_VAR(&_11$$10);
			ZEPHIR_CONCAT_SVS(&_11$$10, " AFTER `", &afterPosition, "`");
			zephir_concat_self(&sql, &_11$$10 TSRMLS_CC);
		}
	}
	RETURN_CCTOR(&sql);

}

/**
 * Generates SQL to modify a column in a table
 */
PHP_METHOD(Phalcon_Db_Dialect_Mysql, modifyColumn) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *tableName_param = NULL, *schemaName_param = NULL, *column, column_sub, *currentColumn = NULL, currentColumn_sub, __$null, afterPosition, sql, defaultValue, columnDefinition, _0, _1, _2, _8, _13, _14, _15, _3$$4, _4$$4, _5$$4, _6$$5, _7$$5, _9$$6, _10$$8, _11$$8, _12$$8, _16$$13;
	zval tableName, schemaName;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&tableName);
	ZVAL_UNDEF(&schemaName);
	ZVAL_UNDEF(&column_sub);
	ZVAL_UNDEF(&currentColumn_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&afterPosition);
	ZVAL_UNDEF(&sql);
	ZVAL_UNDEF(&defaultValue);
	ZVAL_UNDEF(&columnDefinition);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_13);
	ZVAL_UNDEF(&_14);
	ZVAL_UNDEF(&_15);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_6$$5);
	ZVAL_UNDEF(&_7$$5);
	ZVAL_UNDEF(&_9$$6);
	ZVAL_UNDEF(&_10$$8);
	ZVAL_UNDEF(&_11$$8);
	ZVAL_UNDEF(&_12$$8);
	ZVAL_UNDEF(&_16$$13);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 1, &tableName_param, &schemaName_param, &column, &currentColumn);

	if (UNEXPECTED(Z_TYPE_P(tableName_param) != IS_STRING && Z_TYPE_P(tableName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'tableName' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(tableName_param) == IS_STRING)) {
		zephir_get_strval(&tableName, tableName_param);
	} else {
		ZEPHIR_INIT_VAR(&tableName);
		ZVAL_EMPTY_STRING(&tableName);
	}
	if (UNEXPECTED(Z_TYPE_P(schemaName_param) != IS_STRING && Z_TYPE_P(schemaName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'schemaName' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(schemaName_param) == IS_STRING)) {
		zephir_get_strval(&schemaName, schemaName_param);
	} else {
		ZEPHIR_INIT_VAR(&schemaName);
		ZVAL_EMPTY_STRING(&schemaName);
	}
	if (!currentColumn) {
		currentColumn = &currentColumn_sub;
		ZEPHIR_CPY_WRT(currentColumn, &__$null);
	} else {
		ZEPHIR_SEPARATE_PARAM(currentColumn);
	}


	ZEPHIR_CALL_METHOD(&columnDefinition, this_ptr, "getcolumndefinition", NULL, 0, column);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "preparetable", NULL, 0, &tableName, &schemaName);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&sql);
	ZEPHIR_CONCAT_SV(&sql, "ALTER TABLE ", &_0);
	if (Z_TYPE_P(currentColumn) != IS_OBJECT) {
		ZEPHIR_CPY_WRT(currentColumn, column);
	}
	ZEPHIR_CALL_METHOD(&_1, column, "getname", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_2, currentColumn, "getname", NULL, 0);
	zephir_check_call_status();
	if (!ZEPHIR_IS_IDENTICAL(&_1, &_2)) {
		ZEPHIR_CALL_METHOD(&_3$$4, currentColumn, "getname", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_4$$4, column, "getname", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_5$$4);
		ZEPHIR_CONCAT_SVSVSV(&_5$$4, " CHANGE COLUMN `", &_3$$4, "` `", &_4$$4, "` ", &columnDefinition);
		zephir_concat_self(&sql, &_5$$4 TSRMLS_CC);
	} else {
		ZEPHIR_CALL_METHOD(&_6$$5, column, "getname", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_7$$5);
		ZEPHIR_CONCAT_SVSV(&_7$$5, " MODIFY `", &_6$$5, "` ", &columnDefinition);
		zephir_concat_self(&sql, &_7$$5 TSRMLS_CC);
	}
	ZEPHIR_CALL_METHOD(&_8, column, "hasdefault", NULL, 0);
	zephir_check_call_status();
	if (zephir_is_true(&_8)) {
		ZEPHIR_CALL_METHOD(&defaultValue, column, "getdefault", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_9$$6);
		zephir_fast_strtoupper(&_9$$6, &defaultValue);
		if (zephir_memnstr_str(&_9$$6, SL("CURRENT_TIMESTAMP"), "phalcon/db/dialect/mysql.zep", 293)) {
			zephir_concat_self_str(&sql, SL(" DEFAULT CURRENT_TIMESTAMP") TSRMLS_CC);
		} else {
			ZEPHIR_INIT_VAR(&_10$$8);
			ZVAL_STRING(&_10$$8, "\"");
			ZEPHIR_CALL_FUNCTION(&_11$$8, "addcslashes", NULL, 145, &defaultValue, &_10$$8);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(&_12$$8);
			ZEPHIR_CONCAT_SVS(&_12$$8, " DEFAULT \"", &_11$$8, "\"");
			zephir_concat_self(&sql, &_12$$8 TSRMLS_CC);
		}
	}
	ZEPHIR_CALL_METHOD(&_13, column, "isnotnull", NULL, 0);
	zephir_check_call_status();
	if (zephir_is_true(&_13)) {
		zephir_concat_self_str(&sql, SL(" NOT NULL") TSRMLS_CC);
	}
	ZEPHIR_CALL_METHOD(&_14, column, "isautoincrement", NULL, 0);
	zephir_check_call_status();
	if (zephir_is_true(&_14)) {
		zephir_concat_self_str(&sql, SL(" AUTO_INCREMENT") TSRMLS_CC);
	}
	ZEPHIR_CALL_METHOD(&_15, column, "isfirst", NULL, 0);
	zephir_check_call_status();
	if (zephir_is_true(&_15)) {
		zephir_concat_self_str(&sql, SL(" FIRST") TSRMLS_CC);
	} else {
		ZEPHIR_CALL_METHOD(&afterPosition, column, "getafterposition", NULL, 0);
		zephir_check_call_status();
		if (zephir_is_true(&afterPosition)) {
			ZEPHIR_INIT_VAR(&_16$$13);
			ZEPHIR_CONCAT_SVS(&_16$$13, " AFTER `", &afterPosition, "`");
			zephir_concat_self(&sql, &_16$$13 TSRMLS_CC);
		}
	}
	RETURN_CCTOR(&sql);

}

/**
 * Generates SQL to delete a column from a table
 */
PHP_METHOD(Phalcon_Db_Dialect_Mysql, dropColumn) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *tableName_param = NULL, *schemaName_param = NULL, *columnName_param = NULL, _0;
	zval tableName, schemaName, columnName;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&tableName);
	ZVAL_UNDEF(&schemaName);
	ZVAL_UNDEF(&columnName);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &tableName_param, &schemaName_param, &columnName_param);

	if (UNEXPECTED(Z_TYPE_P(tableName_param) != IS_STRING && Z_TYPE_P(tableName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'tableName' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(tableName_param) == IS_STRING)) {
		zephir_get_strval(&tableName, tableName_param);
	} else {
		ZEPHIR_INIT_VAR(&tableName);
		ZVAL_EMPTY_STRING(&tableName);
	}
	if (UNEXPECTED(Z_TYPE_P(schemaName_param) != IS_STRING && Z_TYPE_P(schemaName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'schemaName' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(schemaName_param) == IS_STRING)) {
		zephir_get_strval(&schemaName, schemaName_param);
	} else {
		ZEPHIR_INIT_VAR(&schemaName);
		ZVAL_EMPTY_STRING(&schemaName);
	}
	if (UNEXPECTED(Z_TYPE_P(columnName_param) != IS_STRING && Z_TYPE_P(columnName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'columnName' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(columnName_param) == IS_STRING)) {
		zephir_get_strval(&columnName, columnName_param);
	} else {
		ZEPHIR_INIT_VAR(&columnName);
		ZVAL_EMPTY_STRING(&columnName);
	}


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "preparetable", NULL, 0, &tableName, &schemaName);
	zephir_check_call_status();
	ZEPHIR_CONCAT_SVSVS(return_value, "ALTER TABLE ", &_0, " DROP COLUMN `", &columnName, "`");
	RETURN_MM();

}

/**
 * Generates SQL to add an index to a table
 */
PHP_METHOD(Phalcon_Db_Dialect_Mysql, addIndex) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *tableName_param = NULL, *schemaName_param = NULL, *index, index_sub, sql, indexType, _0, _2, _3, _4, _5, _1$$3;
	zval tableName, schemaName;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&tableName);
	ZVAL_UNDEF(&schemaName);
	ZVAL_UNDEF(&index_sub);
	ZVAL_UNDEF(&sql);
	ZVAL_UNDEF(&indexType);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_1$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &tableName_param, &schemaName_param, &index);

	if (UNEXPECTED(Z_TYPE_P(tableName_param) != IS_STRING && Z_TYPE_P(tableName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'tableName' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(tableName_param) == IS_STRING)) {
		zephir_get_strval(&tableName, tableName_param);
	} else {
		ZEPHIR_INIT_VAR(&tableName);
		ZVAL_EMPTY_STRING(&tableName);
	}
	if (UNEXPECTED(Z_TYPE_P(schemaName_param) != IS_STRING && Z_TYPE_P(schemaName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'schemaName' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(schemaName_param) == IS_STRING)) {
		zephir_get_strval(&schemaName, schemaName_param);
	} else {
		ZEPHIR_INIT_VAR(&schemaName);
		ZVAL_EMPTY_STRING(&schemaName);
	}


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "preparetable", NULL, 0, &tableName, &schemaName);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&sql);
	ZEPHIR_CONCAT_SV(&sql, "ALTER TABLE ", &_0);
	ZEPHIR_CALL_METHOD(&indexType, index, "gettype", NULL, 0);
	zephir_check_call_status();
	if (!(ZEPHIR_IS_EMPTY(&indexType))) {
		ZEPHIR_INIT_VAR(&_1$$3);
		ZEPHIR_CONCAT_SVS(&_1$$3, " ADD ", &indexType, " INDEX ");
		zephir_concat_self(&sql, &_1$$3 TSRMLS_CC);
	} else {
		zephir_concat_self_str(&sql, SL(" ADD INDEX ") TSRMLS_CC);
	}
	ZEPHIR_CALL_METHOD(&_2, index, "getname", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_4, index, "getcolumns", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_3, this_ptr, "getcolumnlist", NULL, 38, &_4);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_5);
	ZEPHIR_CONCAT_SVSVS(&_5, "`", &_2, "` (", &_3, ")");
	zephir_concat_self(&sql, &_5 TSRMLS_CC);
	RETURN_CCTOR(&sql);

}

/**
 * Generates SQL to delete an index from a table
 */
PHP_METHOD(Phalcon_Db_Dialect_Mysql, dropIndex) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *tableName_param = NULL, *schemaName_param = NULL, *indexName_param = NULL, _0;
	zval tableName, schemaName, indexName;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&tableName);
	ZVAL_UNDEF(&schemaName);
	ZVAL_UNDEF(&indexName);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &tableName_param, &schemaName_param, &indexName_param);

	if (UNEXPECTED(Z_TYPE_P(tableName_param) != IS_STRING && Z_TYPE_P(tableName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'tableName' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(tableName_param) == IS_STRING)) {
		zephir_get_strval(&tableName, tableName_param);
	} else {
		ZEPHIR_INIT_VAR(&tableName);
		ZVAL_EMPTY_STRING(&tableName);
	}
	if (UNEXPECTED(Z_TYPE_P(schemaName_param) != IS_STRING && Z_TYPE_P(schemaName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'schemaName' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(schemaName_param) == IS_STRING)) {
		zephir_get_strval(&schemaName, schemaName_param);
	} else {
		ZEPHIR_INIT_VAR(&schemaName);
		ZVAL_EMPTY_STRING(&schemaName);
	}
	if (UNEXPECTED(Z_TYPE_P(indexName_param) != IS_STRING && Z_TYPE_P(indexName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'indexName' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(indexName_param) == IS_STRING)) {
		zephir_get_strval(&indexName, indexName_param);
	} else {
		ZEPHIR_INIT_VAR(&indexName);
		ZVAL_EMPTY_STRING(&indexName);
	}


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "preparetable", NULL, 0, &tableName, &schemaName);
	zephir_check_call_status();
	ZEPHIR_CONCAT_SVSVS(return_value, "ALTER TABLE ", &_0, " DROP INDEX `", &indexName, "`");
	RETURN_MM();

}

/**
 * Generates SQL to add the primary key to a table
 */
PHP_METHOD(Phalcon_Db_Dialect_Mysql, addPrimaryKey) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *tableName_param = NULL, *schemaName_param = NULL, *index, index_sub, _0, _1, _2;
	zval tableName, schemaName;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&tableName);
	ZVAL_UNDEF(&schemaName);
	ZVAL_UNDEF(&index_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &tableName_param, &schemaName_param, &index);

	if (UNEXPECTED(Z_TYPE_P(tableName_param) != IS_STRING && Z_TYPE_P(tableName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'tableName' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(tableName_param) == IS_STRING)) {
		zephir_get_strval(&tableName, tableName_param);
	} else {
		ZEPHIR_INIT_VAR(&tableName);
		ZVAL_EMPTY_STRING(&tableName);
	}
	if (UNEXPECTED(Z_TYPE_P(schemaName_param) != IS_STRING && Z_TYPE_P(schemaName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'schemaName' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(schemaName_param) == IS_STRING)) {
		zephir_get_strval(&schemaName, schemaName_param);
	} else {
		ZEPHIR_INIT_VAR(&schemaName);
		ZVAL_EMPTY_STRING(&schemaName);
	}


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "preparetable", NULL, 0, &tableName, &schemaName);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_2, index, "getcolumns", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "getcolumnlist", NULL, 38, &_2);
	zephir_check_call_status();
	ZEPHIR_CONCAT_SVSVS(return_value, "ALTER TABLE ", &_0, " ADD PRIMARY KEY (", &_1, ")");
	RETURN_MM();

}

/**
 * Generates SQL to delete primary key from a table
 */
PHP_METHOD(Phalcon_Db_Dialect_Mysql, dropPrimaryKey) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *tableName_param = NULL, *schemaName_param = NULL, _0;
	zval tableName, schemaName;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&tableName);
	ZVAL_UNDEF(&schemaName);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &tableName_param, &schemaName_param);

	if (UNEXPECTED(Z_TYPE_P(tableName_param) != IS_STRING && Z_TYPE_P(tableName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'tableName' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(tableName_param) == IS_STRING)) {
		zephir_get_strval(&tableName, tableName_param);
	} else {
		ZEPHIR_INIT_VAR(&tableName);
		ZVAL_EMPTY_STRING(&tableName);
	}
	if (UNEXPECTED(Z_TYPE_P(schemaName_param) != IS_STRING && Z_TYPE_P(schemaName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'schemaName' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(schemaName_param) == IS_STRING)) {
		zephir_get_strval(&schemaName, schemaName_param);
	} else {
		ZEPHIR_INIT_VAR(&schemaName);
		ZVAL_EMPTY_STRING(&schemaName);
	}


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "preparetable", NULL, 0, &tableName, &schemaName);
	zephir_check_call_status();
	ZEPHIR_CONCAT_SVS(return_value, "ALTER TABLE ", &_0, " DROP PRIMARY KEY");
	RETURN_MM();

}

/**
 * Generates SQL to add an index to a table
 */
PHP_METHOD(Phalcon_Db_Dialect_Mysql, addForeignKey) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *tableName_param = NULL, *schemaName_param = NULL, *reference, reference_sub, sql, onDelete, onUpdate, _0, _1, _4, _5, _6, _7, _8, _9, _10, _11, _2$$3, _3$$3, _12$$4, _13$$5;
	zval tableName, schemaName;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&tableName);
	ZVAL_UNDEF(&schemaName);
	ZVAL_UNDEF(&reference_sub);
	ZVAL_UNDEF(&sql);
	ZVAL_UNDEF(&onDelete);
	ZVAL_UNDEF(&onUpdate);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_11);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_12$$4);
	ZVAL_UNDEF(&_13$$5);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &tableName_param, &schemaName_param, &reference);

	if (UNEXPECTED(Z_TYPE_P(tableName_param) != IS_STRING && Z_TYPE_P(tableName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'tableName' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(tableName_param) == IS_STRING)) {
		zephir_get_strval(&tableName, tableName_param);
	} else {
		ZEPHIR_INIT_VAR(&tableName);
		ZVAL_EMPTY_STRING(&tableName);
	}
	if (UNEXPECTED(Z_TYPE_P(schemaName_param) != IS_STRING && Z_TYPE_P(schemaName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'schemaName' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(schemaName_param) == IS_STRING)) {
		zephir_get_strval(&schemaName, schemaName_param);
	} else {
		ZEPHIR_INIT_VAR(&schemaName);
		ZVAL_EMPTY_STRING(&schemaName);
	}


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "preparetable", NULL, 0, &tableName, &schemaName);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&sql);
	ZEPHIR_CONCAT_SVS(&sql, "ALTER TABLE ", &_0, " ADD");
	ZEPHIR_CALL_METHOD(&_1, reference, "getname", NULL, 0);
	zephir_check_call_status();
	if (zephir_is_true(&_1)) {
		ZEPHIR_CALL_METHOD(&_2$$3, reference, "getname", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_3$$3);
		ZEPHIR_CONCAT_SVS(&_3$$3, " CONSTRAINT `", &_2$$3, "`");
		zephir_concat_self(&sql, &_3$$3 TSRMLS_CC);
	}
	ZEPHIR_CALL_METHOD(&_5, reference, "getcolumns", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_4, this_ptr, "getcolumnlist", NULL, 38, &_5);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_7, reference, "getreferencedtable", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_8, reference, "getreferencedschema", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_6, this_ptr, "preparetable", NULL, 0, &_7, &_8);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_10, reference, "getreferencedcolumns", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_9, this_ptr, "getcolumnlist", NULL, 38, &_10);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_11);
	ZEPHIR_CONCAT_SVSVSVS(&_11, " FOREIGN KEY (", &_4, ") REFERENCES ", &_6, "(", &_9, ")");
	zephir_concat_self(&sql, &_11 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&onDelete, reference, "getondelete", NULL, 0);
	zephir_check_call_status();
	if (!(ZEPHIR_IS_EMPTY(&onDelete))) {
		ZEPHIR_INIT_VAR(&_12$$4);
		ZEPHIR_CONCAT_SV(&_12$$4, " ON DELETE ", &onDelete);
		zephir_concat_self(&sql, &_12$$4 TSRMLS_CC);
	}
	ZEPHIR_CALL_METHOD(&onUpdate, reference, "getonupdate", NULL, 0);
	zephir_check_call_status();
	if (!(ZEPHIR_IS_EMPTY(&onUpdate))) {
		ZEPHIR_INIT_VAR(&_13$$5);
		ZEPHIR_CONCAT_SV(&_13$$5, " ON UPDATE ", &onUpdate);
		zephir_concat_self(&sql, &_13$$5 TSRMLS_CC);
	}
	RETURN_CCTOR(&sql);

}

/**
 * Generates SQL to delete a foreign key from a table
 */
PHP_METHOD(Phalcon_Db_Dialect_Mysql, dropForeignKey) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *tableName_param = NULL, *schemaName_param = NULL, *referenceName_param = NULL, _0;
	zval tableName, schemaName, referenceName;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&tableName);
	ZVAL_UNDEF(&schemaName);
	ZVAL_UNDEF(&referenceName);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &tableName_param, &schemaName_param, &referenceName_param);

	if (UNEXPECTED(Z_TYPE_P(tableName_param) != IS_STRING && Z_TYPE_P(tableName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'tableName' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(tableName_param) == IS_STRING)) {
		zephir_get_strval(&tableName, tableName_param);
	} else {
		ZEPHIR_INIT_VAR(&tableName);
		ZVAL_EMPTY_STRING(&tableName);
	}
	if (UNEXPECTED(Z_TYPE_P(schemaName_param) != IS_STRING && Z_TYPE_P(schemaName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'schemaName' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(schemaName_param) == IS_STRING)) {
		zephir_get_strval(&schemaName, schemaName_param);
	} else {
		ZEPHIR_INIT_VAR(&schemaName);
		ZVAL_EMPTY_STRING(&schemaName);
	}
	if (UNEXPECTED(Z_TYPE_P(referenceName_param) != IS_STRING && Z_TYPE_P(referenceName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'referenceName' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(referenceName_param) == IS_STRING)) {
		zephir_get_strval(&referenceName, referenceName_param);
	} else {
		ZEPHIR_INIT_VAR(&referenceName);
		ZVAL_EMPTY_STRING(&referenceName);
	}


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "preparetable", NULL, 0, &tableName, &schemaName);
	zephir_check_call_status();
	ZEPHIR_CONCAT_SVSVS(return_value, "ALTER TABLE ", &_0, " DROP FOREIGN KEY `", &referenceName, "`");
	RETURN_MM();

}

/**
 * Generates SQL to create a table
 */
PHP_METHOD(Phalcon_Db_Dialect_Mysql, createTable) {

	zephir_fcall_cache_entry *_4 = NULL, *_9 = NULL, *_28 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval definition;
	zval *tableName_param = NULL, *schemaName_param = NULL, *definition_param = NULL, temporary, options, table, createLines, columns, column, indexes, index, reference, references, indexName, indexSql, sql, columnLine, indexType, referenceSql, onDelete, onUpdate, defaultValue, *_0, _1, _57, _58, _2$$7, _3$$7, _5$$7, _11$$7, _12$$7, _13$$7, _6$$8, _7$$10, _8$$10, _10$$10, _14$$14, _15$$14, _16$$14, _21$$14, _22$$14, _23$$14, _17$$15, _18$$17, _19$$17, _20$$17, *_24$$21, _25$$21, _26$$23, _27$$23, _29$$25, _30$$25, _31$$26, _32$$26, _33$$28, _34$$28, _35$$30, _36$$30, _37$$31, _38$$31, *_39$$32, _40$$32, _41$$33, _42$$33, _43$$33, _44$$33, _45$$33, _46$$33, _47$$34, _48$$35, _49$$36, _50$$36, _51$$36, _52$$36, _53$$36, _54$$36, _55$$37, _56$$38, _59$$39, _60$$39;
	zval tableName, schemaName;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&tableName);
	ZVAL_UNDEF(&schemaName);
	ZVAL_UNDEF(&temporary);
	ZVAL_UNDEF(&options);
	ZVAL_UNDEF(&table);
	ZVAL_UNDEF(&createLines);
	ZVAL_UNDEF(&columns);
	ZVAL_UNDEF(&column);
	ZVAL_UNDEF(&indexes);
	ZVAL_UNDEF(&index);
	ZVAL_UNDEF(&reference);
	ZVAL_UNDEF(&references);
	ZVAL_UNDEF(&indexName);
	ZVAL_UNDEF(&indexSql);
	ZVAL_UNDEF(&sql);
	ZVAL_UNDEF(&columnLine);
	ZVAL_UNDEF(&indexType);
	ZVAL_UNDEF(&referenceSql);
	ZVAL_UNDEF(&onDelete);
	ZVAL_UNDEF(&onUpdate);
	ZVAL_UNDEF(&defaultValue);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_57);
	ZVAL_UNDEF(&_58);
	ZVAL_UNDEF(&_2$$7);
	ZVAL_UNDEF(&_3$$7);
	ZVAL_UNDEF(&_5$$7);
	ZVAL_UNDEF(&_11$$7);
	ZVAL_UNDEF(&_12$$7);
	ZVAL_UNDEF(&_13$$7);
	ZVAL_UNDEF(&_6$$8);
	ZVAL_UNDEF(&_7$$10);
	ZVAL_UNDEF(&_8$$10);
	ZVAL_UNDEF(&_10$$10);
	ZVAL_UNDEF(&_14$$14);
	ZVAL_UNDEF(&_15$$14);
	ZVAL_UNDEF(&_16$$14);
	ZVAL_UNDEF(&_21$$14);
	ZVAL_UNDEF(&_22$$14);
	ZVAL_UNDEF(&_23$$14);
	ZVAL_UNDEF(&_17$$15);
	ZVAL_UNDEF(&_18$$17);
	ZVAL_UNDEF(&_19$$17);
	ZVAL_UNDEF(&_20$$17);
	ZVAL_UNDEF(&_25$$21);
	ZVAL_UNDEF(&_26$$23);
	ZVAL_UNDEF(&_27$$23);
	ZVAL_UNDEF(&_29$$25);
	ZVAL_UNDEF(&_30$$25);
	ZVAL_UNDEF(&_31$$26);
	ZVAL_UNDEF(&_32$$26);
	ZVAL_UNDEF(&_33$$28);
	ZVAL_UNDEF(&_34$$28);
	ZVAL_UNDEF(&_35$$30);
	ZVAL_UNDEF(&_36$$30);
	ZVAL_UNDEF(&_37$$31);
	ZVAL_UNDEF(&_38$$31);
	ZVAL_UNDEF(&_40$$32);
	ZVAL_UNDEF(&_41$$33);
	ZVAL_UNDEF(&_42$$33);
	ZVAL_UNDEF(&_43$$33);
	ZVAL_UNDEF(&_44$$33);
	ZVAL_UNDEF(&_45$$33);
	ZVAL_UNDEF(&_46$$33);
	ZVAL_UNDEF(&_47$$34);
	ZVAL_UNDEF(&_48$$35);
	ZVAL_UNDEF(&_49$$36);
	ZVAL_UNDEF(&_50$$36);
	ZVAL_UNDEF(&_51$$36);
	ZVAL_UNDEF(&_52$$36);
	ZVAL_UNDEF(&_53$$36);
	ZVAL_UNDEF(&_54$$36);
	ZVAL_UNDEF(&_55$$37);
	ZVAL_UNDEF(&_56$$38);
	ZVAL_UNDEF(&_59$$39);
	ZVAL_UNDEF(&_60$$39);
	ZVAL_UNDEF(&definition);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &tableName_param, &schemaName_param, &definition_param);

	if (UNEXPECTED(Z_TYPE_P(tableName_param) != IS_STRING && Z_TYPE_P(tableName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'tableName' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(tableName_param) == IS_STRING)) {
		zephir_get_strval(&tableName, tableName_param);
	} else {
		ZEPHIR_INIT_VAR(&tableName);
		ZVAL_EMPTY_STRING(&tableName);
	}
	if (UNEXPECTED(Z_TYPE_P(schemaName_param) != IS_STRING && Z_TYPE_P(schemaName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'schemaName' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(schemaName_param) == IS_STRING)) {
		zephir_get_strval(&schemaName, schemaName_param);
	} else {
		ZEPHIR_INIT_VAR(&schemaName);
		ZVAL_EMPTY_STRING(&schemaName);
	}
	ZEPHIR_OBS_COPY_OR_DUP(&definition, definition_param);


	ZEPHIR_OBS_VAR(&columns);
	if (!(zephir_array_isset_string_fetch(&columns, &definition, SL("columns"), 0))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_db_exception_ce, "The index 'columns' is required in the definition array", "phalcon/db/dialect/mysql.zep", 416);
		return;
	}
	ZEPHIR_CALL_METHOD(&table, this_ptr, "preparetable", NULL, 0, &tableName, &schemaName);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&temporary);
	ZVAL_BOOL(&temporary, 0);
	ZEPHIR_OBS_VAR(&options);
	if (zephir_array_isset_string_fetch(&options, &definition, SL("options"), 0)) {
		ZEPHIR_OBS_NVAR(&temporary);
		zephir_array_isset_string_fetch(&temporary, &options, SL("temporary"), 0);
	}
	ZEPHIR_INIT_VAR(&sql);
	if (zephir_is_true(&temporary)) {
		ZEPHIR_CONCAT_SVS(&sql, "CREATE TEMPORARY TABLE ", &table, " (\n\t");
	} else {
		ZEPHIR_CONCAT_SVS(&sql, "CREATE TABLE ", &table, " (\n\t");
	}
	ZEPHIR_INIT_VAR(&createLines);
	array_init(&createLines);
	zephir_is_iterable(&columns, 0, "phalcon/db/dialect/mysql.zep", 479);
	if (Z_TYPE_P(&columns) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&columns), _0)
		{
			ZEPHIR_INIT_NVAR(&column);
			ZVAL_COPY(&column, _0);
			ZEPHIR_CALL_METHOD(&_2$$7, &column, "getname", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&_3$$7, this_ptr, "getcolumndefinition", &_4, 0, &column);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(&columnLine);
			ZEPHIR_CONCAT_SVSV(&columnLine, "`", &_2$$7, "` ", &_3$$7);
			ZEPHIR_CALL_METHOD(&_5$$7, &column, "hasdefault", NULL, 0);
			zephir_check_call_status();
			if (zephir_is_true(&_5$$7)) {
				ZEPHIR_CALL_METHOD(&defaultValue, &column, "getdefault", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_6$$8);
				zephir_fast_strtoupper(&_6$$8, &defaultValue);
				if (zephir_memnstr_str(&_6$$8, SL("CURRENT_TIMESTAMP"), "phalcon/db/dialect/mysql.zep", 445)) {
					zephir_concat_self_str(&columnLine, SL(" DEFAULT CURRENT_TIMESTAMP") TSRMLS_CC);
				} else {
					ZEPHIR_INIT_NVAR(&_7$$10);
					ZVAL_STRING(&_7$$10, "\"");
					ZEPHIR_CALL_FUNCTION(&_8$$10, "addcslashes", &_9, 145, &defaultValue, &_7$$10);
					zephir_check_call_status();
					ZEPHIR_INIT_LNVAR(_10$$10);
					ZEPHIR_CONCAT_SVS(&_10$$10, " DEFAULT \"", &_8$$10, "\"");
					zephir_concat_self(&columnLine, &_10$$10 TSRMLS_CC);
				}
			}
			ZEPHIR_CALL_METHOD(&_11$$7, &column, "isnotnull", NULL, 0);
			zephir_check_call_status();
			if (zephir_is_true(&_11$$7)) {
				zephir_concat_self_str(&columnLine, SL(" NOT NULL") TSRMLS_CC);
			}
			ZEPHIR_CALL_METHOD(&_12$$7, &column, "isautoincrement", NULL, 0);
			zephir_check_call_status();
			if (zephir_is_true(&_12$$7)) {
				zephir_concat_self_str(&columnLine, SL(" AUTO_INCREMENT") TSRMLS_CC);
			}
			ZEPHIR_CALL_METHOD(&_13$$7, &column, "isprimary", NULL, 0);
			zephir_check_call_status();
			if (zephir_is_true(&_13$$7)) {
				zephir_concat_self_str(&columnLine, SL(" PRIMARY KEY") TSRMLS_CC);
			}
			zephir_array_append(&createLines, &columnLine, PH_SEPARATE, "phalcon/db/dialect/mysql.zep", 473);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &columns, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_1, &columns, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_1)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&column, &columns, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&_14$$14, &column, "getname", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&_15$$14, this_ptr, "getcolumndefinition", &_4, 0, &column);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&columnLine);
				ZEPHIR_CONCAT_SVSV(&columnLine, "`", &_14$$14, "` ", &_15$$14);
				ZEPHIR_CALL_METHOD(&_16$$14, &column, "hasdefault", NULL, 0);
				zephir_check_call_status();
				if (zephir_is_true(&_16$$14)) {
					ZEPHIR_CALL_METHOD(&defaultValue, &column, "getdefault", NULL, 0);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_17$$15);
					zephir_fast_strtoupper(&_17$$15, &defaultValue);
					if (zephir_memnstr_str(&_17$$15, SL("CURRENT_TIMESTAMP"), "phalcon/db/dialect/mysql.zep", 445)) {
						zephir_concat_self_str(&columnLine, SL(" DEFAULT CURRENT_TIMESTAMP") TSRMLS_CC);
					} else {
						ZEPHIR_INIT_NVAR(&_18$$17);
						ZVAL_STRING(&_18$$17, "\"");
						ZEPHIR_CALL_FUNCTION(&_19$$17, "addcslashes", &_9, 145, &defaultValue, &_18$$17);
						zephir_check_call_status();
						ZEPHIR_INIT_LNVAR(_20$$17);
						ZEPHIR_CONCAT_SVS(&_20$$17, " DEFAULT \"", &_19$$17, "\"");
						zephir_concat_self(&columnLine, &_20$$17 TSRMLS_CC);
					}
				}
				ZEPHIR_CALL_METHOD(&_21$$14, &column, "isnotnull", NULL, 0);
				zephir_check_call_status();
				if (zephir_is_true(&_21$$14)) {
					zephir_concat_self_str(&columnLine, SL(" NOT NULL") TSRMLS_CC);
				}
				ZEPHIR_CALL_METHOD(&_22$$14, &column, "isautoincrement", NULL, 0);
				zephir_check_call_status();
				if (zephir_is_true(&_22$$14)) {
					zephir_concat_self_str(&columnLine, SL(" AUTO_INCREMENT") TSRMLS_CC);
				}
				ZEPHIR_CALL_METHOD(&_23$$14, &column, "isprimary", NULL, 0);
				zephir_check_call_status();
				if (zephir_is_true(&_23$$14)) {
					zephir_concat_self_str(&columnLine, SL(" PRIMARY KEY") TSRMLS_CC);
				}
				zephir_array_append(&createLines, &columnLine, PH_SEPARATE, "phalcon/db/dialect/mysql.zep", 473);
			ZEPHIR_CALL_METHOD(NULL, &columns, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&column);
	ZEPHIR_OBS_VAR(&indexes);
	if (zephir_array_isset_string_fetch(&indexes, &definition, SL("indexes"), 0)) {
		zephir_is_iterable(&indexes, 0, "phalcon/db/dialect/mysql.zep", 501);
		if (Z_TYPE_P(&indexes) == IS_ARRAY) {
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&indexes), _24$$21)
			{
				ZEPHIR_INIT_NVAR(&index);
				ZVAL_COPY(&index, _24$$21);
				ZEPHIR_CALL_METHOD(&indexName, &index, "getname", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&indexType, &index, "gettype", NULL, 0);
				zephir_check_call_status();
				if (ZEPHIR_IS_STRING(&indexName, "PRIMARY")) {
					ZEPHIR_CALL_METHOD(&_27$$23, &index, "getcolumns", NULL, 0);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&_26$$23, this_ptr, "getcolumnlist", &_28, 38, &_27$$23);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&indexSql);
					ZEPHIR_CONCAT_SVS(&indexSql, "PRIMARY KEY (", &_26$$23, ")");
				} else {
					ZEPHIR_INIT_NVAR(&indexSql);
					if (!(ZEPHIR_IS_EMPTY(&indexType))) {
						ZEPHIR_CALL_METHOD(&_30$$25, &index, "getcolumns", NULL, 0);
						zephir_check_call_status();
						ZEPHIR_CALL_METHOD(&_29$$25, this_ptr, "getcolumnlist", &_28, 38, &_30$$25);
						zephir_check_call_status();
						ZEPHIR_CONCAT_VSVSVS(&indexSql, &indexType, " KEY `", &indexName, "` (", &_29$$25, ")");
					} else {
						ZEPHIR_CALL_METHOD(&_32$$26, &index, "getcolumns", NULL, 0);
						zephir_check_call_status();
						ZEPHIR_CALL_METHOD(&_31$$26, this_ptr, "getcolumnlist", &_28, 38, &_32$$26);
						zephir_check_call_status();
						ZEPHIR_CONCAT_SVSVS(&indexSql, "KEY `", &indexName, "` (", &_31$$26, ")");
					}
				}
				zephir_array_append(&createLines, &indexSql, PH_SEPARATE, "phalcon/db/dialect/mysql.zep", 499);
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, &indexes, "rewind", NULL, 0);
			zephir_check_call_status();
			while (1) {
				ZEPHIR_CALL_METHOD(&_25$$21, &indexes, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_25$$21)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&index, &indexes, "current", NULL, 0);
				zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&indexName, &index, "getname", NULL, 0);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&indexType, &index, "gettype", NULL, 0);
					zephir_check_call_status();
					if (ZEPHIR_IS_STRING(&indexName, "PRIMARY")) {
						ZEPHIR_CALL_METHOD(&_34$$28, &index, "getcolumns", NULL, 0);
						zephir_check_call_status();
						ZEPHIR_CALL_METHOD(&_33$$28, this_ptr, "getcolumnlist", &_28, 38, &_34$$28);
						zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&indexSql);
						ZEPHIR_CONCAT_SVS(&indexSql, "PRIMARY KEY (", &_33$$28, ")");
					} else {
						ZEPHIR_INIT_NVAR(&indexSql);
						if (!(ZEPHIR_IS_EMPTY(&indexType))) {
							ZEPHIR_CALL_METHOD(&_36$$30, &index, "getcolumns", NULL, 0);
							zephir_check_call_status();
							ZEPHIR_CALL_METHOD(&_35$$30, this_ptr, "getcolumnlist", &_28, 38, &_36$$30);
							zephir_check_call_status();
							ZEPHIR_CONCAT_VSVSVS(&indexSql, &indexType, " KEY `", &indexName, "` (", &_35$$30, ")");
						} else {
							ZEPHIR_CALL_METHOD(&_38$$31, &index, "getcolumns", NULL, 0);
							zephir_check_call_status();
							ZEPHIR_CALL_METHOD(&_37$$31, this_ptr, "getcolumnlist", &_28, 38, &_38$$31);
							zephir_check_call_status();
							ZEPHIR_CONCAT_SVSVS(&indexSql, "KEY `", &indexName, "` (", &_37$$31, ")");
						}
					}
					zephir_array_append(&createLines, &indexSql, PH_SEPARATE, "phalcon/db/dialect/mysql.zep", 499);
				ZEPHIR_CALL_METHOD(NULL, &indexes, "next", NULL, 0);
				zephir_check_call_status();
			}
		}
		ZEPHIR_INIT_NVAR(&index);
	}
	ZEPHIR_OBS_VAR(&references);
	if (zephir_array_isset_string_fetch(&references, &definition, SL("references"), 0)) {
		zephir_is_iterable(&references, 0, "phalcon/db/dialect/mysql.zep", 523);
		if (Z_TYPE_P(&references) == IS_ARRAY) {
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&references), _39$$32)
			{
				ZEPHIR_INIT_NVAR(&reference);
				ZVAL_COPY(&reference, _39$$32);
				ZEPHIR_CALL_METHOD(&_41$$33, &reference, "getname", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&_43$$33, &reference, "getcolumns", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&_42$$33, this_ptr, "getcolumnlist", &_28, 38, &_43$$33);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&_44$$33, &reference, "getreferencedtable", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&_46$$33, &reference, "getreferencedcolumns", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&_45$$33, this_ptr, "getcolumnlist", &_28, 38, &_46$$33);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&referenceSql);
				ZEPHIR_CONCAT_SVSVSSVSVS(&referenceSql, "CONSTRAINT `", &_41$$33, "` FOREIGN KEY (", &_42$$33, ")", " REFERENCES `", &_44$$33, "`(", &_45$$33, ")");
				ZEPHIR_CALL_METHOD(&onDelete, &reference, "getondelete", NULL, 0);
				zephir_check_call_status();
				if (!(ZEPHIR_IS_EMPTY(&onDelete))) {
					ZEPHIR_INIT_LNVAR(_47$$34);
					ZEPHIR_CONCAT_SV(&_47$$34, " ON DELETE ", &onDelete);
					zephir_concat_self(&referenceSql, &_47$$34 TSRMLS_CC);
				}
				ZEPHIR_CALL_METHOD(&onUpdate, &reference, "getonupdate", NULL, 0);
				zephir_check_call_status();
				if (!(ZEPHIR_IS_EMPTY(&onUpdate))) {
					ZEPHIR_INIT_LNVAR(_48$$35);
					ZEPHIR_CONCAT_SV(&_48$$35, " ON UPDATE ", &onUpdate);
					zephir_concat_self(&referenceSql, &_48$$35 TSRMLS_CC);
				}
				zephir_array_append(&createLines, &referenceSql, PH_SEPARATE, "phalcon/db/dialect/mysql.zep", 521);
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, &references, "rewind", NULL, 0);
			zephir_check_call_status();
			while (1) {
				ZEPHIR_CALL_METHOD(&_40$$32, &references, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_40$$32)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&reference, &references, "current", NULL, 0);
				zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&_49$$36, &reference, "getname", NULL, 0);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&_51$$36, &reference, "getcolumns", NULL, 0);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&_50$$36, this_ptr, "getcolumnlist", &_28, 38, &_51$$36);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&_52$$36, &reference, "getreferencedtable", NULL, 0);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&_54$$36, &reference, "getreferencedcolumns", NULL, 0);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&_53$$36, this_ptr, "getcolumnlist", &_28, 38, &_54$$36);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&referenceSql);
					ZEPHIR_CONCAT_SVSVSSVSVS(&referenceSql, "CONSTRAINT `", &_49$$36, "` FOREIGN KEY (", &_50$$36, ")", " REFERENCES `", &_52$$36, "`(", &_53$$36, ")");
					ZEPHIR_CALL_METHOD(&onDelete, &reference, "getondelete", NULL, 0);
					zephir_check_call_status();
					if (!(ZEPHIR_IS_EMPTY(&onDelete))) {
						ZEPHIR_INIT_LNVAR(_55$$37);
						ZEPHIR_CONCAT_SV(&_55$$37, " ON DELETE ", &onDelete);
						zephir_concat_self(&referenceSql, &_55$$37 TSRMLS_CC);
					}
					ZEPHIR_CALL_METHOD(&onUpdate, &reference, "getonupdate", NULL, 0);
					zephir_check_call_status();
					if (!(ZEPHIR_IS_EMPTY(&onUpdate))) {
						ZEPHIR_INIT_LNVAR(_56$$38);
						ZEPHIR_CONCAT_SV(&_56$$38, " ON UPDATE ", &onUpdate);
						zephir_concat_self(&referenceSql, &_56$$38 TSRMLS_CC);
					}
					zephir_array_append(&createLines, &referenceSql, PH_SEPARATE, "phalcon/db/dialect/mysql.zep", 521);
				ZEPHIR_CALL_METHOD(NULL, &references, "next", NULL, 0);
				zephir_check_call_status();
			}
		}
		ZEPHIR_INIT_NVAR(&reference);
	}
	ZEPHIR_INIT_VAR(&_57);
	zephir_fast_join_str(&_57, SL(",\n\t"), &createLines TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_58);
	ZEPHIR_CONCAT_VS(&_58, &_57, "\n)");
	zephir_concat_self(&sql, &_58 TSRMLS_CC);
	if (zephir_array_isset_string(&definition, SL("options"))) {
		ZEPHIR_CALL_METHOD(&_59$$39, this_ptr, "_gettableoptions", NULL, 0, &definition);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_60$$39);
		ZEPHIR_CONCAT_SV(&_60$$39, " ", &_59$$39);
		zephir_concat_self(&sql, &_60$$39 TSRMLS_CC);
	}
	RETURN_CCTOR(&sql);

}

/**
 * Generates SQL to truncate a table
 */
PHP_METHOD(Phalcon_Db_Dialect_Mysql, truncateTable) {

	zval *tableName_param = NULL, *schemaName_param = NULL, sql, table;
	zval tableName, schemaName, _0$$3, _1$$4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&tableName);
	ZVAL_UNDEF(&schemaName);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&sql);
	ZVAL_UNDEF(&table);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &tableName_param, &schemaName_param);

	if (UNEXPECTED(Z_TYPE_P(tableName_param) != IS_STRING && Z_TYPE_P(tableName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'tableName' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(tableName_param) == IS_STRING)) {
		zephir_get_strval(&tableName, tableName_param);
	} else {
		ZEPHIR_INIT_VAR(&tableName);
		ZVAL_EMPTY_STRING(&tableName);
	}
	if (UNEXPECTED(Z_TYPE_P(schemaName_param) != IS_STRING && Z_TYPE_P(schemaName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'schemaName' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(schemaName_param) == IS_STRING)) {
		zephir_get_strval(&schemaName, schemaName_param);
	} else {
		ZEPHIR_INIT_VAR(&schemaName);
		ZVAL_EMPTY_STRING(&schemaName);
	}


	ZEPHIR_INIT_VAR(&table);
	if (!(Z_TYPE_P(&schemaName) == IS_UNDEF) && Z_STRLEN_P(&schemaName)) {
		ZEPHIR_INIT_VAR(&_0$$3);
		ZEPHIR_CONCAT_SVSVS(&_0$$3, "`", &schemaName, "`.`", &tableName, "`");
		ZEPHIR_CPY_WRT(&table, &_0$$3);
	} else {
		ZEPHIR_INIT_VAR(&_1$$4);
		ZEPHIR_CONCAT_SVS(&_1$$4, "`", &tableName, "`");
		ZEPHIR_CPY_WRT(&table, &_1$$4);
	}
	ZEPHIR_INIT_VAR(&sql);
	ZEPHIR_CONCAT_SV(&sql, "TRUNCATE TABLE ", &table);
	RETURN_CCTOR(&sql);

}

/**
 * Generates SQL to drop a table
 */
PHP_METHOD(Phalcon_Db_Dialect_Mysql, dropTable) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool ifExists;
	zval *tableName_param = NULL, *schemaName_param = NULL, *ifExists_param = NULL, sql, table;
	zval tableName, schemaName;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&tableName);
	ZVAL_UNDEF(&schemaName);
	ZVAL_UNDEF(&sql);
	ZVAL_UNDEF(&table);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &tableName_param, &schemaName_param, &ifExists_param);

	if (UNEXPECTED(Z_TYPE_P(tableName_param) != IS_STRING && Z_TYPE_P(tableName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'tableName' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(tableName_param) == IS_STRING)) {
		zephir_get_strval(&tableName, tableName_param);
	} else {
		ZEPHIR_INIT_VAR(&tableName);
		ZVAL_EMPTY_STRING(&tableName);
	}
	if (!schemaName_param) {
		ZEPHIR_INIT_VAR(&schemaName);
		ZVAL_STRING(&schemaName, "");
	} else {
		zephir_get_strval(&schemaName, schemaName_param);
	}
	if (!ifExists_param) {
		ifExists = 1;
	} else {
	if (UNEXPECTED(Z_TYPE_P(ifExists_param) != IS_TRUE && Z_TYPE_P(ifExists_param) != IS_FALSE)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'ifExists' must be of the type bool") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	ifExists = (Z_TYPE_P(ifExists_param) == IS_TRUE);
	}


	ZEPHIR_CALL_METHOD(&table, this_ptr, "preparetable", NULL, 0, &tableName, &schemaName);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&sql);
	if (ifExists) {
		ZEPHIR_CONCAT_SV(&sql, "DROP TABLE IF EXISTS ", &table);
	} else {
		ZEPHIR_CONCAT_SV(&sql, "DROP TABLE ", &table);
	}
	RETURN_CCTOR(&sql);

}

/**
 * Generates SQL to create a view
 */
PHP_METHOD(Phalcon_Db_Dialect_Mysql, createView) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval definition;
	zval *viewName_param = NULL, *definition_param = NULL, *schemaName_param = NULL, viewSql, _0;
	zval viewName, schemaName;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&viewName);
	ZVAL_UNDEF(&schemaName);
	ZVAL_UNDEF(&viewSql);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&definition);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &viewName_param, &definition_param, &schemaName_param);

	if (UNEXPECTED(Z_TYPE_P(viewName_param) != IS_STRING && Z_TYPE_P(viewName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'viewName' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(viewName_param) == IS_STRING)) {
		zephir_get_strval(&viewName, viewName_param);
	} else {
		ZEPHIR_INIT_VAR(&viewName);
		ZVAL_EMPTY_STRING(&viewName);
	}
	ZEPHIR_OBS_COPY_OR_DUP(&definition, definition_param);
	if (!schemaName_param) {
		ZEPHIR_INIT_VAR(&schemaName);
		ZVAL_STRING(&schemaName, "");
	} else {
		zephir_get_strval(&schemaName, schemaName_param);
	}


	ZEPHIR_OBS_VAR(&viewSql);
	if (!(zephir_array_isset_string_fetch(&viewSql, &definition, SL("sql"), 0))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_db_exception_ce, "The index 'sql' is required in the definition array", "phalcon/db/dialect/mysql.zep", 577);
		return;
	}
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "preparetable", NULL, 0, &viewName, &schemaName);
	zephir_check_call_status();
	ZEPHIR_CONCAT_SVSV(return_value, "CREATE VIEW ", &_0, " AS ", &viewSql);
	RETURN_MM();

}

/**
 * Generates SQL to drop a view
 */
PHP_METHOD(Phalcon_Db_Dialect_Mysql, dropView) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool ifExists;
	zval *viewName_param = NULL, *schemaName_param = NULL, *ifExists_param = NULL, sql, view;
	zval viewName, schemaName;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&viewName);
	ZVAL_UNDEF(&schemaName);
	ZVAL_UNDEF(&sql);
	ZVAL_UNDEF(&view);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &viewName_param, &schemaName_param, &ifExists_param);

	if (UNEXPECTED(Z_TYPE_P(viewName_param) != IS_STRING && Z_TYPE_P(viewName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'viewName' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(viewName_param) == IS_STRING)) {
		zephir_get_strval(&viewName, viewName_param);
	} else {
		ZEPHIR_INIT_VAR(&viewName);
		ZVAL_EMPTY_STRING(&viewName);
	}
	if (!schemaName_param) {
		ZEPHIR_INIT_VAR(&schemaName);
		ZVAL_STRING(&schemaName, "");
	} else {
		zephir_get_strval(&schemaName, schemaName_param);
	}
	if (!ifExists_param) {
		ifExists = 1;
	} else {
	if (UNEXPECTED(Z_TYPE_P(ifExists_param) != IS_TRUE && Z_TYPE_P(ifExists_param) != IS_FALSE)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'ifExists' must be of the type bool") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	ifExists = (Z_TYPE_P(ifExists_param) == IS_TRUE);
	}


	ZEPHIR_CALL_METHOD(&view, this_ptr, "preparetable", NULL, 0, &viewName, &schemaName);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&sql);
	if (ifExists) {
		ZEPHIR_CONCAT_SV(&sql, "DROP VIEW IF EXISTS ", &view);
	} else {
		ZEPHIR_CONCAT_SV(&sql, "DROP VIEW ", &view);
	}
	RETURN_CCTOR(&sql);

}

/**
 * Generates SQL checking for the existence of a schema.table
 *
 * <code>
 * echo $dialect->tableExists("posts", "blog");
 *
 * echo $dialect->tableExists("posts");
 * </code>
 */
PHP_METHOD(Phalcon_Db_Dialect_Mysql, tableExists) {

	zval *tableName_param = NULL, *schemaName_param = NULL;
	zval tableName, schemaName;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&tableName);
	ZVAL_UNDEF(&schemaName);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &tableName_param, &schemaName_param);

	if (UNEXPECTED(Z_TYPE_P(tableName_param) != IS_STRING && Z_TYPE_P(tableName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'tableName' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(tableName_param) == IS_STRING)) {
		zephir_get_strval(&tableName, tableName_param);
	} else {
		ZEPHIR_INIT_VAR(&tableName);
		ZVAL_EMPTY_STRING(&tableName);
	}
	if (!schemaName_param) {
		ZEPHIR_INIT_VAR(&schemaName);
		ZVAL_STRING(&schemaName, "");
	} else {
		zephir_get_strval(&schemaName, schemaName_param);
	}


	if (!(Z_TYPE_P(&schemaName) == IS_UNDEF) && Z_STRLEN_P(&schemaName)) {
		ZEPHIR_CONCAT_SVSVS(return_value, "SELECT IF(COUNT(*) > 0, 1, 0) FROM `INFORMATION_SCHEMA`.`TABLES` WHERE `TABLE_NAME`= '", &tableName, "' AND `TABLE_SCHEMA` = '", &schemaName, "'");
		RETURN_MM();
	}
	ZEPHIR_CONCAT_SVS(return_value, "SELECT IF(COUNT(*) > 0, 1, 0) FROM `INFORMATION_SCHEMA`.`TABLES` WHERE `TABLE_NAME` = '", &tableName, "' AND `TABLE_SCHEMA` = DATABASE()");
	RETURN_MM();

}

/**
 * Generates SQL checking for the existence of a schema.view
 */
PHP_METHOD(Phalcon_Db_Dialect_Mysql, viewExists) {

	zval *viewName_param = NULL, *schemaName_param = NULL;
	zval viewName, schemaName;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&viewName);
	ZVAL_UNDEF(&schemaName);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &viewName_param, &schemaName_param);

	if (UNEXPECTED(Z_TYPE_P(viewName_param) != IS_STRING && Z_TYPE_P(viewName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'viewName' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(viewName_param) == IS_STRING)) {
		zephir_get_strval(&viewName, viewName_param);
	} else {
		ZEPHIR_INIT_VAR(&viewName);
		ZVAL_EMPTY_STRING(&viewName);
	}
	if (!schemaName_param) {
		ZEPHIR_INIT_VAR(&schemaName);
		ZVAL_STRING(&schemaName, "");
	} else {
		zephir_get_strval(&schemaName, schemaName_param);
	}


	if (!(Z_TYPE_P(&schemaName) == IS_UNDEF) && Z_STRLEN_P(&schemaName)) {
		ZEPHIR_CONCAT_SVSVS(return_value, "SELECT IF(COUNT(*) > 0, 1, 0) FROM `INFORMATION_SCHEMA`.`VIEWS` WHERE `TABLE_NAME`= '", &viewName, "' AND `TABLE_SCHEMA`='", &schemaName, "'");
		RETURN_MM();
	}
	ZEPHIR_CONCAT_SVS(return_value, "SELECT IF(COUNT(*) > 0, 1, 0) FROM `INFORMATION_SCHEMA`.`VIEWS` WHERE `TABLE_NAME`='", &viewName, "' AND `TABLE_SCHEMA` = DATABASE()");
	RETURN_MM();

}

/**
 * Generates SQL describing a table
 *
 * <code>
 * print_r(
 *     $dialect->describeColumns("posts")
 * );
 * </code>
 */
PHP_METHOD(Phalcon_Db_Dialect_Mysql, describeColumns) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *table_param = NULL, *schema_param = NULL, _0;
	zval table, schema;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&table);
	ZVAL_UNDEF(&schema);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &table_param, &schema_param);

	if (UNEXPECTED(Z_TYPE_P(table_param) != IS_STRING && Z_TYPE_P(table_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'table' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(table_param) == IS_STRING)) {
		zephir_get_strval(&table, table_param);
	} else {
		ZEPHIR_INIT_VAR(&table);
		ZVAL_EMPTY_STRING(&table);
	}
	if (!schema_param) {
		ZEPHIR_INIT_VAR(&schema);
		ZVAL_STRING(&schema, "");
	} else {
		zephir_get_strval(&schema, schema_param);
	}


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "preparetable", NULL, 0, &table, &schema);
	zephir_check_call_status();
	ZEPHIR_CONCAT_SV(return_value, "DESCRIBE ", &_0);
	RETURN_MM();

}

/**
 * List all tables in database
 *
 * <code>
 * print_r(
 *     $dialect->listTables("blog")
 * );
 * </code>
 */
PHP_METHOD(Phalcon_Db_Dialect_Mysql, listTables) {

	zval *schemaName_param = NULL;
	zval schemaName;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&schemaName);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &schemaName_param);

	if (!schemaName_param) {
		ZEPHIR_INIT_VAR(&schemaName);
		ZVAL_STRING(&schemaName, "");
	} else {
		zephir_get_strval(&schemaName, schemaName_param);
	}


	if (!(Z_TYPE_P(&schemaName) == IS_UNDEF) && Z_STRLEN_P(&schemaName)) {
		ZEPHIR_CONCAT_SVS(return_value, "SHOW TABLES FROM `", &schemaName, "`");
		RETURN_MM();
	}
	RETURN_MM_STRING("SHOW TABLES");

}

/**
 * Generates the SQL to list all views of a schema or user
 */
PHP_METHOD(Phalcon_Db_Dialect_Mysql, listViews) {

	zval *schemaName_param = NULL;
	zval schemaName;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&schemaName);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &schemaName_param);

	if (!schemaName_param) {
		ZEPHIR_INIT_VAR(&schemaName);
		ZVAL_STRING(&schemaName, "");
	} else {
	if (UNEXPECTED(Z_TYPE_P(schemaName_param) != IS_STRING && Z_TYPE_P(schemaName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'schemaName' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(schemaName_param) == IS_STRING)) {
		zephir_get_strval(&schemaName, schemaName_param);
	} else {
		ZEPHIR_INIT_VAR(&schemaName);
		ZVAL_EMPTY_STRING(&schemaName);
	}
	}


	if (!(Z_TYPE_P(&schemaName) == IS_UNDEF) && Z_STRLEN_P(&schemaName)) {
		ZEPHIR_CONCAT_SVS(return_value, "SELECT `TABLE_NAME` AS view_name FROM `INFORMATION_SCHEMA`.`VIEWS` WHERE `TABLE_SCHEMA` = '", &schemaName, "' ORDER BY view_name");
		RETURN_MM();
	}
	RETURN_MM_STRING("SELECT `TABLE_NAME` AS view_name FROM `INFORMATION_SCHEMA`.`VIEWS` WHERE `TABLE_SCHEMA` = DATABASE() ORDER BY view_name");

}

/**
 * Generates SQL to query indexes on a table
 */
PHP_METHOD(Phalcon_Db_Dialect_Mysql, describeIndexes) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *table_param = NULL, *schema_param = NULL, _0;
	zval table, schema;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&table);
	ZVAL_UNDEF(&schema);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &table_param, &schema_param);

	if (UNEXPECTED(Z_TYPE_P(table_param) != IS_STRING && Z_TYPE_P(table_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'table' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(table_param) == IS_STRING)) {
		zephir_get_strval(&table, table_param);
	} else {
		ZEPHIR_INIT_VAR(&table);
		ZVAL_EMPTY_STRING(&table);
	}
	if (!schema_param) {
		ZEPHIR_INIT_VAR(&schema);
		ZVAL_STRING(&schema, "");
	} else {
		zephir_get_strval(&schema, schema_param);
	}


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "preparetable", NULL, 0, &table, &schema);
	zephir_check_call_status();
	ZEPHIR_CONCAT_SV(return_value, "SHOW INDEXES FROM ", &_0);
	RETURN_MM();

}

/**
 * Generates SQL to query foreign keys on a table
 */
PHP_METHOD(Phalcon_Db_Dialect_Mysql, describeReferences) {

	zval *table_param = NULL, *schema_param = NULL, sql;
	zval table, schema, _0$$3, _1$$4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&table);
	ZVAL_UNDEF(&schema);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&sql);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &table_param, &schema_param);

	if (UNEXPECTED(Z_TYPE_P(table_param) != IS_STRING && Z_TYPE_P(table_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'table' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(table_param) == IS_STRING)) {
		zephir_get_strval(&table, table_param);
	} else {
		ZEPHIR_INIT_VAR(&table);
		ZVAL_EMPTY_STRING(&table);
	}
	if (!schema_param) {
		ZEPHIR_INIT_VAR(&schema);
		ZVAL_STRING(&schema, "");
	} else {
		zephir_get_strval(&schema, schema_param);
	}


	ZEPHIR_INIT_VAR(&sql);
	ZVAL_STRING(&sql, "SELECT DISTINCT KCU.TABLE_NAME, KCU.COLUMN_NAME, KCU.CONSTRAINT_NAME, KCU.REFERENCED_TABLE_SCHEMA, KCU.REFERENCED_TABLE_NAME, KCU.REFERENCED_COLUMN_NAME, RC.UPDATE_RULE, RC.DELETE_RULE FROM INFORMATION_SCHEMA.KEY_COLUMN_USAGE AS KCU LEFT JOIN INFORMATION_SCHEMA.REFERENTIAL_CONSTRAINTS AS RC ON RC.CONSTRAINT_NAME = KCU.CONSTRAINT_NAME AND RC.CONSTRAINT_SCHEMA = KCU.CONSTRAINT_SCHEMA WHERE KCU.REFERENCED_TABLE_NAME IS NOT NULL AND ");
	if (!(Z_TYPE_P(&schema) == IS_UNDEF) && Z_STRLEN_P(&schema)) {
		ZEPHIR_INIT_VAR(&_0$$3);
		ZEPHIR_CONCAT_SVSVS(&_0$$3, "KCU.CONSTRAINT_SCHEMA = '", &schema, "' AND KCU.TABLE_NAME = '", &table, "'");
		zephir_concat_self(&sql, &_0$$3 TSRMLS_CC);
	} else {
		ZEPHIR_INIT_VAR(&_1$$4);
		ZEPHIR_CONCAT_SVS(&_1$$4, "KCU.CONSTRAINT_SCHEMA = DATABASE() AND KCU.TABLE_NAME = '", &table, "'");
		zephir_concat_self(&sql, &_1$$4 TSRMLS_CC);
	}
	RETURN_CCTOR(&sql);

}

/**
 * Generates the SQL to describe the table creation options
 */
PHP_METHOD(Phalcon_Db_Dialect_Mysql, tableOptions) {

	zval *table_param = NULL, *schema_param = NULL, sql;
	zval table, schema;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&table);
	ZVAL_UNDEF(&schema);
	ZVAL_UNDEF(&sql);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &table_param, &schema_param);

	if (UNEXPECTED(Z_TYPE_P(table_param) != IS_STRING && Z_TYPE_P(table_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'table' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(table_param) == IS_STRING)) {
		zephir_get_strval(&table, table_param);
	} else {
		ZEPHIR_INIT_VAR(&table);
		ZVAL_EMPTY_STRING(&table);
	}
	if (!schema_param) {
		ZEPHIR_INIT_VAR(&schema);
		ZVAL_STRING(&schema, "");
	} else {
		zephir_get_strval(&schema, schema_param);
	}


	ZEPHIR_INIT_VAR(&sql);
	ZVAL_STRING(&sql, "SELECT TABLES.TABLE_TYPE AS table_type,TABLES.AUTO_INCREMENT AS auto_increment,TABLES.ENGINE AS engine,TABLES.TABLE_COLLATION AS table_collation FROM INFORMATION_SCHEMA.TABLES WHERE ");
	if (!(Z_TYPE_P(&schema) == IS_UNDEF) && Z_STRLEN_P(&schema)) {
		ZEPHIR_CONCAT_VSVSVS(return_value, &sql, "TABLES.TABLE_SCHEMA = '", &schema, "' AND TABLES.TABLE_NAME = '", &table, "'");
		RETURN_MM();
	}
	ZEPHIR_CONCAT_VSVS(return_value, &sql, "TABLES.TABLE_SCHEMA = DATABASE() AND TABLES.TABLE_NAME = '", &table, "'");
	RETURN_MM();

}

/**
 * Generates SQL to add the table creation options
 */
PHP_METHOD(Phalcon_Db_Dialect_Mysql, _getTableOptions) {

	zval *definition_param = NULL, options, engine, autoIncrement, tableCollation, collationParts, tableOptions, _0$$5, _1$$7, _2$$9, _3$$9, _4$$9;
	zval definition;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&definition);
	ZVAL_UNDEF(&options);
	ZVAL_UNDEF(&engine);
	ZVAL_UNDEF(&autoIncrement);
	ZVAL_UNDEF(&tableCollation);
	ZVAL_UNDEF(&collationParts);
	ZVAL_UNDEF(&tableOptions);
	ZVAL_UNDEF(&_0$$5);
	ZVAL_UNDEF(&_1$$7);
	ZVAL_UNDEF(&_2$$9);
	ZVAL_UNDEF(&_3$$9);
	ZVAL_UNDEF(&_4$$9);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &definition_param);

	ZEPHIR_OBS_COPY_OR_DUP(&definition, definition_param);


	ZEPHIR_OBS_VAR(&options);
	if (zephir_array_isset_string_fetch(&options, &definition, SL("options"), 0)) {
		ZEPHIR_INIT_VAR(&tableOptions);
		array_init(&tableOptions);
		ZEPHIR_OBS_VAR(&engine);
		if (zephir_array_isset_string_fetch(&engine, &options, SL("ENGINE"), 0)) {
			if (zephir_is_true(&engine)) {
				ZEPHIR_INIT_VAR(&_0$$5);
				ZEPHIR_CONCAT_SV(&_0$$5, "ENGINE=", &engine);
				zephir_array_append(&tableOptions, &_0$$5, PH_SEPARATE, "phalcon/db/dialect/mysql.zep", 722);
			}
		}
		ZEPHIR_OBS_VAR(&autoIncrement);
		if (zephir_array_isset_string_fetch(&autoIncrement, &options, SL("AUTO_INCREMENT"), 0)) {
			if (zephir_is_true(&autoIncrement)) {
				ZEPHIR_INIT_VAR(&_1$$7);
				ZEPHIR_CONCAT_SV(&_1$$7, "AUTO_INCREMENT=", &autoIncrement);
				zephir_array_append(&tableOptions, &_1$$7, PH_SEPARATE, "phalcon/db/dialect/mysql.zep", 731);
			}
		}
		ZEPHIR_OBS_VAR(&tableCollation);
		if (zephir_array_isset_string_fetch(&tableCollation, &options, SL("TABLE_COLLATION"), 0)) {
			if (zephir_is_true(&tableCollation)) {
				ZEPHIR_INIT_VAR(&collationParts);
				zephir_fast_explode_str(&collationParts, SL("_"), &tableCollation, LONG_MAX TSRMLS_CC);
				zephir_array_fetch_long(&_2$$9, &collationParts, 0, PH_NOISY | PH_READONLY, "phalcon/db/dialect/mysql.zep", 741 TSRMLS_CC);
				ZEPHIR_INIT_VAR(&_3$$9);
				ZEPHIR_CONCAT_SV(&_3$$9, "DEFAULT CHARSET=", &_2$$9);
				zephir_array_append(&tableOptions, &_3$$9, PH_SEPARATE, "phalcon/db/dialect/mysql.zep", 741);
				ZEPHIR_INIT_VAR(&_4$$9);
				ZEPHIR_CONCAT_SV(&_4$$9, "COLLATE=", &tableCollation);
				zephir_array_append(&tableOptions, &_4$$9, PH_SEPARATE, "phalcon/db/dialect/mysql.zep", 742);
			}
		}
		if (zephir_fast_count_int(&tableOptions TSRMLS_CC)) {
			zephir_fast_join_str(return_value, SL(" "), &tableOptions TSRMLS_CC);
			RETURN_MM();
		}
	}
	RETURN_MM_STRING("");

}

/**
 * Generates SQL to check DB parameter FOREIGN_KEY_CHECKS.
 */
PHP_METHOD(Phalcon_Db_Dialect_Mysql, getForeignKeyChecks) {

	zval sql;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&sql);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&sql);
	ZVAL_STRING(&sql, "SELECT @@foreign_key_checks");
	RETURN_CCTOR(&sql);

}

/**
 * Returns a SQL modified with a LOCK IN SHARE MODE clause
 *
 *<code>
 * $sql = $dialect->sharedLock("SELECT * FROM robots");
 * echo $sql; // SELECT * FROM robots LOCK IN SHARE MODE
 *</code>
 */
PHP_METHOD(Phalcon_Db_Dialect_Mysql, sharedLock) {

	zval *sqlQuery_param = NULL;
	zval sqlQuery;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&sqlQuery);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &sqlQuery_param);

	if (UNEXPECTED(Z_TYPE_P(sqlQuery_param) != IS_STRING && Z_TYPE_P(sqlQuery_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'sqlQuery' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(sqlQuery_param) == IS_STRING)) {
		zephir_get_strval(&sqlQuery, sqlQuery_param);
	} else {
		ZEPHIR_INIT_VAR(&sqlQuery);
		ZVAL_EMPTY_STRING(&sqlQuery);
	}


	ZEPHIR_CONCAT_VS(return_value, &sqlQuery, " LOCK IN SHARE MODE");
	RETURN_MM();

}

/**
 * Checks if the size and/or scale are present and encloses those values
 * in parentheses if need be
 */
PHP_METHOD(Phalcon_Db_Dialect_Mysql, checkColumnSizeAndScale) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *column, column_sub, columnSql, _0, _1$$3, _2$$3, _3$$3, _4$$4, _5$$4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&column_sub);
	ZVAL_UNDEF(&columnSql);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_5$$4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &column);



	ZEPHIR_CALL_METHOD(&_0, column, "getsize", NULL, 0);
	zephir_check_call_status();
	if (zephir_is_true(&_0)) {
		ZEPHIR_CALL_METHOD(&_1$$3, column, "getsize", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_2$$3);
		ZEPHIR_CONCAT_SV(&_2$$3, "(", &_1$$3);
		zephir_concat_self(&columnSql, &_2$$3 TSRMLS_CC);
		ZEPHIR_CALL_METHOD(&_3$$3, column, "getscale", NULL, 0);
		zephir_check_call_status();
		if (zephir_is_true(&_3$$3)) {
			ZEPHIR_CALL_METHOD(&_4$$4, column, "getscale", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(&_5$$4);
			ZEPHIR_CONCAT_SVS(&_5$$4, ",", &_4$$4, ")");
			zephir_concat_self(&columnSql, &_5$$4 TSRMLS_CC);
		} else {
			zephir_concat_self_str(&columnSql, SL(")") TSRMLS_CC);
		}
	} else {
		zephir_concat_self_str(&columnSql, SL(")") TSRMLS_CC);
	}
	RETURN_CCTOR(&columnSql);

}

/**
 * Checks if a column is unsigned or not and returns the relevant SQL syntax
 */
PHP_METHOD(Phalcon_Db_Dialect_Mysql, checkColumnUnsigned) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *column, column_sub, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&column_sub);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &column);



	ZEPHIR_CALL_METHOD(&_0, column, "isunsigned", NULL, 0);
	zephir_check_call_status();
	if (zephir_is_true(&_0)) {
		RETURN_MM_STRING(" UNSIGNED");
	}
	RETURN_MM_STRING("");

}

