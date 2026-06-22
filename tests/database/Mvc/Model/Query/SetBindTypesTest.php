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

#[Group('mysql')]
#[Group('pgsql')]
#[Group('sqlite')]
final class SetBindTypesTest extends AbstractDatabaseTestCase
{
    /**
     * setBindTypes() replaces the current types, or merges them when the
     * second argument is true.
     *
     * Tests Phalcon\Mvc\Model\Query :: setBindTypes()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-06-22
     */
    public function testMvcModelQuerySetBindTypes(): void
    {
        $query = new Query();

        $types = ['id' => 1];
        $query->setBindTypes($types);

        $this->assertSame($types, $query->getBindTypes());

        $query->setBindTypes(['status' => 2], true);

        $this->assertSame(['id' => 1, 'status' => 2], $query->getBindTypes());
    }
}
