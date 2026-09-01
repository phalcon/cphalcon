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

use Phalcon\Mvc\Model\Resultset;
use Phalcon\Tests\AbstractDatabaseTestCase;
use PHPUnit\Framework\Attributes\DataProvider;
use PHPUnit\Framework\Attributes\Group;

#[Group('phql')]
final class GetTypeTest extends AbstractDatabaseTestCase
{
    use ResultsetFixtureTrait;

    public function setUp(): void
    {
        $this->setNewFactoryDefault();
        $this->setDatabase();
        $this->seedResultsetFixture();
    }

    /**
     * A populated resultset streams rows one-by-one (PARTIAL); an empty one
     * holds its rows in memory as an array (FULL).
     *
     * @return array<string, array{0: string, 1: int}>
     */
    public static function getExamples(): array
    {
        return [
            'simple'  => ['simple', Resultset::TYPE_RESULT_PARTIAL],
            'complex' => ['complex', Resultset::TYPE_RESULT_PARTIAL],
            'empty'   => ['empty', Resultset::TYPE_RESULT_FULL],
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
    public function testMvcModelResultsetGetType(string $type, int $expected): void
    {
        $resultset = $this->getResultset($type);

        $this->assertSame($expected, $resultset->getType());
    }
}
