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
use Phalcon\Tests\Support\Models\InvoicesBehavior;
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
    public function testMvcModelAddBehavior(): void
    {
        /**
         * InvoicesBehavior registers a Timestampable behavior via
         * addBehavior() in its initialize(). If the behavior was added, the
         * inv_created_at field is populated automatically on create().
         */
        $invoice = new InvoicesBehavior();
        $invoice->assign(
            [
                'inv_id'          => 1,
                'inv_cst_id'      => 1,
                'inv_status_flag' => 1,
                'inv_title'       => 'behavior test',
                'inv_total'       => 100.00,
            ]
        );

        $result = $invoice->create();

        $this->assertTrue($result);
        $this->assertNotNull($invoice->readAttribute('inv_created_at'));
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function testMvcModelAddBehaviorMethod(): void
    {
        $this->assertContains(
            'addBehavior',
            get_class_methods(Model::class)
        );
    }
}
