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

namespace Phalcon\Test\Integration\Mvc\View;

use function dataDir;
use IntegrationTester;
use Phalcon\Storage\Adapter\Stream;
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
        $this->setDiView();
    }

    /**
     * Tests Phalcon\Mvc\View :: getCache()
     *
     * @param IntegrationTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function mvcViewGetCache(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\View - getCache()');

        $view  = $this->container->get('view');
        $view->setViewsDir(dataDir('fixtures/views/'));

        $cache = $this->getAndSetViewCacheStream();
        $I->assertInstanceOf(Stream::class, $cache);

        $I->assertEquals($view, $view->cache(['key' => 'view_simple_cache']));

        $cache = $view->getCache();
        $I->assertInstanceOf(Stream::class, $cache);
    }
}
