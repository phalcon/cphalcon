
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 *
 * Implementation of this file has been influenced by AuraPHP
 * @link    https://github.com/auraphp/Aura.Html
 * @license https://github.com/auraphp/Aura.Html/blob/2.x/LICENSE
 */

namespace Phalcon\Html\Helper;

use Phalcon\Html\Escaper\EscaperInterface;
use Phalcon\Html\Link\Link;
use Phalcon\Html\Link\Serializer\Header;
use Phalcon\Http\ResponseInterface;

/**
 * Generates a <link rel="preload"> tag for resource hinting.
 * If a ResponseInterface is provided, also sets the HTTP Link header.
 */
class Preload extends AbstractHelper
{
    /**
     * @var ResponseInterface|null
     */
    protected response = null;

    /**
     * @param EscaperInterface      $escaper
     * @param ResponseInterface|null $response
     */
    public function __construct(
        <EscaperInterface> escaper,
        <ResponseInterface> response = null
    ) {
        parent::__construct(escaper);

        let this->response = response;
    }

    /**
     * @param string $href
     * @param string $type
     * @param array  $attributes
     *
     * @return string
     */
    public function __invoke(
        string href,
        string type = "style",
        array attributes = []
    ) -> string {
        var link, header, overrides;

        let overrides = [
            "rel"  : "preload",
            "href" : href,
            "as"   : type
        ];

        unset attributes["rel"];
        unset attributes["href"];
        unset attributes["as"];

        let overrides = array_merge(overrides, attributes);

        if this->response !== null {
            let link   = new Link("preload", href, ["as": type]),
                header = "Link: " . (new Header())->serialize([link]);

            this->response->setRawHeader(header);
        }

        return this->selfClose("link", overrides);
    }
}
