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

namespace Phalcon\Tests\Database\Mvc\Model\MetaData\Memory;

use PDO;
use Phalcon\Mvc\Model\MetaData\Memory;
use Phalcon\Storage\Exception;
use Phalcon\Tests\AbstractDatabaseTestCase;
use Phalcon\Tests\Support\Migrations\InvoicesMigration;
use Phalcon\Tests\Support\Models\Invoices;
use Phalcon\Tests\Support\Models\Robotto;
use Phalcon\Tests\Support\Traits\DiTrait;

/**
 *
 * @group phql
 */
final class ConstructTest extends AbstractDatabaseTestCase
{
    use DiTrait;

    /**
     * @return void
     */
    public function setUp(): void
    {
        try {
            $this->setNewFactoryDefault();
        } catch (Exception $e) {
            $this->fail($e->getMessage());
        }

        $this->setDatabase();

        $this->container->setShared(
            'modelsMetadata',
            function () {
                return new Memory();
            }
        );

        /** @var PDO $connection */
        $connection = self::getConnection();
        $migration  = new InvoicesMigration($connection);
        $migration->insert(1, 1, 0, 'Test Invoice');
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     *
     * @group mysql
     * @group pgsql
     * @group sqlite
     */
    public function testMvcModelMetadataMemoryConstruct(): void
    {
        /** @var \Phalcon\Mvc\Model\MetaDataInterface $md */
        $md = $this->container->getShared('modelsMetadata');

        $md->reset();
        $this->assertTrue($md->isEmpty());

        Invoices::findFirst();

        $this->assertFalse($md->isEmpty());

        $md->reset();
        $this->assertTrue($md->isEmpty());
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     *
     * @group mysql
     * @group pgsql
     * @group sqlite
     */
    public function testMvcModelMetadataMemoryConstructManual(): void
    {
        $metaData = $this->container->getShared('modelsMetadata');
        $robotto  = new Robotto();

        $this->assertSame(
            ['id', 'name', 'type', 'year'],
            $metaData->getAttributes($robotto)
        );
        $this->assertSame(
            ['id'],
            $metaData->getPrimaryKeyAttributes($robotto)
        );
        $this->assertSame(
            ['name', 'type', 'year'],
            $metaData->getNonPrimaryKeyAttributes($robotto)
        );
        $this->assertSame('id', $metaData->getIdentityField($robotto));
    }
}
