
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/object.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/array.h"
#include "kernel/operators.h"
#include "kernel/concat.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 *
 * Implementation of this file has been influenced by AuraPHP
 * @link    https://github.com/auraphp/Aura.Html
 * @license https://github.com/auraphp/Aura.Html/blob/2.x/LICENSE
 */
/**
 * ServiceLocator implementation for Tag helpers.
 *
 * Built-in services are seeded by the constructor. Users may add or override
 * services via `set()`, passing one of:
 *  - a closure / callable (full recipe)
 *  - a class-string (escaper is injected automatically)
 *  - a `[className, [depKey, ...]]` tuple where each dep key is resolved from
 *    the factory's own services or its injected `response` / `url`
 *  - a `[className, [depKey, ...], [extraArg, ...]]` tuple where the extra
 *    args are passed verbatim to the constructor after the resolved deps
 *
 * Helpers are cached per name after first construction.
 *
 * `__call()` resolves the named helper and dispatches to its `__invoke()`,
 * so each entry in the @method block below describes the result of calling
 * `$factory->serviceName(...)` rather than `newInstance("serviceName")`.
 *
 * @property EscaperInterface       $escaper
 * @property ResponseInterface|null $response
 * @property UrlInterface|null      $url
 * @property array                  $factories
 * @property array                  $instances
 *
 * @method string      a(string $href, string $text, array $attributes = [], bool $raw = false)
 * @method string      aRaw(string $href, string $text, array $attributes = [])
 * @method string      base(string $href, array $attributes = [])
 * @method string      body(array $attributes = [])
 * @method Breadcrumbs breadcrumbs(string $indent = '    ', string $delimiter = "\n")
 * @method string      button(string $text, array $attributes = [], bool $raw = false)
 * @method string      buttonRaw(string $text, array $attributes = [])
 * @method string      close(string $tag, bool $raw = false)
 * @method Doctype     doctype(int $type = Doctype::HTML5, string $delimiter = "\n")
 * @method string      element(string $tag, string $text, array $attributes = [], bool $raw = false)
 * @method string      elementRaw(string $tag, string $text, array $attributes = [])
 * @method string      form(array $attributes = [])
 * @method string      friendlyTitle(string $text, string $separator = '-', bool $lowercase = true, mixed $replace = null)
 * @method string      img(string $src, array $attributes = [])
 * @method Checkbox    inputCheckbox(string $name, string $value = null, array $attributes = [])
 * @method Generic     inputColor(string $name, string $value = null, array $attributes = [])
 * @method Generic     inputDate(string $name, string $value = null, array $attributes = [])
 * @method Generic     inputDateTime(string $name, string $value = null, array $attributes = [])
 * @method Generic     inputDateTimeLocal(string $name, string $value = null, array $attributes = [])
 * @method Generic     inputEmail(string $name, string $value = null, array $attributes = [])
 * @method Generic     inputFile(string $name, string $value = null, array $attributes = [])
 * @method Generic     inputHidden(string $name, string $value = null, array $attributes = [])
 * @method Generic     inputImage(string $name, string $value = null, array $attributes = [])
 * @method Generic     inputInput(string $name, string $value = null, array $attributes = [])
 * @method Generic     inputMonth(string $name, string $value = null, array $attributes = [])
 * @method Generic     inputNumeric(string $name, string $value = null, array $attributes = [])
 * @method Generic     inputPassword(string $name, string $value = null, array $attributes = [])
 * @method Radio       inputRadio(string $name, string $value = null, array $attributes = [])
 * @method Generic     inputRange(string $name, string $value = null, array $attributes = [])
 * @method Generic     inputSearch(string $name, string $value = null, array $attributes = [])
 * @method Select      inputSelect(string $name, string $value = null, array $attributes = [])
 * @method Generic     inputSubmit(string $name, string $value = null, array $attributes = [])
 * @method Generic     inputTel(string $name, string $value = null, array $attributes = [])
 * @method Generic     inputText(string $name, string $value = null, array $attributes = [])
 * @method Textarea    inputTextarea(string $name, string $value = null, array $attributes = [])
 * @method Generic     inputTime(string $name, string $value = null, array $attributes = [])
 * @method Generic     inputUrl(string $name, string $value = null, array $attributes = [])
 * @method Generic     inputWeek(string $name, string $value = null, array $attributes = [])
 * @method string      label(string $label, array $attributes = [], bool $raw = false)
 * @method string      labelRaw(string $label, array $attributes = [])
 * @method Link        link(string $indent = '    ', string $delimiter = PHP_EOL)
 * @method Meta        meta(string $indent = '    ', string $delimiter = PHP_EOL)
 * @method Ol          ol(string $indent = '    ', string $delimiter = null, array $attributes = [])
 * @method Ol          olRaw(string $indent = '    ', string $delimiter = null, array $attributes = [])
 * @method string      preload(string $href, string $type = 'style', array $attributes = [])
 * @method Script      script(string $indent = '    ', string $delimiter = PHP_EOL)
 * @method Style       style(string $indent = '    ', string $delimiter = PHP_EOL)
 * @method string      tag(string $name, array $attributes = [])
 * @method Title       title(string $indent = '    ', string $delimiter = PHP_EOL)
 * @method Ul          ul(string $indent = '    ', string $delimiter = null, array $attributes = [])
 * @method Ul          ulRaw(string $indent = '    ', string $delimiter = null, array $attributes = [])
 * @method string      voidTag(string $name, array $attributes = [])
 */
