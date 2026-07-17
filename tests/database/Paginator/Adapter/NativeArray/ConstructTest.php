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

namespace Phalcon\Tests\Database\Paginator\Adapter\NativeArray;

use ArgumentCountError;
use Phalcon\Paginator\Adapter\NativeArray;
use Phalcon\Tests\AbstractDatabaseTestCase;
use PHPUnit\Framework\Attributes\Group;

#[Group('mysql')]
#[Group('pgsql')]
#[Group('sqlite')]
final class ConstructTest extends AbstractDatabaseTestCase
{
    /**
     * Tests Phalcon\Paginator\Adapter\NativeArray :: __construct()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-03-31
     */
    public function testPaginatorAdapterNativearrayConstruct(): void
    {
        $this->expectException(ArgumentCountError::class);

        $paginator = new NativeArray();
    }
}
