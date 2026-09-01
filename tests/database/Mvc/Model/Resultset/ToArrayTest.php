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
final class ToArrayTest extends AbstractDatabaseTestCase
{
    use ResultsetFixtureTrait;

    public function setUp(): void
    {
        $this->setNewFactoryDefault();
        $this->setDatabase();
        $this->seedResultsetFixture();
    }

    /**
     * toArray() returns one entry per row of the resultset.
     *
     * @return array<string, array{0: string, 1: int}>
     */
    public static function getExamples(): array
    {
        return [
            'simple'  => ['simple', 3],
            'complex' => ['complex', 4],
            'empty'   => ['empty', 0],
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
    public function testMvcModelResultsetToArray(string $type, int $expected): void
    {
        $resultset = $this->getResultset($type);

        $array = $resultset->toArray();

        $this->assertIsArray($array);
        $this->assertCount($expected, $array);
    }

    /**
     * toArray() goes through materialize(), which has to account for the row
     * the constructor took off the cursor. Calling it after iteration has
     * started is the case that would otherwise lose or repeat the first row.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-07-29
     */
    #[Group('mysql')]
    #[Group('pgsql')]
    #[Group('sqlite')]
    #[DataProvider('getExamples')]
    public function testMvcModelResultsetToArrayAfterFullTraversal(
        string $type,
        int $expected
    ): void {
        $resultset = $this->getResultset($type);

        foreach ($resultset as $row) {
            $this->assertNotNull($row);
        }

        $this->assertCount($expected, $resultset->toArray());
    }

    /**
     * One row consumed is the boundary where materialize() switches from
     * prepending the row the constructor took to replaying the statement.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-07-29
     */
    #[Group('mysql')]
    #[Group('pgsql')]
    #[Group('sqlite')]
    #[DataProvider('getExamples')]
    public function testMvcModelResultsetToArrayAfterPartialTraversal(
        string $type,
        int $expected
    ): void {
        $resultset = $this->getResultset($type);

        $resultset->rewind();
        $resultset->next();

        $this->assertCount($expected, $resultset->toArray());
    }
}
