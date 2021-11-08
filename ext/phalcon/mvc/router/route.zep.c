
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
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * Phalcon\Mvc\Router\Route
 *
 * This class represents every route added to the router
 */
ZEPHIR_INIT_CLASS(Phalcon_Mvc_Router_Route)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\Mvc\\Router, Route, phalcon, mvc_router_route, phalcon_mvc_router_route_method_entry, 0);

	/**
	 * @var callable|null
	 */
	zend_declare_property_null(phalcon_mvc_router_route_ce, SL("beforeMatch"), ZEND_ACC_PROTECTED);
	/**
	 * @var string|null
	 */
	zend_declare_property_null(phalcon_mvc_router_route_ce, SL("compiledPattern"), ZEND_ACC_PROTECTED);
	/**
	 * @var array
	 */
	zend_declare_property_null(phalcon_mvc_router_route_ce, SL("converters"), ZEND_ACC_PROTECTED);
	/**
	 * @var GroupInterface|null
	 */
	zend_declare_property_null(phalcon_mvc_router_route_ce, SL("group"), ZEND_ACC_PROTECTED);
	/**
	 * @var string|null
	 */
	zend_declare_property_null(phalcon_mvc_router_route_ce, SL("hostname"), ZEND_ACC_PROTECTED);
	/**
	 * @var string|null
	 */
	zend_declare_property_null(phalcon_mvc_router_route_ce, SL("id"), ZEND_ACC_PROTECTED);
	/**
	 * @var array|string
	 */
	zend_declare_property_null(phalcon_mvc_router_route_ce, SL("methods"), ZEND_ACC_PROTECTED);
	/**
	 * @var callable|null
	 */
	zend_declare_property_null(phalcon_mvc_router_route_ce, SL("match"), ZEND_ACC_PROTECTED);
	/**
	 * @var string|null
	 */
	zend_declare_property_null(phalcon_mvc_router_route_ce, SL("name"), ZEND_ACC_PROTECTED);
	/**
	 * @var array
	 */
	zend_declare_property_null(phalcon_mvc_router_route_ce, SL("paths"), ZEND_ACC_PROTECTED);
	/**
	 * @var string
	 */
	zend_declare_property_null(phalcon_mvc_router_route_ce, SL("pattern"), ZEND_ACC_PROTECTED);
	/**
	 * @var int
	 */
	zend_declare_property_long(phalcon_mvc_router_route_ce, SL("uniqueId"), 0, ZEND_ACC_PROTECTED|ZEND_ACC_STATIC);
	phalcon_mvc_router_route_ce->create_object = zephir_init_properties_Phalcon_Mvc_Router_Route;

	zend_class_implements(phalcon_mvc_router_route_ce, 1, phalcon_mvc_router_routeinterface_ce);
	return SUCCESS;
}

/**
 */
PHP_METHOD(Phalcon_Mvc_Router_Route, getId)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "id");
}

/**
 * Phalcon\Mvc\Router\Route constructor
 */
PHP_METHOD(Phalcon_Mvc_Router_Route, __construct)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
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
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 3)
		Z_PARAM_STR(pattern)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(paths)
		Z_PARAM_ZVAL_OR_NULL(httpMethods)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &pattern_param, &paths, &httpMethods);
	if (UNEXPECTED(Z_TYPE_P(pattern_param) != IS_STRING && Z_TYPE_P(pattern_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'pattern' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(pattern_param) == IS_STRING)) {
		zephir_get_strval(&pattern, pattern_param);
	} else {
		ZEPHIR_INIT_VAR(&pattern);
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
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "via", NULL, 0, httpMethods);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(&_0);
	zephir_read_static_property_ce(&_0, phalcon_mvc_router_route_ce, SL("uniqueId"), PH_NOISY_CC);
	ZEPHIR_CPY_WRT(&uniqueId, &_0);
	ZEPHIR_CPY_WRT(&routeId, &uniqueId);
	zephir_update_property_zval(this_ptr, ZEND_STRL("id"), &routeId);
	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(&_0, (zephir_get_numberval(&uniqueId) + 1));
	zephir_update_static_property_ce(phalcon_mvc_router_route_ce, ZEND_STRL("uniqueId"), &_0);
	ZEPHIR_MM_RESTORE();
}

