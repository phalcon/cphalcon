
/*
 +------------------------------------------------------------------------+
 | Phalcon Framework                                                      |
 +------------------------------------------------------------------------+
 | Copyright (c) 2011-2017 Phalcon Team (https://phalconphp.com)          |
 +------------------------------------------------------------------------+
 | This source file is subject to the New BSD License that is bundled     |
 | with this package in the file LICENSE.txt.                             |
 |                                                                        |
 | If you did not receive a copy of the license and are unable to         |
 | obtain it through the world-wide-web, please send an email             |
 | to license@phalconphp.com so we can send you a copy immediately.       |
 +------------------------------------------------------------------------+
 | Authors: Andres Gutierrez <andres@phalconphp.com>                      |
 |          Eduar Carvajal <eduar@phalconphp.com>                         |
 +------------------------------------------------------------------------+
 */

namespace Phalcon\Di\Service;

use Phalcon\Di\Service;

/**
 * Phalcon\Di\Service\SharedService
 *
 *
 *<code>
 * $service = new \Phalcon\Di\Service\SharedService(
 *     "request",
 *     "Phalcon\\Http\\Request"
 * );
 *
 * $request = service->resolve();
 *</code>
 */
class SharedService extends Service
{
	/**
	 * Phalcon\Di\Service\SharedService
	 *
	 * @param mixed definition
	 */
	public final function __construct(definition)
	{
		parent::__construct(definition, true);
	}
}
