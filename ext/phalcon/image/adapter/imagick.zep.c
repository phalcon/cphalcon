
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
#include "kernel/memory.h"
#include "kernel/object.h"
#include "kernel/operators.h"
#include "kernel/exception.h"
#include "kernel/string.h"
#include "kernel/concat.h"
#include "kernel/file.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE
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
 *
 * Capabilities:
 *
 * | Aspect              | Support                                        |
 * |---------------------|------------------------------------------------|
 * | Load formats        | Whatever the linked ImageMagick build supports |
 * | Render/save formats | Whatever the linked ImageMagick build supports |
 * | Backend-only API    | liquidRescale(), setResourceLimit()            |
 *
 * Visual semantics differ from the Gd adapter: blur() maps the radius to a
 * blur sigma, while sharpen and reflection use ImageMagick's own scales.
 * Switching the factory backend can change the rendered output.
 *
 * @extends AbstractAdapter<ImagickNative>
 */
ZEPHIR_INIT_CLASS(Phalcon_Image_Adapter_Imagick)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Image\\Adapter, Imagick, phalcon, image_adapter_imagick, phalcon_image_adapter_abstractadapter_ce, phalcon_image_adapter_imagick_method_entry, 0);

	{
		zval _zc0;
		ZVAL_LONG(&_zc0, 0);
		zephir_declare_typed_property(phalcon_image_adapter_imagick_ce, SL("version"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_LONG, NULL, 0);
	}

	return SUCCESS;
}

/**
 * Loads an image from a file, or creates a blank canvas.
 *
 * When the file exists it is loaded. When the file does not exist and both
 * a width and a height are supplied, a blank transparent canvas is created
 * instead - its realpath, mime and type then describe a PNG canvas rather
 * than the named file. Prefer Imagick::create() for the canvas case; this
 * dual mode is slated for removal in the next major version.
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
	zend_bool _24$$8;
	zval _6$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long width = 0, height = 0, maxPixels = 0, ZEPHIR_LAST_CALL_STATUS;
	zval file_zv, *width_param = NULL, *height_param = NULL, *maxPixels_param = NULL, coalesced, image, _0, _1, _2, _3, _31, _32, _33, _34, _35, _4$$3, _5$$3, _7$$3, _8$$3, _13$$3, _14$$3, _17$$3, _20$$3, _21$$3, _22$$3, _23$$3, _9$$4, _10$$4, _11$$4, _12$$4, _15$$5, _16$$5, _18$$6, _19$$6, _27$$8, _28$$8, _29$$8, _30$$8, _25$$9, _26$$9;
	zend_string *file = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&file_zv);
	ZVAL_UNDEF(&coalesced);
	ZVAL_UNDEF(&image);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_31);
	ZVAL_UNDEF(&_32);
	ZVAL_UNDEF(&_33);
	ZVAL_UNDEF(&_34);
	ZVAL_UNDEF(&_35);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_7$$3);
	ZVAL_UNDEF(&_8$$3);
	ZVAL_UNDEF(&_13$$3);
	ZVAL_UNDEF(&_14$$3);
	ZVAL_UNDEF(&_17$$3);
	ZVAL_UNDEF(&_20$$3);
	ZVAL_UNDEF(&_21$$3);
	ZVAL_UNDEF(&_22$$3);
	ZVAL_UNDEF(&_23$$3);
	ZVAL_UNDEF(&_9$$4);
	ZVAL_UNDEF(&_10$$4);
	ZVAL_UNDEF(&_11$$4);
	ZVAL_UNDEF(&_12$$4);
	ZVAL_UNDEF(&_15$$5);
	ZVAL_UNDEF(&_16$$5);
	ZVAL_UNDEF(&_18$$6);
	ZVAL_UNDEF(&_19$$6);
	ZVAL_UNDEF(&_27$$8);
	ZVAL_UNDEF(&_28$$8);
	ZVAL_UNDEF(&_29$$8);
	ZVAL_UNDEF(&_30$$8);
	ZVAL_UNDEF(&_25$$9);
	ZVAL_UNDEF(&_26$$9);
	ZVAL_UNDEF(&_6$$3);
	ZEND_TLS zephir_method_cache _zephir_call_cache[26];
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	static zend_string *_zephir_prop_2 = NULL;
	static zend_string *_zephir_prop_3 = NULL;
	static zend_string *_zephir_prop_4 = NULL;
	static zend_string *_zephir_prop_5 = NULL;
	static zend_string *_zephir_prop_6 = NULL;
	static zend_string *_zephir_prop_7 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("file", 4, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("image", 5, 1);
	}
	if (UNEXPECTED(!_zephir_prop_2)) {
		_zephir_prop_2 = zend_string_init("maxPixels", 9, 1);
	}
	if (UNEXPECTED(!_zephir_prop_3)) {
		_zephir_prop_3 = zend_string_init("realpath", 8, 1);
	}
	if (UNEXPECTED(!_zephir_prop_4)) {
		_zephir_prop_4 = zend_string_init("type", 4, 1);
	}
	if (UNEXPECTED(!_zephir_prop_5)) {
		_zephir_prop_5 = zend_string_init("width", 5, 1);
	}
	if (UNEXPECTED(!_zephir_prop_6)) {
		_zephir_prop_6 = zend_string_init("height", 6, 1);
	}
	if (UNEXPECTED(!_zephir_prop_7)) {
		_zephir_prop_7 = zend_string_init("mime", 4, 1);
	}

	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 4)
		Z_PARAM_STR(file)
		Z_PARAM_OPTIONAL
		Z_PARAM_LONG_OR_NULL(width, is_null_true)
		Z_PARAM_LONG_OR_NULL(height, is_null_true)
		Z_PARAM_LONG(maxPixels)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	if (ZEND_NUM_ARGS() > 1) {
		width_param = ZEND_CALL_ARG(execute_data, 2);
	}
	if (ZEND_NUM_ARGS() > 2) {
		height_param = ZEND_CALL_ARG(execute_data, 3);
	}
	if (ZEND_NUM_ARGS() > 3) {
		maxPixels_param = ZEND_CALL_ARG(execute_data, 4);
	}
	zephir_memory_observe(&file_zv);
	ZVAL_STR_COPY(&file_zv, file);
	ZEPHIR_CALL_METHOD_CACHED(NULL, this_ptr, "check", &_zephir_call_cache[0]);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_0);
	object_init_ex(&_0, zephir_get_internal_ce(SL("imagick")));
	zephir_constructor_start(&_0);
	ZEPHIR_CALL_METHOD_CACHED(NULL, &_0, "__construct", &_zephir_call_cache[1]);
	zephir_check_call_status();
	zephir_constructor_finish(&_0);
	ZEPHIR_CPY_WRT(&image, &_0);
	ZEPHIR_INIT_NVAR(&_0);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 943, &file_zv);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_1, 944, &image);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(&_1);
	if (maxPixels > 0) {
		ZEPHIR_INIT_NVAR(&_1);
		ZVAL_LONG(&_1, maxPixels);
	} else {
		ZEPHIR_INIT_NVAR(&_1);
		ZVAL_LONG(&_1, 50000000);
	}
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_2, 945, &_1);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_read_property_cached(&_3, this_ptr, _zephir_prop_0, 943, PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CALL_METHOD_CACHED(&_2, this_ptr, "phpFileExists", &_zephir_call_cache[2], &_3);
	zephir_check_call_status();
	if (ZEPHIR_IS_TRUE_IDENTICAL(&_2)) {
		zephir_read_property_cached(&_4$$3, this_ptr, _zephir_prop_0, 943, PH_NOISY_CC | PH_READONLY);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_CALL_FUNCTION(&_5$$3, "realpath", NULL, 42, &_4$$3);
		zephir_check_call_status();
		zephir_cast_to_string(&_6$$3, &_5$$3);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_3, 946, &_6$$3);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		zephir_read_property_cached(&_8$$3, this_ptr, _zephir_prop_3, 946, PH_NOISY_CC | PH_READONLY);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_CALL_METHOD_CACHED(&_7$$3, &image, "pingImage", &_zephir_call_cache[3], &_8$$3);
		zephir_check_call_status();
		if (ZEPHIR_IS_TRUE_IDENTICAL(&_7$$3)) {
			ZEPHIR_CALL_METHOD_CACHED(&_9$$4, &image, "getImageWidth", &_zephir_call_cache[4]);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD_CACHED(&_10$$4, &image, "getImageHeight", &_zephir_call_cache[5]);
			zephir_check_call_status();
			ZVAL_LONG(&_11$$4, zephir_get_intval(&_9$$4));
			ZVAL_LONG(&_12$$4, zephir_get_intval(&_10$$4));
			ZEPHIR_CALL_METHOD_CACHED(NULL, this_ptr, "assertPixelLimit", &_zephir_call_cache[6], &_11$$4, &_12$$4);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD_CACHED(NULL, &image, "clear", &_zephir_call_cache[7]);
			zephir_check_call_status();
		}
		zephir_read_property_cached(&_14$$3, this_ptr, _zephir_prop_3, 946, PH_NOISY_CC | PH_READONLY);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_CALL_METHOD_CACHED(&_13$$3, &image, "readImage", &_zephir_call_cache[8], &_14$$3);
		zephir_check_call_status();
		if (!ZEPHIR_IS_TRUE_IDENTICAL(&_13$$3)) {
			ZEPHIR_INIT_VAR(&_15$$5);
			object_init_ex(&_15$$5, phalcon_image_exceptions_imageloadfailed_ce);
			zephir_constructor_start(&_15$$5);
			zephir_read_property_cached(&_16$$5, this_ptr, _zephir_prop_0, 943, PH_NOISY_CC | PH_READONLY);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			ZEPHIR_CALL_METHOD_CACHED(NULL, &_15$$5, "__construct", &_zephir_call_cache[9], &_16$$5);
			zephir_check_call_status();
			zephir_constructor_finish(&_15$$5);
			zephir_throw_exception_debug(&_15$$5, "phalcon/Image/Adapter/Imagick.zep", 113);
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_CALL_METHOD_CACHED(&_17$$3, &image, "getImageAlphaChannel", &_zephir_call_cache[10]);
		zephir_check_call_status();
		if (!zephir_is_true(&_17$$3)) {
			ZEPHIR_INIT_VAR(&_18$$6);
			ZVAL_STRING(&_18$$6, "Imagick::ALPHACHANNEL_SET");
			ZEPHIR_CALL_FUNCTION(&_19$$6, "constant", NULL, 40, &_18$$6);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD_CACHED(NULL, &image, "setImageAlphaChannel", &_zephir_call_cache[11], &_19$$6);
			zephir_check_call_status();
		}
		ZEPHIR_CALL_METHOD_CACHED(&_20$$3, &image, "getImageType", &_zephir_call_cache[12]);
		zephir_check_call_status();
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_4, 947, &_20$$3);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_INIT_VAR(&_21$$3);
		ZEPHIR_CALL_METHOD_CACHED(&_22$$3, &image, "getImageFormat", &_zephir_call_cache[13]);
		zephir_check_call_status();
		zephir_fast_strtoupper(&_21$$3, &_22$$3);
		ZEPHIR_INIT_VAR(&_23$$3);
		ZVAL_STRING(&_23$$3, "GIF");
		if (ZEPHIR_IS_IDENTICAL(&_23$$3, &_21$$3)) {
			ZEPHIR_CALL_METHOD_CACHED(&coalesced, &image, "coalesceImages", &_zephir_call_cache[14]);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD_CACHED(NULL, &image, "clear", &_zephir_call_cache[15]);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD_CACHED(NULL, &image, "destroy", &_zephir_call_cache[16]);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(&image, &coalesced);
			zephir_update_property_zval_cached(this_ptr, _zephir_prop_1, 944, &image);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
		}
	} else {
		_24$$8 = 0 == (width != 0);
		if (!(_24$$8)) {
			_24$$8 = 0 == (height != 0);
		}
		if (_24$$8) {
			ZEPHIR_INIT_VAR(&_25$$9);
			object_init_ex(&_25$$9, phalcon_image_exceptions_imageloadfailed_ce);
			zephir_constructor_start(&_25$$9);
			zephir_read_property_cached(&_26$$9, this_ptr, _zephir_prop_0, 943, PH_NOISY_CC | PH_READONLY);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			ZEPHIR_CALL_METHOD_CACHED(NULL, &_25$$9, "__construct", &_zephir_call_cache[17], &_26$$9);
			zephir_check_call_status();
			zephir_constructor_finish(&_25$$9);
			zephir_throw_exception_debug(&_25$$9, "phalcon/Image/Adapter/Imagick.zep", 138);
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_INIT_VAR(&_27$$8);
		object_init_ex(&_27$$8, zephir_get_internal_ce(SL("imagickpixel")));
		zephir_constructor_start(&_27$$8);
		ZEPHIR_INIT_VAR(&_28$$8);
		ZVAL_STRING(&_28$$8, "transparent");
		ZEPHIR_CALL_METHOD_CACHED(NULL, &_27$$8, "__construct", &_zephir_call_cache[18], &_28$$8);
		zephir_check_call_status();
		zephir_constructor_finish(&_27$$8);
		ZVAL_LONG(&_29$$8, width);
		ZVAL_LONG(&_30$$8, height);
		ZEPHIR_CALL_METHOD_CACHED(NULL, &image, "newImage", &_zephir_call_cache[19], &_29$$8, &_30$$8, &_27$$8);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&_28$$8);
		ZVAL_STRING(&_28$$8, "png");
		ZEPHIR_CALL_METHOD_CACHED(NULL, &image, "setFormat", &_zephir_call_cache[20], &_28$$8);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&_28$$8);
		ZVAL_STRING(&_28$$8, "png");
		ZEPHIR_CALL_METHOD_CACHED(NULL, &image, "setImageFormat", &_zephir_call_cache[21], &_28$$8);
		zephir_check_call_status();
		zephir_read_property_cached(&_29$$8, this_ptr, _zephir_prop_0, 943, PH_NOISY_CC | PH_READONLY);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_3, 946, &_29$$8);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	ZEPHIR_CALL_METHOD_CACHED(&_31, &image, "getImageWidth", &_zephir_call_cache[22]);
	zephir_check_call_status();
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_5, 948, &_31);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CALL_METHOD_CACHED(&_32, &image, "getImageHeight", &_zephir_call_cache[23]);
	zephir_check_call_status();
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_6, 949, &_32);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CALL_METHOD_CACHED(&_33, &image, "getImageType", &_zephir_call_cache[24]);
	zephir_check_call_status();
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_4, 947, &_33);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CALL_METHOD_CACHED(&_34, &image, "getImageFormat", &_zephir_call_cache[25]);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_35);
	ZEPHIR_CONCAT_SV(&_35, "image/", &_34);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_7, 950, &_35);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
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
	ZEND_TLS zephir_method_cache _zephir_call_cache[2];
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("image", 5, 1);
	}
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	zephir_memory_observe(&_0);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 944, PH_NOISY_CC);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (zephir_is_instance_of(&_0, SL("Imagick"))) {
		zephir_read_property_cached(&_1$$3, this_ptr, _zephir_prop_0, 944, PH_NOISY_CC | PH_READONLY);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_CALL_METHOD_CACHED(NULL, &_1$$3, "clear", &_zephir_call_cache[0]);
		zephir_check_call_status();
		zephir_read_property_cached(&_2$$3, this_ptr, _zephir_prop_0, 944, PH_NOISY_CC | PH_READONLY);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_CALL_METHOD_CACHED(NULL, &_2$$3, "destroy", &_zephir_call_cache[1]);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();
}

/**
 * Creates a blank transparent canvas of the given dimensions, without the
 * load-or-create ambiguity of the constructor.
 *
 * @phpstan-return AbstractAdapter<ImagickNative>
 * @throws Exception
 * @throws ImagickException
 */
