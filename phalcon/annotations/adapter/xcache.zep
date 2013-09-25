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
|          Vladimir Kolesnikov <vladimir@extrememember.com>              |
+------------------------------------------------------------------------+
*/

namespace Phalcon\Annotations\Adapter;

/**
 * Phalcon\Annotations\Adapter\Xcache
 *
 * Stores the parsed annotations to XCache. This adapter is suitable for production
 *
 *<code>
 * $annotations = new \Phalcon\Annotations\Adapter\Xcache();
 *</code>
 */
class Xcache
{
	/**
	 * Reads parsed annotations from XCache
	 *
	 * @param string key
	 * @return Phalcon\Annotations\Reflection
	 */
	public function read(string key) -> <Phalcon\Annotations\Reflection>
	{
		var serialized, data;
		let serialized = xcache_get(strtolower("_PHAN" . key));
		if typeof serialized == "string" {
			let data = unserialize(serialized);
			if typeof data == "object" {
				return data;
			}
		}
	}

	/**
	* Writes parsed annotations to XCache
	*
	* @param string key
	* @param Phalcon\Annotations\Reflection $data
	*/
	public function write(string key, <Phalcon\Annotations\Reflection> data)
	{
		xcache_set(strtolower("_PHAN" . key), serialize(data));
	}

}
