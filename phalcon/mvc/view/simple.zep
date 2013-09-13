
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

namespace Phalcon\Mvc\View;

/**
 * Phalcon\Mvc\View\Simple
 *
 * This component allows to render views without hicherquical levels
 *
 *<code>
 * $view = new Phalcon\Mvc\View\Simple();
 * echo $view->render('templates/my-view', array('content' => $html));
 *</code>
 *
 */
class Simple extends Phalcon\Di\Injectable
{

	protected _options;

	protected _viewsDir;

	protected _partialsDir;

	protected _viewParams;

	protected _engines = false;

	protected _registeredEngines;

	protected _activeRenderPath;

	protected _content;

	protected _cache = false;

	protected _cacheOptions;

}
