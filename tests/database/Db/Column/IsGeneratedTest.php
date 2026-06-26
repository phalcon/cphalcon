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

use Exception;
use Phalcon\Db\Column;
use Phalcon\Tests\AbstractDatabaseTestCase;
use PHPUnit\Framework\Attributes\Group;

final class IsGeneratedTest extends AbstractDatabaseTestCase
{
    /**
     * Tests Phalcon\Db\Column :: throws when `autoIncrement` and `generated`
     * are both provided.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-05-15
     */
    #[Group('mysql')]
    #[Group('pgsql')]
    #[Group('sqlite')]
    public function testDbColumnGeneratedCannotBeAutoIncrement(): void
    {
        $this->expectException(Exception::class);
        $this->expectExceptionMessage(
            'Generated column cannot also be auto-increment'
        );

        new Column(
            'total',
            [
                'type'          => Column::TYPE_INTEGER,
                'size'          => 11,
                'autoIncrement' => true,
                'generated'     => 'price * quantity',
            ]
        );
    }

    /**
     * Tests Phalcon\Db\Column :: throws when both `default` and `generated`
     * are provided.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-05-15
     */
    #[Group('mysql')]
    #[Group('pgsql')]
    #[Group('sqlite')]
    public function testDbColumnGeneratedCannotHaveDefault(): void
    {
        $this->expectException(Exception::class);
        $this->expectExceptionMessage(
            'Generated column cannot have a default value'
        );

        new Column(
            'total',
            [
                'type'      => Column::TYPE_INTEGER,
                'size'      => 11,
                'default'   => 0,
                'generated' => 'price * quantity',
            ]
        );
    }

    /**
     * Tests Phalcon\Db\Column :: throws when `generated` is not a string.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-05-15
     */
    #[Group('mysql')]
    #[Group('pgsql')]
    #[Group('sqlite')]
    public function testDbColumnGeneratedMustBeString(): void
    {
        $this->expectException(Exception::class);
        $this->expectExceptionMessage(
            'Column generation expression must be a string'
        );

        new Column(
            'total',
            [
                'type'      => Column::TYPE_INTEGER,
                'size'      => 11,
                'generated' => 42,
            ]
        );
    }
    /**
     * Tests Phalcon\Db\Column :: isGenerated() - defaults to false when the
     * `generated` key is not provided in the definition array.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-05-15
     */
    #[Group('mysql')]
    #[Group('pgsql')]
    #[Group('sqlite')]
    public function testDbColumnIsGeneratedFalseByDefault(): void
    {
        $column = new Column(
            'total',
            [
                'type' => Column::TYPE_INTEGER,
                'size' => 11,
            ]
        );

        $this->assertFalse($column->isGenerated());
        $this->assertNull($column->getGenerationExpression());
        $this->assertFalse($column->isGenerationStored());
    }

    /**
     * Tests Phalcon\Db\Column :: passing `generated => null` keeps the
     * column non-generated.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-05-15
     */
    #[Group('mysql')]
    #[Group('pgsql')]
    #[Group('sqlite')]
    public function testDbColumnIsGeneratedNullKeepsColumnPlain(): void
    {
        $column = new Column(
            'total',
            [
                'type'      => Column::TYPE_INTEGER,
                'size'      => 11,
                'generated' => null,
            ]
        );

        $this->assertFalse($column->isGenerated());
        $this->assertNull($column->getGenerationExpression());
    }

    /**
     * Tests Phalcon\Db\Column :: isGenerated() - `generated` set as STORED.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-05-15
     */
    #[Group('mysql')]
    #[Group('pgsql')]
    #[Group('sqlite')]
    public function testDbColumnIsGeneratedStored(): void
    {
        $column = new Column(
            'total',
            [
                'type'             => Column::TYPE_INTEGER,
                'size'             => 11,
                'generated'        => 'price * quantity',
                'generationStored' => true,
            ]
        );

        $this->assertTrue($column->isGenerated());
        $this->assertSame('price * quantity', $column->getGenerationExpression());
        $this->assertTrue($column->isGenerationStored());
    }

    /**
     * Tests Phalcon\Db\Column :: isGenerated() - `generated` set as VIRTUAL.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-05-15
     */
    #[Group('mysql')]
    #[Group('pgsql')]
    #[Group('sqlite')]
    public function testDbColumnIsGeneratedVirtual(): void
    {
        $column = new Column(
            'total',
            [
                'type'      => Column::TYPE_INTEGER,
                'size'      => 11,
                'generated' => 'price * quantity',
            ]
        );

        $this->assertTrue($column->isGenerated());
        $this->assertSame('price * quantity', $column->getGenerationExpression());
        $this->assertFalse($column->isGenerationStored());
    }
}
