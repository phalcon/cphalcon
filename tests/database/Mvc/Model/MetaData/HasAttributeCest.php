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
 * Class HasAttributeCest
 */
class HasAttributeCest
{
    use DiTrait;

    public function _before(DatabaseTester $I)
    {
        $this->setNewFactoryDefault();
        $this->setDatabase($I);
    }

 /**
     * Tests Phalcon\Mvc\Model\MetaData :: hasAttribute()
     *
     * @dataProvider getExamples
     *
     * @param DatabaseTester $I
     * @param Example $example
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     *
     * @group  mysql
     * @group  pgsql
     * @group  sqlite
     */
    public function mvcModelMetadataHasAttribute(
        DatabaseTester $I,
        Example $example
    ) {
        $I->wantToTest('Mvc\Model\MetaData - hasAttribute()');

        $service = $example['service'];

        $adapter = $this->newService($service);
        $adapter->setDi($this->container);
        $connection = $I->getConnection();

        $adapter->reset();

        $this->container->setShared('modelsMetadata', $adapter);
        /** @var MetaData $metadata */
        $metadata = $this->container->get('modelsMetadata');

        $model = new Invoices();
        $I->assertTrue($metadata->hasAttribute($model, 'inv_id'));
        $I->assertTrue($metadata->hasAttribute($model, 'inv_cst_id'));
        $I->assertTrue($metadata->hasAttribute($model, 'inv_status_flag'));
        $I->assertTrue($metadata->hasAttribute($model, 'inv_title'));
        $I->assertTrue($metadata->hasAttribute($model, 'inv_total'));
        $I->assertTrue($metadata->hasAttribute($model, 'inv_created_at'));

        $I->assertFalse($metadata->hasAttribute($model, 'unknown'));
        $I->assertFalse($adapter->isEmpty());

        /**
         * Double check it can get from cache systems and not memory
         */
        $adapter = $this->newService($service);
        $this->container->setShared('modelsMetadata', $adapter);
        $adapter->setDi($this->container);

        $I->assertNotEquals($adapter, $metadata);

        $I->assertTrue($adapter->isEmpty());

        $I->assertTrue($adapter->hasAttribute($model, 'inv_id'));
        $I->assertTrue($adapter->hasAttribute($model, 'inv_cst_id'));
        $I->assertTrue($adapter->hasAttribute($model, 'inv_status_flag'));
        $I->assertTrue($adapter->hasAttribute($model, 'inv_title'));
        $I->assertTrue($adapter->hasAttribute($model, 'inv_total'));
        $I->assertTrue($adapter->hasAttribute($model, 'inv_created_at'));

        $I->assertFalse($adapter->hasAttribute($model, 'unknown'));
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