ZEPHIR_INIT_CLASS(Phalcon_Html_TagFactory)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\Html, TagFactory, phalcon, html_tagfactory, phalcon_html_tagfactory_method_entry, 0);

	/**
	 * @var EscaperInterface
	 */
	zend_declare_property_null(phalcon_html_tagfactory_ce, SL("escaper"), ZEND_ACC_PRIVATE);
	/**
	 * @var ResponseInterface|null
	 */
	zend_declare_property_null(phalcon_html_tagfactory_ce, SL("response"), ZEND_ACC_PRIVATE);
	/**
	 * @var UrlInterface|null
	 */
	zend_declare_property_null(phalcon_html_tagfactory_ce, SL("url"), ZEND_ACC_PRIVATE);
	/**
	 * @var array
	 */
	zend_declare_property_null(phalcon_html_tagfactory_ce, SL("factories"), ZEND_ACC_PROTECTED);
	/**
	 * @var array
	 */
	zend_declare_property_null(phalcon_html_tagfactory_ce, SL("instances"), ZEND_ACC_PROTECTED);
	phalcon_html_tagfactory_ce->create_object = zephir_init_properties_Phalcon_Html_TagFactory;

	return SUCCESS;
}

/**
 * TagFactory constructor.
 *
 * @param EscaperInterface       $escaper
 * @param array                  $services
 * @param ResponseInterface|null $response
 * @param UrlInterface|null      $url
 */
PHP_METHOD(Phalcon_Html_TagFactory, __construct)
{
	zend_string *_4;
	zend_ulong _3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_5 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval services;
	zval *escaper, escaper_sub, *services_param = NULL, *response = NULL, response_sub, *url = NULL, url_sub, __$null, name, definition, _0, *_1, _2;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&escaper_sub);
	ZVAL_UNDEF(&response_sub);
	ZVAL_UNDEF(&url_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&definition);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&services);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 4)
		Z_PARAM_OBJECT_OF_CLASS(escaper, phalcon_html_escaper_escaperinterface_ce)
		Z_PARAM_OPTIONAL
		ZEPHIR_Z_PARAM_ARRAY(services, services_param)
		Z_PARAM_OBJECT_OF_CLASS_OR_NULL(response, phalcon_http_responseinterface_ce)
		Z_PARAM_OBJECT_OF_CLASS_OR_NULL(url, phalcon_mvc_url_urlinterface_ce)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 3, &escaper, &services_param, &response, &url);
	if (!services_param) {
		ZEPHIR_INIT_VAR(&services);
		array_init(&services);
	} else {
	ZEPHIR_OBS_COPY_OR_DUP(&services, services_param);
	}
	if (!response) {
		response = &response_sub;
		response = &__$null;
	}
	if (!url) {
		url = &url_sub;
		url = &__$null;
	}
	zephir_update_property_zval(this_ptr, ZEND_STRL("escaper"), escaper);
	zephir_update_property_zval(this_ptr, ZEND_STRL("response"), response);
	zephir_update_property_zval(this_ptr, ZEND_STRL("url"), url);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getdefaultservices", NULL, 0);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, ZEND_STRL("factories"), &_0);
	zephir_is_iterable(&services, 0, "phalcon/Html/TagFactory.zep", 176);
	if (Z_TYPE_P(&services) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&services), _3, _4, _1)
		{
			ZEPHIR_INIT_NVAR(&name);
			if (_4 != NULL) { 
				ZVAL_STR_COPY(&name, _4);
			} else {
				ZVAL_LONG(&name, _3);
			}
			ZEPHIR_INIT_NVAR(&definition);
			ZVAL_COPY(&definition, _1);
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "set", &_5, 0, &name, &definition);
			zephir_check_call_status();
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &services, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_2, &services, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_2)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&name, &services, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&definition, &services, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_CALL_METHOD(NULL, this_ptr, "set", &_5, 0, &name, &definition);
				zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, &services, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&definition);
	ZEPHIR_INIT_NVAR(&name);
	ZEPHIR_MM_RESTORE();
}

/**
 * Magic call to make the helper objects available as methods.
 *
 * @param string $name
 * @param array  $arguments
 *
 * @return false|mixed
 */
PHP_METHOD(Phalcon_Html_TagFactory, __call)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval arguments, _0;
	zval name_zv, *arguments_param = NULL, helper, _1;
	zend_string *name = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_zv);
	ZVAL_UNDEF(&helper);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&arguments);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR(name)
		ZEPHIR_Z_PARAM_ARRAY(arguments, arguments_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	arguments_param = ZEND_CALL_ARG(execute_data, 2);
	ZVAL_STR_COPY(&name_zv, name);
	zephir_get_arrval(&arguments, arguments_param);
	ZEPHIR_CALL_METHOD(&helper, this_ptr, "newinstance", NULL, 0, &name_zv);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_0);
	zephir_create_array(&_0, 2, 0);
	zephir_array_fast_append(&_0, &helper);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "__invoke");
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_CALL_USER_FUNC_ARRAY(return_value, &_0, &arguments);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * @param string $name
 *
 * @return bool
 */
PHP_METHOD(Phalcon_Html_TagFactory, has)
{
	zval name_zv, _0;
	zend_string *name = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_zv);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(name)
	ZEND_PARSE_PARAMETERS_END();
	ZVAL_STR(&name_zv, name);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("factories"), PH_NOISY_CC | PH_READONLY);
	RETURN_BOOL(zephir_array_isset(&_0, &name_zv));
}

