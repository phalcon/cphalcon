
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
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * ServiceLocator implementation for Tag helpers
 */
ZEPHIR_INIT_CLASS(Phalcon_Html_TagFactory) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Html, TagFactory, phalcon, html_tagfactory, phalcon_factory_abstractfactory_ce, phalcon_html_tagfactory_method_entry, 0);

	/**
	 * @var <EscaperInterface>
	 */
	zend_declare_property_null(phalcon_html_tagfactory_ce, SL("escaper"), ZEND_ACC_PRIVATE TSRMLS_CC);

	return SUCCESS;

}

/**
 * TagFactory constructor.
 */
PHP_METHOD(Phalcon_Html_TagFactory, __construct) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval services;
	zval *escaper, escaper_sub, *services_param = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&escaper_sub);
	ZVAL_UNDEF(&services);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &escaper, &services_param);

	if (!services_param) {
		ZEPHIR_INIT_VAR(&services);
		array_init(&services);
	} else {
	ZEPHIR_OBS_COPY_OR_DUP(&services, services_param);
	}


	zephir_update_property_zval(this_ptr, SL("escaper"), escaper);
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
PHP_METHOD(Phalcon_Html_TagFactory, newInstance) {

	zend_class_entry *_4$$3;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, definition, _0, _6, _7, _1$$3, _2$$3, _3$$3, _5$$3;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&definition);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_5$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

	zephir_get_strval(&name, name_param);


	ZEPHIR_CALL_METHOD(NULL, this_ptr, "checkservice", NULL, 0, &name);
	zephir_check_call_status();
	zephir_read_property(&_0, this_ptr, SL("services"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_array_isset(&_0, &name))) {
		zephir_read_property(&_1$$3, this_ptr, SL("mapper"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch(&definition, &_1$$3, &name, PH_NOISY | PH_READONLY, "phalcon/Html/TagFactory.zep", 50 TSRMLS_CC);
		ZEPHIR_INIT_VAR(&_2$$3);
		zephir_fetch_safe_class(&_3$$3, &definition);
		_4$$3 = zephir_fetch_class_str_ex(Z_STRVAL_P(&_3$$3), Z_STRLEN_P(&_3$$3), ZEND_FETCH_CLASS_AUTO);
		object_init_ex(&_2$$3, _4$$3);
		if (zephir_has_constructor(&_2$$3 TSRMLS_CC)) {
			zephir_read_property(&_5$$3, this_ptr, SL("escaper"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_CALL_METHOD(NULL, &_2$$3, "__construct", NULL, 0, &_5$$3);
			zephir_check_call_status();
		}
		zephir_update_property_array(this_ptr, SL("services"), &name, &_2$$3);
	}
	zephir_read_property(&_6, this_ptr, SL("services"), PH_NOISY_CC | PH_READONLY);
	zephir_array_fetch(&_7, &_6, &name, PH_NOISY | PH_READONLY, "phalcon/Html/TagFactory.zep", 54 TSRMLS_CC);
	RETURN_CTOR(&_7);

}

PHP_METHOD(Phalcon_Html_TagFactory, getAdapters) {

	zval *this_ptr = getThis();


	zephir_create_array(return_value, 11, 0 TSRMLS_CC);
	add_assoc_stringl_ex(return_value, SL("a"), SL("\\Phalcon\\Html\\Helper\\Anchor"));
	add_assoc_stringl_ex(return_value, SL("aRaw"), SL("\\Phalcon\\Html\\Helper\\AnchorRaw"));
	add_assoc_stringl_ex(return_value, SL("body"), SL("\\Phalcon\\Html\\Helper\\Body"));
	add_assoc_stringl_ex(return_value, SL("button"), SL("\\Phalcon\\Html\\Helper\\Button"));
	add_assoc_stringl_ex(return_value, SL("close"), SL("\\Phalcon\\Html\\Helper\\Close"));
	add_assoc_stringl_ex(return_value, SL("element"), SL("\\Phalcon\\Html\\Helper\\Element"));
	add_assoc_stringl_ex(return_value, SL("elementRaw"), SL("\\Phalcon\\Html\\Helper\\ElementRaw"));
	add_assoc_stringl_ex(return_value, SL("form"), SL("\\Phalcon\\Html\\Helper\\Form"));
	add_assoc_stringl_ex(return_value, SL("img"), SL("\\Phalcon\\Html\\Helper\\Img"));
	add_assoc_stringl_ex(return_value, SL("label"), SL("\\Phalcon\\Html\\Helper\\Label"));
	add_assoc_stringl_ex(return_value, SL("textarea"), SL("\\Phalcon\\Html\\Helper\\TextArea"));
	return;

}

