
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

namespace Phalcon\Auth\Guard\Config;

use Phalcon\Auth\Exception;
use Phalcon\Auth\Exceptions\ConfigRequiresNonEmptyValue;

class TokenGuardConfig extends AbstractGuardConfig
{
    /**
     * @var string
     */
    protected inputKey;
    /**
     * @var string
     */
    protected storageKey;
    /**
     * @throws Exception
     */
    public function __construct(string inputKey, string storageKey)
    {
        if (inputKey === "") {
            throw new ConfigRequiresNonEmptyValue(
                "Token guard",
                "inputKey"
            );
        }

        if (storageKey === "") {
            throw new ConfigRequiresNonEmptyValue(
                "Token guard",
                "storageKey"
            );
        }
    }

    public function getInputKey() -> string
    {
        return this->inputKey;
    }

    public function getStorageKey() -> string
    {
        return this->storageKey;
    }
}
