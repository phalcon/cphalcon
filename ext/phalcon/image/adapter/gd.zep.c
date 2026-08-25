
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
#include "kernel/array.h"
#include "kernel/exception.h"
#include "kernel/string.h"
#include "kernel/math.h"
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
 * Image manipulation backed by the GD extension.
 *
 * Capabilities:
 *
 * | Aspect              | Support                                     |
 * |---------------------|---------------------------------------------|
 * | Load formats        | GIF, JPEG, JPEG 2000, PNG, WEBP, WBMP, XBM  |
 * | Render/save formats | GIF, JPEG, PNG, WBMP, WEBP, XBM             |
 * | Backend-only API    | none                                        |
 *
 * Unsupported render/save formats raise
 * Phalcon\Image\Exceptions\UnsupportedImageType. Visual semantics differ from
 * the Imagick adapter: blur() applies repeated 3x3 Gaussian convolutions
 * (the radius is the number of passes), while sharpen and reflection use GD's
 * own scales. Switching the factory backend can change the rendered output.
 *
 * @extends AbstractAdapter<GdImage>
 *
 * @phpstan-import-type image_crop_rectangle from ImageTypes
 * @phpstan-import-type image_text_bounds from ImageTypes
 */
ZEPHIR_INIT_CLASS(Phalcon_Image_Adapter_Gd)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Image\\Adapter, Gd, phalcon, image_adapter_gd, phalcon_image_adapter_abstractadapter_ce, phalcon_image_adapter_gd_method_entry, 0);

	return SUCCESS;
}

/**
 * Loads an image from a file, or creates a blank canvas.
 *
 * When the file exists it is loaded. When the file does not exist and both
 * a width and a height are supplied, a blank true-color canvas is created
 * instead - its realpath, mime and type then describe a PNG canvas rather
 * than the named file. Prefer Gd::create() for the canvas case; this dual
 * mode is slated for removal in the next major version.
 *
 * @param string   $file
 * @param int|null $width
 * @param int|null $height
 *
 * @throws Exception
 */
PHP_METHOD(Phalcon_Image_Adapter_Gd, __construct)
{
	zend_bool _27$$13;
	zval _5$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long width, height, maxPixels, ZEPHIR_LAST_CALL_STATUS;
	zval file_zv, *width_param = NULL, *height_param = NULL, *maxPixels_param = NULL, __$true, image, imageInfo, _0, _1, _2, _3$$3, _4$$3, _6$$3, _17$$3, _26$$3, _7$$4, _8$$4, _9$$4, _10$$4, _11$$4, _12$$4, _13$$4, _14$$4, _15$$5, _16$$5, _18$$6, _19$$7, _20$$8, _21$$9, _22$$10, _23$$11, _24$$12, _25$$12, _30$$13, _31$$13, _32$$13, _33$$13, _34$$13, _28$$14, _29$$14;
	zend_string *file = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&file_zv);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&image);
	ZVAL_UNDEF(&imageInfo);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_17$$3);
	ZVAL_UNDEF(&_26$$3);
	ZVAL_UNDEF(&_7$$4);
	ZVAL_UNDEF(&_8$$4);
	ZVAL_UNDEF(&_9$$4);
	ZVAL_UNDEF(&_10$$4);
	ZVAL_UNDEF(&_11$$4);
	ZVAL_UNDEF(&_12$$4);
	ZVAL_UNDEF(&_13$$4);
	ZVAL_UNDEF(&_14$$4);
	ZVAL_UNDEF(&_15$$5);
	ZVAL_UNDEF(&_16$$5);
	ZVAL_UNDEF(&_18$$6);
	ZVAL_UNDEF(&_19$$7);
	ZVAL_UNDEF(&_20$$8);
	ZVAL_UNDEF(&_21$$9);
	ZVAL_UNDEF(&_22$$10);
	ZVAL_UNDEF(&_23$$11);
	ZVAL_UNDEF(&_24$$12);
	ZVAL_UNDEF(&_25$$12);
	ZVAL_UNDEF(&_30$$13);
	ZVAL_UNDEF(&_31$$13);
	ZVAL_UNDEF(&_32$$13);
	ZVAL_UNDEF(&_33$$13);
	ZVAL_UNDEF(&_34$$13);
	ZVAL_UNDEF(&_28$$14);
	ZVAL_UNDEF(&_29$$14);
	ZVAL_UNDEF(&_5$$3);
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
		_zephir_prop_1 = zend_string_init("type", 4, 1);
	}
	if (UNEXPECTED(!_zephir_prop_2)) {
		_zephir_prop_2 = zend_string_init("maxPixels", 9, 1);
	}
	if (UNEXPECTED(!_zephir_prop_3)) {
		_zephir_prop_3 = zend_string_init("realpath", 8, 1);
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
	if (UNEXPECTED(!_zephir_prop_7)) {
		_zephir_prop_7 = zend_string_init("image", 5, 1);
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
	if (!width_param) {
		width = 0;
	} else {
		}
	if (!height_param) {
		height = 0;
	} else {
		}
	if (!maxPixels_param) {
		maxPixels = 0;
	} else {
		}
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "check", NULL, 0);
	zephir_check_call_status();
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 917, &file_zv);
	ZVAL_UNDEF(&_0);
	ZVAL_LONG(&_0, 0);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_1, 918, &_0);
	ZEPHIR_INIT_VAR(&_1);
	if (maxPixels > 0) {
		ZEPHIR_INIT_NVAR(&_1);
		ZVAL_LONG(&_1, maxPixels);
	} else {
		ZEPHIR_INIT_NVAR(&_1);
		ZVAL_LONG(&_1, 50000000);
	}
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_2, 919, &_1);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 917, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_2, this_ptr, "phpfileexists", NULL, 0, &_0);
	zephir_check_call_status();
	if (ZEPHIR_IS_TRUE_IDENTICAL(&_2)) {
		zephir_read_property_cached(&_3$$3, this_ptr, _zephir_prop_0, 917, PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_FUNCTION(&_4$$3, "realpath", NULL, 158, &_3$$3);
		zephir_check_call_status();
		zephir_cast_to_string(&_5$$3, &_4$$3);
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_3, 920, &_5$$3);
		zephir_read_property_cached(&_6$$3, this_ptr, _zephir_prop_0, 917, PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_FUNCTION(&imageInfo, "getimagesize", NULL, 0, &_6$$3);
		zephir_check_call_status();
		if (!ZEPHIR_IS_FALSE_IDENTICAL(&imageInfo)) {
			zephir_memory_observe(&_7$$4);
			zephir_array_fetch_long(&_7$$4, &imageInfo, 0, PH_NOISY, "phalcon/Image/Adapter/Gd.zep", 90);
			zephir_memory_observe(&_8$$4);
			zephir_array_fetch_long(&_8$$4, &imageInfo, 1, PH_NOISY, "phalcon/Image/Adapter/Gd.zep", 90);
			ZVAL_LONG(&_9$$4, zephir_get_intval(&_7$$4));
			ZVAL_LONG(&_10$$4, zephir_get_intval(&_8$$4));
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "assertpixellimit", NULL, 0, &_9$$4, &_10$$4);
			zephir_check_call_status();
			zephir_array_fetch_long(&_11$$4, &imageInfo, 0, PH_NOISY | PH_READONLY, "phalcon/Image/Adapter/Gd.zep", 92);
			zephir_update_property_zval_cached(this_ptr, _zephir_prop_4, 921, &_11$$4);
			zephir_array_fetch_long(&_12$$4, &imageInfo, 1, PH_NOISY | PH_READONLY, "phalcon/Image/Adapter/Gd.zep", 93);
			zephir_update_property_zval_cached(this_ptr, _zephir_prop_5, 922, &_12$$4);
			zephir_array_fetch_long(&_13$$4, &imageInfo, 2, PH_NOISY | PH_READONLY, "phalcon/Image/Adapter/Gd.zep", 94);
			zephir_update_property_zval_cached(this_ptr, _zephir_prop_1, 918, &_13$$4);
			zephir_array_fetch_string(&_14$$4, &imageInfo, SL("mime"), PH_NOISY | PH_READONLY, "phalcon/Image/Adapter/Gd.zep", 95);
			zephir_update_property_zval_cached(this_ptr, _zephir_prop_6, 923, &_14$$4);
		} else {
			ZEPHIR_INIT_VAR(&_15$$5);
			object_init_ex(&_15$$5, phalcon_image_exceptions_imageloadfailed_ce);
			zephir_read_property_cached(&_16$$5, this_ptr, _zephir_prop_0, 917, PH_NOISY_CC | PH_READONLY);
			ZEPHIR_CALL_METHOD(NULL, &_15$$5, "__construct", NULL, 0, &_16$$5);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_15$$5, "phalcon/Image/Adapter/Gd.zep", 97);
			ZEPHIR_MM_RESTORE();
			return;
		}
		zephir_memory_observe(&_17$$3);
		zephir_read_property_cached(&_17$$3, this_ptr, _zephir_prop_1, 918, PH_NOISY_CC);
		do {
			if (ZEPHIR_IS_LONG(&_17$$3, 1)) {
				zephir_read_property_cached(&_18$$6, this_ptr, _zephir_prop_0, 917, PH_NOISY_CC | PH_READONLY);
				ZEPHIR_CALL_FUNCTION(&image, "imagecreatefromgif", NULL, 0, &_18$$6);
				zephir_check_call_status();
				break;
			}
			if (ZEPHIR_IS_LONG(&_17$$3, 2) || ZEPHIR_IS_LONG(&_17$$3, 9)) {
				zephir_read_property_cached(&_19$$7, this_ptr, _zephir_prop_0, 917, PH_NOISY_CC | PH_READONLY);
				ZEPHIR_CALL_FUNCTION(&image, "imagecreatefromjpeg", NULL, 0, &_19$$7);
				zephir_check_call_status();
				break;
			}
			if (ZEPHIR_IS_LONG(&_17$$3, 3)) {
				zephir_read_property_cached(&_20$$8, this_ptr, _zephir_prop_0, 917, PH_NOISY_CC | PH_READONLY);
				ZEPHIR_CALL_FUNCTION(&image, "imagecreatefrompng", NULL, 0, &_20$$8);
				zephir_check_call_status();
				break;
			}
			if (ZEPHIR_IS_LONG(&_17$$3, 18)) {
				zephir_read_property_cached(&_21$$9, this_ptr, _zephir_prop_0, 917, PH_NOISY_CC | PH_READONLY);
				ZEPHIR_CALL_FUNCTION(&image, "imagecreatefromwebp", NULL, 0, &_21$$9);
				zephir_check_call_status();
				break;
			}
			if (ZEPHIR_IS_LONG(&_17$$3, 15)) {
				zephir_read_property_cached(&_22$$10, this_ptr, _zephir_prop_0, 917, PH_NOISY_CC | PH_READONLY);
				ZEPHIR_CALL_FUNCTION(&image, "imagecreatefromwbmp", NULL, 0, &_22$$10);
				zephir_check_call_status();
				break;
			}
			if (ZEPHIR_IS_LONG(&_17$$3, 16)) {
				zephir_read_property_cached(&_23$$11, this_ptr, _zephir_prop_0, 917, PH_NOISY_CC | PH_READONLY);
				ZEPHIR_CALL_FUNCTION(&image, "imagecreatefromxbm", NULL, 0, &_23$$11);
				zephir_check_call_status();
				break;
			}
			ZEPHIR_INIT_VAR(&_24$$12);
			object_init_ex(&_24$$12, phalcon_image_exceptions_unsupportedimagetype_ce);
			zephir_read_property_cached(&_25$$12, this_ptr, _zephir_prop_6, 923, PH_NOISY_CC | PH_READONLY);
			ZEPHIR_CALL_METHOD(NULL, &_24$$12, "__construct", NULL, 0, &_25$$12);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_24$$12, "phalcon/Image/Adapter/Gd.zep", 127);
			ZEPHIR_MM_RESTORE();
			return;
		} while(0);

		zephir_update_property_zval_cached(this_ptr, _zephir_prop_7, 924, &image);
		zephir_read_property_cached(&_26$$3, this_ptr, _zephir_prop_7, 924, PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_FUNCTION(NULL, "imagesavealpha", NULL, 0, &_26$$3, &__$true);
		zephir_check_call_status();
	} else {
		_27$$13 = 0 == width;
		if (!(_27$$13)) {
			_27$$13 = 0 == height;
		}
		if (_27$$13) {
			ZEPHIR_INIT_VAR(&_28$$14);
			object_init_ex(&_28$$14, phalcon_image_exceptions_imageloadfailed_ce);
			zephir_read_property_cached(&_29$$14, this_ptr, _zephir_prop_0, 917, PH_NOISY_CC | PH_READONLY);
			ZEPHIR_CALL_METHOD(NULL, &_28$$14, "__construct", NULL, 0, &_29$$14);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_28$$14, "phalcon/Image/Adapter/Gd.zep", 136);
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZVAL_LONG(&_30$$13, width);
		ZVAL_LONG(&_31$$13, height);
		ZEPHIR_CALL_FUNCTION(&image, "imagecreatetruecolor", NULL, 0, &_30$$13, &_31$$13);
		zephir_check_call_status();
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_7, 924, &image);
		zephir_read_property_cached(&_30$$13, this_ptr, _zephir_prop_7, 924, PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_FUNCTION(NULL, "imagealphablending", NULL, 0, &_30$$13, &__$true);
		zephir_check_call_status();
		zephir_read_property_cached(&_31$$13, this_ptr, _zephir_prop_7, 924, PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_FUNCTION(NULL, "imagesavealpha", NULL, 0, &_31$$13, &__$true);
		zephir_check_call_status();
		zephir_read_property_cached(&_32$$13, this_ptr, _zephir_prop_0, 917, PH_NOISY_CC | PH_READONLY);
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_3, 920, &_32$$13);
		ZVAL_UNDEF(&_33$$13);
		ZVAL_LONG(&_33$$13, width);
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_4, 921, &_33$$13);
		ZVAL_UNDEF(&_33$$13);
		ZVAL_LONG(&_33$$13, height);
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_5, 922, &_33$$13);
		ZVAL_UNDEF(&_33$$13);
		ZVAL_LONG(&_33$$13, 3);
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_1, 918, &_33$$13);
		ZEPHIR_INIT_VAR(&_34$$13);
		ZEPHIR_INIT_NVAR(&_34$$13);
		ZVAL_STRING(&_34$$13, "image/png");
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_6, 923, &_34$$13);
	}
	ZEPHIR_MM_RESTORE();
}

