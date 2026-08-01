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

use Phalcon\Mvc\Model;
use Phalcon\Mvc\Model\Resultset;
use Phalcon\Support\Settings;
use Phalcon\Tests\AbstractDatabaseTestCase;
use Phalcon\Tests\Support\Models\Invoices;
use Phalcon\Tests\Support\Traits\QueryCounterTrait;
use PHPUnit\Framework\Attributes\DataProvider;
use PHPUnit\Framework\Attributes\Group;

/**
 * `orm.resultset_prefetch_records` buffers result-sets no larger than its value
 * at construction time. It defaults to 0, so nothing else in the suite reaches
 * this branch.
 *
 * The setting is read inside the constructor, which means it has to be in place
 * before the find() that builds the result-set - setting it afterwards does
 * nothing. It is also a process-wide static, hence Settings::reset() in
 * tearDown().
 */
#[Group('phql')]
final class PrefetchTest extends AbstractDatabaseTestCase
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

    public function tearDown(): void
    {
        Settings::reset();
    }

    /**
     * The fixture holds 3 invoices, so 3 sits exactly on the inclusive boundary
     * of `count <= prefetchRecords` and 2 just below it.
     *
     * @return array<string, array{0: int, 1: int}>
     */
    public static function getExamples(): array
    {
        return [
            'disabled'   => [0, Resultset::TYPE_RESULT_PARTIAL],
            'belowCount' => [2, Resultset::TYPE_RESULT_PARTIAL],
            'onBoundary' => [3, Resultset::TYPE_RESULT_FULL],
            'aboveCount' => [10, Resultset::TYPE_RESULT_FULL],
        ];
    }

    /**
     * An empty result-set never reaches the prefetch check - the constructor
     * settles it on the first fetch - so it is FULL whatever the setting says.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-07-29
     */
    #[Group('mysql')]
    #[Group('pgsql')]
    #[Group('sqlite')]
    #[DataProvider('getExamples')]
    public function testMvcModelResultsetPrefetchIrrelevantForEmptySet(
        int $prefetch
    ): void {
        Settings::set('orm.resultset_prefetch_records', $prefetch);

        $resultset = Invoices::find(['conditions' => 'inv_id < 0']);

        $this->assertSame(0, $resultset->count());
        $this->assertSame(Resultset::TYPE_RESULT_FULL, $resultset->getType());
    }

    /**
     * Buffering does not change what comes back, only how it is held.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-07-29
     */
    #[Group('mysql')]
    #[Group('pgsql')]
    #[Group('sqlite')]
    #[DataProvider('getExamples')]
    public function testMvcModelResultsetPrefetchKeepsRowsIntact(
        int $prefetch,
        int $expectedType
    ): void {
        Settings::set('orm.resultset_prefetch_records', $prefetch);

        $resultset = Invoices::find(['order' => 'inv_id']);

        $ids = [];
        foreach ($resultset as $invoice) {
            $ids[] = (int) $invoice->inv_id;
        }

        $this->assertSame([1, 2, 3], $ids);
        $this->assertSame(3, $resultset->count());
        $this->assertSame($expectedType, $resultset->getType());
    }

    /**
     * Turning the prefetch on brings the row-count probe back on SQLite, since
     * the constructor has to know the size to decide whether to buffer. That is
     * the cost of opting in, and it is asserted rather than left implied.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-07-29
     */
    #[Group('mysql')]
    #[Group('pgsql')]
    #[Group('sqlite')]
    public function testMvcModelResultsetPrefetchOnCostsTheProbeOnSqlite(): void
    {
        Settings::set('orm.resultset_prefetch_records', 10);

        $this->attachQueryCounter($this->getService('db'));

        $resultset = Invoices::find(['order' => 'inv_id']);

        $this->assertSame(3, $resultset->count());

        $expected = 'sqlite' === self::getDatabaseDriver() ? 1 : 0;

        $this->assertSame($expected, $this->getRowCountProbeCount());
    }

    /**
     * Settings::set() silently ignores keys outside its whitelist, so a typo
     * here would quietly test the default-off behavior instead. This pins the
     * key name so that failure mode cannot happen unnoticed.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-07-29
     */
    #[Group('mysql')]
    #[Group('pgsql')]
    #[Group('sqlite')]
    public function testMvcModelResultsetPrefetchSettingIsRecognised(): void
    {
        Settings::set('orm.resultset_prefetch_records', 7);

        $this->assertSame(7, Settings::get('orm.resultset_prefetch_records'));
    }

    /**
     * Model::setup() is the documented route to the same setting; this pins the
     * option name to the key it maps onto.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-07-29
     */
    #[Group('mysql')]
    #[Group('pgsql')]
    #[Group('sqlite')]
    public function testMvcModelResultsetPrefetchViaModelSetup(): void
    {
        Model::setup(['prefetchRecords' => 10]);

        $this->assertSame(10, Settings::get('orm.resultset_prefetch_records'));

        $resultset = Invoices::find(['order' => 'inv_id']);

        $this->assertSame(Resultset::TYPE_RESULT_FULL, $resultset->getType());
        $this->assertSame(3, $resultset->count());
    }
}
