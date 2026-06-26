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

use Phalcon\Tests\AbstractDatabaseTestCase;
use PHPUnit\Framework\Attributes\DataProvider;
use PHPUnit\Framework\Attributes\Group;

#[Group('phql')]
final class OffsetExistsTest extends AbstractDatabaseTestCase
{
    use ResultsetFixtureTrait;

    public function setUp(): void
    {
        $this->setNewFactoryDefault();
        $this->setDatabase();
        $this->seedResultsetFixture();
    }

    /**
     * An offset exists while it is below the row count: simple has 3 rows,
     * complex has 4, empty has none.
     *
     * @return array<string, array{0: string, 1: int, 2: bool}>
     */
    public static function getExamples(): array
    {
        return [
            'simple-first'   => ['simple', 0, true],
            'simple-last'    => ['simple', 2, true],
            'simple-missing' => ['simple', 3, false],
            'complex-first'  => ['complex', 0, true],
            'complex-last'   => ['complex', 3, true],
            'complex-missing' => ['complex', 4, false],
            'empty-missing'  => ['empty', 0, false],
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
    public function testMvcModelResultsetOffsetExists(
        string $type,
        int $index,
        bool $expected
    ): void {
        $resultset = $this->getResultset($type);

        $this->assertSame($expected, $resultset->offsetExists($index));
    }
}
