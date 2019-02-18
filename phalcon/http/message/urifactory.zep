
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 *
 * Implementation of this file has been influenced by Zend Diactoros
 * @link    https://github.com/zendframework/zend-diactoros
 * @license https://github.com/zendframework/zend-diactoros/blob/master/LICENSE.md
 */

namespace Phalcon\Http\Message;

use Psr\Http\Message\UriFactoryInterface;
use Psr\Http\Message\UriInterface;
use Phalcon\Http\Message\Uri;

class UriFactory implements UriFactoryInterface
{
	/**
	 * Returns a Locator object with all the helpers defined in anonynous
	 * functions
	 */
	public function createUri(string! uri = "") -> <UriInterface>
	{
		return new Uri(uri);
	}
}


