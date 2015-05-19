
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
#include "kernel/hash.h"


/**
 * Phalcon\Cli\Router\Route
 *
 * This class represents every route added to the router
 *
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

	zend_declare_class_constant_string(phalcon_cli_router_route_ce, SL("DEFAULT_DELIMITER"), " " TSRMLS_CC);

	return SUCCESS;

}

/**
 * Phalcon\Cli\Router\Route constructor
 *
 * @param string pattern
 * @param array paths
 */
PHP_METHOD(Phalcon_Cli_Router_Route, __construct) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *pattern_param = NULL, *paths = NULL, *routeId = NULL, *uniqueId = NULL, *delimiter = NULL, *_0;
	zval *pattern = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &pattern_param, &paths);

	if (unlikely(Z_TYPE_P(pattern_param) != IS_STRING && Z_TYPE_P(pattern_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'pattern' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(pattern_param) == IS_STRING)) {
		zephir_get_strval(pattern, pattern_param);
	} else {
		ZEPHIR_INIT_VAR(pattern);
		ZVAL_EMPTY_STRING(pattern);
	}
	if (!paths) {
		paths = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_OBS_VAR(delimiter);
	zephir_read_static_property_ce(&delimiter, phalcon_cli_router_route_ce, SL("_delimiterPath") TSRMLS_CC);
	if (!(zephir_is_true(delimiter))) {
		ZEPHIR_INIT_NVAR(delimiter);
		ZVAL_STRING(delimiter, " ", 1);
	}
	zephir_update_property_this(this_ptr, SL("_delimiter"), delimiter TSRMLS_CC);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "reconfigure", NULL, 0, pattern, paths);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(uniqueId);
	zephir_read_static_property_ce(&uniqueId, phalcon_cli_router_route_ce, SL("_uniqueId") TSRMLS_CC);
	if (Z_TYPE_P(uniqueId) == IS_NULL) {
		ZEPHIR_INIT_NVAR(uniqueId);
		ZVAL_LONG(uniqueId, 0);
	}
	ZEPHIR_CPY_WRT(routeId, uniqueId);
	zephir_update_property_this(this_ptr, SL("_id"), routeId TSRMLS_CC);
	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(_0, (zephir_get_numberval(uniqueId) + 1));
	zephir_update_static_property_ce(phalcon_cli_router_route_ce, SL("_uniqueId"), &_0 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Replaces placeholders from pattern returning a valid PCRE regular expression
 */
PHP_METHOD(Phalcon_Cli_Router_Route, compilePattern) {

	zval *pattern_param = NULL, *idPattern, *part = NULL, *_0, *_1 = NULL, *_2, _3, *_4, *_5 = NULL;
	zval *pattern = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &pattern_param);

	if (unlikely(Z_TYPE_P(pattern_param) != IS_STRING && Z_TYPE_P(pattern_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'pattern' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(pattern_param) == IS_STRING)) {
		zephir_get_strval(pattern, pattern_param);
	} else {
		ZEPHIR_INIT_VAR(pattern);
		ZVAL_EMPTY_STRING(pattern);
	}


	if (zephir_memnstr_str(pattern, SL(":"), "phalcon/cli/router/route.zep", 94)) {
		_0 = zephir_fetch_nproperty_this(this_ptr, SL("_delimiter"), PH_NOISY_CC);
		ZEPHIR_INIT_VAR(idPattern);
		ZEPHIR_CONCAT_VS(idPattern, _0, "([a-zA-Z0-9\\_\\-]+)");
		if (zephir_memnstr_str(pattern, SL(":delimiter"), "phalcon/cli/router/route.zep", 100)) {
			ZEPHIR_INIT_VAR(_1);
			_2 = zephir_fetch_nproperty_this(this_ptr, SL("_delimiter"), PH_NOISY_CC);
			ZEPHIR_SINIT_VAR(_3);
			ZVAL_STRING(&_3, ":delimiter", 0);
			zephir_fast_str_replace(&_1, &_3, _2, pattern TSRMLS_CC);
			zephir_get_strval(pattern, _1);
		}
		_2 = zephir_fetch_nproperty_this(this_ptr, SL("_delimiter"), PH_NOISY_CC);
		ZEPHIR_INIT_VAR(part);
		ZEPHIR_CONCAT_VS(part, _2, ":module");
		if (zephir_memnstr(pattern, part, "phalcon/cli/router/route.zep", 106)) {
			ZEPHIR_INIT_NVAR(_1);
			zephir_fast_str_replace(&_1, part, idPattern, pattern TSRMLS_CC);
			zephir_get_strval(pattern, _1);
		}
		_2 = zephir_fetch_nproperty_this(this_ptr, SL("_delimiter"), PH_NOISY_CC);
		ZEPHIR_INIT_NVAR(part);
		ZEPHIR_CONCAT_VS(part, _2, ":task");
		if (zephir_memnstr(pattern, part, "phalcon/cli/router/route.zep", 112)) {
			ZEPHIR_INIT_NVAR(_1);
			zephir_fast_str_replace(&_1, part, idPattern, pattern TSRMLS_CC);
			zephir_get_strval(pattern, _1);
		}
		_2 = zephir_fetch_nproperty_this(this_ptr, SL("_delimiter"), PH_NOISY_CC);
		ZEPHIR_INIT_NVAR(part);
		ZEPHIR_CONCAT_VS(part, _2, ":namespace");
		if (zephir_memnstr(pattern, part, "phalcon/cli/router/route.zep", 118)) {
			ZEPHIR_INIT_NVAR(_1);
			zephir_fast_str_replace(&_1, part, idPattern, pattern TSRMLS_CC);
			zephir_get_strval(pattern, _1);
		}
		_2 = zephir_fetch_nproperty_this(this_ptr, SL("_delimiter"), PH_NOISY_CC);
		ZEPHIR_INIT_NVAR(part);
		ZEPHIR_CONCAT_VS(part, _2, ":action");
		if (zephir_memnstr(pattern, part, "phalcon/cli/router/route.zep", 124)) {
			ZEPHIR_INIT_NVAR(_1);
			zephir_fast_str_replace(&_1, part, idPattern, pattern TSRMLS_CC);
			zephir_get_strval(pattern, _1);
		}
		_2 = zephir_fetch_nproperty_this(this_ptr, SL("_delimiter"), PH_NOISY_CC);
		ZEPHIR_INIT_NVAR(part);
		ZEPHIR_CONCAT_VS(part, _2, ":params");
		if (zephir_memnstr(pattern, part, "phalcon/cli/router/route.zep", 130)) {
			ZEPHIR_INIT_NVAR(_1);
			_4 = zephir_fetch_nproperty_this(this_ptr, SL("_delimiter"), PH_NOISY_CC);
			ZEPHIR_INIT_VAR(_5);
			ZEPHIR_CONCAT_SVS(_5, "(", _4, ".*)*");
			zephir_fast_str_replace(&_1, part, _5, pattern TSRMLS_CC);
			zephir_get_strval(pattern, _1);
		}
		_2 = zephir_fetch_nproperty_this(this_ptr, SL("_delimiter"), PH_NOISY_CC);
		ZEPHIR_INIT_NVAR(part);
		ZEPHIR_CONCAT_VS(part, _2, ":int");
		if (zephir_memnstr(pattern, part, "phalcon/cli/router/route.zep", 136)) {
			ZEPHIR_INIT_NVAR(_1);
			_4 = zephir_fetch_nproperty_this(this_ptr, SL("_delimiter"), PH_NOISY_CC);
			ZEPHIR_INIT_LNVAR(_5);
			ZEPHIR_CONCAT_VS(_5, _4, "([0-9]+)");
			zephir_fast_str_replace(&_1, part, _5, pattern TSRMLS_CC);
			zephir_get_strval(pattern, _1);
		}
	}
	if (zephir_memnstr_str(pattern, SL("("), "phalcon/cli/router/route.zep", 142)) {
		ZEPHIR_CONCAT_SVS(return_value, "#^", pattern, "$#");
		RETURN_MM();
	}
	if (zephir_memnstr_str(pattern, SL("["), "phalcon/cli/router/route.zep", 147)) {
		ZEPHIR_CONCAT_SVS(return_value, "#^", pattern, "$#");
		RETURN_MM();
	}
	RETURN_CTOR(pattern);

}

/**
 * Extracts parameters from a string
 *
 * @param string pattern
 * @return array|boolean
 */
PHP_METHOD(Phalcon_Cli_Router_Route, extractNamedParams) {

	long _0, _5, _25;
	zend_bool notValid, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17;
	int tmp, cursor, cursorVar, marker, bracketCount = 0, parenthesesCount = 0, foundPattern = 0, intermediate = 0, numberMatches = 0;
	char ch;
	zval *pattern_param = NULL, *matches, _1 = zval_used_for_init, _2 = zval_used_for_init, *_3 = NULL, _18 = zval_used_for_init, _19 = zval_used_for_init, *_20 = NULL, _22 = zval_used_for_init, *_23 = NULL, *_26, *_27 = NULL;
	zval *pattern = NULL, *route, *item = NULL, *variable = NULL, *regexp = NULL, *_4 = NULL, *_21 = NULL, *_24 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &pattern_param);

	if (unlikely(Z_TYPE_P(pattern_param) != IS_STRING && Z_TYPE_P(pattern_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'pattern' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(pattern_param) == IS_STRING)) {
		zephir_get_strval(pattern, pattern_param);
	} else {
		ZEPHIR_INIT_VAR(pattern);
		ZVAL_EMPTY_STRING(pattern);
	}


	if (zephir_fast_strlen_ev(pattern) <= 0) {
		RETURN_MM_BOOL(0);
	}
	ZEPHIR_INIT_VAR(matches);
	array_init(matches);
	ZEPHIR_INIT_VAR(route);
	ZVAL_EMPTY_STRING(route);
	for (_0 = 0; _0 < Z_STRLEN_P(pattern); _0++) {
		cursor = _0; 
		ch = ZEPHIR_STRING_OFFSET(pattern, _0);
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
							ZEPHIR_INIT_NVAR(variable);
							ZVAL_EMPTY_STRING(variable);
							ZEPHIR_INIT_NVAR(regexp);
							ZVAL_EMPTY_STRING(regexp);
							ZEPHIR_SINIT_NVAR(_1);
							ZVAL_LONG(&_1, marker);
							ZEPHIR_SINIT_NVAR(_2);
							ZVAL_LONG(&_2, (cursor - marker));
							ZEPHIR_INIT_NVAR(_3);
							zephir_substr(_3, pattern, zephir_get_intval(&_1), zephir_get_intval(&_2), 0);
							zephir_get_strval(_4, _3);
							ZEPHIR_CPY_WRT(item, _4);
							for (_5 = 0; _5 < Z_STRLEN_P(item); _5++) {
								cursorVar = _5; 
								ch = ZEPHIR_STRING_OFFSET(item, _5);
								if (ch == '\0') {
									break;
								}
								_6 = cursorVar == 0;
								if (_6) {
									_7 = ch >= 'a';
									if (_7) {
										_7 = ch <= 'z';
									}
									_8 = _7;
									if (!(_8)) {
										_9 = ch >= 'A';
										if (_9) {
											_9 = ch <= 'Z';
										}
										_8 = _9;
									}
									_6 = !(_8);
								}
								if (_6) {
									notValid = 1;
									break;
								}
								_10 = ch >= 'a';
								if (_10) {
									_10 = ch <= 'z';
								}
								_11 = _10;
								if (!(_11)) {
									_12 = ch >= 'A';
									if (_12) {
										_12 = ch <= 'Z';
									}
									_11 = _12;
								}
								_13 = _11;
								if (!(_13)) {
									_14 = ch >= '0';
									if (_14) {
										_14 = ch <= '9';
									}
									_13 = _14;
								}
								_15 = _13;
								if (!(_15)) {
									_15 = ch == '-';
								}
								_16 = _15;
								if (!(_16)) {
									_16 = ch == '_';
								}
								_17 = _16;
								if (!(_17)) {
									_17 = ch == ':';
								}
								if (_17) {
									if (ch == ':') {
										ZEPHIR_SINIT_NVAR(_18);
										ZVAL_LONG(&_18, 0);
										ZEPHIR_SINIT_NVAR(_19);
										ZVAL_LONG(&_19, cursorVar);
										ZEPHIR_INIT_NVAR(_20);
										zephir_substr(_20, item, 0 , zephir_get_intval(&_19), 0);
										zephir_get_strval(_21, _20);
										ZEPHIR_CPY_WRT(variable, _21);
										ZEPHIR_SINIT_NVAR(_22);
										ZVAL_LONG(&_22, (cursorVar + 1));
										ZEPHIR_INIT_NVAR(_23);
										zephir_substr(_23, item, zephir_get_intval(&_22), 0, ZEPHIR_SUBSTR_NO_LENGTH);
										zephir_get_strval(_24, _23);
										ZEPHIR_CPY_WRT(regexp, _24);
										break;
									}
								} else {
									notValid = 1;
									break;
								}
							}
							if (!(notValid)) {
								tmp = numberMatches;
								_6 = zephir_is_true(variable);
								if (_6) {
									_6 = zephir_is_true(regexp);
								}
								if (_6) {
									foundPattern = 0;
									for (_25 = 0; _25 < Z_STRLEN_P(regexp); _25++) {
										ch = ZEPHIR_STRING_OFFSET(regexp, _25);
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
										zephir_concat_self(&route, regexp TSRMLS_CC);
										zephir_concat_self_str(&route, ")", sizeof(")")-1 TSRMLS_CC);
									} else {
										zephir_concat_self(&route, regexp TSRMLS_CC);
									}
									ZEPHIR_INIT_NVAR(_20);
									ZVAL_LONG(_20, tmp);
									zephir_array_update_zval(&matches, variable, &_20, PH_COPY | PH_SEPARATE);
								} else {
									_26 = zephir_fetch_nproperty_this(this_ptr, SL("_delimiter"), PH_NOISY_CC);
									ZEPHIR_INIT_LNVAR(_27);
									ZEPHIR_CONCAT_SVS(_27, "([^", _26, "]*)");
									zephir_concat_self(&route, _27 TSRMLS_CC);
									ZEPHIR_INIT_NVAR(_23);
									ZVAL_LONG(_23, tmp);
									zephir_array_update_zval(&matches, item, &_23, PH_COPY | PH_SEPARATE);
								}
							} else {
								zephir_concat_self_str(&route, "{", sizeof("{")-1 TSRMLS_CC);
								zephir_concat_self(&route, item TSRMLS_CC);
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
	zephir_array_fast_append(return_value, route);
	zephir_array_fast_append(return_value, matches);
	RETURN_MM();

}

/**
 * Reconfigure the route adding a new pattern and a set of paths
 *
 * @param string pattern
 * @param array paths
 */
PHP_METHOD(Phalcon_Cli_Router_Route, reConfigure) {

	int _0, ZEPHIR_LAST_CALL_STATUS;
	zval *pattern_param = NULL, *paths = NULL, *moduleName = NULL, *taskName = NULL, *actionName = NULL, *parts, *routePaths = NULL, *realClassName = NULL, *namespaceName, *pcrePattern = NULL, *compiledPattern = NULL, *extracted = NULL, *_1 = NULL, *_2, *_3, _4;
	zval *pattern = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &pattern_param, &paths);

	if (unlikely(Z_TYPE_P(pattern_param) != IS_STRING && Z_TYPE_P(pattern_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'pattern' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(pattern_param) == IS_STRING)) {
		zephir_get_strval(pattern, pattern_param);
	} else {
		ZEPHIR_INIT_VAR(pattern);
		ZVAL_EMPTY_STRING(pattern);
	}
	if (!paths) {
		paths = ZEPHIR_GLOBAL(global_null);
	}


	if (Z_TYPE_P(paths) != IS_NULL) {
		if (Z_TYPE_P(paths) == IS_STRING) {
			ZEPHIR_INIT_VAR(moduleName);
			ZVAL_NULL(moduleName);
			ZEPHIR_INIT_VAR(taskName);
			ZVAL_NULL(taskName);
			ZEPHIR_INIT_VAR(actionName);
			ZVAL_NULL(actionName);
			ZEPHIR_INIT_VAR(parts);
			zephir_fast_explode_str(parts, SL("::"), paths, LONG_MAX TSRMLS_CC);
			do {
				_0 = zephir_fast_count_int(parts TSRMLS_CC);
				if (_0 == 3) {
					ZEPHIR_OBS_NVAR(moduleName);
					zephir_array_fetch_long(&moduleName, parts, 0, PH_NOISY, "phalcon/cli/router/route.zep", 318 TSRMLS_CC);
					ZEPHIR_OBS_NVAR(taskName);
					zephir_array_fetch_long(&taskName, parts, 1, PH_NOISY, "phalcon/cli/router/route.zep", 319 TSRMLS_CC);
					ZEPHIR_OBS_NVAR(actionName);
					zephir_array_fetch_long(&actionName, parts, 2, PH_NOISY, "phalcon/cli/router/route.zep", 320 TSRMLS_CC);
					break;
				}
				if (_0 == 2) {
					ZEPHIR_OBS_NVAR(taskName);
					zephir_array_fetch_long(&taskName, parts, 0, PH_NOISY, "phalcon/cli/router/route.zep", 324 TSRMLS_CC);
					ZEPHIR_OBS_NVAR(actionName);
					zephir_array_fetch_long(&actionName, parts, 1, PH_NOISY, "phalcon/cli/router/route.zep", 325 TSRMLS_CC);
					break;
				}
				if (_0 == 1) {
					ZEPHIR_OBS_NVAR(taskName);
					zephir_array_fetch_long(&taskName, parts, 0, PH_NOISY, "phalcon/cli/router/route.zep", 329 TSRMLS_CC);
					break;
				}
			} while(0);

			ZEPHIR_INIT_VAR(routePaths);
			array_init(routePaths);
			if (Z_TYPE_P(moduleName) != IS_NULL) {
				zephir_array_update_string(&routePaths, SL("module"), &moduleName, PH_COPY | PH_SEPARATE);
			}
			if (Z_TYPE_P(taskName) != IS_NULL) {
				if (zephir_memnstr_str(taskName, SL("\\"), "phalcon/cli/router/route.zep", 344)) {
					ZEPHIR_INIT_VAR(realClassName);
					zephir_get_class_ns(realClassName, taskName, 0 TSRMLS_CC);
					ZEPHIR_INIT_VAR(namespaceName);
					zephir_get_ns_class(namespaceName, taskName, 0 TSRMLS_CC);
					if (zephir_is_true(namespaceName)) {
						zephir_array_update_string(&routePaths, SL("namespace"), &namespaceName, PH_COPY | PH_SEPARATE);
					}
				} else {
					ZEPHIR_CPY_WRT(realClassName, taskName);
				}
				ZEPHIR_INIT_VAR(_1);
				zephir_uncamelize(_1, realClassName);
				zephir_array_update_string(&routePaths, SL("task"), &_1, PH_COPY | PH_SEPARATE);
			}
			if (Z_TYPE_P(actionName) != IS_NULL) {
				zephir_array_update_string(&routePaths, SL("action"), &actionName, PH_COPY | PH_SEPARATE);
			}
		} else {
			ZEPHIR_CPY_WRT(routePaths, paths);
		}
	} else {
		ZEPHIR_INIT_NVAR(routePaths);
		array_init(routePaths);
	}
	if (Z_TYPE_P(routePaths) != IS_ARRAY) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_cli_router_exception_ce, "The route contains invalid paths", "phalcon/cli/router/route.zep", 376);
		return;
	}
	if (!(zephir_start_with_str(pattern, SL("#")))) {
		if (zephir_memnstr_str(pattern, SL("{"), "phalcon/cli/router/route.zep", 384)) {
			ZEPHIR_CALL_METHOD(&extracted, this_ptr, "extractnamedparams", NULL, 0, pattern);
			zephir_check_call_status();
			ZEPHIR_OBS_VAR(pcrePattern);
			zephir_array_fetch_long(&pcrePattern, extracted, 0, PH_NOISY, "phalcon/cli/router/route.zep", 389 TSRMLS_CC);
			ZEPHIR_INIT_NVAR(_1);
			zephir_array_fetch_long(&_2, extracted, 1, PH_NOISY | PH_READONLY, "phalcon/cli/router/route.zep", 390 TSRMLS_CC);
			zephir_fast_array_merge(_1, &(routePaths), &(_2) TSRMLS_CC);
			ZEPHIR_CPY_WRT(routePaths, _1);
		} else {
			ZEPHIR_CPY_WRT(pcrePattern, pattern);
		}
		ZEPHIR_CALL_METHOD(&compiledPattern, this_ptr, "compilepattern", NULL, 0, pcrePattern);
		zephir_check_call_status();
	} else {
		if (zephir_memnstr_str(pattern, SL(":delimiter"), "phalcon/cli/router/route.zep", 401)) {
			ZEPHIR_INIT_NVAR(_1);
			_3 = zephir_fetch_nproperty_this(this_ptr, SL("_delimiter"), PH_NOISY_CC);
			ZEPHIR_SINIT_VAR(_4);
			ZVAL_STRING(&_4, ":delimiter", 0);
			zephir_fast_str_replace(&_1, &_4, _3, pattern TSRMLS_CC);
			zephir_get_strval(pattern, _1);
		}
		ZEPHIR_CPY_WRT(compiledPattern, pattern);
	}
	zephir_update_property_this(this_ptr, SL("_pattern"), pattern TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("_compiledPattern"), compiledPattern TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("_paths"), routePaths TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Returns the route's name
 */
PHP_METHOD(Phalcon_Cli_Router_Route, getName) {


	RETURN_MEMBER(this_ptr, "_name");

}

/**
 * Sets the route's name
 *
 *<code>
 * $router->add('/about', array(
 *     'controller' => 'about'
 * ))->setName('about');
 *</code>
 */
PHP_METHOD(Phalcon_Cli_Router_Route, setName) {

	zval *name_param = NULL;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

	if (unlikely(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(name_param) == IS_STRING)) {
		zephir_get_strval(name, name_param);
	} else {
		ZEPHIR_INIT_VAR(name);
		ZVAL_EMPTY_STRING(name);
	}


	zephir_update_property_this(this_ptr, SL("_name"), name TSRMLS_CC);
	RETURN_THIS();

}

/**
 * Sets a callback that is called if the route is matched.
 * The developer can implement any arbitrary conditions here
 * If the callback returns false the route is treated as not matched
 *
 * @param callback callback
 * @return Phalcon\Cli\Router\Route
 */
PHP_METHOD(Phalcon_Cli_Router_Route, beforeMatch) {

	zval *callback;

	zephir_fetch_params(0, 1, 0, &callback);



	zephir_update_property_this(this_ptr, SL("_beforeMatch"), callback TSRMLS_CC);
	RETURN_THISW();

}

/**
 * Returns the 'before match' callback if any
 *
 * @return mixed
 */
PHP_METHOD(Phalcon_Cli_Router_Route, getBeforeMatch) {


	RETURN_MEMBER(this_ptr, "_beforeMatch");

}

/**
 * Returns the route's id
 */
PHP_METHOD(Phalcon_Cli_Router_Route, getRouteId) {


	RETURN_MEMBER(this_ptr, "_id");

}

/**
 * Returns the route's pattern
 */
PHP_METHOD(Phalcon_Cli_Router_Route, getPattern) {


	RETURN_MEMBER(this_ptr, "_pattern");

}

/**
 * Returns the route's compiled pattern
 */
PHP_METHOD(Phalcon_Cli_Router_Route, getCompiledPattern) {


	RETURN_MEMBER(this_ptr, "_compiledPattern");

}

/**
 * Returns the paths
 */
PHP_METHOD(Phalcon_Cli_Router_Route, getPaths) {


	RETURN_MEMBER(this_ptr, "_paths");

}

/**
 * Returns the paths using positions as keys and names as values
 */
PHP_METHOD(Phalcon_Cli_Router_Route, getReversedPaths) {

	HashTable *_2;
	HashPosition _1;
	zval *reversed, *path = NULL, *position = NULL, *_0, **_3;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(reversed);
	array_init(reversed);
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_paths"), PH_NOISY_CC);
	zephir_is_iterable(_0, &_2, &_1, 0, 0, "phalcon/cli/router/route.zep", 513);
	for (
	  ; zephir_hash_get_current_data_ex(_2, (void**) &_3, &_1) == SUCCESS
	  ; zephir_hash_move_forward_ex(_2, &_1)
	) {
		ZEPHIR_GET_HMKEY(path, _2, _1);
		ZEPHIR_GET_HVALUE(position, _3);
		zephir_array_update_zval(&reversed, position, &path, PH_COPY | PH_SEPARATE);
	}
	RETURN_CCTOR(reversed);

}

/**
 * Adds a converter to perform an additional transformation for certain parameter
 *
 * @param string name
 * @param callable converter
 * @return Phalcon\Cli\Router\Route
 */
PHP_METHOD(Phalcon_Cli_Router_Route, convert) {

	zval *name_param = NULL, *converter;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &name_param, &converter);

	if (unlikely(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(name_param) == IS_STRING)) {
		zephir_get_strval(name, name_param);
	} else {
		ZEPHIR_INIT_VAR(name);
		ZVAL_EMPTY_STRING(name);
	}


	zephir_update_property_array(this_ptr, SL("_converters"), name, converter TSRMLS_CC);
	RETURN_THIS();

}

/**
 * Returns the router converter
 */
PHP_METHOD(Phalcon_Cli_Router_Route, getConverters) {


	RETURN_MEMBER(this_ptr, "_converters");

}

/**
 * Resets the internal route id generator
 */
PHP_METHOD(Phalcon_Cli_Router_Route, reset) {


	zephir_update_static_property_ce(phalcon_cli_router_route_ce, SL("_uniqueId"), &(ZEPHIR_GLOBAL(global_null)) TSRMLS_CC);

}

/**
 * Set the routing delimiter
 */
PHP_METHOD(Phalcon_Cli_Router_Route, delimiter) {

	zval *delimiter_param = NULL;
	zval *delimiter = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &delimiter_param);

	if (!delimiter_param) {
		ZEPHIR_INIT_VAR(delimiter);
		ZVAL_EMPTY_STRING(delimiter);
	} else {
	if (unlikely(Z_TYPE_P(delimiter_param) != IS_STRING && Z_TYPE_P(delimiter_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'delimiter' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(delimiter_param) == IS_STRING)) {
		zephir_get_strval(delimiter, delimiter_param);
	} else {
		ZEPHIR_INIT_VAR(delimiter);
		ZVAL_EMPTY_STRING(delimiter);
	}
	}


	zephir_update_static_property_ce(phalcon_cli_router_route_ce, SL("_delimiterPath"), &delimiter TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Get routing delimiter
 */
PHP_METHOD(Phalcon_Cli_Router_Route, getDelimiter) {

	zval *delimiter = NULL;

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(delimiter);
	zephir_read_static_property_ce(&delimiter, phalcon_cli_router_route_ce, SL("_delimiterPath") TSRMLS_CC);
	if (!(zephir_is_true(delimiter))) {
		ZEPHIR_INIT_NVAR(delimiter);
		ZVAL_STRING(delimiter, " ", 1);
	}
	RETURN_CCTOR(delimiter);

}