/**
 * Sets a callback that is called if the route is matched.
 * The developer can implement any arbitrary conditions here
 * If the callback returns false the route is treated as not matched
 *
 *```php
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
 *```
 */
PHP_METHOD(Phalcon_Mvc_Router_Route, beforeMatch)
{
	zval *callback, callback_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&callback_sub);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(callback)
	ZEND_PARSE_PARAMETERS_END();
#endif


	zephir_fetch_params_without_memory_grow(1, 0, &callback);


	zephir_update_property_zval(this_ptr, ZEND_STRL("beforeMatch"), callback);
	RETURN_THISW();
}

/**
 * Replaces placeholders from pattern returning a valid PCRE regular expression
 */
PHP_METHOD(Phalcon_Mvc_Router_Route, compilePattern)
{
	zend_bool _14;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *pattern_param = NULL, _0$$4, _1$$4, _2$$5, _3$$5, _4$$6, _5$$6, _6$$7, _7$$7, _8$$8, _9$$8, _10$$8, _11$$9, _12$$9, _13$$9;
	zval pattern, idPattern;
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
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(pattern)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &pattern_param);
	if (UNEXPECTED(Z_TYPE_P(pattern_param) != IS_STRING && Z_TYPE_P(pattern_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'pattern' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(pattern_param) == IS_STRING)) {
		zephir_get_strval(&pattern, pattern_param);
	} else {
		ZEPHIR_INIT_VAR(&pattern);
	}


	if (zephir_memnstr_str(&pattern, SL(":"), "phalcon/Mvc/Router/Route.zep", 141)) {
		ZEPHIR_INIT_VAR(&idPattern);
		ZVAL_STRING(&idPattern, "/([\\w0-9\\_\\-]+)");
		if (zephir_memnstr_str(&pattern, SL("/:module"), "phalcon/Mvc/Router/Route.zep", 146)) {
			ZEPHIR_INIT_VAR(&_0$$4);
			ZEPHIR_INIT_VAR(&_1$$4);
			ZVAL_STRING(&_1$$4, "/:module");
			zephir_fast_str_replace(&_0$$4, &_1$$4, &idPattern, &pattern);
			zephir_get_strval(&pattern, &_0$$4);
		}
		if (zephir_memnstr_str(&pattern, SL("/:controller"), "phalcon/Mvc/Router/Route.zep", 151)) {
			ZEPHIR_INIT_VAR(&_2$$5);
			ZEPHIR_INIT_VAR(&_3$$5);
			ZVAL_STRING(&_3$$5, "/:controller");
			zephir_fast_str_replace(&_2$$5, &_3$$5, &idPattern, &pattern);
			zephir_get_strval(&pattern, &_2$$5);
		}
		if (zephir_memnstr_str(&pattern, SL("/:namespace"), "phalcon/Mvc/Router/Route.zep", 156)) {
			ZEPHIR_INIT_VAR(&_4$$6);
			ZEPHIR_INIT_VAR(&_5$$6);
			ZVAL_STRING(&_5$$6, "/:namespace");
			zephir_fast_str_replace(&_4$$6, &_5$$6, &idPattern, &pattern);
			zephir_get_strval(&pattern, &_4$$6);
		}
		if (zephir_memnstr_str(&pattern, SL("/:action"), "phalcon/Mvc/Router/Route.zep", 161)) {
			ZEPHIR_INIT_VAR(&_6$$7);
			ZEPHIR_INIT_VAR(&_7$$7);
			ZVAL_STRING(&_7$$7, "/:action");
			zephir_fast_str_replace(&_6$$7, &_7$$7, &idPattern, &pattern);
			zephir_get_strval(&pattern, &_6$$7);
		}
		if (zephir_memnstr_str(&pattern, SL("/:params"), "phalcon/Mvc/Router/Route.zep", 166)) {
			ZEPHIR_INIT_VAR(&_8$$8);
			ZEPHIR_INIT_VAR(&_9$$8);
			ZVAL_STRING(&_9$$8, "/:params");
			ZEPHIR_INIT_VAR(&_10$$8);
			ZVAL_STRING(&_10$$8, "(/.*)*");
			zephir_fast_str_replace(&_8$$8, &_9$$8, &_10$$8, &pattern);
			zephir_get_strval(&pattern, &_8$$8);
		}
		if (zephir_memnstr_str(&pattern, SL("/:int"), "phalcon/Mvc/Router/Route.zep", 171)) {
			ZEPHIR_INIT_VAR(&_11$$9);
			ZEPHIR_INIT_VAR(&_12$$9);
			ZVAL_STRING(&_12$$9, "/:int");
			ZEPHIR_INIT_VAR(&_13$$9);
			ZVAL_STRING(&_13$$9, "/([0-9]+)");
			zephir_fast_str_replace(&_11$$9, &_12$$9, &_13$$9, &pattern);
			zephir_get_strval(&pattern, &_11$$9);
		}
	}
	_14 = zephir_memnstr_str(&pattern, SL("("), "phalcon/Mvc/Router/Route.zep", 182);
	if (!(_14)) {
		_14 = zephir_memnstr_str(&pattern, SL("["), "phalcon/Mvc/Router/Route.zep", 182);
	}
	if (_14) {
		ZEPHIR_CONCAT_SVS(return_value, "#^", &pattern, "$#u");
		RETURN_MM();
	}
	RETURN_CTOR(&pattern);
}

