
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
#include "kernel/fcall.h"
#include "kernel/object.h"
#include "kernel/memory.h"
#include "kernel/file.h"
#include "kernel/operators.h"
#include "kernel/exception.h"
#include "kernel/concat.h"
#include "kernel/string.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * Phalcon\Image\Adapter\Imagick
 *
 * Image manipulation support. Resize, rotate, crop etc.
 *
 *```php
 * $image = new \Phalcon\Image\Adapter\Imagick("upload/test.jpg");
 *
 * $image->resize(200, 200)->rotate(90)->crop(100, 100);
 *
 * if ($image->save()) {
 *     echo "success";
 * }
 *```
 */
ZEPHIR_INIT_CLASS(Phalcon_Image_Adapter_Imagick)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Image\\Adapter, Imagick, phalcon, image_adapter_imagick, phalcon_image_adapter_abstractadapter_ce, phalcon_image_adapter_imagick_method_entry, 0);

	/**
	 * @var int
	 */
	zend_declare_property_long(phalcon_image_adapter_imagick_ce, SL("version"), 0, ZEND_ACC_PROTECTED);
	return SUCCESS;
}

/**
 * Constructor
 *
 * @param string   $file
 * @param int|null $width
 * @param int|null $height
 *
 * @throws Exception
 * @throws ImagickException
 */
