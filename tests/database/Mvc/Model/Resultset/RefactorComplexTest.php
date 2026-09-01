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
use PHPUnit\Framework\Attributes\Group;

#[Group('mysql')]
#[Group('pgsql')]
#[Group('sqlite')]
final class RefactorComplexTest extends AbstractDatabaseTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-02
     */
    public function testShouldLoadResultsetFromCacheByUsingPhqlFile(): void
    {
        $this->markTestSkipped('Needs review - tocheck after migration');
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-02
     */
    public function testShouldLoadResultsetFromCacheByUsingPhqlLibmemcached(): void
    {
        $this->markTestSkipped('Needs review - tocheck after migration');
    }
}

// Original Cest file content (ComplexCest):
//
// <?php
//
// /**
//  * This file is part of the Phalcon Framework.
//  *
//  * (c) Phalcon Team <team@phalcon.io>
//  *
//  * For the full copyright and license information, please view the LICENSE.txt
//  * file that was distributed with this source code.
//
