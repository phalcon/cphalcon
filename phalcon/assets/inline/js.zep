
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

namespace Phalcon\Assets\Inline;

use Phalcon\Assets\Inline as InlineBase;

/**
 * Phalcon\Assets\Inline\Js
 *
 * Represents an inline Javascript
 */
class Js extends InlineBase
{

	/**
	 * Phalcon\Assets\Inline\Js
	 *
	 * @param string content
	 * @param boolean filter
	 * @param array attributes
	 */
	public function __construct(string content, boolean filter = true, var attributes = null)
	{
		if attributes == null {
			let attributes = ["type": "text/javascript"];
		}
		parent::__construct("js", content, filter, attributes);
	}
}
