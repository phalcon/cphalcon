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

namespace Phalcon\Tests\Database\Mvc\Model\Resultset;

use Phalcon\Tests\AbstractDatabaseTestCase;
use Phalcon\Tests\Support\Models\Invoices;
use Phalcon\Tests\Support\Traits\QueryCounterTrait;
use PHPUnit\Framework\Attributes\Group;

/**
 * Guards the fix for #17399.
 *
 * `PdoResult::numRows()` cannot get a row count out of PDO on SQLite, so it
 * re-runs the query wrapped in a COUNT. `Resultset` used to ask for that count
 * in its constructor, which made every single find() on SQLite cost two
 * statements. The count is now worked out lazily, so a plain traversal never
 * asks for it.
 *
 * These assertions count the probe rather than filtering it out, which is what
 * the rest of the suite does - here the probe *is* the subject.
 */
#[Group('phql')]
final class StatementCountTest extends AbstractDatabaseTestCase
{
    use QueryCounterTrait;
    use ResultsetFixtureTrait;

    public function setUp(): void
    {
        $this->setNewFactoryDefault();
        $this->setDatabase();
        $this->seedResultsetFixture();
        $this->warmMetaData([Invoices::class]);
    }

    /**
     * Asking for the count is what costs the extra statement, and only on
     * SQLite. This is the deliberate remaining cost of the trade, pinned so it
     * stays visible.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-07-29
     */
    #[Group('mysql')]
    #[Group('pgsql')]
    #[Group('sqlite')]
    public function testMvcModelResultsetCountCostsTheProbeOnSqliteOnly(): void
    {
        $this->attachQueryCounter($this->getService('db'));

        $resultset = Invoices::find(['order' => 'inv_id']);

        $this->assertSame(3, $resultset->count());

        $expected = 'sqlite' === self::getDatabaseDriver() ? 1 : 0;

        $this->assertSame($expected, $this->getRowCountProbeCount());
    }

    /**
     * Positioning at the first row answers "is there one?" without needing the
     * whole count, so getFirst() costs a single statement everywhere.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-07-29
     */
    #[Group('mysql')]
    #[Group('pgsql')]
    #[Group('sqlite')]
    public function testMvcModelResultsetGetFirstCostsOneStatement(): void
    {
        $this->attachQueryCounter($this->getService('db'));

        $invoice = Invoices::find(['order' => 'inv_id'])->getFirst();

        $this->assertSame(1, (int) $invoice->inv_id);
        $this->assertRawQueryCount(1);
    }

    /**
     * The whole point of #17399: find() plus a foreach is one statement, and
     * the number is now the same on every driver.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-07-29
     */
    #[Group('mysql')]
    #[Group('pgsql')]
    #[Group('sqlite')]
    public function testMvcModelResultsetTraversalCostsOneStatement(): void
    {
        $this->attachQueryCounter($this->getService('db'));

        $ids = [];
        foreach (Invoices::find(['order' => 'inv_id']) as $invoice) {
            $ids[] = (int) $invoice->inv_id;
        }

        $this->assertSame([1, 2, 3], $ids);
        $this->assertRawQueryCount(1);
        $this->assertSame(0, $this->getRowCountProbeCount());
    }

    /**
     * An empty result-set is settled by the first fetch coming back false, so
     * it costs no more than a populated one.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-07-29
     */
    #[Group('mysql')]
    #[Group('pgsql')]
    #[Group('sqlite')]
    public function testMvcModelResultsetTraversalOfEmptySetCostsOneStatement(): void
    {
        $this->attachQueryCounter($this->getService('db'));

        $rows = [];
        foreach (Invoices::find(['conditions' => 'inv_id < 0']) as $invoice) {
            $rows[] = $invoice->inv_id;
        }

        $this->assertSame([], $rows);
        $this->assertRawQueryCount(1);
    }
}
