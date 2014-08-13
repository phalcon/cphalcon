
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
#include "kernel/exception.h"
#include "kernel/memory.h"
#include "kernel/operators.h"
#include "kernel/fcall.h"
#include "kernel/string.h"
#include "kernel/array.h"


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
ZEPHIR_INIT_CLASS(Phalcon_Image_Adapter) {

	ZEPHIR_REGISTER_CLASS(Phalcon\\Image, Adapter, phalcon, image_adapter, phalcon_image_adapter_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	zend_declare_property_null(phalcon_image_adapter_ce, SL("_image"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_image_adapter_ce, SL("_file"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_image_adapter_ce, SL("_realpath"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_image_adapter_ce, SL("_width"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_image_adapter_ce, SL("_height"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_image_adapter_ce, SL("_type"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_image_adapter_ce, SL("_mime"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_bool(phalcon_image_adapter_ce, SL("_checked"), 0, ZEND_ACC_PROTECTED|ZEND_ACC_STATIC TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(Phalcon_Image_Adapter, getImage) {


	RETURN_MEMBER(this_ptr, "_image");

}

PHP_METHOD(Phalcon_Image_Adapter, getRealpath) {


	RETURN_MEMBER(this_ptr, "_realpath");

}

PHP_METHOD(Phalcon_Image_Adapter, getWidth) {


	RETURN_MEMBER(this_ptr, "_width");

}

PHP_METHOD(Phalcon_Image_Adapter, getHeight) {


	RETURN_MEMBER(this_ptr, "_height");

}

PHP_METHOD(Phalcon_Image_Adapter, getType) {


	RETURN_MEMBER(this_ptr, "_type");

}

PHP_METHOD(Phalcon_Image_Adapter, getMime) {


	RETURN_MEMBER(this_ptr, "_mime");

}

/**
 * Resize the image to the given size
 *
 * @param int width
 * @param int height
 * @param int master
 * @return Phalcon\Image\Adapter
 */
PHP_METHOD(Phalcon_Image_Adapter, resize) {

	zephir_nts_static zephir_fcall_cache_entry *_10 = NULL, *_12 = NULL;
	zend_bool _0, _4;
	double ratio;
	zval *width_param = NULL, *height_param = NULL, *master_param = NULL, *_1 = NULL, *_2, *_3, *_5, *_6, *_7 = NULL, _8 = zval_used_for_init, *_9 = NULL, *_11 = NULL, *_13 = NULL, *_14 = NULL, *_15, *_16;
	int width, height, master, ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 3, &width_param, &height_param, &master_param);

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
	if (!master_param) {
		master = 7;
	} else {
		master = zephir_get_intval(master_param);
	}


	if (master == 7) {
		_0 = !width;
		if (!(_0)) {
			_0 = !height;
		}
		if (_0) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_image_exception_ce, "width and height must be specified", "phalcon/image/adapter.zep", 57);
			return;
		}
	} else {
		if (master == 4) {
			_0 = !width;
			if (!(_0)) {
				_0 = !height;
			}
			if (_0) {
				ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_image_exception_ce, "width and height must be specified", "phalcon/image/adapter.zep", 65);
				return;
			}
			ZEPHIR_INIT_VAR(_1);
			_2 = zephir_fetch_nproperty_this(this_ptr, SL("_width"), PH_NOISY_CC);
			_3 = zephir_fetch_nproperty_this(this_ptr, SL("_height"), PH_NOISY_CC);
			if (((zephir_get_numberval(_2) / width)) > ((zephir_get_numberval(_3) / height))) {
				ZEPHIR_INIT_NVAR(_1);
				ZVAL_LONG(_1, 2);
			} else {
				ZEPHIR_INIT_NVAR(_1);
				ZVAL_LONG(_1, 3);
			}
			master = zephir_get_numberval(_1);
		}
		if (master == 5) {
			_4 = !width;
			if (!(_4)) {
				_4 = !height;
			}
			if (_4) {
				ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_image_exception_ce, "width and height must be specified", "phalcon/image/adapter.zep", 74);
				return;
			}
			ZEPHIR_INIT_LNVAR(_1);
			_2 = zephir_fetch_nproperty_this(this_ptr, SL("_width"), PH_NOISY_CC);
			_3 = zephir_fetch_nproperty_this(this_ptr, SL("_height"), PH_NOISY_CC);
			if (((zephir_get_numberval(_2) / width)) > ((zephir_get_numberval(_3) / height))) {
				ZEPHIR_INIT_NVAR(_1);
				ZVAL_LONG(_1, 3);
			} else {
				ZEPHIR_INIT_NVAR(_1);
				ZVAL_LONG(_1, 2);
			}
			master = zephir_get_numberval(_1);
		}
		do {
			if (master == 2) {
				if (!(width)) {
					ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_image_exception_ce, "width must be specified", "phalcon/image/adapter.zep", 84);
					return;
				}
				_2 = zephir_fetch_nproperty_this(this_ptr, SL("_height"), PH_NOISY_CC);
				_3 = zephir_fetch_nproperty_this(this_ptr, SL("_width"), PH_NOISY_CC);
				height = ((zephir_get_numberval(_2) * width) / zephir_get_numberval(_3));
				break;
			}
			if (master == 3) {
				if (!(height)) {
					ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_image_exception_ce, "height must be specified", "phalcon/image/adapter.zep", 91);
					return;
				}
				_2 = zephir_fetch_nproperty_this(this_ptr, SL("_width"), PH_NOISY_CC);
				_3 = zephir_fetch_nproperty_this(this_ptr, SL("_height"), PH_NOISY_CC);
				width = ((zephir_get_numberval(_2) * height) / zephir_get_numberval(_3));
				break;
			}
			if (master == 6) {
				_4 = !width;
				if (!(_4)) {
					_4 = !height;
				}
				if (_4) {
					ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_image_exception_ce, "width and height must be specified", "phalcon/image/adapter.zep", 99);
					return;
				}
				_2 = zephir_fetch_nproperty_this(this_ptr, SL("_width"), PH_NOISY_CC);
				_3 = zephir_fetch_nproperty_this(this_ptr, SL("_height"), PH_NOISY_CC);
				ZEPHIR_INIT_LNVAR(_1);
				div_function(_1, _2, _3 TSRMLS_CC);
				ratio = zephir_get_numberval(_1);
				if (((width / height)) > ratio) {
					_2 = zephir_fetch_nproperty_this(this_ptr, SL("_height"), PH_NOISY_CC);
					_3 = zephir_fetch_nproperty_this(this_ptr, SL("_width"), PH_NOISY_CC);
					height = ((zephir_get_numberval(_2) * width) / zephir_get_numberval(_3));
				} else {
					_5 = zephir_fetch_nproperty_this(this_ptr, SL("_width"), PH_NOISY_CC);
					_6 = zephir_fetch_nproperty_this(this_ptr, SL("_height"), PH_NOISY_CC);
					width = ((zephir_get_numberval(_5) * height) / zephir_get_numberval(_6));
				}
				break;
			}
			if (master == 1) {
				if (!(width)) {
					ZEPHIR_OBS_VAR(_7);
					zephir_read_property_this(&_7, this_ptr, SL("_width"), PH_NOISY_CC);
					width = zephir_get_intval(_7);
				}
				if (!(height)) {
					ZEPHIR_OBS_NVAR(_7);
					zephir_read_property_this(&_7, this_ptr, SL("_height"), PH_NOISY_CC);
					width = zephir_get_intval(_7);
				}
				break;
			}
		} while(0);

	}
	ZEPHIR_SINIT_VAR(_8);
	ZVAL_LONG(&_8, width);
	ZEPHIR_CALL_FUNCTION(&_9, "round", &_10, &_8);
	zephir_check_call_status();
	ZEPHIR_SINIT_NVAR(_8);
	ZVAL_LONG(&_8, 1);
	ZEPHIR_CALL_FUNCTION(&_11, "max", &_12, _9, &_8);
	zephir_check_call_status();
	width = zephir_get_intval(_11);
	ZEPHIR_SINIT_NVAR(_8);
	ZVAL_LONG(&_8, height);
	ZEPHIR_CALL_FUNCTION(&_13, "round", &_10, &_8);
	zephir_check_call_status();
	ZEPHIR_SINIT_NVAR(_8);
	ZVAL_LONG(&_8, 1);
	ZEPHIR_CALL_FUNCTION(&_14, "max", &_12, _13, &_8);
	zephir_check_call_status();
	height = zephir_get_intval(_14);
	ZEPHIR_INIT_VAR(_15);
	ZVAL_LONG(_15, width);
	ZEPHIR_INIT_VAR(_16);
	ZVAL_LONG(_16, height);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "_resize", NULL, _15, _16);
	zephir_check_call_status();
	RETURN_THIS();

}

/**
 * Crop an image to the given size
 *
 * @param int width
 * @param int height
 * @param int offset_x
 * @param int offset_y
 * @return Phalcon\Image\Adapter
 */
PHP_METHOD(Phalcon_Image_Adapter, crop) {

	zval *width_param = NULL, *height_param = NULL, *offset_x_param = NULL, *offset_y_param = NULL, *_0, *_1, *_2 = NULL, *_3, *_4, *_5, *_6;
	int width, height, offset_x, offset_y, ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 2, &width_param, &height_param, &offset_x_param, &offset_y_param);

	width = zephir_get_intval(width_param);
	height = zephir_get_intval(height_param);
	if (!offset_x_param) {
		offset_x = 0;
	} else {
		offset_x = zephir_get_intval(offset_x_param);
	}
	if (!offset_y_param) {
		offset_y = 0;
	} else {
		offset_y = zephir_get_intval(offset_y_param);
	}


	if (!(offset_x)) {
		_0 = zephir_fetch_nproperty_this(this_ptr, SL("_width"), PH_NOISY_CC);
		offset_x = ((((zephir_get_numberval(_0) - width)) / 2));
	} else {
		if (offset_x < 0) {
			_0 = zephir_fetch_nproperty_this(this_ptr, SL("_width"), PH_NOISY_CC);
			offset_x = ((zephir_get_numberval(_0) - width) + offset_x);
		}
		_1 = zephir_fetch_nproperty_this(this_ptr, SL("_width"), PH_NOISY_CC);
		if (ZEPHIR_LT_LONG(_1, offset_x)) {
			ZEPHIR_OBS_VAR(_2);
			zephir_read_property_this(&_2, this_ptr, SL("_width"), PH_NOISY_CC);
			offset_x = zephir_get_intval(_2);
		}
	}
	if (!(offset_y)) {
		_0 = zephir_fetch_nproperty_this(this_ptr, SL("_height"), PH_NOISY_CC);
		offset_y = ((((zephir_get_numberval(_0) - height)) / 2));
	} else {
		if (offset_y < 0) {
			_0 = zephir_fetch_nproperty_this(this_ptr, SL("_height"), PH_NOISY_CC);
			offset_y = ((zephir_get_numberval(_0) - height) + offset_y);
		}
		_1 = zephir_fetch_nproperty_this(this_ptr, SL("_height"), PH_NOISY_CC);
		if (ZEPHIR_LT_LONG(_1, offset_y)) {
			ZEPHIR_OBS_NVAR(_2);
			zephir_read_property_this(&_2, this_ptr, SL("_height"), PH_NOISY_CC);
			offset_y = zephir_get_intval(_2);
		}
	}
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_width"), PH_NOISY_CC);
	if (width > ((zephir_get_numberval(_0) - offset_x))) {
		_1 = zephir_fetch_nproperty_this(this_ptr, SL("_width"), PH_NOISY_CC);
		width = (zephir_get_numberval(_1) - offset_x);
	}
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_height"), PH_NOISY_CC);
	if (height > ((zephir_get_numberval(_0) - offset_y))) {
		_1 = zephir_fetch_nproperty_this(this_ptr, SL("_height"), PH_NOISY_CC);
		height = (zephir_get_numberval(_1) - offset_y);
	}
	ZEPHIR_INIT_VAR(_3);
	ZVAL_LONG(_3, width);
	ZEPHIR_INIT_VAR(_4);
	ZVAL_LONG(_4, height);
	ZEPHIR_INIT_VAR(_5);
	ZVAL_LONG(_5, offset_y);
	ZEPHIR_INIT_VAR(_6);
	ZVAL_LONG(_6, offset_y);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "_crop", NULL, _3, _4, _5, _6);
	zephir_check_call_status();
	RETURN_THIS();

}

