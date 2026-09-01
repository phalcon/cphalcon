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

namespace Phalcon\Tests\Database\Mvc\Model\Criteria;

use Phalcon\Tests\AbstractDatabaseTestCase;
use Phalcon\Tests\Database\Mvc\Model\Resultset\ResultsetFixtureTrait;
use Phalcon\Tests\Support\Models\Customers;
use Phalcon\Tests\Support\Models\InvoicesBelongsToCustomers;
use Phalcon\Tests\Support\Traits\QueryCounterTrait;
use PHPUnit\Framework\Attributes\Group;

/**
 * The criteria surface is a pass-through: execute() forwards its parameters to
 * Model::find() (Criteria.zep:284), which owns the loading. No engine code is
 * involved, so these tests only need to prove the spec survives the hand-off.
 */
#[Group('phql')]
final class EagerTest extends AbstractDatabaseTestCase
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
     * The same 1 + N -> 2 collapse applies through the criteria surface.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-07-25
     */
    #[Group('mysql')]
    #[Group('pgsql')]
    #[Group('sqlite')]
    public function testMvcModelCriteriaEager(): void
    {
        $this->attachQueryCounter($this->getService('db'));

        $found = InvoicesBelongsToCustomers::query()
            ->eager(['customer'])
            ->orderBy('inv_id')
            ->execute()
        ;

        $names = [];
        foreach ($found as $invoice) {
            $names[] = $invoice->getRelated('customer')->cst_name_last;
        }

        $this->assertSame(
            ['cst-last-1', 'cst-last-2', 'cst-last-2'],
            $names
        );
        $this->assertQueryCount(2);
    }

    /**
     * The setter records the paths in the parameters array verbatim, which is
     * what find() then reads.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-07-25
     */
    #[Group('mysql')]
    #[Group('pgsql')]
    #[Group('sqlite')]
    public function testMvcModelCriteriaEagerParams(): void
    {
        $criteria = InvoicesBelongsToCustomers::query()
            ->eager(['customer', 'customer.invoices'])
        ;

        $params = $criteria->getParams();

        $this->assertArrayHasKey('eager', $params);
        $this->assertSame(
            ['customer', 'customer.invoices'],
            $params['eager']
        );
    }

    /**
     * eager() combines with the rest of the criteria rather than replacing it.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-07-25
     */
    #[Group('mysql')]
    #[Group('pgsql')]
    #[Group('sqlite')]
    public function testMvcModelCriteriaEagerWithConditions(): void
    {
        $found = InvoicesBelongsToCustomers::query()
            ->where('inv_cst_id = 2')
            ->eager(['customer'])
            ->orderBy('inv_id')
            ->execute()
        ;

        $this->assertSame(2, $found->count());

        foreach ($found as $invoice) {
            $this->assertTrue($invoice->isRelationshipLoaded('customer'));
            $this->assertSame(
                'cst-last-2',
                $invoice->getRelated('customer')->cst_name_last
            );
        }
    }

    /**
     * Per-relation options survive the pass-through unchanged.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-07-25
     */
    #[Group('mysql')]
    #[Group('pgsql')]
    #[Group('sqlite')]
    public function testMvcModelCriteriaEagerWithOptions(): void
    {
        $this->attachQueryCounter($this->getService('db'));

        $found = InvoicesBelongsToCustomers::query()
            ->eager(['customer' => ['columns' => 'cst_id, cst_name_last']])
            ->orderBy('inv_id')
            ->execute()
        ;

        $seen = 0;
        foreach ($found as $invoice) {
            $customer = $invoice->getRelated('customer');

            if (null === $customer) {
                continue;
            }

            $this->assertSame(
                'cst-last-' . (int) $invoice->inv_cst_id,
                $customer->cst_name_last
            );

            $seen++;
        }

        $this->assertSame(3, $seen);
        $this->assertQueryCount(2);
    }
}
