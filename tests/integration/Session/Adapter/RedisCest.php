<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Integration\Session\Adapter;

use IntegrationTester;
use Phalcon\Session\Adapter\Redis;

class RedisCest
{
    /**
     * executed before each test
     */
    public function _before(IntegrationTester $I)
    {
        $I->skipTest('REFACTOR');
        $I->checkExtensionIsLoaded('redis');

        if (!isset($_SESSION)) {
            $_SESSION = [];
        }
    }

    /**
     * executed after each test
     */
    public function _after(IntegrationTester $I)
    {
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
    public function testReadAndWriteSession(IntegrationTester $I)
    {
        $sessionID = "abcdef123456";
        $session = new Redis(
            [
                'host'  => env('DATA_REDIS_HOST'),
                'port'  => env('DATA_REDIS_PORT'),
                'index' => env('DATA_REDIS_NAME'),
            ]
        );
        $data = serialize(
            [
                "abc" => "123",
                "def" => "678",
                "xyz" => "zyx"
            ]
        );

        $session->write($sessionID, $data);

        $I->assertEquals($session->read($sessionID), $data);
    }

    /**
     * Tests the destroy
     *
     * @author Sid Roberts <sid@sidroberts.co.uk>
     * @since  2015-07-17
     */
    public function testDestroySession(IntegrationTester $I)
    {
        $sessionID = "abcdef123456";
        $session = new Redis(
            [
                'host'  => env('DATA_REDIS_HOST'),
                'port'  => env('DATA_REDIS_PORT'),
                'index' => env('DATA_REDIS_NAME'),
            ]
        );
        $data = serialize(
            [
                "abc" => "123",
                "def" => "678",
                "xyz" => "zyx"
            ]
        );

        $session->write($sessionID, $data);
        $session->destroy($sessionID);

        $I->assertEquals($session->read($sessionID), null);
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
    public function destroyDataFromSessionSuperGlobal(IntegrationTester $I)
    {
        $session = new Redis(
            [
                'host'     => env('DATA_REDIS_HOST', '127.0.0.1'),
                'port'     => env('DATA_REDIS_PORT', 6379),
                'index'    => env('DATA_REDIS_NAME', 0),
                'uniqueId' => 'session',
                'lifetime' => 3600,
                'prefix'   => '_DESTROY:',
            ]
        );

        $session->start();

        $session->test1 = __METHOD__;
        $I->assertArrayHasKey('session#test1', $_SESSION);
        $I->assertContains(__METHOD__, $_SESSION['session#test1']);

        $session->destroy();
        $I->assertArrayNotHasKey('session#test1', $_SESSION);
    }
}