PHP_METHOD(Phalcon_Image_Adapter_Imagick, create)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *width_param = NULL, *height_param = NULL, _0, _1, _2;
	zend_long width, height, ZEPHIR_LAST_CALL_STATUS;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZEND_TLS zephir_method_cache _zephir_call_cache[1];
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(width)
		Z_PARAM_LONG(height)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 2, 0, &width_param, &height_param);
	object_init_ex(return_value, phalcon_image_adapter_imagick_ce);
	zephir_constructor_start(return_value);
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "");
	ZVAL_LONG(&_1, width);
	ZVAL_LONG(&_2, height);
	ZEPHIR_CALL_METHOD_CACHED(NULL, return_value, "__construct", &_zephir_call_cache[0], &_0, &_1, &_2);
	zephir_check_call_status();
	zephir_constructor_finish(return_value);
	RETURN_MM();
}

/**
 * This method scales the images using liquid rescaling method. Only support
 * Imagick
 *
 * @phpstan-return AbstractAdapter<ImagickNative>
 * @throws Exception
 * @throws ImagickException
 */
PHP_METHOD(Phalcon_Image_Adapter_Imagick, liquidRescale)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *width_param = NULL, *height_param = NULL, *deltaX_param = NULL, *rigidity_param = NULL, image, result, _0, _7, _8, _1$$3, _2$$3, _3$$3, _4$$3, _6$$3, _5$$4;
	zend_long width, height, deltaX = 0, rigidity = 0, ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&image);
	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_5$$4);
	ZEND_TLS zephir_method_cache _zephir_call_cache[6];
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	static zend_string *_zephir_prop_2 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("image", 5, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("width", 5, 1);
	}
	if (UNEXPECTED(!_zephir_prop_2)) {
		_zephir_prop_2 = zend_string_init("height", 6, 1);
	}

	ZEND_PARSE_PARAMETERS_START(2, 4)
		Z_PARAM_LONG(width)
		Z_PARAM_LONG(height)
		Z_PARAM_OPTIONAL
		Z_PARAM_LONG(deltaX)
		Z_PARAM_LONG(rigidity)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 2, 2, &width_param, &height_param, &deltaX_param, &rigidity_param);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 944, PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CPY_WRT(&image, &_0);
	ZVAL_LONG(&_0, 0);
	ZEPHIR_CALL_METHOD_CACHED(NULL, &image, "setIteratorIndex", &_zephir_call_cache[0], &_0);
	zephir_check_call_status();
	while (1) {
		if (!(1)) {
			break;
		}
		ZVAL_LONG(&_1$$3, width);
		ZVAL_LONG(&_2$$3, height);
		ZVAL_LONG(&_3$$3, deltaX);
		ZVAL_LONG(&_4$$3, rigidity);
		ZEPHIR_CALL_METHOD_CACHED(&result, &image, "liquidRescaleImage", &_zephir_call_cache[1], &_1$$3, &_2$$3, &_3$$3, &_4$$3);
		zephir_check_call_status();
		if (!ZEPHIR_IS_TRUE_IDENTICAL(&result)) {
			ZEPHIR_INIT_NVAR(&_5$$4);
			object_init_ex(&_5$$4, phalcon_image_exceptions_resizefailed_ce);
			zephir_constructor_start(&_5$$4);
			ZEPHIR_CALL_METHOD_CACHED(NULL, &_5$$4, "__construct", &_zephir_call_cache[2]);
			zephir_check_call_status();
			zephir_constructor_finish(&_5$$4);
			zephir_throw_exception_debug(&_5$$4, "phalcon/Image/Adapter/Imagick.zep", 213);
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_CALL_METHOD_CACHED(&_6$$3, &image, "nextImage", &_zephir_call_cache[3]);
		zephir_check_call_status();
		if (ZEPHIR_IS_FALSE_IDENTICAL(&_6$$3)) {
			break;
		}
	}
	ZEPHIR_CALL_METHOD_CACHED(&_7, &image, "getImageWidth", &_zephir_call_cache[4]);
	zephir_check_call_status();
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_1, 948, &_7);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CALL_METHOD_CACHED(&_8, &image, "getImageHeight", &_zephir_call_cache[5]);
	zephir_check_call_status();
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_2, 949, &_8);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	RETURN_THIS();
}

/**
 * Sets the limit for a particular resource in megabytes
 *
 * @throws Exception
 * @throws ImagickException
 *
 * @link https://www.php.net/manual/en/imagick.constants.php#imagick.constants.resourcetypes
 */
PHP_METHOD(Phalcon_Image_Adapter_Imagick, setResourceLimit)
{
	zend_bool _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *type_param = NULL, *limit_param = NULL, image, _0, _2$$3, _3$$3, _4$$4;
	zend_long type, limit, ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&image);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$4);
	ZEND_TLS zephir_method_cache _zephir_call_cache[2];
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("image", 5, 1);
	}

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(type)
		Z_PARAM_LONG(limit)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 2, 0, &type_param, &limit_param);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 944, PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CPY_WRT(&image, &_0);
	_1 = type >= 0;
	if (_1) {
		_1 = type <= 6;
	}
	if (_1) {
		ZVAL_LONG(&_2$$3, type);
		ZVAL_LONG(&_3$$3, limit);
		ZEPHIR_CALL_METHOD_CACHED(NULL, &image, "setResourceLimit", &_zephir_call_cache[0], &_2$$3, &_3$$3);
		zephir_check_call_status();
	} else {
		ZEPHIR_INIT_VAR(&_4$$4);
		object_init_ex(&_4$$4, phalcon_image_exceptions_resourcetypeerror_ce);
		zephir_constructor_start(&_4$$4);
		ZEPHIR_CALL_METHOD_CACHED(NULL, &_4$$4, "__construct", &_zephir_call_cache[1]);
		zephir_check_call_status();
		zephir_constructor_finish(&_4$$4);
		zephir_throw_exception_debug(&_4$$4, "phalcon/Image/Adapter/Imagick.zep", 248);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_MM_RESTORE();
}

/**
 * Execute a background.
 *
 * @throws Exception
 * @throws ImagickException
 * @throws ImagickPixelException
 */
PHP_METHOD(Phalcon_Image_Adapter_Imagick, processBackground)
{
	double localOpacity = 0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_10 = NULL;
	zval *red_param = NULL, *green_param = NULL, *blue_param = NULL, *opacity_param = NULL, background, color, image, pixel1, pixel2, result, _0, _1, _2, _3, _4, _5$$3, _6$$3, _11$$3, _12$$3, _13$$3, _14$$3, _15$$3, _16$$3, _17$$3, _18$$3, _19$$3, _21$$3, _7$$4, _8$$5, _9$$5, _20$$8;
	zend_long red, green, blue, opacity, ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&background);
	ZVAL_UNDEF(&color);
	ZVAL_UNDEF(&image);
	ZVAL_UNDEF(&pixel1);
	ZVAL_UNDEF(&pixel2);
	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_11$$3);
	ZVAL_UNDEF(&_12$$3);
	ZVAL_UNDEF(&_13$$3);
	ZVAL_UNDEF(&_14$$3);
	ZVAL_UNDEF(&_15$$3);
	ZVAL_UNDEF(&_16$$3);
	ZVAL_UNDEF(&_17$$3);
	ZVAL_UNDEF(&_18$$3);
	ZVAL_UNDEF(&_19$$3);
	ZVAL_UNDEF(&_21$$3);
	ZVAL_UNDEF(&_7$$4);
	ZVAL_UNDEF(&_8$$5);
	ZVAL_UNDEF(&_9$$5);
	ZVAL_UNDEF(&_20$$8);
	ZEND_TLS zephir_method_cache _zephir_call_cache[16];
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	static zend_string *_zephir_prop_2 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("image", 5, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("width", 5, 1);
	}
	if (UNEXPECTED(!_zephir_prop_2)) {
		_zephir_prop_2 = zend_string_init("height", 6, 1);
	}

	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_LONG(red)
		Z_PARAM_LONG(green)
		Z_PARAM_LONG(blue)
		Z_PARAM_LONG(opacity)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 4, 0, &red_param, &green_param, &blue_param, &opacity_param);
	localOpacity =  (zephir_safe_div_double_long((double) opacity, 100));
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "rgb(%d, %d, %d)");
	ZVAL_LONG(&_1, red);
	ZVAL_LONG(&_2, green);
	ZVAL_LONG(&_3, blue);
	ZEPHIR_CALL_FUNCTION(&color, "sprintf", NULL, 38, &_0, &_1, &_2, &_3);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_0);
	object_init_ex(&_0, zephir_get_internal_ce(SL("imagickpixel")));
	zephir_constructor_start(&_0);
	ZEPHIR_CALL_METHOD_CACHED(NULL, &_0, "__construct", &_zephir_call_cache[0], &color);
	zephir_check_call_status();
	zephir_constructor_finish(&_0);
	ZEPHIR_CPY_WRT(&pixel1, &_0);
	ZEPHIR_INIT_NVAR(&_0);
	ZEPHIR_INIT_NVAR(&_0);
	object_init_ex(&_0, zephir_get_internal_ce(SL("imagickpixel")));
	zephir_constructor_start(&_0);
	ZEPHIR_INIT_VAR(&_4);
	ZVAL_STRING(&_4, "transparent");
	ZEPHIR_CALL_METHOD_CACHED(NULL, &_0, "__construct", &_zephir_call_cache[1], &_4);
	zephir_check_call_status();
	zephir_constructor_finish(&_0);
	ZEPHIR_CPY_WRT(&pixel2, &_0);
	ZEPHIR_INIT_NVAR(&_0);
	ZEPHIR_INIT_NVAR(&_0);
	object_init_ex(&_0, zephir_get_internal_ce(SL("imagick")));
	zephir_constructor_start(&_0);
	ZEPHIR_CALL_METHOD_CACHED(NULL, &_0, "__construct", &_zephir_call_cache[2]);
	zephir_check_call_status();
	zephir_constructor_finish(&_0);
	ZEPHIR_CPY_WRT(&background, &_0);
	ZEPHIR_INIT_NVAR(&_0);
	zephir_read_property_cached(&_1, this_ptr, _zephir_prop_0, 944, PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CPY_WRT(&image, &_1);
	ZVAL_LONG(&_1, 0);
	ZEPHIR_CALL_METHOD_CACHED(NULL, &image, "setIteratorIndex", &_zephir_call_cache[3], &_1);
	zephir_check_call_status();
	while (1) {
		if (!(1)) {
			break;
		}
		zephir_read_property_cached(&_5$$3, this_ptr, _zephir_prop_1, 948, PH_NOISY_CC | PH_READONLY);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		zephir_read_property_cached(&_6$$3, this_ptr, _zephir_prop_2, 949, PH_NOISY_CC | PH_READONLY);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_CALL_METHOD_CACHED(NULL, &background, "newImage", &_zephir_call_cache[4], &_5$$3, &_6$$3, &pixel1);
		zephir_check_call_status();

		/* try_start_1: */

			ZEPHIR_CALL_METHOD_CACHED(&_7$$4, &background, "getImageAlphaChannel", &_zephir_call_cache[5]);
			zephir_check_call_status_or_jump(try_end_1);
			if (!ZEPHIR_IS_TRUE_IDENTICAL(&_7$$4)) {
				ZEPHIR_INIT_NVAR(&_8$$5);
				ZVAL_STRING(&_8$$5, "Imagick::ALPHACHANNEL_SET");
				ZEPHIR_CALL_FUNCTION(&_9$$5, "constant", &_10, 40, &_8$$5);
				zephir_check_call_status_or_jump(try_end_1);
				ZEPHIR_CALL_METHOD_CACHED(NULL, &background, "setImageAlphaChannel", &_zephir_call_cache[6], &_9$$5);
				zephir_check_call_status_or_jump(try_end_1);
			}

		try_end_1:

		if (EG(exception)) {
			ZEPHIR_INIT_NVAR(&_11$$3);
			ZVAL_OBJ(&_11$$3, EG(exception));
			Z_ADDREF_P(&_11$$3);
			ZEPHIR_INIT_NVAR(&_12$$3);
			if (zephir_is_instance_of(&_11$$3, SL("ImagickException"))) {
				zend_clear_exception();
				ZEPHIR_CPY_WRT(&_12$$3, &_11$$3);
				ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_image_exception_ce, "Imagick::getImageAlphaChannel failed", "phalcon/Image/Adapter/Imagick.zep", 288);
				return;
			} else {
				ZEPHIR_MM_RESTORE();
				return;
			}
		}
		ZEPHIR_CALL_METHOD_CACHED(NULL, &background, "setImageBackgroundColor", &_zephir_call_cache[7], &pixel2);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&_13$$3);
		ZVAL_STRING(&_13$$3, "Imagick::EVALUATE_MULTIPLY");
		ZEPHIR_CALL_FUNCTION(&_14$$3, "constant", &_10, 40, &_13$$3);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&_13$$3);
		ZVAL_STRING(&_13$$3, "Imagick::CHANNEL_ALPHA");
		ZEPHIR_CALL_FUNCTION(&_15$$3, "constant", &_10, 40, &_13$$3);
		zephir_check_call_status();
		ZVAL_DOUBLE(&_16$$3, localOpacity);
		ZEPHIR_CALL_METHOD_CACHED(NULL, &background, "evaluateImage", &_zephir_call_cache[8], &_14$$3, &_16$$3, &_15$$3);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD_CACHED(&_17$$3, &image, "getColorspace", &_zephir_call_cache[9]);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD_CACHED(NULL, &background, "setColorspace", &_zephir_call_cache[10], &_17$$3);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&_13$$3);
		ZVAL_STRING(&_13$$3, "Imagick::COMPOSITE_DISSOLVE");
		ZEPHIR_CALL_FUNCTION(&_18$$3, "constant", &_10, 40, &_13$$3);
		zephir_check_call_status();
		ZVAL_LONG(&_16$$3, 0);
		ZVAL_LONG(&_19$$3, 0);
		ZEPHIR_CALL_METHOD_CACHED(&result, &background, "compositeImage", &_zephir_call_cache[11], &image, &_18$$3, &_16$$3, &_19$$3);
		zephir_check_call_status();
		if (!ZEPHIR_IS_TRUE_IDENTICAL(&result)) {
			ZEPHIR_INIT_NVAR(&_20$$8);
			object_init_ex(&_20$$8, phalcon_image_exceptions_compositefailed_ce);
			zephir_constructor_start(&_20$$8);
			ZEPHIR_CALL_METHOD_CACHED(NULL, &_20$$8, "__construct", &_zephir_call_cache[12]);
			zephir_check_call_status();
			zephir_constructor_finish(&_20$$8);
			zephir_throw_exception_debug(&_20$$8, "phalcon/Image/Adapter/Imagick.zep", 311);
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_CALL_METHOD_CACHED(&_21$$3, &image, "nextImage", &_zephir_call_cache[13]);
		zephir_check_call_status();
		if (!ZEPHIR_IS_TRUE_IDENTICAL(&_21$$3)) {
			break;
		}
	}
	ZEPHIR_CALL_METHOD_CACHED(NULL, &image, "clear", &_zephir_call_cache[14]);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD_CACHED(NULL, &image, "destroy", &_zephir_call_cache[15]);
	zephir_check_call_status();
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 944, &background);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_MM_RESTORE();
}