/**
 * {@inheritdoc}
 */
PHP_METHOD(Phalcon_Mvc_Router_Route, convert)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *name_param = NULL, *converter, converter_sub;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&converter_sub);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR(name)
		Z_PARAM_ZVAL(converter)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &name_param, &converter);
	if (UNEXPECTED(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(name_param) == IS_STRING)) {
		zephir_get_strval(&name, name_param);
	} else {
		ZEPHIR_INIT_VAR(&name);
	}


	zephir_update_property_array(this_ptr, SL("converters"), &name, converter);
	RETURN_THIS();
}

/**
 * Extracts parameters from a string
 */
PHP_METHOD(Phalcon_Mvc_Router_Route, extractNamedParams)
{
	long _0, _5$$10, _26$$18;
	zend_long cursor = 0, cursorVar = 0, marker = 0, bracketCount, parenthesesCount, foundPattern, intermediate, numberMatches;
	zend_bool notValid = 0, _6$$11, _7$$11, _8$$11, _9$$11, _10$$11, _11$$11, _12$$11, _13$$11, _14$$11, _15$$11, _16$$11, _17$$11, _25$$17, _29$$34, _30$$35, _31$$35, _32$$35;
	char ch = 0, prevCh;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *pattern_param = NULL, tmp, matches, _1$$10, _2$$10, _3$$10, _18$$15, _19$$15, _20$$15, _22$$15, _23$$15;
	zval pattern, route, item, variable, regexp, _4$$10, _21$$15, _24$$15, _27$$25, _28$$28;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&pattern);
	ZVAL_UNDEF(&route);
	ZVAL_UNDEF(&item);
	ZVAL_UNDEF(&variable);
	ZVAL_UNDEF(&regexp);
	ZVAL_UNDEF(&_4$$10);
	ZVAL_UNDEF(&_21$$15);
	ZVAL_UNDEF(&_24$$15);
	ZVAL_UNDEF(&_27$$25);
	ZVAL_UNDEF(&_28$$28);
	ZVAL_UNDEF(&tmp);
	ZVAL_UNDEF(&matches);
	ZVAL_UNDEF(&_1$$10);
	ZVAL_UNDEF(&_2$$10);
	ZVAL_UNDEF(&_3$$10);
	ZVAL_UNDEF(&_18$$15);
	ZVAL_UNDEF(&_19$$15);
	ZVAL_UNDEF(&_20$$15);
	ZVAL_UNDEF(&_22$$15);
	ZVAL_UNDEF(&_23$$15);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(pattern)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &pattern_param);
	if (UNEXPECTED(Z_TYPE_P(pattern_param) != IS_STRING && Z_TYPE_P(pattern_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'pattern' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(pattern_param) == IS_STRING)) {
		zephir_get_strval(&pattern, pattern_param);
	} else {
		ZEPHIR_INIT_VAR(&pattern);
	}


	prevCh = '\0';
	bracketCount = 0;
	parenthesesCount = 0;
	foundPattern = 0;
	intermediate = 0;
	numberMatches = 0;
	if (zephir_fast_strlen_ev(&pattern) == 0) {
		RETURN_MM_BOOL(0);
	}
	ZEPHIR_INIT_VAR(&matches);
	array_init(&matches);
	ZEPHIR_INIT_VAR(&route);
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
			} else if (ch == '}') {
				bracketCount--;
				if (intermediate > 0) {
					if (bracketCount == 0) {
						numberMatches++;
						ZEPHIR_INIT_NVAR(&variable);
						ZEPHIR_INIT_NVAR(&regexp);
						ZVAL_LONG(&_1$$10, marker);
						ZVAL_LONG(&_2$$10, (cursor - marker));
						ZEPHIR_INIT_NVAR(&_3$$10);
						zephir_substr(&_3$$10, &pattern, zephir_get_intval(&_1$$10), zephir_get_intval(&_2$$10), 0);
						zephir_cast_to_string(&_4$$10, &_3$$10);
						ZEPHIR_CPY_WRT(&item, &_4$$10);
						for (_5$$10 = 0; _5$$10 < Z_STRLEN_P(&item); _5$$10++) {
							cursorVar = _5$$10; 
							ch = ZEPHIR_STRING_OFFSET(&item, _5$$10);
							if (ch == '\0') {
								break;
							}
							_6$$11 = cursorVar == 0;
							if (_6$$11) {
								_7$$11 = ch >= 'a';
								if (_7$$11) {
									_7$$11 = ch <= 'z';
								}
								_8$$11 = _7$$11;
								if (!(_8$$11)) {
									_9$$11 = ch >= 'A';
									if (_9$$11) {
										_9$$11 = ch <= 'Z';
									}
									_8$$11 = _9$$11;
								}
								_6$$11 = !(_8$$11);
							}
							if (_6$$11) {
								notValid = 1;
								break;
							}
							_10$$11 = ch >= 'a';
							if (_10$$11) {
								_10$$11 = ch <= 'z';
							}
							_11$$11 = _10$$11;
							if (!(_11$$11)) {
								_12$$11 = ch >= 'A';
								if (_12$$11) {
									_12$$11 = ch <= 'Z';
								}
								_11$$11 = _12$$11;
							}
							_13$$11 = _11$$11;
							if (!(_13$$11)) {
								_14$$11 = ch >= '0';
								if (_14$$11) {
									_14$$11 = ch <= '9';
								}
								_13$$11 = _14$$11;
							}
							_15$$11 = _13$$11;
							if (!(_15$$11)) {
								_15$$11 = ch == '-';
							}
							_16$$11 = _15$$11;
							if (!(_16$$11)) {
								_16$$11 = ch == '_';
							}
							_17$$11 = _16$$11;
							if (!(_17$$11)) {
								_17$$11 = ch == ':';
							}
							if (_17$$11) {
								if (ch == ':') {
									ZVAL_LONG(&_18$$15, 0);
									ZVAL_LONG(&_19$$15, cursorVar);
									ZEPHIR_INIT_NVAR(&_20$$15);
									zephir_substr(&_20$$15, &item, 0 , zephir_get_intval(&_19$$15), 0);
									zephir_cast_to_string(&_21$$15, &_20$$15);
									ZEPHIR_CPY_WRT(&variable, &_21$$15);
									ZVAL_LONG(&_22$$15, (cursorVar + 1));
									ZEPHIR_INIT_NVAR(&_23$$15);
									zephir_substr(&_23$$15, &item, zephir_get_intval(&_22$$15), 0, ZEPHIR_SUBSTR_NO_LENGTH);
									zephir_cast_to_string(&_24$$15, &_23$$15);
									ZEPHIR_CPY_WRT(&regexp, &_24$$15);
									break;
								}
							} else {
								notValid = 1;
								break;
							}
						}
						if (!(notValid)) {
							ZEPHIR_INIT_NVAR(&tmp);
							ZVAL_LONG(&tmp, numberMatches);
							_25$$17 = zephir_is_true(&variable);
							if (_25$$17) {
								_25$$17 = zephir_is_true(&regexp);
							}
							if (_25$$17) {
								foundPattern = 0;
								for (_26$$18 = 0; _26$$18 < Z_STRLEN_P(&regexp); _26$$18++) {
									ch = ZEPHIR_STRING_OFFSET(&regexp, _26$$18);
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
									ZEPHIR_INIT_NVAR(&_27$$25);
									ZEPHIR_CONCAT_SVS(&_27$$25, "(", &regexp, ")");
									zephir_concat_self(&route, &_27$$25);
								} else {
									zephir_concat_self(&route, &regexp);
								}
								zephir_array_update_zval(&matches, &variable, &tmp, PH_COPY | PH_SEPARATE);
							} else {
								zephir_concat_self_str(&route, "([^/]*)", sizeof("([^/]*)") - 1);
								zephir_array_update_zval(&matches, &item, &tmp, PH_COPY | PH_SEPARATE);
							}
						} else {
							ZEPHIR_INIT_NVAR(&_28$$28);
							ZEPHIR_CONCAT_SVS(&_28$$28, "{", &item, "}");
							zephir_concat_self(&route, &_28$$28);
						}
						continue;
					}
				}
			}
		}
		if (bracketCount == 0) {
			if (ch == '(') {
				parenthesesCount++;
			} else if (ch == ')') {
				parenthesesCount--;
				if (parenthesesCount == 0) {
					numberMatches++;
				}
			}
		}
		if (bracketCount > 0) {
			intermediate++;
		} else {
			_29$$34 = parenthesesCount == 0;
			if (_29$$34) {
				_29$$34 = prevCh != '\\';
			}
			if (_29$$34) {
				_30$$35 = ch == '.';
				if (!(_30$$35)) {
					_30$$35 = ch == '+';
				}
				_31$$35 = _30$$35;
				if (!(_31$$35)) {
					_31$$35 = ch == '|';
				}
				_32$$35 = _31$$35;
				if (!(_32$$35)) {
					_32$$35 = ch == '#';
				}
				if (_32$$35) {
					zephir_concat_self_str(&route, "\\", sizeof("\\") - 1);
				}
			}
			zephir_concat_self_char(&route, ch);
			prevCh = ch;
		}
	}
	zephir_create_array(return_value, 2, 0);
	zephir_array_fast_append(return_value, &route);
	zephir_array_fast_append(return_value, &matches);
	RETURN_MM();
}