PHP_METHOD(Phalcon_Image_Adapter_Imagick, __construct)
{
	zend_bool _22$$7;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long width, height, ZEPHIR_LAST_CALL_STATUS;
	zval *file_param = NULL, *width_param = NULL, *height_param = NULL, image, _0, _1, _32, _33, _34, _35, _36, _37, _38, _39, _40, _2$$3, _3$$3, _4$$3, _5$$3, _6$$3, _10$$3, _11$$3, _15$$3, _16$$3, _17$$3, _18$$3, _7$$4, _8$$4, _9$$4, _12$$5, _13$$5, _14$$5, _19$$6, _20$$6, _21$$6, _26$$7, _27$$7, _28$$7, _29$$7, _30$$7, _31$$7, _23$$8, _24$$8, _25$$8;
	zval file;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&file);
	ZVAL_UNDEF(&image);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_32);
	ZVAL_UNDEF(&_33);
	ZVAL_UNDEF(&_34);
	ZVAL_UNDEF(&_35);
	ZVAL_UNDEF(&_36);
	ZVAL_UNDEF(&_37);
	ZVAL_UNDEF(&_38);
	ZVAL_UNDEF(&_39);
	ZVAL_UNDEF(&_40);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_10$$3);
	ZVAL_UNDEF(&_11$$3);
	ZVAL_UNDEF(&_15$$3);
	ZVAL_UNDEF(&_16$$3);
	ZVAL_UNDEF(&_17$$3);
	ZVAL_UNDEF(&_18$$3);
	ZVAL_UNDEF(&_7$$4);
	ZVAL_UNDEF(&_8$$4);
	ZVAL_UNDEF(&_9$$4);
	ZVAL_UNDEF(&_12$$5);
	ZVAL_UNDEF(&_13$$5);
	ZVAL_UNDEF(&_14$$5);
	ZVAL_UNDEF(&_19$$6);
	ZVAL_UNDEF(&_20$$6);
	ZVAL_UNDEF(&_21$$6);
	ZVAL_UNDEF(&_26$$7);
	ZVAL_UNDEF(&_27$$7);
	ZVAL_UNDEF(&_28$$7);
	ZVAL_UNDEF(&_29$$7);
	ZVAL_UNDEF(&_30$$7);
	ZVAL_UNDEF(&_31$$7);
	ZVAL_UNDEF(&_23$$8);
	ZVAL_UNDEF(&_24$$8);
	ZVAL_UNDEF(&_25$$8);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 3)
		Z_PARAM_STR(file)
		Z_PARAM_OPTIONAL
		Z_PARAM_LONG_OR_NULL(width, is_null_true)
		Z_PARAM_LONG_OR_NULL(height, is_null_true)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &file_param, &width_param, &height_param);
	zephir_get_strval(&file, file_param);
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


	ZEPHIR_CALL_METHOD(NULL, this_ptr, "check", NULL, 407);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, ZEND_STRL("file"), &file);
	ZEPHIR_INIT_VAR(&_0);
	object_init_ex(&_0, zephir_get_internal_ce(SL("imagick")));
	ZEPHIR_CALL_METHOD(NULL, &_0, "__construct", NULL, 0);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, ZEND_STRL("image"), &_0);
	zephir_read_property(&_1, this_ptr, ZEND_STRL("file"), PH_NOISY_CC | PH_READONLY);
	if (1 == (zephir_file_exists(&_1) == SUCCESS)) {
		zephir_read_property(&_2$$3, this_ptr, ZEND_STRL("file"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_FUNCTION(&_3$$3, "realpath", NULL, 71, &_2$$3);
		zephir_check_call_status();
		zephir_update_property_zval(this_ptr, ZEND_STRL("realpath"), &_3$$3);
		zephir_read_property(&_4$$3, this_ptr, ZEND_STRL("image"), PH_NOISY_CC | PH_READONLY);
		zephir_read_property(&_6$$3, this_ptr, ZEND_STRL("realpath"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(&_5$$3, &_4$$3, "readimage", NULL, 0, &_6$$3);
		zephir_check_call_status();
		if (!ZEPHIR_IS_TRUE_IDENTICAL(&_5$$3)) {
			ZEPHIR_INIT_VAR(&_7$$4);
			object_init_ex(&_7$$4, phalcon_image_exception_ce);
			zephir_read_property(&_8$$4, this_ptr, ZEND_STRL("file"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_INIT_VAR(&_9$$4);
			ZEPHIR_CONCAT_SVS(&_9$$4, "Imagick::readImage ", &_8$$4, " failed");
			ZEPHIR_CALL_METHOD(NULL, &_7$$4, "__construct", NULL, 29, &_9$$4);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_7$$4, "phalcon/Image/Adapter/Imagick.zep", 72);
			ZEPHIR_MM_RESTORE();
			return;
		}
		zephir_read_property(&_10$$3, this_ptr, ZEND_STRL("image"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(&_11$$3, &_10$$3, "getimagealphachannel", NULL, 0);
		zephir_check_call_status();
		if (!zephir_is_true(&_11$$3)) {
			zephir_read_property(&_12$$5, this_ptr, ZEND_STRL("image"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_INIT_VAR(&_13$$5);
			ZVAL_STRING(&_13$$5, "Imagick::ALPHACHANNEL_SET");
			ZEPHIR_CALL_FUNCTION(&_14$$5, "constant", NULL, 115, &_13$$5);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, &_12$$5, "setimagealphachannel", NULL, 0, &_14$$5);
			zephir_check_call_status();
		}
		zephir_read_property(&_15$$3, this_ptr, ZEND_STRL("image"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(&_16$$3, &_15$$3, "getimagetype", NULL, 0);
		zephir_check_call_status();
		zephir_update_property_zval(this_ptr, ZEND_STRL("type"), &_16$$3);
		zephir_read_property(&_17$$3, this_ptr, ZEND_STRL("image"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(&_18$$3, &_17$$3, "getimagetype", NULL, 0);
		zephir_check_call_status();
		if (ZEPHIR_IS_LONG(&_18$$3, 1)) {
			zephir_read_property(&_19$$6, this_ptr, ZEND_STRL("image"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_CALL_METHOD(&image, &_19$$6, "coalesceimages", NULL, 0);
			zephir_check_call_status();
			zephir_read_property(&_20$$6, this_ptr, ZEND_STRL("image"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_CALL_METHOD(NULL, &_20$$6, "clear", NULL, 0);
			zephir_check_call_status();
			zephir_read_property(&_21$$6, this_ptr, ZEND_STRL("image"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_CALL_METHOD(NULL, &_21$$6, "destroy", NULL, 0);
			zephir_check_call_status();
			zephir_update_property_zval(this_ptr, ZEND_STRL("image"), &image);
		}
	} else {
		_22$$7 = 0 == width;
		if (!(_22$$7)) {
			_22$$7 = 0 == height;
		}
		if (_22$$7) {
			ZEPHIR_INIT_VAR(&_23$$8);
			object_init_ex(&_23$$8, phalcon_image_exception_ce);
			zephir_read_property(&_24$$8, this_ptr, ZEND_STRL("file"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_INIT_VAR(&_25$$8);
			ZEPHIR_CONCAT_SV(&_25$$8, "Failed to create image from file ", &_24$$8);
			ZEPHIR_CALL_METHOD(NULL, &_23$$8, "__construct", NULL, 29, &_25$$8);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_23$$8, "phalcon/Image/Adapter/Imagick.zep", 97);
			ZEPHIR_MM_RESTORE();
			return;
		}
		zephir_read_property(&_26$$7, this_ptr, ZEND_STRL("image"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_VAR(&_27$$7);
		object_init_ex(&_27$$7, zephir_get_internal_ce(SL("imagickpixel")));
		ZEPHIR_INIT_VAR(&_28$$7);
		ZVAL_STRING(&_28$$7, "transparent");
		ZEPHIR_CALL_METHOD(NULL, &_27$$7, "__construct", NULL, 0, &_28$$7);
		zephir_check_call_status();
		ZVAL_LONG(&_29$$7, width);
		ZVAL_LONG(&_30$$7, height);
		ZEPHIR_CALL_METHOD(NULL, &_26$$7, "newimage", NULL, 0, &_29$$7, &_30$$7, &_27$$7);
		zephir_check_call_status();
		zephir_read_property(&_29$$7, this_ptr, ZEND_STRL("image"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_NVAR(&_28$$7);
		ZVAL_STRING(&_28$$7, "png");
		ZEPHIR_CALL_METHOD(NULL, &_29$$7, "setformat", NULL, 0, &_28$$7);
		zephir_check_call_status();
		zephir_read_property(&_30$$7, this_ptr, ZEND_STRL("image"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_NVAR(&_28$$7);
		ZVAL_STRING(&_28$$7, "png");
		ZEPHIR_CALL_METHOD(NULL, &_30$$7, "setimageformat", NULL, 0, &_28$$7);
		zephir_check_call_status();
		zephir_read_property(&_31$$7, this_ptr, ZEND_STRL("file"), PH_NOISY_CC | PH_READONLY);
		zephir_update_property_zval(this_ptr, ZEND_STRL("realpath"), &_31$$7);
	}
	zephir_read_property(&_32, this_ptr, ZEND_STRL("image"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_33, &_32, "getimagewidth", NULL, 0);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, ZEND_STRL("width"), &_33);
	zephir_read_property(&_34, this_ptr, ZEND_STRL("image"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_35, &_34, "getimageheight", NULL, 0);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, ZEND_STRL("height"), &_35);
	zephir_read_property(&_36, this_ptr, ZEND_STRL("image"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_37, &_36, "getimagetype", NULL, 0);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, ZEND_STRL("type"), &_37);
	zephir_read_property(&_38, this_ptr, ZEND_STRL("image"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_39, &_38, "getimageformat", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_40);
	ZEPHIR_CONCAT_SV(&_40, "image/", &_39);
	zephir_update_property_zval(this_ptr, ZEND_STRL("mime"), &_40);
	ZEPHIR_MM_RESTORE();
}

/**
 * Destroys the loaded image to free up resources.
 */
PHP_METHOD(Phalcon_Image_Adapter_Imagick, __destruct)
{
	zval _0, _1$$3, _2$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);


	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(&_0);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("image"), PH_NOISY_CC);
	if (zephir_is_instance_of(&_0, SL("Imagick"))) {
		zephir_read_property(&_1$$3, this_ptr, ZEND_STRL("image"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(NULL, &_1$$3, "clear", NULL, 0);
		zephir_check_call_status();
		zephir_read_property(&_2$$3, this_ptr, ZEND_STRL("image"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(NULL, &_2$$3, "destroy", NULL, 0);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();
}

/**
 * This method scales the images using liquid rescaling method. Only support
 * Imagick
 *
 * @param int $width    new width
 * @param int $height   new height
 * @param int $deltaX   How much the seam can traverse on x-axis. Passing
 *                      0 causes the seams to be straight.
 * @param int $rigidity Introduces a bias for non-straight seams. This
 *                      parameter is typically 0.
 *
 * @return AbstractAdapter
 * @throws Exception
 * @throws ImagickException
 */
PHP_METHOD(Phalcon_Image_Adapter_Imagick, liquidRescale)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_5 = NULL, *_7 = NULL;
	zval *width_param = NULL, *height_param = NULL, *deltaX_param = NULL, *rigidity_param = NULL, image, result, _0, _8, _9, _1$$3, _2$$3, _3$$3, _4$$3, _6$$3;
	zend_long width, height, deltaX, rigidity, ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&image);
	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_6$$3);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 4)
		Z_PARAM_LONG(width)
		Z_PARAM_LONG(height)
		Z_PARAM_OPTIONAL
		Z_PARAM_LONG(deltaX)
		Z_PARAM_LONG(rigidity)
	ZEND_PARSE_PARAMETERS_END();
#endif


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


	zephir_read_property(&_0, this_ptr, ZEND_STRL("image"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&image, &_0);
	ZVAL_LONG(&_0, 0);
	ZEPHIR_CALL_METHOD(NULL, &image, "setiteratorindex", NULL, 0, &_0);
	zephir_check_call_status();
	while (1) {
		if (!(1)) {
			break;
		}
		ZVAL_LONG(&_1$$3, width);
		ZVAL_LONG(&_2$$3, height);
		ZVAL_LONG(&_3$$3, deltaX);
		ZVAL_LONG(&_4$$3, rigidity);
		ZEPHIR_CALL_METHOD(&result, &image, "liquidrescaleimage", &_5, 0, &_1$$3, &_2$$3, &_3$$3, &_4$$3);
		zephir_check_call_status();
		if (!ZEPHIR_IS_TRUE_IDENTICAL(&result)) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_image_exception_ce, "Imagick::liquidRescale failed", "phalcon/Image/Adapter/Imagick.zep", 165);
			return;
		}
		ZEPHIR_CALL_METHOD(&_6$$3, &image, "nextimage", &_7, 0);
		zephir_check_call_status();
		if (ZEPHIR_IS_FALSE_IDENTICAL(&_6$$3)) {
			break;
		}
	}
	ZEPHIR_CALL_METHOD(&_8, &image, "getimagewidth", NULL, 0);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, ZEND_STRL("width"), &_8);
	ZEPHIR_CALL_METHOD(&_9, &image, "getimageheight", NULL, 0);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, ZEND_STRL("height"), &_9);
	RETURN_THIS();
}

/**
 * Sets the limit for a particular resource in megabytes
 *
 * @param int $type
 * @param int $limit
 *
 * @return void
 * @throws Exception
 * @throws ImagickException
 *
 * @link https://www.php.net/manual/en/imagick.constants.php#imagick.constants.resourcetypes
 */
PHP_METHOD(Phalcon_Image_Adapter_Imagick, setResourceLimit)
{
	zend_bool _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *type_param = NULL, *limit_param = NULL, _1$$3, _2$$3, _3$$3;
	zend_long type, limit, ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(type)
		Z_PARAM_LONG(limit)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &type_param, &limit_param);
	type = zephir_get_intval(type_param);
	limit = zephir_get_intval(limit_param);


	_0 = type >= 0;
	if (_0) {
		_0 = type <= 6;
	}
	if (_0) {
		zephir_read_property(&_1$$3, this_ptr, ZEND_STRL("image"), PH_NOISY_CC | PH_READONLY);
		ZVAL_LONG(&_2$$3, type);
		ZVAL_LONG(&_3$$3, limit);
		ZEPHIR_CALL_METHOD(NULL, &_1$$3, "setresourcelimit", NULL, 0, &_2$$3, &_3$$3);
		zephir_check_call_status();
	} else {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_image_exception_ce, "Cannot set the Resource Type for this image", "phalcon/Image/Adapter/Imagick.zep", 201);
		return;
	}
	ZEPHIR_MM_RESTORE();
}

/**
 * Execute a background.
 *
 * @param int $red
 * @param int $green
 * @param int $blue
 * @param int $opacity
 *
 * @return void
 * @throws Exception
 * @throws ImagickException
 * @throws ImagickPixelException
 */
PHP_METHOD(Phalcon_Image_Adapter_Imagick, processBackground)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_6 = NULL, *_8 = NULL, *_11 = NULL, *_12 = NULL, *_13 = NULL, *_18 = NULL, *_20 = NULL, *_25 = NULL;
	zval *red_param = NULL, *green_param = NULL, *blue_param = NULL, *opacity_param = NULL, background, color, pixel1, pixel2, result, _0, _1, _2, _3, _4$$3, _5$$3, _7$$3, _14$$3, _15$$3, _16$$3, _17$$3, _19$$3, _21$$3, _22$$3, _23$$3, _24$$3, _26$$3, _9$$4, _10$$4;
	zend_long red, green, blue, opacity = 0, ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&background);
	ZVAL_UNDEF(&color);
	ZVAL_UNDEF(&pixel1);
	ZVAL_UNDEF(&pixel2);
	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_7$$3);
	ZVAL_UNDEF(&_14$$3);
	ZVAL_UNDEF(&_15$$3);
	ZVAL_UNDEF(&_16$$3);
	ZVAL_UNDEF(&_17$$3);
	ZVAL_UNDEF(&_19$$3);
	ZVAL_UNDEF(&_21$$3);
	ZVAL_UNDEF(&_22$$3);
	ZVAL_UNDEF(&_23$$3);
	ZVAL_UNDEF(&_24$$3);
	ZVAL_UNDEF(&_26$$3);
	ZVAL_UNDEF(&_9$$4);
	ZVAL_UNDEF(&_10$$4);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_LONG(red)
		Z_PARAM_LONG(green)
		Z_PARAM_LONG(blue)
		Z_PARAM_LONG(opacity)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 4, 0, &red_param, &green_param, &blue_param, &opacity_param);
	red = zephir_get_intval(red_param);
	green = zephir_get_intval(green_param);
	blue = zephir_get_intval(blue_param);
	opacity = zephir_get_intval(opacity_param);


	opacity /= 100;
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "rgb(%d, %d, %d)");
	ZVAL_LONG(&_1, red);
	ZVAL_LONG(&_2, green);
	ZVAL_LONG(&_3, blue);
	ZEPHIR_CALL_FUNCTION(&color, "sprintf", NULL, 113, &_0, &_1, &_2, &_3);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&pixel1);
	object_init_ex(&pixel1, zephir_get_internal_ce(SL("imagickpixel")));
	ZEPHIR_CALL_METHOD(NULL, &pixel1, "__construct", NULL, 0, &color);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&pixel2);
	object_init_ex(&pixel2, zephir_get_internal_ce(SL("imagickpixel")));
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "transparent");
	ZEPHIR_CALL_METHOD(NULL, &pixel2, "__construct", NULL, 0, &_0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&background);
	object_init_ex(&background, zephir_get_internal_ce(SL("imagick")));
	ZEPHIR_CALL_METHOD(NULL, &background, "__construct", NULL, 0);
	zephir_check_call_status();
	zephir_read_property(&_1, this_ptr, ZEND_STRL("image"), PH_NOISY_CC | PH_READONLY);
	ZVAL_LONG(&_2, 0);
	ZEPHIR_CALL_METHOD(NULL, &_1, "setiteratorindex", NULL, 0, &_2);
	zephir_check_call_status();
	while (1) {
		if (!(1)) {
			break;
		}
		zephir_read_property(&_4$$3, this_ptr, ZEND_STRL("width"), PH_NOISY_CC | PH_READONLY);
		zephir_read_property(&_5$$3, this_ptr, ZEND_STRL("height"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(NULL, &background, "newimage", &_6, 0, &_4$$3, &_5$$3, &pixel1);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_7$$3, &background, "getimagealphachannel", &_8, 0);
		zephir_check_call_status();
		if (!ZEPHIR_IS_TRUE_IDENTICAL(&_7$$3)) {
			ZEPHIR_INIT_NVAR(&_9$$4);
			ZVAL_STRING(&_9$$4, "Imagick::ALPHACHANNEL_SET");
			ZEPHIR_CALL_FUNCTION(&_10$$4, "constant", &_11, 115, &_9$$4);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, &background, "setimagealphachannel", &_12, 0, &_10$$4);
			zephir_check_call_status();
		}
		ZEPHIR_CALL_METHOD(NULL, &background, "setimagebackgroundcolor", &_13, 0, &pixel2);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&_14$$3);
		ZVAL_STRING(&_14$$3, "Imagick::EVALUATE_MULTIPLY");
		ZEPHIR_CALL_FUNCTION(&_15$$3, "constant", &_11, 115, &_14$$3);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&_14$$3);
		ZVAL_STRING(&_14$$3, "Imagick::CHANNEL_ALPHA");
		ZEPHIR_CALL_FUNCTION(&_16$$3, "constant", &_11, 115, &_14$$3);
		zephir_check_call_status();
		ZVAL_LONG(&_17$$3, opacity);
		ZEPHIR_CALL_METHOD(NULL, &background, "evaluateimage", &_18, 0, &_15$$3, &_17$$3, &_16$$3);
		zephir_check_call_status();
		zephir_read_property(&_17$$3, this_ptr, ZEND_STRL("image"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(&_19$$3, &_17$$3, "getcolorspace", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &background, "setcolorspace", &_20, 0, &_19$$3);
		zephir_check_call_status();
		zephir_read_property(&_21$$3, this_ptr, ZEND_STRL("image"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_NVAR(&_14$$3);
		ZVAL_STRING(&_14$$3, "Imagick::COMPOSITE_DISSOLVE");
		ZEPHIR_CALL_FUNCTION(&_22$$3, "constant", &_11, 115, &_14$$3);
		zephir_check_call_status();
		ZVAL_LONG(&_23$$3, 0);
		ZVAL_LONG(&_24$$3, 0);
		ZEPHIR_CALL_METHOD(&result, &background, "compositeimage", &_25, 0, &_21$$3, &_22$$3, &_23$$3, &_24$$3);
		zephir_check_call_status();
		if (!ZEPHIR_IS_TRUE_IDENTICAL(&result)) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_image_exception_ce, "Imagick::compositeImage failed", "phalcon/Image/Adapter/Imagick.zep", 263);
			return;
		}
		zephir_read_property(&_23$$3, this_ptr, ZEND_STRL("image"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(&_26$$3, &_23$$3, "nextimage", NULL, 0);
		zephir_check_call_status();
		if (!ZEPHIR_IS_TRUE_IDENTICAL(&_26$$3)) {
			break;
		}
	}
	zephir_read_property(&_2, this_ptr, ZEND_STRL("image"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, &_2, "clear", NULL, 0);
	zephir_check_call_status();
	zephir_read_property(&_3, this_ptr, ZEND_STRL("image"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, &_3, "destroy", NULL, 0);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, ZEND_STRL("image"), &background);
	ZEPHIR_MM_RESTORE();
}

/**
 * Blur image
 *
 * @param int $radius Blur radius
 *
 * @return void
 * @throws ImagickException
 */
PHP_METHOD(Phalcon_Image_Adapter_Imagick, processBlur)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *radius_param = NULL, _0, _1, _2$$3, _3$$3, _4$$3, _5$$3;
	zend_long radius, ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$3);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(radius)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &radius_param);
	radius = zephir_get_intval(radius_param);


	zephir_read_property(&_0, this_ptr, ZEND_STRL("image"), PH_NOISY_CC | PH_READONLY);
	ZVAL_LONG(&_1, 0);
	ZEPHIR_CALL_METHOD(NULL, &_0, "setiteratorindex", NULL, 0, &_1);
	zephir_check_call_status();
	while (1) {
		if (!(1)) {
			break;
		}
		zephir_read_property(&_2$$3, this_ptr, ZEND_STRL("image"), PH_NOISY_CC | PH_READONLY);
		ZVAL_LONG(&_3$$3, radius);
		ZVAL_LONG(&_4$$3, 100);
		ZEPHIR_CALL_METHOD(NULL, &_2$$3, "blurimage", NULL, 0, &_3$$3, &_4$$3);
		zephir_check_call_status();
		zephir_read_property(&_3$$3, this_ptr, ZEND_STRL("image"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(&_5$$3, &_3$$3, "nextimage", NULL, 0);
		zephir_check_call_status();
		if (!ZEPHIR_IS_TRUE_IDENTICAL(&_5$$3)) {
			break;
		}
	}
	ZEPHIR_MM_RESTORE();
}

/**
 * Execute a crop.
 *
 * @param int $width
 * @param int $height
 * @param int $offsetX
 * @param int $offsetY
 *
 * @return void
 * @throws ImagickException
 */
PHP_METHOD(Phalcon_Image_Adapter_Imagick, processCrop)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_5 = NULL, *_6 = NULL, *_8 = NULL;
	zval *width_param = NULL, *height_param = NULL, *offsetX_param = NULL, *offsetY_param = NULL, image, _0, _9, _10, _1$$3, _2$$3, _3$$3, _4$$3, _7$$3;
	zend_long width, height, offsetX, offsetY, ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&image);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_7$$3);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_LONG(width)
		Z_PARAM_LONG(height)
		Z_PARAM_LONG(offsetX)
		Z_PARAM_LONG(offsetY)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 4, 0, &width_param, &height_param, &offsetX_param, &offsetY_param);
	width = zephir_get_intval(width_param);
	height = zephir_get_intval(height_param);
	offsetX = zephir_get_intval(offsetX_param);
	offsetY = zephir_get_intval(offsetY_param);


	zephir_read_property(&_0, this_ptr, ZEND_STRL("image"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&image, &_0);
	ZVAL_LONG(&_0, 0);
	ZEPHIR_CALL_METHOD(NULL, &image, "setiteratorindex", NULL, 0, &_0);
	zephir_check_call_status();
	while (1) {
		if (!(1)) {
			break;
		}
		ZVAL_LONG(&_1$$3, width);
		ZVAL_LONG(&_2$$3, height);
		ZVAL_LONG(&_3$$3, offsetX);
		ZVAL_LONG(&_4$$3, offsetY);
		ZEPHIR_CALL_METHOD(NULL, &image, "cropimage", &_5, 0, &_1$$3, &_2$$3, &_3$$3, &_4$$3);
		zephir_check_call_status();
		ZVAL_LONG(&_1$$3, width);
		ZVAL_LONG(&_2$$3, height);
		ZVAL_LONG(&_3$$3, 0);
		ZVAL_LONG(&_4$$3, 0);
		ZEPHIR_CALL_METHOD(NULL, &image, "setimagepage", &_6, 0, &_1$$3, &_2$$3, &_3$$3, &_4$$3);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_7$$3, &image, "nextimage", &_8, 0);
		zephir_check_call_status();
		if (!ZEPHIR_IS_TRUE_IDENTICAL(&_7$$3)) {
			break;
		}
	}
	ZEPHIR_CALL_METHOD(&_9, &image, "getimagewidth", NULL, 0);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, ZEND_STRL("width"), &_9);
	ZEPHIR_CALL_METHOD(&_10, &image, "getimageheight", NULL, 0);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, ZEND_STRL("height"), &_10);
	ZEPHIR_MM_RESTORE();
}

/**
 * Execute a flip.
 *
 * @param int $direction
 *
 * @return void
 * @throws ImagickException
 */
PHP_METHOD(Phalcon_Image_Adapter_Imagick, processFlip)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *direction_param = NULL, method, _0, _1, _2$$3, _3$$3, _4$$3;
	zend_long direction, ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&method);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(direction)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &direction_param);
	direction = zephir_get_intval(direction_param);


	if (direction == 11) {
		ZEPHIR_INIT_VAR(&method);
		ZVAL_STRING(&method, "flipImage");
	} else {
		ZEPHIR_INIT_NVAR(&method);
		ZVAL_STRING(&method, "flopImage");
	}
	zephir_read_property(&_0, this_ptr, ZEND_STRL("image"), PH_NOISY_CC | PH_READONLY);
	ZVAL_LONG(&_1, 0);
	ZEPHIR_CALL_METHOD(NULL, &_0, "setiteratorindex", NULL, 0, &_1);
	zephir_check_call_status();
	while (1) {
		if (!(1)) {
			break;
		}
		zephir_read_property(&_2$$3, this_ptr, ZEND_STRL("image"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD_ZVAL(NULL, &_2$$3, &method, NULL, 0);
		zephir_check_call_status();
		zephir_read_property(&_3$$3, this_ptr, ZEND_STRL("image"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(&_4$$3, &_3$$3, "nextimage", NULL, 0);
		zephir_check_call_status();
		if (!ZEPHIR_IS_TRUE_IDENTICAL(&_4$$3)) {
			break;
		}
	}
	ZEPHIR_MM_RESTORE();
}

/**
 * Composite one image onto another
 *
 * @param AdapterInterface $image
 *
 * @return void
 * @throws Exception
 * @throws ImagickException
 */
PHP_METHOD(Phalcon_Image_Adapter_Imagick, processMask)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_7 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *image, image_sub, mask, result, _0, _1, _2, _3$$3, _4$$3, _5$$3, _6$$3, _8$$3, _9$$3, _10$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&image_sub);
	ZVAL_UNDEF(&mask);
	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_8$$3);
	ZVAL_UNDEF(&_9$$3);
	ZVAL_UNDEF(&_10$$3);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(image, phalcon_image_adapter_adapterinterface_ce)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &image);


	ZEPHIR_INIT_VAR(&mask);
	object_init_ex(&mask, zephir_get_internal_ce(SL("imagick")));
	ZEPHIR_CALL_METHOD(NULL, &mask, "__construct", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_0, image, "render", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &mask, "readimageblob", NULL, 0, &_0);
	zephir_check_call_status();
	zephir_read_property(&_1, this_ptr, ZEND_STRL("image"), PH_NOISY_CC | PH_READONLY);
	ZVAL_LONG(&_2, 0);
	ZEPHIR_CALL_METHOD(NULL, &_1, "setiteratorindex", NULL, 0, &_2);
	zephir_check_call_status();
	while (1) {
		if (!(1)) {
			break;
		}
		zephir_read_property(&_3$$3, this_ptr, ZEND_STRL("image"), PH_NOISY_CC | PH_READONLY);
		ZVAL_BOOL(&_4$$3, 1);
		ZEPHIR_CALL_METHOD(NULL, &_3$$3, "setimagematte", NULL, 0, &_4$$3);
		zephir_check_call_status();
		zephir_read_property(&_4$$3, this_ptr, ZEND_STRL("image"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_NVAR(&_5$$3);
		ZVAL_STRING(&_5$$3, "Imagick::COMPOSITE_DSTIN");
		ZEPHIR_CALL_FUNCTION(&_6$$3, "constant", &_7, 115, &_5$$3);
		zephir_check_call_status();
		ZVAL_LONG(&_8$$3, 0);
		ZVAL_LONG(&_9$$3, 0);
		ZEPHIR_CALL_METHOD(&result, &_4$$3, "compositeimage", NULL, 0, &mask, &_6$$3, &_8$$3, &_9$$3);
		zephir_check_call_status();
		if (!ZEPHIR_IS_TRUE_IDENTICAL(&result)) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_image_exception_ce, "Imagick::compositeImage failed", "phalcon/Image/Adapter/Imagick.zep", 388);
			return;
		}
		zephir_read_property(&_8$$3, this_ptr, ZEND_STRL("image"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(&_10$$3, &_8$$3, "nextimage", NULL, 0);
		zephir_check_call_status();
		if (!ZEPHIR_IS_TRUE_IDENTICAL(&_10$$3)) {
			break;
		}
	}
	ZEPHIR_CALL_METHOD(NULL, &mask, "clear", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &mask, "destroy", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
}

/**
 * Pixelate image
 *
 * @param int $amount amount to pixelate
 *
 * @return void
 * @throws ImagickException
 */
PHP_METHOD(Phalcon_Image_Adapter_Imagick, processPixelate)
{
	double height = 0, width = 0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *amount_param = NULL, _0, _1, _2, _3, _4$$3, _5$$3, _6$$3, _7$$3, _8$$3, _9$$3;
	zend_long amount, ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_7$$3);
	ZVAL_UNDEF(&_8$$3);
	ZVAL_UNDEF(&_9$$3);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(amount)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &amount_param);
	amount = zephir_get_intval(amount_param);


	zephir_read_property(&_0, this_ptr, ZEND_STRL("width"), PH_NOISY_CC | PH_READONLY);
	width = zephir_safe_div_zval_long(&_0, amount);
	zephir_read_property(&_1, this_ptr, ZEND_STRL("height"), PH_NOISY_CC | PH_READONLY);
	height = zephir_safe_div_zval_long(&_1, amount);
	zephir_read_property(&_2, this_ptr, ZEND_STRL("image"), PH_NOISY_CC | PH_READONLY);
	ZVAL_LONG(&_3, 0);
	ZEPHIR_CALL_METHOD(NULL, &_2, "setiteratorindex", NULL, 0, &_3);
	zephir_check_call_status();
	while (1) {
		if (!(1)) {
			break;
		}
		zephir_read_property(&_4$$3, this_ptr, ZEND_STRL("image"), PH_NOISY_CC | PH_READONLY);
		ZVAL_DOUBLE(&_5$$3, width);
		ZVAL_DOUBLE(&_6$$3, height);
		ZEPHIR_CALL_METHOD(NULL, &_4$$3, "scaleimage", NULL, 0, &_5$$3, &_6$$3);
		zephir_check_call_status();
		zephir_read_property(&_5$$3, this_ptr, ZEND_STRL("image"), PH_NOISY_CC | PH_READONLY);
		zephir_read_property(&_6$$3, this_ptr, ZEND_STRL("width"), PH_NOISY_CC | PH_READONLY);
		zephir_read_property(&_7$$3, this_ptr, ZEND_STRL("height"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(NULL, &_5$$3, "scaleimage", NULL, 0, &_6$$3, &_7$$3);
		zephir_check_call_status();
		zephir_read_property(&_8$$3, this_ptr, ZEND_STRL("image"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(&_9$$3, &_8$$3, "nextimage", NULL, 0);
		zephir_check_call_status();
		if (!ZEPHIR_IS_TRUE_IDENTICAL(&_9$$3)) {
			break;
		}
	}
	ZEPHIR_MM_RESTORE();
}

/**
 * Execute a reflection.
 *
 * @param int  $height
 * @param int  $opacity
 * @param bool $fadeIn
 *
 * @return void
 * @throws Exception
 * @throws ImagickException
 */
PHP_METHOD(Phalcon_Image_Adapter_Imagick, processReflection)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_5 = NULL, *_7 = NULL, *_11 = NULL, *_13 = NULL, *_14 = NULL, *_20 = NULL, *_23 = NULL, *_26 = NULL, *_33 = NULL, *_36 = NULL, *_38 = NULL, *_41 = NULL, *_46 = NULL, *_53 = NULL;
	zend_bool fadeIn, _54$$13;
	zval *height_param = NULL, *opacity_param = NULL, *fadeIn_param = NULL, fade, image, pixel, pseudo, reflection, result, _0, _4, _16, _17, _28, _29, _30, _56, _57, _58, _59, _60, _1$$3, _2$$4, _3$$4, _6$$5, _8$$5, _9$$5, _10$$5, _12$$5, _15$$5, _18$$7, _19$$7, _21$$7, _22$$7, _24$$7, _25$$7, _27$$7, _31$$10, _32$$10, _34$$10, _35$$10, _37$$10, _39$$10, _40$$10, _42$$10, _43$$10, _44$$10, _45$$10, _47$$10, _48$$13, _49$$13, _50$$13, _51$$13, _52$$13, _55$$13;
	zend_long height, opacity, ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&fade);
	ZVAL_UNDEF(&image);
	ZVAL_UNDEF(&pixel);
	ZVAL_UNDEF(&pseudo);
	ZVAL_UNDEF(&reflection);
	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_16);
	ZVAL_UNDEF(&_17);
	ZVAL_UNDEF(&_28);
	ZVAL_UNDEF(&_29);
	ZVAL_UNDEF(&_30);
	ZVAL_UNDEF(&_56);
	ZVAL_UNDEF(&_57);
	ZVAL_UNDEF(&_58);
	ZVAL_UNDEF(&_59);
	ZVAL_UNDEF(&_60);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_6$$5);
	ZVAL_UNDEF(&_8$$5);
	ZVAL_UNDEF(&_9$$5);
	ZVAL_UNDEF(&_10$$5);
	ZVAL_UNDEF(&_12$$5);
	ZVAL_UNDEF(&_15$$5);
	ZVAL_UNDEF(&_18$$7);
	ZVAL_UNDEF(&_19$$7);
	ZVAL_UNDEF(&_21$$7);
	ZVAL_UNDEF(&_22$$7);
	ZVAL_UNDEF(&_24$$7);
	ZVAL_UNDEF(&_25$$7);
	ZVAL_UNDEF(&_27$$7);
	ZVAL_UNDEF(&_31$$10);
	ZVAL_UNDEF(&_32$$10);
	ZVAL_UNDEF(&_34$$10);
	ZVAL_UNDEF(&_35$$10);
	ZVAL_UNDEF(&_37$$10);
	ZVAL_UNDEF(&_39$$10);
	ZVAL_UNDEF(&_40$$10);
	ZVAL_UNDEF(&_42$$10);
	ZVAL_UNDEF(&_43$$10);
	ZVAL_UNDEF(&_44$$10);
	ZVAL_UNDEF(&_45$$10);
	ZVAL_UNDEF(&_47$$10);
	ZVAL_UNDEF(&_48$$13);
	ZVAL_UNDEF(&_49$$13);
	ZVAL_UNDEF(&_50$$13);
	ZVAL_UNDEF(&_51$$13);
	ZVAL_UNDEF(&_52$$13);
	ZVAL_UNDEF(&_55$$13);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_LONG(height)
		Z_PARAM_LONG(opacity)
		Z_PARAM_BOOL(fadeIn)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &height_param, &opacity_param, &fadeIn_param);
	height = zephir_get_intval(height_param);
	opacity = zephir_get_intval(opacity_param);
	fadeIn = zephir_get_boolval(fadeIn_param);


	zephir_read_property(&_0, this_ptr, ZEND_STRL("version"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&reflection);
	if (ZEPHIR_GE_LONG(&_0, 30100)) {
		zephir_read_property(&_1$$3, this_ptr, ZEND_STRL("image"), PH_NOISY_CC | PH_READONLY);
		if (zephir_clone(&reflection, &_1$$3) == FAILURE) {
			RETURN_MM();
		}
	} else {
		zephir_read_property(&_2$$4, this_ptr, ZEND_STRL("image"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(&_3$$4, &_2$$4, "clone", NULL, 0);
		zephir_check_call_status();
		if (zephir_clone(&reflection, &_3$$4) == FAILURE) {
			RETURN_MM();
		}
	}
	ZVAL_LONG(&_4, 0);
	ZEPHIR_CALL_METHOD(NULL, &reflection, "setiteratorindex", NULL, 0, &_4);
	zephir_check_call_status();
	while (1) {
		if (!(1)) {
			break;
		}
		ZEPHIR_CALL_METHOD(NULL, &reflection, "flipimage", &_5, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_6$$5, &reflection, "getimagewidth", &_7, 0);
		zephir_check_call_status();
		ZVAL_LONG(&_8$$5, height);
		ZVAL_LONG(&_9$$5, 0);
		ZVAL_LONG(&_10$$5, 0);
		ZEPHIR_CALL_METHOD(NULL, &reflection, "cropimage", &_11, 0, &_6$$5, &_8$$5, &_9$$5, &_10$$5);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_12$$5, &reflection, "getimagewidth", &_13, 0);
		zephir_check_call_status();
		ZVAL_LONG(&_8$$5, height);
		ZVAL_LONG(&_9$$5, 0);
		ZVAL_LONG(&_10$$5, 0);
		ZEPHIR_CALL_METHOD(NULL, &reflection, "setimagepage", &_14, 0, &_12$$5, &_8$$5, &_9$$5, &_10$$5);
		zephir_check_call_status();
		zephir_read_property(&_8$$5, this_ptr, ZEND_STRL("image"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(&_15$$5, &_8$$5, "nextimage", NULL, 0);
		zephir_check_call_status();
		if (!ZEPHIR_IS_TRUE_IDENTICAL(&_15$$5)) {
			break;
		}
	}
	if (fadeIn) {
		ZEPHIR_INIT_VAR(&pseudo);
		ZVAL_STRING(&pseudo, "gradient:black-transparent");
	} else {
		ZEPHIR_INIT_NVAR(&pseudo);
		ZVAL_STRING(&pseudo, "gradient:transparent-black");
	}
	ZEPHIR_INIT_VAR(&fade);
	object_init_ex(&fade, zephir_get_internal_ce(SL("imagick")));
	ZEPHIR_CALL_METHOD(NULL, &fade, "__construct", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_16, &reflection, "getimagewidth", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_17, &reflection, "getimageheight", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &fade, "newpseudoimage", NULL, 0, &_16, &_17, &pseudo);
	zephir_check_call_status();
	opacity /= 100;
	ZVAL_LONG(&_4, 0);
	ZEPHIR_CALL_METHOD(NULL, &reflection, "setiteratorindex", NULL, 0, &_4);
	zephir_check_call_status();
	while (1) {
		if (!(1)) {
			break;
		}
		ZEPHIR_INIT_NVAR(&_18$$7);
		ZVAL_STRING(&_18$$7, "Imagick::COMPOSITE_DSTOUT");
		ZEPHIR_CALL_FUNCTION(&_19$$7, "constant", &_20, 115, &_18$$7);
		zephir_check_call_status();
		ZVAL_LONG(&_21$$7, 0);
		ZVAL_LONG(&_22$$7, 0);
		ZEPHIR_CALL_METHOD(&result, &reflection, "compositeimage", &_23, 0, &fade, &_19$$7, &_21$$7, &_22$$7);
		zephir_check_call_status();
		if (!ZEPHIR_IS_TRUE_IDENTICAL(&result)) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_image_exception_ce, "Imagick::compositeImage failed", "phalcon/Image/Adapter/Imagick.zep", 495);
			return;
		}
		ZEPHIR_INIT_NVAR(&_18$$7);
		ZVAL_STRING(&_18$$7, "Imagick::EVALUATE_MULTIPLY");
		ZEPHIR_CALL_FUNCTION(&_24$$7, "constant", &_20, 115, &_18$$7);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&_18$$7);
		ZVAL_STRING(&_18$$7, "Imagick::CHANNEL_ALPHA");
		ZEPHIR_CALL_FUNCTION(&_25$$7, "constant", &_20, 115, &_18$$7);
		zephir_check_call_status();
		ZVAL_LONG(&_21$$7, opacity);
		ZEPHIR_CALL_METHOD(NULL, &reflection, "evaluateimage", &_26, 0, &_24$$7, &_21$$7, &_25$$7);
		zephir_check_call_status();
		zephir_read_property(&_21$$7, this_ptr, ZEND_STRL("image"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(&_27$$7, &_21$$7, "nextimage", NULL, 0);
		zephir_check_call_status();
		if (!ZEPHIR_IS_TRUE_IDENTICAL(&_27$$7)) {
			break;
		}
	}
	ZEPHIR_CALL_METHOD(NULL, &fade, "destroy", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&image);
	object_init_ex(&image, zephir_get_internal_ce(SL("imagick")));
	ZEPHIR_CALL_METHOD(NULL, &image, "__construct", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&pixel);
	object_init_ex(&pixel, zephir_get_internal_ce(SL("imagickpixel")));
	ZEPHIR_CALL_METHOD(NULL, &pixel, "__construct", NULL, 0);
	zephir_check_call_status();
	zephir_read_property(&_4, this_ptr, ZEND_STRL("image"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_28, &_4, "getimageheight", NULL, 0);
	zephir_check_call_status();
	height = (zephir_get_numberval(&_28) + height);
	zephir_read_property(&_29, this_ptr, ZEND_STRL("image"), PH_NOISY_CC | PH_READONLY);
	ZVAL_LONG(&_30, 0);
	ZEPHIR_CALL_METHOD(NULL, &_29, "setiteratorindex", NULL, 0, &_30);
	zephir_check_call_status();
	while (1) {
		if (!(1)) {
			break;
		}
		zephir_read_property(&_31$$10, this_ptr, ZEND_STRL("width"), PH_NOISY_CC | PH_READONLY);
		ZVAL_LONG(&_32$$10, height);
		ZEPHIR_CALL_METHOD(NULL, &image, "newimage", &_33, 0, &_31$$10, &_32$$10, &pixel);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&_34$$10);
		ZVAL_STRING(&_34$$10, "Imagick::ALPHACHANNEL_SET");
		ZEPHIR_CALL_FUNCTION(&_35$$10, "constant", &_20, 115, &_34$$10);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &image, "setimagealphachannel", &_36, 0, &_35$$10);
		zephir_check_call_status();
		zephir_read_property(&_32$$10, this_ptr, ZEND_STRL("image"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(&_37$$10, &_32$$10, "getcolorspace", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &image, "setcolorspace", &_38, 0, &_37$$10);
		zephir_check_call_status();
		zephir_read_property(&_39$$10, this_ptr, ZEND_STRL("image"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(&_40$$10, &_39$$10, "getimagedelay", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &image, "setimagedelay", &_41, 0, &_40$$10);
		zephir_check_call_status();
		zephir_read_property(&_42$$10, this_ptr, ZEND_STRL("image"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_NVAR(&_34$$10);
		ZVAL_STRING(&_34$$10, "Imagick::COMPOSITE_SRC");
		ZEPHIR_CALL_FUNCTION(&_43$$10, "constant", &_20, 115, &_34$$10);
		zephir_check_call_status();
		ZVAL_LONG(&_44$$10, 0);
		ZVAL_LONG(&_45$$10, 0);
		ZEPHIR_CALL_METHOD(&result, &image, "compositeimage", &_46, 0, &_42$$10, &_43$$10, &_44$$10, &_45$$10);
		zephir_check_call_status();
		if (!ZEPHIR_IS_TRUE_IDENTICAL(&result)) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_image_exception_ce, "Imagick::compositeImage failed", "phalcon/Image/Adapter/Imagick.zep", 534);
			return;
		}
		zephir_read_property(&_44$$10, this_ptr, ZEND_STRL("image"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(&_47$$10, &_44$$10, "nextimage", NULL, 0);
		zephir_check_call_status();
		if (!ZEPHIR_IS_TRUE_IDENTICAL(&_47$$10)) {
			break;
		}
	}
	ZVAL_LONG(&_30, 0);
	ZEPHIR_CALL_METHOD(NULL, &image, "setiteratorindex", NULL, 0, &_30);
	zephir_check_call_status();
	ZVAL_LONG(&_30, 0);
	ZEPHIR_CALL_METHOD(NULL, &reflection, "setiteratorindex", NULL, 0, &_30);
	zephir_check_call_status();
	while (1) {
		if (!(1)) {
			break;
		}
		ZEPHIR_INIT_NVAR(&_48$$13);
		ZVAL_STRING(&_48$$13, "Imagick::COMPOSITE_OVER");
		ZEPHIR_CALL_FUNCTION(&_49$$13, "constant", &_20, 115, &_48$$13);
		zephir_check_call_status();
		zephir_read_property(&_50$$13, this_ptr, ZEND_STRL("height"), PH_NOISY_CC | PH_READONLY);
		ZVAL_LONG(&_51$$13, 0);
		ZEPHIR_CALL_METHOD(&result, &image, "compositeimage", &_46, 0, &reflection, &_49$$13, &_51$$13, &_50$$13);
		zephir_check_call_status();
		if (!ZEPHIR_IS_TRUE_IDENTICAL(&result)) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_image_exception_ce, "Imagick::compositeImage failed", "phalcon/Image/Adapter/Imagick.zep", 554);
			return;
		}
		ZEPHIR_CALL_METHOD(&_52$$13, &image, "nextimage", &_53, 0);
		zephir_check_call_status();
		_54$$13 = !ZEPHIR_IS_TRUE_IDENTICAL(&_52$$13);
		if (!(_54$$13)) {
			ZEPHIR_CALL_METHOD(&_55$$13, &reflection, "nextimage", NULL, 0);
			zephir_check_call_status();
			_54$$13 = !ZEPHIR_IS_TRUE_IDENTICAL(&_55$$13);
		}
		if (_54$$13) {
			break;
		}
	}
	ZEPHIR_CALL_METHOD(NULL, &reflection, "destroy", NULL, 0);
	zephir_check_call_status();
	zephir_read_property(&_30, this_ptr, ZEND_STRL("image"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, &_30, "clear", NULL, 0);
	zephir_check_call_status();
	zephir_read_property(&_56, this_ptr, ZEND_STRL("image"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, &_56, "destroy", NULL, 0);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, ZEND_STRL("image"), &image);
	zephir_read_property(&_57, this_ptr, ZEND_STRL("image"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_58, &_57, "getimagewidth", NULL, 0);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, ZEND_STRL("width"), &_58);
	zephir_read_property(&_59, this_ptr, ZEND_STRL("image"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_60, &_59, "getimageheight", NULL, 0);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, ZEND_STRL("height"), &_60);
	ZEPHIR_MM_RESTORE();
}

/**
 * Execute a render.
 *
 * @param string $extension
 * @param int    $quality
 *
 * @return string
 * @throws ImagickException
 */
PHP_METHOD(Phalcon_Image_Adapter_Imagick, processRender)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long quality, ZEPHIR_LAST_CALL_STATUS;
	zval *extension_param = NULL, *quality_param = NULL, image, _0, _1, _2, _3, _4, _5$$4, _6$$4, _7$$4;
	zval extension;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&extension);
	ZVAL_UNDEF(&image);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_7$$4);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR(extension)
		Z_PARAM_LONG(quality)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &extension_param, &quality_param);
	zephir_get_strval(&extension, extension_param);
	quality = zephir_get_intval(quality_param);


	zephir_read_property(&_0, this_ptr, ZEND_STRL("image"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&image, &_0);
	ZEPHIR_CALL_METHOD(NULL, &image, "setformat", NULL, 0, &extension);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &image, "setimageformat", NULL, 0, &extension);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &image, "stripimage", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_1, &image, "getimagetype", NULL, 0);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, ZEND_STRL("type"), &_1);
	ZEPHIR_CALL_METHOD(&_2, &image, "getimageformat", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_3);
	ZEPHIR_CONCAT_SV(&_3, "image/", &_2);
	zephir_update_property_zval(this_ptr, ZEND_STRL("mime"), &_3);
	ZEPHIR_INIT_VAR(&_4);
	zephir_fast_strtolower(&_4, &extension);
	zephir_get_strval(&extension, &_4);
	do {
		if (ZEPHIR_IS_STRING(&extension, "gif")) {
			ZEPHIR_CALL_METHOD(NULL, &image, "optimizeimagelayers", NULL, 0);
			zephir_check_call_status();
			break;
		}
		if (ZEPHIR_IS_STRING(&extension, "jpg") || ZEPHIR_IS_STRING(&extension, "jpeg")) {
			ZEPHIR_INIT_VAR(&_5$$4);
			ZVAL_STRING(&_5$$4, "Imagick::COMPRESSION_JPEG");
			ZEPHIR_CALL_FUNCTION(&_6$$4, "constant", NULL, 115, &_5$$4);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, &image, "setimagecompression", NULL, 0, &_6$$4);
			zephir_check_call_status();
			ZVAL_LONG(&_7$$4, quality);
			ZEPHIR_CALL_METHOD(NULL, &image, "setimagecompressionquality", NULL, 0, &_7$$4);
			zephir_check_call_status();
		}
	} while(0);

	ZEPHIR_RETURN_CALL_METHOD(&image, "getimageblob", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Execute a resize.
 *
 * @param int $width
 * @param int $height
 *
 * @return void
 * @throws ImagickException
 */
PHP_METHOD(Phalcon_Image_Adapter_Imagick, processResize)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_3 = NULL, *_5 = NULL;
	zval *width_param = NULL, *height_param = NULL, image, _0, _6, _7, _1$$3, _2$$3, _4$$3;
	zend_long width, height, ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&image);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_4$$3);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(width)
		Z_PARAM_LONG(height)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &width_param, &height_param);
	width = zephir_get_intval(width_param);
	height = zephir_get_intval(height_param);


	zephir_read_property(&_0, this_ptr, ZEND_STRL("image"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&image, &_0);
	ZVAL_LONG(&_0, 0);
	ZEPHIR_CALL_METHOD(NULL, &image, "setiteratorindex", NULL, 0, &_0);
	zephir_check_call_status();
	while (1) {
		if (!(1)) {
			break;
		}
		ZVAL_LONG(&_1$$3, width);
		ZVAL_LONG(&_2$$3, height);
		ZEPHIR_CALL_METHOD(NULL, &image, "scaleimage", &_3, 0, &_1$$3, &_2$$3);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_4$$3, &image, "nextimage", &_5, 0);
		zephir_check_call_status();
		if (!ZEPHIR_IS_TRUE_IDENTICAL(&_4$$3)) {
			break;
		}
	}
	ZEPHIR_CALL_METHOD(&_6, &image, "getimagewidth", NULL, 0);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, ZEND_STRL("width"), &_6);
	ZEPHIR_CALL_METHOD(&_7, &image, "getimageheight", NULL, 0);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, ZEND_STRL("height"), &_7);
	ZEPHIR_MM_RESTORE();
}

