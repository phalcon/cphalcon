
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
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "kernel/exception.h"
#include "kernel/fcall.h"
#include "kernel/file.h"
#include "kernel/concat.h"
#include "ext/spl/spl_exceptions.h"


/*
 +------------------------------------------------------------------------+
 | Phalcon Framework                                                      |
 +------------------------------------------------------------------------+
 | Copyright (c) 2011-2014 Phalcon Team (http://www.phalconphp.com)       |
 +------------------------------------------------------------------------+
 | This source file is subject to the New BSD License that is bundled     |
 | with this package in the file docs/LICENSE.txt.                        |
 |                                                                        |
 | If you did not receive a copy of the license and are unable to         |
 | obtain it through the world-wide-web, please send an email             |
 | to license@phalconphp.com so we can send you a copy immediately.       |
 +------------------------------------------------------------------------+
 | Authors: Andres Gutierrez <andres@phalconphp.com>                      |
 |          Eduar Carvajal <eduar@phalconphp.com>                         |
 +------------------------------------------------------------------------+
 */
ZEPHIR_INIT_CLASS(Phalcon_Image_Adapter_Imagick) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Image\\Adapter, Imagick, phalcon, image_adapter_imagick, phalcon_image_adapter_ce, phalcon_image_adapter_imagick_method_entry, 0);

	zend_declare_property_long(phalcon_image_adapter_imagick_ce, SL("_version"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(phalcon_image_adapter_imagick_ce TSRMLS_CC, 1, phalcon_image_adapterinterface_ce);
	return SUCCESS;

}

PHP_METHOD(Phalcon_Image_Adapter_Imagick, check) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_4 = NULL, *_6 = NULL;
	zval *_0, _1, _2 = zval_used_for_init, *_3 = NULL, *_5 = NULL, *_7;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_static_property_ce(phalcon_image_adapter_imagick_ce, SL("_checked") TSRMLS_CC);
	if (zephir_is_true(_0)) {
		RETURN_MM_BOOL(1);
	}
	ZEPHIR_SINIT_VAR(_1);
	ZVAL_STRING(&_1, "imagick", 0);
	if (!(zephir_class_exists(&_1, 1 TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_image_exception_ce, "Imagick is not installed, or the extension is not loaded", "phalcon/image/adapter/imagick.zep", 33);
		return;
	}
	ZEPHIR_SINIT_VAR(_2);
	ZVAL_STRING(&_2, "Imagick::IMAGICK_EXTNUM", 0);
	ZEPHIR_CALL_FUNCTION(&_3, "defined", &_4, &_2);
	zephir_check_call_status();
	if (zephir_is_true(_3)) {
		ZEPHIR_SINIT_NVAR(_2);
		ZVAL_STRING(&_2, "Imagick::IMAGICK_EXTNUM", 0);
		ZEPHIR_CALL_FUNCTION(&_5, "constant", &_6, &_2);
		zephir_check_call_status();
		zephir_update_property_this(this_ptr, SL("_version"), _5 TSRMLS_CC);
	}
	zephir_update_static_property_ce(phalcon_image_adapter_imagick_ce, SL("_checked"), ZEPHIR_GLOBAL(global_true) TSRMLS_CC);
	_7 = zephir_fetch_static_property_ce(phalcon_image_adapter_imagick_ce, SL("_checked") TSRMLS_CC);
	RETURN_CTOR(_7);

}

PHP_METHOD(Phalcon_Image_Adapter_Imagick, __construct) {

	zend_bool _20;
	zephir_nts_static zephir_fcall_cache_entry *_6 = NULL, *_17 = NULL;
	zend_class_entry *_2, *_21;
	int width, height, ZEPHIR_LAST_CALL_STATUS;
	zval *file_param = NULL, *width_param = NULL, *height_param = NULL, *image = NULL, *_0, *_1, *_3, *_4, *_5 = NULL, *_7, *_8 = NULL, *_9, *_10 = NULL, *_11, *_12 = NULL, *_13 = NULL, *_14, _15, *_16 = NULL, *_18, *_19, *_22 = NULL, *_23;
	zval *file = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &file_param, &width_param, &height_param);

	if (unlikely(Z_TYPE_P(file_param) != IS_STRING && Z_TYPE_P(file_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'file' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (unlikely(Z_TYPE_P(file_param) == IS_STRING)) {
		file = file_param;
	} else {
		ZEPHIR_INIT_VAR(file);
		ZVAL_EMPTY_STRING(file);
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


	_0 = zephir_fetch_static_property_ce(phalcon_image_adapter_imagick_ce, SL("_checked") TSRMLS_CC);
	if (!(zephir_is_true(_0))) {
		ZEPHIR_CALL_SELF(NULL, "check", NULL);
		zephir_check_call_status();
	}
	zephir_update_property_this(this_ptr, SL("_file"), file TSRMLS_CC);
	ZEPHIR_INIT_VAR(_1);
	_2 = zend_fetch_class(SL("Imagick"), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
	object_init_ex(_1, _2);
	if (zephir_has_constructor(_1 TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(NULL, _1, "__construct", NULL);
		zephir_check_call_status();
	}
	zephir_update_property_this(this_ptr, SL("_image"), _1 TSRMLS_CC);
	_3 = zephir_fetch_nproperty_this(this_ptr, SL("_file"), PH_NOISY_CC);
	if ((zephir_file_exists(_3 TSRMLS_CC) == SUCCESS)) {
		_4 = zephir_fetch_nproperty_this(this_ptr, SL("_file"), PH_NOISY_CC);
		ZEPHIR_CALL_FUNCTION(&_5, "realpath", &_6, _4);
		zephir_check_call_status();
		zephir_update_property_this(this_ptr, SL("_realpath"), _5 TSRMLS_CC);
		_7 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		_9 = zephir_fetch_nproperty_this(this_ptr, SL("_realpath"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(&_8, _7, "readimage", NULL, _9);
		zephir_check_call_status();
		if (!(zephir_is_true(_8))) {
			ZEPHIR_INIT_VAR(_10);
			object_init_ex(_10, phalcon_image_exception_ce);
			_11 = zephir_fetch_nproperty_this(this_ptr, SL("_file"), PH_NOISY_CC);
			ZEPHIR_INIT_VAR(_12);
			ZEPHIR_CONCAT_SVS(_12, "Imagick::readImage ", _11, " failed");
			ZEPHIR_CALL_METHOD(NULL, _10, "__construct", NULL, _12);
			zephir_check_call_status();
			zephir_throw_exception_debug(_10, "phalcon/image/adapter/imagick.zep", 61 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
		_11 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(&_13, _11, "getimagealphachannel",  NULL);
		zephir_check_call_status();
		if (!(zephir_is_true(_13))) {
			_14 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
			ZEPHIR_SINIT_VAR(_15);
			ZVAL_STRING(&_15, "Imagick::ALPHACHANNEL_SET", 0);
			ZEPHIR_CALL_FUNCTION(&_16, "constant", &_17, &_15);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, _14, "setimagealphachannel", NULL, _16);
			zephir_check_call_status();
		}
		_11 = zephir_fetch_nproperty_this(this_ptr, SL("_type"), PH_NOISY_CC);
		if (ZEPHIR_IS_LONG(_11, 1)) {
			_14 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
			ZEPHIR_CALL_METHOD(&image, _14, "coalesceimages",  NULL);
			zephir_check_call_status();
			_18 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
			ZEPHIR_CALL_METHOD(NULL, _18, "clear", NULL);
			zephir_check_call_status();
			_19 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
			ZEPHIR_CALL_METHOD(NULL, _19, "destroy", NULL);
			zephir_check_call_status();
			zephir_update_property_this(this_ptr, SL("_image"), image TSRMLS_CC);
		}
	} else {
		_20 = !width;
		if (!(_20)) {
			_20 = !height;
		}
		if (_20) {
			ZEPHIR_INIT_LNVAR(_10);
			object_init_ex(_10, phalcon_image_exception_ce);
			_4 = zephir_fetch_nproperty_this(this_ptr, SL("_file"), PH_NOISY_CC);
			ZEPHIR_INIT_LNVAR(_12);
			ZEPHIR_CONCAT_SV(_12, "Failed to create image from file ", _4);
			ZEPHIR_CALL_METHOD(NULL, _10, "__construct", NULL, _12);
			zephir_check_call_status();
			zephir_throw_exception_debug(_10, "phalcon/image/adapter/imagick.zep", 77 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
		_7 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		ZEPHIR_INIT_LNVAR(_10);
		_21 = zend_fetch_class(SL("ImagickPixel"), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
		object_init_ex(_10, _21);
		if (zephir_has_constructor(_10 TSRMLS_CC)) {
			ZEPHIR_INIT_VAR(_22);
			ZVAL_STRING(_22, "transparent", 0);
			ZEPHIR_CALL_METHOD(NULL, _10, "__construct", NULL, _22);
			zephir_check_temp_parameter(_22);
			zephir_check_call_status();
		}
		ZEPHIR_INIT_NVAR(_22);
		ZVAL_LONG(_22, width);
		ZEPHIR_INIT_VAR(_23);
		ZVAL_LONG(_23, height);
		ZEPHIR_CALL_METHOD(NULL, _7, "newimage", NULL, _22, _23, _10);
		zephir_check_call_status();
		_9 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		ZEPHIR_INIT_NVAR(_22);
		ZVAL_STRING(_22, "png", 0);
		ZEPHIR_CALL_METHOD(NULL, _9, "setformat", NULL, _22);
		zephir_check_temp_parameter(_22);
		zephir_check_call_status();
		_11 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		ZEPHIR_INIT_NVAR(_22);
		ZVAL_STRING(_22, "png", 0);
		ZEPHIR_CALL_METHOD(NULL, _11, "setimageformat", NULL, _22);
		zephir_check_temp_parameter(_22);
		zephir_check_call_status();
		_14 = zephir_fetch_nproperty_this(this_ptr, SL("_file"), PH_NOISY_CC);
		zephir_update_property_this(this_ptr, SL("_realpath"), _14 TSRMLS_CC);
	}
	_4 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&_5, _4, "getimagewidth",  NULL);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("_width"), _5 TSRMLS_CC);
	_7 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&_8, _7, "getimageheight",  NULL);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("_height"), _8 TSRMLS_CC);
	_9 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&_13, _9, "getimagetype",  NULL);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("_type"), _13 TSRMLS_CC);
	_18 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&_16, _18, "getimageformat",  NULL);
	zephir_check_call_status();
	ZEPHIR_INIT_LNVAR(_12);
	ZEPHIR_CONCAT_SV(_12, "image/", _16);
	zephir_update_property_this(this_ptr, SL("_mime"), _12 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Phalcon_Image_Adapter_Imagick, _resize) {

	zval *width_param = NULL, *height_param = NULL, *_0, *_1 = NULL, *_2, *_3 = NULL, *_4, *_5 = NULL, *_6 = NULL;
	int width, height, ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &width_param, &height_param);

	width = zephir_get_intval(width_param);
	height = zephir_get_intval(height_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_LONG(_1, 0);
	ZEPHIR_CALL_METHOD(NULL, _0, "setiteratorindex", NULL, _1);
	zephir_check_call_status();
	while (1) {
		_2 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		ZEPHIR_INIT_NVAR(_1);
		ZVAL_LONG(_1, width);
		ZEPHIR_INIT_NVAR(_3);
		ZVAL_LONG(_3, height);
		ZEPHIR_CALL_METHOD(NULL, _2, "scaleimage", NULL, _1, _3);
		zephir_check_call_status();
		_4 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(&_5, _4, "nextimage",  NULL);
		zephir_check_call_status();
		if (!(zephir_is_true(_5))) {
			break;
		}
	}
	_2 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&_5, _2, "getimagewidth",  NULL);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("_width"), _5 TSRMLS_CC);
	_4 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&_6, _4, "getimageheight",  NULL);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("_height"), _6 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Phalcon_Image_Adapter_Imagick, _crop) {

	zval *width_param = NULL, *height_param = NULL, *offset_x_param = NULL, *offset_y_param = NULL, *image, *_0 = NULL, *_1 = NULL, *_2 = NULL, *_3 = NULL, *_4 = NULL, *_5 = NULL;
	int width, height, offset_x, offset_y, ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 4, 0, &width_param, &height_param, &offset_x_param, &offset_y_param);

	width = zephir_get_intval(width_param);
	height = zephir_get_intval(height_param);
	offset_x = zephir_get_intval(offset_x_param);
	offset_y = zephir_get_intval(offset_y_param);


	ZEPHIR_OBS_VAR(image);
	zephir_read_property_this(&image, this_ptr, SL("_image"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_0);
	ZVAL_LONG(_0, 0);
	ZEPHIR_CALL_METHOD(NULL, image, "setiteratorindex", NULL, _0);
	zephir_check_call_status();
	while (1) {
		ZEPHIR_INIT_NVAR(_0);
		ZVAL_LONG(_0, width);
		ZEPHIR_INIT_NVAR(_1);
		ZVAL_LONG(_1, height);
		ZEPHIR_INIT_NVAR(_2);
		ZVAL_LONG(_2, offset_x);
		ZEPHIR_INIT_NVAR(_3);
		ZVAL_LONG(_3, offset_y);
		ZEPHIR_CALL_METHOD(NULL, image, "cropimage", NULL, _0, _1, _2, _3);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(_0);
		ZVAL_LONG(_0, width);
		ZEPHIR_INIT_NVAR(_1);
		ZVAL_LONG(_1, height);
		ZEPHIR_INIT_NVAR(_2);
		ZVAL_LONG(_2, 0);
		ZEPHIR_INIT_NVAR(_3);
		ZVAL_LONG(_3, 0);
		ZEPHIR_CALL_METHOD(NULL, image, "setimagepage", NULL, _0, _1, _2, _3);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_4, image, "nextimage",  NULL);
		zephir_check_call_status();
		if (!(zephir_is_true(_4))) {
			break;
		}
	}
	ZEPHIR_CALL_METHOD(&_4, image, "getimagewidth",  NULL);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("_width"), _4 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&_5, image, "getimageheight",  NULL);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("_height"), _5 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Phalcon_Image_Adapter_Imagick, _rotate) {

	zend_class_entry *_2;
	zval *degrees_param = NULL, *pixel, *_0, *_1 = NULL, *_3, *_4, *_5, *_6, *_7 = NULL, *_8, *_9 = NULL, *_10 = NULL;
	int degrees, ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &degrees_param);

	degrees = zephir_get_intval(degrees_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_LONG(_1, 0);
	ZEPHIR_CALL_METHOD(NULL, _0, "setiteratorindex", NULL, _1);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(pixel);
	_2 = zend_fetch_class(SL("ImagickPixel"), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
	object_init_ex(pixel, _2);
	if (zephir_has_constructor(pixel TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(NULL, pixel, "__construct", NULL);
		zephir_check_call_status();
	}
	while (1) {
		_3 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		ZEPHIR_INIT_NVAR(_1);
		ZVAL_LONG(_1, degrees);
		ZEPHIR_CALL_METHOD(NULL, _3, "rotateimage", NULL, pixel, _1);
		zephir_check_call_status();
		_4 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		_5 = zephir_fetch_nproperty_this(this_ptr, SL("_width"), PH_NOISY_CC);
		_6 = zephir_fetch_nproperty_this(this_ptr, SL("_height"), PH_NOISY_CC);
		ZEPHIR_INIT_NVAR(_1);
		ZVAL_LONG(_1, 0);
		ZEPHIR_INIT_NVAR(_7);
		ZVAL_LONG(_7, 0);
		ZEPHIR_CALL_METHOD(NULL, _4, "setimagepage", NULL, _5, _6, _1, _7);
		zephir_check_call_status();
		_8 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(&_9, _8, "nextimage",  NULL);
		zephir_check_call_status();
		if (!(zephir_is_true(_9))) {
			break;
		}
	}
	_3 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&_9, _3, "getimagewidth",  NULL);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("_width"), _9 TSRMLS_CC);
	_4 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&_10, _4, "getimageheight",  NULL);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("_height"), _10 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Phalcon_Image_Adapter_Imagick, _flip) {

	zval *direction_param = NULL, *func, *_0, *_1, *_2, *_3, *_4 = NULL;
	int direction, ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &direction_param);

	direction = zephir_get_intval(direction_param);


	ZEPHIR_INIT_VAR(func);
	ZVAL_STRING(func, "flipImage", 1);
	if (direction == 11) {
		ZEPHIR_INIT_BNVAR(func);
		ZVAL_STRING(func, "flopImage", 1);
	}
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_LONG(_1, 0);
	ZEPHIR_CALL_METHOD(NULL, _0, "setiteratorindex", NULL, _1);
	zephir_check_call_status();
	while (1) {
		_2 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(NULL, _2, Z_STRVAL_P(func), NULL);
		zephir_check_call_status();
		_3 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(&_4, _3, "nextimage",  NULL);
		zephir_check_call_status();
		if (!(zephir_is_true(_4))) {
			break;
		}
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Phalcon_Image_Adapter_Imagick, _sharpen) {

	zval *amount_param = NULL, *_0, *_1, *_2 = NULL, *_3, *_4 = NULL, *_5, *_6 = NULL;
	int amount, ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &amount_param);

	amount = zephir_get_intval(amount_param);


	ZEPHIR_INIT_VAR(_0);
	if (amount < 5) {
		ZEPHIR_INIT_BNVAR(_0);
		ZVAL_LONG(_0, 5);
	} else {
		ZEPHIR_INIT_BNVAR(_0);
		ZVAL_LONG(_0, amount);
	}
	amount = zephir_get_numberval(_0);
	amount = (((amount * 3.0)) / 100);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_2);
	ZVAL_LONG(_2, 0);
	ZEPHIR_CALL_METHOD(NULL, _1, "setiteratorindex", NULL, _2);
	zephir_check_call_status();
	while (1) {
		_3 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		ZEPHIR_INIT_NVAR(_2);
		ZVAL_LONG(_2, 0);
		ZEPHIR_INIT_NVAR(_4);
		ZVAL_LONG(_4, amount);
		ZEPHIR_CALL_METHOD(NULL, _3, "sharpenimage", NULL, _2, _4);
		zephir_check_call_status();
		_5 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(&_6, _5, "nextimage",  NULL);
		zephir_check_call_status();
		if (!(zephir_is_true(_6))) {
			break;
		}
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Phalcon_Image_Adapter_Imagick, _reflection) {

	zephir_fcall_cache_entry *_18 = NULL, *_19 = NULL, *_21 = NULL, *_23 = NULL, *_25 = NULL, *_27 = NULL;
	zephir_nts_static zephir_fcall_cache_entry *_10 = NULL;
	zend_class_entry *_8, *_14, *_15;
	zend_bool fade_in, _28;
	zval *height_param = NULL, *opacity_param = NULL, *fade_in_param = NULL, *reflection, *fade, *pseudo, *image, *pixel, *_0, *_1, *_2 = NULL, *_3 = NULL, *_4 = NULL, *_5 = NULL, *_6 = NULL, *_7 = NULL, _9 = zval_used_for_init, *_11 = NULL, *_12 = NULL, *_13 = NULL, *_16, *_17, *_20, *_22, *_24, *_26, *_29 = NULL;
	int height, opacity, ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &height_param, &opacity_param, &fade_in_param);

	height = zephir_get_intval(height_param);
	opacity = zephir_get_intval(opacity_param);
	fade_in = zephir_get_boolval(fade_in_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_version"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(reflection);
	if (ZEPHIR_GE_LONG(_0, 30100)) {
		_1 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		if (zephir_clone(reflection, _1 TSRMLS_CC) == FAILURE) {
			RETURN_MM();
		}
	} else {
		_1 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(&_2, _1, "clone",  NULL);
		zephir_check_call_status();
		if (zephir_clone(reflection, _2 TSRMLS_CC) == FAILURE) {
			RETURN_MM();
		}
	}
	ZEPHIR_INIT_VAR(_3);
	ZVAL_LONG(_3, 0);
	ZEPHIR_CALL_METHOD(NULL, reflection, "setiteratorindex", NULL, _3);
	zephir_check_call_status();
	while (1) {
		ZEPHIR_CALL_METHOD(NULL, reflection, "flipimage", NULL);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_2, reflection, "getimagewidth",  NULL);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(_3);
		ZVAL_LONG(_3, height);
		ZEPHIR_INIT_NVAR(_4);
		ZVAL_LONG(_4, 0);
		ZEPHIR_INIT_NVAR(_5);
		ZVAL_LONG(_5, 0);
		ZEPHIR_CALL_METHOD(NULL, reflection, "cropimage", NULL, _2, _3, _4, _5);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_6, reflection, "getimagewidth",  NULL);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(_3);
		ZVAL_LONG(_3, height);
		ZEPHIR_INIT_NVAR(_4);
		ZVAL_LONG(_4, 0);
		ZEPHIR_INIT_NVAR(_5);
		ZVAL_LONG(_5, 0);
		ZEPHIR_CALL_METHOD(NULL, reflection, "setimagepage", NULL, _6, _3, _4, _5);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_7, reflection, "nextimage",  NULL);
		zephir_check_call_status();
		if (!(zephir_is_true(_7))) {
			break;
		}
	}
	if (fade_in) {
		ZEPHIR_INIT_VAR(pseudo);
		ZVAL_STRING(pseudo, "gradient:black-transparent", 1);
	} else {
		ZEPHIR_INIT_BNVAR(pseudo);
		ZVAL_STRING(pseudo, "gradient:transparent-black", 1);
	}
	ZEPHIR_INIT_VAR(fade);
	_8 = zend_fetch_class(SL("Imagick"), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
	object_init_ex(fade, _8);
	if (zephir_has_constructor(fade TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(NULL, fade, "__construct", NULL);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_METHOD(&_2, reflection, "getimagewidth",  NULL);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_6, reflection, "getimageheight",  NULL);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, fade, "newpseudoimage", NULL, _2, _6, pseudo);
	zephir_check_call_status();
	opacity /= 100;
	ZEPHIR_INIT_BNVAR(_3);
	ZVAL_LONG(_3, 0);
	ZEPHIR_CALL_METHOD(NULL, reflection, "setiteratorindex", NULL, _3);
	zephir_check_call_status();
	while (1) {
		ZEPHIR_SINIT_NVAR(_9);
		ZVAL_STRING(&_9, "Imagick::COMPOSITE_DSTOUT", 0);
		ZEPHIR_CALL_FUNCTION(&_7, "constant", &_10, &_9);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(_3);
		ZVAL_LONG(_3, 0);
		ZEPHIR_INIT_NVAR(_4);
		ZVAL_LONG(_4, 0);
		ZEPHIR_CALL_METHOD(NULL, reflection, "compositeimage", NULL, fade, _7, _3, _4);
		zephir_check_call_status();
		ZEPHIR_SINIT_NVAR(_9);
		ZVAL_STRING(&_9, "Imagick::EVALUATE_MULTIPLY", 0);
		ZEPHIR_CALL_FUNCTION(&_11, "constant", &_10, &_9);
		zephir_check_call_status();
		ZEPHIR_SINIT_NVAR(_9);
		ZVAL_STRING(&_9, "Imagick::CHANNEL_ALPHA", 0);
		ZEPHIR_CALL_FUNCTION(&_12, "constant", &_10, &_9);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(_3);
		ZVAL_LONG(_3, (opacity / 100));
		ZEPHIR_CALL_METHOD(NULL, reflection, "evaluateimage", NULL, _11, _3, _12);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_13, reflection, "nextimage",  NULL);
		zephir_check_call_status();
		if (!(zephir_is_true(_13))) {
			break;
		}
	}
	ZEPHIR_CALL_METHOD(NULL, fade, "destroy", NULL);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(image);
	_14 = zend_fetch_class(SL("Imagick"), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
	object_init_ex(image, _14);
	if (zephir_has_constructor(image TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(NULL, image, "__construct", NULL);
		zephir_check_call_status();
	}
	ZEPHIR_INIT_VAR(pixel);
	_15 = zend_fetch_class(SL("ImagickPixel"), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
	object_init_ex(pixel, _15);
	if (zephir_has_constructor(pixel TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(NULL, pixel, "__construct", NULL);
		zephir_check_call_status();
	}
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&_2, _1, "getimageheight",  NULL);
	zephir_check_call_status();
	height = (zephir_get_numberval(_2) + height);
	_16 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
	ZEPHIR_INIT_BNVAR(_3);
	ZVAL_LONG(_3, 0);
	ZEPHIR_CALL_METHOD(NULL, _16, "setiteratorindex", NULL, _3);
	zephir_check_call_status();
	while (1) {
		_17 = zephir_fetch_nproperty_this(this_ptr, SL("_width"), PH_NOISY_CC);
		ZEPHIR_INIT_NVAR(_3);
		ZVAL_LONG(_3, height);
		ZEPHIR_CALL_METHOD(NULL, image, "newimage", &_18, _17, _3, pixel);
		zephir_check_call_status();
		ZEPHIR_SINIT_NVAR(_9);
		ZVAL_STRING(&_9, "Imagick::ALPHACHANNEL_SET", 0);
		ZEPHIR_CALL_FUNCTION(&_6, "constant", &_10, &_9);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, image, "setimagealphachannel", &_19, _6);
		zephir_check_call_status();
		_20 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(&_7, _20, "getcolorspace",  NULL);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, image, "setcolorspace", &_21, _7);
		zephir_check_call_status();
		_22 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(&_11, _22, "getimagedelay",  NULL);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, image, "setimagedelay", &_23, _11);
		zephir_check_call_status();
		_24 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		ZEPHIR_SINIT_NVAR(_9);
		ZVAL_STRING(&_9, "Imagick::COMPOSITE_SRC", 0);
		ZEPHIR_CALL_FUNCTION(&_12, "constant", &_10, &_9);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(_3);
		ZVAL_LONG(_3, 0);
		ZEPHIR_INIT_NVAR(_4);
		ZVAL_LONG(_4, 0);
		ZEPHIR_CALL_METHOD(NULL, image, "compositeimage", &_25, _24, _12, _3, _4);
		zephir_check_call_status();
		_26 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(&_13, _26, "nextimage",  NULL);
		zephir_check_call_status();
		if (!(zephir_is_true(_13))) {
			break;
		}
	}
	ZEPHIR_INIT_BNVAR(_3);
	ZVAL_LONG(_3, 0);
	ZEPHIR_CALL_METHOD(NULL, image, "setiteratorindex", NULL, _3);
	zephir_check_call_status();
	ZEPHIR_INIT_BNVAR(_3);
	ZVAL_LONG(_3, 0);
	ZEPHIR_CALL_METHOD(NULL, reflection, "setiteratorindex", NULL, _3);
	zephir_check_call_status();
	while (1) {
		ZEPHIR_SINIT_NVAR(_9);
		ZVAL_STRING(&_9, "Imagick::COMPOSITE_OVER", 0);
		ZEPHIR_CALL_FUNCTION(&_2, "constant", &_10, &_9);
		zephir_check_call_status();
		_1 = zephir_fetch_nproperty_this(this_ptr, SL("_height"), PH_NOISY_CC);
		ZEPHIR_INIT_NVAR(_3);
		ZVAL_LONG(_3, 0);
		ZEPHIR_CALL_METHOD(NULL, image, "compositeimage", &_25, reflection, _2, _3, _1);
		zephir_check_call_status();
		ZEPHIR_SINIT_NVAR(_9);
		ZVAL_STRING(&_9, "Imagick::ALPHACHANNEL_SET", 0);
		ZEPHIR_CALL_FUNCTION(&_6, "constant", &_10, &_9);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, image, "setimagealphachannel", &_19, _6);
		zephir_check_call_status();
		_17 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(&_7, _17, "getcolorspace",  NULL);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, image, "setcolorspace", &_21, _7);
		zephir_check_call_status();
		_20 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(&_11, _20, "getimagedelay",  NULL);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, image, "setimagedelay", &_23, _11);
		zephir_check_call_status();
		_22 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		ZEPHIR_SINIT_NVAR(_9);
		ZVAL_STRING(&_9, "Imagick::COMPOSITE_SRC", 0);
		ZEPHIR_CALL_FUNCTION(&_12, "constant", &_10, &_9);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(_3);
		ZVAL_LONG(_3, 0);
		ZEPHIR_INIT_NVAR(_4);
		ZVAL_LONG(_4, 0);
		ZEPHIR_CALL_METHOD(NULL, image, "compositeimage", &_25, _22, _12, _3, _4);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_13, image, "nextimage",  &_27);
		zephir_check_call_status();
		_28 = !zephir_is_true(_13);
		if (!(_28)) {
			ZEPHIR_CALL_METHOD(&_29, reflection, "nextimage",  NULL);
			zephir_check_call_status();
			_28 = !zephir_is_true(_29);
		}
		if (_28) {
			break;
		}
	}
	ZEPHIR_CALL_METHOD(NULL, reflection, "destroy", NULL);
	zephir_check_call_status();
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(NULL, _1, "clear", NULL);
	zephir_check_call_status();
	_17 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(NULL, _17, "destroy", NULL);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("_image"), image TSRMLS_CC);
	_20 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&_2, _20, "getimagewidth",  NULL);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("_width"), _2 TSRMLS_CC);
	_22 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&_6, _22, "getimageheight",  NULL);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("_height"), _6 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Phalcon_Image_Adapter_Imagick, _watermark) {

	zephir_nts_static zephir_fcall_cache_entry *_7 = NULL;
	zend_class_entry *_0;
	int offset_x, offset_y, opacity, ZEPHIR_LAST_CALL_STATUS;
	zval *image, *offset_x_param = NULL, *offset_y_param = NULL, *opacity_param = NULL, *watermark, *_1 = NULL, *_2 = NULL, *_3, *_4, _5 = zval_used_for_init, *_6 = NULL, *_8 = NULL, *_9, *_10 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 4, 0, &image, &offset_x_param, &offset_y_param, &opacity_param);

	offset_x = zephir_get_intval(offset_x_param);
	offset_y = zephir_get_intval(offset_y_param);
	opacity = zephir_get_intval(opacity_param);


	if (!(zephir_instance_of_ev(image, phalcon_image_adapter_ce TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Parameter 'image' must be an instance of 'Phalcon\\Image\\Adapter'", "", 0);
		return;
	}
	opacity = (opacity / 100);
	ZEPHIR_INIT_VAR(watermark);
	_0 = zend_fetch_class(SL("Imagick"), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
	object_init_ex(watermark, _0);
	if (zephir_has_constructor(watermark TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(NULL, watermark, "__construct", NULL);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_METHOD(&_1, image, "render",  NULL);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, watermark, "readimageblob", NULL, _1);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_2);
	ZVAL_LONG(_2, opacity);
	ZEPHIR_CALL_METHOD(NULL, watermark, "setimageopacity", NULL, _2);
	zephir_check_call_status();
	_3 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
	ZEPHIR_INIT_BNVAR(_2);
	ZVAL_LONG(_2, 0);
	ZEPHIR_CALL_METHOD(NULL, _3, "setiteratorindex", NULL, _2);
	zephir_check_call_status();
	while (1) {
		_4 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		ZEPHIR_SINIT_NVAR(_5);
		ZVAL_STRING(&_5, "Imagick::COMPOSITE_OVER", 0);
		ZEPHIR_CALL_FUNCTION(&_6, "constant", &_7, &_5);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(_2);
		ZVAL_LONG(_2, offset_x);
		ZEPHIR_INIT_NVAR(_8);
		ZVAL_LONG(_8, offset_y);
		ZEPHIR_CALL_METHOD(NULL, _4, "compositeimage", NULL, watermark, _6, _2, _8);
		zephir_check_call_status();
		_9 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(&_10, _9, "nextimage",  NULL);
		zephir_check_call_status();
		if (!(zephir_is_true(_10))) {
			break;
		}
	}
	ZEPHIR_CALL_METHOD(NULL, watermark, "clear", NULL);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, watermark, "destroy", NULL);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Phalcon_Image_Adapter_Imagick, _text) {

	zephir_nts_static zephir_fcall_cache_entry *_5 = NULL, *_9 = NULL, *_11 = NULL;
	zend_class_entry *_0, *_6;
	int offset_x, offset_y, opacity, r, g, b, size, ZEPHIR_LAST_CALL_STATUS;
	zval *text_param = NULL, *offset_x_param = NULL, *offset_y_param = NULL, *opacity_param = NULL, *r_param = NULL, *g_param = NULL, *b_param = NULL, *size_param = NULL, *fontfile_param = NULL, *draw, *color = NULL, *pixel, *gravity = NULL, _1 = zval_used_for_init, _2, _3, _4, *_7 = NULL, *_8 = NULL, *_10 = NULL, *_12, *_13, *_14 = NULL, *_15 = NULL, *_16;
	zval *text = NULL, *fontfile = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 9, 0, &text_param, &offset_x_param, &offset_y_param, &opacity_param, &r_param, &g_param, &b_param, &size_param, &fontfile_param);

	zephir_get_strval(text, text_param);
	offset_x = zephir_get_intval(offset_x_param);
	offset_y = zephir_get_intval(offset_y_param);
	opacity = zephir_get_intval(opacity_param);
	r = zephir_get_intval(r_param);
	g = zephir_get_intval(g_param);
	b = zephir_get_intval(b_param);
	size = zephir_get_intval(size_param);
	zephir_get_strval(fontfile, fontfile_param);


	opacity = (opacity / 100);
	ZEPHIR_INIT_VAR(draw);
	_0 = zend_fetch_class(SL("ImagickDraw"), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
	object_init_ex(draw, _0);
	if (zephir_has_constructor(draw TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(NULL, draw, "__construct", NULL);
		zephir_check_call_status();
	}
	ZEPHIR_SINIT_VAR(_1);
	ZVAL_STRING(&_1, "rgb(%d, %d, %d)", 0);
	ZEPHIR_SINIT_VAR(_2);
	ZVAL_LONG(&_2, r);
	ZEPHIR_SINIT_VAR(_3);
	ZVAL_LONG(&_3, g);
	ZEPHIR_SINIT_VAR(_4);
	ZVAL_LONG(&_4, b);
	ZEPHIR_CALL_FUNCTION(&color, "sprintf", &_5, &_1, &_2, &_3, &_4);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(pixel);
	_6 = zend_fetch_class(SL("ImagickPixel"), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
	object_init_ex(pixel, _6);
	if (zephir_has_constructor(pixel TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(NULL, pixel, "__construct", NULL, color);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_METHOD(NULL, draw, "setfillcolor", NULL, pixel);
	zephir_check_call_status();
	if (fontfile && Z_STRLEN_P(fontfile)) {
		ZEPHIR_CALL_METHOD(NULL, draw, "setfont", NULL, fontfile);
		zephir_check_call_status();
	}
	if (size) {
		ZEPHIR_INIT_VAR(_7);
		ZVAL_LONG(_7, size);
		ZEPHIR_CALL_METHOD(NULL, draw, "setfontsize", NULL, _7);
		zephir_check_call_status();
	}
	if (opacity) {
		ZEPHIR_INIT_NVAR(_7);
		ZVAL_LONG(_7, opacity);
		ZEPHIR_CALL_METHOD(NULL, draw, "setfillopacity", NULL, _7);
		zephir_check_call_status();
	}
	if (offset_x < 0) {
		ZEPHIR_SINIT_NVAR(_1);
		ZVAL_LONG(&_1, offset_x);
		ZEPHIR_CALL_FUNCTION(&_8, "abs", &_9, &_1);
		zephir_check_call_status();
		offset_x = zephir_get_numberval(_8);
		if (offset_y < 0) {
			ZEPHIR_SINIT_NVAR(_1);
			ZVAL_LONG(&_1, offset_y);
			ZEPHIR_CALL_FUNCTION(&_10, "abs", &_9, &_1);
			zephir_check_call_status();
			offset_y = zephir_get_numberval(_10);
			ZEPHIR_SINIT_NVAR(_1);
			ZVAL_STRING(&_1, "Imagick::GRAVITY_SOUTHEAST", 0);
			ZEPHIR_CALL_FUNCTION(&gravity, "constant", &_11, &_1);
			zephir_check_call_status();
		} else {
			ZEPHIR_SINIT_NVAR(_1);
			ZVAL_STRING(&_1, "Imagick::GRAVITY_NORTHEAST", 0);
			ZEPHIR_CALL_FUNCTION(&gravity, "constant", &_11, &_1);
			zephir_check_call_status();
		}
	}
	ZEPHIR_CALL_METHOD(NULL, draw, "setgravity", NULL, gravity);
	zephir_check_call_status();
	_12 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
	ZEPHIR_INIT_NVAR(_7);
	ZVAL_LONG(_7, 0);
	ZEPHIR_CALL_METHOD(NULL, _12, "setiteratorindex", NULL, _7);
	zephir_check_call_status();
	while (1) {
		_13 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		ZEPHIR_INIT_NVAR(_7);
		ZVAL_LONG(_7, offset_x);
		ZEPHIR_INIT_NVAR(_14);
		ZVAL_LONG(_14, offset_y);
		ZEPHIR_INIT_NVAR(_15);
		ZVAL_LONG(_15, 0);
		ZEPHIR_CALL_METHOD(NULL, _13, "annotateimage", NULL, draw, _7, _14, _15, text);
		zephir_check_call_status();
		_16 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(&_8, _16, "nextimage",  NULL);
		zephir_check_call_status();
		if (!(zephir_is_true(_8))) {
			break;
		}
	}
	ZEPHIR_CALL_METHOD(NULL, draw, "destroy", NULL);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Phalcon_Image_Adapter_Imagick, _mask) {

	zephir_nts_static zephir_fcall_cache_entry *_8 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zend_class_entry *_0;
	zval *image, *mask, *_1 = NULL, *_2, *_3 = NULL, *_4, *_5, _6 = zval_used_for_init, *_7 = NULL, *_9 = NULL, *_10, *_11 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &image);



	if (!(zephir_instance_of_ev(image, phalcon_image_adapter_ce TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Parameter 'image' must be an instance of 'Phalcon\\Image\\Adapter'", "", 0);
		return;
	}
	ZEPHIR_INIT_VAR(mask);
	_0 = zend_fetch_class(SL("Imagick"), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
	object_init_ex(mask, _0);
	if (zephir_has_constructor(mask TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(NULL, mask, "__construct", NULL);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_METHOD(&_1, image, "render",  NULL);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, mask, "readimageblob", NULL, _1);
	zephir_check_call_status();
	_2 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_3);
	ZVAL_LONG(_3, 0);
	ZEPHIR_CALL_METHOD(NULL, _2, "setiteratorindex", NULL, _3);
	zephir_check_call_status();
	while (1) {
		_4 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		ZEPHIR_INIT_NVAR(_3);
		ZVAL_LONG(_3, 1);
		ZEPHIR_CALL_METHOD(NULL, _4, "setimagematte", NULL, _3);
		zephir_check_call_status();
		_5 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		ZEPHIR_SINIT_NVAR(_6);
		ZVAL_STRING(&_6, "Imagick::COMPOSITE_DSTIN", 0);
		ZEPHIR_CALL_FUNCTION(&_7, "constant", &_8, &_6);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(_3);
		ZVAL_LONG(_3, 0);
		ZEPHIR_INIT_NVAR(_9);
		ZVAL_LONG(_9, 0);
		ZEPHIR_CALL_METHOD(NULL, _5, "compositeimage", NULL, mask, _7, _3, _9);
		zephir_check_call_status();
		_10 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(&_11, _10, "nextimage",  NULL);
		zephir_check_call_status();
		if (!(zephir_is_true(_11))) {
			break;
		}
	}
	ZEPHIR_CALL_METHOD(NULL, mask, "clear", NULL);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, mask, "destroy", NULL);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Phalcon_Image_Adapter_Imagick, _background) {

	zephir_fcall_cache_entry *_12 = NULL, *_14 = NULL, *_17 = NULL, *_18 = NULL, *_20 = NULL, *_23 = NULL, *_27 = NULL;
	zend_class_entry *_5, *_6, *_8;
	zephir_nts_static zephir_fcall_cache_entry *_4 = NULL, *_16 = NULL;
	zval *r_param = NULL, *g_param = NULL, *b_param = NULL, *opacity_param = NULL, *background, *color = NULL, *pixel1, *pixel2, _0 = zval_used_for_init, _1, _2, _3, *_7 = NULL, *_9, *_10, *_11, *_13 = NULL, *_15 = NULL, *_19 = NULL, *_21, *_22 = NULL, *_24, *_25 = NULL, *_26 = NULL, *_28, *_29 = NULL;
	int r, g, b, opacity, ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 4, 0, &r_param, &g_param, &b_param, &opacity_param);

	r = zephir_get_intval(r_param);
	g = zephir_get_intval(g_param);
	b = zephir_get_intval(b_param);
	opacity = zephir_get_intval(opacity_param);


	ZEPHIR_SINIT_VAR(_0);
	ZVAL_STRING(&_0, "rgb(%d, %d, %d)", 0);
	ZEPHIR_SINIT_VAR(_1);
	ZVAL_LONG(&_1, r);
	ZEPHIR_SINIT_VAR(_2);
	ZVAL_LONG(&_2, g);
	ZEPHIR_SINIT_VAR(_3);
	ZVAL_LONG(&_3, b);
	ZEPHIR_CALL_FUNCTION(&color, "sprintf", &_4, &_0, &_1, &_2, &_3);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(pixel1);
	_5 = zend_fetch_class(SL("ImagickPixel"), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
	object_init_ex(pixel1, _5);
	if (zephir_has_constructor(pixel1 TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(NULL, pixel1, "__construct", NULL, color);
		zephir_check_call_status();
	}
	opacity = (opacity / 100);
	ZEPHIR_INIT_VAR(pixel2);
	_6 = zend_fetch_class(SL("ImagickPixel"), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
	object_init_ex(pixel2, _6);
	if (zephir_has_constructor(pixel2 TSRMLS_CC)) {
		ZEPHIR_INIT_VAR(_7);
		ZVAL_STRING(_7, "transparent", 0);
		ZEPHIR_CALL_METHOD(NULL, pixel2, "__construct", NULL, _7);
		zephir_check_temp_parameter(_7);
		zephir_check_call_status();
	}
	ZEPHIR_INIT_VAR(background);
	_8 = zend_fetch_class(SL("Imagick"), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
	object_init_ex(background, _8);
	if (zephir_has_constructor(background TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(NULL, background, "__construct", NULL);
		zephir_check_call_status();
	}
	_9 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
	ZEPHIR_INIT_BNVAR(_7);
	ZVAL_LONG(_7, 0);
	ZEPHIR_CALL_METHOD(NULL, _9, "setiteratorindex", NULL, _7);
	zephir_check_call_status();
	while (1) {
		_10 = zephir_fetch_nproperty_this(this_ptr, SL("_width"), PH_NOISY_CC);
		_11 = zephir_fetch_nproperty_this(this_ptr, SL("_height"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(NULL, background, "newimage", &_12, _10, _11, pixel1);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_13, background, "getimagealphachannel",  &_14);
		zephir_check_call_status();
		if (!(zephir_is_true(_13))) {
			ZEPHIR_SINIT_NVAR(_0);
			ZVAL_STRING(&_0, "Imagick::ALPHACHANNEL_SET", 0);
			ZEPHIR_CALL_FUNCTION(&_15, "constant", &_16, &_0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, background, "setimagealphachannel", &_17, _15);
			zephir_check_call_status();
		}
		ZEPHIR_CALL_METHOD(NULL, background, "setimagebackgroundcolor", &_18, pixel2);
		zephir_check_call_status();
		ZEPHIR_SINIT_NVAR(_0);
		ZVAL_STRING(&_0, "Imagick::EVALUATE_MULTIPLY", 0);
		ZEPHIR_CALL_FUNCTION(&_15, "constant", &_16, &_0);
		zephir_check_call_status();
		ZEPHIR_SINIT_NVAR(_0);
		ZVAL_STRING(&_0, "Imagick::CHANNEL_ALPHA", 0);
		ZEPHIR_CALL_FUNCTION(&_19, "constant", &_16, &_0);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(_7);
		ZVAL_LONG(_7, opacity);
		ZEPHIR_CALL_METHOD(NULL, background, "evaluateimage", &_20, _15, _7, _19);
		zephir_check_call_status();
		_21 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(&_22, _21, "getcolorspace",  NULL);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, background, "setcolorspace", &_23, _22);
		zephir_check_call_status();
		_24 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		ZEPHIR_SINIT_NVAR(_0);
		ZVAL_STRING(&_0, "Imagick::COMPOSITE_DISSOLVE", 0);
		ZEPHIR_CALL_FUNCTION(&_25, "constant", &_16, &_0);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(_7);
		ZVAL_LONG(_7, 0);
		ZEPHIR_INIT_NVAR(_26);
		ZVAL_LONG(_26, 0);
		ZEPHIR_CALL_METHOD(NULL, background, "compositeimage", &_27, _24, _25, _7, _26);
		zephir_check_call_status();
		_28 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(&_29, _28, "nextimage",  NULL);
		zephir_check_call_status();
		if (!(zephir_is_true(_29))) {
			break;
		}
	}
	_10 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(NULL, _10, "clear", NULL);
	zephir_check_call_status();
	_11 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(NULL, _11, "destroy", NULL);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("_image"), background TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Phalcon_Image_Adapter_Imagick, _blur) {

	zval *radius_param = NULL, *_0, *_1 = NULL, *_2, *_3 = NULL, *_4, *_5 = NULL;
	int radius, ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &radius_param);

	radius = zephir_get_intval(radius_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_LONG(_1, 0);
	ZEPHIR_CALL_METHOD(NULL, _0, "setiteratorindex", NULL, _1);
	zephir_check_call_status();
	while (1) {
		_2 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		ZEPHIR_INIT_NVAR(_1);
		ZVAL_LONG(_1, radius);
		ZEPHIR_INIT_NVAR(_3);
		ZVAL_LONG(_3, 100);
		ZEPHIR_CALL_METHOD(NULL, _2, "blurimage", NULL, _1, _3);
		zephir_check_call_status();
		_4 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(&_5, _4, "nextimage",  NULL);
		zephir_check_call_status();
		if (!(zephir_is_true(_5))) {
			break;
		}
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Phalcon_Image_Adapter_Imagick, _pixelate) {

	zval *amount_param = NULL, *_0, *_1, *_2, *_3 = NULL, *_4, *_5 = NULL, *_6, *_7, *_8, *_9, *_10 = NULL;
	int amount, width, height, ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &amount_param);

	amount = zephir_get_intval(amount_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_width"), PH_NOISY_CC);
	width = (zephir_get_numberval(_0) / amount);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("_height"), PH_NOISY_CC);
	height = (zephir_get_numberval(_1) / amount);
	_2 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_3);
	ZVAL_LONG(_3, 0);
	ZEPHIR_CALL_METHOD(NULL, _2, "setiteratorindex", NULL, _3);
	zephir_check_call_status();
	while (1) {
		_4 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		ZEPHIR_INIT_NVAR(_3);
		ZVAL_LONG(_3, width);
		ZEPHIR_INIT_NVAR(_5);
		ZVAL_LONG(_5, height);
		ZEPHIR_CALL_METHOD(NULL, _4, "scaleimage", NULL, _3, _5);
		zephir_check_call_status();
		_6 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		_7 = zephir_fetch_nproperty_this(this_ptr, SL("_width"), PH_NOISY_CC);
		_8 = zephir_fetch_nproperty_this(this_ptr, SL("_height"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(NULL, _6, "scaleimage", NULL, _7, _8);
		zephir_check_call_status();
		_9 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(&_10, _9, "nextimage",  NULL);
		zephir_check_call_status();
		if (!(zephir_is_true(_10))) {
			break;
		}
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Phalcon_Image_Adapter_Imagick, _save) {

	zend_bool _15;
	zephir_nts_static zephir_fcall_cache_entry *_1 = NULL, *_10 = NULL, *_12 = NULL, *_18 = NULL;
	int quality, ZEPHIR_LAST_CALL_STATUS;
	zval *file_param = NULL, *quality_param = NULL, *ext = NULL, *fp = NULL, _0 = zval_used_for_init, *_2, *_3, *_4, *_5 = NULL, *_6, *_7 = NULL, *_8, *_9 = NULL, *_11, *_13, *_14 = NULL, *_16 = NULL, *_17 = NULL, *_19, *_20;
	zval *file = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &file_param, &quality_param);

	zephir_get_strval(file, file_param);
	quality = zephir_get_intval(quality_param);


	ZEPHIR_SINIT_VAR(_0);
	ZVAL_LONG(&_0, 4);
	ZEPHIR_CALL_FUNCTION(&ext, "pathinfo", &_1, file, &_0);
	zephir_check_call_status();
	_2 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(NULL, _2, "setformat", NULL, ext);
	zephir_check_call_status();
	_3 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(NULL, _3, "setimageformat", NULL, ext);
	zephir_check_call_status();
	_4 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&_5, _4, "getimagetype",  NULL);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("_type"), _5 TSRMLS_CC);
	_6 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&_7, _6, "getimageformat",  NULL);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_8);
	ZEPHIR_CONCAT_SV(_8, "image/", _7);
	zephir_update_property_this(this_ptr, SL("_mime"), _8 TSRMLS_CC);
	ZEPHIR_SINIT_NVAR(_0);
	ZVAL_STRING(&_0, "gif", 0);
	ZEPHIR_CALL_FUNCTION(&_9, "strcasecmp", &_10, ext, &_0);
	zephir_check_call_status();
	if (ZEPHIR_IS_LONG(_9, 0)) {
		_11 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(NULL, _11, "optimizeimagelayers", NULL);
		zephir_check_call_status();
		ZEPHIR_SINIT_NVAR(_0);
		ZVAL_STRING(&_0, "w", 0);
		ZEPHIR_CALL_FUNCTION(&fp, "fopen", &_12, file, &_0);
		zephir_check_call_status();
		_13 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(NULL, _13, "writeimagesfile", NULL, fp);
		zephir_check_call_status();
		zephir_fclose(fp TSRMLS_CC);
		RETURN_MM_NULL();
	} else {
		ZEPHIR_SINIT_NVAR(_0);
		ZVAL_STRING(&_0, "jpg", 0);
		ZEPHIR_CALL_FUNCTION(&_14, "strcasecmp", &_10, ext, &_0);
		zephir_check_call_status();
		_15 = ZEPHIR_IS_LONG(_14, 0);
		if (!(_15)) {
			ZEPHIR_SINIT_NVAR(_0);
			ZVAL_STRING(&_0, "jpeg", 0);
			ZEPHIR_CALL_FUNCTION(&_16, "strcasecmp", &_10, ext, &_0);
			zephir_check_call_status();
			_15 = ZEPHIR_IS_LONG(_16, 0);
		}
		if (_15) {
			_11 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
			ZEPHIR_SINIT_NVAR(_0);
			ZVAL_STRING(&_0, "Imagick::COMPRESSION_JPEG", 0);
			ZEPHIR_CALL_FUNCTION(&_17, "constant", &_18, &_0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, _11, "setimagecompression", NULL, _17);
			zephir_check_call_status();
		}
		_13 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		ZEPHIR_INIT_VAR(_19);
		ZVAL_LONG(_19, quality);
		ZEPHIR_CALL_METHOD(NULL, _13, "setimagecompressionquality", NULL, _19);
		zephir_check_call_status();
		_20 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(NULL, _20, "writeimage", NULL, file);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Phalcon_Image_Adapter_Imagick, _render) {

	zend_bool _7;
	zephir_nts_static zephir_fcall_cache_entry *_5 = NULL, *_10 = NULL;
	int quality, ZEPHIR_LAST_CALL_STATUS;
	zval *ext_param = NULL, *quality_param = NULL, *image, *_0 = NULL, *_1 = NULL, *_2, _3 = zval_used_for_init, *_4 = NULL, *_6 = NULL, *_8 = NULL, *_9 = NULL, *_11;
	zval *ext = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &ext_param, &quality_param);

	zephir_get_strval(ext, ext_param);
	quality = zephir_get_intval(quality_param);


	ZEPHIR_OBS_VAR(image);
	zephir_read_property_this(&image, this_ptr, SL("_image"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(NULL, image, "setformat", NULL, ext);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, image, "setimageformat", NULL, ext);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_0, image, "getimagetype",  NULL);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("_type"), _0 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&_1, image, "getimageformat",  NULL);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_2);
	ZEPHIR_CONCAT_SV(_2, "image/", _1);
	zephir_update_property_this(this_ptr, SL("_mime"), _2 TSRMLS_CC);
	ZEPHIR_SINIT_VAR(_3);
	ZVAL_STRING(&_3, "gif", 0);
	ZEPHIR_CALL_FUNCTION(&_4, "strcasecmp", &_5, ext, &_3);
	zephir_check_call_status();
	if (ZEPHIR_IS_LONG(_4, 0)) {
		ZEPHIR_CALL_METHOD(NULL, image, "optimizeimagelayers", NULL);
		zephir_check_call_status();
		ZEPHIR_RETURN_CALL_METHOD(image, "getimagesblob", NULL);
		zephir_check_call_status();
		RETURN_MM();
	} else {
		ZEPHIR_SINIT_NVAR(_3);
		ZVAL_STRING(&_3, "jpg", 0);
		ZEPHIR_CALL_FUNCTION(&_6, "strcasecmp", &_5, ext, &_3);
		zephir_check_call_status();
		_7 = ZEPHIR_IS_LONG(_6, 0);
		if (!(_7)) {
			ZEPHIR_SINIT_NVAR(_3);
			ZVAL_STRING(&_3, "jpeg", 0);
			ZEPHIR_CALL_FUNCTION(&_8, "strcasecmp", &_5, ext, &_3);
			zephir_check_call_status();
			_7 = ZEPHIR_IS_LONG(_8, 0);
		}
		if (_7) {
			ZEPHIR_SINIT_NVAR(_3);
			ZVAL_STRING(&_3, "Imagick::COMPRESSION_JPEG", 0);
			ZEPHIR_CALL_FUNCTION(&_9, "constant", &_10, &_3);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, image, "setimagecompression", NULL, _9);
			zephir_check_call_status();
		}
		ZEPHIR_INIT_VAR(_11);
		ZVAL_LONG(_11, quality);
		ZEPHIR_CALL_METHOD(NULL, image, "setimagecompressionquality", NULL, _11);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Phalcon_Image_Adapter_Imagick, __destruct) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *image;

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(image);
	zephir_read_property_this(&image, this_ptr, SL("_image"), PH_NOISY_CC);
	if (zephir_is_true(image)) {
		ZEPHIR_CALL_METHOD(NULL, image, "clear", NULL);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, image, "destroy", NULL);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();

}

