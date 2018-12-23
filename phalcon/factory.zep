
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon;

use Phalcon\Factory\Exception;
use Phalcon\Config;

abstract class Factory implements FactoryInterface
{
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
			let className = $namespace."\\".adapter;

			return new {className}(config);
		}

		throw new Exception("You must provide 'adapter' option in factory config parameter.");
	}
}
