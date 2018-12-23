
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Config\Adapter;

use Phalcon\Config;
use Phalcon\Config\Exception;

/**
 * Phalcon\Config\Adapter\Yaml
 *
 * Reads YAML files and converts them to Phalcon\Config objects.
 *
 * Given the following configuration file:
 *
 *<code>
 * phalcon:
 *   baseuri:        /phalcon/
 *   controllersDir: !approot  /app/controllers/
 * models:
 *   metadata: memory
 *</code>
 *
 * You can read it as follows:
 *
 *<code>
 * define(
 *     "APPROOT",
 *     dirname(__DIR__)
 * );
 *
 * $config = new \Phalcon\Config\Adapter\Yaml(
 *     "path/config.yaml",
 *     [
 *         "!approot" => function($value) {
 *             return APPROOT . $value;
 *         },
 *     ]
 * );
 *
 * echo $config->phalcon->controllersDir;
 * echo $config->phalcon->baseuri;
 * echo $config->models->metadata;
 *</code>
 */
class Yaml extends Config
{

	/**
	 * Phalcon\Config\Adapter\Yaml constructor
	 *
	 * @throws \Phalcon\Config\Exception
	 */
	public function __construct(string! filePath, array! callbacks = null)
	{
		var yamlConfig;
		int ndocs = 0;

		if !extension_loaded("yaml") {
			throw new Exception("Yaml extension not loaded");
		}

		if callbacks !== null {
			let yamlConfig = yaml_parse_file(filePath, 0, ndocs, callbacks);
		} else {
			let yamlConfig = yaml_parse_file(filePath);
		}

		if yamlConfig === false {
			throw new Exception("Configuration file " . basename(filePath) . " can't be loaded");
		}

		parent::__construct(yamlConfig);
	}
}
