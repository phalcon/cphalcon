
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

use Phalcon\Contracts\Auth\AuthTypes;

/**
 * @phpstan-import-type auth_user_row from AuthTypes
 */
class MemoryAdapterConfig extends AbstractAdapterConfig
{
    protected array users = [];

    /**
     * @phpstan-param list<auth_user_row> $users
     */
    public function __construct(array users = [], string model = null)
    {
        let this->users = users;

        parent::__construct(model);
    }

    /**
     * @phpstan-return list<auth_user_row>
     */
    public function getUsers() -> array
    {
        return this->users;
    }
}
