
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

namespace Phalcon\ADR\Responder\Formatter;

use Phalcon\Contracts\ADR\Payload\Payload;
use Phalcon\Contracts\ADR\Responder\Formatter\Formatter;

/**
 * Renders a payload as JSON.
 */
class JsonFormatter implements Formatter
{
    public function accepts(string acceptHeader) -> bool
    {
        return strpos(acceptHeader, "application/json") !== false
            || strpos(acceptHeader, "+json") !== false;
    }

    public function contentType() -> string
    {
        return "application/json";
    }

    public function format(<Payload> payload) -> string
    {
        var content;

        let content = payload->getResult();
        if null === content {
            let content = payload->getMessages();
        }

        return (string) json_encode(content);
    }
}
