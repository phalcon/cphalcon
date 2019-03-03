
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
#include "kernel/fcall.h"
#include "kernel/memory.h"
#include "kernel/operators.h"
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
 * Phalcon\Mvc\Router\Route
 *
 * This class represents every route added to the router
 */
ZEPHIR_INIT_CLASS(Phalcon_Mvc_Router_Route) {

	ZEPHIR_REGISTER_CLASS(Phalcon\\Mvc\\Router, Route, phalcon, mvc_router_route, phalcon_mvc_router_route_method_entry, 0);

	zend_declare_property_null(phalcon_mvc_router_route_ce, SL("_pattern"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_mvc_router_route_ce, SL("_compiledPattern"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_mvc_router_route_ce, SL("_paths"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_mvc_router_route_ce, SL("_methods"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_mvc_router_route_ce, SL("_hostname"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_mvc_router_route_ce, SL("_converters"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_mvc_router_route_ce, SL("_id"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_mvc_router_route_ce, SL("_name"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_mvc_router_route_ce, SL("_beforeMatch"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_mvc_router_route_ce, SL("_match"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_mvc_router_route_ce, SL("_group"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_mvc_router_route_ce, SL("_uniqueId"), ZEND_ACC_PROTECTED|ZEND_ACC_STATIC TSRMLS_CC);

	zend_class_implements(phalcon_mvc_router_route_ce TSRMLS_CC, 1, phalcon_mvc_router_routeinterface_ce);
	return SUCCESS;

}

PHP_METHOD(Phalcon_Mvc_Router_Route, getId) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "_id");

}

/**
 * Phalcon\Mvc\Router\Route constructor
 */
PHP_METHOD(Phalcon_Mvc_Router_Route, __construct) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *pattern_param = NULL, *paths = NULL, paths_sub, *httpMethods = NULL, httpMethods_sub, __$null, routeId, uniqueId, _0;
	zval pattern;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&pattern);
	ZVAL_UNDEF(&paths_sub);
	ZVAL_UNDEF(&httpMethods_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&routeId);
	ZVAL_UNDEF(&uniqueId);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &pattern_param, &paths, &httpMethods);

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
	if (!httpMethods) {
		httpMethods = &httpMethods_sub;
		httpMethods = &__$null;
	}


	ZEPHIR_CALL_METHOD(NULL, this_ptr, "reconfigure", NULL, 0, &pattern, paths);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, SL("_methods"), httpMethods);
	ZEPHIR_OBS_VAR(&uniqueId);
	zephir_read_static_property_ce(&uniqueId, phalcon_mvc_router_route_ce, SL("_uniqueId"), PH_NOISY_CC);
	if (Z_TYPE_P(&uniqueId) == IS_NULL) {
		ZEPHIR_INIT_NVAR(&uniqueId);
		ZVAL_LONG(&uniqueId, 0);
	}
	ZEPHIR_CPY_WRT(&routeId, &uniqueId);
	zephir_update_property_zval(this_ptr, SL("_id"), &routeId);
	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(&_0, (zephir_get_numberval(&uniqueId) + 1));
	zend_update_static_property(phalcon_mvc_router_route_ce, ZEND_STRL("_uniqueId"), &_0);
	ZEPHIR_MM_RESTORE();

}

/**
 * Replaces placeholders from pattern returning a valid PCRE regular expression
 */
PHP_METHOD(Phalcon_Mvc_Router_Route, compilePattern) {

	zval *pattern_param = NULL, idPattern, _0$$4, _1$$4, _2$$5, _3$$5, _4$$6, _5$$6, _6$$7, _7$$7, _8$$8, _9$$8, _10$$8, _11$$9, _12$$9, _13$$9;
	zval pattern;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&pattern);
	ZVAL_UNDEF(&idPattern);
	ZVAL_UNDEF(&_0$$4);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&_2$$5);
	ZVAL_UNDEF(&_3$$5);
	ZVAL_UNDEF(&_4$$6);
	ZVAL_UNDEF(&_5$$6);
	ZVAL_UNDEF(&_6$$7);
	ZVAL_UNDEF(&_7$$7);
	ZVAL_UNDEF(&_8$$8);
	ZVAL_UNDEF(&_9$$8);
	ZVAL_UNDEF(&_10$$8);
	ZVAL_UNDEF(&_11$$9);
	ZVAL_UNDEF(&_12$$9);
	ZVAL_UNDEF(&_13$$9);

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


	if (zephir_memnstr_str(&pattern, SL(":"), "phalcon/mvc/router/route.zep", 80)) {
		ZEPHIR_INIT_VAR(&idPattern);
		ZVAL_STRING(&idPattern, "/([\\w0-9\\_\\-]+)");
		if (zephir_memnstr_str(&pattern, SL("/:module"), "phalcon/mvc/router/route.zep", 86)) {
			ZEPHIR_INIT_VAR(&_0$$4);
			ZEPHIR_INIT_VAR(&_1$$4);
			ZVAL_STRING(&_1$$4, "/:module");
			zephir_fast_str_replace(&_0$$4, &_1$$4, &idPattern, &pattern TSRMLS_CC);
			zephir_get_strval(&pattern, &_0$$4);
		}
		if (zephir_memnstr_str(&pattern, SL("/:controller"), "phalcon/mvc/router/route.zep", 91)) {
			ZEPHIR_INIT_VAR(&_2$$5);
			ZEPHIR_INIT_VAR(&_3$$5);
			ZVAL_STRING(&_3$$5, "/:controller");
			zephir_fast_str_replace(&_2$$5, &_3$$5, &idPattern, &pattern TSRMLS_CC);
			zephir_get_strval(&pattern, &_2$$5);
		}
		if (zephir_memnstr_str(&pattern, SL("/:namespace"), "phalcon/mvc/router/route.zep", 96)) {
			ZEPHIR_INIT_VAR(&_4$$6);
			ZEPHIR_INIT_VAR(&_5$$6);
			ZVAL_STRING(&_5$$6, "/:namespace");
			zephir_fast_str_replace(&_4$$6, &_5$$6, &idPattern, &pattern TSRMLS_CC);
			zephir_get_strval(&pattern, &_4$$6);
		}
		if (zephir_memnstr_str(&pattern, SL("/:action"), "phalcon/mvc/router/route.zep", 101)) {
			ZEPHIR_INIT_VAR(&_6$$7);
			ZEPHIR_INIT_VAR(&_7$$7);
			ZVAL_STRING(&_7$$7, "/:action");
			zephir_fast_str_replace(&_6$$7, &_7$$7, &idPattern, &pattern TSRMLS_CC);
			zephir_get_strval(&pattern, &_6$$7);
		}
		if (zephir_memnstr_str(&pattern, SL("/:params"), "phalcon/mvc/router/route.zep", 106)) {
			ZEPHIR_INIT_VAR(&_8$$8);
			ZEPHIR_INIT_VAR(&_9$$8);
			ZVAL_STRING(&_9$$8, "/:params");
			ZEPHIR_INIT_VAR(&_10$$8);
			ZVAL_STRING(&_10$$8, "(/.*)*");
			zephir_fast_str_replace(&_8$$8, &_9$$8, &_10$$8, &pattern TSRMLS_CC);
			zephir_get_strval(&pattern, &_8$$8);
		}
		if (zephir_memnstr_str(&pattern, SL("/:int"), "phalcon/mvc/router/route.zep", 111)) {
			ZEPHIR_INIT_VAR(&_11$$9);
			ZEPHIR_INIT_VAR(&_12$$9);
			ZVAL_STRING(&_12$$9, "/:int");
			ZEPHIR_INIT_VAR(&_13$$9);
			ZVAL_STRING(&_13$$9, "/([0-9]+)");
			zephir_fast_str_replace(&_11$$9, &_12$$9, &_13$$9, &pattern TSRMLS_CC);
			zephir_get_strval(&pattern, &_11$$9);
		}
	}
	if (zephir_memnstr_str(&pattern, SL("("), "phalcon/mvc/router/route.zep", 117)) {
		ZEPHIR_CONCAT_SVS(return_value, "#^", &pattern, "$#u");
		RETURN_MM();
	}
	if (zephir_memnstr_str(&pattern, SL("["), "phalcon/mvc/router/route.zep", 122)) {
		ZEPHIR_CONCAT_SVS(return_value, "#^", &pattern, "$#u");
		RETURN_MM();
	}
	RETURN_CTOR(&pattern);

}

/**
 * Set one or more HTTP methods that constraint the matching of the route
 *
 *<code>
 * $route->via("GET");
 *
 * $route->via(
 *     [
 *         "GET",
 *         "POST",
 *     ]
 * );
 *</code>
 */
PHP_METHOD(Phalcon_Mvc_Router_Route, via) {

	zval *httpMethods, httpMethods_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&httpMethods_sub);

	zephir_fetch_params(0, 1, 0, &httpMethods);



	zephir_update_property_zval(this_ptr, SL("_methods"), httpMethods);
	RETURN_THISW();

}

/**
 * Extracts parameters from a string
 */
PHP_METHOD(Phalcon_Mvc_Router_Route, extractNamedParams) {

	long _0, _5$$11, _26$$19;
	zend_bool notValid = 0, _6$$12, _7$$12, _8$$12, _9$$12, _10$$12, _11$$12, _12$$12, _13$$12, _14$$12, _15$$12, _16$$12, _17$$12, _25$$18, _31$$36, _32$$37, _33$$37, _34$$37;
	zend_long tmp = 0, cursor = 0, cursorVar = 0, marker = 0, bracketCount, parenthesesCount, foundPattern, intermediate, numberMatches;
	char ch = 0, prevCh;
	zval *pattern_param = NULL, matches, _1$$11, _2$$11, _3$$11, _18$$16, _19$$16, _20$$16, _22$$16, _23$$16, _28$$19, _29$$28;
	zval pattern, route, item, variable, regexp, _4$$11, _21$$16, _24$$16, _27$$26, _30$$29;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&pattern);
	ZVAL_UNDEF(&route);
	ZVAL_UNDEF(&item);
	ZVAL_UNDEF(&variable);
	ZVAL_UNDEF(&regexp);
	ZVAL_UNDEF(&_4$$11);
	ZVAL_UNDEF(&_21$$16);
	ZVAL_UNDEF(&_24$$16);
	ZVAL_UNDEF(&_27$$26);
	ZVAL_UNDEF(&_30$$29);
	ZVAL_UNDEF(&matches);
	ZVAL_UNDEF(&_1$$11);
	ZVAL_UNDEF(&_2$$11);
	ZVAL_UNDEF(&_3$$11);
	ZVAL_UNDEF(&_18$$16);
	ZVAL_UNDEF(&_19$$16);
	ZVAL_UNDEF(&_20$$16);
	ZVAL_UNDEF(&_22$$16);
	ZVAL_UNDEF(&_23$$16);
	ZVAL_UNDEF(&_28$$19);
	ZVAL_UNDEF(&_29$$28);

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


	prevCh = '\0';
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
										ZEPHIR_INIT_LNVAR(_27$$26);
										ZEPHIR_CONCAT_SVS(&_27$$26, "(", &regexp, ")");
										zephir_concat_self(&route, &_27$$26 TSRMLS_CC);
									} else {
										zephir_concat_self(&route, &regexp TSRMLS_CC);
									}
									ZEPHIR_INIT_NVAR(&_28$$19);
									ZVAL_LONG(&_28$$19, tmp);
									zephir_array_update_zval(&matches, &variable, &_28$$19, PH_COPY | PH_SEPARATE);
								} else {
									zephir_concat_self_str(&route, "([^/]*)", sizeof("([^/]*)")-1 TSRMLS_CC);
									ZEPHIR_INIT_NVAR(&_29$$28);
									ZVAL_LONG(&_29$$28, tmp);
									zephir_array_update_zval(&matches, &item, &_29$$28, PH_COPY | PH_SEPARATE);
								}
							} else {
								ZEPHIR_INIT_LNVAR(_30$$29);
								ZEPHIR_CONCAT_SVS(&_30$$29, "{", &item, "}");
								zephir_concat_self(&route, &_30$$29 TSRMLS_CC);
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
			_31$$36 = parenthesesCount == 0;
			if (_31$$36) {
				_31$$36 = prevCh != '\\';
			}
			if (_31$$36) {
				_32$$37 = ch == '.';
				if (!(_32$$37)) {
					_32$$37 = ch == '+';
				}
				_33$$37 = _32$$37;
				if (!(_33$$37)) {
					_33$$37 = ch == '|';
				}
				_34$$37 = _33$$37;
				if (!(_34$$37)) {
					_34$$37 = ch == '#';
				}
				if (_34$$37) {
					zephir_concat_self_str(&route, "\\", sizeof("\\")-1 TSRMLS_CC);
				}
			}
			zephir_concat_self_char(&route, ch TSRMLS_CC);
			prevCh = ch;
		}
	}
	zephir_create_array(return_value, 2, 0 TSRMLS_CC);
	zephir_array_fast_append(return_value, &route);
	zephir_array_fast_append(return_value, &matches);
	RETURN_MM();

}