/**
 * Execute a rotation.
 *
 * @param int $degrees
 *
 * @return void
 * @throws ImagickException
 */
PHP_METHOD(Phalcon_Image_Adapter_Imagick, processRotate)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *degrees_param = NULL, pixel, _0, _1, _9, _10, _11, _2$$3, _3$$3, _4$$3, _5$$3, _6$$3, _7$$3, _8$$3;
	zend_long degrees, ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&pixel);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_11);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_7$$3);
	ZVAL_UNDEF(&_8$$3);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(degrees)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &degrees_param);
	degrees = zephir_get_intval(degrees_param);


	zephir_read_property(&_0, this_ptr, ZEND_STRL("image"), PH_NOISY_CC | PH_READONLY);
	ZVAL_LONG(&_1, 0);
	ZEPHIR_CALL_METHOD(NULL, &_0, "setiteratorindex", NULL, 0, &_1);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&pixel);
	object_init_ex(&pixel, zephir_get_internal_ce(SL("imagickpixel")));
	ZEPHIR_CALL_METHOD(NULL, &pixel, "__construct", NULL, 0);
	zephir_check_call_status();
	while (1) {
		if (!(1)) {
			break;
		}
		zephir_read_property(&_2$$3, this_ptr, ZEND_STRL("image"), PH_NOISY_CC | PH_READONLY);
		ZVAL_LONG(&_3$$3, degrees);
		ZEPHIR_CALL_METHOD(NULL, &_2$$3, "rotateimage", NULL, 0, &pixel, &_3$$3);
		zephir_check_call_status();
		zephir_read_property(&_3$$3, this_ptr, ZEND_STRL("image"), PH_NOISY_CC | PH_READONLY);
		zephir_read_property(&_4$$3, this_ptr, ZEND_STRL("width"), PH_NOISY_CC | PH_READONLY);
		zephir_read_property(&_5$$3, this_ptr, ZEND_STRL("height"), PH_NOISY_CC | PH_READONLY);
		ZVAL_LONG(&_6$$3, 0);
		ZVAL_LONG(&_7$$3, 0);
		ZEPHIR_CALL_METHOD(NULL, &_3$$3, "setimagepage", NULL, 0, &_4$$3, &_5$$3, &_6$$3, &_7$$3);
		zephir_check_call_status();
		zephir_read_property(&_6$$3, this_ptr, ZEND_STRL("image"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(&_8$$3, &_6$$3, "nextimage", NULL, 0);
		zephir_check_call_status();
		if (!ZEPHIR_IS_TRUE_IDENTICAL(&_8$$3)) {
			break;
		}
	}
	zephir_read_property(&_1, this_ptr, ZEND_STRL("image"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_9, &_1, "getimagewidth", NULL, 0);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, ZEND_STRL("width"), &_9);
	zephir_read_property(&_10, this_ptr, ZEND_STRL("image"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_11, &_10, "getimageheight", NULL, 0);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, ZEND_STRL("height"), &_11);
	ZEPHIR_MM_RESTORE();
}

/**
 * Execute a save.
 *
 * @param string $file
 * @param int    $quality
 *
 * @return void
 * @throws ImagickException
 */
PHP_METHOD(Phalcon_Image_Adapter_Imagick, processSave)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long quality, ZEPHIR_LAST_CALL_STATUS;
	zval *file_param = NULL, *quality_param = NULL, extension, fp, _0, _1, _2, _3, _4, _5, _6, _7, _17, _8$$3, _9$$3, _10$$3, _11$$4, _12$$4, _13$$4, _14$$5, _15$$5, _16$$5;
	zval file;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&file);
	ZVAL_UNDEF(&extension);
	ZVAL_UNDEF(&fp);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_17);
	ZVAL_UNDEF(&_8$$3);
	ZVAL_UNDEF(&_9$$3);
	ZVAL_UNDEF(&_10$$3);
	ZVAL_UNDEF(&_11$$4);
	ZVAL_UNDEF(&_12$$4);
	ZVAL_UNDEF(&_13$$4);
	ZVAL_UNDEF(&_14$$5);
	ZVAL_UNDEF(&_15$$5);
	ZVAL_UNDEF(&_16$$5);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR(file)
		Z_PARAM_LONG(quality)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &file_param, &quality_param);
	zephir_get_strval(&file, file_param);
	quality = zephir_get_intval(quality_param);


	ZVAL_LONG(&_0, 4);
	ZEPHIR_CALL_FUNCTION(&extension, "pathinfo", NULL, 85, &file, &_0);
	zephir_check_call_status();
	zephir_read_property(&_0, this_ptr, ZEND_STRL("image"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, &_0, "setformat", NULL, 0, &extension);
	zephir_check_call_status();
	zephir_read_property(&_1, this_ptr, ZEND_STRL("image"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, &_1, "setimageformat", NULL, 0, &extension);
	zephir_check_call_status();
	zephir_read_property(&_2, this_ptr, ZEND_STRL("image"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_3, &_2, "getimagetype", NULL, 0);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, ZEND_STRL("type"), &_3);
	zephir_read_property(&_4, this_ptr, ZEND_STRL("image"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_5, &_4, "getimageformat", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_6);
	ZEPHIR_CONCAT_SV(&_6, "image/", &_5);
	zephir_update_property_zval(this_ptr, ZEND_STRL("mime"), &_6);
	ZEPHIR_INIT_VAR(&_7);
	zephir_fast_strtolower(&_7, &extension);
	ZEPHIR_CPY_WRT(&extension, &_7);
	do {
		if (ZEPHIR_IS_STRING(&extension, "gif")) {
			zephir_read_property(&_8$$3, this_ptr, ZEND_STRL("image"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_CALL_METHOD(NULL, &_8$$3, "optimizeimagelayers", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(&_9$$3);
			ZVAL_STRING(&_9$$3, "w");
			ZEPHIR_CALL_FUNCTION(&fp, "fopen", NULL, 135, &file, &_9$$3);
			zephir_check_call_status();
			zephir_read_property(&_10$$3, this_ptr, ZEND_STRL("image"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_CALL_METHOD(NULL, &_10$$3, "writeimagesfile", NULL, 0, &fp);
			zephir_check_call_status();
			zephir_fclose(&fp);
			RETURN_MM_NULL();
		}
		if (ZEPHIR_IS_STRING(&extension, "jpg") || ZEPHIR_IS_STRING(&extension, "jpeg")) {
			zephir_read_property(&_11$$4, this_ptr, ZEND_STRL("image"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_INIT_VAR(&_12$$4);
			ZVAL_STRING(&_12$$4, "Imagick::COMPRESSION_JPEG");
			ZEPHIR_CALL_FUNCTION(&_13$$4, "constant", NULL, 115, &_12$$4);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, &_11$$4, "setimagecompression", NULL, 0, &_13$$4);
			zephir_check_call_status();
		}
	} while(0);

	if (quality >= 0) {
		ZVAL_LONG(&_15$$5, quality);
		ZVAL_LONG(&_16$$5, 1);
		ZEPHIR_CALL_METHOD(&_14$$5, this_ptr, "checkhighlow", NULL, 0, &_15$$5, &_16$$5);
		zephir_check_call_status();
		quality = zephir_get_numberval(&_14$$5);
		zephir_read_property(&_15$$5, this_ptr, ZEND_STRL("image"), PH_NOISY_CC | PH_READONLY);
		ZVAL_LONG(&_16$$5, quality);
		ZEPHIR_CALL_METHOD(NULL, &_15$$5, "setimagecompressionquality", NULL, 0, &_16$$5);
		zephir_check_call_status();
	}
	zephir_read_property(&_17, this_ptr, ZEND_STRL("image"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, &_17, "writeimage", NULL, 0, &file);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
}

/**
 * Execute a sharpen.
 *
 * @param int $amount
 *
 * @return void
 * @throws ImagickException
 */
PHP_METHOD(Phalcon_Image_Adapter_Imagick, processSharpen)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *amount_param = NULL, _0, _1, _2, _3$$3, _4$$3, _5$$3, _6$$3;
	zend_long amount, ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_6$$3);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(amount)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &amount_param);
	amount = zephir_get_intval(amount_param);


	ZEPHIR_INIT_VAR(&_0);
	if (amount < 5) {
		ZEPHIR_INIT_NVAR(&_0);
		ZVAL_LONG(&_0, 5);
	} else {
		ZEPHIR_INIT_NVAR(&_0);
		ZVAL_LONG(&_0, amount);
	}
	amount = zephir_get_numberval(&_0);
	amount = (long) (zephir_safe_div_long_long(((amount * 3.0)), 100));
	zephir_read_property(&_1, this_ptr, ZEND_STRL("image"), PH_NOISY_CC | PH_READONLY);
	ZVAL_LONG(&_2, 0);
	ZEPHIR_CALL_METHOD(NULL, &_1, "setiteratorindex", NULL, 0, &_2);
	zephir_check_call_status();
	while (1) {
		if (!(1)) {
			break;
		}
		zephir_read_property(&_3$$3, this_ptr, ZEND_STRL("image"), PH_NOISY_CC | PH_READONLY);
		ZVAL_LONG(&_4$$3, 0);
		ZVAL_LONG(&_5$$3, amount);
		ZEPHIR_CALL_METHOD(NULL, &_3$$3, "sharpenimage", NULL, 0, &_4$$3, &_5$$3);
		zephir_check_call_status();
		zephir_read_property(&_4$$3, this_ptr, ZEND_STRL("image"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(&_6$$3, &_4$$3, "nextimage", NULL, 0);
		zephir_check_call_status();
		if (!ZEPHIR_IS_TRUE_IDENTICAL(&_6$$3)) {
			break;
		}
	}
	ZEPHIR_MM_RESTORE();
}

/**
 * Execute a text
 *
 * @param string      $text
 * @param mixed       $offsetX
 * @param mixed       $offsetY
 * @param int         $opacity
 * @param int         $red
 * @param int         $green
 * @param int         $blue
 * @param int         $size
 * @param string|null $fontFile
 *
 * @return void
 * @throws ImagickDrawException
 * @throws ImagickException
 * @throws ImagickPixelException
 */
PHP_METHOD(Phalcon_Image_Adapter_Imagick, processText)
{
	zend_bool _7$$8, _9$$8, _10$$8, _11$$8, _12$$11, _14$$11, _15$$11, _16$$11;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long opacity, red, green, blue, size, ZEPHIR_LAST_CALL_STATUS;
	zval *text_param = NULL, *offsetX = NULL, offsetX_sub, *offsetY = NULL, offsetY_sub, *opacity_param = NULL, *red_param = NULL, *green_param = NULL, *blue_param = NULL, *size_param = NULL, *fontFile_param = NULL, color, draw, gravity, x, y, _0, _1, _2, _3, _4$$4, _5$$5, _6$$7, _8$$8, _13$$11, _17$$12, _18$$14, _19$$14, _20$$14;
	zval text, fontFile;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&text);
	ZVAL_UNDEF(&fontFile);
	ZVAL_UNDEF(&offsetX_sub);
	ZVAL_UNDEF(&offsetY_sub);
	ZVAL_UNDEF(&color);
	ZVAL_UNDEF(&draw);
	ZVAL_UNDEF(&gravity);
	ZVAL_UNDEF(&x);
	ZVAL_UNDEF(&y);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&_6$$7);
	ZVAL_UNDEF(&_8$$8);
	ZVAL_UNDEF(&_13$$11);
	ZVAL_UNDEF(&_17$$12);
	ZVAL_UNDEF(&_18$$14);
	ZVAL_UNDEF(&_19$$14);
	ZVAL_UNDEF(&_20$$14);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(8, 9)
		Z_PARAM_STR(text)
		Z_PARAM_ZVAL(offsetX)
		Z_PARAM_ZVAL(offsetY)
		Z_PARAM_LONG(opacity)
		Z_PARAM_LONG(red)
		Z_PARAM_LONG(green)
		Z_PARAM_LONG(blue)
		Z_PARAM_LONG(size)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR_OR_NULL(fontFile)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 8, 1, &text_param, &offsetX, &offsetY, &opacity_param, &red_param, &green_param, &blue_param, &size_param, &fontFile_param);
	zephir_get_strval(&text, text_param);
	ZEPHIR_SEPARATE_PARAM(offsetX);
	ZEPHIR_SEPARATE_PARAM(offsetY);
	opacity = zephir_get_intval(opacity_param);
	red = zephir_get_intval(red_param);
	green = zephir_get_intval(green_param);
	blue = zephir_get_intval(blue_param);
	size = zephir_get_intval(size_param);
	if (!fontFile_param) {
		ZEPHIR_INIT_VAR(&fontFile);
	} else {
		zephir_get_strval(&fontFile, fontFile_param);
	}


	opacity = (long) (zephir_safe_div_long_long(opacity, 100));
	ZEPHIR_INIT_VAR(&draw);
	object_init_ex(&draw, zephir_get_internal_ce(SL("imagickdraw")));
	ZEPHIR_CALL_METHOD(NULL, &draw, "__construct", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "rgb(%d, %d, %d)");
	ZVAL_LONG(&_1, red);
	ZVAL_LONG(&_2, green);
	ZVAL_LONG(&_3, blue);
	ZEPHIR_CALL_FUNCTION(&color, "sprintf", NULL, 113, &_0, &_1, &_2, &_3);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_0);
	object_init_ex(&_0, zephir_get_internal_ce(SL("imagickpixel")));
	ZEPHIR_CALL_METHOD(NULL, &_0, "__construct", NULL, 0, &color);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &draw, "setfillcolor", NULL, 0, &_0);
	zephir_check_call_status();
	if (Z_TYPE_P(&fontFile) != IS_NULL) {
		ZEPHIR_CALL_METHOD(NULL, &draw, "setfont", NULL, 0, &fontFile);
		zephir_check_call_status();
	}
	if (size) {
		ZVAL_LONG(&_4$$4, size);
		ZEPHIR_CALL_METHOD(NULL, &draw, "setfontsize", NULL, 0, &_4$$4);
		zephir_check_call_status();
	}
	if (opacity) {
		ZVAL_LONG(&_5$$5, opacity);
		ZEPHIR_CALL_METHOD(NULL, &draw, "setfillopacity", NULL, 0, &_5$$5);
		zephir_check_call_status();
	}
	ZEPHIR_INIT_VAR(&gravity);
	ZVAL_NULL(&gravity);
	if (((Z_TYPE_P(offsetX) == IS_TRUE || Z_TYPE_P(offsetX) == IS_FALSE) == 1)) {
		if (((Z_TYPE_P(offsetY) == IS_TRUE || Z_TYPE_P(offsetY) == IS_FALSE) == 1)) {
			ZEPHIR_INIT_NVAR(offsetX);
			ZVAL_LONG(offsetX, 0);
			ZEPHIR_INIT_NVAR(offsetY);
			ZVAL_LONG(offsetY, 0);
			ZEPHIR_INIT_VAR(&_6$$7);
			ZVAL_STRING(&_6$$7, "Imagick::GRAVITY_CENTER");
			ZEPHIR_CALL_FUNCTION(&gravity, "constant", NULL, 115, &_6$$7);
			zephir_check_call_status();
		} else if (Z_TYPE_P(offsetY) == IS_LONG) {
			ZEPHIR_INIT_VAR(&y);
			ZVAL_LONG(&y, zephir_get_intval(offsetY));
			_7$$8 = ZEPHIR_IS_TRUE_IDENTICAL(offsetX);
			if (_7$$8) {
				_7$$8 = ZEPHIR_LT_LONG(&y, 0);
			}
			if (_7$$8) {
				ZEPHIR_INIT_VAR(&_8$$8);
				ZVAL_STRING(&_8$$8, "Imagick::GRAVITY_SOUTHEAST");
				ZEPHIR_CALL_FUNCTION(&gravity, "constant", NULL, 115, &_8$$8);
				zephir_check_call_status();
			} else {
			}
			_9$$8 = ZEPHIR_IS_TRUE_IDENTICAL(offsetX);
			if (_9$$8) {
				_9$$8 = ZEPHIR_GE_LONG(&y, 0);
			}
			if (_9$$8) {
				ZEPHIR_INIT_NVAR(&_8$$8);
				ZVAL_STRING(&_8$$8, "Imagick::GRAVITY_NORTHEAST");
				ZEPHIR_CALL_FUNCTION(&gravity, "constant", NULL, 115, &_8$$8);
				zephir_check_call_status();
			} else {
			}
			_10$$8 = !ZEPHIR_IS_TRUE_IDENTICAL(offsetX);
			if (_10$$8) {
				_10$$8 = ZEPHIR_LT_LONG(&y, 0);
			}
			if (_10$$8) {
				ZEPHIR_INIT_NVAR(&_8$$8);
				ZVAL_STRING(&_8$$8, "Imagick::GRAVITY_SOUTH");
				ZEPHIR_CALL_FUNCTION(&gravity, "constant", NULL, 115, &_8$$8);
				zephir_check_call_status();
			} else {
			}
			_11$$8 = !ZEPHIR_IS_TRUE_IDENTICAL(offsetX);
			if (_11$$8) {
				_11$$8 = ZEPHIR_GE_LONG(&y, 0);
			}
			if (_11$$8) {
				ZEPHIR_INIT_NVAR(&_8$$8);
				ZVAL_STRING(&_8$$8, "Imagick::GRAVITY_NORTH");
				ZEPHIR_CALL_FUNCTION(&gravity, "constant", NULL, 115, &_8$$8);
				zephir_check_call_status();
			} else {
			}
			ZEPHIR_INIT_NVAR(offsetX);
			ZVAL_LONG(offsetX, 0);
			if (ZEPHIR_LT_LONG(&y, 0)) {
				ZEPHIR_INIT_NVAR(offsetY);
				ZVAL_LONG(offsetY, (zephir_get_numberval(&y) * -1));
			} else {
			}
		}
	} else if (Z_TYPE_P(offsetX) == IS_LONG) {
		ZEPHIR_INIT_VAR(&x);
		ZVAL_LONG(&x, zephir_get_intval(offsetX));
		if (zephir_is_true(offsetX)) {
			if (((Z_TYPE_P(offsetY) == IS_TRUE || Z_TYPE_P(offsetY) == IS_FALSE) == 1)) {
				_12$$11 = ZEPHIR_IS_TRUE_IDENTICAL(offsetY);
				if (_12$$11) {
					_12$$11 = ZEPHIR_LT_LONG(&x, 0);
				}
				if (_12$$11) {
					ZEPHIR_INIT_VAR(&_13$$11);
					ZVAL_STRING(&_13$$11, "Imagick::GRAVITY_SOUTHEAST");
					ZEPHIR_CALL_FUNCTION(&gravity, "constant", NULL, 115, &_13$$11);
					zephir_check_call_status();
				} else {
				}
				_14$$11 = ZEPHIR_IS_TRUE_IDENTICAL(offsetY);
				if (_14$$11) {
					_14$$11 = ZEPHIR_GE_LONG(&x, 0);
				}
				if (_14$$11) {
					ZEPHIR_INIT_NVAR(&_13$$11);
					ZVAL_STRING(&_13$$11, "Imagick::GRAVITY_SOUTH");
					ZEPHIR_CALL_FUNCTION(&gravity, "constant", NULL, 115, &_13$$11);
					zephir_check_call_status();
				} else {
				}
				_15$$11 = !ZEPHIR_IS_TRUE_IDENTICAL(offsetY);
				if (_15$$11) {
					_15$$11 = ZEPHIR_LT_LONG(&x, 0);
				}
				if (_15$$11) {
					ZEPHIR_INIT_NVAR(&_13$$11);
					ZVAL_STRING(&_13$$11, "Imagick::GRAVITY_EAST");
					ZEPHIR_CALL_FUNCTION(&gravity, "constant", NULL, 115, &_13$$11);
					zephir_check_call_status();
				} else {
				}
				_16$$11 = !ZEPHIR_IS_TRUE_IDENTICAL(offsetY);
				if (_16$$11) {
					_16$$11 = ZEPHIR_GE_LONG(&x, 0);
				}
				if (_16$$11) {
					ZEPHIR_INIT_NVAR(&_13$$11);
					ZVAL_STRING(&_13$$11, "Imagick::GRAVITY_WEST");
					ZEPHIR_CALL_FUNCTION(&gravity, "constant", NULL, 115, &_13$$11);
					zephir_check_call_status();
				} else {
				}
				ZEPHIR_INIT_NVAR(offsetY);
				ZVAL_LONG(offsetY, 0);
				if (ZEPHIR_LT_LONG(&x, 0)) {
					ZEPHIR_INIT_NVAR(offsetX);
					ZVAL_LONG(offsetX, (zephir_get_numberval(&x) * -1));
				} else {
				}
			} else if (Z_TYPE_P(offsetY) == IS_LONG) {
				ZEPHIR_INIT_NVAR(&y);
				ZVAL_LONG(&y, zephir_get_intval(offsetY));
				if (ZEPHIR_LT_LONG(&x, 0)) {
					ZEPHIR_INIT_NVAR(offsetX);
					ZVAL_LONG(offsetX, (zephir_get_numberval(&x) * -1));
				} else {
					ZEPHIR_INIT_NVAR(offsetX);
					ZVAL_LONG(offsetX, 0);
				}
				if (ZEPHIR_LT_LONG(&y, 0)) {
					ZEPHIR_INIT_NVAR(offsetY);
					ZVAL_LONG(offsetY, (zephir_get_numberval(&y) * -1));
				} else {
				}
				if (ZEPHIR_LT_LONG(&y, 0)) {
					ZEPHIR_INIT_VAR(&_17$$12);
					ZVAL_STRING(&_17$$12, "Imagick::GRAVITY_SOUTHEAST");
					ZEPHIR_CALL_FUNCTION(&gravity, "constant", NULL, 115, &_17$$12);
					zephir_check_call_status();
				} else {
				}
				if (ZEPHIR_GE_LONG(&y, 0)) {
					ZEPHIR_INIT_NVAR(&_17$$12);
					ZVAL_STRING(&_17$$12, "Imagick::GRAVITY_NORTHEAST");
					ZEPHIR_CALL_FUNCTION(&gravity, "constant", NULL, 115, &_17$$12);
					zephir_check_call_status();
				} else {
				}
			}
		}
	}
	if (Z_TYPE_P(&gravity) != IS_NULL) {
		ZEPHIR_CALL_METHOD(NULL, &draw, "setgravity", NULL, 0, &gravity);
		zephir_check_call_status();
	}
	zephir_read_property(&_1, this_ptr, ZEND_STRL("image"), PH_NOISY_CC | PH_READONLY);
	ZVAL_LONG(&_2, 0);
	ZEPHIR_CALL_METHOD(NULL, &_1, "setiteratorindex", NULL, 0, &_2);
	zephir_check_call_status();
	while (1) {
		if (!(1)) {
			break;
		}
		zephir_read_property(&_18$$14, this_ptr, ZEND_STRL("image"), PH_NOISY_CC | PH_READONLY);
		ZVAL_LONG(&_19$$14, 0);
		ZEPHIR_CALL_METHOD(NULL, &_18$$14, "annotateimage", NULL, 0, &draw, offsetX, offsetY, &_19$$14, &text);
		zephir_check_call_status();
		zephir_read_property(&_19$$14, this_ptr, ZEND_STRL("image"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(&_20$$14, &_19$$14, "nextimage", NULL, 0);
		zephir_check_call_status();
		if (!ZEPHIR_IS_TRUE_IDENTICAL(&_20$$14)) {
			break;
		}
	}
	ZEPHIR_CALL_METHOD(NULL, &draw, "destroy", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
}

/**
 * Add Watermark
 *
 * @param AdapterInterface $image
 * @param int              $offsetX
 * @param int              $offsetY
 * @param int              $opacity
 *
 * @return void
 * @throws Exception
 * @throws ImagickException
 */
PHP_METHOD(Phalcon_Image_Adapter_Imagick, processWatermark)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long offsetX, offsetY, opacity, ZEPHIR_LAST_CALL_STATUS;
	zval *image, image_sub, *offsetX_param = NULL, *offsetY_param = NULL, *opacity_param = NULL, result, watermark, _0, _1, _2, _3, _4, _5, _6$$3, _7$$3, _8$$3, _9$$3, _10$$3, _11$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&image_sub);
	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&watermark);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_7$$3);
	ZVAL_UNDEF(&_8$$3);
	ZVAL_UNDEF(&_9$$3);
	ZVAL_UNDEF(&_10$$3);
	ZVAL_UNDEF(&_11$$3);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_OBJECT_OF_CLASS(image, phalcon_image_adapter_adapterinterface_ce)
		Z_PARAM_LONG(offsetX)
		Z_PARAM_LONG(offsetY)
		Z_PARAM_LONG(opacity)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 4, 0, &image, &offsetX_param, &offsetY_param, &opacity_param);
	offsetX = zephir_get_intval(offsetX_param);
	offsetY = zephir_get_intval(offsetY_param);
	opacity = zephir_get_intval(opacity_param);


	opacity = (long) (zephir_safe_div_long_long(opacity, 100));
	ZEPHIR_INIT_VAR(&watermark);
	object_init_ex(&watermark, zephir_get_internal_ce(SL("imagick")));
	ZEPHIR_CALL_METHOD(NULL, &watermark, "__construct", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_0, image, "render", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &watermark, "readimageblob", NULL, 0, &_0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "Imagick::EVALUATE_MULTIPLY");
	ZEPHIR_CALL_FUNCTION(&_2, "constant", NULL, 115, &_1);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "Imagick::CHANNEL_ALPHA");
	ZEPHIR_CALL_FUNCTION(&_3, "constant", NULL, 115, &_1);
	zephir_check_call_status();
	ZVAL_LONG(&_4, opacity);
	ZEPHIR_CALL_METHOD(NULL, &watermark, "evaluateimage", NULL, 0, &_2, &_4, &_3);
	zephir_check_call_status();
	zephir_read_property(&_4, this_ptr, ZEND_STRL("image"), PH_NOISY_CC | PH_READONLY);
	ZVAL_LONG(&_5, 0);
	ZEPHIR_CALL_METHOD(NULL, &_4, "setiteratorindex", NULL, 0, &_5);
	zephir_check_call_status();
	while (1) {
		if (!(1)) {
			break;
		}
		zephir_read_property(&_6$$3, this_ptr, ZEND_STRL("image"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_NVAR(&_7$$3);
		ZVAL_STRING(&_7$$3, "Imagick::COMPOSITE_OVER");
		ZEPHIR_CALL_FUNCTION(&_8$$3, "constant", NULL, 115, &_7$$3);
		zephir_check_call_status();
		ZVAL_LONG(&_9$$3, offsetX);
		ZVAL_LONG(&_10$$3, offsetY);
		ZEPHIR_CALL_METHOD(&result, &_6$$3, "compositeimage", NULL, 0, &watermark, &_8$$3, &_9$$3, &_10$$3);
		zephir_check_call_status();
		if (!ZEPHIR_IS_TRUE_IDENTICAL(&result)) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_image_exception_ce, "Imagick::compositeImage failed", "phalcon/Image/Adapter/Imagick.zep", 893);
			return;
		}
		zephir_read_property(&_9$$3, this_ptr, ZEND_STRL("image"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(&_11$$3, &_9$$3, "nextimage", NULL, 0);
		zephir_check_call_status();
		if (!ZEPHIR_IS_TRUE_IDENTICAL(&_11$$3)) {
			break;
		}
	}
	ZEPHIR_CALL_METHOD(NULL, &watermark, "clear", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &watermark, "destroy", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
}

/**
 * Checks if Imagick is enabled
 *
 * @return void
 * @throws Exception
 */
PHP_METHOD(Phalcon_Image_Adapter_Imagick, check)
{
	zval _0, _1, _2, _3$$4, _4$$4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_4$$4);


	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "imagick");
	if (1 != zephir_class_exists(&_0, 1)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_image_exception_ce, "Imagick is not installed, or the extension is not loaded", "phalcon/Image/Adapter/Imagick.zep", 916);
		return;
	}
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "Imagick::IMAGICK_EXTNUM");
	ZEPHIR_CALL_FUNCTION(&_2, "defined", NULL, 114, &_1);
	zephir_check_call_status();
	if (zephir_is_true(&_2)) {
		ZEPHIR_INIT_VAR(&_3$$4);
		ZVAL_STRING(&_3$$4, "Imagick::IMAGICK_EXTNUM");
		ZEPHIR_CALL_FUNCTION(&_4$$4, "constant", NULL, 115, &_3$$4);
		zephir_check_call_status();
		zephir_update_property_zval(this_ptr, ZEND_STRL("version"), &_4$$4);
	}
	ZEPHIR_MM_RESTORE();
}

