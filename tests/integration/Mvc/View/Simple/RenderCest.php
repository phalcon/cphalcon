<?php
declare(strict_types=1);

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Integration\Mvc\View\Simple;

use IntegrationTester;
use Phalcon\Mvc\View\Simple;
use Phalcon\Storage\Adapter\Stream;
use Phalcon\Test\Fixtures\Traits\DiTrait;
use function cacheModelsDir;
use function dataDir;
use function file_get_contents;
use function json_decode;

class RenderCest
{
    use DiTrait;

    public function _before(IntegrationTester $I)
    {
        $this->newDi();
        $this->setDiViewSimple();
    }

    /**
     * Tests render
     *
     * @author Kamil Skowron <git@hedonsoftware.com>
     * @since  2014-05-28
     */
    public function testRender(IntegrationTester $I)
    {
        $view = $this->container->get('viewSimple');

        $I->assertEquals(
            'here',
            $view->render('currentrender/other')
        );
    }

    /**
     * Tests render
     *
     * @author Kamil Skowron <git@hedonsoftware.com>
     * @since  2014-05-28
     */
    public function testRenderStandard(IntegrationTester $I)
    {
        $view = $this->container->get('viewSimple');

        $I->assertEquals(
            'We are here',
            $view->render('simple/index')
        );

        $I->assertEquals(
            'We are here',
            $view->getContent()
        );
    }
    /**
     * Tests Phalcon\Mvc\View\Simple :: render()
     *
     * @param IntegrationTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function mvcViewSimpleRender(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\View\Simple - render()');

        $class = Stream::class;
        $cache = $this->getAndSetViewCacheStream();
        $I->assertInstanceOf($class, $cache);

        $view = new Simple();
        $view->setViewsDir(dataDir('fixtures/views/'));

        // No cache before DI is set
        $I->assertFalse($view->getCache());

        $view->setDI($this->container);
        $I->assertEquals($view, $view->cache(['key' => 'view_simple_cache']));

        $cache = $view->getCache();
        $I->assertInstanceOf(Stream::class, $cache);

        $timeNow = time();
        $view->setParamToView('a_cool_var', $timeNow);

        $I->assertEquals(
            "<p>$timeNow</p>",
            rtrim($view->render('currentrender/coolVar'))
        );

        $file     = cacheModelsDir('phstrm-/vi/ew/_s/im/pl/e_/ca/c/view_simple_cache');
        $contents = file_get_contents($file);
        $contents = json_decode($contents, true);
        $I->assertEquals("<p>$timeNow</p>", rtrim(unserialize($contents["content"])));

        $I->safeDeleteFile($file);
        $I->dontSeeFileFound($file);

    }
}
