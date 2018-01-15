
#ifdef HAVE_CONFIG_H
#include "../ext_config.h"
#endif

#include <php.h>
#include "../php_ext.h"
#include "../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"


ZEPHIR_INIT_CLASS(Phalcon_Image) {

	ZEPHIR_REGISTER_CLASS(Phalcon, Image, phalcon, image, NULL, 0);

	zephir_declare_class_constant_long(phalcon_image_ce, SL("NONE"), 1);

	zephir_declare_class_constant_long(phalcon_image_ce, SL("WIDTH"), 2);

	zephir_declare_class_constant_long(phalcon_image_ce, SL("HEIGHT"), 3);

	zephir_declare_class_constant_long(phalcon_image_ce, SL("AUTO"), 4);

	zephir_declare_class_constant_long(phalcon_image_ce, SL("INVERSE"), 5);

	zephir_declare_class_constant_long(phalcon_image_ce, SL("PRECISE"), 6);

	zephir_declare_class_constant_long(phalcon_image_ce, SL("TENSILE"), 7);

	zephir_declare_class_constant_long(phalcon_image_ce, SL("HORIZONTAL"), 11);

	zephir_declare_class_constant_long(phalcon_image_ce, SL("VERTICAL"), 12);

	return SUCCESS;

}

