
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Http\Message;

use Phalcon\Http\Message\Request;
use Psr\Http\Message\RequestInterface;
use Psr\Http\Message\RequestFactoryInterface;

/**
 * PSR-17 RequestFactory
 */
final class RequestFactory implements RequestFactoryInterface
{
    /**
     * Create a new request.
     */
    public function createRequest(string method, var uri) -> <RequestInterface>
    {
        return new Request(method, uri);
    }
}