/**
 * Blur image
 *
 * @throws ImagickException
 */
PHP_METHOD(Phalcon_Image_Adapter_Imagick, processBlur)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *radius_param = NULL, image, _0, _1$$3, _2$$3, _3$$3;
	zend_long radius, ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&image);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZEND_TLS zephir_method_cache _zephir_call_cache[3];
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("image", 5, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(radius)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &radius_param);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 944, PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CPY_WRT(&image, &_0);
	ZVAL_LONG(&_0, 0);
	ZEPHIR_CALL_METHOD_CACHED(NULL, &image, "setIteratorIndex", &_zephir_call_cache[0], &_0);
	zephir_check_call_status();
	while (1) {
		if (!(1)) {
			break;
		}
		ZVAL_LONG(&_1$$3, radius);
		ZVAL_LONG(&_2$$3, 100);
		ZEPHIR_CALL_METHOD_CACHED(NULL, &image, "blurImage", &_zephir_call_cache[1], &_1$$3, &_2$$3);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD_CACHED(&_3$$3, &image, "nextImage", &_zephir_call_cache[2]);
		zephir_check_call_status();
		if (!ZEPHIR_IS_TRUE_IDENTICAL(&_3$$3)) {
			break;
		}
	}
	ZEPHIR_MM_RESTORE();
}

/**
 * Execute a crop.
 *
 * @throws ImagickException
 */
PHP_METHOD(Phalcon_Image_Adapter_Imagick, processCrop)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *width_param = NULL, *height_param = NULL, *offsetX_param = NULL, *offsetY_param = NULL, image, _0, _6, _7, _1$$3, _2$$3, _3$$3, _4$$3, _5$$3;
	zend_long width, height, offsetX, offsetY, ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&image);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$3);
	ZEND_TLS zephir_method_cache _zephir_call_cache[6];
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	static zend_string *_zephir_prop_2 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("image", 5, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("width", 5, 1);
	}
	if (UNEXPECTED(!_zephir_prop_2)) {
		_zephir_prop_2 = zend_string_init("height", 6, 1);
	}

	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_LONG(width)
		Z_PARAM_LONG(height)
		Z_PARAM_LONG(offsetX)
		Z_PARAM_LONG(offsetY)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 4, 0, &width_param, &height_param, &offsetX_param, &offsetY_param);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 944, PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CPY_WRT(&image, &_0);
	ZVAL_LONG(&_0, 0);
	ZEPHIR_CALL_METHOD_CACHED(NULL, &image, "setIteratorIndex", &_zephir_call_cache[0], &_0);
	zephir_check_call_status();
	while (1) {
		if (!(1)) {
			break;
		}
		ZVAL_LONG(&_1$$3, width);
		ZVAL_LONG(&_2$$3, height);
		ZVAL_LONG(&_3$$3, offsetX);
		ZVAL_LONG(&_4$$3, offsetY);
		ZEPHIR_CALL_METHOD_CACHED(NULL, &image, "cropImage", &_zephir_call_cache[1], &_1$$3, &_2$$3, &_3$$3, &_4$$3);
		zephir_check_call_status();
		ZVAL_LONG(&_1$$3, width);
		ZVAL_LONG(&_2$$3, height);
		ZVAL_LONG(&_3$$3, 0);
		ZVAL_LONG(&_4$$3, 0);
		ZEPHIR_CALL_METHOD_CACHED(NULL, &image, "setImagePage", &_zephir_call_cache[2], &_1$$3, &_2$$3, &_3$$3, &_4$$3);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD_CACHED(&_5$$3, &image, "nextImage", &_zephir_call_cache[3]);
		zephir_check_call_status();
		if (!ZEPHIR_IS_TRUE_IDENTICAL(&_5$$3)) {
			break;
		}
	}
	ZEPHIR_CALL_METHOD_CACHED(&_6, &image, "getImageWidth", &_zephir_call_cache[4]);
	zephir_check_call_status();
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_1, 948, &_6);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CALL_METHOD_CACHED(&_7, &image, "getImageHeight", &_zephir_call_cache[5]);
	zephir_check_call_status();
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_2, 949, &_7);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_MM_RESTORE();
}

/**
 * Execute a flip.
 *
 * @throws ImagickException
 */
PHP_METHOD(Phalcon_Image_Adapter_Imagick, processFlip)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *direction_param = NULL, image, method, _0, _1$$3;
	zend_long direction, ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&image);
	ZVAL_UNDEF(&method);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	ZEND_TLS zephir_method_cache _zephir_call_cache[2];
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("image", 5, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(direction)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &direction_param);
	if (direction == 11) {
		ZEPHIR_INIT_VAR(&method);
		ZVAL_STRING(&method, "flipImage");
	} else {
		ZEPHIR_INIT_NVAR(&method);
		ZVAL_STRING(&method, "flopImage");
	}
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 944, PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CPY_WRT(&image, &_0);
	ZVAL_LONG(&_0, 0);
	ZEPHIR_CALL_METHOD_CACHED(NULL, &image, "setIteratorIndex", &_zephir_call_cache[0], &_0);
	zephir_check_call_status();
	while (1) {
		if (!(1)) {
			break;
		}
		ZEPHIR_CALL_METHOD_ZVAL(NULL, &image, &method, NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD_CACHED(&_1$$3, &image, "nextImage", &_zephir_call_cache[1]);
		zephir_check_call_status();
		if (!ZEPHIR_IS_TRUE_IDENTICAL(&_1$$3)) {
			break;
		}
	}
	ZEPHIR_MM_RESTORE();
}

/**
 * Composite one image onto another
 *
 * @throws Exception
 * @throws ImagickException
 */
PHP_METHOD(Phalcon_Image_Adapter_Imagick, processMask)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_6 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *mask, mask_sub, current, image, result, _0, _1, _2, _3$$3, _4$$3, _5$$3, _7$$3, _9$$3, _8$$4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&mask_sub);
	ZVAL_UNDEF(&current);
	ZVAL_UNDEF(&image);
	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_7$$3);
	ZVAL_UNDEF(&_9$$3);
	ZVAL_UNDEF(&_8$$4);
	ZEND_TLS zephir_method_cache _zephir_call_cache[10];
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("image", 5, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(mask, phalcon_image_adapter_adapterinterface_ce)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &mask);
	ZEPHIR_INIT_VAR(&_0);
	object_init_ex(&_0, zephir_get_internal_ce(SL("imagick")));
	zephir_constructor_start(&_0);
	ZEPHIR_CALL_METHOD_CACHED(NULL, &_0, "__construct", &_zephir_call_cache[0]);
	zephir_check_call_status();
	zephir_constructor_finish(&_0);
	ZEPHIR_CPY_WRT(&image, &_0);
	ZEPHIR_INIT_NVAR(&_0);
	zephir_memory_observe(&current);
	zephir_read_property_cached(&current, this_ptr, _zephir_prop_0, 944, PH_NOISY_CC);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CALL_METHOD_CACHED(&_1, mask, "render", &_zephir_call_cache[1]);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD_CACHED(NULL, &image, "readImageBlob", &_zephir_call_cache[2], &_1);
	zephir_check_call_status();
	ZVAL_LONG(&_2, 0);
	ZEPHIR_CALL_METHOD_CACHED(NULL, &current, "setIteratorIndex", &_zephir_call_cache[3], &_2);
	zephir_check_call_status();
	while (1) {
		if (!(1)) {
			break;
		}
		ZVAL_BOOL(&_3$$3, 1);
		ZEPHIR_CALL_METHOD_CACHED(NULL, &current, "setImageMatte", &_zephir_call_cache[4], &_3$$3);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&_4$$3);
		ZVAL_STRING(&_4$$3, "Imagick::COMPOSITE_DSTIN");
		ZEPHIR_CALL_FUNCTION(&_5$$3, "constant", &_6, 40, &_4$$3);
		zephir_check_call_status();
		ZVAL_LONG(&_3$$3, 0);
		ZVAL_LONG(&_7$$3, 0);
		ZEPHIR_CALL_METHOD_CACHED(&result, &current, "compositeImage", &_zephir_call_cache[5], &image, &_5$$3, &_3$$3, &_7$$3);
		zephir_check_call_status();
		if (!ZEPHIR_IS_TRUE_IDENTICAL(&result)) {
			ZEPHIR_INIT_NVAR(&_8$$4);
			object_init_ex(&_8$$4, phalcon_image_exceptions_compositefailed_ce);
			zephir_constructor_start(&_8$$4);
			ZEPHIR_CALL_METHOD_CACHED(NULL, &_8$$4, "__construct", &_zephir_call_cache[6]);
			zephir_check_call_status();
			zephir_constructor_finish(&_8$$4);
			zephir_throw_exception_debug(&_8$$4, "phalcon/Image/Adapter/Imagick.zep", 433);
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_CALL_METHOD_CACHED(&_9$$3, &current, "nextImage", &_zephir_call_cache[7]);
		zephir_check_call_status();
		if (!ZEPHIR_IS_TRUE_IDENTICAL(&_9$$3)) {
			break;
		}
	}
	ZEPHIR_CALL_METHOD_CACHED(NULL, &image, "clear", &_zephir_call_cache[8]);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD_CACHED(NULL, &image, "destroy", &_zephir_call_cache[9]);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
}

/**
 * Pixelate image
 *
 * @throws ImagickException
 */
