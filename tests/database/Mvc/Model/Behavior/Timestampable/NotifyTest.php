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

namespace Phalcon\Tests\Database\Mvc\Model\Behavior\Timestampable;

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
    public function testMvcModelBehaviorTimestampableNotify(): void
    {
        $invoice = new InvoicesBehavior();
        $invoice->assign(
            [
                'inv_id'          => 1,
                'inv_cst_id'      => 1,
                'inv_status_flag' => Invoices::STATUS_PAID,
                'inv_title'       => 'timestampable test',
                'inv_total'       => 100.00,
            ]
        );

        // inv_created_at is intentionally not provided
        $this->assertTrue($invoice->create());

        // Timestampable::notify('beforeCreate') populated it
        $createdAt = $invoice->readAttribute('inv_created_at');

        $this->assertNotNull($createdAt);
        $this->assertMatchesRegularExpression(
            '/^\d{4}-\d{2}-\d{2} \d{2}:\d{2}:\d{2}$/',
            $createdAt
        );
    }
}
