
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Html\Helper;

use Phalcon\Html\Helper\AbstractHelper;

/**
 * Phalcon\Html\Helper\FormClose
 *
 * Creates a form closing tag
 */
class FormClose extends AbstractHelper
{
	/**
	 * @var array  attributes Any additional attributes
	 */
	public function __invoke() -> string
	{
		return "</form>";
	}
}
