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

use Phalcon\Mvc\Model\Resultset;
use Phalcon\Mvc\Model\Resultset\Simple;
use Phalcon\Tests\AbstractDatabaseTestCase;
use Phalcon\Tests\Database\Mvc\Model\Resultset\ResultsetFixtureTrait;
use PHPUnit\Framework\Attributes\Group;

#[Group('phql')]
final class SliceRowsTest extends AbstractDatabaseTestCase
{
    use ResultsetFixtureTrait;

    public function setUp(): void
    {
        $this->setNewFactoryDefault();
        $this->setDatabase();
        $this->seedResultsetFixture();
    }

    /**
     * materialize() is idempotent and flips a resultset to TYPE_RESULT_FULL.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-07-25
     */
    #[Group('mysql')]
    #[Group('pgsql')]
    #[Group('sqlite')]
    public function testMvcModelResultsetMaterializeIsIdempotent(): void
    {
        $source = $this->getResultset('simple');

        $source->materialize();
        $source->materialize();

        $this->assertSame(Resultset::TYPE_RESULT_FULL, $source->getType());
        $this->assertSame(3, $source->count());
        $this->assertCount(3, $source->toArray());
    }

    /**
     * A sliced resultset is a fully working Simple built over an in-memory row
     * slice: correct class, correct count, hydrates real models, and iterates
     * more than once.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-07-25
     */
    #[Group('mysql')]
    #[Group('pgsql')]
    #[Group('sqlite')]
    public function testMvcModelResultsetSimpleSliceRows(): void
    {
        $source = $this->getResultset('simple');
        $source->materialize();

        $sliced = $source->sliceRows([0, 2]);

        $this->assertInstanceOf(Simple::class, $sliced);
        $this->assertSame(2, $sliced->count());
        $this->assertSame(Resultset::TYPE_RESULT_FULL, $sliced->getType());

        $first = [];
        foreach ($sliced as $record) {
            $first[] = $record->inv_id;
        }

        $second = [];
        foreach ($sliced as $record) {
            $second[] = $record->inv_id;
        }

        $this->assertCount(2, $first);
        $this->assertSame($first, $second);
    }

    /**
     * Slicing with no indexes yields a usable empty resultset - the default a
     * to-many parent with no children receives.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-07-25
     */
    #[Group('mysql')]
    #[Group('pgsql')]
    #[Group('sqlite')]
    public function testMvcModelResultsetSimpleSliceRowsEmpty(): void
    {
        $source = $this->getResultset('simple');

        $sliced = $source->sliceRows([]);

        $this->assertSame(0, $sliced->count());
        $this->assertSame([], $sliced->toArray());
    }
}
