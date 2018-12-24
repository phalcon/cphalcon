
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
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
	public static function load(var config) -> object
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