/**
 * Destructor
 */
PHP_METHOD(Phalcon_Image_Adapter_Gd, __destruct)
{
	zval __$null;
	zval *this_ptr = getThis();

	ZVAL_NULL(&__$null);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("image", 5, 1);
	}
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 924, &__$null);
}

/**
 * Creates a blank true-color canvas of the given dimensions, without the
 * load-or-create ambiguity of the constructor.
 *
 * @phpstan-return AbstractAdapter<GdImage>
 * @throws Exception
 */
PHP_METHOD(Phalcon_Image_Adapter_Gd, create)
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
	object_init_ex(return_value, phalcon_image_adapter_gd_ce);
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "");
	ZVAL_LONG(&_1, width);
	ZVAL_LONG(&_2, height);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 0, &_0, &_1, &_2);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * @throws Exception
 */
PHP_METHOD(Phalcon_Image_Adapter_Gd, getVersion)
{
	zval info, matches, reported, version, _0, _1, _2, _3$$5, _4$$5, _5$$5;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&info);
	ZVAL_UNDEF(&matches);
	ZVAL_UNDEF(&reported);
	ZVAL_UNDEF(&version);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3$$5);
	ZVAL_UNDEF(&_4$$5);
	ZVAL_UNDEF(&_5$$5);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "gd_info");
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "phpfunctionexists", NULL, 0, &_1);
	zephir_check_call_status();
	if (!ZEPHIR_IS_TRUE_IDENTICAL(&_0)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_image_exceptions_extensionnotloaded_ce, "GD", "phalcon/Image/Adapter/Gd.zep", 187);
		return;
	}
	ZEPHIR_INIT_VAR(&version);
	ZVAL_STRING(&version, "");
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "GD_VERSION");
	ZEPHIR_CALL_FUNCTION(&_2, "defined", NULL, 148, &_1);
	zephir_check_call_status();
	if (zephir_is_true(&_2)) {
		ZEPHIR_INIT_NVAR(&version);
		ZEPHIR_GET_CONSTANT(&version, "GD_VERSION");
	} else {
		ZEPHIR_CALL_FUNCTION(&info, "gd_info", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&matches);
		ZVAL_NULL(&matches);
		zephir_memory_observe(&reported);
		zephir_array_fetch_string(&reported, &info, SL("GD Version"), PH_NOISY, "phalcon/Image/Adapter/Gd.zep", 199);
		ZEPHIR_INIT_VAR(&_3$$5);
		ZVAL_STRING(&_3$$5, "/\\d+\\.\\d+(?:\\.\\d+)?/");
		ZEPHIR_INIT_VAR(&_4$$5);
		ZEPHIR_INIT_VAR(&_5$$5);
		ZVAL_STRING(&_5$$5, "/\\d+\\.\\d+(?:\\.\\d+)?/");
		zephir_preg_match(&_4$$5, &_5$$5, &reported, &matches, 0, 0 , 0 );
		if (zephir_is_true(&_4$$5)) {
			ZEPHIR_OBS_NVAR(&version);
			zephir_array_fetch_long(&version, &matches, 0, PH_NOISY, "phalcon/Image/Adapter/Gd.zep", 208);
		}
	}
	RETURN_CCTOR(&version);
}

PHP_METHOD(Phalcon_Image_Adapter_Gd, processBackground)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *red_param = NULL, *green_param = NULL, *blue_param = NULL, *opacity_param = NULL, __$true, background, color, copy, image, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9;
	zend_long red, green, blue, opacity, ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&background);
	ZVAL_UNDEF(&color);
	ZVAL_UNDEF(&copy);
	ZVAL_UNDEF(&image);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_9);
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
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_DOUBLE(&_1, ((zephir_safe_div_long_long((opacity * 127), 100)) - (double) (127)));
	ZEPHIR_CALL_FUNCTION(&_2, "abs", NULL, 0, &_1);
	zephir_check_call_status();
	zephir_round(&_0, &_2, NULL, NULL);
	opacity = zephir_get_intval(&_0);
	zephir_read_property_cached(&_1, this_ptr, _zephir_prop_0, 924, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&image, &_1);
	zephir_read_property_cached(&_1, this_ptr, _zephir_prop_1, 921, PH_NOISY_CC | PH_READONLY);
	zephir_read_property_cached(&_3, this_ptr, _zephir_prop_2, 922, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&background, this_ptr, "processcreate", NULL, 0, &_1, &_3);
	zephir_check_call_status();
	ZVAL_LONG(&_4, red);
	ZVAL_LONG(&_5, green);
	ZVAL_LONG(&_6, blue);
	ZVAL_LONG(&_7, opacity);
	ZEPHIR_CALL_FUNCTION(&color, "imagecolorallocatealpha", NULL, 0, &background, &_4, &_5, &_6, &_7);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(NULL, "imagealphablending", NULL, 0, &background, &__$true);
	zephir_check_call_status();
	zephir_read_property_cached(&_4, this_ptr, _zephir_prop_1, 921, PH_NOISY_CC | PH_READONLY);
	zephir_read_property_cached(&_5, this_ptr, _zephir_prop_2, 922, PH_NOISY_CC | PH_READONLY);
	ZVAL_LONG(&_6, 0);
	ZVAL_LONG(&_7, 0);
	ZVAL_LONG(&_8, 0);
	ZVAL_LONG(&_9, 0);
	ZEPHIR_CALL_FUNCTION(&copy, "imagecopy", NULL, 0, &background, &image, &_6, &_7, &_8, &_9, &_4, &_5);
	zephir_check_call_status();
	if (!ZEPHIR_IS_FALSE_IDENTICAL(&copy)) {
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 924, &background);
	}
	ZEPHIR_MM_RESTORE();
}

