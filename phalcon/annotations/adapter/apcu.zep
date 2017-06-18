
/*
 +------------------------------------------------------------------------+
 | Phalcon Framework                                                      |
 +------------------------------------------------------------------------+
 | Copyright (c) 2011-2017 Phalcon Team (https://phalconphp.com)          |
 +------------------------------------------------------------------------+
 | This source file is subject to the New BSD License that is bundled     |
 | with this package in the file LICENSE.txt.                             |
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
use Phalcon\Annotations\Reflection;

/**
 * Phalcon\Annotations\Adapter\Apcu
 *
 * Stores the parsed annotations in APCu. This adapter is suitable for production
 *
 *<code>
 * use Phalcon\Annotations\Adapter\Apcu;
 *
 * $annotations = new Apcu();
 *</code>
 */
class Apcu extends Adapter
{

	protected _prefix = "";

	protected _ttl = 172800;

	/**
	 * Phalcon\Annotations\Adapter\Apcu constructor
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
	 * Reads parsed annotations from APCu
	 */
	public function read(string! key) -> <Reflection> | boolean
	{
		return apcu_fetch(strtolower("_PHAN" . this->_prefix . key));
	}

	/**
	 * Writes parsed annotations to APCu
	 */
	public function write(string! key, <Reflection> data)
	{
		return apcu_store(strtolower("_PHAN" . this->_prefix . key), data, this->_ttl);
	}
}
