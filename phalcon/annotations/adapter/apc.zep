
/*
 +------------------------------------------------------------------------+
 | Phalcon Framework                                                      |
 +------------------------------------------------------------------------+
 | Copyright (c) 2011-2013 Phalcon Team (http://www.phalconphp.com)       |
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

namespace Phalcon\Annotations\Adapter;

/**
 * Phalcon\Annotations\Adapter\Apc
 *
 * Stores the parsed annotations in APC. This adapter is suitable for production
 *
 *<code>
 * $annotations = new \Phalcon\Annotations\Adapter\Apc();
 *</code>
 */
class Apc
{

	/**
	 * Reads parsed annotations from APC
	 *
	 * @param string key
	 * @return Phalcon\Annotations\Reflection
	 */
	public function read(string! key) -> <Phalcon\Annotations\Reflection> | boolean
	{
		return apc_fetch(strtolower("_PHAN" . key));
	}

	/**
	 * Writes parsed annotations to APC
	 *
 	 * @param string key
	 * @param Phalcon\Annotations\Reflection data
	 */
	public function write(string! key, <Phalcon\Annotations\Reflection> data)
	{
		return apc_store(strtolower("_PHAN" . key), data);
	}

}
