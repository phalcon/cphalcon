
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
#include "kernel/fcall.h"
#include "kernel/memory.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/array.h"
#include "kernel/operators.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * ServiceLocator implementation for Tag helpers.
 *
 * Services are registered using the constructor using a key-value pair. The
 * key is the name of the tag helper, while the value is a callable that returns
 * the object.
 *
 * The class implements `__call()` to allow calling helper objects as methods.
 *
 * @property EscaperInterface $escaper
 * @property array            $services
 *
 * @method string a(string $href, string $text, array $attributes = [], bool $raw = false)
 * @method string base(string $href, array $attributes = [])
 * @method string body(array $attributes = [])
 * @method string button(string $text, array $attributes = [], bool $raw = false)
 * @method string close(string $tag, bool $raw = false)
 * @method string doctype(int $flag, string $delimiter)
 * @method string element(string $tag, string $text, array $attributes = [], bool $raw = false)
 * @method string form(array $attributes = [])
 * @method string img(string $src, array $attributes = [])
 * @method string inputCheckbox(string $name, string $value = null, array $attributes = [])
 * @method string inputColor(string $name, string $value = null, array $attributes = [])
 * @method string inputDate(string $name, string $value = null, array $attributes = [])
 * @method string inputDateTime(string $name, string $value = null, array $attributes = [])
 * @method string inputDateTimeLocal(string $name, string $value = null, array $attributes = [])
 * @method string inputEmail(string $name, string $value = null, array $attributes = [])
 * @method string inputFile(string $name, string $value = null, array $attributes = [])
 * @method string inputHidden(string $name, string $value = null, array $attributes = [])
 * @method string inputImage(string $name, string $value = null, array $attributes = [])
 * @method string inputInput(string $name, string $value = null, array $attributes = [])
 * @method string inputMonth(string $name, string $value = null, array $attributes = [])
 * @method string inputNumeric(string $name, string $value = null, array $attributes = [])
 * @method string inputPassword(string $name, string $value = null, array $attributes = [])
 * @method string inputRadio(string $name, string $value = null, array $attributes = [])
 * @method string inputRange(string $name, string $value = null, array $attributes = [])
 * @method string inputSearch(string $name, string $value = null, array $attributes = [])
 * @method string inputSelect(string $name, string $value = null, array $attributes = [])
 * @method string inputSubmit(string $name, string $value = null, array $attributes = [])
 * @method string inputTel(string $name, string $value = null, array $attributes = [])
 * @method string inputText(string $name, string $value = null, array $attributes = [])
 * @method string inputTextarea(string $name, string $value = null, array $attributes = [])
 * @method string inputTime(string $name, string $value = null, array $attributes = [])
 * @method string inputUrl(string $name, string $value = null, array $attributes = [])
 * @method string inputWeek(string $name, string $value = null, array $attributes = [])
 * @method string label(string $label, array $attributes = [], bool $raw = false)
 * @method string link(string $indent = '    ', string $delimiter = PHP_EOL)
 * @method string meta(string $indent = '    ', string $delimiter = PHP_EOL)
 * @method string ol(string $text, array $attributes = [], bool $raw = false)
 * @method string script(string $indent = '    ', string $delimiter = PHP_EOL)
 * @method string style(string $indent = '    ', string $delimiter = PHP_EOL)
 * @method string title(string $indent = '    ', string $delimiter = PHP_EOL)
 * @method string ul(string $text, array $attributes = [], bool $raw = false)
 */
ZEPHIR_INIT_CLASS(Phalcon_Html_TagFactory)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Html, TagFactory, phalcon, html_tagfactory, phalcon_factory_abstractfactory_ce, phalcon_html_tagfactory_method_entry, 0);

	/**
	 * @var EscaperInterface
	 */
	zend_declare_property_null(phalcon_html_tagfactory_ce, SL("escaper"), ZEND_ACC_PRIVATE);
	/**
	 * @var array
	 */
	zend_declare_property_null(phalcon_html_tagfactory_ce, SL("services"), ZEND_ACC_PROTECTED);
	phalcon_html_tagfactory_ce->create_object = zephir_init_properties_Phalcon_Html_TagFactory;

	return SUCCESS;
}

/**
 * TagFactory constructor.
 *
 * @param Escaper $escaper
 * @param array   $services
 */
