
/*
 +------------------------------------------------------------------------+
 | Phalcon Framework                                                      |
 +------------------------------------------------------------------------+
 | Copyright (c) 2011-2015 Phalcon Team (http://www.phalconphp.com)       |
 +------------------------------------------------------------------------+
 | This source file is subject to the New BSD License that is bundled     |
 | with this package in the file docs/LICENSE.txt.                        |
 |                                                                        |
 | If you did not receive a copy of the license and are unable to         |
 | obtain it through the world-wide-web, please send an email             |
 | to license@phalconphp.com so we can send you a copy immediately.       |
 +------------------------------------------------------------------------+
 | Authors: Andres Gutierrez <andres@phalconphp.com>                      |
 |          Eduar Carvajal <eduar@phalconphp.com>                         |
 +------------------------------------------------------------------------+
 */

namespace Phalcon\Forms\Element;

use Phalcon\Forms\Element;
use Phalcon\Forms\ElementInterface;

/**
 * Phalcon\Forms\Element\Password
 *
 * Component INPUT[type=password] for forms
 */
class Password extends Element implements ElementInterface
{

	/**
	 * Renders the element widget returning html
	 *
	 * @param array $attributes
	 * @return string
	 */
	public function render(attributes = null) -> string
	{
		return \Phalcon\Tag::passwordField(this->prepareAttributes(attributes));
	}
}
