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

use Phalcon\Mvc\Model\MetaData;
use Phalcon\Tests\AbstractDatabaseTestCase;
use Phalcon\Tests\Support\Models\Invoices;
use Phalcon\Tests\Support\Traits\DiTrait;

final class GetDataTypesTest extends AbstractDatabaseTestCase
{
    use DiTrait;

    /**
     * @return array[]
     */
    public static function getExamples(): array
    {
        return [
            [
                'metadataMemory',
            ],
            [
                'metadataApcu',
            ],
            [
                'metadataRedis',
            ],
            [
                'metadataLibmemcached',
            ],
        ];
    }

    public function setUp(): void
    {
        $this->setNewFactoryDefault();
        $this->setDatabase();
    }

    /**
     * @dataProvider getExamples
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2020-02-01
     *
     * @group mysql
     */
    public function testMvcModelMetadataGetDataTypes(
        string $service
    ): void {
        $adapter = $this->newService($service);
        $adapter->setDi($this->container);
        $connection = self::getConnection();

        $adapter->reset();
        $this->assertTrue($adapter->isEmpty());

        $this->container->setShared('modelsMetadata', $adapter);

        /** @var MetaData $metadata */
        $metadata = $this->container->get('modelsMetadata');

        $model    = new Invoices();
        $expected = $this->getTypes();
        $actual   = $metadata->getDataTypes($model);
        $this->assertEquals($expected, $actual);

        $this->assertFalse($adapter->isEmpty());

        /**
         * Double check it can get from cache systems and not memory
         */
        $adapter = $this->newService($service);
        $this->container->setShared('modelsMetadata', $adapter);
        $adapter->setDi($this->container);

        $this->assertNotEquals($adapter, $metadata);

        $this->assertTrue($adapter->isEmpty());

        $actual = $adapter->getDataTypes($model);
        $this->assertEquals($expected, $actual);
    }

    private function getTypes(): array
    {
        $driver = self::getDriver();
        switch ($driver) {
            case 'mysql':
                return [
                    'inv_id'          => 0,
                    'inv_cst_id'      => 0,
                    'inv_status_flag' => 26,
                    'inv_title'       => 2,
                    'inv_total'       => 7,
                    'inv_created_at'  => 4,
                ];
            case 'sqlite':
                return [
                    'inv_id'          => 0,
                    'inv_cst_id'      => 0,
                    'inv_status_flag' => 0,
                    'inv_title'       => 2,
                    'inv_total'       => 2,
                    'inv_created_at'  => 2,
                ];
            default:
                return [
                    'inv_id'          => 0,
                    'inv_cst_id'      => 0,
                    'inv_status_flag' => 22,
                    'inv_title'       => 2,
                    'inv_total'       => 3,
                    'inv_created_at'  => 17,
                ];
        }
    }
}