/**
 * Reconfigure the route adding a new pattern and a set of paths
 */
PHP_METHOD(Phalcon_Mvc_Router_Route, reConfigure) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *pattern_param = NULL, *paths = NULL, paths_sub, __$null, routePaths, pcrePattern, compiledPattern, extracted, _0$$4, _1$$4;
	zval pattern;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&pattern);
	ZVAL_UNDEF(&paths_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&routePaths);
	ZVAL_UNDEF(&pcrePattern);
	ZVAL_UNDEF(&compiledPattern);
	ZVAL_UNDEF(&extracted);
	ZVAL_UNDEF(&_0$$4);
	ZVAL_UNDEF(&_1$$4);

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


	ZEPHIR_CALL_SELF(&routePaths, "getroutepaths", NULL, 0, paths);
	zephir_check_call_status();
	if (!(zephir_start_with_str(&pattern, SL("#")))) {
		if (zephir_memnstr_str(&pattern, SL("{"), "phalcon/mvc/router/route.zep", 300)) {
			ZEPHIR_CALL_METHOD(&extracted, this_ptr, "extractnamedparams", NULL, 0, &pattern);
			zephir_check_call_status();
			ZEPHIR_OBS_VAR(&pcrePattern);
			zephir_array_fetch_long(&pcrePattern, &extracted, 0, PH_NOISY, "phalcon/mvc/router/route.zep", 305 TSRMLS_CC);
			ZEPHIR_INIT_VAR(&_0$$4);
			zephir_array_fetch_long(&_1$$4, &extracted, 1, PH_NOISY | PH_READONLY, "phalcon/mvc/router/route.zep", 306 TSRMLS_CC);
			zephir_fast_array_merge(&_0$$4, &routePaths, &_1$$4 TSRMLS_CC);
			ZEPHIR_CPY_WRT(&routePaths, &_0$$4);
		} else {
			ZEPHIR_CPY_WRT(&pcrePattern, &pattern);
		}
		ZEPHIR_CALL_METHOD(&compiledPattern, this_ptr, "compilepattern", NULL, 0, &pcrePattern);
		zephir_check_call_status();
	} else {
		ZEPHIR_CPY_WRT(&compiledPattern, &pattern);
	}
	zephir_update_property_zval(this_ptr, SL("_pattern"), &pattern);
	zephir_update_property_zval(this_ptr, SL("_compiledPattern"), &compiledPattern);
	zephir_update_property_zval(this_ptr, SL("_paths"), &routePaths);
	ZEPHIR_MM_RESTORE();

}

