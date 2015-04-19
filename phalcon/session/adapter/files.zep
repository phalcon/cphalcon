
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

namespace Phalcon\Session\Adapter;

use Phalcon\Session\Adapter;

/**
 * Phalcon\Session\Adapter\Files
 *
 * This adapter store sessions in plain files
 *
 *<code>
 * $session = new \Phalcon\Session\Adapter\Files(array(
 *    'uniqueId' => 'my-private-app',
 *    'savePath' => 'session-save-path',
 *    'name' => 'session-name',
 *    'cookie_lifetime' => 'session-cookie-lifetime',
 *    'cookie_path' => 'session-cookie-path',
 *    'cookie_domain' => 'session-cookie-domain',
 *    'cookie_secure' => 'session-cookie-secure',
 *    'cookie_httponly' => 'session-cookie-httponly'
 * ));
 *
 * $session->start();
 *
 * $session->set('var', 'some-value');
 *
 * echo $session->get('var');
 *</code>
 */
class Files extends Adapter
{
	/**
	 * {@inheritdoc}
	 */
	public function read(string sessionId) -> string
	{
		var session_file;
		let session_file = session_save_path() . DIRECTORY_SEPARATOR . "sess_" . this->getId();

		if is_file(session_file) {
			return file_get_contents(session_file);
		} else {
			return "";
		}

	}

	/**
	 * {@inheritdoc}
	 */
	protected function configure() -> void
	{
		var path;
		let path = this->getOption("savePath");

		if path {
			session_save_path(path);
		}

		parent::configure();
	}
}