/**
 * Returns the 'before match' callback if any
 */
PHP_METHOD(Phalcon_Mvc_Router_Route, getBeforeMatch)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "beforeMatch");
}

/**
 * Returns the route's compiled pattern
 */
PHP_METHOD(Phalcon_Mvc_Router_Route, getCompiledPattern)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "compiledPattern");
}

/**
 * Returns the router converter
 */
PHP_METHOD(Phalcon_Mvc_Router_Route, getConverters)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "converters");
}

/**
 * Returns the group associated with the route
 */
PHP_METHOD(Phalcon_Mvc_Router_Route, getGroup)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "group");
}

/**
 * Returns the HTTP methods that constraint matching the route
 */
PHP_METHOD(Phalcon_Mvc_Router_Route, getHttpMethods)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "methods");
}

/**
 * Returns the hostname restriction if any
 */
PHP_METHOD(Phalcon_Mvc_Router_Route, getHostname)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "hostname");
}

/**
 * Returns the 'match' callback if any
 */
PHP_METHOD(Phalcon_Mvc_Router_Route, getMatch)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "match");
}

/**
 * Returns the route's name
 */
PHP_METHOD(Phalcon_Mvc_Router_Route, getName)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "name");
}

/**
 * Returns the paths
 */
PHP_METHOD(Phalcon_Mvc_Router_Route, getPaths)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "paths");
}

