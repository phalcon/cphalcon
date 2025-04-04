
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
#include "kernel/fcall.h"
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
 * This class represents every route added to the router
 */
ZEPHIR_INIT_CLASS(Phalcon_Cli_Router_Route)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\Cli\\Router, Route, phalcon, cli_router_route, phalcon_cli_router_route_method_entry, 0);

	/**
	 * @var mixed|null
	 */
	zend_declare_property_null(phalcon_cli_router_route_ce, SL("beforeMatch"), ZEND_ACC_PROTECTED);
	/**
	 * @var string
	 */
	zend_declare_property_string(phalcon_cli_router_route_ce, SL("compiledPattern"), "", ZEND_ACC_PROTECTED);
	/**
	 * @var array
	 */
	zend_declare_property_null(phalcon_cli_router_route_ce, SL("converters"), ZEND_ACC_PROTECTED);
	/**
	 * @var string
	 */
	zend_declare_property_null(phalcon_cli_router_route_ce, SL("delimiter"), ZEND_ACC_PROTECTED);
	/**
	 * @var string
	 */
	zend_declare_property_string(phalcon_cli_router_route_ce, SL("delimiterPath"), " ", ZEND_ACC_PROTECTED|ZEND_ACC_STATIC);
	/**
	 * @var string
	 */
	zend_declare_property_string(phalcon_cli_router_route_ce, SL("description"), "", ZEND_ACC_PROTECTED);
	/**
	 * @var string
	 */
	zend_declare_property_null(phalcon_cli_router_route_ce, SL("routeId"), ZEND_ACC_PROTECTED);
	/**
	 * @var string
	 */
	zend_declare_property_string(phalcon_cli_router_route_ce, SL("name"), "", ZEND_ACC_PROTECTED);
	/**
	 * @var array
	 */
	zend_declare_property_null(phalcon_cli_router_route_ce, SL("paths"), ZEND_ACC_PROTECTED);
	/**
	 * @var string
	 */
	zend_declare_property_string(phalcon_cli_router_route_ce, SL("pattern"), "", ZEND_ACC_PROTECTED);
	/**
	 * @var int
	 */
	zend_declare_property_long(phalcon_cli_router_route_ce, SL("uniqueId"), 0, ZEND_ACC_PROTECTED|ZEND_ACC_STATIC);
	phalcon_cli_router_route_ce->create_object = zephir_init_properties_Phalcon_Cli_Router_Route;
	zephir_declare_class_constant_string(phalcon_cli_router_route_ce, SL("DEFAULT_DELIMITER"), " ");

	zend_class_implements(phalcon_cli_router_route_ce, 1, phalcon_cli_router_routeinterface_ce);
	return SUCCESS;
}

/**
 * @param array|string paths
 */
PHP_METHOD(Phalcon_Cli_Router_Route, __construct)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *pattern_param = NULL, *paths = NULL, paths_sub, __$null, routeId, uniqueId, _0, _1;
	zval pattern, _2;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&pattern);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&paths_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&routeId);
	ZVAL_UNDEF(&uniqueId);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_STR(pattern)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(paths)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
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
	zephir_memory_observe(&_0);
	zephir_read_static_property_ce(&_0, phalcon_cli_router_route_ce, SL("delimiterPath"), PH_NOISY_CC);
	zephir_update_property_zval(this_ptr, ZEND_STRL("delimiter"), &_0);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "reconfigure", NULL, 0, &pattern, paths);
	zephir_check_call_status();
	zephir_memory_observe(&_1);
	zephir_read_static_property_ce(&_1, phalcon_cli_router_route_ce, SL("uniqueId"), PH_NOISY_CC);
	ZEPHIR_CPY_WRT(&uniqueId, &_1);
	ZEPHIR_CPY_WRT(&routeId, &uniqueId);
	zephir_cast_to_string(&_2, &routeId);
	zephir_update_property_zval(this_ptr, ZEND_STRL("routeId"), &_2);
	ZVAL_UNDEF(&_1);
	ZVAL_LONG(&_1, (zephir_get_numberval(&uniqueId) + 1));
	zephir_update_static_property_ce(phalcon_cli_router_route_ce, ZEND_STRL("uniqueId"), &_1);
	ZEPHIR_MM_RESTORE();
}

