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
use PHPUnit\Framework\Attributes\Group;

#[Group('mysql')]
#[Group('pgsql')]
#[Group('sqlite')]
final class UnderscoreGetTest extends AbstractDatabaseTestCase
{
    /**
     * Tests Phalcon\Paginator\Repository :: __get()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-06-22
     */
    public function testPaginatorRepositoryUnderscoreGet(): void
    {
        $repository = new Repository();
        $repository->setProperties([Repository::PROPERTY_LIMIT => 15]);

        // The magic getter resolves to the matching getter method.
        $this->assertSame(15, $repository->limit);

        // Aliases are resolved to the real property name before the getter
        // is called.
        $repository->setAliases(['perPage' => 'limit']);

        $this->assertSame(15, $repository->perPage);

        // An undefined property triggers a notice and yields null.
        $this->assertNull(@$repository->undefined);
    }
}
