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

namespace Phalcon\Tests\Database\Mvc\Model\Resultset\Complex;

use Phalcon\Mvc\Model\Resultset;
use Phalcon\Mvc\Model\Resultset\Complex;
use Phalcon\Mvc\Model\Row;
use Phalcon\Tests\AbstractDatabaseTestCase;
use Phalcon\Tests\Database\Mvc\Model\Resultset\ResultsetFixtureTrait;
use PHPUnit\Framework\Attributes\Group;

#[Group('phql')]
final class SerializeTest extends AbstractDatabaseTestCase
{
    use ResultsetFixtureTrait;

    public function setUp(): void
    {
        $this->setNewFactoryDefault();
        $this->setDatabase();
        $this->setDiService('phpSerializer');
        $this->seedResultsetFixture();
    }

    /**
     * Serializing a complex resultset and restoring it preserves its rows.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-06-22
     */
    #[Group('mysql')]
    #[Group('pgsql')]
    #[Group('sqlite')]
    public function testMvcModelResultsetComplexSerialize(): void
    {
        $original = $this->getResultset('complex');

        $restored = new Complex(null);
        $restored->unserialize($original->serialize());

        // A complex resultset hydrates rows of models whose internal snapshot
        // state is not part of the serialized payload, so compare the restored
        // row count rather than a deep object graph.
        $this->assertCount(4, $restored);
        $this->assertSame($original->count(), $restored->count());
    }

    /**
     * A restored resultset that was serialized under HYDRATE_ARRAYS keeps its
     * rows reachable too.
     *
     * @issue  https://github.com/phalcon/cphalcon/issues/17574
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-09-07
     */
    #[Group('mysql')]
    #[Group('pgsql')]
    #[Group('sqlite')]
    public function testMvcModelResultsetComplexSerializeRestoredHydrateArraysTraverses(): void
    {
        $original = $this->getResultset('complex');
        $original->setHydrateMode(Resultset::HYDRATE_ARRAYS);

        $restored = new Complex(null);
        $restored->unserialize($original->serialize());

        $records = $restored->toArray();

        $this->assertCount(4, $records);
        $this->assertIsArray($records[0]);
    }

    /**
     * The rows of a restored resultset are already hydrated, so the cursor has
     * to report them as valid even though they are objects and not arrays.
     *
     * @issue  https://github.com/phalcon/cphalcon/issues/17574
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-09-07
     */
    #[Group('mysql')]
    #[Group('pgsql')]
    #[Group('sqlite')]
    public function testMvcModelResultsetComplexSerializeRestoredTraverses(): void
    {
        $original = $this->getResultset('complex');

        $restored = new Complex(null);
        $restored->unserialize($original->serialize());

        $restored->rewind();

        $this->assertTrue($restored->valid());
        $this->assertInstanceOf(Row::class, $restored->getFirst());

        $records = [];
        foreach ($restored as $record) {
            $records[] = $record;
        }

        $this->assertCount(4, $records);
        $this->assertContainsOnlyInstancesOf(Row::class, $records);
        $this->assertCount(4, $restored->toArray());
    }
}