/**
 * Rotate the image by a given amount
 *
 * @param int degrees
 * @return Phalcon\Image\Adapter
 */
PHP_METHOD(Phalcon_Image_Adapter, rotate) {

	zval *degrees_param = NULL, *_0;
	int degrees, ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &degrees_param);

	degrees = zephir_get_intval(degrees_param);


	if (degrees > 180) {
		degrees %= 360;
		if (degrees > 180) {
			degrees -= 360;
		}
	} else {
		while (1) {
			if (!(degrees < -180)) {
				break;
			}
			degrees += 360;
		}
	}
	ZEPHIR_INIT_VAR(_0);
	ZVAL_LONG(_0, degrees);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "_rotate", NULL, _0);
	zephir_check_call_status();
	RETURN_THIS();

}

/**
 * Flip the image along the horizontal or vertical axis
 *
 * @param int direction
 * @return Phalcon\Image\Adapter
 */
PHP_METHOD(Phalcon_Image_Adapter, flip) {

	zend_bool _0;
	zval *direction_param = NULL, *_1;
	int direction, ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &direction_param);

	direction = zephir_get_intval(direction_param);


	_0 = direction != 11;
	if (_0) {
		_0 = direction != 12;
	}
	if (_0) {
		direction = 11;
	}
	ZEPHIR_INIT_VAR(_1);
	ZVAL_LONG(_1, direction);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "_flip", NULL, _1);
	zephir_check_call_status();
	RETURN_THIS();

}

