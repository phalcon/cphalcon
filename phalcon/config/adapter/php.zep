
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

/**
 * Phalcon\Config\Adapter\Php
 *
 * Reads php files and converts them to Phalcon\Config objects.
 *
 * Given the next configuration file:
 *
 *<code>
 *<?php
 *return array(
 * 'database' => array(
 *     'adapter' => 'Mysql',
 *     'host' => 'localhost',
 *     'username' => 'scott',
 *     'password' => 'cheetah',
 *     'dbname' => 'test_db'
 * ),
 *
 * phalcon' => array(
 *    'controllersDir' => '../app/controllers/',
 *    'modelsDir' => '../app/models/',
 *    'viewsDir' => '../app/views/'
 *));
 *</code>
 *
 * You can read it as follows:
 *
 *<code>
 * $config = new Phalcon\Config\Adapter\Php("path/config.php");
 * echo $config->phalcon->controllersDir;
 * echo $config->database->username;
 *</code>
 */
class Php extends Config
{

	/**
	 * Phalcon\Config\Adapter\Php constructor
	 */
	public function __construct(string! filePath)
	{
		parent::__construct(require filePath);
	}
}
