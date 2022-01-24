
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 *
 * Implementation of this file has been influenced by Zend Diactoros
 * @link    https://github.com/zendframework/zend-diactoros
 * @license https://github.com/zendframework/zend-diactoros/blob/master/LICENSE.md
 */

namespace Phalcon\Http\Message;

use PsrExt\Http\Message\ResponseInterface;
use PsrExt\Http\Message\ResponseFactoryInterface;

/**
 * PSR-17 ResponseFactory
 */
final class ResponseFactory implements ResponseFactoryInterface
{
    /**
     * Create a new response.
     *
     * @param int    $code         The HTTP status code. Defaults to 200.
     * @param string $reasonPhrase The reason phrase to associate with the status
     *                             code in the generated response. If none is
     *                             provided, implementations MAY use the defaults
     *                             as suggested in the HTTP specification.
     *
     * @return ResponseInterface
     */
    public function createResponse(int code = 200, string reasonPhrase = "") -> <ResponseInterface>
    {
        return (new Response())->withStatus(code, reasonPhrase);
    }
}
