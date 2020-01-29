<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Test\Integration\Url;

use Codeception\Example;
use IntegrationTester;
use Phalcon\Mvc\Router;
use Phalcon\Test\Fixtures\Traits\DiTrait;
use Phalcon\Test\Fixtures\Traits\RouterTrait;

/**
 * Class SetBaseUriCest
 */
class SetBaseUriCest
{
    use DiTrait;
    use RouterTrait;

    /**
     * executed before each test
     */
    public function _before()
    {
        $this->newDi();
        $this->setDiUrl();
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
     * Tests the url with a controller and action
     *
     * @author       Nikolaos Dimopoulos <nikos@phalcon.io>
     * @since        2014-09-04
     *
     * @dataProvider getUrlToSetBaseUri
     */
    public function shouldCorrectSetBaseUri(IntegrationTester $I, Example $example)
    {
        $url = $this->getService('url');

        $url->setBaseUri(
            $example['base_url']
        );

        $actual = $url->get(
            $example['param']
        );

        $I->assertEquals(
            $example['expected'],
            $actual
        );
    }

    /**
     * Tests the url with a controller and action
     *
     * @author       Olivier Monaco <olivier.monaco@nospam.free.fr>
     * @since        2015-02-03
     * @issue  https://github.com/phalcon/cphalcon/issues/3315
     *
     * @dataProvider getUrlToSetWithoutDi
     */
    public function shouldGetCorrectUrl(IntegrationTester $I, Example $example)
    {
        $params   = $example[0];
        $expected = $example[1];

        $url = $this->getService('url');

        $url->setBaseUri(
            $params['base_url']
        );

        $actual = $url->get(
            $params['get']
        );

        $I->assertEquals($expected, $actual);
    }

    /**
     * Test should avoid double slash when joining baseUri to provided uri
     *
     * @author       Olivier Monaco <olivier.monaco@nospam.free.fr>
     * @since        2015-02-03
     * @issue  https://github.com/phalcon/cphalcon/issues/3315
     *
     * @dataProvider getUrlToSetWithoutDiTwoParam
     */
    public function shouldGetCorrectUrlWithGetParam(IntegrationTester $I, Example $example)
    {
        $params   = $example[0];
        $expected = $example[1];

        $url = $this->getService('url');

        $url->setBaseUri(
            $params['base_url']
        );

        $actual = $url->get(
            $params['get'],
            $params['second_get']
        );

        $I->assertEquals($expected, $actual);
    }

    private function getUrlToSetBaseUri(): array
    {
        return [
            // Tests the url with a controller and action
            [
                'base_url' => '/',
                'param'    => [
                    'for'        => 'adminProducts',
                    'controller' => 'products',
                    'action'     => 'index',
                ],
                'expected' => '/admin/products/p/index',
            ],

            // Tests the url with a controller
            [
                'base_url' => '/',
                'param'    => [
                    'for'   => 'classApi',
                    'class' => 'Some',
                ],
                'expected' => '/api/classes/Some',
            ],

            // Tests the url with a year/month/title
            [
                'base_url' => '/',
                'param'    => [
                    'for'        => 'lang-controller',
                    'lang'       => 'de',
                    'controller' => 'index',
                ],
                'expected' => '/de/index',
            ],

            // Tests the url for a different language
            [
                'base_url' => '/',
                'param'    => [
                    'for'   => 'blogPost',
                    'year'  => '2010',
                    'month' => '10',
                    'title' => 'cloudflare-anade-recursos-a-tu-servidor',
                ],
                'expected' => '/2010/10/cloudflare-anade-recursos-a-tu-servidor',
            ],

            // Tests the url with external website
            [
                'base_url' => '/',
                'param'    => [
                    'for'     => 'wikipedia',
                    'article' => 'Television_news',
                ],
                'expected' => '/wiki/Television_news',
            ],
        ];
    }

    private function getUrlToSetWithoutDi(): array
    {
        return [
            [
                [
                    'base_url' => 'http://www.test.com',
                    'get'      => '',
                ],
                'http://www.test.com',
            ],
            [
                [
                    'base_url' => 'http://www.test.com',
                    'get'      => '/',
                ],
                'http://www.test.com/',
            ],
            [
                [
                    'base_url' => 'http://www.test.com',
                    'get'      => '/path',
                ],
                'http://www.test.com/path',
            ],
            //Test urls that contains colons in schema definition and as parameter
            [
                [
                    'base_url' => 'http://www.test.com',
                    'get'      => '/controller/action/param/colon:param',
                ],
                'http://www.test.com/controller/action/param/colon:param',
            ],
            [
                [
                    'base_url' => 'base_url\' => \'http://www.test.com',
                    'get'      => 'http://www.example.com',
                ],
                'http://www.example.com',
            ],
            [
                [
                    'base_url' => 'base_url\' => \'http://www.test.com',
                    'get'      => '//www.example.com',
                ],
                '//www.example.com',
            ],
            [
                [
                    'base_url' => 'base_url\' => \'http://www.test.com',
                    'get'      => 'schema:example.com',
                ],
                'schema:example.com',
            ],
        ];
    }

    private function getUrlToSetWithoutDiTwoParam(): array
    {
        return [
            [
                [
                    'base_url'   => 'http://www.test.com/?_url=/',
                    'get'        => 'path',
                    'second_get' => ['params' => 'one'],
                ],
                'http://www.test.com/?_url=/path&params=one',
            ],
        ];
    }
}