/**
 * Returns routePaths
 */
PHP_METHOD(Phalcon_Mvc_Router_Route, getRoutePaths) {

	zend_long _0$$4;
	zval *paths = NULL, paths_sub, __$null, moduleName, controllerName, actionName, parts, routePaths, realClassName, namespaceName, _1$$9;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&paths_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&moduleName);
	ZVAL_UNDEF(&controllerName);
	ZVAL_UNDEF(&actionName);
	ZVAL_UNDEF(&parts);
	ZVAL_UNDEF(&routePaths);
	ZVAL_UNDEF(&realClassName);
	ZVAL_UNDEF(&namespaceName);
	ZVAL_UNDEF(&_1$$9);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &paths);

	if (!paths) {
		paths = &paths_sub;
		paths = &__$null;
	}


	if (Z_TYPE_P(paths) != IS_NULL) {
		if (Z_TYPE_P(paths) == IS_STRING) {
			ZEPHIR_INIT_VAR(&moduleName);
			ZVAL_NULL(&moduleName);
			ZEPHIR_INIT_VAR(&controllerName);
			ZVAL_NULL(&controllerName);
			ZEPHIR_INIT_VAR(&actionName);
			ZVAL_NULL(&actionName);
			ZEPHIR_INIT_VAR(&parts);
			zephir_fast_explode_str(&parts, SL("::"), paths, LONG_MAX TSRMLS_CC);
			do {
				_0$$4 = zephir_fast_count_int(&parts TSRMLS_CC);
				if (_0$$4 == 3) {
					ZEPHIR_OBS_NVAR(&moduleName);
					zephir_array_fetch_long(&moduleName, &parts, 0, PH_NOISY, "phalcon/mvc/router/route.zep", 358 TSRMLS_CC);
					ZEPHIR_OBS_NVAR(&controllerName);
					zephir_array_fetch_long(&controllerName, &parts, 1, PH_NOISY, "phalcon/mvc/router/route.zep", 359 TSRMLS_CC);
					ZEPHIR_OBS_NVAR(&actionName);
					zephir_array_fetch_long(&actionName, &parts, 2, PH_NOISY, "phalcon/mvc/router/route.zep", 360 TSRMLS_CC);
					break;
				}
				if (_0$$4 == 2) {
					ZEPHIR_OBS_NVAR(&controllerName);
					zephir_array_fetch_long(&controllerName, &parts, 0, PH_NOISY, "phalcon/mvc/router/route.zep", 364 TSRMLS_CC);
					ZEPHIR_OBS_NVAR(&actionName);
					zephir_array_fetch_long(&actionName, &parts, 1, PH_NOISY, "phalcon/mvc/router/route.zep", 365 TSRMLS_CC);
					break;
				}
				if (_0$$4 == 1) {
					ZEPHIR_OBS_NVAR(&controllerName);
					zephir_array_fetch_long(&controllerName, &parts, 0, PH_NOISY, "phalcon/mvc/router/route.zep", 369 TSRMLS_CC);
					break;
				}
			} while(0);

			ZEPHIR_INIT_VAR(&routePaths);
			array_init(&routePaths);
			if (Z_TYPE_P(&moduleName) != IS_NULL) {
				zephir_array_update_string(&routePaths, SL("module"), &moduleName, PH_COPY | PH_SEPARATE);
			}
			if (Z_TYPE_P(&controllerName) != IS_NULL) {
				if (zephir_memnstr_str(&controllerName, SL("\\"), "phalcon/mvc/router/route.zep", 384)) {
					ZEPHIR_INIT_VAR(&realClassName);
					zephir_get_class_ns(&realClassName, &controllerName, 0 TSRMLS_CC);
					ZEPHIR_INIT_VAR(&namespaceName);
					zephir_get_ns_class(&namespaceName, &controllerName, 0 TSRMLS_CC);
					if (zephir_is_true(&namespaceName)) {
						zephir_array_update_string(&routePaths, SL("namespace"), &namespaceName, PH_COPY | PH_SEPARATE);
					}
				} else {
					ZEPHIR_CPY_WRT(&realClassName, &controllerName);
				}
				ZEPHIR_INIT_VAR(&_1$$9);
				zephir_uncamelize(&_1$$9, &realClassName, NULL  );
				zephir_array_update_string(&routePaths, SL("controller"), &_1$$9, PH_COPY | PH_SEPARATE);
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
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_router_exception_ce, "The route contains invalid paths", "phalcon/mvc/router/route.zep", 416);
		return;
	}
	RETURN_CCTOR(&routePaths);

}