PHP_METHOD(Phalcon_Image_Adapter_Imagick, processPixelate)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *amount_param = NULL, image, _0, _1, _2, _3$$3, _4$$3, _5$$3;
	zend_long amount, ZEPHIR_LAST_CALL_STATUS, height = 0, width = 0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&image);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$3);
	ZEND_TLS zephir_method_cache _zephir_call_cache[4];
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	static zend_string *_zephir_prop_2 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("width", 5, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("height", 6, 1);
	}
	if (UNEXPECTED(!_zephir_prop_2)) {
		_zephir_prop_2 = zend_string_init("image", 5, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(amount)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &amount_param);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 948, PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(&_1);
	zephir_div_zval_long(&_1, &_0, amount);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	width = zephir_get_intval(&_1);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_1, 949, PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(&_2);
	zephir_div_zval_long(&_2, &_0, amount);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	height = zephir_get_intval(&_2);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_2, 944, PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CPY_WRT(&image, &_0);
	ZVAL_LONG(&_0, 0);
	ZEPHIR_CALL_METHOD_CACHED(NULL, &image, "setIteratorIndex", &_zephir_call_cache[0], &_0);
	zephir_check_call_status();
	while (1) {
		if (!(1)) {
			break;
		}
		ZVAL_LONG(&_3$$3, width);
		ZVAL_LONG(&_4$$3, height);
		ZEPHIR_CALL_METHOD_CACHED(NULL, &image, "scaleImage", &_zephir_call_cache[1], &_3$$3, &_4$$3);
		zephir_check_call_status();
		zephir_read_property_cached(&_3$$3, this_ptr, _zephir_prop_0, 948, PH_NOISY_CC | PH_READONLY);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		zephir_read_property_cached(&_4$$3, this_ptr, _zephir_prop_1, 949, PH_NOISY_CC | PH_READONLY);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_CALL_METHOD_CACHED(NULL, &image, "scaleImage", &_zephir_call_cache[2], &_3$$3, &_4$$3);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD_CACHED(&_5$$3, &image, "nextImage", &_zephir_call_cache[3]);
		zephir_check_call_status();
		if (!ZEPHIR_IS_TRUE_IDENTICAL(&_5$$3)) {
			break;
		}
	}
	ZEPHIR_MM_RESTORE();
}

/**
 * Execute a reflection.
 *
 * @throws Exception
 * @throws ImagickException
 */
PHP_METHOD(Phalcon_Image_Adapter_Imagick, processReflection)
{
	double fadeOpacity = 0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_13 = NULL;
	zend_bool fadeIn, _38$$13;
	zval *height_param = NULL, *opacity_param = NULL, *fadeIn_param = NULL, current, fade, hasNext, image, pixel, pseudo, reflection, result, _0, _2, _8, _9, _10, _19, _20, _21, _40, _1$$4, _3$$5, _4$$5, _5$$5, _6$$5, _7$$5, _11$$7, _12$$7, _14$$7, _15$$7, _17$$7, _18$$7, _16$$8, _22$$10, _23$$10, _24$$10, _25$$10, _26$$10, _27$$10, _28$$10, _29$$10, _31$$10, _30$$11, _32$$13, _33$$13, _34$$13, _35$$13, _37$$13, _39$$13, _36$$14;
	zend_long height, opacity, ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&current);
	ZVAL_UNDEF(&fade);
	ZVAL_UNDEF(&hasNext);
	ZVAL_UNDEF(&image);
	ZVAL_UNDEF(&pixel);
	ZVAL_UNDEF(&pseudo);
	ZVAL_UNDEF(&reflection);
	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_19);
	ZVAL_UNDEF(&_20);
	ZVAL_UNDEF(&_21);
	ZVAL_UNDEF(&_40);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&_3$$5);
	ZVAL_UNDEF(&_4$$5);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&_6$$5);
	ZVAL_UNDEF(&_7$$5);
	ZVAL_UNDEF(&_11$$7);
	ZVAL_UNDEF(&_12$$7);
	ZVAL_UNDEF(&_14$$7);
	ZVAL_UNDEF(&_15$$7);
	ZVAL_UNDEF(&_17$$7);
	ZVAL_UNDEF(&_18$$7);
	ZVAL_UNDEF(&_16$$8);
	ZVAL_UNDEF(&_22$$10);
	ZVAL_UNDEF(&_23$$10);
	ZVAL_UNDEF(&_24$$10);
	ZVAL_UNDEF(&_25$$10);
	ZVAL_UNDEF(&_26$$10);
	ZVAL_UNDEF(&_27$$10);
	ZVAL_UNDEF(&_28$$10);
	ZVAL_UNDEF(&_29$$10);
	ZVAL_UNDEF(&_31$$10);
	ZVAL_UNDEF(&_30$$11);
	ZVAL_UNDEF(&_32$$13);
	ZVAL_UNDEF(&_33$$13);
	ZVAL_UNDEF(&_34$$13);
	ZVAL_UNDEF(&_35$$13);
	ZVAL_UNDEF(&_37$$13);
	ZVAL_UNDEF(&_39$$13);
	ZVAL_UNDEF(&_36$$14);
	ZEND_TLS zephir_method_cache _zephir_call_cache[42];
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	static zend_string *_zephir_prop_2 = NULL;
	static zend_string *_zephir_prop_3 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("image", 5, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("version", 7, 1);
	}
	if (UNEXPECTED(!_zephir_prop_2)) {
		_zephir_prop_2 = zend_string_init("width", 5, 1);
	}
	if (UNEXPECTED(!_zephir_prop_3)) {
		_zephir_prop_3 = zend_string_init("height", 6, 1);
	}

	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_LONG(height)
		Z_PARAM_LONG(opacity)
		Z_PARAM_BOOL(fadeIn)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 3, 0, &height_param, &opacity_param, &fadeIn_param);
	zephir_memory_observe(&current);
	zephir_read_property_cached(&current, this_ptr, _zephir_prop_0, 944, PH_NOISY_CC);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_1, 951, PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(&reflection);
	if (ZEPHIR_GE_LONG(&_0, 30100)) {
		if (zephir_clone(&reflection, &current) == FAILURE) {
			ZEPHIR_MM_RESTORE();
			return;
		}
	} else {
		ZEPHIR_CALL_METHOD_CACHED(&_1$$4, &current, "clone", &_zephir_call_cache[0]);
		zephir_check_call_status();
		if (zephir_clone(&reflection, &_1$$4) == FAILURE) {
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	ZVAL_LONG(&_2, 0);
	ZEPHIR_CALL_METHOD_CACHED(NULL, &reflection, "setIteratorIndex", &_zephir_call_cache[1], &_2);
	zephir_check_call_status();
	while (1) {
		if (!(1)) {
			break;
		}
		ZEPHIR_CALL_METHOD_CACHED(NULL, &reflection, "flipImage", &_zephir_call_cache[2]);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD_CACHED(&_3$$5, &reflection, "getImageWidth", &_zephir_call_cache[3]);
		zephir_check_call_status();
		ZVAL_LONG(&_4$$5, height);
		ZVAL_LONG(&_5$$5, 0);
		ZVAL_LONG(&_6$$5, 0);
		ZEPHIR_CALL_METHOD_CACHED(NULL, &reflection, "cropImage", &_zephir_call_cache[4], &_3$$5, &_4$$5, &_5$$5, &_6$$5);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD_CACHED(&_7$$5, &reflection, "getImageWidth", &_zephir_call_cache[5]);
		zephir_check_call_status();
		ZVAL_LONG(&_4$$5, height);
		ZVAL_LONG(&_5$$5, 0);
		ZVAL_LONG(&_6$$5, 0);
		ZEPHIR_CALL_METHOD_CACHED(NULL, &reflection, "setImagePage", &_zephir_call_cache[6], &_7$$5, &_4$$5, &_5$$5, &_6$$5);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD_CACHED(&hasNext, &reflection, "nextImage", &_zephir_call_cache[7]);
		zephir_check_call_status();
		if (!ZEPHIR_IS_TRUE_IDENTICAL(&hasNext)) {
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
	ZEPHIR_INIT_VAR(&_8);
	object_init_ex(&_8, zephir_get_internal_ce(SL("imagick")));
	zephir_constructor_start(&_8);
	ZEPHIR_CALL_METHOD_CACHED(NULL, &_8, "__construct", &_zephir_call_cache[8]);
	zephir_check_call_status();
	zephir_constructor_finish(&_8);
	ZEPHIR_CPY_WRT(&fade, &_8);
	ZEPHIR_INIT_NVAR(&_8);
	ZEPHIR_CALL_METHOD_CACHED(&_9, &reflection, "getImageWidth", &_zephir_call_cache[9]);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD_CACHED(&_10, &reflection, "getImageHeight", &_zephir_call_cache[10]);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD_CACHED(NULL, &fade, "newPseudoImage", &_zephir_call_cache[11], &_9, &_10, &pseudo);
	zephir_check_call_status();
	fadeOpacity =  (zephir_safe_div_double_long((double) opacity, 100));
	ZVAL_LONG(&_2, 0);
	ZEPHIR_CALL_METHOD_CACHED(NULL, &reflection, "setIteratorIndex", &_zephir_call_cache[12], &_2);
	zephir_check_call_status();
	while (1) {
		if (!(1)) {
			break;
		}
		ZEPHIR_INIT_NVAR(&_11$$7);
		ZVAL_STRING(&_11$$7, "Imagick::COMPOSITE_DSTOUT");
		ZEPHIR_CALL_FUNCTION(&_12$$7, "constant", &_13, 40, &_11$$7);
		zephir_check_call_status();
		ZVAL_LONG(&_14$$7, 0);
		ZVAL_LONG(&_15$$7, 0);
		ZEPHIR_CALL_METHOD_CACHED(&result, &reflection, "compositeImage", &_zephir_call_cache[13], &fade, &_12$$7, &_14$$7, &_15$$7);
		zephir_check_call_status();
		if (!ZEPHIR_IS_TRUE_IDENTICAL(&result)) {
			ZEPHIR_INIT_NVAR(&_16$$8);
			object_init_ex(&_16$$8, phalcon_image_exceptions_compositefailed_ce);
			zephir_constructor_start(&_16$$8);
			ZEPHIR_CALL_METHOD_CACHED(NULL, &_16$$8, "__construct", &_zephir_call_cache[14]);
			zephir_check_call_status();
			zephir_constructor_finish(&_16$$8);
			zephir_throw_exception_debug(&_16$$8, "phalcon/Image/Adapter/Imagick.zep", 547);
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_INIT_NVAR(&_11$$7);
		ZVAL_STRING(&_11$$7, "Imagick::EVALUATE_MULTIPLY");
		ZEPHIR_CALL_FUNCTION(&_17$$7, "constant", &_13, 40, &_11$$7);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&_11$$7);
		ZVAL_STRING(&_11$$7, "Imagick::CHANNEL_ALPHA");
		ZEPHIR_CALL_FUNCTION(&_18$$7, "constant", &_13, 40, &_11$$7);
		zephir_check_call_status();
		ZVAL_DOUBLE(&_14$$7, fadeOpacity);
		ZEPHIR_CALL_METHOD_CACHED(NULL, &reflection, "evaluateImage", &_zephir_call_cache[15], &_17$$7, &_14$$7, &_18$$7);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD_CACHED(&hasNext, &reflection, "nextImage", &_zephir_call_cache[16]);
		zephir_check_call_status();
		if (!ZEPHIR_IS_TRUE_IDENTICAL(&hasNext)) {
			break;
		}
	}
	ZEPHIR_CALL_METHOD_CACHED(NULL, &fade, "destroy", &_zephir_call_cache[17]);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_8);
	object_init_ex(&_8, zephir_get_internal_ce(SL("imagick")));
	zephir_constructor_start(&_8);
	ZEPHIR_CALL_METHOD_CACHED(NULL, &_8, "__construct", &_zephir_call_cache[18]);
	zephir_check_call_status();
	zephir_constructor_finish(&_8);
	ZEPHIR_CPY_WRT(&image, &_8);
	ZEPHIR_INIT_NVAR(&_8);
	ZEPHIR_INIT_NVAR(&_8);
	object_init_ex(&_8, zephir_get_internal_ce(SL("imagickpixel")));
	zephir_constructor_start(&_8);
	ZEPHIR_CALL_METHOD_CACHED(NULL, &_8, "__construct", &_zephir_call_cache[19]);
	zephir_check_call_status();
	zephir_constructor_finish(&_8);
	ZEPHIR_CPY_WRT(&pixel, &_8);
	ZEPHIR_INIT_NVAR(&_8);
	ZVAL_LONG(&_2, 0);
	ZEPHIR_CALL_METHOD_CACHED(NULL, &current, "setIteratorIndex", &_zephir_call_cache[20], &_2);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD_CACHED(&_19, &current, "getImageHeight", &_zephir_call_cache[21]);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_20);
	ZVAL_LONG(&_20, height);
	ZEPHIR_INIT_VAR(&_21);
	zephir_add_function(&_21, &_19, &_20);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	height = zephir_get_intval(&_21);
	while (1) {
		if (!(1)) {
			break;
		}
		zephir_read_property_cached(&_22$$10, this_ptr, _zephir_prop_2, 948, PH_NOISY_CC | PH_READONLY);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZVAL_LONG(&_23$$10, height);
		ZEPHIR_CALL_METHOD_CACHED(NULL, &image, "newImage", &_zephir_call_cache[22], &_22$$10, &_23$$10, &pixel);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&_24$$10);
		ZVAL_STRING(&_24$$10, "Imagick::ALPHACHANNEL_SET");
		ZEPHIR_CALL_FUNCTION(&_25$$10, "constant", &_13, 40, &_24$$10);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD_CACHED(NULL, &image, "setImageAlphaChannel", &_zephir_call_cache[23], &_25$$10);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD_CACHED(&_26$$10, &current, "getColorspace", &_zephir_call_cache[24]);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD_CACHED(NULL, &image, "setColorspace", &_zephir_call_cache[25], &_26$$10);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD_CACHED(&_27$$10, &current, "getImageDelay", &_zephir_call_cache[26]);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD_CACHED(NULL, &image, "setImageDelay", &_zephir_call_cache[27], &_27$$10);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&_24$$10);
		ZVAL_STRING(&_24$$10, "Imagick::COMPOSITE_SRC");
		ZEPHIR_CALL_FUNCTION(&_28$$10, "constant", &_13, 40, &_24$$10);
		zephir_check_call_status();
		ZVAL_LONG(&_23$$10, 0);
		ZVAL_LONG(&_29$$10, 0);
		ZEPHIR_CALL_METHOD_CACHED(&result, &image, "compositeImage", &_zephir_call_cache[28], &current, &_28$$10, &_23$$10, &_29$$10);
		zephir_check_call_status();
		if (!ZEPHIR_IS_TRUE_IDENTICAL(&result)) {
			ZEPHIR_INIT_NVAR(&_30$$11);
			object_init_ex(&_30$$11, phalcon_image_exceptions_compositefailed_ce);
			zephir_constructor_start(&_30$$11);
			ZEPHIR_CALL_METHOD_CACHED(NULL, &_30$$11, "__construct", &_zephir_call_cache[29]);
			zephir_check_call_status();
			zephir_constructor_finish(&_30$$11);
			zephir_throw_exception_debug(&_30$$11, "phalcon/Image/Adapter/Imagick.zep", 589);
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_CALL_METHOD_CACHED(&_31$$10, &current, "nextImage", &_zephir_call_cache[30]);
		zephir_check_call_status();
		if (!ZEPHIR_IS_TRUE_IDENTICAL(&_31$$10)) {
			break;
		}
	}
	ZVAL_LONG(&_2, 0);
	ZEPHIR_CALL_METHOD_CACHED(NULL, &image, "setIteratorIndex", &_zephir_call_cache[31], &_2);
	zephir_check_call_status();
	ZVAL_LONG(&_2, 0);
	ZEPHIR_CALL_METHOD_CACHED(NULL, &reflection, "setIteratorIndex", &_zephir_call_cache[32], &_2);
	zephir_check_call_status();
	while (1) {
		if (!(1)) {
			break;
		}
		ZEPHIR_INIT_NVAR(&_32$$13);
		ZVAL_STRING(&_32$$13, "Imagick::COMPOSITE_OVER");
		ZEPHIR_CALL_FUNCTION(&_33$$13, "constant", &_13, 40, &_32$$13);
		zephir_check_call_status();
		zephir_read_property_cached(&_34$$13, this_ptr, _zephir_prop_3, 949, PH_NOISY_CC | PH_READONLY);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZVAL_LONG(&_35$$13, 0);
		ZEPHIR_CALL_METHOD_CACHED(&result, &image, "compositeImage", &_zephir_call_cache[33], &reflection, &_33$$13, &_35$$13, &_34$$13);
		zephir_check_call_status();
		if (!ZEPHIR_IS_TRUE_IDENTICAL(&result)) {
			ZEPHIR_INIT_NVAR(&_36$$14);
			object_init_ex(&_36$$14, phalcon_image_exceptions_compositefailed_ce);
			zephir_constructor_start(&_36$$14);
			ZEPHIR_CALL_METHOD_CACHED(NULL, &_36$$14, "__construct", &_zephir_call_cache[34]);
			zephir_check_call_status();
			zephir_constructor_finish(&_36$$14);
			zephir_throw_exception_debug(&_36$$14, "phalcon/Image/Adapter/Imagick.zep", 609);
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_CALL_METHOD_CACHED(&_37$$13, &image, "nextImage", &_zephir_call_cache[35]);
		zephir_check_call_status();
		_38$$13 = !ZEPHIR_IS_TRUE_IDENTICAL(&_37$$13);
		if (!(_38$$13)) {
			ZEPHIR_CALL_METHOD_CACHED(&_39$$13, &reflection, "nextImage", &_zephir_call_cache[36]);
			zephir_check_call_status();
			_38$$13 = !ZEPHIR_IS_TRUE_IDENTICAL(&_39$$13);
		}
		if (_38$$13) {
			break;
		}
	}
	ZEPHIR_CALL_METHOD_CACHED(NULL, &reflection, "destroy", &_zephir_call_cache[37]);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD_CACHED(NULL, &current, "clear", &_zephir_call_cache[38]);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD_CACHED(NULL, &current, "destroy", &_zephir_call_cache[39]);
	zephir_check_call_status();
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 944, &image);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CALL_METHOD_CACHED(&_19, &image, "getImageWidth", &_zephir_call_cache[40]);
	zephir_check_call_status();
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_2, 948, &_19);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CALL_METHOD_CACHED(&_40, &image, "getImageHeight", &_zephir_call_cache[41]);
	zephir_check_call_status();
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_3, 949, &_40);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_MM_RESTORE();
}

