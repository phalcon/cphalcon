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

namespace Phalcon\Tests\Database\Mvc\Model\Eager;

use Phalcon\Tests\AbstractDatabaseTestCase;
use Phalcon\Tests\Database\Mvc\Model\Resultset\ResultsetFixtureTrait;
use Phalcon\Tests\Support\Models\Customers;
use Phalcon\Tests\Support\Models\InvoicesBelongsToCustomers;
use Phalcon\Tests\Support\Traits\QueryCounterTrait;
use PHPUnit\Framework\Attributes\Group;

#[Group('phql')]
final class FindEagerToOneTest extends AbstractDatabaseTestCase
{
    use QueryCounterTrait;
    use ResultsetFixtureTrait;

    public function setUp(): void
    {
        $this->setNewFactoryDefault();
        $this->setDatabase();
        $this->seedResultsetFixture();
        $this->warmMetaData(
            [
                InvoicesBelongsToCustomers::class,
                Customers::class,
            ]
        );
    }

    /**
     * The same loop with eager loading costs exactly 2 queries and returns
     * identical data.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-07-25
     */
    #[Group('mysql')]
    #[Group('pgsql')]
    #[Group('sqlite')]
    public function testMvcModelFindEagerCostsTwo(): void
    {
        $lazy = [];
        foreach (InvoicesBelongsToCustomers::find(['order' => 'inv_id']) as $invoice) {
            $lazy[] = $invoice->getRelated('customer')->cst_name_last;
        }

        $this->attachQueryCounter($this->getService('db'));

        $eager = [];
        $found = InvoicesBelongsToCustomers::find(
            [
                'order' => 'inv_id',
                'eager' => ['customer'],
            ]
        );

        foreach ($found as $invoice) {
            $eager[] = $invoice->getRelated('customer')->cst_name_last;
        }

        $this->assertSame($lazy, $eager);
        $this->assertQueryCount(2);
    }

    /**
     * A parent set with no rows short-circuits: the relation query is never
     * issued, because WHERE IN () is not valid SQL and there is nothing to
     * stamp.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-07-25
     */
    #[Group('mysql')]
    #[Group('pgsql')]
    #[Group('sqlite')]
    public function testMvcModelFindEagerEmptyParentSet(): void
    {
        $this->attachQueryCounter($this->getService('db'));

        $found = InvoicesBelongsToCustomers::find(
            [
                'conditions' => 'inv_id < 0',
                'eager'      => ['customer'],
            ]
        );

        $this->assertSame(0, $found->count());
        $this->assertQueryCount(1);
    }

    /**
     * Property access goes through the same cache, so the ergonomic form from
     * the issue is covered too.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-07-25
     */
    #[Group('mysql')]
    #[Group('pgsql')]
    #[Group('sqlite')]
    public function testMvcModelFindEagerPropertyAccess(): void
    {
        $this->attachQueryCounter($this->getService('db'));

        $found = InvoicesBelongsToCustomers::find(
            [
                'order' => 'inv_id',
                'eager' => ['customer'],
            ]
        );

        foreach ($found as $invoice) {
            $this->assertNotNull($invoice->customer->cst_name_last);
        }

        $this->assertQueryCount(2);
    }

    /**
     * Without eager loading the fixture costs 1 + N queries: one for the
     * invoices and one per invoice for its customer, including a repeat of the
     * same customer, because each iteration hydrates a fresh instance with an
     * empty relation cache.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-07-25
     */
    #[Group('mysql')]
    #[Group('pgsql')]
    #[Group('sqlite')]
    public function testMvcModelFindLazyCostsOnePlusN(): void
    {
        $this->attachQueryCounter($this->getService('db'));

        $names = [];
        foreach (InvoicesBelongsToCustomers::find(['order' => 'inv_id']) as $invoice) {
            $names[] = $invoice->getRelated('customer')->cst_name_last;
        }

        $this->assertCount(3, $names);
        $this->assertQueryCount(4);
    }
}
