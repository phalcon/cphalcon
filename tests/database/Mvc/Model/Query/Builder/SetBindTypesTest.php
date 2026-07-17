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

namespace Phalcon\Tests\Database\Mvc\Model\Query\Builder;

use Phalcon\Mvc\Model\Query\Builder;
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
     * Tests Phalcon\Mvc\Model\Query\Builder :: setBindTypes()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-06-22
     */
    public function testMvcModelQueryBuilderSetBindTypes(): void
    {
        $builder = new Builder();

        $types = ['name' => 2, 'id' => 1];
        $builder->setBindTypes($types);

        $this->assertSame($types, $builder->getBindTypes());

        $builder->setBindTypes(['status' => 1], true);

        $this->assertSame(
            ['name' => 2, 'id' => 1, 'status' => 1],
            $builder->getBindTypes()
        );
    }
}