PHP_METHOD(Phalcon_Image_Adapter_Gd, processBlur)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_2 = NULL;
	zval *radius_param = NULL, image, _0, _1$$3;
	zend_long radius, ZEPHIR_LAST_CALL_STATUS, counter = 0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&image);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
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
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 924, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&image, &_0);
	counter = 0;
	while (1) {
		if (!(counter < radius)) {
			break;
		}
		ZVAL_LONG(&_1$$3, 7);
		ZEPHIR_CALL_FUNCTION(NULL, "imagefilter", &_2, 0, &image, &_1$$3);
		zephir_check_call_status();
		counter++;
	}
	ZEPHIR_MM_RESTORE();
}

/**
 * @phpstan-return GdImage
 */
PHP_METHOD(Phalcon_Image_Adapter_Gd, processCreate)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *width_param = NULL, *height_param = NULL, __$false, __$true, image, _0, _1;
	zend_long width, height, ZEPHIR_LAST_CALL_STATUS;

	ZVAL_BOOL(&__$false, 0);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&image);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(width)
		Z_PARAM_LONG(height)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 2, 0, &width_param, &height_param);
	ZVAL_LONG(&_0, width);
	ZVAL_LONG(&_1, height);
	ZEPHIR_CALL_FUNCTION(&image, "imagecreatetruecolor", NULL, 0, &_0, &_1);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(NULL, "imagealphablending", NULL, 0, &image, &__$false);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(NULL, "imagesavealpha", NULL, 0, &image, &__$true);
	zephir_check_call_status();
	RETURN_CCTOR(&image);
}

PHP_METHOD(Phalcon_Image_Adapter_Gd, processCrop)
{
	zval rect;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *width_param = NULL, *height_param = NULL, *offsetX_param = NULL, *offsetY_param = NULL, current, image, _0, _1, _2;
	zend_long width, height, offsetX, offsetY, ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&current);
	ZVAL_UNDEF(&image);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&rect);
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
	ZEPHIR_INIT_VAR(&rect);
	zephir_create_array(&rect, 4, 0);
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_LONG(&_0, offsetX);
	zephir_array_update_string(&rect, SL("x"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_LONG(&_0, offsetY);
	zephir_array_update_string(&rect, SL("y"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_LONG(&_0, width);
	zephir_array_update_string(&rect, SL("width"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_LONG(&_0, height);
	zephir_array_update_string(&rect, SL("height"), &_0, PH_COPY | PH_SEPARATE);
	zephir_memory_observe(&current);
	zephir_read_property_cached(&current, this_ptr, _zephir_prop_0, 924, PH_NOISY_CC);
	ZEPHIR_CALL_FUNCTION(&image, "imagecrop", NULL, 0, &current, &rect);
	zephir_check_call_status();
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 924, &image);
	ZEPHIR_CALL_FUNCTION(&_1, "imagesx", NULL, 0, &image);
	zephir_check_call_status();
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_1, 921, &_1);
	ZEPHIR_CALL_FUNCTION(&_2, "imagesy", NULL, 0, &image);
	zephir_check_call_status();
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_2, 922, &_2);
	ZEPHIR_MM_RESTORE();
}

PHP_METHOD(Phalcon_Image_Adapter_Gd, processFlip)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *direction_param = NULL, image, _0, _1$$3, _2$$4;
	zend_long direction, ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&image);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$4);
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
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 924, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&image, &_0);
	if (direction == 11) {
		ZVAL_LONG(&_1$$3, 1);
		ZEPHIR_CALL_FUNCTION(NULL, "imageflip", NULL, 0, &image, &_1$$3);
		zephir_check_call_status();
	} else {
		ZVAL_LONG(&_2$$4, 2);
		ZEPHIR_CALL_FUNCTION(NULL, "imageflip", NULL, 0, &image, &_2$$4);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();
}

PHP_METHOD(Phalcon_Image_Adapter_Gd, processMask)
{
	zend_bool _9;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_21 = NULL, *_22 = NULL, *_25 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS, alpha = 0, maskHeight = 0, maskWidth = 0, x = 0, y = 0;
	zval *mask, mask_sub, __$true, blue, color, current, height, index, green, maskImage, newImage, pixel, red, tempImage, width, _0, _1, _2, _3, _4, _5, _6, _7, _8, _10$$3, _11$$3, _12$$3, _13$$3, _14$$3, _15$$3, _16$$3, _17$$3, _18$$4, _19$$5, _20$$5, _23$$5, _24$$5;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&mask_sub);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&blue);
	ZVAL_UNDEF(&color);
	ZVAL_UNDEF(&current);
	ZVAL_UNDEF(&height);
	ZVAL_UNDEF(&index);
	ZVAL_UNDEF(&green);
	ZVAL_UNDEF(&maskImage);
	ZVAL_UNDEF(&newImage);
	ZVAL_UNDEF(&pixel);
	ZVAL_UNDEF(&red);
	ZVAL_UNDEF(&tempImage);
	ZVAL_UNDEF(&width);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_10$$3);
	ZVAL_UNDEF(&_11$$3);
	ZVAL_UNDEF(&_12$$3);
	ZVAL_UNDEF(&_13$$3);
	ZVAL_UNDEF(&_14$$3);
	ZVAL_UNDEF(&_15$$3);
	ZVAL_UNDEF(&_16$$3);
	ZVAL_UNDEF(&_17$$3);
	ZVAL_UNDEF(&_18$$4);
	ZVAL_UNDEF(&_19$$5);
	ZVAL_UNDEF(&_20$$5);
	ZVAL_UNDEF(&_23$$5);
	ZVAL_UNDEF(&_24$$5);
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
		Z_PARAM_OBJECT_OF_CLASS(mask, phalcon_image_adapter_adapterinterface_ce)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &mask);
	ZEPHIR_CALL_METHOD(&_0, mask, "render", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&maskImage, "imagecreatefromstring", NULL, 0, &_0);
	zephir_check_call_status();
	zephir_memory_observe(&current);
	zephir_read_property_cached(&current, this_ptr, _zephir_prop_0, 924, PH_NOISY_CC);
	ZEPHIR_CALL_FUNCTION(&_1, "imagesx", NULL, 0, &maskImage);
	zephir_check_call_status();
	maskWidth = zephir_get_intval(&_1);
	ZEPHIR_CALL_FUNCTION(&_2, "imagesy", NULL, 0, &maskImage);
	zephir_check_call_status();
	maskHeight = zephir_get_intval(&_2);
	alpha = 127;
	ZEPHIR_CALL_FUNCTION(NULL, "imagesavealpha", NULL, 0, &maskImage, &__$true);
	zephir_check_call_status();
	zephir_read_property_cached(&_3, this_ptr, _zephir_prop_1, 921, PH_NOISY_CC | PH_READONLY);
	zephir_read_property_cached(&_4, this_ptr, _zephir_prop_2, 922, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&newImage, this_ptr, "processcreate", NULL, 0, &_3, &_4);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(NULL, "imagesavealpha", NULL, 0, &newImage, &__$true);
	zephir_check_call_status();
	ZVAL_LONG(&_5, 0);
	ZVAL_LONG(&_6, 0);
	ZVAL_LONG(&_7, 0);
	ZVAL_LONG(&_8, alpha);
	ZEPHIR_CALL_FUNCTION(&color, "imagecolorallocatealpha", NULL, 0, &newImage, &_5, &_6, &_7, &_8);
	zephir_check_call_status();
	ZVAL_LONG(&_5, 0);
	ZVAL_LONG(&_6, 0);
	ZEPHIR_CALL_FUNCTION(NULL, "imagefill", NULL, 0, &newImage, &_5, &_6, &color);
	zephir_check_call_status();
	zephir_read_property_cached(&_5, this_ptr, _zephir_prop_1, 921, PH_NOISY_CC | PH_READONLY);
	_9 = !ZEPHIR_IS_LONG_IDENTICAL(&_5, maskWidth);
	if (!(_9)) {
		zephir_read_property_cached(&_6, this_ptr, _zephir_prop_2, 922, PH_NOISY_CC | PH_READONLY);
		_9 = !ZEPHIR_IS_LONG_IDENTICAL(&_6, maskHeight);
	}
	if (_9) {
		zephir_read_property_cached(&_10$$3, this_ptr, _zephir_prop_1, 921, PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CPY_WRT(&width, &_10$$3);
		zephir_read_property_cached(&_10$$3, this_ptr, _zephir_prop_2, 922, PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CPY_WRT(&height, &_10$$3);
		ZEPHIR_CALL_FUNCTION(&tempImage, "imagecreatetruecolor", NULL, 0, &width, &height);
		zephir_check_call_status();
		zephir_read_property_cached(&_10$$3, this_ptr, _zephir_prop_1, 921, PH_NOISY_CC | PH_READONLY);
		zephir_read_property_cached(&_11$$3, this_ptr, _zephir_prop_2, 922, PH_NOISY_CC | PH_READONLY);
		ZVAL_LONG(&_12$$3, 0);
		ZVAL_LONG(&_13$$3, 0);
		ZVAL_LONG(&_14$$3, 0);
		ZVAL_LONG(&_15$$3, 0);
		ZVAL_LONG(&_16$$3, maskWidth);
		ZVAL_LONG(&_17$$3, maskHeight);
		ZEPHIR_CALL_FUNCTION(NULL, "imagecopyresampled", NULL, 0, &tempImage, &maskImage, &_12$$3, &_13$$3, &_14$$3, &_15$$3, &_10$$3, &_11$$3, &_16$$3, &_17$$3);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(&maskImage, &tempImage);
	}
	x = 0;
	while (1) {
		zephir_read_property_cached(&_7, this_ptr, _zephir_prop_1, 921, PH_NOISY_CC | PH_READONLY);
		if (!(ZEPHIR_GT_LONG(&_7, x))) {
			break;
		}
		y = 0;
		while (1) {
			zephir_read_property_cached(&_18$$4, this_ptr, _zephir_prop_2, 922, PH_NOISY_CC | PH_READONLY);
			if (!(ZEPHIR_GT_LONG(&_18$$4, y))) {
				break;
			}
			ZVAL_LONG(&_19$$5, x);
			ZVAL_LONG(&_20$$5, y);
			ZEPHIR_CALL_FUNCTION(&index, "imagecolorat", &_21, 0, &maskImage, &_19$$5, &_20$$5);
			zephir_check_call_status();
			ZEPHIR_CALL_FUNCTION(&color, "imagecolorsforindex", &_22, 0, &maskImage, &index);
			zephir_check_call_status();
			zephir_array_fetch_string(&_23$$5, &color, SL("red"), PH_NOISY | PH_READONLY, "phalcon/Image/Adapter/Gd.zep", 401);
			ZVAL_DOUBLE(&_19$$5, zephir_safe_div_zval_long(&_23$$5, 2));
			alpha = (127 - zephir_get_intval(&_19$$5));
			ZVAL_LONG(&_20$$5, x);
			ZVAL_LONG(&_24$$5, y);
			ZEPHIR_CALL_FUNCTION(&index, "imagecolorat", &_21, 0, &current, &_20$$5, &_24$$5);
			zephir_check_call_status();
			ZEPHIR_CALL_FUNCTION(&color, "imagecolorsforindex", &_22, 0, &current, &index);
			zephir_check_call_status();
			ZEPHIR_OBS_NVAR(&red);
			zephir_array_fetch_string(&red, &color, SL("red"), PH_NOISY, "phalcon/Image/Adapter/Gd.zep", 406);
			ZEPHIR_OBS_NVAR(&green);
			zephir_array_fetch_string(&green, &color, SL("green"), PH_NOISY, "phalcon/Image/Adapter/Gd.zep", 407);
			ZEPHIR_OBS_NVAR(&blue);
			zephir_array_fetch_string(&blue, &color, SL("blue"), PH_NOISY, "phalcon/Image/Adapter/Gd.zep", 408);
			ZVAL_LONG(&_20$$5, alpha);
			ZEPHIR_CALL_FUNCTION(&pixel, "imagecolorallocatealpha", NULL, 0, &newImage, &red, &green, &blue, &_20$$5);
			zephir_check_call_status();
			ZVAL_LONG(&_20$$5, x);
			ZVAL_LONG(&_24$$5, y);
			ZEPHIR_CALL_FUNCTION(NULL, "imagesetpixel", &_25, 0, &newImage, &_20$$5, &_24$$5, &pixel);
			zephir_check_call_status();
			y++;
		}
		x++;
	}
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 924, &newImage);
	ZEPHIR_MM_RESTORE();
}