/**
 * Execute a render.
 *
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
	ZEND_TLS zephir_method_cache _zephir_call_cache[11];
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	static zend_string *_zephir_prop_2 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("image", 5, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("type", 4, 1);
	}
	if (UNEXPECTED(!_zephir_prop_2)) {
		_zephir_prop_2 = zend_string_init("mime", 4, 1);
	}

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_ZVAL(extension_param)
		Z_PARAM_LONG(quality)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 2, 0, &extension_param, &quality_param);
	zephir_get_strval(&extension, extension_param);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 944, PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CPY_WRT(&image, &_0);
	ZEPHIR_CALL_METHOD_CACHED(NULL, &image, "setFormat", &_zephir_call_cache[0], &extension);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD_CACHED(NULL, &image, "setImageFormat", &_zephir_call_cache[1], &extension);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD_CACHED(NULL, &image, "stripImage", &_zephir_call_cache[2]);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD_CACHED(&_1, &image, "getImageType", &_zephir_call_cache[3]);
	zephir_check_call_status();
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_1, 947, &_1);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CALL_METHOD_CACHED(&_2, &image, "getImageFormat", &_zephir_call_cache[4]);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_3);
	ZEPHIR_CONCAT_SV(&_3, "image/", &_2);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_2, 950, &_3);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(&_4);
	zephir_fast_strtolower(&_4, &extension);
	zephir_get_strval(&extension, &_4);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (ZEPHIR_IS_STRING(&extension, "gif")) { goto zephir_switch_0_clause_0; }
	if (ZEPHIR_IS_STRING(&extension, "jpg")) { goto zephir_switch_0_clause_1; }
	if (ZEPHIR_IS_STRING(&extension, "jpeg")) { goto zephir_switch_0_clause_2; }
	goto zephir_switch_0_end;
	zephir_switch_0_clause_0: ;
		ZEPHIR_CALL_METHOD_CACHED(NULL, this_ptr, "setFramesFormat", &_zephir_call_cache[5], &image, &extension);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD_CACHED(NULL, &image, "optimizeImageLayers", &_zephir_call_cache[6]);
		zephir_check_call_status();
		ZEPHIR_RETURN_CALL_METHOD_CACHED(&image, "getImagesBlob", &_zephir_call_cache[7]);
		zephir_check_call_status();
		RETURN_MM();
	zephir_switch_0_clause_1: ;
	zephir_switch_0_clause_2: ;
		ZEPHIR_INIT_VAR(&_5$$4);
		ZVAL_STRING(&_5$$4, "Imagick::COMPRESSION_JPEG");
		ZEPHIR_CALL_FUNCTION(&_6$$4, "constant", NULL, 40, &_5$$4);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD_CACHED(NULL, &image, "setImageCompression", &_zephir_call_cache[8], &_6$$4);
		zephir_check_call_status();
		ZVAL_LONG(&_7$$4, quality);
		ZEPHIR_CALL_METHOD_CACHED(NULL, &image, "setImageCompressionQuality", &_zephir_call_cache[9], &_7$$4);
		zephir_check_call_status();
	zephir_switch_0_end: ;

	ZEPHIR_RETURN_CALL_METHOD_CACHED(&image, "getImageBlob", &_zephir_call_cache[10]);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Execute a resize.
 *
 * @throws ImagickException
 */
PHP_METHOD(Phalcon_Image_Adapter_Imagick, processResize)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *width_param = NULL, *height_param = NULL, image, _0, _4, _5, _1$$3, _2$$3, _3$$3;
	zend_long width, height, ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&image);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZEND_TLS zephir_method_cache _zephir_call_cache[5];
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	static zend_string *_zephir_prop_2 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("image", 5, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("width", 5, 1);
	}
	if (UNEXPECTED(!_zephir_prop_2)) {
		_zephir_prop_2 = zend_string_init("height", 6, 1);
	}

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(width)
		Z_PARAM_LONG(height)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 2, 0, &width_param, &height_param);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 944, PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CPY_WRT(&image, &_0);
	ZVAL_LONG(&_0, 0);
	ZEPHIR_CALL_METHOD_CACHED(NULL, &image, "setIteratorIndex", &_zephir_call_cache[0], &_0);
	zephir_check_call_status();
	while (1) {
		if (!(1)) {
			break;
		}
		ZVAL_LONG(&_1$$3, width);
		ZVAL_LONG(&_2$$3, height);
		ZEPHIR_CALL_METHOD_CACHED(NULL, &image, "scaleImage", &_zephir_call_cache[1], &_1$$3, &_2$$3);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD_CACHED(&_3$$3, &image, "nextImage", &_zephir_call_cache[2]);
		zephir_check_call_status();
		if (!ZEPHIR_IS_TRUE_IDENTICAL(&_3$$3)) {
			break;
		}
	}
	ZEPHIR_CALL_METHOD_CACHED(&_4, &image, "getImageWidth", &_zephir_call_cache[3]);
	zephir_check_call_status();
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_1, 948, &_4);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CALL_METHOD_CACHED(&_5, &image, "getImageHeight", &_zephir_call_cache[4]);
	zephir_check_call_status();
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_2, 949, &_5);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_MM_RESTORE();
}

/**
 * Execute a rotation.
 *
 * @throws ImagickException
 */
PHP_METHOD(Phalcon_Image_Adapter_Imagick, processRotate)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *degrees_param = NULL, image, pixel, _0, _1, _7, _8, _2$$3, _3$$3, _4$$3, _5$$3, _6$$3;
	zend_long degrees, ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&image);
	ZVAL_UNDEF(&pixel);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_6$$3);
	ZEND_TLS zephir_method_cache _zephir_call_cache[7];
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	static zend_string *_zephir_prop_2 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("image", 5, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("width", 5, 1);
	}
	if (UNEXPECTED(!_zephir_prop_2)) {
		_zephir_prop_2 = zend_string_init("height", 6, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(degrees)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &degrees_param);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 944, PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CPY_WRT(&image, &_0);
	ZVAL_LONG(&_0, 0);
	ZEPHIR_CALL_METHOD_CACHED(NULL, &image, "setIteratorIndex", &_zephir_call_cache[0], &_0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_1);
	object_init_ex(&_1, zephir_get_internal_ce(SL("imagickpixel")));
	zephir_constructor_start(&_1);
	ZEPHIR_CALL_METHOD_CACHED(NULL, &_1, "__construct", &_zephir_call_cache[1]);
	zephir_check_call_status();
	zephir_constructor_finish(&_1);
	ZEPHIR_CPY_WRT(&pixel, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	while (1) {
		if (!(1)) {
			break;
		}
		ZVAL_LONG(&_2$$3, degrees);
		ZEPHIR_CALL_METHOD_CACHED(NULL, &image, "rotateImage", &_zephir_call_cache[2], &pixel, &_2$$3);
		zephir_check_call_status();
		zephir_read_property_cached(&_2$$3, this_ptr, _zephir_prop_1, 948, PH_NOISY_CC | PH_READONLY);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		zephir_read_property_cached(&_3$$3, this_ptr, _zephir_prop_2, 949, PH_NOISY_CC | PH_READONLY);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZVAL_LONG(&_4$$3, 0);
		ZVAL_LONG(&_5$$3, 0);
		ZEPHIR_CALL_METHOD_CACHED(NULL, &image, "setImagePage", &_zephir_call_cache[3], &_2$$3, &_3$$3, &_4$$3, &_5$$3);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD_CACHED(&_6$$3, &image, "nextImage", &_zephir_call_cache[4]);
		zephir_check_call_status();
		if (!ZEPHIR_IS_TRUE_IDENTICAL(&_6$$3)) {
			break;
		}
	}
	ZEPHIR_CALL_METHOD_CACHED(&_7, &image, "getImageWidth", &_zephir_call_cache[5]);
	zephir_check_call_status();
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_1, 948, &_7);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CALL_METHOD_CACHED(&_8, &image, "getImageHeight", &_zephir_call_cache[6]);
	zephir_check_call_status();
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_2, 949, &_8);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_MM_RESTORE();
}

/**
 * Execute a save.
 *
 * @throws ImagickException
 */
