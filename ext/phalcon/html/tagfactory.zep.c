
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
#include "kernel/operators.h"
#include "kernel/array.h"
#include "kernel/exception.h"
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
 * @phpstan-import-type html_attributes from HtmlTypes
 * @phpstan-import-type html_group_options from HtmlTypes
 * @phpstan-import-type html_factory_instances from HtmlTypes
 * @phpstan-import-type html_factory_services from HtmlTypes
 *
 * @method string        a(string $href, string $text, html_attributes $attributes = [], bool $raw = false)
 * @method string        aRaw(string $href, string $text, html_attributes $attributes = [])
 * @method string        base(string $href, html_attributes $attributes = [])
 * @method string        body(html_attributes $attributes = [])
 * @method Breadcrumbs   breadcrumbs(string $indent = '    ', string $delimiter = "\n")
 * @method string        button(string $text, html_attributes $attributes = [], bool $raw = false)
 * @method string        buttonRaw(string $text, html_attributes $attributes = [])
 * @method string        close(string $tag, bool $raw = false)
 * @method Doctype       doctype(int $type = Doctype::HTML5, string $delimiter = "\n")
 * @method string        element(string $tag, string $text, html_attributes $attributes = [], bool $raw = false)
 * @method string        elementRaw(string $tag, string $text, html_attributes $attributes = [])
 * @method string        form(html_attributes $attributes = [])
 * @method string        friendlyTitle(string $text, string $separator = '-', bool $lower = true, mixed $replace = null)
 * @method string        img(string $src, html_attributes $attributes = [])
 * @method Checkbox      inputCheckbox(string $name, string $value = null, html_attributes $attributes = [])
 * @method CheckboxGroup inputCheckboxGroup(string $name, array $options, mixed $checked = null, array $attributes = [])
 * @method Generic       inputColor(string $name, string $value = null, html_attributes $attributes = [])
 * @method Generic       inputDate(string $name, string $value = null, html_attributes $attributes = [])
 * @method Generic       inputDateTime(string $name, string $value = null, html_attributes $attributes = [])
 * @method Generic       inputDateTimeLocal(string $name, string $value = null, html_attributes $attributes = [])
 * @method Generic       inputEmail(string $name, string $value = null, html_attributes $attributes = [])
 * @method Generic       inputFile(string $name, string $value = null, html_attributes $attributes = [])
 * @method Generic       inputHidden(string $name, string $value = null, html_attributes $attributes = [])
 * @method Generic       inputImage(string $name, string $value = null, html_attributes $attributes = [])
 * @method Generic       inputInput(string $name, string $value = null, html_attributes $attributes = [])
 * @method Generic       inputMonth(string $name, string $value = null, html_attributes $attributes = [])
 * @method Generic       inputNumeric(string $name, string $value = null, html_attributes $attributes = [])
 * @method Generic       inputPassword(string $name, string $value = null, html_attributes $attributes = [])
 * @method Radio         inputRadio(string $name, string $value = null, html_attributes $attributes = [])
 * @method RadioGroup    inputRadioGroup(string $name, array $options, mixed $checked = null, array $attributes = [])
 * @method Generic       inputRange(string $name, string $value = null, html_attributes $attributes = [])
 * @method Generic       inputSearch(string $name, string $value = null, html_attributes $attributes = [])
 * @method Select        inputSelect(string $name, string $value = null, html_attributes $attributes = [])
 * @method Generic       inputSubmit(string $name, string $value = null, html_attributes $attributes = [])
 * @method Generic       inputTel(string $name, string $value = null, html_attributes $attributes = [])
 * @method Generic       inputText(string $name, string $value = null, html_attributes $attributes = [])
 * @method Textarea      inputTextarea(string $name, string $value = null, html_attributes $attributes = [])
 * @method Generic       inputTime(string $name, string $value = null, html_attributes $attributes = [])
 * @method Generic       inputUrl(string $name, string $value = null, html_attributes $attributes = [])
 * @method Generic       inputWeek(string $name, string $value = null, html_attributes $attributes = [])
 * @method string        label(string $label, html_attributes $attributes = [], bool $raw = false)
 * @method string        labelRaw(string $label, html_attributes $attributes = [])
 * @method Link          link(string $indent = '    ', string $delimiter = "\n")
 * @method Meta          meta(string $indent = '    ', string $delimiter = "\n")
 * @method Ol            ol(string $indent = '    ', string $delimiter = null, html_attributes $attributes = [])
 * @method Ol            olRaw(string $indent = '    ', string $delimiter = null, html_attributes $attributes = [])
 * @method string        preload(string $href, string $type = 'style', html_attributes $attributes = [])
 * @method Script        script(string $indent = '    ', string $delimiter = "\n")
 * @method Style         style(string $indent = '    ', string $delimiter = "\n")
 * @method string        tag(string $name, html_attributes $attributes = [])
 * @method Title         title(string $indent = '    ', string $delimiter = "\n")
 * @method Ul            ul(string $indent = '    ', string $delimiter = null, html_attributes $attributes = [])
 * @method Ul            ulRaw(string $indent = '    ', string $delimiter = null, html_attributes $attributes = [])
 * @method string        voidTag(string $name, html_attributes $attributes = [])
 */
