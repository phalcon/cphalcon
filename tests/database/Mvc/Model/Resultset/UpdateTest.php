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

namespace Phalcon\Tests\Database\Mvc\Model\Resultset;

use Phalcon\Tests\AbstractDatabaseTestCase;
use Phalcon\Tests\Support\Migrations\InvoicesMigration;
use Phalcon\Tests\Support\Models\Invoices;
use Phalcon\Tests\Support\Traits\DiTrait;

/**
 *
 * @group phql
 */
final class UpdateTest extends AbstractDatabaseTestCase
{
    use DiTrait;

    public function setUp(): void
    {
        $this->setNewFactoryDefault();
        $this->setDatabase();

        $connection = self::getConnection();
        $migration  = new InvoicesMigration($connection);
        $migration->insert(1, 1, 0, 'Test Invoice One');
        $migration->insert(2, 1, 0, 'Test Invoice Two');
    }

    public function tearDown(): void
    {
        $this->tearDownDatabase();
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     *
     * @group mysql
     * @group pgsql
     * @group sqlite
     */
    public function testMvcModelResultsetUpdate(): void
    {
        $invoices = Invoices::find(
            [
                'conditions' => 'inv_status_flag = 0',
            ]
        );

        $this->assertTrue(
            $invoices->update(['inv_status_flag' => 1])
        );
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-02
     *
     * @group mysql
     * @group pgsql
     * @group sqlite
     */
    public function testMvcModelResultsetUpdateThrowsOnInvalidData(): void
    {
        $invoices = Invoices::find(
            [
                'conditions' => 'inv_status_flag = 0',
            ]
        );

        $this->expectException(\PDOException::class);

        $invoices->update(['inv_title' => str_repeat('a', 1000)]);
    }
}