/**
 * Returns the route's name
 */
PHP_METHOD(Phalcon_Mvc_Router_Route, getName) {

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
PHP_METHOD(Phalcon_Mvc_Router_Route, setName) {

	zval *name_param = NULL;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

	zephir_get_strval(&name, name_param);


	zephir_update_property_zval(this_ptr, SL("_name"), &name);
	RETURN_THIS();

}

/**
 * Sets a callback that is called if the route is matched.
 * The developer can implement any arbitrary conditions here
 * If the callback returns false the route is treated as not matched
 *
 *<code>
 * $router->add(
 *     "/login",
 *     [
 *         "module"     => "admin",
 *         "controller" => "session",
 *     ]
 * )->beforeMatch(
 *     function ($uri, $route) {
 *         // Check if the request was made with Ajax
 *         if ($_SERVER["HTTP_X_REQUESTED_WITH"] === "xmlhttprequest") {
 *             return false;
 *         }
 *
 *         return true;
 *     }
 * );
 *</code>
 */
PHP_METHOD(Phalcon_Mvc_Router_Route, beforeMatch) {

	zval *callback, callback_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&callback_sub);

	zephir_fetch_params(0, 1, 0, &callback);



	zephir_update_property_zval(this_ptr, SL("_beforeMatch"), callback);
	RETURN_THISW();

}

