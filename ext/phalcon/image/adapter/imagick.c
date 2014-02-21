
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
	zval *_0, _1, _2 = zval_used_for_init, *_3, *_4, *_5, *_6;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_static_property_ce(phalcon_image_adapter_imagick_ce, SL("_checked") TSRMLS_CC);
	if (zephir_is_true(_0)) {
		RETURN_MM_BOOL(1);
	}
	ZEPHIR_SINIT_VAR(_1);
	ZVAL_STRING(&_1, "imagick", 0);
	if (!(zephir_class_exists(&_1, 1 TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_STR(phalcon_image_exception_ce, "Imagick is not installed, or the extension is not loaded");
		return;
	}
	ZEPHIR_SINIT_VAR(_2);
	ZVAL_STRING(&_2, "Imagick::IMAGICK_EXTNUM", 0);
	ZEPHIR_INIT_VAR(_3);
	zephir_call_func_p1(_3, "defined", &_2);
	zephir_check_call_status();
	if (zephir_is_true(_3)) {
		ZEPHIR_SINIT_NVAR(_2);
		ZVAL_STRING(&_2, "Imagick::IMAGICK_EXTNUM", 0);
		ZEPHIR_INIT_VAR(_4);
		zephir_call_func_p1(_4, "constant", &_2);
		zephir_check_call_status();
		zephir_update_property_this(this_ptr, SL("_version"), _4 TSRMLS_CC);
	}
	zephir_update_static_property_ce(phalcon_image_adapter_imagick_ce, SL("_checked"), ZEPHIR_GLOBAL(global_true) TSRMLS_CC);
	_6 = zephir_fetch_static_property_ce(phalcon_image_adapter_imagick_ce, SL("_checked") TSRMLS_CC);
	RETURN_CTOR(_6);

}

PHP_METHOD(Phalcon_Image_Adapter_Imagick, __construct) {

	zend_bool _18;
	zend_class_entry *_2, *_19;
	int width, height, ZEPHIR_LAST_CALL_STATUS;
	zval *file_param = NULL, *width_param = NULL, *height_param = NULL, *image, *_0, *_1, *_3, *_4, *_5 = NULL, *_6, *_7 = NULL, *_8, *_9 = NULL, *_10, *_11 = NULL, *_12 = NULL, *_13, _14, *_15 = NULL, *_16, *_17;
	zval *file = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &file_param, &width_param, &height_param);

	if (Z_TYPE_P(file_param) != IS_STRING && Z_TYPE_P(file_param) != IS_NULL) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'file' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (Z_TYPE_P(file_param) == IS_STRING) {
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
		zephir_check_call_status();
	}
	zephir_update_property_this(this_ptr, SL("_file"), file TSRMLS_CC);
	ZEPHIR_INIT_VAR(_1);
	_2 = zend_fetch_class(SL("Imagick"), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
	object_init_ex(_1, _2);
	zephir_call_method_noret(_1, "__construct");
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("_image"), _1 TSRMLS_CC);
	_3 = zephir_fetch_nproperty_this(this_ptr, SL("_file"), PH_NOISY_CC);
	if ((zephir_file_exists(_3 TSRMLS_CC) == SUCCESS)) {
		_4 = zephir_fetch_nproperty_this(this_ptr, SL("_file"), PH_NOISY_CC);
		ZEPHIR_INIT_VAR(_5);
		zephir_call_func_p1(_5, "realpath", _4);
		zephir_check_call_status();
		zephir_update_property_this(this_ptr, SL("_realpath"), _5 TSRMLS_CC);
		_6 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		ZEPHIR_INIT_VAR(_7);
		_8 = zephir_fetch_nproperty_this(this_ptr, SL("_realpath"), PH_NOISY_CC);
		zephir_call_method_p1(_7, _6, "readimage", _8);
		zephir_check_call_status();
		if (!(zephir_is_true(_7))) {
			ZEPHIR_INIT_VAR(_9);
			object_init_ex(_9, phalcon_image_exception_ce);
			_10 = zephir_fetch_nproperty_this(this_ptr, SL("_file"), PH_NOISY_CC);
			ZEPHIR_INIT_VAR(_11);
			ZEPHIR_CONCAT_SVS(_11, "Imagick::readImage ", _10, " failed");
			zephir_call_method_p1_noret(_9, "__construct", _11);
			zephir_check_call_status();
			zephir_throw_exception(_9 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
		_10 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		ZEPHIR_INIT_VAR(_12);
		zephir_call_method(_12, _10, "getimagealphachannel");
		zephir_check_call_status();
		if (!(zephir_is_true(_12))) {
			_13 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
			ZEPHIR_SINIT_VAR(_14);
			ZVAL_STRING(&_14, "Imagick::ALPHACHANNEL_SET", 0);
			ZEPHIR_INIT_VAR(_15);
			zephir_call_func_p1(_15, "constant", &_14);
			zephir_check_call_status();
			zephir_call_method_p1_noret(_13, "setimagealphachannel", _15);
			zephir_check_call_status();
		}
		_10 = zephir_fetch_nproperty_this(this_ptr, SL("_type"), PH_NOISY_CC);
		if (ZEPHIR_IS_LONG(_10, 1)) {
			_13 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
			ZEPHIR_INIT_VAR(image);
			zephir_call_method(image, _13, "coalesceimages");
			zephir_check_call_status();
			_16 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
			zephir_call_method_noret(_16, "clear");
			zephir_check_call_status();
			_17 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
			zephir_call_method_noret(_17, "destroy");
			zephir_check_call_status();
			zephir_update_property_this(this_ptr, SL("_image"), image TSRMLS_CC);
		}
	} else {
		_18 = !width;
		if (!(_18)) {
			_18 = !height;
		}
		if (_18) {
			ZEPHIR_INIT_LNVAR(_9);
			object_init_ex(_9, phalcon_image_exception_ce);
			_4 = zephir_fetch_nproperty_this(this_ptr, SL("_file"), PH_NOISY_CC);
			ZEPHIR_INIT_LNVAR(_11);
			ZEPHIR_CONCAT_SV(_11, "Failed to create image from file ", _4);
			zephir_call_method_p1_noret(_9, "__construct", _11);
			zephir_check_call_status();
			zephir_throw_exception(_9 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
		_6 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		ZEPHIR_INIT_LNVAR(_9);
		_19 = zend_fetch_class(SL("ImagickPixel"), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
		object_init_ex(_9, _19);
		ZEPHIR_INIT_NVAR(_5);
		ZVAL_STRING(_5, "transparent", 1);
		zephir_call_method_p1_noret(_9, "__construct", _5);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(_5);
		ZVAL_LONG(_5, width);
		ZEPHIR_INIT_NVAR(_7);
		ZVAL_LONG(_7, height);
		zephir_call_method_p3_noret(_6, "newimage", _5, _7, _9);
		zephir_check_call_status();
		_8 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		ZEPHIR_INIT_NVAR(_5);
		ZVAL_STRING(_5, "png", 1);
		zephir_call_method_p1_noret(_8, "setformat", _5);
		zephir_check_call_status();
		_10 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		ZEPHIR_INIT_NVAR(_5);
		ZVAL_STRING(_5, "png", 1);
		zephir_call_method_p1_noret(_10, "setimageformat", _5);
		zephir_check_call_status();
		_13 = zephir_fetch_nproperty_this(this_ptr, SL("_file"), PH_NOISY_CC);
		zephir_update_property_this(this_ptr, SL("_realpath"), _13 TSRMLS_CC);
	}
	_4 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
	ZEPHIR_INIT_NVAR(_5);
	zephir_call_method(_5, _4, "getimagewidth");
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("_width"), _5 TSRMLS_CC);
	_6 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
	ZEPHIR_INIT_NVAR(_7);
	zephir_call_method(_7, _6, "getimageheight");
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("_height"), _7 TSRMLS_CC);
	_8 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
	ZEPHIR_INIT_NVAR(_12);
	zephir_call_method(_12, _8, "getimagetype");
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("_type"), _12 TSRMLS_CC);
	_16 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
	ZEPHIR_INIT_NVAR(_15);
	zephir_call_method(_15, _16, "getimageformat");
	zephir_check_call_status();
	ZEPHIR_INIT_LNVAR(_11);
	ZEPHIR_CONCAT_SV(_11, "image/", _15);
	zephir_update_property_this(this_ptr, SL("_mime"), _11 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Phalcon_Image_Adapter_Imagick, _resize) {

	zval *width_param = NULL, *height_param = NULL, *_0, *_1 = NULL, *_2, *_3 = NULL, *_4, *_5;
	int width, height, ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &width_param, &height_param);

	width = zephir_get_intval(width_param);
	height = zephir_get_intval(height_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_LONG(_1, 0);
	zephir_call_method_p1_noret(_0, "setiteratorindex", _1);
	zephir_check_call_status();
	while (1) {
		_2 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		ZEPHIR_INIT_NVAR(_1);
		ZVAL_LONG(_1, width);
		ZEPHIR_INIT_NVAR(_3);
		ZVAL_LONG(_3, height);
		zephir_call_method_p2_noret(_2, "scaleimage", _1, _3);
		zephir_check_call_status();
		_4 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		ZEPHIR_INIT_NVAR(_1);
		zephir_call_method(_1, _4, "nextimage");
		zephir_check_call_status();
		if (!(zephir_is_true(_1))) {
			break;
		}
	}
	_2 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
	ZEPHIR_INIT_NVAR(_3);
	zephir_call_method(_3, _2, "getimagewidth");
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("_width"), _3 TSRMLS_CC);
	_4 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_5);
	zephir_call_method(_5, _4, "getimageheight");
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("_height"), _5 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Phalcon_Image_Adapter_Imagick, _crop) {

	zval *width_param = NULL, *height_param = NULL, *offset_x_param = NULL, *offset_y_param = NULL, *image, *_0 = NULL, *_1 = NULL, *_2 = NULL, *_3 = NULL;
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
	zephir_call_method_p1_noret(image, "setiteratorindex", _0);
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
		zephir_call_method_p4_noret(image, "cropimage", _0, _1, _2, _3);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(_0);
		ZVAL_LONG(_0, width);
		ZEPHIR_INIT_NVAR(_1);
		ZVAL_LONG(_1, height);
		ZEPHIR_INIT_NVAR(_2);
		ZVAL_LONG(_2, 0);
		ZEPHIR_INIT_NVAR(_3);
		ZVAL_LONG(_3, 0);
		zephir_call_method_p4_noret(image, "setimagepage", _0, _1, _2, _3);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(_0);
		zephir_call_method(_0, image, "nextimage");
		zephir_check_call_status();
		if (!(zephir_is_true(_0))) {
			break;
		}
	}
	ZEPHIR_INIT_NVAR(_1);
	zephir_call_method(_1, image, "getimagewidth");
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("_width"), _1 TSRMLS_CC);
	ZEPHIR_INIT_NVAR(_2);
	zephir_call_method(_2, image, "getimageheight");
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("_height"), _2 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Phalcon_Image_Adapter_Imagick, _rotate) {

	zend_class_entry *_2;
	zval *degrees_param = NULL, *pixel, *_0, *_1 = NULL, *_3, *_4, *_5, *_6, *_7 = NULL, *_8, *_9;
	int degrees, ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &degrees_param);

	degrees = zephir_get_intval(degrees_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_LONG(_1, 0);
	zephir_call_method_p1_noret(_0, "setiteratorindex", _1);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(pixel);
	_2 = zend_fetch_class(SL("ImagickPixel"), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
	object_init_ex(pixel, _2);
	zephir_call_method_noret(pixel, "__construct");
	zephir_check_call_status();
	while (1) {
		_3 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		ZEPHIR_INIT_NVAR(_1);
		ZVAL_LONG(_1, degrees);
		zephir_call_method_p2_noret(_3, "rotateimage", pixel, _1);
		zephir_check_call_status();
		_4 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		_5 = zephir_fetch_nproperty_this(this_ptr, SL("_width"), PH_NOISY_CC);
		_6 = zephir_fetch_nproperty_this(this_ptr, SL("_height"), PH_NOISY_CC);
		ZEPHIR_INIT_NVAR(_1);
		ZVAL_LONG(_1, 0);
		ZEPHIR_INIT_NVAR(_7);
		ZVAL_LONG(_7, 0);
		zephir_call_method_p4_noret(_4, "setimagepage", _5, _6, _1, _7);
		zephir_check_call_status();
		_8 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		ZEPHIR_INIT_NVAR(_1);
		zephir_call_method(_1, _8, "nextimage");
		zephir_check_call_status();
		if (!(zephir_is_true(_1))) {
			break;
		}
	}
	_3 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
	ZEPHIR_INIT_NVAR(_7);
	zephir_call_method(_7, _3, "getimagewidth");
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("_width"), _7 TSRMLS_CC);
	_4 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_9);
	zephir_call_method(_9, _4, "getimageheight");
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("_height"), _9 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Phalcon_Image_Adapter_Imagick, _flip) {

	zval *direction_param = NULL, *func, *_0, *_1 = NULL, *_2, *_3;
	int direction, ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &direction_param);

	direction = zephir_get_intval(direction_param);


	ZEPHIR_INIT_VAR(func);
	ZVAL_STRING(func, "flipImage", 1);
	if ((direction == 11)) {
		ZEPHIR_INIT_BNVAR(func);
		ZVAL_STRING(func, "flopImage", 1);
	}
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_LONG(_1, 0);
	zephir_call_method_p1_noret(_0, "setiteratorindex", _1);
	zephir_check_call_status();
	while (1) {
		_2 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		zephir_call_method_zval_noret(_2, func);
		zephir_check_call_status();
		_3 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		ZEPHIR_INIT_NVAR(_1);
		zephir_call_method(_1, _3, "nextimage");
		zephir_check_call_status();
		if (!(zephir_is_true(_1))) {
			break;
		}
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Phalcon_Image_Adapter_Imagick, _sharpen) {

	zval *amount_param = NULL, *_0, *_1, *_2 = NULL, *_3, *_4 = NULL, *_5;
	int amount, ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &amount_param);

	amount = zephir_get_intval(amount_param);


	ZEPHIR_INIT_VAR(_0);
	if ((amount < 5)) {
		ZVAL_LONG(_0, 5);
	} else {
		ZVAL_LONG(_0, amount);
	}
	amount = zephir_get_numberval(_0);
	amount = (((amount * 3.0)) / 100);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_2);
	ZVAL_LONG(_2, 0);
	zephir_call_method_p1_noret(_1, "setiteratorindex", _2);
	zephir_check_call_status();
	while (1) {
		_3 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		ZEPHIR_INIT_NVAR(_2);
		ZVAL_LONG(_2, 0);
		ZEPHIR_INIT_NVAR(_4);
		ZVAL_LONG(_4, amount);
		zephir_call_method_p2_noret(_3, "sharpenimage", _2, _4);
		zephir_check_call_status();
		_5 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		ZEPHIR_INIT_NVAR(_2);
		zephir_call_method(_2, _5, "nextimage");
		zephir_check_call_status();
		if (!(zephir_is_true(_2))) {
			break;
		}
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Phalcon_Image_Adapter_Imagick, _reflection) {

	zend_function *_9 = NULL, *_15 = NULL, *_16 = NULL, *_18 = NULL, *_20 = NULL, *_23 = NULL, *_25 = NULL, *_26 = NULL, *_27 = NULL, *_28 = NULL, *_29 = NULL, *_30 = NULL;
	zend_class_entry *_7, *_11, *_12;
	zend_bool fade_in, _31;
	zval *height_param = NULL, *opacity_param = NULL, *fade_in_param = NULL, *reflection, *fade, *pseudo = NULL, *image, *pixel, *_0, *_1, *_2 = NULL, *_3 = NULL, *_4 = NULL, *_5 = NULL, *_6 = NULL, _8 = zval_used_for_init, *_10 = NULL, *_13, *_14, *_17, *_19, *_21, *_22 = NULL, *_24;
	int height, opacity, ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &height_param, &opacity_param, &fade_in_param);

	height = zephir_get_intval(height_param);
	opacity = zephir_get_intval(opacity_param);
	fade_in = zephir_get_boolval(fade_in_param);


	ZEPHIR_INIT_VAR(reflection);
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_version"), PH_NOISY_CC);
	if (ZEPHIR_GE_LONG(_0, 30100)) {
		_1 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		if (zephir_clone(reflection, _1 TSRMLS_CC) == FAILURE) {
			RETURN_MM();
		}
	} else {
		_1 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		ZEPHIR_INIT_VAR(_2);
		zephir_call_method(_2, _1, "clone");
		zephir_check_call_status();
		if (zephir_clone(reflection, _2 TSRMLS_CC) == FAILURE) {
			RETURN_MM();
		}
	}
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_LONG(_2, 0);
	zephir_call_method_p1_noret(reflection, "setiteratorindex", _2);
	zephir_check_call_status();
	while (1) {
		zephir_call_method_noret(reflection, "flipimage");
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(_2);
		zephir_call_method(_2, reflection, "getimagewidth");
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(_3);
		ZVAL_LONG(_3, height);
		ZEPHIR_INIT_NVAR(_4);
		ZVAL_LONG(_4, 0);
		ZEPHIR_INIT_NVAR(_5);
		ZVAL_LONG(_5, 0);
		zephir_call_method_p4_noret(reflection, "cropimage", _2, _3, _4, _5);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(_3);
		zephir_call_method(_3, reflection, "getimagewidth");
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(_4);
		ZVAL_LONG(_4, height);
		ZEPHIR_INIT_NVAR(_5);
		ZVAL_LONG(_5, 0);
		ZEPHIR_INIT_NVAR(_6);
		ZVAL_LONG(_6, 0);
		zephir_call_method_p4_noret(reflection, "setimagepage", _3, _4, _5, _6);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(_4);
		zephir_call_method(_4, reflection, "nextimage");
		zephir_check_call_status();
		if (!(zephir_is_true(_4))) {
			break;
		}
	}
	ZEPHIR_INIT_NVAR(_2);
	if (fade_in) {
		ZVAL_STRING(_2, "gradient:black-transparent", 1);
	} else {
		ZVAL_STRING(_2, "gradient:transparent-black", 1);
	}
	ZEPHIR_CPY_WRT(pseudo, _2);
	ZEPHIR_INIT_VAR(fade);
	_7 = zend_fetch_class(SL("Imagick"), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
	object_init_ex(fade, _7);
	zephir_call_method_noret(fade, "__construct");
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_2);
	zephir_call_method(_2, reflection, "getimagewidth");
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_3);
	zephir_call_method(_3, reflection, "getimageheight");
	zephir_check_call_status();
	zephir_call_method_p3_noret(fade, "newpseudoimage", _2, _3, pseudo);
	zephir_check_call_status();
	opacity /= 100;
	ZEPHIR_INIT_NVAR(_4);
	ZVAL_LONG(_4, 0);
	zephir_call_method_p1_noret(reflection, "setiteratorindex", _4);
	zephir_check_call_status();
	while (1) {
		ZEPHIR_SINIT_NVAR(_8);
		ZVAL_STRING(&_8, "Imagick::COMPOSITE_DSTOUT", 0);
		ZEPHIR_INIT_NVAR(_4);
		ZEPHIR_CALL_INTERNAL_FUNCTION(_4, &_4, "constant", &_9, 1, &_8);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(_5);
		ZVAL_LONG(_5, 0);
		ZEPHIR_INIT_NVAR(_6);
		ZVAL_LONG(_6, 0);
		zephir_call_method_p4_noret(reflection, "compositeimage", fade, _4, _5, _6);
		zephir_check_call_status();
		ZEPHIR_SINIT_NVAR(_8);
		ZVAL_STRING(&_8, "Imagick::EVALUATE_MULTIPLY", 0);
		ZEPHIR_INIT_NVAR(_5);
		ZEPHIR_CALL_INTERNAL_FUNCTION(_5, &_5, "constant", &_9, 1, &_8);
		zephir_check_call_status();
		ZEPHIR_SINIT_NVAR(_8);
		ZVAL_STRING(&_8, "Imagick::CHANNEL_ALPHA", 0);
		ZEPHIR_INIT_NVAR(_6);
		ZEPHIR_CALL_INTERNAL_FUNCTION(_6, &_6, "constant", &_9, 1, &_8);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(_10);
		ZVAL_LONG(_10, (opacity / 100));
		zephir_call_method_p3_noret(reflection, "evaluateimage", _5, _10, _6);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(_10);
		zephir_call_method(_10, reflection, "nextimage");
		zephir_check_call_status();
		if (!(zephir_is_true(_10))) {
			break;
		}
	}
	zephir_call_method_noret(fade, "destroy");
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(image);
	_11 = zend_fetch_class(SL("Imagick"), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
	object_init_ex(image, _11);
	zephir_call_method_noret(image, "__construct");
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(pixel);
	_12 = zend_fetch_class(SL("ImagickPixel"), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
	object_init_ex(pixel, _12);
	zephir_call_method_noret(pixel, "__construct");
	zephir_check_call_status();
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
	ZEPHIR_INIT_NVAR(_2);
	zephir_call_method(_2, _1, "getimageheight");
	zephir_check_call_status();
	height = (zephir_get_numberval(_2) + height);
	_13 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
	ZEPHIR_INIT_NVAR(_3);
	ZVAL_LONG(_3, 0);
	zephir_call_method_p1_noret(_13, "setiteratorindex", _3);
	zephir_check_call_status();
	while (1) {
		_14 = zephir_fetch_nproperty_this(this_ptr, SL("_width"), PH_NOISY_CC);
		ZEPHIR_INIT_NVAR(_3);
		ZVAL_LONG(_3, height);
		zephir_call_method_p3_cache_noret(image, "newimage", &_15, _14, _3, pixel);
		zephir_check_call_status();
		ZEPHIR_SINIT_NVAR(_8);
		ZVAL_STRING(&_8, "Imagick::ALPHACHANNEL_SET", 0);
		ZEPHIR_INIT_NVAR(_3);
		ZEPHIR_CALL_INTERNAL_FUNCTION(_3, &_3, "constant", &_9, 1, &_8);
		zephir_check_call_status();
		zephir_call_method_p1_cache_noret(image, "setimagealphachannel", &_16, _3);
		zephir_check_call_status();
		_17 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		ZEPHIR_INIT_NVAR(_4);
		zephir_call_method(_4, _17, "getcolorspace");
		zephir_check_call_status();
		zephir_call_method_p1_cache_noret(image, "setcolorspace", &_18, _4);
		zephir_check_call_status();
		_19 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		ZEPHIR_INIT_NVAR(_5);
		zephir_call_method(_5, _19, "getimagedelay");
		zephir_check_call_status();
		zephir_call_method_p1_cache_noret(image, "setimagedelay", &_20, _5);
		zephir_check_call_status();
		_21 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		ZEPHIR_SINIT_NVAR(_8);
		ZVAL_STRING(&_8, "Imagick::COMPOSITE_SRC", 0);
		ZEPHIR_INIT_NVAR(_6);
		ZEPHIR_CALL_INTERNAL_FUNCTION(_6, &_6, "constant", &_9, 1, &_8);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(_10);
		ZVAL_LONG(_10, 0);
		ZEPHIR_INIT_NVAR(_22);
		ZVAL_LONG(_22, 0);
		zephir_call_method_p4_cache_noret(image, "compositeimage", &_23, _21, _6, _10, _22);
		zephir_check_call_status();
		_24 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		ZEPHIR_INIT_NVAR(_10);
		zephir_call_method(_10, _24, "nextimage");
		zephir_check_call_status();
		if (!(zephir_is_true(_10))) {
			break;
		}
	}
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_LONG(_2, 0);
	zephir_call_method_p1_noret(image, "setiteratorindex", _2);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_LONG(_2, 0);
	zephir_call_method_p1_noret(reflection, "setiteratorindex", _2);
	zephir_check_call_status();
	while (1) {
		ZEPHIR_SINIT_NVAR(_8);
		ZVAL_STRING(&_8, "Imagick::COMPOSITE_OVER", 0);
		ZEPHIR_INIT_NVAR(_2);
		ZEPHIR_CALL_INTERNAL_FUNCTION(_2, &_2, "constant", &_9, 1, &_8);
		zephir_check_call_status();
		_1 = zephir_fetch_nproperty_this(this_ptr, SL("_height"), PH_NOISY_CC);
		ZEPHIR_INIT_NVAR(_3);
		ZVAL_LONG(_3, 0);
		zephir_call_method_p4_cache_noret(image, "compositeimage", &_25, reflection, _2, _3, _1);
		zephir_check_call_status();
		ZEPHIR_SINIT_NVAR(_8);
		ZVAL_STRING(&_8, "Imagick::ALPHACHANNEL_SET", 0);
		ZEPHIR_INIT_NVAR(_3);
		ZEPHIR_CALL_INTERNAL_FUNCTION(_3, &_3, "constant", &_9, 1, &_8);
		zephir_check_call_status();
		zephir_call_method_p1_cache_noret(image, "setimagealphachannel", &_26, _3);
		zephir_check_call_status();
		_14 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		ZEPHIR_INIT_NVAR(_4);
		zephir_call_method(_4, _14, "getcolorspace");
		zephir_check_call_status();
		zephir_call_method_p1_cache_noret(image, "setcolorspace", &_27, _4);
		zephir_check_call_status();
		_17 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		ZEPHIR_INIT_NVAR(_5);
		zephir_call_method(_5, _17, "getimagedelay");
		zephir_check_call_status();
		zephir_call_method_p1_cache_noret(image, "setimagedelay", &_28, _5);
		zephir_check_call_status();
		_19 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		ZEPHIR_SINIT_NVAR(_8);
		ZVAL_STRING(&_8, "Imagick::COMPOSITE_SRC", 0);
		ZEPHIR_INIT_NVAR(_6);
		ZEPHIR_CALL_INTERNAL_FUNCTION(_6, &_6, "constant", &_9, 1, &_8);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(_10);
		ZVAL_LONG(_10, 0);
		ZEPHIR_INIT_NVAR(_22);
		ZVAL_LONG(_22, 0);
		zephir_call_method_p4_cache_noret(image, "compositeimage", &_29, _19, _6, _10, _22);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(_10);
		zephir_call_method_cache(_10, image, "nextimage", &_30);
		zephir_check_call_status();
		_31 = !zephir_is_true(_10);
		if (!(_31)) {
			ZEPHIR_INIT_NVAR(_22);
			zephir_call_method(_22, reflection, "nextimage");
			zephir_check_call_status();
			_31 = !zephir_is_true(_22);
		}
		if (_31) {
			break;
		}
	}
	zephir_call_method_noret(reflection, "destroy");
	zephir_check_call_status();
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
	zephir_call_method_noret(_1, "clear");
	zephir_check_call_status();
	_14 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
	zephir_call_method_noret(_14, "destroy");
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("_image"), image TSRMLS_CC);
	_17 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
	ZEPHIR_INIT_NVAR(_2);
	zephir_call_method(_2, _17, "getimagewidth");
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("_width"), _2 TSRMLS_CC);
	_19 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
	ZEPHIR_INIT_NVAR(_3);
	zephir_call_method(_3, _19, "getimageheight");
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("_height"), _3 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Phalcon_Image_Adapter_Imagick, _watermark) {

	zend_function *_6 = NULL;
	zend_class_entry *_0;
	int offset_x, offset_y, opacity, ZEPHIR_LAST_CALL_STATUS;
	zval *image, *offset_x_param = NULL, *offset_y_param = NULL, *opacity_param = NULL, *watermark, *_1, *_2 = NULL, *_3, *_4, _5 = zval_used_for_init, *_7 = NULL, *_8 = NULL, *_9;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 4, 0, &image, &offset_x_param, &offset_y_param, &opacity_param);

	offset_x = zephir_get_intval(offset_x_param);
	offset_y = zephir_get_intval(offset_y_param);
	opacity = zephir_get_intval(opacity_param);


	if (!(zephir_instance_of_ev(image, phalcon_image_adapter_ce TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_STR(spl_ce_InvalidArgumentException, "Parameter 'image' must be an instance of 'Phalcon\\Image\\Adapter'");
		return;
	}
	opacity = (opacity / 100);
	ZEPHIR_INIT_VAR(watermark);
	_0 = zend_fetch_class(SL("Imagick"), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
	object_init_ex(watermark, _0);
	zephir_call_method_noret(watermark, "__construct");
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_1);
	zephir_call_method(_1, image, "render");
	zephir_check_call_status();
	zephir_call_method_p1_noret(watermark, "readimageblob", _1);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_2);
	ZVAL_LONG(_2, opacity);
	zephir_call_method_p1_noret(watermark, "setimageopacity", _2);
	zephir_check_call_status();
	_3 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
	ZEPHIR_INIT_BNVAR(_2);
	ZVAL_LONG(_2, 0);
	zephir_call_method_p1_noret(_3, "setiteratorindex", _2);
	zephir_check_call_status();
	while (1) {
		_4 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		ZEPHIR_SINIT_NVAR(_5);
		ZVAL_STRING(&_5, "Imagick::COMPOSITE_OVER", 0);
		ZEPHIR_INIT_NVAR(_2);
		ZEPHIR_CALL_INTERNAL_FUNCTION(_2, &_2, "constant", &_6, 1, &_5);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(_7);
		ZVAL_LONG(_7, offset_x);
		ZEPHIR_INIT_NVAR(_8);
		ZVAL_LONG(_8, offset_y);
		zephir_call_method_p4_noret(_4, "compositeimage", watermark, _2, _7, _8);
		zephir_check_call_status();
		_9 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		ZEPHIR_INIT_NVAR(_7);
		zephir_call_method(_7, _9, "nextimage");
		zephir_check_call_status();
		if (!(zephir_is_true(_7))) {
			break;
		}
	}
	zephir_call_method_noret(watermark, "clear");
	zephir_check_call_status();
	zephir_call_method_noret(watermark, "destroy");
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Phalcon_Image_Adapter_Imagick, _text) {

	zend_class_entry *_0, *_5;
	int offset_x, offset_y, opacity, r, g, b, size, ZEPHIR_LAST_CALL_STATUS;
	zval *text_param = NULL, *offset_x_param = NULL, *offset_y_param = NULL, *opacity_param = NULL, *r_param = NULL, *g_param = NULL, *b_param = NULL, *size_param = NULL, *fontfile_param = NULL, *draw, *color, *pixel, *gravity, _1 = zval_used_for_init, _2, _3, _4, *_6 = NULL, *_7 = NULL, *_8, *_9, *_10 = NULL, *_11;
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
	zephir_call_method_noret(draw, "__construct");
	zephir_check_call_status();
	ZEPHIR_SINIT_VAR(_1);
	ZVAL_STRING(&_1, "rgb(%d, %d, %d)", 0);
	ZEPHIR_SINIT_VAR(_2);
	ZVAL_LONG(&_2, r);
	ZEPHIR_SINIT_VAR(_3);
	ZVAL_LONG(&_3, g);
	ZEPHIR_SINIT_VAR(_4);
	ZVAL_LONG(&_4, b);
	ZEPHIR_INIT_VAR(color);
	zephir_call_func_p4(color, "sprintf", &_1, &_2, &_3, &_4);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(pixel);
	_5 = zend_fetch_class(SL("ImagickPixel"), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
	object_init_ex(pixel, _5);
	zephir_call_method_p1_noret(pixel, "__construct", color);
	zephir_check_call_status();
	zephir_call_method_p1_noret(draw, "setfillcolor", pixel);
	zephir_check_call_status();
	if (fontfile && Z_STRLEN_P(fontfile)) {
		zephir_call_method_p1_noret(draw, "setfont", fontfile);
		zephir_check_call_status();
	}
	if (size) {
		ZEPHIR_INIT_VAR(_6);
		ZVAL_LONG(_6, size);
		zephir_call_method_p1_noret(draw, "setfontsize", _6);
		zephir_check_call_status();
	}
	if (opacity) {
		ZEPHIR_INIT_NVAR(_6);
		ZVAL_LONG(_6, opacity);
		zephir_call_method_p1_noret(draw, "setfillopacity", _6);
		zephir_check_call_status();
	}
	if ((offset_x < 0)) {
		ZEPHIR_SINIT_NVAR(_1);
		ZVAL_LONG(&_1, offset_x);
		ZEPHIR_INIT_NVAR(_6);
		zephir_call_func_p1(_6, "abs", &_1);
		zephir_check_call_status();
		offset_x = zephir_get_numberval(_6);
		ZEPHIR_INIT_VAR(gravity);
		if ((offset_y < 0)) {
			ZEPHIR_SINIT_NVAR(_1);
			ZVAL_LONG(&_1, offset_y);
			ZEPHIR_INIT_VAR(_7);
			zephir_call_func_p1(_7, "abs", &_1);
			zephir_check_call_status();
			offset_y = zephir_get_numberval(_7);
			ZEPHIR_SINIT_NVAR(_1);
			ZVAL_STRING(&_1, "Imagick::GRAVITY_SOUTHEAST", 0);
			zephir_call_func_p1(gravity, "constant", &_1);
			zephir_check_call_status();
		} else {
			ZEPHIR_SINIT_NVAR(_1);
			ZVAL_STRING(&_1, "Imagick::GRAVITY_NORTHEAST", 0);
			zephir_call_func_p1(gravity, "constant", &_1);
			zephir_check_call_status();
		}
	}
	zephir_call_method_p1_noret(draw, "setgravity", gravity);
	zephir_check_call_status();
	_8 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
	ZEPHIR_INIT_NVAR(_6);
	ZVAL_LONG(_6, 0);
	zephir_call_method_p1_noret(_8, "setiteratorindex", _6);
	zephir_check_call_status();
	while (1) {
		_9 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		ZEPHIR_INIT_NVAR(_6);
		ZVAL_LONG(_6, offset_x);
		ZEPHIR_INIT_NVAR(_7);
		ZVAL_LONG(_7, offset_y);
		ZEPHIR_INIT_NVAR(_10);
		ZVAL_LONG(_10, 0);
		zephir_call_method_p5_noret(_9, "annotateimage", draw, _6, _7, _10, text);
		zephir_check_call_status();
		_11 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		ZEPHIR_INIT_NVAR(_6);
		zephir_call_method(_6, _11, "nextimage");
		zephir_check_call_status();
		if (!(zephir_is_true(_6))) {
			break;
		}
	}
	zephir_call_method_noret(draw, "destroy");
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Phalcon_Image_Adapter_Imagick, _mask) {

	zend_function *_7 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zend_class_entry *_0;
	zval *image, *mask, *_1, *_2, *_3 = NULL, *_4, *_5, _6 = zval_used_for_init, *_8 = NULL, *_9 = NULL, *_10;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &image);



	if (!(zephir_instance_of_ev(image, phalcon_image_adapter_ce TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_STR(spl_ce_InvalidArgumentException, "Parameter 'image' must be an instance of 'Phalcon\\Image\\Adapter'");
		return;
	}
	ZEPHIR_INIT_VAR(mask);
	_0 = zend_fetch_class(SL("Imagick"), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
	object_init_ex(mask, _0);
	zephir_call_method_noret(mask, "__construct");
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_1);
	zephir_call_method(_1, image, "render");
	zephir_check_call_status();
	zephir_call_method_p1_noret(mask, "readimageblob", _1);
	zephir_check_call_status();
	_2 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_3);
	ZVAL_LONG(_3, 0);
	zephir_call_method_p1_noret(_2, "setiteratorindex", _3);
	zephir_check_call_status();
	while (1) {
		_4 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		ZEPHIR_INIT_NVAR(_3);
		ZVAL_LONG(_3, 1);
		zephir_call_method_p1_noret(_4, "setimagematte", _3);
		zephir_check_call_status();
		_5 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		ZEPHIR_SINIT_NVAR(_6);
		ZVAL_STRING(&_6, "Imagick::COMPOSITE_DSTIN", 0);
		ZEPHIR_INIT_NVAR(_3);
		ZEPHIR_CALL_INTERNAL_FUNCTION(_3, &_3, "constant", &_7, 1, &_6);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(_8);
		ZVAL_LONG(_8, 0);
		ZEPHIR_INIT_NVAR(_9);
		ZVAL_LONG(_9, 0);
		zephir_call_method_p4_noret(_5, "compositeimage", mask, _3, _8, _9);
		zephir_check_call_status();
		_10 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		ZEPHIR_INIT_NVAR(_8);
		zephir_call_method(_8, _10, "nextimage");
		zephir_check_call_status();
		if (!(zephir_is_true(_8))) {
			break;
		}
	}
	zephir_call_method_noret(mask, "clear");
	zephir_check_call_status();
	zephir_call_method_noret(mask, "destroy");
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Phalcon_Image_Adapter_Imagick, _background) {

	zend_function *_11 = NULL, *_12 = NULL, *_14 = NULL, *_15 = NULL, *_16 = NULL, *_19 = NULL, *_21 = NULL, *_26 = NULL;
	zend_class_entry *_4, *_5, *_7;
	zval *r_param = NULL, *g_param = NULL, *b_param = NULL, *opacity_param = NULL, *background, *color, *pixel1, *pixel2, _0 = zval_used_for_init, _1, _2, _3, *_6 = NULL, *_8, *_9, *_10, *_13 = NULL, *_17 = NULL, *_18 = NULL, *_20, *_22, *_23 = NULL, *_24 = NULL, *_25 = NULL, *_27;
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
	ZEPHIR_INIT_VAR(color);
	zephir_call_func_p4(color, "sprintf", &_0, &_1, &_2, &_3);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(pixel1);
	_4 = zend_fetch_class(SL("ImagickPixel"), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
	object_init_ex(pixel1, _4);
	zephir_call_method_p1_noret(pixel1, "__construct", color);
	zephir_check_call_status();
	opacity = (opacity / 100);
	ZEPHIR_INIT_VAR(pixel2);
	_5 = zend_fetch_class(SL("ImagickPixel"), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
	object_init_ex(pixel2, _5);
	ZEPHIR_INIT_VAR(_6);
	ZVAL_STRING(_6, "transparent", 1);
	zephir_call_method_p1_noret(pixel2, "__construct", _6);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(background);
	_7 = zend_fetch_class(SL("Imagick"), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
	object_init_ex(background, _7);
	zephir_call_method_noret(background, "__construct");
	zephir_check_call_status();
	_8 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
	ZEPHIR_INIT_BNVAR(_6);
	ZVAL_LONG(_6, 0);
	zephir_call_method_p1_noret(_8, "setiteratorindex", _6);
	zephir_check_call_status();
	while (1) {
		_9 = zephir_fetch_nproperty_this(this_ptr, SL("_width"), PH_NOISY_CC);
		_10 = zephir_fetch_nproperty_this(this_ptr, SL("_height"), PH_NOISY_CC);
		zephir_call_method_p3_cache_noret(background, "newimage", &_11, _9, _10, pixel1);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(_6);
		zephir_call_method_cache(_6, background, "getimagealphachannel", &_12);
		zephir_check_call_status();
		if (!(zephir_is_true(_6))) {
			ZEPHIR_SINIT_NVAR(_0);
			ZVAL_STRING(&_0, "Imagick::ALPHACHANNEL_SET", 0);
			ZEPHIR_INIT_NVAR(_13);
			ZEPHIR_CALL_INTERNAL_FUNCTION(_13, &_13, "constant", &_14, 1, &_0);
			zephir_check_call_status();
			zephir_call_method_p1_cache_noret(background, "setimagealphachannel", &_15, _13);
			zephir_check_call_status();
		}
		zephir_call_method_p1_cache_noret(background, "setimagebackgroundcolor", &_16, pixel2);
		zephir_check_call_status();
		ZEPHIR_SINIT_NVAR(_0);
		ZVAL_STRING(&_0, "Imagick::EVALUATE_MULTIPLY", 0);
		ZEPHIR_INIT_NVAR(_13);
		ZEPHIR_CALL_INTERNAL_FUNCTION(_13, &_13, "constant", &_14, 1, &_0);
		zephir_check_call_status();
		ZEPHIR_SINIT_NVAR(_0);
		ZVAL_STRING(&_0, "Imagick::CHANNEL_ALPHA", 0);
		ZEPHIR_INIT_NVAR(_17);
		ZEPHIR_CALL_INTERNAL_FUNCTION(_17, &_17, "constant", &_14, 1, &_0);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(_18);
		ZVAL_LONG(_18, opacity);
		zephir_call_method_p3_cache_noret(background, "evaluateimage", &_19, _13, _18, _17);
		zephir_check_call_status();
		_20 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		ZEPHIR_INIT_NVAR(_18);
		zephir_call_method(_18, _20, "getcolorspace");
		zephir_check_call_status();
		zephir_call_method_p1_cache_noret(background, "setcolorspace", &_21, _18);
		zephir_check_call_status();
		_22 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		ZEPHIR_SINIT_NVAR(_0);
		ZVAL_STRING(&_0, "Imagick::COMPOSITE_DISSOLVE", 0);
		ZEPHIR_INIT_NVAR(_23);
		ZEPHIR_CALL_INTERNAL_FUNCTION(_23, &_23, "constant", &_14, 1, &_0);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(_24);
		ZVAL_LONG(_24, 0);
		ZEPHIR_INIT_NVAR(_25);
		ZVAL_LONG(_25, 0);
		zephir_call_method_p4_cache_noret(background, "compositeimage", &_26, _22, _23, _24, _25);
		zephir_check_call_status();
		_27 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		ZEPHIR_INIT_NVAR(_24);
		zephir_call_method(_24, _27, "nextimage");
		zephir_check_call_status();
		if (!(zephir_is_true(_24))) {
			break;
		}
	}
	_9 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
	zephir_call_method_noret(_9, "clear");
	zephir_check_call_status();
	_10 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
	zephir_call_method_noret(_10, "destroy");
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("_image"), background TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Phalcon_Image_Adapter_Imagick, _blur) {

	zval *radius_param = NULL, *_0, *_1 = NULL, *_2, *_3 = NULL, *_4;
	int radius, ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &radius_param);

	radius = zephir_get_intval(radius_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_LONG(_1, 0);
	zephir_call_method_p1_noret(_0, "setiteratorindex", _1);
	zephir_check_call_status();
	while (1) {
		_2 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		ZEPHIR_INIT_NVAR(_1);
		ZVAL_LONG(_1, radius);
		ZEPHIR_INIT_NVAR(_3);
		ZVAL_LONG(_3, 100);
		zephir_call_method_p2_noret(_2, "blurimage", _1, _3);
		zephir_check_call_status();
		_4 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		ZEPHIR_INIT_NVAR(_1);
		zephir_call_method(_1, _4, "nextimage");
		zephir_check_call_status();
		if (!(zephir_is_true(_1))) {
			break;
		}
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Phalcon_Image_Adapter_Imagick, _pixelate) {

	zval *amount_param = NULL, *_0, *_1, *_2, *_3 = NULL, *_4, *_5 = NULL, *_6, *_7, *_8, *_9;
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
	zephir_call_method_p1_noret(_2, "setiteratorindex", _3);
	zephir_check_call_status();
	while (1) {
		_4 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		ZEPHIR_INIT_NVAR(_3);
		ZVAL_LONG(_3, width);
		ZEPHIR_INIT_NVAR(_5);
		ZVAL_LONG(_5, height);
		zephir_call_method_p2_noret(_4, "scaleimage", _3, _5);
		zephir_check_call_status();
		_6 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		_7 = zephir_fetch_nproperty_this(this_ptr, SL("_width"), PH_NOISY_CC);
		_8 = zephir_fetch_nproperty_this(this_ptr, SL("_height"), PH_NOISY_CC);
		zephir_call_method_p2_noret(_6, "scaleimage", _7, _8);
		zephir_check_call_status();
		_9 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		ZEPHIR_INIT_NVAR(_3);
		zephir_call_method(_3, _9, "nextimage");
		zephir_check_call_status();
		if (!(zephir_is_true(_3))) {
			break;
		}
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Phalcon_Image_Adapter_Imagick, _save) {

	zend_bool _12;
	int quality, ZEPHIR_LAST_CALL_STATUS;
	zval *file_param = NULL, *quality_param = NULL, *ext, *fp, _0 = zval_used_for_init, *_1, *_2, *_3, *_4, *_5, *_6, *_7, *_8, *_9, *_10, *_11, *_13, *_14 = NULL, *_15;
	zval *file = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &file_param, &quality_param);

	zephir_get_strval(file, file_param);
	quality = zephir_get_intval(quality_param);


	ZEPHIR_SINIT_VAR(_0);
	ZVAL_LONG(&_0, 4);
	ZEPHIR_INIT_VAR(ext);
	zephir_call_func_p2(ext, "pathinfo", file, &_0);
	zephir_check_call_status();
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
	zephir_call_method_p1_noret(_1, "setformat", ext);
	zephir_check_call_status();
	_2 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
	zephir_call_method_p1_noret(_2, "setimageformat", ext);
	zephir_check_call_status();
	_3 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_4);
	zephir_call_method(_4, _3, "getimagetype");
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("_type"), _4 TSRMLS_CC);
	_5 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_6);
	zephir_call_method(_6, _5, "getimageformat");
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_7);
	ZEPHIR_CONCAT_SV(_7, "image/", _6);
	zephir_update_property_this(this_ptr, SL("_mime"), _7 TSRMLS_CC);
	ZEPHIR_SINIT_NVAR(_0);
	ZVAL_STRING(&_0, "gif", 0);
	ZEPHIR_INIT_VAR(_8);
	zephir_call_func_p2(_8, "strcasecmp", ext, &_0);
	zephir_check_call_status();
	if (ZEPHIR_IS_LONG(_8, 0)) {
		_9 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		zephir_call_method_noret(_9, "optimizeimagelayers");
		zephir_check_call_status();
		ZEPHIR_SINIT_NVAR(_0);
		ZVAL_STRING(&_0, "w", 0);
		ZEPHIR_INIT_VAR(fp);
		zephir_call_func_p2(fp, "fopen", file, &_0);
		zephir_check_call_status();
		_10 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		zephir_call_method_p1_noret(_10, "writeimagesfile", fp);
		zephir_check_call_status();
		zephir_fclose(fp TSRMLS_CC);
		RETURN_MM_NULL();
	} else {
		ZEPHIR_SINIT_NVAR(_0);
		ZVAL_STRING(&_0, "jpg", 0);
		ZEPHIR_INIT_VAR(_11);
		zephir_call_func_p2(_11, "strcasecmp", ext, &_0);
		zephir_check_call_status();
		_12 = ZEPHIR_IS_LONG(_11, 0);
		if (!(_12)) {
			ZEPHIR_SINIT_NVAR(_0);
			ZVAL_STRING(&_0, "jpeg", 0);
			ZEPHIR_INIT_VAR(_13);
			zephir_call_func_p2(_13, "strcasecmp", ext, &_0);
			zephir_check_call_status();
			_12 = ZEPHIR_IS_LONG(_13, 0);
		}
		if (_12) {
			_9 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
			ZEPHIR_SINIT_NVAR(_0);
			ZVAL_STRING(&_0, "Imagick::COMPRESSION_JPEG", 0);
			ZEPHIR_INIT_VAR(_14);
			zephir_call_func_p1(_14, "constant", &_0);
			zephir_check_call_status();
			zephir_call_method_p1_noret(_9, "setimagecompression", _14);
			zephir_check_call_status();
		}
		_10 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		ZEPHIR_INIT_NVAR(_14);
		ZVAL_LONG(_14, quality);
		zephir_call_method_p1_noret(_10, "setimagecompressionquality", _14);
		zephir_check_call_status();
		_15 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		zephir_call_method_p1_noret(_15, "writeimage", file);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Phalcon_Image_Adapter_Imagick, _render) {

	zend_bool _6;
	int quality, ZEPHIR_LAST_CALL_STATUS;
	zval *ext_param = NULL, *quality_param = NULL, *image, *_0, *_1, *_2, _3 = zval_used_for_init, *_4, *_5, *_7, *_8 = NULL;
	zval *ext = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &ext_param, &quality_param);

	zephir_get_strval(ext, ext_param);
	quality = zephir_get_intval(quality_param);


	ZEPHIR_OBS_VAR(image);
	zephir_read_property_this(&image, this_ptr, SL("_image"), PH_NOISY_CC);
	zephir_call_method_p1_noret(image, "setformat", ext);
	zephir_check_call_status();
	zephir_call_method_p1_noret(image, "setimageformat", ext);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_0);
	zephir_call_method(_0, image, "getimagetype");
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("_type"), _0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_1);
	zephir_call_method(_1, image, "getimageformat");
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_2);
	ZEPHIR_CONCAT_SV(_2, "image/", _1);
	zephir_update_property_this(this_ptr, SL("_mime"), _2 TSRMLS_CC);
	ZEPHIR_SINIT_VAR(_3);
	ZVAL_STRING(&_3, "gif", 0);
	ZEPHIR_INIT_VAR(_4);
	zephir_call_func_p2(_4, "strcasecmp", ext, &_3);
	zephir_check_call_status();
	if (ZEPHIR_IS_LONG(_4, 0)) {
		zephir_call_method_noret(image, "optimizeimagelayers");
		zephir_check_call_status();
		zephir_call_method(return_value, image, "getimagesblob");
		zephir_check_call_status();
		RETURN_MM();
	} else {
		ZEPHIR_SINIT_NVAR(_3);
		ZVAL_STRING(&_3, "jpg", 0);
		ZEPHIR_INIT_VAR(_5);
		zephir_call_func_p2(_5, "strcasecmp", ext, &_3);
		zephir_check_call_status();
		_6 = ZEPHIR_IS_LONG(_5, 0);
		if (!(_6)) {
			ZEPHIR_SINIT_NVAR(_3);
			ZVAL_STRING(&_3, "jpeg", 0);
			ZEPHIR_INIT_VAR(_7);
			zephir_call_func_p2(_7, "strcasecmp", ext, &_3);
			zephir_check_call_status();
			_6 = ZEPHIR_IS_LONG(_7, 0);
		}
		if (_6) {
			ZEPHIR_SINIT_NVAR(_3);
			ZVAL_STRING(&_3, "Imagick::COMPRESSION_JPEG", 0);
			ZEPHIR_INIT_VAR(_8);
			zephir_call_func_p1(_8, "constant", &_3);
			zephir_check_call_status();
			zephir_call_method_p1_noret(image, "setimagecompression", _8);
			zephir_check_call_status();
		}
		ZEPHIR_INIT_NVAR(_8);
		ZVAL_LONG(_8, quality);
		zephir_call_method_p1_noret(image, "setimagecompressionquality", _8);
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
		zephir_call_method_noret(image, "clear");
		zephir_check_call_status();
		zephir_call_method_noret(image, "destroy");
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();

}

