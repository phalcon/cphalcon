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

use PDO;
use Phalcon\Tests\AbstractDatabaseTestCase;
use Phalcon\Tests\Support\Migrations\CustomersMigration;
use Phalcon\Tests\Support\Migrations\InvoicesMigration;
use Phalcon\Tests\Support\Models\Customers;
use Phalcon\Tests\Support\Models\InvoicesBelongsToCustomers;
use Phalcon\Tests\Support\Traits\DiTrait;
use Phalcon\Tests\Support\Traits\QueryCounterTrait;
use PHPUnit\Framework\Attributes\Group;

/**
 * Eager loading against a dataset wide enough for attribution to be provable.
 *
 * Six customers and nine invoices, with the foreign keys deliberately shuffled
 * and repeated, one customer left unreferenced, and one invoice carrying a null
 * foreign key. A narrower fixture cannot distinguish a correct implementation
 * from one that mis-attributes children, because too few keys are in play.
 */
#[Group('phql')]
final class FindEagerDatasetTest extends AbstractDatabaseTestCase
{
    use DiTrait;
    use QueryCounterTrait;

    /**
     * inv_id => inv_cst_id. Customer 6 is referenced by nothing; invoice 109
     * has no customer at all.
     */
    private const EXPECTED = [
        101 => 1,
        102 => 3,
        103 => 5,
        104 => 3,
        105 => 2,
        106 => 5,
        107 => 1,
        108 => 4,
        109 => null,
    ];

    private InvoicesMigration $invoicesMigration;

    public function setUp(): void
    {
        $this->setNewFactoryDefault();
        $this->setDatabase();

        /** @var PDO $connection */
        $connection = self::getPdoConnection();

        // the migration constructor drops and recreates its table, so it is
        // built once here and reused - constructing a second one mid-test
        // would silently wipe these rows
        $customers               = new CustomersMigration($connection);
        $this->invoicesMigration = new InvoicesMigration($connection);

        $invoices = $this->invoicesMigration;

        $customers->insert(1, 0, 'cst-first-1', 'cst-last-1');
        $customers->insert(2, 0, 'cst-first-2', 'cst-last-2');
        $customers->insert(3, 0, 'cst-first-3', 'cst-last-3');
        $customers->insert(4, 0, 'cst-first-4', 'cst-last-4');
        $customers->insert(5, 0, 'cst-first-5', 'cst-last-5');
        $customers->insert(6, 0, 'cst-first-6', 'cst-last-6');

        $invoices->insert(101, 1, 0, 'inv-title-101');
        $invoices->insert(102, 3, 0, 'inv-title-102');
        $invoices->insert(103, 5, 0, 'inv-title-103');
        $invoices->insert(104, 3, 0, 'inv-title-104');
        $invoices->insert(105, 2, 0, 'inv-title-105');
        $invoices->insert(106, 5, 0, 'inv-title-106');
        $invoices->insert(107, 1, 0, 'inv-title-107');
        $invoices->insert(108, 4, 0, 'inv-title-108');
        $invoices->insert(109, null, 0, 'inv-title-109');

        $this->warmMetaData(
            [
                InvoicesBelongsToCustomers::class,
                Customers::class,
            ]
        );
    }

    /**
     * Every invoice receives its own customer, not merely some customer.
     * Nine invoices resolve to five distinct customers plus one null, in two
     * queries.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-07-25
     */
    #[Group('mysql')]
    #[Group('pgsql')]
    #[Group('sqlite')]
    public function testMvcModelFindEagerAttributesEveryParentCorrectly(): void
    {
        $this->attachQueryCounter($this->getService('db'));

        $found = InvoicesBelongsToCustomers::find(
            [
                'order' => 'inv_id',
                'eager' => ['customer'],
            ]
        );

        $actual = [];
        foreach ($found as $invoice) {
            $customer = $invoice->getRelated('customer');

            if (null === $customer) {
                $actual[(int) $invoice->inv_id] = null;

                continue;
            }

            // the related record must match the key it was attributed by,
            // and carry that customer's own data
            $this->assertSame(
                (int) $invoice->inv_cst_id,
                (int) $customer->cst_id
            );
            $this->assertSame(
                'cst-last-' . (int) $customer->cst_id,
                $customer->cst_name_last
            );

            $actual[(int) $invoice->inv_id] = (int) $customer->cst_id;
        }

        $this->assertSame(self::EXPECTED, $actual);
        $this->assertQueryCount(2);
    }

