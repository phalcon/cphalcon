
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
#include "Zend/zend_closures.h"


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
 * services via `set()`, passing a Closure that returns the helper instance.
 *
 * Helpers are cached per name after first construction.
 *
 * `__call()` resolves the named helper and dispatches to its `__invoke()`,
 * so each entry in the @method block below describes the result of calling
 * `$factory->serviceName(...)` rather than `newInstance("serviceName")`.
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
 * @method Link        link(string $indent = '    ', string $delimiter = "\n")
 * @method Meta        meta(string $indent = '    ', string $delimiter = "\n")
 * @method Ol          ol(string $indent = '    ', string $delimiter = null, array $attributes = [])
 * @method Ol          olRaw(string $indent = '    ', string $delimiter = null, array $attributes = [])
 * @method string      preload(string $href, string $type = 'style', array $attributes = [])
 * @method Script      script(string $indent = '    ', string $delimiter = "\n")
 * @method Style       style(string $indent = '    ', string $delimiter = "\n")
 * @method string      tag(string $name, array $attributes = [])
 * @method Title       title(string $indent = '    ', string $delimiter = "\n")
 * @method Ul          ul(string $indent = '    ', string $delimiter = null, array $attributes = [])
 * @method Ul          ulRaw(string $indent = '    ', string $delimiter = null, array $attributes = [])
 * @method string      voidTag(string $name, array $attributes = [])
 */
ZEPHIR_INIT_CLASS(Phalcon_Html_TagFactory)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\Html, TagFactory, phalcon, html_tagfactory, phalcon_html_tagfactory_method_entry, 0);

	/**
	 * @var Doctype
	 */
	zend_declare_property_null(phalcon_html_tagfactory_ce, SL("doctype"), ZEND_ACC_PRIVATE);
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
 * @param EscaperInterface          $escaper
 * @param array<string, Closure>    $services  Map of service name to a
 *                                             zero-arg Closure that returns
 *                                             the helper instance.
 * @param ResponseInterface|null    $response
 * @param UrlInterface|null         $url
 */
PHP_METHOD(Phalcon_Html_TagFactory, __construct)
{
	zend_string *_5;
	zend_ulong _4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_6 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval services;
	zval *escaper, escaper_sub, *services_param = NULL, *response = NULL, response_sub, *url = NULL, url_sub, __$null, name, definition, _0, _1, *_2, _3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&escaper_sub);
	ZVAL_UNDEF(&response_sub);
	ZVAL_UNDEF(&url_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&definition);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3);
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
	ZEPHIR_INIT_VAR(&_0);
	object_init_ex(&_0, phalcon_html_helper_doctype_ce);
	ZEPHIR_CALL_METHOD(NULL, &_0, "__construct", NULL, 358);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, ZEND_STRL("doctype"), &_0);
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "getdefaultservices", NULL, 0);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, ZEND_STRL("factories"), &_1);
	zephir_is_iterable(&services, 0, "phalcon/Html/TagFactory.zep", 173);
	if (Z_TYPE_P(&services) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&services), _4, _5, _2)
		{
			ZEPHIR_INIT_NVAR(&name);
			if (_5 != NULL) { 
				ZVAL_STR_COPY(&name, _5);
			} else {
				ZVAL_LONG(&name, _4);
			}
			ZEPHIR_INIT_NVAR(&definition);
			ZVAL_COPY(&definition, _2);
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "set", &_6, 0, &name, &definition);
			zephir_check_call_status();
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &services, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_3, &services, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_3)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&name, &services, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&definition, &services, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_CALL_METHOD(NULL, this_ptr, "set", &_6, 0, &name, &definition);
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
 * @return mixed
 * @throws \Phalcon\Html\Exception
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
 * @return object
 * @throws \Phalcon\Html\Exception
 */
