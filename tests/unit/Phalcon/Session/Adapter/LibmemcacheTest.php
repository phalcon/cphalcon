<?php
/**
 * LibmemcachedTest.php
 * \Phalcon\Session\Adapter\Libmemcached
 *
 * Tests the \Phalcon\Session\Adapter\Libmemcached component
 *
 * Phalcon Framework
 *
 * @copyright (c) 2011-2015 Phalcon Team
 * @link      http://www.phalconphp.com
 * @author    Andres Gutierrez <andres@phalconphp.com>
 * @author    Nikolaos Dimopoulos <nikos@phalconphp.com>
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file docs/LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */

namespace Phalcon\Tests\unit\Phalcon\Session\Adapter;

use \PhalconTest\Session\Adapter\Libmemcached as PhTLibmemcached;
use \Codeception\TestCase\Test as CdTest;

use \Phalcon\Tests\unit\Phalcon\_Helper\TestsBase as TBase;

class LibmemcachedTest extends TBase
{
    /**
     * Tests read and write
     *
     * @author Sid Roberts <sid@sidroberts.co.uk>
     * @since  2015-07-17
     */
    public function testReadAndWriteSession()
    {
        $this->specify(
            "The session cannot be read or written from",
            function () {
                if (!extension_loaded('memcached')) {
                    $this->markTestSkipped('Warning: memcached extension is not loaded');
                    return false;
                }

                $sessionID = "abcdef123456";

                $session = new PhTLibmemcached(
                    array(
                        "host" => "127.0.0.1",
                        "port" => 11211
                    )
                );

                $data = serialize(
                    array(
                        "abc" => "123",
                        "def" => "678",
                        "xyz" => "zyx"
                    )
                );

                $session->write($sessionID, $data);

                expect($session->read($sessionID))->equals($data);
            }
        );
    }

    /**
     * Tests the destroy
     *
     * @author Sid Roberts <sid@sidroberts.co.uk>
     * @since  2015-07-17
     */
    public function testDestroySession()
    {
        $this->specify(
            "The session cannot be destroyed",
            function () {
                if (!extension_loaded('memcached')) {
                    $this->markTestSkipped('Warning: memcached extension is not loaded');
                    return false;
                }

                $sessionID = "abcdef123456";

                $session = new PhTLibmemcached(
                    array(
                        "host" => "127.0.0.1",
                        "port" => 11211
                    )
                );

                $data = serialize(
                    array(
                        "abc" => "123",
                        "def" => "678",
                        "xyz" => "zyx"
                    )
                );

                $session->write($sessionID, $data);

                $session->destroy($sessionID);

                expect($session->read($sessionID))->equals(null);
            }
        );
    }
}
