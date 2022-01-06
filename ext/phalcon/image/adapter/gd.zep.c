
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
#include "kernel/fcall.h"
#include "kernel/file.h"
#include "kernel/memory.h"
#include "kernel/array.h"
#include "kernel/exception.h"
#include "kernel/concat.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/string.h"
#include "kernel/math.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
ZEPHIR_INIT_CLASS(Phalcon_Image_Adapter_Gd)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Image\\Adapter, Gd, phalcon, image_adapter_gd, phalcon_image_adapter_abstractadapter_ce, phalcon_image_adapter_gd_method_entry, 0);

	/**
	 * @var bool
	 */
	zend_declare_property_bool(phalcon_image_adapter_gd_ce, SL("checked"), 0, ZEND_ACC_PROTECTED|ZEND_ACC_STATIC);
	return SUCCESS;
}

PHP_METHOD(Phalcon_Image_Adapter_Gd, __construct)
{
	zend_bool _25$$13;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long width, height, ZEPHIR_LAST_CALL_STATUS;
	zval *file_param = NULL, *width_param = NULL, *height_param = NULL, __$true, imageinfo, _0, _1, _2$$4, _3$$4, _4$$4, _9$$4, _24$$4, _5$$5, _6$$5, _7$$5, _8$$5, _10$$6, _11$$6, _12$$7, _13$$7, _14$$8, _15$$8, _16$$9, _17$$9, _18$$10, _19$$10, _20$$11, _21$$12, _22$$12, _23$$12, _29$$13, _30$$13, _31$$13, _32$$13, _33$$13, _34$$13, _26$$14, _27$$14, _28$$14;
	zval file;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&file);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&imageinfo);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_9$$4);
	ZVAL_UNDEF(&_24$$4);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&_6$$5);
	ZVAL_UNDEF(&_7$$5);
	ZVAL_UNDEF(&_8$$5);
	ZVAL_UNDEF(&_10$$6);
	ZVAL_UNDEF(&_11$$6);
	ZVAL_UNDEF(&_12$$7);
	ZVAL_UNDEF(&_13$$7);
	ZVAL_UNDEF(&_14$$8);
	ZVAL_UNDEF(&_15$$8);
	ZVAL_UNDEF(&_16$$9);
	ZVAL_UNDEF(&_17$$9);
	ZVAL_UNDEF(&_18$$10);
	ZVAL_UNDEF(&_19$$10);
	ZVAL_UNDEF(&_20$$11);
	ZVAL_UNDEF(&_21$$12);
	ZVAL_UNDEF(&_22$$12);
	ZVAL_UNDEF(&_23$$12);
	ZVAL_UNDEF(&_29$$13);
	ZVAL_UNDEF(&_30$$13);
	ZVAL_UNDEF(&_31$$13);
	ZVAL_UNDEF(&_32$$13);
	ZVAL_UNDEF(&_33$$13);
	ZVAL_UNDEF(&_34$$13);
	ZVAL_UNDEF(&_26$$14);
	ZVAL_UNDEF(&_27$$14);
	ZVAL_UNDEF(&_28$$14);
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
	if (UNEXPECTED(Z_TYPE_P(file_param) != IS_STRING && Z_TYPE_P(file_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'file' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(file_param) == IS_STRING)) {
		zephir_get_strval(&file, file_param);
	} else {
		ZEPHIR_INIT_VAR(&file);
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


	zephir_read_static_property_ce(&_0, phalcon_image_adapter_gd_ce, SL("checked"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_is_true(&_0))) {
		ZEPHIR_CALL_SELF(NULL, "check", NULL, 0);
		zephir_check_call_status();
	}
	zephir_update_property_zval(this_ptr, ZEND_STRL("file"), &file);
	zephir_read_property(&_1, this_ptr, ZEND_STRL("file"), PH_NOISY_CC | PH_READONLY);
	if ((zephir_file_exists(&_1) == SUCCESS)) {
		zephir_read_property(&_2$$4, this_ptr, ZEND_STRL("file"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_FUNCTION(&_3$$4, "realpath", NULL, 102, &_2$$4);
		zephir_check_call_status();
		zephir_update_property_zval(this_ptr, ZEND_STRL("realpath"), &_3$$4);
		zephir_read_property(&_4$$4, this_ptr, ZEND_STRL("file"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_FUNCTION(&imageinfo, "getimagesize", NULL, 328, &_4$$4);
		zephir_check_call_status();
		if (zephir_is_true(&imageinfo)) {
			zephir_array_fetch_long(&_5$$5, &imageinfo, 0, PH_NOISY | PH_READONLY, "phalcon/Image/Adapter/Gd.zep", 38);
			zephir_update_property_zval(this_ptr, ZEND_STRL("width"), &_5$$5);
			zephir_array_fetch_long(&_6$$5, &imageinfo, 1, PH_NOISY | PH_READONLY, "phalcon/Image/Adapter/Gd.zep", 39);
			zephir_update_property_zval(this_ptr, ZEND_STRL("height"), &_6$$5);
			zephir_array_fetch_long(&_7$$5, &imageinfo, 2, PH_NOISY | PH_READONLY, "phalcon/Image/Adapter/Gd.zep", 40);
			zephir_update_property_zval(this_ptr, ZEND_STRL("type"), &_7$$5);
			zephir_array_fetch_string(&_8$$5, &imageinfo, SL("mime"), PH_NOISY | PH_READONLY, "phalcon/Image/Adapter/Gd.zep", 41);
			zephir_update_property_zval(this_ptr, ZEND_STRL("mime"), &_8$$5);
		}
		zephir_read_property(&_9$$4, this_ptr, ZEND_STRL("type"), PH_NOISY_CC | PH_READONLY);
		do {
			if (ZEPHIR_IS_LONG(&_9$$4, 1)) {
				zephir_read_property(&_10$$6, this_ptr, ZEND_STRL("file"), PH_NOISY_CC | PH_READONLY);
				ZEPHIR_CALL_FUNCTION(&_11$$6, "imagecreatefromgif", NULL, 435, &_10$$6);
				zephir_check_call_status();
				zephir_update_property_zval(this_ptr, ZEND_STRL("image"), &_11$$6);
				break;
			}
			if (ZEPHIR_IS_LONG(&_9$$4, 2)) {
				zephir_read_property(&_12$$7, this_ptr, ZEND_STRL("file"), PH_NOISY_CC | PH_READONLY);
				ZEPHIR_CALL_FUNCTION(&_13$$7, "imagecreatefromjpeg", NULL, 436, &_12$$7);
				zephir_check_call_status();
				zephir_update_property_zval(this_ptr, ZEND_STRL("image"), &_13$$7);
				break;
			}
			if (ZEPHIR_IS_LONG(&_9$$4, 3)) {
				zephir_read_property(&_14$$8, this_ptr, ZEND_STRL("file"), PH_NOISY_CC | PH_READONLY);
				ZEPHIR_CALL_FUNCTION(&_15$$8, "imagecreatefrompng", NULL, 437, &_14$$8);
				zephir_check_call_status();
				zephir_update_property_zval(this_ptr, ZEND_STRL("image"), &_15$$8);
				break;
			}
			if (ZEPHIR_IS_LONG(&_9$$4, 15)) {
				zephir_read_property(&_16$$9, this_ptr, ZEND_STRL("file"), PH_NOISY_CC | PH_READONLY);
				ZEPHIR_CALL_FUNCTION(&_17$$9, "imagecreatefromwbmp", NULL, 438, &_16$$9);
				zephir_check_call_status();
				zephir_update_property_zval(this_ptr, ZEND_STRL("image"), &_17$$9);
				break;
			}
			if (ZEPHIR_IS_LONG(&_9$$4, 16)) {
				zephir_read_property(&_18$$10, this_ptr, ZEND_STRL("file"), PH_NOISY_CC | PH_READONLY);
				ZEPHIR_CALL_FUNCTION(&_19$$10, "imagecreatefromxbm", NULL, 439, &_18$$10);
				zephir_check_call_status();
				zephir_update_property_zval(this_ptr, ZEND_STRL("image"), &_19$$10);
				break;
			}
			zephir_read_property(&_20$$11, this_ptr, ZEND_STRL("mime"), PH_NOISY_CC | PH_READONLY);
			if (zephir_is_true(&_20$$11)) {
				ZEPHIR_INIT_VAR(&_21$$12);
				object_init_ex(&_21$$12, phalcon_image_exception_ce);
				zephir_read_property(&_22$$12, this_ptr, ZEND_STRL("mime"), PH_NOISY_CC | PH_READONLY);
				ZEPHIR_INIT_VAR(&_23$$12);
				ZEPHIR_CONCAT_SVS(&_23$$12, "Installed GD does not support ", &_22$$12, " images");
				ZEPHIR_CALL_METHOD(NULL, &_21$$12, "__construct", NULL, 31, &_23$$12);
				zephir_check_call_status();
				zephir_throw_exception_debug(&_21$$12, "phalcon/Image/Adapter/Gd.zep", 69);
				ZEPHIR_MM_RESTORE();
				return;
			}
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_image_exception_ce, "Installed GD does not support such images", "phalcon/Image/Adapter/Gd.zep", 74);
			return;
		} while(0);

		zephir_read_property(&_24$$4, this_ptr, ZEND_STRL("image"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_FUNCTION(NULL, "imagesavealpha", NULL, 440, &_24$$4, &__$true);
		zephir_check_call_status();
	} else {
		_25$$13 = !width;
		if (!(_25$$13)) {
			_25$$13 = !height;
		}
		if (UNEXPECTED(_25$$13)) {
			ZEPHIR_INIT_VAR(&_26$$14);
			object_init_ex(&_26$$14, phalcon_image_exception_ce);
			zephir_read_property(&_27$$14, this_ptr, ZEND_STRL("file"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_INIT_VAR(&_28$$14);
			ZEPHIR_CONCAT_SV(&_28$$14, "Failed to create image from file ", &_27$$14);
			ZEPHIR_CALL_METHOD(NULL, &_26$$14, "__construct", NULL, 31, &_28$$14);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_26$$14, "phalcon/Image/Adapter/Gd.zep", 83);
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZVAL_LONG(&_29$$13, width);
		ZVAL_LONG(&_30$$13, height);
		ZEPHIR_CALL_FUNCTION(&_31$$13, "imagecreatetruecolor", NULL, 441, &_29$$13, &_30$$13);
		zephir_check_call_status();
		zephir_update_property_zval(this_ptr, ZEND_STRL("image"), &_31$$13);
		zephir_read_property(&_29$$13, this_ptr, ZEND_STRL("image"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_FUNCTION(NULL, "imagealphablending", NULL, 442, &_29$$13, &__$true);
		zephir_check_call_status();
		zephir_read_property(&_30$$13, this_ptr, ZEND_STRL("image"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_FUNCTION(NULL, "imagesavealpha", NULL, 440, &_30$$13, &__$true);
		zephir_check_call_status();
		zephir_read_property(&_32$$13, this_ptr, ZEND_STRL("file"), PH_NOISY_CC | PH_READONLY);
		zephir_update_property_zval(this_ptr, ZEND_STRL("realpath"), &_32$$13);
		ZEPHIR_INIT_ZVAL_NREF(_33$$13);
		ZVAL_LONG(&_33$$13, width);
		zephir_update_property_zval(this_ptr, ZEND_STRL("width"), &_33$$13);
		ZEPHIR_INIT_ZVAL_NREF(_33$$13);
		ZVAL_LONG(&_33$$13, height);
		zephir_update_property_zval(this_ptr, ZEND_STRL("height"), &_33$$13);
		ZEPHIR_INIT_ZVAL_NREF(_33$$13);
		ZVAL_LONG(&_33$$13, 3);
		zephir_update_property_zval(this_ptr, ZEND_STRL("type"), &_33$$13);
		ZEPHIR_INIT_VAR(&_34$$13);
		ZEPHIR_INIT_NVAR(&_34$$13);
		ZVAL_STRING(&_34$$13, "image/png");
		zephir_update_property_zval(this_ptr, ZEND_STRL("mime"), &_34$$13);
	}
	ZEPHIR_MM_RESTORE();
}

PHP_METHOD(Phalcon_Image_Adapter_Gd, __destruct)
{
	zval image, _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&image);
	ZVAL_UNDEF(&_0);


	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, ZEND_STRL("image"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&image, &_0);
	if (Z_TYPE_P(&image) == IS_RESOURCE) {
		ZEPHIR_CALL_FUNCTION(NULL, "imagedestroy", NULL, 443, &image);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();
}

PHP_METHOD(Phalcon_Image_Adapter_Gd, check)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval __$true, version, _0, _1, _2, _3, _6, _4$$5, _5$$5;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&version);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_4$$5);
	ZVAL_UNDEF(&_5$$5);


	ZEPHIR_MM_GROW();

	zephir_read_static_property_ce(&_0, phalcon_image_adapter_gd_ce, SL("checked"), PH_NOISY_CC | PH_READONLY);
	if (zephir_is_true(&_0)) {
		RETURN_MM_BOOL(1);
	}
	if (UNEXPECTED(!((zephir_function_exists_ex(ZEND_STRL("gd_info")) == SUCCESS)))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_image_exception_ce, "GD is either not installed or not enabled, check your configuration", "phalcon/Image/Adapter/Gd.zep", 121);
		return;
	}
	ZEPHIR_CALL_SELF(&version, "getversion", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "2.0.1");
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, ">=");
	ZEPHIR_CALL_FUNCTION(&_3, "version_compare", NULL, 88, &version, &_1, &_2);
	zephir_check_call_status();
	if (UNEXPECTED(!zephir_is_true(&_3))) {
		ZEPHIR_INIT_VAR(&_4$$5);
		object_init_ex(&_4$$5, phalcon_image_exception_ce);
		ZEPHIR_INIT_VAR(&_5$$5);
		ZEPHIR_CONCAT_SV(&_5$$5, "Phalcon\\Image\\Adapter\\GD requires GD version '2.0.1' or greater, you have ", &version);
		ZEPHIR_CALL_METHOD(NULL, &_4$$5, "__construct", NULL, 31, &_5$$5);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_4$$5, "phalcon/Image/Adapter/Gd.zep", 129);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_update_static_property_ce(phalcon_image_adapter_gd_ce, ZEND_STRL("checked"), &__$true);
	zephir_read_static_property_ce(&_6, phalcon_image_adapter_gd_ce, SL("checked"), PH_NOISY_CC | PH_READONLY);
	RETURN_CTOR(&_6);
}

PHP_METHOD(Phalcon_Image_Adapter_Gd, getVersion)
{
	zval version, info, matches, _0, _1, _2$$5, _3$$5, _4$$5, _5$$5;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&version);
	ZVAL_UNDEF(&info);
	ZVAL_UNDEF(&matches);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2$$5);
	ZVAL_UNDEF(&_3$$5);
	ZVAL_UNDEF(&_4$$5);
	ZVAL_UNDEF(&_5$$5);


	ZEPHIR_MM_GROW();

	if (UNEXPECTED(!((zephir_function_exists_ex(ZEND_STRL("gd_info")) == SUCCESS)))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_image_exception_ce, "GD is either not installed or not enabled, check your configuration", "phalcon/Image/Adapter/Gd.zep", 144);
		return;
	}
	ZEPHIR_INIT_VAR(&version);
	ZVAL_NULL(&version);
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "GD_VERSION");
	ZEPHIR_CALL_FUNCTION(&_1, "defined", NULL, 141, &_0);
	zephir_check_call_status();
	if (zephir_is_true(&_1)) {
		ZEPHIR_INIT_NVAR(&version);
		ZEPHIR_GET_CONSTANT(&version, "GD_VERSION");
	} else {
		ZEPHIR_CALL_FUNCTION(&info, "gd_info", NULL, 444);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&matches);
		ZVAL_NULL(&matches);
		zephir_array_fetch_string(&_2$$5, &info, SL("GD Version"), PH_NOISY | PH_READONLY, "phalcon/Image/Adapter/Gd.zep", 155);
		ZEPHIR_INIT_VAR(&_3$$5);
		ZVAL_STRING(&_3$$5, "/\\d+\\.\\d+(?:\\.\\d+)?/");
		ZEPHIR_INIT_VAR(&_4$$5);
		ZEPHIR_INIT_VAR(&_5$$5);
		ZVAL_STRING(&_5$$5, "/\\d+\\.\\d+(?:\\.\\d+)?/");
		zephir_preg_match(&_4$$5, &_5$$5, &_2$$5, &matches, 0, 0 , 0 );
		if (zephir_is_true(&_4$$5)) {
			ZEPHIR_OBS_NVAR(&version);
			zephir_array_fetch_long(&version, &matches, 0, PH_NOISY, "phalcon/Image/Adapter/Gd.zep", 156);
		}
	}
	RETURN_CCTOR(&version);
}

PHP_METHOD(Phalcon_Image_Adapter_Gd, processBackground)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *r_param = NULL, *g_param = NULL, *b_param = NULL, *opacity_param = NULL, __$true, background, color, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12$$3;
	zend_long r, g, b, opacity, ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&background);
	ZVAL_UNDEF(&color);
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
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_11);
	ZVAL_UNDEF(&_12$$3);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_LONG(r)
		Z_PARAM_LONG(g)
		Z_PARAM_LONG(b)
		Z_PARAM_LONG(opacity)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 4, 0, &r_param, &g_param, &b_param, &opacity_param);
	r = zephir_get_intval(r_param);
	g = zephir_get_intval(g_param);
	b = zephir_get_intval(b_param);
	opacity = zephir_get_intval(opacity_param);


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_DOUBLE(&_1, ((zephir_safe_div_long_long((opacity * 127), 100)) - (double) (127)));
	ZEPHIR_CALL_FUNCTION(&_2, "abs", NULL, 299, &_1);
	zephir_check_call_status();
	zephir_round(&_0, &_2, NULL, NULL);
	opacity = zephir_get_intval(&_0);
	zephir_read_property(&_1, this_ptr, ZEND_STRL("width"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_3, this_ptr, ZEND_STRL("height"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&background, this_ptr, "processcreate", NULL, 0, &_1, &_3);
	zephir_check_call_status();
	ZVAL_LONG(&_4, r);
	ZVAL_LONG(&_5, g);
	ZVAL_LONG(&_6, b);
	ZVAL_LONG(&_7, opacity);
	ZEPHIR_CALL_FUNCTION(&color, "imagecolorallocatealpha", NULL, 445, &background, &_4, &_5, &_6, &_7);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(NULL, "imagealphablending", NULL, 442, &background, &__$true);
	zephir_check_call_status();
	zephir_read_property(&_4, this_ptr, ZEND_STRL("image"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_5, this_ptr, ZEND_STRL("width"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_6, this_ptr, ZEND_STRL("height"), PH_NOISY_CC | PH_READONLY);
	ZVAL_LONG(&_7, 0);
	ZVAL_LONG(&_8, 0);
	ZVAL_LONG(&_9, 0);
	ZVAL_LONG(&_10, 0);
	ZEPHIR_CALL_FUNCTION(&_11, "imagecopy", NULL, 446, &background, &_4, &_7, &_8, &_9, &_10, &_5, &_6);
	zephir_check_call_status();
	if (zephir_is_true(&_11)) {
		zephir_read_property(&_12$$3, this_ptr, ZEND_STRL("image"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_FUNCTION(NULL, "imagedestroy", NULL, 443, &_12$$3);
		zephir_check_call_status();
		zephir_update_property_zval(this_ptr, ZEND_STRL("image"), &background);
	}
	ZEPHIR_MM_RESTORE();
}

PHP_METHOD(Phalcon_Image_Adapter_Gd, processBlur)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_2 = NULL;
	zval *radius_param = NULL, _0$$3, _1$$3;
	zend_long radius, ZEPHIR_LAST_CALL_STATUS, i = 0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$3);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(radius)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &radius_param);
	radius = zephir_get_intval(radius_param);


	i = 0;
	while (1) {
		if (!(i < radius)) {
			break;
		}
		zephir_read_property(&_0$$3, this_ptr, ZEND_STRL("image"), PH_NOISY_CC | PH_READONLY);
		ZVAL_LONG(&_1$$3, 7);
		ZEPHIR_CALL_FUNCTION(NULL, "imagefilter", &_2, 447, &_0$$3, &_1$$3);
		zephir_check_call_status();
		i++;
	}
	ZEPHIR_MM_RESTORE();
}

PHP_METHOD(Phalcon_Image_Adapter_Gd, processCreate)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *width_param = NULL, *height_param = NULL, __$false, __$true, image, _0, _1;
	zend_long width, height, ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$false, 0);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&image);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
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


	ZVAL_LONG(&_0, width);
	ZVAL_LONG(&_1, height);
	ZEPHIR_CALL_FUNCTION(&image, "imagecreatetruecolor", NULL, 441, &_0, &_1);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(NULL, "imagealphablending", NULL, 442, &image, &__$false);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(NULL, "imagesavealpha", NULL, 440, &image, &__$true);
	zephir_check_call_status();
	RETURN_CCTOR(&image);
}

