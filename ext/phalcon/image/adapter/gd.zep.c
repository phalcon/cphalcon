
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
#include "kernel/exception.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/array.h"
#include "kernel/string.h"
#include "kernel/concat.h"
#include "kernel/file.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/math.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
ZEPHIR_INIT_CLASS(Phalcon_Image_Adapter_Gd) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Image\\Adapter, Gd, phalcon, image_adapter_gd, phalcon_image_adapter_ce, phalcon_image_adapter_gd_method_entry, 0);

	zend_declare_property_bool(phalcon_image_adapter_gd_ce, SL("_checked"), 0, ZEND_ACC_PROTECTED|ZEND_ACC_STATIC TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(Phalcon_Image_Adapter_Gd, check) {

	zval __$true, version, info, matches, _0, _1, _2, _7, _8, _11, _3$$6, _4$$6, _5$$6, _6$$6, _9$$8, _10$$8;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&version);
	ZVAL_UNDEF(&info);
	ZVAL_UNDEF(&matches);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_11);
	ZVAL_UNDEF(&_3$$6);
	ZVAL_UNDEF(&_4$$6);
	ZVAL_UNDEF(&_5$$6);
	ZVAL_UNDEF(&_6$$6);
	ZVAL_UNDEF(&_9$$8);
	ZVAL_UNDEF(&_10$$8);

	ZEPHIR_MM_GROW();

	zephir_read_static_property_ce(&_0, phalcon_image_adapter_gd_ce, SL("_checked"), PH_NOISY_CC | PH_READONLY);
	if (zephir_is_true(&_0)) {
		RETURN_MM_BOOL(1);
	}
	if (!((zephir_function_exists_ex(SL("gd_info") TSRMLS_CC) == SUCCESS))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_image_exception_ce, "GD is either not installed or not enabled, check your configuration", "phalcon/image/adapter/gd.zep", 29);
		return;
	}
	ZEPHIR_INIT_VAR(&version);
	ZVAL_NULL(&version);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "GD_VERSION");
	ZEPHIR_CALL_FUNCTION(&_2, "defined", NULL, 228, &_1);
	zephir_check_call_status();
	if (zephir_is_true(&_2)) {
		ZEPHIR_INIT_NVAR(&version);
		ZEPHIR_GET_CONSTANT(&version, "GD_VERSION");
	} else {
		ZEPHIR_CALL_FUNCTION(&info, "gd_info", NULL, 239);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&matches);
		ZVAL_NULL(&matches);
		zephir_array_fetch_string(&_3$$6, &info, SL("GD Version"), PH_NOISY | PH_READONLY, "phalcon/image/adapter/gd.zep", 37 TSRMLS_CC);
		ZEPHIR_INIT_VAR(&_4$$6);
		ZVAL_STRING(&_4$$6, "/\\d+\\.\\d+(?:\\.\\d+)?/");
		ZEPHIR_INIT_VAR(&_5$$6);
		ZEPHIR_INIT_VAR(&_6$$6);
		ZVAL_STRING(&_6$$6, "/\\d+\\.\\d+(?:\\.\\d+)?/");
		zephir_preg_match(&_5$$6, &_6$$6, &_3$$6, &matches, 0, 0 , 0  TSRMLS_CC);
		if (zephir_is_true(&_5$$6)) {
			ZEPHIR_OBS_NVAR(&version);
			zephir_array_fetch_long(&version, &matches, 0, PH_NOISY, "phalcon/image/adapter/gd.zep", 38 TSRMLS_CC);
		}
	}
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "2.0.1");
	ZEPHIR_INIT_VAR(&_7);
	ZVAL_STRING(&_7, ">=");
	ZEPHIR_CALL_FUNCTION(&_8, "version_compare", NULL, 240, &version, &_1, &_7);
	zephir_check_call_status();
	if (!(zephir_is_true(&_8))) {
		ZEPHIR_INIT_VAR(&_9$$8);
		object_init_ex(&_9$$8, phalcon_image_exception_ce);
		ZEPHIR_INIT_VAR(&_10$$8);
		ZEPHIR_CONCAT_SV(&_10$$8, "Phalcon\\Image\\Adapter\\GD requires GD version '2.0.1' or greater, you have ", &version);
		ZEPHIR_CALL_METHOD(NULL, &_9$$8, "__construct", NULL, 4, &_10$$8);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_9$$8, "phalcon/image/adapter/gd.zep", 43 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zend_update_static_property(phalcon_image_adapter_gd_ce, ZEND_STRL("_checked"), &__$true);
	zephir_read_static_property_ce(&_11, phalcon_image_adapter_gd_ce, SL("_checked"), PH_NOISY_CC | PH_READONLY);
	RETURN_CTOR(&_11);

}

