
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

namespace Phalcon\Annotations\Adapter;

use Phalcon\Annotations\Adapter;
use Phalcon\Annotations\AdapterInterface;
use Phalcon\Annotations\Reflection;

/**
 * Phalcon\Annotations\Adapter\Apc
 *
 * Stores the parsed annotations in APC. This adapter is suitable for production
 *
 *<code>
 * $annotations = new \Phalcon\Annotations\Adapter\Apc();
 *</code>
 */
class Apc extends Adapter implements AdapterInterface
{

	protected _prefix = "";

	protected _ttl = 172800;

	/**
	 * Phalcon\Annotations\Adapter\Apc constructor
	 *
	 * @param array options
	 */
	public function __construct(options = null)
	{
		var prefix, ttl;

		if typeof options == "array" {
			if fetch prefix, options["prefix"] {
				let this->_prefix = prefix;
			}
			if fetch ttl, options["lifetime"] {
				let this->_ttl = ttl;
			}
		}
	}

	/**
	 * Reads parsed annotations from APC
	 *
	 * @param string key
	 * @return Phalcon\Annotations\Reflection
	 */
	public function read(string! key) -> <Reflection> | boolean
	{
		return apc_fetch(strtolower("_PHAN" . this->_prefix . key));
	}

	/**
	 * Writes parsed annotations to APC
	 */
	public function write(string! key, <Reflection> data)
	{
		return apc_store(strtolower("_PHAN" . this->_prefix . key), data, this->_ttl);
	}
}
