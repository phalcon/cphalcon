
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

namespace Phalcon\Assets\Resource;

use Phalcon\Assets\Resource as ResourceBase;

/**
 * Phalcon\Assets\Resource\Css
 *
 * Represents CSS resources
 */
class Css extends ResourceBase
{

	/**
	 * Phalcon\Assets\Resource\Css
	 *
	 * @param string path
	 * @param boolean local
	 * @param boolean filter
	 * @param array attributes
	 */
	public function __construct(string! path, boolean local = true, boolean filter = true, attributes = null)
	{
		parent::__construct("css", path, local, filter, attributes);
	}
}
