
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
 | Authors: Olivier Monaco <olivier.monaco@free.fr>                       |
 +------------------------------------------------------------------------+
 */
namespace Phalcon;

use Phalcon\Exception;

/**
 * Phalcon\EnumValueNotExists
 */
class EnumValueNotExists extends Exception
{
	public function __construct(name, cls)
	{
		parent::__construct("\"".name."\" is not a value of ".cls);
	}
}