PHP_METHOD(Phalcon_Image_Adapter_Gd, processPixelate)
{
	zend_bool _3$$4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_7 = NULL, *_8 = NULL;
	zval *amount_param = NULL, color, image, x2, y2, _0, _1$$3, _2$$4, _4$$4, _5$$4, _6$$4;
	zend_long amount, ZEPHIR_LAST_CALL_STATUS, x = 0, x1 = 0, y = 0, y1 = 0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&color);
	ZVAL_UNDEF(&image);
	ZVAL_UNDEF(&x2);
	ZVAL_UNDEF(&y2);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_5$$4);
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

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(amount)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &amount_param);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 924, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&image, &_0);
	x = 0;
	while (1) {
		zephir_read_property_cached(&_0, this_ptr, _zephir_prop_1, 921, PH_NOISY_CC | PH_READONLY);
		if (!(ZEPHIR_GT_LONG(&_0, x))) {
			break;
		}
		y = 0;
		while (1) {
			zephir_read_property_cached(&_1$$3, this_ptr, _zephir_prop_2, 922, PH_NOISY_CC | PH_READONLY);
			if (!(ZEPHIR_GT_LONG(&_1$$3, y))) {
				break;
			}
			x1 = ((x + (zephir_safe_div_long_long(amount, 2))));
			y1 = ((y + (zephir_safe_div_long_long(amount, 2))));
			zephir_read_property_cached(&_2$$4, this_ptr, _zephir_prop_1, 921, PH_NOISY_CC | PH_READONLY);
			_3$$4 = ZEPHIR_LE_LONG(&_2$$4, x1);
			if (!(_3$$4)) {
				zephir_read_property_cached(&_4$$4, this_ptr, _zephir_prop_2, 922, PH_NOISY_CC | PH_READONLY);
				_3$$4 = ZEPHIR_LE_LONG(&_4$$4, y1);
			}
			if (_3$$4) {
				break;
			}
			ZVAL_LONG(&_5$$4, x1);
			ZVAL_LONG(&_6$$4, y1);
			ZEPHIR_CALL_FUNCTION(&color, "imagecolorat", &_7, 0, &image, &_5$$4, &_6$$4);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(&x2);
			ZVAL_LONG(&x2, (x + amount));
			ZEPHIR_INIT_NVAR(&y2);
			ZVAL_LONG(&y2, (y + amount));
			ZVAL_LONG(&_5$$4, x);
			ZVAL_LONG(&_6$$4, y);
			ZEPHIR_CALL_FUNCTION(NULL, "imagefilledrectangle", &_8, 0, &image, &_5$$4, &_6$$4, &x2, &y2, &color);
			zephir_check_call_status();
			y += amount;
		}
		x += amount;
	}
	ZEPHIR_MM_RESTORE();
}

