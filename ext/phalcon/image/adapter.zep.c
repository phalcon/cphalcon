
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
#include "kernel/math.h"
#include "kernel/fcall.h"
#include "kernel/string.h"
#include "kernel/array.h"


/**
 * Phalcon\Image\Adapter
 *
 * All image adapters must use this class
 */
ZEPHIR_INIT_CLASS(Phalcon_Image_Adapter) {

	ZEPHIR_REGISTER_CLASS(Phalcon\\Image, Adapter, phalcon, image_adapter, phalcon_image_adapter_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	zend_declare_property_null(phalcon_image_adapter_ce, SL("_image"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_image_adapter_ce, SL("_file"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_image_adapter_ce, SL("_realpath"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * Image width
	 *
	 * @var int
	 */
	zend_declare_property_null(phalcon_image_adapter_ce, SL("_width"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * Image height
	 *
	 * @var int
	 */
	zend_declare_property_null(phalcon_image_adapter_ce, SL("_height"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * Image type
	 *
	 * Driver dependent
	 *
	 * @var int
	 */
	zend_declare_property_null(phalcon_image_adapter_ce, SL("_type"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * Image mime type
	 *
	 * @var string
	 */
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

/**
 * Image width
 *
 * @var int
 */
PHP_METHOD(Phalcon_Image_Adapter, getWidth) {


	RETURN_MEMBER(this_ptr, "_width");

}

/**
 * Image height
 *
 * @var int
 */
PHP_METHOD(Phalcon_Image_Adapter, getHeight) {


	RETURN_MEMBER(this_ptr, "_height");

}

/**
 * Image type
 *
 * Driver dependent
 *
 * @var int
 */
PHP_METHOD(Phalcon_Image_Adapter, getType) {


	RETURN_MEMBER(this_ptr, "_type");

}

/**
 * Image mime type
 *
 * @var string
 */
PHP_METHOD(Phalcon_Image_Adapter, getMime) {


	RETURN_MEMBER(this_ptr, "_mime");

}

/**
 * Resize the image to the given size
 */
PHP_METHOD(Phalcon_Image_Adapter, resize) {

	zephir_fcall_cache_entry *_12 = NULL;
	zend_bool _0, _4;
	double ratio;
	zval *width_param = NULL, *height_param = NULL, *master_param = NULL, *_1 = NULL, *_2, *_3, *_5, *_6, *_7 = NULL, *_8, _9, *_10 = NULL, *_11 = NULL, _13, *_14 = NULL, *_15 = NULL, *_16;
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
		master = 4;
	} else {
		master = zephir_get_intval(master_param);
	}


	if (master == 7) {
		_0 = !width;
		if (!(_0)) {
			_0 = !height;
		}
		if (_0) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_image_exception_ce, "width and height must be specified", "phalcon/image/adapter.zep", 80);
			return;
		}
	} else {
		if (master == 4) {
			_0 = !width;
			if (!(_0)) {
				_0 = !height;
			}
			if (_0) {
				ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_image_exception_ce, "width and height must be specified", "phalcon/image/adapter.zep", 88);
				return;
			}
			ZEPHIR_INIT_VAR(_1);
			_2 = zephir_fetch_nproperty_this(this_ptr, SL("_width"), PH_NOISY_CC);
			_3 = zephir_fetch_nproperty_this(this_ptr, SL("_height"), PH_NOISY_CC);
			if ((zephir_safe_div_zval_long(_2, width TSRMLS_CC)) > (int) (zephir_safe_div_zval_long(_3, height TSRMLS_CC))) {
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
				ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_image_exception_ce, "width and height must be specified", "phalcon/image/adapter.zep", 97);
				return;
			}
			ZEPHIR_INIT_LNVAR(_1);
			_2 = zephir_fetch_nproperty_this(this_ptr, SL("_width"), PH_NOISY_CC);
			_3 = zephir_fetch_nproperty_this(this_ptr, SL("_height"), PH_NOISY_CC);
			if ((zephir_safe_div_zval_long(_2, width TSRMLS_CC)) > (int) (zephir_safe_div_zval_long(_3, height TSRMLS_CC))) {
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
					ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_image_exception_ce, "width must be specified", "phalcon/image/adapter.zep", 107);
					return;
				}
				_2 = zephir_fetch_nproperty_this(this_ptr, SL("_height"), PH_NOISY_CC);
				_3 = zephir_fetch_nproperty_this(this_ptr, SL("_width"), PH_NOISY_CC);
				height = (long) (zephir_safe_div_long_zval((zephir_get_numberval(_2) * width), _3 TSRMLS_CC));
				break;
			}
			if (master == 3) {
				if (!(height)) {
					ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_image_exception_ce, "height must be specified", "phalcon/image/adapter.zep", 114);
					return;
				}
				_2 = zephir_fetch_nproperty_this(this_ptr, SL("_width"), PH_NOISY_CC);
				_3 = zephir_fetch_nproperty_this(this_ptr, SL("_height"), PH_NOISY_CC);
				width = (long) (zephir_safe_div_long_zval((zephir_get_numberval(_2) * height), _3 TSRMLS_CC));
				break;
			}
			if (master == 6) {
				_4 = !width;
				if (!(_4)) {
					_4 = !height;
				}
				if (_4) {
					ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_image_exception_ce, "width and height must be specified", "phalcon/image/adapter.zep", 121);
					return;
				}
				_2 = zephir_fetch_nproperty_this(this_ptr, SL("_width"), PH_NOISY_CC);
				_3 = zephir_fetch_nproperty_this(this_ptr, SL("_height"), PH_NOISY_CC);
				ZEPHIR_INIT_LNVAR(_1);
				div_function(_1, _2, _3 TSRMLS_CC);
				ratio = zephir_get_numberval(_1);
				if ((zephir_safe_div_long_long(width, height TSRMLS_CC)) > ratio) {
					_2 = zephir_fetch_nproperty_this(this_ptr, SL("_height"), PH_NOISY_CC);
					_3 = zephir_fetch_nproperty_this(this_ptr, SL("_width"), PH_NOISY_CC);
					height = (long) (zephir_safe_div_long_zval((zephir_get_numberval(_2) * width), _3 TSRMLS_CC));
				} else {
					_5 = zephir_fetch_nproperty_this(this_ptr, SL("_width"), PH_NOISY_CC);
					_6 = zephir_fetch_nproperty_this(this_ptr, SL("_height"), PH_NOISY_CC);
					width = (long) (zephir_safe_div_long_zval((zephir_get_numberval(_5) * height), _6 TSRMLS_CC));
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
	ZEPHIR_INIT_VAR(_8);
	ZEPHIR_SINIT_VAR(_9);
	ZVAL_LONG(&_9, width);
	zephir_round(_8, &_9, NULL, NULL TSRMLS_CC);
	ZEPHIR_INIT_VAR(_10);
	ZVAL_LONG(_10, 1);
	ZEPHIR_CALL_FUNCTION(&_11, "max", &_12, 228, _8, _10);
	zephir_check_call_status();
	width = zephir_get_intval(_11);
	ZEPHIR_INIT_NVAR(_10);
	ZEPHIR_SINIT_VAR(_13);
	ZVAL_LONG(&_13, height);
	zephir_round(_10, &_13, NULL, NULL TSRMLS_CC);
	ZEPHIR_INIT_VAR(_14);
	ZVAL_LONG(_14, 1);
	ZEPHIR_CALL_FUNCTION(&_15, "max", &_12, 228, _10, _14);
	zephir_check_call_status();
	height = zephir_get_intval(_15);
	ZEPHIR_INIT_NVAR(_14);
	ZVAL_LONG(_14, width);
	ZEPHIR_INIT_VAR(_16);
	ZVAL_LONG(_16, height);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "_resize", NULL, 0, _14, _16);
	zephir_check_call_status();
	RETURN_THIS();

}

/**
 * This method scales the images using liquid rescaling method. Only support Imagick
 *
 * @param int $width   new width
 * @param int $height  new height
 * @param int $deltaX How much the seam can traverse on x-axis. Passing 0 causes the seams to be straight.
 * @param int $rigidity Introduces a bias for non-straight seams. This parameter is typically 0.
 */
PHP_METHOD(Phalcon_Image_Adapter, liquidRescale) {

	zval *width_param = NULL, *height_param = NULL, *deltaX_param = NULL, *rigidity_param = NULL, *_0, *_1, *_2, *_3;
	int width, height, deltaX, rigidity, ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 2, &width_param, &height_param, &deltaX_param, &rigidity_param);

	width = zephir_get_intval(width_param);
	height = zephir_get_intval(height_param);
	if (!deltaX_param) {
		deltaX = 0;
	} else {
		deltaX = zephir_get_intval(deltaX_param);
	}
	if (!rigidity_param) {
		rigidity = 0;
	} else {
		rigidity = zephir_get_intval(rigidity_param);
	}


	ZEPHIR_INIT_VAR(_0);
	ZVAL_LONG(_0, width);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_LONG(_1, height);
	ZEPHIR_INIT_VAR(_2);
	ZVAL_LONG(_2, deltaX);
	ZEPHIR_INIT_VAR(_3);
	ZVAL_LONG(_3, rigidity);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "_liquidrescale", NULL, 0, _0, _1, _2, _3);
	zephir_check_call_status();
	RETURN_THIS();

}

/**
 * Crop an image to the given size
 */
PHP_METHOD(Phalcon_Image_Adapter, crop) {

	zval *width_param = NULL, *height_param = NULL, *offsetX_param = NULL, *offsetY_param = NULL, _0, *_1, *_2, *_3 = NULL, _4, *_5, *_6, *_7, *_8;
	int width, height, offsetX, offsetY, ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 2, &width_param, &height_param, &offsetX_param, &offsetY_param);

	width = zephir_get_intval(width_param);
	height = zephir_get_intval(height_param);
	if (!offsetX_param) {
		offsetX = 0;
	} else {
		offsetX = zephir_get_intval(offsetX_param);
	}
	if (!offsetY_param) {
		offsetY = 0;
	} else {
		offsetY = zephir_get_intval(offsetY_param);
	}


	ZEPHIR_SINIT_VAR(_0);
	ZVAL_LONG(&_0, offsetX);
	if (Z_TYPE_P(&_0) == IS_NULL) {
		_1 = zephir_fetch_nproperty_this(this_ptr, SL("_width"), PH_NOISY_CC);
		offsetX = (long) ((zephir_safe_div_long_long(((zephir_get_numberval(_1) - width)), 2 TSRMLS_CC)));
	} else {
		if (offsetX < 0) {
			_1 = zephir_fetch_nproperty_this(this_ptr, SL("_width"), PH_NOISY_CC);
			offsetX = ((zephir_get_numberval(_1) - width) + offsetX);
		}
		_2 = zephir_fetch_nproperty_this(this_ptr, SL("_width"), PH_NOISY_CC);
		if (ZEPHIR_LT_LONG(_2, offsetX)) {
			ZEPHIR_OBS_VAR(_3);
			zephir_read_property_this(&_3, this_ptr, SL("_width"), PH_NOISY_CC);
			offsetX = zephir_get_intval(_3);
		}
	}
	ZEPHIR_SINIT_VAR(_4);
	ZVAL_LONG(&_4, offsetY);
	if (Z_TYPE_P(&_4) == IS_NULL) {
		_1 = zephir_fetch_nproperty_this(this_ptr, SL("_height"), PH_NOISY_CC);
		offsetY = (long) ((zephir_safe_div_long_long(((zephir_get_numberval(_1) - height)), 2 TSRMLS_CC)));
	} else {
		if (offsetY < 0) {
			_1 = zephir_fetch_nproperty_this(this_ptr, SL("_height"), PH_NOISY_CC);
			offsetY = ((zephir_get_numberval(_1) - height) + offsetY);
		}
		_2 = zephir_fetch_nproperty_this(this_ptr, SL("_height"), PH_NOISY_CC);
		if (ZEPHIR_LT_LONG(_2, offsetY)) {
			ZEPHIR_OBS_NVAR(_3);
			zephir_read_property_this(&_3, this_ptr, SL("_height"), PH_NOISY_CC);
			offsetY = zephir_get_intval(_3);
		}
	}
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("_width"), PH_NOISY_CC);
	if (width > ((zephir_get_numberval(_1) - offsetX))) {
		_2 = zephir_fetch_nproperty_this(this_ptr, SL("_width"), PH_NOISY_CC);
		width = (zephir_get_numberval(_2) - offsetX);
	}
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("_height"), PH_NOISY_CC);
	if (height > ((zephir_get_numberval(_1) - offsetY))) {
		_2 = zephir_fetch_nproperty_this(this_ptr, SL("_height"), PH_NOISY_CC);
		height = (zephir_get_numberval(_2) - offsetY);
	}
	ZEPHIR_INIT_VAR(_5);
	ZVAL_LONG(_5, width);
	ZEPHIR_INIT_VAR(_6);
	ZVAL_LONG(_6, height);
	ZEPHIR_INIT_VAR(_7);
	ZVAL_LONG(_7, offsetX);
	ZEPHIR_INIT_VAR(_8);
	ZVAL_LONG(_8, offsetY);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "_crop", NULL, 0, _5, _6, _7, _8);
	zephir_check_call_status();
	RETURN_THIS();

}

