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

namespace Phalcon\Tests\Database\Db\Index;

use Phalcon\Db\Exception;
use Phalcon\Db\Index;
use Phalcon\Tests\AbstractDatabaseTestCase;

final class GetDirectionsTest extends AbstractDatabaseTestCase
{
    /**
     * Legacy positional constructor leaves `getDirections()` empty.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-05-15
     *
     * @group mysql
     * @group pgsql
     * @group sqlite
     */
    public function testDbIndexLegacyHasNoDirections(): void
    {
        $index = new Index('idx_email', ['email']);

        $this->assertSame([], $index->getDirections());
    }

    /**
     * Definition-array `directions` is stored verbatim.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-05-15
     *
     * @group mysql
     * @group pgsql
     * @group sqlite
     */
    public function testDbIndexDefinitionDirectionsStored(): void
    {
        $index = new Index(
            'idx_compound',
            [
                'columns'    => ['col1', 'col2'],
                'directions' => ['DESC', 'ASC'],
            ]
        );

        $this->assertSame(['DESC', 'ASC'], $index->getDirections());
    }

    /**
     * Non-array `directions` throws.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-05-15
     *
     * @group mysql
     * @group pgsql
     * @group sqlite
     */
    public function testDbIndexDirectionsMustBeArray(): void
    {
        $this->expectException(Exception::class);
        $this->expectExceptionMessage(
            "Index definition 'directions' key must be an array"
        );

        new Index(
            'idx_bad',
            [
                'columns'    => ['col1'],
                'directions' => 'DESC',
            ]
        );
    }
}
