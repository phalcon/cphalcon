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

namespace Phalcon\Test\Integration\Mvc\Model\Resultset\Simple;

use function cacheFolder;
use IntegrationTester;
use Phalcon\Mvc\Model\Resultset\Simple;
use Phalcon\Test\Fixtures\Traits\DiTrait;
use Phalcon\Test\Models\Robots;

/**
 * Class ConstructCest
 */
class ConstructCest
{
    use DiTrait;

    /**
     * @param IntegrationTester $I
     */
    public function _before(IntegrationTester $I)
    {
        $this->setNewFactoryDefault();
        $this->setDiMysql();
        $I->cleanDir(cacheFolder());
    }

    /**
     * Tests Phalcon\Mvc\Model\Resultset\Simple :: __construct()
     *
     * @param IntegrationTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function mvcModelResultsetSimpleConstruct(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\Model\Resultset\Simple - __construct()');

        $cache   = $this->getAndSetModelsCacheStream();
        $manager = $this->getService('modelsManager');

        $robots = $manager->executeQuery('SELECT * FROM ' . Robots::class);

        $I->assertInstanceOf(Simple::class, $robots);

        $I->assertCount(3, $robots);
        $I->assertEquals($robots->count(), 3);

        $cache->set('test-resultset', $robots);

        $I->amInPath(cacheFolder());
        $I->seeFileFound('test-resultset');

        $robots = $cache->get('test-resultset');

        $I->assertInstanceOf(Simple::class, $robots);
        $I->assertCount(3, $robots);
        $I->assertEquals($robots->count(), 3);
        $cache->delete('test-resultset');

        $I->amInPath(cacheFolder());
        $I->dontSeeFileFound('test-resultset');
    }
}