ZEPHIR_INIT_CLASS(Phalcon_Html_TagFactory)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\Html, TagFactory, phalcon, html_tagfactory, phalcon_html_tagfactory_method_entry, 0);

	{
		zval _zc0;
		ZVAL_UNDEF(&_zc0);
		zephir_declare_typed_property(phalcon_html_tagfactory_ce, SL("doctype"), &_zc0, ZEND_ACC_PRIVATE, 0, SL("Phalcon\\Html\\Helper\\Doctype"));
	}

	{
		zval _zc0;
		ZVAL_UNDEF(&_zc0);
		zephir_declare_typed_property(phalcon_html_tagfactory_ce, SL("escaper"), &_zc0, ZEND_ACC_PRIVATE, 0, SL("Phalcon\\Html\\Escaper\\EscaperInterface"));
	}

	{
		zval _zc0;
		ZVAL_NULL(&_zc0);
		zephir_declare_typed_property(phalcon_html_tagfactory_ce, SL("response"), &_zc0, ZEND_ACC_PRIVATE, MAY_BE_NULL, SL("Phalcon\\Http\\ResponseInterface"));
	}

	{
		zval _zc0;
		ZVAL_NULL(&_zc0);
		zephir_declare_typed_property(phalcon_html_tagfactory_ce, SL("url"), &_zc0, ZEND_ACC_PRIVATE, MAY_BE_NULL, SL("Phalcon\\Mvc\\Url\\UrlInterface"));
	}

	/**
	 * @phpstan-var html_factory_services
	 */
	{
		zval _zc0;
		array_init_size(&_zc0, 1);
		zephir_declare_typed_property(phalcon_html_tagfactory_ce, SL("factories"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_ARRAY, NULL, 0);
	}

	/**
	 * @phpstan-var html_factory_instances
	 */
	{
		zval _zc0;
		array_init_size(&_zc0, 1);
		zephir_declare_typed_property(phalcon_html_tagfactory_ce, SL("instances"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_ARRAY, NULL, 0);
	}

	return SUCCESS;
}

/**
 * TagFactory constructor.
 *
 * `$services` maps a service name to a zero-arg Closure that returns the
 * helper instance.
 *
 * @phpstan-param html_factory_services $services
 */
PHP_METHOD(Phalcon_Html_TagFactory, __construct)
{
	zend_bool _7;
	zend_string *_4;
	zend_ulong _3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_5 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval services;
	zval *escaper, escaper_sub, *services_param = NULL, *response = NULL, response_sub, *url = NULL, url_sub, __$null, name, definition, _0, _1, *_2, _6;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&escaper_sub);
	ZVAL_UNDEF(&response_sub);
	ZVAL_UNDEF(&url_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&definition);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&services);
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	static zend_string *_zephir_prop_2 = NULL;
	static zend_string *_zephir_prop_3 = NULL;
	static zend_string *_zephir_prop_4 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("escaper", 7, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("response", 8, 1);
	}
	if (UNEXPECTED(!_zephir_prop_2)) {
		_zephir_prop_2 = zend_string_init("url", 3, 1);
	}
	if (UNEXPECTED(!_zephir_prop_3)) {
		_zephir_prop_3 = zend_string_init("doctype", 7, 1);
	}
	if (UNEXPECTED(!_zephir_prop_4)) {
		_zephir_prop_4 = zend_string_init("factories", 9, 1);
	}

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
		zephir_get_arrval(&services, services_param);
	}
	if (!response) {
		response = &response_sub;
		response = &__$null;
	}
	if (!url) {
		url = &url_sub;
		url = &__$null;
	}
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 862, escaper);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_1, 863, response);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_2, 864, url);
	ZEPHIR_INIT_VAR(&_0);
	object_init_ex(&_0, phalcon_html_helper_doctype_ce);
	ZEPHIR_CALL_METHOD(NULL, &_0, "__construct", NULL, 0);
	zephir_check_call_status();
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_3, 865, &_0);
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "getdefaultservices", NULL, 0);
	zephir_check_call_status();
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_4, 866, &_1);
	zephir_is_iterable(&services, 0, "phalcon/Html/TagFactory.zep", 166);
	if (Z_TYPE_P(&services) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&services), _3, _4, _2)
		{
			ZEPHIR_INIT_NVAR(&name);
			if (_4 != NULL) { 
				ZVAL_STR_COPY(&name, _4);
			} else {
				ZVAL_LONG(&name, _3);
			}
			ZEPHIR_INIT_NVAR(&definition);
			ZVAL_COPY(&definition, _2);
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "set", &_5, 0, &name, &definition);
			zephir_check_call_status();
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &services, "rewind", NULL, 0);
		zephir_check_call_status();
		_7 = 1;
		while (1) {
			if (_7) {
				_7 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, &services, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_6, &services, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_6)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&name, &services, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&definition, &services, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_CALL_METHOD(NULL, this_ptr, "set", &_5, 0, &name, &definition);
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
 * @phpstan-param array<int, mixed> $arguments
 *
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
	zephir_memory_observe(&name_zv);
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
 */
PHP_METHOD(Phalcon_Html_TagFactory, has)
{
	zval name_zv, _0;
	zend_string *name = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_zv);
	ZVAL_UNDEF(&_0);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("factories", 9, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(name)
	ZEND_PARSE_PARAMETERS_END();
	ZVAL_STR(&name_zv, name);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 866, PH_NOISY_CC | PH_READONLY);
	RETURN_BOOL(zephir_array_isset_value(&_0, &name_zv));
}

/**
 * Create or return a cached instance of the helper.
 *
 * @throws \Phalcon\Html\Exception
 *
 * @phpstan-return ($name is 'doctype' ? Doctype : object)
 */
