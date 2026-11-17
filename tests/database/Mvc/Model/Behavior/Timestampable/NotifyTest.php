<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Tests\Database\Mvc\Model\Behavior\Timestampable;

use Phalcon\Mvc\Model\Behavior\Timestampable;
use Phalcon\Tests\AbstractDatabaseTestCase;
use Phalcon\Tests\Support\Migrations\InvoicesMigration;
use Phalcon\Tests\Support\Models\Invoices;
use Phalcon\Tests\Support\Models\InvoicesBehavior;
use Phalcon\Tests\Support\Traits\DiTrait;
use Phalcon\Tests\Support\Traits\ErrorHandlerTrait;
use PHPUnit\Framework\Attributes\Group;

#[Group('mysql')]
#[Group('pgsql')]
#[Group('sqlite')]
final class NotifyTest extends AbstractDatabaseTestCase
{
    use DiTrait;
    use ErrorHandlerTrait;

    public function setUp(): void
    {
        $this->setNewFactoryDefault();
        $this->setDatabase();

        $connection = self::getPdoConnection();
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

    /**
     * A null format is used: date() gives a deprecation and an empty
     * string, the same as cphalcon.
     *
     * @issue  https://github.com/phalcon/phalcon/issues/821
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-11-17
     */
    public function testMvcModelBehaviorTimestampableNotifyFormatNull(): void
    {
        $behavior = new Timestampable(
            [
                'beforeCreate' => [
                    'field'  => 'inv_created_at',
                    'format' => null,
                ],
            ]
        );
        $invoice  = new Invoices();

        [, $messages] = $this->collectErrors(
            fn () => $behavior->notify('beforeCreate', $invoice)
        );

        $this->assertSame(
            ['date(): Passing null to parameter #1 ($format) of type string is deprecated'],
            $messages
        );
        $this->assertSame('', $invoice->readAttribute('inv_created_at'));
    }
}
