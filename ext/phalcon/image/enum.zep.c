
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


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
ZEPHIR_INIT_CLASS(Phalcon_Image_Enum)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\Image, Enum, phalcon, image_enum, NULL, 0);

	zephir_declare_class_constant_long(phalcon_image_enum_ce, SL("AUTO"), 4);

	zephir_declare_class_constant_long(phalcon_image_enum_ce, SL("HEIGHT"), 3);

	zephir_declare_class_constant_long(phalcon_image_enum_ce, SL("INVERSE"), 5);

	zephir_declare_class_constant_long(phalcon_image_enum_ce, SL("NONE"), 1);

	zephir_declare_class_constant_long(phalcon_image_enum_ce, SL("PRECISE"), 6);

	zephir_declare_class_constant_long(phalcon_image_enum_ce, SL("TENSILE"), 7);

	zephir_declare_class_constant_long(phalcon_image_enum_ce, SL("WIDTH"), 2);

	zephir_declare_class_constant_long(phalcon_image_enum_ce, SL("HORIZONTAL"), 11);

	zephir_declare_class_constant_long(phalcon_image_enum_ce, SL("VERTICAL"), 12);

	return SUCCESS;
}

