
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 *
 * Implementation of this file has been influenced by sinbadxiii/cphalcon-uuid
 * @link    https://github.com/sinbadxiii/cphalcon-uuid
 */

namespace Phalcon\Encryption\Security;

use Phalcon\Encryption\Security\Uuid\Version1;
use Phalcon\Encryption\Security\Uuid\Version3;
use Phalcon\Encryption\Security\Uuid\Version4;
use Phalcon\Encryption\Security\Uuid\Version5;
use Phalcon\Encryption\Security\Uuid\Version6;
use Phalcon\Encryption\Security\Uuid\Version7;

/**
 * Factory that generates UUIDs of versions 1 through 7.
 *
 * Each call creates a new immutable version object. Cast to string for the
 * UUID value; use the returned object for additional methods such as
 * getDateTime() or getNode().
 */
class Uuid
{
    /**
     * Generates a version 1 (time-based) UUID.
     */
    public function v1() -> <Version1>
    {
        return new Version1();
    }

    /**
     * Generates a version 3 (name-based MD5) UUID.
     */
    public function v3(string! namespaceName, string! name) -> <Version3>
    {
        return new Version3(namespaceName, name);
    }

    /**
     * Generates a version 4 (random) UUID.
     */
    public function v4() -> <Version4>
    {
        return new Version4();
    }

    /**
     * Generates a version 5 (name-based SHA-1) UUID.
     */
    public function v5(string! namespaceName, string! name) -> <Version5>
    {
        return new Version5(namespaceName, name);
    }

    /**
     * Generates a version 6 (reordered time-based) UUID.
     */
    public function v6() -> <Version6>
    {
        return new Version6();
    }

    /**
     * Generates a version 7 (Unix timestamp) UUID.
     */
    public function v7() -> <Version7>
    {
        return new Version7();
    }
}