PHP_METHOD(Phalcon_Image_Adapter_Imagick, processSave)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long quality, ZEPHIR_LAST_CALL_STATUS;
	zval file_zv, *quality_param = NULL, extension, fp, image, _0, _1, _2, _3, _4, _5$$3, _6$$4, _7$$4, _8$$5, _9$$5, _10$$5;
	zend_string *file = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&file_zv);
	ZVAL_UNDEF(&extension);
	ZVAL_UNDEF(&fp);
	ZVAL_UNDEF(&image);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_7$$4);
	ZVAL_UNDEF(&_8$$5);
	ZVAL_UNDEF(&_9$$5);
	ZVAL_UNDEF(&_10$$5);
	ZEND_TLS zephir_method_cache _zephir_call_cache[13];
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	static zend_string *_zephir_prop_2 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("image", 5, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("type", 4, 1);
	}
	if (UNEXPECTED(!_zephir_prop_2)) {
		_zephir_prop_2 = zend_string_init("mime", 4, 1);
	}

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR(file)
		Z_PARAM_LONG(quality)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	quality_param = ZEND_CALL_ARG(execute_data, 2);
	zephir_memory_observe(&file_zv);
	ZVAL_STR_COPY(&file_zv, file);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 944, PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CPY_WRT(&image, &_0);
	ZVAL_LONG(&_0, 4);
	ZEPHIR_CALL_FUNCTION(&extension, "pathinfo", NULL, 66, &file_zv, &_0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD_CACHED(NULL, &image, "setFormat", &_zephir_call_cache[0], &extension);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD_CACHED(NULL, &image, "setImageFormat", &_zephir_call_cache[1], &extension);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD_CACHED(&_1, &image, "getImageType", &_zephir_call_cache[2]);
	zephir_check_call_status();
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_1, 947, &_1);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CALL_METHOD_CACHED(&_2, &image, "getImageFormat", &_zephir_call_cache[3]);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_3);
	ZEPHIR_CONCAT_SV(&_3, "image/", &_2);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_2, 950, &_3);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(&_4);
	zephir_fast_strtolower(&_4, &extension);
	ZEPHIR_CPY_WRT(&extension, &_4);
	if (ZEPHIR_IS_STRING(&extension, "gif")) { goto zephir_switch_0_clause_0; }
	if (ZEPHIR_IS_STRING(&extension, "jpg")) { goto zephir_switch_0_clause_1; }
	if (ZEPHIR_IS_STRING(&extension, "jpeg")) { goto zephir_switch_0_clause_2; }
	goto zephir_switch_0_end;
	zephir_switch_0_clause_0: ;
		ZEPHIR_CALL_METHOD_CACHED(NULL, this_ptr, "setFramesFormat", &_zephir_call_cache[4], &image, &extension);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD_CACHED(NULL, &image, "optimizeImageLayers", &_zephir_call_cache[5]);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_5$$3);
		ZVAL_STRING(&_5$$3, "w");
		ZEPHIR_CALL_METHOD_CACHED(&fp, this_ptr, "phpFopen", &_zephir_call_cache[6], &file_zv, &_5$$3);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD_CACHED(NULL, &image, "writeImagesFile", &_zephir_call_cache[7], &fp);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD_CACHED(NULL, this_ptr, "phpFclose", &_zephir_call_cache[8], &fp);
		zephir_check_call_status();
		RETURN_MM_BOOL(1);
	zephir_switch_0_clause_1: ;
	zephir_switch_0_clause_2: ;
		ZEPHIR_INIT_VAR(&_6$$4);
		ZVAL_STRING(&_6$$4, "Imagick::COMPRESSION_JPEG");
		ZEPHIR_CALL_FUNCTION(&_7$$4, "constant", NULL, 40, &_6$$4);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD_CACHED(NULL, &image, "setImageCompression", &_zephir_call_cache[9], &_7$$4);
		zephir_check_call_status();
	zephir_switch_0_end: ;

	if (quality >= 0) {
		ZVAL_LONG(&_9$$5, quality);
		ZVAL_LONG(&_10$$5, 1);
		ZEPHIR_CALL_METHOD_CACHED(&_8$$5, this_ptr, "checkHighLow", &_zephir_call_cache[10], &_9$$5, &_10$$5);
		zephir_check_call_status();
		quality = zephir_get_intval(&_8$$5);
		ZVAL_LONG(&_9$$5, quality);
		ZEPHIR_CALL_METHOD_CACHED(NULL, &image, "setImageCompressionQuality", &_zephir_call_cache[11], &_9$$5);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_METHOD_CACHED(NULL, &image, "writeImage", &_zephir_call_cache[12], &file_zv);
	zephir_check_call_status();
	RETURN_MM_BOOL(1);
}

/**
 * Execute a sharpen.
 *
 * @throws ImagickException
 */
PHP_METHOD(Phalcon_Image_Adapter_Imagick, processSharpen)
{
	double sigma = 0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *amount_param = NULL, image, _0, _1, _2$$3, _3$$3, _4$$3;
	zend_long amount, ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&image);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZEND_TLS zephir_method_cache _zephir_call_cache[3];
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("image", 5, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(amount)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &amount_param);
	ZEPHIR_INIT_VAR(&_0);
	if (amount < 5) {
		ZEPHIR_INIT_NVAR(&_0);
		ZVAL_LONG(&_0, 5);
	} else {
		ZEPHIR_INIT_NVAR(&_0);
		ZVAL_LONG(&_0, amount);
	}
	amount = zephir_get_intval(&_0);
	sigma =  (zephir_safe_div_double_long(((double) amount * 3.0), 100));
	zephir_read_property_cached(&_1, this_ptr, _zephir_prop_0, 944, PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CPY_WRT(&image, &_1);
	ZVAL_LONG(&_1, 0);
	ZEPHIR_CALL_METHOD_CACHED(NULL, &image, "setIteratorIndex", &_zephir_call_cache[0], &_1);
	zephir_check_call_status();
	while (1) {
		if (!(1)) {
			break;
		}
		ZVAL_LONG(&_2$$3, 0);
		ZVAL_DOUBLE(&_3$$3, sigma);
		ZEPHIR_CALL_METHOD_CACHED(NULL, &image, "sharpenImage", &_zephir_call_cache[1], &_2$$3, &_3$$3);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD_CACHED(&_4$$3, &image, "nextImage", &_zephir_call_cache[2]);
		zephir_check_call_status();
		if (!ZEPHIR_IS_TRUE_IDENTICAL(&_4$$3)) {
			break;
		}
	}
	ZEPHIR_MM_RESTORE();
}

/**
 * Execute a text
 *
 * @throws ImagickDrawException
 * @throws ImagickException
 * @throws ImagickPixelException
 */
PHP_METHOD(Phalcon_Image_Adapter_Imagick, processText)
{
	zend_bool _7$$8, _9$$8, _10$$8, _11$$8, _13$$11, _15$$11, _16$$11, _17$$11;
	double textOpacity = 0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long opacity, red, green, blue, size, ZEPHIR_LAST_CALL_STATUS, _21, _22;
	zval text_zv, *offsetX = NULL, offsetX_sub, *offsetY = NULL, offsetY_sub, *opacity_param = NULL, *red_param = NULL, *green_param = NULL, *blue_param = NULL, *size_param = NULL, fontFile_zv, color, draw, gravity, image, x, y, _0, _1, _2, _3, _4$$4, _5$$5, _6$$7, _8$$8, _12$$8, _14$$11, _18$$11, _19$$12, _20$$12, _23$$14, _24$$14;
	zend_string *text = NULL, *fontFile = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&text_zv);
	ZVAL_UNDEF(&offsetX_sub);
	ZVAL_UNDEF(&offsetY_sub);
	ZVAL_UNDEF(&fontFile_zv);
	ZVAL_UNDEF(&color);
	ZVAL_UNDEF(&draw);
	ZVAL_UNDEF(&gravity);
	ZVAL_UNDEF(&image);
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
	ZVAL_UNDEF(&_12$$8);
	ZVAL_UNDEF(&_14$$11);
	ZVAL_UNDEF(&_18$$11);
	ZVAL_UNDEF(&_19$$12);
	ZVAL_UNDEF(&_20$$12);
	ZVAL_UNDEF(&_23$$14);
	ZVAL_UNDEF(&_24$$14);
	ZEND_TLS zephir_method_cache _zephir_call_cache[11];
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("image", 5, 1);
	}

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
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	offsetX = ZEND_CALL_ARG(execute_data, 2);
	offsetY = ZEND_CALL_ARG(execute_data, 3);
	opacity_param = ZEND_CALL_ARG(execute_data, 4);
	red_param = ZEND_CALL_ARG(execute_data, 5);
	green_param = ZEND_CALL_ARG(execute_data, 6);
	blue_param = ZEND_CALL_ARG(execute_data, 7);
	size_param = ZEND_CALL_ARG(execute_data, 8);
	zephir_memory_observe(&text_zv);
	ZVAL_STR_COPY(&text_zv, text);
	ZEPHIR_SEPARATE_PARAM(offsetX);
	ZEPHIR_SEPARATE_PARAM(offsetY);
	if (!fontFile) {
		ZEPHIR_INIT_VAR(&fontFile_zv);
	} else {
		zephir_memory_observe(&fontFile_zv);
	ZVAL_STR_COPY(&fontFile_zv, fontFile);
	}
	textOpacity =  (zephir_safe_div_double_long((double) opacity, 100));
	ZEPHIR_INIT_VAR(&_0);
	object_init_ex(&_0, zephir_get_internal_ce(SL("imagickdraw")));
	zephir_constructor_start(&_0);
	ZEPHIR_CALL_METHOD_CACHED(NULL, &_0, "__construct", &_zephir_call_cache[0]);
	zephir_check_call_status();
	zephir_constructor_finish(&_0);
	ZEPHIR_CPY_WRT(&draw, &_0);
	ZEPHIR_INIT_NVAR(&_0);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "rgb(%d, %d, %d)");
	ZVAL_LONG(&_1, red);
	ZVAL_LONG(&_2, green);
	ZVAL_LONG(&_3, blue);
	ZEPHIR_CALL_FUNCTION(&color, "sprintf", NULL, 38, &_0, &_1, &_2, &_3);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_0);
	object_init_ex(&_0, zephir_get_internal_ce(SL("imagickpixel")));
	zephir_constructor_start(&_0);
	ZEPHIR_CALL_METHOD_CACHED(NULL, &_0, "__construct", &_zephir_call_cache[1], &color);
	zephir_check_call_status();
	zephir_constructor_finish(&_0);
	ZEPHIR_CALL_METHOD_CACHED(NULL, &draw, "setFillColor", &_zephir_call_cache[2], &_0);
	zephir_check_call_status();
	if (Z_TYPE_P(&fontFile_zv) != IS_NULL) {
		ZEPHIR_CALL_METHOD_CACHED(NULL, &draw, "setFont", &_zephir_call_cache[3], &fontFile_zv);
		zephir_check_call_status();
	}
	if (size) {
		ZVAL_LONG(&_4$$4, size);
		ZEPHIR_CALL_METHOD_CACHED(NULL, &draw, "setFontSize", &_zephir_call_cache[4], &_4$$4);
		zephir_check_call_status();
	}
	if (textOpacity) {
		ZVAL_DOUBLE(&_5$$5, textOpacity);
		ZEPHIR_CALL_METHOD_CACHED(NULL, &draw, "setfillopacity", &_zephir_call_cache[5], &_5$$5);
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
			ZEPHIR_CALL_FUNCTION(&gravity, "constant", NULL, 40, &_6$$7);
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
				ZEPHIR_CALL_FUNCTION(&gravity, "constant", NULL, 40, &_8$$8);
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
				ZEPHIR_CALL_FUNCTION(&gravity, "constant", NULL, 40, &_8$$8);
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
				ZEPHIR_CALL_FUNCTION(&gravity, "constant", NULL, 40, &_8$$8);
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
				ZEPHIR_CALL_FUNCTION(&gravity, "constant", NULL, 40, &_8$$8);
				zephir_check_call_status();
			} else {
			}
			ZEPHIR_INIT_NVAR(offsetX);
			ZVAL_LONG(offsetX, 0);
			if (ZEPHIR_LT_LONG(&y, 0)) {
				ZEPHIR_INIT_VAR(&_12$$8);
				ZVAL_LONG(&_12$$8, -1);
				ZEPHIR_INIT_NVAR(offsetY);
				mul_function(offsetY, &y, &_12$$8);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
			} else {
			}
		}
	} else if (Z_TYPE_P(offsetX) == IS_LONG) {
		ZEPHIR_INIT_VAR(&x);
		ZVAL_LONG(&x, zephir_get_intval(offsetX));
		if (zephir_is_true(offsetX)) {
			if (((Z_TYPE_P(offsetY) == IS_TRUE || Z_TYPE_P(offsetY) == IS_FALSE) == 1)) {
				_13$$11 = ZEPHIR_IS_TRUE_IDENTICAL(offsetY);
				if (_13$$11) {
					_13$$11 = ZEPHIR_LT_LONG(&x, 0);
				}
				if (_13$$11) {
					ZEPHIR_INIT_VAR(&_14$$11);
					ZVAL_STRING(&_14$$11, "Imagick::GRAVITY_SOUTHEAST");
					ZEPHIR_CALL_FUNCTION(&gravity, "constant", NULL, 40, &_14$$11);
					zephir_check_call_status();
				} else {
				}
				_15$$11 = ZEPHIR_IS_TRUE_IDENTICAL(offsetY);
				if (_15$$11) {
					_15$$11 = ZEPHIR_GE_LONG(&x, 0);
				}
				if (_15$$11) {
					ZEPHIR_INIT_NVAR(&_14$$11);
					ZVAL_STRING(&_14$$11, "Imagick::GRAVITY_SOUTH");
					ZEPHIR_CALL_FUNCTION(&gravity, "constant", NULL, 40, &_14$$11);
					zephir_check_call_status();
				} else {
				}
				_16$$11 = !ZEPHIR_IS_TRUE_IDENTICAL(offsetY);
				if (_16$$11) {
					_16$$11 = ZEPHIR_LT_LONG(&x, 0);
				}
				if (_16$$11) {
					ZEPHIR_INIT_NVAR(&_14$$11);
					ZVAL_STRING(&_14$$11, "Imagick::GRAVITY_EAST");
					ZEPHIR_CALL_FUNCTION(&gravity, "constant", NULL, 40, &_14$$11);
					zephir_check_call_status();
				} else {
				}
				_17$$11 = !ZEPHIR_IS_TRUE_IDENTICAL(offsetY);
				if (_17$$11) {
					_17$$11 = ZEPHIR_GE_LONG(&x, 0);
				}
				if (_17$$11) {
					ZEPHIR_INIT_NVAR(&_14$$11);
					ZVAL_STRING(&_14$$11, "Imagick::GRAVITY_WEST");
					ZEPHIR_CALL_FUNCTION(&gravity, "constant", NULL, 40, &_14$$11);
					zephir_check_call_status();
				} else {
				}
				ZEPHIR_INIT_NVAR(offsetY);
				ZVAL_LONG(offsetY, 0);
				if (ZEPHIR_LT_LONG(&x, 0)) {
					ZEPHIR_INIT_VAR(&_18$$11);
					ZVAL_LONG(&_18$$11, -1);
					ZEPHIR_INIT_NVAR(offsetX);
					mul_function(offsetX, &x, &_18$$11);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
				} else {
				}
			} else if (Z_TYPE_P(offsetY) == IS_LONG) {
				ZEPHIR_INIT_NVAR(&y);
				ZVAL_LONG(&y, zephir_get_intval(offsetY));
				if (ZEPHIR_LT_LONG(&x, 0)) {
					ZEPHIR_INIT_VAR(&_19$$12);
					ZVAL_LONG(&_19$$12, -1);
					ZEPHIR_INIT_NVAR(offsetX);
					mul_function(offsetX, &x, &_19$$12);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
				} else {
					ZEPHIR_INIT_NVAR(offsetX);
					ZVAL_LONG(offsetX, 0);
				}
				if (ZEPHIR_LT_LONG(&y, 0)) {
					ZEPHIR_INIT_NVAR(&_19$$12);
					ZVAL_LONG(&_19$$12, -1);
					ZEPHIR_INIT_NVAR(offsetY);
					mul_function(offsetY, &y, &_19$$12);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
				} else {
				}
				if (ZEPHIR_LT_LONG(&y, 0)) {
					ZEPHIR_INIT_VAR(&_20$$12);
					ZVAL_STRING(&_20$$12, "Imagick::GRAVITY_SOUTHEAST");
					ZEPHIR_CALL_FUNCTION(&gravity, "constant", NULL, 40, &_20$$12);
					zephir_check_call_status();
				} else {
				}
				if (ZEPHIR_GE_LONG(&y, 0)) {
					ZEPHIR_INIT_NVAR(&_20$$12);
					ZVAL_STRING(&_20$$12, "Imagick::GRAVITY_NORTHEAST");
					ZEPHIR_CALL_FUNCTION(&gravity, "constant", NULL, 40, &_20$$12);
					zephir_check_call_status();
				} else {
				}
			}
		}
	}
	if (Z_TYPE_P(&gravity) != IS_NULL) {
		ZEPHIR_CALL_METHOD_CACHED(NULL, &draw, "setGravity", &_zephir_call_cache[6], &gravity);
		zephir_check_call_status();
	}
	_21 = zephir_get_intval(offsetX);
	ZEPHIR_INIT_NVAR(offsetX);
	ZVAL_LONG(offsetX, _21);
	_22 = zephir_get_intval(offsetY);
	ZEPHIR_INIT_NVAR(offsetY);
	ZVAL_LONG(offsetY, _22);
	zephir_read_property_cached(&_1, this_ptr, _zephir_prop_0, 944, PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CPY_WRT(&image, &_1);
	ZVAL_LONG(&_1, 0);
	ZEPHIR_CALL_METHOD_CACHED(NULL, &image, "setIteratorIndex", &_zephir_call_cache[7], &_1);
	zephir_check_call_status();
	while (1) {
		if (!(1)) {
			break;
		}
		ZVAL_LONG(&_23$$14, 0);
		ZEPHIR_CALL_METHOD_CACHED(NULL, &image, "annotateImage", &_zephir_call_cache[8], &draw, offsetX, offsetY, &_23$$14, &text_zv);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD_CACHED(&_24$$14, &image, "nextImage", &_zephir_call_cache[9]);
		zephir_check_call_status();
		if (!ZEPHIR_IS_TRUE_IDENTICAL(&_24$$14)) {
			break;
		}
	}
	ZEPHIR_CALL_METHOD_CACHED(NULL, &draw, "destroy", &_zephir_call_cache[10]);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
}

