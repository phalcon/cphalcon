
/*
 +------------------------------------------------------------------------+
 | Phalcon Framework                                                      |
 +------------------------------------------------------------------------+
 | Copyright (c) 2011-2015 Phalcon Team (http://www.phalconphp.com)       |
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
 * phalcon
 *   baseuri: /phalcon/
 * models:
 *   metadata: memory
 *</code>
 *
 * You can read it as follows:
 *
 *<code>
 * $config = new Phalcon\Config\Adapter\Yaml("path/config.yaml");
 * echo $config->phalcon->baseuri;
 * echo $config->models->metadata;
 *</code>
 *
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
