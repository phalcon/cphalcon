
/*
 +------------------------------------------------------------------------+
 | Phalcon Framework                                                      |
 +------------------------------------------------------------------------+
 | Copyright (c) 2011-2017 Phalcon Team (https://phalconphp.com)          |
 +------------------------------------------------------------------------+
 | This source file is subject to the New BSD License that is bundled     |
 | with this package in the file LICENSE.txt.                             |
 |                                                                        |
 | If you did not receive a copy of the license and are unable to         |
 | obtain it through the world-wide-web, please send an email             |
 | to license@phalconphp.com so we can send you a copy immediately.       |
 +------------------------------------------------------------------------+
 | Authors: Andres Gutierrez <andres@phalconphp.com>                      |
 |          Eduar Carvajal <eduar@phalconphp.com>                         |
 |          Wojciech Ślawski <jurigag@gmail.com>                          |
 +------------------------------------------------------------------------+
 */

namespace Phalcon\Image;

use Phalcon\Factory as BaseFactory;
use Phalcon\Factory\Exception;
use Phalcon\Config;

/**
 * Loads Image Adapter class using 'adapter' option
 *
 *<code>
 * use Phalcon\Image\Factory;
 *
 * $options = [
 *     "width"   => 200,
 *     "height"  => 200,
 *     "file"    => "upload/test.jpg",
 *     "adapter" => "imagick",
 * ];
 * $image = Factory::load($options);
 *</code>
 */
class Factory extends BaseFactory
{
	/**
	 * @param \Phalcon\Config|array config
	 */
	public static function load(var config) -> <AdapterInterface>
	{
		return self::loadClass("Phalcon\\Image\\Adapter", config);
	}

	protected static function loadClass(string $namespace, var config)
	{
		var adapter, className, file, height, width;

		if typeof config == "object" && config instanceof Config {
			let config = config->toArray();
		}

		if typeof config != "array" {
			throw new Exception("Config must be array or Phalcon\\Config object");
		}

		if !fetch file, config["file"] {
			throw new Exception("You must provide 'file' option in factory config parameter.");
		}

		if fetch adapter, config["adapter"] {
			let className = $namespace."\\".camelize(adapter);

			if fetch width, config["width"] {
				if fetch height, config["height"] {
					return new {className}(file, width, height);
				}

				return new {className}(file, width);
			}

			return new {className}(file);
		}

		throw new Exception("You must provide 'adapter' option in factory config parameter.");
	}
}
