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

namespace Phalcon\Tests\Database\Mvc\Model;

use Phalcon\Tests\AbstractDatabaseTestCase;
use Phalcon\Tests\Support\Migrations\InvoicesMigration;
use Phalcon\Tests\Support\Models\Invoices;
use Phalcon\Tests\Support\Traits\DiTrait;
use PHPUnit\Framework\Attributes\Group;

#[Group('mysql')]
#[Group('pgsql')]
#[Group('sqlite')]
final class DumpTest extends AbstractDatabaseTestCase
{
    use DiTrait;

    public function setUp(): void
    {
        $this->setNewFactoryDefault();
        $this->setDatabase();

        $connection = self::getConnection();
        (new InvoicesMigration($connection));
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function testMvcModelDump(): void
    {
        $invoice = new Invoices();
        $invoice->assign(
            [
                'inv_id'          => 1,
                'inv_cst_id'      => 2,
                'inv_status_flag' => 1,
                'inv_title'       => 'dump test',
                'inv_total'       => 100.00,
            ]
        );

        $dump = $invoice->dump();

        $this->assertIsArray($dump);
        $this->assertArrayHasKey('inv_id', $dump);
        $this->assertEquals(1, $dump['inv_id']);
        $this->assertEquals('dump test', $dump['inv_title']);
    }
}