/**
 * Sharpen the image by a given amount
 *
 * @param int amount
 * @return Phalcon\Image\Adapter
 */
PHP_METHOD(Phalcon_Image_Adapter, sharpen) {

	zval *amount_param = NULL, *_0;
	int amount, ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &amount_param);

	amount = zephir_get_intval(amount_param);


	if (amount > 100) {
		amount = 100;
	} else {
		if (amount < 1) {
			amount = 1;
		}
	}
	ZEPHIR_INIT_VAR(_0);
	ZVAL_LONG(_0, amount);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "_sharpen", NULL, _0);
	zephir_check_call_status();
	RETURN_THIS();

}

/**
 * Add a reflection to an image
 *
 * @param int height
 * @param int opacity
 * @param boolean fade_in
 * @return Phalcon\Image\Adapter
 */
PHP_METHOD(Phalcon_Image_Adapter, reflection) {

	zend_bool fade_in, _0;
	zval *height_param = NULL, *opacity_param = NULL, *fade_in_param = NULL, *_1, *_2, *_3, *_4;
	int height, opacity, ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &height_param, &opacity_param, &fade_in_param);

	height = zephir_get_intval(height_param);
	if (!opacity_param) {
		opacity = 100;
	} else {
		opacity = zephir_get_intval(opacity_param);
	}
	if (!fade_in_param) {
		fade_in = 0;
	} else {
		fade_in = zephir_get_boolval(fade_in_param);
	}


	_0 = height <= 0;
	if (!(_0)) {
		_1 = zephir_fetch_nproperty_this(this_ptr, SL("_height"), PH_NOISY_CC);
		_0 = ZEPHIR_LT_LONG(_1, height);
	}
	if (_0) {
		ZEPHIR_OBS_VAR(_2);
		zephir_read_property_this(&_2, this_ptr, SL("_height"), PH_NOISY_CC);
		height = zephir_get_intval(_2);
	}
	if (opacity < 0) {
		opacity = 0;
	} else {
		if (opacity > 100) {
			opacity = 100;
		}
	}
	ZEPHIR_INIT_VAR(_3);
	ZVAL_LONG(_3, height);
	ZEPHIR_INIT_VAR(_4);
	ZVAL_LONG(_4, opacity);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "_reflection", NULL, _3, _4, (fade_in ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false)));
	zephir_check_call_status();
	RETURN_THIS();

}