/**
 * Create or return a cached instance of the helper.
 *
 * @param string $name
 *
 * @return mixed
 * @throws Exception
 */
PHP_METHOD(Phalcon_Html_TagFactory, newInstance)
{
	zval _16$$12;
	zend_bool _5$$4, _6$$4;
	zval _2$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_11 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval name_zv, factory, className, deps, args, depName, resolved, extra, extraArg, _0, _3, _18, _19, _1$$3, _4$$4, _7$$5, _8$$6, *_9$$6, _10$$6, _14$$6, *_12$$9, _13$$9, _15$$12, _17$$12;
	zend_string *name = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_zv);
	ZVAL_UNDEF(&factory);
	ZVAL_UNDEF(&className);
	ZVAL_UNDEF(&deps);
	ZVAL_UNDEF(&args);
	ZVAL_UNDEF(&depName);
	ZVAL_UNDEF(&resolved);
	ZVAL_UNDEF(&extra);
	ZVAL_UNDEF(&extraArg);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_18);
	ZVAL_UNDEF(&_19);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_7$$5);
	ZVAL_UNDEF(&_8$$6);
	ZVAL_UNDEF(&_10$$6);
	ZVAL_UNDEF(&_14$$6);
	ZVAL_UNDEF(&_13$$9);
	ZVAL_UNDEF(&_15$$12);
	ZVAL_UNDEF(&_17$$12);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_16$$12);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(name)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	ZVAL_STR_COPY(&name_zv, name);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("factories"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_array_isset(&_0, &name_zv))) {
		ZEPHIR_INIT_VAR(&_1$$3);
		object_init_ex(&_1$$3, phalcon_html_exception_ce);
		ZEPHIR_INIT_VAR(&_2$$3);
		ZEPHIR_CONCAT_SVS(&_2$$3, "Service ", &name_zv, " is not registered");
		ZEPHIR_CALL_METHOD(NULL, &_1$$3, "__construct", NULL, 38, &_2$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$3, "phalcon/Html/TagFactory.zep", 218);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_read_property(&_3, this_ptr, ZEND_STRL("instances"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_array_isset(&_3, &name_zv))) {
		zephir_read_property(&_4$$4, this_ptr, ZEND_STRL("factories"), PH_NOISY_CC | PH_READONLY);
		zephir_memory_observe(&factory);
		zephir_array_fetch(&factory, &_4$$4, &name_zv, PH_NOISY, "phalcon/Html/TagFactory.zep", 222);
		_5$$4 = Z_TYPE_P(&factory) == IS_OBJECT;
		if (!(_5$$4)) {
			_6$$4 = Z_TYPE_P(&factory) == IS_ARRAY;
			if (_6$$4) {
				_6$$4 = zephir_is_callable(&factory);
			}
			_5$$4 = _6$$4;
		}
		if (_5$$4) {
			ZEPHIR_INIT_VAR(&_7$$5);
			ZEPHIR_CALL_USER_FUNC(&_7$$5, &factory);
			zephir_check_call_status();
			zephir_update_property_array(this_ptr, SL("instances"), &name_zv, &_7$$5);
		} else if (Z_TYPE_P(&factory) == IS_ARRAY) {
			zephir_memory_observe(&className);
			zephir_array_fetch_long(&className, &factory, 0, PH_NOISY, "phalcon/Html/TagFactory.zep", 227);
			zephir_memory_observe(&deps);
			zephir_array_fetch_long(&deps, &factory, 1, PH_NOISY, "phalcon/Html/TagFactory.zep", 228);
			ZEPHIR_INIT_VAR(&args);
			zephir_create_array(&args, 1, 0);
			zephir_memory_observe(&_8$$6);
			zephir_read_property(&_8$$6, this_ptr, ZEND_STRL("escaper"), PH_NOISY_CC);
			zephir_array_fast_append(&args, &_8$$6);
			zephir_is_iterable(&deps, 0, "phalcon/Html/TagFactory.zep", 236);
			if (Z_TYPE_P(&deps) == IS_ARRAY) {
				ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&deps), _9$$6)
				{
					ZEPHIR_INIT_NVAR(&depName);
					ZVAL_COPY(&depName, _9$$6);
					ZEPHIR_CALL_METHOD(&resolved, this_ptr, "resolvedependency", &_11, 0, &depName);
					zephir_check_call_status();
					zephir_array_append(&args, &resolved, PH_SEPARATE, "phalcon/Html/TagFactory.zep", 233);
				} ZEND_HASH_FOREACH_END();
			} else {
				ZEPHIR_CALL_METHOD(NULL, &deps, "rewind", NULL, 0);
				zephir_check_call_status();
				while (1) {
					ZEPHIR_CALL_METHOD(&_10$$6, &deps, "valid", NULL, 0);
					zephir_check_call_status();
					if (!zend_is_true(&_10$$6)) {
						break;
					}
					ZEPHIR_CALL_METHOD(&depName, &deps, "current", NULL, 0);
					zephir_check_call_status();
						ZEPHIR_CALL_METHOD(&resolved, this_ptr, "resolvedependency", &_11, 0, &depName);
						zephir_check_call_status();
						zephir_array_append(&args, &resolved, PH_SEPARATE, "phalcon/Html/TagFactory.zep", 233);
					ZEPHIR_CALL_METHOD(NULL, &deps, "next", NULL, 0);
					zephir_check_call_status();
				}
			}
			ZEPHIR_INIT_NVAR(&depName);
			if (zephir_array_isset_long(&factory, 2)) {
				zephir_memory_observe(&extra);
				zephir_array_fetch_long(&extra, &factory, 2, PH_NOISY, "phalcon/Html/TagFactory.zep", 237);
				zephir_is_iterable(&extra, 0, "phalcon/Html/TagFactory.zep", 241);
				if (Z_TYPE_P(&extra) == IS_ARRAY) {
					ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&extra), _12$$9)
					{
						ZEPHIR_INIT_NVAR(&extraArg);
						ZVAL_COPY(&extraArg, _12$$9);
						zephir_array_append(&args, &extraArg, PH_SEPARATE, "phalcon/Html/TagFactory.zep", 239);
					} ZEND_HASH_FOREACH_END();
				} else {
					ZEPHIR_CALL_METHOD(NULL, &extra, "rewind", NULL, 0);
					zephir_check_call_status();
					while (1) {
						ZEPHIR_CALL_METHOD(&_13$$9, &extra, "valid", NULL, 0);
						zephir_check_call_status();
						if (!zend_is_true(&_13$$9)) {
							break;
						}
						ZEPHIR_CALL_METHOD(&extraArg, &extra, "current", NULL, 0);
						zephir_check_call_status();
							zephir_array_append(&args, &extraArg, PH_SEPARATE, "phalcon/Html/TagFactory.zep", 239);
						ZEPHIR_CALL_METHOD(NULL, &extra, "next", NULL, 0);
						zephir_check_call_status();
					}
				}
				ZEPHIR_INIT_NVAR(&extraArg);
			}
			ZEPHIR_INIT_VAR(&_14$$6);
			ZEPHIR_LAST_CALL_STATUS = zephir_create_instance_params(&_14$$6, &className, &args);
			zephir_check_call_status();
			zephir_update_property_array(this_ptr, SL("instances"), &name_zv, &_14$$6);
		} else {
			ZEPHIR_INIT_VAR(&_15$$12);
			ZEPHIR_INIT_VAR(&_16$$12);
			zephir_create_array(&_16$$12, 1, 0);
			zephir_memory_observe(&_17$$12);
			zephir_read_property(&_17$$12, this_ptr, ZEND_STRL("escaper"), PH_NOISY_CC);
			zephir_array_fast_append(&_16$$12, &_17$$12);
			ZEPHIR_LAST_CALL_STATUS = zephir_create_instance_params(&_15$$12, &factory, &_16$$12);
			zephir_check_call_status();
			zephir_update_property_array(this_ptr, SL("instances"), &name_zv, &_15$$12);
		}
	}
	zephir_read_property(&_18, this_ptr, ZEND_STRL("instances"), PH_NOISY_CC | PH_READONLY);
	zephir_array_fetch(&_19, &_18, &name_zv, PH_NOISY | PH_READONLY, "phalcon/Html/TagFactory.zep", 252);
	RETURN_CTOR(&_19);
}