PHP_METHOD(Phalcon_Html_TagFactory, __construct)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval services;
	zval *escaper, escaper_sub, *services_param = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&escaper_sub);
	ZVAL_UNDEF(&services);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_OBJECT_OF_CLASS(escaper, phalcon_html_escaper_escaperinterface_ce)
		Z_PARAM_OPTIONAL
		Z_PARAM_ARRAY(services)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &escaper, &services_param);
	if (!services_param) {
		ZEPHIR_INIT_VAR(&services);
		array_init(&services);
	} else {
	ZEPHIR_OBS_COPY_OR_DUP(&services, services_param);
	}


	zephir_update_property_zval(this_ptr, ZEND_STRL("escaper"), escaper);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "init", NULL, 0, &services);
	zephir_check_call_status();
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
	zval *name_param = NULL, *arguments_param = NULL, helper, _1;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&helper);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&arguments);
	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR(name)
		Z_PARAM_ARRAY(arguments)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &name_param, &arguments_param);
	zephir_get_strval(&name, name_param);
	zephir_get_arrval(&arguments, arguments_param);


	ZEPHIR_CALL_METHOD(&helper, this_ptr, "newinstance", NULL, 0, &name);
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
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *name_param = NULL, _0;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(name)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);
	zephir_get_strval(&name, name_param);


	zephir_read_property(&_0, this_ptr, ZEND_STRL("mapper"), PH_NOISY_CC | PH_READONLY);
	RETURN_MM_BOOL(zephir_array_isset(&_0, &name));
}

/**
 * Create a new instance of the object
 *
 * @param string $name
 *
 * @return mixed
 * @throws Exception
 */
PHP_METHOD(Phalcon_Html_TagFactory, newInstance)
{
	zval _2$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, definition, _0, _4, _5, _1$$3, _3$$3;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&definition);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_2$$3);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(name)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);
	zephir_get_strval(&name, name_param);


	zephir_read_property(&_0, this_ptr, ZEND_STRL("services"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_array_isset(&_0, &name))) {
		ZEPHIR_CALL_METHOD(&definition, this_ptr, "getservice", NULL, 0, &name);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_1$$3);
		ZEPHIR_INIT_VAR(&_2$$3);
		zephir_create_array(&_2$$3, 1, 0);
		ZEPHIR_OBS_VAR(&_3$$3);
		zephir_read_property(&_3$$3, this_ptr, ZEND_STRL("escaper"), PH_NOISY_CC);
		zephir_array_fast_append(&_2$$3, &_3$$3);
		ZEPHIR_LAST_CALL_STATUS = zephir_create_instance_params(&_1$$3, &definition, &_2$$3);
		zephir_check_call_status();
		zephir_update_property_array(this_ptr, SL("services"), &name, &_1$$3);
	}
	zephir_read_property(&_4, this_ptr, ZEND_STRL("services"), PH_NOISY_CC | PH_READONLY);
	zephir_array_fetch(&_5, &_4, &name, PH_NOISY | PH_READONLY, "phalcon/Html/TagFactory.zep", 145);
	RETURN_CTOR(&_5);
}

/**
 * @param string   $name
 * @param callable $method
 */
PHP_METHOD(Phalcon_Html_TagFactory, set)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *name_param = NULL, *method, method_sub, _0;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&method_sub);
	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR(name)
		Z_PARAM_ZVAL(method)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &name_param, &method);
	zephir_get_strval(&name, name_param);


	zephir_update_property_array(this_ptr, SL("mapper"), &name, method);
	zephir_unset_property_array(this_ptr, ZEND_STRL("services"), &name);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("services"), PH_NOISY_CC | PH_READONLY);
	zephir_array_unset(&_0, &name, PH_SEPARATE);
	ZEPHIR_MM_RESTORE();
}

/**
 * @return string
 */
PHP_METHOD(Phalcon_Html_TagFactory, getExceptionClass)
{
	zval *this_ptr = getThis();



	RETURN_STRING("Phalcon\\Html\\Exception");
}

/**
 * Returns the available services
 *
 * @return string[]
 */
