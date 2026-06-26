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

namespace Phalcon\Tests\Database\Paginator\Repository;

use Phalcon\Paginator\Repository;
use Phalcon\Tests\AbstractDatabaseTestCase;
use PHPUnit\Framework\Attributes\DataProvider;
use PHPUnit\Framework\Attributes\Group;

#[Group('mysql')]
#[Group('pgsql')]
#[Group('sqlite')]
final class GettersTest extends AbstractDatabaseTestCase
{
    /**
     * Every page-state getter reads a single property, returning a documented
     * default when that property is absent.
     *
     * @return array<string, array{0: string, 1: string, 2: mixed, 3: mixed}>
     */
    public static function getExamples(): array
    {
        return [
            'getCurrent'    => ['getCurrent', Repository::PROPERTY_CURRENT_PAGE, 3, 0],
            'getFirst'      => ['getFirst', Repository::PROPERTY_FIRST_PAGE, 1, 0],
            'getItems'      => ['getItems', Repository::PROPERTY_ITEMS, ['a', 'b'], null],
            'getLast'       => ['getLast', Repository::PROPERTY_LAST_PAGE, 9, 0],
            'getLimit'      => ['getLimit', Repository::PROPERTY_LIMIT, 25, 0],
            'getNext'       => ['getNext', Repository::PROPERTY_NEXT_PAGE, 4, 0],
            'getPrevious'   => ['getPrevious', Repository::PROPERTY_PREVIOUS_PAGE, 2, 0],
            'getTotalItems' => ['getTotalItems', Repository::PROPERTY_TOTAL_ITEMS, 200, 0],
        ];
    }

    /**
     * Tests Phalcon\Paginator\Repository :: page-state getters
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-06-22
     */
    #[Group('mysql')]
    #[Group('pgsql')]
    #[Group('sqlite')]
    #[DataProvider('getExamples')]
    public function testPaginatorRepositoryGetters(
        string $getter,
        string $property,
        mixed $value,
        mixed $default
    ): void {
        $empty = new Repository();

        $this->assertSame($default, $empty->{$getter}());

        $repository = new Repository();
        $repository->setProperties([$property => $value]);

        $this->assertSame($value, $repository->{$getter}());
    }
}
