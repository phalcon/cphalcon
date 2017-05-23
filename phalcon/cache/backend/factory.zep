
/*
 +------------------------------------------------------------------------+
 | Phalcon Framework                                                      |
 +------------------------------------------------------------------------+
 | Copyright (c) 2011-2017 Phalcon Team (https://phalconphp.com)          |
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

namespace Phalcon\Cache\Backend;

use Phalcon\Factory as BaseFactory;
use Phalcon\Factory\Exception;
use Phalcon\Cache\BackendInterface;
use Phalcon\Cache\Frontend\Factory as FrontendFactory;
use Phalcon\Config;

/**
 * Loads Backend Cache Adapter class using 'adapter' option, if frontend will be provided as array it will call Frontend Cache Factory
 *
 *<code>
 * use Phalcon\Cache\Backend\Factory;
 * use Phalcon\Cache\Frontend\Data;
 *
 * $options = [
 *     "prefix"   => "app-data",
 *     "frontend" => new Data(),
 *     "adapter"  => "apc",
 * ];
 * $backendCache = Factory::load($options);
 *</code>
 */
class Factory extends BaseFactory
{
	/**
	 * @param \Phalcon\Config|array config
	 */
	public static function load(var config) -> <BackendInterface>
	{
		return self::loadClass("Phalcon\\Cache\\Backend", config);
	}

	/**
	 * @param \Phalcon\Config|array config
	 */
	public static function loadForDi(var config) -> array
	{
		return self::loadAsArray("Phalcon\\Cache\\Backend", config);
	}

	protected static function loadClass(string $namespace, var config)
	{
		var frontend, className, params;

		let params = self::checkArguments($namespace, config);

		let frontend = FrontendFactory::load(params["frontend"]);
		let className = params["className"];

		return new {className}(frontend, params["config"]);
	}

	protected static function loadAsArray(string $namespace, var config)
	{
		var params;

		let params = self::checkArguments($namespace, config);

		unset params["frontend"]["adapter"];

		return [
			"className" : params["className"],
			"arguments" : [
				[
					"type" : "instance",
					"className" : "Phalcon\\Cache\\Frontend\\".params["frontendAdapter"],
					"arguments" : [
						params["frontend"]
					]
				],
				[
					"type" : "parameter",
					"value" : params["config"]
				]
			]
		];
	}

	protected static function checkArguments(string $namespace, var config)
	{
		var adapter, frontend, frontendAdapter, params;

		let params = [];

		if typeof config == "object" && config instanceof Config {
			let config = config->toArray();
		}

		if typeof config != "array" {
			throw new Exception("Config must be array or Phalcon\\Config object");
		}

		if !fetch frontend, config["frontend"] {
			throw new Exception("You must provide 'frontend' option in factory config parameter.");
		}

		if fetch adapter, config["adapter"] {
			unset config["adapter"];
			unset config["frontend"];

			if !fetch frontendAdapter, frontend["adapter"] {
				throw new Exception("You must provide 'adapter' option for frontend");
			}

			let params["frontendAdapter"] = frontendAdapter;
			let params["frontend"] = frontend;
			let params["className"] = $namespace."\\".camelize(adapter);
			let params["config"] = config;

			return params;
		} else {
			throw new Exception("You must provide 'adapter' option in factory config parameter.");
		}
	}
}