/**
 * Register a helper. Accepts a closure/callable (full recipe), a
 * class-string (wrapped into a closure that injects the escaper), or a
 * `[className, [depName, ...]]` tuple where each dep is resolved from
 * the factory's own services or its injected `response`/`url`.
 *
 * @param string $name
 * @param mixed  $definition
 */
PHP_METHOD(Phalcon_Html_TagFactory, set)
{
	zval name_zv, *definition, definition_sub, _0;
	zend_string *name = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_zv);
	ZVAL_UNDEF(&definition_sub);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR(name)
		Z_PARAM_ZVAL(definition)
	ZEND_PARSE_PARAMETERS_END();
	definition = ZEND_CALL_ARG(execute_data, 2);
	ZVAL_STR(&name_zv, name);
	zephir_update_property_array(this_ptr, SL("factories"), &name_zv, definition);
	zephir_unset_property_array(this_ptr, ZEND_STRL("instances"), &name_zv);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("instances"), PH_NOISY_CC | PH_READONLY);
	zephir_array_unset(&_0, &name_zv, PH_SEPARATE);
}

/**
 * Resolves a dependency key for the tuple form of a service recipe.
 * Recognized keys: `response`, `url`. Anything else is treated as a
 * sibling service name and resolved via `newInstance()`. Tuple form is
 * `[className, [depKey, ...]]` or `[className, [depKey, ...], [extraArg, ...]]`
 * where extra args are passed through to the constructor verbatim.
 *
 * @param string $name
 *
 * @return mixed
 */
PHP_METHOD(Phalcon_Html_TagFactory, resolveDependency)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval name_zv;
	zend_string *name = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_zv);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(name)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	ZVAL_STR_COPY(&name_zv, name);
	if (ZEPHIR_IS_STRING_IDENTICAL(&name_zv, "response")) {
		RETURN_MM_MEMBER(getThis(), "response");
	}
	if (ZEPHIR_IS_STRING_IDENTICAL(&name_zv, "url")) {
		RETURN_MM_MEMBER(getThis(), "url");
	}
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "newinstance", NULL, 0, &name_zv);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Default service recipes. Each entry is either a class-string (escaper
 * is injected automatically) or a `[className, [depKey, ...]]` tuple
 * where each dep key is resolved by `resolveDependency()`.
 *
 * @return array
 */
