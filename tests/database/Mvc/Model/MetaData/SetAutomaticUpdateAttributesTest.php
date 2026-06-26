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
use PHPUnit\Framework\Attributes\DataProvider;
use PHPUnit\Framework\Attributes\Group;

final class SetAutomaticUpdateAttributesTest extends AbstractDatabaseTestCase
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
    public function testMvcModelMetadataSetAutomaticUpdateAttributes(
        string $service
    ): void {
        $adapter = $this->newService($service);
        $adapter->setDi($this->container);

        $adapter->reset();

        $this->container->setShared('modelsMetadata', $adapter);

        /** @var MetaData $metadata */
        $metadata = $this->container->get('modelsMetadata');

        $model = new Invoices();
        $metadata->getAttributes($model);

        $metadata->setAutomaticUpdateAttributes($model, ['inv_total' => true]);

        $this->assertEquals(
            ['inv_total' => true],
            $metadata->getAutomaticUpdateAttributes($model)
        );
    }
}
