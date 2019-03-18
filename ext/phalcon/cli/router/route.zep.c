
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
#include "kernel/object.h"
#include "kernel/memory.h"
#include "kernel/operators.h"
#include "kernel/fcall.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/string.h"
#include "kernel/concat.h"
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
 * Phalcon\Cli\Router\Route
 *
 * This class represents every route added to the router
 */
ZEPHIR_INIT_CLASS(Phalcon_Cli_Router_Route) {

	ZEPHIR_REGISTER_CLASS(Phalcon\\Cli\\Router, Route, phalcon, cli_router_route, phalcon_cli_router_route_method_entry, 0);

	zend_declare_property_null(phalcon_cli_router_route_ce, SL("_pattern"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_cli_router_route_ce, SL("_compiledPattern"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_cli_router_route_ce, SL("_paths"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_cli_router_route_ce, SL("_converters"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_cli_router_route_ce, SL("_id"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_cli_router_route_ce, SL("_name"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_cli_router_route_ce, SL("_beforeMatch"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_cli_router_route_ce, SL("_delimiter"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_cli_router_route_ce, SL("_uniqueId"), ZEND_ACC_PROTECTED|ZEND_ACC_STATIC TSRMLS_CC);

	zend_declare_property_null(phalcon_cli_router_route_ce, SL("_delimiterPath"), ZEND_ACC_PROTECTED|ZEND_ACC_STATIC TSRMLS_CC);

	zephir_declare_class_constant_string(phalcon_cli_router_route_ce, SL("DEFAULT_DELIMITER"), " ");

	return SUCCESS;

}

/**
 * Phalcon\Cli\Router\Route constructor
 *
 * @param array paths
 */
PHP_METHOD(Phalcon_Cli_Router_Route, __construct) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *pattern_param = NULL, *paths = NULL, paths_sub, __$null, routeId, uniqueId, delimiter, _0;
	zval pattern;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&pattern);
	ZVAL_UNDEF(&paths_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&routeId);
	ZVAL_UNDEF(&uniqueId);
	ZVAL_UNDEF(&delimiter);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &pattern_param, &paths);

	if (UNEXPECTED(Z_TYPE_P(pattern_param) != IS_STRING && Z_TYPE_P(pattern_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'pattern' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(pattern_param) == IS_STRING)) {
		zephir_get_strval(&pattern, pattern_param);
	} else {
		ZEPHIR_INIT_VAR(&pattern);
		ZVAL_EMPTY_STRING(&pattern);
	}
	if (!paths) {
		paths = &paths_sub;
		paths = &__$null;
	}


	ZEPHIR_OBS_VAR(&delimiter);
	zephir_read_static_property_ce(&delimiter, phalcon_cli_router_route_ce, SL("_delimiterPath"), PH_NOISY_CC);
	if (!(zephir_is_true(&delimiter))) {
		ZEPHIR_INIT_NVAR(&delimiter);
		ZVAL_STRING(&delimiter, " ");
	}
	zephir_update_property_zval(this_ptr, SL("_delimiter"), &delimiter);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "reconfigure", NULL, 0, &pattern, paths);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(&uniqueId);
	zephir_read_static_property_ce(&uniqueId, phalcon_cli_router_route_ce, SL("_uniqueId"), PH_NOISY_CC);
	if (Z_TYPE_P(&uniqueId) == IS_NULL) {
		ZEPHIR_INIT_NVAR(&uniqueId);
		ZVAL_LONG(&uniqueId, 0);
	}
	ZEPHIR_CPY_WRT(&routeId, &uniqueId);
	zephir_update_property_zval(this_ptr, SL("_id"), &routeId);
	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(&_0, (zephir_get_numberval(&uniqueId) + 1));
	zend_update_static_property(phalcon_cli_router_route_ce, ZEND_STRL("_uniqueId"), &_0);
	ZEPHIR_MM_RESTORE();

}

/**
 * Replaces placeholders from pattern returning a valid PCRE regular expression
 */
PHP_METHOD(Phalcon_Cli_Router_Route, compilePattern) {

	zval *pattern_param = NULL, idPattern, part, _0$$3, _4$$3, _6$$3, _8$$3, _10$$3, _12$$3, _16$$3, _1$$4, _2$$4, _3$$4, _5$$5, _7$$6, _9$$7, _11$$8, _13$$9, _14$$9, _15$$9, _17$$10, _18$$10, _19$$10;
	zval pattern;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&pattern);
	ZVAL_UNDEF(&idPattern);
	ZVAL_UNDEF(&part);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_8$$3);
	ZVAL_UNDEF(&_10$$3);
	ZVAL_UNDEF(&_12$$3);
	ZVAL_UNDEF(&_16$$3);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&_7$$6);
	ZVAL_UNDEF(&_9$$7);
	ZVAL_UNDEF(&_11$$8);
	ZVAL_UNDEF(&_13$$9);
	ZVAL_UNDEF(&_14$$9);
	ZVAL_UNDEF(&_15$$9);
	ZVAL_UNDEF(&_17$$10);
	ZVAL_UNDEF(&_18$$10);
	ZVAL_UNDEF(&_19$$10);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &pattern_param);

	if (UNEXPECTED(Z_TYPE_P(pattern_param) != IS_STRING && Z_TYPE_P(pattern_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'pattern' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(pattern_param) == IS_STRING)) {
		zephir_get_strval(&pattern, pattern_param);
	} else {
		ZEPHIR_INIT_VAR(&pattern);
		ZVAL_EMPTY_STRING(&pattern);
	}


	if (zephir_memnstr_str(&pattern, SL(":"), "phalcon/cli/router/route.zep", 82)) {
		zephir_read_property(&_0$$3, this_ptr, SL("_delimiter"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_VAR(&idPattern);
		ZEPHIR_CONCAT_VS(&idPattern, &_0$$3, "([a-zA-Z0-9\\_\\-]+)");
		if (zephir_memnstr_str(&pattern, SL(":delimiter"), "phalcon/cli/router/route.zep", 88)) {
			ZEPHIR_INIT_VAR(&_1$$4);
			zephir_read_property(&_2$$4, this_ptr, SL("_delimiter"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_INIT_VAR(&_3$$4);
			ZVAL_STRING(&_3$$4, ":delimiter");
			zephir_fast_str_replace(&_1$$4, &_3$$4, &_2$$4, &pattern TSRMLS_CC);
			zephir_get_strval(&pattern, &_1$$4);
		}
		zephir_read_property(&_4$$3, this_ptr, SL("_delimiter"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_VAR(&part);
		ZEPHIR_CONCAT_VS(&part, &_4$$3, ":module");
		if (zephir_memnstr(&pattern, &part, "phalcon/cli/router/route.zep", 94)) {
			ZEPHIR_INIT_VAR(&_5$$5);
			zephir_fast_str_replace(&_5$$5, &part, &idPattern, &pattern TSRMLS_CC);
			zephir_get_strval(&pattern, &_5$$5);
		}
		zephir_read_property(&_6$$3, this_ptr, SL("_delimiter"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_NVAR(&part);
		ZEPHIR_CONCAT_VS(&part, &_6$$3, ":task");
		if (zephir_memnstr(&pattern, &part, "phalcon/cli/router/route.zep", 100)) {
			ZEPHIR_INIT_VAR(&_7$$6);
			zephir_fast_str_replace(&_7$$6, &part, &idPattern, &pattern TSRMLS_CC);
			zephir_get_strval(&pattern, &_7$$6);
		}
		zephir_read_property(&_8$$3, this_ptr, SL("_delimiter"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_NVAR(&part);
		ZEPHIR_CONCAT_VS(&part, &_8$$3, ":namespace");
		if (zephir_memnstr(&pattern, &part, "phalcon/cli/router/route.zep", 106)) {
			ZEPHIR_INIT_VAR(&_9$$7);
			zephir_fast_str_replace(&_9$$7, &part, &idPattern, &pattern TSRMLS_CC);
			zephir_get_strval(&pattern, &_9$$7);
		}
		zephir_read_property(&_10$$3, this_ptr, SL("_delimiter"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_NVAR(&part);
		ZEPHIR_CONCAT_VS(&part, &_10$$3, ":action");
		if (zephir_memnstr(&pattern, &part, "phalcon/cli/router/route.zep", 112)) {
			ZEPHIR_INIT_VAR(&_11$$8);
			zephir_fast_str_replace(&_11$$8, &part, &idPattern, &pattern TSRMLS_CC);
			zephir_get_strval(&pattern, &_11$$8);
		}
		zephir_read_property(&_12$$3, this_ptr, SL("_delimiter"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_NVAR(&part);
		ZEPHIR_CONCAT_VS(&part, &_12$$3, ":params");
		if (zephir_memnstr(&pattern, &part, "phalcon/cli/router/route.zep", 118)) {
			ZEPHIR_INIT_VAR(&_13$$9);
			zephir_read_property(&_14$$9, this_ptr, SL("_delimiter"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_INIT_VAR(&_15$$9);
			ZEPHIR_CONCAT_SVS(&_15$$9, "(", &_14$$9, ".*)*");
			zephir_fast_str_replace(&_13$$9, &part, &_15$$9, &pattern TSRMLS_CC);
			zephir_get_strval(&pattern, &_13$$9);
		}
		zephir_read_property(&_16$$3, this_ptr, SL("_delimiter"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_NVAR(&part);
		ZEPHIR_CONCAT_VS(&part, &_16$$3, ":int");
		if (zephir_memnstr(&pattern, &part, "phalcon/cli/router/route.zep", 124)) {
			ZEPHIR_INIT_VAR(&_17$$10);
			zephir_read_property(&_18$$10, this_ptr, SL("_delimiter"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_INIT_VAR(&_19$$10);
			ZEPHIR_CONCAT_VS(&_19$$10, &_18$$10, "([0-9]+)");
			zephir_fast_str_replace(&_17$$10, &part, &_19$$10, &pattern TSRMLS_CC);
			zephir_get_strval(&pattern, &_17$$10);
		}
	}
	if (zephir_memnstr_str(&pattern, SL("("), "phalcon/cli/router/route.zep", 130)) {
		ZEPHIR_CONCAT_SVS(return_value, "#^", &pattern, "$#");
		RETURN_MM();
	}
	if (zephir_memnstr_str(&pattern, SL("["), "phalcon/cli/router/route.zep", 135)) {
		ZEPHIR_CONCAT_SVS(return_value, "#^", &pattern, "$#");
		RETURN_MM();
	}
	RETURN_CTOR(&pattern);

}

/**
 * Extracts parameters from a string
 *
 * @return array|bool
 */
PHP_METHOD(Phalcon_Cli_Router_Route, extractNamedParams) {

	long _0, _5$$11, _26$$19;
	zend_bool notValid = 0, _6$$12, _7$$12, _8$$12, _9$$12, _10$$12, _11$$12, _12$$12, _13$$12, _14$$12, _15$$12, _16$$12, _17$$12, _25$$18;
	zend_long tmp = 0, cursor = 0, cursorVar = 0, marker = 0, bracketCount, parenthesesCount, foundPattern, intermediate, numberMatches;
	char ch = 0;
	zval *pattern_param = NULL, matches, _1$$11, _2$$11, _3$$11, _18$$16, _19$$16, _20$$16, _22$$16, _23$$16, _27$$19, _28$$28, _29$$28, _30$$28;
	zval pattern, route, item, variable, regexp, _4$$11, _21$$16, _24$$16;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&pattern);
	ZVAL_UNDEF(&route);
	ZVAL_UNDEF(&item);
	ZVAL_UNDEF(&variable);
	ZVAL_UNDEF(&regexp);
	ZVAL_UNDEF(&_4$$11);
	ZVAL_UNDEF(&_21$$16);
	ZVAL_UNDEF(&_24$$16);
	ZVAL_UNDEF(&matches);
	ZVAL_UNDEF(&_1$$11);
	ZVAL_UNDEF(&_2$$11);
	ZVAL_UNDEF(&_3$$11);
	ZVAL_UNDEF(&_18$$16);
	ZVAL_UNDEF(&_19$$16);
	ZVAL_UNDEF(&_20$$16);
	ZVAL_UNDEF(&_22$$16);
	ZVAL_UNDEF(&_23$$16);
	ZVAL_UNDEF(&_27$$19);
	ZVAL_UNDEF(&_28$$28);
	ZVAL_UNDEF(&_29$$28);
	ZVAL_UNDEF(&_30$$28);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &pattern_param);

	if (UNEXPECTED(Z_TYPE_P(pattern_param) != IS_STRING && Z_TYPE_P(pattern_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'pattern' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(pattern_param) == IS_STRING)) {
		zephir_get_strval(&pattern, pattern_param);
	} else {
		ZEPHIR_INIT_VAR(&pattern);
		ZVAL_EMPTY_STRING(&pattern);
	}


	bracketCount = 0;
	parenthesesCount = 0;
	foundPattern = 0;
	intermediate = 0;
	numberMatches = 0;
	if (zephir_fast_strlen_ev(&pattern) <= 0) {
		RETURN_MM_BOOL(0);
	}
	ZEPHIR_INIT_VAR(&matches);
	array_init(&matches);
	ZEPHIR_INIT_VAR(&route);
	ZVAL_STRING(&route, "");
	for (_0 = 0; _0 < Z_STRLEN_P(&pattern); _0++) {
		cursor = _0; 
		ch = ZEPHIR_STRING_OFFSET(&pattern, _0);
		if (parenthesesCount == 0) {
			if (ch == '{') {
				if (bracketCount == 0) {
					marker = (cursor + 1);
					intermediate = 0;
					notValid = 0;
				}
				bracketCount++;
			} else {
				if (ch == '}') {
					bracketCount--;
					if (intermediate > 0) {
						if (bracketCount == 0) {
							numberMatches++;
							ZEPHIR_INIT_NVAR(&variable);
							ZVAL_STRING(&variable, "");
							ZEPHIR_INIT_NVAR(&regexp);
							ZVAL_STRING(&regexp, "");
							ZVAL_LONG(&_1$$11, marker);
							ZVAL_LONG(&_2$$11, (cursor - marker));
							ZEPHIR_INIT_NVAR(&_3$$11);
							zephir_substr(&_3$$11, &pattern, zephir_get_intval(&_1$$11), zephir_get_intval(&_2$$11), 0);
							zephir_get_strval(&_4$$11, &_3$$11);
							ZEPHIR_CPY_WRT(&item, &_4$$11);
							for (_5$$11 = 0; _5$$11 < Z_STRLEN_P(&item); _5$$11++) {
								cursorVar = _5$$11; 
								ch = ZEPHIR_STRING_OFFSET(&item, _5$$11);
								if (ch == '\0') {
									break;
								}
								_6$$12 = cursorVar == 0;
								if (_6$$12) {
									_7$$12 = ch >= 'a';
									if (_7$$12) {
										_7$$12 = ch <= 'z';
									}
									_8$$12 = _7$$12;
									if (!(_8$$12)) {
										_9$$12 = ch >= 'A';
										if (_9$$12) {
											_9$$12 = ch <= 'Z';
										}
										_8$$12 = _9$$12;
									}
									_6$$12 = !(_8$$12);
								}
								if (_6$$12) {
									notValid = 1;
									break;
								}
								_10$$12 = ch >= 'a';
								if (_10$$12) {
									_10$$12 = ch <= 'z';
								}
								_11$$12 = _10$$12;
								if (!(_11$$12)) {
									_12$$12 = ch >= 'A';
									if (_12$$12) {
										_12$$12 = ch <= 'Z';
									}
									_11$$12 = _12$$12;
								}
								_13$$12 = _11$$12;
								if (!(_13$$12)) {
									_14$$12 = ch >= '0';
									if (_14$$12) {
										_14$$12 = ch <= '9';
									}
									_13$$12 = _14$$12;
								}
								_15$$12 = _13$$12;
								if (!(_15$$12)) {
									_15$$12 = ch == '-';
								}
								_16$$12 = _15$$12;
								if (!(_16$$12)) {
									_16$$12 = ch == '_';
								}
								_17$$12 = _16$$12;
								if (!(_17$$12)) {
									_17$$12 = ch == ':';
								}
								if (_17$$12) {
									if (ch == ':') {
										ZVAL_LONG(&_18$$16, 0);
										ZVAL_LONG(&_19$$16, cursorVar);
										ZEPHIR_INIT_NVAR(&_20$$16);
										zephir_substr(&_20$$16, &item, 0 , zephir_get_intval(&_19$$16), 0);
										zephir_get_strval(&_21$$16, &_20$$16);
										ZEPHIR_CPY_WRT(&variable, &_21$$16);
										ZVAL_LONG(&_22$$16, (cursorVar + 1));
										ZEPHIR_INIT_NVAR(&_23$$16);
										zephir_substr(&_23$$16, &item, zephir_get_intval(&_22$$16), 0, ZEPHIR_SUBSTR_NO_LENGTH);
										zephir_get_strval(&_24$$16, &_23$$16);
										ZEPHIR_CPY_WRT(&regexp, &_24$$16);
										break;
									}
								} else {
									notValid = 1;
									break;
								}
							}
							if (!(notValid)) {
								tmp = numberMatches;
								_25$$18 = zephir_is_true(&variable);
								if (_25$$18) {
									_25$$18 = zephir_is_true(&regexp);
								}
								if (_25$$18) {
									foundPattern = 0;
									for (_26$$19 = 0; _26$$19 < Z_STRLEN_P(&regexp); _26$$19++) {
										ch = ZEPHIR_STRING_OFFSET(&regexp, _26$$19);
										if (ch == '\0') {
											break;
										}
										if (!(foundPattern)) {
											if (ch == '(') {
												foundPattern = 1;
											}
										} else {
											if (ch == ')') {
												foundPattern = 2;
												break;
											}
										}
									}
									if (foundPattern != 2) {
										zephir_concat_self_str(&route, "(", sizeof("(")-1 TSRMLS_CC);
										zephir_concat_self(&route, &regexp TSRMLS_CC);
										zephir_concat_self_str(&route, ")", sizeof(")")-1 TSRMLS_CC);
									} else {
										zephir_concat_self(&route, &regexp TSRMLS_CC);
									}
									ZEPHIR_INIT_NVAR(&_27$$19);
									ZVAL_LONG(&_27$$19, tmp);
									zephir_array_update_zval(&matches, &variable, &_27$$19, PH_COPY | PH_SEPARATE);
								} else {
									zephir_read_property(&_28$$28, this_ptr, SL("_delimiter"), PH_NOISY_CC | PH_READONLY);
									ZEPHIR_INIT_LNVAR(_29$$28);
									ZEPHIR_CONCAT_SVS(&_29$$28, "([^", &_28$$28, "]*)");
									zephir_concat_self(&route, &_29$$28 TSRMLS_CC);
									ZEPHIR_INIT_NVAR(&_30$$28);
									ZVAL_LONG(&_30$$28, tmp);
									zephir_array_update_zval(&matches, &item, &_30$$28, PH_COPY | PH_SEPARATE);
								}
							} else {
								zephir_concat_self_str(&route, "{", sizeof("{")-1 TSRMLS_CC);
								zephir_concat_self(&route, &item TSRMLS_CC);
								zephir_concat_self_str(&route, "}", sizeof("}")-1 TSRMLS_CC);
							}
							continue;
						}
					}
				}
			}
		}
		if (bracketCount == 0) {
			if (ch == '(') {
				parenthesesCount++;
			} else {
				if (ch == ')') {
					parenthesesCount--;
					if (parenthesesCount == 0) {
						numberMatches++;
					}
				}
			}
		}
		if (bracketCount > 0) {
			intermediate++;
		} else {
			zephir_concat_self_char(&route, ch TSRMLS_CC);
		}
	}
	zephir_create_array(return_value, 2, 0 TSRMLS_CC);
	zephir_array_fast_append(return_value, &route);
	zephir_array_fast_append(return_value, &matches);
	RETURN_MM();

}

/**
 * Reconfigure the route adding a new pattern and a set of paths
 *
 * @param array paths
 */
PHP_METHOD(Phalcon_Cli_Router_Route, reConfigure) {

	zend_long ZEPHIR_LAST_CALL_STATUS, _0$$4;
	zval *pattern_param = NULL, *paths = NULL, paths_sub, __$null, moduleName, taskName, actionName, parts, routePaths, realClassName, namespaceName, pcrePattern, compiledPattern, extracted, _1$$9, _2$$18, _3$$18, _4$$21, _5$$21, _6$$21;
	zval pattern;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&pattern);
	ZVAL_UNDEF(&paths_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&moduleName);
	ZVAL_UNDEF(&taskName);
	ZVAL_UNDEF(&actionName);
	ZVAL_UNDEF(&parts);
	ZVAL_UNDEF(&routePaths);
	ZVAL_UNDEF(&realClassName);
	ZVAL_UNDEF(&namespaceName);
	ZVAL_UNDEF(&pcrePattern);
	ZVAL_UNDEF(&compiledPattern);
	ZVAL_UNDEF(&extracted);
	ZVAL_UNDEF(&_1$$9);
	ZVAL_UNDEF(&_2$$18);
	ZVAL_UNDEF(&_3$$18);
	ZVAL_UNDEF(&_4$$21);
	ZVAL_UNDEF(&_5$$21);
	ZVAL_UNDEF(&_6$$21);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &pattern_param, &paths);

	if (UNEXPECTED(Z_TYPE_P(pattern_param) != IS_STRING && Z_TYPE_P(pattern_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'pattern' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(pattern_param) == IS_STRING)) {
		zephir_get_strval(&pattern, pattern_param);
	} else {
		ZEPHIR_INIT_VAR(&pattern);
		ZVAL_EMPTY_STRING(&pattern);
	}
	if (!paths) {
		paths = &paths_sub;
		paths = &__$null;
	}


	if (Z_TYPE_P(paths) != IS_NULL) {
		if (Z_TYPE_P(paths) == IS_STRING) {
			ZEPHIR_INIT_VAR(&moduleName);
			ZVAL_NULL(&moduleName);
			ZEPHIR_INIT_VAR(&taskName);
			ZVAL_NULL(&taskName);
			ZEPHIR_INIT_VAR(&actionName);
			ZVAL_NULL(&actionName);
			ZEPHIR_INIT_VAR(&parts);
			zephir_fast_explode_str(&parts, SL("::"), paths, LONG_MAX TSRMLS_CC);
			do {
				_0$$4 = zephir_fast_count_int(&parts TSRMLS_CC);
				if (_0$$4 == 3) {
					ZEPHIR_OBS_NVAR(&moduleName);
					zephir_array_fetch_long(&moduleName, &parts, 0, PH_NOISY, "phalcon/cli/router/route.zep", 304 TSRMLS_CC);
					ZEPHIR_OBS_NVAR(&taskName);
					zephir_array_fetch_long(&taskName, &parts, 1, PH_NOISY, "phalcon/cli/router/route.zep", 305 TSRMLS_CC);
					ZEPHIR_OBS_NVAR(&actionName);
					zephir_array_fetch_long(&actionName, &parts, 2, PH_NOISY, "phalcon/cli/router/route.zep", 306 TSRMLS_CC);
					break;
				}
				if (_0$$4 == 2) {
					ZEPHIR_OBS_NVAR(&taskName);
					zephir_array_fetch_long(&taskName, &parts, 0, PH_NOISY, "phalcon/cli/router/route.zep", 310 TSRMLS_CC);
					ZEPHIR_OBS_NVAR(&actionName);
					zephir_array_fetch_long(&actionName, &parts, 1, PH_NOISY, "phalcon/cli/router/route.zep", 311 TSRMLS_CC);
					break;
				}
				if (_0$$4 == 1) {
					ZEPHIR_OBS_NVAR(&taskName);
					zephir_array_fetch_long(&taskName, &parts, 0, PH_NOISY, "phalcon/cli/router/route.zep", 315 TSRMLS_CC);
					break;
				}
			} while(0);

			ZEPHIR_INIT_VAR(&routePaths);
			array_init(&routePaths);
			if (Z_TYPE_P(&moduleName) != IS_NULL) {
				zephir_array_update_string(&routePaths, SL("module"), &moduleName, PH_COPY | PH_SEPARATE);
			}
			if (Z_TYPE_P(&taskName) != IS_NULL) {
				if (zephir_memnstr_str(&taskName, SL("\\"), "phalcon/cli/router/route.zep", 330)) {
					ZEPHIR_INIT_VAR(&realClassName);
					zephir_get_class_ns(&realClassName, &taskName, 0 TSRMLS_CC);
					ZEPHIR_INIT_VAR(&namespaceName);
					zephir_get_ns_class(&namespaceName, &taskName, 0 TSRMLS_CC);
					if (zephir_is_true(&namespaceName)) {
						zephir_array_update_string(&routePaths, SL("namespace"), &namespaceName, PH_COPY | PH_SEPARATE);
					}
				} else {
					ZEPHIR_CPY_WRT(&realClassName, &taskName);
				}
				ZEPHIR_INIT_VAR(&_1$$9);
				zephir_uncamelize(&_1$$9, &realClassName, NULL  );
				zephir_array_update_string(&routePaths, SL("task"), &_1$$9, PH_COPY | PH_SEPARATE);
			}
			if (Z_TYPE_P(&actionName) != IS_NULL) {
				zephir_array_update_string(&routePaths, SL("action"), &actionName, PH_COPY | PH_SEPARATE);
			}
		} else {
			ZEPHIR_CPY_WRT(&routePaths, paths);
		}
	} else {
		ZEPHIR_INIT_NVAR(&routePaths);
		array_init(&routePaths);
	}
	if (Z_TYPE_P(&routePaths) != IS_ARRAY) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_cli_router_exception_ce, "The route contains invalid paths", "phalcon/cli/router/route.zep", 362);
		return;
	}
	if (!(zephir_start_with_str(&pattern, SL("#")))) {
		if (zephir_memnstr_str(&pattern, SL("{"), "phalcon/cli/router/route.zep", 370)) {
			ZEPHIR_CALL_METHOD(&extracted, this_ptr, "extractnamedparams", NULL, 0, &pattern);
			zephir_check_call_status();
			ZEPHIR_OBS_VAR(&pcrePattern);
			zephir_array_fetch_long(&pcrePattern, &extracted, 0, PH_NOISY, "phalcon/cli/router/route.zep", 375 TSRMLS_CC);
			ZEPHIR_INIT_VAR(&_2$$18);
			zephir_array_fetch_long(&_3$$18, &extracted, 1, PH_NOISY | PH_READONLY, "phalcon/cli/router/route.zep", 376 TSRMLS_CC);
			zephir_fast_array_merge(&_2$$18, &routePaths, &_3$$18 TSRMLS_CC);
			ZEPHIR_CPY_WRT(&routePaths, &_2$$18);
		} else {
			ZEPHIR_CPY_WRT(&pcrePattern, &pattern);
		}
		ZEPHIR_CALL_METHOD(&compiledPattern, this_ptr, "compilepattern", NULL, 0, &pcrePattern);
		zephir_check_call_status();
	} else {
		if (zephir_memnstr_str(&pattern, SL(":delimiter"), "phalcon/cli/router/route.zep", 387)) {
			ZEPHIR_INIT_VAR(&_4$$21);
			zephir_read_property(&_5$$21, this_ptr, SL("_delimiter"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_INIT_VAR(&_6$$21);
			ZVAL_STRING(&_6$$21, ":delimiter");
			zephir_fast_str_replace(&_4$$21, &_6$$21, &_5$$21, &pattern TSRMLS_CC);
			zephir_get_strval(&pattern, &_4$$21);
		}
		ZEPHIR_CPY_WRT(&compiledPattern, &pattern);
	}
	zephir_update_property_zval(this_ptr, SL("_pattern"), &pattern);
	zephir_update_property_zval(this_ptr, SL("_compiledPattern"), &compiledPattern);
	zephir_update_property_zval(this_ptr, SL("_paths"), &routePaths);
	ZEPHIR_MM_RESTORE();

}

/**
 * Returns the route's name
 */
PHP_METHOD(Phalcon_Cli_Router_Route, getName) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "_name");

}

/**
 * Sets the route's name
 *
 *<code>
 * $router->add(
 *     "/about",
 *     [
 *         "controller" => "about",
 *     ]
 * )->setName("about");
 *</code>
 */
PHP_METHOD(Phalcon_Cli_Router_Route, setName) {

	zval *name_param = NULL;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

	if (UNEXPECTED(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(name_param) == IS_STRING)) {
		zephir_get_strval(&name, name_param);
	} else {
		ZEPHIR_INIT_VAR(&name);
		ZVAL_EMPTY_STRING(&name);
	}


	zephir_update_property_zval(this_ptr, SL("_name"), &name);
	RETURN_THIS();

}

/**
 * Sets a callback that is called if the route is matched.
 * The developer can implement any arbitrary conditions here
 * If the callback returns false the route is treated as not matched
 *
 * @param callback callback
 */
PHP_METHOD(Phalcon_Cli_Router_Route, beforeMatch) {

	zval *callback, callback_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&callback_sub);

	zephir_fetch_params(0, 1, 0, &callback);



	zephir_update_property_zval(this_ptr, SL("_beforeMatch"), callback);
	RETURN_THISW();

}

/**
 * Returns the 'before match' callback if any
 *
 * @return mixed
 */
PHP_METHOD(Phalcon_Cli_Router_Route, getBeforeMatch) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "_beforeMatch");

}

/**
 * Returns the route's id
 */
PHP_METHOD(Phalcon_Cli_Router_Route, getRouteId) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "_id");

}

/**
 * Returns the route's pattern
 */
PHP_METHOD(Phalcon_Cli_Router_Route, getPattern) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "_pattern");

}

/**
 * Returns the route's compiled pattern
 */
PHP_METHOD(Phalcon_Cli_Router_Route, getCompiledPattern) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "_compiledPattern");

}

/**
 * Returns the paths
 */
PHP_METHOD(Phalcon_Cli_Router_Route, getPaths) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "_paths");

}

/**
 * Returns the paths using positions as keys and names as values
 */
PHP_METHOD(Phalcon_Cli_Router_Route, getReversedPaths) {

	zend_string *_4;
	zend_ulong _3;
	zval reversed, path, position, _0, *_1, _2;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&reversed);
	ZVAL_UNDEF(&path);
	ZVAL_UNDEF(&position);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&reversed);
	array_init(&reversed);
	zephir_read_property(&_0, this_ptr, SL("_paths"), PH_NOISY_CC | PH_READONLY);
	zephir_is_iterable(&_0, 0, "phalcon/cli/router/route.zep", 501);
	if (Z_TYPE_P(&_0) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&_0), _3, _4, _1)
		{
			ZEPHIR_INIT_NVAR(&path);
			if (_4 != NULL) { 
				ZVAL_STR_COPY(&path, _4);
			} else {
				ZVAL_LONG(&path, _3);
			}
			ZEPHIR_INIT_NVAR(&position);
			ZVAL_COPY(&position, _1);
			zephir_array_update_zval(&reversed, &position, &path, PH_COPY | PH_SEPARATE);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &_0, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_2, &_0, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_2)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&path, &_0, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&position, &_0, "current", NULL, 0);
			zephir_check_call_status();
				zephir_array_update_zval(&reversed, &position, &path, PH_COPY | PH_SEPARATE);
			ZEPHIR_CALL_METHOD(NULL, &_0, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&position);
	ZEPHIR_INIT_NVAR(&path);
	RETURN_CCTOR(&reversed);

}

/**
 * Adds a converter to perform an additional transformation for certain parameter
 *
 * @param callable converter
 */
PHP_METHOD(Phalcon_Cli_Router_Route, convert) {

	zval *name_param = NULL, *converter, converter_sub;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&converter_sub);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &name_param, &converter);

	if (UNEXPECTED(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(name_param) == IS_STRING)) {
		zephir_get_strval(&name, name_param);
	} else {
		ZEPHIR_INIT_VAR(&name);
		ZVAL_EMPTY_STRING(&name);
	}


	zephir_update_property_array(this_ptr, SL("_converters"), &name, converter);
	RETURN_THIS();

}

/**
 * Returns the router converter
 */
PHP_METHOD(Phalcon_Cli_Router_Route, getConverters) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "_converters");

}

