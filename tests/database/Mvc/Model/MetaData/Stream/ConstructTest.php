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

namespace Phalcon\Tests\Database\Mvc\Model\MetaData\Stream;

use PDO;
use Phalcon\Mvc\Model\MetaData\Stream;
use Phalcon\Storage\Exception;
use Phalcon\Tests\AbstractDatabaseTestCase;
use Phalcon\Tests\Support\Migrations\InvoicesMigration;
use Phalcon\Tests\Support\Models\Invoices;
use Phalcon\Tests\Support\Traits\DiTrait;

use function cacheDir;

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
                return new Stream(
                    [
                        'metaDataDir' => cacheDir(),
                    ]
                );
            }
        );

        /** @var PDO $connection */
        $connection = self::getConnection();
        $migration  = new InvoicesMigration($connection);
        $migration->insert(1, 1, 0, 'Test Invoice');
    }

    /**
     * @return void
     */
    public function tearDown(): void
    {
        $this->safeDeleteFile(cacheDir('meta-phalcon_tests_support_models_invoices.php'));
        $this->safeDeleteFile(cacheDir('map-phalcon_tests_support_models_invoices.php'));

        $this->tearDownDatabase();
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     *
     * @group mysql
     */
    public function testMvcModelMetadataStreamConstruct(): void
    {
        /** @var \Phalcon\Mvc\Model\MetaDataInterface $md */
        $md = $this->container->getShared('modelsMetadata');

        $md->reset();
        $this->assertTrue($md->isEmpty());

        Invoices::findFirst();

        $this->assertTrue(
            file_exists(cacheDir('meta-phalcon_tests_support_models_invoices.php'))
        );

        $this->assertTrue(
            file_exists(cacheDir('map-phalcon_tests_support_models_invoices.php'))
        );

        $this->assertFalse($md->isEmpty());

        $md->reset();
        $this->assertTrue($md->isEmpty());
    }
}