PHP_METHOD(Phalcon_Image_Adapter_Gd, processReflection)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_23 = NULL;
	zend_bool fadeIn;
	zval *height_param = NULL, *opacity_param = NULL, *fadeIn_param = NULL, image, line, reflection, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _25, _26, _10$$5, _11$$5, _16$$5, _17$$5, _18$$5, _19$$5, _20$$5, _21$$5, _22$$5, _24$$5, _12$$6, _13$$6, _14$$7, _15$$7;
	zend_long height, opacity, ZEPHIR_LAST_CALL_STATUS, destinationY = 0, destinationOpacity = 0, offset = 0, stepping = 0, sourceY = 0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&image);
	ZVAL_UNDEF(&line);
	ZVAL_UNDEF(&reflection);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_25);
	ZVAL_UNDEF(&_26);
	ZVAL_UNDEF(&_10$$5);
	ZVAL_UNDEF(&_11$$5);
	ZVAL_UNDEF(&_16$$5);
	ZVAL_UNDEF(&_17$$5);
	ZVAL_UNDEF(&_18$$5);
	ZVAL_UNDEF(&_19$$5);
	ZVAL_UNDEF(&_20$$5);
	ZVAL_UNDEF(&_21$$5);
	ZVAL_UNDEF(&_22$$5);
	ZVAL_UNDEF(&_24$$5);
	ZVAL_UNDEF(&_12$$6);
	ZVAL_UNDEF(&_13$$6);
	ZVAL_UNDEF(&_14$$7);
	ZVAL_UNDEF(&_15$$7);
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

	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_LONG(height)
		Z_PARAM_LONG(opacity)
		Z_PARAM_BOOL(fadeIn)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 3, 0, &height_param, &opacity_param, &fadeIn_param);
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_DOUBLE(&_1, ((zephir_safe_div_long_long((opacity * 127), 100)) - (double) (127)));
	ZEPHIR_CALL_FUNCTION(&_2, "abs", NULL, 0, &_1);
	zephir_check_call_status();
	zephir_round(&_0, &_2, NULL, NULL);
	opacity = zephir_get_intval(&_0);
	zephir_read_property_cached(&_1, this_ptr, _zephir_prop_0, 924, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&image, &_1);
	if (opacity < 127) {
		stepping = (long) (zephir_safe_div_long_long(((127 - opacity)), height));
	} else {
		stepping = (long) (zephir_safe_div_long_long(127, height));
	}
	zephir_read_property_cached(&_1, this_ptr, _zephir_prop_1, 921, PH_NOISY_CC | PH_READONLY);
	zephir_read_property_cached(&_3, this_ptr, _zephir_prop_2, 922, PH_NOISY_CC | PH_READONLY);
	ZVAL_LONG(&_4, (zephir_get_numberval(&_3) + height));
	ZEPHIR_CALL_METHOD(&reflection, this_ptr, "processcreate", NULL, 0, &_1, &_4);
	zephir_check_call_status();
	zephir_read_property_cached(&_4, this_ptr, _zephir_prop_1, 921, PH_NOISY_CC | PH_READONLY);
	zephir_read_property_cached(&_5, this_ptr, _zephir_prop_2, 922, PH_NOISY_CC | PH_READONLY);
	ZVAL_LONG(&_6, 0);
	ZVAL_LONG(&_7, 0);
	ZVAL_LONG(&_8, 0);
	ZVAL_LONG(&_9, 0);
	ZEPHIR_CALL_FUNCTION(NULL, "imagecopy", NULL, 0, &reflection, &image, &_6, &_7, &_8, &_9, &_4, &_5);
	zephir_check_call_status();
	offset = 0;
	while (1) {
		if (!(height >= offset)) {
			break;
		}
		zephir_read_property_cached(&_10$$5, this_ptr, _zephir_prop_2, 922, PH_NOISY_CC | PH_READONLY);
		sourceY = ((zephir_get_numberval(&_10$$5) - offset) - 1);
		zephir_read_property_cached(&_11$$5, this_ptr, _zephir_prop_2, 922, PH_NOISY_CC | PH_READONLY);
		destinationY = (zephir_get_numberval(&_11$$5) + offset);
		if (fadeIn) {
			ZEPHIR_INIT_NVAR(&_12$$6);
			ZVAL_LONG(&_13$$6, (opacity + ((stepping * ((height - offset))))));
			zephir_round(&_12$$6, &_13$$6, NULL, NULL);
			destinationOpacity = zephir_get_intval(&_12$$6);
		} else {
			ZEPHIR_INIT_NVAR(&_14$$7);
			ZVAL_LONG(&_15$$7, (opacity + ((stepping * offset))));
			zephir_round(&_14$$7, &_15$$7, NULL, NULL);
			destinationOpacity = zephir_get_intval(&_14$$7);
		}
		zephir_read_property_cached(&_16$$5, this_ptr, _zephir_prop_1, 921, PH_NOISY_CC | PH_READONLY);
		ZVAL_LONG(&_17$$5, 1);
		ZEPHIR_CALL_METHOD(&line, this_ptr, "processcreate", NULL, 0, &_16$$5, &_17$$5);
		zephir_check_call_status();
		zephir_read_property_cached(&_17$$5, this_ptr, _zephir_prop_1, 921, PH_NOISY_CC | PH_READONLY);
		ZVAL_LONG(&_18$$5, 0);
		ZVAL_LONG(&_19$$5, 0);
		ZVAL_LONG(&_20$$5, 0);
		ZVAL_LONG(&_21$$5, sourceY);
		ZVAL_LONG(&_22$$5, 1);
		ZEPHIR_CALL_FUNCTION(NULL, "imagecopy", NULL, 0, &line, &image, &_18$$5, &_19$$5, &_20$$5, &_21$$5, &_17$$5, &_22$$5);
		zephir_check_call_status();
		ZVAL_LONG(&_18$$5, 4);
		ZVAL_LONG(&_19$$5, 0);
		ZVAL_LONG(&_20$$5, 0);
		ZVAL_LONG(&_21$$5, 0);
		ZVAL_LONG(&_22$$5, destinationOpacity);
		ZEPHIR_CALL_FUNCTION(NULL, "imagefilter", &_23, 0, &line, &_18$$5, &_19$$5, &_20$$5, &_21$$5, &_22$$5);
		zephir_check_call_status();
		zephir_read_property_cached(&_18$$5, this_ptr, _zephir_prop_1, 921, PH_NOISY_CC | PH_READONLY);
		ZVAL_LONG(&_19$$5, 0);
		ZVAL_LONG(&_20$$5, destinationY);
		ZVAL_LONG(&_21$$5, 0);
		ZVAL_LONG(&_22$$5, 0);
		ZVAL_LONG(&_24$$5, 1);
		ZEPHIR_CALL_FUNCTION(NULL, "imagecopy", NULL, 0, &reflection, &line, &_19$$5, &_20$$5, &_21$$5, &_22$$5, &_18$$5, &_24$$5);
		zephir_check_call_status();
		offset++;
	}
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 924, &reflection);
	ZEPHIR_CALL_FUNCTION(&_25, "imagesx", NULL, 0, &reflection);
	zephir_check_call_status();
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_1, 921, &_25);
	ZEPHIR_CALL_FUNCTION(&_26, "imagesy", NULL, 0, &reflection);
	zephir_check_call_status();
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_2, 922, &_26);
	ZEPHIR_MM_RESTORE();
}

PHP_METHOD(Phalcon_Image_Adapter_Gd, processRender)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long quality, ZEPHIR_LAST_CALL_STATUS;
	zval *extension_param = NULL, *quality_param = NULL, __$null, image, _0, _1, _2$$4, _3$$9;
	zval extension;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&extension);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&image);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_3$$9);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("image", 5, 1);
	}

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_ZVAL(extension_param)
		Z_PARAM_LONG(quality)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 2, 0, &extension_param, &quality_param);
	zephir_get_strval(&extension, extension_param);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 924, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&image, &_0);
	ZEPHIR_INIT_VAR(&_1);
	zephir_fast_strtolower(&_1, &extension);
	zephir_get_strval(&extension, &_1);
	ZEPHIR_CALL_FUNCTION(NULL, "ob_start", NULL, 0);
	zephir_check_call_status();
	do {
		if (ZEPHIR_IS_STRING(&extension, "gif")) {
			ZEPHIR_CALL_FUNCTION(NULL, "imagegif", NULL, 0, &image);
			zephir_check_call_status();
			break;
		}
		if (ZEPHIR_IS_STRING(&extension, "jpg") || ZEPHIR_IS_STRING(&extension, "jpeg")) {
			ZVAL_LONG(&_2$$4, quality);
			ZEPHIR_CALL_FUNCTION(NULL, "imagejpeg", NULL, 0, &image, &__$null, &_2$$4);
			zephir_check_call_status();
			break;
		}
		if (ZEPHIR_IS_STRING(&extension, "png")) {
			ZEPHIR_CALL_FUNCTION(NULL, "imagepng", NULL, 0, &image);
			zephir_check_call_status();
			break;
		}
		if (ZEPHIR_IS_STRING(&extension, "wbmp")) {
			ZEPHIR_CALL_FUNCTION(NULL, "imagewbmp", NULL, 0, &image);
			zephir_check_call_status();
			break;
		}
		if (ZEPHIR_IS_STRING(&extension, "webp")) {
			ZEPHIR_CALL_FUNCTION(NULL, "imagewebp", NULL, 0, &image);
			zephir_check_call_status();
			break;
		}
		if (ZEPHIR_IS_STRING(&extension, "xbm")) {
			ZEPHIR_CALL_FUNCTION(NULL, "imagexbm", NULL, 0, &image, &__$null);
			zephir_check_call_status();
			break;
		}
		ZEPHIR_INIT_VAR(&_3$$9);
		object_init_ex(&_3$$9, phalcon_image_exceptions_unsupportedimagetype_ce);
		ZEPHIR_CALL_METHOD(NULL, &_3$$9, "__construct", NULL, 0, &extension);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_3$$9, "phalcon/Image/Adapter/Gd.zep", 594);
		ZEPHIR_MM_RESTORE();
		return;
	} while(0);

	ZEPHIR_RETURN_CALL_FUNCTION("ob_get_clean", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();
}

PHP_METHOD(Phalcon_Image_Adapter_Gd, processResize)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *width_param = NULL, *height_param = NULL, __$false, __$true, current, image, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9;
	zend_long width, height, ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$false, 0);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&current);
	ZVAL_UNDEF(&image);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_9);
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
	zephir_memory_observe(&current);
	zephir_read_property_cached(&current, this_ptr, _zephir_prop_0, 924, PH_NOISY_CC);
	ZVAL_LONG(&_0, width);
	ZVAL_LONG(&_1, height);
	ZEPHIR_CALL_FUNCTION(&image, "imagecreatetruecolor", NULL, 0, &_0, &_1);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(NULL, "imagealphablending", NULL, 0, &image, &__$false);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(NULL, "imagesavealpha", NULL, 0, &image, &__$true);
	zephir_check_call_status();
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_1, 921, PH_NOISY_CC | PH_READONLY);
	zephir_read_property_cached(&_1, this_ptr, _zephir_prop_2, 922, PH_NOISY_CC | PH_READONLY);
	ZVAL_LONG(&_2, 0);
	ZVAL_LONG(&_3, 0);
	ZVAL_LONG(&_4, 0);
	ZVAL_LONG(&_5, 0);
	ZVAL_LONG(&_6, width);
	ZVAL_LONG(&_7, height);
	ZEPHIR_CALL_FUNCTION(NULL, "imagecopyresampled", NULL, 0, &image, &current, &_2, &_3, &_4, &_5, &_6, &_7, &_0, &_1);
	zephir_check_call_status();
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 924, &image);
	ZEPHIR_CALL_FUNCTION(&_8, "imagesx", NULL, 0, &image);
	zephir_check_call_status();
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_1, 921, &_8);
	ZEPHIR_CALL_FUNCTION(&_9, "imagesy", NULL, 0, &image);
	zephir_check_call_status();
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_2, 922, &_9);
	ZEPHIR_MM_RESTORE();
}

PHP_METHOD(Phalcon_Image_Adapter_Gd, processRotate)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *degrees_param = NULL, __$true, copy, current, height, image, transparent, width, _0, _1, _2, _3, _4;
	zend_long degrees, ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&copy);
	ZVAL_UNDEF(&current);
	ZVAL_UNDEF(&height);
	ZVAL_UNDEF(&image);
	ZVAL_UNDEF(&transparent);
	ZVAL_UNDEF(&width);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
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
	zephir_memory_observe(&current);
	zephir_read_property_cached(&current, this_ptr, _zephir_prop_0, 924, PH_NOISY_CC);
	ZVAL_LONG(&_0, 0);
	ZVAL_LONG(&_1, 0);
	ZVAL_LONG(&_2, 0);
	ZVAL_LONG(&_3, 127);
	ZEPHIR_CALL_FUNCTION(&transparent, "imagecolorallocatealpha", NULL, 0, &current, &_0, &_1, &_2, &_3);
	zephir_check_call_status();
	ZVAL_LONG(&_0, (360 - degrees));
	ZEPHIR_CALL_FUNCTION(&image, "imagerotate", NULL, 0, &current, &_0, &transparent);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(NULL, "imagesavealpha", NULL, 0, &image, &__$true);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&width, "imagesx", NULL, 0, &image);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&height, "imagesy", NULL, 0, &image);
	zephir_check_call_status();
	ZVAL_LONG(&_0, 0);
	ZVAL_LONG(&_1, 0);
	ZVAL_LONG(&_2, 0);
	ZVAL_LONG(&_3, 0);
	ZVAL_LONG(&_4, 100);
	ZEPHIR_CALL_FUNCTION(&copy, "imagecopymerge", NULL, 0, &current, &image, &_0, &_1, &_2, &_3, &width, &height, &_4);
	zephir_check_call_status();
	if (!ZEPHIR_IS_FALSE_IDENTICAL(&copy)) {
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 924, &image);
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_1, 921, &width);
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_2, 922, &height);
	}
	ZEPHIR_MM_RESTORE();
}