PHP_METHOD(Phalcon_Html_TagFactory, newInstance)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval name_zv, factory, _0, _2, _5, _6, _1$$3, _3$$4, _4$$4;
	zend_string *name = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_zv);
	ZVAL_UNDEF(&factory);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_4$$4);
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("factories", 9, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("instances", 9, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(name)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&name_zv);
	ZVAL_STR_COPY(&name_zv, name);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 866, PH_NOISY_CC | PH_READONLY);
	if (!(zephir_array_isset_value(&_0, &name_zv))) {
		ZEPHIR_INIT_VAR(&_1$$3);
		object_init_ex(&_1$$3, phalcon_html_exceptions_servicenotregistered_ce);
		ZEPHIR_CALL_METHOD(NULL, &_1$$3, "__construct", NULL, 0, &name_zv);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$3, "phalcon/Html/TagFactory.zep", 203);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_read_property_cached(&_2, this_ptr, _zephir_prop_1, 867, PH_NOISY_CC | PH_READONLY);
	if (!(zephir_array_isset_value(&_2, &name_zv))) {
		zephir_read_property_cached(&_3$$4, this_ptr, _zephir_prop_0, 866, PH_NOISY_CC | PH_READONLY);
		zephir_memory_observe(&factory);
		zephir_array_fetch(&factory, &_3$$4, &name_zv, PH_NOISY, "phalcon/Html/TagFactory.zep", 207);
		ZEPHIR_INIT_VAR(&_4$$4);
		ZEPHIR_CALL_USER_FUNC(&_4$$4, &factory);
		zephir_check_call_status();
		zephir_update_property_array(this_ptr, SL("instances"), &name_zv, &_4$$4);
	}
	zephir_read_property_cached(&_5, this_ptr, _zephir_prop_1, 867, PH_NOISY_CC | PH_READONLY);
	zephir_array_fetch(&_6, &_5, &name_zv, PH_NOISY | PH_READONLY, "phalcon/Html/TagFactory.zep", 211);
	RETURN_CTOR(&_6);
}

/**
 * Register a helper via a zero-argument Closure. The Closure is invoked on
 * the first matching `newInstance()` call and its return value is cached.
 * Passing a new definition clears any cached instance so the next call to
 * `newInstance()` rebuilds it.
 */
PHP_METHOD(Phalcon_Html_TagFactory, set)
{
	zval name_zv, *definition, definition_sub, _0;
	zend_string *name = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_zv);
	ZVAL_UNDEF(&definition_sub);
	ZVAL_UNDEF(&_0);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("instances", 9, 1);
	}

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR(name)
		Z_PARAM_OBJECT_OF_CLASS(definition, zend_ce_closure)
	ZEND_PARSE_PARAMETERS_END();
	definition = ZEND_CALL_ARG(execute_data, 2);
	ZVAL_STR(&name_zv, name);
	zephir_update_property_array(this_ptr, SL("factories"), &name_zv, definition);
	zephir_unset_property_array(this_ptr, ZEND_STRL("instances"), &name_zv);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 867, PH_NOISY_CC | PH_READONLY);
	zephir_array_unset(&_0, &name_zv, PH_SEPARATE);
}

/**
 * Default service recipes. Every entry is a callable that returns a
 * fully-constructed helper instance. Services are built lazily and cached.
 *
 * @phpstan-return html_factory_services
 */
