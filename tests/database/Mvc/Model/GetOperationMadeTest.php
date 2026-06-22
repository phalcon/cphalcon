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

use Phalcon\Mvc\Model;
use Phalcon\Tests\AbstractDatabaseTestCase;
use Phalcon\Tests\Support\Migrations\InvoicesMigration;
use Phalcon\Tests\Support\Models\Invoices;
use Phalcon\Tests\Support\Traits\DiTrait;
use PHPUnit\Framework\Attributes\Group;

#[Group('mysql')]
#[Group('pgsql')]
#[Group('sqlite')]
final class GetOperationMadeTest extends AbstractDatabaseTestCase
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
    public function testMvcModelGetOperationMade(): void
    {
        $invoice = new Invoices();

        // No operation performed yet
        $this->assertSame(Model::OP_NONE, $invoice->getOperationMade());

        $invoice->assign(
            [
                'inv_id'          => 1,
                'inv_cst_id'      => 1,
                'inv_status_flag' => 1,
                'inv_title'       => 'operation test',
                'inv_total'       => 100.00,
                'inv_created_at'  => date('Y-m-d H:i:s'),
            ]
        );

        $this->assertTrue($invoice->create());

        // A create operation was performed
        $this->assertSame(Model::OP_CREATE, $invoice->getOperationMade());
    }
}
