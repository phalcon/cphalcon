<?php

namespace Phalcon\Test\Unit\Session\Adapter;

use Phalcon\Test\Module\UnitTest;
use Phalcon\Session\Adapter\Libmemcached;

/**
 * Phalcon\Test\Unit\Session\Adapter\LibmemcachedTest
 * Tests the \Phalcon\Session\Adapter\Libmemcached component
 *
 * @copyright (c) 2011-2017 Phalcon Team
 * @link      https://phalconphp.com
 * @author    Andres Gutierrez <andres@phalconphp.com>
 * @author    Nikolaos Dimopoulos <nikos@phalconphp.com>
 * @package   Phalcon\Test\Unit\Session\Adapter
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */
class LibmemcachedTest extends UnitTest
{
    /**
     * executed before each test
     */
    public function _before()
    {
        parent::_before();

        if (!extension_loaded('memcached')) {
            $this->markTestSkipped('Warning: memcached extension is not loaded');
        }

        if (!isset($_SESSION)) {
            $_SESSION = [];
        }
    }

    /**
     * executed after each test
     */
    protected function _after()
    {
        parent::_after();

        if (PHP_SESSION_ACTIVE == session_status()) {
            session_destroy();
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

                $session = new Libmemcached([
                    'servers' => [
                        [
                            'host' => env('TEST_MC_HOST', '127.0.0.1'),
                            'port' => env('TEST_MC_PORT', 11211),
                        ]
                    ],
                    'client' => []
                ]);

                $data = serialize(
                    [
                        'abc' => '123',
                        'def' => '678',
                        'xyz' => 'zyx'
                    ]
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

                $session = new Libmemcached([
                    'servers' => [
                        [
                            'host' => env('TEST_MC_HOST', '127.0.0.1'),
                            'port' => env('TEST_MC_PORT', 11211),
                        ]
                    ],
                    'client' => []
                ]);

                $data = serialize(
                    [
                        'abc' => '123',
                        'def' => '678',
                        'xyz' => 'zyx'
                    ]
                );

                $session->write($sessionID, $data);
                $session->destroy($sessionID);

                expect($session->read($sessionID))->equals(null);
            }
        );
    }

    /**
     * Tests the destroy with cleanning $_SESSION
     *
     * @test
     * @issue  https://github.com/phalcon/cphalcon/issues/12326
     * @issue  https://github.com/phalcon/cphalcon/issues/12835
     * @author Serghei Iakovelev <serghei@phalconphp.com>
     * @since  2017-05-08
     */
    public function destroyDataFromSessionSuperGlobal()
    {
        $this->specify(
            'The libmemcached adapter does not clear session superglobal after destroy',
            function () {
                $session = new Libmemcached([
                    'servers'  => [
                        [
                            'host' => env('TEST_MC_HOST', '127.0.0.1'),
                            'port' => env('TEST_MC_PORT', 11211),
                        ],
                    ],
                    'client'   => [],
                    'uniqueId' => 'session',
                    'lifetime' => 3600,
                ]);

                $session->start();

                $session->test1 = __METHOD__;
                expect($_SESSION)->hasKey('session#test1');
                expect($_SESSION['session#test1'])->contains(__METHOD__);

                $session->destroy();
                expect($_SESSION)->hasntKey('session#test1');
            }
        );
    }
}