/**
 * Rotate the image by a given amount
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
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "_rotate", NULL, 0, _0);
	zephir_check_call_status();
	RETURN_THIS();

}

/**
 * Flip the image along the horizontal or vertical axis
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
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "_flip", NULL, 0, _1);
	zephir_check_call_status();
	RETURN_THIS();

}

/**
 * Sharpen the image by a given amount
 */
PHP_METHOD(Phalcon_Image_Adapter, sharpen) {

	zval *amount_param = NULL, *_0;
	int amount, ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &amount_param);

	amount = zephir_get_intval(amount_param);


	if (amount > 100) {
		amount = 100;
	} else if (amount < 1) {
		amount = 1;
	}
	ZEPHIR_INIT_VAR(_0);
	ZVAL_LONG(_0, amount);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "_sharpen", NULL, 0, _0);
	zephir_check_call_status();
	RETURN_THIS();

}

/**
 * Add a reflection to an image
 */
PHP_METHOD(Phalcon_Image_Adapter, reflection) {

	zend_bool fadeIn, _0;
	zval *height_param = NULL, *opacity_param = NULL, *fadeIn_param = NULL, *_1, *_2, *_3, *_4;
	int height, opacity, ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &height_param, &opacity_param, &fadeIn_param);

	height = zephir_get_intval(height_param);
	if (!opacity_param) {
		opacity = 100;
	} else {
		opacity = zephir_get_intval(opacity_param);
	}
	if (!fadeIn_param) {
		fadeIn = 0;
	} else {
		fadeIn = zephir_get_boolval(fadeIn_param);
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
	} else if (opacity > 100) {
		opacity = 100;
	}
	ZEPHIR_INIT_VAR(_3);
	ZVAL_LONG(_3, height);
	ZEPHIR_INIT_VAR(_4);
	ZVAL_LONG(_4, opacity);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "_reflection", NULL, 0, _3, _4, (fadeIn ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false)));
	zephir_check_call_status();
	RETURN_THIS();

}

