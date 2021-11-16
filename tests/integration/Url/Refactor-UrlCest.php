<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Tests\Url;

use Codeception\Example;
use IntegrationTester;
use Phalcon\Mvc\Router;
use Phalcon\Tests\Fixtures\Traits\DiTrait;
use Phalcon\Tests\Fixtures\Traits\RouterTrait;

class UrlCest
{
    use DiTrait;
    use RouterTrait;

    /**
     * executed before each test
     */
    public function _before()
    {
        $this->newDi();
        $this->setDiService('url');
        $this->setupRoutes();
    }

    /**
     * Depends on the RouterTrait
     */
    private function setupRoutes()
    {
        $container  = $this->getDi();
        $router     = new Router(false);
        $routerData = $this->getDataToSetDi();

        foreach ($routerData as $data) {
            $this->getRouteAndSetRouteMethod($router, $data)->setName($data['setname']);
        }

        $router->removeExtraSlashes(true);

        $container->set('router', $router);
    }

    private function getDataToSetDi(): array
    {
        return [
            [
                '/admin/:controller/p/:action',
                [
                    'controller' => 1,
                    'action'     => 2,
                ],
                'methodName' => 'add',
                'setname'    => 'adminProducts',
            ],
            [
                '/api/classes/{class}',
                'methodName' => 'add',
                'setname'    => 'classApi',
            ],
            [
                '/{year}/{month}/{title}',
                'methodName' => 'add',
                'setname'    => 'blogPost',
            ],
            [
                '/wiki/{article:[a-z]+}',
                'methodName' => 'add',
                'setname'    => 'wikipedia',
            ],
            [
                '/news/{country:[a-z]{2}}/([a-z+])/([a-z\-+])/{page}',
                [
                    'section' => 2,
                    'article' => 3,
                ],
                'methodName' => 'add',
                'setname'    => 'news',
            ],
            [
                '/([a-z]{2})/([a-zA-Z0-9_-]+)(/|)',
                [
                    'lang'       => 1,
                    'module'     => 'main',
                    'controller' => 2,
                    'action'     => 'index',
                ],
                'methodName' => 'add',
                'setname'    => 'lang-controller',
            ],
        ];
    }

    /**
     * Tests the base url
     *
     * @author       Nikolaos Dimopoulos <nikos@phalcon.io>
     * @since        2014-09-04
     *
     * @dataProvider getUrlToSetServer
     */
    public function shouldGetCorrectUrlWithServer(IntegrationTester $I, Example $example)
    {
        $params = $example['params'];

        $_SERVER['PHP_SELF'] = $params['server_php_self'];

        $url = $this->getService('url');

        $actual = $url->get(
            $params['get']
        );

        $I->assertEquals(
            $example['expected'],
            $actual
        );
    }

    private function getUrlToSetServer(): array
    {
        return [
            //Tests the base url
            [
                'params'   => [
                    'server_php_self' => '/index.php',
                    'get'             => null,
                ],
                'expected' => '/',
            ],

            //Tests a different url
            [
                'params'   => [
                    'server_php_self' => '/index.php',
                    'get'             => 'classes/api/Some',
                ],
                'expected' => '/classes/api/Some',
            ],
        ];
    }
}
