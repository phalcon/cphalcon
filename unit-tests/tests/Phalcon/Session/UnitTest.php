<?php
/**
 * UnitTest.php
 * Session_UnitTest
 *
 * Tests the \Phalcon\Session component
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

use \Phalcon\Session\Adapter\Files as PhSession;

class Session_UnitTest extends Phalcon_Test_UnitTestCase
{
    /**
     * Tests starting the session
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-11-05
     */
    public function testStart()
    {
        $this->markTestSkipped('Need to talk to Andres on this');
        $session = new PhSession();

        $actual = $session->start();

        //$session->destroy();

        $this->assertTrue($actual, 'Session has been started');
    }

    /**
     * Tests whether the session has started
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-11-05
     */
    public function testIsStarted()
    {
        $this->markTestSkipped('Need to talk to Andres on this');
        $session = new PhSession();

        $session->start();
        $actual = $session->isStarted();

        //$session->destroy();

        $this->assertTrue($actual, 'Session has not been started');
    }

    /**
     * Tests the get/set in the session
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-11-05
     */
    public function testGetSet()
    {
        $this->markTestSkipped('Need to talk to Andres on this');
        $session = new PhSession();

        $session->start();

        $session->set('some', 'value');

        $expected = 'value';
        $actual   = $session->get('some');

        //$session->destroy();

        $this->assertEquals($expected, $actual, 'Session value not correct');
    }
}