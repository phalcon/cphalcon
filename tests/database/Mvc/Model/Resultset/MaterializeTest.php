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
use Phalcon\Tests\Support\Traits\QueryCounterTrait;
use PHPUnit\Framework\Attributes\DataProvider;
use PHPUnit\Framework\Attributes\Group;

/**
 * The constructor consumes the first row to tell an empty result-set from a
 * populated one without paying for a row count. materialize() therefore has to
 * put that row back: when the cursor has not moved past it the remainder is
 * fetched and the consumed row prepended, and only once the cursor has advanced
 * is the statement replayed.
 *
 * The pointer 0 / pointer 1 boundary is where that branch flips, so it is
 * covered from both sides. Getting it wrong drops or duplicates the first row.
 */
#[Group('phql')]
final class MaterializeTest extends AbstractDatabaseTestCase
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
     * How far to advance the cursor before materialising. 0 exercises the
     * prepend path, anything above it the replay path.
     *
     * @return array<string, array{0: int}>
     */
    public static function getExamples(): array
    {
        return [
            'untouched'       => [0],
            'oneRowConsumed'  => [1],
            'twoRowsConsumed' => [2],
            'drained'         => [3],
        ];
    }

    /**
     * Materialising flips the result-set to TYPE_RESULT_FULL whatever the
     * cursor was doing beforehand.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-07-29
     */
    #[Group('mysql')]
    #[Group('pgsql')]
    #[Group('sqlite')]
    #[DataProvider('getExamples')]
    public function testMvcModelResultsetMaterializeFlipsType(int $consume): void
    {
        $resultset = Invoices::find(['order' => 'inv_id']);

        $this->assertSame(Resultset::TYPE_RESULT_PARTIAL, $resultset->getType());

        $this->consume($resultset, $consume);
        $resultset->materialize();

        $this->assertSame(Resultset::TYPE_RESULT_FULL, $resultset->getType());
    }

    /**
     * Eager loading materialises a freshly built result-set. That has to stay
     * free of a replay, or the row count probe would simply be traded for a
     * re-execution of the same statement.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-07-29
     */
    #[Group('mysql')]
    #[Group('pgsql')]
    #[Group('sqlite')]
    public function testMvcModelResultsetMaterializeFreshCostsNoExtraStatement(): void
    {
        $this->attachQueryCounter($this->getService('db'));

        $resultset = Invoices::find(['order' => 'inv_id']);
        $resultset->materialize();

        $this->assertCount(3, $resultset->toArray());
        $this->assertRawQueryCount(1);
    }

    /**
     * Calling it twice is a no-op the second time round.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-07-29
     */
    #[Group('mysql')]
    #[Group('pgsql')]
    #[Group('sqlite')]
    public function testMvcModelResultsetMaterializeIsIdempotent(): void
    {
        $resultset = Invoices::find(['order' => 'inv_id']);

        $resultset->materialize();
        $first = $resultset->toArray();

        $resultset->materialize();
        $second = $resultset->toArray();

        $this->assertSame($first, $second);
        $this->assertCount(3, $second);
    }

    /**
     * Whatever the cursor has already read, the materialised set is the whole
     * set, in order, with the first row present exactly once.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-07-29
     */
    #[Group('mysql')]
    #[Group('pgsql')]
    #[Group('sqlite')]
    #[DataProvider('getExamples')]
    public function testMvcModelResultsetMaterializeKeepsEveryRow(int $consume): void
    {
        $resultset = Invoices::find(['order' => 'inv_id']);

        $this->consume($resultset, $consume);

        $ids = array_map(
            fn (array $row): int => (int) $row['inv_id'],
            $resultset->toArray()
        );

        $this->assertSame([1, 2, 3], $ids);
    }

    /**
     * An empty result-set is already materialised by the constructor, so
     * materialize() has nothing to replay.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-07-29
     */
    #[Group('mysql')]
    #[Group('pgsql')]
    #[Group('sqlite')]
    public function testMvcModelResultsetMaterializeOnEmptySet(): void
    {
        $resultset = Invoices::find(['conditions' => 'inv_id < 0']);

        $resultset->materialize();

        $this->assertSame([], $resultset->toArray());
        $this->assertSame(0, $resultset->count());
        $this->assertSame(Resultset::TYPE_RESULT_FULL, $resultset->getType());
    }

    /**
     * Reads the given number of rows off the cursor, leaving the pointer where
     * a caller mid-iteration would have left it.
     */
    private function consume(Resultset $resultset, int $rows): void
    {
        if (0 === $rows) {
            return;
        }

        $resultset->rewind();

        for ($index = 0; $index < $rows; $index++) {
            $resultset->current();
            $resultset->next();
        }
    }
}
