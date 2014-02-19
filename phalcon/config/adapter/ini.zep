
/*
 +------------------------------------------------------------------------+
 | Phalcon Framework                                                      |
 +------------------------------------------------------------------------+
 | Copyright (c) 2011-2014 Phalcon Team (http://www.phalconphp.com)       |
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

class Ini extends \Phalcon\Config
{

	/**
	 * Phalcon\Config\Adapter\Ini constructor
	 *
	 * @param string filePath
	 */
	public function __construct(string! filePath)
	{
		var config, iniConfig, section, directives, directiveParts, key, value;

		let config = [];

		let iniConfig = parse_ini_file($filePath, true);
		if iniConfig === false {
			throw new \Phalcon\Config\Exception("Configuration file " . basename(filePath) . " can't be loaded");
		}

		for section, directives in iniConfig {
			for key, value in directives {
				if memstr(key, ".") {
					let directiveParts = explode(".", key);
					let config[section][directiveParts[0]][directiveParts[1]] = value;
				} else {
					let config[section][$key] = value;
				}
			}
		}

		parent::__construct(config);
	}

}