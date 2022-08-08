
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * Interface for Phalcon\Image\Adapter classes
 */
ZEPHIR_INIT_CLASS(Phalcon_Image_Adapter_AdapterInterface)
{
	ZEPHIR_REGISTER_INTERFACE(Phalcon\\Image\\Adapter, AdapterInterface, phalcon, image_adapter_adapterinterface, phalcon_image_adapter_adapterinterface_method_entry);

	return SUCCESS;
}

/**
 * Add a background to an image
 *
 * @param string $color
 * @param int    $opacity
 *
 * @return AdapterInterface
 */
ZEPHIR_DOC_METHOD(Phalcon_Image_Adapter_AdapterInterface, background);
/**
 * Blur an image
 *
 * @param int $radius
 *
 * @return AdapterInterface
 */
ZEPHIR_DOC_METHOD(Phalcon_Image_Adapter_AdapterInterface, blur);
/**
 * Crop an image
 *
 * @param int      $width
 * @param int      $height
 * @param int|null $offsetX
 * @param int|null $offsetY
 *
 * @return AdapterInterface
 */
ZEPHIR_DOC_METHOD(Phalcon_Image_Adapter_AdapterInterface, crop);
/**
 * Flip an image
 *
 * @param int $direction
 *
 * @return AdapterInterface
 */
ZEPHIR_DOC_METHOD(Phalcon_Image_Adapter_AdapterInterface, flip);
/**
 * Add a mask to an image
 *
 * @param AdapterInterface $mask
 *
 * @return AdapterInterface
 */
ZEPHIR_DOC_METHOD(Phalcon_Image_Adapter_AdapterInterface, mask);
/**
 * Pixelate an image
 *
 * @param int $amount
 *
 * @return AdapterInterface
 */
ZEPHIR_DOC_METHOD(Phalcon_Image_Adapter_AdapterInterface, pixelate);
/**
 * Reflect an image
 *
 * @param int  $height
 * @param int  $opacity
 * @param bool $fadeIn
 *
 * @return AdapterInterface
 */
ZEPHIR_DOC_METHOD(Phalcon_Image_Adapter_AdapterInterface, reflection);
/**
 * Render an image
 *
 * @param string|null $extension
 * @param int         $quality
 *
 * @return string
 */
ZEPHIR_DOC_METHOD(Phalcon_Image_Adapter_AdapterInterface, render);
/**
 * Resize an image
 *
 * @param int|null $width
 * @param int|null $height
 * @param int      $master
 *
 * @return AdapterInterface
 */
ZEPHIR_DOC_METHOD(Phalcon_Image_Adapter_AdapterInterface, resize);
/**
 * Rotate an image
 *
 * @param int $degrees
 *
 * @return AdapterInterface
 */
ZEPHIR_DOC_METHOD(Phalcon_Image_Adapter_AdapterInterface, rotate);
/**
 * Save an image
 *
 * @param string|null $file
 * @param int         $quality
 *
 * @return AdapterInterface
 */
ZEPHIR_DOC_METHOD(Phalcon_Image_Adapter_AdapterInterface, save);
/**
 * Sharpen an image
 *
 * @param int $amount
 *
 * @return AdapterInterface
 */
ZEPHIR_DOC_METHOD(Phalcon_Image_Adapter_AdapterInterface, sharpen);
/**
 * Adds text on an image
 *
 * @param string      $text
 * @param int         $offsetX
 * @param int         $offsetY
 * @param int         $opacity
 * @param string      $color
 * @param int         $size
 * @param string|null $fontFile
 *
 * @return AdapterInterface
 */
ZEPHIR_DOC_METHOD(Phalcon_Image_Adapter_AdapterInterface, text);
/**
 * Add a watermark on an image
 *
 * @param AdapterInterface $watermark
 * @param int              $offsetX
 * @param int              $offsetY
 * @param int              $opacity
 *
 * @return AdapterInterface
 */
ZEPHIR_DOC_METHOD(Phalcon_Image_Adapter_AdapterInterface, watermark);