/**
 * Add Watermark
 *
 * @throws Exception
 * @throws ImagickException
 */
PHP_METHOD(Phalcon_Image_Adapter_Imagick, processWatermark)
{
	double watermarkOpacity = 0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_3 = NULL;
	zend_long offsetX, offsetY, opacity, ZEPHIR_LAST_CALL_STATUS;
	zval *watermark, watermark_sub, *offsetX_param = NULL, *offsetY_param = NULL, *opacity_param = NULL, current, image, result, _0, _1, _2, _4, _5, _6$$3, _7$$3, _8$$3, _9$$3, _11$$3, _10$$4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&watermark_sub);
	ZVAL_UNDEF(&current);
	ZVAL_UNDEF(&image);
	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_7$$3);
	ZVAL_UNDEF(&_8$$3);
	ZVAL_UNDEF(&_9$$3);
	ZVAL_UNDEF(&_11$$3);
	ZVAL_UNDEF(&_10$$4);
	ZEND_TLS zephir_method_cache _zephir_call_cache[10];
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("image", 5, 1);
	}

	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_OBJECT_OF_CLASS(watermark, phalcon_image_adapter_adapterinterface_ce)
		Z_PARAM_LONG(offsetX)
		Z_PARAM_LONG(offsetY)
		Z_PARAM_LONG(opacity)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 4, 0, &watermark, &offsetX_param, &offsetY_param, &opacity_param);
	watermarkOpacity =  (zephir_safe_div_double_long((double) opacity, 100));
	ZEPHIR_INIT_VAR(&_0);
	object_init_ex(&_0, zephir_get_internal_ce(SL("imagick")));
	zephir_constructor_start(&_0);
	ZEPHIR_CALL_METHOD_CACHED(NULL, &_0, "__construct", &_zephir_call_cache[0]);
	zephir_check_call_status();
	zephir_constructor_finish(&_0);
	ZEPHIR_CPY_WRT(&image, &_0);
	ZEPHIR_INIT_NVAR(&_0);
	ZEPHIR_CALL_METHOD_CACHED(&_1, watermark, "render", &_zephir_call_cache[1]);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD_CACHED(NULL, &image, "readImageBlob", &_zephir_call_cache[2], &_1);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "Imagick::EVALUATE_MULTIPLY");
	ZEPHIR_CALL_FUNCTION(&_2, "constant", &_3, 40, &_0);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "Imagick::CHANNEL_ALPHA");
	ZEPHIR_CALL_FUNCTION(&_4, "constant", &_3, 40, &_0);
	zephir_check_call_status();
	ZVAL_DOUBLE(&_5, watermarkOpacity);
	ZEPHIR_CALL_METHOD_CACHED(NULL, &image, "evaluateImage", &_zephir_call_cache[3], &_2, &_5, &_4);
	zephir_check_call_status();
	zephir_memory_observe(&current);
	zephir_read_property_cached(&current, this_ptr, _zephir_prop_0, 944, PH_NOISY_CC);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZVAL_LONG(&_5, 0);
	ZEPHIR_CALL_METHOD_CACHED(NULL, &current, "setIteratorIndex", &_zephir_call_cache[4], &_5);
	zephir_check_call_status();
	while (1) {
		if (!(1)) {
			break;
		}
		ZEPHIR_INIT_NVAR(&_6$$3);
		ZVAL_STRING(&_6$$3, "Imagick::COMPOSITE_OVER");
		ZEPHIR_CALL_FUNCTION(&_7$$3, "constant", &_3, 40, &_6$$3);
		zephir_check_call_status();
		ZVAL_LONG(&_8$$3, offsetX);
		ZVAL_LONG(&_9$$3, offsetY);
		ZEPHIR_CALL_METHOD_CACHED(&result, &current, "compositeImage", &_zephir_call_cache[5], &image, &_7$$3, &_8$$3, &_9$$3);
		zephir_check_call_status();
		if (!ZEPHIR_IS_TRUE_IDENTICAL(&result)) {
			ZEPHIR_INIT_NVAR(&_10$$4);
			object_init_ex(&_10$$4, phalcon_image_exceptions_compositefailed_ce);
			zephir_constructor_start(&_10$$4);
			ZEPHIR_CALL_METHOD_CACHED(NULL, &_10$$4, "__construct", &_zephir_call_cache[6]);
			zephir_check_call_status();
			zephir_constructor_finish(&_10$$4);
			zephir_throw_exception_debug(&_10$$4, "phalcon/Image/Adapter/Imagick.zep", 952);
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_CALL_METHOD_CACHED(&_11$$3, &current, "nextImage", &_zephir_call_cache[7]);
		zephir_check_call_status();
		if (!ZEPHIR_IS_TRUE_IDENTICAL(&_11$$3)) {
			break;
		}
	}
	ZEPHIR_CALL_METHOD_CACHED(NULL, &image, "clear", &_zephir_call_cache[8]);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD_CACHED(NULL, &image, "destroy", &_zephir_call_cache[9]);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
}

/**
 * Checks if Imagick is enabled
 *
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
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("version", 7, 1);
	}
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "imagick");
	if (1 != zephir_class_exists(&_0, 1)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_image_exceptions_extensionnotloaded_ce, "Imagick", "phalcon/Image/Adapter/Imagick.zep", 972);
		return;
	}
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "Imagick::IMAGICK_EXTNUM");
	ZEPHIR_CALL_FUNCTION(&_2, "defined", NULL, 39, &_1);
	zephir_check_call_status();
	if (zephir_is_true(&_2)) {
		ZEPHIR_INIT_VAR(&_3$$4);
		ZVAL_STRING(&_3$$4, "Imagick::IMAGICK_EXTNUM");
		ZEPHIR_CALL_FUNCTION(&_4$$4, "constant", NULL, 40, &_3$$4);
		zephir_check_call_status();
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 951, &_4$$4);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	ZEPHIR_MM_RESTORE();
}

/**
 * Marks every frame with the format.
 *
 * setImageFormat() marks the current frame only, and a wand built with
 * newImage() carries no format at all, which stops a multi frame write.
 *
 * @throws ImagickException
 */
PHP_METHOD(Phalcon_Image_Adapter_Imagick, setFramesFormat)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_string *extension = NULL;
	zval *image, image_sub, extension_zv, _0, _1$$3;

	ZVAL_UNDEF(&image_sub);
	ZVAL_UNDEF(&extension_zv);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	ZEND_TLS zephir_method_cache _zephir_call_cache[4];
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_ZVAL(image)
		Z_PARAM_STR(extension)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	image = ZEND_CALL_ARG(execute_data, 1);
	zephir_memory_observe(&extension_zv);
	ZVAL_STR_COPY(&extension_zv, extension);
	ZVAL_LONG(&_0, 0);
	ZEPHIR_CALL_METHOD_CACHED(NULL, image, "setIteratorIndex", &_zephir_call_cache[0], &_0);
	zephir_check_call_status();
	while (1) {
		if (!(1)) {
			break;
		}
		ZEPHIR_CALL_METHOD_CACHED(NULL, image, "setImageFormat", &_zephir_call_cache[1], &extension_zv);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD_CACHED(&_1$$3, image, "nextImage", &_zephir_call_cache[2]);
		zephir_check_call_status();
		if (!ZEPHIR_IS_TRUE_IDENTICAL(&_1$$3)) {
			break;
		}
	}
	ZEPHIR_CALL_METHOD_CACHED(NULL, image, "setFormat", &_zephir_call_cache[3], &extension_zv);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
}

/**
 * Closes an open file pointer
 *
 * @link https://php.net/manual/en/function.fclose.php
 *
 * @param resource $handle
 *
 * @return bool
 */
PHP_METHOD(Phalcon_Image_Adapter_Imagick, phpFclose)
{
	zval *handle, handle_sub;

	ZVAL_UNDEF(&handle_sub);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle);
	RETURN_BOOL(zephir_fclose(handle));
}

/**
 * Gets line from file pointer and parse for CSV fields
 *
 * @param resource $stream
 * @param int      $length
 * @param string   $separator
 * @param string   $enclosure
 * @param string   $escape
 *
 * @return array<array-key, mixed>|false
 *
 * @link https://php.net/manual/en/function.fgetcsv.php
 */
