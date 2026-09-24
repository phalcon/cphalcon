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
use Phalcon\Tests\Support\Migrations\InvoicesMigration;
use Phalcon\Tests\Support\Models\Invoices;
use Phalcon\Tests\Support\Traits\DiTrait;
use PHPUnit\Framework\Attributes\DataProvider;
use PHPUnit\Framework\Attributes\Group;

use function strtolower;

final class ReadMetaDataTest extends AbstractDatabaseTestCase
{
    use DiTrait;

    public function setUp(): void
    {
        $this->setNewFactoryDefault();
        $this->setDatabase();

        (new InvoicesMigration(self::getPdoConnection()))->clear();
    }

    /**
     * @return array[]
     */
    public static function getExamples(): array
    {
        return [
            ['metadataMemory'],
            ['metadataApcu'],
            ['metadataRedis'],
            ['metadataLibmemcached'],
            ['metadataStream'],
        ];
    }

    /**
     * @return array[]
     */
    public static function getExamplesInvalidCache(): array
    {
        return [
            ['metadataApcu'],
            ['metadataRedis'],
            ['metadataLibmemcached'],
        ];
    }

    /**
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2020-02-01
     */
    #[Group('mysql')]
    #[Group('pgsql')]
    #[Group('sqlite')]
    #[DataProvider('getExamples')]
    public function testMvcModelMetadataReadMetaData(
        string $service
    ): void {
        $adapter = $this->newService($service);
        $adapter->setDi($this->container);

        $adapter->reset();

        $this->container->setShared('modelsMetadata', $adapter);

        /** @var MetaData $metadata */
        $metadata = $this->container->get('modelsMetadata');

        $model  = new Invoices();
        $result = $metadata->readMetaData($model);

        $this->assertIsArray($result);
        $this->assertEquals(
            ['inv_id'],
            $result[MetaData::MODELS_PRIMARY_KEY]
        );
    }

    /**
     * A cached value that is not an array is a cache miss. The meta-data
     * is read again from the database.
     *
     * @issue  https://github.com/phalcon/cphalcon/issues/17608
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-09-24
     */
    #[Group('mysql')]
    #[Group('pgsql')]
    #[Group('sqlite')]
    #[DataProvider('getExamplesInvalidCache')]
    public function testMvcModelMetadataReadMetaDataInvalidCache(
        string $service
    ): void {
        $adapter = $this->newService($service);
        $adapter->setDi($this->container);

        $adapter->reset();

        $key = strtolower(Invoices::class);
        $adapter->getAdapter()->set('meta-' . $key, 1);
        $adapter->getAdapter()->set('map-' . $key, 1);

        $this->container->setShared('modelsMetadata', $adapter);

        /** @var MetaData $metadata */
        $metadata = $this->container->get('modelsMetadata');

        $model  = new Invoices();
        $result = $metadata->readMetaData($model);

        $this->assertIsArray($result);
        $this->assertEquals(
            ['inv_id'],
            $result[MetaData::MODELS_PRIMARY_KEY]
        );
        $this->assertIsArray($metadata->readColumnMap($model));
    }
}