/**
 * Add a watermark to an image with a specified opacity
 *
 * @param Phalcon\Image\Adapter watermark
 * @param int offset_x
 * @param int offset_y
 * @param int opacity
 * @return Phalcon\Image\Adapter
 */
PHP_METHOD(Phalcon_Image_Adapter, watermark) {

	int offset_x, offset_y, opacity, tmp, ZEPHIR_LAST_CALL_STATUS;
	zval *watermark, *offset_x_param = NULL, *offset_y_param = NULL, *opacity_param = NULL, *_0, *_1 = NULL, *_2, *_3, *_4, *_5, *_6;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 3, &watermark, &offset_x_param, &offset_y_param, &opacity_param);

	if (!offset_x_param) {
		offset_x = 0;
	} else {
		offset_x = zephir_get_intval(offset_x_param);
	}
	if (!offset_y_param) {
		offset_y = 0;
	} else {
		offset_y = zephir_get_intval(offset_y_param);
	}
	if (!opacity_param) {
		opacity = 100;
	} else {
		opacity = zephir_get_intval(opacity_param);
	}


	if (!(zephir_instance_of_ev(watermark, phalcon_image_adapter_ce TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Parameter 'watermark' must be an instance of 'Phalcon\\Image\\Adapter'", "", 0);
		return;
	}
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_width"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&_1, watermark, "getwidth",  NULL);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_2);
	zephir_sub_function(_2, _0, _1 TSRMLS_CC);
	tmp = zephir_get_numberval(_2);
	if (offset_x < 0) {
		offset_x = 0;
	} else {
		if (offset_x > tmp) {
			offset_x = tmp;
		}
	}
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_height"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&_1, watermark, "getheight",  NULL);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_3);
	zephir_sub_function(_3, _0, _1 TSRMLS_CC);
	tmp = zephir_get_numberval(_3);
	if (offset_y < 0) {
		offset_y = 0;
	} else {
		if (offset_y > tmp) {
			offset_y = tmp;
		}
	}
	if (opacity < 0) {
		opacity = 0;
	} else {
		if (opacity > 100) {
			opacity = 100;
		}
	}
	ZEPHIR_INIT_VAR(_4);
	ZVAL_LONG(_4, offset_x);
	ZEPHIR_INIT_VAR(_5);
	ZVAL_LONG(_5, offset_y);
	ZEPHIR_INIT_VAR(_6);
	ZVAL_LONG(_6, opacity);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "_watermark", NULL, watermark, _4, _5, _6);
	zephir_check_call_status();
	RETURN_THIS();

}

