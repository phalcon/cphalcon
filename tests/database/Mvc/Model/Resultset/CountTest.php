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
final class CountTest extends AbstractDatabaseTestCase
{
    use ResultsetFixtureTrait;

    public function setUp(): void
    {
        $this->setNewFactoryDefault();
        $this->setDatabase();
        $this->seedResultsetFixture();
    }

    /**
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
    public function testMvcModelResultsetCount(string $type, int $expected): void
    {
        $resultset = $this->getResultset($type);

        $this->assertSame($expected, $resultset->count());
    }

    /**
     * The count is worked out lazily now, so it has to come out the same
     * whenever it is asked for. The constructor has already taken the first row
     * off the cursor by the time any of these run, which is exactly the state
     * the driver has to keep reporting the full total in.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-07-29
     */
    #[Group('mysql')]
    #[Group('pgsql')]
    #[Group('sqlite')]
    #[DataProvider('getExamples')]
    public function testMvcModelResultsetCountMidTraversal(
        string $type,
        int $expected
    ): void {
        $resultset = $this->getResultset($type);

        $resultset->rewind();
        $resultset->next();

        $this->assertSame($expected, $resultset->count());

        foreach ($resultset as $row) {
            $this->assertNotNull($row);
        }

        $this->assertSame($expected, $resultset->count());
    }

    /**
     * Once the rows are in memory the count comes off the array rather than the
     * driver, and must not disagree with what the driver said.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-07-29
     */
    #[Group('mysql')]
    #[Group('pgsql')]
    #[Group('sqlite')]
    #[DataProvider('getExamples')]
    public function testMvcModelResultsetCountWhenMaterialised(
        string $type,
        int $expected
    ): void {
        $resultset = $this->getResultset($type);

        $resultset->materialize();

        $this->assertSame($expected, $resultset->count());
        $this->assertCount($expected, $resultset->toArray());
    }
}
