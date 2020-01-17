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
use Phalcon\Test\Fixtures\Migrations\InvoicesMigration;
use Phalcon\Test\Fixtures\Traits\DiTrait;
use Phalcon\Test\Models\Invoices;

use function cacheModelsDir;

class ConstructCest
{
    use DiTrait;

    public function _before(IntegrationTester $I)
    {
        $this->setNewFactoryDefault();
        $this->setDiMysql();

        $I->cleanDir(cacheModelsDir());
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

        $migration = new InvoicesMigration($this->container->get('db'));
        $migration->create();

        /**
         * Insert 5 records
         */
        $migration->insert(1, 1, 1, "title 1", 100.00, "2019-12-25 01:02:03");
        $migration->insert(2, 1, 1, "title 2", 200.00, "2019-12-25 01:02:03");
        $migration->insert(3, 1, 1, "title 3", 300.00, "2019-12-25 01:02:03");
        $migration->insert(4, 1, 1, "title 4", 400.00, "2019-12-25 01:02:03");
        $migration->insert(5, 1, 1, "title 5", 500.00, "2019-12-25 01:02:03");

        $cache   = $this->getAndSetModelsCacheStream();
        $manager = $this->getService('modelsManager');

        $filePath = cacheModelsDir() . 'ph-strm/' . Str::dirFromFile('test-resultset');

        $invoices = $manager->executeQuery('SELECT * FROM ' . Invoices::class);

        $I->assertInstanceOf(Simple::class, $invoices);

        $I->assertCount(5, $invoices);
        $I->assertEquals(5, $invoices->count());

        $cache->set('test-resultset', $invoices);

        $I->seeFileFound('test-resultset', $filePath);

        $invoices = $cache->get('test-resultset');

        $I->assertInstanceOf(Simple::class, $invoices);
        $I->assertCount(5, $invoices);
        $I->assertEquals(5, $invoices->count());

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

        $migration->drop();
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

        $migration = new InvoicesMigration($this->container->get('db'));
        $migration->create();

        /**
         * Insert 5 records
         */
        $migration->insert(1, 1, 1, "title 1", 100.00, "2019-12-25 01:02:03");
        $migration->insert(2, 1, 1, "title 2", 200.00, "2019-12-25 01:02:03");
        $migration->insert(3, 1, 1, "title 3", 300.00, "2019-12-25 01:02:03");
        $migration->insert(4, 1, 1, "title 4", 400.00, "2019-12-25 01:02:03");
        $migration->insert(5, 1, 1, "title 5", 500.00, "2019-12-25 01:02:03");

        $cache   = $this->getAndSetModelsCacheStream();
        $manager = $this->getService('modelsManager');

        $filePath = cacheModelsDir() . 'ph-strm/' . Str::dirFromFile('test-resultset');

        $invoices = $manager->executeQuery('SELECT inv_id FROM ' . Invoices::class);

        $I->assertInstanceOf(Simple::class, $invoices);
        $I->assertCount(5, $invoices);
        $I->assertEquals(5, $invoices->count());

        $cache->set('test-resultset', $invoices);

        $I->seeFileFound('test-resultset', $filePath);

        $invoices = $cache->get('test-resultset');

        $I->assertInstanceOf(Simple::class, $invoices);
        $I->assertCount(5, $invoices);
        $I->assertEquals(5, $invoices->count());

        $cache->delete('test-resultset');

        $I->dontSeeFileFound('test-resultset', $filePath);
    }
}
