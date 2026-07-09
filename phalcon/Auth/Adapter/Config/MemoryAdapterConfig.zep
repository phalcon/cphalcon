
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

namespace Phalcon\Auth\Adapter\Config;

use Phalcon\Auth\Adapter\Config\Traits\ModelConfigTrait;
use Phalcon\Contracts\Auth\Adapter\AdapterConfig;

/**
 * @phpstan-type AuthUserRow array{id?: int|string}&array<string, mixed>
 */
class MemoryAdapterConfig implements AdapterConfig
{
    use ModelConfigTrait;

    /**
     * @var array
     */
    protected users = [];

    /**
     * @phpstan-param list<AuthUserRow> $users
     */
    public function __construct(array users = [], string model = null)
    {
        let this->users = users,
            this->model = model;
    }

    /**
     * @phpstan-return list<AuthUserRow>
     */
    public function getUsers() -> array
    {
        return this->users;
    }
}