PHP_METHOD(Phalcon_Html_TagFactory, getDefaultServices)
{
	zval _0, _2;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval __$null, __$true, _1;

	ZVAL_NULL(&__$null);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	zephir_create_array(return_value, 53, 0);
	add_assoc_stringl_ex(return_value, SL("a"), SL("Phalcon\\Html\\Helper\\Anchor"));
	ZEPHIR_INIT_VAR(&_0);
	zephir_create_array(&_0, 3, 0);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "Phalcon\\Html\\Helper\\Anchor");
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	array_init(&_1);
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_INIT_VAR(&_2);
	zephir_create_array(&_2, 2, 0);
	zephir_array_fast_append(&_2, &__$null);
	zephir_array_fast_append(&_2, &__$true);
	zephir_array_fast_append(&_0, &_2);
	zephir_array_update_string(return_value, SL("aRaw"), &_0, PH_COPY | PH_SEPARATE);
	add_assoc_stringl_ex(return_value, SL("base"), SL("Phalcon\\Html\\Helper\\Base"));
	add_assoc_stringl_ex(return_value, SL("body"), SL("Phalcon\\Html\\Helper\\Body"));
	ZEPHIR_INIT_NVAR(&_0);
	zephir_create_array(&_0, 2, 0);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "Phalcon\\Html\\Helper\\Breadcrumbs");
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_INIT_NVAR(&_2);
	zephir_create_array(&_2, 1, 0);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "url");
	zephir_array_fast_append(&_2, &_1);
	zephir_array_fast_append(&_0, &_2);
	zephir_array_update_string(return_value, SL("breadcrumbs"), &_0, PH_COPY | PH_SEPARATE);
	add_assoc_stringl_ex(return_value, SL("button"), SL("Phalcon\\Html\\Helper\\Button"));
	ZEPHIR_INIT_NVAR(&_0);
	zephir_create_array(&_0, 3, 0);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "Phalcon\\Html\\Helper\\Button");
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	array_init(&_1);
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_INIT_NVAR(&_2);
	zephir_create_array(&_2, 2, 0);
	zephir_array_fast_append(&_2, &__$null);
	zephir_array_fast_append(&_2, &__$true);
	zephir_array_fast_append(&_0, &_2);
	zephir_array_update_string(return_value, SL("buttonRaw"), &_0, PH_COPY | PH_SEPARATE);
	add_assoc_stringl_ex(return_value, SL("close"), SL("Phalcon\\Html\\Helper\\Close"));
	add_assoc_stringl_ex(return_value, SL("doctype"), SL("Phalcon\\Html\\Helper\\Doctype"));
	add_assoc_stringl_ex(return_value, SL("element"), SL("Phalcon\\Html\\Helper\\Element"));
	ZEPHIR_INIT_NVAR(&_0);
	zephir_create_array(&_0, 3, 0);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "Phalcon\\Html\\Helper\\Element");
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	array_init(&_1);
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_INIT_NVAR(&_2);
	zephir_create_array(&_2, 2, 0);
	zephir_array_fast_append(&_2, &__$null);
	zephir_array_fast_append(&_2, &__$true);
	zephir_array_fast_append(&_0, &_2);
	zephir_array_update_string(return_value, SL("elementRaw"), &_0, PH_COPY | PH_SEPARATE);
	add_assoc_stringl_ex(return_value, SL("form"), SL("Phalcon\\Html\\Helper\\Form"));
	add_assoc_stringl_ex(return_value, SL("friendlyTitle"), SL("Phalcon\\Html\\Helper\\FriendlyTitle"));
	add_assoc_stringl_ex(return_value, SL("img"), SL("Phalcon\\Html\\Helper\\Img"));
	ZEPHIR_INIT_NVAR(&_0);
	zephir_create_array(&_0, 2, 0);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "Phalcon\\Html\\Helper\\Input\\Checkbox");
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_INIT_NVAR(&_2);
	zephir_create_array(&_2, 1, 0);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "doctype");
	zephir_array_fast_append(&_2, &_1);
	zephir_array_fast_append(&_0, &_2);
	zephir_array_update_string(return_value, SL("inputCheckbox"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_0);
	zephir_create_array(&_0, 3, 0);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "Phalcon\\Html\\Helper\\Input\\Generic");
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_INIT_NVAR(&_2);
	zephir_create_array(&_2, 1, 0);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "doctype");
	zephir_array_fast_append(&_2, &_1);
	zephir_array_fast_append(&_0, &_2);
	ZEPHIR_INIT_NVAR(&_2);
	zephir_create_array(&_2, 1, 0);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "color");
	zephir_array_fast_append(&_2, &_1);
	zephir_array_fast_append(&_0, &_2);
	zephir_array_update_string(return_value, SL("inputColor"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_0);
	zephir_create_array(&_0, 3, 0);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "Phalcon\\Html\\Helper\\Input\\Generic");
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_INIT_NVAR(&_2);
	zephir_create_array(&_2, 1, 0);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "doctype");
	zephir_array_fast_append(&_2, &_1);
	zephir_array_fast_append(&_0, &_2);
	ZEPHIR_INIT_NVAR(&_2);
	zephir_create_array(&_2, 1, 0);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "date");
	zephir_array_fast_append(&_2, &_1);
	zephir_array_fast_append(&_0, &_2);
	zephir_array_update_string(return_value, SL("inputDate"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_0);
	zephir_create_array(&_0, 3, 0);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "Phalcon\\Html\\Helper\\Input\\Generic");
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_INIT_NVAR(&_2);
	zephir_create_array(&_2, 1, 0);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "doctype");
	zephir_array_fast_append(&_2, &_1);
	zephir_array_fast_append(&_0, &_2);
	ZEPHIR_INIT_NVAR(&_2);
	zephir_create_array(&_2, 1, 0);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "datetime");
	zephir_array_fast_append(&_2, &_1);
	zephir_array_fast_append(&_0, &_2);
	zephir_array_update_string(return_value, SL("inputDateTime"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_0);
	zephir_create_array(&_0, 3, 0);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "Phalcon\\Html\\Helper\\Input\\Generic");
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_INIT_NVAR(&_2);
	zephir_create_array(&_2, 1, 0);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "doctype");
	zephir_array_fast_append(&_2, &_1);
	zephir_array_fast_append(&_0, &_2);
	ZEPHIR_INIT_NVAR(&_2);
	zephir_create_array(&_2, 1, 0);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "datetime-local");
	zephir_array_fast_append(&_2, &_1);
	zephir_array_fast_append(&_0, &_2);
	zephir_array_update_string(return_value, SL("inputDateTimeLocal"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_0);
	zephir_create_array(&_0, 3, 0);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "Phalcon\\Html\\Helper\\Input\\Generic");
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_INIT_NVAR(&_2);
	zephir_create_array(&_2, 1, 0);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "doctype");
	zephir_array_fast_append(&_2, &_1);
	zephir_array_fast_append(&_0, &_2);
	ZEPHIR_INIT_NVAR(&_2);
	zephir_create_array(&_2, 1, 0);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "email");
	zephir_array_fast_append(&_2, &_1);
	zephir_array_fast_append(&_0, &_2);
	zephir_array_update_string(return_value, SL("inputEmail"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_0);
	zephir_create_array(&_0, 3, 0);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "Phalcon\\Html\\Helper\\Input\\Generic");
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_INIT_NVAR(&_2);
	zephir_create_array(&_2, 1, 0);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "doctype");
	zephir_array_fast_append(&_2, &_1);
	zephir_array_fast_append(&_0, &_2);
	ZEPHIR_INIT_NVAR(&_2);
	zephir_create_array(&_2, 1, 0);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "file");
	zephir_array_fast_append(&_2, &_1);
	zephir_array_fast_append(&_0, &_2);
	zephir_array_update_string(return_value, SL("inputFile"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_0);
	zephir_create_array(&_0, 3, 0);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "Phalcon\\Html\\Helper\\Input\\Generic");
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_INIT_NVAR(&_2);
	zephir_create_array(&_2, 1, 0);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "doctype");
	zephir_array_fast_append(&_2, &_1);
	zephir_array_fast_append(&_0, &_2);
	ZEPHIR_INIT_NVAR(&_2);
	zephir_create_array(&_2, 1, 0);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "hidden");
	zephir_array_fast_append(&_2, &_1);
	zephir_array_fast_append(&_0, &_2);
	zephir_array_update_string(return_value, SL("inputHidden"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_0);
	zephir_create_array(&_0, 3, 0);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "Phalcon\\Html\\Helper\\Input\\Generic");
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_INIT_NVAR(&_2);
	zephir_create_array(&_2, 1, 0);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "doctype");
	zephir_array_fast_append(&_2, &_1);
	zephir_array_fast_append(&_0, &_2);
	ZEPHIR_INIT_NVAR(&_2);
	zephir_create_array(&_2, 1, 0);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "image");
	zephir_array_fast_append(&_2, &_1);
	zephir_array_fast_append(&_0, &_2);
	zephir_array_update_string(return_value, SL("inputImage"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_0);
	zephir_create_array(&_0, 2, 0);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "Phalcon\\Html\\Helper\\Input\\Generic");
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_INIT_NVAR(&_2);
	zephir_create_array(&_2, 1, 0);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "doctype");
	zephir_array_fast_append(&_2, &_1);
	zephir_array_fast_append(&_0, &_2);
	zephir_array_update_string(return_value, SL("inputInput"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_0);
	zephir_create_array(&_0, 3, 0);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "Phalcon\\Html\\Helper\\Input\\Generic");
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_INIT_NVAR(&_2);
	zephir_create_array(&_2, 1, 0);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "doctype");
	zephir_array_fast_append(&_2, &_1);
	zephir_array_fast_append(&_0, &_2);
	ZEPHIR_INIT_NVAR(&_2);
	zephir_create_array(&_2, 1, 0);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "month");
	zephir_array_fast_append(&_2, &_1);
	zephir_array_fast_append(&_0, &_2);
	zephir_array_update_string(return_value, SL("inputMonth"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_0);
	zephir_create_array(&_0, 3, 0);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "Phalcon\\Html\\Helper\\Input\\Generic");
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_INIT_NVAR(&_2);
	zephir_create_array(&_2, 1, 0);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "doctype");
	zephir_array_fast_append(&_2, &_1);
	zephir_array_fast_append(&_0, &_2);
	ZEPHIR_INIT_NVAR(&_2);
	zephir_create_array(&_2, 1, 0);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "number");
	zephir_array_fast_append(&_2, &_1);
	zephir_array_fast_append(&_0, &_2);
	zephir_array_update_string(return_value, SL("inputNumeric"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_0);
	zephir_create_array(&_0, 3, 0);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "Phalcon\\Html\\Helper\\Input\\Generic");
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_INIT_NVAR(&_2);
	zephir_create_array(&_2, 1, 0);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "doctype");
	zephir_array_fast_append(&_2, &_1);
	zephir_array_fast_append(&_0, &_2);
	ZEPHIR_INIT_NVAR(&_2);
	zephir_create_array(&_2, 1, 0);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "password");
	zephir_array_fast_append(&_2, &_1);
	zephir_array_fast_append(&_0, &_2);
	zephir_array_update_string(return_value, SL("inputPassword"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_0);
	zephir_create_array(&_0, 2, 0);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "Phalcon\\Html\\Helper\\Input\\Radio");
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_INIT_NVAR(&_2);
	zephir_create_array(&_2, 1, 0);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "doctype");
	zephir_array_fast_append(&_2, &_1);
	zephir_array_fast_append(&_0, &_2);
	zephir_array_update_string(return_value, SL("inputRadio"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_0);
	zephir_create_array(&_0, 3, 0);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "Phalcon\\Html\\Helper\\Input\\Generic");
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_INIT_NVAR(&_2);
	zephir_create_array(&_2, 1, 0);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "doctype");
	zephir_array_fast_append(&_2, &_1);
	zephir_array_fast_append(&_0, &_2);
	ZEPHIR_INIT_NVAR(&_2);
	zephir_create_array(&_2, 1, 0);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "range");
	zephir_array_fast_append(&_2, &_1);
	zephir_array_fast_append(&_0, &_2);
	zephir_array_update_string(return_value, SL("inputRange"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_0);
	zephir_create_array(&_0, 3, 0);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "Phalcon\\Html\\Helper\\Input\\Generic");
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_INIT_NVAR(&_2);
	zephir_create_array(&_2, 1, 0);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "doctype");
	zephir_array_fast_append(&_2, &_1);
	zephir_array_fast_append(&_0, &_2);
	ZEPHIR_INIT_NVAR(&_2);
	zephir_create_array(&_2, 1, 0);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "search");
	zephir_array_fast_append(&_2, &_1);
	zephir_array_fast_append(&_0, &_2);
	zephir_array_update_string(return_value, SL("inputSearch"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_0);
	zephir_create_array(&_0, 2, 0);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "Phalcon\\Html\\Helper\\Input\\Select");
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_INIT_NVAR(&_2);
	zephir_create_array(&_2, 1, 0);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "doctype");
	zephir_array_fast_append(&_2, &_1);
	zephir_array_fast_append(&_0, &_2);
	zephir_array_update_string(return_value, SL("inputSelect"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_0);
	zephir_create_array(&_0, 3, 0);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "Phalcon\\Html\\Helper\\Input\\Generic");
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_INIT_NVAR(&_2);
	zephir_create_array(&_2, 1, 0);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "doctype");
	zephir_array_fast_append(&_2, &_1);
	zephir_array_fast_append(&_0, &_2);
	ZEPHIR_INIT_NVAR(&_2);
	zephir_create_array(&_2, 1, 0);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "submit");
	zephir_array_fast_append(&_2, &_1);
	zephir_array_fast_append(&_0, &_2);
	zephir_array_update_string(return_value, SL("inputSubmit"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_0);
	zephir_create_array(&_0, 3, 0);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "Phalcon\\Html\\Helper\\Input\\Generic");
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_INIT_NVAR(&_2);
	zephir_create_array(&_2, 1, 0);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "doctype");
	zephir_array_fast_append(&_2, &_1);
	zephir_array_fast_append(&_0, &_2);
	ZEPHIR_INIT_NVAR(&_2);
	zephir_create_array(&_2, 1, 0);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "tel");
	zephir_array_fast_append(&_2, &_1);
	zephir_array_fast_append(&_0, &_2);
	zephir_array_update_string(return_value, SL("inputTel"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_0);
	zephir_create_array(&_0, 3, 0);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "Phalcon\\Html\\Helper\\Input\\Generic");
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_INIT_NVAR(&_2);
	zephir_create_array(&_2, 1, 0);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "doctype");
	zephir_array_fast_append(&_2, &_1);
	zephir_array_fast_append(&_0, &_2);
	ZEPHIR_INIT_NVAR(&_2);
	zephir_create_array(&_2, 1, 0);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "text");
	zephir_array_fast_append(&_2, &_1);
	zephir_array_fast_append(&_0, &_2);
	zephir_array_update_string(return_value, SL("inputText"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_0);
	zephir_create_array(&_0, 2, 0);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "Phalcon\\Html\\Helper\\Input\\Textarea");
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_INIT_NVAR(&_2);
	zephir_create_array(&_2, 1, 0);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "doctype");
	zephir_array_fast_append(&_2, &_1);
	zephir_array_fast_append(&_0, &_2);
	zephir_array_update_string(return_value, SL("inputTextarea"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_0);
	zephir_create_array(&_0, 3, 0);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "Phalcon\\Html\\Helper\\Input\\Generic");
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_INIT_NVAR(&_2);
	zephir_create_array(&_2, 1, 0);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "doctype");
	zephir_array_fast_append(&_2, &_1);
	zephir_array_fast_append(&_0, &_2);
	ZEPHIR_INIT_NVAR(&_2);
	zephir_create_array(&_2, 1, 0);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "time");
	zephir_array_fast_append(&_2, &_1);
	zephir_array_fast_append(&_0, &_2);
	zephir_array_update_string(return_value, SL("inputTime"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_0);
	zephir_create_array(&_0, 3, 0);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "Phalcon\\Html\\Helper\\Input\\Generic");
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_INIT_NVAR(&_2);
	zephir_create_array(&_2, 1, 0);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "doctype");
	zephir_array_fast_append(&_2, &_1);
	zephir_array_fast_append(&_0, &_2);
	ZEPHIR_INIT_NVAR(&_2);
	zephir_create_array(&_2, 1, 0);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "url");
	zephir_array_fast_append(&_2, &_1);
	zephir_array_fast_append(&_0, &_2);
	zephir_array_update_string(return_value, SL("inputUrl"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_0);
	zephir_create_array(&_0, 3, 0);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "Phalcon\\Html\\Helper\\Input\\Generic");
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_INIT_NVAR(&_2);
	zephir_create_array(&_2, 1, 0);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "doctype");
	zephir_array_fast_append(&_2, &_1);
	zephir_array_fast_append(&_0, &_2);
	ZEPHIR_INIT_NVAR(&_2);
	zephir_create_array(&_2, 1, 0);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "week");
	zephir_array_fast_append(&_2, &_1);
	zephir_array_fast_append(&_0, &_2);
	zephir_array_update_string(return_value, SL("inputWeek"), &_0, PH_COPY | PH_SEPARATE);
	add_assoc_stringl_ex(return_value, SL("label"), SL("Phalcon\\Html\\Helper\\Label"));
	ZEPHIR_INIT_NVAR(&_0);
	zephir_create_array(&_0, 3, 0);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "Phalcon\\Html\\Helper\\Label");
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	array_init(&_1);
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_INIT_NVAR(&_2);
	zephir_create_array(&_2, 2, 0);
	zephir_array_fast_append(&_2, &__$null);
	zephir_array_fast_append(&_2, &__$true);
	zephir_array_fast_append(&_0, &_2);
	zephir_array_update_string(return_value, SL("labelRaw"), &_0, PH_COPY | PH_SEPARATE);
	add_assoc_stringl_ex(return_value, SL("link"), SL("Phalcon\\Html\\Helper\\Link"));
	add_assoc_stringl_ex(return_value, SL("meta"), SL("Phalcon\\Html\\Helper\\Meta"));
	add_assoc_stringl_ex(return_value, SL("ol"), SL("Phalcon\\Html\\Helper\\Ol"));
	ZEPHIR_INIT_NVAR(&_0);
	zephir_create_array(&_0, 3, 0);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "Phalcon\\Html\\Helper\\Ol");
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	array_init(&_1);
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_INIT_NVAR(&_2);
	zephir_create_array(&_2, 2, 0);
	zephir_array_fast_append(&_2, &__$null);
	zephir_array_fast_append(&_2, &__$true);
	zephir_array_fast_append(&_0, &_2);
	zephir_array_update_string(return_value, SL("olRaw"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_0);
	zephir_create_array(&_0, 2, 0);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "Phalcon\\Html\\Helper\\Preload");
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_INIT_NVAR(&_2);
	zephir_create_array(&_2, 1, 0);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "response");
	zephir_array_fast_append(&_2, &_1);
	zephir_array_fast_append(&_0, &_2);
	zephir_array_update_string(return_value, SL("preload"), &_0, PH_COPY | PH_SEPARATE);
	add_assoc_stringl_ex(return_value, SL("script"), SL("Phalcon\\Html\\Helper\\Script"));
	add_assoc_stringl_ex(return_value, SL("style"), SL("Phalcon\\Html\\Helper\\Style"));
	add_assoc_stringl_ex(return_value, SL("tag"), SL("Phalcon\\Html\\Helper\\Tag"));
	add_assoc_stringl_ex(return_value, SL("title"), SL("Phalcon\\Html\\Helper\\Title"));
	add_assoc_stringl_ex(return_value, SL("ul"), SL("Phalcon\\Html\\Helper\\Ul"));
	ZEPHIR_INIT_NVAR(&_0);
	zephir_create_array(&_0, 3, 0);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "Phalcon\\Html\\Helper\\Ul");
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	array_init(&_1);
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_INIT_NVAR(&_2);
	zephir_create_array(&_2, 2, 0);
	zephir_array_fast_append(&_2, &__$null);
	zephir_array_fast_append(&_2, &__$true);
	zephir_array_fast_append(&_0, &_2);
	zephir_array_update_string(return_value, SL("ulRaw"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_0);
	zephir_create_array(&_0, 2, 0);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "Phalcon\\Html\\Helper\\VoidTag");
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_INIT_NVAR(&_2);
	zephir_create_array(&_2, 1, 0);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "doctype");
	zephir_array_fast_append(&_2, &_1);
	zephir_array_fast_append(&_0, &_2);
	zephir_array_update_string(return_value, SL("voidTag"), &_0, PH_COPY | PH_SEPARATE);
	RETURN_MM();
}

zend_object *zephir_init_properties_Phalcon_Html_TagFactory(zend_class_entry *class_type)
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
		zephir_read_property_ex(&_0, this_ptr, ZEND_STRL("instances"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("instances"), &_1$$3);
		}
		zephir_read_property_ex(&_2, this_ptr, ZEND_STRL("factories"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_2) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_3$$4);
			array_init(&_3$$4);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("factories"), &_3$$4);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}
}

