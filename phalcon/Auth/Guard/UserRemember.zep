
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 *
 * Implementation of this file has been influenced by sinbadxiii/cphalcon-auth
 * @link    https://github.com/sinbadxiii/cphalcon-auth
 */

namespace Phalcon\Auth\Guard;

use InvalidArgumentException;
use Phalcon\Support\Helper\Json\Decode;

/**
 * Value object representing the contents of a remember-me cookie.
 *
 * @phpstan-type RememberPayload array{id?: int|string, token?: string, user_agent?: string}
 */
final class UserRemember
{
    /**
     * @var int|string|null
     */
    protected id;
    /**
     * @var string
     */
    protected token;
    /**
     * @var string
     */
    protected userAgent;

    /**
     * Accepts either the raw JSON cookie value (string) or the already
     * decoded associative array. Malformed input degrades to an empty
     * payload so callers can read getters without null-guarding.
     *
     * @param string|array<string, mixed> $payload
     */
    public function __construct(var payload)
    {
        if (typeof payload !== "array" && typeof payload !== "string") {
            throw new \TypeError("The parameter must be 'int' or 'string'");
        }

        var data, rawId;

        try {
            let data = typeof payload === "string" ? (new Decode())->__invoke(payload, true) : payload;
        } catch InvalidArgumentException {
            let data = [];
        }

        if (typeof data !== "array") {
            let data = [];
        }

        /** @var RememberPayload $data */
        let rawId = isset(data["id"]) ? data["id"] : null;

        let this->id        = (typeof rawId === "int" || typeof rawId === "string") ? rawId : null;
        let this->token     = isset(data["token"]) ? (string) data["token"] : "";
        let this->userAgent = isset(data["user_agent"]) ? (string) data["user_agent"] : "";
    }

    public function getId() -> int | string | null
    {
        return this->id;
    }

    public function getToken() -> string
    {
        return this->token;
    }

    public function getUserAgent() -> string
    {
        return this->userAgent;
    }
}
