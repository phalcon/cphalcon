
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
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
	 * @param array attributes
	 */
	public function __construct(string content, bool filter = true, var attributes = null)
	{
		if attributes == null {
			let attributes = ["type": "text/javascript"];
		}

		parent::__construct("js", content, filter, attributes);
	}
}
