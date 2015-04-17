<?php

/**
 * Config.php
 * Phalcon_Test_Config
 *
 * Encapsulates the configuration needed for the tests
 *
 * PhalconPHP Framework
 *
 * @copyright (c) 2011-2015 Phalcon Team
 * @link      http://www.phalconphp.com
 * @author    Andres Gutierrez <andres@phalconphp.com>
 * @author    Eduar Carvajal <eduar@phalconphp.com>
 * @author    Nikolaos Dimopoulos <nikos@niden.net>
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file docs/LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */

namespace Phalcon\Test;

class Config
{
	public static function init()
	{
		if (file_exists(__DIR__ . '/config.db.local.php')) {
			$db_config = require (__DIR__ . '/config.db.local.php');
		}
		else {
			$db_config = array(
				'mysql'      => array(
					'host'     => 'localhost',
					'username' => 'root',
					'password' => '',
					'dbname'   => 'phalcon_test',
				),
				'postgresql' => array(
					'host'     => '127.0.0.1',
					'username' => 'postgres',
					'password' => '',
					'dbname'   => 'phalcon_test',
					'schema'   => 'public',
				),
				'sqlite'     => array(
					'host'     => '',
					'username' => '',
					'password' => '',
					'dbname'   => '/tmp/phalcon_test.sqlite',
				),
			);
		}

		$config = array(
			'db' => $db_config,
			'tr' => array(
				'en' => array(
					'hi'        => 'Hello',
					'bye'       => 'Good Bye',
					'hello-key' => 'Hello %name%',
					'song-key'  => 'This song is %song% (%artist%)',
				),
				'es' => array(
					'hi'        => 'Hola',
					'bye'       => 'Adiós',
					'hello-key' => 'Hola %name%',
					'song-key'  => 'La canción es %song% (%artist%)',
				),
				'fr' => array(
					'hi'        => 'Bonjour',
					'bye'       => 'Au revoir',
					'hello-key' => 'Bonjour %name%',
					'song-key'  => 'La chanson est %song% (%artist%)',
				),
				'hi' => array(
					'hi'        => 'हाय',
					'bye'       => 'अलविदा',
					'hello-key' => 'हाय %name%',
					'song-key'  => 'यह गीत %song% (%artist%) है',
				),
			),
		);

		return $config;
	}
}
