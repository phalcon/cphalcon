
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
 * ServiceLocator implementation for Tag helpers
 */
ZEPHIR_INIT_CLASS(Phalcon_Html_TagFactory)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Html, TagFactory, phalcon, html_tagfactory, phalcon_factory_abstractfactory_ce, phalcon_html_tagfactory_method_entry, 0);

	/**
	 * @var EscaperInterface
	 */
	zend_declare_property_null(phalcon_html_tagfactory_ce, SL("escaper"), ZEND_ACC_PRIVATE);
	return SUCCESS;
}

/**
 * TagFactory constructor.
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
		Z_PARAM_OBJECT_OF_CLASS(escaper, phalcon_escaper_escaperinterface_ce)
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
 * @param string name
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
	zephir_array_fetch(&_5, &_4, &name, PH_NOISY | PH_READONLY, "phalcon/Html/TagFactory.zep", 57);
	RETURN_CTOR(&_5);
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
 * Returns the available adapters
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
	add_assoc_stringl_ex(return_value, SL("element"), SL("Phalcon\\Html\\Helper\\Element"));
	add_assoc_stringl_ex(return_value, SL("form"), SL("Phalcon\\Html\\Helper\\Form"));
	add_assoc_stringl_ex(return_value, SL("img"), SL("Phalcon\\Html\\Helper\\Img"));
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
	add_assoc_stringl_ex(return_value, SL("inputRange"), SL("Phalcon\\Html\\Helper\\Input\\Range"));
	add_assoc_stringl_ex(return_value, SL("inputSelect"), SL("Phalcon\\Html\\Helper\\Input\\Select"));
	add_assoc_stringl_ex(return_value, SL("inputSearch"), SL("Phalcon\\Html\\Helper\\Input\\Search"));
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

