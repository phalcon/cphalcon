
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
 * Phalcon\Mvc\Model\MetaData\Session
 *
 * Stores model meta-data in session. Data will erased when the session finishes.
 * Meta-data are permanent while the session is active.
 *
 * You can query the meta-data by printing $_SESSION['$PMM$']
 *
 *<code>
 * $metaData = new Phalcon\Mvc\Model\Metadata\Session(array(
 *    'prefix' => 'my-app-id'
 * ));
 *</code>
 */
class Session extends Phalcon\Mvc\Model\MetaData implements Phalcon\Mvc\Model\MetaDataInterface
{

	protected _prefix = "";

	/**
	 * Phalcon\Mvc\Model\MetaData\Session constructor
	 *
	 * @param array options
	 */
	public function __construct($options=null)
	{
		if typeof options == "array" {
			if fetch prefix, options["prefix"] {
				let this->_prefix = prefix;
			}
		}
		let this->_metaData = [];
	}

	/**
	 * Reads meta-data from $_SESSION
	 *
	 * @param string key
	 * @return array
	 */
	public function read(string! key)
	{
		let session = _SESSION,
			prefixKey = "$PMM$" . this->_prefix;
		if isset session[prefixKey] {
			if fetch metaData, session[prefixKey][key] {
				return metaData;
			}
		}
		return null;
	}

	/**
	 * Writes the meta-data to $_SESSION
	 *
	 * @param string key
	 * @param array data
	 */
	public function write(string! key, data)
	{
		let _SESSION["$PMM$" . this->_prefix][key] = data;
	}

}