/**
 * Returns the route's pattern
 */
PHP_METHOD(Phalcon_Mvc_Router_Route, getPattern)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "pattern");
}

/**
 * Returns the paths using positions as keys and names as values
 */
PHP_METHOD(Phalcon_Mvc_Router_Route, getReversedPaths)
{
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);


	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, ZEND_STRL("paths"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_FUNCTION("array_flip", NULL, 186, &_0);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Returns the route's id
 */
PHP_METHOD(Phalcon_Mvc_Router_Route, getRouteId)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "id");
}

/**
 * Returns routePaths
 */
PHP_METHOD(Phalcon_Mvc_Router_Route, getRoutePaths)
{
	zend_long _0$$4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *paths = NULL, paths_sub, __$null, moduleName, controllerName, actionName, parts, routePaths, realClassName, namespaceName;
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
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(paths)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &paths);
	if (!paths) {
		paths = &paths_sub;
		ZEPHIR_CPY_WRT(paths, &__$null);
	} else {
		ZEPHIR_SEPARATE_PARAM(paths);
	}


	if (Z_TYPE_P(paths) == IS_NULL) {
		ZEPHIR_INIT_NVAR(paths);
		array_init(paths);
	}
	if (Z_TYPE_P(paths) == IS_STRING) {
		ZEPHIR_INIT_VAR(&moduleName);
		ZVAL_NULL(&moduleName);
		ZEPHIR_INIT_VAR(&controllerName);
		ZVAL_NULL(&controllerName);
		ZEPHIR_INIT_VAR(&actionName);
		ZVAL_NULL(&actionName);
		ZEPHIR_INIT_VAR(&parts);
		zephir_fast_explode_str(&parts, SL("::"), paths, LONG_MAX);
		do {
			_0$$4 = zephir_fast_count_int(&parts);
			if (_0$$4 == 3) {
				ZEPHIR_OBS_NVAR(&moduleName);
				zephir_array_fetch_long(&moduleName, &parts, 0, PH_NOISY, "phalcon/Mvc/Router/Route.zep", 459);
				ZEPHIR_OBS_NVAR(&controllerName);
				zephir_array_fetch_long(&controllerName, &parts, 1, PH_NOISY, "phalcon/Mvc/Router/Route.zep", 460);
				ZEPHIR_OBS_NVAR(&actionName);
				zephir_array_fetch_long(&actionName, &parts, 2, PH_NOISY, "phalcon/Mvc/Router/Route.zep", 461);
				break;
			}
			if (_0$$4 == 2) {
				ZEPHIR_OBS_NVAR(&controllerName);
				zephir_array_fetch_long(&controllerName, &parts, 0, PH_NOISY, "phalcon/Mvc/Router/Route.zep", 465);
				ZEPHIR_OBS_NVAR(&actionName);
				zephir_array_fetch_long(&actionName, &parts, 1, PH_NOISY, "phalcon/Mvc/Router/Route.zep", 466);
				break;
			}
			if (_0$$4 == 1) {
				ZEPHIR_OBS_NVAR(&controllerName);
				zephir_array_fetch_long(&controllerName, &parts, 0, PH_NOISY, "phalcon/Mvc/Router/Route.zep", 470);
				break;
			}
		} while(0);

		ZEPHIR_INIT_VAR(&routePaths);
		array_init(&routePaths);
		if (Z_TYPE_P(&moduleName) != IS_NULL) {
			zephir_array_update_string(&routePaths, SL("module"), &moduleName, PH_COPY | PH_SEPARATE);
		}
		if (Z_TYPE_P(&controllerName) != IS_NULL) {
			if (zephir_memnstr_str(&controllerName, SL("\\"), "phalcon/Mvc/Router/Route.zep", 484)) {
				ZEPHIR_INIT_VAR(&realClassName);
				zephir_get_class_ns(&realClassName, &controllerName, 0);
				ZEPHIR_INIT_VAR(&namespaceName);
				zephir_get_ns_class(&namespaceName, &controllerName, 0);
				if (zephir_is_true(&namespaceName)) {
					zephir_array_update_string(&routePaths, SL("namespace"), &namespaceName, PH_COPY | PH_SEPARATE);
				}
			} else {
				ZEPHIR_CPY_WRT(&realClassName, &controllerName);
			}
			zephir_array_update_string(&routePaths, SL("controller"), &realClassName, PH_COPY | PH_SEPARATE);
		}
		if (Z_TYPE_P(&actionName) != IS_NULL) {
			zephir_array_update_string(&routePaths, SL("action"), &actionName, PH_COPY | PH_SEPARATE);
		}
	} else {
		ZEPHIR_CPY_WRT(&routePaths, paths);
	}
	if (UNEXPECTED(Z_TYPE_P(&routePaths) != IS_ARRAY)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_router_exception_ce, "The route contains invalid paths", "phalcon/Mvc/Router/Route.zep", 511);
		return;
	}
	RETURN_CCTOR(&routePaths);
}

