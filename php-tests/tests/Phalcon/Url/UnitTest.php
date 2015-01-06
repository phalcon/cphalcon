<?php
/**
 * UnitTest.php
 * \Phalcon\Url\UnitTest
 *
 * Tests the \Phalcon\Url component
 *
 * PhalconPHP Framework
 *
 * @copyright (c) 2011-2014 Phalcon Team
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

namespace Phalcon\Test\Url;

use \Phalcon\Test\UnitTestCase as PhTestUnitTestCase;

use \Phalcon\Mvc\Router as PhRouter;
use \Phalcon\Mvc\Url as PhUrl;

class UnitTest extends PhTestUnitTestCase
{
    /**
     * Sets the environment
     */
    public function setUp()
    {
        parent::setUp();

        $this->di->set(
            'router',
            function () {

                $router = new PhRouter(false);

                $router->add(
                    '/admin/:controller/p/:action',
                    array(
                        'controller' => 1,
                        'action'     => 2,
                    )
                )->setName('adminProducts');

                $router->add('/api/classes/{class}')->setName('classApi');

                $router->add('/{year}/{month}/{title}')->setName('blogPost');

                $router->add('/wiki/{article:[a-z]+}')->setName('wikipedia');

                $router->add(
                    '/news/{country:[a-z]{2}}/([a-z+])/([a-z\-+])/{page}',
                    array(
                        'section' => 2,
                        'article' => 3,
                    )
                )->setName('news');

                $router->add(
                    '/([a-z]{2})/([a-zA-Z0-9_-]+)(/|)',
                    array(
                        'lang'       => 1,
                        'module'     => 'main',
                        'controller' => 2,
                        'action'     => 'index',
                    )
                )->setName('lang-controller');

                return $router;
            }
        );
    }

    /**
     * Tests the base url
     *
     * @author Nikos Dimopoulos <nikos@phalconphp.com>
     * @since  2012-11-29
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
     * @author Nikos Dimopoulos <nikos@phalconphp.com>
     * @since  2012-11-29
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
     * @author Nikos Dimopoulos <nikos@phalconphp.com>
     * @since  2012-11-29
     */
    public function testUrlForControllerAction()
    {
        $url = new PhUrl();

        $url->setDI($this->di);

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
     * @author Nikos Dimopoulos <nikos@phalconphp.com>
     * @since  2012-11-29
     */
    public function testUrlForController()
    {
        $url = new PhUrl();

        $url->setDI($this->di);

        $params   = array(
            'for'   => 'classApi',
            'class' => 'Some',
        );
        $expected = '/api/classes/Some';
        $actual   = $url->get($params);

        $this->assertEquals($expected, $actual, 'Class Url not correct');

    }

    /**
     * Tests the url with a year/month/title
     *
     * @author Nikos Dimopoulos <nikos@phalconphp.com>
     * @since  2012-11-29
     */
    public function testUrlForBlogMixedParameters()
    {
        $url = new PhUrl();

        $url->setDI($this->di);

        $params   = array(
            'for'        => 'lang-controller',
            'lang'       => 'de',
            'controller' => 'index',
        );
        $expected = '/de/index';
        $actual   = $url->get($params);

        $this->assertEquals($expected, $actual, 'Language Url not correct');

    }

    /**
     * Tests the url with a year/month/title
     *
     * @author Nikos Dimopoulos <nikos@phalconphp.com>
     * @since  2012-11-29
     */
    public function testUrlForDifferentLanguage()
    {
        $url = new PhUrl();

        $url->setDI($this->di);

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
     * @author Nikos Dimopoulos <nikos@phalconphp.com>
     * @since  2012-11-29
     */
    public function testUrlForExternalSite()
    {
        $url = new PhUrl();

        $url->setDI($this->di);

        $params   = array(
            'for'     => 'wikipedia',
            'article' => 'Television_news',
        );
        $expected = '/wiki/Television_news';
        $actual   = $url->get($params);

        $this->assertEquals($expected, $actual, 'External Site Url not correct');

    }

    /**
     * @ticket 1960
     * @author Vladimir Kolesnikov <vladimir@extrememember.com>
     * @since 2014-02-02
     */
    public function testIssue1960()
    {
    	$url = new \Phalcon\Mvc\Url();
    	$url->setDI($this->di);

    	$params   = 'http://www.google.com/';
    	$expected = 'http://www.google.com/';
    	$actual   = $url->get($params);

    	$this->assertEquals($expected, $actual, 'External Site Url not correct');
    }
}