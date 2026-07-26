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

use Phalcon\Mvc\Model\Exceptions\InvalidEagerParameter;
use Phalcon\Mvc\Model\Exceptions\InvalidEagerPath;
use Phalcon\Mvc\Model\Exceptions\UnknownEagerRelation;
use Phalcon\Mvc\Model\Exceptions\UnsupportedEagerHydration;
use Phalcon\Mvc\Model\Exceptions\UnsupportedEagerOption;
use Phalcon\Mvc\Model\Resultset;
use Phalcon\Tests\AbstractDatabaseTestCase;
use Phalcon\Tests\Database\Mvc\Model\Resultset\ResultsetFixtureTrait;
use Phalcon\Tests\Support\Models\Customers;
use Phalcon\Tests\Support\Models\InvoicesBelongsToCustomers;
use PHPUnit\Framework\Attributes\Group;

/**
 * Every way of getting this wrong should name the mistake.
 *
 * Loading nothing is indistinguishable from the feature not existing, which is
 * the failure mode most likely to be reported as "eager loading doesn't work".
 */
#[Group('phql')]
final class FindEagerFailuresTest extends AbstractDatabaseTestCase
{
    use ResultsetFixtureTrait;

    public function setUp(): void
    {
        $this->setNewFactoryDefault();
        $this->setDatabase();
        $this->seedResultsetFixture();
    }

    /**
     * Stamped relations do not mark the record dirty, so a later save() does
     * not write the relation back.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-07-25
     */
    #[Group('mysql')]
    #[Group('pgsql')]
    #[Group('sqlite')]
    public function testMvcModelFindEagerDoesNotDirtyTheRecord(): void
    {
        $found = InvoicesBelongsToCustomers::find(
            [
                'conditions' => 'inv_id = 2',
                'eager'      => ['customer'],
            ]
        );

        $invoice = $found->getFirst();

        $this->assertTrue($invoice->isRelationshipLoaded('customer'));

        $invoice->inv_title = 'changed';

        $this->assertTrue($invoice->save());

        $reloaded = InvoicesBelongsToCustomers::findFirst('inv_id = 2');

        $this->assertSame('changed', $reloaded->inv_title);
        $this->assertSame(2, (int) $reloaded->inv_cst_id);
    }

    /**
     * An empty eager array is a no-op, not an error.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-07-25
     */
    #[Group('mysql')]
    #[Group('pgsql')]
    #[Group('sqlite')]
    public function testMvcModelFindEagerEmptyArrayIsNoOp(): void
    {
        $found = InvoicesBelongsToCustomers::find(['eager' => []]);

        $this->assertSame(3, $found->count());

        foreach ($found as $invoice) {
            $this->assertFalse($invoice->isRelationshipLoaded('customer'));
        }
    }

    /**
     * The sibling find methods ignore unknown parameter keys, so `eager` is
     * inert there rather than throwing - and rather than silently working.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-07-25
     */
    #[Group('mysql')]
    #[Group('pgsql')]
    #[Group('sqlite')]
    public function testMvcModelFindEagerIgnoredBySiblingMethods(): void
    {
        $this->assertSame(
            3,
            InvoicesBelongsToCustomers::count(['eager' => ['customer']])
        );

        $invoice = InvoicesBelongsToCustomers::findFirst(
            [
                'conditions' => 'inv_id = 1',
                'eager'      => ['customer'],
            ]
        );

        $this->assertNotNull($invoice);
        $this->assertFalse($invoice->isRelationshipLoaded('customer'));
    }

    /**
     * Eager loading writes to a relation cache or a Row attribute, neither of
     * which exists under array hydration.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-07-25
     */
    #[Group('mysql')]
    #[Group('pgsql')]
    #[Group('sqlite')]
    public function testMvcModelFindEagerRejectsArrayHydration(): void
    {
        $this->expectException(UnsupportedEagerHydration::class);

        InvoicesBelongsToCustomers::find(
            [
                'eager'     => ['customer'],
                'hydration' => Resultset::HYDRATE_ARRAYS,
            ]
        );
    }

    /**
     * A path deeper than the cap is refused. An unbounded path is never
     * intentional, and a to-many hop following a to-one hop can fan out to an
     * entire table.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-07-25
     */
    #[Group('mysql')]
    #[Group('pgsql')]
    #[Group('sqlite')]
    public function testMvcModelFindEagerRejectsExcessiveDepth(): void
    {
        $this->expectException(InvalidEagerPath::class);

        InvoicesBelongsToCustomers::find(
            [
                'eager' => ['customer.invoices.customer.invoices.customer.invoices'],
            ]
        );
    }

    /**
     * A per-parent limit needs a window function PHQL cannot express, and
     * applying it to the batch would return N children in total rather than N
     * per parent.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-07-25
     */
    #[Group('mysql')]
    #[Group('pgsql')]
    #[Group('sqlite')]
    public function testMvcModelFindEagerRejectsLimit(): void
    {
        $this->expectException(UnsupportedEagerOption::class);
        $this->expectExceptionMessage("'limit'");

        Customers::find(['eager' => ['invoices' => ['limit' => 5]]]);
    }

    /**
     * A malformed path throws rather than resolving to nothing.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-07-25
     */
    #[Group('mysql')]
    #[Group('pgsql')]
    #[Group('sqlite')]
    public function testMvcModelFindEagerRejectsMalformedPath(): void
    {
        $this->expectException(InvalidEagerPath::class);

        InvoicesBelongsToCustomers::find(['eager' => ['customer..country']]);
    }

    /**
     * A bare string is rejected. Accepting it would mean two shapes for one
     * concept forever; array-only can be widened later, the reverse cannot.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-07-25
     */
    #[Group('mysql')]
    #[Group('pgsql')]
    #[Group('sqlite')]
    public function testMvcModelFindEagerRejectsString(): void
    {
        $this->expectException(InvalidEagerParameter::class);

        InvoicesBelongsToCustomers::find(['eager' => 'customer']);
    }

    /**
     * A misspelled alias is resolvable before any query runs, so it throws
     * naming the model and the alias rather than quietly loading nothing.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-07-25
     */
    #[Group('mysql')]
    #[Group('pgsql')]
    #[Group('sqlite')]
    public function testMvcModelFindEagerRejectsUnknownAlias(): void
    {
        $this->expectException(UnknownEagerRelation::class);
        $this->expectExceptionMessage("alias 'custmoer'");

        InvoicesBelongsToCustomers::find(['eager' => ['custmoer']]);
    }
}
