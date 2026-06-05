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

final class IsInvisibleTest extends AbstractDatabaseTestCase
{
    /**
     * Legacy positional constructor - `isInvisible()` defaults to false.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-05-15
     *
     * @group mysql
     * @group pgsql
     * @group sqlite
     */
    public function testDbIndexLegacyPositionalIsVisible(): void
    {
        $index = new Index('idx_email', ['email'], 'UNIQUE');

        $this->assertSame('idx_email', $index->getName());
        $this->assertSame(['email'], $index->getColumns());
        $this->assertSame('UNIQUE', $index->getType());
        $this->assertFalse($index->isInvisible());
    }

    /**
     * Definition-array constructor with `invisible => true`.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-05-15
     *
     * @group mysql
     * @group pgsql
     * @group sqlite
     */
    public function testDbIndexDefinitionInvisibleTrue(): void
    {
        $index = new Index(
            'idx_hidden',
            [
                'columns'   => ['col1'],
                'type'      => 'UNIQUE',
                'invisible' => true,
            ]
        );

        $this->assertSame('idx_hidden', $index->getName());
        $this->assertSame(['col1'], $index->getColumns());
        $this->assertSame('UNIQUE', $index->getType());
        $this->assertTrue($index->isInvisible());
    }

    /**
     * Definition-array form ignores the third positional `type` argument.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-05-15
     *
     * @group mysql
     * @group pgsql
     * @group sqlite
     */
    public function testDbIndexDefinitionIgnoresPositionalType(): void
    {
        $index = new Index(
            'idx_combo',
            [
                'columns' => ['col1'],
                'type'    => 'UNIQUE',
            ],
            'FULLTEXT'
        );

        $this->assertSame('UNIQUE', $index->getType());
    }

    /**
     * Definition-array with `columns` not an array throws.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-05-15
     *
     * @group mysql
     * @group pgsql
     * @group sqlite
     */
    public function testDbIndexDefinitionColumnsMustBeArray(): void
    {
        $this->expectException(Exception::class);
        $this->expectExceptionMessage(
            "Index definition 'columns' key must be an array"
        );

        new Index(
            'idx_bad',
            [
                'columns' => 'not_an_array',
            ]
        );
    }
}
