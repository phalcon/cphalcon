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
use Phalcon\Paginator\RepositoryInterface;
use Phalcon\Tests\AbstractDatabaseTestCase;
use PHPUnit\Framework\Attributes\Group;

#[Group('mysql')]
#[Group('pgsql')]
#[Group('sqlite')]
final class SetPropertiesTest extends AbstractDatabaseTestCase
{
    /**
     * Tests Phalcon\Paginator\Repository :: setProperties()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-06-22
     */
    public function testPaginatorRepositorySetProperties(): void
    {
        $repository = new Repository();

        $properties = [
            Repository::PROPERTY_LIMIT       => 10,
            Repository::PROPERTY_TOTAL_ITEMS => 100,
        ];

        $this->assertInstanceOf(
            RepositoryInterface::class,
            $repository->setProperties($properties)
        );

        $this->assertSame(10, $repository->getLimit());
        $this->assertSame(100, $repository->getTotalItems());
        $this->assertSame($properties, $repository->jsonSerialize());
    }
}