/**
 * Add a watermark to an image with the specified opacity
 */
PHP_METHOD(Phalcon_Image_Adapter, watermark) {

	int offsetX, offsetY, opacity, tmp, ZEPHIR_LAST_CALL_STATUS;
	zval *watermark, *offsetX_param = NULL, *offsetY_param = NULL, *opacity_param = NULL, *_0, *_1 = NULL, *_2, *_3, *_4, *_5, *_6;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 3, &watermark, &offsetX_param, &offsetY_param, &opacity_param);

	if (!offsetX_param) {
		offsetX = 0;
	} else {
		offsetX = zephir_get_intval(offsetX_param);
	}
	if (!offsetY_param) {
		offsetY = 0;
	} else {
		offsetY = zephir_get_intval(offsetY_param);
	}
	if (!opacity_param) {
		opacity = 100;
	} else {
		opacity = zephir_get_intval(opacity_param);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_width"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&_1, watermark, "getwidth", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_2);
	sub_function(_2, _0, _1 TSRMLS_CC);
	tmp = zephir_get_numberval(_2);
	if (offsetX < 0) {
		offsetX = 0;
	} else if (offsetX > tmp) {
		offsetX = tmp;
	}
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_height"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&_1, watermark, "getheight", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_3);
	sub_function(_3, _0, _1 TSRMLS_CC);
	tmp = zephir_get_numberval(_3);
	if (offsetY < 0) {
		offsetY = 0;
	} else if (offsetY > tmp) {
		offsetY = tmp;
	}
	if (opacity < 0) {
		opacity = 0;
	} else if (opacity > 100) {
		opacity = 100;
	}
	ZEPHIR_INIT_VAR(_4);
	ZVAL_LONG(_4, offsetX);
	ZEPHIR_INIT_VAR(_5);
	ZVAL_LONG(_5, offsetY);
	ZEPHIR_INIT_VAR(_6);
	ZVAL_LONG(_6, opacity);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "_watermark", NULL, 0, watermark, _4, _5, _6);
	zephir_check_call_status();
	RETURN_THIS();

}

