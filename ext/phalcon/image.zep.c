
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

	zend_declare_class_constant_long(phalcon_image_ce, SL("NONE"), 1 TSRMLS_CC);

	zend_declare_class_constant_long(phalcon_image_ce, SL("WIDTH"), 2 TSRMLS_CC);

	zend_declare_class_constant_long(phalcon_image_ce, SL("HEIGHT"), 3 TSRMLS_CC);

	zend_declare_class_constant_long(phalcon_image_ce, SL("AUTO"), 4 TSRMLS_CC);

	zend_declare_class_constant_long(phalcon_image_ce, SL("INVERSE"), 5 TSRMLS_CC);

	zend_declare_class_constant_long(phalcon_image_ce, SL("PRECISE"), 6 TSRMLS_CC);

	zend_declare_class_constant_long(phalcon_image_ce, SL("TENSILE"), 7 TSRMLS_CC);

	zend_declare_class_constant_long(phalcon_image_ce, SL("HORIZONTAL"), 11 TSRMLS_CC);

	zend_declare_class_constant_long(phalcon_image_ce, SL("VERTICAL"), 12 TSRMLS_CC);

	return SUCCESS;

}

