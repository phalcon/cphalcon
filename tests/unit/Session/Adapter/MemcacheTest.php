<?php

namespace Phalcon\Test\Unit\Session\Adapter;

use Phalcon\Test\Proxy\Session\Adapter\Memcache;
use Phalcon\Test\Module\UnitTest;

/**
 * \Phalcon\Test\Unit\Session\Adapter\MemcacheTest
 * Tests the \Phalcon\Session\Adapter\Memcache component
 *
 * @copyright (c) 2011-2016 Phalcon Team
 * @link      http://www.phalconphp.com
 * @author    Andres Gutierrez <andres@phalconphp.com>
 * @author    Nikolaos Dimopoulos <nikos@phalconphp.com>
 * @package   Phalcon\Test\Unit\Session\Adapter
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file docs/LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */
class MemcacheTest extends UnitTest
{
    /**
     * executed before each test
     */
    public function _before()
    {
        parent::_before();

        if (!extension_loaded('memcache')) {
            $this->markTestSkipped('Warning: memcache extension is not loaded');
        }
    }

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
                $sessionID = "abcdef123456";

                $session = new Memcache(
                    array(
                        "host" => TEST_MC_HOST,
                        "port" => TEST_MC_PORT
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
                $sessionID = "abcdef123456";

                $session = new Memcache(
                    array(
                        "host" => TEST_MC_HOST,
                        "port" => TEST_MC_PORT
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
