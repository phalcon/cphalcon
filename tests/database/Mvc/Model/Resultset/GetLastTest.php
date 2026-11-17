<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Tests\Database\Mvc\Model\Resultset;

use Phalcon\Mvc\Model\Resultset;
use Phalcon\Mvc\Model\Row;
use Phalcon\Tests\AbstractDatabaseTestCase;
use Phalcon\Tests\Support\Models\Invoices;
use PHPUnit\Framework\Attributes\DataProvider;
use PHPUnit\Framework\Attributes\Group;
use stdClass;

use function get_debug_type;

#[Group('phql')]
final class GetLastTest extends AbstractDatabaseTestCase
{
    use ResultsetFixtureTrait;

    public function setUp(): void
    {
        $this->setNewFactoryDefault();
        $this->setDatabase();
        $this->seedResultsetFixture();
    }

    /**
     * @return array<string, array{0: string, 1: string|null}>
     */
    public static function getExamples(): array
    {
        return [
            'simple'  => ['simple', Invoices::class],
            'complex' => ['complex', Row::class],
            'empty'   => ['empty', null],
        ];
    }

    /**
     * The hydration mode and the type of the row.
     *
     * @return array<string, array{0: int, 1: string}>
     */
    public static function getHydrateModeExamples(): array
    {
        return [
            'arrays'  => [Resultset::HYDRATE_ARRAYS, 'array'],
            'objects' => [Resultset::HYDRATE_OBJECTS, stdClass::class],
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
    public function testMvcModelResultsetGetLast(string $type, ?string $expected): void
    {
        $resultset = $this->getResultset($type);

        $last = $resultset->getLast();

        if (null === $expected) {
            $this->assertNull($last);

            return;
        }

        $this->assertInstanceOf($expected, $last);
    }

    /**
     * With the hydration mode arrays or objects, getLast() on a simple
     * resultset gives the row as an array or a stdClass.
     *
     * @issue  https://github.com/phalcon/phalcon/issues/819
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-11-16
     */
    #[Group('mysql')]
    #[Group('pgsql')]
    #[Group('sqlite')]
    #[DataProvider('getHydrateModeExamples')]
    public function testMvcModelResultsetGetLastHydrateMode(int $mode, string $expected): void
    {
        $resultset = Invoices::find(['order' => 'inv_id']);
        $resultset->setHydrateMode($mode);

        $last = $resultset->getLast();

        $this->assertSame($expected, get_debug_type($last));
        $this->assertSame('inv-title-3', ((array) $last)['inv_title']);
    }
}
