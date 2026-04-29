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

namespace Phalcon\Tests\Database\Mvc\Model\MetaData\Libmemcached;

use PDO;
use Phalcon\Cache\AdapterFactory;
use Phalcon\Mvc\Model\MetaData\Libmemcached;
use Phalcon\Storage\Exception;
use Phalcon\Storage\SerializerFactory;
use Phalcon\Tests\AbstractDatabaseTestCase;
use Phalcon\Tests\Support\Migrations\InvoicesMigration;
use Phalcon\Tests\Support\Models\Invoices;
use Phalcon\Tests\Support\Traits\DiTrait;

use function getOptionsLibmemcached;

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
        $this->checkExtensionIsLoaded('memcached');

        try {
            $this->setNewFactoryDefault();
        } catch (Exception $e) {
            $this->fail($e->getMessage());
        }

        $this->setDatabase();

        $this->container->setShared(
            'modelsMetadata',
            function () {
                $serializer = new SerializerFactory();
                $factory    = new AdapterFactory($serializer);

                return new Libmemcached(
                    $factory,
                    getOptionsLibmemcached()
                );
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
    public function testMvcModelMetadataLibmemcachedConstruct(): void
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
}
