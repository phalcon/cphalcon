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

namespace Phalcon\Tests\Database\Mvc\Model\MetaData;

use Codeception\Example;
use DatabaseTester;
use Phalcon\Mvc\Model\MetaData;
use Phalcon\Tests\Fixtures\Traits\DiTrait;
use Phalcon\Tests\Models\Invoices;

/**
 * Class GetIdentityFieldCest
 */
class GetIdentityFieldCest
{
    use DiTrait;

    public function _before(DatabaseTester $I)
    {
        $this->setNewFactoryDefault();
        $this->setDatabase($I);
    }

    /**
     * Tests Phalcon\Mvc\Model\MetaData :: getIdentityField()
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
    public function mvcModelMetadataGetIdentityField(
        DatabaseTester $I,
        Example $example
    ) {
        $I->wantToTest('Mvc\Model\MetaData - getIdentityField()');

        $service = $example['service'];

        $adapter = $this->newService($service);
        $adapter->setDi($this->container);
        $connection = $I->getConnection();

        $adapter->reset();
        $I->assertTrue($adapter->isEmpty());

        $this->container->setShared('modelsMetadata', $adapter);

        /** @var MetaData $metadata */
        $metadata = $this->container->get('modelsMetadata');

        $model    = new Invoices();
        $expected = 'inv_id';
        $actual   = $metadata->getIdentityField($model);
        $I->assertEquals($expected, $actual);

        $I->assertFalse($adapter->isEmpty());

        /**
         * Double check it can get from cache systems and not memory
         */
        $adapter = $this->newService($service);
        $this->container->setShared('modelsMetadata', $adapter);
        $adapter->setDi($this->container);

        $I->assertNotEquals($adapter, $metadata);

        $I->assertTrue($adapter->isEmpty());

        $model    = new Invoices();
        $expected = 'inv_id';
        $actual   = $adapter->getIdentityField($model);
        $I->assertEquals($expected, $actual);
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
