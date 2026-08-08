
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
#include "kernel/operators.h"
#include "kernel/exception.h"
#include "kernel/concat.h"
#include "kernel/string.h"
#include "kernel/file.h"


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
	zend_bool _22$$7;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long width, height, ZEPHIR_LAST_CALL_STATUS;
	zval file_zv, *width_param = NULL, *height_param = NULL, image, _0, _1, _2, _31, _32, _33, _34, _35, _36, _37, _38, _39, _3$$3, _4$$3, _5$$3, _6$$3, _7$$3, _10$$3, _11$$3, _15$$3, _16$$3, _17$$3, _18$$3, _8$$4, _9$$4, _12$$5, _13$$5, _14$$5, _19$$6, _20$$6, _21$$6, _25$$7, _26$$7, _27$$7, _28$$7, _29$$7, _30$$7, _23$$8, _24$$8;
	zend_string *file = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&file_zv);
	ZVAL_UNDEF(&image);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_31);
	ZVAL_UNDEF(&_32);
	ZVAL_UNDEF(&_33);
	ZVAL_UNDEF(&_34);
	ZVAL_UNDEF(&_35);
	ZVAL_UNDEF(&_36);
	ZVAL_UNDEF(&_37);
	ZVAL_UNDEF(&_38);
	ZVAL_UNDEF(&_39);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_7$$3);
	ZVAL_UNDEF(&_10$$3);
	ZVAL_UNDEF(&_11$$3);
	ZVAL_UNDEF(&_15$$3);
	ZVAL_UNDEF(&_16$$3);
	ZVAL_UNDEF(&_17$$3);
	ZVAL_UNDEF(&_18$$3);
	ZVAL_UNDEF(&_8$$4);
	ZVAL_UNDEF(&_9$$4);
	ZVAL_UNDEF(&_12$$5);
	ZVAL_UNDEF(&_13$$5);
	ZVAL_UNDEF(&_14$$5);
	ZVAL_UNDEF(&_19$$6);
	ZVAL_UNDEF(&_20$$6);
	ZVAL_UNDEF(&_21$$6);
	ZVAL_UNDEF(&_25$$7);
	ZVAL_UNDEF(&_26$$7);
	ZVAL_UNDEF(&_27$$7);
	ZVAL_UNDEF(&_28$$7);
	ZVAL_UNDEF(&_29$$7);
	ZVAL_UNDEF(&_30$$7);
	ZVAL_UNDEF(&_23$$8);
	ZVAL_UNDEF(&_24$$8);
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	static zend_string *_zephir_prop_2 = NULL;
	static zend_string *_zephir_prop_3 = NULL;
	static zend_string *_zephir_prop_4 = NULL;
	static zend_string *_zephir_prop_5 = NULL;
	static zend_string *_zephir_prop_6 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("file", 4, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("image", 5, 1);
	}
	if (UNEXPECTED(!_zephir_prop_2)) {
		_zephir_prop_2 = zend_string_init("realpath", 8, 1);
	}
	if (UNEXPECTED(!_zephir_prop_3)) {
		_zephir_prop_3 = zend_string_init("type", 4, 1);
	}
	if (UNEXPECTED(!_zephir_prop_4)) {
		_zephir_prop_4 = zend_string_init("width", 5, 1);
	}
	if (UNEXPECTED(!_zephir_prop_5)) {
		_zephir_prop_5 = zend_string_init("height", 6, 1);
	}
	if (UNEXPECTED(!_zephir_prop_6)) {
		_zephir_prop_6 = zend_string_init("mime", 4, 1);
	}

	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 3)
		Z_PARAM_STR(file)
		Z_PARAM_OPTIONAL
		Z_PARAM_LONG_OR_NULL(width, is_null_true)
		Z_PARAM_LONG_OR_NULL(height, is_null_true)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	if (ZEND_NUM_ARGS() > 1) {
		width_param = ZEND_CALL_ARG(execute_data, 2);
	}
	if (ZEND_NUM_ARGS() > 2) {
		height_param = ZEND_CALL_ARG(execute_data, 3);
	}
	zephir_memory_observe(&file_zv);
	ZVAL_STR_COPY(&file_zv, file);
	if (!width_param) {
		width = 0;
	} else {
		}
	if (!height_param) {
		height = 0;
	} else {
		}
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "check", NULL, 0);
	zephir_check_call_status();
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 917, &file_zv);
	ZEPHIR_INIT_VAR(&_0);
	object_init_ex(&_0, zephir_get_internal_ce(SL("imagick")));
	ZEPHIR_CALL_METHOD(NULL, &_0, "__construct", NULL, 0);
	zephir_check_call_status();
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_1, 918, &_0);
	zephir_read_property_cached(&_2, this_ptr, _zephir_prop_0, 917, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "phpfileexists", NULL, 0, &_2);
	zephir_check_call_status();
	if (ZEPHIR_IS_TRUE_IDENTICAL(&_1)) {
		zephir_read_property_cached(&_3$$3, this_ptr, _zephir_prop_0, 917, PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_FUNCTION(&_4$$3, "realpath", NULL, 157, &_3$$3);
		zephir_check_call_status();
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_2, 919, &_4$$3);
		zephir_read_property_cached(&_5$$3, this_ptr, _zephir_prop_1, 918, PH_NOISY_CC | PH_READONLY);
		zephir_read_property_cached(&_7$$3, this_ptr, _zephir_prop_2, 919, PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(&_6$$3, &_5$$3, "readimage", NULL, 0, &_7$$3);
		zephir_check_call_status();
		if (!ZEPHIR_IS_TRUE_IDENTICAL(&_6$$3)) {
			ZEPHIR_INIT_VAR(&_8$$4);
			object_init_ex(&_8$$4, phalcon_image_exceptions_imageloadfailed_ce);
			zephir_read_property_cached(&_9$$4, this_ptr, _zephir_prop_0, 917, PH_NOISY_CC | PH_READONLY);
			ZEPHIR_CALL_METHOD(NULL, &_8$$4, "__construct", NULL, 0, &_9$$4);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_8$$4, "phalcon/Image/Adapter/Imagick.zep", 93);
			ZEPHIR_MM_RESTORE();
			return;
		}
		zephir_read_property_cached(&_10$$3, this_ptr, _zephir_prop_1, 918, PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(&_11$$3, &_10$$3, "getimagealphachannel", NULL, 0);
		zephir_check_call_status();
		if (!zephir_is_true(&_11$$3)) {
			zephir_read_property_cached(&_12$$5, this_ptr, _zephir_prop_1, 918, PH_NOISY_CC | PH_READONLY);
			ZEPHIR_INIT_VAR(&_13$$5);
			ZVAL_STRING(&_13$$5, "Imagick::ALPHACHANNEL_SET");
			ZEPHIR_CALL_FUNCTION(&_14$$5, "constant", NULL, 148, &_13$$5);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, &_12$$5, "setimagealphachannel", NULL, 0, &_14$$5);
			zephir_check_call_status();
		}
		zephir_read_property_cached(&_15$$3, this_ptr, _zephir_prop_1, 918, PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(&_16$$3, &_15$$3, "getimagetype", NULL, 0);
		zephir_check_call_status();
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_3, 920, &_16$$3);
		zephir_read_property_cached(&_17$$3, this_ptr, _zephir_prop_1, 918, PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(&_18$$3, &_17$$3, "getimagetype", NULL, 0);
		zephir_check_call_status();
		if (ZEPHIR_IS_LONG(&_18$$3, 1)) {
			zephir_read_property_cached(&_19$$6, this_ptr, _zephir_prop_1, 918, PH_NOISY_CC | PH_READONLY);
			ZEPHIR_CALL_METHOD(&image, &_19$$6, "coalesceimages", NULL, 0);
			zephir_check_call_status();
			zephir_read_property_cached(&_20$$6, this_ptr, _zephir_prop_1, 918, PH_NOISY_CC | PH_READONLY);
			ZEPHIR_CALL_METHOD(NULL, &_20$$6, "clear", NULL, 0);
			zephir_check_call_status();
			zephir_read_property_cached(&_21$$6, this_ptr, _zephir_prop_1, 918, PH_NOISY_CC | PH_READONLY);
			ZEPHIR_CALL_METHOD(NULL, &_21$$6, "destroy", NULL, 0);
			zephir_check_call_status();
			zephir_update_property_zval_cached(this_ptr, _zephir_prop_1, 918, &image);
		}
	} else {
		_22$$7 = 0 == width;
		if (!(_22$$7)) {
			_22$$7 = 0 == height;
		}
		if (_22$$7) {
			ZEPHIR_INIT_VAR(&_23$$8);
			object_init_ex(&_23$$8, phalcon_image_exceptions_imageloadfailed_ce);
			zephir_read_property_cached(&_24$$8, this_ptr, _zephir_prop_0, 917, PH_NOISY_CC | PH_READONLY);
			ZEPHIR_CALL_METHOD(NULL, &_23$$8, "__construct", NULL, 0, &_24$$8);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_23$$8, "phalcon/Image/Adapter/Imagick.zep", 116);
			ZEPHIR_MM_RESTORE();
			return;
		}
		zephir_read_property_cached(&_25$$7, this_ptr, _zephir_prop_1, 918, PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_VAR(&_26$$7);
		object_init_ex(&_26$$7, zephir_get_internal_ce(SL("imagickpixel")));
		ZEPHIR_INIT_VAR(&_27$$7);
		ZVAL_STRING(&_27$$7, "transparent");
		ZEPHIR_CALL_METHOD(NULL, &_26$$7, "__construct", NULL, 0, &_27$$7);
		zephir_check_call_status();
		ZVAL_LONG(&_28$$7, width);
		ZVAL_LONG(&_29$$7, height);
		ZEPHIR_CALL_METHOD(NULL, &_25$$7, "newimage", NULL, 0, &_28$$7, &_29$$7, &_26$$7);
		zephir_check_call_status();
		zephir_read_property_cached(&_28$$7, this_ptr, _zephir_prop_1, 918, PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_NVAR(&_27$$7);
		ZVAL_STRING(&_27$$7, "png");
		ZEPHIR_CALL_METHOD(NULL, &_28$$7, "setformat", NULL, 0, &_27$$7);
		zephir_check_call_status();
		zephir_read_property_cached(&_29$$7, this_ptr, _zephir_prop_1, 918, PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_NVAR(&_27$$7);
		ZVAL_STRING(&_27$$7, "png");
		ZEPHIR_CALL_METHOD(NULL, &_29$$7, "setimageformat", NULL, 0, &_27$$7);
		zephir_check_call_status();
		zephir_read_property_cached(&_30$$7, this_ptr, _zephir_prop_0, 917, PH_NOISY_CC | PH_READONLY);
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_2, 919, &_30$$7);
	}
	zephir_read_property_cached(&_31, this_ptr, _zephir_prop_1, 918, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_32, &_31, "getimagewidth", NULL, 0);
	zephir_check_call_status();
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_4, 921, &_32);
	zephir_read_property_cached(&_33, this_ptr, _zephir_prop_1, 918, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_34, &_33, "getimageheight", NULL, 0);
	zephir_check_call_status();
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_5, 922, &_34);
	zephir_read_property_cached(&_35, this_ptr, _zephir_prop_1, 918, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_36, &_35, "getimagetype", NULL, 0);
	zephir_check_call_status();
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_3, 920, &_36);
	zephir_read_property_cached(&_37, this_ptr, _zephir_prop_1, 918, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_38, &_37, "getimageformat", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_39);
	ZEPHIR_CONCAT_SV(&_39, "image/", &_38);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_6, 923, &_39);
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
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("image", 5, 1);
	}
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	zephir_memory_observe(&_0);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 918, PH_NOISY_CC);
	if (zephir_is_instance_of(&_0, SL("Imagick"))) {
		zephir_read_property_cached(&_1$$3, this_ptr, _zephir_prop_0, 918, PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(NULL, &_1$$3, "clear", NULL, 0);
		zephir_check_call_status();
		zephir_read_property_cached(&_2$$3, this_ptr, _zephir_prop_0, 918, PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(NULL, &_2$$3, "destroy", NULL, 0);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();
}

/**
 * Creates a blank transparent canvas of the given dimensions, without the
 * load-or-create ambiguity of the constructor.
 *
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
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(width)
		Z_PARAM_LONG(height)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 2, 0, &width_param, &height_param);
	object_init_ex(return_value, phalcon_image_adapter_imagick_ce);
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "");
	ZVAL_LONG(&_1, width);
	ZVAL_LONG(&_2, height);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 0, &_0, &_1, &_2);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * This method scales the images using liquid rescaling method. Only support
 * Imagick
 *
 * @throws Exception
 * @throws ImagickException
 */
PHP_METHOD(Phalcon_Image_Adapter_Imagick, liquidRescale)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_5 = NULL, *_7 = NULL, *_9 = NULL;
	zval *width_param = NULL, *height_param = NULL, *deltaX_param = NULL, *rigidity_param = NULL, image, result, _0, _10, _11, _1$$3, _2$$3, _3$$3, _4$$3, _8$$3, _6$$4;
	zend_long width, height, deltaX, rigidity, ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&image);
	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_11);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_8$$3);
	ZVAL_UNDEF(&_6$$4);
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
	if (!deltaX_param) {
		deltaX = 0;
	} else {
		}
	if (!rigidity_param) {
		rigidity = 0;
	} else {
		}
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 918, PH_NOISY_CC | PH_READONLY);
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
			ZEPHIR_INIT_NVAR(&_6$$4);
			object_init_ex(&_6$$4, phalcon_image_exceptions_resizefailed_ce);
			ZEPHIR_CALL_METHOD(NULL, &_6$$4, "__construct", &_7, 0);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_6$$4, "phalcon/Image/Adapter/Imagick.zep", 188);
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_CALL_METHOD(&_8$$3, &image, "nextimage", &_9, 0);
		zephir_check_call_status();
		if (ZEPHIR_IS_FALSE_IDENTICAL(&_8$$3)) {
			break;
		}
	}
	ZEPHIR_CALL_METHOD(&_10, &image, "getimagewidth", NULL, 0);
	zephir_check_call_status();
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_1, 921, &_10);
	ZEPHIR_CALL_METHOD(&_11, &image, "getimageheight", NULL, 0);
	zephir_check_call_status();
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_2, 922, &_11);
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
	zval *type_param = NULL, *limit_param = NULL, _1$$3, _2$$3, _3$$3, _4$$4;
	zend_long type, limit, ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$4);
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
	_0 = type >= 0;
	if (_0) {
		_0 = type <= 6;
	}
	if (_0) {
		zephir_read_property_cached(&_1$$3, this_ptr, _zephir_prop_0, 918, PH_NOISY_CC | PH_READONLY);
		ZVAL_LONG(&_2$$3, type);
		ZVAL_LONG(&_3$$3, limit);
		ZEPHIR_CALL_METHOD(NULL, &_1$$3, "setresourcelimit", NULL, 0, &_2$$3, &_3$$3);
		zephir_check_call_status();
	} else {
		ZEPHIR_INIT_VAR(&_4$$4);
		object_init_ex(&_4$$4, phalcon_image_exceptions_resourcetypeerror_ce);
		ZEPHIR_CALL_METHOD(NULL, &_4$$4, "__construct", NULL, 0);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_4$$4, "phalcon/Image/Adapter/Imagick.zep", 222);
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
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_6 = NULL, *_8 = NULL, *_11 = NULL, *_12 = NULL, *_15 = NULL, *_20 = NULL, *_22 = NULL, *_27 = NULL, *_29 = NULL;
	zval *red_param = NULL, *green_param = NULL, *blue_param = NULL, *opacity_param = NULL, background, color, pixel1, pixel2, result, _0, _1, _2, _3, _4$$3, _5$$3, _13$$3, _14$$3, _16$$3, _17$$3, _18$$3, _19$$3, _21$$3, _23$$3, _24$$3, _25$$3, _26$$3, _30$$3, _7$$4, _9$$5, _10$$5, _28$$7;
	zend_long red, green, blue, opacity, ZEPHIR_LAST_CALL_STATUS, localOpacity = 0;
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
	ZVAL_UNDEF(&_13$$3);
	ZVAL_UNDEF(&_14$$3);
	ZVAL_UNDEF(&_16$$3);
	ZVAL_UNDEF(&_17$$3);
	ZVAL_UNDEF(&_18$$3);
	ZVAL_UNDEF(&_19$$3);
	ZVAL_UNDEF(&_21$$3);
	ZVAL_UNDEF(&_23$$3);
	ZVAL_UNDEF(&_24$$3);
	ZVAL_UNDEF(&_25$$3);
	ZVAL_UNDEF(&_26$$3);
	ZVAL_UNDEF(&_30$$3);
	ZVAL_UNDEF(&_7$$4);
	ZVAL_UNDEF(&_9$$5);
	ZVAL_UNDEF(&_10$$5);
	ZVAL_UNDEF(&_28$$7);
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
	localOpacity = opacity;
	localOpacity /= 100;
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "rgb(%d, %d, %d)");
	ZVAL_LONG(&_1, red);
	ZVAL_LONG(&_2, green);
	ZVAL_LONG(&_3, blue);
	ZEPHIR_CALL_FUNCTION(&color, "sprintf", NULL, 145, &_0, &_1, &_2, &_3);
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
	zephir_read_property_cached(&_1, this_ptr, _zephir_prop_0, 918, PH_NOISY_CC | PH_READONLY);
	ZVAL_LONG(&_2, 0);
	ZEPHIR_CALL_METHOD(NULL, &_1, "setiteratorindex", NULL, 0, &_2);
	zephir_check_call_status();
	while (1) {
		if (!(1)) {
			break;
		}
		zephir_read_property_cached(&_4$$3, this_ptr, _zephir_prop_1, 921, PH_NOISY_CC | PH_READONLY);
		zephir_read_property_cached(&_5$$3, this_ptr, _zephir_prop_2, 922, PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(NULL, &background, "newimage", &_6, 0, &_4$$3, &_5$$3, &pixel1);
		zephir_check_call_status();

		/* try_start_1: */

			ZEPHIR_CALL_METHOD(&_7$$4, &background, "getimagealphachannel", &_8, 0);
			zephir_check_call_status_or_jump(try_end_1);
			if (!ZEPHIR_IS_TRUE_IDENTICAL(&_7$$4)) {
				ZEPHIR_INIT_NVAR(&_9$$5);
				ZVAL_STRING(&_9$$5, "Imagick::ALPHACHANNEL_SET");
				ZEPHIR_CALL_FUNCTION(&_10$$5, "constant", &_11, 148, &_9$$5);
				zephir_check_call_status_or_jump(try_end_1);
				ZEPHIR_CALL_METHOD(NULL, &background, "setimagealphachannel", &_12, 0, &_10$$5);
				zephir_check_call_status_or_jump(try_end_1);
			}

		try_end_1:

		if (EG(exception)) {
			ZEPHIR_INIT_NVAR(&_13$$3);
			ZVAL_OBJ(&_13$$3, EG(exception));
			Z_ADDREF_P(&_13$$3);
			ZEPHIR_INIT_NVAR(&_14$$3);
			if (zephir_is_instance_of(&_13$$3, SL("ImagickException"))) {
				zend_clear_exception();
				ZEPHIR_CPY_WRT(&_14$$3, &_13$$3);
				ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_image_exception_ce, "Imagick::getImageAlphaChannel failed", "phalcon/Image/Adapter/Imagick.zep", 260);
				return;
			}
		}
		ZEPHIR_CALL_METHOD(NULL, &background, "setimagebackgroundcolor", &_15, 0, &pixel2);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&_16$$3);
		ZVAL_STRING(&_16$$3, "Imagick::EVALUATE_MULTIPLY");
		ZEPHIR_CALL_FUNCTION(&_17$$3, "constant", &_11, 148, &_16$$3);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&_16$$3);
		ZVAL_STRING(&_16$$3, "Imagick::CHANNEL_ALPHA");
		ZEPHIR_CALL_FUNCTION(&_18$$3, "constant", &_11, 148, &_16$$3);
		zephir_check_call_status();
		ZVAL_LONG(&_19$$3, localOpacity);
		ZEPHIR_CALL_METHOD(NULL, &background, "evaluateimage", &_20, 0, &_17$$3, &_19$$3, &_18$$3);
		zephir_check_call_status();
		zephir_read_property_cached(&_19$$3, this_ptr, _zephir_prop_0, 918, PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(&_21$$3, &_19$$3, "getcolorspace", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &background, "setcolorspace", &_22, 0, &_21$$3);
		zephir_check_call_status();
		zephir_read_property_cached(&_23$$3, this_ptr, _zephir_prop_0, 918, PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_NVAR(&_16$$3);
		ZVAL_STRING(&_16$$3, "Imagick::COMPOSITE_DISSOLVE");
		ZEPHIR_CALL_FUNCTION(&_24$$3, "constant", &_11, 148, &_16$$3);
		zephir_check_call_status();
		ZVAL_LONG(&_25$$3, 0);
		ZVAL_LONG(&_26$$3, 0);
		ZEPHIR_CALL_METHOD(&result, &background, "compositeimage", &_27, 0, &_23$$3, &_24$$3, &_25$$3, &_26$$3);
		zephir_check_call_status();
		if (!ZEPHIR_IS_TRUE_IDENTICAL(&result)) {
			ZEPHIR_INIT_NVAR(&_28$$7);
			object_init_ex(&_28$$7, phalcon_image_exceptions_compositefailed_ce);
			ZEPHIR_CALL_METHOD(NULL, &_28$$7, "__construct", &_29, 0);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_28$$7, "phalcon/Image/Adapter/Imagick.zep", 283);
			ZEPHIR_MM_RESTORE();
			return;
		}
		zephir_read_property_cached(&_25$$3, this_ptr, _zephir_prop_0, 918, PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(&_30$$3, &_25$$3, "nextimage", NULL, 0);
		zephir_check_call_status();
		if (!ZEPHIR_IS_TRUE_IDENTICAL(&_30$$3)) {
			break;
		}
	}
	zephir_read_property_cached(&_2, this_ptr, _zephir_prop_0, 918, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, &_2, "clear", NULL, 0);
	zephir_check_call_status();
	zephir_read_property_cached(&_3, this_ptr, _zephir_prop_0, 918, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, &_3, "destroy", NULL, 0);
	zephir_check_call_status();
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 918, &background);
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
	zval *radius_param = NULL, _0, _1, _2$$3, _3$$3, _4$$3, _5$$3;
	zend_long radius, ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$3);
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
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 918, PH_NOISY_CC | PH_READONLY);
	ZVAL_LONG(&_1, 0);
	ZEPHIR_CALL_METHOD(NULL, &_0, "setiteratorindex", NULL, 0, &_1);
	zephir_check_call_status();
	while (1) {
		if (!(1)) {
			break;
		}
		zephir_read_property_cached(&_2$$3, this_ptr, _zephir_prop_0, 918, PH_NOISY_CC | PH_READONLY);
		ZVAL_LONG(&_3$$3, radius);
		ZVAL_LONG(&_4$$3, 100);
		ZEPHIR_CALL_METHOD(NULL, &_2$$3, "blurimage", NULL, 0, &_3$$3, &_4$$3);
		zephir_check_call_status();
		zephir_read_property_cached(&_3$$3, this_ptr, _zephir_prop_0, 918, PH_NOISY_CC | PH_READONLY);
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
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 918, PH_NOISY_CC | PH_READONLY);
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
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_1, 921, &_9);
	ZEPHIR_CALL_METHOD(&_10, &image, "getimageheight", NULL, 0);
	zephir_check_call_status();
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_2, 922, &_10);
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
	zval *direction_param = NULL, method, _0, _1, _2$$3, _3$$3, _4$$3;
	zend_long direction, ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&method);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
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
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 918, PH_NOISY_CC | PH_READONLY);
	ZVAL_LONG(&_1, 0);
	ZEPHIR_CALL_METHOD(NULL, &_0, "setiteratorindex", NULL, 0, &_1);
	zephir_check_call_status();
	while (1) {
		if (!(1)) {
			break;
		}
		zephir_read_property_cached(&_2$$3, this_ptr, _zephir_prop_0, 918, PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD_ZVAL(NULL, &_2$$3, &method, NULL, 0);
		zephir_check_call_status();
		zephir_read_property_cached(&_3$$3, this_ptr, _zephir_prop_0, 918, PH_NOISY_CC | PH_READONLY);
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
 * @throws Exception
 * @throws ImagickException
 */
PHP_METHOD(Phalcon_Image_Adapter_Imagick, processMask)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_7 = NULL, *_11 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *mask, mask_sub, image, result, _0, _1, _2, _3$$3, _4$$3, _5$$3, _6$$3, _8$$3, _9$$3, _12$$3, _10$$4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&mask_sub);
	ZVAL_UNDEF(&image);
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
	ZVAL_UNDEF(&_12$$3);
	ZVAL_UNDEF(&_10$$4);
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
	ZEPHIR_INIT_VAR(&image);
	object_init_ex(&image, zephir_get_internal_ce(SL("imagick")));
	ZEPHIR_CALL_METHOD(NULL, &image, "__construct", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_0, mask, "render", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &image, "readimageblob", NULL, 0, &_0);
	zephir_check_call_status();
	zephir_read_property_cached(&_1, this_ptr, _zephir_prop_0, 918, PH_NOISY_CC | PH_READONLY);
	ZVAL_LONG(&_2, 0);
	ZEPHIR_CALL_METHOD(NULL, &_1, "setiteratorindex", NULL, 0, &_2);
	zephir_check_call_status();
	while (1) {
		if (!(1)) {
			break;
		}
		zephir_read_property_cached(&_3$$3, this_ptr, _zephir_prop_0, 918, PH_NOISY_CC | PH_READONLY);
		ZVAL_BOOL(&_4$$3, 1);
		ZEPHIR_CALL_METHOD(NULL, &_3$$3, "setimagematte", NULL, 0, &_4$$3);
		zephir_check_call_status();
		zephir_read_property_cached(&_4$$3, this_ptr, _zephir_prop_0, 918, PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_NVAR(&_5$$3);
		ZVAL_STRING(&_5$$3, "Imagick::COMPOSITE_DSTIN");
		ZEPHIR_CALL_FUNCTION(&_6$$3, "constant", &_7, 148, &_5$$3);
		zephir_check_call_status();
		ZVAL_LONG(&_8$$3, 0);
		ZVAL_LONG(&_9$$3, 0);
		ZEPHIR_CALL_METHOD(&result, &_4$$3, "compositeimage", NULL, 0, &image, &_6$$3, &_8$$3, &_9$$3);
		zephir_check_call_status();
		if (!ZEPHIR_IS_TRUE_IDENTICAL(&result)) {
			ZEPHIR_INIT_NVAR(&_10$$4);
			object_init_ex(&_10$$4, phalcon_image_exceptions_compositefailed_ce);
			ZEPHIR_CALL_METHOD(NULL, &_10$$4, "__construct", &_11, 0);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_10$$4, "phalcon/Image/Adapter/Imagick.zep", 393);
			ZEPHIR_MM_RESTORE();
			return;
		}
		zephir_read_property_cached(&_8$$3, this_ptr, _zephir_prop_0, 918, PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(&_12$$3, &_8$$3, "nextimage", NULL, 0);
		zephir_check_call_status();
		if (!ZEPHIR_IS_TRUE_IDENTICAL(&_12$$3)) {
			break;
		}
	}
	ZEPHIR_CALL_METHOD(NULL, &image, "clear", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &image, "destroy", NULL, 0);
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
	zval *amount_param = NULL, _0, _1, _2, _3, _4$$3, _5$$3, _6$$3, _7$$3, _8$$3, _9$$3;
	zend_long amount, ZEPHIR_LAST_CALL_STATUS, height = 0, width = 0;
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
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 921, PH_NOISY_CC | PH_READONLY);
	width = (int) (zephir_safe_div_zval_long(&_0, amount));
	zephir_read_property_cached(&_1, this_ptr, _zephir_prop_1, 922, PH_NOISY_CC | PH_READONLY);
	height = (int) (zephir_safe_div_zval_long(&_1, amount));
	zephir_read_property_cached(&_2, this_ptr, _zephir_prop_2, 918, PH_NOISY_CC | PH_READONLY);
	ZVAL_LONG(&_3, 0);
	ZEPHIR_CALL_METHOD(NULL, &_2, "setiteratorindex", NULL, 0, &_3);
	zephir_check_call_status();
	while (1) {
		if (!(1)) {
			break;
		}
		zephir_read_property_cached(&_4$$3, this_ptr, _zephir_prop_2, 918, PH_NOISY_CC | PH_READONLY);
		ZVAL_LONG(&_5$$3, width);
		ZVAL_LONG(&_6$$3, height);
		ZEPHIR_CALL_METHOD(NULL, &_4$$3, "scaleimage", NULL, 0, &_5$$3, &_6$$3);
		zephir_check_call_status();
		zephir_read_property_cached(&_5$$3, this_ptr, _zephir_prop_2, 918, PH_NOISY_CC | PH_READONLY);
		zephir_read_property_cached(&_6$$3, this_ptr, _zephir_prop_0, 921, PH_NOISY_CC | PH_READONLY);
		zephir_read_property_cached(&_7$$3, this_ptr, _zephir_prop_1, 922, PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(NULL, &_5$$3, "scaleimage", NULL, 0, &_6$$3, &_7$$3);
		zephir_check_call_status();
		zephir_read_property_cached(&_8$$3, this_ptr, _zephir_prop_2, 918, PH_NOISY_CC | PH_READONLY);
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
 * @throws Exception
 * @throws ImagickException
 */
PHP_METHOD(Phalcon_Image_Adapter_Imagick, processReflection)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_5 = NULL, *_7 = NULL, *_11 = NULL, *_13 = NULL, *_14 = NULL, *_20 = NULL, *_23 = NULL, *_25 = NULL, *_28 = NULL, *_35 = NULL, *_38 = NULL, *_40 = NULL, *_43 = NULL, *_48 = NULL, *_57 = NULL;
	zend_bool fadeIn, _58$$13;
	zval *height_param = NULL, *opacity_param = NULL, *fadeIn_param = NULL, fade, image, pixel, pseudo, reflection, result, _0, _4, _16, _17, _30, _31, _32, _60, _61, _62, _63, _64, _1$$3, _2$$4, _3$$4, _6$$5, _8$$5, _9$$5, _10$$5, _12$$5, _15$$5, _18$$7, _19$$7, _21$$7, _22$$7, _26$$7, _27$$7, _29$$7, _24$$8, _33$$10, _34$$10, _36$$10, _37$$10, _39$$10, _41$$10, _42$$10, _44$$10, _45$$10, _46$$10, _47$$10, _50$$10, _49$$11, _51$$13, _52$$13, _53$$13, _54$$13, _56$$13, _59$$13, _55$$14;
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
	ZVAL_UNDEF(&_30);
	ZVAL_UNDEF(&_31);
	ZVAL_UNDEF(&_32);
	ZVAL_UNDEF(&_60);
	ZVAL_UNDEF(&_61);
	ZVAL_UNDEF(&_62);
	ZVAL_UNDEF(&_63);
	ZVAL_UNDEF(&_64);
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
	ZVAL_UNDEF(&_26$$7);
	ZVAL_UNDEF(&_27$$7);
	ZVAL_UNDEF(&_29$$7);
	ZVAL_UNDEF(&_24$$8);
	ZVAL_UNDEF(&_33$$10);
	ZVAL_UNDEF(&_34$$10);
	ZVAL_UNDEF(&_36$$10);
	ZVAL_UNDEF(&_37$$10);
	ZVAL_UNDEF(&_39$$10);
	ZVAL_UNDEF(&_41$$10);
	ZVAL_UNDEF(&_42$$10);
	ZVAL_UNDEF(&_44$$10);
	ZVAL_UNDEF(&_45$$10);
	ZVAL_UNDEF(&_46$$10);
	ZVAL_UNDEF(&_47$$10);
	ZVAL_UNDEF(&_50$$10);
	ZVAL_UNDEF(&_49$$11);
	ZVAL_UNDEF(&_51$$13);
	ZVAL_UNDEF(&_52$$13);
	ZVAL_UNDEF(&_53$$13);
	ZVAL_UNDEF(&_54$$13);
	ZVAL_UNDEF(&_56$$13);
	ZVAL_UNDEF(&_59$$13);
	ZVAL_UNDEF(&_55$$14);
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	static zend_string *_zephir_prop_2 = NULL;
	static zend_string *_zephir_prop_3 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("version", 7, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("image", 5, 1);
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
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 924, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&reflection);
	if (ZEPHIR_GE_LONG(&_0, 30100)) {
		zephir_read_property_cached(&_1$$3, this_ptr, _zephir_prop_1, 918, PH_NOISY_CC | PH_READONLY);
		if (zephir_clone(&reflection, &_1$$3) == FAILURE) {
			RETURN_MM();
		}
	} else {
		zephir_read_property_cached(&_2$$4, this_ptr, _zephir_prop_1, 918, PH_NOISY_CC | PH_READONLY);
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
		zephir_read_property_cached(&_8$$5, this_ptr, _zephir_prop_1, 918, PH_NOISY_CC | PH_READONLY);
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
		ZEPHIR_CALL_FUNCTION(&_19$$7, "constant", &_20, 148, &_18$$7);
		zephir_check_call_status();
		ZVAL_LONG(&_21$$7, 0);
		ZVAL_LONG(&_22$$7, 0);
		ZEPHIR_CALL_METHOD(&result, &reflection, "compositeimage", &_23, 0, &fade, &_19$$7, &_21$$7, &_22$$7);
		zephir_check_call_status();
		if (!ZEPHIR_IS_TRUE_IDENTICAL(&result)) {
			ZEPHIR_INIT_NVAR(&_24$$8);
			object_init_ex(&_24$$8, phalcon_image_exceptions_compositefailed_ce);
			ZEPHIR_CALL_METHOD(NULL, &_24$$8, "__construct", &_25, 0);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_24$$8, "phalcon/Image/Adapter/Imagick.zep", 492);
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_INIT_NVAR(&_18$$7);
		ZVAL_STRING(&_18$$7, "Imagick::EVALUATE_MULTIPLY");
		ZEPHIR_CALL_FUNCTION(&_26$$7, "constant", &_20, 148, &_18$$7);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&_18$$7);
		ZVAL_STRING(&_18$$7, "Imagick::CHANNEL_ALPHA");
		ZEPHIR_CALL_FUNCTION(&_27$$7, "constant", &_20, 148, &_18$$7);
		zephir_check_call_status();
		ZVAL_LONG(&_21$$7, opacity);
		ZEPHIR_CALL_METHOD(NULL, &reflection, "evaluateimage", &_28, 0, &_26$$7, &_21$$7, &_27$$7);
		zephir_check_call_status();
		zephir_read_property_cached(&_21$$7, this_ptr, _zephir_prop_1, 918, PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(&_29$$7, &_21$$7, "nextimage", NULL, 0);
		zephir_check_call_status();
		if (!ZEPHIR_IS_TRUE_IDENTICAL(&_29$$7)) {
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
	zephir_read_property_cached(&_4, this_ptr, _zephir_prop_1, 918, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_30, &_4, "getimageheight", NULL, 0);
	zephir_check_call_status();
	height = (zephir_get_numberval(&_30) + height);
	zephir_read_property_cached(&_31, this_ptr, _zephir_prop_1, 918, PH_NOISY_CC | PH_READONLY);
	ZVAL_LONG(&_32, 0);
	ZEPHIR_CALL_METHOD(NULL, &_31, "setiteratorindex", NULL, 0, &_32);
	zephir_check_call_status();
	while (1) {
		if (!(1)) {
			break;
		}
		zephir_read_property_cached(&_33$$10, this_ptr, _zephir_prop_2, 921, PH_NOISY_CC | PH_READONLY);
		ZVAL_LONG(&_34$$10, height);
		ZEPHIR_CALL_METHOD(NULL, &image, "newimage", &_35, 0, &_33$$10, &_34$$10, &pixel);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&_36$$10);
		ZVAL_STRING(&_36$$10, "Imagick::ALPHACHANNEL_SET");
		ZEPHIR_CALL_FUNCTION(&_37$$10, "constant", &_20, 148, &_36$$10);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &image, "setimagealphachannel", &_38, 0, &_37$$10);
		zephir_check_call_status();
		zephir_read_property_cached(&_34$$10, this_ptr, _zephir_prop_1, 918, PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(&_39$$10, &_34$$10, "getcolorspace", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &image, "setcolorspace", &_40, 0, &_39$$10);
		zephir_check_call_status();
		zephir_read_property_cached(&_41$$10, this_ptr, _zephir_prop_1, 918, PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(&_42$$10, &_41$$10, "getimagedelay", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &image, "setimagedelay", &_43, 0, &_42$$10);
		zephir_check_call_status();
		zephir_read_property_cached(&_44$$10, this_ptr, _zephir_prop_1, 918, PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_NVAR(&_36$$10);
		ZVAL_STRING(&_36$$10, "Imagick::COMPOSITE_SRC");
		ZEPHIR_CALL_FUNCTION(&_45$$10, "constant", &_20, 148, &_36$$10);
		zephir_check_call_status();
		ZVAL_LONG(&_46$$10, 0);
		ZVAL_LONG(&_47$$10, 0);
		ZEPHIR_CALL_METHOD(&result, &image, "compositeimage", &_48, 0, &_44$$10, &_45$$10, &_46$$10, &_47$$10);
		zephir_check_call_status();
		if (!ZEPHIR_IS_TRUE_IDENTICAL(&result)) {
			ZEPHIR_INIT_NVAR(&_49$$11);
			object_init_ex(&_49$$11, phalcon_image_exceptions_compositefailed_ce);
			ZEPHIR_CALL_METHOD(NULL, &_49$$11, "__construct", &_25, 0);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_49$$11, "phalcon/Image/Adapter/Imagick.zep", 531);
			ZEPHIR_MM_RESTORE();
			return;
		}
		zephir_read_property_cached(&_46$$10, this_ptr, _zephir_prop_1, 918, PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(&_50$$10, &_46$$10, "nextimage", NULL, 0);
		zephir_check_call_status();
		if (!ZEPHIR_IS_TRUE_IDENTICAL(&_50$$10)) {
			break;
		}
	}
	ZVAL_LONG(&_32, 0);
	ZEPHIR_CALL_METHOD(NULL, &image, "setiteratorindex", NULL, 0, &_32);
	zephir_check_call_status();
	ZVAL_LONG(&_32, 0);
	ZEPHIR_CALL_METHOD(NULL, &reflection, "setiteratorindex", NULL, 0, &_32);
	zephir_check_call_status();
	while (1) {
		if (!(1)) {
			break;
		}
		ZEPHIR_INIT_NVAR(&_51$$13);
		ZVAL_STRING(&_51$$13, "Imagick::COMPOSITE_OVER");
		ZEPHIR_CALL_FUNCTION(&_52$$13, "constant", &_20, 148, &_51$$13);
		zephir_check_call_status();
		zephir_read_property_cached(&_53$$13, this_ptr, _zephir_prop_3, 922, PH_NOISY_CC | PH_READONLY);
		ZVAL_LONG(&_54$$13, 0);
		ZEPHIR_CALL_METHOD(&result, &image, "compositeimage", &_48, 0, &reflection, &_52$$13, &_54$$13, &_53$$13);
		zephir_check_call_status();
		if (!ZEPHIR_IS_TRUE_IDENTICAL(&result)) {
			ZEPHIR_INIT_NVAR(&_55$$14);
			object_init_ex(&_55$$14, phalcon_image_exceptions_compositefailed_ce);
			ZEPHIR_CALL_METHOD(NULL, &_55$$14, "__construct", &_25, 0);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_55$$14, "phalcon/Image/Adapter/Imagick.zep", 551);
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_CALL_METHOD(&_56$$13, &image, "nextimage", &_57, 0);
		zephir_check_call_status();
		_58$$13 = !ZEPHIR_IS_TRUE_IDENTICAL(&_56$$13);
		if (!(_58$$13)) {
			ZEPHIR_CALL_METHOD(&_59$$13, &reflection, "nextimage", NULL, 0);
			zephir_check_call_status();
			_58$$13 = !ZEPHIR_IS_TRUE_IDENTICAL(&_59$$13);
		}
		if (_58$$13) {
			break;
		}
	}
	ZEPHIR_CALL_METHOD(NULL, &reflection, "destroy", NULL, 0);
	zephir_check_call_status();
	zephir_read_property_cached(&_32, this_ptr, _zephir_prop_1, 918, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, &_32, "clear", NULL, 0);
	zephir_check_call_status();
	zephir_read_property_cached(&_60, this_ptr, _zephir_prop_1, 918, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, &_60, "destroy", NULL, 0);
	zephir_check_call_status();
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_1, 918, &image);
	zephir_read_property_cached(&_61, this_ptr, _zephir_prop_1, 918, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_62, &_61, "getimagewidth", NULL, 0);
	zephir_check_call_status();
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_2, 921, &_62);
	zephir_read_property_cached(&_63, this_ptr, _zephir_prop_1, 918, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_64, &_63, "getimageheight", NULL, 0);
	zephir_check_call_status();
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_3, 922, &_64);
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
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 918, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&image, &_0);
	ZEPHIR_CALL_METHOD(NULL, &image, "setformat", NULL, 0, &extension);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &image, "setimageformat", NULL, 0, &extension);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &image, "stripimage", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_1, &image, "getimagetype", NULL, 0);
	zephir_check_call_status();
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_1, 920, &_1);
	ZEPHIR_CALL_METHOD(&_2, &image, "getimageformat", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_3);
	ZEPHIR_CONCAT_SV(&_3, "image/", &_2);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_2, 923, &_3);
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
			ZEPHIR_CALL_FUNCTION(&_6$$4, "constant", NULL, 148, &_5$$4);
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
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 918, PH_NOISY_CC | PH_READONLY);
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
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_1, 921, &_6);
	ZEPHIR_CALL_METHOD(&_7, &image, "getimageheight", NULL, 0);
	zephir_check_call_status();
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_2, 922, &_7);
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
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 918, PH_NOISY_CC | PH_READONLY);
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
		zephir_read_property_cached(&_2$$3, this_ptr, _zephir_prop_0, 918, PH_NOISY_CC | PH_READONLY);
		ZVAL_LONG(&_3$$3, degrees);
		ZEPHIR_CALL_METHOD(NULL, &_2$$3, "rotateimage", NULL, 0, &pixel, &_3$$3);
		zephir_check_call_status();
		zephir_read_property_cached(&_3$$3, this_ptr, _zephir_prop_0, 918, PH_NOISY_CC | PH_READONLY);
		zephir_read_property_cached(&_4$$3, this_ptr, _zephir_prop_1, 921, PH_NOISY_CC | PH_READONLY);
		zephir_read_property_cached(&_5$$3, this_ptr, _zephir_prop_2, 922, PH_NOISY_CC | PH_READONLY);
		ZVAL_LONG(&_6$$3, 0);
		ZVAL_LONG(&_7$$3, 0);
		ZEPHIR_CALL_METHOD(NULL, &_3$$3, "setimagepage", NULL, 0, &_4$$3, &_5$$3, &_6$$3, &_7$$3);
		zephir_check_call_status();
		zephir_read_property_cached(&_6$$3, this_ptr, _zephir_prop_0, 918, PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(&_8$$3, &_6$$3, "nextimage", NULL, 0);
		zephir_check_call_status();
		if (!ZEPHIR_IS_TRUE_IDENTICAL(&_8$$3)) {
			break;
		}
	}
	zephir_read_property_cached(&_1, this_ptr, _zephir_prop_0, 918, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_9, &_1, "getimagewidth", NULL, 0);
	zephir_check_call_status();
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_1, 921, &_9);
	zephir_read_property_cached(&_10, this_ptr, _zephir_prop_0, 918, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_11, &_10, "getimageheight", NULL, 0);
	zephir_check_call_status();
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_2, 922, &_11);
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
	zval file_zv, *quality_param = NULL, extension, fp, _0, _1, _2, _3, _4, _5, _6, _7, _17, _8$$3, _9$$3, _10$$3, _11$$4, _12$$4, _13$$4, _14$$5, _15$$5, _16$$5;
	zend_string *file = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&file_zv);
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
	ZVAL_LONG(&_0, 4);
	ZEPHIR_CALL_FUNCTION(&extension, "pathinfo", NULL, 199, &file_zv, &_0);
	zephir_check_call_status();
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 918, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, &_0, "setformat", NULL, 0, &extension);
	zephir_check_call_status();
	zephir_read_property_cached(&_1, this_ptr, _zephir_prop_0, 918, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, &_1, "setimageformat", NULL, 0, &extension);
	zephir_check_call_status();
	zephir_read_property_cached(&_2, this_ptr, _zephir_prop_0, 918, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_3, &_2, "getimagetype", NULL, 0);
	zephir_check_call_status();
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_1, 920, &_3);
	zephir_read_property_cached(&_4, this_ptr, _zephir_prop_0, 918, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_5, &_4, "getimageformat", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_6);
	ZEPHIR_CONCAT_SV(&_6, "image/", &_5);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_2, 923, &_6);
	ZEPHIR_INIT_VAR(&_7);
	zephir_fast_strtolower(&_7, &extension);
	ZEPHIR_CPY_WRT(&extension, &_7);
	do {
		if (ZEPHIR_IS_STRING(&extension, "gif")) {
			zephir_read_property_cached(&_8$$3, this_ptr, _zephir_prop_0, 918, PH_NOISY_CC | PH_READONLY);
			ZEPHIR_CALL_METHOD(NULL, &_8$$3, "optimizeimagelayers", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(&_9$$3);
			ZVAL_STRING(&_9$$3, "w");
			ZEPHIR_CALL_METHOD(&fp, this_ptr, "phpfopen", NULL, 0, &file_zv, &_9$$3);
			zephir_check_call_status();
			zephir_read_property_cached(&_10$$3, this_ptr, _zephir_prop_0, 918, PH_NOISY_CC | PH_READONLY);
			ZEPHIR_CALL_METHOD(NULL, &_10$$3, "writeimagesfile", NULL, 0, &fp);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "phpfclose", NULL, 0, &fp);
			zephir_check_call_status();
			RETURN_MM_NULL();
		}
		if (ZEPHIR_IS_STRING(&extension, "jpg") || ZEPHIR_IS_STRING(&extension, "jpeg")) {
			zephir_read_property_cached(&_11$$4, this_ptr, _zephir_prop_0, 918, PH_NOISY_CC | PH_READONLY);
			ZEPHIR_INIT_VAR(&_12$$4);
			ZVAL_STRING(&_12$$4, "Imagick::COMPRESSION_JPEG");
			ZEPHIR_CALL_FUNCTION(&_13$$4, "constant", NULL, 148, &_12$$4);
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
		zephir_read_property_cached(&_15$$5, this_ptr, _zephir_prop_0, 918, PH_NOISY_CC | PH_READONLY);
		ZVAL_LONG(&_16$$5, quality);
		ZEPHIR_CALL_METHOD(NULL, &_15$$5, "setimagecompressionquality", NULL, 0, &_16$$5);
		zephir_check_call_status();
	}
	zephir_read_property_cached(&_17, this_ptr, _zephir_prop_0, 918, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, &_17, "writeimage", NULL, 0, &file_zv);
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
	amount = zephir_get_numberval(&_0);
	amount = (long) (zephir_safe_div_long_long(((amount * 3.0)), 100));
	zephir_read_property_cached(&_1, this_ptr, _zephir_prop_0, 918, PH_NOISY_CC | PH_READONLY);
	ZVAL_LONG(&_2, 0);
	ZEPHIR_CALL_METHOD(NULL, &_1, "setiteratorindex", NULL, 0, &_2);
	zephir_check_call_status();
	while (1) {
		if (!(1)) {
			break;
		}
		zephir_read_property_cached(&_3$$3, this_ptr, _zephir_prop_0, 918, PH_NOISY_CC | PH_READONLY);
		ZVAL_LONG(&_4$$3, 0);
		ZVAL_LONG(&_5$$3, amount);
		ZEPHIR_CALL_METHOD(NULL, &_3$$3, "sharpenimage", NULL, 0, &_4$$3, &_5$$3);
		zephir_check_call_status();
		zephir_read_property_cached(&_4$$3, this_ptr, _zephir_prop_0, 918, PH_NOISY_CC | PH_READONLY);
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
 * @throws ImagickDrawException
 * @throws ImagickException
 * @throws ImagickPixelException
 */
PHP_METHOD(Phalcon_Image_Adapter_Imagick, processText)
{
	zend_bool _7$$8, _9$$8, _10$$8, _11$$8, _12$$11, _14$$11, _15$$11, _16$$11;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long opacity, red, green, blue, size, ZEPHIR_LAST_CALL_STATUS;
	zval text_zv, *offsetX = NULL, offsetX_sub, *offsetY = NULL, offsetY_sub, *opacity_param = NULL, *red_param = NULL, *green_param = NULL, *blue_param = NULL, *size_param = NULL, fontFile_zv, color, draw, gravity, x, y, _0, _1, _2, _3, _4$$4, _5$$5, _6$$7, _8$$8, _13$$11, _17$$12, _18$$14, _19$$14, _20$$14;
	zend_string *text = NULL, *fontFile = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&text_zv);
	ZVAL_UNDEF(&offsetX_sub);
	ZVAL_UNDEF(&offsetY_sub);
	ZVAL_UNDEF(&fontFile_zv);
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
	ZEPHIR_CALL_FUNCTION(&color, "sprintf", NULL, 145, &_0, &_1, &_2, &_3);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_0);
	object_init_ex(&_0, zephir_get_internal_ce(SL("imagickpixel")));
	ZEPHIR_CALL_METHOD(NULL, &_0, "__construct", NULL, 0, &color);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &draw, "setfillcolor", NULL, 0, &_0);
	zephir_check_call_status();
	if (Z_TYPE_P(&fontFile_zv) != IS_NULL) {
		ZEPHIR_CALL_METHOD(NULL, &draw, "setfont", NULL, 0, &fontFile_zv);
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
			ZEPHIR_CALL_FUNCTION(&gravity, "constant", NULL, 148, &_6$$7);
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
				ZEPHIR_CALL_FUNCTION(&gravity, "constant", NULL, 148, &_8$$8);
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
				ZEPHIR_CALL_FUNCTION(&gravity, "constant", NULL, 148, &_8$$8);
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
				ZEPHIR_CALL_FUNCTION(&gravity, "constant", NULL, 148, &_8$$8);
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
				ZEPHIR_CALL_FUNCTION(&gravity, "constant", NULL, 148, &_8$$8);
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
					ZEPHIR_CALL_FUNCTION(&gravity, "constant", NULL, 148, &_13$$11);
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
					ZEPHIR_CALL_FUNCTION(&gravity, "constant", NULL, 148, &_13$$11);
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
					ZEPHIR_CALL_FUNCTION(&gravity, "constant", NULL, 148, &_13$$11);
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
					ZEPHIR_CALL_FUNCTION(&gravity, "constant", NULL, 148, &_13$$11);
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
					ZEPHIR_CALL_FUNCTION(&gravity, "constant", NULL, 148, &_17$$12);
					zephir_check_call_status();
				} else {
				}
				if (ZEPHIR_GE_LONG(&y, 0)) {
					ZEPHIR_INIT_NVAR(&_17$$12);
					ZVAL_STRING(&_17$$12, "Imagick::GRAVITY_NORTHEAST");
					ZEPHIR_CALL_FUNCTION(&gravity, "constant", NULL, 148, &_17$$12);
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
	zephir_read_property_cached(&_1, this_ptr, _zephir_prop_0, 918, PH_NOISY_CC | PH_READONLY);
	ZVAL_LONG(&_2, 0);
	ZEPHIR_CALL_METHOD(NULL, &_1, "setiteratorindex", NULL, 0, &_2);
	zephir_check_call_status();
	while (1) {
		if (!(1)) {
			break;
		}
		zephir_read_property_cached(&_18$$14, this_ptr, _zephir_prop_0, 918, PH_NOISY_CC | PH_READONLY);
		ZVAL_LONG(&_19$$14, 0);
		ZEPHIR_CALL_METHOD(NULL, &_18$$14, "annotateimage", NULL, 0, &draw, offsetX, offsetY, &_19$$14, &text_zv);
		zephir_check_call_status();
		zephir_read_property_cached(&_19$$14, this_ptr, _zephir_prop_0, 918, PH_NOISY_CC | PH_READONLY);
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
 * @throws Exception
 * @throws ImagickException
 */
PHP_METHOD(Phalcon_Image_Adapter_Imagick, processWatermark)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_12 = NULL;
	zend_long offsetX, offsetY, opacity, ZEPHIR_LAST_CALL_STATUS;
	zval *watermark, watermark_sub, *offsetX_param = NULL, *offsetY_param = NULL, *opacity_param = NULL, image, result, _0, _1, _2, _3, _4, _5, _6$$3, _7$$3, _8$$3, _9$$3, _10$$3, _13$$3, _11$$4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&watermark_sub);
	ZVAL_UNDEF(&image);
	ZVAL_UNDEF(&result);
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
	ZVAL_UNDEF(&_13$$3);
	ZVAL_UNDEF(&_11$$4);
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
	opacity = (long) (zephir_safe_div_long_long(opacity, 100));
	ZEPHIR_INIT_VAR(&image);
	object_init_ex(&image, zephir_get_internal_ce(SL("imagick")));
	ZEPHIR_CALL_METHOD(NULL, &image, "__construct", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_0, watermark, "render", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &image, "readimageblob", NULL, 0, &_0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "Imagick::EVALUATE_MULTIPLY");
	ZEPHIR_CALL_FUNCTION(&_2, "constant", NULL, 148, &_1);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "Imagick::CHANNEL_ALPHA");
	ZEPHIR_CALL_FUNCTION(&_3, "constant", NULL, 148, &_1);
	zephir_check_call_status();
	ZVAL_LONG(&_4, opacity);
	ZEPHIR_CALL_METHOD(NULL, &image, "evaluateimage", NULL, 0, &_2, &_4, &_3);
	zephir_check_call_status();
	zephir_read_property_cached(&_4, this_ptr, _zephir_prop_0, 918, PH_NOISY_CC | PH_READONLY);
	ZVAL_LONG(&_5, 0);
	ZEPHIR_CALL_METHOD(NULL, &_4, "setiteratorindex", NULL, 0, &_5);
	zephir_check_call_status();
	while (1) {
		if (!(1)) {
			break;
		}
		zephir_read_property_cached(&_6$$3, this_ptr, _zephir_prop_0, 918, PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_NVAR(&_7$$3);
		ZVAL_STRING(&_7$$3, "Imagick::COMPOSITE_OVER");
		ZEPHIR_CALL_FUNCTION(&_8$$3, "constant", NULL, 148, &_7$$3);
		zephir_check_call_status();
		ZVAL_LONG(&_9$$3, offsetX);
		ZVAL_LONG(&_10$$3, offsetY);
		ZEPHIR_CALL_METHOD(&result, &_6$$3, "compositeimage", NULL, 0, &image, &_8$$3, &_9$$3, &_10$$3);
		zephir_check_call_status();
		if (!ZEPHIR_IS_TRUE_IDENTICAL(&result)) {
			ZEPHIR_INIT_NVAR(&_11$$4);
			object_init_ex(&_11$$4, phalcon_image_exceptions_compositefailed_ce);
			ZEPHIR_CALL_METHOD(NULL, &_11$$4, "__construct", &_12, 0);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_11$$4, "phalcon/Image/Adapter/Imagick.zep", 857);
			ZEPHIR_MM_RESTORE();
			return;
		}
		zephir_read_property_cached(&_9$$3, this_ptr, _zephir_prop_0, 918, PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(&_13$$3, &_9$$3, "nextimage", NULL, 0);
		zephir_check_call_status();
		if (!ZEPHIR_IS_TRUE_IDENTICAL(&_13$$3)) {
			break;
		}
	}
	ZEPHIR_CALL_METHOD(NULL, &image, "clear", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &image, "destroy", NULL, 0);
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
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("version", 7, 1);
	}
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "imagick");
	if (1 != zephir_class_exists(&_0, 1)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_image_exceptions_extensionnotloaded_ce, "Imagick", "phalcon/Image/Adapter/Imagick.zep", 878);
		return;
	}
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "Imagick::IMAGICK_EXTNUM");
	ZEPHIR_CALL_FUNCTION(&_2, "defined", NULL, 147, &_1);
	zephir_check_call_status();
	if (zephir_is_true(&_2)) {
		ZEPHIR_INIT_VAR(&_3$$4);
		ZVAL_STRING(&_3$$4, "Imagick::IMAGICK_EXTNUM");
		ZEPHIR_CALL_FUNCTION(&_4$$4, "constant", NULL, 148, &_3$$4);
		zephir_check_call_status();
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 924, &_4$$4);
	}
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
	zend_long length, ZEPHIR_LAST_CALL_STATUS;
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
	if (!length_param) {
		length = 0;
	} else {
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
	ZEPHIR_RETURN_CALL_FUNCTION("fgetcsv", NULL, 159, stream, &_0, &separator_zv, enclosure, escape);
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
	zend_long offset, length, ZEPHIR_LAST_CALL_STATUS;
	zend_bool useIncludePath;
	zval filename_zv, *useIncludePath_param = NULL, *context = NULL, context_sub, *offset_param = NULL, *length_param = NULL, __$null, _0$$3, _1$$3, _2, _3, _4;
	zend_string *filename = NULL;

	ZVAL_UNDEF(&filename_zv);
	ZVAL_UNDEF(&context_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
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
	if (!useIncludePath_param) {
		useIncludePath = 0;
	} else {
		}
	if (!context) {
		context = &context_sub;
		context = &__$null;
	}
	if (!offset_param) {
		offset = 0;
	} else {
		}
	if (!length_param) {
		length = 0;
	} else {
		}
	if (0 == length) {
		ZVAL_BOOL(&_0$$3, (useIncludePath ? 1 : 0));
		ZVAL_LONG(&_1$$3, offset);
		ZEPHIR_RETURN_CALL_FUNCTION("file_get_contents", NULL, 160, &filename_zv, &_0$$3, context, &_1$$3);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZVAL_BOOL(&_2, (useIncludePath ? 1 : 0));
	ZVAL_LONG(&_3, offset);
	ZVAL_LONG(&_4, length);
	ZEPHIR_RETURN_CALL_FUNCTION("file_get_contents", NULL, 160, &filename_zv, &_2, context, &_3, &_4);
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
	zend_long flags, ZEPHIR_LAST_CALL_STATUS;
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
	if (!flags_param) {
		flags = 0;
	} else {
		}
	if (!context) {
		context = &context_sub;
		context = &__$null;
	}
	ZVAL_LONG(&_0, flags);
	ZEPHIR_RETURN_CALL_FUNCTION("file_put_contents", NULL, 161, &filename_zv, data, &_0, context);
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
	zend_bool useIncludePath;
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
	if (!useIncludePath_param) {
		useIncludePath = 0;
	} else {
		}
	if (!context) {
		context = &context_sub;
		context = &__$null;
	}
	ZVAL_BOOL(&_0, (useIncludePath ? 1 : 0));
	ZEPHIR_RETURN_CALL_FUNCTION("fopen", NULL, 162, &filename_zv, &mode_zv, &_0, context);
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
	zend_long length, ZEPHIR_LAST_CALL_STATUS;
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
	if (!length_param) {
		length = 0;
	} else {
		}
	if (0 == length) {
		zephir_fwrite(return_value, handle, &data_zv);
		RETURN_MM();
	}
	ZVAL_LONG(&_0, length);
	ZEPHIR_RETURN_CALL_FUNCTION("fwrite", NULL, 163, handle, &data_zv, &_0);
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
	ZEPHIR_RETURN_CALL_FUNCTION("is_writable", NULL, 164, &filename_zv);
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
	ZEPHIR_RETURN_CALL_FUNCTION("unlink", NULL, 165, &filename_zv, context);
	zephir_check_call_status();
	RETURN_MM();
}

