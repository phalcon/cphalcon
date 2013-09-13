
/*
 +------------------------------------------------------------------------+
 | Phalcon Framework                                                      |
 +------------------------------------------------------------------------+
 | Copyright (c) 2011-2013 Phalcon Team (http://www.phalconphp.com)       |
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

namespace Phalcon\Http;

/**
 * Phalcon\Http\Cookie
 *
 * Provide OO wrappers to manage a HTTP cookie
 */
class Cookie implements Phalcon\Di\InjectionAwareInterface
{

	protected _readed = false;

	protected _restored = false;

	protected _useEncryption = false;

	protected _dependencyInjector;

	protected _filter;

	protected _name;

	protected _value;

	protected _expire;

	protected _path = "/";

	protected _domain;

	protected _secure;

	protected _httpOnly = true;

}
