
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
#include "kernel/string.h"
#include "kernel/array.h"
#include "kernel/concat.h"
#include "kernel/file.h"
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
ZEPHIR_INIT_CLASS(Phalcon_Image_Adapter_Gd) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Image\\Adapter, Gd, phalcon, image_adapter_gd, phalcon_image_adapter_ce, phalcon_image_adapter_gd_method_entry, 0);

	zend_class_implements(phalcon_image_adapter_gd_ce TSRMLS_CC, 1, phalcon_image_adapterinterface_ce);

	return SUCCESS;

}

PHP_METHOD(Phalcon_Image_Adapter_Gd, check) {

	zval *version = NULL, *info, *matches, *_0, _1 = zval_used_for_init, *_2, *_3 = NULL, *_4, _5, _6, *_7, *_8, *_9;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_static_property_ce(phalcon_image_adapter_gd_ce, SL("_checked") TSRMLS_CC);
	if (zephir_is_true(_0)) {
		RETURN_MM_BOOL(1);
	}
	if (!((zephir_function_exists_ex(SS("gd_info") TSRMLS_CC) == SUCCESS))) {
		ZEPHIR_THROW_EXCEPTION_STR(phalcon_image_exception_ce, "GD is either not installed or not enabled, check your configuration");
		return;
	}
	ZEPHIR_INIT_VAR(version);
	ZVAL_NULL(version);
	ZEPHIR_SINIT_VAR(_1);
	ZVAL_STRING(&_1, "GD_VERSION", 0);
	ZEPHIR_INIT_VAR(_2);
	zephir_call_func_p1(_2, "defined", &_1);
	if (zephir_is_true(_2)) {
		ZEPHIR_INIT_BNVAR(version);
		ZEPHIR_GET_CONSTANT(version, "GD_VERSION");
	} else {
		ZEPHIR_INIT_VAR(info);
		zephir_call_func(info, "gd_info");
		ZEPHIR_INIT_VAR(matches);
		ZVAL_NULL(matches);
		ZEPHIR_INIT_VAR(_3);
		zephir_array_fetch_string(&_4, info, SL("GD Version"), PH_NOISY | PH_READONLY TSRMLS_CC);
		ZEPHIR_SINIT_NVAR(_1);
		ZVAL_STRING(&_1, "/\\d+\\.\\d+(?:\\.\\d+)?/", 0);
		zephir_preg_match(_3, &(_3), &_1, _4, matches, 0 TSRMLS_CC);
		if (zephir_is_true(_3)) {
			ZEPHIR_OBS_NVAR(version);
			zephir_array_fetch_long(&version, matches, 0, PH_NOISY TSRMLS_CC);
		}
	}
	ZEPHIR_SINIT_VAR(_5);
	ZVAL_STRING(&_5, "2.0.1", 0);
	ZEPHIR_SINIT_VAR(_6);
	ZVAL_STRING(&_6, ">=", 0);
	ZEPHIR_INIT_NVAR(_3);
	zephir_call_func_p3(_3, "version_compare", version, &_5, &_6);
	if (!(zephir_is_true(_3))) {
		ZEPHIR_INIT_VAR(_7);
		object_init_ex(_7, phalcon_image_exception_ce);
		ZEPHIR_INIT_VAR(_8);
		ZEPHIR_CONCAT_SV(_8, "Phalcon\\Image\\Adapter\\GD requires GD version '2.0.1' or greater, you have ", version);
		zephir_call_method_p1_noret(_7, "__construct", _8);
		zephir_throw_exception(_7 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_update_static_property_ce(phalcon_image_adapter_gd_ce, SL("_checked"), ZEPHIR_GLOBAL(global_true) TSRMLS_CC);
	_9 = zephir_fetch_static_property_ce(phalcon_image_adapter_gd_ce, SL("_checked") TSRMLS_CC);
	RETURN_CTOR(_9);

}

PHP_METHOD(Phalcon_Image_Adapter_Gd, __construct) {

	int width, height;
	zval *file_param = NULL, *width_param = NULL, *height_param = NULL, *imageinfo, *_0, *_1, *_2, *_3 = NULL, *_4, *_5, *_6, *_7, *_8, *_9 = NULL, *_10 = NULL, *_11 = NULL, *_12;
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


	_0 = zephir_fetch_static_property_ce(phalcon_image_adapter_gd_ce, SL("_checked") TSRMLS_CC);
	if (!(zephir_is_true(_0))) {
	}
	zephir_update_property_this(this_ptr, SL("_file"), file TSRMLS_CC);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("_file"), PH_NOISY_CC);
	if ((zephir_file_exists(_1 TSRMLS_CC) == SUCCESS)) {
		_2 = zephir_fetch_nproperty_this(this_ptr, SL("_file"), PH_NOISY_CC);
		ZEPHIR_INIT_VAR(_3);
		zephir_call_func_p1(_3, "realpath", _2);
		zephir_update_property_this(this_ptr, SL("_realpath"), _3 TSRMLS_CC);
		_4 = zephir_fetch_nproperty_this(this_ptr, SL("_file"), PH_NOISY_CC);
		ZEPHIR_INIT_VAR(imageinfo);
		zephir_call_func_p1(imageinfo, "getimagesize", _4);
		if (zephir_is_true(imageinfo)) {
			zephir_array_fetch_long(&_5, imageinfo, 0, PH_NOISY | PH_READONLY TSRMLS_CC);
			zephir_update_property_this(this_ptr, SL("_width"), _5 TSRMLS_CC);
			zephir_array_fetch_long(&_6, imageinfo, 1, PH_NOISY | PH_READONLY TSRMLS_CC);
			zephir_update_property_this(this_ptr, SL("_height"), _6 TSRMLS_CC);
			zephir_array_fetch_long(&_7, imageinfo, 2, PH_NOISY | PH_READONLY TSRMLS_CC);
			zephir_update_property_this(this_ptr, SL("_type"), _7 TSRMLS_CC);
			zephir_array_fetch_string(&_8, imageinfo, SL("mime"), PH_NOISY | PH_READONLY TSRMLS_CC);
			zephir_update_property_this(this_ptr, SL("_mime"), _8 TSRMLS_CC);
		}
		_5 = zephir_fetch_nproperty_this(this_ptr, SL("_type"), PH_NOISY_CC);
		do {
			if (ZEPHIR_IS_LONG(_5, 1)) {
				_6 = zephir_fetch_nproperty_this(this_ptr, SL("_file"), PH_NOISY_CC);
				ZEPHIR_INIT_VAR(_9);
				zephir_call_func_p1(_9, "imagecreatefromgif", _6);
				zephir_update_property_this(this_ptr, SL("_image"), _9 TSRMLS_CC);
				break;
			}
			if (ZEPHIR_IS_LONG(_5, 2)) {
				_5 = zephir_fetch_nproperty_this(this_ptr, SL("_file"), PH_NOISY_CC);
				ZEPHIR_INIT_NVAR(_9);
				zephir_call_func_p1(_9, "imagecreatefromjpeg", _5);
				zephir_update_property_this(this_ptr, SL("_image"), _9 TSRMLS_CC);
				break;
			}
			if (ZEPHIR_IS_LONG(_5, 3)) {
				_5 = zephir_fetch_nproperty_this(this_ptr, SL("_file"), PH_NOISY_CC);
				ZEPHIR_INIT_NVAR(_9);
				zephir_call_func_p1(_9, "imagecreatefrompng", _5);
				zephir_update_property_this(this_ptr, SL("_image"), _9 TSRMLS_CC);
				break;
			}
			if (ZEPHIR_IS_LONG(_5, 15)) {
				_5 = zephir_fetch_nproperty_this(this_ptr, SL("_file"), PH_NOISY_CC);
				ZEPHIR_INIT_NVAR(_9);
				zephir_call_func_p1(_9, "imagecreatefromwbmp", _5);
				zephir_update_property_this(this_ptr, SL("_image"), _9 TSRMLS_CC);
				break;
			}
			if (ZEPHIR_IS_LONG(_5, 16)) {
				_5 = zephir_fetch_nproperty_this(this_ptr, SL("_file"), PH_NOISY_CC);
				ZEPHIR_INIT_NVAR(_9);
				zephir_call_func_p1(_9, "imagecreatefromxbm", _5);
				zephir_update_property_this(this_ptr, SL("_image"), _9 TSRMLS_CC);
				break;
			}
			_5 = zephir_fetch_nproperty_this(this_ptr, SL("_mime"), PH_NOISY_CC);
			if (zephir_is_true(_5)) {
				ZEPHIR_INIT_VAR(_10);
				object_init_ex(_10, phalcon_image_exception_ce);
				_6 = zephir_fetch_nproperty_this(this_ptr, SL("_mime"), PH_NOISY_CC);
				ZEPHIR_INIT_VAR(_11);
				ZEPHIR_CONCAT_SVS(_11, "Installed GD does not support ", _6, " images");
				zephir_call_method_p1_noret(_10, "__construct", _11);
				zephir_throw_exception(_10 TSRMLS_CC);
				ZEPHIR_MM_RESTORE();
				return;
			} else {
				ZEPHIR_INIT_LNVAR(_10);
				object_init_ex(_10, phalcon_image_exception_ce);
				ZEPHIR_INIT_NVAR(_9);
				ZVAL_STRING(_9, "Installed GD does not support such images", 1);
				zephir_call_method_p1_noret(_10, "__construct", _9);
				zephir_throw_exception(_10 TSRMLS_CC);
				ZEPHIR_MM_RESTORE();
				return;
			}
			break;
		} while(0);

		_5 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		zephir_call_func_p2_noret("imagesavealpha", _5, ZEPHIR_GLOBAL(global_true));
	} else {
		if ((!width || !height)) {
			ZEPHIR_INIT_LNVAR(_10);
			object_init_ex(_10, phalcon_image_exception_ce);
			_2 = zephir_fetch_nproperty_this(this_ptr, SL("_file"), PH_NOISY_CC);
			ZEPHIR_INIT_LNVAR(_11);
			ZEPHIR_CONCAT_SV(_11, "Failed to create image from file ", _2);
			zephir_call_method_p1_noret(_10, "__construct", _11);
			zephir_throw_exception(_10 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_INIT_NVAR(_3);
		ZVAL_LONG(_3, width);
		ZEPHIR_INIT_NVAR(_9);
		ZVAL_LONG(_9, height);
		ZEPHIR_INIT_VAR(_12);
		zephir_call_func_p2(_12, "imagecreatetruecolor", _3, _9);
		zephir_update_property_this(this_ptr, SL("_image"), _12 TSRMLS_CC);
		_4 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		zephir_call_func_p2_noret("imagealphablending", _4, ZEPHIR_GLOBAL(global_true));
		_5 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		zephir_call_func_p2_noret("imagesavealpha", _5, ZEPHIR_GLOBAL(global_true));
		_6 = zephir_fetch_nproperty_this(this_ptr, SL("_file"), PH_NOISY_CC);
		zephir_update_property_this(this_ptr, SL("_realpath"), _6 TSRMLS_CC);
		ZEPHIR_INIT_ZVAL_NREF(_7);
		ZVAL_LONG(_7, width);
		zephir_update_property_zval(this_ptr, SL("_width"), _7 TSRMLS_CC);
		ZEPHIR_INIT_ZVAL_NREF(_7);
		ZVAL_LONG(_7, height);
		zephir_update_property_zval(this_ptr, SL("_height"), _7 TSRMLS_CC);
		ZEPHIR_INIT_ZVAL_NREF(_7);
		ZVAL_LONG(_7, 3);
		zephir_update_property_this(this_ptr, SL("_type"), _7 TSRMLS_CC);
		ZEPHIR_INIT_ZVAL_NREF(_7);
		ZVAL_STRING(_7, "image/png", 1);
		zephir_update_property_this(this_ptr, SL("_mime"), _7 TSRMLS_CC);
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Phalcon_Image_Adapter_Gd, _resize) {

	zval *width_param = NULL, *height_param = NULL, *image, *pre_width = NULL, *pre_height = NULL, *reduction_width, *reduction_height, *_0, _1 = zval_used_for_init, *_2, *_3, *_4, *_5, *_6, *_7, *_8 = NULL, *_9 = NULL, *_10 = NULL, *_11 = NULL, *_12 = NULL, *_13, *_14, *_15;
	int width, height;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &width_param, &height_param);

		width = zephir_get_intval(width_param);
		height = zephir_get_intval(height_param);


	ZEPHIR_INIT_VAR(image);
	ZEPHIR_INIT_VAR(_0);
	ZEPHIR_GET_CONSTANT(_0, "PHP_VERSION");
	ZEPHIR_SINIT_VAR(_1);
	ZVAL_STRING(&_1, "5.5.0", 0);
	ZEPHIR_INIT_VAR(_2);
	zephir_call_func_p2(_2, "version_compare", _0, &_1);
	if (ZEPHIR_LT_LONG(_2, 0)) {
		ZEPHIR_OBS_VAR(pre_width);
		zephir_read_property_this(&pre_width, this_ptr, SL("_width"), PH_NOISY_CC);
		ZEPHIR_OBS_VAR(pre_height);
		zephir_read_property_this(&pre_height, this_ptr, SL("_height"), PH_NOISY_CC);
		_3 = zephir_fetch_nproperty_this(this_ptr, SL("_width"), PH_NOISY_CC);
		_4 = zephir_fetch_nproperty_this(this_ptr, SL("_height"), PH_NOISY_CC);
		if (((width > ((zephir_get_numberval(_3) / 2))) && (height > ((zephir_get_numberval(_4) / 2))))) {
			ZEPHIR_SINIT_NVAR(_1);
			ZVAL_LONG(&_1, (width * 1.1));
			ZEPHIR_INIT_VAR(reduction_width);
			zephir_call_func_p1(reduction_width, "round", &_1);
			ZEPHIR_SINIT_NVAR(_1);
			ZVAL_LONG(&_1, (height * 1.1));
			ZEPHIR_INIT_VAR(reduction_height);
			zephir_call_func_p1(reduction_height, "round", &_1);
			while (1) {
				if (!((ZEPHIR_IS_LONG(reduction_width, (zephir_get_numberval(pre_width) / 2)) && ZEPHIR_IS_LONG(reduction_height, (zephir_get_numberval(pre_height) / 2))))) {
					break;
				}
				ZEPHIR_INIT_NVAR(pre_width);
				ZVAL_DOUBLE(pre_width, 2);
				ZEPHIR_INIT_NVAR(pre_height);
				ZVAL_DOUBLE(pre_height, 2);
			}
			zephir_call_method_p2(image, this_ptr, "_create", pre_width, pre_height);
			_5 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
			_6 = zephir_fetch_nproperty_this(this_ptr, SL("_width"), PH_NOISY_CC);
			_7 = zephir_fetch_nproperty_this(this_ptr, SL("_height"), PH_NOISY_CC);
			ZEPHIR_INIT_VAR(_8);
			ZVAL_LONG(_8, 0);
			ZEPHIR_INIT_VAR(_9);
			ZVAL_LONG(_9, 0);
			ZEPHIR_INIT_VAR(_10);
			ZVAL_LONG(_10, 0);
			ZEPHIR_INIT_VAR(_11);
			ZVAL_LONG(_11, 0);
			ZEPHIR_INIT_VAR(_12);
			zephir_call_func_p10(_12, "imagecopyresized", image, _5, _8, _9, _10, _11, pre_width, pre_height, _6, _7);
			if (zephir_is_true(_12)) {
				_13 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
				zephir_call_func_p1_noret("imagedestroy", _13);
				zephir_update_property_this(this_ptr, SL("_image"), image TSRMLS_CC);
			}
		}
		ZEPHIR_INIT_NVAR(_8);
		ZVAL_LONG(_8, width);
		ZEPHIR_INIT_NVAR(_9);
		ZVAL_LONG(_9, height);
		zephir_call_method_p2(image, this_ptr, "_create", _8, _9);
		_5 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		ZEPHIR_INIT_NVAR(_8);
		ZVAL_LONG(_8, 0);
		ZEPHIR_INIT_NVAR(_9);
		ZVAL_LONG(_9, 0);
		ZEPHIR_INIT_NVAR(_10);
		ZVAL_LONG(_10, 0);
		ZEPHIR_INIT_NVAR(_11);
		ZVAL_LONG(_11, 0);
		ZEPHIR_INIT_NVAR(_12);
		ZVAL_LONG(_12, width);
		ZEPHIR_INIT_VAR(_14);
		ZVAL_LONG(_14, height);
		ZEPHIR_INIT_VAR(_15);
		zephir_call_func_p10(_15, "imagecopyresampled", image, _5, _8, _9, _10, _11, _12, _14, pre_width, pre_height);
		if (zephir_is_true(_15)) {
			_6 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
			zephir_call_func_p1_noret("imagedestroy", _6);
			zephir_update_property_this(this_ptr, SL("_image"), image TSRMLS_CC);
			ZEPHIR_INIT_NVAR(_8);
			zephir_call_func_p1(_8, "imagesx", image);
			zephir_update_property_this(this_ptr, SL("_width"), _8 TSRMLS_CC);
			ZEPHIR_INIT_NVAR(_9);
			zephir_call_func_p1(_9, "imagesy", image);
			zephir_update_property_this(this_ptr, SL("_height"), _9 TSRMLS_CC);
		}
	} else {
		_3 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		ZEPHIR_INIT_NVAR(_8);
		ZVAL_LONG(_8, width);
		ZEPHIR_INIT_NVAR(_9);
		ZVAL_LONG(_9, height);
		ZEPHIR_INIT_BNVAR(image);
		zephir_call_func_p3(image, "imagescale", _3, _8, _9);
		_4 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		zephir_call_func_p1_noret("imagedestroy", _4);
		zephir_update_property_this(this_ptr, SL("_image"), image TSRMLS_CC);
		ZEPHIR_INIT_NVAR(_8);
		zephir_call_func_p1(_8, "imagesx", image);
		zephir_update_property_this(this_ptr, SL("_width"), _8 TSRMLS_CC);
		ZEPHIR_INIT_NVAR(_9);
		zephir_call_func_p1(_9, "imagesx", image);
		zephir_update_property_this(this_ptr, SL("_height"), _9 TSRMLS_CC);
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Phalcon_Image_Adapter_Gd, _crop) {

	zval *width_param = NULL, *height_param = NULL, *offset_x_param = NULL, *offset_y_param = NULL, *image, *rect, *_0, _1, *_2, *_3, *_4 = NULL, *_5 = NULL, *_6, *_7, *_8, *_9, *_10, *_11, *_12, *_13;
	int width, height, offset_x, offset_y;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 4, 0, &width_param, &height_param, &offset_x_param, &offset_y_param);

		width = zephir_get_intval(width_param);
		height = zephir_get_intval(height_param);
		offset_x = zephir_get_intval(offset_x_param);
		offset_y = zephir_get_intval(offset_y_param);


	ZEPHIR_INIT_VAR(image);
	ZEPHIR_INIT_VAR(_0);
	ZEPHIR_GET_CONSTANT(_0, "PHP_VERSION");
	ZEPHIR_SINIT_VAR(_1);
	ZVAL_STRING(&_1, "5.5.0", 0);
	ZEPHIR_INIT_VAR(_2);
	zephir_call_func_p2(_2, "version_compare", _0, &_1);
	if (ZEPHIR_LT_LONG(_2, 0)) {
		ZVAL_NULL(image);
		_3 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		ZEPHIR_INIT_VAR(_4);
		ZVAL_LONG(_4, 0);
		ZEPHIR_INIT_VAR(_5);
		ZVAL_LONG(_5, 0);
		ZEPHIR_INIT_VAR(_6);
		ZVAL_LONG(_6, offset_x);
		ZEPHIR_INIT_VAR(_7);
		ZVAL_LONG(_7, offset_y);
		ZEPHIR_INIT_VAR(_8);
		ZVAL_LONG(_8, width);
		ZEPHIR_INIT_VAR(_9);
		ZVAL_LONG(_9, height);
		ZEPHIR_INIT_VAR(_10);
		ZVAL_LONG(_10, width);
		ZEPHIR_INIT_VAR(_11);
		ZVAL_LONG(_11, height);
		ZEPHIR_INIT_VAR(_12);
		zephir_call_func_p10(_12, "imagecopyresampled", image, _3, _4, _5, _6, _7, _8, _9, _10, _11);
		if (zephir_is_true(_12)) {
			_13 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
			zephir_call_func_p1_noret("imagedestroy", _13);
			zephir_update_property_this(this_ptr, SL("_image"), image TSRMLS_CC);
			ZEPHIR_INIT_NVAR(_4);
			zephir_call_func_p1(_4, "imagesx", image);
			zephir_update_property_this(this_ptr, SL("_width"), _4 TSRMLS_CC);
			ZEPHIR_INIT_NVAR(_5);
			zephir_call_func_p1(_5, "imagesy", image);
			zephir_update_property_this(this_ptr, SL("_height"), _5 TSRMLS_CC);
		}
	} else {
		ZEPHIR_INIT_VAR(rect);
		array_init_size(rect, 5);
		ZEPHIR_INIT_NVAR(_4);
		ZVAL_LONG(_4, offset_x);
		zephir_array_update_string(&rect, SL("x"), &_4, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_NVAR(_4);
		ZVAL_LONG(_4, offset_y);
		zephir_array_update_string(&rect, SL("y"), &_4, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_NVAR(_4);
		ZVAL_LONG(_4, width);
		zephir_array_update_string(&rect, SL("width"), &_4, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_NVAR(_4);
		ZVAL_LONG(_4, height);
		zephir_array_update_string(&rect, SL("height"), &_4, PH_COPY | PH_SEPARATE);
		_3 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		zephir_call_func_p2(image, "imagecrop", _3, rect);
		_13 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		zephir_call_func_p1_noret("imagedestroy", _13);
		zephir_update_property_this(this_ptr, SL("_image"), image TSRMLS_CC);
		ZEPHIR_INIT_NVAR(_4);
		zephir_call_func_p1(_4, "imagesx", image);
		zephir_update_property_this(this_ptr, SL("_width"), _4 TSRMLS_CC);
		ZEPHIR_INIT_NVAR(_5);
		zephir_call_func_p1(_5, "imagesx", image);
		zephir_update_property_this(this_ptr, SL("_height"), _5 TSRMLS_CC);
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Phalcon_Image_Adapter_Gd, _rotate) {

	zval *degrees_param = NULL, *image, *transparent, *width, *height, *_0, _1, _2, _3, _4, *_5, *_6, *_7, *_8, *_9, *_10, *_11, *_12, *_13;
	int degrees;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &degrees_param);

		degrees = zephir_get_intval(degrees_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
	ZEPHIR_SINIT_VAR(_1);
	ZVAL_LONG(&_1, 0);
	ZEPHIR_SINIT_VAR(_2);
	ZVAL_LONG(&_2, 0);
	ZEPHIR_SINIT_VAR(_3);
	ZVAL_LONG(&_3, 0);
	ZEPHIR_SINIT_VAR(_4);
	ZVAL_LONG(&_4, 127);
	ZEPHIR_INIT_VAR(transparent);
	zephir_call_func_p5(transparent, "imagecolorallocatealpha", _0, &_1, &_2, &_3, &_4);
	_5 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_6);
	ZVAL_LONG(_6, (360 - degrees));
	ZEPHIR_INIT_VAR(_7);
	ZVAL_LONG(_7, 1);
	ZEPHIR_INIT_VAR(image);
	zephir_call_func_p4(image, "imagerotate", _5, _6, transparent, _7);
	zephir_call_func_p2_noret("imagesavealpha", image, ZEPHIR_GLOBAL(global_true));
	ZEPHIR_INIT_VAR(width);
	zephir_call_func_p1(width, "imagesx", image);
	ZEPHIR_INIT_VAR(height);
	zephir_call_func_p1(height, "imagesy", image);
	_8 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
	ZEPHIR_INIT_BNVAR(_6);
	ZVAL_LONG(_6, 0);
	ZEPHIR_INIT_BNVAR(_7);
	ZVAL_LONG(_7, 0);
	ZEPHIR_INIT_VAR(_9);
	ZVAL_LONG(_9, 0);
	ZEPHIR_INIT_VAR(_10);
	ZVAL_LONG(_10, 0);
	ZEPHIR_INIT_VAR(_11);
	ZVAL_LONG(_11, 100);
	ZEPHIR_INIT_VAR(_12);
	zephir_call_func_p9(_12, "imagecopymerge", _8, image, _6, _7, _9, _10, width, height, _11);
	if (zephir_is_true(_12)) {
		_13 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		zephir_call_func_p1_noret("imagedestroy", _13);
		zephir_update_property_this(this_ptr, SL("_image"), image TSRMLS_CC);
		zephir_update_property_this(this_ptr, SL("_width"), width TSRMLS_CC);
		zephir_update_property_this(this_ptr, SL("_height"), height TSRMLS_CC);
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Phalcon_Image_Adapter_Gd, _flip) {

	zval *direction_param = NULL, *image, *_0, _1, *_2, *_3, *_4, *_5, *_6, *_7, *_8, *_9 = NULL, *_10 = NULL, *_11 = NULL, *_12 = NULL, *_13 = NULL;
	int direction, x;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &direction_param);

		direction = zephir_get_intval(direction_param);


	ZEPHIR_INIT_VAR(_0);
	ZEPHIR_GET_CONSTANT(_0, "PHP_VERSION");
	ZEPHIR_SINIT_VAR(_1);
	ZVAL_STRING(&_1, "5.5.0", 0);
	ZEPHIR_INIT_VAR(_2);
	zephir_call_func_p2(_2, "version_compare", _0, &_1);
	if (ZEPHIR_LT_LONG(_2, 0)) {
		_3 = zephir_fetch_nproperty_this(this_ptr, SL("_width"), PH_NOISY_CC);
		_4 = zephir_fetch_nproperty_this(this_ptr, SL("_height"), PH_NOISY_CC);
		ZEPHIR_INIT_VAR(image);
		zephir_call_method_p2(image, this_ptr, "_create", _3, _4);
		if ((direction == 11)) {
			x = 0;
			while (1) {
				_5 = zephir_fetch_nproperty_this(this_ptr, SL("_width"), PH_NOISY_CC);
				if (!(ZEPHIR_LT_LONG(_5, x))) {
					break;
				}
				x++;
				_6 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
				_7 = zephir_fetch_nproperty_this(this_ptr, SL("_width"), PH_NOISY_CC);
				_8 = zephir_fetch_nproperty_this(this_ptr, SL("_height"), PH_NOISY_CC);
				ZEPHIR_INIT_NVAR(_9);
				ZVAL_LONG(_9, x);
				ZEPHIR_INIT_NVAR(_10);
				ZVAL_LONG(_10, 0);
				ZEPHIR_INIT_NVAR(_11);
				ZVAL_LONG(_11, ((zephir_get_numberval(_7) - x) - 1));
				ZEPHIR_INIT_NVAR(_12);
				ZVAL_LONG(_12, 0);
				ZEPHIR_INIT_NVAR(_13);
				ZVAL_LONG(_13, 1);
				zephir_call_func_p8_noret("imagecopy", image, _6, _9, _10, _11, _12, _13, _8);
			}
		} else {
			x = 0;
			while (1) {
				_5 = zephir_fetch_nproperty_this(this_ptr, SL("_height"), PH_NOISY_CC);
				if (!(ZEPHIR_LT_LONG(_5, x))) {
					break;
				}
				x++;
				_6 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
				_7 = zephir_fetch_nproperty_this(this_ptr, SL("_height"), PH_NOISY_CC);
				_8 = zephir_fetch_nproperty_this(this_ptr, SL("_width"), PH_NOISY_CC);
				ZEPHIR_INIT_NVAR(_9);
				ZVAL_LONG(_9, 0);
				ZEPHIR_INIT_NVAR(_10);
				ZVAL_LONG(_10, x);
				ZEPHIR_INIT_NVAR(_11);
				ZVAL_LONG(_11, 0);
				ZEPHIR_INIT_NVAR(_12);
				ZVAL_LONG(_12, ((zephir_get_numberval(_7) - x) - 1));
				ZEPHIR_INIT_NVAR(_13);
				ZVAL_LONG(_13, 1);
				zephir_call_func_p8_noret("imagecopy", image, _6, _9, _10, _11, _12, _8, _13);
			}
		}
		_5 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		zephir_call_func_p1_noret("imagedestroy", _5);
		zephir_update_property_this(this_ptr, SL("_image"), image TSRMLS_CC);
		ZEPHIR_INIT_NVAR(_9);
		zephir_call_func_p1(_9, "imagesx", image);
		zephir_update_property_this(this_ptr, SL("_width"), _9 TSRMLS_CC);
		ZEPHIR_INIT_NVAR(_10);
		zephir_call_func_p1(_10, "imagesy", image);
		zephir_update_property_this(this_ptr, SL("_height"), _10 TSRMLS_CC);
	} else {
		if ((direction == 11)) {
			_3 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
			ZEPHIR_INIT_NVAR(_11);
			ZEPHIR_GET_CONSTANT(_11, "IMG_FLIP_HORIZONTAL");
			zephir_call_func_p2_noret("imageflip", _3, _11);
		} else {
			_4 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
			ZEPHIR_INIT_NVAR(_12);
			ZEPHIR_GET_CONSTANT(_12, "IMG_FLIP_VERTICAL");
			zephir_call_func_p2_noret("imageflip", _4, _12);
		}
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Phalcon_Image_Adapter_Gd, _sharpen) {

	zval *amount_param = NULL, *matrix, _0 = zval_used_for_init, *_1, *_2, *_3, *_4, *_5, *_6, *_7, *_8;
	int amount;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &amount_param);

		amount = zephir_get_intval(amount_param);


	ZEPHIR_SINIT_VAR(_0);
	ZVAL_LONG(&_0, (-18 + ((amount * 0.08))));
	ZEPHIR_INIT_VAR(_1);
	zephir_call_func_p1(_1, "abs", &_0);
	ZEPHIR_SINIT_NVAR(_0);
	ZVAL_LONG(&_0, 2);
	ZEPHIR_INIT_VAR(_2);
	zephir_call_func_p2(_2, "round", _1, &_0);
	amount = zephir_get_intval(_2);
	ZEPHIR_INIT_VAR(matrix);
	array_init_size(matrix, 4);
	ZEPHIR_INIT_VAR(_3);
	array_init_size(_3, 4);
	ZEPHIR_INIT_VAR(_4);
	ZVAL_LONG(_4, -1);
	zephir_array_fast_append(_3, _4);
	ZEPHIR_INIT_BNVAR(_4);
	ZVAL_LONG(_4, -1);
	zephir_array_fast_append(_3, _4);
	ZEPHIR_INIT_BNVAR(_4);
	ZVAL_LONG(_4, -1);
	zephir_array_fast_append(_3, _4);
	zephir_array_fast_append(matrix, _3);
	ZEPHIR_INIT_BNVAR(_3);
	array_init_size(_3, 4);
	ZEPHIR_INIT_BNVAR(_4);
	ZVAL_LONG(_4, -1);
	zephir_array_fast_append(_3, _4);
	ZEPHIR_INIT_BNVAR(_4);
	ZVAL_LONG(_4, amount);
	zephir_array_fast_append(_3, _4);
	ZEPHIR_INIT_BNVAR(_4);
	ZVAL_LONG(_4, -1);
	zephir_array_fast_append(_3, _4);
	zephir_array_fast_append(matrix, _3);
	ZEPHIR_INIT_BNVAR(_3);
	array_init_size(_3, 4);
	ZEPHIR_INIT_BNVAR(_4);
	ZVAL_LONG(_4, -1);
	zephir_array_fast_append(_3, _4);
	ZEPHIR_INIT_BNVAR(_4);
	ZVAL_LONG(_4, -1);
	zephir_array_fast_append(_3, _4);
	ZEPHIR_INIT_BNVAR(_4);
	ZVAL_LONG(_4, -1);
	zephir_array_fast_append(_3, _4);
	zephir_array_fast_append(matrix, _3);
	_5 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
	ZEPHIR_INIT_BNVAR(_3);
	ZVAL_LONG(_3, (amount - 8));
	ZEPHIR_INIT_BNVAR(_4);
	ZVAL_LONG(_4, 0);
	ZEPHIR_INIT_VAR(_6);
	zephir_call_func_p4(_6, "imageconvolution", _5, matrix, _3, _4);
	if (zephir_is_true(_6)) {
		_7 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		ZEPHIR_INIT_BNVAR(_3);
		zephir_call_func_p1(_3, "imagesx", _7);
		zephir_update_property_this(this_ptr, SL("_width"), _3 TSRMLS_CC);
		_8 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		ZEPHIR_INIT_BNVAR(_4);
		zephir_call_func_p1(_4, "imagesy", _8);
		zephir_update_property_this(this_ptr, SL("_height"), _4 TSRMLS_CC);
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Phalcon_Image_Adapter_Gd, _reflection) {

	zend_function *_15 = NULL;
	zend_bool fade_in;
	zval *height_param = NULL, *opacity_param = NULL, *fade_in_param = NULL, *reflection, *line = NULL, _0 = zval_used_for_init, *_1, *_2, *_3, *_4, *_5 = NULL, *_6, *_7, *_8, *_9 = NULL, *_10 = NULL, *_11 = NULL, *_12, *_13, *_14, *_16, *_17, *_18 = NULL, *_19 = NULL, *_20 = NULL, *_21, *_22 = NULL;
	int height, opacity, stepping, offset, src_y, dst_y, dst_opacity;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &height_param, &opacity_param, &fade_in_param);

		height = zephir_get_intval(height_param);
		opacity = zephir_get_intval(opacity_param);
		fade_in = zephir_get_boolval(fade_in_param);


	ZEPHIR_SINIT_VAR(_0);
	ZVAL_LONG(&_0, ((((opacity * 127) / 100)) - 127));
	ZEPHIR_INIT_VAR(_1);
	zephir_call_func_p1(_1, "abs", &_0);
	ZEPHIR_INIT_VAR(_2);
	zephir_call_func_p1(_2, "round", _1);
	opacity = zephir_get_intval(_2);
	if ((opacity < 127)) {
		stepping = (((127 - opacity)) / height);
	} else {
		stepping = (127 / height);
	}
	_3 = zephir_fetch_nproperty_this(this_ptr, SL("_width"), PH_NOISY_CC);
	_4 = zephir_fetch_nproperty_this(this_ptr, SL("_height"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_5);
	ZVAL_LONG(_5, (zephir_get_numberval(_4) + height));
	ZEPHIR_INIT_VAR(reflection);
	zephir_call_method_p2(reflection, this_ptr, "_create", _3, _5);
	_6 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
	_7 = zephir_fetch_nproperty_this(this_ptr, SL("_width"), PH_NOISY_CC);
	_8 = zephir_fetch_nproperty_this(this_ptr, SL("_height"), PH_NOISY_CC);
	ZEPHIR_INIT_BNVAR(_5);
	ZVAL_LONG(_5, 0);
	ZEPHIR_INIT_VAR(_9);
	ZVAL_LONG(_9, 0);
	ZEPHIR_INIT_VAR(_10);
	ZVAL_LONG(_10, 0);
	ZEPHIR_INIT_VAR(_11);
	ZVAL_LONG(_11, 0);
	zephir_call_func_p8_noret("imagecopy", reflection, _6, _5, _9, _10, _11, _7, _8);
	offset = 0;
	while (1) {
		if (!((height >= offset))) {
			break;
		}
		_12 = zephir_fetch_nproperty_this(this_ptr, SL("_height"), PH_NOISY_CC);
		src_y = ((zephir_get_numberval(_12) - offset) - 1);
		_13 = zephir_fetch_nproperty_this(this_ptr, SL("_height"), PH_NOISY_CC);
		dst_y = (zephir_get_numberval(_13) + offset);
		if (fade_in) {
			ZEPHIR_SINIT_NVAR(_0);
			ZVAL_LONG(&_0, (opacity + ((stepping * ((height - offset))))));
			ZEPHIR_INIT_NVAR(_5);
			zephir_call_func_p1(_5, "round", &_0);
			dst_opacity = zephir_get_intval(_5);
		} else {
			ZEPHIR_SINIT_NVAR(_0);
			ZVAL_LONG(&_0, (opacity + ((stepping * offset))));
			ZEPHIR_INIT_NVAR(_9);
			zephir_call_func_p1(_9, "round", &_0);
			dst_opacity = zephir_get_intval(_9);
		}
		_14 = zephir_fetch_nproperty_this(this_ptr, SL("_width"), PH_NOISY_CC);
		ZEPHIR_INIT_NVAR(_10);
		ZVAL_LONG(_10, 1);
		ZEPHIR_INIT_NVAR(line);
		zephir_call_method_p2_cache(line, this_ptr, "_create", &_15, _14, _10);
		_16 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		_17 = zephir_fetch_nproperty_this(this_ptr, SL("_width"), PH_NOISY_CC);
		ZEPHIR_INIT_NVAR(_10);
		ZVAL_LONG(_10, 0);
		ZEPHIR_INIT_NVAR(_11);
		ZVAL_LONG(_11, 0);
		ZEPHIR_INIT_NVAR(_18);
		ZVAL_LONG(_18, 0);
		ZEPHIR_INIT_NVAR(_19);
		ZVAL_LONG(_19, src_y);
		ZEPHIR_INIT_NVAR(_20);
		ZVAL_LONG(_20, 1);
		zephir_call_func_p8_noret("imagecopy", line, _16, _10, _11, _18, _19, _17, _20);
		ZEPHIR_INIT_NVAR(_10);
		ZEPHIR_GET_CONSTANT(_10, "IMG_FILTER_COLORIZE");
		ZEPHIR_INIT_NVAR(_11);
		ZVAL_LONG(_11, 0);
		ZEPHIR_INIT_NVAR(_18);
		ZVAL_LONG(_18, 0);
		ZEPHIR_INIT_NVAR(_19);
		ZVAL_LONG(_19, 0);
		ZEPHIR_INIT_NVAR(_20);
		ZVAL_LONG(_20, dst_opacity);
		zephir_call_func_p6_noret("imagefilter", line, _10, _11, _18, _19, _20);
		_21 = zephir_fetch_nproperty_this(this_ptr, SL("_width"), PH_NOISY_CC);
		ZEPHIR_INIT_NVAR(_11);
		ZVAL_LONG(_11, 0);
		ZEPHIR_INIT_NVAR(_18);
		ZVAL_LONG(_18, dst_y);
		ZEPHIR_INIT_NVAR(_19);
		ZVAL_LONG(_19, 0);
		ZEPHIR_INIT_NVAR(_20);
		ZVAL_LONG(_20, 0);
		ZEPHIR_INIT_NVAR(_22);
		ZVAL_LONG(_22, 1);
		zephir_call_func_p8_noret("imagecopy", reflection, line, _11, _18, _19, _20, _21, _22);
		offset++;
	}
	_12 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
	zephir_call_func_p1_noret("imagedestroy", _12);
	zephir_update_property_this(this_ptr, SL("_image"), reflection TSRMLS_CC);
	ZEPHIR_INIT_BNVAR(_11);
	zephir_call_func_p1(_11, "imagesx", reflection);
	zephir_update_property_this(this_ptr, SL("_width"), _11 TSRMLS_CC);
	ZEPHIR_INIT_NVAR(_18);
	zephir_call_func_p1(_18, "imagesy", reflection);
	zephir_update_property_this(this_ptr, SL("_height"), _18 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Phalcon_Image_Adapter_Gd, _watermark) {

	int offset_x, offset_y, opacity, width, height;
	zval *watermark, *offset_x_param = NULL, *offset_y_param = NULL, *opacity_param = NULL, *overlay, *color, *_0, *_1, *_2, _3 = zval_used_for_init, *_4 = NULL, *_5 = NULL, _6, _7, _8, *_9 = NULL, *_10 = NULL, *_11 = NULL, *_12 = NULL, *_13 = NULL, *_14, *_15;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 4, 0, &watermark, &offset_x_param, &offset_y_param, &opacity_param);

		offset_x = zephir_get_intval(offset_x_param);
		offset_y = zephir_get_intval(offset_y_param);
		opacity = zephir_get_intval(opacity_param);


	ZEPHIR_INIT_VAR(_0);
	zephir_call_method(_0, watermark, "render");
	ZEPHIR_INIT_VAR(overlay);
	zephir_call_func_p1(overlay, "imagecreatefromstring", _0);
	zephir_call_func_p2_noret("imagesavealpha", overlay, ZEPHIR_GLOBAL(global_true));
	ZEPHIR_INIT_VAR(_1);
	zephir_call_func_p1(_1, "imagesx", overlay);
	width = zephir_get_intval(_1);
	ZEPHIR_INIT_VAR(_2);
	zephir_call_func_p1(_2, "imagesy", overlay);
	height = zephir_get_intval(_2);
	if ((opacity < 100)) {
		ZEPHIR_SINIT_VAR(_3);
		ZVAL_LONG(&_3, ((((opacity * 127) / 100)) - 127));
		ZEPHIR_INIT_VAR(_4);
		zephir_call_func_p1(_4, "abs", &_3);
		ZEPHIR_INIT_VAR(_5);
		zephir_call_func_p1(_5, "round", _4);
		opacity = zephir_get_intval(_5);
		ZEPHIR_SINIT_NVAR(_3);
		ZVAL_LONG(&_3, 127);
		ZEPHIR_SINIT_VAR(_6);
		ZVAL_LONG(&_6, 127);
		ZEPHIR_SINIT_VAR(_7);
		ZVAL_LONG(&_7, 127);
		ZEPHIR_SINIT_VAR(_8);
		ZVAL_LONG(&_8, opacity);
		ZEPHIR_INIT_VAR(color);
		zephir_call_func_p5(color, "imagecolorallocatealpha", overlay, &_3, &_6, &_7, &_8);
		ZEPHIR_INIT_VAR(_9);
		ZEPHIR_GET_CONSTANT(_9, "IMG_EFFECT_OVERLAY");
		zephir_call_func_p2_noret("imagelayereffect", overlay, _9);
		ZEPHIR_INIT_VAR(_10);
		ZVAL_LONG(_10, 0);
		ZEPHIR_INIT_VAR(_11);
		ZVAL_LONG(_11, 0);
		ZEPHIR_INIT_VAR(_12);
		ZVAL_LONG(_12, width);
		ZEPHIR_INIT_VAR(_13);
		ZVAL_LONG(_13, height);
		zephir_call_func_p6_noret("imagefilledrectangle", overlay, _10, _11, _12, _13, color);
	}
	_14 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
	zephir_call_func_p2_noret("imagealphablending", _14, ZEPHIR_GLOBAL(global_true));
	_15 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
	ZEPHIR_INIT_NVAR(_4);
	ZVAL_LONG(_4, offset_x);
	ZEPHIR_INIT_NVAR(_5);
	ZVAL_LONG(_5, offset_y);
	ZEPHIR_INIT_NVAR(_9);
	ZVAL_LONG(_9, 0);
	ZEPHIR_INIT_NVAR(_10);
	ZVAL_LONG(_10, 0);
	ZEPHIR_INIT_NVAR(_11);
	ZVAL_LONG(_11, width);
	ZEPHIR_INIT_NVAR(_12);
	ZVAL_LONG(_12, height);
	ZEPHIR_INIT_NVAR(_13);
	zephir_call_func_p8(_13, "imagecopy", _15, overlay, _4, _5, _9, _10, _11, _12);
	if (zephir_is_true(_13)) {
		zephir_call_func_p1_noret("imagedestroy", overlay);
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Phalcon_Image_Adapter_Gd, _text) {

	int offset_x, offset_y, opacity, r, g, b, size, angle, s0 = 0, s1 = 0, s4 = 0, s5 = 0, width, height;
	zval *text_param = NULL, *offset_x_param = NULL, *offset_y_param = NULL, *opacity_param = NULL, *r_param = NULL, *g_param = NULL, *b_param = NULL, *size_param = NULL, *fontfile_param = NULL, *space, *color, _0 = zval_used_for_init, *_1, *_2, *_3 = NULL, *_4 = NULL, *_5, *_6, *_7, *_8, *_9, *_10, _11 = zval_used_for_init, _12 = zval_used_for_init, _13 = zval_used_for_init, *_14, *_15 = NULL, *_16 = NULL, *_17 = NULL, *_18, *_19;
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


	ZEPHIR_SINIT_VAR(_0);
	ZVAL_LONG(&_0, ((((opacity * 127) / 100)) - 127));
	ZEPHIR_INIT_VAR(_1);
	zephir_call_func_p1(_1, "abs", &_0);
	ZEPHIR_INIT_VAR(_2);
	zephir_call_func_p1(_2, "round", _1);
	opacity = zephir_get_intval(_2);
	ZEPHIR_INIT_VAR(color);
	if (fontfile && Z_STRLEN_P(fontfile)) {
		ZEPHIR_INIT_VAR(_3);
		ZVAL_LONG(_3, size);
		ZEPHIR_INIT_VAR(_4);
		ZVAL_LONG(_4, 0);
		ZEPHIR_INIT_VAR(space);
		zephir_call_func_p4(space, "imagettfbbox", _3, _4, fontfile, text);
		if (zephir_array_isset_long(space, 0)) {
			ZEPHIR_OBS_VAR(_5);
			zephir_array_fetch_long(&_5, space, 0, PH_NOISY TSRMLS_CC);
			s0 = zephir_get_intval(_5);
			ZEPHIR_OBS_VAR(_6);
			zephir_array_fetch_long(&_6, space, 1, PH_NOISY TSRMLS_CC);
			s1 = zephir_get_intval(_6);
			ZEPHIR_OBS_VAR(_7);
			zephir_array_fetch_long(&_7, space, 4, PH_NOISY TSRMLS_CC);
			s4 = zephir_get_intval(_7);
			ZEPHIR_OBS_VAR(_8);
			zephir_array_fetch_long(&_8, space, 5, PH_NOISY TSRMLS_CC);
			s5 = zephir_get_intval(_8);
		}
		if ((((!s0 || !s1) || !s4) || !s5)) {
			ZEPHIR_INIT_VAR(_9);
			object_init_ex(_9, phalcon_image_exception_ce);
			ZEPHIR_INIT_NVAR(_3);
			ZVAL_STRING(_3, "Call to imagettfbbox() failed", 1);
			zephir_call_method_p1_noret(_9, "__construct", _3);
			zephir_throw_exception(_9 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_SINIT_NVAR(_0);
		ZVAL_LONG(&_0, (s4 - s0));
		ZEPHIR_INIT_NVAR(_3);
		zephir_call_func_p1(_3, "abs", &_0);
		width = (zephir_get_numberval(_3) + 10);
		ZEPHIR_SINIT_NVAR(_0);
		ZVAL_LONG(&_0, (s5 - s1));
		ZEPHIR_INIT_NVAR(_4);
		zephir_call_func_p1(_4, "abs", &_0);
		height = (zephir_get_numberval(_4) + 10);
		if ((offset_x < 0)) {
			_10 = zephir_fetch_nproperty_this(this_ptr, SL("_width"), PH_NOISY_CC);
			offset_x = ((zephir_get_numberval(_10) - width) + offset_x);
		}
		if ((offset_y < 0)) {
			_10 = zephir_fetch_nproperty_this(this_ptr, SL("_height"), PH_NOISY_CC);
			offset_y = ((zephir_get_numberval(_10) - height) + offset_y);
		}
		_10 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		ZEPHIR_SINIT_NVAR(_0);
		ZVAL_LONG(&_0, r);
		ZEPHIR_SINIT_VAR(_11);
		ZVAL_LONG(&_11, g);
		ZEPHIR_SINIT_VAR(_12);
		ZVAL_LONG(&_12, b);
		ZEPHIR_SINIT_VAR(_13);
		ZVAL_LONG(&_13, opacity);
		zephir_call_func_p5(color, "imagecolorallocatealpha", _10, &_0, &_11, &_12, &_13);
		angle = 0;
		_14 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		ZEPHIR_INIT_VAR(_15);
		ZVAL_LONG(_15, size);
		ZEPHIR_INIT_VAR(_16);
		ZVAL_LONG(_16, angle);
		ZEPHIR_INIT_VAR(_17);
		ZVAL_LONG(_17, offset_x);
		ZEPHIR_INIT_VAR(_18);
		ZVAL_LONG(_18, offset_y);
		zephir_call_func_p8_noret("imagettftext", _14, _15, _16, _17, _18, color, fontfile, text);
	} else {
		ZEPHIR_INIT_NVAR(_3);
		ZVAL_LONG(_3, size);
		ZEPHIR_INIT_NVAR(_4);
		zephir_call_func_p1(_4, "imagefontwidth", _3);
		width = (zephir_get_intval(_4) * zephir_fast_strlen_ev(text));
		ZEPHIR_INIT_NVAR(_3);
		ZVAL_LONG(_3, size);
		ZEPHIR_INIT_NVAR(_15);
		zephir_call_func_p1(_15, "imagefontheight", _3);
		height = zephir_get_intval(_15);
		if ((offset_x < 0)) {
			_14 = zephir_fetch_nproperty_this(this_ptr, SL("_width"), PH_NOISY_CC);
			offset_x = ((zephir_get_numberval(_14) - width) + offset_x);
		}
		if ((offset_y < 0)) {
			_10 = zephir_fetch_nproperty_this(this_ptr, SL("_height"), PH_NOISY_CC);
			offset_y = ((zephir_get_numberval(_10) - height) + offset_y);
		}
		_10 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		ZEPHIR_SINIT_NVAR(_0);
		ZVAL_LONG(&_0, r);
		ZEPHIR_SINIT_NVAR(_11);
		ZVAL_LONG(&_11, g);
		ZEPHIR_SINIT_NVAR(_12);
		ZVAL_LONG(&_12, b);
		ZEPHIR_SINIT_NVAR(_13);
		ZVAL_LONG(&_13, opacity);
		zephir_call_func_p5(color, "imagecolorallocatealpha", _10, &_0, &_11, &_12, &_13);
		_19 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		ZEPHIR_INIT_NVAR(_3);
		ZVAL_LONG(_3, size);
		ZEPHIR_INIT_NVAR(_16);
		ZVAL_LONG(_16, offset_x);
		ZEPHIR_INIT_NVAR(_17);
		ZVAL_LONG(_17, offset_y);
		zephir_call_func_p6_noret("imagestring", _19, _3, _16, _17, text, color);
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Phalcon_Image_Adapter_Gd, _mask) {

	int mask_width, mask_height, x, y, _21;
	zval *mask, *maskImage = NULL, *newimage, *tempImage, *color = NULL, *index = NULL, *alpha = NULL, *_0, *_1, *_2, *_3, *_4, _5 = zval_used_for_init, _6 = zval_used_for_init, _7, _8, *_9 = NULL, *_10 = NULL, *_11, *_12, *_13, *_14, *_15, *_16, *_17, *_18, *_19, *_20, *_22, *_23, *_24, *_25;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &mask);



	ZEPHIR_INIT_VAR(_0);
	zephir_call_method(_0, mask, "render");
	ZEPHIR_INIT_VAR(maskImage);
	zephir_call_func_p1(maskImage, "imagecreatefromstring", _0);
	ZEPHIR_INIT_VAR(_1);
	zephir_call_func_p1(_1, "imagesx", mask);
	mask_width = zephir_get_intval(_1);
	ZEPHIR_INIT_VAR(_2);
	zephir_call_func_p1(_2, "imagesy", mask);
	mask_height = zephir_get_intval(_2);
	ZEPHIR_INIT_VAR(alpha);
	ZVAL_LONG(alpha, 127);
	zephir_call_func_p2_noret("imagesavealpha", mask, ZEPHIR_GLOBAL(global_true));
	_3 = zephir_fetch_nproperty_this(this_ptr, SL("_width"), PH_NOISY_CC);
	_4 = zephir_fetch_nproperty_this(this_ptr, SL("_height"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(newimage);
	zephir_call_method_p2(newimage, this_ptr, "_create", _3, _4);
	zephir_call_func_p2_noret("imagesavealpha", newimage, ZEPHIR_GLOBAL(global_true));
	ZEPHIR_SINIT_VAR(_5);
	ZVAL_LONG(&_5, 0);
	ZEPHIR_SINIT_VAR(_6);
	ZVAL_LONG(&_6, 0);
	ZEPHIR_SINIT_VAR(_7);
	ZVAL_LONG(&_7, 0);
	ZEPHIR_SINIT_VAR(_8);
	ZVAL_LONG(&_8, 127);
	ZEPHIR_INIT_VAR(color);
	zephir_call_func_p5(color, "imagecolorallocatealpha", newimage, &_5, &_6, &_7, &_8);
	ZEPHIR_INIT_VAR(_9);
	ZVAL_LONG(_9, 0);
	ZEPHIR_INIT_VAR(_10);
	ZVAL_LONG(_10, 0);
	zephir_call_func_p4_noret("imagefill", newimage, _9, _10, color);
	_11 = zephir_fetch_nproperty_this(this_ptr, SL("_width"), PH_NOISY_CC);
	_12 = zephir_fetch_nproperty_this(this_ptr, SL("_height"), PH_NOISY_CC);
	if ((!ZEPHIR_IS_LONG(_11, mask_width) || !ZEPHIR_IS_LONG(_12, mask_height))) {
		_13 = zephir_fetch_nproperty_this(this_ptr, SL("_width"), PH_NOISY_CC);
		_14 = zephir_fetch_nproperty_this(this_ptr, SL("_height"), PH_NOISY_CC);
		ZEPHIR_INIT_VAR(tempImage);
		zephir_call_func_p2(tempImage, "imagecreatetruecolor", _13, _14);
		_15 = zephir_fetch_nproperty_this(this_ptr, SL("_width"), PH_NOISY_CC);
		_16 = zephir_fetch_nproperty_this(this_ptr, SL("_height"), PH_NOISY_CC);
		ZEPHIR_INIT_BNVAR(_9);
		ZVAL_LONG(_9, 0);
		ZEPHIR_INIT_BNVAR(_10);
		ZVAL_LONG(_10, 0);
		ZEPHIR_INIT_VAR(_17);
		ZVAL_LONG(_17, 0);
		ZEPHIR_INIT_VAR(_18);
		ZVAL_LONG(_18, 0);
		ZEPHIR_INIT_VAR(_19);
		ZVAL_LONG(_19, mask_width);
		ZEPHIR_INIT_VAR(_20);
		ZVAL_LONG(_20, mask_height);
		zephir_call_func_p10_noret("imagecopyresampled", tempImage, maskImage, _9, _10, _17, _18, _15, _16, _19, _20);
		zephir_call_func_p1_noret("imagedestroy", maskImage);
		ZEPHIR_CPY_WRT(maskImage, tempImage);
	}
	x = 0;
	while (1) {
		_13 = zephir_fetch_nproperty_this(this_ptr, SL("_width"), PH_NOISY_CC);
		if (!(ZEPHIR_LT_LONG(_13, x))) {
			break;
		}
		y = 0;
		while (1) {
			_14 = zephir_fetch_nproperty_this(this_ptr, SL("_height"), PH_NOISY_CC);
			if (!(ZEPHIR_LT_LONG(_14, y))) {
				break;
			}
			ZEPHIR_SINIT_NVAR(_5);
			ZVAL_LONG(&_5, x);
			ZEPHIR_SINIT_NVAR(_6);
			ZVAL_LONG(&_6, y);
			ZEPHIR_INIT_NVAR(index);
			zephir_call_func_p3(index, "imagecolorat", maskImage, &_5, &_6);
			ZEPHIR_INIT_NVAR(color);
			zephir_call_func_p2(color, "imagecolorsforindex", maskImage, index);
			if (zephir_array_isset_string(color, SS("red"))) {
				zephir_array_fetch_string(&_15, alpha, SL("red"), PH_NOISY | PH_READONLY TSRMLS_CC);
				_21 = (127 - ((zephir_get_numberval(_15) / 2)));
				ZEPHIR_INIT_NVAR(alpha);
				ZVAL_LONG(alpha, _21);
			}
			_16 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
			ZEPHIR_SINIT_NVAR(_5);
			ZVAL_LONG(&_5, x);
			ZEPHIR_SINIT_NVAR(_6);
			ZVAL_LONG(&_6, y);
			ZEPHIR_INIT_NVAR(index);
			zephir_call_func_p3(index, "imagecolorat", _16, &_5, &_6);
			_22 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
			ZEPHIR_INIT_NVAR(color);
			zephir_call_func_p2(color, "imagecolorsforindex", _22, index);
			zephir_array_fetch_string(&_23, color, SL("red"), PH_NOISY | PH_READONLY TSRMLS_CC);
			zephir_array_fetch_string(&_24, color, SL("green"), PH_NOISY | PH_READONLY TSRMLS_CC);
			zephir_array_fetch_string(&_25, color, SL("blue"), PH_NOISY | PH_READONLY TSRMLS_CC);
			ZEPHIR_INIT_NVAR(color);
			zephir_call_func_p5(color, "imagecolorallocatealpha", newimage, _23, _24, _25, alpha);
			ZEPHIR_INIT_NVAR(_9);
			ZVAL_LONG(_9, x);
			ZEPHIR_INIT_NVAR(_10);
			ZVAL_LONG(_10, y);
			zephir_call_func_p4_noret("imagesetpixel", newimage, _9, _10, color);
			y++;
		}
		x++;
	}
	_13 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
	zephir_call_func_p1_noret("imagedestroy", _13);
	zephir_call_func_p1_noret("imagedestroy", maskImage);
	zephir_update_property_this(this_ptr, SL("_image"), newimage TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Phalcon_Image_Adapter_Gd, _background) {

	zval *r_param = NULL, *g_param = NULL, *b_param = NULL, *opacity_param = NULL, *background, *color, *_0, *_1, _2, _3, _4, _5, *_6, *_7, *_8, *_9, *_10, *_11, *_12, *_13, *_14;
	int r, g, b, opacity;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 4, 0, &r_param, &g_param, &b_param, &opacity_param);

		r = zephir_get_intval(r_param);
		g = zephir_get_intval(g_param);
		b = zephir_get_intval(b_param);
		opacity = zephir_get_intval(opacity_param);


	opacity = ((((opacity * 127) / 100)) - 127);
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_width"), PH_NOISY_CC);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("_height"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(background);
	zephir_call_method_p2(background, this_ptr, "_create", _0, _1);
	ZEPHIR_SINIT_VAR(_2);
	ZVAL_LONG(&_2, r);
	ZEPHIR_SINIT_VAR(_3);
	ZVAL_LONG(&_3, g);
	ZEPHIR_SINIT_VAR(_4);
	ZVAL_LONG(&_4, b);
	ZEPHIR_SINIT_VAR(_5);
	ZVAL_LONG(&_5, opacity);
	ZEPHIR_INIT_VAR(color);
	zephir_call_func_p5(color, "imagecolorallocatealpha", background, &_2, &_3, &_4, &_5);
	zephir_call_func_p2_noret("imagealphablending", background, ZEPHIR_GLOBAL(global_true));
	_6 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
	_7 = zephir_fetch_nproperty_this(this_ptr, SL("_width"), PH_NOISY_CC);
	_8 = zephir_fetch_nproperty_this(this_ptr, SL("_height"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_9);
	ZVAL_LONG(_9, 0);
	ZEPHIR_INIT_VAR(_10);
	ZVAL_LONG(_10, 0);
	ZEPHIR_INIT_VAR(_11);
	ZVAL_LONG(_11, 0);
	ZEPHIR_INIT_VAR(_12);
	ZVAL_LONG(_12, 0);
	ZEPHIR_INIT_VAR(_13);
	zephir_call_func_p8(_13, "imagecopy", background, _6, _9, _10, _11, _12, _7, _8);
	if (zephir_is_true(_13)) {
		_14 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		zephir_call_func_p1_noret("imagedestroy", _14);
		zephir_update_property_this(this_ptr, SL("_image"), background TSRMLS_CC);
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Phalcon_Image_Adapter_Gd, _blur) {

	zval *radius_param = NULL, *_0, *_1 = NULL;
	int radius, i;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &radius_param);

		radius = zephir_get_intval(radius_param);


	i = 0;
	while (1) {
		if (!((i < radius))) {
			break;
		}
		_0 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		ZEPHIR_INIT_NVAR(_1);
		ZEPHIR_GET_CONSTANT(_1, "IMG_FILTER_GAUSSIAN_BLUR");
		zephir_call_func_p2_noret("imagefilter", _0, _1);
		i++;
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Phalcon_Image_Adapter_Gd, _pixelate) {

	zval *amount_param = NULL, *color = NULL, *_0, *_1, *_2, _3 = zval_used_for_init, _4 = zval_used_for_init, *_5, *_6 = NULL, *_7 = NULL, *_8 = NULL, *_9 = NULL;
	int amount, x, y, x1, y1, x2, y2;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &amount_param);

		amount = zephir_get_intval(amount_param);


	x = 0;
	while (1) {
		_0 = zephir_fetch_nproperty_this(this_ptr, SL("_width"), PH_NOISY_CC);
		if (!(ZEPHIR_LT_LONG(_0, x))) {
			break;
		}
		y = 0;
		while (1) {
			_1 = zephir_fetch_nproperty_this(this_ptr, SL("_height"), PH_NOISY_CC);
			if (!(ZEPHIR_LT_LONG(_1, y))) {
				break;
			}
			x1 = (x + (amount / 2));
			y1 = (y + (amount / 2));
			_2 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
			ZEPHIR_SINIT_NVAR(_3);
			ZVAL_LONG(&_3, x1);
			ZEPHIR_SINIT_NVAR(_4);
			ZVAL_LONG(&_4, y1);
			ZEPHIR_INIT_NVAR(color);
			zephir_call_func_p3(color, "imagecolorat", _2, &_3, &_4);
			x2 = (x + amount);
			y2 = (y + amount);
			_5 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
			ZEPHIR_INIT_NVAR(_6);
			ZVAL_LONG(_6, x1);
			ZEPHIR_INIT_NVAR(_7);
			ZVAL_LONG(_7, y1);
			ZEPHIR_INIT_NVAR(_8);
			ZVAL_LONG(_8, x2);
			ZEPHIR_INIT_NVAR(_9);
			ZVAL_LONG(_9, y2);
			zephir_call_func_p6_noret("imagefilledrectangle", _5, _6, _7, _8, _9, color);
			y += amount;
		}
		x += amount;
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Phalcon_Image_Adapter_Gd, _save) {

	int quality;
	zval *file_param = NULL, *quality_param = NULL, *ext, _0 = zval_used_for_init, *_1, *_2, *_3 = NULL, *_4, *_5, *_6 = NULL, *_7, *_8, *_9;
	zval *file = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &file_param, &quality_param);

		zephir_get_strval(file, file_param);
		quality = zephir_get_intval(quality_param);


	ZEPHIR_SINIT_VAR(_0);
	ZVAL_LONG(&_0, 4);
	ZEPHIR_INIT_VAR(ext);
	zephir_call_func_p2(ext, "pathinfo", file, &_0);
	ZEPHIR_SINIT_NVAR(_0);
	ZVAL_STRING(&_0, "gif", 0);
	ZEPHIR_INIT_VAR(_1);
	zephir_call_func_p2(_1, "strcasecmp", ext, &_0);
	if (ZEPHIR_IS_LONG(_1, 0)) {
		ZEPHIR_INIT_ZVAL_NREF(_2);
		ZVAL_LONG(_2, 1);
		zephir_update_property_this(this_ptr, SL("_type"), _2 TSRMLS_CC);
		_2 = zephir_fetch_nproperty_this(this_ptr, SL("_type"), PH_NOISY_CC);
		ZEPHIR_INIT_VAR(_3);
		zephir_call_func_p1(_3, "image_type_to_mime_type", _2);
		zephir_update_property_this(this_ptr, SL("_mime"), _3 TSRMLS_CC);
		_4 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		zephir_call_func_p2_noret("imagegif", _4, file);
		RETURN_MM_BOOL(1);
	}
	ZEPHIR_SINIT_NVAR(_0);
	ZVAL_STRING(&_0, "jpg", 0);
	ZEPHIR_INIT_NVAR(_3);
	zephir_call_func_p2(_3, "strcmp", ext, &_0);
	ZEPHIR_SINIT_NVAR(_0);
	ZVAL_STRING(&_0, "jpeg", 0);
	ZEPHIR_INIT_VAR(_5);
	zephir_call_func_p2(_5, "strcmp", ext, &_0);
	if ((ZEPHIR_IS_LONG(_3, 0) || ZEPHIR_IS_LONG(_5, 0))) {
		ZEPHIR_INIT_ZVAL_NREF(_2);
		ZVAL_LONG(_2, 2);
		zephir_update_property_this(this_ptr, SL("_type"), _2 TSRMLS_CC);
		_2 = zephir_fetch_nproperty_this(this_ptr, SL("_type"), PH_NOISY_CC);
		ZEPHIR_INIT_VAR(_6);
		zephir_call_func_p1(_6, "image_type_to_mime_type", _2);
		zephir_update_property_this(this_ptr, SL("_mime"), _6 TSRMLS_CC);
		_4 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		ZEPHIR_INIT_VAR(_7);
		ZVAL_LONG(_7, quality);
		zephir_call_func_p3_noret("imagejpeg", _4, file, _7);
		RETURN_MM_BOOL(1);
	}
	ZEPHIR_SINIT_NVAR(_0);
	ZVAL_STRING(&_0, "png", 0);
	ZEPHIR_INIT_NVAR(_3);
	zephir_call_func_p2(_3, "strcmp", ext, &_0);
	if (ZEPHIR_IS_LONG(_3, 0)) {
		ZEPHIR_INIT_ZVAL_NREF(_2);
		ZVAL_LONG(_2, 3);
		zephir_update_property_this(this_ptr, SL("_type"), _2 TSRMLS_CC);
		_2 = zephir_fetch_nproperty_this(this_ptr, SL("_type"), PH_NOISY_CC);
		ZEPHIR_INIT_NVAR(_6);
		zephir_call_func_p1(_6, "image_type_to_mime_type", _2);
		zephir_update_property_this(this_ptr, SL("_mime"), _6 TSRMLS_CC);
		_4 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		zephir_call_func_p2_noret("imagejpeg", _4, file);
		RETURN_MM_BOOL(1);
	}
	ZEPHIR_SINIT_NVAR(_0);
	ZVAL_STRING(&_0, "wbmp", 0);
	ZEPHIR_INIT_NVAR(_3);
	zephir_call_func_p2(_3, "strcmp", ext, &_0);
	if (ZEPHIR_IS_LONG(_3, 0)) {
		ZEPHIR_INIT_ZVAL_NREF(_2);
		ZVAL_LONG(_2, 15);
		zephir_update_property_this(this_ptr, SL("_type"), _2 TSRMLS_CC);
		_2 = zephir_fetch_nproperty_this(this_ptr, SL("_type"), PH_NOISY_CC);
		ZEPHIR_INIT_NVAR(_6);
		zephir_call_func_p1(_6, "image_type_to_mime_type", _2);
		zephir_update_property_this(this_ptr, SL("_mime"), _6 TSRMLS_CC);
		_4 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		zephir_call_func_p2_noret("imagewbmp", _4, file);
		RETURN_MM_BOOL(1);
	}
	ZEPHIR_SINIT_NVAR(_0);
	ZVAL_STRING(&_0, "xbm", 0);
	ZEPHIR_INIT_NVAR(_3);
	zephir_call_func_p2(_3, "strcmp", ext, &_0);
	if (ZEPHIR_IS_LONG(_3, 0)) {
		ZEPHIR_INIT_ZVAL_NREF(_2);
		ZVAL_LONG(_2, 16);
		zephir_update_property_this(this_ptr, SL("_type"), _2 TSRMLS_CC);
		_2 = zephir_fetch_nproperty_this(this_ptr, SL("_type"), PH_NOISY_CC);
		ZEPHIR_INIT_NVAR(_6);
		zephir_call_func_p1(_6, "image_type_to_mime_type", _2);
		zephir_update_property_this(this_ptr, SL("_mime"), _6 TSRMLS_CC);
		_4 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		zephir_call_func_p2_noret("imagexbm", _4, file);
		RETURN_MM_BOOL(1);
	}
	ZEPHIR_INIT_VAR(_8);
	object_init_ex(_8, phalcon_image_exception_ce);
	ZEPHIR_INIT_VAR(_9);
	ZEPHIR_CONCAT_SVS(_9, "Installed GD does not support '", ext, "' images");
	zephir_call_method_p1_noret(_8, "__construct", _9);
	zephir_throw_exception(_8 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();
	return;

}

PHP_METHOD(Phalcon_Image_Adapter_Gd, _render) {

	int quality;
	zval *ext_param = NULL, *quality_param = NULL, _0 = zval_used_for_init, *_1, *_2, *_3, *_4, *_5 = NULL, *_6;
	zval *ext = NULL, *_7;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &ext_param, &quality_param);

		zephir_get_strval(ext, ext_param);
		quality = zephir_get_intval(quality_param);


	ZEPHIR_SINIT_VAR(_0);
	ZVAL_STRING(&_0, "gif", 0);
	ZEPHIR_INIT_VAR(_1);
	zephir_call_func_p2(_1, "strcasecmp", ext, &_0);
	if (ZEPHIR_IS_LONG(_1, 0)) {
		_2 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		zephir_call_func_p1_noret("imagegif", _2);
		RETURN_MM_NULL();
	}
	ZEPHIR_SINIT_NVAR(_0);
	ZVAL_STRING(&_0, "jpg", 0);
	ZEPHIR_INIT_VAR(_3);
	zephir_call_func_p2(_3, "strcmp", ext, &_0);
	ZEPHIR_SINIT_NVAR(_0);
	ZVAL_STRING(&_0, "jpeg", 0);
	ZEPHIR_INIT_VAR(_4);
	zephir_call_func_p2(_4, "strcmp", ext, &_0);
	if ((ZEPHIR_IS_LONG(_3, 0) || ZEPHIR_IS_LONG(_4, 0))) {
		_2 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		ZEPHIR_INIT_VAR(_5);
		ZVAL_LONG(_5, quality);
		zephir_call_func_p3_noret("imagejpeg", _2, ZEPHIR_GLOBAL(global_null), _5);
		RETURN_MM_NULL();
	}
	ZEPHIR_SINIT_NVAR(_0);
	ZVAL_STRING(&_0, "png", 0);
	ZEPHIR_INIT_NVAR(_5);
	zephir_call_func_p2(_5, "strcmp", ext, &_0);
	if (ZEPHIR_IS_LONG(_5, 0)) {
		_2 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		zephir_call_func_p1_noret("imagejpeg", _2);
		RETURN_MM_NULL();
	}
	ZEPHIR_SINIT_NVAR(_0);
	ZVAL_STRING(&_0, "wbmp", 0);
	ZEPHIR_INIT_NVAR(_5);
	zephir_call_func_p2(_5, "strcmp", ext, &_0);
	if (ZEPHIR_IS_LONG(_5, 0)) {
		_2 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		zephir_call_func_p1_noret("imagewbmp", _2);
		RETURN_MM_NULL();
	}
	ZEPHIR_SINIT_NVAR(_0);
	ZVAL_STRING(&_0, "xbm", 0);
	ZEPHIR_INIT_NVAR(_5);
	zephir_call_func_p2(_5, "strcmp", ext, &_0);
	if (ZEPHIR_IS_LONG(_5, 0)) {
		_2 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		zephir_call_func_p2_noret("imagexbm", _2, ZEPHIR_GLOBAL(global_null));
		RETURN_MM_NULL();
	}
	ZEPHIR_INIT_VAR(_6);
	object_init_ex(_6, phalcon_image_exception_ce);
	ZEPHIR_INIT_VAR(_7);
	ZEPHIR_CONCAT_SVS(_7, "Installed GD does not support '", ext, "' images");
	zephir_call_method_p1_noret(_6, "__construct", _7);
	zephir_throw_exception(_6 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();
	return;

}

PHP_METHOD(Phalcon_Image_Adapter_Gd, _create) {

	zval *width_param = NULL, *height_param = NULL, *image, *_0, *_1;
	int width, height;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &width_param, &height_param);

		width = zephir_get_intval(width_param);
		height = zephir_get_intval(height_param);


	ZEPHIR_INIT_VAR(_0);
	ZVAL_LONG(_0, width);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_LONG(_1, height);
	ZEPHIR_INIT_VAR(image);
	zephir_call_func_p2(image, "imagecreatetruecolor", _0, _1);
	zephir_call_func_p2_noret("imagealphablending", image, ZEPHIR_GLOBAL(global_false));
	zephir_call_func_p2_noret("imagesavealpha", image, ZEPHIR_GLOBAL(global_true));
	RETURN_CCTOR(image);

}

PHP_METHOD(Phalcon_Image_Adapter_Gd, __destruct) {

	zval *image;

	ZEPHIR_MM_GROW();

	image = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
	if ((Z_TYPE_P(image) == IS_RESOURCE)) {
		zephir_call_func_p1_noret("imagedestroy", image);
	}
	ZEPHIR_MM_RESTORE();

}

