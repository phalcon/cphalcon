
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 *
 * Based on the Action Domain Responder pattern
 * @link    https://pmjones.io/adr/
 */

namespace Phalcon\ADR\Responder;

use Phalcon\Contracts\ADR\Payload\Payload;
use Phalcon\Contracts\ADR\Responder\Responder;
use Phalcon\Http\RequestInterface;
use Phalcon\Http\ResponseInterface;

/**
 * Composes single-purpose responders. Each link receives the request, the
 * response threaded so far, and the payload, and returns the response.
 */
class ChainResponder implements Responder
{
    /**
     * @var Responder[]
     */
    protected links;

    public function __construct(array links = [])
    {
        let this->links = links;
    }

    public function __invoke(
        <RequestInterface> request, 
        <ResponseInterface> response, 
        <Payload> payload
    ) -> <ResponseInterface> {
        var link;

        for link in this->links {
            let response = link->__invoke(request, response, payload);
        }

        return response;
    }

    public function with(<Responder> link) -> <ChainResponder>
    {
        var links;

        let links   = this->links,
            links[] = link;

        return new ChainResponder(links);
    }
}
