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

namespace Phalcon\Tests\Database\Mvc\Model\Manager;

use Phalcon\Mvc\Model\Behavior\Timestampable;
use Phalcon\Tests\AbstractDatabaseTestCase;
use Phalcon\Tests\Support\Migrations\InvoicesMigration;
use Phalcon\Tests\Support\Models\Invoices;
use Phalcon\Tests\Support\Traits\DiTrait;
use PHPUnit\Framework\Attributes\Group;

#[Group('mysql')]
#[Group('pgsql')]
#[Group('sqlite')]
final class AddBehaviorTest extends AbstractDatabaseTestCase
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
    public function testMvcModelManagerAddBehavior(): void
    {
        $manager = $this->container->get('modelsManager');
        $invoice = new Invoices();

        $manager->addBehavior(
            $invoice,
            new Timestampable(
                [
                    'beforeCreate' => [
                        'field'  => 'inv_created_at',
                        'format' => 'Y-m-d H:i:s',
                    ],
                ]
            )
        );

        $invoice->assign(
            [
                'inv_id'          => 1,
                'inv_cst_id'      => 1,
                'inv_status_flag' => 1,
                'inv_title'       => 'manager behavior',
                'inv_total'       => 100.00,
            ]
        );

        $this->assertTrue($invoice->create());

        // The behavior registered through the manager populated the field
        $this->assertNotNull($invoice->readAttribute('inv_created_at'));
    }
}
