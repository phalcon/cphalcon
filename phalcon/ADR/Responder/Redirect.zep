
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 *
 * Based on the Action Domain Responder pattern
 * @link    https://pmjones.io/adr/
 */

namespace Phalcon\ADR\Responder;

/**
 * Value object describing a redirect. An Action sets it on the payload; the
 * RedirectResponder turns it into a `Location` header and status code.
 */
class Redirect
{
    /**
     * @var int
     */
    protected status;

    /**
     * @var string
     */
    protected url;

    public function __construct(string url, int status = 302)
    {
        let this->url    = url,
            this->status = status;
    }

    public static function permanent(string url) -> <Redirect>
    {
        return new self(url, 301);
    }

    public static function seeOther(string url) -> <Redirect>
    {
        return new self(url, 303);
    }

    public function status() -> int
    {
        return this->status;
    }

    public static function temporary(string url) -> <Redirect>
    {
        return new self(url, 302);
    }

    public function url() -> string
    {
        return this->url;
    }
}
