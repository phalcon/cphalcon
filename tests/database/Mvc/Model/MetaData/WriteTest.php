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
use Phalcon\Tests\Support\Traits\DiTrait;
use PHPUnit\Framework\Attributes\DataProvider;
use PHPUnit\Framework\Attributes\Group;

final class WriteTest extends AbstractDatabaseTestCase
{
    use DiTrait;

    public function setUp(): void
    {
        $this->setNewFactoryDefault();
        $this->setDatabase();
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
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2020-02-01
     */
    #[Group('mysql')]
    #[Group('pgsql')]
    #[Group('sqlite')]
    #[DataProvider('getExamples')]
    public function testMvcModelMetadataWrite(
        string $service
    ): void {
        $adapter = $this->newService($service);
        $adapter->setDi($this->container);

        $adapter->reset();

        $this->container->setShared('modelsMetadata', $adapter);

        /** @var MetaData $metadata */
        $metadata = $this->container->get('modelsMetadata');

        // write() persists the data to the underlying adapter
        $metadata->write('test-metadata-key', ['key' => 'value']);

        $result = $metadata->read('test-metadata-key');

        if ('metadataMemory' === $service) {
            // The Memory adapter keeps data only in temporal memory; its
            // write() is a no-op so nothing is persisted.
            $this->assertNull($result);

            return;
        }

        $this->assertEquals(['key' => 'value'], $result);
    }
}
