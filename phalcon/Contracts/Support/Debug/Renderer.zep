
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Contracts\Support\Debug;

use Phalcon\Support\Debug\Report\ExceptionReport;

/**
 * Canonical contract for Phalcon\Support\Debug renderers. Turns an
 * ExceptionReport into output.
 */
interface Renderer extends TemplateAware
{
    /**
     * Returns the CSS sources block for the given base URI.
     *
     * @param string $uri
     *
     * @return string
     */
    public function getCssSources(string uri) -> string;

    /**
     * Returns the JavaScript sources block for the given base URI.
     *
     * @param string $uri
     *
     * @return string
     */
    public function getJsSources(string uri) -> string;

    /**
     * Returns the framework version block.
     *
     * @return string
     */
    public function getVersion() -> string;

    /**
     * Renders the report.
     *
     * @param ExceptionReport $report
     *
     * @return string
     */
    public function render(<ExceptionReport> report) -> string;
}
