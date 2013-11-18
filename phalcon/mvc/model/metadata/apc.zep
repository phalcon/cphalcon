
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

namespace Phalcon\Mvc\Model\MetaData;

/**
 * Phalcon\Mvc\Model\MetaData\Apc
 *
 * Stores model meta-data in the APC cache. Data will erased if the web server is restarted
 *
 * By default meta-data is stored for 48 hours (172800 seconds)
 *
 * You can query the meta-data by printing apc_fetch('$PMM$') or apc_fetch('$PMM$my-app-id')
 *
 *<code>
 *	$metaData = new Phalcon\Mvc\Model\Metadata\Apc(array(
 *		'prefix' => 'my-app-id',
 *		'lifetime' => 86400
 *	));
 *</code>
 */
class Apc extends Phalcon\Mvc\Model\MetaData implements Phalcon\Mvc\Model\MetaDataInterface
{

	protected _prefix = "";

	protected _ttl = 172800;

	/**
	 * Phalcon\Mvc\Model\MetaData\Apc constructor
	 *
	 * @param array options
	 */
	public function __construct(options=null)
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

		let this->_metaData = [];
	}

	/**
	 * Reads meta-data from APC
	 *
	 * @param  string key
	 * @return array
	 */
	public function read(string! key)
	{
		var data;

		let data = apc_fetch("$PMM$" . this->_prefix . key);
		if typeof data == "array" {
			return data;
		}
		return null;
	}

	/**
	 * Writes the meta-data to APC
	 *
	 * @param string key
	 * @param array data
	 */
	public function write(string! key, data)
	{
		apc_store("$PMM$" . this->_prefix . key, data, this->_ttl);
	}

}