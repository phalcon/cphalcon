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
use Phalcon\Tests\Support\Models\Invoices;
use Phalcon\Tests\Support\Models\InvoicesBelongsToCustomers;
use Phalcon\Tests\Support\Traits\QueryCounterTrait;
use PHPUnit\Framework\Attributes\Group;

#[Group('phql')]
final class FindEagerNestedTest extends AbstractDatabaseTestCase
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
     * A path implies its prefixes and prefixes dedupe, so listing the prefix
     * explicitly does not add a query.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-07-25
     */
    #[Group('mysql')]
    #[Group('pgsql')]
    #[Group('sqlite')]
    public function testMvcModelFindEagerNestedPrefixDedupe(): void
    {
        $this->attachQueryCounter($this->getService('db'));

        $found = InvoicesBelongsToCustomers::find(
            [
                'order' => 'inv_id',
                'eager' => ['customer', 'customer.invoices'],
            ]
        );

        foreach ($found as $invoice) {
            $invoice->getRelated('customer');
        }

        $this->assertQueryCount(3);
    }

    /**
     * Nesting below a to-many level works too: the children are handed out by
     * sliced resultsets, so the level-2 map is attached to each slice rather
     * than stamped on instances the caller will never see.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-07-25
     */
    #[Group('mysql')]
    #[Group('pgsql')]
    #[Group('sqlite')]
    public function testMvcModelFindEagerNestedThroughToMany(): void
    {
        $this->attachQueryCounter($this->getService('db'));

        $customers = Customers::find(
            [
                'order' => 'cst_id',
                'eager' => ['invoices.customer'],
            ]
        );

        $seen = 0;
        foreach ($customers as $customer) {
            foreach ($customer->getRelated('invoices') as $invoice) {
                $this->assertTrue($invoice->isRelationshipLoaded('customer'));
                $seen++;
            }
        }

        $this->assertSame(3, $seen);
        $this->assertQueryCount(3);
    }

    /**
     * A two-level path costs one query per node - 3 total - and the second
     * level is reachable through a to-one first level, whose children are
     * retained instances stamped directly.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-07-25
     */
    #[Group('mysql')]
    #[Group('pgsql')]
    #[Group('sqlite')]
    public function testMvcModelFindEagerNestedThroughToOne(): void
    {
        $this->attachQueryCounter($this->getService('db'));

        $found = InvoicesBelongsToCustomers::find(
            [
                'order' => 'inv_id',
                'eager' => ['customer.invoices'],
            ]
        );

        foreach ($found as $invoice) {
            $customer = $invoice->getRelated('customer');

            if (null === $customer) {
                continue;
            }

            $this->assertTrue($customer->isRelationshipLoaded('invoices'));
        }

        $this->assertQueryCount(3);
    }
}