/**
 * Returns the 'before match' callback if any
 */
PHP_METHOD(Phalcon_Mvc_Router_Route, getBeforeMatch) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "_beforeMatch");

}

/**
 * Allows to set a callback to handle the request directly in the route
 *
 *<code>
 * $router->add(
 *     "/help",
 *     []
 * )->match(
 *     function () {
 *         return $this->getResponse()->redirect("https://support.google.com/", true);
 *     }
 * );
 *</code>
 */
PHP_METHOD(Phalcon_Mvc_Router_Route, match) {

	zval *callback, callback_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&callback_sub);

	zephir_fetch_params(0, 1, 0, &callback);



	zephir_update_property_zval(this_ptr, SL("_match"), callback);
	RETURN_THISW();

}

/**
 * Returns the 'match' callback if any
 */
PHP_METHOD(Phalcon_Mvc_Router_Route, getMatch) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "_match");

}

/**
 * Returns the route's id
 */
PHP_METHOD(Phalcon_Mvc_Router_Route, getRouteId) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "_id");

}

/**
 * Returns the route's pattern
 */
PHP_METHOD(Phalcon_Mvc_Router_Route, getPattern) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "_pattern");

}

/**
 * Returns the route's compiled pattern
 */
PHP_METHOD(Phalcon_Mvc_Router_Route, getCompiledPattern) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "_compiledPattern");

}

