
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
#include "kernel/array.h"
#include "kernel/concat.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/string.h"


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
ZEPHIR_INIT_CLASS(Phalcon_Image_Adapter_Gd) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Image\\Adapter, Gd, phalcon, image_adapter_gd, phalcon_image_adapter_ce, phalcon_image_adapter_gd_method_entry, 0);

	zend_class_implements(phalcon_image_adapter_gd_ce TSRMLS_CC, 1, phalcon_image_adapterinterface_ce);

	return SUCCESS;

}

PHP_METHOD(Phalcon_Image_Adapter_Gd, check) {

	zval *version = NULL, *info, *matches, *_0, _1 = zval_used_for_init, *_2, *_3, *_4, *_5 = NULL, *_6 = NULL, _7, *_8, *_9;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_static_property_ce(phalcon_image_adapter_gd_ce, SL("_checked") TSRMLS_CC);
	if (zephir_is_true(_0)) {
		RETURN_MM_BOOL(1);
	}
	ZEPHIR_SINIT_VAR(_1);
	ZVAL_STRING(&_1, "gd_info", 0);
	ZEPHIR_INIT_VAR(_2);
	zephir_call_func_p1(_2, "function_exists", &_1);
	if (!(zephir_is_true(_2))) {
		ZEPHIR_THROW_EXCEPTION_STR(phalcon_image_exception_ce, "GD is either not installed or not enabled, check your configuration");
		return;
	}
	ZEPHIR_INIT_VAR(version);
	ZVAL_NULL(version);
	ZEPHIR_SINIT_NVAR(_1);
	ZVAL_STRING(&_1, "GD_VERSION", 0);
	ZEPHIR_INIT_VAR(_3);
	zephir_call_func_p1(_3, "defined", &_1);
	if (zephir_is_true(_3)) {
		ZEPHIR_INIT_BNVAR(version);
		ZVAL_STRING(version, "2.0.35", 1);
	} else {
		ZEPHIR_INIT_VAR(info);
		zephir_call_func(info, "gd_info");
		ZEPHIR_INIT_VAR(matches);
		ZVAL_NULL(matches);
		zephir_array_fetch_string(&_4, info, SL("GD Version"), PH_NOISY | PH_READONLY TSRMLS_CC);
		ZEPHIR_INIT_VAR(_5);
		ZVAL_STRING(_5, "/\d+\.\d+(?:\.\d+)?/", 1);
		Z_SET_ISREF_P(matches);
		ZEPHIR_INIT_VAR(_6);
		zephir_call_func_p3(_6, "preg_match", _5, _4, matches);
		if (zephir_is_true(_6)) {
			ZEPHIR_OBS_NVAR(version);
			zephir_array_fetch_long(&version, matches, 0, PH_NOISY TSRMLS_CC);
		}
	}
	ZEPHIR_SINIT_NVAR(_1);
	ZVAL_STRING(&_1, "2.0.1", 0);
	ZEPHIR_SINIT_VAR(_7);
	ZVAL_STRING(&_7, ">=", 0);
	ZEPHIR_INIT_NVAR(_5);
	zephir_call_func_p3(_5, "version_compare", version, &_1, &_7);
	if (!(zephir_is_true(_5))) {
		ZEPHIR_INIT_NVAR(_6);
		object_init_ex(_6, phalcon_image_exception_ce);
		ZEPHIR_INIT_VAR(_8);
		ZEPHIR_CONCAT_SV(_8, "Phalcon\\Image\\Adapter\\GD requires GD version '2.0.1' or greater, you have ", version);
		zephir_call_method_p1_noret(_6, "__construct", _8);
		zephir_throw_exception(_6 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_update_static_property_ce(phalcon_image_adapter_gd_ce, SL("_checked"), ZEPHIR_GLOBAL(global_true) TSRMLS_CC);
	_9 = zephir_fetch_static_property_ce(phalcon_image_adapter_gd_ce, SL("_checked") TSRMLS_CC);
	RETURN_CTOR(_9);

}

PHP_METHOD(Phalcon_Image_Adapter_Gd, __construct) {

	int width, height;
	zval *file_param = NULL, *width_param = NULL, *height_param = NULL, *imageinfo, *_0, *_1, *_2, *_3, *_4 = NULL, *_5, *_6, *_7, *_8, *_9, *_10 = NULL, *_11 = NULL, *_12, _13, _14;
	zval *file = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &file_param, &width_param, &height_param);

		if (Z_TYPE_P(file_param) != IS_STRING) {
				zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'file' must be a string") TSRMLS_CC);
				RETURN_MM_NULL();
		}

		file = file_param;

	if (!width_param || Z_TYPE_P(width_param) == IS_NULL) {
		width = 0;
	} else {
		width = zephir_get_intval(width_param);
	}
	if (!height_param || Z_TYPE_P(height_param) == IS_NULL) {
		height = 0;
	} else {
		height = zephir_get_intval(height_param);
	}


	_0 = zephir_fetch_static_property_ce(phalcon_image_adapter_gd_ce, SL("_checked") TSRMLS_CC);
	if (!(zephir_is_true(_0))) {
	}
	zephir_update_property_this(this_ptr, SL("_file"), file TSRMLS_CC);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("_file"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_2);
	zephir_call_func_p1(_2, "file_exists", _1);
	if (zephir_is_true(_2)) {
		_3 = zephir_fetch_nproperty_this(this_ptr, SL("_file"), PH_NOISY_CC);
		ZEPHIR_INIT_VAR(_4);
		zephir_call_func_p1(_4, "realpath", _3);
		zephir_update_property_this(this_ptr, SL("_realpath"), _4 TSRMLS_CC);
		_5 = zephir_fetch_nproperty_this(this_ptr, SL("_file"), PH_NOISY_CC);
		ZEPHIR_INIT_VAR(imageinfo);
		zephir_call_func_p1(imageinfo, "getimagesize", _5);
		if (zephir_is_true(imageinfo)) {
			zephir_array_fetch_long(&_6, imageinfo, 0, PH_NOISY | PH_READONLY TSRMLS_CC);
			zephir_update_property_this(this_ptr, SL("_width"), _6 TSRMLS_CC);
			zephir_array_fetch_long(&_7, imageinfo, 1, PH_NOISY | PH_READONLY TSRMLS_CC);
			zephir_update_property_this(this_ptr, SL("_height"), _7 TSRMLS_CC);
			zephir_array_fetch_long(&_8, imageinfo, 2, PH_NOISY | PH_READONLY TSRMLS_CC);
			zephir_update_property_this(this_ptr, SL("_type"), _8 TSRMLS_CC);
			zephir_array_fetch_string(&_9, imageinfo, SL("mime"), PH_NOISY | PH_READONLY TSRMLS_CC);
			zephir_update_property_this(this_ptr, SL("_mime"), _9 TSRMLS_CC);
		}
		_6 = zephir_fetch_nproperty_this(this_ptr, SL("_type"), PH_NOISY_CC);
		do {
			if (ZEPHIR_IS_LONG(_6, 1)) {
				_7 = zephir_fetch_nproperty_this(this_ptr, SL("_file"), PH_NOISY_CC);
				ZEPHIR_INIT_VAR(_10);
				zephir_call_func_p1(_10, "imagecreatefromgif", _7);
				zephir_update_property_this(this_ptr, SL("_image"), _10 TSRMLS_CC);
				break;
			}
			if (ZEPHIR_IS_LONG(_6, 2)) {
				_6 = zephir_fetch_nproperty_this(this_ptr, SL("_file"), PH_NOISY_CC);
				ZEPHIR_INIT_NVAR(_10);
				zephir_call_func_p1(_10, "imagecreatefromjpeg", _6);
				zephir_update_property_this(this_ptr, SL("_image"), _10 TSRMLS_CC);
				break;
			}
			if (ZEPHIR_IS_LONG(_6, 3)) {
				_6 = zephir_fetch_nproperty_this(this_ptr, SL("_file"), PH_NOISY_CC);
				ZEPHIR_INIT_NVAR(_10);
				zephir_call_func_p1(_10, "imagecreatefrompng", _6);
				zephir_update_property_this(this_ptr, SL("_image"), _10 TSRMLS_CC);
				break;
			}
			if (ZEPHIR_IS_LONG(_6, 15)) {
				_6 = zephir_fetch_nproperty_this(this_ptr, SL("_file"), PH_NOISY_CC);
				ZEPHIR_INIT_NVAR(_10);
				zephir_call_func_p1(_10, "imagecreatefromwbmp", _6);
				zephir_update_property_this(this_ptr, SL("_image"), _10 TSRMLS_CC);
				break;
			}
			if (ZEPHIR_IS_LONG(_6, 16)) {
				_6 = zephir_fetch_nproperty_this(this_ptr, SL("_file"), PH_NOISY_CC);
				ZEPHIR_INIT_NVAR(_10);
				zephir_call_func_p1(_10, "imagecreatefromxbm", _6);
				zephir_update_property_this(this_ptr, SL("_image"), _10 TSRMLS_CC);
				break;
			}
			_6 = zephir_fetch_nproperty_this(this_ptr, SL("_mime"), PH_NOISY_CC);
			if (zephir_is_true(_6)) {
				ZEPHIR_INIT_NVAR(_10);
				object_init_ex(_10, phalcon_image_exception_ce);
				_7 = zephir_fetch_nproperty_this(this_ptr, SL("_mime"), PH_NOISY_CC);
				ZEPHIR_INIT_VAR(_11);
				ZEPHIR_CONCAT_SVS(_11, "Installed GD does not support ", _7, " images");
				zephir_call_method_p1_noret(_10, "__construct", _11);
				zephir_throw_exception(_10 TSRMLS_CC);
				ZEPHIR_MM_RESTORE();
				return;
			} else {
				ZEPHIR_INIT_NVAR(_10);
				object_init_ex(_10, phalcon_image_exception_ce);
				ZEPHIR_INIT_VAR(_12);
				ZVAL_STRING(_12, "Installed GD does not support such images", 1);
				zephir_call_method_p1_noret(_10, "__construct", _12);
				zephir_throw_exception(_10 TSRMLS_CC);
				ZEPHIR_MM_RESTORE();
				return;
			}
			break;
		} while(0);

		_6 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		zephir_call_func_p2_noret("imagesavealpha", _6, ZEPHIR_GLOBAL(global_true));
	} else {
		if ((!width || !height)) {
			ZEPHIR_INIT_NVAR(_4);
			object_init_ex(_4, phalcon_image_exception_ce);
			_3 = zephir_fetch_nproperty_this(this_ptr, SL("_file"), PH_NOISY_CC);
			ZEPHIR_INIT_LNVAR(_11);
			ZEPHIR_CONCAT_SV(_11, "Failed to create image from file ", _3);
			zephir_call_method_p1_noret(_4, "__construct", _11);
			zephir_throw_exception(_4 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_SINIT_VAR(_13);
		ZVAL_LONG(&_13, width);
		ZEPHIR_SINIT_VAR(_14);
		ZVAL_LONG(&_14, height);
		ZEPHIR_INIT_NVAR(_4);
		zephir_call_func_p2(_4, "imagecreatetruecolor", &_13, &_14);
		zephir_update_property_this(this_ptr, SL("_image"), _4 TSRMLS_CC);
		_5 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		zephir_call_func_p2_noret("imagealphablending", _5, ZEPHIR_GLOBAL(global_true));
		_6 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		zephir_call_func_p2_noret("imagesavealpha", _6, ZEPHIR_GLOBAL(global_true));
		_7 = zephir_fetch_nproperty_this(this_ptr, SL("_file"), PH_NOISY_CC);
		zephir_update_property_this(this_ptr, SL("_realpath"), _7 TSRMLS_CC);
		ZEPHIR_INIT_ZVAL_NREF(_8);
		ZVAL_LONG(_8, width);
		zephir_update_property_zval(this_ptr, SL("_width"), _8 TSRMLS_CC);
		ZEPHIR_INIT_ZVAL_NREF(_8);
		ZVAL_LONG(_8, height);
		zephir_update_property_zval(this_ptr, SL("_height"), _8 TSRMLS_CC);
		ZEPHIR_INIT_ZVAL_NREF(_8);
		ZVAL_LONG(_8, 3);
		zephir_update_property_this(this_ptr, SL("_type"), _8 TSRMLS_CC);
		ZEPHIR_INIT_ZVAL_NREF(_8);
		ZVAL_STRING(_8, "image/png", 1);
		zephir_update_property_this(this_ptr, SL("_mime"), _8 TSRMLS_CC);
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Phalcon_Image_Adapter_Gd, _resize) {

	zval *width_param = NULL, *height_param = NULL, *image, *pre_width = NULL, *pre_height = NULL, *reduction_width, *reduction_height, _0 = zval_used_for_init, _1 = zval_used_for_init, *_2, *_3, *_4, *_5, *_6, *_7, _8 = zval_used_for_init, _9 = zval_used_for_init, *_10 = NULL, *_11, *_12 = NULL, _13, _14, *_15;
	int width, height;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &width_param, &height_param);

		width = zephir_get_intval(width_param);
		height = zephir_get_intval(height_param);


	ZEPHIR_INIT_VAR(image);
	ZEPHIR_SINIT_VAR(_0);
	ZVAL_STRING(&_0, "5.5.1", 0);
	ZEPHIR_SINIT_VAR(_1);
	ZVAL_STRING(&_1, "5.5.0", 0);
	ZEPHIR_INIT_VAR(_2);
	zephir_call_func_p2(_2, "version_compare", &_0, &_1);
	if (ZEPHIR_LT_LONG(_2, 0)) {
		ZEPHIR_OBS_VAR(pre_width);
		zephir_read_property_this(&pre_width, this_ptr, SL("_width"), PH_NOISY_CC);
		ZEPHIR_OBS_VAR(pre_height);
		zephir_read_property_this(&pre_height, this_ptr, SL("_height"), PH_NOISY_CC);
		_3 = zephir_fetch_nproperty_this(this_ptr, SL("_width"), PH_NOISY_CC);
		_4 = zephir_fetch_nproperty_this(this_ptr, SL("_height"), PH_NOISY_CC);
		if (((width > ((zephir_get_numberval(_3) / 2))) && (height > ((zephir_get_numberval(_4) / 2))))) {
			ZEPHIR_SINIT_NVAR(_0);
			ZVAL_LONG(&_0, (width * 1.1));
			ZEPHIR_INIT_VAR(reduction_width);
			zephir_call_func_p1(reduction_width, "round", &_0);
			ZEPHIR_SINIT_NVAR(_0);
			ZVAL_LONG(&_0, (height * 1.1));
			ZEPHIR_INIT_VAR(reduction_height);
			zephir_call_func_p1(reduction_height, "round", &_0);
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
			ZEPHIR_SINIT_NVAR(_0);
			ZVAL_LONG(&_0, 0);
			ZEPHIR_SINIT_NVAR(_1);
			ZVAL_LONG(&_1, 0);
			ZEPHIR_SINIT_VAR(_8);
			ZVAL_LONG(&_8, 0);
			ZEPHIR_SINIT_VAR(_9);
			ZVAL_LONG(&_9, 0);
			ZEPHIR_INIT_VAR(_10);
			zephir_call_func_p10(_10, "imagecopyresized", image, _5, &_0, &_1, &_8, &_9, pre_width, pre_height, _6, _7);
			if (zephir_is_true(_10)) {
				_11 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
				zephir_call_func_p1_noret("imagedestroy", _11);
				zephir_update_property_this(this_ptr, SL("_image"), image TSRMLS_CC);
			}
		}
		ZEPHIR_INIT_NVAR(_10);
		ZVAL_LONG(_10, width);
		ZEPHIR_INIT_VAR(_12);
		ZVAL_LONG(_12, height);
		zephir_call_method_p2(image, this_ptr, "_create", _10, _12);
		_5 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		ZEPHIR_SINIT_NVAR(_0);
		ZVAL_LONG(&_0, 0);
		ZEPHIR_SINIT_NVAR(_1);
		ZVAL_LONG(&_1, 0);
		ZEPHIR_SINIT_NVAR(_8);
		ZVAL_LONG(&_8, 0);
		ZEPHIR_SINIT_NVAR(_9);
		ZVAL_LONG(&_9, 0);
		ZEPHIR_SINIT_VAR(_13);
		ZVAL_LONG(&_13, width);
		ZEPHIR_SINIT_VAR(_14);
		ZVAL_LONG(&_14, height);
		ZEPHIR_INIT_NVAR(_10);
		zephir_call_func_p10(_10, "imagecopyresampled", image, _5, &_0, &_1, &_8, &_9, &_13, &_14, pre_width, pre_height);
		if (zephir_is_true(_10)) {
			_6 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
			zephir_call_func_p1_noret("imagedestroy", _6);
			zephir_update_property_this(this_ptr, SL("_image"), image TSRMLS_CC);
			ZEPHIR_INIT_NVAR(_12);
			zephir_call_func_p1(_12, "imagesx", image);
			zephir_update_property_this(this_ptr, SL("_width"), _12 TSRMLS_CC);
			ZEPHIR_INIT_VAR(_15);
			zephir_call_func_p1(_15, "imagesy", image);
			zephir_update_property_this(this_ptr, SL("_height"), _15 TSRMLS_CC);
		}
	} else {
		_3 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		ZEPHIR_SINIT_NVAR(_0);
		ZVAL_LONG(&_0, width);
		ZEPHIR_SINIT_NVAR(_1);
		ZVAL_LONG(&_1, height);
		ZEPHIR_INIT_BNVAR(image);
		zephir_call_func_p3(image, "imagescale", _3, &_0, &_1);
		_4 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		zephir_call_func_p1_noret("imagedestroy", _4);
		zephir_update_property_this(this_ptr, SL("_image"), image TSRMLS_CC);
		ZEPHIR_INIT_NVAR(_10);
		zephir_call_func_p1(_10, "imagesx", image);
		zephir_update_property_this(this_ptr, SL("_width"), _10 TSRMLS_CC);
		ZEPHIR_INIT_NVAR(_12);
		zephir_call_func_p1(_12, "imagesx", image);
		zephir_update_property_this(this_ptr, SL("_height"), _12 TSRMLS_CC);
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Phalcon_Image_Adapter_Gd, _crop) {

	zval *width_param = NULL, *height_param = NULL, *offset_x_param = NULL, *offset_y_param = NULL, *image, *rect, _0 = zval_used_for_init, _1 = zval_used_for_init, *_2, *_3, _4, _5, _6, _7, _8, _9, *_10 = NULL, *_11, *_12 = NULL, *_13;
	int width, height, offset_x, offset_y;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 4, 0, &width_param, &height_param, &offset_x_param, &offset_y_param);

		width = zephir_get_intval(width_param);
		height = zephir_get_intval(height_param);
		offset_x = zephir_get_intval(offset_x_param);
		offset_y = zephir_get_intval(offset_y_param);


	ZEPHIR_INIT_VAR(image);
	ZEPHIR_SINIT_VAR(_0);
	ZVAL_STRING(&_0, "5.5.1", 0);
	ZEPHIR_SINIT_VAR(_1);
	ZVAL_STRING(&_1, "5.5.0", 0);
	ZEPHIR_INIT_VAR(_2);
	zephir_call_func_p2(_2, "version_compare", &_0, &_1);
	if (ZEPHIR_LT_LONG(_2, 0)) {
		ZVAL_NULL(image);
		_3 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		ZEPHIR_SINIT_NVAR(_0);
		ZVAL_LONG(&_0, 0);
		ZEPHIR_SINIT_NVAR(_1);
		ZVAL_LONG(&_1, 0);
		ZEPHIR_SINIT_VAR(_4);
		ZVAL_LONG(&_4, offset_x);
		ZEPHIR_SINIT_VAR(_5);
		ZVAL_LONG(&_5, offset_y);
		ZEPHIR_SINIT_VAR(_6);
		ZVAL_LONG(&_6, width);
		ZEPHIR_SINIT_VAR(_7);
		ZVAL_LONG(&_7, height);
		ZEPHIR_SINIT_VAR(_8);
		ZVAL_LONG(&_8, width);
		ZEPHIR_SINIT_VAR(_9);
		ZVAL_LONG(&_9, height);
		ZEPHIR_INIT_VAR(_10);
		zephir_call_func_p10(_10, "imagecopyresampled", image, _3, &_0, &_1, &_4, &_5, &_6, &_7, &_8, &_9);
		if (zephir_is_true(_10)) {
			_11 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
			zephir_call_func_p1_noret("imagedestroy", _11);
			zephir_update_property_this(this_ptr, SL("_image"), image TSRMLS_CC);
			ZEPHIR_INIT_VAR(_12);
			zephir_call_func_p1(_12, "imagesx", image);
			zephir_update_property_this(this_ptr, SL("_width"), _12 TSRMLS_CC);
			ZEPHIR_INIT_VAR(_13);
			zephir_call_func_p1(_13, "imagesy", image);
			zephir_update_property_this(this_ptr, SL("_height"), _13 TSRMLS_CC);
		}
	} else {
		ZEPHIR_INIT_VAR(rect);
		array_init(rect);
		ZEPHIR_INIT_NVAR(_10);
		ZVAL_LONG(_10, offset_x);
		zephir_array_update_string(&rect, SL("x"), &_10, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_NVAR(_10);
		ZVAL_LONG(_10, offset_y);
		zephir_array_update_string(&rect, SL("y"), &_10, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_NVAR(_10);
		ZVAL_LONG(_10, width);
		zephir_array_update_string(&rect, SL("width"), &_10, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_NVAR(_10);
		ZVAL_LONG(_10, height);
		zephir_array_update_string(&rect, SL("height"), &_10, PH_COPY | PH_SEPARATE);
		_3 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		zephir_call_func_p2(image, "imagecrop", _3, rect);
		_11 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		zephir_call_func_p1_noret("imagedestroy", _11);
		zephir_update_property_this(this_ptr, SL("_image"), image TSRMLS_CC);
		ZEPHIR_INIT_NVAR(_10);
		zephir_call_func_p1(_10, "imagesx", image);
		zephir_update_property_this(this_ptr, SL("_width"), _10 TSRMLS_CC);
		ZEPHIR_INIT_NVAR(_12);
		zephir_call_func_p1(_12, "imagesx", image);
		zephir_update_property_this(this_ptr, SL("_height"), _12 TSRMLS_CC);
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Phalcon_Image_Adapter_Gd, _rotate) {

	zval *degrees_param = NULL, *image, *transparent, *width, *height, *_0, _1 = zval_used_for_init, _2 = zval_used_for_init, _3 = zval_used_for_init, _4 = zval_used_for_init, *_5, *_6, _7, *_8, *_9;
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
	ZEPHIR_SINIT_NVAR(_1);
	ZVAL_LONG(&_1, (360 - degrees));
	ZEPHIR_SINIT_NVAR(_2);
	ZVAL_LONG(&_2, 1);
	ZEPHIR_INIT_VAR(image);
	zephir_call_func_p4(image, "imagerotate", _5, &_1, transparent, &_2);
	zephir_call_func_p2_noret("imagesavealpha", image, ZEPHIR_GLOBAL(global_true));
	ZEPHIR_INIT_VAR(width);
	zephir_call_func_p1(width, "imagesx", image);
	ZEPHIR_INIT_VAR(height);
	zephir_call_func_p1(height, "imagesy", image);
	_6 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
	ZEPHIR_SINIT_NVAR(_1);
	ZVAL_LONG(&_1, 0);
	ZEPHIR_SINIT_NVAR(_2);
	ZVAL_LONG(&_2, 0);
	ZEPHIR_SINIT_NVAR(_3);
	ZVAL_LONG(&_3, 0);
	ZEPHIR_SINIT_NVAR(_4);
	ZVAL_LONG(&_4, 0);
	ZEPHIR_SINIT_VAR(_7);
	ZVAL_LONG(&_7, 100);
	ZEPHIR_INIT_VAR(_8);
	zephir_call_func_p9(_8, "imagecopymerge", _6, image, &_1, &_2, &_3, &_4, width, height, &_7);
	if (zephir_is_true(_8)) {
		_9 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		zephir_call_func_p1_noret("imagedestroy", _9);
		zephir_update_property_this(this_ptr, SL("_image"), image TSRMLS_CC);
		zephir_update_property_this(this_ptr, SL("_width"), width TSRMLS_CC);
		zephir_update_property_this(this_ptr, SL("_height"), height TSRMLS_CC);
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Phalcon_Image_Adapter_Gd, _flip) {

	zval *direction_param = NULL, *image, _0 = zval_used_for_init, _1 = zval_used_for_init, *_2, *_3, *_4, *_5, *_6, *_7, *_8, _9 = zval_used_for_init, _10 = zval_used_for_init, _11 = zval_used_for_init, *_12, *_13;
	int direction, x;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &direction_param);

		direction = zephir_get_intval(direction_param);


	ZEPHIR_SINIT_VAR(_0);
	ZVAL_STRING(&_0, "5.5.1", 0);
	ZEPHIR_SINIT_VAR(_1);
	ZVAL_STRING(&_1, "5.5.0", 0);
	ZEPHIR_INIT_VAR(_2);
	zephir_call_func_p2(_2, "version_compare", &_0, &_1);
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
				ZEPHIR_SINIT_NVAR(_0);
				ZVAL_LONG(&_0, x);
				ZEPHIR_SINIT_NVAR(_1);
				ZVAL_LONG(&_1, 0);
				ZEPHIR_SINIT_NVAR(_9);
				ZVAL_LONG(&_9, ((zephir_get_numberval(_7) - x) - 1));
				ZEPHIR_SINIT_NVAR(_10);
				ZVAL_LONG(&_10, 0);
				ZEPHIR_SINIT_NVAR(_11);
				ZVAL_LONG(&_11, 1);
				zephir_call_func_p8_noret("imagecopy", image, _6, &_0, &_1, &_9, &_10, &_11, _8);
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
				ZEPHIR_SINIT_NVAR(_0);
				ZVAL_LONG(&_0, 0);
				ZEPHIR_SINIT_NVAR(_1);
				ZVAL_LONG(&_1, x);
				ZEPHIR_SINIT_NVAR(_9);
				ZVAL_LONG(&_9, 0);
				ZEPHIR_SINIT_NVAR(_10);
				ZVAL_LONG(&_10, ((zephir_get_numberval(_7) - x) - 1));
				ZEPHIR_SINIT_NVAR(_11);
				ZVAL_LONG(&_11, 1);
				zephir_call_func_p8_noret("imagecopy", image, _6, &_0, &_1, &_9, &_10, _8, &_11);
			}
		}
		_5 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		zephir_call_func_p1_noret("imagedestroy", _5);
		zephir_update_property_this(this_ptr, SL("_image"), image TSRMLS_CC);
		ZEPHIR_INIT_VAR(_12);
		zephir_call_func_p1(_12, "imagesx", image);
		zephir_update_property_this(this_ptr, SL("_width"), _12 TSRMLS_CC);
		ZEPHIR_INIT_VAR(_13);
		zephir_call_func_p1(_13, "imagesy", image);
		zephir_update_property_this(this_ptr, SL("_height"), _13 TSRMLS_CC);
	} else {
		if ((direction == 11)) {
			_3 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
			ZEPHIR_SINIT_NVAR(_0);
			ZVAL_LONG(&_0, 1);
			zephir_call_func_p2_noret("imageflip", _3, &_0);
		} else {
			_4 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
			ZEPHIR_SINIT_NVAR(_0);
			ZVAL_LONG(&_0, 2);
			zephir_call_func_p2_noret("imageflip", _4, &_0);
		}
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Phalcon_Image_Adapter_Gd, _sharpen) {

	zval *amount_param = NULL, *matrix, _0 = zval_used_for_init, *_1, *_2, *_3, *_4, _5, *_6, *_7, *_8;
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
	array_init(matrix);
	ZEPHIR_INIT_BNVAR(_2);
	array_init(_2);
	ZEPHIR_INIT_VAR(_3);
	ZVAL_LONG(_3, -1);
	zephir_array_fast_append(_2, _3);
	ZEPHIR_INIT_BNVAR(_3);
	ZVAL_LONG(_3, -1);
	zephir_array_fast_append(_2, _3);
	ZEPHIR_INIT_BNVAR(_3);
	ZVAL_LONG(_3, -1);
	zephir_array_fast_append(_2, _3);
	zephir_array_fast_append(matrix, _2);
	ZEPHIR_INIT_BNVAR(_2);
	array_init(_2);
	ZEPHIR_INIT_BNVAR(_3);
	ZVAL_LONG(_3, -1);
	zephir_array_fast_append(_2, _3);
	ZEPHIR_INIT_BNVAR(_3);
	ZVAL_LONG(_3, amount);
	zephir_array_fast_append(_2, _3);
	ZEPHIR_INIT_BNVAR(_3);
	ZVAL_LONG(_3, -1);
	zephir_array_fast_append(_2, _3);
	zephir_array_fast_append(matrix, _2);
	ZEPHIR_INIT_BNVAR(_2);
	array_init(_2);
	ZEPHIR_INIT_BNVAR(_3);
	ZVAL_LONG(_3, -1);
	zephir_array_fast_append(_2, _3);
	ZEPHIR_INIT_BNVAR(_3);
	ZVAL_LONG(_3, -1);
	zephir_array_fast_append(_2, _3);
	ZEPHIR_INIT_BNVAR(_3);
	ZVAL_LONG(_3, -1);
	zephir_array_fast_append(_2, _3);
	zephir_array_fast_append(matrix, _2);
	_4 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
	ZEPHIR_SINIT_NVAR(_0);
	ZVAL_LONG(&_0, (amount - 8));
	ZEPHIR_SINIT_VAR(_5);
	ZVAL_LONG(&_5, 0);
	ZEPHIR_INIT_BNVAR(_2);
	zephir_call_func_p4(_2, "imageconvolution", _4, matrix, &_0, &_5);
	if (zephir_is_true(_2)) {
		_6 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		ZEPHIR_INIT_BNVAR(_3);
		zephir_call_func_p1(_3, "imagesx", _6);
		zephir_update_property_this(this_ptr, SL("_width"), _3 TSRMLS_CC);
		_7 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		ZEPHIR_INIT_VAR(_8);
		zephir_call_func_p1(_8, "imagesy", _7);
		zephir_update_property_this(this_ptr, SL("_height"), _8 TSRMLS_CC);
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Phalcon_Image_Adapter_Gd, _reflection) {

	zend_function *_14 = NULL;
	zend_bool fade_in;
	zval *height_param = NULL, *opacity_param = NULL, *fade_in_param = NULL, *reflection, *line = NULL, _0 = zval_used_for_init, *_1, *_2 = NULL, *_3, *_4, *_5, *_6, *_7, _8 = zval_used_for_init, _9 = zval_used_for_init, _10 = zval_used_for_init, *_11, *_12, *_13, *_15, *_16, _17 = zval_used_for_init, *_18, *_19;
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
	ZEPHIR_INIT_BNVAR(_2);
	ZVAL_LONG(_2, (zephir_get_numberval(_4) + height));
	ZEPHIR_INIT_VAR(reflection);
	zephir_call_method_p2(reflection, this_ptr, "_create", _3, _2);
	_5 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
	_6 = zephir_fetch_nproperty_this(this_ptr, SL("_width"), PH_NOISY_CC);
	_7 = zephir_fetch_nproperty_this(this_ptr, SL("_height"), PH_NOISY_CC);
	ZEPHIR_SINIT_NVAR(_0);
	ZVAL_LONG(&_0, 0);
	ZEPHIR_SINIT_VAR(_8);
	ZVAL_LONG(&_8, 0);
	ZEPHIR_SINIT_VAR(_9);
	ZVAL_LONG(&_9, 0);
	ZEPHIR_SINIT_VAR(_10);
	ZVAL_LONG(&_10, 0);
	zephir_call_func_p8_noret("imagecopy", reflection, _5, &_0, &_8, &_9, &_10, _6, _7);
	offset = 0;
	while (1) {
		if (!((height >= offset))) {
			break;
		}
		_11 = zephir_fetch_nproperty_this(this_ptr, SL("_height"), PH_NOISY_CC);
		src_y = ((zephir_get_numberval(_11) - offset) - 1);
		_12 = zephir_fetch_nproperty_this(this_ptr, SL("_height"), PH_NOISY_CC);
		dst_y = (zephir_get_numberval(_12) + offset);
		if (fade_in) {
			ZEPHIR_SINIT_NVAR(_0);
			ZVAL_LONG(&_0, (opacity + ((stepping * ((height - offset))))));
			ZEPHIR_INIT_NVAR(_2);
			zephir_call_func_p1(_2, "round", &_0);
			dst_opacity = zephir_get_intval(_2);
		} else {
			ZEPHIR_SINIT_NVAR(_0);
			ZVAL_LONG(&_0, (opacity + ((stepping * offset))));
			ZEPHIR_INIT_NVAR(_2);
			zephir_call_func_p1(_2, "round", &_0);
			dst_opacity = zephir_get_intval(_2);
		}
		_13 = zephir_fetch_nproperty_this(this_ptr, SL("_width"), PH_NOISY_CC);
		ZEPHIR_INIT_NVAR(_2);
		ZVAL_LONG(_2, 1);
		ZEPHIR_INIT_NVAR(line);
		zephir_call_method_p2_cache(line, this_ptr, "_create", &_14, _13, _2);
		_15 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		_16 = zephir_fetch_nproperty_this(this_ptr, SL("_width"), PH_NOISY_CC);
		ZEPHIR_SINIT_NVAR(_0);
		ZVAL_LONG(&_0, 0);
		ZEPHIR_SINIT_NVAR(_8);
		ZVAL_LONG(&_8, 0);
		ZEPHIR_SINIT_NVAR(_9);
		ZVAL_LONG(&_9, 0);
		ZEPHIR_SINIT_NVAR(_10);
		ZVAL_LONG(&_10, src_y);
		ZEPHIR_SINIT_NVAR(_17);
		ZVAL_LONG(&_17, 1);
		zephir_call_func_p8_noret("imagecopy", line, _15, &_0, &_8, &_9, &_10, _16, &_17);
		ZEPHIR_SINIT_NVAR(_0);
		ZVAL_LONG(&_0, 4);
		ZEPHIR_SINIT_NVAR(_8);
		ZVAL_LONG(&_8, 0);
		ZEPHIR_SINIT_NVAR(_9);
		ZVAL_LONG(&_9, 0);
		ZEPHIR_SINIT_NVAR(_10);
		ZVAL_LONG(&_10, 0);
		ZEPHIR_SINIT_NVAR(_17);
		ZVAL_LONG(&_17, dst_opacity);
		zephir_call_func_p6_noret("imagefilter", line, &_0, &_8, &_9, &_10, &_17);
		_18 = zephir_fetch_nproperty_this(this_ptr, SL("_width"), PH_NOISY_CC);
		ZEPHIR_SINIT_NVAR(_0);
		ZVAL_LONG(&_0, 0);
		ZEPHIR_SINIT_NVAR(_8);
		ZVAL_LONG(&_8, dst_y);
		ZEPHIR_SINIT_NVAR(_9);
		ZVAL_LONG(&_9, 0);
		ZEPHIR_SINIT_NVAR(_10);
		ZVAL_LONG(&_10, 0);
		ZEPHIR_SINIT_NVAR(_17);
		ZVAL_LONG(&_17, 1);
		zephir_call_func_p8_noret("imagecopy", reflection, line, &_0, &_8, &_9, &_10, _18, &_17);
		offset++;
	}
	_11 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
	zephir_call_func_p1_noret("imagedestroy", _11);
	zephir_update_property_this(this_ptr, SL("_image"), reflection TSRMLS_CC);
	ZEPHIR_INIT_BNVAR(_2);
	zephir_call_func_p1(_2, "imagesx", reflection);
	zephir_update_property_this(this_ptr, SL("_width"), _2 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_19);
	zephir_call_func_p1(_19, "imagesy", reflection);
	zephir_update_property_this(this_ptr, SL("_height"), _19 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Phalcon_Image_Adapter_Gd, _watermark) {

	int offset_x, offset_y, opacity, width, height;
	zval *watermark, *offset_x_param = NULL, *offset_y_param = NULL, *opacity_param = NULL, *overlay, *color, *_0, *_1, _2 = zval_used_for_init, *_3 = NULL, _4 = zval_used_for_init, _5 = zval_used_for_init, _6 = zval_used_for_init, *_7, *_8, _9, _10;

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
	ZEPHIR_INIT_BNVAR(_1);
	zephir_call_func_p1(_1, "imagesy", overlay);
	height = zephir_get_intval(_1);
	if ((opacity < 100)) {
		ZEPHIR_SINIT_VAR(_2);
		ZVAL_LONG(&_2, ((((opacity * 127) / 100)) - 127));
		ZEPHIR_INIT_BNVAR(_1);
		zephir_call_func_p1(_1, "abs", &_2);
		ZEPHIR_INIT_VAR(_3);
		zephir_call_func_p1(_3, "round", _1);
		opacity = zephir_get_intval(_3);
		ZEPHIR_SINIT_NVAR(_2);
		ZVAL_LONG(&_2, 127);
		ZEPHIR_SINIT_VAR(_4);
		ZVAL_LONG(&_4, 127);
		ZEPHIR_SINIT_VAR(_5);
		ZVAL_LONG(&_5, 127);
		ZEPHIR_SINIT_VAR(_6);
		ZVAL_LONG(&_6, opacity);
		ZEPHIR_INIT_VAR(color);
		zephir_call_func_p5(color, "imagecolorallocatealpha", overlay, &_2, &_4, &_5, &_6);
		ZEPHIR_SINIT_NVAR(_2);
		ZVAL_LONG(&_2, 3);
		zephir_call_func_p2_noret("imagelayereffect", overlay, &_2);
		ZEPHIR_SINIT_NVAR(_2);
		ZVAL_LONG(&_2, 0);
		ZEPHIR_SINIT_NVAR(_4);
		ZVAL_LONG(&_4, 0);
		ZEPHIR_SINIT_NVAR(_5);
		ZVAL_LONG(&_5, width);
		ZEPHIR_SINIT_NVAR(_6);
		ZVAL_LONG(&_6, height);
		zephir_call_func_p6_noret("imagefilledrectangle", overlay, &_2, &_4, &_5, &_6, color);
	}
	_7 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
	zephir_call_func_p2_noret("imagealphablending", _7, ZEPHIR_GLOBAL(global_true));
	_8 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
	ZEPHIR_SINIT_NVAR(_2);
	ZVAL_LONG(&_2, offset_x);
	ZEPHIR_SINIT_NVAR(_4);
	ZVAL_LONG(&_4, offset_y);
	ZEPHIR_SINIT_NVAR(_5);
	ZVAL_LONG(&_5, 0);
	ZEPHIR_SINIT_NVAR(_6);
	ZVAL_LONG(&_6, 0);
	ZEPHIR_SINIT_VAR(_9);
	ZVAL_LONG(&_9, width);
	ZEPHIR_SINIT_VAR(_10);
	ZVAL_LONG(&_10, height);
	ZEPHIR_INIT_NVAR(_3);
	zephir_call_func_p8(_3, "imagecopy", _8, overlay, &_2, &_4, &_5, &_6, &_9, &_10);
	if (zephir_is_true(_3)) {
		zephir_call_func_p1_noret("imagedestroy", overlay);
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Phalcon_Image_Adapter_Gd, _text) {

	int offset_x, offset_y, opacity, r, g, b, size, angle, s0 = 0, s1 = 0, s4 = 0, s5 = 0, width, height;
	zval *text_param = NULL, *offset_x_param = NULL, *offset_y_param = NULL, *opacity_param = NULL, *r_param = NULL, *g_param = NULL, *b_param = NULL, *size_param = NULL, *fontfile_param = NULL, *space, *color, _0 = zval_used_for_init, *_1, *_2, _3 = zval_used_for_init, *_4 = NULL, *_5 = NULL, *_6, _7 = zval_used_for_init, _8 = zval_used_for_init, *_9, *_10;
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
		ZEPHIR_SINIT_NVAR(_0);
		ZVAL_LONG(&_0, size);
		ZEPHIR_SINIT_VAR(_3);
		ZVAL_LONG(&_3, 0);
		ZEPHIR_INIT_VAR(space);
		zephir_call_func_p4(space, "imagettfbbox", &_0, &_3, fontfile, text);
		if (zephir_array_isset_long(space, 0)) {
			ZEPHIR_OBS_VAR(_4);
			zephir_array_fetch_long(&_4, space, 0, PH_NOISY TSRMLS_CC);
			s0 = zephir_get_intval(_4);
			ZEPHIR_OBS_NVAR(_4);
			zephir_array_fetch_long(&_4, space, 1, PH_NOISY TSRMLS_CC);
			s1 = zephir_get_intval(_4);
			ZEPHIR_OBS_NVAR(_4);
			zephir_array_fetch_long(&_4, space, 4, PH_NOISY TSRMLS_CC);
			s4 = zephir_get_intval(_4);
			ZEPHIR_OBS_NVAR(_4);
			zephir_array_fetch_long(&_4, space, 5, PH_NOISY TSRMLS_CC);
			s5 = zephir_get_intval(_4);
		}
		if ((((!s0 || !s1) || !s4) || !s5)) {
			ZEPHIR_INIT_BNVAR(_2);
			object_init_ex(_2, phalcon_image_exception_ce);
			ZEPHIR_INIT_VAR(_5);
			ZVAL_STRING(_5, "Call to imagettfbbox() failed", 1);
			zephir_call_method_p1_noret(_2, "__construct", _5);
			zephir_throw_exception(_2 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_SINIT_NVAR(_0);
		ZVAL_LONG(&_0, (s4 - s0));
		ZEPHIR_INIT_BNVAR(_2);
		zephir_call_func_p1(_2, "abs", &_0);
		width = (zephir_get_numberval(_2) + 10);
		ZEPHIR_SINIT_NVAR(_0);
		ZVAL_LONG(&_0, (s5 - s1));
		ZEPHIR_INIT_NVAR(_5);
		zephir_call_func_p1(_5, "abs", &_0);
		height = (zephir_get_numberval(_5) + 10);
		if ((offset_x < 0)) {
			_6 = zephir_fetch_nproperty_this(this_ptr, SL("_width"), PH_NOISY_CC);
			offset_x = ((zephir_get_numberval(_6) - width) + offset_x);
		}
		if ((offset_y < 0)) {
			_6 = zephir_fetch_nproperty_this(this_ptr, SL("_height"), PH_NOISY_CC);
			offset_y = ((zephir_get_numberval(_6) - height) + offset_y);
		}
		_6 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		ZEPHIR_SINIT_NVAR(_0);
		ZVAL_LONG(&_0, r);
		ZEPHIR_SINIT_NVAR(_3);
		ZVAL_LONG(&_3, g);
		ZEPHIR_SINIT_VAR(_7);
		ZVAL_LONG(&_7, b);
		ZEPHIR_SINIT_VAR(_8);
		ZVAL_LONG(&_8, opacity);
		zephir_call_func_p5(color, "imagecolorallocatealpha", _6, &_0, &_3, &_7, &_8);
		angle = 0;
		_9 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		ZEPHIR_SINIT_NVAR(_0);
		ZVAL_LONG(&_0, size);
		ZEPHIR_SINIT_NVAR(_3);
		ZVAL_LONG(&_3, angle);
		ZEPHIR_SINIT_NVAR(_7);
		ZVAL_LONG(&_7, offset_x);
		ZEPHIR_SINIT_NVAR(_8);
		ZVAL_LONG(&_8, offset_y);
		zephir_call_func_p8_noret("imagettftext", _9, &_0, &_3, &_7, &_8, color, fontfile, text);
	} else {
		ZEPHIR_SINIT_NVAR(_0);
		ZVAL_LONG(&_0, size);
		ZEPHIR_INIT_NVAR(_5);
		zephir_call_func_p1(_5, "imagefontwidth", &_0);
		width = (zephir_get_intval(_5) * zephir_fast_strlen_ev(text));
		ZEPHIR_SINIT_NVAR(_0);
		ZVAL_LONG(&_0, size);
		ZEPHIR_INIT_NVAR(_5);
		zephir_call_func_p1(_5, "imagefontheight", &_0);
		height = zephir_get_intval(_5);
		if ((offset_x < 0)) {
			_9 = zephir_fetch_nproperty_this(this_ptr, SL("_width"), PH_NOISY_CC);
			offset_x = ((zephir_get_numberval(_9) - width) + offset_x);
		}
		if ((offset_y < 0)) {
			_6 = zephir_fetch_nproperty_this(this_ptr, SL("_height"), PH_NOISY_CC);
			offset_y = ((zephir_get_numberval(_6) - height) + offset_y);
		}
		_6 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		ZEPHIR_SINIT_NVAR(_0);
		ZVAL_LONG(&_0, r);
		ZEPHIR_SINIT_NVAR(_3);
		ZVAL_LONG(&_3, g);
		ZEPHIR_SINIT_NVAR(_7);
		ZVAL_LONG(&_7, b);
		ZEPHIR_SINIT_NVAR(_8);
		ZVAL_LONG(&_8, opacity);
		zephir_call_func_p5(color, "imagecolorallocatealpha", _6, &_0, &_3, &_7, &_8);
		_10 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		ZEPHIR_SINIT_NVAR(_0);
		ZVAL_LONG(&_0, size);
		ZEPHIR_SINIT_NVAR(_3);
		ZVAL_LONG(&_3, offset_x);
		ZEPHIR_SINIT_NVAR(_7);
		ZVAL_LONG(&_7, offset_y);
		zephir_call_func_p6_noret("imagestring", _10, &_0, &_3, &_7, text, color);
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Phalcon_Image_Adapter_Gd, _mask) {

	int mask_width, mask_height, x, y, _16;
	zval *mask, *maskImage = NULL, *newimage, *tempImage, *color = NULL, *index = NULL, *alpha = NULL, *_0, *_1, *_2, *_3, _4 = zval_used_for_init, _5 = zval_used_for_init, _6 = zval_used_for_init, _7 = zval_used_for_init, *_8, *_9, *_10, *_11, *_12, *_13, _14, _15, *_17, *_18, *_19, *_20;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &mask);



	ZEPHIR_INIT_VAR(_0);
	zephir_call_method(_0, mask, "render");
	ZEPHIR_INIT_VAR(maskImage);
	zephir_call_func_p1(maskImage, "imagecreatefromstring", _0);
	ZEPHIR_INIT_VAR(_1);
	zephir_call_func_p1(_1, "imagesx", mask);
	mask_width = zephir_get_intval(_1);
	ZEPHIR_INIT_BNVAR(_1);
	zephir_call_func_p1(_1, "imagesy", mask);
	mask_height = zephir_get_intval(_1);
	ZEPHIR_INIT_VAR(alpha);
	ZVAL_LONG(alpha, 127);
	zephir_call_func_p2_noret("imagesavealpha", mask, ZEPHIR_GLOBAL(global_true));
	_2 = zephir_fetch_nproperty_this(this_ptr, SL("_width"), PH_NOISY_CC);
	_3 = zephir_fetch_nproperty_this(this_ptr, SL("_height"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(newimage);
	zephir_call_method_p2(newimage, this_ptr, "_create", _2, _3);
	zephir_call_func_p2_noret("imagesavealpha", newimage, ZEPHIR_GLOBAL(global_true));
	ZEPHIR_SINIT_VAR(_4);
	ZVAL_LONG(&_4, 0);
	ZEPHIR_SINIT_VAR(_5);
	ZVAL_LONG(&_5, 0);
	ZEPHIR_SINIT_VAR(_6);
	ZVAL_LONG(&_6, 0);
	ZEPHIR_SINIT_VAR(_7);
	ZVAL_LONG(&_7, 127);
	ZEPHIR_INIT_VAR(color);
	zephir_call_func_p5(color, "imagecolorallocatealpha", newimage, &_4, &_5, &_6, &_7);
	ZEPHIR_SINIT_NVAR(_4);
	ZVAL_LONG(&_4, 0);
	ZEPHIR_SINIT_NVAR(_5);
	ZVAL_LONG(&_5, 0);
	zephir_call_func_p4_noret("imagefill", newimage, &_4, &_5, color);
	_8 = zephir_fetch_nproperty_this(this_ptr, SL("_width"), PH_NOISY_CC);
	_9 = zephir_fetch_nproperty_this(this_ptr, SL("_height"), PH_NOISY_CC);
	if ((!ZEPHIR_IS_LONG(_8, mask_width) || !ZEPHIR_IS_LONG(_9, mask_height))) {
		_10 = zephir_fetch_nproperty_this(this_ptr, SL("_width"), PH_NOISY_CC);
		_11 = zephir_fetch_nproperty_this(this_ptr, SL("_height"), PH_NOISY_CC);
		ZEPHIR_INIT_VAR(tempImage);
		zephir_call_func_p2(tempImage, "imagecreatetruecolor", _10, _11);
		_12 = zephir_fetch_nproperty_this(this_ptr, SL("_width"), PH_NOISY_CC);
		_13 = zephir_fetch_nproperty_this(this_ptr, SL("_height"), PH_NOISY_CC);
		ZEPHIR_SINIT_NVAR(_4);
		ZVAL_LONG(&_4, 0);
		ZEPHIR_SINIT_NVAR(_5);
		ZVAL_LONG(&_5, 0);
		ZEPHIR_SINIT_NVAR(_6);
		ZVAL_LONG(&_6, 0);
		ZEPHIR_SINIT_NVAR(_7);
		ZVAL_LONG(&_7, 0);
		ZEPHIR_SINIT_VAR(_14);
		ZVAL_LONG(&_14, mask_width);
		ZEPHIR_SINIT_VAR(_15);
		ZVAL_LONG(&_15, mask_height);
		zephir_call_func_p10_noret("imagecopyresampled", tempImage, maskImage, &_4, &_5, &_6, &_7, _12, _13, &_14, &_15);
		zephir_call_func_p1_noret("imagedestroy", maskImage);
		ZEPHIR_CPY_WRT(maskImage, tempImage);
	}
	x = 0;
	while (1) {
		_10 = zephir_fetch_nproperty_this(this_ptr, SL("_width"), PH_NOISY_CC);
		if (!(ZEPHIR_LT_LONG(_10, x))) {
			break;
		}
		y = 0;
		while (1) {
			_11 = zephir_fetch_nproperty_this(this_ptr, SL("_height"), PH_NOISY_CC);
			if (!(ZEPHIR_LT_LONG(_11, y))) {
				break;
			}
			ZEPHIR_SINIT_NVAR(_4);
			ZVAL_LONG(&_4, x);
			ZEPHIR_SINIT_NVAR(_5);
			ZVAL_LONG(&_5, y);
			ZEPHIR_INIT_NVAR(index);
			zephir_call_func_p3(index, "imagecolorat", maskImage, &_4, &_5);
			ZEPHIR_INIT_NVAR(color);
			zephir_call_func_p2(color, "imagecolorsforindex", maskImage, index);
			if (zephir_array_isset_string(color, SS("red"))) {
				zephir_array_fetch_string(&_12, alpha, SL("red"), PH_NOISY | PH_READONLY TSRMLS_CC);
				_16 = (127 - ((zephir_get_numberval(_12) / 2)));
				ZEPHIR_INIT_NVAR(alpha);
				ZVAL_LONG(alpha, _16);
			}
			_13 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
			ZEPHIR_SINIT_NVAR(_4);
			ZVAL_LONG(&_4, x);
			ZEPHIR_SINIT_NVAR(_5);
			ZVAL_LONG(&_5, y);
			ZEPHIR_INIT_NVAR(index);
			zephir_call_func_p3(index, "imagecolorat", _13, &_4, &_5);
			_17 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
			ZEPHIR_INIT_NVAR(color);
			zephir_call_func_p2(color, "imagecolorsforindex", _17, index);
			zephir_array_fetch_string(&_18, color, SL("red"), PH_NOISY | PH_READONLY TSRMLS_CC);
			zephir_array_fetch_string(&_19, color, SL("green"), PH_NOISY | PH_READONLY TSRMLS_CC);
			zephir_array_fetch_string(&_20, color, SL("blue"), PH_NOISY | PH_READONLY TSRMLS_CC);
			ZEPHIR_INIT_NVAR(color);
			zephir_call_func_p5(color, "imagecolorallocatealpha", newimage, _18, _19, _20, alpha);
			ZEPHIR_SINIT_NVAR(_4);
			ZVAL_LONG(&_4, x);
			ZEPHIR_SINIT_NVAR(_5);
			ZVAL_LONG(&_5, y);
			zephir_call_func_p4_noret("imagesetpixel", newimage, &_4, &_5, color);
			y++;
		}
		x++;
	}
	_10 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
	zephir_call_func_p1_noret("imagedestroy", _10);
	zephir_call_func_p1_noret("imagedestroy", maskImage);
	zephir_update_property_this(this_ptr, SL("_image"), newimage TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Phalcon_Image_Adapter_Gd, _background) {

	zval *r_param = NULL, *g_param = NULL, *b_param = NULL, *opacity_param = NULL, *background, *color, *_0, *_1, _2 = zval_used_for_init, _3 = zval_used_for_init, _4 = zval_used_for_init, _5 = zval_used_for_init, *_6, *_7, *_8, *_9, *_10;
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
	ZEPHIR_SINIT_NVAR(_2);
	ZVAL_LONG(&_2, 0);
	ZEPHIR_SINIT_NVAR(_3);
	ZVAL_LONG(&_3, 0);
	ZEPHIR_SINIT_NVAR(_4);
	ZVAL_LONG(&_4, 0);
	ZEPHIR_SINIT_NVAR(_5);
	ZVAL_LONG(&_5, 0);
	ZEPHIR_INIT_VAR(_9);
	zephir_call_func_p8(_9, "imagecopy", background, _6, &_2, &_3, &_4, &_5, _7, _8);
	if (zephir_is_true(_9)) {
		_10 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		zephir_call_func_p1_noret("imagedestroy", _10);
		zephir_update_property_this(this_ptr, SL("_image"), background TSRMLS_CC);
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Phalcon_Image_Adapter_Gd, _blur) {

	zval *radius_param = NULL, *_0, _1 = zval_used_for_init;
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
		ZEPHIR_SINIT_NVAR(_1);
		ZVAL_LONG(&_1, 7);
		zephir_call_func_p2_noret("imagefilter", _0, &_1);
		i++;
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Phalcon_Image_Adapter_Gd, _pixelate) {

	zval *amount_param = NULL, *color = NULL, *_0, *_1, *_2, _3 = zval_used_for_init, _4 = zval_used_for_init, *_5, _6 = zval_used_for_init, _7 = zval_used_for_init;
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
			ZEPHIR_SINIT_NVAR(_3);
			ZVAL_LONG(&_3, x1);
			ZEPHIR_SINIT_NVAR(_4);
			ZVAL_LONG(&_4, y1);
			ZEPHIR_SINIT_NVAR(_6);
			ZVAL_LONG(&_6, x2);
			ZEPHIR_SINIT_NVAR(_7);
			ZVAL_LONG(&_7, y2);
			zephir_call_func_p6_noret("imagefilledrectangle", _5, &_3, &_4, &_6, &_7, color);
			y += amount;
		}
		x += amount;
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Phalcon_Image_Adapter_Gd, _save) {

	int quality;
	zval *file_param = NULL, *quality_param = NULL, *ext, _0 = zval_used_for_init, *_1, *_2, *_3 = NULL, *_4, *_5, *_6 = NULL, *_7;
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
		ZEPHIR_SINIT_NVAR(_0);
		ZVAL_LONG(&_0, quality);
		zephir_call_func_p3_noret("imagejpeg", _4, file, &_0);
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
	ZEPHIR_INIT_NVAR(_3);
	object_init_ex(_3, phalcon_image_exception_ce);
	ZEPHIR_INIT_VAR(_7);
	ZEPHIR_CONCAT_SVS(_7, "Installed GD does not support '", ext, "' images");
	zephir_call_method_p1_noret(_3, "__construct", _7);
	zephir_throw_exception(_3 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();
	return;

}

PHP_METHOD(Phalcon_Image_Adapter_Gd, _render) {

	int quality;
	zval *ext_param = NULL, *quality_param = NULL, _0 = zval_used_for_init, *_1, *_2, *_3, *_4, *_5, *_6, *_7, *_8, *_9;
	zval *ext = NULL;

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
		ZEPHIR_SINIT_NVAR(_0);
		ZVAL_LONG(&_0, quality);
		zephir_call_func_p3_noret("imagejpeg", _2, ZEPHIR_GLOBAL(global_null), &_0);
		RETURN_MM_NULL();
	}
	ZEPHIR_SINIT_NVAR(_0);
	ZVAL_STRING(&_0, "png", 0);
	ZEPHIR_INIT_VAR(_5);
	zephir_call_func_p2(_5, "strcmp", ext, &_0);
	if (ZEPHIR_IS_LONG(_5, 0)) {
		_2 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		zephir_call_func_p1_noret("imagejpeg", _2);
		RETURN_MM_NULL();
	}
	ZEPHIR_SINIT_NVAR(_0);
	ZVAL_STRING(&_0, "wbmp", 0);
	ZEPHIR_INIT_VAR(_6);
	zephir_call_func_p2(_6, "strcmp", ext, &_0);
	if (ZEPHIR_IS_LONG(_6, 0)) {
		_2 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		zephir_call_func_p1_noret("imagewbmp", _2);
		RETURN_MM_NULL();
	}
	ZEPHIR_SINIT_NVAR(_0);
	ZVAL_STRING(&_0, "xbm", 0);
	ZEPHIR_INIT_VAR(_7);
	zephir_call_func_p2(_7, "strcmp", ext, &_0);
	if (ZEPHIR_IS_LONG(_7, 0)) {
		_2 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		zephir_call_func_p2_noret("imagexbm", _2, ZEPHIR_GLOBAL(global_null));
		RETURN_MM_NULL();
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

PHP_METHOD(Phalcon_Image_Adapter_Gd, _create) {

	zval *width_param = NULL, *height_param = NULL, *image, _0, _1;
	int width, height;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &width_param, &height_param);

		width = zephir_get_intval(width_param);
		height = zephir_get_intval(height_param);


	ZEPHIR_SINIT_VAR(_0);
	ZVAL_LONG(&_0, width);
	ZEPHIR_SINIT_VAR(_1);
	ZVAL_LONG(&_1, height);
	ZEPHIR_INIT_VAR(image);
	zephir_call_func_p2(image, "imagecreatetruecolor", &_0, &_1);
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