PHP_METHOD(Phalcon_Image_Adapter_Gd, processCrop)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *width_param = NULL, *height_param = NULL, *offsetX_param = NULL, *offsetY_param = NULL, image, rect, _0, _1, _2, _3, _4;
	zend_long width, height, offsetX, offsetY, ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&image);
	ZVAL_UNDEF(&rect);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
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
	zephir_read_property(&_1, this_ptr, ZEND_STRL("image"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_FUNCTION(&image, "imagecrop", NULL, 448, &_1, &rect);
	zephir_check_call_status();
	zephir_read_property(&_2, this_ptr, ZEND_STRL("image"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_FUNCTION(NULL, "imagedestroy", NULL, 443, &_2);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, ZEND_STRL("image"), &image);
	ZEPHIR_CALL_FUNCTION(&_3, "imagesx", NULL, 449, &image);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, ZEND_STRL("width"), &_3);
	ZEPHIR_CALL_FUNCTION(&_4, "imagesy", NULL, 450, &image);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, ZEND_STRL("height"), &_4);
	ZEPHIR_MM_RESTORE();
}

PHP_METHOD(Phalcon_Image_Adapter_Gd, processFlip)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *direction_param = NULL, _0$$3, _1$$3, _2$$4, _3$$4;
	zend_long direction, ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_3$$4);
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
		zephir_read_property(&_0$$3, this_ptr, ZEND_STRL("image"), PH_NOISY_CC | PH_READONLY);
		ZVAL_LONG(&_1$$3, 1);
		ZEPHIR_CALL_FUNCTION(NULL, "imageflip", NULL, 451, &_0$$3, &_1$$3);
		zephir_check_call_status();
	} else {
		zephir_read_property(&_2$$4, this_ptr, ZEND_STRL("image"), PH_NOISY_CC | PH_READONLY);
		ZVAL_LONG(&_3$$4, 2);
		ZEPHIR_CALL_FUNCTION(NULL, "imageflip", NULL, 451, &_2$$4, &_3$$4);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();
}

