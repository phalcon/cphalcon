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
final class GetAliasesTest extends AbstractDatabaseTestCase
{
    /**
     * Tests Phalcon\Paginator\Repository :: getAliases()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-06-22
     */
    public function testPaginatorRepositoryGetAliases(): void
    {
        $repository = new Repository();

        $this->assertSame([], $repository->getAliases());

        $repository->setAliases(['perPage' => 'limit']);

        $this->assertSame(['perPage' => 'limit'], $repository->getAliases());
    }
}
