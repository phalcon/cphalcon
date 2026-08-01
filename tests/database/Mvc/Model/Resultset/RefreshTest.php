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

use Phalcon\Mvc\Model\Resultset;
use Phalcon\Tests\AbstractDatabaseTestCase;
use Phalcon\Tests\Support\Models\Invoices;
use PHPUnit\Framework\Attributes\Group;

/**
 * refresh() replays the statement, so everything derived from the previous run
 * has to go with it - including the cursor position.
 *
 * NOTE: the cursor reset is a behavior change. refresh() used to leave the
 * pointer wherever iteration had abandoned it, which meant a result-set was not
 * traversable again after delete() or update() had run it to the end. valid()
 * is now driven by the row the cursor sits on rather than by a stored count,
 * which makes leaving a stale pointer behind incorrect rather than merely
 * untidy.
 */
#[Group('phql')]
final class RefreshTest extends AbstractDatabaseTestCase
{
    use ResultsetFixtureTrait;

    public function setUp(): void
    {
        $this->setNewFactoryDefault();
        $this->setDatabase();
        $this->seedResultsetFixture();
    }

    /**
     * delete() runs the result-set to the end and then refreshes it. The
     * refreshed set reflects the delete and starts from the top again.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-07-29
     */
    #[Group('mysql')]
    #[Group('pgsql')]
    #[Group('sqlite')]
    public function testMvcModelResultsetRefreshAfterDelete(): void
    {
        $resultset = Invoices::find(['order' => 'inv_id']);

        $this->assertTrue($resultset->delete());

        $this->assertSame(0, $resultset->count());
        $this->assertSame([], $resultset->toArray());
    }

    /**
     * A result-set that had been pulled into memory goes back to streaming, and
     * its count is worked out afresh rather than kept from the previous run.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-07-29
     */
    #[Group('mysql')]
    #[Group('pgsql')]
    #[Group('sqlite')]
    public function testMvcModelResultsetRefreshDiscardsMaterialisedRows(): void
    {
        $resultset = Invoices::find(['order' => 'inv_id']);

        $resultset->materialize();

        $this->assertSame(Resultset::TYPE_RESULT_FULL, $resultset->getType());

        $this->assertTrue($resultset->refresh());

        $this->assertSame(Resultset::TYPE_RESULT_PARTIAL, $resultset->getType());
        $this->assertSame(3, $resultset->count());
        $this->assertCount(3, $resultset->toArray());
    }

    /**
     * A refreshed result-set is traversable from the beginning again.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-07-29
     */
    #[Group('mysql')]
    #[Group('pgsql')]
    #[Group('sqlite')]
    public function testMvcModelResultsetRefreshRewindsTheCursor(): void
    {
        $resultset = Invoices::find(['order' => 'inv_id']);

        foreach ($resultset as $invoice) {
            $this->assertNotNull($invoice->inv_id);
        }

        $this->assertTrue($resultset->refresh());

        $ids = [];
        foreach ($resultset as $invoice) {
            $ids[] = (int) $invoice->inv_id;
        }

        $this->assertSame([1, 2, 3], $ids);
        $this->assertSame(3, $resultset->count());
    }

    /**
     * Refreshing a result-set whose rows have since gone settles it as empty.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-07-29
     */
    #[Group('mysql')]
    #[Group('pgsql')]
    #[Group('sqlite')]
    public function testMvcModelResultsetRefreshToEmpty(): void
    {
        $resultset = Invoices::find(['order' => 'inv_id']);

        $this->assertSame(3, $resultset->count());

        Invoices::find()->delete();

        $this->assertTrue($resultset->refresh());

        $this->assertSame(0, $resultset->count());
        $this->assertSame(Resultset::TYPE_RESULT_FULL, $resultset->getType());
        $this->assertFalse($resultset->valid());
    }
}
