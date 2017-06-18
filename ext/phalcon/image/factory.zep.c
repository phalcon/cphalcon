
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
#include "kernel/object.h"
#include "kernel/exception.h"
#include "kernel/array.h"
#include "kernel/concat.h"
#include "kernel/string.h"
#include "kernel/operators.h"


/**
 * Loads Image Adapter class using 'adapter' option
 *
 *<code>
 * use Phalcon\Image\Factory;
 *
 * $options = [
 *     "width"   => 200,
 *     "height"  => 200,
 *     "file"    => "upload/test.jpg",
 *     "adapter" => "imagick",
 * ];
 * $image = Factory::load($options);
 *</code>
 */
ZEPHIR_INIT_CLASS(Phalcon_Image_Factory) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Image, Factory, phalcon, image_factory, phalcon_factory_ce, phalcon_image_factory_method_entry, 0);

	return SUCCESS;

}

/**
 * @param \Phalcon\Config|array config
 */
PHP_METHOD(Phalcon_Image_Factory, load) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *config, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &config);



	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "Phalcon\\Image\\Adapter", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_RETURN_CALL_SELF("loadclass", NULL, 0, _0, config);
	zephir_check_temp_parameter(_0);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Phalcon_Image_Factory, loadClass) {

	zend_class_entry *_8$$6, *_4$$8, *_6$$7;
	zend_bool _0;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *namespace_param = NULL, *config = NULL, *adapter = NULL, *className = NULL, *file = NULL, *height = NULL, *width = NULL, *_1$$3 = NULL, *_2$$6, *_7$$6 = NULL, *_3$$8 = NULL, *_5$$7 = NULL;
	zval *namespace = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &namespace_param, &config);

	zephir_get_strval(namespace, namespace_param);
	ZEPHIR_SEPARATE_PARAM(config);


	_0 = Z_TYPE_P(config) == IS_OBJECT;
	if (_0) {
		_0 = zephir_instance_of_ev(config, phalcon_config_ce TSRMLS_CC);
	}
	if (_0) {
		ZEPHIR_CALL_METHOD(&_1$$3, config, "toarray", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(config, _1$$3);
	}
	if (Z_TYPE_P(config) != IS_ARRAY) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_factory_exception_ce, "Config must be array or Phalcon\\Config object", "phalcon/image/factory.zep", 61);
		return;
	}
	ZEPHIR_OBS_VAR(file);
	if (!(zephir_array_isset_string_fetch(&file, config, SS("file"), 0 TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_factory_exception_ce, "You must provide 'file' option in factory config parameter.", "phalcon/image/factory.zep", 65);
		return;
	}
	ZEPHIR_OBS_VAR(adapter);
	if (zephir_array_isset_string_fetch(&adapter, config, SS("adapter"), 0 TSRMLS_CC)) {
		ZEPHIR_INIT_VAR(_2$$6);
		zephir_camelize(_2$$6, adapter, NULL  );
		ZEPHIR_INIT_VAR(className);
		ZEPHIR_CONCAT_VSV(className, namespace, "\\", _2$$6);
		ZEPHIR_OBS_VAR(width);
		if (zephir_array_isset_string_fetch(&width, config, SS("width"), 0 TSRMLS_CC)) {
			ZEPHIR_OBS_VAR(height);
			if (zephir_array_isset_string_fetch(&height, config, SS("height"), 0 TSRMLS_CC)) {
				zephir_fetch_safe_class(_3$$8, className);
					_4$$8 = zend_fetch_class(Z_STRVAL_P(_3$$8), Z_STRLEN_P(_3$$8), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
				object_init_ex(return_value, _4$$8);
				if (zephir_has_constructor(return_value TSRMLS_CC)) {
					ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 0, file, width, height);
					zephir_check_call_status();
				}
				RETURN_MM();
			}
			zephir_fetch_safe_class(_5$$7, className);
				_6$$7 = zend_fetch_class(Z_STRVAL_P(_5$$7), Z_STRLEN_P(_5$$7), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
			object_init_ex(return_value, _6$$7);
			if (zephir_has_constructor(return_value TSRMLS_CC)) {
				ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 0, file, width);
				zephir_check_call_status();
			}
			RETURN_MM();
		}
		zephir_fetch_safe_class(_7$$6, className);
			_8$$6 = zend_fetch_class(Z_STRVAL_P(_7$$6), Z_STRLEN_P(_7$$6), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
		object_init_ex(return_value, _8$$6);
		if (zephir_has_constructor(return_value TSRMLS_CC)) {
			ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 0, file);
			zephir_check_call_status();
		}
		RETURN_MM();
	}
	ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_factory_exception_ce, "You must provide 'adapter' option in factory config parameter.", "phalcon/image/factory.zep", 82);
	return;

}