PHP_METHOD(Phalcon_Html_TagFactory, getServices)
{
	zval *this_ptr = getThis();



	zephir_create_array(return_value, 41, 0);
	add_assoc_stringl_ex(return_value, SL("a"), SL("Phalcon\\Html\\Helper\\Anchor"));
	add_assoc_stringl_ex(return_value, SL("base"), SL("Phalcon\\Html\\Helper\\Base"));
	add_assoc_stringl_ex(return_value, SL("body"), SL("Phalcon\\Html\\Helper\\Body"));
	add_assoc_stringl_ex(return_value, SL("button"), SL("Phalcon\\Html\\Helper\\Button"));
	add_assoc_stringl_ex(return_value, SL("close"), SL("Phalcon\\Html\\Helper\\Close"));
	add_assoc_stringl_ex(return_value, SL("doctype"), SL("Phalcon\\Html\\Helper\\Doctype"));
	add_assoc_stringl_ex(return_value, SL("element"), SL("Phalcon\\Html\\Helper\\Element"));
	add_assoc_stringl_ex(return_value, SL("form"), SL("Phalcon\\Html\\Helper\\Form"));
	add_assoc_stringl_ex(return_value, SL("img"), SL("Phalcon\\Html\\Helper\\Img"));
	add_assoc_stringl_ex(return_value, SL("inputCheckbox"), SL("Phalcon\\Html\\Helper\\Input\\Checkbox"));
	add_assoc_stringl_ex(return_value, SL("inputColor"), SL("Phalcon\\Html\\Helper\\Input\\Color"));
	add_assoc_stringl_ex(return_value, SL("inputDate"), SL("Phalcon\\Html\\Helper\\Input\\Date"));
	add_assoc_stringl_ex(return_value, SL("inputDateTime"), SL("Phalcon\\Html\\Helper\\Input\\DateTime"));
	add_assoc_stringl_ex(return_value, SL("inputDateTimeLocal"), SL("Phalcon\\Html\\Helper\\Input\\DateTimeLocal"));
	add_assoc_stringl_ex(return_value, SL("inputEmail"), SL("Phalcon\\Html\\Helper\\Input\\Email"));
	add_assoc_stringl_ex(return_value, SL("inputFile"), SL("Phalcon\\Html\\Helper\\Input\\File"));
	add_assoc_stringl_ex(return_value, SL("inputHidden"), SL("Phalcon\\Html\\Helper\\Input\\Hidden"));
	add_assoc_stringl_ex(return_value, SL("inputImage"), SL("Phalcon\\Html\\Helper\\Input\\Image"));
	add_assoc_stringl_ex(return_value, SL("inputInput"), SL("Phalcon\\Html\\Helper\\Input\\Input"));
	add_assoc_stringl_ex(return_value, SL("inputMonth"), SL("Phalcon\\Html\\Helper\\Input\\Month"));
	add_assoc_stringl_ex(return_value, SL("inputNumeric"), SL("Phalcon\\Html\\Helper\\Input\\Numeric"));
	add_assoc_stringl_ex(return_value, SL("inputPassword"), SL("Phalcon\\Html\\Helper\\Input\\Password"));
	add_assoc_stringl_ex(return_value, SL("inputRadio"), SL("Phalcon\\Html\\Helper\\Input\\Radio"));
	add_assoc_stringl_ex(return_value, SL("inputRange"), SL("Phalcon\\Html\\Helper\\Input\\Range"));
	add_assoc_stringl_ex(return_value, SL("inputSearch"), SL("Phalcon\\Html\\Helper\\Input\\Search"));
	add_assoc_stringl_ex(return_value, SL("inputSelect"), SL("Phalcon\\Html\\Helper\\Input\\Select"));
	add_assoc_stringl_ex(return_value, SL("inputSubmit"), SL("Phalcon\\Html\\Helper\\Input\\Submit"));
	add_assoc_stringl_ex(return_value, SL("inputTel"), SL("Phalcon\\Html\\Helper\\Input\\Tel"));
	add_assoc_stringl_ex(return_value, SL("inputText"), SL("Phalcon\\Html\\Helper\\Input\\Text"));
	add_assoc_stringl_ex(return_value, SL("inputTextarea"), SL("Phalcon\\Html\\Helper\\Input\\Textarea"));
	add_assoc_stringl_ex(return_value, SL("inputTime"), SL("Phalcon\\Html\\Helper\\Input\\Time"));
	add_assoc_stringl_ex(return_value, SL("inputUrl"), SL("Phalcon\\Html\\Helper\\Input\\Url"));
	add_assoc_stringl_ex(return_value, SL("inputWeek"), SL("Phalcon\\Html\\Helper\\Input\\Week"));
	add_assoc_stringl_ex(return_value, SL("label"), SL("Phalcon\\Html\\Helper\\Label"));
	add_assoc_stringl_ex(return_value, SL("link"), SL("Phalcon\\Html\\Helper\\Link"));
	add_assoc_stringl_ex(return_value, SL("meta"), SL("Phalcon\\Html\\Helper\\Meta"));
	add_assoc_stringl_ex(return_value, SL("ol"), SL("Phalcon\\Html\\Helper\\Ol"));
	add_assoc_stringl_ex(return_value, SL("script"), SL("Phalcon\\Html\\Helper\\Script"));
	add_assoc_stringl_ex(return_value, SL("style"), SL("Phalcon\\Html\\Helper\\Style"));
	add_assoc_stringl_ex(return_value, SL("title"), SL("Phalcon\\Html\\Helper\\Title"));
	add_assoc_stringl_ex(return_value, SL("ul"), SL("Phalcon\\Html\\Helper\\Ul"));
	return;
}

zend_object *zephir_init_properties_Phalcon_Html_TagFactory(zend_class_entry *class_type)
{
		zval _0, _2, _1$$3, _3$$4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$4);
	

		ZEPHIR_MM_GROW();
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property_ex(&_0, this_ptr, ZEND_STRL("mapper"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("mapper"), &_1$$3);
		}
		zephir_read_property_ex(&_2, this_ptr, ZEND_STRL("services"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_2) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_3$$4);
			array_init(&_3$$4);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("services"), &_3$$4);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}
}

