
extern zend_class_entry *phalcon_db_dialect_ce;

ZEPHIR_INIT_CLASS(Phalcon_Db_Dialect);

PHP_METHOD(Phalcon_Db_Dialect, registerCustomFunction);
PHP_METHOD(Phalcon_Db_Dialect, getCustomFunctions);
PHP_METHOD(Phalcon_Db_Dialect, escape);
PHP_METHOD(Phalcon_Db_Dialect, limit);
PHP_METHOD(Phalcon_Db_Dialect, forUpdate);
PHP_METHOD(Phalcon_Db_Dialect, sharedLock);
PHP_METHOD(Phalcon_Db_Dialect, getColumnList);
PHP_METHOD(Phalcon_Db_Dialect, getSqlColumn);
PHP_METHOD(Phalcon_Db_Dialect, getSqlExpression);
PHP_METHOD(Phalcon_Db_Dialect, getSqlTable);
PHP_METHOD(Phalcon_Db_Dialect, select);
PHP_METHOD(Phalcon_Db_Dialect, supportsSavepoints);
PHP_METHOD(Phalcon_Db_Dialect, supportsReleaseSavepoints);
PHP_METHOD(Phalcon_Db_Dialect, createSavepoint);
PHP_METHOD(Phalcon_Db_Dialect, releaseSavepoint);
PHP_METHOD(Phalcon_Db_Dialect, rollbackSavepoint);
PHP_METHOD(Phalcon_Db_Dialect, getSqlExpressionScalar);
PHP_METHOD(Phalcon_Db_Dialect, getSqlExpressionObject);
PHP_METHOD(Phalcon_Db_Dialect, getSqlExpressionQualified);
PHP_METHOD(Phalcon_Db_Dialect, getSqlExpressionBinaryOperations);
PHP_METHOD(Phalcon_Db_Dialect, getSqlExpressionUnaryOperations);
PHP_METHOD(Phalcon_Db_Dialect, getSqlExpressionFunctionCall);
PHP_METHOD(Phalcon_Db_Dialect, getSqlExpressionList);
PHP_METHOD(Phalcon_Db_Dialect, getSqlExpressionAll);
PHP_METHOD(Phalcon_Db_Dialect, getSqlExpressionCastValue);
PHP_METHOD(Phalcon_Db_Dialect, getSqlExpressionConvertValue);
PHP_METHOD(Phalcon_Db_Dialect, getSqlExpressionCase);
PHP_METHOD(Phalcon_Db_Dialect, getSqlExpressionFrom);
PHP_METHOD(Phalcon_Db_Dialect, getSqlExpressionJoins);
PHP_METHOD(Phalcon_Db_Dialect, getSqlExpressionWhere);
PHP_METHOD(Phalcon_Db_Dialect, getSqlExpressionGroupBy);
PHP_METHOD(Phalcon_Db_Dialect, getSqlExpressionHaving);
PHP_METHOD(Phalcon_Db_Dialect, getSqlExpressionOrderBy);
PHP_METHOD(Phalcon_Db_Dialect, getSqlExpressionLimit);
PHP_METHOD(Phalcon_Db_Dialect, prepareColumnAlias);
PHP_METHOD(Phalcon_Db_Dialect, prepareTable);
PHP_METHOD(Phalcon_Db_Dialect, prepareQualified);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialect_registercustomfunction, 0, 0, 2)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, customFunction)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialect_escape, 0, 0, 1)
	ZEND_ARG_INFO(0, str)
	ZEND_ARG_INFO(0, escapeChar)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialect_limit, 0, 0, 2)
	ZEND_ARG_INFO(0, sqlQuery)
	ZEND_ARG_INFO(0, number)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialect_forupdate, 0, 0, 1)
	ZEND_ARG_INFO(0, sqlQuery)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialect_sharedlock, 0, 0, 1)
	ZEND_ARG_INFO(0, sqlQuery)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialect_getcolumnlist, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, columnList, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialect_getsqlcolumn, 0, 0, 1)
	ZEND_ARG_INFO(0, column)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialect_getsqlexpression, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, expression, 0)
	ZEND_ARG_INFO(0, escapeChar)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialect_getsqltable, 0, 0, 1)
	ZEND_ARG_INFO(0, table)
	ZEND_ARG_INFO(0, escapeChar)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialect_select, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, definition, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialect_createsavepoint, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialect_releasesavepoint, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialect_rollbacksavepoint, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialect_getsqlexpressionscalar, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, expression, 0)
	ZEND_ARG_INFO(0, escapeChar)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialect_getsqlexpressionobject, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, expression, 0)
	ZEND_ARG_INFO(0, escapeChar)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialect_getsqlexpressionqualified, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, expression, 0)
	ZEND_ARG_INFO(0, escapeChar)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialect_getsqlexpressionbinaryoperations, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, expression, 0)
	ZEND_ARG_INFO(0, escapeChar)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialect_getsqlexpressionunaryoperations, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, expression, 0)
	ZEND_ARG_INFO(0, escapeChar)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialect_getsqlexpressionfunctioncall, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, expression, 0)
	ZEND_ARG_INFO(0, escapeChar)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialect_getsqlexpressionlist, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, expression, 0)
	ZEND_ARG_INFO(0, escapeChar)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialect_getsqlexpressionall, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, expression, 0)
	ZEND_ARG_INFO(0, escapeChar)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialect_getsqlexpressioncastvalue, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, expression, 0)
	ZEND_ARG_INFO(0, escapeChar)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialect_getsqlexpressionconvertvalue, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, expression, 0)
	ZEND_ARG_INFO(0, escapeChar)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialect_getsqlexpressioncase, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, expression, 0)
	ZEND_ARG_INFO(0, escapeChar)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialect_getsqlexpressionfrom, 0, 0, 1)
	ZEND_ARG_INFO(0, expression)
	ZEND_ARG_INFO(0, escapeChar)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialect_getsqlexpressionjoins, 0, 0, 1)
	ZEND_ARG_INFO(0, expression)
	ZEND_ARG_INFO(0, escapeChar)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialect_getsqlexpressionwhere, 0, 0, 1)
	ZEND_ARG_INFO(0, expression)
	ZEND_ARG_INFO(0, escapeChar)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialect_getsqlexpressiongroupby, 0, 0, 1)
	ZEND_ARG_INFO(0, expression)
	ZEND_ARG_INFO(0, escapeChar)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialect_getsqlexpressionhaving, 0, 0, 1)
	ZEND_ARG_INFO(0, expression)
	ZEND_ARG_INFO(0, escapeChar)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialect_getsqlexpressionorderby, 0, 0, 1)
	ZEND_ARG_INFO(0, expression)
	ZEND_ARG_INFO(0, escapeChar)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialect_getsqlexpressionlimit, 0, 0, 1)
	ZEND_ARG_INFO(0, expression)
	ZEND_ARG_INFO(0, escapeChar)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialect_preparecolumnalias, 0, 0, 1)
	ZEND_ARG_INFO(0, qualified)
	ZEND_ARG_INFO(0, alias)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialect_preparetable, 0, 0, 1)
	ZEND_ARG_INFO(0, table)
	ZEND_ARG_INFO(0, schema)
	ZEND_ARG_INFO(0, alias)
	ZEND_ARG_INFO(0, escapeChar)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialect_preparequalified, 0, 0, 1)
	ZEND_ARG_INFO(0, column)
	ZEND_ARG_INFO(0, domain)
	ZEND_ARG_INFO(0, escapeChar)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_db_dialect_method_entry) {
	PHP_ME(Phalcon_Db_Dialect, registerCustomFunction, arginfo_phalcon_db_dialect_registercustomfunction, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Dialect, getCustomFunctions, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Dialect, escape, arginfo_phalcon_db_dialect_escape, ZEND_ACC_PUBLIC|ZEND_ACC_FINAL)
	PHP_ME(Phalcon_Db_Dialect, limit, arginfo_phalcon_db_dialect_limit, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Dialect, forUpdate, arginfo_phalcon_db_dialect_forupdate, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Dialect, sharedLock, arginfo_phalcon_db_dialect_sharedlock, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Dialect, getColumnList, arginfo_phalcon_db_dialect_getcolumnlist, ZEND_ACC_PUBLIC|ZEND_ACC_FINAL)
	PHP_ME(Phalcon_Db_Dialect, getSqlColumn, arginfo_phalcon_db_dialect_getsqlcolumn, ZEND_ACC_PUBLIC|ZEND_ACC_FINAL)
	PHP_ME(Phalcon_Db_Dialect, getSqlExpression, arginfo_phalcon_db_dialect_getsqlexpression, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Dialect, getSqlTable, arginfo_phalcon_db_dialect_getsqltable, ZEND_ACC_PUBLIC|ZEND_ACC_FINAL)
	PHP_ME(Phalcon_Db_Dialect, select, arginfo_phalcon_db_dialect_select, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Dialect, supportsSavepoints, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Dialect, supportsReleaseSavepoints, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Dialect, createSavepoint, arginfo_phalcon_db_dialect_createsavepoint, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Dialect, releaseSavepoint, arginfo_phalcon_db_dialect_releasesavepoint, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Dialect, rollbackSavepoint, arginfo_phalcon_db_dialect_rollbacksavepoint, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Dialect, getSqlExpressionScalar, arginfo_phalcon_db_dialect_getsqlexpressionscalar, ZEND_ACC_PROTECTED|ZEND_ACC_FINAL)
	PHP_ME(Phalcon_Db_Dialect, getSqlExpressionObject, arginfo_phalcon_db_dialect_getsqlexpressionobject, ZEND_ACC_PROTECTED|ZEND_ACC_FINAL)
	PHP_ME(Phalcon_Db_Dialect, getSqlExpressionQualified, arginfo_phalcon_db_dialect_getsqlexpressionqualified, ZEND_ACC_PROTECTED|ZEND_ACC_FINAL)
	PHP_ME(Phalcon_Db_Dialect, getSqlExpressionBinaryOperations, arginfo_phalcon_db_dialect_getsqlexpressionbinaryoperations, ZEND_ACC_PROTECTED|ZEND_ACC_FINAL)
	PHP_ME(Phalcon_Db_Dialect, getSqlExpressionUnaryOperations, arginfo_phalcon_db_dialect_getsqlexpressionunaryoperations, ZEND_ACC_PROTECTED|ZEND_ACC_FINAL)
	PHP_ME(Phalcon_Db_Dialect, getSqlExpressionFunctionCall, arginfo_phalcon_db_dialect_getsqlexpressionfunctioncall, ZEND_ACC_PROTECTED|ZEND_ACC_FINAL)
	PHP_ME(Phalcon_Db_Dialect, getSqlExpressionList, arginfo_phalcon_db_dialect_getsqlexpressionlist, ZEND_ACC_PROTECTED|ZEND_ACC_FINAL)
	PHP_ME(Phalcon_Db_Dialect, getSqlExpressionAll, arginfo_phalcon_db_dialect_getsqlexpressionall, ZEND_ACC_PROTECTED|ZEND_ACC_FINAL)
	PHP_ME(Phalcon_Db_Dialect, getSqlExpressionCastValue, arginfo_phalcon_db_dialect_getsqlexpressioncastvalue, ZEND_ACC_PROTECTED|ZEND_ACC_FINAL)
	PHP_ME(Phalcon_Db_Dialect, getSqlExpressionConvertValue, arginfo_phalcon_db_dialect_getsqlexpressionconvertvalue, ZEND_ACC_PROTECTED|ZEND_ACC_FINAL)
	PHP_ME(Phalcon_Db_Dialect, getSqlExpressionCase, arginfo_phalcon_db_dialect_getsqlexpressioncase, ZEND_ACC_PROTECTED|ZEND_ACC_FINAL)
	PHP_ME(Phalcon_Db_Dialect, getSqlExpressionFrom, arginfo_phalcon_db_dialect_getsqlexpressionfrom, ZEND_ACC_PROTECTED|ZEND_ACC_FINAL)
	PHP_ME(Phalcon_Db_Dialect, getSqlExpressionJoins, arginfo_phalcon_db_dialect_getsqlexpressionjoins, ZEND_ACC_PROTECTED|ZEND_ACC_FINAL)
	PHP_ME(Phalcon_Db_Dialect, getSqlExpressionWhere, arginfo_phalcon_db_dialect_getsqlexpressionwhere, ZEND_ACC_PROTECTED|ZEND_ACC_FINAL)
	PHP_ME(Phalcon_Db_Dialect, getSqlExpressionGroupBy, arginfo_phalcon_db_dialect_getsqlexpressiongroupby, ZEND_ACC_PROTECTED|ZEND_ACC_FINAL)
	PHP_ME(Phalcon_Db_Dialect, getSqlExpressionHaving, arginfo_phalcon_db_dialect_getsqlexpressionhaving, ZEND_ACC_PROTECTED|ZEND_ACC_FINAL)
	PHP_ME(Phalcon_Db_Dialect, getSqlExpressionOrderBy, arginfo_phalcon_db_dialect_getsqlexpressionorderby, ZEND_ACC_PROTECTED|ZEND_ACC_FINAL)
	PHP_ME(Phalcon_Db_Dialect, getSqlExpressionLimit, arginfo_phalcon_db_dialect_getsqlexpressionlimit, ZEND_ACC_PROTECTED|ZEND_ACC_FINAL)
	PHP_ME(Phalcon_Db_Dialect, prepareColumnAlias, arginfo_phalcon_db_dialect_preparecolumnalias, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Db_Dialect, prepareTable, arginfo_phalcon_db_dialect_preparetable, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Db_Dialect, prepareQualified, arginfo_phalcon_db_dialect_preparequalified, ZEND_ACC_PROTECTED)
	PHP_FE_END
};