/**
 * Add a text to an image with a specified opacity
 */
PHP_METHOD(Phalcon_Image_Adapter, text) {

	zend_bool _0;
	int offsetX, offsetY, opacity, size, ZEPHIR_LAST_CALL_STATUS;
	zval *text_param = NULL, *offsetX_param = NULL, *offsetY_param = NULL, *opacity_param = NULL, *color_param = NULL, *size_param = NULL, *fontfile_param = NULL, *colors = NULL, _1, _2, *_3, _4 = zval_used_for_init, *_5 = NULL, *_6 = NULL, *_7 = NULL, *_8, *_9, *_10, *_11, *_12;
	zval *text = NULL, *color = NULL, *fontfile = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 6, &text_param, &offsetX_param, &offsetY_param, &opacity_param, &color_param, &size_param, &fontfile_param);

	zephir_get_strval(text, text_param);
	if (!offsetX_param) {
		offsetX = 0;
	} else {
		offsetX = zephir_get_intval(offsetX_param);
	}
	if (!offsetY_param) {
		offsetY = 0;
	} else {
		offsetY = zephir_get_intval(offsetY_param);
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
	} else if (opacity > 100) {
		opacity = 100;
	}
	_0 = zephir_fast_strlen_ev(color) > 1;
	if (_0) {
		ZEPHIR_SINIT_VAR(_1);
		ZVAL_LONG(&_1, 0);
		ZEPHIR_SINIT_VAR(_2);
		ZVAL_LONG(&_2, 1);
		ZEPHIR_INIT_VAR(_3);
		zephir_substr(_3, color, 0 , 1 , 0);
		_0 = ZEPHIR_IS_STRING_IDENTICAL(_3, "#");
	}
	if (_0) {
		ZEPHIR_SINIT_VAR(_4);
		ZVAL_LONG(&_4, 1);
		ZEPHIR_INIT_VAR(_5);
		zephir_substr(_5, color, 1 , 0, ZEPHIR_SUBSTR_NO_LENGTH);
		zephir_get_strval(color, _5);
	}
	if (zephir_fast_strlen_ev(color) == 3) {
		ZEPHIR_INIT_NVAR(_5);
		ZVAL_STRING(_5, "/./", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_INIT_VAR(_6);
		ZVAL_STRING(_6, "$0$0", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_FUNCTION(&_7, "preg_replace", NULL, 82, _5, _6, color);
		zephir_check_temp_parameter(_5);
		zephir_check_temp_parameter(_6);
		zephir_check_call_status();
		zephir_get_strval(color, _7);
	}
	ZEPHIR_SINIT_NVAR(_4);
	ZVAL_LONG(&_4, 2);
	ZEPHIR_CALL_FUNCTION(&_7, "str_split", NULL, 229, color, &_4);
	zephir_check_call_status();
	ZEPHIR_SINIT_NVAR(_4);
	ZVAL_STRING(&_4, "hexdec", 0);
	ZEPHIR_CALL_FUNCTION(&colors, "array_map", NULL, 230, &_4, _7);
	zephir_check_call_status();
	zephir_array_fetch_long(&_8, colors, 0, PH_NOISY | PH_READONLY, "phalcon/image/adapter.zep", 333 TSRMLS_CC);
	zephir_array_fetch_long(&_9, colors, 1, PH_NOISY | PH_READONLY, "phalcon/image/adapter.zep", 333 TSRMLS_CC);
	zephir_array_fetch_long(&_10, colors, 2, PH_NOISY | PH_READONLY, "phalcon/image/adapter.zep", 333 TSRMLS_CC);
	ZEPHIR_INIT_NVAR(_5);
	ZVAL_LONG(_5, offsetX);
	ZEPHIR_INIT_NVAR(_6);
	ZVAL_LONG(_6, offsetY);
	ZEPHIR_INIT_VAR(_11);
	ZVAL_LONG(_11, opacity);
	ZEPHIR_INIT_VAR(_12);
	ZVAL_LONG(_12, size);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "_text", NULL, 0, text, _5, _6, _11, _8, _9, _10, _12, fontfile);
	zephir_check_call_status();
	RETURN_THIS();

}

