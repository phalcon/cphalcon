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

use Phalcon\Mvc\Model\Exceptions\MissingEagerKeyColumn;
use Phalcon\Mvc\Model\Row;
use Phalcon\Tests\AbstractDatabaseTestCase;
use Phalcon\Tests\Database\Mvc\Model\Resultset\ResultsetFixtureTrait;
use Phalcon\Tests\Support\Models\Customers;
use Phalcon\Tests\Support\Models\Invoices;
use Phalcon\Tests\Support\Models\InvoicesBelongsToCustomers;
use Phalcon\Tests\Support\Traits\QueryCounterTrait;
use PHPUnit\Framework\Attributes\Group;

/**
 * Restricting a relation's columns returns Row objects for that relation,
 * exactly as find(['columns' => ...]) does today.
 *
 * Query.zep:1377-1391 is what makes this a Row rather than a half-populated
 * model, and it disables snapshots for it - so there is no partially populated
 * model to corrupt.
 */
#[Group('phql')]
final class FindEagerColumnsTest extends AbstractDatabaseTestCase
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
                Invoices::class,
            ]
        );
    }

    /**
     * The same rule one level up: a column-restricted parent must select the
     * local key or the relation cannot be resolved.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-07-25
     */
    #[Group('mysql')]
    #[Group('pgsql')]
    #[Group('sqlite')]
    public function testMvcModelFindEagerRejectsMissingLocalColumn(): void
    {
        $this->expectException(MissingEagerKeyColumn::class);
        $this->expectExceptionMessage("'inv_cst_id'");

        InvoicesBelongsToCustomers::find(
            [
                'columns' => 'inv_id, inv_title',
                'eager'   => ['customer'],
            ]
        );
    }

    /**
     * Omitting the join key from the relation's columns would leave every row
     * unattributable, so it throws naming the relation and the column rather
     * than silently adding a field the caller did not ask for.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-07-25
     */
    #[Group('mysql')]
    #[Group('pgsql')]
    #[Group('sqlite')]
    public function testMvcModelFindEagerRejectsMissingReferencedColumn(): void
    {
        $this->expectException(MissingEagerKeyColumn::class);
        $this->expectExceptionMessage("'cst_id'");

        InvoicesBelongsToCustomers::find(
            [
                'eager' => ['customer' => ['columns' => 'cst_name_last']],
            ]
        );
    }

    /**
     * Columns are per-node, so one find can produce both shapes: model parents
     * with Row children.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-07-25
     */
    #[Group('mysql')]
    #[Group('pgsql')]
    #[Group('sqlite')]
    public function testMvcModelFindEagerRelationColumns(): void
    {
        $this->attachQueryCounter($this->getService('db'));

        $found = InvoicesBelongsToCustomers::find(
            [
                'order' => 'inv_id',
                'eager' => [
                    'customer' => ['columns' => 'cst_id, cst_name_last'],
                ],
            ]
        );

        $seen = 0;
        foreach ($found as $invoice) {
            $this->assertInstanceOf(
                InvoicesBelongsToCustomers::class,
                $invoice
            );

            $customer = $invoice->getRelated('customer');

            if (null === $customer) {
                continue;
            }

            $this->assertInstanceOf(Row::class, $customer);
            $this->assertSame(
                'cst-last-' . (int) $invoice->inv_cst_id,
                $customer->cst_name_last
            );

            $seen++;
        }

        $this->assertSame(3, $seen);
        $this->assertQueryCount(2);
    }

    /**
     * A column-restricted parent yields Rows, which are stamped through
     * writeAttribute() and read back as a property or an offset.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-07-25
     */
    #[Group('mysql')]
    #[Group('pgsql')]
    #[Group('sqlite')]
    public function testMvcModelFindEagerRowParents(): void
    {
        $this->attachQueryCounter($this->getService('db'));

        $found = InvoicesBelongsToCustomers::find(
            [
                'columns' => 'inv_id, inv_cst_id',
                'order'   => 'inv_id',
                'eager'   => ['customer'],
            ]
        );

        $seen = 0;
        foreach ($found as $row) {
            $this->assertInstanceOf(Row::class, $row);

            if (null === $row->customer) {
                continue;
            }

            $this->assertSame($row->customer, $row['customer']);
            $this->assertSame(
                'cst-last-' . (int) $row->inv_cst_id,
                $row->customer->cst_name_last
            );

            $seen++;
        }

        $this->assertSame(3, $seen);
        $this->assertQueryCount(2);
    }

    /**
     * A to-many relation restricted to columns yields a resultset of Rows.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-07-25
     */
    #[Group('mysql')]
    #[Group('pgsql')]
    #[Group('sqlite')]
    public function testMvcModelFindEagerToManyColumns(): void
    {
        $found = Customers::find(
            [
                'order' => 'cst_id',
                'eager' => [
                    'invoices' => ['columns' => 'inv_id, inv_cst_id'],
                ],
            ]
        );

        $counts = [];
        foreach ($found as $customer) {
            $this->assertInstanceOf(Customers::class, $customer);

            $seen = 0;
            foreach ($customer->getRelated('invoices') as $invoice) {
                $this->assertInstanceOf(Row::class, $invoice);
                $seen++;
            }

            $counts[(int) $customer->cst_id] = $seen;
        }

        $this->assertSame([1 => 1, 2 => 2, 3 => 0], $counts);
    }
}
