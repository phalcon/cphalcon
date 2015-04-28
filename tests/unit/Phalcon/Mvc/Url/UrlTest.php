<?php
/**
 * UrlTest.php
 * \Phalcon\Mvc\Url\UrlTest
 *
 * Tests the Phalcon\Mvc\Url component
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

namespace Phalcon\Tests\unit\Phalcon\Mvc\Url;

use Phalcon\DI as PhDI;
use Phalcon\Mvc\Router as PhRouter;
use \PhalconTest\Mvc\Url as PhTUrl;

use \Phalcon\Tests\unit\Phalcon\_Helper\TestsBase as TBase;

class UrlTest extends TBase
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
                $url      = new PhTUrl();
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
                $url      = new PhTUrl();
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
                $url      = new PhTUrl();
                $url->setDI($di);
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
                $url      = new PhTUrl();
                $url->setDI($di);
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
                $url      = new PhTUrl();
                $url->setDI($di);
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
                $url      = new PhTUrl();
                $url->setDI($di);
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
                $url      = new PhTUrl();
                $url->setDI($di);
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
     * Sets the environment
     */
    private function setupDI()
    {
        PhDI::reset();
        $di = new PhDI();

        $di->set(
            'router',
            function () {
                $router = new PhRouter(false);

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

                return $router;
            }
        );

        return $di;
    }
}