/**
 * Allows to set a callback to handle the request directly in the route
 *
 *```php
 * $router->add(
 *     "/help",
 *     []
 * )->match(
 *     function () {
 *         return $this->getResponse()->redirect("https://support.google.com/", true);
 *     }
 * );
 *```
 */
PHP_METHOD(Phalcon_Mvc_Router_Route, match)
{
	zval *callback, callback_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&callback_sub);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(callback)
	ZEND_PARSE_PARAMETERS_END();
#endif


	zephir_fetch_params_without_memory_grow(1, 0, &callback);


	zephir_update_property_zval(this_ptr, ZEND_STRL("match"), callback);
	RETURN_THISW();
}

/**
 * Reconfigure the route adding a new pattern and a set of paths
 */
PHP_METHOD(Phalcon_Mvc_Router_Route, reConfigure)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
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
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_STR(pattern)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(paths)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &pattern_param, &paths);
	if (UNEXPECTED(Z_TYPE_P(pattern_param) != IS_STRING && Z_TYPE_P(pattern_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'pattern' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(pattern_param) == IS_STRING)) {
		zephir_get_strval(&pattern, pattern_param);
	} else {
		ZEPHIR_INIT_VAR(&pattern);
	}
	if (!paths) {
		paths = &paths_sub;
		paths = &__$null;
	}


	ZEPHIR_CALL_SELF(&routePaths, "getroutepaths", NULL, 0, paths);
	zephir_check_call_status();
	if (!(zephir_start_with_str(&pattern, SL("#")))) {
		if (zephir_memnstr_str(&pattern, SL("{"), "phalcon/Mvc/Router/Route.zep", 551)) {
			ZEPHIR_CALL_METHOD(&extracted, this_ptr, "extractnamedparams", NULL, 0, &pattern);
			zephir_check_call_status();
			ZEPHIR_OBS_VAR(&pcrePattern);
			zephir_array_fetch_long(&pcrePattern, &extracted, 0, PH_NOISY, "phalcon/Mvc/Router/Route.zep", 556);
			ZEPHIR_INIT_VAR(&_0$$4);
			zephir_array_fetch_long(&_1$$4, &extracted, 1, PH_NOISY | PH_READONLY, "phalcon/Mvc/Router/Route.zep", 557);
			zephir_fast_array_merge(&_0$$4, &routePaths, &_1$$4);
			ZEPHIR_CPY_WRT(&routePaths, &_0$$4);
		} else {
			ZEPHIR_CPY_WRT(&pcrePattern, &pattern);
		}
		ZEPHIR_CALL_METHOD(&compiledPattern, this_ptr, "compilepattern", NULL, 0, &pcrePattern);
		zephir_check_call_status();
	} else {
		ZEPHIR_CPY_WRT(&compiledPattern, &pattern);
	}
	zephir_update_property_zval(this_ptr, ZEND_STRL("pattern"), &pattern);
	zephir_update_property_zval(this_ptr, ZEND_STRL("compiledPattern"), &compiledPattern);
	zephir_update_property_zval(this_ptr, ZEND_STRL("paths"), &routePaths);
	ZEPHIR_MM_RESTORE();
}

