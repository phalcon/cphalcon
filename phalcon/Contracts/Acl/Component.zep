
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Contracts\Acl;

/**
 * Canonical contract for an ACL component entity.
 */
interface Component
{
    /**
     * Magic method __toString
     */
    public function __toString() -> string;

    /**
     * Returns component description
     */
    public function getDescription() -> string | null;

    /**
     * Returns the component name
     */
    public function getName() -> string;
}
