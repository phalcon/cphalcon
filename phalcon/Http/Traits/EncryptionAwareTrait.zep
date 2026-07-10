
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Http\Traits;

/**
 * Provides the implicit encryption flag and its accessor shared by the HTTP
 * cookie classes.
 */
trait EncryptionAwareTrait
{
    /**
     * @var bool
     */
    protected useEncryption = false;

    /**
     * Check if implicit encryption is being used
     */
    public function isUsingEncryption() -> bool
    {
        return this->useEncryption;
    }
}
