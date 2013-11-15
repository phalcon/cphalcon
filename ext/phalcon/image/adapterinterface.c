
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


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
ZEPHIR_INIT_CLASS(Phalcon_Image_AdapterInterface) {

	ZEPHIR_REGISTER_INTERFACE(Phalcon\\Image, AdapterInterface, phalcon, image_adapterinterface, phalcon_image_adapterinterface_method_entry);


	return SUCCESS;

}

ZEPHIR_DOC_METHOD(Phalcon_Image_AdapterInterface, resize);

ZEPHIR_DOC_METHOD(Phalcon_Image_AdapterInterface, crop);

ZEPHIR_DOC_METHOD(Phalcon_Image_AdapterInterface, rotate);

ZEPHIR_DOC_METHOD(Phalcon_Image_AdapterInterface, flip);

ZEPHIR_DOC_METHOD(Phalcon_Image_AdapterInterface, sharpen);

ZEPHIR_DOC_METHOD(Phalcon_Image_AdapterInterface, reflection);

ZEPHIR_DOC_METHOD(Phalcon_Image_AdapterInterface, watermark);

ZEPHIR_DOC_METHOD(Phalcon_Image_AdapterInterface, text);

ZEPHIR_DOC_METHOD(Phalcon_Image_AdapterInterface, mask);

ZEPHIR_DOC_METHOD(Phalcon_Image_AdapterInterface, background);

ZEPHIR_DOC_METHOD(Phalcon_Image_AdapterInterface, blur);

ZEPHIR_DOC_METHOD(Phalcon_Image_AdapterInterface, pixelate);

ZEPHIR_DOC_METHOD(Phalcon_Image_AdapterInterface, save);

ZEPHIR_DOC_METHOD(Phalcon_Image_AdapterInterface, render);

