<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Integration\Mvc\Model\Resultset;

use IntegrationTester;
use Phalcon\Mvc\Model\Resultset\Complex;
use Phalcon\Test\Fixtures\Traits\DiTrait;
use Phalcon\Test\Models\Robots;
use Phalcon\Test\Models\RobotsParts;

class ComplexCest
{
    use DiTrait;

    public function _before(IntegrationTester $I)
    {
        $this->setNewFactoryDefault();
        $this->setDiMysql();
    }

    /**
     * Work with Complex Resultset by load data from the file cache (PHQL
     * option).
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2012-12-28
     */
    public function shouldLoadResultsetFromCacheByUsingPhqlFile(IntegrationTester $I)
    {
        $cache   = $this->getAndSetModelsCacheFile();
        $manager = $this->container->get('modelsManager');

        $robots = $manager->executeQuery(
            'SELECT r.*, p.* FROM ' . Robots::class . ' r JOIN ' . RobotsParts::class . ' p '
        );

        $I->assertInstanceOf(Complex::class, $robots);
        $I->assertCount(3, $robots);
        $I->assertEquals(3, $robots->count());

        $cache->save('test-resultset', $robots);

        $I->amInPath(cacheFolder());
        $I->seeFileFound('test-resultset');

        $robots = $cache->get('test-resultset');

        $I->assertInstanceOf(Complex::class, $robots);
        $I->assertCount(3, $robots);
        $I->assertEquals(3, $robots->count());

        $cache->delete('test-resultset');
        $I->amInPath(cacheFolder());
        $I->dontSeeFileFound('test-resultset');
    }

    public function shouldLoadResultsetFromCacheByUsingPhqlLibmemcached(IntegrationTester $I)
    {
        $cache   = $this->getAndSetModelsCacheFileLibmemcached();
        $manager = $this->container->get('modelsManager');

        $robots = $manager->executeQuery(
            'SELECT r.*, p.* FROM ' . Robots::class . ' r JOIN ' . RobotsParts::class . ' p '
        );

        $I->assertInstanceOf(Complex::class, $robots);
        $I->assertCount(3, $robots);
        $I->assertEquals(3, $robots->count());

        $cache->save('test-resultset', $robots);

        $robots = $cache->get('test-resultset');

        $I->assertInstanceOf(Complex::class, $robots);
        $I->assertCount(3, $robots);
        $I->assertEquals(3, $robots->count());

        $cache->delete('test-resultset');
    }
}
