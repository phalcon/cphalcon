
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Assets\Asset;

use Phalcon\Assets\Asset as AssetBase;

/**
 * Phalcon\Assets\Asset\Js
 *
 * Represents Javascript assets
 */
class Js extends AssetBase
{
	/**
	 * Phalcon\Assets\Asset\Js
	 */
	public function __construct(string! path, bool local = true, bool filter = true, array attributes = [])
	{
		parent::__construct("js", path, local, filter, attributes);
	}
}