/**
 * Add a text to an image with a specified opacity
 *
 * @param string text
 * @param int offset_x
 * @param int offset_y
 * @param int opacity
 * @param string color
 * @param int size
 * @param string fontfile
 * @return Phalcon\Image\Adapter
 */
PHP_METHOD(Phalcon_Image_Adapter, text) {

	zephir_nts_static zephir_fcall_cache_entry *_4 = NULL, *_8 = NULL, *_9 = NULL, *_10 = NULL;
	zend_bool _0;
	int offset_x, offset_y, opacity, size, ZEPHIR_LAST_CALL_STATUS;
	zval *text_param = NULL, *offset_x_param = NULL, *offset_y_param = NULL, *opacity_param = NULL, *color_param = NULL, *size_param = NULL, *fontfile_param = NULL, *colors = NULL, _1 = zval_used_for_init, _2, *_3 = NULL, *_5 = NULL, *_6 = NULL, *_7 = NULL, *_11, *_12, *_13, *_14, *_15;
	zval *text = NULL, *color = NULL, *fontfile = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 6, &text_param, &offset_x_param, &offset_y_param, &opacity_param, &color_param, &size_param, &fontfile_param);

	zephir_get_strval(text, text_param);
	if (!offset_x_param) {
		offset_x = 0;
	} else {
		offset_x = zephir_get_intval(offset_x_param);
	}
	if (!offset_y_param) {
		offset_y = 0;
	} else {
		offset_y = zephir_get_intval(offset_y_param);
	}
	if (!opacity_param) {
		opacity = 100;
	} else {
		opacity = zephir_get_intval(opacity_param);
	}
	if (!color_param) {
		ZEPHIR_INIT_VAR(color);
		ZVAL_STRING(color, "000000", 1);
	} else {
		zephir_get_strval(color, color_param);
	}
	if (!size_param) {
		size = 12;
	} else {
		size = zephir_get_intval(size_param);
	}
	if (!fontfile_param) {
		ZEPHIR_INIT_VAR(fontfile);
		ZVAL_EMPTY_STRING(fontfile);
	} else {
		zephir_get_strval(fontfile, fontfile_param);
	}


	if (opacity < 0) {
		opacity = 0;
	} else {
		if (opacity > 100) {
			opacity = 100;
		}
	}
	_0 = zephir_fast_strlen_ev(color) > 1;
	if (_0) {
		ZEPHIR_SINIT_VAR(_1);
		ZVAL_LONG(&_1, 0);
		ZEPHIR_SINIT_VAR(_2);
		ZVAL_LONG(&_2, 1);
		ZEPHIR_CALL_FUNCTION(&_3, "substr", &_4, color, &_1, &_2);
		zephir_check_call_status();
		_0 = ZEPHIR_IS_STRING_IDENTICAL(_3, "#");
	}
	if (_0) {
		ZEPHIR_SINIT_NVAR(_1);
		ZVAL_LONG(&_1, 1);
		ZEPHIR_CALL_FUNCTION(&_5, "substr", &_4, color, &_1);
		zephir_check_call_status();
		zephir_get_strval(color, _5);
	}
	if (zephir_fast_strlen_ev(color) == 3) {
		ZEPHIR_INIT_VAR(_6);
		ZVAL_STRING(_6, "/./", 0);
		ZEPHIR_INIT_VAR(_7);
		ZVAL_STRING(_7, "$0$0", 0);
		ZEPHIR_CALL_FUNCTION(&_5, "preg_replace", &_8, _6, _7, color);
		zephir_check_temp_parameter(_6);
		zephir_check_temp_parameter(_7);
		zephir_check_call_status();
		zephir_get_strval(color, _5);
	}
	ZEPHIR_SINIT_NVAR(_1);
	ZVAL_LONG(&_1, 2);
	ZEPHIR_CALL_FUNCTION(&_5, "str_split", &_9, color, &_1);
	zephir_check_call_status();
	ZEPHIR_SINIT_NVAR(_1);
	ZVAL_STRING(&_1, "hexdec", 0);
	ZEPHIR_CALL_FUNCTION(&colors, "array_map", &_10, &_1, _5);
	zephir_check_call_status();
	zephir_array_fetch_long(&_11, colors, 0, PH_NOISY | PH_READONLY, "phalcon/image/adapter.zep", 346 TSRMLS_CC);
	zephir_array_fetch_long(&_12, colors, 1, PH_NOISY | PH_READONLY, "phalcon/image/adapter.zep", 346 TSRMLS_CC);
	zephir_array_fetch_long(&_13, colors, 2, PH_NOISY | PH_READONLY, "phalcon/image/adapter.zep", 346 TSRMLS_CC);
	ZEPHIR_INIT_NVAR(_6);
	ZVAL_LONG(_6, offset_x);
	ZEPHIR_INIT_NVAR(_7);
	ZVAL_LONG(_7, offset_y);
	ZEPHIR_INIT_VAR(_14);
	ZVAL_LONG(_14, opacity);
	ZEPHIR_INIT_VAR(_15);
	ZVAL_LONG(_15, size);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "_text", NULL, text, _6, _7, _14, _11, _12, _13, _15, fontfile);
	zephir_check_call_status();
	RETURN_THIS();

}

