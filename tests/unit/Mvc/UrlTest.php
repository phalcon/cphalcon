<?php

/*
 +------------------------------------------------------------------------+
 | Phalcon Framework                                                      |
 +------------------------------------------------------------------------+
 | Copyright (c) 2011-present Phalcon Team (https://phalconphp.com)       |
 +------------------------------------------------------------------------+
 | This source file is subject to the New BSD License that is bundled     |
 | with this package in the file LICENSE.txt.                             |
 |                                                                        |
 | If you did not receive a copy of the license and are unable to         |
 | obtain it through the world-wide-web, please send an email             |
 | to license@phalconphp.com so we can send you a copy immediately.       |
 +------------------------------------------------------------------------+
 */

namespace Phalcon\Test\Unit\Mvc;

use Phalcon\Di;
use Phalcon\Mvc\Url;
use Phalcon\Mvc\Router;
use Phalcon\Test\Module\UnitTest;
use Helper\Mvc\RouterTrait;

/**
 * Phalcon\Test\Unit\Mvc\UrlTest
 *
 * Tests the Phalcon\Mvc\Url component
 *
 * @package Phalcon\Test\Unit\Mvc
 */
class UrlTest extends UnitTest
{
    use RouterTrait;

    /**
     * @var Di
     */
    protected $di;

    /**
     * @var Url
     */
    protected $url;

    /**
     * executed before each test
     */
    protected function _before()
    {
        $this->di = $this->setupDI();
        $this->url = new Url();
    }

    /**
     * Tests the base url
     *
     * @test
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-04
     */
    public function shouldGetCorrectUrlWithServer()//+
    {
        $this->specify(
            'The base url is not correct',
            function ($params, $expected) {
                $_SERVER['PHP_SELF'] = $params['server_php_self'];
                $this->url->setDI($this->setupDI());

                expect($this->url->get($params['get']))->equals($expected);
            },
            [
                'examples' => include_once PATH_FIXTURES . 'mvc/url_test/url_to_set_server.php'
            ]
        );
    }

    /**
     * Tests the url with a controller and action
     *
     * @test
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-04
     */
    public function shouldCorrectSetBaseUri()//+
    {
        $this->specify(
            'URL with controller/action not correct',
            function ($params, $expected) {
                $this->url->setBaseUri($params['base_url']);
                $this->url->setDI($this->setupDI());

                expect($this->url->get($params['param']))->equals($expected);
            },
            [
                'examples' => include_once PATH_FIXTURES . 'mvc/url_test/url_to_set_base_uri.php'
            ]
        );
    }

    /**
     * Tests the url with a controller and action
     *
     * @test
     * @author Olivier Monaco <olivier.monaco@nospam.free.fr>
     * @since  2015-02-03
     * @issue  https://github.com/phalcon/cphalcon/issues/3315
     */
    public function shouldGetCorrectUrl()
    {
        $this->specify(
            'Url::get with one param does not return expected value',
            function ($params, $expected) {
                $this->url->setBaseUri($params['base_url']);

                expect($this->url->get($params['get']))->equals($expected);
            },
            [
                'examples' => include_once PATH_FIXTURES . 'mvc/url_test/url_to_set_without_di.php'
            ]
        );
    }

    /**
     * Test should avoid double slash when joining baseUri to provided uri
     *
     * @test
     * @author Olivier Monaco <olivier.monaco@nospam.free.fr>
     * @since  2015-02-03
     * @issue  https://github.com/phalcon/cphalcon/issues/3315
     */
    public function shouldGetCorrectUrlWithGetParam()
    {
        $this->specify(
            'Url::get with two param does not return expected value',
            function ($params, $expected) {
                $this->url->setBaseUri($params['base_url']);

                expect($this->url->get($params['get'], $params['second_get']))->equals($expected);
            },
            [
                'examples' => include_once PATH_FIXTURES . 'mvc/url_test/url_to_set_without_di_two_param.php'
            ]
        );
    }

    /**
     * Sets the environment
     */
    protected function setupDI()
    {
        Di::reset();
        $di = new Di();
        $that = $this;

        $di->set(
            'router',
            function () use ($that) {
                $router = new Router(false);
                $routerData = include PATH_FIXTURES . 'mvc/url_test/data_to_set_di.php';
                foreach ($routerData as $data) {
                    $that->getRouteAndSetRouteMethod($router, $data)->setName($data['setname']);
                }
                $router->removeExtraSlashes(true);

                return $router;
            }
        );

        return $di;
    }
}
