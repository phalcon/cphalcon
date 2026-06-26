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

use Phalcon\Mvc\Model\Resultset\Complex;
use Phalcon\Mvc\Model\Resultset\Simple;
use Phalcon\Tests\AbstractDatabaseTestCase;
use PHPUnit\Framework\Attributes\DataProvider;
use PHPUnit\Framework\Attributes\Group;

#[Group('phql')]
final class ConstructTest extends AbstractDatabaseTestCase
{
    use ResultsetFixtureTrait;

    public function setUp(): void
    {
        $this->setNewFactoryDefault();
        $this->setDatabase();
        $this->seedResultsetFixture();
    }

    /**
     * Building a resultset yields the concrete type that matches the query:
     * single-model queries hydrate a Simple (even when empty), joined queries
     * a Complex.
     *
     * @return array<string, array{0: string, 1: class-string, 2: int}>
     */
    public static function getExamples(): array
    {
        return [
            'simple'  => ['simple', Simple::class, 3],
            'complex' => ['complex', Complex::class, 4],
            'empty'   => ['empty', Simple::class, 0],
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
    public function testMvcModelResultsetConstruct(
        string $type,
        string $expectedClass,
        int $expectedCount
    ): void {
        $resultset = $this->getResultset($type);

        $this->assertInstanceOf($expectedClass, $resultset);
        $this->assertCount($expectedCount, $resultset);
    }
}