/**
 * @throws Exception
 */
PHP_METHOD(Phalcon_Image_Adapter_Gd, processSave)
{
	zval _3$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long quality, ZEPHIR_LAST_CALL_STATUS;
	zval file_zv, *quality_param = NULL, __$false, extension, image, _0, _4, _15, _1$$3, _2$$3, _5$$4, _6$$5, _7$$6, _8$$6, _9$$6, _10$$8, _11$$9, _12$$10, _13$$11, _14$$12;
	zend_string *file = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&file_zv);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&extension);
	ZVAL_UNDEF(&image);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_15);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_6$$5);
	ZVAL_UNDEF(&_7$$6);
	ZVAL_UNDEF(&_8$$6);
	ZVAL_UNDEF(&_9$$6);
	ZVAL_UNDEF(&_10$$8);
	ZVAL_UNDEF(&_11$$9);
	ZVAL_UNDEF(&_12$$10);
	ZVAL_UNDEF(&_13$$11);
	ZVAL_UNDEF(&_14$$12);
	ZVAL_UNDEF(&_3$$3);
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
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 924, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&image, &_0);
	ZVAL_LONG(&_0, 4);
	ZEPHIR_CALL_FUNCTION(&extension, "pathinfo", NULL, 202, &file_zv, &_0);
	zephir_check_call_status();
	if (1 == ZEPHIR_IS_EMPTY(&extension)) {
		zephir_read_property_cached(&_1$$3, this_ptr, _zephir_prop_1, 918, PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_FUNCTION(&_2$$3, "image_type_to_extension", NULL, 0, &_1$$3, &__$false);
		zephir_check_call_status();
		zephir_cast_to_string(&_3$$3, &_2$$3);
		ZEPHIR_CPY_WRT(&extension, &_3$$3);
	}
	ZEPHIR_INIT_VAR(&_4);
	zephir_fast_strtolower(&_4, &extension);
	ZEPHIR_CPY_WRT(&extension, &_4);
	do {
		if (ZEPHIR_IS_STRING(&extension, "gif")) {
			ZVAL_UNDEF(&_5$$4);
			ZVAL_LONG(&_5$$4, 1);
			zephir_update_property_zval_cached(this_ptr, _zephir_prop_1, 918, &_5$$4);
			ZEPHIR_CALL_FUNCTION(NULL, "imagegif", NULL, 0, &image, &file_zv);
			zephir_check_call_status();
			break;
		}
		if (ZEPHIR_IS_STRING(&extension, "jpg") || ZEPHIR_IS_STRING(&extension, "jpeg")) {
			ZVAL_UNDEF(&_6$$5);
			ZVAL_LONG(&_6$$5, 2);
			zephir_update_property_zval_cached(this_ptr, _zephir_prop_1, 918, &_6$$5);
			if (quality >= 0) {
				ZVAL_LONG(&_8$$6, quality);
				ZVAL_LONG(&_9$$6, 1);
				ZEPHIR_CALL_METHOD(&_7$$6, this_ptr, "checkhighlow", NULL, 0, &_8$$6, &_9$$6);
				zephir_check_call_status();
				quality = zephir_get_numberval(&_7$$6);
				ZVAL_LONG(&_8$$6, quality);
				ZEPHIR_CALL_FUNCTION(NULL, "imagejpeg", NULL, 0, &image, &file_zv, &_8$$6);
				zephir_check_call_status();
			} else {
				ZEPHIR_CALL_FUNCTION(NULL, "imagejpeg", NULL, 0, &image, &file_zv);
				zephir_check_call_status();
			}
			break;
		}
		if (ZEPHIR_IS_STRING(&extension, "png")) {
			ZVAL_UNDEF(&_10$$8);
			ZVAL_LONG(&_10$$8, 3);
			zephir_update_property_zval_cached(this_ptr, _zephir_prop_1, 918, &_10$$8);
			ZEPHIR_CALL_FUNCTION(NULL, "imagepng", NULL, 0, &image, &file_zv);
			zephir_check_call_status();
			break;
		}
		if (ZEPHIR_IS_STRING(&extension, "wbmp")) {
			ZVAL_UNDEF(&_11$$9);
			ZVAL_LONG(&_11$$9, 15);
			zephir_update_property_zval_cached(this_ptr, _zephir_prop_1, 918, &_11$$9);
			ZEPHIR_CALL_FUNCTION(NULL, "imagewbmp", NULL, 0, &image, &file_zv);
			zephir_check_call_status();
			break;
		}
		if (ZEPHIR_IS_STRING(&extension, "webp")) {
			ZVAL_UNDEF(&_12$$10);
			ZVAL_LONG(&_12$$10, 18);
			zephir_update_property_zval_cached(this_ptr, _zephir_prop_1, 918, &_12$$10);
			ZEPHIR_CALL_FUNCTION(NULL, "imagewebp", NULL, 0, &image, &file_zv);
			zephir_check_call_status();
			break;
		}
		if (ZEPHIR_IS_STRING(&extension, "xbm")) {
			ZVAL_UNDEF(&_13$$11);
			ZVAL_LONG(&_13$$11, 16);
			zephir_update_property_zval_cached(this_ptr, _zephir_prop_1, 918, &_13$$11);
			ZEPHIR_CALL_FUNCTION(NULL, "imagexbm", NULL, 0, &image, &file_zv);
			zephir_check_call_status();
			break;
		}
		ZEPHIR_INIT_VAR(&_14$$12);
		object_init_ex(&_14$$12, phalcon_image_exceptions_unsupportedimagetype_ce);
		ZEPHIR_CALL_METHOD(NULL, &_14$$12, "__construct", NULL, 0, &extension);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_14$$12, "phalcon/Image/Adapter/Gd.zep", 720);
		ZEPHIR_MM_RESTORE();
		return;
	} while(0);

	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_1, 918, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_FUNCTION(&_15, "image_type_to_mime_type", NULL, 0, &_0);
	zephir_check_call_status();
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_2, 923, &_15);
	RETURN_MM_BOOL(1);
}

PHP_METHOD(Phalcon_Image_Adapter_Gd, processSharpen)
{
	zval matrix, _3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *amount_param = NULL, image, result, _0, _1, _2, _4, _5, _6, _7$$3, _8$$3;
	zend_long amount, ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&image);
	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7$$3);
	ZVAL_UNDEF(&_8$$3);
	ZVAL_UNDEF(&matrix);
	ZVAL_UNDEF(&_3);
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
		Z_PARAM_LONG(amount)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &amount_param);
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_LONG(&_1, (-18 + ((amount * 0.08))));
	ZEPHIR_CALL_FUNCTION(&_2, "abs", NULL, 0, &_1);
	zephir_check_call_status();
	ZVAL_LONG(&_1, 2);
	zephir_round(&_0, &_2, &_1, NULL);
	amount = zephir_get_intval(&_0);
	ZEPHIR_INIT_VAR(&matrix);
	zephir_create_array(&matrix, 3, 0);
	ZEPHIR_INIT_VAR(&_3);
	zephir_create_array(&_3, 3, 0);
	ZEPHIR_INIT_VAR(&_4);
	ZVAL_LONG(&_4, -1);
	zephir_array_fast_append(&_3, &_4);
	ZEPHIR_INIT_NVAR(&_4);
	ZVAL_LONG(&_4, -1);
	zephir_array_fast_append(&_3, &_4);
	ZEPHIR_INIT_NVAR(&_4);
	ZVAL_LONG(&_4, -1);
	zephir_array_fast_append(&_3, &_4);
	zephir_array_fast_append(&matrix, &_3);
	ZEPHIR_INIT_NVAR(&_3);
	zephir_create_array(&_3, 3, 0);
	ZEPHIR_INIT_NVAR(&_4);
	ZVAL_LONG(&_4, -1);
	zephir_array_fast_append(&_3, &_4);
	ZEPHIR_INIT_NVAR(&_4);
	ZVAL_LONG(&_4, amount);
	zephir_array_fast_append(&_3, &_4);
	ZEPHIR_INIT_NVAR(&_4);
	ZVAL_LONG(&_4, -1);
	zephir_array_fast_append(&_3, &_4);
	zephir_array_fast_append(&matrix, &_3);
	ZEPHIR_INIT_NVAR(&_3);
	zephir_create_array(&_3, 3, 0);
	ZEPHIR_INIT_NVAR(&_4);
	ZVAL_LONG(&_4, -1);
	zephir_array_fast_append(&_3, &_4);
	ZEPHIR_INIT_NVAR(&_4);
	ZVAL_LONG(&_4, -1);
	zephir_array_fast_append(&_3, &_4);
	ZEPHIR_INIT_NVAR(&_4);
	ZVAL_LONG(&_4, -1);
	zephir_array_fast_append(&_3, &_4);
	zephir_array_fast_append(&matrix, &_3);
	zephir_read_property_cached(&_5, this_ptr, _zephir_prop_0, 924, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&image, &_5);
	ZVAL_LONG(&_5, (amount - 8));
	ZVAL_LONG(&_6, 0);
	ZEPHIR_CALL_FUNCTION(&result, "imageconvolution", NULL, 0, &image, &matrix, &_5, &_6);
	zephir_check_call_status();
	if (ZEPHIR_IS_TRUE_IDENTICAL(&result)) {
		ZEPHIR_CALL_FUNCTION(&_7$$3, "imagesx", NULL, 0, &image);
		zephir_check_call_status();
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_1, 921, &_7$$3);
		ZEPHIR_CALL_FUNCTION(&_8$$3, "imagesy", NULL, 0, &image);
		zephir_check_call_status();
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_2, 922, &_8$$3);
	}
	ZEPHIR_MM_RESTORE();
}