/**
 * Resets the internal route id generator
 */
PHP_METHOD(Phalcon_Cli_Router_Route, reset) {

	zval __$null;
	zval *this_ptr = getThis();

	ZVAL_NULL(&__$null);


	zend_update_static_property(phalcon_cli_router_route_ce, ZEND_STRL("_uniqueId"), &__$null);

}

/**
 * Set the routing delimiter
 */
PHP_METHOD(Phalcon_Cli_Router_Route, delimiter) {

	zval *delimiter_param = NULL;
	zval delimiter;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&delimiter);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &delimiter_param);

	if (!delimiter_param) {
		ZEPHIR_INIT_VAR(&delimiter);
		ZVAL_STRING(&delimiter, "");
	} else {
	if (UNEXPECTED(Z_TYPE_P(delimiter_param) != IS_STRING && Z_TYPE_P(delimiter_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'delimiter' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(delimiter_param) == IS_STRING)) {
		zephir_get_strval(&delimiter, delimiter_param);
	} else {
		ZEPHIR_INIT_VAR(&delimiter);
		ZVAL_EMPTY_STRING(&delimiter);
	}
	}


	zend_update_static_property(phalcon_cli_router_route_ce, ZEND_STRL("_delimiterPath"), &delimiter);
	ZEPHIR_MM_RESTORE();

}

/**
 * Get routing delimiter
 */
PHP_METHOD(Phalcon_Cli_Router_Route, getDelimiter) {

	zval delimiter;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&delimiter);

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(&delimiter);
	zephir_read_static_property_ce(&delimiter, phalcon_cli_router_route_ce, SL("_delimiterPath"), PH_NOISY_CC);
	if (!(zephir_is_true(&delimiter))) {
		ZEPHIR_INIT_NVAR(&delimiter);
		ZVAL_STRING(&delimiter, " ");
	}
	RETURN_CCTOR(&delimiter);

}