/**
 * Composite one image onto another
 *
 * @param Phalcon\Image\Adapter watermark
 * @return Phalcon\Image\Adapter
 */
PHP_METHOD(Phalcon_Image_Adapter, mask) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *watermark;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &watermark);



	if (!(zephir_instance_of_ev(watermark, phalcon_image_adapter_ce TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Parameter 'watermark' must be an instance of 'Phalcon\\Image\\Adapter'", "", 0);
		return;
	}
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "_mask", NULL, watermark);
	zephir_check_call_status();
	RETURN_THIS();

}

/**
 * Set the background color of an image
 *
 * @param string color
 * @param int opacity
 * @return Phalcon\Image\Adapter
 */
PHP_METHOD(Phalcon_Image_Adapter, background) {

	zephir_nts_static zephir_fcall_cache_entry *_4 = NULL, *_8 = NULL, *_9 = NULL, *_10 = NULL;
	zend_bool _0;
	int opacity, ZEPHIR_LAST_CALL_STATUS;
	zval *color_param = NULL, *opacity_param = NULL, *colors = NULL, _1 = zval_used_for_init, _2, *_3 = NULL, *_5 = NULL, *_6 = NULL, *_7, *_11, *_12, *_13;
	zval *color = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &color_param, &opacity_param);

	zephir_get_strval(color, color_param);
	ZEPHIR_SEPARATE_PARAM(color);
	if (!opacity_param) {
		opacity = 100;
	} else {
		opacity = zephir_get_intval(opacity_param);
	}


	_0 = zephir_fast_strlen_ev(color) > 1;
	if (_0) {
		ZEPHIR_SINIT_VAR(_1);
		ZVAL_LONG(&_1, 0);
		ZEPHIR_SINIT_VAR(_2);
		ZVAL_LONG(&_2, 1);
		ZEPHIR_CALL_FUNCTION(&_3, "substr", &_4, color, &_1, &_2);
		zephir_check_call_status();
		_0 = ZEPHIR_IS_STRING_IDENTICAL(_3, "#");
	}
	if (_0) {
		ZEPHIR_SINIT_NVAR(_1);
		ZVAL_LONG(&_1, 1);
		ZEPHIR_CALL_FUNCTION(&_5, "substr", &_4, color, &_1);
		zephir_check_call_status();
		zephir_get_strval(color, _5);
	}
	if (zephir_fast_strlen_ev(color) == 3) {
		ZEPHIR_INIT_VAR(_6);
		ZVAL_STRING(_6, "/./", 0);
		ZEPHIR_INIT_VAR(_7);
		ZVAL_STRING(_7, "$0$0", 0);
		ZEPHIR_CALL_FUNCTION(&_5, "preg_replace", &_8, _6, _7, color);
		zephir_check_temp_parameter(_6);
		zephir_check_temp_parameter(_7);
		zephir_check_call_status();
		zephir_get_strval(color, _5);
	}
	ZEPHIR_SINIT_NVAR(_1);
	ZVAL_LONG(&_1, 2);
	ZEPHIR_CALL_FUNCTION(&_5, "str_split", &_9, color, &_1);
	zephir_check_call_status();
	ZEPHIR_SINIT_NVAR(_1);
	ZVAL_STRING(&_1, "hexdec", 0);
	ZEPHIR_CALL_FUNCTION(&colors, "array_map", &_10, &_1, _5);
	zephir_check_call_status();
	zephir_array_fetch_long(&_11, colors, 0, PH_NOISY | PH_READONLY, "phalcon/image/adapter.zep", 384 TSRMLS_CC);
	zephir_array_fetch_long(&_12, colors, 1, PH_NOISY | PH_READONLY, "phalcon/image/adapter.zep", 384 TSRMLS_CC);
	zephir_array_fetch_long(&_13, colors, 2, PH_NOISY | PH_READONLY, "phalcon/image/adapter.zep", 384 TSRMLS_CC);
	ZEPHIR_INIT_NVAR(_6);
	ZVAL_LONG(_6, opacity);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "_background", NULL, _11, _12, _13, _6);
	zephir_check_call_status();
	RETURN_THIS();

}

