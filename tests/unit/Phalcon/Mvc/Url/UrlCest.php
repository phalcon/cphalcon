<?php
/**
 * UrlCest.php
 * \Phalcon\Url
 *
 * Tests the \Phalcon\Url component
 *
 * Phalcon Framework
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

use CodeGuy;
use Phalcon\DI as PhDI;
use Phalcon\Mvc\Router as PhRouter;
use Phalcon\Mvc\Url as PhUrl;

class UrlCest
{
    private $di;

    /**
     * Sets the environment
     */
    public function _before(CodeGuy $I)
    {
        PhDI::reset();
        $this->di = new PhDI();

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
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-04
     *
     * @param CodeGuy $I
     */
    public function testUrlBase(CodeGuy $I)
    {
        $_SERVER['PHP_SELF'] = '/index.php';

        $url = new PhUrl();

        $expected = '/';
        $actual   = $url->get();

        $I->assertEquals($expected, $actual, 'Base URL not correct');
    }

    /**
     * Tests a different url
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-04
     *
     * @param CodeGuy $I
     */
    public function testUrlOther(CodeGuy $I)
    {
        $_SERVER['PHP_SELF'] = '/index.php';

        $url = new PhUrl();

        $expected = '/classes/api/Some';
        $actual   = $url->get('classes/api/Some');

        $I->assertEquals($expected, $actual, 'Different URL not correct');
    }

    /**
     * Tests the url with a controller and action
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-04
     *
     * @param CodeGuy $I
     */
    public function testUrlForControllerAction(CodeGuy $I)
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

        $I->assertEquals($expected, $actual, 'URL with controller/action not correct');
    }

    /**
     * Tests the url with a controller
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-04
     *
     * @param CodeGuy $I
     */
    public function testUrlForController(CodeGuy $I)
    {
        $url = new PhUrl();

        $url->setDI($this->di);

        $params   = array(
            'for'   => 'classApi',
            'class' => 'Some',
        );
        $expected = '/api/classes/Some';
        $actual   = $url->get($params);

        $I->assertEquals($expected, $actual, 'URL for controller not correct');
    }

    /**
     * Tests the url with a year/month/title
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-04
     *
     * @param CodeGuy $I
     */
    public function testUrlForBlogMixedParameters(CodeGuy $I)
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

        $I->assertEquals($expected, $actual, 'URL with year/month/title not correct');
    }

    /**
     * Tests the url for a different language
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-04
     *
     * @param CodeGuy $I
     */
    public function testUrlForDifferentLanguage(CodeGuy $I)
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

        $I->assertEquals($expected, $actual, 'URL for a different language not correct');
    }

    /**
     * Tests the url with external website
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-04
     *
     * @param CodeGuy $I
     */
    public function testUrlForExternalSite(CodeGuy $I)
    {
        $url = new PhUrl();

        $url->setDI($this->di);

        $params   = array(
            'for'     => 'wikipedia',
            'article' => 'Television_news',
        );
        $expected = '/wiki/Television_news';
        $actual   = $url->get($params);

        $I->assertEquals($expected, $actual, 'URL for external site not correct');
    }
}