PHP_METHOD(Phalcon_Html_TagFactory, newInstance)
{
	zval _2$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval name_zv, factory, _0, _3, _6, _7, _1$$3, _4$$4, _5$$4;
	zend_string *name = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_zv);
	ZVAL_UNDEF(&factory);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_2$$3);
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
		zephir_throw_exception_debug(&_1$$3, "phalcon/Html/TagFactory.zep", 216);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_read_property(&_3, this_ptr, ZEND_STRL("instances"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_array_isset(&_3, &name_zv))) {
		zephir_read_property(&_4$$4, this_ptr, ZEND_STRL("factories"), PH_NOISY_CC | PH_READONLY);
		zephir_memory_observe(&factory);
		zephir_array_fetch(&factory, &_4$$4, &name_zv, PH_NOISY, "phalcon/Html/TagFactory.zep", 220);
		ZEPHIR_INIT_VAR(&_5$$4);
		ZEPHIR_CALL_USER_FUNC(&_5$$4, &factory);
		zephir_check_call_status();
		zephir_update_property_array(this_ptr, SL("instances"), &name_zv, &_5$$4);
	}
	zephir_read_property(&_6, this_ptr, ZEND_STRL("instances"), PH_NOISY_CC | PH_READONLY);
	zephir_array_fetch(&_7, &_6, &name_zv, PH_NOISY | PH_READONLY, "phalcon/Html/TagFactory.zep", 224);
	RETURN_CTOR(&_7);
}

/**
 * Register a helper via a zero-argument Closure. The Closure is invoked on
 * the first matching `newInstance()` call and its return value is cached.
 * Passing a new definition clears any cached instance so the next call to
 * `newInstance()` rebuilds it.
 *
 * @param string  $name
 * @param Closure $definition
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
		Z_PARAM_OBJECT_OF_CLASS(definition, zend_ce_closure)
	ZEND_PARSE_PARAMETERS_END();
	definition = ZEND_CALL_ARG(execute_data, 2);
	ZVAL_STR(&name_zv, name);
	zephir_update_property_array(this_ptr, SL("factories"), &name_zv, definition);
	zephir_unset_property_array(this_ptr, ZEND_STRL("instances"), &name_zv);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("instances"), PH_NOISY_CC | PH_READONLY);
	zephir_array_unset(&_0, &name_zv, PH_SEPARATE);
}

/**
 * Default service recipes. Every entry is a Closure that returns a
 * fully-constructed helper instance. Services are built lazily and cached.
 *
 * @return array
 */
