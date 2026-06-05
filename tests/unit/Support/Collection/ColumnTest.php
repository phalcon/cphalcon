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

namespace Phalcon\Tests\Unit\Support\Collection;

use Phalcon\Support\Collection;
use stdClass;

final class ColumnTest extends AbstractCollectionTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-05-12
     */
    public function testSupportCollectionColumnExtractsFromArrays(): void
    {
        $collection = new Collection([
            'a' => ['name' => 'Alice', 'age' => 30],
            'b' => ['name' => 'Bob',   'age' => 25],
        ]);

        $this->assertSame(
            ['a' => 'Alice', 'b' => 'Bob'],
            $collection->column('name')
        );
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-05-12
     */
    public function testSupportCollectionColumnExtractsFromObjectProperty(): void
    {
        $row1       = new stdClass();
        $row1->name = 'Alice';
        $row2       = new stdClass();
        $row2->name = 'Bob';

        $collection = new Collection(['a' => $row1, 'b' => $row2]);

        $this->assertSame(
            ['a' => 'Alice', 'b' => 'Bob'],
            $collection->column('name')
        );
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-05-12
     */
    public function testSupportCollectionColumnExtractsFromObjectMethod(): void
    {
        $obj = new class {
            public function name(): string
            {
                return 'X';
            }
        };

        $collection = new Collection(['a' => $obj]);

        $this->assertSame(['a' => 'X'], $collection->column('name'));
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-05-12
     */
    public function testSupportCollectionColumnReturnsNullWhenMissing(): void
    {
        $collection = new Collection(['a' => ['x' => 1]]);

        $this->assertSame(['a' => null], $collection->column('missing'));
    }
}
