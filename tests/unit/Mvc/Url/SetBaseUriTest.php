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

namespace Phalcon\Tests\Unit\Mvc\Url;

use Phalcon\Mvc\Router;
use Phalcon\Tests\AbstractUnitTestCase;
use Phalcon\Tests\Support\Traits\DiTrait;
use Phalcon\Tests\Unit\Mvc\Fake\RouterTrait;

final class SetBaseUriTest extends AbstractUnitTestCase
{
    use DiTrait;
    use RouterTrait;

    /**
     * @return array
     */
    public static function getDataToSetDi(): array
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
     * @return array[]
     */
    public static function getUrlToSetBaseUri(): array
    {
        return [
            // Tests the url with a controller and action
            [
                '/',
                [
                    'for'        => 'adminProducts',
                    'controller' => 'products',
                    'action'     => 'index',
                ],
                '/admin/products/p/index',
            ],

            // Tests the url with a controller
            [
                '/',
                [
                    'for'   => 'classApi',
                    'class' => 'Some',
                ],
                '/api/classes/Some',
            ],

            // Tests the url with a year/month/title
            [
                '/',
                [
                    'for'        => 'lang-controller',
                    'lang'       => 'de',
                    'controller' => 'index',
                ],
                '/de/index',
            ],

            // Tests the url for a different language
            [
                '/',
                [
                    'for'   => 'blogPost',
                    'year'  => '2010',
                    'month' => '10',
                    'title' => 'cloudflare-anade-recursos-a-tu-servidor',
                ],
                '/2010/10/cloudflare-anade-recursos-a-tu-servidor',
            ],

            // Tests the url with external website
            [
                '/',
                [
                    'for'     => 'wikipedia',
                    'article' => 'Television_news',
                ],
                '/wiki/Television_news',
            ],
        ];
    }

    /**
     * @return array
     */
    public static function getUrlToSetServer(): array
    {
        return [
            //Tests the base url
            [
                '/index.php',
                null,
                '/',
            ],
            //Tests a different url
            [
                '/index.php',
                'classes/api/Some',
                '/classes/api/Some',
            ],
        ];
    }

    /**
     * @return array[]
     */
    public static function getUrlToSetWithoutDi(): array
    {
        return [
            [
                'https://www.test.com',
                '',
                'https://www.test.com',
            ],
            [
                'https://www.test.com',
                '/',
                'https://www.test.com/',
            ],
            [
                'https://www.test.com',
                '/path',
                'https://www.test.com/path',
            ],
            //Test urls that contains colons in schema definition and as parameter
            [
                'https://www.test.com',
                '/controller/action/param/colon:param',
                'https://www.test.com/controller/action/param/colon:param',
            ],
            [
                'base_url\' => \'https://www.test.com',
                'https://www.example.com',
                'https://www.example.com',
            ],
            [
                'base_url\' => \'https://www.test.com',
                '//www.example.com',
                '//www.example.com',
            ],
            [
                'base_url\' => \'https://www.test.com',
                'schema:example.com',
                'schema:example.com',
            ],
        ];
    }

    /**
     * @return array[]
     */
    public static function getUrlToSetWithoutDiTwoParam(): array
    {
        return [
            [
                'https://www.test.com/?_url=/',
                'path',
                ['params' => 'one'],
                'https://www.test.com/?_url=/path&params=one',
            ],
        ];
    }

    /**
     * executed before each test
     */
    public function setUp(): void
    {
        $this->newDi();
        $this->setDiService('url');
        $this->setupRoutes();
    }

    /**
     * @dataProvider getUrlToSetServer
     *
     * @author       Nikolaos Dimopoulos <nikos@phalcon.io>
     * @since        2014-09-04
     */
    public function shouldGetCorrectUrlWithServer(
        string $phpSelf,
        string $name,
        string $expected
    ): void {
        $store = $_SERVER;

        $_SERVER['PHP_SELF'] = $phpSelf;
        $url                 = $this->getService('url');

        $actual = $url->get($name);

        $this->assertEquals($expected, $actual);
    }

    /**
     * @dataProvider getUrlToSetWithoutDi
     *
     * @issue  https://github.com/phalcon/cphalcon/issues/3315
     * @author       Olivier Monaco <olivier.monaco@nospam.free.fr>
     * @since        2015-02-03
     */
    public function testMvcUrlGetCorrectUrl(
        string $baseUrl,
        string $name,
        string $expected
    ): void {
        $url = $this->getService('url');

        $url->setBaseUri($baseUrl);
        $actual = $url->get($name);

        $this->assertEquals($expected, $actual);
    }

    /**
     * @dataProvider getUrlToSetWithoutDiTwoParam
     *
     * @issue        @3315
     * @author       Olivier Monaco <olivier.monaco@nospam.free.fr>
     * @since        2015-02-03
     */
    public function testMvcUrlGetCorrectUrlWithGetParam(
        string $baseUrl,
        string $name,
        array $params,
        string $expected
    ): void {
        $url = $this->getService('url');

        $url->setBaseUri($baseUrl);

        $actual = $url->get($name, $params);

        $this->assertEquals($expected, $actual);
    }

    /**
     * @dataProvider getUrlToSetBaseUri
     *
     * @author       Nikolaos Dimopoulos <nikos@phalcon.io>
     * @since        2014-09-04
     */
    public function testMvcUrlSetBaseUri(
        string $baseUri,
        array $param,
        string $expected
    ): void {
        $url = $this->getService('url');

        $url->setBaseUri($baseUri);
        $actual = $url->get($param);

        $this->assertEquals($expected, $actual);
    }

    /**
     * Depends on the RouterTrait
     */
    private function setupRoutes()
    {
        $router     = new Router(false);
        $routerData = $this->getDataToSetDi();

        foreach ($routerData as $data) {
            $this->getRouteAndSetRouteMethod($router, $data)->setName($data['setname']);
        }

        $router->removeExtraSlashes(true);

        $this->container->set('router', $router);
    }
}
