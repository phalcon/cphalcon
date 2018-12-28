
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
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

