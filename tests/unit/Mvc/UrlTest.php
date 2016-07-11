<?php

namespace Phalcon\Test\Unit\Mvc;

use Phalcon\Test\Proxy\Mvc\Url;
use Phalcon\Mvc\Router;
use Phalcon\Di;
use Phalcon\Test\Module\UnitTest;

/**
 * \Phalcon\Test\Unit\Mvc\UrlTest
 * Tests the Phalcon\Mvc\Url component
 *
 * @copyright (c) 2011-2016 Phalcon Team
 * @link      http://www.phalconphp.com
 * @author    Andres Gutierrez <andres@phalconphp.com>
 * @author    Nikolaos Dimopoulos <nikos@phalconphp.com>
 * @package   Phalcon\Test\Unit\Mvc
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file docs/LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */
class UrlTest extends UnitTest
{
    /**
     * Tests the base url
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-04
     */
    public function testUrlBase()
    {
        $this->specify(
            "The base url is not correct",
            function () {
                $_SERVER['PHP_SELF'] = '/index.php';

                $di       = $this->setupDI();
                $url      = new Url();
                $url->setDI($di);
                $expected = '/';
                $actual   = $url->get();

                expect($actual)->equals($expected);
            }
        );
    }

    /**
     * Tests a different url
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-04
     */
    public function testUrlOther()
    {
        $this->specify(
            "different url is not correct",
            function () {

                $_SERVER['PHP_SELF'] = '/index.php';

                $di       = $this->setupDI();
                $url      = new Url();
                $url->setDI($di);
                $expected = '/classes/api/Some';
                $actual   = $url->get('classes/api/Some');

                expect($actual)->equals($expected);
            }
        );
    }

    /**
     * Tests the url with a controller and action
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-04
     */
    public function testUrlForControllerAction()
    {
        $this->specify(
            "URL with controller/action not correct",
            function () {

                $di       = $this->setupDI();
                $url      = new Url();
                $url->setDI($di);
                $url->setBaseUri('/');
                $params   = [
                    'for'        => 'adminProducts',
                    'controller' => 'products',
                    'action'     => 'index',
                ];
                $expected = '/admin/products/p/index';
                $actual   = $url->get($params);

                expect($actual)->equals($expected);
            }
        );
    }

    /**
     * Tests the url with a controller
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-04
     */
    public function testUrlForController()
    {
        $this->specify(
            "URL for controller not correct",
            function () {

                $di       = $this->setupDI();
                $url      = new Url();
                $url->setDI($di);
                $url->setBaseUri('/');
                $params   = [
                    'for'   => 'classApi',
                    'class' => 'Some',
                ];
                $expected = '/api/classes/Some';
                $actual   = $url->get($params);

                expect($actual)->equals($expected);
            }
        );
    }

    /**
     * Tests the url with a year/month/title
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-04
     */
    public function testUrlForBlogMixedParameters()
    {
        $this->specify(
            "URL with year/month/title not correct",
            function () {

                $di       = $this->setupDI();
                $url      = new Url();
                $url->setDI($di);
                $url->setBaseUri('/');
                $params   = [
                    'for'        => 'lang-controller',
                    'lang'       => 'de',
                    'controller' => 'index',
                ];
                $expected = '/de/index';
                $actual   = $url->get($params);

                expect($actual)->equals($expected);
            }
        );
    }

    /**
     * Tests the url for a different language
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-04
     */
    public function testUrlForDifferentLanguage()
    {
        $this->specify(
            "URL for a different language not correct",
            function () {

                $di       = $this->setupDI();
                $url      = new Url();
                $url->setDI($di);
                $url->setBaseUri('/');
                $params   = [
                    'for'   => 'blogPost',
                    'year'  => '2010',
                    'month' => '10',
                    'title' => 'cloudflare-anade-recursos-a-tu-servidor',
                ];
                $expected = '/2010/10/cloudflare-anade-recursos-a-tu-servidor';
                $actual   = $url->get($params);

                expect($actual)->equals($expected);
            }
        );
    }

    /**
     * Test should avoid double slash when joining baseUri to provided uri
     *
     * @author Olivier Monaco <olivier.monaco@nospam.free.fr>
     * @since  2015-02-03
     * @issue  3315
     */
    public function testUrlForGet()
    {
        $this->specify(
            "Url::get does not return expected value",
            function () {
                $url = new Url();
                $url->setBaseUri('http://www.test.com');

                expect($url->get(''))->equals('http://www.test.com');
                expect($url->get('/'))->equals('http://www.test.com/');
                expect($url->get('/path'))->equals('http://www.test.com/path');

                $url->setBaseUri('http://www.test.com/?_url=/');

                expect($url->get('path', ['params' => 'one']))->equals('http://www.test.com/?_url=/path&params=one');
            }
        );
    }

    /**
     * Tests the url with external website
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-04
     */
    public function testUrlForExternalSite()
    {
        $this->specify(
            "URL for a different language not correct",
            function () {

                $di       = $this->setupDI();
                $url      = new Url();
                $url->setDI($di);
                $url->setBaseUri('/');
                $params   = [
                    'for'     => 'wikipedia',
                    'article' => 'Television_news',
                ];
                $expected = '/wiki/Television_news';
                $actual   = $url->get($params);

                expect($actual)->equals($expected);
            }
        );
    }
    
    /**
     * Test urls that contains colons in schema definition and as parameter
     * 
     * @author Anton Melnik <melnik.anton2100@gmail.com>
     * @since 2016-05-07
     */
    public function testUrlWithColons()
    {
        $this->specify(
            "URL with colon is not correct",
            function () {
                $di = $this->setupDI();
                $url = new Url();
		$url->setBaseUri('http://www.test.com');
                
                expect($url->get("/controller/action/param/colon:param"))
                        ->equals("http://www.test.com/controller/action/param/colon:param");
                
                expect($url->get("http://www.example.com"))->equals('http://www.example.com');
                expect($url->get("//www.example.com"))->equals('//www.example.com');
                expect($url->get("schema:example.com"))->equals('schema:example.com');
            }
        );
    }

    /**
     * Sets the environment
     */
    private function setupDI()
    {
        Di::reset();
        $di = new Di();

        $di->set(
            'router',
            function () {
                $router = new Router(false);

                $router->add(
                    '/admin/:controller/p/:action',
                    [
                        'controller' => 1,
                        'action'     => 2,
                    ]
                )->setName('adminProducts');

                $router->add('/api/classes/{class}')->setName('classApi');

                $router->add('/{year}/{month}/{title}')->setName('blogPost');

                $router->add('/wiki/{article:[a-z]+}')->setName('wikipedia');

                $router->add(
                    '/news/{country:[a-z]{2}}/([a-z+])/([a-z\-+])/{page}',
                    [
                        'section' => 2,
                        'article' => 3,
                    ]
                )->setName('news');

                $router->add(
                    '/([a-z]{2})/([a-zA-Z0-9_-]+)(/|)',
                    [
                        'lang'       => 1,
                        'module'     => 'main',
                        'controller' => 2,
                        'action'     => 'index',
                    ]
                )->setName('lang-controller');

                $router->removeExtraSlashes(true);

                return $router;
            }
        );

        return $di;
    }
}
