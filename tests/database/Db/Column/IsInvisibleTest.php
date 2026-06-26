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

namespace Phalcon\Tests\Database\Db\Column;

use Phalcon\Db\Column;
use Phalcon\Tests\AbstractDatabaseTestCase;
use PHPUnit\Framework\Attributes\Group;

final class IsInvisibleTest extends AbstractDatabaseTestCase
{
    /**
     * Tests Phalcon\Db\Column :: isInvisible() - explicit `false` is honored.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-05-15
     */
    #[Group('mysql')]
    #[Group('pgsql')]
    #[Group('sqlite')]
    public function testDbColumnIsInvisibleFalse(): void
    {
        $column = new Column(
            'email',
            [
                'type'      => Column::TYPE_VARCHAR,
                'size'      => 255,
                'invisible' => false,
            ]
        );

        $this->assertFalse($column->isInvisible());
    }
    /**
     * Tests Phalcon\Db\Column :: isInvisible() - defaults to false when
     * the `invisible` key is not provided.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-05-15
     */
    #[Group('mysql')]
    #[Group('pgsql')]
    #[Group('sqlite')]
    public function testDbColumnIsInvisibleFalseByDefault(): void
    {
        $column = new Column(
            'email',
            [
                'type' => Column::TYPE_VARCHAR,
                'size' => 255,
            ]
        );

        $this->assertFalse($column->isInvisible());
    }

    /**
     * Tests Phalcon\Db\Column :: isInvisible() - explicit `true` is honored.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-05-15
     */
    #[Group('mysql')]
    #[Group('pgsql')]
    #[Group('sqlite')]
    public function testDbColumnIsInvisibleTrue(): void
    {
        $column = new Column(
            'internal_id',
            [
                'type'      => Column::TYPE_INTEGER,
                'size'      => 11,
                'invisible' => true,
            ]
        );

        $this->assertTrue($column->isInvisible());
    }
}
