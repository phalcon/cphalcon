
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Acl;

use Phalcon\Acl\Traits\ItemTrait;

/**
 * Shared base for ACL Role and Component entities: a name and an optional
 * description.
 *
 * @todo Remove in v7. Kept only for backwards compatibility; the logic now
 *       lives in `Phalcon\Acl\Traits\ItemTrait` - compose that trait directly
 *       instead of extending this class.
 */
abstract class AbstractElement
{
    use ItemTrait;
}