/**
 * Composite one image onto another
 */
PHP_METHOD(Phalcon_Image_Adapter, mask) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *watermark;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &watermark);



	ZEPHIR_CALL_METHOD(NULL, this_ptr, "_mask", NULL, 0, watermark);
	zephir_check_call_status();
	RETURN_THIS();

}

/**
 * Set the background color of an image
 */
PHP_METHOD(Phalcon_Image_Adapter, background) {

	zend_bool _0;
	int opacity, ZEPHIR_LAST_CALL_STATUS;
	zval *color_param = NULL, *opacity_param = NULL, *colors = NULL, _1, _2, *_3, _4 = zval_used_for_init, *_5 = NULL, *_6, *_7 = NULL, *_8, *_9, *_10;
	zval *color = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &color_param, &opacity_param);

	zephir_get_strval(color, color_param);
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
		ZEPHIR_INIT_VAR(_3);
		zephir_substr(_3, color, 0 , 1 , 0);
		_0 = ZEPHIR_IS_STRING_IDENTICAL(_3, "#");
	}
	if (_0) {
		ZEPHIR_SINIT_VAR(_4);
		ZVAL_LONG(&_4, 1);
		ZEPHIR_INIT_VAR(_5);
		zephir_substr(_5, color, 1 , 0, ZEPHIR_SUBSTR_NO_LENGTH);
		zephir_get_strval(color, _5);
	}
	if (zephir_fast_strlen_ev(color) == 3) {
		ZEPHIR_INIT_NVAR(_5);
		ZVAL_STRING(_5, "/./", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_INIT_VAR(_6);
		ZVAL_STRING(_6, "$0$0", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_FUNCTION(&_7, "preg_replace", NULL, 82, _5, _6, color);
		zephir_check_temp_parameter(_5);
		zephir_check_temp_parameter(_6);
		zephir_check_call_status();
		zephir_get_strval(color, _7);
	}
	ZEPHIR_SINIT_NVAR(_4);
	ZVAL_LONG(&_4, 2);
	ZEPHIR_CALL_FUNCTION(&_7, "str_split", NULL, 229, color, &_4);
	zephir_check_call_status();
	ZEPHIR_SINIT_NVAR(_4);
	ZVAL_STRING(&_4, "hexdec", 0);
	ZEPHIR_CALL_FUNCTION(&colors, "array_map", NULL, 230, &_4, _7);
	zephir_check_call_status();
	zephir_array_fetch_long(&_8, colors, 0, PH_NOISY | PH_READONLY, "phalcon/image/adapter.zep", 364 TSRMLS_CC);
	zephir_array_fetch_long(&_9, colors, 1, PH_NOISY | PH_READONLY, "phalcon/image/adapter.zep", 364 TSRMLS_CC);
	zephir_array_fetch_long(&_10, colors, 2, PH_NOISY | PH_READONLY, "phalcon/image/adapter.zep", 364 TSRMLS_CC);
	ZEPHIR_INIT_NVAR(_5);
	ZVAL_LONG(_5, opacity);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "_background", NULL, 0, _8, _9, _10, _5);
	zephir_check_call_status();
	RETURN_THIS();

}

