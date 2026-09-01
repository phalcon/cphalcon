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

namespace Phalcon\Tests\Database\Mvc\Model\Row;

use Phalcon\Mvc\Model\Row;
use Phalcon\Tests\AbstractDatabaseTestCase;
use PHPUnit\Framework\Attributes\Group;

final class OffsetGetTest extends AbstractDatabaseTestCase
{
    /**
     * @author Sid Roberts <https://github.com/SidRoberts>
     * @since  2019-06-01
     */
    #[Group('mysql')]
    #[Group('pgsql')]
    #[Group('sqlite')]
    public function testMvcModelRowOffsetGet(): void
    {
        $row = new Row();

        $row->writeAttribute('inv_title', 'Sample title');

        $this->assertEquals(
            'Sample title',
            $row['inv_title']
        );
    }

    /**
     * Regression coverage for [#17041]: reading a property that exists on
     * the row but holds a null value must return null - not throw - so
     * Resultset\Complex rows with NULL columns can be accessed via the
     * ArrayAccess contract without `property_exists` guards.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-05-21
     */
    #[Group('mysql')]
    #[Group('pgsql')]
    #[Group('sqlite')]
    public function testMvcModelRowOffsetGetReturnsNullForNullValuedColumn(): void
    {
        $row = new Row();
        $row->writeAttribute('inv_discount', null);

        $this->assertNull($row['inv_discount']);
    }
}