PHP_METHOD(Phalcon_Image_Adapter_Gd, __construct) {

	zend_bool _25$$14;
	zend_long width, height, ZEPHIR_LAST_CALL_STATUS;
	zval *file_param = NULL, *width_param = NULL, *height_param = NULL, __$true, imageinfo, _0, _1, _2$$4, _3$$4, _4$$4, _9$$4, _24$$4, _5$$5, _6$$5, _7$$5, _8$$5, _10$$6, _11$$6, _12$$7, _13$$7, _14$$8, _15$$8, _16$$9, _17$$9, _18$$10, _19$$10, _20$$11, _21$$12, _22$$12, _23$$12, _29$$14, _30$$14, _31$$14, _32$$14, _33$$14, _34$$14, _26$$15, _27$$15, _28$$15;
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
	ZVAL_UNDEF(&_29$$14);
	ZVAL_UNDEF(&_30$$14);
	ZVAL_UNDEF(&_31$$14);
	ZVAL_UNDEF(&_32$$14);
	ZVAL_UNDEF(&_33$$14);
	ZVAL_UNDEF(&_34$$14);
	ZVAL_UNDEF(&_26$$15);
	ZVAL_UNDEF(&_27$$15);
	ZVAL_UNDEF(&_28$$15);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &file_param, &width_param, &height_param);

	if (UNEXPECTED(Z_TYPE_P(file_param) != IS_STRING && Z_TYPE_P(file_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'file' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(file_param) == IS_STRING)) {
		zephir_get_strval(&file, file_param);
	} else {
		ZEPHIR_INIT_VAR(&file);
		ZVAL_EMPTY_STRING(&file);
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


	zephir_read_static_property_ce(&_0, phalcon_image_adapter_gd_ce, SL("_checked"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_is_true(&_0))) {
		ZEPHIR_CALL_SELF(NULL, "check", NULL, 0);
		zephir_check_call_status();
	}
	zephir_update_property_zval(this_ptr, SL("_file"), &file);
	zephir_read_property(&_1, this_ptr, SL("_file"), PH_NOISY_CC | PH_READONLY);
	if ((zephir_file_exists(&_1 TSRMLS_CC) == SUCCESS)) {
		zephir_read_property(&_2$$4, this_ptr, SL("_file"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_FUNCTION(&_3$$4, "realpath", NULL, 49, &_2$$4);
		zephir_check_call_status();
		zephir_update_property_zval(this_ptr, SL("_realpath"), &_3$$4);
		zephir_read_property(&_4$$4, this_ptr, SL("_file"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_FUNCTION(&imageinfo, "getimagesize", NULL, 241, &_4$$4);
		zephir_check_call_status();
		if (zephir_is_true(&imageinfo)) {
			zephir_array_fetch_long(&_5$$5, &imageinfo, 0, PH_NOISY | PH_READONLY, "phalcon/image/adapter/gd.zep", 67 TSRMLS_CC);
			zephir_update_property_zval(this_ptr, SL("_width"), &_5$$5);
			zephir_array_fetch_long(&_6$$5, &imageinfo, 1, PH_NOISY | PH_READONLY, "phalcon/image/adapter/gd.zep", 68 TSRMLS_CC);
			zephir_update_property_zval(this_ptr, SL("_height"), &_6$$5);
			zephir_array_fetch_long(&_7$$5, &imageinfo, 2, PH_NOISY | PH_READONLY, "phalcon/image/adapter/gd.zep", 69 TSRMLS_CC);
			zephir_update_property_zval(this_ptr, SL("_type"), &_7$$5);
			zephir_array_fetch_string(&_8$$5, &imageinfo, SL("mime"), PH_NOISY | PH_READONLY, "phalcon/image/adapter/gd.zep", 70 TSRMLS_CC);
			zephir_update_property_zval(this_ptr, SL("_mime"), &_8$$5);
		}
		zephir_read_property(&_9$$4, this_ptr, SL("_type"), PH_NOISY_CC | PH_READONLY);
		do {
			if (ZEPHIR_IS_LONG(&_9$$4, 1)) {
				zephir_read_property(&_10$$6, this_ptr, SL("_file"), PH_NOISY_CC | PH_READONLY);
				ZEPHIR_CALL_FUNCTION(&_11$$6, "imagecreatefromgif", NULL, 242, &_10$$6);
				zephir_check_call_status();
				zephir_update_property_zval(this_ptr, SL("_image"), &_11$$6);
				break;
			}
			if (ZEPHIR_IS_LONG(&_9$$4, 2)) {
				zephir_read_property(&_12$$7, this_ptr, SL("_file"), PH_NOISY_CC | PH_READONLY);
				ZEPHIR_CALL_FUNCTION(&_13$$7, "imagecreatefromjpeg", NULL, 243, &_12$$7);
				zephir_check_call_status();
				zephir_update_property_zval(this_ptr, SL("_image"), &_13$$7);
				break;
			}
			if (ZEPHIR_IS_LONG(&_9$$4, 3)) {
				zephir_read_property(&_14$$8, this_ptr, SL("_file"), PH_NOISY_CC | PH_READONLY);
				ZEPHIR_CALL_FUNCTION(&_15$$8, "imagecreatefrompng", NULL, 244, &_14$$8);
				zephir_check_call_status();
				zephir_update_property_zval(this_ptr, SL("_image"), &_15$$8);
				break;
			}
			if (ZEPHIR_IS_LONG(&_9$$4, 15)) {
				zephir_read_property(&_16$$9, this_ptr, SL("_file"), PH_NOISY_CC | PH_READONLY);
				ZEPHIR_CALL_FUNCTION(&_17$$9, "imagecreatefromwbmp", NULL, 245, &_16$$9);
				zephir_check_call_status();
				zephir_update_property_zval(this_ptr, SL("_image"), &_17$$9);
				break;
			}
			if (ZEPHIR_IS_LONG(&_9$$4, 16)) {
				zephir_read_property(&_18$$10, this_ptr, SL("_file"), PH_NOISY_CC | PH_READONLY);
				ZEPHIR_CALL_FUNCTION(&_19$$10, "imagecreatefromxbm", NULL, 246, &_18$$10);
				zephir_check_call_status();
				zephir_update_property_zval(this_ptr, SL("_image"), &_19$$10);
				break;
			}
			zephir_read_property(&_20$$11, this_ptr, SL("_mime"), PH_NOISY_CC | PH_READONLY);
			if (zephir_is_true(&_20$$11)) {
				ZEPHIR_INIT_VAR(&_21$$12);
				object_init_ex(&_21$$12, phalcon_image_exception_ce);
				zephir_read_property(&_22$$12, this_ptr, SL("_mime"), PH_NOISY_CC | PH_READONLY);
				ZEPHIR_INIT_VAR(&_23$$12);
				ZEPHIR_CONCAT_SVS(&_23$$12, "Installed GD does not support ", &_22$$12, " images");
				ZEPHIR_CALL_METHOD(NULL, &_21$$12, "__construct", NULL, 4, &_23$$12);
				zephir_check_call_status();
				zephir_throw_exception_debug(&_21$$12, "phalcon/image/adapter/gd.zep", 91 TSRMLS_CC);
				ZEPHIR_MM_RESTORE();
				return;
			} else {
				ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_image_exception_ce, "Installed GD does not support such images", "phalcon/image/adapter/gd.zep", 93);
				return;
			}
			break;
		} while(0);

		zephir_read_property(&_24$$4, this_ptr, SL("_image"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_FUNCTION(NULL, "imagesavealpha", NULL, 247, &_24$$4, &__$true);
		zephir_check_call_status();
	} else {
		_25$$14 = !width;
		if (!(_25$$14)) {
			_25$$14 = !height;
		}
		if (_25$$14) {
			ZEPHIR_INIT_VAR(&_26$$15);
			object_init_ex(&_26$$15, phalcon_image_exception_ce);
			zephir_read_property(&_27$$15, this_ptr, SL("_file"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_INIT_VAR(&_28$$15);
			ZEPHIR_CONCAT_SV(&_28$$15, "Failed to create image from file ", &_27$$15);
			ZEPHIR_CALL_METHOD(NULL, &_26$$15, "__construct", NULL, 4, &_28$$15);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_26$$15, "phalcon/image/adapter/gd.zep", 102 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZVAL_LONG(&_29$$14, width);
		ZVAL_LONG(&_30$$14, height);
		ZEPHIR_CALL_FUNCTION(&_31$$14, "imagecreatetruecolor", NULL, 248, &_29$$14, &_30$$14);
		zephir_check_call_status();
		zephir_update_property_zval(this_ptr, SL("_image"), &_31$$14);
		zephir_read_property(&_29$$14, this_ptr, SL("_image"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_FUNCTION(NULL, "imagealphablending", NULL, 249, &_29$$14, &__$true);
		zephir_check_call_status();
		zephir_read_property(&_30$$14, this_ptr, SL("_image"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_FUNCTION(NULL, "imagesavealpha", NULL, 247, &_30$$14, &__$true);
		zephir_check_call_status();
		zephir_read_property(&_32$$14, this_ptr, SL("_file"), PH_NOISY_CC | PH_READONLY);
		zephir_update_property_zval(this_ptr, SL("_realpath"), &_32$$14);
		ZEPHIR_INIT_ZVAL_NREF(_33$$14);
		ZVAL_LONG(&_33$$14, width);
		zephir_update_property_zval(this_ptr, SL("_width"), &_33$$14);
		ZEPHIR_INIT_ZVAL_NREF(_33$$14);
		ZVAL_LONG(&_33$$14, height);
		zephir_update_property_zval(this_ptr, SL("_height"), &_33$$14);
		ZEPHIR_INIT_ZVAL_NREF(_33$$14);
		ZVAL_LONG(&_33$$14, 3);
		zephir_update_property_zval(this_ptr, SL("_type"), &_33$$14);
		ZEPHIR_INIT_VAR(&_34$$14);
		ZEPHIR_INIT_NVAR(&_34$$14);
		ZVAL_STRING(&_34$$14, "image/png");
		zephir_update_property_zval(this_ptr, SL("_mime"), &_34$$14);
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Phalcon_Image_Adapter_Gd, _resize) {

	zend_bool _4$$3, _8$$4;
	zval *width_param = NULL, *height_param = NULL, image, pre_width, pre_height, reduction_width, reduction_height, _0, _1, _2, _3$$3, _5$$3, _18$$3, _19$$3, _20$$3, _21$$3, _22$$3, _23$$3, _24$$3, _25$$3, _6$$4, _7$$4, _9$$4, _10$$4, _11$$4, _12$$4, _13$$4, _14$$4, _15$$4, _16$$4, _17$$6, _26$$7, _27$$7, _28$$7, _29$$8, _30$$8, _31$$8, _32$$8, _33$$8;
	zend_long width, height, ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&image);
	ZVAL_UNDEF(&pre_width);
	ZVAL_UNDEF(&pre_height);
	ZVAL_UNDEF(&reduction_width);
	ZVAL_UNDEF(&reduction_height);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_18$$3);
	ZVAL_UNDEF(&_19$$3);
	ZVAL_UNDEF(&_20$$3);
	ZVAL_UNDEF(&_21$$3);
	ZVAL_UNDEF(&_22$$3);
	ZVAL_UNDEF(&_23$$3);
	ZVAL_UNDEF(&_24$$3);
	ZVAL_UNDEF(&_25$$3);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_7$$4);
	ZVAL_UNDEF(&_9$$4);
	ZVAL_UNDEF(&_10$$4);
	ZVAL_UNDEF(&_11$$4);
	ZVAL_UNDEF(&_12$$4);
	ZVAL_UNDEF(&_13$$4);
	ZVAL_UNDEF(&_14$$4);
	ZVAL_UNDEF(&_15$$4);
	ZVAL_UNDEF(&_16$$4);
	ZVAL_UNDEF(&_17$$6);
	ZVAL_UNDEF(&_26$$7);
	ZVAL_UNDEF(&_27$$7);
	ZVAL_UNDEF(&_28$$7);
	ZVAL_UNDEF(&_29$$8);
	ZVAL_UNDEF(&_30$$8);
	ZVAL_UNDEF(&_31$$8);
	ZVAL_UNDEF(&_32$$8);
	ZVAL_UNDEF(&_33$$8);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &width_param, &height_param);

	width = zephir_get_intval(width_param);
	height = zephir_get_intval(height_param);


	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_GET_CONSTANT(&_0, "PHP_VERSION");
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "5.5.0");
	ZEPHIR_CALL_FUNCTION(&_2, "version_compare", NULL, 240, &_0, &_1);
	zephir_check_call_status();
	if (ZEPHIR_LT_LONG(&_2, 0)) {
		ZEPHIR_OBS_VAR(&pre_width);
		zephir_read_property(&pre_width, this_ptr, SL("_width"), PH_NOISY_CC);
		ZEPHIR_OBS_VAR(&pre_height);
		zephir_read_property(&pre_height, this_ptr, SL("_height"), PH_NOISY_CC);
		zephir_read_property(&_3$$3, this_ptr, SL("_width"), PH_NOISY_CC | PH_READONLY);
		_4$$3 = width > (zephir_safe_div_zval_long(&_3$$3, 2 TSRMLS_CC));
		if (_4$$3) {
			zephir_read_property(&_5$$3, this_ptr, SL("_height"), PH_NOISY_CC | PH_READONLY);
			_4$$3 = height > (zephir_safe_div_zval_long(&_5$$3, 2 TSRMLS_CC));
		}
		if (_4$$3) {
			ZVAL_LONG(&_6$$4, (width * 1.1));
			ZEPHIR_INIT_VAR(&reduction_width);
			zephir_round(&reduction_width, &_6$$4, NULL, NULL TSRMLS_CC);
			ZVAL_LONG(&_7$$4, (height * 1.1));
			ZEPHIR_INIT_VAR(&reduction_height);
			zephir_round(&reduction_height, &_7$$4, NULL, NULL TSRMLS_CC);
			while (1) {
				_8$$4 = ZEPHIR_LT_LONG(&reduction_width, zephir_safe_div_zval_long(&pre_width, 2 TSRMLS_CC));
				if (_8$$4) {
					_8$$4 = ZEPHIR_LT_LONG(&reduction_height, zephir_safe_div_zval_long(&pre_height, 2 TSRMLS_CC));
				}
				if (!(_8$$4)) {
					break;
				}
				ZEPHIR_INIT_NVAR(&pre_width);
				ZVAL_DOUBLE(&pre_width, 2);
				ZEPHIR_INIT_NVAR(&pre_height);
				ZVAL_DOUBLE(&pre_height, 2);
			}
			ZEPHIR_CALL_METHOD(&image, this_ptr, "_create", NULL, 0, &pre_width, &pre_height);
			zephir_check_call_status();
			zephir_read_property(&_9$$4, this_ptr, SL("_image"), PH_NOISY_CC | PH_READONLY);
			zephir_read_property(&_10$$4, this_ptr, SL("_width"), PH_NOISY_CC | PH_READONLY);
			zephir_read_property(&_11$$4, this_ptr, SL("_height"), PH_NOISY_CC | PH_READONLY);
			ZVAL_LONG(&_12$$4, 0);
			ZVAL_LONG(&_13$$4, 0);
			ZVAL_LONG(&_14$$4, 0);
			ZVAL_LONG(&_15$$4, 0);
			ZEPHIR_CALL_FUNCTION(&_16$$4, "imagecopyresized", NULL, 250, &image, &_9$$4, &_12$$4, &_13$$4, &_14$$4, &_15$$4, &pre_width, &pre_height, &_10$$4, &_11$$4);
			zephir_check_call_status();
			if (zephir_is_true(&_16$$4)) {
				zephir_read_property(&_17$$6, this_ptr, SL("_image"), PH_NOISY_CC | PH_READONLY);
				ZEPHIR_CALL_FUNCTION(NULL, "imagedestroy", NULL, 251, &_17$$6);
				zephir_check_call_status();
				zephir_update_property_zval(this_ptr, SL("_image"), &image);
			}
		}
		ZVAL_LONG(&_18$$3, width);
		ZVAL_LONG(&_19$$3, height);
		ZEPHIR_CALL_METHOD(&image, this_ptr, "_create", NULL, 0, &_18$$3, &_19$$3);
		zephir_check_call_status();
		zephir_read_property(&_18$$3, this_ptr, SL("_image"), PH_NOISY_CC | PH_READONLY);
		ZVAL_LONG(&_19$$3, 0);
		ZVAL_LONG(&_20$$3, 0);
		ZVAL_LONG(&_21$$3, 0);
		ZVAL_LONG(&_22$$3, 0);
		ZVAL_LONG(&_23$$3, width);
		ZVAL_LONG(&_24$$3, height);
		ZEPHIR_CALL_FUNCTION(&_25$$3, "imagecopyresampled", NULL, 252, &image, &_18$$3, &_19$$3, &_20$$3, &_21$$3, &_22$$3, &_23$$3, &_24$$3, &pre_width, &pre_height);
		zephir_check_call_status();
		if (zephir_is_true(&_25$$3)) {
			zephir_read_property(&_26$$7, this_ptr, SL("_image"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_CALL_FUNCTION(NULL, "imagedestroy", NULL, 251, &_26$$7);
			zephir_check_call_status();
			zephir_update_property_zval(this_ptr, SL("_image"), &image);
			ZEPHIR_CALL_FUNCTION(&_27$$7, "imagesx", NULL, 253, &image);
			zephir_check_call_status();
			zephir_update_property_zval(this_ptr, SL("_width"), &_27$$7);
			ZEPHIR_CALL_FUNCTION(&_28$$7, "imagesy", NULL, 254, &image);
			zephir_check_call_status();
			zephir_update_property_zval(this_ptr, SL("_height"), &_28$$7);
		}
	} else {
		zephir_read_property(&_29$$8, this_ptr, SL("_image"), PH_NOISY_CC | PH_READONLY);
		ZVAL_LONG(&_30$$8, width);
		ZVAL_LONG(&_31$$8, height);
		ZEPHIR_CALL_FUNCTION(&image, "imagescale", NULL, 255, &_29$$8, &_30$$8, &_31$$8);
		zephir_check_call_status();
		zephir_read_property(&_30$$8, this_ptr, SL("_image"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_FUNCTION(NULL, "imagedestroy", NULL, 251, &_30$$8);
		zephir_check_call_status();
		zephir_update_property_zval(this_ptr, SL("_image"), &image);
		ZEPHIR_CALL_FUNCTION(&_32$$8, "imagesx", NULL, 253, &image);
		zephir_check_call_status();
		zephir_update_property_zval(this_ptr, SL("_width"), &_32$$8);
		ZEPHIR_CALL_FUNCTION(&_33$$8, "imagesy", NULL, 254, &image);
		zephir_check_call_status();
		zephir_update_property_zval(this_ptr, SL("_height"), &_33$$8);
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Phalcon_Image_Adapter_Gd, _crop) {

	zval *width_param = NULL, *height_param = NULL, *offsetX_param = NULL, *offsetY_param = NULL, image, rect, _0, _1, _2, _3$$3, _4$$3, _5$$3, _6$$3, _7$$3, _8$$3, _9$$3, _10$$3, _11$$3, _12$$3, _13$$4, _14$$4, _15$$4, _16$$5, _17$$5, _18$$5, _19$$5, _20$$5;
	zend_long width, height, offsetX, offsetY, ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&image);
	ZVAL_UNDEF(&rect);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_7$$3);
	ZVAL_UNDEF(&_8$$3);
	ZVAL_UNDEF(&_9$$3);
	ZVAL_UNDEF(&_10$$3);
	ZVAL_UNDEF(&_11$$3);
	ZVAL_UNDEF(&_12$$3);
	ZVAL_UNDEF(&_13$$4);
	ZVAL_UNDEF(&_14$$4);
	ZVAL_UNDEF(&_15$$4);
	ZVAL_UNDEF(&_16$$5);
	ZVAL_UNDEF(&_17$$5);
	ZVAL_UNDEF(&_18$$5);
	ZVAL_UNDEF(&_19$$5);
	ZVAL_UNDEF(&_20$$5);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 4, 0, &width_param, &height_param, &offsetX_param, &offsetY_param);

	width = zephir_get_intval(width_param);
	height = zephir_get_intval(height_param);
	offsetX = zephir_get_intval(offsetX_param);
	offsetY = zephir_get_intval(offsetY_param);


	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_GET_CONSTANT(&_0, "PHP_VERSION");
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "5.5.0");
	ZEPHIR_CALL_FUNCTION(&_2, "version_compare", NULL, 240, &_0, &_1);
	zephir_check_call_status();
	if (ZEPHIR_LT_LONG(&_2, 0)) {
		ZVAL_LONG(&_3$$3, width);
		ZVAL_LONG(&_4$$3, height);
		ZEPHIR_CALL_METHOD(&image, this_ptr, "_create", NULL, 0, &_3$$3, &_4$$3);
		zephir_check_call_status();
		zephir_read_property(&_3$$3, this_ptr, SL("_image"), PH_NOISY_CC | PH_READONLY);
		ZVAL_LONG(&_4$$3, 0);
		ZVAL_LONG(&_5$$3, 0);
		ZVAL_LONG(&_6$$3, offsetX);
		ZVAL_LONG(&_7$$3, offsetY);
		ZVAL_LONG(&_8$$3, width);
		ZVAL_LONG(&_9$$3, height);
		ZVAL_LONG(&_10$$3, width);
		ZVAL_LONG(&_11$$3, height);
		ZEPHIR_CALL_FUNCTION(&_12$$3, "imagecopyresampled", NULL, 252, &image, &_3$$3, &_4$$3, &_5$$3, &_6$$3, &_7$$3, &_8$$3, &_9$$3, &_10$$3, &_11$$3);
		zephir_check_call_status();
		if (zephir_is_true(&_12$$3)) {
			zephir_read_property(&_13$$4, this_ptr, SL("_image"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_CALL_FUNCTION(NULL, "imagedestroy", NULL, 251, &_13$$4);
			zephir_check_call_status();
			zephir_update_property_zval(this_ptr, SL("_image"), &image);
			ZEPHIR_CALL_FUNCTION(&_14$$4, "imagesx", NULL, 253, &image);
			zephir_check_call_status();
			zephir_update_property_zval(this_ptr, SL("_width"), &_14$$4);
			ZEPHIR_CALL_FUNCTION(&_15$$4, "imagesy", NULL, 254, &image);
			zephir_check_call_status();
			zephir_update_property_zval(this_ptr, SL("_height"), &_15$$4);
		}
	} else {
		ZEPHIR_INIT_VAR(&rect);
		zephir_create_array(&rect, 4, 0 TSRMLS_CC);
		ZEPHIR_INIT_VAR(&_16$$5);
		ZVAL_LONG(&_16$$5, offsetX);
		zephir_array_update_string(&rect, SL("x"), &_16$$5, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_NVAR(&_16$$5);
		ZVAL_LONG(&_16$$5, offsetY);
		zephir_array_update_string(&rect, SL("y"), &_16$$5, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_NVAR(&_16$$5);
		ZVAL_LONG(&_16$$5, width);
		zephir_array_update_string(&rect, SL("width"), &_16$$5, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_NVAR(&_16$$5);
		ZVAL_LONG(&_16$$5, height);
		zephir_array_update_string(&rect, SL("height"), &_16$$5, PH_COPY | PH_SEPARATE);
		zephir_read_property(&_17$$5, this_ptr, SL("_image"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_FUNCTION(&image, "imagecrop", NULL, 256, &_17$$5, &rect);
		zephir_check_call_status();
		zephir_read_property(&_18$$5, this_ptr, SL("_image"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_FUNCTION(NULL, "imagedestroy", NULL, 251, &_18$$5);
		zephir_check_call_status();
		zephir_update_property_zval(this_ptr, SL("_image"), &image);
		ZEPHIR_CALL_FUNCTION(&_19$$5, "imagesx", NULL, 253, &image);
		zephir_check_call_status();
		zephir_update_property_zval(this_ptr, SL("_width"), &_19$$5);
		ZEPHIR_CALL_FUNCTION(&_20$$5, "imagesy", NULL, 254, &image);
		zephir_check_call_status();
		zephir_update_property_zval(this_ptr, SL("_height"), &_20$$5);
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Phalcon_Image_Adapter_Gd, _rotate) {

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

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &degrees_param);

	degrees = zephir_get_intval(degrees_param);


	zephir_read_property(&_0, this_ptr, SL("_image"), PH_NOISY_CC | PH_READONLY);
	ZVAL_LONG(&_1, 0);
	ZVAL_LONG(&_2, 0);
	ZVAL_LONG(&_3, 0);
	ZVAL_LONG(&_4, 127);
	ZEPHIR_CALL_FUNCTION(&transparent, "imagecolorallocatealpha", NULL, 257, &_0, &_1, &_2, &_3, &_4);
	zephir_check_call_status();
	zephir_read_property(&_1, this_ptr, SL("_image"), PH_NOISY_CC | PH_READONLY);
	ZVAL_LONG(&_2, (360 - degrees));
	ZVAL_LONG(&_3, 1);
	ZEPHIR_CALL_FUNCTION(&image, "imagerotate", NULL, 258, &_1, &_2, &transparent, &_3);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(NULL, "imagesavealpha", NULL, 247, &image, &__$true);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&width, "imagesx", NULL, 253, &image);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&height, "imagesy", NULL, 254, &image);
	zephir_check_call_status();
	zephir_read_property(&_2, this_ptr, SL("_image"), PH_NOISY_CC | PH_READONLY);
	ZVAL_LONG(&_3, 0);
	ZVAL_LONG(&_4, 0);
	ZVAL_LONG(&_5, 0);
	ZVAL_LONG(&_6, 0);
	ZVAL_LONG(&_7, 100);
	ZEPHIR_CALL_FUNCTION(&_8, "imagecopymerge", NULL, 259, &_2, &image, &_3, &_4, &_5, &_6, &width, &height, &_7);
	zephir_check_call_status();
	if (zephir_is_true(&_8)) {
		zephir_read_property(&_9$$3, this_ptr, SL("_image"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_FUNCTION(NULL, "imagedestroy", NULL, 251, &_9$$3);
		zephir_check_call_status();
		zephir_update_property_zval(this_ptr, SL("_image"), &image);
		zephir_update_property_zval(this_ptr, SL("_width"), &width);
		zephir_update_property_zval(this_ptr, SL("_height"), &height);
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Phalcon_Image_Adapter_Gd, _flip) {

	zephir_fcall_cache_entry *_14 = NULL;
	zval *direction_param = NULL, image, _0, _1, _2, _3$$3, _4$$3, _24$$3, _25$$3, _26$$3, _5$$4, _6$$5, _7$$5, _8$$5, _9$$5, _10$$5, _11$$5, _12$$5, _13$$5, _15$$6, _16$$7, _17$$7, _18$$7, _19$$7, _20$$7, _21$$7, _22$$7, _23$$7, _27$$9, _28$$9, _29$$10, _30$$10;
	zend_long direction, ZEPHIR_LAST_CALL_STATUS, x = 0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&image);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_24$$3);
	ZVAL_UNDEF(&_25$$3);
	ZVAL_UNDEF(&_26$$3);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_6$$5);
	ZVAL_UNDEF(&_7$$5);
	ZVAL_UNDEF(&_8$$5);
	ZVAL_UNDEF(&_9$$5);
	ZVAL_UNDEF(&_10$$5);
	ZVAL_UNDEF(&_11$$5);
	ZVAL_UNDEF(&_12$$5);
	ZVAL_UNDEF(&_13$$5);
	ZVAL_UNDEF(&_15$$6);
	ZVAL_UNDEF(&_16$$7);
	ZVAL_UNDEF(&_17$$7);
	ZVAL_UNDEF(&_18$$7);
	ZVAL_UNDEF(&_19$$7);
	ZVAL_UNDEF(&_20$$7);
	ZVAL_UNDEF(&_21$$7);
	ZVAL_UNDEF(&_22$$7);
	ZVAL_UNDEF(&_23$$7);
	ZVAL_UNDEF(&_27$$9);
	ZVAL_UNDEF(&_28$$9);
	ZVAL_UNDEF(&_29$$10);
	ZVAL_UNDEF(&_30$$10);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &direction_param);

	direction = zephir_get_intval(direction_param);


	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_GET_CONSTANT(&_0, "PHP_VERSION");
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "5.5.0");
	ZEPHIR_CALL_FUNCTION(&_2, "version_compare", NULL, 240, &_0, &_1);
	zephir_check_call_status();
	if (ZEPHIR_LT_LONG(&_2, 0)) {
		zephir_read_property(&_3$$3, this_ptr, SL("_width"), PH_NOISY_CC | PH_READONLY);
		zephir_read_property(&_4$$3, this_ptr, SL("_height"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(&image, this_ptr, "_create", NULL, 0, &_3$$3, &_4$$3);
		zephir_check_call_status();
		if (direction == 11) {
			x = 0;
			while (1) {
				zephir_read_property(&_5$$4, this_ptr, SL("_width"), PH_NOISY_CC | PH_READONLY);
				if (!(ZEPHIR_GT_LONG(&_5$$4, x))) {
					break;
				}
				x++;
				zephir_read_property(&_6$$5, this_ptr, SL("_image"), PH_NOISY_CC | PH_READONLY);
				zephir_read_property(&_7$$5, this_ptr, SL("_width"), PH_NOISY_CC | PH_READONLY);
				zephir_read_property(&_8$$5, this_ptr, SL("_height"), PH_NOISY_CC | PH_READONLY);
				ZVAL_LONG(&_9$$5, x);
				ZVAL_LONG(&_10$$5, 0);
				ZVAL_LONG(&_11$$5, ((zephir_get_numberval(&_7$$5) - x) - 1));
				ZVAL_LONG(&_12$$5, 0);
				ZVAL_LONG(&_13$$5, 1);
				ZEPHIR_CALL_FUNCTION(NULL, "imagecopy", &_14, 260, &image, &_6$$5, &_9$$5, &_10$$5, &_11$$5, &_12$$5, &_13$$5, &_8$$5);
				zephir_check_call_status();
			}
		} else {
			x = 0;
			while (1) {
				zephir_read_property(&_15$$6, this_ptr, SL("_height"), PH_NOISY_CC | PH_READONLY);
				if (!(ZEPHIR_GT_LONG(&_15$$6, x))) {
					break;
				}
				x++;
				zephir_read_property(&_16$$7, this_ptr, SL("_image"), PH_NOISY_CC | PH_READONLY);
				zephir_read_property(&_17$$7, this_ptr, SL("_height"), PH_NOISY_CC | PH_READONLY);
				zephir_read_property(&_18$$7, this_ptr, SL("_width"), PH_NOISY_CC | PH_READONLY);
				ZVAL_LONG(&_19$$7, 0);
				ZVAL_LONG(&_20$$7, x);
				ZVAL_LONG(&_21$$7, 0);
				ZVAL_LONG(&_22$$7, ((zephir_get_numberval(&_17$$7) - x) - 1));
				ZVAL_LONG(&_23$$7, 1);
				ZEPHIR_CALL_FUNCTION(NULL, "imagecopy", &_14, 260, &image, &_16$$7, &_19$$7, &_20$$7, &_21$$7, &_22$$7, &_18$$7, &_23$$7);
				zephir_check_call_status();
			}
		}
		zephir_read_property(&_24$$3, this_ptr, SL("_image"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_FUNCTION(NULL, "imagedestroy", NULL, 251, &_24$$3);
		zephir_check_call_status();
		zephir_update_property_zval(this_ptr, SL("_image"), &image);
		ZEPHIR_CALL_FUNCTION(&_25$$3, "imagesx", NULL, 253, &image);
		zephir_check_call_status();
		zephir_update_property_zval(this_ptr, SL("_width"), &_25$$3);
		ZEPHIR_CALL_FUNCTION(&_26$$3, "imagesy", NULL, 254, &image);
		zephir_check_call_status();
		zephir_update_property_zval(this_ptr, SL("_height"), &_26$$3);
	} else {
		if (direction == 11) {
			zephir_read_property(&_27$$9, this_ptr, SL("_image"), PH_NOISY_CC | PH_READONLY);
			ZVAL_LONG(&_28$$9, 1);
			ZEPHIR_CALL_FUNCTION(NULL, "imageflip", NULL, 261, &_27$$9, &_28$$9);
			zephir_check_call_status();
		} else {
			zephir_read_property(&_29$$10, this_ptr, SL("_image"), PH_NOISY_CC | PH_READONLY);
			ZVAL_LONG(&_30$$10, 2);
			ZEPHIR_CALL_FUNCTION(NULL, "imageflip", NULL, 261, &_29$$10, &_30$$10);
			zephir_check_call_status();
		}
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Phalcon_Image_Adapter_Gd, _sharpen) {

	zval _3;
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

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &amount_param);

	amount = zephir_get_intval(amount_param);


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_LONG(&_1, (-18 + ((amount * 0.08))));
	ZEPHIR_CALL_FUNCTION(&_2, "abs", NULL, 189, &_1);
	zephir_check_call_status();
	ZVAL_LONG(&_1, 2);
	zephir_round(&_0, &_2, &_1, NULL TSRMLS_CC);
	amount = zephir_get_intval(&_0);
	ZEPHIR_INIT_VAR(&matrix);
	zephir_create_array(&matrix, 3, 0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_3);
	zephir_create_array(&_3, 3, 0 TSRMLS_CC);
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
	zephir_create_array(&_3, 3, 0 TSRMLS_CC);
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
	zephir_create_array(&_3, 3, 0 TSRMLS_CC);
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
	zephir_read_property(&_5, this_ptr, SL("_image"), PH_NOISY_CC | PH_READONLY);
	ZVAL_LONG(&_6, (amount - 8));
	ZVAL_LONG(&_7, 0);
	ZEPHIR_CALL_FUNCTION(&_8, "imageconvolution", NULL, 262, &_5, &matrix, &_6, &_7);
	zephir_check_call_status();
	if (zephir_is_true(&_8)) {
		zephir_read_property(&_9$$3, this_ptr, SL("_image"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_FUNCTION(&_10$$3, "imagesx", NULL, 253, &_9$$3);
		zephir_check_call_status();
		zephir_update_property_zval(this_ptr, SL("_width"), &_10$$3);
		zephir_read_property(&_11$$3, this_ptr, SL("_image"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_FUNCTION(&_12$$3, "imagesy", NULL, 254, &_11$$3);
		zephir_check_call_status();
		zephir_update_property_zval(this_ptr, SL("_height"), &_12$$3);
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Phalcon_Image_Adapter_Gd, _reflection) {

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

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &height_param, &opacity_param, &fadeIn_param);

	height = zephir_get_intval(height_param);
	opacity = zephir_get_intval(opacity_param);
	fadeIn = zephir_get_boolval(fadeIn_param);


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_DOUBLE(&_1, ((zephir_safe_div_long_long((opacity * 127), 100 TSRMLS_CC)) - (double) (127)));
	ZEPHIR_CALL_FUNCTION(&_2, "abs", NULL, 189, &_1);
	zephir_check_call_status();
	zephir_round(&_0, &_2, NULL, NULL TSRMLS_CC);
	opacity = zephir_get_intval(&_0);
	if (opacity < 127) {
		stepping = (long) (zephir_safe_div_long_long(((127 - opacity)), height TSRMLS_CC));
	} else {
		stepping = (long) (zephir_safe_div_long_long(127, height TSRMLS_CC));
	}
	zephir_read_property(&_1, this_ptr, SL("_width"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_3, this_ptr, SL("_height"), PH_NOISY_CC | PH_READONLY);
	ZVAL_LONG(&_4, (zephir_get_numberval(&_3) + height));
	ZEPHIR_CALL_METHOD(&reflection, this_ptr, "_create", NULL, 0, &_1, &_4);
	zephir_check_call_status();
	zephir_read_property(&_4, this_ptr, SL("_image"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_5, this_ptr, SL("_width"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_6, this_ptr, SL("_height"), PH_NOISY_CC | PH_READONLY);
	ZVAL_LONG(&_7, 0);
	ZVAL_LONG(&_8, 0);
	ZVAL_LONG(&_9, 0);
	ZVAL_LONG(&_10, 0);
	ZEPHIR_CALL_FUNCTION(NULL, "imagecopy", NULL, 260, &reflection, &_4, &_7, &_8, &_9, &_10, &_5, &_6);
	zephir_check_call_status();
	offset = 0;
	while (1) {
		if (!(height >= offset)) {
			break;
		}
		zephir_read_property(&_11$$5, this_ptr, SL("_height"), PH_NOISY_CC | PH_READONLY);
		src_y = ((zephir_get_numberval(&_11$$5) - offset) - 1);
		zephir_read_property(&_12$$5, this_ptr, SL("_height"), PH_NOISY_CC | PH_READONLY);
		dst_y = (zephir_get_numberval(&_12$$5) + offset);
		if (fadeIn) {
			ZEPHIR_INIT_NVAR(&_13$$6);
			ZVAL_LONG(&_14$$6, (opacity + ((stepping * ((height - offset))))));
			zephir_round(&_13$$6, &_14$$6, NULL, NULL TSRMLS_CC);
			dst_opacity = zephir_get_intval(&_13$$6);
		} else {
			ZEPHIR_INIT_NVAR(&_15$$7);
			ZVAL_LONG(&_16$$7, (opacity + ((stepping * offset))));
			zephir_round(&_15$$7, &_16$$7, NULL, NULL TSRMLS_CC);
			dst_opacity = zephir_get_intval(&_15$$7);
		}
		zephir_read_property(&_17$$5, this_ptr, SL("_width"), PH_NOISY_CC | PH_READONLY);
		ZVAL_LONG(&_18$$5, 1);
		ZEPHIR_CALL_METHOD(&line, this_ptr, "_create", NULL, 0, &_17$$5, &_18$$5);
		zephir_check_call_status();
		zephir_read_property(&_18$$5, this_ptr, SL("_image"), PH_NOISY_CC | PH_READONLY);
		zephir_read_property(&_19$$5, this_ptr, SL("_width"), PH_NOISY_CC | PH_READONLY);
		ZVAL_LONG(&_20$$5, 0);
		ZVAL_LONG(&_21$$5, 0);
		ZVAL_LONG(&_22$$5, 0);
		ZVAL_LONG(&_23$$5, src_y);
		ZVAL_LONG(&_24$$5, 1);
		ZEPHIR_CALL_FUNCTION(NULL, "imagecopy", NULL, 260, &line, &_18$$5, &_20$$5, &_21$$5, &_22$$5, &_23$$5, &_19$$5, &_24$$5);
		zephir_check_call_status();
		ZVAL_LONG(&_20$$5, 4);
		ZVAL_LONG(&_21$$5, 0);
		ZVAL_LONG(&_22$$5, 0);
		ZVAL_LONG(&_23$$5, 0);
		ZVAL_LONG(&_24$$5, dst_opacity);
		ZEPHIR_CALL_FUNCTION(NULL, "imagefilter", &_25, 263, &line, &_20$$5, &_21$$5, &_22$$5, &_23$$5, &_24$$5);
		zephir_check_call_status();
		zephir_read_property(&_20$$5, this_ptr, SL("_width"), PH_NOISY_CC | PH_READONLY);
		ZVAL_LONG(&_21$$5, 0);
		ZVAL_LONG(&_22$$5, dst_y);
		ZVAL_LONG(&_23$$5, 0);
		ZVAL_LONG(&_24$$5, 0);
		ZVAL_LONG(&_26$$5, 1);
		ZEPHIR_CALL_FUNCTION(NULL, "imagecopy", NULL, 260, &reflection, &line, &_21$$5, &_22$$5, &_23$$5, &_24$$5, &_20$$5, &_26$$5);
		zephir_check_call_status();
		offset++;
	}
	zephir_read_property(&_7, this_ptr, SL("_image"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_FUNCTION(NULL, "imagedestroy", NULL, 251, &_7);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, SL("_image"), &reflection);
	ZEPHIR_CALL_FUNCTION(&_27, "imagesx", NULL, 253, &reflection);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, SL("_width"), &_27);
	ZEPHIR_CALL_FUNCTION(&_28, "imagesy", NULL, 254, &reflection);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, SL("_height"), &_28);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Phalcon_Image_Adapter_Gd, _watermark) {

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

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 4, 0, &watermark, &offsetX_param, &offsetY_param, &opacity_param);

	offsetX = zephir_get_intval(offsetX_param);
	offsetY = zephir_get_intval(offsetY_param);
	opacity = zephir_get_intval(opacity_param);


	ZEPHIR_CALL_METHOD(&_0, watermark, "render", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&overlay, "imagecreatefromstring", NULL, 264, &_0);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(NULL, "imagesavealpha", NULL, 247, &overlay, &__$true);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&_1, "imagesx", NULL, 253, &overlay);
	zephir_check_call_status();
	width = zephir_get_intval(&_1);
	ZEPHIR_CALL_FUNCTION(&_2, "imagesy", NULL, 254, &overlay);
	zephir_check_call_status();
	height = zephir_get_intval(&_2);
	if (opacity < 100) {
		ZEPHIR_INIT_VAR(&_3$$3);
		ZVAL_DOUBLE(&_4$$3, ((zephir_safe_div_long_long((opacity * 127), 100 TSRMLS_CC)) - (double) (127)));
		ZEPHIR_CALL_FUNCTION(&_5$$3, "abs", NULL, 189, &_4$$3);
		zephir_check_call_status();
		zephir_round(&_3$$3, &_5$$3, NULL, NULL TSRMLS_CC);
		opacity = zephir_get_intval(&_3$$3);
		ZVAL_LONG(&_4$$3, 127);
		ZVAL_LONG(&_6$$3, 127);
		ZVAL_LONG(&_7$$3, 127);
		ZVAL_LONG(&_8$$3, opacity);
		ZEPHIR_CALL_FUNCTION(&color, "imagecolorallocatealpha", NULL, 257, &overlay, &_4$$3, &_6$$3, &_7$$3, &_8$$3);
		zephir_check_call_status();
		ZVAL_LONG(&_4$$3, 3);
		ZEPHIR_CALL_FUNCTION(NULL, "imagelayereffect", NULL, 265, &overlay, &_4$$3);
		zephir_check_call_status();
		ZVAL_LONG(&_4$$3, 0);
		ZVAL_LONG(&_6$$3, 0);
		ZVAL_LONG(&_7$$3, width);
		ZVAL_LONG(&_8$$3, height);
		ZEPHIR_CALL_FUNCTION(NULL, "imagefilledrectangle", NULL, 266, &overlay, &_4$$3, &_6$$3, &_7$$3, &_8$$3, &color);
		zephir_check_call_status();
	}
	zephir_read_property(&_9, this_ptr, SL("_image"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_FUNCTION(NULL, "imagealphablending", NULL, 249, &_9, &__$true);
	zephir_check_call_status();
	zephir_read_property(&_10, this_ptr, SL("_image"), PH_NOISY_CC | PH_READONLY);
	ZVAL_LONG(&_11, offsetX);
	ZVAL_LONG(&_12, offsetY);
	ZVAL_LONG(&_13, 0);
	ZVAL_LONG(&_14, 0);
	ZVAL_LONG(&_15, width);
	ZVAL_LONG(&_16, height);
	ZEPHIR_CALL_FUNCTION(&_17, "imagecopy", NULL, 260, &_10, &overlay, &_11, &_12, &_13, &_14, &_15, &_16);
	zephir_check_call_status();
	if (zephir_is_true(&_17)) {
		ZEPHIR_CALL_FUNCTION(NULL, "imagedestroy", NULL, 251, &overlay);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Phalcon_Image_Adapter_Gd, _text) {

	zend_bool _9$$3, _10$$3, _11$$3;
	zend_long offsetX, offsetY, opacity, r, g, b, size, ZEPHIR_LAST_CALL_STATUS, angle = 0, s0, s1, s4, s5, width = 0, height = 0;
	zval *text_param = NULL, *offsetX_param = NULL, *offsetY_param = NULL, *opacity_param = NULL, *r_param = NULL, *g_param = NULL, *b_param = NULL, *size_param = NULL, *fontfile_param = NULL, space, color, _0, _1, _2, _3$$3, _4$$3, _12$$3, _13$$3, _16$$3, _17$$3, _18$$3, _19$$3, _5$$4, _6$$4, _7$$4, _8$$4, _14$$6, _15$$7, _20$$8, _21$$8, _22$$8, _25$$8, _26$$8, _27$$8, _28$$8, _23$$9, _24$$10;
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
	ZVAL_UNDEF(&_12$$3);
	ZVAL_UNDEF(&_13$$3);
	ZVAL_UNDEF(&_16$$3);
	ZVAL_UNDEF(&_17$$3);
	ZVAL_UNDEF(&_18$$3);
	ZVAL_UNDEF(&_19$$3);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_7$$4);
	ZVAL_UNDEF(&_8$$4);
	ZVAL_UNDEF(&_14$$6);
	ZVAL_UNDEF(&_15$$7);
	ZVAL_UNDEF(&_20$$8);
	ZVAL_UNDEF(&_21$$8);
	ZVAL_UNDEF(&_22$$8);
	ZVAL_UNDEF(&_25$$8);
	ZVAL_UNDEF(&_26$$8);
	ZVAL_UNDEF(&_27$$8);
	ZVAL_UNDEF(&_28$$8);
	ZVAL_UNDEF(&_23$$9);
	ZVAL_UNDEF(&_24$$10);

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


	s0 = 0;
	s1 = 0;
	s4 = 0;
	s5 = 0;
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_DOUBLE(&_1, ((zephir_safe_div_long_long((opacity * 127), 100 TSRMLS_CC)) - (double) (127)));
	ZEPHIR_CALL_FUNCTION(&_2, "abs", NULL, 189, &_1);
	zephir_check_call_status();
	zephir_round(&_0, &_2, NULL, NULL TSRMLS_CC);
	opacity = zephir_get_intval(&_0);
	if (!(Z_TYPE_P(&fontfile) == IS_UNDEF) && Z_STRLEN_P(&fontfile)) {
		ZVAL_LONG(&_3$$3, size);
		ZVAL_LONG(&_4$$3, 0);
		ZEPHIR_CALL_FUNCTION(&space, "imagettfbbox", NULL, 0, &_3$$3, &_4$$3, &fontfile, &text);
		zephir_check_call_status();
		if (zephir_array_isset_long(&space, 0)) {
			ZEPHIR_OBS_VAR(&_5$$4);
			zephir_array_fetch_long(&_5$$4, &space, 0, PH_NOISY, "phalcon/image/adapter/gd.zep", 341 TSRMLS_CC);
			s0 = zephir_get_intval(&_5$$4);
			ZEPHIR_OBS_VAR(&_6$$4);
			zephir_array_fetch_long(&_6$$4, &space, 1, PH_NOISY, "phalcon/image/adapter/gd.zep", 342 TSRMLS_CC);
			s1 = zephir_get_intval(&_6$$4);
			ZEPHIR_OBS_VAR(&_7$$4);
			zephir_array_fetch_long(&_7$$4, &space, 4, PH_NOISY, "phalcon/image/adapter/gd.zep", 343 TSRMLS_CC);
			s4 = zephir_get_intval(&_7$$4);
			ZEPHIR_OBS_VAR(&_8$$4);
			zephir_array_fetch_long(&_8$$4, &space, 5, PH_NOISY, "phalcon/image/adapter/gd.zep", 344 TSRMLS_CC);
			s5 = zephir_get_intval(&_8$$4);
		}
		_9$$3 = !s0;
		if (!(_9$$3)) {
			_9$$3 = !s1;
		}
		_10$$3 = _9$$3;
		if (!(_10$$3)) {
			_10$$3 = !s4;
		}
		_11$$3 = _10$$3;
		if (!(_11$$3)) {
			_11$$3 = !s5;
		}
		if (_11$$3) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_image_exception_ce, "Call to imagettfbbox() failed", "phalcon/image/adapter/gd.zep", 348);
			return;
		}
		ZVAL_LONG(&_3$$3, (s4 - s0));
		ZEPHIR_CALL_FUNCTION(&_12$$3, "abs", NULL, 189, &_3$$3);
		zephir_check_call_status();
		width = (zephir_get_numberval(&_12$$3) + 10);
		ZVAL_LONG(&_3$$3, (s5 - s1));
		ZEPHIR_CALL_FUNCTION(&_13$$3, "abs", NULL, 189, &_3$$3);
		zephir_check_call_status();
		height = (zephir_get_numberval(&_13$$3) + 10);
		if (offsetX < 0) {
			zephir_read_property(&_14$$6, this_ptr, SL("_width"), PH_NOISY_CC | PH_READONLY);
			offsetX = ((zephir_get_numberval(&_14$$6) - width) + offsetX);
		}
		if (offsetY < 0) {
			zephir_read_property(&_15$$7, this_ptr, SL("_height"), PH_NOISY_CC | PH_READONLY);
			offsetY = ((zephir_get_numberval(&_15$$7) - height) + offsetY);
		}
		zephir_read_property(&_3$$3, this_ptr, SL("_image"), PH_NOISY_CC | PH_READONLY);
		ZVAL_LONG(&_4$$3, r);
		ZVAL_LONG(&_16$$3, g);
		ZVAL_LONG(&_17$$3, b);
		ZVAL_LONG(&_18$$3, opacity);
		ZEPHIR_CALL_FUNCTION(&color, "imagecolorallocatealpha", NULL, 257, &_3$$3, &_4$$3, &_16$$3, &_17$$3, &_18$$3);
		zephir_check_call_status();
		angle = 0;
		zephir_read_property(&_4$$3, this_ptr, SL("_image"), PH_NOISY_CC | PH_READONLY);
		ZVAL_LONG(&_16$$3, size);
		ZVAL_LONG(&_17$$3, angle);
		ZVAL_LONG(&_18$$3, offsetX);
		ZVAL_LONG(&_19$$3, offsetY);
		ZEPHIR_CALL_FUNCTION(NULL, "imagettftext", NULL, 0, &_4$$3, &_16$$3, &_17$$3, &_18$$3, &_19$$3, &color, &fontfile, &text);
		zephir_check_call_status();
	} else {
		ZVAL_LONG(&_20$$8, size);
		ZEPHIR_CALL_FUNCTION(&_21$$8, "imagefontwidth", NULL, 267, &_20$$8);
		zephir_check_call_status();
		width = (zephir_get_intval(&_21$$8) * zephir_fast_strlen_ev(&text));
		ZVAL_LONG(&_20$$8, size);
		ZEPHIR_CALL_FUNCTION(&_22$$8, "imagefontheight", NULL, 268, &_20$$8);
		zephir_check_call_status();
		height = zephir_get_intval(&_22$$8);
		if (offsetX < 0) {
			zephir_read_property(&_23$$9, this_ptr, SL("_width"), PH_NOISY_CC | PH_READONLY);
			offsetX = ((zephir_get_numberval(&_23$$9) - width) + offsetX);
		}
		if (offsetY < 0) {
			zephir_read_property(&_24$$10, this_ptr, SL("_height"), PH_NOISY_CC | PH_READONLY);
			offsetY = ((zephir_get_numberval(&_24$$10) - height) + offsetY);
		}
		zephir_read_property(&_20$$8, this_ptr, SL("_image"), PH_NOISY_CC | PH_READONLY);
		ZVAL_LONG(&_25$$8, r);
		ZVAL_LONG(&_26$$8, g);
		ZVAL_LONG(&_27$$8, b);
		ZVAL_LONG(&_28$$8, opacity);
		ZEPHIR_CALL_FUNCTION(&color, "imagecolorallocatealpha", NULL, 257, &_20$$8, &_25$$8, &_26$$8, &_27$$8, &_28$$8);
		zephir_check_call_status();
		zephir_read_property(&_25$$8, this_ptr, SL("_image"), PH_NOISY_CC | PH_READONLY);
		ZVAL_LONG(&_26$$8, size);
		ZVAL_LONG(&_27$$8, offsetX);
		ZVAL_LONG(&_28$$8, offsetY);
		ZEPHIR_CALL_FUNCTION(NULL, "imagestring", NULL, 269, &_25$$8, &_26$$8, &_27$$8, &_28$$8, &text, &color);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Phalcon_Image_Adapter_Gd, _mask) {

	zend_bool _9;
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

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &mask);



	ZEPHIR_CALL_METHOD(&_0, mask, "render", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&maskImage, "imagecreatefromstring", NULL, 264, &_0);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&_1, "imagesx", NULL, 253, &maskImage);
	zephir_check_call_status();
	mask_width = zephir_get_intval(&_1);
	ZEPHIR_CALL_FUNCTION(&_2, "imagesy", NULL, 254, &maskImage);
	zephir_check_call_status();
	mask_height = zephir_get_intval(&_2);
	alpha = 127;
	ZEPHIR_CALL_FUNCTION(NULL, "imagesavealpha", NULL, 247, &maskImage, &__$true);
	zephir_check_call_status();
	zephir_read_property(&_3, this_ptr, SL("_width"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_4, this_ptr, SL("_height"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&newimage, this_ptr, "_create", NULL, 0, &_3, &_4);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(NULL, "imagesavealpha", NULL, 247, &newimage, &__$true);
	zephir_check_call_status();
	ZVAL_LONG(&_5, 0);
	ZVAL_LONG(&_6, 0);
	ZVAL_LONG(&_7, 0);
	ZVAL_LONG(&_8, alpha);
	ZEPHIR_CALL_FUNCTION(&color, "imagecolorallocatealpha", NULL, 257, &newimage, &_5, &_6, &_7, &_8);
	zephir_check_call_status();
	ZVAL_LONG(&_5, 0);
	ZVAL_LONG(&_6, 0);
	ZEPHIR_CALL_FUNCTION(NULL, "imagefill", NULL, 270, &newimage, &_5, &_6, &color);
	zephir_check_call_status();
	zephir_read_property(&_5, this_ptr, SL("_width"), PH_NOISY_CC | PH_READONLY);
	_9 = !ZEPHIR_IS_LONG(&_5, mask_width);
	if (!(_9)) {
		zephir_read_property(&_6, this_ptr, SL("_height"), PH_NOISY_CC | PH_READONLY);
		_9 = !ZEPHIR_IS_LONG(&_6, mask_height);
	}
	if (_9) {
		zephir_read_property(&_10$$3, this_ptr, SL("_width"), PH_NOISY_CC | PH_READONLY);
		zephir_read_property(&_11$$3, this_ptr, SL("_height"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_FUNCTION(&tempImage, "imagecreatetruecolor", NULL, 248, &_10$$3, &_11$$3);
		zephir_check_call_status();
		zephir_read_property(&_12$$3, this_ptr, SL("_width"), PH_NOISY_CC | PH_READONLY);
		zephir_read_property(&_13$$3, this_ptr, SL("_height"), PH_NOISY_CC | PH_READONLY);
		ZVAL_LONG(&_14$$3, 0);
		ZVAL_LONG(&_15$$3, 0);
		ZVAL_LONG(&_16$$3, 0);
		ZVAL_LONG(&_17$$3, 0);
		ZVAL_LONG(&_18$$3, mask_width);
		ZVAL_LONG(&_19$$3, mask_height);
		ZEPHIR_CALL_FUNCTION(NULL, "imagecopyresampled", NULL, 252, &tempImage, &maskImage, &_14$$3, &_15$$3, &_16$$3, &_17$$3, &_12$$3, &_13$$3, &_18$$3, &_19$$3);
		zephir_check_call_status();
		ZEPHIR_CALL_FUNCTION(NULL, "imagedestroy", NULL, 251, &maskImage);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(&maskImage, &tempImage);
	}
	x = 0;
	while (1) {
		zephir_read_property(&_7, this_ptr, SL("_width"), PH_NOISY_CC | PH_READONLY);
		if (!(ZEPHIR_GT_LONG(&_7, x))) {
			break;
		}
		y = 0;
		while (1) {
			zephir_read_property(&_20$$4, this_ptr, SL("_height"), PH_NOISY_CC | PH_READONLY);
			if (!(ZEPHIR_GT_LONG(&_20$$4, y))) {
				break;
			}
			ZVAL_LONG(&_21$$5, x);
			ZVAL_LONG(&_22$$5, y);
			ZEPHIR_CALL_FUNCTION(&index, "imagecolorat", &_23, 271, &maskImage, &_21$$5, &_22$$5);
			zephir_check_call_status();
			ZEPHIR_CALL_FUNCTION(&color, "imagecolorsforindex", &_24, 272, &maskImage, &index);
			zephir_check_call_status();
			if (zephir_array_isset_string(&color, SL("red"))) {
				zephir_array_fetch_string(&_25$$6, &color, SL("red"), PH_NOISY | PH_READONLY, "phalcon/image/adapter/gd.zep", 421 TSRMLS_CC);
				ZVAL_DOUBLE(&_26$$6, zephir_safe_div_zval_long(&_25$$6, 2 TSRMLS_CC));
				alpha = (127 - zephir_get_intval(&_26$$6));
			}
			zephir_read_property(&_21$$5, this_ptr, SL("_image"), PH_NOISY_CC | PH_READONLY);
			ZVAL_LONG(&_22$$5, x);
			ZVAL_LONG(&_27$$5, y);
			ZEPHIR_CALL_FUNCTION(&index, "imagecolorat", &_23, 271, &_21$$5, &_22$$5, &_27$$5);
			zephir_check_call_status();
			zephir_read_property(&_22$$5, this_ptr, SL("_image"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_CALL_FUNCTION(&color, "imagecolorsforindex", &_24, 272, &_22$$5, &index);
			zephir_check_call_status();
			ZEPHIR_OBS_NVAR(&r);
			zephir_array_fetch_string(&r, &color, SL("red"), PH_NOISY, "phalcon/image/adapter/gd.zep", 426 TSRMLS_CC);
			ZEPHIR_OBS_NVAR(&g);
			zephir_array_fetch_string(&g, &color, SL("green"), PH_NOISY, "phalcon/image/adapter/gd.zep", 426 TSRMLS_CC);
			ZEPHIR_OBS_NVAR(&b);
			zephir_array_fetch_string(&b, &color, SL("blue"), PH_NOISY, "phalcon/image/adapter/gd.zep", 426 TSRMLS_CC);
			ZVAL_LONG(&_27$$5, alpha);
			ZEPHIR_CALL_FUNCTION(&color, "imagecolorallocatealpha", NULL, 257, &newimage, &r, &g, &b, &_27$$5);
			zephir_check_call_status();
			ZVAL_LONG(&_27$$5, x);
			ZVAL_LONG(&_28$$5, y);
			ZEPHIR_CALL_FUNCTION(NULL, "imagesetpixel", &_29, 273, &newimage, &_27$$5, &_28$$5, &color);
			zephir_check_call_status();
			y++;
		}
		x++;
	}
	zephir_read_property(&_8, this_ptr, SL("_image"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_FUNCTION(NULL, "imagedestroy", NULL, 251, &_8);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(NULL, "imagedestroy", NULL, 251, &maskImage);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, SL("_image"), &newimage);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Phalcon_Image_Adapter_Gd, _background) {

	zval *r_param = NULL, *g_param = NULL, *b_param = NULL, *opacity_param = NULL, __$true, background, color, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10$$3;
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
	ZVAL_UNDEF(&_10$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 4, 0, &r_param, &g_param, &b_param, &opacity_param);

	r = zephir_get_intval(r_param);
	g = zephir_get_intval(g_param);
	b = zephir_get_intval(b_param);
	opacity = zephir_get_intval(opacity_param);


	opacity = (long) (((zephir_safe_div_long_long((opacity * 127), 100 TSRMLS_CC)) - (double) (127)));
	zephir_read_property(&_0, this_ptr, SL("_width"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_1, this_ptr, SL("_height"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&background, this_ptr, "_create", NULL, 0, &_0, &_1);
	zephir_check_call_status();
	ZVAL_LONG(&_2, r);
	ZVAL_LONG(&_3, g);
	ZVAL_LONG(&_4, b);
	ZVAL_LONG(&_5, opacity);
	ZEPHIR_CALL_FUNCTION(&color, "imagecolorallocatealpha", NULL, 257, &background, &_2, &_3, &_4, &_5);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(NULL, "imagealphablending", NULL, 249, &background, &__$true);
	zephir_check_call_status();
	zephir_read_property(&_2, this_ptr, SL("_image"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_3, this_ptr, SL("_width"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_4, this_ptr, SL("_height"), PH_NOISY_CC | PH_READONLY);
	ZVAL_LONG(&_5, 0);
	ZVAL_LONG(&_6, 0);
	ZVAL_LONG(&_7, 0);
	ZVAL_LONG(&_8, 0);
	ZEPHIR_CALL_FUNCTION(&_9, "imagecopy", NULL, 260, &background, &_2, &_5, &_6, &_7, &_8, &_3, &_4);
	zephir_check_call_status();
	if (zephir_is_true(&_9)) {
		zephir_read_property(&_10$$3, this_ptr, SL("_image"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_FUNCTION(NULL, "imagedestroy", NULL, 251, &_10$$3);
		zephir_check_call_status();
		zephir_update_property_zval(this_ptr, SL("_image"), &background);
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Phalcon_Image_Adapter_Gd, _blur) {

	zephir_fcall_cache_entry *_2 = NULL;
	zval *radius_param = NULL, _0$$3, _1$$3;
	zend_long radius, ZEPHIR_LAST_CALL_STATUS, i = 0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &radius_param);

	radius = zephir_get_intval(radius_param);


	i = 0;
	while (1) {
		if (!(i < radius)) {
			break;
		}
		zephir_read_property(&_0$$3, this_ptr, SL("_image"), PH_NOISY_CC | PH_READONLY);
		ZVAL_LONG(&_1$$3, 7);
		ZEPHIR_CALL_FUNCTION(NULL, "imagefilter", &_2, 263, &_0$$3, &_1$$3);
		zephir_check_call_status();
		i++;
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Phalcon_Image_Adapter_Gd, _pixelate) {

	zephir_fcall_cache_entry *_5 = NULL, *_9 = NULL;
	zval *amount_param = NULL, color, _0, _1$$3, _2$$4, _3$$4, _4$$4, _6$$4, _7$$4, _8$$4;
	zend_long amount, ZEPHIR_LAST_CALL_STATUS, x = 0, y = 0, x1 = 0, y1 = 0, x2 = 0, y2 = 0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&color);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_7$$4);
	ZVAL_UNDEF(&_8$$4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &amount_param);

	amount = zephir_get_intval(amount_param);


	x = 0;
	while (1) {
		zephir_read_property(&_0, this_ptr, SL("_width"), PH_NOISY_CC | PH_READONLY);
		if (!(ZEPHIR_GT_LONG(&_0, x))) {
			break;
		}
		y = 0;
		while (1) {
			zephir_read_property(&_1$$3, this_ptr, SL("_height"), PH_NOISY_CC | PH_READONLY);
			if (!(ZEPHIR_GT_LONG(&_1$$3, y))) {
				break;
			}
			x1 = (x + zephir_safe_div_long_long(amount, 2 TSRMLS_CC));
			y1 = (y + zephir_safe_div_long_long(amount, 2 TSRMLS_CC));
			zephir_read_property(&_2$$4, this_ptr, SL("_image"), PH_NOISY_CC | PH_READONLY);
			ZVAL_LONG(&_3$$4, x1);
			ZVAL_LONG(&_4$$4, y1);
			ZEPHIR_CALL_FUNCTION(&color, "imagecolorat", &_5, 271, &_2$$4, &_3$$4, &_4$$4);
			zephir_check_call_status();
			x2 = (x + amount);
			y2 = (y + amount);
			zephir_read_property(&_3$$4, this_ptr, SL("_image"), PH_NOISY_CC | PH_READONLY);
			ZVAL_LONG(&_4$$4, x);
			ZVAL_LONG(&_6$$4, y);
			ZVAL_LONG(&_7$$4, x2);
			ZVAL_LONG(&_8$$4, y2);
			ZEPHIR_CALL_FUNCTION(NULL, "imagefilledrectangle", &_9, 266, &_3$$4, &_4$$4, &_6$$4, &_7$$4, &_8$$4, &color);
			zephir_check_call_status();
			y += amount;
		}
		x += amount;
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Phalcon_Image_Adapter_Gd, _save) {

	zend_bool _8;
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

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &file_param, &quality_param);

	zephir_get_strval(&file, file_param);
	quality = zephir_get_intval(quality_param);


	ZVAL_LONG(&_0, 4);
	ZEPHIR_CALL_FUNCTION(&ext, "pathinfo", NULL, 64, &file, &_0);
	zephir_check_call_status();
	if (!(zephir_is_true(&ext))) {
		zephir_read_property(&_1$$3, this_ptr, SL("_type"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_FUNCTION(&ext, "image_type_to_extension", NULL, 274, &_1$$3, &__$false);
		zephir_check_call_status();
	}
	ZEPHIR_INIT_VAR(&_2);
	zephir_fast_strtolower(&_2, &ext);
	ZEPHIR_CPY_WRT(&ext, &_2);
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_STRING(&_2, "gif");
	ZEPHIR_CALL_FUNCTION(&_3, "strcmp", NULL, 275, &ext, &_2);
	zephir_check_call_status();
	if (ZEPHIR_IS_LONG(&_3, 0)) {
		ZEPHIR_INIT_ZVAL_NREF(_4$$4);
		ZVAL_LONG(&_4$$4, 1);
		zephir_update_property_zval(this_ptr, SL("_type"), &_4$$4);
		zephir_read_property(&_4$$4, this_ptr, SL("_type"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_FUNCTION(&_5$$4, "image_type_to_mime_type", NULL, 276, &_4$$4);
		zephir_check_call_status();
		zephir_update_property_zval(this_ptr, SL("_mime"), &_5$$4);
		zephir_read_property(&_6$$4, this_ptr, SL("_image"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_FUNCTION(NULL, "imagegif", NULL, 277, &_6$$4, &file);
		zephir_check_call_status();
		RETURN_MM_BOOL(1);
	}
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_STRING(&_2, "jpg");
	ZEPHIR_CALL_FUNCTION(&_7, "strcmp", NULL, 275, &ext, &_2);
	zephir_check_call_status();
	_8 = ZEPHIR_IS_LONG(&_7, 0);
	if (!(_8)) {
		ZEPHIR_INIT_NVAR(&_2);
		ZVAL_STRING(&_2, "jpeg");
		ZEPHIR_CALL_FUNCTION(&_9, "strcmp", NULL, 275, &ext, &_2);
		zephir_check_call_status();
		_8 = ZEPHIR_IS_LONG(&_9, 0);
	}
	if (_8) {
		ZEPHIR_INIT_ZVAL_NREF(_10$$5);
		ZVAL_LONG(&_10$$5, 2);
		zephir_update_property_zval(this_ptr, SL("_type"), &_10$$5);
		zephir_read_property(&_10$$5, this_ptr, SL("_type"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_FUNCTION(&_11$$5, "image_type_to_mime_type", NULL, 276, &_10$$5);
		zephir_check_call_status();
		zephir_update_property_zval(this_ptr, SL("_mime"), &_11$$5);
		if (quality >= 0) {
			if (quality < 1) {
				quality = 1;
			} else if (quality > 100) {
				quality = 100;
			}
			zephir_read_property(&_12$$6, this_ptr, SL("_image"), PH_NOISY_CC | PH_READONLY);
			ZVAL_LONG(&_13$$6, quality);
			ZEPHIR_CALL_FUNCTION(NULL, "imagejpeg", NULL, 278, &_12$$6, &file, &_13$$6);
			zephir_check_call_status();
		} else {
			zephir_read_property(&_14$$9, this_ptr, SL("_image"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_CALL_FUNCTION(NULL, "imagejpeg", NULL, 278, &_14$$9, &file);
			zephir_check_call_status();
		}
		RETURN_MM_BOOL(1);
	}
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_STRING(&_2, "png");
	ZEPHIR_CALL_FUNCTION(&_15, "strcmp", NULL, 275, &ext, &_2);
	zephir_check_call_status();
	if (ZEPHIR_IS_LONG(&_15, 0)) {
		ZEPHIR_INIT_ZVAL_NREF(_16$$10);
		ZVAL_LONG(&_16$$10, 3);
		zephir_update_property_zval(this_ptr, SL("_type"), &_16$$10);
		zephir_read_property(&_16$$10, this_ptr, SL("_type"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_FUNCTION(&_17$$10, "image_type_to_mime_type", NULL, 276, &_16$$10);
		zephir_check_call_status();
		zephir_update_property_zval(this_ptr, SL("_mime"), &_17$$10);
		zephir_read_property(&_18$$10, this_ptr, SL("_image"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_FUNCTION(NULL, "imagepng", NULL, 279, &_18$$10, &file);
		zephir_check_call_status();
		RETURN_MM_BOOL(1);
	}
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_STRING(&_2, "wbmp");
	ZEPHIR_CALL_FUNCTION(&_19, "strcmp", NULL, 275, &ext, &_2);
	zephir_check_call_status();
	if (ZEPHIR_IS_LONG(&_19, 0)) {
		ZEPHIR_INIT_ZVAL_NREF(_20$$11);
		ZVAL_LONG(&_20$$11, 15);
		zephir_update_property_zval(this_ptr, SL("_type"), &_20$$11);
		zephir_read_property(&_20$$11, this_ptr, SL("_type"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_FUNCTION(&_21$$11, "image_type_to_mime_type", NULL, 276, &_20$$11);
		zephir_check_call_status();
		zephir_update_property_zval(this_ptr, SL("_mime"), &_21$$11);
		zephir_read_property(&_22$$11, this_ptr, SL("_image"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_FUNCTION(NULL, "imagewbmp", NULL, 280, &_22$$11, &file);
		zephir_check_call_status();
		RETURN_MM_BOOL(1);
	}
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_STRING(&_2, "xbm");
	ZEPHIR_CALL_FUNCTION(&_23, "strcmp", NULL, 275, &ext, &_2);
	zephir_check_call_status();
	if (ZEPHIR_IS_LONG(&_23, 0)) {
		ZEPHIR_INIT_ZVAL_NREF(_24$$12);
		ZVAL_LONG(&_24$$12, 16);
		zephir_update_property_zval(this_ptr, SL("_type"), &_24$$12);
		zephir_read_property(&_24$$12, this_ptr, SL("_type"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_FUNCTION(&_25$$12, "image_type_to_mime_type", NULL, 276, &_24$$12);
		zephir_check_call_status();
		zephir_update_property_zval(this_ptr, SL("_mime"), &_25$$12);
		zephir_read_property(&_26$$12, this_ptr, SL("_image"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_FUNCTION(NULL, "imagexbm", NULL, 281, &_26$$12, &file);
		zephir_check_call_status();
		RETURN_MM_BOOL(1);
	}
	ZEPHIR_INIT_NVAR(&_2);
	object_init_ex(&_2, phalcon_image_exception_ce);
	ZEPHIR_INIT_VAR(&_27);
	ZEPHIR_CONCAT_SVS(&_27, "Installed GD does not support '", &ext, "' images");
	ZEPHIR_CALL_METHOD(NULL, &_2, "__construct", NULL, 4, &_27);
	zephir_check_call_status();
	zephir_throw_exception_debug(&_2, "phalcon/image/adapter/gd.zep", 545 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();
	return;

}

PHP_METHOD(Phalcon_Image_Adapter_Gd, _render) {

	zend_bool _5;
	zend_long quality, ZEPHIR_LAST_CALL_STATUS;
	zval *ext_param = NULL, *quality_param = NULL, __$null, _0, _1, _2, _4, _6, _9, _11, _13, _3$$3, _7$$4, _8$$4, _10$$5, _12$$6, _14$$7;
	zval ext, _15;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&ext);
	ZVAL_UNDEF(&_15);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_11);
	ZVAL_UNDEF(&_13);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_7$$4);
	ZVAL_UNDEF(&_8$$4);
	ZVAL_UNDEF(&_10$$5);
	ZVAL_UNDEF(&_12$$6);
	ZVAL_UNDEF(&_14$$7);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &ext_param, &quality_param);

	zephir_get_strval(&ext, ext_param);
	quality = zephir_get_intval(quality_param);


	ZEPHIR_INIT_VAR(&_0);
	zephir_fast_strtolower(&_0, &ext);
	zephir_get_strval(&ext, &_0);
	ZEPHIR_CALL_FUNCTION(NULL, "ob_start", NULL, 114);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "gif");
	ZEPHIR_CALL_FUNCTION(&_2, "strcmp", NULL, 275, &ext, &_1);
	zephir_check_call_status();
	if (ZEPHIR_IS_LONG(&_2, 0)) {
		zephir_read_property(&_3$$3, this_ptr, SL("_image"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_FUNCTION(NULL, "imagegif", NULL, 277, &_3$$3);
		zephir_check_call_status();
		ZEPHIR_RETURN_CALL_FUNCTION("ob_get_clean", NULL, 282);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "jpg");
	ZEPHIR_CALL_FUNCTION(&_4, "strcmp", NULL, 275, &ext, &_1);
	zephir_check_call_status();
	_5 = ZEPHIR_IS_LONG(&_4, 0);
	if (!(_5)) {
		ZEPHIR_INIT_NVAR(&_1);
		ZVAL_STRING(&_1, "jpeg");
		ZEPHIR_CALL_FUNCTION(&_6, "strcmp", NULL, 275, &ext, &_1);
		zephir_check_call_status();
		_5 = ZEPHIR_IS_LONG(&_6, 0);
	}
	if (_5) {
		zephir_read_property(&_7$$4, this_ptr, SL("_image"), PH_NOISY_CC | PH_READONLY);
		ZVAL_LONG(&_8$$4, quality);
		ZEPHIR_CALL_FUNCTION(NULL, "imagejpeg", NULL, 278, &_7$$4, &__$null, &_8$$4);
		zephir_check_call_status();
		ZEPHIR_RETURN_CALL_FUNCTION("ob_get_clean", NULL, 282);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "png");
	ZEPHIR_CALL_FUNCTION(&_9, "strcmp", NULL, 275, &ext, &_1);
	zephir_check_call_status();
	if (ZEPHIR_IS_LONG(&_9, 0)) {
		zephir_read_property(&_10$$5, this_ptr, SL("_image"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_FUNCTION(NULL, "imagepng", NULL, 279, &_10$$5);
		zephir_check_call_status();
		ZEPHIR_RETURN_CALL_FUNCTION("ob_get_clean", NULL, 282);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "wbmp");
	ZEPHIR_CALL_FUNCTION(&_11, "strcmp", NULL, 275, &ext, &_1);
	zephir_check_call_status();
	if (ZEPHIR_IS_LONG(&_11, 0)) {
		zephir_read_property(&_12$$6, this_ptr, SL("_image"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_FUNCTION(NULL, "imagewbmp", NULL, 280, &_12$$6);
		zephir_check_call_status();
		ZEPHIR_RETURN_CALL_FUNCTION("ob_get_clean", NULL, 282);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "xbm");
	ZEPHIR_CALL_FUNCTION(&_13, "strcmp", NULL, 275, &ext, &_1);
	zephir_check_call_status();
	if (ZEPHIR_IS_LONG(&_13, 0)) {
		zephir_read_property(&_14$$7, this_ptr, SL("_image"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_FUNCTION(NULL, "imagexbm", NULL, 281, &_14$$7, &__$null);
		zephir_check_call_status();
		ZEPHIR_RETURN_CALL_FUNCTION("ob_get_clean", NULL, 282);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_INIT_NVAR(&_1);
	object_init_ex(&_1, phalcon_image_exception_ce);
	ZEPHIR_INIT_VAR(&_15);
	ZEPHIR_CONCAT_SVS(&_15, "Installed GD does not support '", &ext, "' images");
	ZEPHIR_CALL_METHOD(NULL, &_1, "__construct", NULL, 4, &_15);
	zephir_check_call_status();
	zephir_throw_exception_debug(&_1, "phalcon/image/adapter/gd.zep", 573 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();
	return;

}

PHP_METHOD(Phalcon_Image_Adapter_Gd, _create) {

	zval *width_param = NULL, *height_param = NULL, __$false, __$true, image, _0, _1;
	zend_long width, height, ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$false, 0);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&image);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &width_param, &height_param);

	width = zephir_get_intval(width_param);
	height = zephir_get_intval(height_param);


	ZVAL_LONG(&_0, width);
	ZVAL_LONG(&_1, height);
	ZEPHIR_CALL_FUNCTION(&image, "imagecreatetruecolor", NULL, 248, &_0, &_1);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(NULL, "imagealphablending", NULL, 249, &image, &__$false);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(NULL, "imagesavealpha", NULL, 247, &image, &__$true);
	zephir_check_call_status();
	RETURN_CCTOR(&image);

}

PHP_METHOD(Phalcon_Image_Adapter_Gd, __destruct) {

	zval image;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&image);

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(&image);
	zephir_read_property(&image, this_ptr, SL("_image"), PH_NOISY_CC);
	if (Z_TYPE_P(&image) == IS_RESOURCE) {
		ZEPHIR_CALL_FUNCTION(NULL, "imagedestroy", NULL, 251, &image);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();

}