    /**
     * An invoice whose foreign key is null resolves to null without a query.
     *
     * This is the case that motivated using array_key_exists rather than isset
     * for the `related` cache: a stored null is a real cached answer, and
     * isset() would have treated it as "never loaded" and re-queried per row.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-07-25
     */
    #[Group('mysql')]
    #[Group('pgsql')]
    #[Group('sqlite')]
    public function testMvcModelFindEagerCachesNullRelation(): void
    {
        $this->attachQueryCounter($this->getService('db'));

        $found = InvoicesBelongsToCustomers::find(
            [
                'conditions' => 'inv_id = 109',
                'eager'      => ['customer'],
            ]
        );

        $invoice = $found->getFirst();

        $this->assertTrue($invoice->isRelationshipLoaded('customer'));
        $this->assertNull($invoice->getRelated('customer'));
        $this->assertNull($invoice->getRelated('customer'));
        $this->assertNull($invoice->customer);

        // one query for the invoice; the null key set short-circuits the
        // relation query entirely, and repeat access adds nothing
        $this->assertQueryCount(1);
    }

    /**
     * Query count is flat in the number of parents: doubling the invoices
     * leaves the eager cost at two while the lazy cost tracks the row count.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-07-25
     */
    #[Group('mysql')]
    #[Group('pgsql')]
    #[Group('sqlite')]
    public function testMvcModelFindEagerIsFlatInParentCount(): void
    {
        $invoices = $this->invoicesMigration;

        $invoices->insert(201, 2, 0, 'inv-title-201');
        $invoices->insert(202, 4, 0, 'inv-title-202');
        $invoices->insert(203, 6, 0, 'inv-title-203');
        $invoices->insert(204, 1, 0, 'inv-title-204');
        $invoices->insert(205, 3, 0, 'inv-title-205');
        $invoices->insert(206, 5, 0, 'inv-title-206');
        $invoices->insert(207, 2, 0, 'inv-title-207');
        $invoices->insert(208, 6, 0, 'inv-title-208');
        $invoices->insert(209, 4, 0, 'inv-title-209');

        $this->attachQueryCounter($this->getService('db'));

        $seen  = 0;
        $found = InvoicesBelongsToCustomers::find(
            [
                'order' => 'inv_id',
                'eager' => ['customer'],
            ]
        );

        foreach ($found as $invoice) {
            $customer = $invoice->getRelated('customer');

            if (null !== $customer) {
                $this->assertSame(
                    (int) $invoice->inv_cst_id,
                    (int) $customer->cst_id
                );
            }

            $seen++;
        }

        $this->assertSame(18, $seen);
        $this->assertQueryCount(2);
    }

    /**
     * The same access pattern without eager loading costs one query for the
     * invoices plus one per invoice - including the null foreign key, which
     * still round-trips.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-07-25
     */
    #[Group('mysql')]
    #[Group('pgsql')]
    #[Group('sqlite')]
    public function testMvcModelFindLazyCostsOnePerInvoice(): void
    {
        $this->attachQueryCounter($this->getService('db'));

        $actual = [];
        foreach (InvoicesBelongsToCustomers::find(['order' => 'inv_id']) as $invoice) {
            $customer = $invoice->getRelated('customer');

            $actual[(int) $invoice->inv_id] = null === $customer
                ? null
                : (int) $customer->cst_id;
        }

        $this->assertSame(self::EXPECTED, $actual);
        $this->assertQueryCount(1 + count(self::EXPECTED));
    }
}
