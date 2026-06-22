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

namespace Phalcon\Tests\Database\Mvc\Model\Behavior\SoftDelete;

use Phalcon\Tests\AbstractDatabaseTestCase;
use Phalcon\Tests\Support\Migrations\InvoicesMigration;
use Phalcon\Tests\Support\Models\Invoices;
use Phalcon\Tests\Support\Models\InvoicesBehavior;
use Phalcon\Tests\Support\Traits\DiTrait;
use PHPUnit\Framework\Attributes\Group;

#[Group('mysql')]
#[Group('pgsql')]
#[Group('sqlite')]
final class NotifyTest extends AbstractDatabaseTestCase
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
    public function testMvcModelBehaviorSoftdeleteNotify(): void
    {
        $invoice = new InvoicesBehavior();
        $invoice->assign(
            [
                'inv_id'          => 1,
                'inv_cst_id'      => 1,
                'inv_status_flag' => Invoices::STATUS_PAID,
                'inv_title'       => 'soft delete test',
                'inv_total'       => 100.00,
            ]
        );

        $this->assertTrue($invoice->create());

        // A "delete" is intercepted by SoftDelete and turned into an update
        $this->assertTrue($invoice->delete());

        // The record is still present in the database
        $found = InvoicesBehavior::findFirst('inv_id = 1');
        $this->assertNotNull($found);

        // ...but flagged as inactive instead of removed
        $this->assertEquals(
            Invoices::STATUS_INACTIVE,
            $found->readAttribute('inv_status_flag')
        );
    }
}
