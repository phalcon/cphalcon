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

class Url_UnitTest extends \PhalconUnitTestCase
{
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

    public function testUrlBase()
    {
        $_SERVER['PHP_SELF'] = '/index.php';

        $url = new PhUrl();

        $expected = '/';
        $actual   = $url->get();

        $this->assertEquals($expected, $actual, 'Base Url not correct');
    }

    public function testUrlOther()
    {
        $_SERVER['PHP_SELF'] = '/index.php';

        $url = new PhUrl();

        $expected = '/classes/api/Some';
        $actual   = $url->get('classes/api/Some');

        $this->assertEquals($expected, $actual, 'Base Url not correct');
    }

    public function testUrlFor()
    {
        $url = new PhUrl();

        $url->setDI($this->_di);

        $routes = array(
            array(
                'paths' => array(
                    'for' => 'adminProducts',
                    'controller' => 'products',
                    'action' => 'index'
                ),
                'url' => '/admin/products/p/index'
            ),
            array(
                'paths' => array(
                    'for' => 'classApi',
                    'class' => 'Some',
                ),
                'url' => '/api/classes/Some'
            ),
            array(
                'paths' => array(
                    'for' => 'blogPost',
                    'year' => '2010',
                    'month' => '10',
                    'title' => 'cloudflare-anade-recursos-a-tu-servidor',
                ),
                'url' => '/2010/10/cloudflare-anade-recursos-a-tu-servidor'
            ),
            array(
                'paths' => array(
                    'for' => 'wikipedia',
                    'article' => 'Television_news'
                ),
                'url' => '/wiki/Television_news'
            )
        );

        foreach($routes as $route)
        {
            $this->assertEquals($url->get($route['paths']), $route['url']);
        }

    }
}