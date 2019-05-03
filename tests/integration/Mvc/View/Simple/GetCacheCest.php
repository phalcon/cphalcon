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
use Phalcon\Storage\Adapter\Stream;
use Phalcon\Mvc\View\Simple;
use Phalcon\Test\Fixtures\Traits\DiTrait;

/**
 * Class GetCacheCest
 */
class GetCacheCest
{
    use DiTrait;

    public function _before(IntegrationTester $I)
    {
        $this->setNewFactoryDefault();
        $this->setDiViewSimple();
    }

    /**
     * Tests Phalcon\Mvc\View\Simple :: getCache()
     *
     * @param IntegrationTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function mvcViewSimpleGetCache(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\View\Simple - getCache()');


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
    }
}
