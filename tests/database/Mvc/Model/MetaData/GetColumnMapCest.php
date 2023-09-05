<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the
 * LICENSE.txt file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Tests\Database\Mvc\Model\MetaData;

use Codeception\Example;
use DatabaseTester;
use Phalcon\Mvc\Model\MetaData;
use Phalcon\Storage\Exception;
use Phalcon\Tests\Fixtures\Traits\DiTrait;
use Phalcon\Tests\Models\Invoices;
use Phalcon\Tests\Models\InvoicesMap;

/**
 * Class GetColumnMapCest
 */
class GetColumnMapCest
{
    use DiTrait;

    /**
     * Executed before each test
     *
     * @param  DatabaseTester $I
     * @return void
     */
    public function _before(DatabaseTester $I): void
    {
        try {
            $this->setNewFactoryDefault();
        } catch (Exception $e) {
            $I->fail($e->getMessage());
        }

        $this->setDatabase($I);
    }

    /**
     * Tests Phalcon\Mvc\Model\MetaData :: getColumnMap()
     *
     * @dataProvider getExamples
     *
     * @param DatabaseTester $I
     * @param Example $example
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-02-01
     *
     * @group  mysql
     * @group  pgsql
     * @group  sqlite
     */
    public function mvcModelMetadataGetColumnMap(
        DatabaseTester $I,
        Example $example
    ) {
        $I->wantToTest('Mvc\Model\MetaData - getColumnMap()');

        $service = $example['service'];

        $adapter = $this->newService($service);
        $adapter->setDi($this->container);
        $connection = $I->getConnection();

        $adapter->reset();

        $this->container->setShared('modelsMetadata', $adapter);

        /** @var MetaData $metadata */
        $metadata = $this->container->get('modelsMetadata');
        $model    = new Invoices();

        $I->assertNull($metadata->getColumnMap($model));

        $model    = new InvoicesMap();
        $expected = [
            'inv_id'          => 'id',
            'inv_cst_id'      => 'cst_id',
            'inv_status_flag' => 'status_flag',
            'inv_title'       => 'title',
            'inv_total'       => 'total',
            'inv_created_at'  => 'created_at',
        ];

        $I->assertEquals($expected, $metadata->getColumnMap($model));

        $I->assertTrue($adapter->isEmpty());

        /**
         * Double check it can get from cache systems and not memory
         */
        $adapter = $this->newService($service);
        $this->container->setShared('modelsMetadata', $adapter);
        $adapter->setDi($this->container);

        $I->assertNotEquals($adapter, $metadata);

        $I->assertTrue($adapter->isEmpty());

        $I->assertEquals($expected, $adapter->getColumnMap($model));
    }

    /**
     * @return array[]
     */
    private function getExamples(): array
    {
        return [
            [
                'service' => 'metadataMemory',
                'className' => 'Memory',
            ],
            [
                'service' => 'metadataApcu',
                'className' => 'Apcu',
            ],
            [
                'service' => 'metadataRedis',
                'className' => 'Redis',
            ],
            [
                'service' => 'metadataLibmemcached',
                'className' => 'Libmemcached',
            ],
        ];
    }
}
