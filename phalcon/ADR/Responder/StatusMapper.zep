
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

use Phalcon\ADR\Payload\Status;

/**
 * Maps a domain `Status` to an HTTP status code.
 *
 * `Status` is the single source of truth: the default map covers every
 * `Status` constant. Any status that is not mapped resolves to 500, never a
 * silent 200. Every entry can be overridden through the constructor.
 */
final class StatusMapper
{
    /**
     * @var array
     */
    protected map;

    public function __construct(array overrides = [])
    {
        let this->map = overrides + [
            Status::ACCEPTED           : 202,
            Status::AUTHENTICATED      : 200,
            Status::AUTHORIZED         : 200,
            Status::CREATED            : 201,
            Status::DELETED            : 200,
            Status::ERROR              : 500,
            Status::FAILURE            : 400,
            Status::FOUND              : 200,
            Status::METHOD_NOT_ALLOWED : 405,
            Status::NOT_ACCEPTED       : 406,
            Status::NOT_AUTHENTICATED  : 401,
            Status::NOT_AUTHORIZED     : 403,
            Status::NOT_CREATED        : 422,
            Status::NOT_DELETED        : 422,
            Status::NOT_FOUND          : 404,
            Status::NOT_UPDATED        : 422,
            Status::NOT_VALID          : 422,
            Status::PROCESSING         : 102,
            Status::SUCCESS            : 200,
            Status::UPDATED            : 200,
            Status::VALID              : 200
        ];
    }

    /**
     * Returns the HTTP status code for the given domain status.
     *
     * An unmapped status resolves to 500 (server error), never a silent 200.
     */
    public function toHttpCode(string status) -> int
    {
        return isset this->map[status] ? this->map[status] : 500;
    }
}
