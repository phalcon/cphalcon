
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Annotations\Router;

/**
 * Sets the prefix of every route of a controller. It is the attribute form of
 * `@RoutePrefix`.
 */
#[\Attribute(\Attribute::TARGET_CLASS)]
class RoutePrefix
{
    /**
     * @var string
     */
    public prefix;

    public function __construct(string prefix)
    {
        let this->prefix = prefix;
    }
}