/**
 * Blur image
 *
 * @param int radius
 * @return Phalcon\Image\Adapter
 */
PHP_METHOD(Phalcon_Image_Adapter, blur) {

	zval *radius_param = NULL, *_0;
	int radius, ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &radius_param);

	radius = zephir_get_intval(radius_param);


	if (radius < 1) {
		radius = 1;
	} else {
		if (radius > 100) {
			radius = 100;
		}
	}
	ZEPHIR_INIT_VAR(_0);
	ZVAL_LONG(_0, radius);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "_blur", NULL, _0);
	zephir_check_call_status();
	RETURN_THIS();

}

/**
 * Pixelate image
 *
 * @param int amount
 * @return Phalcon\Image\Adapter
 */
PHP_METHOD(Phalcon_Image_Adapter, pixelate) {

	zval *amount_param = NULL, *_0;
	int amount, ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &amount_param);

	amount = zephir_get_intval(amount_param);


	if (amount < 2) {
		amount = 2;
	}
	ZEPHIR_INIT_VAR(_0);
	ZVAL_LONG(_0, amount);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "_pixelate", NULL, _0);
	zephir_check_call_status();
	RETURN_THIS();

}

/**
 * Save the image
 *
 * @param string file
 * @param int quality
 * @return Phalcon\Image\Adapter
 */