/**
 * Resets the internal route id generator
 */
PHP_METHOD(Phalcon_Mvc_Router_Route, reset)
{
	zval _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);



	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(&_0, 0);
	zephir_update_static_property_ce(phalcon_mvc_router_route_ce, ZEND_STRL("uniqueId"), &_0);
}

/**
 * Sets the group associated with the route
 */
PHP_METHOD(Phalcon_Mvc_Router_Route, setGroup)
{
	zval *group, group_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&group_sub);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(group, phalcon_mvc_router_groupinterface_ce)
	ZEND_PARSE_PARAMETERS_END();
#endif


	zephir_fetch_params_without_memory_grow(1, 0, &group);


	zephir_update_property_zval(this_ptr, ZEND_STRL("group"), group);
	RETURN_THISW();
}

/**
 * Sets a set of HTTP methods that constraint the matching of the route (alias of via)
 *
 *```php
 * $route->setHttpMethods("GET");
 *
 * $route->setHttpMethods(
 *     [
 *         "GET",
 *         "POST",
 *     ]
 * );
 *```
 */
PHP_METHOD(Phalcon_Mvc_Router_Route, setHttpMethods)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *httpMethods, httpMethods_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&httpMethods_sub);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(httpMethods)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &httpMethods);


	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "via", NULL, 0, httpMethods);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Sets a hostname restriction to the route
 *
 *```php
 * $route->setHostname("localhost");
 *```
 */
