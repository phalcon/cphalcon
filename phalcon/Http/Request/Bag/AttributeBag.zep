
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Http\Request\Bag;

/**
 * Holds the request attributes: arbitrary, application-defined values
 * attached to the request during its lifecycle (router, dispatcher,
 * security components etc.). Unlike the other request bags, it is not
 * hydrated from a superglobal — it always starts empty.
 *
 * The base class supplies the entire surface; this class exists as a
 * distinct type so DI typing and IDE autocomplete stay precise.
 */
class AttributeBag extends AbstractBag
{
}
