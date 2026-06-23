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
final class NextTest extends AbstractDatabaseTestCase
{
    use ResultsetFixtureTrait;

    /**
     * From row 0, next() advances a populated resultset to row 1; an empty
     * one stays invalid, so key() is null.
     *
     * @return array<string, array{0: string, 1: int|null}>
     */
    public static function getExamples(): array
    {
        return [
            'simple'  => ['simple', 1],
            'complex' => ['complex', 1],
            'empty'   => ['empty', null],
        ];
    }

    public function setUp(): void
    {
        $this->setNewFactoryDefault();
        $this->setDatabase();
        $this->seedResultsetFixture();
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-06-22
     */
    #[Group('mysql')]
    #[Group('pgsql')]
    #[Group('sqlite')]
    #[DataProvider('getExamples')]
    public function testMvcModelResultsetNext(string $type, ?int $expected): void
    {
        $resultset = $this->getResultset($type);

        $resultset->rewind();
        $resultset->next();

        $this->assertSame($expected, $resultset->key());
    }
}