/**
 * Sets a callback that is called if the route is matched.
 * The developer can implement any arbitrary conditions here
 * If the callback returns false the route is treated as not matched
 *
 * @param mixed callback
 */
PHP_METHOD(Phalcon_Cli_Router_Route, beforeMatch)
{
	zval *callback, callback_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&callback_sub);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(callback)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &callback);
	zephir_update_property_zval(this_ptr, ZEND_STRL("beforeMatch"), callback);
	RETURN_THISW();
}

/**
 * Replaces placeholders from pattern returning a valid PCRE regular
 * expression
 */
PHP_METHOD(Phalcon_Cli_Router_Route, compilePattern)
{
	zend_bool _20;
	zval map;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *pattern_param = NULL, idPattern, _0$$3, _1$$3, _2$$3, _3$$3, _4$$3, _5$$3, _6$$3, _7$$3, _8$$3, _9$$3, _10$$3, _11$$3, _12$$3, _13$$3, _14$$3, _15$$3, _16$$3, _17$$3, _18$$3, _19$$3;
	zval pattern;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&pattern);
	ZVAL_UNDEF(&idPattern);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_7$$3);
	ZVAL_UNDEF(&_8$$3);
	ZVAL_UNDEF(&_9$$3);
	ZVAL_UNDEF(&_10$$3);
	ZVAL_UNDEF(&_11$$3);
	ZVAL_UNDEF(&_12$$3);
	ZVAL_UNDEF(&_13$$3);
	ZVAL_UNDEF(&_14$$3);
	ZVAL_UNDEF(&_15$$3);
	ZVAL_UNDEF(&_16$$3);
	ZVAL_UNDEF(&_17$$3);
	ZVAL_UNDEF(&_18$$3);
	ZVAL_UNDEF(&_19$$3);
	ZVAL_UNDEF(&map);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(pattern)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
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
	if (zephir_memnstr_str(&pattern, SL(":"), "phalcon/Cli/Router/Route.zep", 121)) {
		zephir_read_property(&_0$$3, this_ptr, ZEND_STRL("delimiter"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_VAR(&idPattern);
		ZEPHIR_CONCAT_VS(&idPattern, &_0$$3, "([a-zA-Z0-9\\_\\-]+)");
		ZEPHIR_INIT_VAR(&map);
		zephir_create_array(&map, 7, 0);
		zephir_memory_observe(&_1$$3);
		zephir_read_property(&_1$$3, this_ptr, ZEND_STRL("delimiter"), PH_NOISY_CC);
		zephir_array_update_string(&map, SL(":delimiter"), &_1$$3, PH_COPY | PH_SEPARATE);
		zephir_read_property(&_2$$3, this_ptr, ZEND_STRL("delimiter"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_VAR(&_3$$3);
		ZEPHIR_CONCAT_VS(&_3$$3, &_2$$3, ":module");
		zephir_array_update_zval(&map, &_3$$3, &idPattern, PH_COPY);
		zephir_read_property(&_4$$3, this_ptr, ZEND_STRL("delimiter"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_VAR(&_5$$3);
		ZEPHIR_CONCAT_VS(&_5$$3, &_4$$3, ":task");
		zephir_array_update_zval(&map, &_5$$3, &idPattern, PH_COPY);
		zephir_read_property(&_6$$3, this_ptr, ZEND_STRL("delimiter"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_VAR(&_7$$3);
		ZEPHIR_CONCAT_VS(&_7$$3, &_6$$3, ":namespace");
		zephir_array_update_zval(&map, &_7$$3, &idPattern, PH_COPY);
		zephir_read_property(&_8$$3, this_ptr, ZEND_STRL("delimiter"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_VAR(&_9$$3);
		ZEPHIR_CONCAT_VS(&_9$$3, &_8$$3, ":action");
		zephir_array_update_zval(&map, &_9$$3, &idPattern, PH_COPY);
		zephir_read_property(&_10$$3, this_ptr, ZEND_STRL("delimiter"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_VAR(&_11$$3);
		ZEPHIR_CONCAT_VS(&_11$$3, &_10$$3, ":params");
		zephir_read_property(&_12$$3, this_ptr, ZEND_STRL("delimiter"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_VAR(&_13$$3);
		ZEPHIR_CONCAT_SVS(&_13$$3, "(", &_12$$3, ".*)*");
		zephir_array_update_zval(&map, &_11$$3, &_13$$3, PH_COPY);
		zephir_read_property(&_14$$3, this_ptr, ZEND_STRL("delimiter"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_NVAR(&_13$$3);
		ZEPHIR_CONCAT_VS(&_13$$3, &_14$$3, ":int");
		zephir_read_property(&_15$$3, this_ptr, ZEND_STRL("delimiter"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_VAR(&_16$$3);
		ZEPHIR_CONCAT_VS(&_16$$3, &_15$$3, "([0-9]+)");
		zephir_array_update_zval(&map, &_13$$3, &_16$$3, PH_COPY);
		ZEPHIR_INIT_VAR(&_17$$3);
		ZEPHIR_INIT_VAR(&_18$$3);
		zephir_array_keys(&_18$$3, &map);
		ZEPHIR_CALL_FUNCTION(&_19$$3, "array_values", NULL, 14, &map);
		zephir_check_call_status();
		zephir_fast_str_replace(&_17$$3, &_18$$3, &_19$$3, &pattern);
		zephir_get_strval(&pattern, &_17$$3);
	}
	_20 = zephir_memnstr_str(&pattern, SL("("), "phalcon/Cli/Router/Route.zep", 146);
	if (!(_20)) {
		_20 = zephir_memnstr_str(&pattern, SL("["), "phalcon/Cli/Router/Route.zep", 146);
	}
	if (_20) {
		ZEPHIR_CONCAT_SVS(return_value, "#^", &pattern, "$#");
		RETURN_MM();
	}
	RETURN_CTOR(&pattern);
}

/**
 * Adds a converter to perform an additional transformation for certain
 * parameter
 *
 * @param callable converter
 */
PHP_METHOD(Phalcon_Cli_Router_Route, convert)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *name_param = NULL, *converter, converter_sub;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&converter_sub);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR(name)
		Z_PARAM_ZVAL(converter)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
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
 * Set the routing delimiter
 */
PHP_METHOD(Phalcon_Cli_Router_Route, delimiter)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *delimiter_param = NULL;
	zval delimiter;

	ZVAL_UNDEF(&delimiter);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR_OR_NULL(delimiter)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 0, 1, &delimiter_param);
	if (!delimiter_param) {
		ZEPHIR_INIT_VAR(&delimiter);
	} else {
	if (UNEXPECTED(Z_TYPE_P(delimiter_param) != IS_STRING && Z_TYPE_P(delimiter_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'delimiter' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(delimiter_param) == IS_STRING)) {
		zephir_get_strval(&delimiter, delimiter_param);
	} else {
		ZEPHIR_INIT_VAR(&delimiter);
	}
	}
	zephir_update_static_property_ce(phalcon_cli_router_route_ce, ZEND_STRL("delimiterPath"), &delimiter);
	ZEPHIR_MM_RESTORE();
}

/**
 * Extracts parameters from a string
 */
PHP_METHOD(Phalcon_Cli_Router_Route, extractNamedParams)
{
	long _0, _5$$10, _26$$18;
	zend_long cursor = 0, cursorVar = 0, marker = 0, bracketCount, parenthesesCount, foundPattern, intermediate, numberMatches;
	zend_bool notValid = 0, _6$$11, _7$$11, _8$$11, _9$$11, _10$$11, _11$$11, _12$$11, _13$$11, _14$$11, _15$$11, _16$$11, _17$$11, _25$$17;
	zval matches;
	char ch = 0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *pattern_param = NULL, tmp, _1$$10, _2$$10, _3$$10, _18$$15, _19$$15, _20$$15, _22$$15, _23$$15, _28$$27, _29$$27;
	zval pattern, route, item, variable, regexp, _4$$10, _21$$15, _24$$15, _27$$25, _30$$28;
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
	ZVAL_UNDEF(&_30$$28);
	ZVAL_UNDEF(&tmp);
	ZVAL_UNDEF(&_1$$10);
	ZVAL_UNDEF(&_2$$10);
	ZVAL_UNDEF(&_3$$10);
	ZVAL_UNDEF(&_18$$15);
	ZVAL_UNDEF(&_19$$15);
	ZVAL_UNDEF(&_20$$15);
	ZVAL_UNDEF(&_22$$15);
	ZVAL_UNDEF(&_23$$15);
	ZVAL_UNDEF(&_28$$27);
	ZVAL_UNDEF(&_29$$27);
	ZVAL_UNDEF(&matches);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(pattern)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
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
								zephir_read_property(&_28$$27, this_ptr, ZEND_STRL("delimiter"), PH_NOISY_CC | PH_READONLY);
								ZEPHIR_INIT_NVAR(&_29$$27);
								ZEPHIR_CONCAT_SVS(&_29$$27, "([^", &_28$$27, "]*)");
								zephir_concat_self(&route, &_29$$27);
								zephir_array_update_zval(&matches, &item, &tmp, PH_COPY | PH_SEPARATE);
							}
						} else {
							ZEPHIR_INIT_NVAR(&_30$$28);
							ZEPHIR_CONCAT_SVS(&_30$$28, "{", &item, "}");
							zephir_concat_self(&route, &_30$$28);
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
			zephir_concat_self_char(&route, ch);
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
PHP_METHOD(Phalcon_Cli_Router_Route, getBeforeMatch)
{

	RETURN_MEMBER(getThis(), "beforeMatch");
}

/**
 * Returns the route's compiled pattern
 */
PHP_METHOD(Phalcon_Cli_Router_Route, getCompiledPattern)
{

	RETURN_MEMBER(getThis(), "compiledPattern");
}

/**
 * Returns the router converter
 */
PHP_METHOD(Phalcon_Cli_Router_Route, getConverters)
{

	RETURN_MEMBER(getThis(), "converters");
}

/**
 * Get routing delimiter
 */
PHP_METHOD(Phalcon_Cli_Router_Route, getDelimiter)
{
	zval _0;

	ZVAL_UNDEF(&_0);
	zephir_read_static_property_ce(&_0, phalcon_cli_router_route_ce, SL("delimiterPath"), PH_NOISY_CC | PH_READONLY);
	RETURN_CTORW(&_0);
}

/**
 * Returns the route's description
 */
PHP_METHOD(Phalcon_Cli_Router_Route, getDescription)
{

	RETURN_MEMBER(getThis(), "description");
}

/**
 * Returns the route's name
 */
PHP_METHOD(Phalcon_Cli_Router_Route, getName)
{

	RETURN_MEMBER(getThis(), "name");
}

/**
 * Returns the paths
 */
PHP_METHOD(Phalcon_Cli_Router_Route, getPaths)
{

	RETURN_MEMBER(getThis(), "paths");
}

/**
 * Returns the route's pattern
 */
PHP_METHOD(Phalcon_Cli_Router_Route, getPattern)
{

	RETURN_MEMBER(getThis(), "pattern");
}

/**
 * Returns the paths using positions as keys and names as values
 */
PHP_METHOD(Phalcon_Cli_Router_Route, getReversedPaths)
{
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	zephir_read_property(&_0, this_ptr, ZEND_STRL("paths"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_FUNCTION("array_flip", NULL, 101, &_0);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Returns the route's id
 */
PHP_METHOD(Phalcon_Cli_Router_Route, getRouteId)
{

	RETURN_MEMBER(getThis(), "routeId");
}

/**
 * Reconfigure the route adding a new pattern and a set of paths
 *
 * @param string pattern
 * @param array|string|null paths
 *
 * @return void
 */
PHP_METHOD(Phalcon_Cli_Router_Route, reConfigure)
{
	zend_bool _1$$10;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS, _0$$4;
	zval *pattern_param = NULL, *paths = NULL, paths_sub, __$null, moduleName, taskName, actionName, parts, routePaths, realClassName, namespaceName, pcrePattern, compiledPattern, extracted, _2$$9, _3$$18, _4$$18, _5$$21, _6$$21, _7$$21;
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
	ZVAL_UNDEF(&_2$$9);
	ZVAL_UNDEF(&_3$$18);
	ZVAL_UNDEF(&_4$$18);
	ZVAL_UNDEF(&_5$$21);
	ZVAL_UNDEF(&_6$$21);
	ZVAL_UNDEF(&_7$$21);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_STR(pattern)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(paths)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
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
		ZEPHIR_INIT_VAR(&taskName);
		ZVAL_NULL(&taskName);
		ZEPHIR_INIT_VAR(&actionName);
		ZVAL_NULL(&actionName);
		ZEPHIR_INIT_VAR(&parts);
		zephir_fast_explode_str(&parts, SL("::"), paths, LONG_MAX);
		do {
			_0$$4 = zephir_fast_count_int(&parts);
			if (_0$$4 == 3) {
				ZEPHIR_OBS_NVAR(&moduleName);
				zephir_array_fetch_long(&moduleName, &parts, 0, PH_NOISY, "phalcon/Cli/Router/Route.zep", 417);
				ZEPHIR_OBS_NVAR(&taskName);
				zephir_array_fetch_long(&taskName, &parts, 1, PH_NOISY, "phalcon/Cli/Router/Route.zep", 418);
				ZEPHIR_OBS_NVAR(&actionName);
				zephir_array_fetch_long(&actionName, &parts, 2, PH_NOISY, "phalcon/Cli/Router/Route.zep", 419);
				break;
			}
			if (_0$$4 == 2) {
				ZEPHIR_OBS_NVAR(&taskName);
				zephir_array_fetch_long(&taskName, &parts, 0, PH_NOISY, "phalcon/Cli/Router/Route.zep", 423);
				ZEPHIR_OBS_NVAR(&actionName);
				zephir_array_fetch_long(&actionName, &parts, 1, PH_NOISY, "phalcon/Cli/Router/Route.zep", 424);
				break;
			}
			if (_0$$4 == 1) {
				ZEPHIR_OBS_NVAR(&taskName);
				zephir_array_fetch_long(&taskName, &parts, 0, PH_NOISY, "phalcon/Cli/Router/Route.zep", 428);
				break;
			}
		} while(0);

		ZEPHIR_INIT_VAR(&routePaths);
		array_init(&routePaths);
		if (Z_TYPE_P(&moduleName) != IS_NULL) {
			zephir_array_update_string(&routePaths, SL("module"), &moduleName, PH_COPY | PH_SEPARATE);
		}
		if (Z_TYPE_P(&taskName) != IS_NULL) {
			if (zephir_memnstr_str(&taskName, SL("\\"), "phalcon/Cli/Router/Route.zep", 442)) {
				ZEPHIR_INIT_VAR(&realClassName);
				zephir_get_class_ns(&realClassName, &taskName, 0);
				ZEPHIR_INIT_VAR(&namespaceName);
				zephir_get_ns_class(&namespaceName, &taskName, 0);
				_1$$10 = Z_TYPE_P(&namespaceName) == IS_NULL;
				if (!(_1$$10)) {
					_1$$10 = Z_TYPE_P(&realClassName) == IS_NULL;
				}
				if (UNEXPECTED(_1$$10)) {
					ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_cli_router_exception_ce, "The route contains invalid paths", "phalcon/Cli/Router/Route.zep", 452);
					return;
				}
				if (zephir_is_true(&namespaceName)) {
					zephir_array_update_string(&routePaths, SL("namespace"), &namespaceName, PH_COPY | PH_SEPARATE);
				}
			} else {
				ZEPHIR_CPY_WRT(&realClassName, &taskName);
			}
			ZEPHIR_INIT_VAR(&_2$$9);
			zephir_uncamelize(&_2$$9, &realClassName, NULL );
			zephir_array_update_string(&routePaths, SL("task"), &_2$$9, PH_COPY | PH_SEPARATE);
		}
		if (Z_TYPE_P(&actionName) != IS_NULL) {
			zephir_array_update_string(&routePaths, SL("action"), &actionName, PH_COPY | PH_SEPARATE);
		}
	} else {
		ZEPHIR_CPY_WRT(&routePaths, paths);
	}
	if (UNEXPECTED(Z_TYPE_P(&routePaths) != IS_ARRAY)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_cli_router_exception_ce, "The route contains invalid paths", "phalcon/Cli/Router/Route.zep", 476);
		return;
	}
	if (!(zephir_start_with_str(&pattern, SL("#")))) {
		if (zephir_memnstr_str(&pattern, SL("{"), "phalcon/Cli/Router/Route.zep", 484)) {
			ZEPHIR_CALL_METHOD(&extracted, this_ptr, "extractnamedparams", NULL, 0, &pattern);
			zephir_check_call_status();
			zephir_memory_observe(&pcrePattern);
			zephir_array_fetch_long(&pcrePattern, &extracted, 0, PH_NOISY, "phalcon/Cli/Router/Route.zep", 489);
			ZEPHIR_INIT_VAR(&_3$$18);
			zephir_array_fetch_long(&_4$$18, &extracted, 1, PH_NOISY | PH_READONLY, "phalcon/Cli/Router/Route.zep", 490);
			zephir_fast_array_merge(&_3$$18, &routePaths, &_4$$18);
			ZEPHIR_CPY_WRT(&routePaths, &_3$$18);
		} else {
			ZEPHIR_CPY_WRT(&pcrePattern, &pattern);
		}
		ZEPHIR_CALL_METHOD(&compiledPattern, this_ptr, "compilepattern", NULL, 0, &pcrePattern);
		zephir_check_call_status();
	} else {
		if (zephir_memnstr_str(&pattern, SL(":delimiter"), "phalcon/Cli/Router/Route.zep", 501)) {
			ZEPHIR_INIT_VAR(&_5$$21);
			zephir_read_property(&_6$$21, this_ptr, ZEND_STRL("delimiter"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_INIT_VAR(&_7$$21);
			ZVAL_STRING(&_7$$21, ":delimiter");
			zephir_fast_str_replace(&_5$$21, &_7$$21, &_6$$21, &pattern);
			zephir_get_strval(&pattern, &_5$$21);
		}
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
PHP_METHOD(Phalcon_Cli_Router_Route, reset)
{
	zval _0;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_0);
	ZVAL_LONG(&_0, 0);
	zephir_update_static_property_ce(phalcon_cli_router_route_ce, ZEND_STRL("uniqueId"), &_0);
}

/**
 * Sets the route's description
 */
PHP_METHOD(Phalcon_Cli_Router_Route, setDescription)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *description_param = NULL;
	zval description;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&description);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(description)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &description_param);
	if (UNEXPECTED(Z_TYPE_P(description_param) != IS_STRING && Z_TYPE_P(description_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'description' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(description_param) == IS_STRING)) {
		zephir_get_strval(&description, description_param);
	} else {
		ZEPHIR_INIT_VAR(&description);
	}
	zephir_update_property_zval(this_ptr, ZEND_STRL("description"), &description);
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
PHP_METHOD(Phalcon_Cli_Router_Route, setName)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *name_param = NULL;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(name)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &name_param);
	if (UNEXPECTED(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(name_param) == IS_STRING)) {
		zephir_get_strval(&name, name_param);
	} else {
		ZEPHIR_INIT_VAR(&name);
	}
	zephir_update_property_zval(this_ptr, ZEND_STRL("name"), &name);
	RETURN_THIS();
}

zend_object *zephir_init_properties_Phalcon_Cli_Router_Route(zend_class_entry *class_type)
{
		zval _0, _2, _1$$3, _3$$4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$4);
	

		ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
		zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property_ex(&_0, this_ptr, ZEND_STRL("paths"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("paths"), &_1$$3);
		}
		zephir_read_property_ex(&_2, this_ptr, ZEND_STRL("converters"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_2) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_3$$4);
			array_init(&_3$$4);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("converters"), &_3$$4);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}
}

