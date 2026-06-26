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

use Phalcon\Mvc\Model\Exceptions\IndexNotInCursor;
use Phalcon\Mvc\Model\Row;
use Phalcon\Tests\AbstractDatabaseTestCase;
use Phalcon\Tests\Support\Models\Invoices;
use PHPUnit\Framework\Attributes\DataProvider;
use PHPUnit\Framework\Attributes\Group;

#[Group('phql')]
final class OffsetGetTest extends AbstractDatabaseTestCase
{
    use ResultsetFixtureTrait;

    public function setUp(): void
    {
        $this->setNewFactoryDefault();
        $this->setDatabase();
        $this->seedResultsetFixture();
    }

    /**
     * offsetGet() returns the record at a valid position; an offset at or
     * beyond the row count throws IndexNotInCursor (so it always throws on an
     * empty resultset).
     *
     * @return array<string, array{0: string, 1: int, 2: string|null, 3: bool}>
     */
    public static function getExamples(): array
    {
        return [
            'simple'  => ['simple', 0, Invoices::class, false],
            'complex' => ['complex', 0, Row::class, false],
            'empty'   => ['empty', 0, null, true],
        ];
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-06-22
     */
    #[Group('mysql')]
    #[Group('pgsql')]
    #[Group('sqlite')]
    #[DataProvider('getExamples')]
    public function testMvcModelResultsetOffsetGet(
        string $type,
        int $index,
        ?string $expected,
        bool $throws
    ): void {
        $resultset = $this->getResultset($type);

        if ($throws) {
            $this->expectException(IndexNotInCursor::class);

            $resultset->offsetGet($index);

            return;
        }

        $this->assertInstanceOf($expected, $resultset->offsetGet($index));
    }
}
