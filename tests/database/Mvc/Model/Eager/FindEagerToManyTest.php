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

use Phalcon\Mvc\Model\Resultset\Simple;
use Phalcon\Tests\AbstractDatabaseTestCase;
use Phalcon\Tests\Database\Mvc\Model\Resultset\ResultsetFixtureTrait;
use Phalcon\Tests\Support\Models\Customers;
use Phalcon\Tests\Support\Models\Invoices;
use Phalcon\Tests\Support\Traits\QueryCounterTrait;
use PHPUnit\Framework\Attributes\Group;

#[Group('phql')]
final class FindEagerToManyTest extends AbstractDatabaseTestCase
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
                Customers::class,
                Invoices::class,
            ]
        );
    }

    /**
     * A hasMany relation costs 2 queries regardless of parent count, each
     * parent receives its own resultset, and a parent with no children gets an
     * empty resultset rather than null.
     *
     * Fixture: cst 1 -> 1 invoice, cst 2 -> 2 invoices, cst 3 -> none.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-07-25
     */
    #[Group('mysql')]
    #[Group('pgsql')]
    #[Group('sqlite')]
    public function testMvcModelFindEagerHasMany(): void
    {
        $this->attachQueryCounter($this->getService('db'));

        $customers = Customers::find(
            [
                'order' => 'cst_id',
                'eager' => ['invoices'],
            ]
        );

        $counts = [];
        foreach ($customers as $customer) {
            $related = $customer->getRelated('invoices');

            $this->assertInstanceOf(Simple::class, $related);

            $counts[$customer->cst_id] = $related->count();
        }

        $this->assertSame([1 => 1, 2 => 2, 3 => 0], $counts);
        $this->assertQueryCount(2);
    }

    /**
     * Each parent's slice contains only its own children, and a slice is
     * independently iterable more than once.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-07-25
     */
    #[Group('mysql')]
    #[Group('pgsql')]
    #[Group('sqlite')]
    public function testMvcModelFindEagerHasManySliceContents(): void
    {
        $customers = Customers::find(
            [
                'conditions' => 'cst_id = 2',
                'eager'      => ['invoices'],
            ]
        );

        $customer = $customers->getFirst();
        $related  = $customer->getRelated('invoices');

        $first = [];
        foreach ($related as $invoice) {
            $this->assertSame(2, (int) $invoice->inv_cst_id);
            $first[] = $invoice->inv_id;
        }

        $second = [];
        foreach ($related as $invoice) {
            $second[] = $invoice->inv_id;
        }

        $this->assertCount(2, $first);
        $this->assertSame($first, $second);
    }

    /**
     * Eager and lazy return the same data for the same relation.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-07-25
     */
    #[Group('mysql')]
    #[Group('pgsql')]
    #[Group('sqlite')]
    public function testMvcModelFindEagerHasManyParity(): void
    {
        $lazy = [];
        foreach (Customers::find(['order' => 'cst_id']) as $customer) {
            $lazy[$customer->cst_id] = $customer
                ->getRelated('invoices')
                ->toArray()
            ;
        }

        $eager = [];
        $found = Customers::find(
            [
                'order' => 'cst_id',
                'eager' => ['invoices'],
            ]
        );

        foreach ($found as $customer) {
            $eager[$customer->cst_id] = $customer
                ->getRelated('invoices')
                ->toArray()
            ;
        }

        $this->assertSame($lazy, $eager);
    }
}