PHP_METHOD(Phalcon_Image_Adapter, save) {

	int quality, ZEPHIR_LAST_CALL_STATUS;
	zval *file_param = NULL, *quality_param = NULL, *_0, *_2;
	zval *file = NULL, *_1 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &file_param, &quality_param);

	if (!file_param) {
		ZEPHIR_INIT_VAR(file);
		ZVAL_EMPTY_STRING(file);
	} else {
		zephir_get_strval(file, file_param);
	}
	if (!quality_param) {
		quality = 100;
	} else {
		quality = zephir_get_intval(quality_param);
	}


	if (!(file && Z_STRLEN_P(file))) {
		ZEPHIR_OBS_VAR(_0);
		zephir_read_property_this(&_0, this_ptr, SL("_realpath"), PH_NOISY_CC);
		zephir_get_strval(_1, _0);
		ZEPHIR_CPY_WRT(file, _1);
	}
	if (quality < 1) {
		quality = 1;
	} else {
		if (quality > 100) {
			quality = 100;
		}
	}
	ZEPHIR_INIT_VAR(_2);
	ZVAL_LONG(_2, quality);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "_save", NULL, file, _2);
	zephir_check_call_status();
	RETURN_THIS();

}

/**
 * Render the image and return the binary string
 *
 * @param string ext
 * @param int quality
 * @return string
 */
PHP_METHOD(Phalcon_Image_Adapter, render) {

	zephir_nts_static zephir_fcall_cache_entry *_3 = NULL;
	int quality, ZEPHIR_LAST_CALL_STATUS;
	zval *ext_param = NULL, *quality_param = NULL, *_0, _1, *_2 = NULL, *_5;
	zval *ext = NULL, *_4 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &ext_param, &quality_param);

	if (!ext_param) {
		ZEPHIR_INIT_VAR(ext);
		ZVAL_EMPTY_STRING(ext);
	} else {
		zephir_get_strval(ext, ext_param);
	}
	if (!quality_param) {
		quality = 100;
	} else {
		quality = zephir_get_intval(quality_param);
	}


	if (!(ext && Z_STRLEN_P(ext))) {
		_0 = zephir_fetch_nproperty_this(this_ptr, SL("_file"), PH_NOISY_CC);
		ZEPHIR_SINIT_VAR(_1);
		ZVAL_LONG(&_1, 4);
		ZEPHIR_CALL_FUNCTION(&_2, "pathinfo", &_3, _0, &_1);
		zephir_check_call_status();
		zephir_get_strval(_4, _2);
		ZEPHIR_CPY_WRT(ext, _4);
	}
	if (ZEPHIR_IS_EMPTY(ext)) {
		ZEPHIR_INIT_NVAR(ext);
		ZVAL_STRING(ext, "png", 1);
	}
	if (quality < 1) {
		quality = 1;
	} else {
		if (quality > 100) {
			quality = 100;
		}
	}
	ZEPHIR_INIT_VAR(_5);
	ZVAL_LONG(_5, quality);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "_render", NULL, ext, _5);
	zephir_check_call_status();
	RETURN_MM();

}

