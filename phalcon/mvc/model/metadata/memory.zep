
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
use Phalcon\Mvc\Model\Exception;

/**
 * Phalcon\Mvc\Model\MetaData\Memory
 *
 * Stores model meta-data in memory. Data will be erased when the request finishes
 *
 */
class Memory extends MetaData implements MetaDataInterface
{

	/**
	 * Phalcon\Mvc\Model\MetaData\Memory constructor
	 *
	 * @param array options
	 */
	public function __construct(var options = null)
	{
		let this->_metaData = [];
	}

	/**
	 * Reads the meta-data from temporal memory
	 *
	 * @param string key
	 * @return array
	 */
	public function read(string! key)
	{
		return null;
	}

	/**
	 * Writes the meta-data to temporal memory
	 *
	 * @param string key
	 * @param array data
	 */
	public function write(string! key, var data) -> void
	{
		return;
	}
}
