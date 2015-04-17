
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

namespace Phalcon\Mvc\Model\MetaData;

use Phalcon\Mvc\Model\MetaData;
use Phalcon\Mvc\Model\MetaDataInterface;

/**
 * Phalcon\Mvc\Model\MetaData\Xcache
 *
 * Stores model meta-data in the XCache cache. Data will erased if the web server is restarted
 *
 * By default meta-data is stored for 48 hours (172800 seconds)
 *
 * You can query the meta-data by printing xcache_get('$PMM$') or xcache_get('$PMM$my-app-id')
 *
 *<code>
 *	$metaData = new Phalcon\Mvc\Model\Metadata\Xcache(array(
 *		'prefix' => 'my-app-id',
 *		'lifetime' => 86400
 *	));
 *</code>
 */
class Xcache extends MetaData implements MetaDataInterface
{

	protected _prefix = "";

	protected _ttl = 172800;

	/**
	 * Phalcon\Mvc\Model\MetaData\Xcache constructor
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
		let this->_metaData = [];
	}

	/**
	 * Reads metadata from XCache
	 *
	 * @param  string key
	 * @return array
	 */
	public function read(string! key)
	{
		var data;
		let data = xcache_get("$PMM$" . this->_prefix . key);
		if typeof data == "array" {
			return data;
		}
		return null;
	}

	/**
	 *  Writes the metadata to XCache
	 *
	 * @param string key
	 * @param array data
	 */
	public function write(string! key, data)
	{
		xcache_set("$PMM$" . this->_prefix . key, data, this->_ttl);
	}
}