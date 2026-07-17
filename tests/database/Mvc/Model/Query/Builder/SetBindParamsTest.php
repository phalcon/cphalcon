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
final class SetBindParamsTest extends AbstractDatabaseTestCase
{
    /**
     * setBindParams() replaces the current params, or merges them when the
     * second argument is true.
     *
     * Tests Phalcon\Mvc\Model\Query\Builder :: setBindParams()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-06-22
     */
    public function testMvcModelQueryBuilderSetBindParams(): void
    {
        $builder = new Builder();

        $params = ['name' => 'Peter', 'id' => 5];
        $builder->setBindParams($params);

        $this->assertSame($params, $builder->getBindParams());

        $builder->setBindParams(['status' => 1], true);

        $this->assertSame(
            ['name' => 'Peter', 'id' => 5, 'status' => 1],
            $builder->getBindParams()
        );
    }
}
