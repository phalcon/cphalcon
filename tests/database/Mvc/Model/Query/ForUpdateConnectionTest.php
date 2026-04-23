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

namespace Phalcon\Tests\Database\Mvc\Model\Query;

use PDO;
use Phalcon\Tests\AbstractDatabaseTestCase;
use Phalcon\Tests\Support\Migrations\InvoicesMigration;
use Phalcon\Tests\Support\Models\InvoicesReadWrite;
use Phalcon\Tests\Support\Traits\DiTrait;

/**
 * @group phql
 */
final class ForUpdateConnectionTest extends AbstractDatabaseTestCase
{
    use DiTrait;

    public function setUp(): void
    {
        $this->setNewFactoryDefault();
        $this->setDatabase();

        $this->container->setShared('dbRead', $this->newDbService());
        $this->container->setShared('dbWrite', $this->newDbService());

        /** @var PDO $connection */
        $connection = self::getConnection();
        (new InvoicesMigration($connection));
    }

    /**
     * @issue  https://github.com/phalcon/cphalcon/issues/16032
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-23
     *
     * @group mysql
     */
    public function testMvcModelQueryForUpdateUsesWriteConnection(): void
    {
        InvoicesReadWrite::find(['for_update' => true]);

        $writeSql = $this->container->getShared('dbWrite')->getRealSQLStatement();

        $this->assertNotEmpty($writeSql);
        $this->assertStringContainsString('FOR UPDATE', $writeSql);
    }
}