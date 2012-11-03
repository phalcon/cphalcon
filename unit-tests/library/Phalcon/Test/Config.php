<?php
/**
 * Config.php
 * Phalcon_Test_Config
 *
 * Encapsulates the configuration needed for the tests
 *
 * PhalconPHP Framework
 *
 * @copyright (c) 2011-2012 Phalcon Team
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

class Phalcon_Test_Config
{
    public static function init()
    {
        $config = array(
            'db' => array(
                        'mysql'      => array(
                            'host'     => 'localhost',
                            'username' => 'root',
                            'password' => '1234',
                            'dbname'   => 'phalcon_test',
                        ),
                        'postgresql' => array(
                            'host'     => '127.0.0.1',
                            'username' => 'postgres',
                            'password' => '1234',
                            'dbname'   => 'phalcon_test',
                            'schema'   => 'public',
                        ),
                        'sqlite'     => array(
                            'host'     => '',
                            'username' => '',
                            'password' => '',
                            'dbname'   => '/tmp/phalcon_test.sqlite',
                        ),
                    ),
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
                    ),
        );

        return $config;
    }
}

/**
 * Class used by Phalcon\Filter
 */
class IPv4Filter
{

    public function filter($value)
    {
        return filter_var($value, FILTER_VALIDATE_IP, FILTER_FLAG_IPV4);
    }

}