PHP_METHOD(Phalcon_Html_TagFactory, getDefaultServices)
{
	zval escaper, response, url, _0, _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&escaper);
	ZVAL_UNDEF(&response);
	ZVAL_UNDEF(&url);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	zephir_read_property(&_0, this_ptr, ZEND_STRL("escaper"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&escaper, &_0);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("response"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&response, &_0);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("url"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&url, &_0);
	zephir_create_array(return_value, 53, 0);
	ZEPHIR_INIT_VAR(&_1);
	ZEPHIR_INIT_NVAR(&_1);
	zephir_create_closure_ex(&_1, this_ptr, phalcon_7__closure_ce, SL("__invoke"));
	zephir_update_static_property_ce(phalcon_7__closure_ce, ZEND_STRL("escaper"), &escaper);
	zephir_array_update_string(return_value, SL("a"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_1);
	ZEPHIR_INIT_NVAR(&_1);
	zephir_create_closure_ex(&_1, this_ptr, phalcon_8__closure_ce, SL("__invoke"));
	zephir_update_static_property_ce(phalcon_8__closure_ce, ZEND_STRL("escaper"), &escaper);
	zephir_array_update_string(return_value, SL("aRaw"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_1);
	ZEPHIR_INIT_NVAR(&_1);
	zephir_create_closure_ex(&_1, this_ptr, phalcon_9__closure_ce, SL("__invoke"));
	zephir_update_static_property_ce(phalcon_9__closure_ce, ZEND_STRL("escaper"), &escaper);
	zephir_array_update_string(return_value, SL("base"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_1);
	ZEPHIR_INIT_NVAR(&_1);
	zephir_create_closure_ex(&_1, this_ptr, phalcon_10__closure_ce, SL("__invoke"));
	zephir_update_static_property_ce(phalcon_10__closure_ce, ZEND_STRL("escaper"), &escaper);
	zephir_array_update_string(return_value, SL("body"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_1);
	ZEPHIR_INIT_NVAR(&_1);
	zephir_create_closure_ex(&_1, NULL, phalcon_11__closure_ce, SL("__invoke"));
	zephir_update_static_property_ce(phalcon_11__closure_ce, ZEND_STRL("escaper"), &escaper);
	zephir_update_static_property_ce(phalcon_11__closure_ce, ZEND_STRL("url"), &url);
	zephir_array_update_string(return_value, SL("breadcrumbs"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_1);
	ZEPHIR_INIT_NVAR(&_1);
	zephir_create_closure_ex(&_1, this_ptr, phalcon_12__closure_ce, SL("__invoke"));
	zephir_update_static_property_ce(phalcon_12__closure_ce, ZEND_STRL("escaper"), &escaper);
	zephir_array_update_string(return_value, SL("button"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_1);
	ZEPHIR_INIT_NVAR(&_1);
	zephir_create_closure_ex(&_1, this_ptr, phalcon_13__closure_ce, SL("__invoke"));
	zephir_update_static_property_ce(phalcon_13__closure_ce, ZEND_STRL("escaper"), &escaper);
	zephir_array_update_string(return_value, SL("buttonRaw"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_1);
	ZEPHIR_INIT_NVAR(&_1);
	zephir_create_closure_ex(&_1, this_ptr, phalcon_14__closure_ce, SL("__invoke"));
	zephir_update_static_property_ce(phalcon_14__closure_ce, ZEND_STRL("escaper"), &escaper);
	zephir_array_update_string(return_value, SL("close"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_1);
	ZEPHIR_INIT_NVAR(&_1);
	zephir_create_closure_ex(&_1, this_ptr, phalcon_15__closure_ce, SL("__invoke"));
	zephir_array_update_string(return_value, SL("doctype"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_1);
	ZEPHIR_INIT_NVAR(&_1);
	zephir_create_closure_ex(&_1, this_ptr, phalcon_16__closure_ce, SL("__invoke"));
	zephir_update_static_property_ce(phalcon_16__closure_ce, ZEND_STRL("escaper"), &escaper);
	zephir_array_update_string(return_value, SL("element"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_1);
	ZEPHIR_INIT_NVAR(&_1);
	zephir_create_closure_ex(&_1, this_ptr, phalcon_17__closure_ce, SL("__invoke"));
	zephir_update_static_property_ce(phalcon_17__closure_ce, ZEND_STRL("escaper"), &escaper);
	zephir_array_update_string(return_value, SL("elementRaw"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_1);
	ZEPHIR_INIT_NVAR(&_1);
	zephir_create_closure_ex(&_1, this_ptr, phalcon_18__closure_ce, SL("__invoke"));
	zephir_update_static_property_ce(phalcon_18__closure_ce, ZEND_STRL("escaper"), &escaper);
	zephir_array_update_string(return_value, SL("form"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_1);
	ZEPHIR_INIT_NVAR(&_1);
	zephir_create_closure_ex(&_1, NULL, phalcon_19__closure_ce, SL("__invoke"));
	zephir_update_static_property_ce(phalcon_19__closure_ce, ZEND_STRL("escaper"), &escaper);
	zephir_array_update_string(return_value, SL("friendlyTitle"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_1);
	ZEPHIR_INIT_NVAR(&_1);
	zephir_create_closure_ex(&_1, this_ptr, phalcon_20__closure_ce, SL("__invoke"));
	zephir_update_static_property_ce(phalcon_20__closure_ce, ZEND_STRL("escaper"), &escaper);
	zephir_array_update_string(return_value, SL("img"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_1);
	ZEPHIR_INIT_NVAR(&_1);
	zephir_create_closure_ex(&_1, this_ptr, phalcon_21__closure_ce, SL("__invoke"));
	zephir_update_static_property_ce(phalcon_21__closure_ce, ZEND_STRL("escaper"), &escaper);
	zephir_array_update_string(return_value, SL("inputCheckbox"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_1);
	ZEPHIR_INIT_NVAR(&_1);
	zephir_create_closure_ex(&_1, this_ptr, phalcon_22__closure_ce, SL("__invoke"));
	zephir_update_static_property_ce(phalcon_22__closure_ce, ZEND_STRL("escaper"), &escaper);
	zephir_array_update_string(return_value, SL("inputColor"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_1);
	ZEPHIR_INIT_NVAR(&_1);
	zephir_create_closure_ex(&_1, this_ptr, phalcon_23__closure_ce, SL("__invoke"));
	zephir_update_static_property_ce(phalcon_23__closure_ce, ZEND_STRL("escaper"), &escaper);
	zephir_array_update_string(return_value, SL("inputDate"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_1);
	ZEPHIR_INIT_NVAR(&_1);
	zephir_create_closure_ex(&_1, this_ptr, phalcon_24__closure_ce, SL("__invoke"));
	zephir_update_static_property_ce(phalcon_24__closure_ce, ZEND_STRL("escaper"), &escaper);
	zephir_array_update_string(return_value, SL("inputDateTime"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_1);
	ZEPHIR_INIT_NVAR(&_1);
	zephir_create_closure_ex(&_1, this_ptr, phalcon_25__closure_ce, SL("__invoke"));
	zephir_update_static_property_ce(phalcon_25__closure_ce, ZEND_STRL("escaper"), &escaper);
	zephir_array_update_string(return_value, SL("inputDateTimeLocal"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_1);
	ZEPHIR_INIT_NVAR(&_1);
	zephir_create_closure_ex(&_1, this_ptr, phalcon_26__closure_ce, SL("__invoke"));
	zephir_update_static_property_ce(phalcon_26__closure_ce, ZEND_STRL("escaper"), &escaper);
	zephir_array_update_string(return_value, SL("inputEmail"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_1);
	ZEPHIR_INIT_NVAR(&_1);
	zephir_create_closure_ex(&_1, this_ptr, phalcon_27__closure_ce, SL("__invoke"));
	zephir_update_static_property_ce(phalcon_27__closure_ce, ZEND_STRL("escaper"), &escaper);
	zephir_array_update_string(return_value, SL("inputFile"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_1);
	ZEPHIR_INIT_NVAR(&_1);
	zephir_create_closure_ex(&_1, this_ptr, phalcon_28__closure_ce, SL("__invoke"));
	zephir_update_static_property_ce(phalcon_28__closure_ce, ZEND_STRL("escaper"), &escaper);
	zephir_array_update_string(return_value, SL("inputHidden"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_1);
	ZEPHIR_INIT_NVAR(&_1);
	zephir_create_closure_ex(&_1, this_ptr, phalcon_29__closure_ce, SL("__invoke"));
	zephir_update_static_property_ce(phalcon_29__closure_ce, ZEND_STRL("escaper"), &escaper);
	zephir_array_update_string(return_value, SL("inputImage"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_1);
	ZEPHIR_INIT_NVAR(&_1);
	zephir_create_closure_ex(&_1, this_ptr, phalcon_30__closure_ce, SL("__invoke"));
	zephir_update_static_property_ce(phalcon_30__closure_ce, ZEND_STRL("escaper"), &escaper);
	zephir_array_update_string(return_value, SL("inputInput"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_1);
	ZEPHIR_INIT_NVAR(&_1);
	zephir_create_closure_ex(&_1, this_ptr, phalcon_31__closure_ce, SL("__invoke"));
	zephir_update_static_property_ce(phalcon_31__closure_ce, ZEND_STRL("escaper"), &escaper);
	zephir_array_update_string(return_value, SL("inputMonth"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_1);
	ZEPHIR_INIT_NVAR(&_1);
	zephir_create_closure_ex(&_1, this_ptr, phalcon_32__closure_ce, SL("__invoke"));
	zephir_update_static_property_ce(phalcon_32__closure_ce, ZEND_STRL("escaper"), &escaper);
	zephir_array_update_string(return_value, SL("inputNumeric"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_1);
	ZEPHIR_INIT_NVAR(&_1);
	zephir_create_closure_ex(&_1, this_ptr, phalcon_33__closure_ce, SL("__invoke"));
	zephir_update_static_property_ce(phalcon_33__closure_ce, ZEND_STRL("escaper"), &escaper);
	zephir_array_update_string(return_value, SL("inputPassword"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_1);
	ZEPHIR_INIT_NVAR(&_1);
	zephir_create_closure_ex(&_1, this_ptr, phalcon_34__closure_ce, SL("__invoke"));
	zephir_update_static_property_ce(phalcon_34__closure_ce, ZEND_STRL("escaper"), &escaper);
	zephir_array_update_string(return_value, SL("inputRadio"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_1);
	ZEPHIR_INIT_NVAR(&_1);
	zephir_create_closure_ex(&_1, this_ptr, phalcon_35__closure_ce, SL("__invoke"));
	zephir_update_static_property_ce(phalcon_35__closure_ce, ZEND_STRL("escaper"), &escaper);
	zephir_array_update_string(return_value, SL("inputRange"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_1);
	ZEPHIR_INIT_NVAR(&_1);
	zephir_create_closure_ex(&_1, this_ptr, phalcon_36__closure_ce, SL("__invoke"));
	zephir_update_static_property_ce(phalcon_36__closure_ce, ZEND_STRL("escaper"), &escaper);
	zephir_array_update_string(return_value, SL("inputSearch"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_1);
	ZEPHIR_INIT_NVAR(&_1);
	zephir_create_closure_ex(&_1, this_ptr, phalcon_37__closure_ce, SL("__invoke"));
	zephir_update_static_property_ce(phalcon_37__closure_ce, ZEND_STRL("escaper"), &escaper);
	zephir_array_update_string(return_value, SL("inputSelect"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_1);
	ZEPHIR_INIT_NVAR(&_1);
	zephir_create_closure_ex(&_1, this_ptr, phalcon_38__closure_ce, SL("__invoke"));
	zephir_update_static_property_ce(phalcon_38__closure_ce, ZEND_STRL("escaper"), &escaper);
	zephir_array_update_string(return_value, SL("inputSubmit"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_1);
	ZEPHIR_INIT_NVAR(&_1);
	zephir_create_closure_ex(&_1, this_ptr, phalcon_39__closure_ce, SL("__invoke"));
	zephir_update_static_property_ce(phalcon_39__closure_ce, ZEND_STRL("escaper"), &escaper);
	zephir_array_update_string(return_value, SL("inputTel"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_1);
	ZEPHIR_INIT_NVAR(&_1);
	zephir_create_closure_ex(&_1, this_ptr, phalcon_40__closure_ce, SL("__invoke"));
	zephir_update_static_property_ce(phalcon_40__closure_ce, ZEND_STRL("escaper"), &escaper);
	zephir_array_update_string(return_value, SL("inputText"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_1);
	ZEPHIR_INIT_NVAR(&_1);
	zephir_create_closure_ex(&_1, this_ptr, phalcon_41__closure_ce, SL("__invoke"));
	zephir_update_static_property_ce(phalcon_41__closure_ce, ZEND_STRL("escaper"), &escaper);
	zephir_array_update_string(return_value, SL("inputTextarea"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_1);
	ZEPHIR_INIT_NVAR(&_1);
	zephir_create_closure_ex(&_1, this_ptr, phalcon_42__closure_ce, SL("__invoke"));
	zephir_update_static_property_ce(phalcon_42__closure_ce, ZEND_STRL("escaper"), &escaper);
	zephir_array_update_string(return_value, SL("inputTime"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_1);
	ZEPHIR_INIT_NVAR(&_1);
	zephir_create_closure_ex(&_1, this_ptr, phalcon_43__closure_ce, SL("__invoke"));
	zephir_update_static_property_ce(phalcon_43__closure_ce, ZEND_STRL("escaper"), &escaper);
	zephir_array_update_string(return_value, SL("inputUrl"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_1);
	ZEPHIR_INIT_NVAR(&_1);
	zephir_create_closure_ex(&_1, this_ptr, phalcon_44__closure_ce, SL("__invoke"));
	zephir_update_static_property_ce(phalcon_44__closure_ce, ZEND_STRL("escaper"), &escaper);
	zephir_array_update_string(return_value, SL("inputWeek"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_1);
	ZEPHIR_INIT_NVAR(&_1);
	zephir_create_closure_ex(&_1, this_ptr, phalcon_45__closure_ce, SL("__invoke"));
	zephir_update_static_property_ce(phalcon_45__closure_ce, ZEND_STRL("escaper"), &escaper);
	zephir_array_update_string(return_value, SL("label"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_1);
	ZEPHIR_INIT_NVAR(&_1);
	zephir_create_closure_ex(&_1, this_ptr, phalcon_46__closure_ce, SL("__invoke"));
	zephir_update_static_property_ce(phalcon_46__closure_ce, ZEND_STRL("escaper"), &escaper);
	zephir_array_update_string(return_value, SL("labelRaw"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_1);
	ZEPHIR_INIT_NVAR(&_1);
	zephir_create_closure_ex(&_1, this_ptr, phalcon_47__closure_ce, SL("__invoke"));
	zephir_update_static_property_ce(phalcon_47__closure_ce, ZEND_STRL("escaper"), &escaper);
	zephir_array_update_string(return_value, SL("link"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_1);
	ZEPHIR_INIT_NVAR(&_1);
	zephir_create_closure_ex(&_1, this_ptr, phalcon_48__closure_ce, SL("__invoke"));
	zephir_update_static_property_ce(phalcon_48__closure_ce, ZEND_STRL("escaper"), &escaper);
	zephir_array_update_string(return_value, SL("meta"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_1);
	ZEPHIR_INIT_NVAR(&_1);
	zephir_create_closure_ex(&_1, this_ptr, phalcon_49__closure_ce, SL("__invoke"));
	zephir_update_static_property_ce(phalcon_49__closure_ce, ZEND_STRL("escaper"), &escaper);
	zephir_array_update_string(return_value, SL("ol"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_1);
	ZEPHIR_INIT_NVAR(&_1);
	zephir_create_closure_ex(&_1, this_ptr, phalcon_50__closure_ce, SL("__invoke"));
	zephir_update_static_property_ce(phalcon_50__closure_ce, ZEND_STRL("escaper"), &escaper);
	zephir_array_update_string(return_value, SL("olRaw"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_1);
	ZEPHIR_INIT_NVAR(&_1);
	zephir_create_closure_ex(&_1, NULL, phalcon_51__closure_ce, SL("__invoke"));
	zephir_update_static_property_ce(phalcon_51__closure_ce, ZEND_STRL("escaper"), &escaper);
	zephir_update_static_property_ce(phalcon_51__closure_ce, ZEND_STRL("response"), &response);
	zephir_array_update_string(return_value, SL("preload"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_1);
	ZEPHIR_INIT_NVAR(&_1);
	zephir_create_closure_ex(&_1, this_ptr, phalcon_52__closure_ce, SL("__invoke"));
	zephir_update_static_property_ce(phalcon_52__closure_ce, ZEND_STRL("escaper"), &escaper);
	zephir_array_update_string(return_value, SL("script"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_1);
	ZEPHIR_INIT_NVAR(&_1);
	zephir_create_closure_ex(&_1, this_ptr, phalcon_53__closure_ce, SL("__invoke"));
	zephir_update_static_property_ce(phalcon_53__closure_ce, ZEND_STRL("escaper"), &escaper);
	zephir_array_update_string(return_value, SL("style"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_1);
	ZEPHIR_INIT_NVAR(&_1);
	zephir_create_closure_ex(&_1, this_ptr, phalcon_54__closure_ce, SL("__invoke"));
	zephir_update_static_property_ce(phalcon_54__closure_ce, ZEND_STRL("escaper"), &escaper);
	zephir_array_update_string(return_value, SL("tag"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_1);
	ZEPHIR_INIT_NVAR(&_1);
	zephir_create_closure_ex(&_1, this_ptr, phalcon_55__closure_ce, SL("__invoke"));
	zephir_update_static_property_ce(phalcon_55__closure_ce, ZEND_STRL("escaper"), &escaper);
	zephir_array_update_string(return_value, SL("title"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_1);
	ZEPHIR_INIT_NVAR(&_1);
	zephir_create_closure_ex(&_1, this_ptr, phalcon_56__closure_ce, SL("__invoke"));
	zephir_update_static_property_ce(phalcon_56__closure_ce, ZEND_STRL("escaper"), &escaper);
	zephir_array_update_string(return_value, SL("ul"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_1);
	ZEPHIR_INIT_NVAR(&_1);
	zephir_create_closure_ex(&_1, this_ptr, phalcon_57__closure_ce, SL("__invoke"));
	zephir_update_static_property_ce(phalcon_57__closure_ce, ZEND_STRL("escaper"), &escaper);
	zephir_array_update_string(return_value, SL("ulRaw"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_1);
	ZEPHIR_INIT_NVAR(&_1);
	zephir_create_closure_ex(&_1, this_ptr, phalcon_58__closure_ce, SL("__invoke"));
	zephir_update_static_property_ce(phalcon_58__closure_ce, ZEND_STRL("escaper"), &escaper);
	zephir_array_update_string(return_value, SL("voidTag"), &_1, PH_COPY | PH_SEPARATE);
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