PHP_METHOD(Phalcon_Html_TagFactory, getDefaultServices)
{
	zval escaper, response, url, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&escaper);
	ZVAL_UNDEF(&response);
	ZVAL_UNDEF(&url);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_11);
	ZVAL_UNDEF(&_12);
	ZVAL_UNDEF(&_13);
	ZVAL_UNDEF(&_14);
	ZVAL_UNDEF(&_15);
	ZVAL_UNDEF(&_16);
	ZVAL_UNDEF(&_17);
	ZVAL_UNDEF(&_18);
	ZVAL_UNDEF(&_19);
	ZVAL_UNDEF(&_20);
	ZVAL_UNDEF(&_21);
	ZVAL_UNDEF(&_22);
	ZVAL_UNDEF(&_23);
	ZVAL_UNDEF(&_24);
	ZVAL_UNDEF(&_25);
	ZVAL_UNDEF(&_26);
	ZVAL_UNDEF(&_27);
	ZVAL_UNDEF(&_28);
	ZVAL_UNDEF(&_29);
	ZVAL_UNDEF(&_30);
	ZVAL_UNDEF(&_31);
	ZVAL_UNDEF(&_32);
	ZVAL_UNDEF(&_33);
	ZVAL_UNDEF(&_34);
	ZVAL_UNDEF(&_35);
	ZVAL_UNDEF(&_36);
	ZVAL_UNDEF(&_37);
	ZVAL_UNDEF(&_38);
	ZVAL_UNDEF(&_39);
	ZVAL_UNDEF(&_40);
	ZVAL_UNDEF(&_41);
	ZVAL_UNDEF(&_42);
	ZVAL_UNDEF(&_43);
	ZVAL_UNDEF(&_44);
	ZVAL_UNDEF(&_45);
	ZVAL_UNDEF(&_46);
	ZVAL_UNDEF(&_47);
	ZVAL_UNDEF(&_48);
	ZVAL_UNDEF(&_49);
	ZVAL_UNDEF(&_50);
	ZVAL_UNDEF(&_51);
	ZVAL_UNDEF(&_52);
	ZVAL_UNDEF(&_53);
	ZVAL_UNDEF(&_54);
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	static zend_string *_zephir_prop_2 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("escaper", 7, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("response", 8, 1);
	}
	if (UNEXPECTED(!_zephir_prop_2)) {
		_zephir_prop_2 = zend_string_init("url", 3, 1);
	}
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 862, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&escaper, &_0);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_1, 863, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&response, &_0);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_2, 864, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&url, &_0);
	zephir_create_array(return_value, 59, 0);
	ZEPHIR_INIT_VAR(&_1);
	object_init_ex(&_1, phalcon_35__closure_ce);
	zephir_update_property_zval(&_1, SL("escaper"), &escaper);
	zephir_update_property_zval(&_1, SL("__$zephir_this"), this_ptr);
	ZEPHIR_INIT_VAR(&_2);
	ZEPHIR_INIT_NVAR(&_2);
	zephir_create_closure_bound(&_2, &_1, this_ptr, phalcon_35__closure_ce, SL("__invoke"));
	zephir_array_update_string(return_value, SL("a"), &_2, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_2);
	object_init_ex(&_2, phalcon_36__closure_ce);
	zephir_update_property_zval(&_2, SL("escaper"), &escaper);
	zephir_update_property_zval(&_2, SL("__$zephir_this"), this_ptr);
	ZEPHIR_INIT_VAR(&_3);
	ZEPHIR_INIT_NVAR(&_3);
	zephir_create_closure_bound(&_3, &_2, this_ptr, phalcon_36__closure_ce, SL("__invoke"));
	zephir_array_update_string(return_value, SL("aRaw"), &_3, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_3);
	object_init_ex(&_3, phalcon_37__closure_ce);
	zephir_update_property_zval(&_3, SL("escaper"), &escaper);
	zephir_update_property_zval(&_3, SL("__$zephir_this"), this_ptr);
	ZEPHIR_INIT_VAR(&_4);
	ZEPHIR_INIT_NVAR(&_4);
	zephir_create_closure_bound(&_4, &_3, this_ptr, phalcon_37__closure_ce, SL("__invoke"));
	zephir_array_update_string(return_value, SL("base"), &_4, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_4);
	object_init_ex(&_4, phalcon_38__closure_ce);
	zephir_update_property_zval(&_4, SL("escaper"), &escaper);
	zephir_update_property_zval(&_4, SL("__$zephir_this"), this_ptr);
	ZEPHIR_INIT_VAR(&_5);
	ZEPHIR_INIT_NVAR(&_5);
	zephir_create_closure_bound(&_5, &_4, this_ptr, phalcon_38__closure_ce, SL("__invoke"));
	zephir_array_update_string(return_value, SL("body"), &_5, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_5);
	object_init_ex(&_5, phalcon_39__closure_ce);
	zephir_update_property_zval(&_5, SL("escaper"), &escaper);
	zephir_update_property_zval(&_5, SL("url"), &url);
	ZEPHIR_INIT_VAR(&_6);
	ZEPHIR_INIT_NVAR(&_6);
	zephir_create_closure_bound(&_6, &_5, NULL, phalcon_39__closure_ce, SL("__invoke"));
	zephir_array_update_string(return_value, SL("breadcrumbs"), &_6, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_6);
	object_init_ex(&_6, phalcon_40__closure_ce);
	zephir_update_property_zval(&_6, SL("escaper"), &escaper);
	zephir_update_property_zval(&_6, SL("__$zephir_this"), this_ptr);
	ZEPHIR_INIT_VAR(&_7);
	ZEPHIR_INIT_NVAR(&_7);
	zephir_create_closure_bound(&_7, &_6, this_ptr, phalcon_40__closure_ce, SL("__invoke"));
	zephir_array_update_string(return_value, SL("button"), &_7, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_7);
	object_init_ex(&_7, phalcon_41__closure_ce);
	zephir_update_property_zval(&_7, SL("escaper"), &escaper);
	zephir_update_property_zval(&_7, SL("__$zephir_this"), this_ptr);
	ZEPHIR_INIT_VAR(&_8);
	ZEPHIR_INIT_NVAR(&_8);
	zephir_create_closure_bound(&_8, &_7, this_ptr, phalcon_41__closure_ce, SL("__invoke"));
	zephir_array_update_string(return_value, SL("buttonRaw"), &_8, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_8);
	object_init_ex(&_8, phalcon_42__closure_ce);
	zephir_update_property_zval(&_8, SL("escaper"), &escaper);
	zephir_update_property_zval(&_8, SL("__$zephir_this"), this_ptr);
	ZEPHIR_INIT_VAR(&_9);
	ZEPHIR_INIT_NVAR(&_9);
	zephir_create_closure_bound(&_9, &_8, this_ptr, phalcon_42__closure_ce, SL("__invoke"));
	zephir_array_update_string(return_value, SL("close"), &_9, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_9);
	ZEPHIR_INIT_NVAR(&_9);
	zephir_create_closure_ex(&_9, this_ptr, phalcon_43__closure_ce, SL("__invoke"));
	zephir_array_update_string(return_value, SL("doctype"), &_9, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_9);
	object_init_ex(&_9, phalcon_44__closure_ce);
	zephir_update_property_zval(&_9, SL("escaper"), &escaper);
	zephir_update_property_zval(&_9, SL("__$zephir_this"), this_ptr);
	ZEPHIR_INIT_VAR(&_10);
	ZEPHIR_INIT_NVAR(&_10);
	zephir_create_closure_bound(&_10, &_9, this_ptr, phalcon_44__closure_ce, SL("__invoke"));
	zephir_array_update_string(return_value, SL("element"), &_10, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_10);
	object_init_ex(&_10, phalcon_45__closure_ce);
	zephir_update_property_zval(&_10, SL("escaper"), &escaper);
	zephir_update_property_zval(&_10, SL("__$zephir_this"), this_ptr);
	ZEPHIR_INIT_VAR(&_11);
	ZEPHIR_INIT_NVAR(&_11);
	zephir_create_closure_bound(&_11, &_10, this_ptr, phalcon_45__closure_ce, SL("__invoke"));
	zephir_array_update_string(return_value, SL("elementRaw"), &_11, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_11);
	object_init_ex(&_11, phalcon_46__closure_ce);
	zephir_update_property_zval(&_11, SL("escaper"), &escaper);
	zephir_update_property_zval(&_11, SL("__$zephir_this"), this_ptr);
	ZEPHIR_INIT_VAR(&_12);
	ZEPHIR_INIT_NVAR(&_12);
	zephir_create_closure_bound(&_12, &_11, this_ptr, phalcon_46__closure_ce, SL("__invoke"));
	zephir_array_update_string(return_value, SL("form"), &_12, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_12);
	object_init_ex(&_12, phalcon_47__closure_ce);
	zephir_update_property_zval(&_12, SL("escaper"), &escaper);
	ZEPHIR_INIT_VAR(&_13);
	ZEPHIR_INIT_NVAR(&_13);
	zephir_create_closure_bound(&_13, &_12, NULL, phalcon_47__closure_ce, SL("__invoke"));
	zephir_array_update_string(return_value, SL("friendlyTitle"), &_13, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_13);
	object_init_ex(&_13, phalcon_48__closure_ce);
	zephir_update_property_zval(&_13, SL("escaper"), &escaper);
	zephir_update_property_zval(&_13, SL("__$zephir_this"), this_ptr);
	ZEPHIR_INIT_VAR(&_14);
	ZEPHIR_INIT_NVAR(&_14);
	zephir_create_closure_bound(&_14, &_13, this_ptr, phalcon_48__closure_ce, SL("__invoke"));
	zephir_array_update_string(return_value, SL("img"), &_14, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_14);
	object_init_ex(&_14, phalcon_49__closure_ce);
	zephir_update_property_zval(&_14, SL("escaper"), &escaper);
	zephir_update_property_zval(&_14, SL("__$zephir_this"), this_ptr);
	ZEPHIR_INIT_VAR(&_15);
	ZEPHIR_INIT_NVAR(&_15);
	zephir_create_closure_bound(&_15, &_14, this_ptr, phalcon_49__closure_ce, SL("__invoke"));
	zephir_array_update_string(return_value, SL("inputCheckbox"), &_15, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_15);
	object_init_ex(&_15, phalcon_50__closure_ce);
	zephir_update_property_zval(&_15, SL("escaper"), &escaper);
	zephir_update_property_zval(&_15, SL("__$zephir_this"), this_ptr);
	ZEPHIR_INIT_VAR(&_16);
	ZEPHIR_INIT_NVAR(&_16);
	zephir_create_closure_bound(&_16, &_15, this_ptr, phalcon_50__closure_ce, SL("__invoke"));
	zephir_array_update_string(return_value, SL("inputCheckboxGroup"), &_16, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_16);
	object_init_ex(&_16, phalcon_51__closure_ce);
	zephir_update_property_zval(&_16, SL("escaper"), &escaper);
	zephir_update_property_zval(&_16, SL("__$zephir_this"), this_ptr);
	ZEPHIR_INIT_VAR(&_17);
	ZEPHIR_INIT_NVAR(&_17);
	zephir_create_closure_bound(&_17, &_16, this_ptr, phalcon_51__closure_ce, SL("__invoke"));
	zephir_array_update_string(return_value, SL("inputColor"), &_17, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_17);
	object_init_ex(&_17, phalcon_52__closure_ce);
	zephir_update_property_zval(&_17, SL("escaper"), &escaper);
	zephir_update_property_zval(&_17, SL("__$zephir_this"), this_ptr);
	ZEPHIR_INIT_VAR(&_18);
	ZEPHIR_INIT_NVAR(&_18);
	zephir_create_closure_bound(&_18, &_17, this_ptr, phalcon_52__closure_ce, SL("__invoke"));
	zephir_array_update_string(return_value, SL("inputDate"), &_18, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_18);
	object_init_ex(&_18, phalcon_53__closure_ce);
	zephir_update_property_zval(&_18, SL("escaper"), &escaper);
	zephir_update_property_zval(&_18, SL("__$zephir_this"), this_ptr);
	ZEPHIR_INIT_VAR(&_19);
	ZEPHIR_INIT_NVAR(&_19);
	zephir_create_closure_bound(&_19, &_18, this_ptr, phalcon_53__closure_ce, SL("__invoke"));
	zephir_array_update_string(return_value, SL("inputDateTime"), &_19, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_19);
	object_init_ex(&_19, phalcon_54__closure_ce);
	zephir_update_property_zval(&_19, SL("escaper"), &escaper);
	zephir_update_property_zval(&_19, SL("__$zephir_this"), this_ptr);
	ZEPHIR_INIT_VAR(&_20);
	ZEPHIR_INIT_NVAR(&_20);
	zephir_create_closure_bound(&_20, &_19, this_ptr, phalcon_54__closure_ce, SL("__invoke"));
	zephir_array_update_string(return_value, SL("inputDateTimeLocal"), &_20, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_20);
	object_init_ex(&_20, phalcon_55__closure_ce);
	zephir_update_property_zval(&_20, SL("escaper"), &escaper);
	zephir_update_property_zval(&_20, SL("__$zephir_this"), this_ptr);
	ZEPHIR_INIT_VAR(&_21);
	ZEPHIR_INIT_NVAR(&_21);
	zephir_create_closure_bound(&_21, &_20, this_ptr, phalcon_55__closure_ce, SL("__invoke"));
	zephir_array_update_string(return_value, SL("inputEmail"), &_21, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_21);
	object_init_ex(&_21, phalcon_56__closure_ce);
	zephir_update_property_zval(&_21, SL("escaper"), &escaper);
	zephir_update_property_zval(&_21, SL("__$zephir_this"), this_ptr);
	ZEPHIR_INIT_VAR(&_22);
	ZEPHIR_INIT_NVAR(&_22);
	zephir_create_closure_bound(&_22, &_21, this_ptr, phalcon_56__closure_ce, SL("__invoke"));
	zephir_array_update_string(return_value, SL("inputFile"), &_22, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_22);
	object_init_ex(&_22, phalcon_57__closure_ce);
	zephir_update_property_zval(&_22, SL("escaper"), &escaper);
	zephir_update_property_zval(&_22, SL("__$zephir_this"), this_ptr);
	ZEPHIR_INIT_VAR(&_23);
	ZEPHIR_INIT_NVAR(&_23);
	zephir_create_closure_bound(&_23, &_22, this_ptr, phalcon_57__closure_ce, SL("__invoke"));
	zephir_array_update_string(return_value, SL("inputHidden"), &_23, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_23);
	object_init_ex(&_23, phalcon_58__closure_ce);
	zephir_update_property_zval(&_23, SL("escaper"), &escaper);
	zephir_update_property_zval(&_23, SL("__$zephir_this"), this_ptr);
	ZEPHIR_INIT_VAR(&_24);
	ZEPHIR_INIT_NVAR(&_24);
	zephir_create_closure_bound(&_24, &_23, this_ptr, phalcon_58__closure_ce, SL("__invoke"));
	zephir_array_update_string(return_value, SL("inputImage"), &_24, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_24);
	object_init_ex(&_24, phalcon_59__closure_ce);
	zephir_update_property_zval(&_24, SL("escaper"), &escaper);
	zephir_update_property_zval(&_24, SL("__$zephir_this"), this_ptr);
	ZEPHIR_INIT_VAR(&_25);
	ZEPHIR_INIT_NVAR(&_25);
	zephir_create_closure_bound(&_25, &_24, this_ptr, phalcon_59__closure_ce, SL("__invoke"));
	zephir_array_update_string(return_value, SL("inputInput"), &_25, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_25);
	object_init_ex(&_25, phalcon_60__closure_ce);
	zephir_update_property_zval(&_25, SL("escaper"), &escaper);
	zephir_update_property_zval(&_25, SL("__$zephir_this"), this_ptr);
	ZEPHIR_INIT_VAR(&_26);
	ZEPHIR_INIT_NVAR(&_26);
	zephir_create_closure_bound(&_26, &_25, this_ptr, phalcon_60__closure_ce, SL("__invoke"));
	zephir_array_update_string(return_value, SL("inputMonth"), &_26, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_26);
	object_init_ex(&_26, phalcon_61__closure_ce);
	zephir_update_property_zval(&_26, SL("escaper"), &escaper);
	zephir_update_property_zval(&_26, SL("__$zephir_this"), this_ptr);
	ZEPHIR_INIT_VAR(&_27);
	ZEPHIR_INIT_NVAR(&_27);
	zephir_create_closure_bound(&_27, &_26, this_ptr, phalcon_61__closure_ce, SL("__invoke"));
	zephir_array_update_string(return_value, SL("inputNumeric"), &_27, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_27);
	object_init_ex(&_27, phalcon_62__closure_ce);
	zephir_update_property_zval(&_27, SL("escaper"), &escaper);
	zephir_update_property_zval(&_27, SL("__$zephir_this"), this_ptr);
	ZEPHIR_INIT_VAR(&_28);
	ZEPHIR_INIT_NVAR(&_28);
	zephir_create_closure_bound(&_28, &_27, this_ptr, phalcon_62__closure_ce, SL("__invoke"));
	zephir_array_update_string(return_value, SL("inputPassword"), &_28, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_28);
	object_init_ex(&_28, phalcon_63__closure_ce);
	zephir_update_property_zval(&_28, SL("escaper"), &escaper);
	zephir_update_property_zval(&_28, SL("__$zephir_this"), this_ptr);
	ZEPHIR_INIT_VAR(&_29);
	ZEPHIR_INIT_NVAR(&_29);
	zephir_create_closure_bound(&_29, &_28, this_ptr, phalcon_63__closure_ce, SL("__invoke"));
	zephir_array_update_string(return_value, SL("inputRadio"), &_29, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_29);
	object_init_ex(&_29, phalcon_64__closure_ce);
	zephir_update_property_zval(&_29, SL("escaper"), &escaper);
	zephir_update_property_zval(&_29, SL("__$zephir_this"), this_ptr);
	ZEPHIR_INIT_VAR(&_30);
	ZEPHIR_INIT_NVAR(&_30);
	zephir_create_closure_bound(&_30, &_29, this_ptr, phalcon_64__closure_ce, SL("__invoke"));
	zephir_array_update_string(return_value, SL("inputRadioGroup"), &_30, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_30);
	object_init_ex(&_30, phalcon_65__closure_ce);
	zephir_update_property_zval(&_30, SL("escaper"), &escaper);
	zephir_update_property_zval(&_30, SL("__$zephir_this"), this_ptr);
	ZEPHIR_INIT_VAR(&_31);
	ZEPHIR_INIT_NVAR(&_31);
	zephir_create_closure_bound(&_31, &_30, this_ptr, phalcon_65__closure_ce, SL("__invoke"));
	zephir_array_update_string(return_value, SL("inputRange"), &_31, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_31);
	object_init_ex(&_31, phalcon_66__closure_ce);
	zephir_update_property_zval(&_31, SL("escaper"), &escaper);
	zephir_update_property_zval(&_31, SL("__$zephir_this"), this_ptr);
	ZEPHIR_INIT_VAR(&_32);
	ZEPHIR_INIT_NVAR(&_32);
	zephir_create_closure_bound(&_32, &_31, this_ptr, phalcon_66__closure_ce, SL("__invoke"));
	zephir_array_update_string(return_value, SL("inputSearch"), &_32, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_32);
	object_init_ex(&_32, phalcon_67__closure_ce);
	zephir_update_property_zval(&_32, SL("escaper"), &escaper);
	zephir_update_property_zval(&_32, SL("__$zephir_this"), this_ptr);
	ZEPHIR_INIT_VAR(&_33);
	ZEPHIR_INIT_NVAR(&_33);
	zephir_create_closure_bound(&_33, &_32, this_ptr, phalcon_67__closure_ce, SL("__invoke"));
	zephir_array_update_string(return_value, SL("inputSelect"), &_33, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_33);
	object_init_ex(&_33, phalcon_68__closure_ce);
	zephir_update_property_zval(&_33, SL("escaper"), &escaper);
	zephir_update_property_zval(&_33, SL("__$zephir_this"), this_ptr);
	ZEPHIR_INIT_VAR(&_34);
	ZEPHIR_INIT_NVAR(&_34);
	zephir_create_closure_bound(&_34, &_33, this_ptr, phalcon_68__closure_ce, SL("__invoke"));
	zephir_array_update_string(return_value, SL("inputSubmit"), &_34, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_34);
	object_init_ex(&_34, phalcon_69__closure_ce);
	zephir_update_property_zval(&_34, SL("escaper"), &escaper);
	zephir_update_property_zval(&_34, SL("__$zephir_this"), this_ptr);
	ZEPHIR_INIT_VAR(&_35);
	ZEPHIR_INIT_NVAR(&_35);
	zephir_create_closure_bound(&_35, &_34, this_ptr, phalcon_69__closure_ce, SL("__invoke"));
	zephir_array_update_string(return_value, SL("inputTel"), &_35, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_35);
	object_init_ex(&_35, phalcon_70__closure_ce);
	zephir_update_property_zval(&_35, SL("escaper"), &escaper);
	zephir_update_property_zval(&_35, SL("__$zephir_this"), this_ptr);
	ZEPHIR_INIT_VAR(&_36);
	ZEPHIR_INIT_NVAR(&_36);
	zephir_create_closure_bound(&_36, &_35, this_ptr, phalcon_70__closure_ce, SL("__invoke"));
	zephir_array_update_string(return_value, SL("inputText"), &_36, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_36);
	object_init_ex(&_36, phalcon_71__closure_ce);
	zephir_update_property_zval(&_36, SL("escaper"), &escaper);
	zephir_update_property_zval(&_36, SL("__$zephir_this"), this_ptr);
	ZEPHIR_INIT_VAR(&_37);
	ZEPHIR_INIT_NVAR(&_37);
	zephir_create_closure_bound(&_37, &_36, this_ptr, phalcon_71__closure_ce, SL("__invoke"));
	zephir_array_update_string(return_value, SL("inputTextarea"), &_37, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_37);
	object_init_ex(&_37, phalcon_72__closure_ce);
	zephir_update_property_zval(&_37, SL("escaper"), &escaper);
	zephir_update_property_zval(&_37, SL("__$zephir_this"), this_ptr);
	ZEPHIR_INIT_VAR(&_38);
	ZEPHIR_INIT_NVAR(&_38);
	zephir_create_closure_bound(&_38, &_37, this_ptr, phalcon_72__closure_ce, SL("__invoke"));
	zephir_array_update_string(return_value, SL("inputTime"), &_38, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_38);
	object_init_ex(&_38, phalcon_73__closure_ce);
	zephir_update_property_zval(&_38, SL("escaper"), &escaper);
	zephir_update_property_zval(&_38, SL("__$zephir_this"), this_ptr);
	ZEPHIR_INIT_VAR(&_39);
	ZEPHIR_INIT_NVAR(&_39);
	zephir_create_closure_bound(&_39, &_38, this_ptr, phalcon_73__closure_ce, SL("__invoke"));
	zephir_array_update_string(return_value, SL("inputUrl"), &_39, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_39);
	object_init_ex(&_39, phalcon_74__closure_ce);
	zephir_update_property_zval(&_39, SL("escaper"), &escaper);
	zephir_update_property_zval(&_39, SL("__$zephir_this"), this_ptr);
	ZEPHIR_INIT_VAR(&_40);
	ZEPHIR_INIT_NVAR(&_40);
	zephir_create_closure_bound(&_40, &_39, this_ptr, phalcon_74__closure_ce, SL("__invoke"));
	zephir_array_update_string(return_value, SL("inputWeek"), &_40, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_40);
	object_init_ex(&_40, phalcon_75__closure_ce);
	zephir_update_property_zval(&_40, SL("escaper"), &escaper);
	zephir_update_property_zval(&_40, SL("__$zephir_this"), this_ptr);
	ZEPHIR_INIT_VAR(&_41);
	ZEPHIR_INIT_NVAR(&_41);
	zephir_create_closure_bound(&_41, &_40, this_ptr, phalcon_75__closure_ce, SL("__invoke"));
	zephir_array_update_string(return_value, SL("label"), &_41, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_41);
	object_init_ex(&_41, phalcon_76__closure_ce);
	zephir_update_property_zval(&_41, SL("escaper"), &escaper);
	zephir_update_property_zval(&_41, SL("__$zephir_this"), this_ptr);
	ZEPHIR_INIT_VAR(&_42);
	ZEPHIR_INIT_NVAR(&_42);
	zephir_create_closure_bound(&_42, &_41, this_ptr, phalcon_76__closure_ce, SL("__invoke"));
	zephir_array_update_string(return_value, SL("labelRaw"), &_42, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_42);
	object_init_ex(&_42, phalcon_77__closure_ce);
	zephir_update_property_zval(&_42, SL("escaper"), &escaper);
	zephir_update_property_zval(&_42, SL("__$zephir_this"), this_ptr);
	ZEPHIR_INIT_VAR(&_43);
	ZEPHIR_INIT_NVAR(&_43);
	zephir_create_closure_bound(&_43, &_42, this_ptr, phalcon_77__closure_ce, SL("__invoke"));
	zephir_array_update_string(return_value, SL("link"), &_43, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_43);
	object_init_ex(&_43, phalcon_78__closure_ce);
	zephir_update_property_zval(&_43, SL("escaper"), &escaper);
	zephir_update_property_zval(&_43, SL("__$zephir_this"), this_ptr);
	ZEPHIR_INIT_VAR(&_44);
	ZEPHIR_INIT_NVAR(&_44);
	zephir_create_closure_bound(&_44, &_43, this_ptr, phalcon_78__closure_ce, SL("__invoke"));
	zephir_array_update_string(return_value, SL("meta"), &_44, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_44);
	object_init_ex(&_44, phalcon_79__closure_ce);
	zephir_update_property_zval(&_44, SL("escaper"), &escaper);
	zephir_update_property_zval(&_44, SL("__$zephir_this"), this_ptr);
	ZEPHIR_INIT_VAR(&_45);
	ZEPHIR_INIT_NVAR(&_45);
	zephir_create_closure_bound(&_45, &_44, this_ptr, phalcon_79__closure_ce, SL("__invoke"));
	zephir_array_update_string(return_value, SL("ol"), &_45, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_45);
	object_init_ex(&_45, phalcon_80__closure_ce);
	zephir_update_property_zval(&_45, SL("escaper"), &escaper);
	zephir_update_property_zval(&_45, SL("__$zephir_this"), this_ptr);
	ZEPHIR_INIT_VAR(&_46);
	ZEPHIR_INIT_NVAR(&_46);
	zephir_create_closure_bound(&_46, &_45, this_ptr, phalcon_80__closure_ce, SL("__invoke"));
	zephir_array_update_string(return_value, SL("olRaw"), &_46, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_46);
	object_init_ex(&_46, phalcon_81__closure_ce);
	zephir_update_property_zval(&_46, SL("escaper"), &escaper);
	zephir_update_property_zval(&_46, SL("response"), &response);
	ZEPHIR_INIT_VAR(&_47);
	ZEPHIR_INIT_NVAR(&_47);
	zephir_create_closure_bound(&_47, &_46, NULL, phalcon_81__closure_ce, SL("__invoke"));
	zephir_array_update_string(return_value, SL("preload"), &_47, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_47);
	object_init_ex(&_47, phalcon_82__closure_ce);
	zephir_update_property_zval(&_47, SL("escaper"), &escaper);
	zephir_update_property_zval(&_47, SL("__$zephir_this"), this_ptr);
	ZEPHIR_INIT_VAR(&_48);
	ZEPHIR_INIT_NVAR(&_48);
	zephir_create_closure_bound(&_48, &_47, this_ptr, phalcon_82__closure_ce, SL("__invoke"));
	zephir_array_update_string(return_value, SL("script"), &_48, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_48);
	object_init_ex(&_48, phalcon_83__closure_ce);
	zephir_update_property_zval(&_48, SL("escaper"), &escaper);
	zephir_update_property_zval(&_48, SL("__$zephir_this"), this_ptr);
	ZEPHIR_INIT_VAR(&_49);
	ZEPHIR_INIT_NVAR(&_49);
	zephir_create_closure_bound(&_49, &_48, this_ptr, phalcon_83__closure_ce, SL("__invoke"));
	zephir_array_update_string(return_value, SL("style"), &_49, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_49);
	object_init_ex(&_49, phalcon_84__closure_ce);
	zephir_update_property_zval(&_49, SL("escaper"), &escaper);
	zephir_update_property_zval(&_49, SL("__$zephir_this"), this_ptr);
	ZEPHIR_INIT_VAR(&_50);
	ZEPHIR_INIT_NVAR(&_50);
	zephir_create_closure_bound(&_50, &_49, this_ptr, phalcon_84__closure_ce, SL("__invoke"));
	zephir_array_update_string(return_value, SL("tag"), &_50, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_50);
	object_init_ex(&_50, phalcon_85__closure_ce);
	zephir_update_property_zval(&_50, SL("escaper"), &escaper);
	zephir_update_property_zval(&_50, SL("__$zephir_this"), this_ptr);
	ZEPHIR_INIT_VAR(&_51);
	ZEPHIR_INIT_NVAR(&_51);
	zephir_create_closure_bound(&_51, &_50, this_ptr, phalcon_85__closure_ce, SL("__invoke"));
	zephir_array_update_string(return_value, SL("title"), &_51, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_51);
	object_init_ex(&_51, phalcon_86__closure_ce);
	zephir_update_property_zval(&_51, SL("escaper"), &escaper);
	zephir_update_property_zval(&_51, SL("__$zephir_this"), this_ptr);
	ZEPHIR_INIT_VAR(&_52);
	ZEPHIR_INIT_NVAR(&_52);
	zephir_create_closure_bound(&_52, &_51, this_ptr, phalcon_86__closure_ce, SL("__invoke"));
	zephir_array_update_string(return_value, SL("ul"), &_52, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_52);
	object_init_ex(&_52, phalcon_87__closure_ce);
	zephir_update_property_zval(&_52, SL("escaper"), &escaper);
	zephir_update_property_zval(&_52, SL("__$zephir_this"), this_ptr);
	ZEPHIR_INIT_VAR(&_53);
	ZEPHIR_INIT_NVAR(&_53);
	zephir_create_closure_bound(&_53, &_52, this_ptr, phalcon_87__closure_ce, SL("__invoke"));
	zephir_array_update_string(return_value, SL("ulRaw"), &_53, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_53);
	object_init_ex(&_53, phalcon_88__closure_ce);
	zephir_update_property_zval(&_53, SL("escaper"), &escaper);
	zephir_update_property_zval(&_53, SL("__$zephir_this"), this_ptr);
	ZEPHIR_INIT_VAR(&_54);
	ZEPHIR_INIT_NVAR(&_54);
	zephir_create_closure_bound(&_54, &_53, this_ptr, phalcon_88__closure_ce, SL("__invoke"));
	zephir_array_update_string(return_value, SL("voidTag"), &_54, PH_COPY | PH_SEPARATE);
	RETURN_MM();
}

