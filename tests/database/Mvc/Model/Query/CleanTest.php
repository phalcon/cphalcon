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

namespace Phalcon\Tests\Database\Mvc\Model\Query;

use Phalcon\Mvc\Model\Query;
use Phalcon\Tests\AbstractDatabaseTestCase;
use PHPUnit\Framework\Attributes\Group;
use ReflectionClass;

#[Group('mysql')]
#[Group('pgsql')]
#[Group('sqlite')]
final class CleanTest extends AbstractDatabaseTestCase
{
    /**
     * clean() empties the internal PHQL cache shared across queries.
     *
     * Tests Phalcon\Mvc\Model\Query :: clean()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-06-22
     */
    public function testMvcModelQueryClean(): void
    {
        Query::clean();

        $reflection = new ReflectionClass(Query::class);
        $property   = $reflection->getProperty('internalPhqlCache');
        $property->setAccessible(true);

        $this->assertSame([], $property->getValue());
    }
}
