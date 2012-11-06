<?php
/**
 * UnitTest.php
 * Mvc_Micro_UnitTest
 *
 * Tests the \Phalcon\Mvc\Micro component
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

use \Phalcon\Mvc\Micro as Micro;

class Mvc_Micro_UnitTest extends Phalcon_Test_UnitTestCase
{
    /**
     * Tests the getNumberAccess
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-11-06
     */
    public function testMicroGetNumberAccess()
    {
        $handler = new Mvc_Micro_Helper_RestHandler($this);
        $app     = new Micro();

        $app->get('/api/site', array($handler, 'find'));
        $app->post('/api/site/save', array($handler, 'save'));

        $_SERVER['REQUEST_METHOD'] = 'GET';
        $_GET['_url'] = '/api/site';

        $app->handle();

        $expected = 1;
        $actual   = $handler->getNumberAccess();

        $this->assertEquals(
            $expected,
            $actual,
            'getNumberAccess does not return correct results'
        );
    }

    /**
     * Tests the getTrace
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-11-06
     */
    public function testMicroGetTrace()
    {
        $handler = new Mvc_Micro_Helper_RestHandler($this);
        $app     = new Micro();

        $app->get('/api/site', array($handler, 'find'));
        $app->post('/api/site/save', array($handler, 'save'));

        $_SERVER['REQUEST_METHOD'] = 'GET';
        $_GET['_url'] = '/api/site';

        $app->handle();

        $expected = array('find');
        $actual   = $handler->getTrace();

        $this->assertEquals(
            $expected,
            $actual,
            'getTrace does not return correct results'
        );
    }

    /**
     * Tests the getNumberAccess
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-11-06
     */
    public function testMicroGetNumberAccessTwice()
    {
        $handler = new Mvc_Micro_Helper_RestHandler($this);
        $app     = new Micro();

        $app->get('/api/site', array($handler, 'find'));
        $app->post('/api/site/save', array($handler, 'save'));

        $_SERVER['REQUEST_METHOD'] = 'GET';
        $_GET['_url'] = '/api/site';

        $app->handle();

        $_SERVER['REQUEST_METHOD'] = 'POST';
        $_GET['_url'] = '/api/site/save';

        $app->handle();

        $expected = 2;
        $actual   = $handler->getNumberAccess();

        $this->assertEquals(
            $expected,
            $actual,
            'getNumberAccess does not return correct results'
        );
    }
    /**
     * Tests the getTrace
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-11-06
     */
    public function testMicroGetTraceTwice()
    {
        $handler = new Mvc_Micro_Helper_RestHandler($this);
        $app     = new Micro();

        $app->get('/api/site', array($handler, 'find'));
        $app->post('/api/site/save', array($handler, 'save'));

        $_SERVER['REQUEST_METHOD'] = 'GET';
        $_GET['_url'] = '/api/site';

        $app->handle();

        $_SERVER['REQUEST_METHOD'] = 'POST';
        $_GET['_url'] = '/api/site/save';

        $app->handle();

        $expected = array('find', 'save');
        $actual   = $handler->getTrace();

        $this->assertEquals(
            $expected,
            $actual,
            'getTrace does not return correct results'
        );
    }

    /**
     * Tests the notFound
     *
     * @issue  T169
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-11-06
     */
    public function testMicroNotFound_T169()
    {
        $this->markTestSkipped('Waiting for issue resolution on this');
        $handler = new Mvc_Micro_Helper_RestHandler($this);
        $app     = new Micro();

        $app->get('/api/site', array($handler, 'find'));
        $app->post('/api/site/save', array($handler, 'save'));

        $app->notFound(
            function () use ($app) {
                $app->response->setStatusCode(404, "Not Found")->sendHeaders();
                echo 'This is crazy, but this page was not found!';
            }
        );

        $_SERVER['REQUEST_METHOD'] = 'GET';
        $_GET['_url'] = '/fourohfour';

        $app->handle();

        $expected = 1;
        $actual   = $handler->getNumberAccess();

        $this->assertEquals(
            $expected,
            $actual,
            'getNumberAccess does not return correct results'
        );
    }
}