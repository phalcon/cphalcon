
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
#include "kernel/fcall.h"
#include "kernel/memory.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/object.h"
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
 * Phalcon\Image/ImageFactory
 */
ZEPHIR_INIT_CLASS(Phalcon_Image_ImageFactory) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Image, ImageFactory, phalcon, image_imagefactory, phalcon_factory_abstractfactory_ce, phalcon_image_imagefactory_method_entry, 0);

	return SUCCESS;

}

/**
 * TagFactory constructor.
 */
PHP_METHOD(Phalcon_Image_ImageFactory, __construct) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *services_param = NULL;
	zval services;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&services);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &services_param);

	if (!services_param) {
		ZEPHIR_INIT_VAR(&services);
		array_init(&services);
	} else {
	ZEPHIR_OBS_COPY_OR_DUP(&services, services_param);
	}


	ZEPHIR_CALL_METHOD(NULL, this_ptr, "init", NULL, 0, &services);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Factory to create an instace from a Config object
 */
PHP_METHOD(Phalcon_Image_ImageFactory, load) {

	zephir_fcall_cache_entry *_1 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *config = NULL, config_sub, height, file, name, width, _0, _2, _3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&config_sub);
	ZVAL_UNDEF(&height);
	ZVAL_UNDEF(&file);
	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&width);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &config);

	ZEPHIR_SEPARATE_PARAM(config);


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "checkconfig", NULL, 0, config);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(config, &_0);
	if (UNEXPECTED(!(zephir_array_isset_string(config, SL("file"))))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_image_exception_ce, "You must provide 'file' option in factory config parameter.", "phalcon/Image/ImageFactory.zep", 43);
		return;
	}
	ZEPHIR_OBS_VAR(&name);
	zephir_array_fetch_string(&name, config, SL("adapter"), PH_NOISY, "phalcon/Image/ImageFactory.zep", 46 TSRMLS_CC);
	zephir_array_unset_string(config, SL("adapter"), PH_SEPARATE);
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "file");
	ZEPHIR_CALL_CE_STATIC(&file, phalcon_helper_arr_ce, "get", &_1, 8, config, &_2);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_STRING(&_2, "height");
	ZVAL_NULL(&_3);
	ZEPHIR_CALL_CE_STATIC(&height, phalcon_helper_arr_ce, "get", &_1, 8, config, &_2, &_3);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_STRING(&_2, "width");
	ZVAL_NULL(&_3);
	ZEPHIR_CALL_CE_STATIC(&width, phalcon_helper_arr_ce, "get", &_1, 8, config, &_2, &_3);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "newinstance", NULL, 0, &name, &file, &width, &height);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Creates a new instance
 */
PHP_METHOD(Phalcon_Image_ImageFactory, newInstance) {

	zend_class_entry *_4$$3;
	zend_long width, height, ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, *file_param = NULL, *width_param = NULL, *height_param = NULL, definition, _0, _7, _8, _1$$3, _2$$3, _3$$3, _5$$3, _6$$3;
	zval name, file;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&file);
	ZVAL_UNDEF(&definition);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_6$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 2, &name_param, &file_param, &width_param, &height_param);

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
	if (UNEXPECTED(Z_TYPE_P(file_param) != IS_STRING && Z_TYPE_P(file_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'file' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(file_param) == IS_STRING)) {
		zephir_get_strval(&file, file_param);
	} else {
		ZEPHIR_INIT_VAR(&file);
		ZVAL_EMPTY_STRING(&file);
	}
	if (!width_param) {
		width = 0;
	} else {
		width = zephir_get_intval(width_param);
	}
	if (!height_param) {
		height = 0;
	} else {
		height = zephir_get_intval(height_param);
	}


	ZEPHIR_CALL_METHOD(NULL, this_ptr, "checkservice", NULL, 0, &name);
	zephir_check_call_status();
	zephir_read_property(&_0, this_ptr, SL("services"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_array_isset(&_0, &name))) {
		zephir_read_property(&_1$$3, this_ptr, SL("mapper"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch(&definition, &_1$$3, &name, PH_NOISY | PH_READONLY, "phalcon/Image/ImageFactory.zep", 72 TSRMLS_CC);
		ZEPHIR_INIT_VAR(&_2$$3);
		zephir_fetch_safe_class(&_3$$3, &definition);
		_4$$3 = zephir_fetch_class_str_ex(Z_STRVAL_P(&_3$$3), Z_STRLEN_P(&_3$$3), ZEND_FETCH_CLASS_AUTO);
		object_init_ex(&_2$$3, _4$$3);
		if (zephir_has_constructor(&_2$$3 TSRMLS_CC)) {
			ZVAL_LONG(&_5$$3, width);
			ZVAL_LONG(&_6$$3, height);
			ZEPHIR_CALL_METHOD(NULL, &_2$$3, "__construct", NULL, 0, &file, &_5$$3, &_6$$3);
			zephir_check_call_status();
		}
		zephir_update_property_array(this_ptr, SL("services"), &name, &_2$$3);
	}
	zephir_read_property(&_7, this_ptr, SL("services"), PH_NOISY_CC | PH_READONLY);
	zephir_array_fetch(&_8, &_7, &name, PH_NOISY | PH_READONLY, "phalcon/Image/ImageFactory.zep", 76 TSRMLS_CC);
	RETURN_CTOR(&_8);

}

PHP_METHOD(Phalcon_Image_ImageFactory, getAdapters) {

	zval *this_ptr = getThis();


	zephir_create_array(return_value, 2, 0 TSRMLS_CC);
	add_assoc_stringl_ex(return_value, SL("gd"), SL("\\Phalcon\\Image\\Adapter\\Gd"));
	add_assoc_stringl_ex(return_value, SL("imagick"), SL("\\Phalcon\\Image\\Adapter\\Imagick"));
	return;

}

