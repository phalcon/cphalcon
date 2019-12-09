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

namespace Phalcon\Test\Integration\Mvc\Model\Resultset\Simple;

use IntegrationTester;
use Phalcon\Helper\Str;
use Phalcon\Mvc\Model\Resultset\Simple;
use Phalcon\Test\Fixtures\Traits\DiTrait;
use Phalcon\Test\Models\Robots;

use function cacheModelsDir;

class ConstructCest
{
    use DiTrait;

    public function _before(IntegrationTester $I)
    {
        $this->setNewFactoryDefault();
        $this->setDiMysql();

        $I->cleanDir(
            cacheModelsDir()
        );
    }

    public function _after(IntegrationTester $I)
    {
        $this->container['db']->close();
    }

    /**
     * Tests Phalcon\Mvc\Model\Resultset\Simple :: __construct()
     * Work with Simple Resultset by load data from the file cache (complete
     * PHQL option).
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-04-27
     */
    public function mvcModelResultsetSimpleConstructCompletePhql(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\Model\Resultset\Simple - __construct() - complete PHQL');

        $cache   = $this->getAndSetModelsCacheStream();
        $manager = $this->getService('modelsManager');

        $filePath = cacheModelsDir() . 'phstrm-/' . Str::dirFromFile('test-resultset');

        $robots = $manager->executeQuery('SELECT * FROM ' . Robots::class);

        $I->assertInstanceOf(Simple::class, $robots);

        $I->assertCount(6, $robots);
        $I->assertEquals(6, $robots->count());

        $cache->set('test-resultset', $robots);

        $I->seeFileFound('test-resultset', $filePath);

        $robots = $cache->get('test-resultset');

        $I->assertInstanceOf(Simple::class, $robots);
        $I->assertCount(6, $robots);
        $I->assertEquals(6, $robots->count());

        $I->assertTrue(
            $cache->clear()
        );

        $I->amInPath(
            cacheModelsDir()
        );

        $I->dontSeeFileFound(
            'test-resultset',
            $filePath
        );
    }

    /**
     * Tests Phalcon\Mvc\Model\Resultset\Simple :: __construct()
     * Work with Simple Resultset by load data from the file cache (incomplete
     * PHQL option).
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-04-27
     */
    public function mvcModelResultsetSimpleConstructIncompletePhql(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\Model\Resultset\Simple - __construct() - incomplete PHQL');

        $cache   = $this->getAndSetModelsCacheStream();
        $manager = $this->getService('modelsManager');

        $filePath = cacheModelsDir() . 'phstrm-/' . Str::dirFromFile('test-resultset');

        $robots = $manager->executeQuery('SELECT id FROM ' . Robots::class);

        $I->assertInstanceOf(Simple::class, $robots);
        $I->assertCount(6, $robots);
        $I->assertEquals(6, $robots->count());

        $cache->set('test-resultset', $robots);

        $I->seeFileFound('test-resultset', $filePath);

        $robots = $cache->get('test-resultset');

        $I->assertInstanceOf(Simple::class, $robots);
        $I->assertCount(6, $robots);
        $I->assertEquals(6, $robots->count());

        $cache->delete('test-resultset');

        $I->dontSeeFileFound('test-resultset', $filePath);
    }
}