PHP_METHOD(Phalcon_Image_Adapter_Imagick, phpFgetCsv)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_string *separator = NULL;
	zend_long length = 0, ZEPHIR_LAST_CALL_STATUS;
	zval *stream, stream_sub, *length_param = NULL, separator_zv, *enclosure = NULL, enclosure_sub, *escape = NULL, escape_sub, __$null, _0;

	ZVAL_UNDEF(&stream_sub);
	ZVAL_UNDEF(&separator_zv);
	ZVAL_UNDEF(&enclosure_sub);
	ZVAL_UNDEF(&escape_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 5)
		Z_PARAM_ZVAL(stream)
		Z_PARAM_OPTIONAL
		Z_PARAM_LONG(length)
		Z_PARAM_STR(separator)
		Z_PARAM_ZVAL_OR_NULL(enclosure)
		Z_PARAM_ZVAL_OR_NULL(escape)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	stream = ZEND_CALL_ARG(execute_data, 1);
	if (ZEND_NUM_ARGS() > 1) {
		length_param = ZEND_CALL_ARG(execute_data, 2);
	}
	if (ZEND_NUM_ARGS() > 3) {
		enclosure = ZEND_CALL_ARG(execute_data, 4);
	}
	if (ZEND_NUM_ARGS() > 4) {
		escape = ZEND_CALL_ARG(execute_data, 5);
	}
	if (!separator) {
		separator = zend_string_init(ZEND_STRL(","), 0);
		zephir_memory_observe(&separator_zv);
		ZVAL_STR(&separator_zv, separator);
	} else {
		zephir_memory_observe(&separator_zv);
	ZVAL_STR_COPY(&separator_zv, separator);
	}
	if (!enclosure) {
		enclosure = &enclosure_sub;
		ZEPHIR_CPY_WRT(enclosure, &__$null);
	} else {
		ZEPHIR_SEPARATE_PARAM(enclosure);
	}
	if (!escape) {
		escape = &escape_sub;
		ZEPHIR_CPY_WRT(escape, &__$null);
	} else {
		ZEPHIR_SEPARATE_PARAM(escape);
	}
	if (Z_TYPE_P(enclosure) == IS_NULL) {
		ZEPHIR_INIT_NVAR(enclosure);
		ZVAL_STRING(enclosure, "\"");
	}
	if (Z_TYPE_P(escape) == IS_NULL) {
		ZEPHIR_INIT_NVAR(escape);
		ZVAL_STRING(escape, "\\");
	}
	ZVAL_LONG(&_0, length);
	ZEPHIR_RETURN_CALL_FUNCTION("fgetcsv", NULL, 44, stream, &_0, &separator_zv, enclosure, escape);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * @param string $filename
 *
 * @return bool
 *
 * @link https://php.net/manual/en/function.file-exists.php
 */
PHP_METHOD(Phalcon_Image_Adapter_Imagick, phpFileExists)
{
	zval filename_zv;
	zend_string *filename = NULL;

	ZVAL_UNDEF(&filename_zv);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(filename)
	ZEND_PARSE_PARAMETERS_END();
	ZVAL_STR(&filename_zv, filename);
	RETURN_BOOL((zephir_file_exists(&filename_zv) == SUCCESS));
}

/**
 * @param string        $filename
 * @param bool          $useIncludePath
 * @param resource|null $context
 * @param int           $offset
 * @param int|null      $length
 *
 * @return false|string
 *
 * @link https://php.net/manual/en/function.file-get-contents.php
 */
PHP_METHOD(Phalcon_Image_Adapter_Imagick, phpFileGetContents)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_2 = NULL;
	zend_long offset = 0, length = 0, ZEPHIR_LAST_CALL_STATUS;
	zend_bool useIncludePath = 0;
	zval filename_zv, *useIncludePath_param = NULL, *context = NULL, context_sub, *offset_param = NULL, *length_param = NULL, __$null, _0$$3, _1$$3, _3, _4, _5;
	zend_string *filename = NULL;

	ZVAL_UNDEF(&filename_zv);
	ZVAL_UNDEF(&context_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 5)
		Z_PARAM_STR(filename)
		Z_PARAM_OPTIONAL
		Z_PARAM_BOOL(useIncludePath)
		Z_PARAM_ZVAL_OR_NULL(context)
		Z_PARAM_LONG(offset)
		Z_PARAM_LONG_OR_NULL(length, is_null_true)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	if (ZEND_NUM_ARGS() > 1) {
		useIncludePath_param = ZEND_CALL_ARG(execute_data, 2);
	}
	if (ZEND_NUM_ARGS() > 2) {
		context = ZEND_CALL_ARG(execute_data, 3);
	}
	if (ZEND_NUM_ARGS() > 3) {
		offset_param = ZEND_CALL_ARG(execute_data, 4);
	}
	if (ZEND_NUM_ARGS() > 4) {
		length_param = ZEND_CALL_ARG(execute_data, 5);
	}
	zephir_memory_observe(&filename_zv);
	ZVAL_STR_COPY(&filename_zv, filename);
	if (!context) {
		context = &context_sub;
		context = &__$null;
	}
	if (0 == (length != 0)) {
		ZVAL_BOOL(&_0$$3, (useIncludePath ? 1 : 0));
		ZVAL_LONG(&_1$$3, offset);
		ZEPHIR_RETURN_CALL_FUNCTION("file_get_contents", &_2, 45, &filename_zv, &_0$$3, context, &_1$$3);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZVAL_BOOL(&_3, (useIncludePath ? 1 : 0));
	ZVAL_LONG(&_4, offset);
	ZVAL_LONG(&_5, length);
	ZEPHIR_RETURN_CALL_FUNCTION("file_get_contents", &_2, 45, &filename_zv, &_3, context, &_4, &_5);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * @param string   $filename
 * @param mixed    $data
 * @param int      $flags
 * @param resource $context
 *
 * @return false|int
 *
 * @link https://php.net/manual/en/function.file-put-contents.php
 */
PHP_METHOD(Phalcon_Image_Adapter_Imagick, phpFilePutContents)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long flags = 0, ZEPHIR_LAST_CALL_STATUS;
	zval filename_zv, *data, data_sub, *flags_param = NULL, *context = NULL, context_sub, __$null, _0;
	zend_string *filename = NULL;

	ZVAL_UNDEF(&filename_zv);
	ZVAL_UNDEF(&data_sub);
	ZVAL_UNDEF(&context_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 4)
		Z_PARAM_STR(filename)
		Z_PARAM_ZVAL(data)
		Z_PARAM_OPTIONAL
		Z_PARAM_LONG(flags)
		Z_PARAM_ZVAL_OR_NULL(context)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	data = ZEND_CALL_ARG(execute_data, 2);
	if (ZEND_NUM_ARGS() > 2) {
		flags_param = ZEND_CALL_ARG(execute_data, 3);
	}
	if (ZEND_NUM_ARGS() > 3) {
		context = ZEND_CALL_ARG(execute_data, 4);
	}
	zephir_memory_observe(&filename_zv);
	ZVAL_STR_COPY(&filename_zv, filename);
	if (!context) {
		context = &context_sub;
		context = &__$null;
	}
	ZVAL_LONG(&_0, flags);
	ZEPHIR_RETURN_CALL_FUNCTION("file_put_contents", NULL, 46, &filename_zv, data, &_0, context);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * @param string        $filename
 * @param string        $mode
 * @param bool          $useIncludePath
 * @param resource|null $context
 *
 * @return resource|false
 *
 * @link https://php.net/manual/en/function.fopen.php
 */
PHP_METHOD(Phalcon_Image_Adapter_Imagick, phpFopen)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool useIncludePath = 0;
	zval filename_zv, mode_zv, *useIncludePath_param = NULL, *context = NULL, context_sub, __$null, _0;
	zend_string *filename = NULL, *mode = NULL;

	ZVAL_UNDEF(&filename_zv);
	ZVAL_UNDEF(&mode_zv);
	ZVAL_UNDEF(&context_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 4)
		Z_PARAM_STR(filename)
		Z_PARAM_STR(mode)
		Z_PARAM_OPTIONAL
		Z_PARAM_BOOL(useIncludePath)
		Z_PARAM_ZVAL_OR_NULL(context)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	if (ZEND_NUM_ARGS() > 2) {
		useIncludePath_param = ZEND_CALL_ARG(execute_data, 3);
	}
	if (ZEND_NUM_ARGS() > 3) {
		context = ZEND_CALL_ARG(execute_data, 4);
	}
	zephir_memory_observe(&filename_zv);
	ZVAL_STR_COPY(&filename_zv, filename);
	zephir_memory_observe(&mode_zv);
	ZVAL_STR_COPY(&mode_zv, mode);
	if (!context) {
		context = &context_sub;
		context = &__$null;
	}
	ZVAL_BOOL(&_0, (useIncludePath ? 1 : 0));
	ZEPHIR_RETURN_CALL_FUNCTION("fopen", NULL, 47, &filename_zv, &mode_zv, &_0, context);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Binary-safe file write
 *
 * @link https://php.net/manual/en/function.fwrite.php
 *
 * @param resource $handle
 * @param string   $data
 * @param int|null $length
 *
 * @return false|int
 */
PHP_METHOD(Phalcon_Image_Adapter_Imagick, phpFwrite)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_1 = NULL;
	zend_long length = 0, ZEPHIR_LAST_CALL_STATUS;
	zend_string *data = NULL;
	zval *handle, handle_sub, data_zv, *length_param = NULL, _0;

	ZVAL_UNDEF(&handle_sub);
	ZVAL_UNDEF(&data_zv);
	ZVAL_UNDEF(&_0);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 3)
		Z_PARAM_ZVAL(handle)
		Z_PARAM_STR(data)
		Z_PARAM_OPTIONAL
		Z_PARAM_LONG_OR_NULL(length, is_null_true)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	handle = ZEND_CALL_ARG(execute_data, 1);
	if (ZEND_NUM_ARGS() > 2) {
		length_param = ZEND_CALL_ARG(execute_data, 3);
	}
	zephir_memory_observe(&data_zv);
	ZVAL_STR_COPY(&data_zv, data);
	if (0 == (length != 0)) {
		zephir_fwrite(return_value, handle, &data_zv);
		RETURN_MM();
	}
	ZVAL_LONG(&_0, length);
	ZEPHIR_RETURN_CALL_FUNCTION("fwrite", &_1, 48, handle, &data_zv, &_0);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Tells whether the filename is a directory
 *
 * @param string $filename
 *
 * @return bool
 *
 * @link https://php.net/manual/en/function.is-dir.php
 */
PHP_METHOD(Phalcon_Image_Adapter_Imagick, phpIsDir)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval filename_zv;
	zend_string *filename = NULL;

	ZVAL_UNDEF(&filename_zv);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(filename)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&filename_zv);
	ZVAL_STR_COPY(&filename_zv, filename);
	ZEPHIR_RETURN_CALL_FUNCTION("is_dir", NULL, 49, &filename_zv);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Tells whether the filename is writable
 *
 * @param string $filename
 *
 * @return bool
 *
 * @link https://php.net/manual/en/function.is-writable.php
 */
PHP_METHOD(Phalcon_Image_Adapter_Imagick, phpIsWritable)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval filename_zv;
	zend_string *filename = NULL;

	ZVAL_UNDEF(&filename_zv);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(filename)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&filename_zv);
	ZVAL_STR_COPY(&filename_zv, filename);
	ZEPHIR_RETURN_CALL_FUNCTION("is_writable", NULL, 50, &filename_zv);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Makes a directory
 *
 * @param string        $directory
 * @param int           $permissions
 * @param bool          $recursive
 * @param resource|null $context
 *
 * @return bool
 *
 * @link https://php.net/manual/en/function.mkdir.php
 */
PHP_METHOD(Phalcon_Image_Adapter_Imagick, phpMkdir)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_bool recursive = 0;
	zend_long permissions = 0777, ZEPHIR_LAST_CALL_STATUS;
	zval directory_zv, *permissions_param = NULL, *recursive_param = NULL, *context = NULL, context_sub, __$null, _0, _1;
	zend_string *directory = NULL;

	ZVAL_UNDEF(&directory_zv);
	ZVAL_UNDEF(&context_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 4)
		Z_PARAM_STR(directory)
		Z_PARAM_OPTIONAL
		Z_PARAM_LONG(permissions)
		Z_PARAM_BOOL(recursive)
		Z_PARAM_ZVAL_OR_NULL(context)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	if (ZEND_NUM_ARGS() > 1) {
		permissions_param = ZEND_CALL_ARG(execute_data, 2);
	}
	if (ZEND_NUM_ARGS() > 2) {
		recursive_param = ZEND_CALL_ARG(execute_data, 3);
	}
	if (ZEND_NUM_ARGS() > 3) {
		context = ZEND_CALL_ARG(execute_data, 4);
	}
	zephir_memory_observe(&directory_zv);
	ZVAL_STR_COPY(&directory_zv, directory);
	if (!context) {
		context = &context_sub;
		context = &__$null;
	}
	ZVAL_LONG(&_0, permissions);
	ZVAL_BOOL(&_1, (recursive ? 1 : 0));
	ZEPHIR_RETURN_CALL_FUNCTION("mkdir", NULL, 51, &directory_zv, &_0, &_1, context);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * @param string        $filename
 * @param resource|null $context
 *
 * @return bool
 *
 * @link https://php.net/manual/en/function.unlink.php
 */
PHP_METHOD(Phalcon_Image_Adapter_Imagick, phpUnlink)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval filename_zv, *context = NULL, context_sub, __$null;
	zend_string *filename = NULL;

	ZVAL_UNDEF(&filename_zv);
	ZVAL_UNDEF(&context_sub);
	ZVAL_NULL(&__$null);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_STR(filename)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(context)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	if (ZEND_NUM_ARGS() > 1) {
		context = ZEND_CALL_ARG(execute_data, 2);
	}
	zephir_memory_observe(&filename_zv);
	ZVAL_STR_COPY(&filename_zv, filename);
	if (!context) {
		context = &context_sub;
		context = &__$null;
	}
	ZEPHIR_RETURN_CALL_FUNCTION("unlink", NULL, 52, &filename_zv, context);
	zephir_check_call_status();
	RETURN_MM();
}

