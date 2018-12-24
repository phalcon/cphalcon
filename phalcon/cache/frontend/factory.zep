
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Cache\Frontend;

use Phalcon\Cache\FrontendInterface;
use Phalcon\Factory\Exception;
use Phalcon\Factory as BaseFactory;
use Phalcon\Config;

/**
 * Loads Frontend Cache Adapter class using 'adapter' option
 *
 *<code>
 * use Phalcon\Cache\Frontend\Factory;
 *
 * $options = [
 *     "lifetime" => 172800,
 *     "adapter"  => "data",
 * ];
 * $frontendCache = Factory::load($options);
 *</code>
 */
class Factory extends BaseFactory
{
	/**
	 * @param \Phalcon\Config|array config
	 */
	public static function load(var config) -> object
	{
		return self::loadClass("Phalcon\\Cache\\Frontend", config);
	}

	protected static function loadClass(string $namespace, var config)
	{
		var adapter, className;

		if typeof config == "object" && config instanceof Config {
			let config = config->toArray();
		}

		if typeof config != "array" {
			throw new Exception("Config must be array or Phalcon\\Config object");
		}

		if fetch adapter, config["adapter"] {
			unset config["adapter"];
			let className = $namespace."\\".camelize(adapter);

			if className == "Phalcon\\Cache\\Frontend\\None" {
				return new {className}();
			} else {
				return new {className}(config);
			}
		}

		throw new Exception("You must provide 'adapter' option in factory config parameter.");
	}
}
