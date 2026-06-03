
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

namespace Phalcon\Auth;

use Phalcon\Auth\Exceptions\DataMustContainIdKey;
use Phalcon\Contracts\Auth\AuthUser as AuthUserContract;

/**
 * Lightweight value object returned by array-backed adapters (Memory, Stream)
 * when no application model class is configured.
 */
class AuthUser implements AuthUserContract
{
    /**
     * @phpstan-var array<string, mixed>
     * @var array
     */
    protected data;

    /**
     * @param array<string, mixed> $data
     *
     * @throws Exception when $data does not contain a scalar 'id' key.
     */
    public function __construct(array data)
    {
        if (!isset(data["id"]) || (typeof data["id"] !== "int" && typeof data["id"] !== "string")) {
            throw new DataMustContainIdKey();
        }

        let this->data = data;
    }

    public function getAuthIdentifier() -> int | string
    {
        var id;

        /** @var int|string $id (validated in constructor) */
        let id = this->data["id"];

        return id;
    }

    public function getAuthPassword() -> string
    {
        var password;

        fetch password, this->data["password"];

        return typeof password === "string" ? password : "";
    }

    /**
     * Returns the underlying data array.
     *
     * @return array<string, mixed>
     */
    public function toArray() -> array
    {
        return this->data;
    }
}