PHP_METHOD(Phalcon_Image_Adapter_Gd, processMask)
{
	zend_bool _9;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_23 = NULL, *_24 = NULL, *_29 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS, mask_width = 0, mask_height = 0, x = 0, y = 0, alpha = 0;
	zval *mask, mask_sub, __$true, maskImage, newimage, tempImage, color, index, r, g, b, _0, _1, _2, _3, _4, _5, _6, _7, _8, _10$$3, _11$$3, _12$$3, _13$$3, _14$$3, _15$$3, _16$$3, _17$$3, _18$$3, _19$$3, _20$$4, _21$$5, _22$$5, _27$$5, _28$$5, _25$$6, _26$$6;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&mask_sub);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&maskImage);
	ZVAL_UNDEF(&newimage);
	ZVAL_UNDEF(&tempImage);
	ZVAL_UNDEF(&color);
	ZVAL_UNDEF(&index);
	ZVAL_UNDEF(&r);
	ZVAL_UNDEF(&g);
	ZVAL_UNDEF(&b);
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
	ZVAL_UNDEF(&_18$$3);
	ZVAL_UNDEF(&_19$$3);
	ZVAL_UNDEF(&_20$$4);
	ZVAL_UNDEF(&_21$$5);
	ZVAL_UNDEF(&_22$$5);
	ZVAL_UNDEF(&_27$$5);
	ZVAL_UNDEF(&_28$$5);
	ZVAL_UNDEF(&_25$$6);
	ZVAL_UNDEF(&_26$$6);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(mask, phalcon_image_adapter_adapterinterface_ce)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &mask);


	ZEPHIR_CALL_METHOD(&_0, mask, "render", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&maskImage, "imagecreatefromstring", NULL, 452, &_0);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&_1, "imagesx", NULL, 449, &maskImage);
	zephir_check_call_status();
	mask_width = zephir_get_intval(&_1);
	ZEPHIR_CALL_FUNCTION(&_2, "imagesy", NULL, 450, &maskImage);
	zephir_check_call_status();
	mask_height = zephir_get_intval(&_2);
	alpha = 127;
	ZEPHIR_CALL_FUNCTION(NULL, "imagesavealpha", NULL, 440, &maskImage, &__$true);
	zephir_check_call_status();
	zephir_read_property(&_3, this_ptr, ZEND_STRL("width"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_4, this_ptr, ZEND_STRL("height"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&newimage, this_ptr, "processcreate", NULL, 0, &_3, &_4);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(NULL, "imagesavealpha", NULL, 440, &newimage, &__$true);
	zephir_check_call_status();
	ZVAL_LONG(&_5, 0);
	ZVAL_LONG(&_6, 0);
	ZVAL_LONG(&_7, 0);
	ZVAL_LONG(&_8, alpha);
	ZEPHIR_CALL_FUNCTION(&color, "imagecolorallocatealpha", NULL, 445, &newimage, &_5, &_6, &_7, &_8);
	zephir_check_call_status();
	ZVAL_LONG(&_5, 0);
	ZVAL_LONG(&_6, 0);
	ZEPHIR_CALL_FUNCTION(NULL, "imagefill", NULL, 453, &newimage, &_5, &_6, &color);
	zephir_check_call_status();
	zephir_read_property(&_5, this_ptr, ZEND_STRL("width"), PH_NOISY_CC | PH_READONLY);
	_9 = !ZEPHIR_IS_LONG(&_5, mask_width);
	if (!(_9)) {
		zephir_read_property(&_6, this_ptr, ZEND_STRL("height"), PH_NOISY_CC | PH_READONLY);
		_9 = !ZEPHIR_IS_LONG(&_6, mask_height);
	}
	if (_9) {
		zephir_read_property(&_10$$3, this_ptr, ZEND_STRL("width"), PH_NOISY_CC | PH_READONLY);
		zephir_read_property(&_11$$3, this_ptr, ZEND_STRL("height"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_FUNCTION(&tempImage, "imagecreatetruecolor", NULL, 441, &_10$$3, &_11$$3);
		zephir_check_call_status();
		zephir_read_property(&_12$$3, this_ptr, ZEND_STRL("width"), PH_NOISY_CC | PH_READONLY);
		zephir_read_property(&_13$$3, this_ptr, ZEND_STRL("height"), PH_NOISY_CC | PH_READONLY);
		ZVAL_LONG(&_14$$3, 0);
		ZVAL_LONG(&_15$$3, 0);
		ZVAL_LONG(&_16$$3, 0);
		ZVAL_LONG(&_17$$3, 0);
		ZVAL_LONG(&_18$$3, mask_width);
		ZVAL_LONG(&_19$$3, mask_height);
		ZEPHIR_CALL_FUNCTION(NULL, "imagecopyresampled", NULL, 454, &tempImage, &maskImage, &_14$$3, &_15$$3, &_16$$3, &_17$$3, &_12$$3, &_13$$3, &_18$$3, &_19$$3);
		zephir_check_call_status();
		ZEPHIR_CALL_FUNCTION(NULL, "imagedestroy", NULL, 443, &maskImage);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(&maskImage, &tempImage);
	}
	x = 0;
	while (1) {
		zephir_read_property(&_7, this_ptr, ZEND_STRL("width"), PH_NOISY_CC | PH_READONLY);
		if (!(ZEPHIR_GT_LONG(&_7, x))) {
			break;
		}
		y = 0;
		while (1) {
			zephir_read_property(&_20$$4, this_ptr, ZEND_STRL("height"), PH_NOISY_CC | PH_READONLY);
			if (!(ZEPHIR_GT_LONG(&_20$$4, y))) {
				break;
			}
			ZVAL_LONG(&_21$$5, x);
			ZVAL_LONG(&_22$$5, y);
			ZEPHIR_CALL_FUNCTION(&index, "imagecolorat", &_23, 455, &maskImage, &_21$$5, &_22$$5);
			zephir_check_call_status();
			ZEPHIR_CALL_FUNCTION(&color, "imagecolorsforindex", &_24, 456, &maskImage, &index);
			zephir_check_call_status();
			if (zephir_array_isset_string(&color, SL("red"))) {
				zephir_array_fetch_string(&_25$$6, &color, SL("red"), PH_NOISY | PH_READONLY, "phalcon/Image/Adapter/Gd.zep", 291);
				ZVAL_DOUBLE(&_26$$6, zephir_safe_div_zval_long(&_25$$6, 2));
				alpha = (127 - zephir_get_intval(&_26$$6));
			}
			zephir_read_property(&_21$$5, this_ptr, ZEND_STRL("image"), PH_NOISY_CC | PH_READONLY);
			ZVAL_LONG(&_22$$5, x);
			ZVAL_LONG(&_27$$5, y);
			ZEPHIR_CALL_FUNCTION(&index, "imagecolorat", &_23, 455, &_21$$5, &_22$$5, &_27$$5);
			zephir_check_call_status();
			zephir_read_property(&_22$$5, this_ptr, ZEND_STRL("image"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_CALL_FUNCTION(&color, "imagecolorsforindex", &_24, 456, &_22$$5, &index);
			zephir_check_call_status();
			ZEPHIR_OBS_NVAR(&r);
			zephir_array_fetch_string(&r, &color, SL("red"), PH_NOISY, "phalcon/Image/Adapter/Gd.zep", 296);
			ZEPHIR_OBS_NVAR(&g);
			zephir_array_fetch_string(&g, &color, SL("green"), PH_NOISY, "phalcon/Image/Adapter/Gd.zep", 297);
			ZEPHIR_OBS_NVAR(&b);
			zephir_array_fetch_string(&b, &color, SL("blue"), PH_NOISY, "phalcon/Image/Adapter/Gd.zep", 298);
			ZVAL_LONG(&_27$$5, alpha);
			ZEPHIR_CALL_FUNCTION(&color, "imagecolorallocatealpha", NULL, 445, &newimage, &r, &g, &b, &_27$$5);
			zephir_check_call_status();
			ZVAL_LONG(&_27$$5, x);
			ZVAL_LONG(&_28$$5, y);
			ZEPHIR_CALL_FUNCTION(NULL, "imagesetpixel", &_29, 457, &newimage, &_27$$5, &_28$$5, &color);
			zephir_check_call_status();
			y++;
		}
		x++;
	}
	zephir_read_property(&_8, this_ptr, ZEND_STRL("image"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_FUNCTION(NULL, "imagedestroy", NULL, 443, &_8);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(NULL, "imagedestroy", NULL, 443, &maskImage);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, ZEND_STRL("image"), &newimage);
	ZEPHIR_MM_RESTORE();
}

PHP_METHOD(Phalcon_Image_Adapter_Gd, processPixelate)
{
	zend_bool _3$$4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_8 = NULL, *_12 = NULL;
	zval *amount_param = NULL, color, _0, _1$$3, _2$$4, _4$$4, _5$$4, _6$$4, _7$$4, _9$$4, _10$$4, _11$$4;
	zend_long amount, ZEPHIR_LAST_CALL_STATUS, x = 0, y = 0, x1 = 0, y1 = 0, x2 = 0, y2 = 0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&color);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_7$$4);
	ZVAL_UNDEF(&_9$$4);
	ZVAL_UNDEF(&_10$$4);
	ZVAL_UNDEF(&_11$$4);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(amount)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &amount_param);
	amount = zephir_get_intval(amount_param);


	x = 0;
	while (1) {
		zephir_read_property(&_0, this_ptr, ZEND_STRL("width"), PH_NOISY_CC | PH_READONLY);
		if (!(ZEPHIR_GT_LONG(&_0, x))) {
			break;
		}
		y = 0;
		while (1) {
			zephir_read_property(&_1$$3, this_ptr, ZEND_STRL("height"), PH_NOISY_CC | PH_READONLY);
			if (!(ZEPHIR_GT_LONG(&_1$$3, y))) {
				break;
			}
			x1 = (x + zephir_safe_div_long_long(amount, 2));
			y1 = (y + zephir_safe_div_long_long(amount, 2));
			zephir_read_property(&_2$$4, this_ptr, ZEND_STRL("width"), PH_NOISY_CC | PH_READONLY);
			_3$$4 = ZEPHIR_LE_LONG(&_2$$4, x1);
			if (!(_3$$4)) {
				zephir_read_property(&_4$$4, this_ptr, ZEND_STRL("height"), PH_NOISY_CC | PH_READONLY);
				_3$$4 = ZEPHIR_LE_LONG(&_4$$4, y1);
			}
			if (_3$$4) {
				break;
			}
			zephir_read_property(&_5$$4, this_ptr, ZEND_STRL("image"), PH_NOISY_CC | PH_READONLY);
			ZVAL_LONG(&_6$$4, x1);
			ZVAL_LONG(&_7$$4, y1);
			ZEPHIR_CALL_FUNCTION(&color, "imagecolorat", &_8, 455, &_5$$4, &_6$$4, &_7$$4);
			zephir_check_call_status();
			x2 = (x + amount);
			y2 = (y + amount);
			zephir_read_property(&_6$$4, this_ptr, ZEND_STRL("image"), PH_NOISY_CC | PH_READONLY);
			ZVAL_LONG(&_7$$4, x);
			ZVAL_LONG(&_9$$4, y);
			ZVAL_LONG(&_10$$4, x2);
			ZVAL_LONG(&_11$$4, y2);
			ZEPHIR_CALL_FUNCTION(NULL, "imagefilledrectangle", &_12, 458, &_6$$4, &_7$$4, &_9$$4, &_10$$4, &_11$$4, &color);
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
	zephir_fcall_cache_entry *_25 = NULL;
	zend_bool fadeIn;
	zval *height_param = NULL, *opacity_param = NULL, *fadeIn_param = NULL, reflection, line, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _27, _28, _11$$5, _12$$5, _17$$5, _18$$5, _19$$5, _20$$5, _21$$5, _22$$5, _23$$5, _24$$5, _26$$5, _13$$6, _14$$6, _15$$7, _16$$7;
	zend_long height, opacity, ZEPHIR_LAST_CALL_STATUS, stepping = 0, offset = 0, src_y = 0, dst_y = 0, dst_opacity = 0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&reflection);
	ZVAL_UNDEF(&line);
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
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_27);
	ZVAL_UNDEF(&_28);
	ZVAL_UNDEF(&_11$$5);
	ZVAL_UNDEF(&_12$$5);
	ZVAL_UNDEF(&_17$$5);
	ZVAL_UNDEF(&_18$$5);
	ZVAL_UNDEF(&_19$$5);
	ZVAL_UNDEF(&_20$$5);
	ZVAL_UNDEF(&_21$$5);
	ZVAL_UNDEF(&_22$$5);
	ZVAL_UNDEF(&_23$$5);
	ZVAL_UNDEF(&_24$$5);
	ZVAL_UNDEF(&_26$$5);
	ZVAL_UNDEF(&_13$$6);
	ZVAL_UNDEF(&_14$$6);
	ZVAL_UNDEF(&_15$$7);
	ZVAL_UNDEF(&_16$$7);
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


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_DOUBLE(&_1, ((zephir_safe_div_long_long((opacity * 127), 100)) - (double) (127)));
	ZEPHIR_CALL_FUNCTION(&_2, "abs", NULL, 299, &_1);
	zephir_check_call_status();
	zephir_round(&_0, &_2, NULL, NULL);
	opacity = zephir_get_intval(&_0);
	if (opacity < 127) {
		stepping = (long) (zephir_safe_div_long_long(((127 - opacity)), height));
	} else {
		stepping = (long) (zephir_safe_div_long_long(127, height));
	}
	zephir_read_property(&_1, this_ptr, ZEND_STRL("width"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_3, this_ptr, ZEND_STRL("height"), PH_NOISY_CC | PH_READONLY);
	ZVAL_LONG(&_4, (zephir_get_numberval(&_3) + height));
	ZEPHIR_CALL_METHOD(&reflection, this_ptr, "processcreate", NULL, 0, &_1, &_4);
	zephir_check_call_status();
	zephir_read_property(&_4, this_ptr, ZEND_STRL("image"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_5, this_ptr, ZEND_STRL("width"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_6, this_ptr, ZEND_STRL("height"), PH_NOISY_CC | PH_READONLY);
	ZVAL_LONG(&_7, 0);
	ZVAL_LONG(&_8, 0);
	ZVAL_LONG(&_9, 0);
	ZVAL_LONG(&_10, 0);
	ZEPHIR_CALL_FUNCTION(NULL, "imagecopy", NULL, 446, &reflection, &_4, &_7, &_8, &_9, &_10, &_5, &_6);
	zephir_check_call_status();
	offset = 0;
	while (1) {
		if (!(height >= offset)) {
			break;
		}
		zephir_read_property(&_11$$5, this_ptr, ZEND_STRL("height"), PH_NOISY_CC | PH_READONLY);
		src_y = ((zephir_get_numberval(&_11$$5) - offset) - 1);
		zephir_read_property(&_12$$5, this_ptr, ZEND_STRL("height"), PH_NOISY_CC | PH_READONLY);
		dst_y = (zephir_get_numberval(&_12$$5) + offset);
		if (fadeIn) {
			ZEPHIR_INIT_NVAR(&_13$$6);
			ZVAL_LONG(&_14$$6, (opacity + ((stepping * ((height - offset))))));
			zephir_round(&_13$$6, &_14$$6, NULL, NULL);
			dst_opacity = zephir_get_intval(&_13$$6);
		} else {
			ZEPHIR_INIT_NVAR(&_15$$7);
			ZVAL_LONG(&_16$$7, (opacity + ((stepping * offset))));
			zephir_round(&_15$$7, &_16$$7, NULL, NULL);
			dst_opacity = zephir_get_intval(&_15$$7);
		}
		zephir_read_property(&_17$$5, this_ptr, ZEND_STRL("width"), PH_NOISY_CC | PH_READONLY);
		ZVAL_LONG(&_18$$5, 1);
		ZEPHIR_CALL_METHOD(&line, this_ptr, "processcreate", NULL, 0, &_17$$5, &_18$$5);
		zephir_check_call_status();
		zephir_read_property(&_18$$5, this_ptr, ZEND_STRL("image"), PH_NOISY_CC | PH_READONLY);
		zephir_read_property(&_19$$5, this_ptr, ZEND_STRL("width"), PH_NOISY_CC | PH_READONLY);
		ZVAL_LONG(&_20$$5, 0);
		ZVAL_LONG(&_21$$5, 0);
		ZVAL_LONG(&_22$$5, 0);
		ZVAL_LONG(&_23$$5, src_y);
		ZVAL_LONG(&_24$$5, 1);
		ZEPHIR_CALL_FUNCTION(NULL, "imagecopy", NULL, 446, &line, &_18$$5, &_20$$5, &_21$$5, &_22$$5, &_23$$5, &_19$$5, &_24$$5);
		zephir_check_call_status();
		ZVAL_LONG(&_20$$5, 4);
		ZVAL_LONG(&_21$$5, 0);
		ZVAL_LONG(&_22$$5, 0);
		ZVAL_LONG(&_23$$5, 0);
		ZVAL_LONG(&_24$$5, dst_opacity);
		ZEPHIR_CALL_FUNCTION(NULL, "imagefilter", &_25, 447, &line, &_20$$5, &_21$$5, &_22$$5, &_23$$5, &_24$$5);
		zephir_check_call_status();
		zephir_read_property(&_20$$5, this_ptr, ZEND_STRL("width"), PH_NOISY_CC | PH_READONLY);
		ZVAL_LONG(&_21$$5, 0);
		ZVAL_LONG(&_22$$5, dst_y);
		ZVAL_LONG(&_23$$5, 0);
		ZVAL_LONG(&_24$$5, 0);
		ZVAL_LONG(&_26$$5, 1);
		ZEPHIR_CALL_FUNCTION(NULL, "imagecopy", NULL, 446, &reflection, &line, &_21$$5, &_22$$5, &_23$$5, &_24$$5, &_20$$5, &_26$$5);
		zephir_check_call_status();
		offset++;
	}
	zephir_read_property(&_7, this_ptr, ZEND_STRL("image"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_FUNCTION(NULL, "imagedestroy", NULL, 443, &_7);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, ZEND_STRL("image"), &reflection);
	ZEPHIR_CALL_FUNCTION(&_27, "imagesx", NULL, 449, &reflection);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, ZEND_STRL("width"), &_27);
	ZEPHIR_CALL_FUNCTION(&_28, "imagesy", NULL, 450, &reflection);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, ZEND_STRL("height"), &_28);
	ZEPHIR_MM_RESTORE();
}

PHP_METHOD(Phalcon_Image_Adapter_Gd, processRender)
{
	zend_bool _4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long quality, ZEPHIR_LAST_CALL_STATUS;
	zval *ext_param = NULL, *quality_param = NULL, __$null, _0, _1, _2, _3, _5, _6, _7, _8, _9$$3, _10$$4, _11$$4, _12$$5, _13$$6, _14$$7, _15$$8;
	zval ext, _16$$8;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&ext);
	ZVAL_UNDEF(&_16$$8);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_9$$3);
	ZVAL_UNDEF(&_10$$4);
	ZVAL_UNDEF(&_11$$4);
	ZVAL_UNDEF(&_12$$5);
	ZVAL_UNDEF(&_13$$6);
	ZVAL_UNDEF(&_14$$7);
	ZVAL_UNDEF(&_15$$8);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR(ext)
		Z_PARAM_LONG(quality)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &ext_param, &quality_param);
	zephir_get_strval(&ext, ext_param);
	quality = zephir_get_intval(quality_param);


	ZEPHIR_INIT_VAR(&_0);
	zephir_fast_strtolower(&_0, &ext);
	zephir_get_strval(&ext, &_0);
	ZEPHIR_CALL_FUNCTION(NULL, "ob_start", NULL, 459);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "gif");
	ZEPHIR_CALL_FUNCTION(&_2, "strcmp", NULL, 308, &ext, &_1);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "jpg");
	ZEPHIR_CALL_FUNCTION(&_3, "strcmp", NULL, 308, &ext, &_1);
	zephir_check_call_status();
	_4 = ZEPHIR_IS_LONG(&_3, 0);
	if (!(_4)) {
		ZEPHIR_INIT_NVAR(&_1);
		ZVAL_STRING(&_1, "jpeg");
		ZEPHIR_CALL_FUNCTION(&_5, "strcmp", NULL, 308, &ext, &_1);
		zephir_check_call_status();
		_4 = ZEPHIR_IS_LONG(&_5, 0);
	}
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "png");
	ZEPHIR_CALL_FUNCTION(&_6, "strcmp", NULL, 308, &ext, &_1);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "wbmp");
	ZEPHIR_CALL_FUNCTION(&_7, "strcmp", NULL, 308, &ext, &_1);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "xbm");
	ZEPHIR_CALL_FUNCTION(&_8, "strcmp", NULL, 308, &ext, &_1);
	zephir_check_call_status();
	if (ZEPHIR_IS_LONG(&_2, 0)) {
		zephir_read_property(&_9$$3, this_ptr, ZEND_STRL("image"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_FUNCTION(NULL, "imagegif", NULL, 460, &_9$$3);
		zephir_check_call_status();
	} else if (_4) {
		zephir_read_property(&_10$$4, this_ptr, ZEND_STRL("image"), PH_NOISY_CC | PH_READONLY);
		ZVAL_LONG(&_11$$4, quality);
		ZEPHIR_CALL_FUNCTION(NULL, "imagejpeg", NULL, 461, &_10$$4, &__$null, &_11$$4);
		zephir_check_call_status();
	} else if (ZEPHIR_IS_LONG(&_6, 0)) {
		zephir_read_property(&_12$$5, this_ptr, ZEND_STRL("image"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_FUNCTION(NULL, "imagepng", NULL, 462, &_12$$5);
		zephir_check_call_status();
	} else if (ZEPHIR_IS_LONG(&_7, 0)) {
		zephir_read_property(&_13$$6, this_ptr, ZEND_STRL("image"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_FUNCTION(NULL, "imagewbmp", NULL, 463, &_13$$6);
		zephir_check_call_status();
	} else if (ZEPHIR_IS_LONG(&_8, 0)) {
		zephir_read_property(&_14$$7, this_ptr, ZEND_STRL("image"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_FUNCTION(NULL, "imagexbm", NULL, 464, &_14$$7, &__$null);
		zephir_check_call_status();
	} else {
		ZEPHIR_INIT_VAR(&_15$$8);
		object_init_ex(&_15$$8, phalcon_image_exception_ce);
		ZEPHIR_INIT_VAR(&_16$$8);
		ZEPHIR_CONCAT_SVS(&_16$$8, "Installed GD does not support '", &ext, "' images");
		ZEPHIR_CALL_METHOD(NULL, &_15$$8, "__construct", NULL, 31, &_16$$8);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_15$$8, "phalcon/Image/Adapter/Gd.zep", 454);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_RETURN_CALL_FUNCTION("ob_get_clean", NULL, 465);
	zephir_check_call_status();
	RETURN_MM();
}

PHP_METHOD(Phalcon_Image_Adapter_Gd, processResize)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *width_param = NULL, *height_param = NULL, image, _0, _1, _2, _3, _4;
	zend_long width, height, ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&image);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
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
	ZVAL_LONG(&_1, width);
	ZVAL_LONG(&_2, height);
	ZEPHIR_CALL_FUNCTION(&image, "imagescale", NULL, 466, &_0, &_1, &_2);
	zephir_check_call_status();
	zephir_read_property(&_1, this_ptr, ZEND_STRL("image"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_FUNCTION(NULL, "imagedestroy", NULL, 443, &_1);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, ZEND_STRL("image"), &image);
	ZEPHIR_CALL_FUNCTION(&_3, "imagesx", NULL, 449, &image);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, ZEND_STRL("width"), &_3);
	ZEPHIR_CALL_FUNCTION(&_4, "imagesy", NULL, 450, &image);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, ZEND_STRL("height"), &_4);
	ZEPHIR_MM_RESTORE();
}

PHP_METHOD(Phalcon_Image_Adapter_Gd, processRotate)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *degrees_param = NULL, __$true, image, transparent, width, height, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9$$3;
	zend_long degrees, ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&image);
	ZVAL_UNDEF(&transparent);
	ZVAL_UNDEF(&width);
	ZVAL_UNDEF(&height);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_9$$3);
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
	ZVAL_LONG(&_2, 0);
	ZVAL_LONG(&_3, 0);
	ZVAL_LONG(&_4, 127);
	ZEPHIR_CALL_FUNCTION(&transparent, "imagecolorallocatealpha", NULL, 445, &_0, &_1, &_2, &_3, &_4);
	zephir_check_call_status();
	zephir_read_property(&_1, this_ptr, ZEND_STRL("image"), PH_NOISY_CC | PH_READONLY);
	ZVAL_LONG(&_2, (360 - degrees));
	ZVAL_LONG(&_3, 1);
	ZEPHIR_CALL_FUNCTION(&image, "imagerotate", NULL, 467, &_1, &_2, &transparent, &_3);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(NULL, "imagesavealpha", NULL, 440, &image, &__$true);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&width, "imagesx", NULL, 449, &image);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&height, "imagesy", NULL, 450, &image);
	zephir_check_call_status();
	zephir_read_property(&_2, this_ptr, ZEND_STRL("image"), PH_NOISY_CC | PH_READONLY);
	ZVAL_LONG(&_3, 0);
	ZVAL_LONG(&_4, 0);
	ZVAL_LONG(&_5, 0);
	ZVAL_LONG(&_6, 0);
	ZVAL_LONG(&_7, 100);
	ZEPHIR_CALL_FUNCTION(&_8, "imagecopymerge", NULL, 468, &_2, &image, &_3, &_4, &_5, &_6, &width, &height, &_7);
	zephir_check_call_status();
	if (zephir_is_true(&_8)) {
		zephir_read_property(&_9$$3, this_ptr, ZEND_STRL("image"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_FUNCTION(NULL, "imagedestroy", NULL, 443, &_9$$3);
		zephir_check_call_status();
		zephir_update_property_zval(this_ptr, ZEND_STRL("image"), &image);
		zephir_update_property_zval(this_ptr, ZEND_STRL("width"), &width);
		zephir_update_property_zval(this_ptr, ZEND_STRL("height"), &height);
	}
	ZEPHIR_MM_RESTORE();
}

PHP_METHOD(Phalcon_Image_Adapter_Gd, processSave)
{
	zend_bool _8;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long quality, ZEPHIR_LAST_CALL_STATUS;
	zval *file_param = NULL, *quality_param = NULL, __$false, ext, _0, _2, _3, _7, _9, _15, _19, _23, _27, _1$$3, _4$$4, _5$$4, _6$$4, _10$$5, _11$$5, _12$$6, _13$$6, _14$$9, _16$$10, _17$$10, _18$$10, _20$$11, _21$$11, _22$$11, _24$$12, _25$$12, _26$$12;
	zval file;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&file);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&ext);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_15);
	ZVAL_UNDEF(&_19);
	ZVAL_UNDEF(&_23);
	ZVAL_UNDEF(&_27);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_10$$5);
	ZVAL_UNDEF(&_11$$5);
	ZVAL_UNDEF(&_12$$6);
	ZVAL_UNDEF(&_13$$6);
	ZVAL_UNDEF(&_14$$9);
	ZVAL_UNDEF(&_16$$10);
	ZVAL_UNDEF(&_17$$10);
	ZVAL_UNDEF(&_18$$10);
	ZVAL_UNDEF(&_20$$11);
	ZVAL_UNDEF(&_21$$11);
	ZVAL_UNDEF(&_22$$11);
	ZVAL_UNDEF(&_24$$12);
	ZVAL_UNDEF(&_25$$12);
	ZVAL_UNDEF(&_26$$12);
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
	ZEPHIR_CALL_FUNCTION(&ext, "pathinfo", NULL, 116, &file, &_0);
	zephir_check_call_status();
	if (!(zephir_is_true(&ext))) {
		zephir_read_property(&_1$$3, this_ptr, ZEND_STRL("type"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_FUNCTION(&ext, "image_type_to_extension", NULL, 469, &_1$$3, &__$false);
		zephir_check_call_status();
	}
	ZEPHIR_INIT_VAR(&_2);
	zephir_fast_strtolower(&_2, &ext);
	ZEPHIR_CPY_WRT(&ext, &_2);
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_STRING(&_2, "gif");
	ZEPHIR_CALL_FUNCTION(&_3, "strcmp", NULL, 308, &ext, &_2);
	zephir_check_call_status();
	if (ZEPHIR_IS_LONG(&_3, 0)) {
		ZEPHIR_INIT_ZVAL_NREF(_4$$4);
		ZVAL_LONG(&_4$$4, 1);
		zephir_update_property_zval(this_ptr, ZEND_STRL("type"), &_4$$4);
		zephir_read_property(&_4$$4, this_ptr, ZEND_STRL("type"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_FUNCTION(&_5$$4, "image_type_to_mime_type", NULL, 470, &_4$$4);
		zephir_check_call_status();
		zephir_update_property_zval(this_ptr, ZEND_STRL("mime"), &_5$$4);
		zephir_read_property(&_6$$4, this_ptr, ZEND_STRL("image"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_FUNCTION(NULL, "imagegif", NULL, 460, &_6$$4, &file);
		zephir_check_call_status();
		RETURN_MM_BOOL(1);
	}
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_STRING(&_2, "jpg");
	ZEPHIR_CALL_FUNCTION(&_7, "strcmp", NULL, 308, &ext, &_2);
	zephir_check_call_status();
	_8 = ZEPHIR_IS_LONG(&_7, 0);
	if (!(_8)) {
		ZEPHIR_INIT_NVAR(&_2);
		ZVAL_STRING(&_2, "jpeg");
		ZEPHIR_CALL_FUNCTION(&_9, "strcmp", NULL, 308, &ext, &_2);
		zephir_check_call_status();
		_8 = ZEPHIR_IS_LONG(&_9, 0);
	}
	if (_8) {
		ZEPHIR_INIT_ZVAL_NREF(_10$$5);
		ZVAL_LONG(&_10$$5, 2);
		zephir_update_property_zval(this_ptr, ZEND_STRL("type"), &_10$$5);
		zephir_read_property(&_10$$5, this_ptr, ZEND_STRL("type"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_FUNCTION(&_11$$5, "image_type_to_mime_type", NULL, 470, &_10$$5);
		zephir_check_call_status();
		zephir_update_property_zval(this_ptr, ZEND_STRL("mime"), &_11$$5);
		if (quality >= 0) {
			if (quality < 1) {
				quality = 1;
			} else if (quality > 100) {
				quality = 100;
			}
			zephir_read_property(&_12$$6, this_ptr, ZEND_STRL("image"), PH_NOISY_CC | PH_READONLY);
			ZVAL_LONG(&_13$$6, quality);
			ZEPHIR_CALL_FUNCTION(NULL, "imagejpeg", NULL, 461, &_12$$6, &file, &_13$$6);
			zephir_check_call_status();
		} else {
			zephir_read_property(&_14$$9, this_ptr, ZEND_STRL("image"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_CALL_FUNCTION(NULL, "imagejpeg", NULL, 461, &_14$$9, &file);
			zephir_check_call_status();
		}
		RETURN_MM_BOOL(1);
	}
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_STRING(&_2, "png");
	ZEPHIR_CALL_FUNCTION(&_15, "strcmp", NULL, 308, &ext, &_2);
	zephir_check_call_status();
	if (ZEPHIR_IS_LONG(&_15, 0)) {
		ZEPHIR_INIT_ZVAL_NREF(_16$$10);
		ZVAL_LONG(&_16$$10, 3);
		zephir_update_property_zval(this_ptr, ZEND_STRL("type"), &_16$$10);
		zephir_read_property(&_16$$10, this_ptr, ZEND_STRL("type"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_FUNCTION(&_17$$10, "image_type_to_mime_type", NULL, 470, &_16$$10);
		zephir_check_call_status();
		zephir_update_property_zval(this_ptr, ZEND_STRL("mime"), &_17$$10);
		zephir_read_property(&_18$$10, this_ptr, ZEND_STRL("image"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_FUNCTION(NULL, "imagepng", NULL, 462, &_18$$10, &file);
		zephir_check_call_status();
		RETURN_MM_BOOL(1);
	}
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_STRING(&_2, "wbmp");
	ZEPHIR_CALL_FUNCTION(&_19, "strcmp", NULL, 308, &ext, &_2);
	zephir_check_call_status();
	if (ZEPHIR_IS_LONG(&_19, 0)) {
		ZEPHIR_INIT_ZVAL_NREF(_20$$11);
		ZVAL_LONG(&_20$$11, 15);
		zephir_update_property_zval(this_ptr, ZEND_STRL("type"), &_20$$11);
		zephir_read_property(&_20$$11, this_ptr, ZEND_STRL("type"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_FUNCTION(&_21$$11, "image_type_to_mime_type", NULL, 470, &_20$$11);
		zephir_check_call_status();
		zephir_update_property_zval(this_ptr, ZEND_STRL("mime"), &_21$$11);
		zephir_read_property(&_22$$11, this_ptr, ZEND_STRL("image"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_FUNCTION(NULL, "imagewbmp", NULL, 463, &_22$$11, &file);
		zephir_check_call_status();
		RETURN_MM_BOOL(1);
	}
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_STRING(&_2, "xbm");
	ZEPHIR_CALL_FUNCTION(&_23, "strcmp", NULL, 308, &ext, &_2);
	zephir_check_call_status();
	if (ZEPHIR_IS_LONG(&_23, 0)) {
		ZEPHIR_INIT_ZVAL_NREF(_24$$12);
		ZVAL_LONG(&_24$$12, 16);
		zephir_update_property_zval(this_ptr, ZEND_STRL("type"), &_24$$12);
		zephir_read_property(&_24$$12, this_ptr, ZEND_STRL("type"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_FUNCTION(&_25$$12, "image_type_to_mime_type", NULL, 470, &_24$$12);
		zephir_check_call_status();
		zephir_update_property_zval(this_ptr, ZEND_STRL("mime"), &_25$$12);
		zephir_read_property(&_26$$12, this_ptr, ZEND_STRL("image"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_FUNCTION(NULL, "imagexbm", NULL, 464, &_26$$12, &file);
		zephir_check_call_status();
		RETURN_MM_BOOL(1);
	}
	ZEPHIR_INIT_NVAR(&_2);
	object_init_ex(&_2, phalcon_image_exception_ce);
	ZEPHIR_INIT_VAR(&_27);
	ZEPHIR_CONCAT_SVS(&_27, "Installed GD does not support '", &ext, "' images");
	ZEPHIR_CALL_METHOD(NULL, &_2, "__construct", NULL, 31, &_27);
	zephir_check_call_status();
	zephir_throw_exception_debug(&_2, "phalcon/Image/Adapter/Gd.zep", 576);
	ZEPHIR_MM_RESTORE();
	return;
}

PHP_METHOD(Phalcon_Image_Adapter_Gd, processSharpen)
{
	zval _3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *amount_param = NULL, matrix, _0, _1, _2, _4, _5, _6, _7, _8, _9$$3, _10$$3, _11$$3, _12$$3;
	zend_long amount, ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&matrix);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_9$$3);
	ZVAL_UNDEF(&_10$$3);
	ZVAL_UNDEF(&_11$$3);
	ZVAL_UNDEF(&_12$$3);
	ZVAL_UNDEF(&_3);
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
	ZVAL_LONG(&_1, (-18 + ((amount * 0.08))));
	ZEPHIR_CALL_FUNCTION(&_2, "abs", NULL, 299, &_1);
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
	zephir_read_property(&_5, this_ptr, ZEND_STRL("image"), PH_NOISY_CC | PH_READONLY);
	ZVAL_LONG(&_6, (amount - 8));
	ZVAL_LONG(&_7, 0);
	ZEPHIR_CALL_FUNCTION(&_8, "imageconvolution", NULL, 471, &_5, &matrix, &_6, &_7);
	zephir_check_call_status();
	if (zephir_is_true(&_8)) {
		zephir_read_property(&_9$$3, this_ptr, ZEND_STRL("image"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_FUNCTION(&_10$$3, "imagesx", NULL, 449, &_9$$3);
		zephir_check_call_status();
		zephir_update_property_zval(this_ptr, ZEND_STRL("width"), &_10$$3);
		zephir_read_property(&_11$$3, this_ptr, ZEND_STRL("image"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_FUNCTION(&_12$$3, "imagesy", NULL, 450, &_11$$3);
		zephir_check_call_status();
		zephir_update_property_zval(this_ptr, ZEND_STRL("height"), &_12$$3);
	}
	ZEPHIR_MM_RESTORE();
}

PHP_METHOD(Phalcon_Image_Adapter_Gd, processText)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long offsetX, offsetY, opacity, r, g, b, size, ZEPHIR_LAST_CALL_STATUS, angle = 0, bottomLeftX, bottomLeftY, topRightX, topRightY, width = 0, height = 0;
	zval *text_param = NULL, *offsetX_param = NULL, *offsetY_param = NULL, *opacity_param = NULL, *r_param = NULL, *g_param = NULL, *b_param = NULL, *size_param = NULL, *fontfile_param = NULL, space, color, _0, _1, _2, _3$$3, _4$$3, _9$$3, _10$$3, _13$$3, _14$$3, _15$$3, _16$$3, _5$$5, _6$$5, _7$$5, _8$$5, _11$$6, _12$$7, _17$$8, _18$$8, _19$$8, _22$$8, _23$$8, _24$$8, _25$$8, _20$$9, _21$$10;
	zval text, fontfile;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&text);
	ZVAL_UNDEF(&fontfile);
	ZVAL_UNDEF(&space);
	ZVAL_UNDEF(&color);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_9$$3);
	ZVAL_UNDEF(&_10$$3);
	ZVAL_UNDEF(&_13$$3);
	ZVAL_UNDEF(&_14$$3);
	ZVAL_UNDEF(&_15$$3);
	ZVAL_UNDEF(&_16$$3);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&_6$$5);
	ZVAL_UNDEF(&_7$$5);
	ZVAL_UNDEF(&_8$$5);
	ZVAL_UNDEF(&_11$$6);
	ZVAL_UNDEF(&_12$$7);
	ZVAL_UNDEF(&_17$$8);
	ZVAL_UNDEF(&_18$$8);
	ZVAL_UNDEF(&_19$$8);
	ZVAL_UNDEF(&_22$$8);
	ZVAL_UNDEF(&_23$$8);
	ZVAL_UNDEF(&_24$$8);
	ZVAL_UNDEF(&_25$$8);
	ZVAL_UNDEF(&_20$$9);
	ZVAL_UNDEF(&_21$$10);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(9, 9)
		Z_PARAM_STR(text)
		Z_PARAM_LONG(offsetX)
		Z_PARAM_LONG(offsetY)
		Z_PARAM_LONG(opacity)
		Z_PARAM_LONG(r)
		Z_PARAM_LONG(g)
		Z_PARAM_LONG(b)
		Z_PARAM_LONG(size)
		Z_PARAM_STR(fontfile)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 9, 0, &text_param, &offsetX_param, &offsetY_param, &opacity_param, &r_param, &g_param, &b_param, &size_param, &fontfile_param);
	zephir_get_strval(&text, text_param);
	offsetX = zephir_get_intval(offsetX_param);
	offsetY = zephir_get_intval(offsetY_param);
	opacity = zephir_get_intval(opacity_param);
	r = zephir_get_intval(r_param);
	g = zephir_get_intval(g_param);
	b = zephir_get_intval(b_param);
	size = zephir_get_intval(size_param);
	zephir_get_strval(&fontfile, fontfile_param);


	bottomLeftX = 0;
	bottomLeftY = 0;
	topRightX = 0;
	topRightY = 0;
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_DOUBLE(&_1, ((zephir_safe_div_long_long((opacity * 127), 100)) - (double) (127)));
	ZEPHIR_CALL_FUNCTION(&_2, "abs", NULL, 299, &_1);
	zephir_check_call_status();
	zephir_round(&_0, &_2, NULL, NULL);
	opacity = zephir_get_intval(&_0);
	if (!(ZEPHIR_IS_EMPTY(&fontfile))) {
		ZVAL_LONG(&_3$$3, size);
		ZVAL_LONG(&_4$$3, 0);
		ZEPHIR_CALL_FUNCTION(&space, "imagettfbbox", NULL, 472, &_3$$3, &_4$$3, &fontfile, &text);
		zephir_check_call_status();
		if (ZEPHIR_IS_FALSE_IDENTICAL(&space)) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_image_exception_ce, "Call to imagettfbbox() failed", "phalcon/Image/Adapter/Gd.zep", 618);
			return;
		}
		if (zephir_array_isset_long(&space, 0)) {
			ZEPHIR_OBS_VAR(&_5$$5);
			zephir_array_fetch_long(&_5$$5, &space, 0, PH_NOISY, "phalcon/Image/Adapter/Gd.zep", 622);
			bottomLeftX = zephir_get_intval(&_5$$5);
			ZEPHIR_OBS_VAR(&_6$$5);
			zephir_array_fetch_long(&_6$$5, &space, 1, PH_NOISY, "phalcon/Image/Adapter/Gd.zep", 623);
			bottomLeftY = zephir_get_intval(&_6$$5);
			ZEPHIR_OBS_VAR(&_7$$5);
			zephir_array_fetch_long(&_7$$5, &space, 4, PH_NOISY, "phalcon/Image/Adapter/Gd.zep", 624);
			topRightX = zephir_get_intval(&_7$$5);
			ZEPHIR_OBS_VAR(&_8$$5);
			zephir_array_fetch_long(&_8$$5, &space, 5, PH_NOISY, "phalcon/Image/Adapter/Gd.zep", 625);
			topRightY = zephir_get_intval(&_8$$5);
		}
		ZVAL_LONG(&_3$$3, (topRightX - bottomLeftX));
		ZEPHIR_CALL_FUNCTION(&_9$$3, "abs", NULL, 299, &_3$$3);
		zephir_check_call_status();
		width = (zephir_get_numberval(&_9$$3) + 10);
		ZVAL_LONG(&_3$$3, (topRightY - bottomLeftY));
		ZEPHIR_CALL_FUNCTION(&_10$$3, "abs", NULL, 299, &_3$$3);
		zephir_check_call_status();
		height = (zephir_get_numberval(&_10$$3) + 10);
		if (offsetX < 0) {
			zephir_read_property(&_11$$6, this_ptr, ZEND_STRL("width"), PH_NOISY_CC | PH_READONLY);
			offsetX = ((zephir_get_numberval(&_11$$6) - width) + offsetX);
		}
		if (offsetY < 0) {
			zephir_read_property(&_12$$7, this_ptr, ZEND_STRL("height"), PH_NOISY_CC | PH_READONLY);
			offsetY = ((zephir_get_numberval(&_12$$7) - height) + offsetY);
		}
		zephir_read_property(&_3$$3, this_ptr, ZEND_STRL("image"), PH_NOISY_CC | PH_READONLY);
		ZVAL_LONG(&_4$$3, r);
		ZVAL_LONG(&_13$$3, g);
		ZVAL_LONG(&_14$$3, b);
		ZVAL_LONG(&_15$$3, opacity);
		ZEPHIR_CALL_FUNCTION(&color, "imagecolorallocatealpha", NULL, 445, &_3$$3, &_4$$3, &_13$$3, &_14$$3, &_15$$3);
		zephir_check_call_status();
		angle = 0;
		zephir_read_property(&_4$$3, this_ptr, ZEND_STRL("image"), PH_NOISY_CC | PH_READONLY);
		ZVAL_LONG(&_13$$3, size);
		ZVAL_LONG(&_14$$3, angle);
		ZVAL_LONG(&_15$$3, offsetX);
		ZVAL_LONG(&_16$$3, offsetY);
		ZEPHIR_CALL_FUNCTION(NULL, "imagettftext", NULL, 473, &_4$$3, &_13$$3, &_14$$3, &_15$$3, &_16$$3, &color, &fontfile, &text);
		zephir_check_call_status();
	} else {
		ZVAL_LONG(&_17$$8, size);
		ZEPHIR_CALL_FUNCTION(&_18$$8, "imagefontwidth", NULL, 474, &_17$$8);
		zephir_check_call_status();
		width = (zephir_get_intval(&_18$$8) * zephir_fast_strlen_ev(&text));
		ZVAL_LONG(&_17$$8, size);
		ZEPHIR_CALL_FUNCTION(&_19$$8, "imagefontheight", NULL, 475, &_17$$8);
		zephir_check_call_status();
		height = zephir_get_intval(&_19$$8);
		if (offsetX < 0) {
			zephir_read_property(&_20$$9, this_ptr, ZEND_STRL("width"), PH_NOISY_CC | PH_READONLY);
			offsetX = ((zephir_get_numberval(&_20$$9) - width) + offsetX);
		}
		if (offsetY < 0) {
			zephir_read_property(&_21$$10, this_ptr, ZEND_STRL("height"), PH_NOISY_CC | PH_READONLY);
			offsetY = ((zephir_get_numberval(&_21$$10) - height) + offsetY);
		}
		zephir_read_property(&_17$$8, this_ptr, ZEND_STRL("image"), PH_NOISY_CC | PH_READONLY);
		ZVAL_LONG(&_22$$8, r);
		ZVAL_LONG(&_23$$8, g);
		ZVAL_LONG(&_24$$8, b);
		ZVAL_LONG(&_25$$8, opacity);
		ZEPHIR_CALL_FUNCTION(&color, "imagecolorallocatealpha", NULL, 445, &_17$$8, &_22$$8, &_23$$8, &_24$$8, &_25$$8);
		zephir_check_call_status();
		zephir_read_property(&_22$$8, this_ptr, ZEND_STRL("image"), PH_NOISY_CC | PH_READONLY);
		ZVAL_LONG(&_23$$8, size);
		ZVAL_LONG(&_24$$8, offsetX);
		ZVAL_LONG(&_25$$8, offsetY);
		ZEPHIR_CALL_FUNCTION(NULL, "imagestring", NULL, 476, &_22$$8, &_23$$8, &_24$$8, &_25$$8, &text, &color);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();
}

PHP_METHOD(Phalcon_Image_Adapter_Gd, processWatermark)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long offsetX, offsetY, opacity, ZEPHIR_LAST_CALL_STATUS, width = 0, height = 0;
	zval *watermark, watermark_sub, *offsetX_param = NULL, *offsetY_param = NULL, *opacity_param = NULL, __$true, overlay, color, _0, _1, _2, _9, _10, _11, _12, _13, _14, _15, _16, _17, _3$$3, _4$$3, _5$$3, _6$$3, _7$$3, _8$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&watermark_sub);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&overlay);
	ZVAL_UNDEF(&color);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_11);
	ZVAL_UNDEF(&_12);
	ZVAL_UNDEF(&_13);
	ZVAL_UNDEF(&_14);
	ZVAL_UNDEF(&_15);
	ZVAL_UNDEF(&_16);
	ZVAL_UNDEF(&_17);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_7$$3);
	ZVAL_UNDEF(&_8$$3);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_OBJECT_OF_CLASS(watermark, phalcon_image_adapter_adapterinterface_ce)
		Z_PARAM_LONG(offsetX)
		Z_PARAM_LONG(offsetY)
		Z_PARAM_LONG(opacity)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 4, 0, &watermark, &offsetX_param, &offsetY_param, &opacity_param);
	offsetX = zephir_get_intval(offsetX_param);
	offsetY = zephir_get_intval(offsetY_param);
	opacity = zephir_get_intval(opacity_param);


	ZEPHIR_CALL_METHOD(&_0, watermark, "render", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&overlay, "imagecreatefromstring", NULL, 452, &_0);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(NULL, "imagesavealpha", NULL, 440, &overlay, &__$true);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&_1, "imagesx", NULL, 449, &overlay);
	zephir_check_call_status();
	width = zephir_get_intval(&_1);
	ZEPHIR_CALL_FUNCTION(&_2, "imagesy", NULL, 450, &overlay);
	zephir_check_call_status();
	height = zephir_get_intval(&_2);
	if (opacity < 100) {
		ZEPHIR_INIT_VAR(&_3$$3);
		ZVAL_DOUBLE(&_4$$3, ((zephir_safe_div_long_long((opacity * 127), 100)) - (double) (127)));
		ZEPHIR_CALL_FUNCTION(&_5$$3, "abs", NULL, 299, &_4$$3);
		zephir_check_call_status();
		zephir_round(&_3$$3, &_5$$3, NULL, NULL);
		opacity = zephir_get_intval(&_3$$3);
		ZVAL_LONG(&_4$$3, 127);
		ZVAL_LONG(&_6$$3, 127);
		ZVAL_LONG(&_7$$3, 127);
		ZVAL_LONG(&_8$$3, opacity);
		ZEPHIR_CALL_FUNCTION(&color, "imagecolorallocatealpha", NULL, 445, &overlay, &_4$$3, &_6$$3, &_7$$3, &_8$$3);
		zephir_check_call_status();
		ZVAL_LONG(&_4$$3, 3);
		ZEPHIR_CALL_FUNCTION(NULL, "imagelayereffect", NULL, 477, &overlay, &_4$$3);
		zephir_check_call_status();
		ZVAL_LONG(&_4$$3, 0);
		ZVAL_LONG(&_6$$3, 0);
		ZVAL_LONG(&_7$$3, width);
		ZVAL_LONG(&_8$$3, height);
		ZEPHIR_CALL_FUNCTION(NULL, "imagefilledrectangle", NULL, 458, &overlay, &_4$$3, &_6$$3, &_7$$3, &_8$$3, &color);
		zephir_check_call_status();
	}
	zephir_read_property(&_9, this_ptr, ZEND_STRL("image"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_FUNCTION(NULL, "imagealphablending", NULL, 442, &_9, &__$true);
	zephir_check_call_status();
	zephir_read_property(&_10, this_ptr, ZEND_STRL("image"), PH_NOISY_CC | PH_READONLY);
	ZVAL_LONG(&_11, offsetX);
	ZVAL_LONG(&_12, offsetY);
	ZVAL_LONG(&_13, 0);
	ZVAL_LONG(&_14, 0);
	ZVAL_LONG(&_15, width);
	ZVAL_LONG(&_16, height);
	ZEPHIR_CALL_FUNCTION(&_17, "imagecopy", NULL, 446, &_10, &overlay, &_11, &_12, &_13, &_14, &_15, &_16);
	zephir_check_call_status();
	if (zephir_is_true(&_17)) {
		ZEPHIR_CALL_FUNCTION(NULL, "imagedestroy", NULL, 443, &overlay);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();
}

