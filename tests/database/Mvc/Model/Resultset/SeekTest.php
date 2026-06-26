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
final class SeekTest extends AbstractDatabaseTestCase
{
    use ResultsetFixtureTrait;

    public function setUp(): void
    {
        $this->setNewFactoryDefault();
        $this->setDatabase();
        $this->seedResultsetFixture();
    }

    /**
     * seek() moves the cursor to a given position; seeking inside an empty
     * resultset leaves it invalid, so key() is null.
     *
     * @return array<string, array{0: string, 1: int, 2: int|null}>
     */
    public static function getExamples(): array
    {
        return [
            'simple'  => ['simple', 1, 1],
            'complex' => ['complex', 2, 2],
            'empty'   => ['empty', 0, null],
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
    public function testMvcModelResultsetSeek(
        string $type,
        int $position,
        ?int $expectedKey
    ): void {
        $resultset = $this->getResultset($type);

        $resultset->seek($position);

        $this->assertSame($expectedKey, $resultset->key());
    }
}