/**
 * @throws Exception
 */
PHP_METHOD(Phalcon_Image_Adapter_Gd, processText)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long opacity, red, green, blue, size, ZEPHIR_LAST_CALL_STATUS, angle = 0, bottomLeftX = 0, bottomLeftY = 0, topRightX = 0, topRightY = 0, _1, _2;
	zval text_zv, *offsetX = NULL, offsetX_sub, *offsetY = NULL, offsetY_sub, *opacity_param = NULL, *red_param = NULL, *green_param = NULL, *blue_param = NULL, *size_param = NULL, fontFile_zv, color, height, image, space, width, _0, _3, _4, _5$$3, _6$$3, _12$$3, _13$$3, _20$$3, _21$$3, _7$$4, _8$$5, _9$$5, _10$$5, _11$$5, _14$$6, _15$$6, _16$$6, _17$$7, _18$$7, _19$$7, _22$$8, _23$$8, _30$$8, _31$$8, _32$$8, _24$$9, _25$$9, _26$$9, _27$$10, _28$$10, _29$$10;
	zend_string *text = NULL, *fontFile = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&text_zv);
	ZVAL_UNDEF(&offsetX_sub);
	ZVAL_UNDEF(&offsetY_sub);
	ZVAL_UNDEF(&fontFile_zv);
	ZVAL_UNDEF(&color);
	ZVAL_UNDEF(&height);
	ZVAL_UNDEF(&image);
	ZVAL_UNDEF(&space);
	ZVAL_UNDEF(&width);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_12$$3);
	ZVAL_UNDEF(&_13$$3);
	ZVAL_UNDEF(&_20$$3);
	ZVAL_UNDEF(&_21$$3);
	ZVAL_UNDEF(&_7$$4);
	ZVAL_UNDEF(&_8$$5);
	ZVAL_UNDEF(&_9$$5);
	ZVAL_UNDEF(&_10$$5);
	ZVAL_UNDEF(&_11$$5);
	ZVAL_UNDEF(&_14$$6);
	ZVAL_UNDEF(&_15$$6);
	ZVAL_UNDEF(&_16$$6);
	ZVAL_UNDEF(&_17$$7);
	ZVAL_UNDEF(&_18$$7);
	ZVAL_UNDEF(&_19$$7);
	ZVAL_UNDEF(&_22$$8);
	ZVAL_UNDEF(&_23$$8);
	ZVAL_UNDEF(&_30$$8);
	ZVAL_UNDEF(&_31$$8);
	ZVAL_UNDEF(&_32$$8);
	ZVAL_UNDEF(&_24$$9);
	ZVAL_UNDEF(&_25$$9);
	ZVAL_UNDEF(&_26$$9);
	ZVAL_UNDEF(&_27$$10);
	ZVAL_UNDEF(&_28$$10);
	ZVAL_UNDEF(&_29$$10);
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
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 924, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&image, &_0);
	bottomLeftX = 0;
	bottomLeftY = 0;
	topRightX = 0;
	topRightY = 0;
	_1 = zephir_get_intval(offsetX);
	ZEPHIR_INIT_NVAR(offsetX);
	ZVAL_LONG(offsetX, _1);
	_2 = zephir_get_intval(offsetY);
	ZEPHIR_INIT_NVAR(offsetY);
	ZVAL_LONG(offsetY, _2);
	ZEPHIR_INIT_VAR(&_3);
	ZVAL_DOUBLE(&_0, ((zephir_safe_div_long_long((opacity * 127), 100)) - (double) (127)));
	ZEPHIR_CALL_FUNCTION(&_4, "abs", NULL, 0, &_0);
	zephir_check_call_status();
	zephir_round(&_3, &_4, NULL, NULL);
	opacity = zephir_get_intval(&_3);
	ZEPHIR_INIT_VAR(&width);
	if (1 != ZEPHIR_IS_EMPTY(&fontFile_zv)) {
		ZVAL_LONG(&_5$$3, size);
		ZVAL_LONG(&_6$$3, 0);
		ZEPHIR_CALL_FUNCTION(&space, "imagettfbbox", NULL, 0, &_5$$3, &_6$$3, &fontFile_zv, &text_zv);
		zephir_check_call_status();
		if (ZEPHIR_IS_FALSE_IDENTICAL(&space)) {
			ZEPHIR_INIT_VAR(&_7$$4);
			object_init_ex(&_7$$4, phalcon_image_exceptions_textrenderingfailed_ce);
			ZEPHIR_CALL_METHOD(NULL, &_7$$4, "__construct", NULL, 0);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_7$$4, "phalcon/Image/Adapter/Gd.zep", 791);
			ZEPHIR_MM_RESTORE();
			return;
		}
		if (1 == zephir_array_isset_value_long(&space, 0)) {
			zephir_memory_observe(&_8$$5);
			zephir_array_fetch_long(&_8$$5, &space, 0, PH_NOISY, "phalcon/Image/Adapter/Gd.zep", 795);
			bottomLeftX = zephir_get_intval(&_8$$5);
			zephir_memory_observe(&_9$$5);
			zephir_array_fetch_long(&_9$$5, &space, 1, PH_NOISY, "phalcon/Image/Adapter/Gd.zep", 796);
			bottomLeftY = zephir_get_intval(&_9$$5);
			zephir_memory_observe(&_10$$5);
			zephir_array_fetch_long(&_10$$5, &space, 4, PH_NOISY, "phalcon/Image/Adapter/Gd.zep", 797);
			topRightX = zephir_get_intval(&_10$$5);
			zephir_memory_observe(&_11$$5);
			zephir_array_fetch_long(&_11$$5, &space, 5, PH_NOISY, "phalcon/Image/Adapter/Gd.zep", 798);
			topRightY = zephir_get_intval(&_11$$5);
		}
		ZVAL_LONG(&_5$$3, (topRightX - bottomLeftX));
		ZEPHIR_CALL_FUNCTION(&_12$$3, "abs", NULL, 0, &_5$$3);
		zephir_check_call_status();
		ZVAL_LONG(&width, (zephir_get_numberval(&_12$$3) + 10));
		ZVAL_LONG(&_5$$3, (topRightY - bottomLeftY));
		ZEPHIR_CALL_FUNCTION(&_13$$3, "abs", NULL, 0, &_5$$3);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&height);
		ZVAL_LONG(&height, (zephir_get_numberval(&_13$$3) + 10));
		if (ZEPHIR_LT_LONG(offsetX, 0)) {
			zephir_read_property_cached(&_14$$6, this_ptr, _zephir_prop_1, 921, PH_NOISY_CC | PH_READONLY);
			ZEPHIR_INIT_VAR(&_15$$6);
			zephir_sub_function(&_15$$6, &_14$$6, &width);
			ZEPHIR_INIT_VAR(&_16$$6);
			zephir_add_function(&_16$$6, &_15$$6, offsetX);
			ZEPHIR_CPY_WRT(offsetX, &_16$$6);
		}
		if (ZEPHIR_LT_LONG(offsetY, 0)) {
			zephir_read_property_cached(&_17$$7, this_ptr, _zephir_prop_2, 922, PH_NOISY_CC | PH_READONLY);
			ZEPHIR_INIT_VAR(&_18$$7);
			zephir_sub_function(&_18$$7, &_17$$7, &height);
			ZEPHIR_INIT_VAR(&_19$$7);
			zephir_add_function(&_19$$7, &_18$$7, offsetY);
			ZEPHIR_CPY_WRT(offsetY, &_19$$7);
		}
		ZVAL_LONG(&_5$$3, red);
		ZVAL_LONG(&_6$$3, green);
		ZVAL_LONG(&_20$$3, blue);
		ZVAL_LONG(&_21$$3, opacity);
		ZEPHIR_CALL_FUNCTION(&color, "imagecolorallocatealpha", NULL, 0, &image, &_5$$3, &_6$$3, &_20$$3, &_21$$3);
		zephir_check_call_status();
		angle = 0;
		ZVAL_LONG(&_5$$3, size);
		ZVAL_LONG(&_6$$3, angle);
		ZEPHIR_CALL_FUNCTION(NULL, "imagettftext", NULL, 0, &image, &_5$$3, &_6$$3, offsetX, offsetY, &color, &fontFile_zv, &text_zv);
		zephir_check_call_status();
	} else {
		ZVAL_LONG(&_22$$8, size);
		ZEPHIR_CALL_FUNCTION(&_23$$8, "imagefontwidth", NULL, 0, &_22$$8);
		zephir_check_call_status();
		ZVAL_LONG(&width, (zephir_get_numberval(&_23$$8) * zephir_fast_strlen_ev(&text_zv)));
		ZVAL_LONG(&_22$$8, size);
		ZEPHIR_CALL_FUNCTION(&height, "imagefontheight", NULL, 0, &_22$$8);
		zephir_check_call_status();
		if (ZEPHIR_LT_LONG(offsetX, 0)) {
			zephir_read_property_cached(&_24$$9, this_ptr, _zephir_prop_1, 921, PH_NOISY_CC | PH_READONLY);
			ZEPHIR_INIT_VAR(&_25$$9);
			zephir_sub_function(&_25$$9, &_24$$9, &width);
			ZEPHIR_INIT_VAR(&_26$$9);
			zephir_add_function(&_26$$9, &_25$$9, offsetX);
			ZEPHIR_CPY_WRT(offsetX, &_26$$9);
		}
		if (ZEPHIR_LT_LONG(offsetY, 0)) {
			zephir_read_property_cached(&_27$$10, this_ptr, _zephir_prop_2, 922, PH_NOISY_CC | PH_READONLY);
			ZEPHIR_INIT_VAR(&_28$$10);
			zephir_sub_function(&_28$$10, &_27$$10, &height);
			ZEPHIR_INIT_VAR(&_29$$10);
			zephir_add_function(&_29$$10, &_28$$10, offsetY);
			ZEPHIR_CPY_WRT(offsetY, &_29$$10);
		}
		ZVAL_LONG(&_22$$8, red);
		ZVAL_LONG(&_30$$8, green);
		ZVAL_LONG(&_31$$8, blue);
		ZVAL_LONG(&_32$$8, opacity);
		ZEPHIR_CALL_FUNCTION(&color, "imagecolorallocatealpha", NULL, 0, &image, &_22$$8, &_30$$8, &_31$$8, &_32$$8);
		zephir_check_call_status();
		ZVAL_LONG(&_22$$8, size);
		ZEPHIR_CALL_FUNCTION(NULL, "imagestring", NULL, 0, &image, &_22$$8, offsetX, offsetY, &text_zv, &color);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();
}