/**
 * Returns the paths
 */
PHP_METHOD(Phalcon_Mvc_Router_Route, getPaths) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "_paths");

}

/**
 * Returns the paths using positions as keys and names as values
 */
PHP_METHOD(Phalcon_Mvc_Router_Route, getReversedPaths) {

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
	zephir_is_iterable(&_0, 0, "phalcon/mvc/router/route.zep", 557);
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
 * Sets a set of HTTP methods that constraint the matching of the route (alias of via)
 *
 *<code>
 * $route->setHttpMethods("GET");
 * $route->setHttpMethods(["GET", "POST"]);
 *</code>
 */
PHP_METHOD(Phalcon_Mvc_Router_Route, setHttpMethods) {

	zval *httpMethods, httpMethods_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&httpMethods_sub);

	zephir_fetch_params(0, 1, 0, &httpMethods);



	zephir_update_property_zval(this_ptr, SL("_methods"), httpMethods);
	RETURN_THISW();

}

/**
 * Returns the HTTP methods that constraint matching the route
 */
PHP_METHOD(Phalcon_Mvc_Router_Route, getHttpMethods) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "_methods");

}

/**
 * Sets a hostname restriction to the route
 *
 *<code>
 * $route->setHostname("localhost");
 *</code>
 */
PHP_METHOD(Phalcon_Mvc_Router_Route, setHostname) {

	zval *hostname_param = NULL;
	zval hostname;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&hostname);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &hostname_param);

	if (UNEXPECTED(Z_TYPE_P(hostname_param) != IS_STRING && Z_TYPE_P(hostname_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'hostname' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(hostname_param) == IS_STRING)) {
		zephir_get_strval(&hostname, hostname_param);
	} else {
		ZEPHIR_INIT_VAR(&hostname);
		ZVAL_EMPTY_STRING(&hostname);
	}


	zephir_update_property_zval(this_ptr, SL("_hostname"), &hostname);
	RETURN_THIS();

}

/**
 * Returns the hostname restriction if any
 */
PHP_METHOD(Phalcon_Mvc_Router_Route, getHostname) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "_hostname");

}

/**
 * Sets the group associated with the route
 */
PHP_METHOD(Phalcon_Mvc_Router_Route, setGroup) {

	zval *group, group_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&group_sub);

	zephir_fetch_params(0, 1, 0, &group);



	zephir_update_property_zval(this_ptr, SL("_group"), group);
	RETURN_THISW();

}

/**
 * Returns the group associated with the route
 */
PHP_METHOD(Phalcon_Mvc_Router_Route, getGroup) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "_group");

}

/**
 * {@inheritdoc}
 */
PHP_METHOD(Phalcon_Mvc_Router_Route, convert) {

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
PHP_METHOD(Phalcon_Mvc_Router_Route, getConverters) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "_converters");

}

/**
 * Resets the internal route id generator
 */
PHP_METHOD(Phalcon_Mvc_Router_Route, reset) {

	zval __$null;
	zval *this_ptr = getThis();

	ZVAL_NULL(&__$null);


	zend_update_static_property(phalcon_mvc_router_route_ce, ZEND_STRL("_uniqueId"), &__$null);

}

