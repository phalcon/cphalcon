
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

namespace Phalcon\Assets\Inline;

/**
 * Phalcon\Assets\Inline\Css
 *
 * Represents inline CSS
 */
class Css extends \Phalcon\Assets\Inline
{

	/**
	 * Phalcon\Assets\Inline\Css
	 *
	 * @param string content
	 * @param boolean filter
	 * @param array attributes
	 */
	public function __construct(string content, boolean filter = true, attributes = null)
	{
		if attributes == null {
			let attributes = ["type": "text/css"];
		}
		parent::__construct("css", content, filter, attributes);
	}
}
