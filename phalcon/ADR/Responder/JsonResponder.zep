
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

use Phalcon\ADR\Responder\Formatter\JsonFormatter;

/**
 * A formatted responder bound to the JSON formatter.
 */
class JsonResponder extends AbstractFormattedResponder
{
    public function __construct()
    {
        parent::__construct(
            [
                new JsonFormatter()
            ]
        );
    }
}
