
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Mvc\Url;

/**
 * Interface for Phalcon\Mvc\Url\UrlInterface
 */
interface UrlInterface
{
    /**
     * Generates a URL
     *
     * @param string|array uri
     * @param array|object args Optional arguments to be appended to the query string
     */
    public function get(uri = null, args = null, bool local = null) -> string;

    /**
     * Returns a base path
     */
    public function getBasePath() -> string;

    /**
     * Returns the prefix for all the generated urls. By default /
     */
    public function getBaseUri() -> string;

    /**
     * Sets a base paths for all the generated paths
     */
    public function setBasePath(string! basePath) -> <UrlInterface>;

    /**
     * Sets a prefix to all the urls generated
     */
    public function setBaseUri(string! baseUri) -> <UrlInterface>;

    /**
     * Generates a local path
     */
    public function path(string path = null) -> string;
}
