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

namespace Phalcon\Tests\Database\Mvc\Model\Resultset\Simple;

use Phalcon\Mvc\Model\Eager\Loader;
use Phalcon\Tests\AbstractDatabaseTestCase;
use Phalcon\Tests\Database\Mvc\Model\Resultset\ResultsetFixtureTrait;
use Phalcon\Tests\Support\Models\Customers;
use Phalcon\Tests\Support\Models\InvoicesBelongsToCustomers;
use PHPUnit\Framework\Attributes\Group;

#[Group('phql')]
final class SetEagerMapTest extends AbstractDatabaseTestCase
{
    use ResultsetFixtureTrait;

    public function setUp(): void
    {
        $this->setNewFactoryDefault();
        $this->setDatabase();
        $this->seedResultsetFixture();
    }

    /**
     * Keys are always strings. A single field is the value cast to string,
     * which also neutralizes the PostgreSQL-int / MySQL-string mismatch.
     * Multiple fields are length-prefixed so ['a|b', 'c'] cannot collide with
     * ['a', 'b|c'].
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-07-25
     */
    #[Group('mysql')]
    #[Group('pgsql')]
    #[Group('sqlite')]
    public function testMvcModelEagerLoaderBuildKey(): void
    {
        $this->assertSame('2', Loader::buildKey([2]));
        $this->assertSame('2', Loader::buildKey(['2']));
        $this->assertNotSame(
            Loader::buildKey(['a|b', 'c']),
            Loader::buildKey(['a', 'b|c'])
        );
        $this->assertSame(
            Loader::buildKey([1, 'x']),
            Loader::buildKey(['1', 'x'])
        );
    }

    /**
     * setRelated() writes through to the same cache getRelated() reads, and
     * normalizes the alias to lower case.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-07-25
     */
    #[Group('mysql')]
    #[Group('pgsql')]
    #[Group('sqlite')]
    public function testMvcModelSetRelated(): void
    {
        $customer = Customers::findFirst('cst_id = 2');
        $invoice  = InvoicesBelongsToCustomers::findFirst('inv_id = 1');

        $this->assertFalse($invoice->isRelationshipLoaded('customer'));

        $result = $invoice->setRelated('CUSTOMER', $customer);

        $this->assertSame($invoice, $result);
        $this->assertTrue($invoice->isRelationshipLoaded('customer'));
        $this->assertSame($customer, $invoice->getRelated('customer'));
    }

    /**
     * A map placed on the resultset is applied to every record as it hydrates,
     * so getRelated() answers from the cache and issues no query. Rows whose
     * key is absent from the map fall back to the 'empty' default.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-07-25
     */
    #[Group('mysql')]
    #[Group('pgsql')]
    #[Group('sqlite')]
    public function testMvcModelResultsetSimpleSetEagerMap(): void
    {
        $customer = Customers::findFirst('cst_id = 2');
        $this->assertNotNull($customer);

        $resultset = InvoicesBelongsToCustomers::find(['order' => 'inv_id']);
        $resultset->setEagerMap(
            [
                'customer' => [
                    'fields'  => ['inv_cst_id'],
                    'records' => ['2' => $customer],
                    'empty'   => null,
                ],
            ]
        );

        $stamped   = 0;
        $defaulted = 0;

        foreach ($resultset as $invoice) {
            $this->assertTrue($invoice->isRelationshipLoaded('customer'));

            $related = $invoice->getRelated('customer');

            if (null === $related) {
                $defaulted++;

                continue;
            }

            $this->assertSame($customer, $related);
            $stamped++;
        }

        // fixture: inv 1 -> cst 1 (absent from map), inv 2 and 3 -> cst 2
        $this->assertSame(2, $stamped);
        $this->assertSame(1, $defaulted);
    }

    /**
     * With no map set, hydration is byte-for-byte the behavior it has today.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-07-25
     */
    #[Group('mysql')]
    #[Group('pgsql')]
    #[Group('sqlite')]
    public function testMvcModelResultsetSimpleSetEagerMapAbsent(): void
    {
        $resultset = InvoicesBelongsToCustomers::find(['order' => 'inv_id']);

        foreach ($resultset as $invoice) {
            $this->assertFalse($invoice->isRelationshipLoaded('customer'));
        }
    }

    /**
     * A Row parent - what a column-restricted find yields - is stamped through
     * writeAttribute() instead, and read back as a property or an offset.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-07-25
     */
    #[Group('mysql')]
    #[Group('pgsql')]
    #[Group('sqlite')]
    public function testMvcModelResultsetSimpleSetEagerMapOnRows(): void
    {
        $customer = Customers::findFirst('cst_id = 2');

        $resultset = InvoicesBelongsToCustomers::find(
            [
                'columns' => 'inv_id, inv_cst_id',
                'order'   => 'inv_id',
            ]
        );

        $resultset->setEagerMap(
            [
                'customer' => [
                    'fields'  => ['inv_cst_id'],
                    'records' => ['2' => $customer],
                    'empty'   => null,
                ],
            ]
        );

        $stamped = 0;
        foreach ($resultset as $row) {
            if (null === $row->customer) {
                continue;
            }

            $this->assertSame($customer, $row->customer);
            $this->assertSame($customer, $row['customer']);
            $stamped++;
        }

        $this->assertSame(2, $stamped);
    }
}
