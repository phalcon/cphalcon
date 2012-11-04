<?php
/**
 * UnitTest.php
 * \Phalcon\Url\UnitTest
 *
 * Tests the \Phalcon\Url component
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

use \Phalcon\Mvc\Router as PhRouter;
use \Phalcon\Mvc\Url as PhUrl;

class Url_UnitTest extends Phalcon_Test_UnitTestCase
{
    /**
     * Sets the environment
     */
    public function setUp()
    {
        parent::setUp();

        $this->_di->set(
            'router',
            function()
            {
                $router = new PhRouter(false);

                $router->add('/admin/:controller/p/:action')
                       ->setName('adminProducts');
                $router->add('/api/classes/{class}')
                       ->setName('classApi');
                $router->add('/{year}/{month}/{title}')
                       ->setName('blogPost');
                $router->add('/wiki/{article:[a-z]+}')
                       ->setName('wikipedia');
                return $router;
            }
        );
    }

    /**
     * Tests the base url
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-11-02
     */
    public function testUrlBase()
    {
        $_SERVER['PHP_SELF'] = '/index.php';

        $url = new PhUrl();

        $expected = '/';
        $actual   = $url->get();

        $this->assertEquals($expected, $actual, 'Base Url not correct');
    }

    /**
     * Tests a different url
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-11-02
     */
    public function testUrlOther()
    {
        $_SERVER['PHP_SELF'] = '/index.php';

        $url = new PhUrl();

        $expected = '/classes/api/Some';
        $actual   = $url->get('classes/api/Some');

        $this->assertEquals($expected, $actual, 'Base Url not correct');
    }

    /**
     * Tests the url with a controller and action
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-11-02
     */
    public function testUrlForControllerAction()
    {
        $url = new PhUrl();

        $url->setDI($this->_di);

        $params   = array(
                        'for'        => 'adminProducts',
                        'controller' => 'products',
                        'action'     => 'index',
                    );
        $expected = '/admin/products/p/index';
        $actual   = $url->get($params);

        $this->assertEquals($expected, $actual, 'Controller/Action Url not correct');

    }

    /**
     * Tests the url with a controller
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-11-02
     */
    public function testUrlForController()
    {
        $this->markTestSkipped('Need to talk to Andres on this');
        $url = new PhUrl();

        $url->setDI($this->_di);

        $params   = array(
                        'for'        => 'classApi',
                        'controller' => 'Some',
                    );
        $expected = '/admin/classes/Some';
        $actual   = $url->get($params);

        $this->assertEquals($expected, $actual, 'Controller Url not correct');

    }

    /**
     * Tests the url with a year/month/title
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-11-02
     */
    public function testUrlForBlogMixedParameters()
    {
        $url = new PhUrl();

        $url->setDI($this->_di);

        $params   = array(
                        'for'   => 'blogPost',
                        'year'  => '2010',
                        'month' => '10',
                        'title' => 'cloudflare-anade-recursos-a-tu-servidor',
                    );
        $expected = '/2010/10/cloudflare-anade-recursos-a-tu-servidor';
        $actual   = $url->get($params);

        $this->assertEquals($expected, $actual, 'Mixed Parameters Url not correct');

    }

    /**
     * Tests the url with external website
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-11-02
     */
    public function testUrlForExternalSite()
    {
        $url = new PhUrl();

        $url->setDI($this->_di);

        $params   = array(
                        'for'     => 'wikipedia',
                        'article' => 'Television_news',
                    );
        $expected = '/wiki/Television_news';
        $actual   = $url->get($params);

        $this->assertEquals($expected, $actual, 'External Site Url not correct');

    }
}