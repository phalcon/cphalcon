
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
 * Central registry of the array shapes used across the Image namespace.
 *
 * This is a type registry, not a contract. It declares no members and must
 * not be implemented; it exists only so that every shape below has a single
 * definition, imported where it is needed with a phpstan-import-type tag
 * naming this interface as the source.
 *
 * Alias names are prefixed with `image_` because PHPStan resolves imported
 * type names per file and has no namespacing for them: the prefix is what
 * keeps generic names such as `config` from clashing with an alias imported
 * from another namespace into the same file.
 *
 * @phpstan-type image_channel int<0, 255>
 * @phpstan-type image_color_channels array{image_channel, image_channel, image_channel}
 * @phpstan-type image_crop_rectangle array{
 *     x: int,
 *     y: int,
 *     width: int,
 *     height: int,
 * }
 * @phpstan-type image_factory_config array{
 *     adapter: string,
 *     file: string,
 *     height?: int|null,
 *     width?: int|null,
 * }
 * @phpstan-type image_factory_services array<string, class-string<AdapterInterface>>
 * @phpstan-type image_text_bounds array<int, int>
 */
ZEPHIR_INIT_CLASS(Phalcon_Contracts_Image_ImageTypes)
{
	ZEPHIR_REGISTER_INTERFACE(Phalcon\\Contracts\\Image, ImageTypes, phalcon, contracts_image_imagetypes, NULL);

	return SUCCESS;
}