PHP_METHOD(Phalcon_Mvc_Router_Route, setHostname)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *hostname_param = NULL;
	zval hostname;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&hostname);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(hostname)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &hostname_param);
	if (UNEXPECTED(Z_TYPE_P(hostname_param) != IS_STRING && Z_TYPE_P(hostname_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'hostname' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(hostname_param) == IS_STRING)) {
		zephir_get_strval(&hostname, hostname_param);
	} else {
		ZEPHIR_INIT_VAR(&hostname);
	}


	zephir_update_property_zval(this_ptr, ZEND_STRL("hostname"), &hostname);
	RETURN_THIS();
}

/**
 * Sets the route's name
 *
 *```php
 * $router->add(
 *     "/about",
 *     [
 *         "controller" => "about",
 *     ]
 * )->setName("about");
 *```
 */
PHP_METHOD(Phalcon_Mvc_Router_Route, setName)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *name_param = NULL;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(name)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);
	zephir_get_strval(&name, name_param);


	zephir_update_property_zval(this_ptr, ZEND_STRL("name"), &name);
	RETURN_THIS();
}

/**
 * Set one or more HTTP methods that constraint the matching of the route
 *
 *```php
 * $route->via("GET");
 *
 * $route->via(
 *     [
 *         "GET",
 *         "POST",
 *     ]
 * );
 *```
 */
PHP_METHOD(Phalcon_Mvc_Router_Route, via)
{
	zval *httpMethods, httpMethods_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&httpMethods_sub);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(httpMethods)
	ZEND_PARSE_PARAMETERS_END();
#endif


	zephir_fetch_params_without_memory_grow(1, 0, &httpMethods);


	zephir_update_property_zval(this_ptr, ZEND_STRL("methods"), httpMethods);
	RETURN_THISW();
}

zend_object *zephir_init_properties_Phalcon_Mvc_Router_Route(zend_class_entry *class_type)
{
		zval _0, _2, _4, _1$$3, _3$$4, _5$$5;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_5$$5);
	

		ZEPHIR_MM_GROW();
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property_ex(&_0, this_ptr, ZEND_STRL("paths"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("paths"), &_1$$3);
		}
		zephir_read_property_ex(&_2, this_ptr, ZEND_STRL("methods"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_2) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_3$$4);
			array_init(&_3$$4);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("methods"), &_3$$4);
		}
		zephir_read_property_ex(&_4, this_ptr, ZEND_STRL("converters"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_4) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_5$$5);
			array_init(&_5$$5);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("converters"), &_5$$5);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}
}