PHP_METHOD(Phalcon_Image_Adapter_Gd, processWatermark)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long offsetX, offsetY, opacity, ZEPHIR_LAST_CALL_STATUS, height = 0, width = 0;
	zval *watermark, watermark_sub, *offsetX_param = NULL, *offsetY_param = NULL, *opacity_param = NULL, __$true, color, image, overlay, _0, _1, _2, _3, _10, _11, _12, _13, _14, _4$$3, _5$$3, _6$$3, _7$$3, _8$$3, _9$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&watermark_sub);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&color);
	ZVAL_UNDEF(&image);
	ZVAL_UNDEF(&overlay);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_11);
	ZVAL_UNDEF(&_12);
	ZVAL_UNDEF(&_13);
	ZVAL_UNDEF(&_14);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_7$$3);
	ZVAL_UNDEF(&_8$$3);
	ZVAL_UNDEF(&_9$$3);
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
	ZEPHIR_CALL_METHOD(&_0, watermark, "render", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&overlay, "imagecreatefromstring", NULL, 0, &_0);
	zephir_check_call_status();
	zephir_read_property_cached(&_1, this_ptr, _zephir_prop_0, 924, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&image, &_1);
	ZEPHIR_CALL_FUNCTION(NULL, "imagesavealpha", NULL, 0, &overlay, &__$true);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&_2, "imagesx", NULL, 0, &overlay);
	zephir_check_call_status();
	width = zephir_get_intval(&_2);
	ZEPHIR_CALL_FUNCTION(&_3, "imagesy", NULL, 0, &overlay);
	zephir_check_call_status();
	height = zephir_get_intval(&_3);
	if (opacity < 100) {
		ZEPHIR_INIT_VAR(&_4$$3);
		ZVAL_DOUBLE(&_5$$3, ((zephir_safe_div_long_long((opacity * 127), 100)) - (double) (127)));
		ZEPHIR_CALL_FUNCTION(&_6$$3, "abs", NULL, 0, &_5$$3);
		zephir_check_call_status();
		zephir_round(&_4$$3, &_6$$3, NULL, NULL);
		opacity = zephir_get_intval(&_4$$3);
		ZVAL_LONG(&_5$$3, 127);
		ZVAL_LONG(&_7$$3, 127);
		ZVAL_LONG(&_8$$3, 127);
		ZVAL_LONG(&_9$$3, opacity);
		ZEPHIR_CALL_FUNCTION(&color, "imagecolorallocatealpha", NULL, 0, &overlay, &_5$$3, &_7$$3, &_8$$3, &_9$$3);
		zephir_check_call_status();
		ZVAL_LONG(&_5$$3, 3);
		ZEPHIR_CALL_FUNCTION(NULL, "imagelayereffect", NULL, 0, &overlay, &_5$$3);
		zephir_check_call_status();
		ZVAL_LONG(&_5$$3, 0);
		ZVAL_LONG(&_7$$3, 0);
		ZVAL_LONG(&_8$$3, width);
		ZVAL_LONG(&_9$$3, height);
		ZEPHIR_CALL_FUNCTION(NULL, "imagefilledrectangle", NULL, 0, &overlay, &_5$$3, &_7$$3, &_8$$3, &_9$$3, &color);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_FUNCTION(NULL, "imagealphablending", NULL, 0, &image, &__$true);
	zephir_check_call_status();
	ZVAL_LONG(&_1, offsetX);
	ZVAL_LONG(&_10, offsetY);
	ZVAL_LONG(&_11, 0);
	ZVAL_LONG(&_12, 0);
	ZVAL_LONG(&_13, width);
	ZVAL_LONG(&_14, height);
	ZEPHIR_CALL_FUNCTION(NULL, "imagecopy", NULL, 0, &image, &overlay, &_1, &_10, &_11, &_12, &_13, &_14);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
}

/**
 * Checks the installed version of GD
 *
 * @throws Exception
 */
PHP_METHOD(Phalcon_Image_Adapter_Gd, check)
{
	zval version, _0, _1, _2, _3$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&version);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3$$3);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	ZEPHIR_CALL_METHOD(&version, this_ptr, "getversion", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "2.0.1");
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, ">=");
	ZEPHIR_CALL_FUNCTION(&_2, "version_compare", NULL, 0, &version, &_0, &_1);
	zephir_check_call_status();
	if (!ZEPHIR_IS_TRUE_IDENTICAL(&_2)) {
		ZEPHIR_INIT_VAR(&_3$$3);
		object_init_ex(&_3$$3, phalcon_image_exceptions_versionmismatch_ce);
		ZEPHIR_CALL_METHOD(NULL, &_3$$3, "__construct", NULL, 0, &version);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_3$$3, "phalcon/Image/Adapter/Gd.zep", 932);
		ZEPHIR_MM_RESTORE();
		return;
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
PHP_METHOD(Phalcon_Image_Adapter_Gd, phpFclose)
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
PHP_METHOD(Phalcon_Image_Adapter_Gd, phpFgetCsv)
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
	ZEPHIR_RETURN_CALL_FUNCTION("fgetcsv", NULL, 160, stream, &_0, &separator_zv, enclosure, escape);
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
PHP_METHOD(Phalcon_Image_Adapter_Gd, phpFileExists)
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
PHP_METHOD(Phalcon_Image_Adapter_Gd, phpFileGetContents)
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
		ZEPHIR_RETURN_CALL_FUNCTION("file_get_contents", NULL, 161, &filename_zv, &_0$$3, context, &_1$$3);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZVAL_BOOL(&_2, (useIncludePath ? 1 : 0));
	ZVAL_LONG(&_3, offset);
	ZVAL_LONG(&_4, length);
	ZEPHIR_RETURN_CALL_FUNCTION("file_get_contents", NULL, 161, &filename_zv, &_2, context, &_3, &_4);
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
PHP_METHOD(Phalcon_Image_Adapter_Gd, phpFilePutContents)
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
	ZEPHIR_RETURN_CALL_FUNCTION("file_put_contents", NULL, 162, &filename_zv, data, &_0, context);
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
PHP_METHOD(Phalcon_Image_Adapter_Gd, phpFopen)
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
	ZEPHIR_RETURN_CALL_FUNCTION("fopen", NULL, 163, &filename_zv, &mode_zv, &_0, context);
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
PHP_METHOD(Phalcon_Image_Adapter_Gd, phpFwrite)
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
	ZEPHIR_RETURN_CALL_FUNCTION("fwrite", NULL, 164, handle, &data_zv, &_0);
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
PHP_METHOD(Phalcon_Image_Adapter_Gd, phpIsWritable)
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
	ZEPHIR_RETURN_CALL_FUNCTION("is_writable", NULL, 165, &filename_zv);
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
PHP_METHOD(Phalcon_Image_Adapter_Gd, phpUnlink)
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
	ZEPHIR_RETURN_CALL_FUNCTION("unlink", NULL, 166, &filename_zv, context);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Find out whether an extension is loaded
 *
 * @param string $name
 *
 * @return bool
 *
 * @link https://php.net/manual/en/function.extension-loaded.php
 */
PHP_METHOD(Phalcon_Image_Adapter_Gd, phpExtensionLoaded)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval name_zv;
	zend_string *name = NULL;

	ZVAL_UNDEF(&name_zv);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(name)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&name_zv);
	ZVAL_STR_COPY(&name_zv, name);
	ZEPHIR_RETURN_CALL_FUNCTION("extension_loaded", NULL, 465, &name_zv);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Return true if the given function has been defined
 *
 * @param string $functionName
 *
 * @return bool
 *
 * @link https://php.net/manual/en/function.function-exists.php
 */
PHP_METHOD(Phalcon_Image_Adapter_Gd, phpFunctionExists)
{
	zval functionName_zv;
	zend_string *functionName = NULL;

	ZVAL_UNDEF(&functionName_zv);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(functionName)
	ZEND_PARSE_PARAMETERS_END();
	ZVAL_STR(&functionName_zv, functionName);
	RETURN_BOOL((zephir_function_exists(&functionName_zv) == SUCCESS));
}

