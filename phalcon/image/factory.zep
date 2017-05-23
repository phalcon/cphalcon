
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

	public static function loadForDi(var config) -> array
	{
		return self::loadAsArray("Phalcon\\Image\\Adapter", config);
	}

	protected static function loadClass(string $namespace, var config)
	{
		var width, height, className, params;

		let params = self::checkArguments($namespace, config);

		let width = 0;
		let className = params["className"];

		if fetch height, params["height"] {
			fetch width, params["width"];
			return new {className}(params["file"], width, height);
		} elseif fetch width, params["width"] {
			return new {className}(params["file"], width);
		}

		return new {className}(params["file"]);
	}

	protected static function loadAsArray(string $namespace, var config)
	{
		var height, width, params;

		let params = self::checkArguments($namespace, config);

		let width = 0;

		if fetch height, params["height"] {
			fetch width, params["width"];
			return [
				"className" : params["className"],
				"arguments" : [
					[
						"type" : "parameter",
						"value" : params["file"]
					],
					[
						"type" : "parameter",
						"value" : width
					],
					[
						"type" : "parameter",
						"value" : height
					]
				]
			];
		} elseif fetch width, params["width"] {
			return [
				"className" : params["className"],
				"arguments" : [
					[
						"type" : "parameter",
						"value" : params["file"]
					],
					[
						"type" : "parameter",
						"value" : width
					]
				]
			];
		}

		return [
			"className" : params["className"],
			"arguments" : [
				[
					"type" : "parameter",
					"value" : params["file"]
				]
			]
		];
	}

	protected static function checkArguments(string $namespace, var config)
	{
		var adapter, file, height, width, params;

		let params = [];

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
			let params["file"] = file;
			let params["className"] = $namespace."\\".camelize(adapter);

			if fetch width, config["width"] {
				let params["width"] = width;
				if fetch height, config["height"] {
					let params["height"] = height;
				}
			}

			return params;
		} else {
			throw new Exception("You must provide 'adapter' option in factory config parameter.");
		}
	}
}