/**
 * Blur image
 */
PHP_METHOD(Phalcon_Image_Adapter, blur) {

	zval *radius_param = NULL, *_0;
	int radius, ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &radius_param);

	radius = zephir_get_intval(radius_param);


	if (radius < 1) {
		radius = 1;
	} else if (radius > 100) {
		radius = 100;
	}
	ZEPHIR_INIT_VAR(_0);
	ZVAL_LONG(_0, radius);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "_blur", NULL, 0, _0);
	zephir_check_call_status();
	RETURN_THIS();

}

/**
 * Pixelate image
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
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "_pixelate", NULL, 0, _0);
	zephir_check_call_status();
	RETURN_THIS();

}

/**
 * Save the image
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
	} else if (quality > 100) {
		quality = 100;
	}
	ZEPHIR_INIT_VAR(_2);
	ZVAL_LONG(_2, quality);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "_save", NULL, 0, file, _2);
	zephir_check_call_status();
	RETURN_THIS();

}

/**
 * Render the image and return the binary string
 */
PHP_METHOD(Phalcon_Image_Adapter, render) {

	int quality, ZEPHIR_LAST_CALL_STATUS;
	zval *ext_param = NULL, *quality_param = NULL, *_0, _1, *_2 = NULL, *_4;
	zval *ext = NULL, *_3 = NULL;

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
		ZEPHIR_CALL_FUNCTION(&_2, "pathinfo", NULL, 207, _0, &_1);
		zephir_check_call_status();
		zephir_get_strval(_3, _2);
		ZEPHIR_CPY_WRT(ext, _3);
	}
	if (ZEPHIR_IS_EMPTY(ext)) {
		ZEPHIR_INIT_NVAR(ext);
		ZVAL_STRING(ext, "png", 1);
	}
	if (quality < 1) {
		quality = 1;
	} else if (quality > 100) {
		quality = 100;
	}
	ZEPHIR_INIT_VAR(_4);
	ZVAL_LONG(_4, quality);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "_render", NULL, 0, ext, _4);
	zephir_check_call_status();
	RETURN_MM();

}

