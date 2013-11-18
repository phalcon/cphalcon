
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
#include "kernel/fcall.h"
#include "kernel/exception.h"
#include "kernel/concat.h"
#include "ext/spl/spl_exceptions.h"


/*
 +------------------------------------------------------------------------+
 | Phalcon Framework                                                      |
 +------------------------------------------------------------------------+
 | Copyright (c) 2011-2013 Phalcon Team (http://www.phalconphp.com)       |
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

	zval *_0, _1 = zval_used_for_init, *_2, *_3 = NULL, *_4, *_5, *_6;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_static_property_ce(phalcon_image_adapter_imagick_ce, SL("_checked") TSRMLS_CC);
	if (zephir_is_true(_0)) {
		RETURN_MM_BOOL(1);
	}
	ZEPHIR_SINIT_VAR(_1);
	ZVAL_STRING(&_1, "imagick", 0);
	ZEPHIR_INIT_VAR(_2);
	zephir_call_func_p1(_2, "class_exists", &_1);
	if (!(zephir_is_true(_2))) {
		ZEPHIR_INIT_VAR(_3);
		object_init_ex(_3, phalcon_image_exception_ce);
		ZEPHIR_INIT_VAR(_4);
		ZVAL_STRING(_4, "Imagick is not installed, or the extension is not loaded", 1);
		zephir_call_method_p1_noret(_3, "__construct", _4);
		zephir_throw_exception(_3 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
		RETURN_MM_NULL();
	}
	ZEPHIR_SINIT_NVAR(_1);
	ZVAL_STRING(&_1, "Imagick::IMAGICK_EXTNUM", 0);
	ZEPHIR_INIT_NVAR(_3);
	zephir_call_func_p1(_3, "defined", &_1);
	if (zephir_is_true(_3)) {
		ZEPHIR_INIT_ZVAL_NREF(_5);
		ZVAL_LONG(_5, 30001);
		zephir_update_property_this(this_ptr, SL("_version"), _5 TSRMLS_CC);
	}
	zephir_update_static_property_ce(phalcon_image_adapter_imagick_ce, SL("_checked"), ZEPHIR_GLOBAL(global_true) TSRMLS_CC);
	_6 = zephir_fetch_static_property_ce(phalcon_image_adapter_imagick_ce, SL("_checked") TSRMLS_CC);
	RETURN_CTOR(_6);

}

PHP_METHOD(Phalcon_Image_Adapter_Imagick, __construct) {

	zend_class_entry *_2, *_17;
	int width, height;
	zval *file_param = NULL, *width_param = NULL, *height_param = NULL, *image, *_0, *_1, *_3, *_4, *_5, *_6 = NULL, *_7, *_8 = NULL, *_9, *_10 = NULL, *_11, *_12 = NULL, *_13, *_14 = NULL, *_15, *_16;
	zval *file = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &file_param, &width_param, &height_param);

		if (Z_TYPE_P(file_param) != IS_STRING) {
				zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'file' must be a string") TSRMLS_CC);
				RETURN_MM_NULL();
		}

		file = file_param;

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
	}
	zephir_update_property_this(this_ptr, SL("_file"), file TSRMLS_CC);
	ZEPHIR_INIT_VAR(_1);
	_2 = zend_fetch_class(SL("Imagick"), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
	object_init_ex(_1, _2);
	zephir_call_method_noret(_1, "__construct");
	zephir_update_property_this(this_ptr, SL("_image"), _1 TSRMLS_CC);
	_3 = zephir_fetch_nproperty_this(this_ptr, SL("_file"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_4);
	zephir_call_func_p1(_4, "file_exists", _3);
	if (zephir_is_true(_4)) {
		_5 = zephir_fetch_nproperty_this(this_ptr, SL("_file"), PH_NOISY_CC);
		ZEPHIR_INIT_VAR(_6);
		zephir_call_func_p1(_6, "realpath", _5);
		zephir_update_property_this(this_ptr, SL("_realpath"), _6 TSRMLS_CC);
		_7 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		ZEPHIR_INIT_VAR(_8);
		_9 = zephir_fetch_nproperty_this(this_ptr, SL("_realpath"), PH_NOISY_CC);
		zephir_call_method_p1(_8, _7, "readimage", _9);
		if (!(zephir_is_true(_8))) {
			ZEPHIR_INIT_VAR(_10);
			object_init_ex(_10, phalcon_image_exception_ce);
			_11 = zephir_fetch_nproperty_this(this_ptr, SL("_file"), PH_NOISY_CC);
			ZEPHIR_INIT_VAR(_12);
			ZEPHIR_CONCAT_SVS(_12, "Imagick::readImage ", _11, " failed");
			zephir_call_method_p1_noret(_10, "__construct", _12);
			zephir_throw_exception(_10 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
			RETURN_MM_NULL();
		}
		_11 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		ZEPHIR_INIT_NVAR(_10);
		zephir_call_method(_10, _11, "getimagealphachannel");
		if (!(zephir_is_true(_10))) {
			_13 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
			ZEPHIR_INIT_VAR(_14);
			ZVAL_LONG(_14, 8);
			zephir_call_method_p1_noret(_13, "setimagealphachannel", _14);
		}
		_11 = zephir_fetch_nproperty_this(this_ptr, SL("_type"), PH_NOISY_CC);
		if (ZEPHIR_IS_LONG(_11, 1)) {
			_13 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
			ZEPHIR_INIT_VAR(image);
			zephir_call_method(image, _13, "coalesceimages");
			_15 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
			zephir_call_method_noret(_15, "clear");
			_16 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
			zephir_call_method_noret(_16, "destroy");
			zephir_update_property_this(this_ptr, SL("_image"), image TSRMLS_CC);
		}
	} else {
		if ((!width || !height)) {
			ZEPHIR_INIT_NVAR(_6);
			object_init_ex(_6, phalcon_image_exception_ce);
			_5 = zephir_fetch_nproperty_this(this_ptr, SL("_file"), PH_NOISY_CC);
			ZEPHIR_INIT_LNVAR(_12);
			ZEPHIR_CONCAT_SV(_12, "Failed to create image from file ", _5);
			zephir_call_method_p1_noret(_6, "__construct", _12);
			zephir_throw_exception(_6 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
		_7 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		ZEPHIR_INIT_NVAR(_6);
		_17 = zend_fetch_class(SL("ImagickPixel"), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
		object_init_ex(_6, _17);
		ZEPHIR_INIT_NVAR(_8);
		ZVAL_STRING(_8, "transparent", 1);
		zephir_call_method_p1_noret(_6, "__construct", _8);
		ZEPHIR_INIT_NVAR(_8);
		ZVAL_LONG(_8, width);
		ZEPHIR_INIT_NVAR(_10);
		ZVAL_LONG(_10, height);
		zephir_call_method_p3_noret(_7, "newimage", _8, _10, _6);
		_9 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		ZEPHIR_INIT_NVAR(_8);
		ZVAL_STRING(_8, "png", 1);
		zephir_call_method_p1_noret(_9, "setformat", _8);
		_11 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		ZEPHIR_INIT_NVAR(_8);
		ZVAL_STRING(_8, "png", 1);
		zephir_call_method_p1_noret(_11, "setimageformat", _8);
		_13 = zephir_fetch_nproperty_this(this_ptr, SL("_file"), PH_NOISY_CC);
		zephir_update_property_this(this_ptr, SL("_realpath"), _13 TSRMLS_CC);
	}
	_5 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
	ZEPHIR_INIT_NVAR(_6);
	zephir_call_method(_6, _5, "getimagewidth");
	zephir_update_property_this(this_ptr, SL("_width"), _6 TSRMLS_CC);
	_7 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
	ZEPHIR_INIT_NVAR(_8);
	zephir_call_method(_8, _7, "getimageheight");
	zephir_update_property_this(this_ptr, SL("_height"), _8 TSRMLS_CC);
	_9 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
	ZEPHIR_INIT_NVAR(_10);
	zephir_call_method(_10, _9, "getimagetype");
	zephir_update_property_this(this_ptr, SL("_type"), _10 TSRMLS_CC);
	_15 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
	ZEPHIR_INIT_NVAR(_14);
	zephir_call_method(_14, _15, "getimageformat");
	ZEPHIR_INIT_LNVAR(_12);
	ZEPHIR_CONCAT_SV(_12, "image/", _14);
	zephir_update_property_this(this_ptr, SL("_mime"), _12 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Phalcon_Image_Adapter_Imagick, _resize) {

	zend_function *_4 = NULL, *_6 = NULL;
	zval *width_param = NULL, *height_param = NULL, *_0, *_1 = NULL, *_2, *_3 = NULL, *_5, *_7;
	int width, height;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &width_param, &height_param);

		width = zephir_get_intval(width_param);
		height = zephir_get_intval(height_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_LONG(_1, 0);
	zephir_call_method_p1_noret(_0, "setiteratorindex", _1);
	while (1) {
		_2 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		ZEPHIR_INIT_NVAR(_1);
		ZVAL_LONG(_1, width);
		ZEPHIR_INIT_NVAR(_3);
		ZVAL_LONG(_3, height);
		zephir_call_method_p2_cache_noret(_2, "scaleimage", &_4, _1, _3);
		_5 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		ZEPHIR_INIT_NVAR(_1);
		zephir_call_method_cache(_1, _5, "nextimage", &_6);
		if (!(zephir_is_true(_1))) {
			break;
		}
	}
	_2 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
	ZEPHIR_INIT_NVAR(_3);
	zephir_call_method(_3, _2, "getimagewidth");
	zephir_update_property_this(this_ptr, SL("_width"), _3 TSRMLS_CC);
	_5 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_7);
	zephir_call_method(_7, _5, "getimageheight");
	zephir_update_property_this(this_ptr, SL("_height"), _7 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Phalcon_Image_Adapter_Imagick, _crop) {

	zend_function *_4 = NULL, *_5 = NULL, *_6 = NULL;
	zval *width_param = NULL, *height_param = NULL, *offset_x_param = NULL, *offset_y_param = NULL, *image, *_0 = NULL, *_1 = NULL, *_2 = NULL, *_3 = NULL;
	int width, height, offset_x, offset_y;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 4, 0, &width_param, &height_param, &offset_x_param, &offset_y_param);

		width = zephir_get_intval(width_param);
		height = zephir_get_intval(height_param);
		offset_x = zephir_get_intval(offset_x_param);
		offset_y = zephir_get_intval(offset_y_param);


	image = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_0);
	ZVAL_LONG(_0, 0);
	zephir_call_method_p1_noret(image, "setiteratorindex", _0);
	while (1) {
		ZEPHIR_INIT_NVAR(_0);
		ZVAL_LONG(_0, width);
		ZEPHIR_INIT_NVAR(_1);
		ZVAL_LONG(_1, height);
		ZEPHIR_INIT_NVAR(_2);
		ZVAL_LONG(_2, offset_x);
		ZEPHIR_INIT_NVAR(_3);
		ZVAL_LONG(_3, offset_y);
		zephir_call_method_p4_cache_noret(image, "cropimage", &_4, _0, _1, _2, _3);
		ZEPHIR_INIT_NVAR(_0);
		ZVAL_LONG(_0, width);
		ZEPHIR_INIT_NVAR(_1);
		ZVAL_LONG(_1, height);
		ZEPHIR_INIT_NVAR(_2);
		ZVAL_LONG(_2, 0);
		ZEPHIR_INIT_NVAR(_3);
		ZVAL_LONG(_3, 0);
		zephir_call_method_p4_cache_noret(image, "setimagepage", &_5, _0, _1, _2, _3);
		ZEPHIR_INIT_NVAR(_0);
		zephir_call_method_cache(_0, image, "nextimage", &_6);
		if (!(zephir_is_true(_0))) {
			break;
		}
	}
	ZEPHIR_INIT_NVAR(_1);
	zephir_call_method(_1, image, "getimagewidth");
	zephir_update_property_this(this_ptr, SL("_width"), _1 TSRMLS_CC);
	ZEPHIR_INIT_NVAR(_2);
	zephir_call_method(_2, image, "getimageheight");
	zephir_update_property_this(this_ptr, SL("_height"), _2 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Phalcon_Image_Adapter_Imagick, _rotate) {

	zend_function *_4 = NULL, *_9 = NULL, *_11 = NULL;
	zend_class_entry *_2;
	zval *degrees_param = NULL, *pixel, *_0, *_1 = NULL, *_3, *_5, *_6, *_7, *_8 = NULL, *_10, *_12;
	int degrees;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &degrees_param);

		degrees = zephir_get_intval(degrees_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_LONG(_1, 0);
	zephir_call_method_p1_noret(_0, "setiteratorindex", _1);
	ZEPHIR_INIT_VAR(pixel);
	_2 = zend_fetch_class(SL("ImagickPixel"), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
	object_init_ex(pixel, _2);
	zephir_call_method_noret(pixel, "__construct");
	while (1) {
		_3 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		ZEPHIR_INIT_NVAR(_1);
		ZVAL_LONG(_1, degrees);
		zephir_call_method_p2_cache_noret(_3, "rotateimage", &_4, pixel, _1);
		_5 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		_6 = zephir_fetch_nproperty_this(this_ptr, SL("_width"), PH_NOISY_CC);
		_7 = zephir_fetch_nproperty_this(this_ptr, SL("_height"), PH_NOISY_CC);
		ZEPHIR_INIT_NVAR(_1);
		ZVAL_LONG(_1, 0);
		ZEPHIR_INIT_NVAR(_8);
		ZVAL_LONG(_8, 0);
		zephir_call_method_p4_cache_noret(_5, "setimagepage", &_9, _6, _7, _1, _8);
		_10 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		ZEPHIR_INIT_NVAR(_1);
		zephir_call_method_cache(_1, _10, "nextimage", &_11);
		if (!(zephir_is_true(_1))) {
			break;
		}
	}
	_3 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
	ZEPHIR_INIT_NVAR(_8);
	zephir_call_method(_8, _3, "getimagewidth");
	zephir_update_property_this(this_ptr, SL("_width"), _8 TSRMLS_CC);
	_5 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_12);
	zephir_call_method(_12, _5, "getimageheight");
	zephir_update_property_this(this_ptr, SL("_height"), _12 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Phalcon_Image_Adapter_Imagick, _flip) {

	zend_function *_4 = NULL;
	zval *direction_param = NULL, *func, *_0, *_1 = NULL, *_2, *_3;
	int direction;

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
	while (1) {
		_2 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		zephir_call_method_zval_noret(_2, func);
		_3 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		ZEPHIR_INIT_NVAR(_1);
		zephir_call_method_cache(_1, _3, "nextimage", &_4);
		if (!(zephir_is_true(_1))) {
			break;
		}
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Phalcon_Image_Adapter_Imagick, _sharpen) {

	zend_function *_4 = NULL, *_6 = NULL;
	zval *amount_param = NULL, *_0, *_1 = NULL, *_2, *_3 = NULL, *_5;
	int amount;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &amount_param);

		amount = zephir_get_intval(amount_param);


	amount = (0 == 1);
	amount = (((amount * 3.0)) / 100);
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_LONG(_1, 0);
	zephir_call_method_p1_noret(_0, "setiteratorindex", _1);
	while (1) {
		_2 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		ZEPHIR_INIT_NVAR(_1);
		ZVAL_LONG(_1, 0);
		ZEPHIR_INIT_NVAR(_3);
		ZVAL_LONG(_3, amount);
		zephir_call_method_p2_cache_noret(_2, "sharpenimage", &_4, _1, _3);
		_5 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		ZEPHIR_INIT_NVAR(_1);
		zephir_call_method_cache(_1, _5, "nextimage", &_6);
		if (!(zephir_is_true(_1))) {
			break;
		}
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Phalcon_Image_Adapter_Imagick, _reflection) {

	zend_class_entry *_13, *_17, *_18;
	zend_function *_3 = NULL, *_4 = NULL, *_8 = NULL, *_9 = NULL, *_11 = NULL, *_12 = NULL, *_14 = NULL, *_15 = NULL, *_16 = NULL, *_21 = NULL, *_22 = NULL, *_24 = NULL, *_25 = NULL, *_27 = NULL, *_28 = NULL, *_31 = NULL, *_33 = NULL, *_34 = NULL, *_35 = NULL, *_36 = NULL, *_37 = NULL, *_38 = NULL, *_39 = NULL, *_40 = NULL, *_41 = NULL, *_42 = NULL;
	zend_bool fade_in;
	zval *height_param = NULL, *opacity_param = NULL, *fade_in_param = NULL, *reflection, *fade, *pseudo, *image, *pixel, *_0, *_1, *_2 = NULL, *_5 = NULL, *_6 = NULL, *_7 = NULL, *_10 = NULL, *_19, *_20, *_23, *_26, *_29, *_30 = NULL, *_32;
	int height, opacity;

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
		if (zephir_clone(reflection, _2 TSRMLS_CC) == FAILURE) {
			RETURN_MM();
		}
	}
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_LONG(_2, 0);
	zephir_call_method_p1_noret(reflection, "setiteratorindex", _2);
	while (1) {
		zephir_call_method_cache_noret(reflection, "flipimage", &_3);
		ZEPHIR_INIT_NVAR(_2);
		zephir_call_method_cache(_2, reflection, "getimagewidth", &_4);
		ZEPHIR_INIT_NVAR(_5);
		ZVAL_LONG(_5, height);
		ZEPHIR_INIT_NVAR(_6);
		ZVAL_LONG(_6, 0);
		ZEPHIR_INIT_NVAR(_7);
		ZVAL_LONG(_7, 0);
		zephir_call_method_p4_cache_noret(reflection, "cropimage", &_8, _2, _5, _6, _7);
		ZEPHIR_INIT_NVAR(_5);
		zephir_call_method_cache(_5, reflection, "getimagewidth", &_9);
		ZEPHIR_INIT_NVAR(_6);
		ZVAL_LONG(_6, height);
		ZEPHIR_INIT_NVAR(_7);
		ZVAL_LONG(_7, 0);
		ZEPHIR_INIT_NVAR(_10);
		ZVAL_LONG(_10, 0);
		zephir_call_method_p4_cache_noret(reflection, "setimagepage", &_11, _5, _6, _7, _10);
		ZEPHIR_INIT_NVAR(_6);
		zephir_call_method_cache(_6, reflection, "nextimage", &_12);
		if (!(zephir_is_true(_6))) {
			break;
		}
	}
	ZEPHIR_INIT_VAR(pseudo);
	ZVAL_LONG(pseudo, (0 == 1));
	ZEPHIR_INIT_VAR(fade);
	_13 = zend_fetch_class(SL("Imagick"), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
	object_init_ex(fade, _13);
	zephir_call_method_noret(fade, "__construct");
	ZEPHIR_INIT_NVAR(_2);
	zephir_call_method(_2, reflection, "getimagewidth");
	ZEPHIR_INIT_NVAR(_5);
	zephir_call_method(_5, reflection, "getimageheight");
	zephir_call_method_p3_noret(fade, "newpseudoimage", _2, _5, pseudo);
	opacity /= 100;
	ZEPHIR_INIT_NVAR(_6);
	ZVAL_LONG(_6, 0);
	zephir_call_method_p1_noret(reflection, "setiteratorindex", _6);
	while (1) {
		ZEPHIR_INIT_NVAR(_6);
		ZVAL_LONG(_6, 24);
		ZEPHIR_INIT_NVAR(_7);
		ZVAL_LONG(_7, 0);
		ZEPHIR_INIT_NVAR(_10);
		ZVAL_LONG(_10, 0);
		zephir_call_method_p4_cache_noret(reflection, "compositeimage", &_14, fade, _6, _7, _10);
		ZEPHIR_INIT_NVAR(_6);
		ZVAL_LONG(_6, 7);
		ZEPHIR_INIT_NVAR(_7);
		ZVAL_LONG(_7, (opacity / 100));
		ZEPHIR_INIT_NVAR(_10);
		ZVAL_LONG(_10, 8);
		zephir_call_method_p3_cache_noret(reflection, "evaluateimage", &_15, _6, _7, _10);
		ZEPHIR_INIT_NVAR(_6);
		zephir_call_method_cache(_6, reflection, "nextimage", &_16);
		if (!(zephir_is_true(_6))) {
			break;
		}
	}
	zephir_call_method_noret(fade, "destroy");
	ZEPHIR_INIT_VAR(image);
	_17 = zend_fetch_class(SL("Imagick"), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
	object_init_ex(image, _17);
	zephir_call_method_noret(image, "__construct");
	ZEPHIR_INIT_VAR(pixel);
	_18 = zend_fetch_class(SL("ImagickPixel"), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
	object_init_ex(pixel, _18);
	zephir_call_method_noret(pixel, "__construct");
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
	ZEPHIR_INIT_NVAR(_2);
	zephir_call_method(_2, _1, "getimageheight");
	height = (zephir_get_numberval(_2) + height);
	_19 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
	ZEPHIR_INIT_NVAR(_5);
	ZVAL_LONG(_5, 0);
	zephir_call_method_p1_noret(_19, "setiteratorindex", _5);
	while (1) {
		_20 = zephir_fetch_nproperty_this(this_ptr, SL("_width"), PH_NOISY_CC);
		ZEPHIR_INIT_NVAR(_5);
		ZVAL_LONG(_5, height);
		zephir_call_method_p3_cache_noret(image, "newimage", &_21, _20, _5, pixel);
		ZEPHIR_INIT_NVAR(_5);
		ZVAL_LONG(_5, 8);
		zephir_call_method_p1_cache_noret(image, "setimagealphachannel", &_22, _5);
		_23 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		ZEPHIR_INIT_NVAR(_5);
		zephir_call_method_cache(_5, _23, "getcolorspace", &_24);
		zephir_call_method_p1_cache_noret(image, "setcolorspace", &_25, _5);
		_26 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		ZEPHIR_INIT_NVAR(_6);
		zephir_call_method_cache(_6, _26, "getimagedelay", &_27);
		zephir_call_method_p1_cache_noret(image, "setimagedelay", &_28, _6);
		_29 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		ZEPHIR_INIT_NVAR(_7);
		ZVAL_LONG(_7, 48);
		ZEPHIR_INIT_NVAR(_10);
		ZVAL_LONG(_10, 0);
		ZEPHIR_INIT_NVAR(_30);
		ZVAL_LONG(_30, 0);
		zephir_call_method_p4_cache_noret(image, "compositeimage", &_31, _29, _7, _10, _30);
		_32 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		ZEPHIR_INIT_NVAR(_7);
		zephir_call_method_cache(_7, _32, "nextimage", &_33);
		if (!(zephir_is_true(_7))) {
			break;
		}
	}
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_LONG(_2, 0);
	zephir_call_method_p1_noret(image, "setiteratorindex", _2);
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_LONG(_2, 0);
	zephir_call_method_p1_noret(reflection, "setiteratorindex", _2);
	while (1) {
		_1 = zephir_fetch_nproperty_this(this_ptr, SL("_height"), PH_NOISY_CC);
		ZEPHIR_INIT_NVAR(_2);
		ZVAL_LONG(_2, 40);
		ZEPHIR_INIT_NVAR(_5);
		ZVAL_LONG(_5, 0);
		zephir_call_method_p4_cache_noret(image, "compositeimage", &_34, reflection, _2, _5, _1);
		ZEPHIR_INIT_NVAR(_2);
		ZVAL_LONG(_2, 8);
		zephir_call_method_p1_cache_noret(image, "setimagealphachannel", &_35, _2);
		_20 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		ZEPHIR_INIT_NVAR(_2);
		zephir_call_method_cache(_2, _20, "getcolorspace", &_36);
		zephir_call_method_p1_cache_noret(image, "setcolorspace", &_37, _2);
		_23 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		ZEPHIR_INIT_NVAR(_5);
		zephir_call_method_cache(_5, _23, "getimagedelay", &_38);
		zephir_call_method_p1_cache_noret(image, "setimagedelay", &_39, _5);
		_26 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		ZEPHIR_INIT_NVAR(_6);
		ZVAL_LONG(_6, 48);
		ZEPHIR_INIT_NVAR(_7);
		ZVAL_LONG(_7, 0);
		ZEPHIR_INIT_NVAR(_10);
		ZVAL_LONG(_10, 0);
		zephir_call_method_p4_cache_noret(image, "compositeimage", &_40, _26, _6, _7, _10);
		ZEPHIR_INIT_NVAR(_6);
		zephir_call_method_cache(_6, image, "nextimage", &_41);
		ZEPHIR_INIT_NVAR(_7);
		zephir_call_method_cache(_7, reflection, "nextimage", &_42);
		if ((!zephir_is_true(_6) || !zephir_is_true(_7))) {
			break;
		}
	}
	zephir_call_method_noret(reflection, "destroy");
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
	zephir_call_method_noret(_1, "clear");
	_20 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
	zephir_call_method_noret(_20, "destroy");
	zephir_update_property_this(this_ptr, SL("_image"), image TSRMLS_CC);
	_23 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
	ZEPHIR_INIT_NVAR(_2);
	zephir_call_method(_2, _23, "getimagewidth");
	zephir_update_property_this(this_ptr, SL("_width"), _2 TSRMLS_CC);
	_26 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
	ZEPHIR_INIT_NVAR(_5);
	zephir_call_method(_5, _26, "getimageheight");
	zephir_update_property_this(this_ptr, SL("_height"), _5 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Phalcon_Image_Adapter_Imagick, _watermark) {

	zend_function *_7 = NULL, *_9 = NULL;
	zend_class_entry *_0;
	int offset_x, offset_y, opacity;
	zval *image, *offset_x_param = NULL, *offset_y_param = NULL, *opacity_param = NULL, *watermark, *_1, *_2 = NULL, *_3, *_4, *_5 = NULL, *_6 = NULL, *_8;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 4, 0, &image, &offset_x_param, &offset_y_param, &opacity_param);

		offset_x = zephir_get_intval(offset_x_param);
		offset_y = zephir_get_intval(offset_y_param);
		opacity = zephir_get_intval(opacity_param);


	opacity = (opacity / 100);
	ZEPHIR_INIT_VAR(watermark);
	_0 = zend_fetch_class(SL("Imagick"), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
	object_init_ex(watermark, _0);
	zephir_call_method_noret(watermark, "__construct");
	ZEPHIR_INIT_VAR(_1);
	zephir_call_method(_1, image, "render");
	zephir_call_method_p1_noret(watermark, "readimageblob", _1);
	ZEPHIR_INIT_VAR(_2);
	ZVAL_LONG(_2, opacity);
	zephir_call_method_p1_noret(watermark, "setimageopacity", _2);
	_3 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
	ZEPHIR_INIT_BNVAR(_2);
	ZVAL_LONG(_2, 0);
	zephir_call_method_p1_noret(_3, "setiteratorindex", _2);
	while (1) {
		_4 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		ZEPHIR_INIT_NVAR(_2);
		ZVAL_LONG(_2, 40);
		ZEPHIR_INIT_NVAR(_5);
		ZVAL_LONG(_5, offset_x);
		ZEPHIR_INIT_NVAR(_6);
		ZVAL_LONG(_6, offset_y);
		zephir_call_method_p4_cache_noret(_4, "compositeimage", &_7, watermark, _2, _5, _6);
		_8 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		ZEPHIR_INIT_NVAR(_2);
		zephir_call_method_cache(_2, _8, "nextimage", &_9);
		if (!(zephir_is_true(_2))) {
			break;
		}
	}
	zephir_call_method_noret(watermark, "clear");
	zephir_call_method_noret(watermark, "destroy");
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Phalcon_Image_Adapter_Imagick, _text) {

	zend_function *_11 = NULL, *_13 = NULL;
	zend_class_entry *_0, *_5;
	int offset_x, offset_y, opacity, r, g, b, size;
	zval *text_param = NULL, *offset_x_param = NULL, *offset_y_param = NULL, *opacity_param = NULL, *r_param = NULL, *g_param = NULL, *b_param = NULL, *size_param = NULL, *fontfile_param = NULL, *draw, *color, *pixel, *gravity, _1 = zval_used_for_init, _2, _3, _4, *_6 = NULL, *_7 = NULL, *_8, *_9, *_10 = NULL, *_12;
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
	ZEPHIR_INIT_VAR(pixel);
	_5 = zend_fetch_class(SL("ImagickPixel"), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
	object_init_ex(pixel, _5);
	zephir_call_method_p1_noret(pixel, "__construct", color);
	zephir_call_method_p1_noret(draw, "setfillcolor", pixel);
	if (fontfile && Z_STRLEN_P(fontfile)) {
		zephir_call_method_p1_noret(draw, "setfont", fontfile);
	}
	if (size) {
		ZEPHIR_INIT_VAR(_6);
		ZVAL_LONG(_6, size);
		zephir_call_method_p1_noret(draw, "setfontsize", _6);
	}
	if (opacity) {
		ZEPHIR_INIT_NVAR(_6);
		ZVAL_LONG(_6, opacity);
		zephir_call_method_p1_noret(draw, "setfillopacity", _6);
	}
	if ((offset_x < 0)) {
		ZEPHIR_SINIT_NVAR(_1);
		ZVAL_LONG(&_1, offset_x);
		ZEPHIR_INIT_NVAR(_6);
		zephir_call_func_p1(_6, "abs", &_1);
		offset_x = zephir_get_numberval(_6);
		ZEPHIR_INIT_VAR(gravity);
		if ((offset_y < 0)) {
			ZEPHIR_SINIT_NVAR(_1);
			ZVAL_LONG(&_1, offset_y);
			ZEPHIR_INIT_VAR(_7);
			zephir_call_func_p1(_7, "abs", &_1);
			offset_y = zephir_get_numberval(_7);
			ZVAL_LONG(gravity, 9);
		} else {
			ZVAL_LONG(gravity, 3);
		}
	}
	zephir_call_method_p1_noret(draw, "setgravity", gravity);
	_8 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
	ZEPHIR_INIT_NVAR(_6);
	ZVAL_LONG(_6, 0);
	zephir_call_method_p1_noret(_8, "setiteratorindex", _6);
	while (1) {
		_9 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		ZEPHIR_INIT_NVAR(_6);
		ZVAL_LONG(_6, offset_x);
		ZEPHIR_INIT_NVAR(_7);
		ZVAL_LONG(_7, offset_y);
		ZEPHIR_INIT_NVAR(_10);
		ZVAL_LONG(_10, 0);
		zephir_call_method_p5_cache_noret(_9, "annotateimage", &_11, draw, _6, _7, _10, text);
		_12 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		ZEPHIR_INIT_NVAR(_6);
		zephir_call_method_cache(_6, _12, "nextimage", &_13);
		if (!(zephir_is_true(_6))) {
			break;
		}
	}
	zephir_call_method_noret(draw, "destroy");
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Phalcon_Image_Adapter_Imagick, _mask) {

	zend_function *_5 = NULL, *_9 = NULL, *_11 = NULL;
	zend_class_entry *_0;
	zval *image, *mask, *_1, *_2, *_3 = NULL, *_4, *_6, *_7 = NULL, *_8 = NULL, *_10;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &image);



	ZEPHIR_INIT_VAR(mask);
	_0 = zend_fetch_class(SL("Imagick"), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
	object_init_ex(mask, _0);
	zephir_call_method_noret(mask, "__construct");
	ZEPHIR_INIT_VAR(_1);
	zephir_call_method(_1, image, "render");
	zephir_call_method_p1_noret(mask, "readimageblob", _1);
	_2 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_3);
	ZVAL_LONG(_3, 0);
	zephir_call_method_p1_noret(_2, "setiteratorindex", _3);
	while (1) {
		_4 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		ZEPHIR_INIT_NVAR(_3);
		ZVAL_LONG(_3, 1);
		zephir_call_method_p1_cache_noret(_4, "setimagematte", &_5, _3);
		_6 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		ZEPHIR_INIT_NVAR(_3);
		ZVAL_LONG(_3, 23);
		ZEPHIR_INIT_NVAR(_7);
		ZVAL_LONG(_7, 0);
		ZEPHIR_INIT_NVAR(_8);
		ZVAL_LONG(_8, 0);
		zephir_call_method_p4_cache_noret(_6, "compositeimage", &_9, mask, _3, _7, _8);
		_10 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		ZEPHIR_INIT_NVAR(_3);
		zephir_call_method_cache(_3, _10, "nextimage", &_11);
		if (!(zephir_is_true(_3))) {
			break;
		}
	}
	zephir_call_method_noret(mask, "clear");
	zephir_call_method_noret(mask, "destroy");
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Phalcon_Image_Adapter_Imagick, _background) {

	zend_function *_11 = NULL, *_12 = NULL, *_14 = NULL, *_15 = NULL, *_18 = NULL, *_20 = NULL, *_21 = NULL, *_24 = NULL, *_26 = NULL;
	zend_class_entry *_4, *_5, *_7;
	zval *r_param = NULL, *g_param = NULL, *b_param = NULL, *opacity_param = NULL, *background, *color, *pixel1, *pixel2, _0, _1, _2, _3, *_6 = NULL, *_8, *_9, *_10, *_13 = NULL, *_16 = NULL, *_17 = NULL, *_19, *_22, *_23 = NULL, *_25;
	int r, g, b, opacity;

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
	ZEPHIR_INIT_VAR(pixel1);
	_4 = zend_fetch_class(SL("ImagickPixel"), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
	object_init_ex(pixel1, _4);
	zephir_call_method_p1_noret(pixel1, "__construct", color);
	opacity = (opacity / 100);
	ZEPHIR_INIT_VAR(pixel2);
	_5 = zend_fetch_class(SL("ImagickPixel"), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
	object_init_ex(pixel2, _5);
	ZEPHIR_INIT_VAR(_6);
	ZVAL_STRING(_6, "transparent", 1);
	zephir_call_method_p1_noret(pixel2, "__construct", _6);
	ZEPHIR_INIT_VAR(background);
	_7 = zend_fetch_class(SL("Imagick"), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
	object_init_ex(background, _7);
	zephir_call_method_noret(background, "__construct");
	_8 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
	ZEPHIR_INIT_BNVAR(_6);
	ZVAL_LONG(_6, 0);
	zephir_call_method_p1_noret(_8, "setiteratorindex", _6);
	while (1) {
		_9 = zephir_fetch_nproperty_this(this_ptr, SL("_width"), PH_NOISY_CC);
		_10 = zephir_fetch_nproperty_this(this_ptr, SL("_height"), PH_NOISY_CC);
		zephir_call_method_p3_cache_noret(background, "newimage", &_11, _9, _10, pixel1);
		ZEPHIR_INIT_NVAR(_6);
		zephir_call_method_cache(_6, background, "getimagealphachannel", &_12);
		if (!(zephir_is_true(_6))) {
			ZEPHIR_INIT_NVAR(_13);
			ZVAL_LONG(_13, 8);
			zephir_call_method_p1_cache_noret(background, "setimagealphachannel", &_14, _13);
		}
		zephir_call_method_p1_cache_noret(background, "setimagebackgroundcolor", &_15, pixel2);
		ZEPHIR_INIT_NVAR(_13);
		ZVAL_LONG(_13, 7);
		ZEPHIR_INIT_NVAR(_16);
		ZVAL_LONG(_16, opacity);
		ZEPHIR_INIT_NVAR(_17);
		ZVAL_LONG(_17, 8);
		zephir_call_method_p3_cache_noret(background, "evaluateimage", &_18, _13, _16, _17);
		_19 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		ZEPHIR_INIT_NVAR(_13);
		zephir_call_method_cache(_13, _19, "getcolorspace", &_20);
		zephir_call_method_p1_cache_noret(background, "setcolorspace", &_21, _13);
		_22 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		ZEPHIR_INIT_NVAR(_16);
		ZVAL_LONG(_16, 28);
		ZEPHIR_INIT_NVAR(_17);
		ZVAL_LONG(_17, 0);
		ZEPHIR_INIT_NVAR(_23);
		ZVAL_LONG(_23, 0);
		zephir_call_method_p4_cache_noret(background, "compositeimage", &_24, _22, _16, _17, _23);
		_25 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		ZEPHIR_INIT_NVAR(_16);
		zephir_call_method_cache(_16, _25, "nextimage", &_26);
		if (!(zephir_is_true(_16))) {
			break;
		}
	}
	_9 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
	zephir_call_method_noret(_9, "clear");
	_10 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
	zephir_call_method_noret(_10, "destroy");
	zephir_update_property_this(this_ptr, SL("_image"), background TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Phalcon_Image_Adapter_Imagick, _blur) {

	zend_function *_4 = NULL, *_6 = NULL;
	zval *radius_param = NULL, *_0, *_1 = NULL, *_2, *_3 = NULL, *_5;
	int radius;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &radius_param);

		radius = zephir_get_intval(radius_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_LONG(_1, 0);
	zephir_call_method_p1_noret(_0, "setiteratorindex", _1);
	while (1) {
		_2 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		ZEPHIR_INIT_NVAR(_1);
		ZVAL_LONG(_1, radius);
		ZEPHIR_INIT_NVAR(_3);
		ZVAL_LONG(_3, 100);
		zephir_call_method_p2_cache_noret(_2, "blurimage", &_4, _1, _3);
		_5 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		ZEPHIR_INIT_NVAR(_1);
		zephir_call_method_cache(_1, _5, "nextimage", &_6);
		if (!(zephir_is_true(_1))) {
			break;
		}
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Phalcon_Image_Adapter_Imagick, _pixelate) {

	zend_function *_6 = NULL, *_10 = NULL, *_12 = NULL;
	zval *amount_param = NULL, *_0, *_1, *_2, *_3 = NULL, *_4, *_5 = NULL, *_7, *_8, *_9, *_11;
	int amount, width, height;

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
	while (1) {
		_4 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		ZEPHIR_INIT_NVAR(_3);
		ZVAL_LONG(_3, width);
		ZEPHIR_INIT_NVAR(_5);
		ZVAL_LONG(_5, height);
		zephir_call_method_p2_cache_noret(_4, "scaleimage", &_6, _3, _5);
		_7 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		_8 = zephir_fetch_nproperty_this(this_ptr, SL("_width"), PH_NOISY_CC);
		_9 = zephir_fetch_nproperty_this(this_ptr, SL("_height"), PH_NOISY_CC);
		zephir_call_method_p2_cache_noret(_7, "scaleimage", &_10, _8, _9);
		_11 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		ZEPHIR_INIT_NVAR(_3);
		zephir_call_method_cache(_3, _11, "nextimage", &_12);
		if (!(zephir_is_true(_3))) {
			break;
		}
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Phalcon_Image_Adapter_Imagick, _save) {

	int quality;
	zval *file_param = NULL, *quality_param = NULL, *ext, *fp, _0 = zval_used_for_init, *_1, *_2, *_3, *_4, *_5, *_6, *_7, *_8, *_9, *_10, *_11, *_12, *_13 = NULL, *_14;
	zval *file = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &file_param, &quality_param);

		zephir_get_strval(file, file_param);
		quality = zephir_get_intval(quality_param);


	ZEPHIR_SINIT_VAR(_0);
	ZVAL_LONG(&_0, 4);
	ZEPHIR_INIT_VAR(ext);
	zephir_call_func_p2(ext, "pathinfo", file, &_0);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
	zephir_call_method_p1_noret(_1, "setformat", ext);
	_2 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
	zephir_call_method_p1_noret(_2, "setimageformat", ext);
	_3 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_4);
	zephir_call_method(_4, _3, "getimagetype");
	zephir_update_property_this(this_ptr, SL("_type"), _4 TSRMLS_CC);
	_5 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_6);
	zephir_call_method(_6, _5, "getimageformat");
	ZEPHIR_INIT_VAR(_7);
	ZEPHIR_CONCAT_SV(_7, "image/", _6);
	zephir_update_property_this(this_ptr, SL("_mime"), _7 TSRMLS_CC);
	ZEPHIR_SINIT_NVAR(_0);
	ZVAL_STRING(&_0, "gif", 0);
	ZEPHIR_INIT_VAR(_8);
	zephir_call_func_p2(_8, "strcasecmp", ext, &_0);
	if (ZEPHIR_IS_LONG(_8, 0)) {
		_9 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		zephir_call_method_noret(_9, "optimizeimagelayers");
		ZEPHIR_SINIT_NVAR(_0);
		ZVAL_STRING(&_0, "w", 0);
		ZEPHIR_INIT_VAR(fp);
		zephir_call_func_p2(fp, "fopen", file, &_0);
		_10 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		zephir_call_method_p1_noret(_10, "writeimagesfile", fp);
		zephir_call_func_p1_noret("fclose", fp);
		RETURN_MM_NULL();
	} else {
		ZEPHIR_SINIT_NVAR(_0);
		ZVAL_STRING(&_0, "jpg", 0);
		ZEPHIR_INIT_VAR(_11);
		zephir_call_func_p2(_11, "strcasecmp", ext, &_0);
		ZEPHIR_SINIT_NVAR(_0);
		ZVAL_STRING(&_0, "jpeg", 0);
		ZEPHIR_INIT_VAR(_12);
		zephir_call_func_p2(_12, "strcasecmp", ext, &_0);
		if ((ZEPHIR_IS_LONG(_11, 0) || ZEPHIR_IS_LONG(_12, 0))) {
			_9 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
			ZEPHIR_INIT_VAR(_13);
			ZVAL_LONG(_13, 8);
			zephir_call_method_p1_noret(_9, "setimagecompression", _13);
		}
		_10 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		ZEPHIR_INIT_NVAR(_13);
		ZVAL_LONG(_13, quality);
		zephir_call_method_p1_noret(_10, "setimagecompressionquality", _13);
		_14 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		zephir_call_method_p1_noret(_14, "writeimage", file);
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Phalcon_Image_Adapter_Imagick, _render) {

	int quality;
	zval *ext_param = NULL, *quality_param = NULL, *image, *_0, *_1, *_2, _3 = zval_used_for_init, *_4, *_5, *_6, *_7 = NULL;
	zval *ext = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &ext_param, &quality_param);

		zephir_get_strval(ext, ext_param);
		quality = zephir_get_intval(quality_param);


	image = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
	zephir_call_method_p1_noret(image, "setformat", ext);
	zephir_call_method_p1_noret(image, "setimageformat", ext);
	ZEPHIR_INIT_VAR(_0);
	zephir_call_method(_0, image, "getimagetype");
	zephir_update_property_this(this_ptr, SL("_type"), _0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_1);
	zephir_call_method(_1, image, "getimageformat");
	ZEPHIR_INIT_VAR(_2);
	ZEPHIR_CONCAT_SV(_2, "image/", _1);
	zephir_update_property_this(this_ptr, SL("_mime"), _2 TSRMLS_CC);
	ZEPHIR_SINIT_VAR(_3);
	ZVAL_STRING(&_3, "gif", 0);
	ZEPHIR_INIT_VAR(_4);
	zephir_call_func_p2(_4, "strcasecmp", ext, &_3);
	if (ZEPHIR_IS_LONG(_4, 0)) {
		zephir_call_method_noret(image, "optimizeimagelayers");
		zephir_call_method(return_value, image, "getimagesblob");
		RETURN_MM();
	} else {
		ZEPHIR_SINIT_NVAR(_3);
		ZVAL_STRING(&_3, "jpg", 0);
		ZEPHIR_INIT_VAR(_5);
		zephir_call_func_p2(_5, "strcasecmp", ext, &_3);
		ZEPHIR_SINIT_NVAR(_3);
		ZVAL_STRING(&_3, "jpeg", 0);
		ZEPHIR_INIT_VAR(_6);
		zephir_call_func_p2(_6, "strcasecmp", ext, &_3);
		if ((ZEPHIR_IS_LONG(_5, 0) || ZEPHIR_IS_LONG(_6, 0))) {
			ZEPHIR_INIT_VAR(_7);
			ZVAL_LONG(_7, 8);
			zephir_call_method_p1_noret(image, "setimagecompression", _7);
		}
		ZEPHIR_INIT_NVAR(_7);
		ZVAL_LONG(_7, quality);
		zephir_call_method_p1_noret(image, "setimagecompressionquality", _7);
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Phalcon_Image_Adapter_Imagick, __destruct) {

	zval *image;

	ZEPHIR_MM_GROW();

	image = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
	if (zephir_is_true(image)) {
		zephir_call_method_noret(image, "clear");
		zephir_call_method_noret(image, "destroy");
	}
	ZEPHIR_MM_RESTORE();

}

