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

namespace Phalcon\Tests\Database\Db\Index;

use Phalcon\Db\Index;
use Phalcon\Tests\AbstractDatabaseTestCase;
use PHPUnit\Framework\Attributes\Group;

#[Group('mysql')]
#[Group('pgsql')]
#[Group('sqlite')]
final class ConstructTest extends AbstractDatabaseTestCase
{
    /**
     * Tests Phalcon\Db\Index :: __construct()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function testDbIndexConstruct(): void
    {
        $index = new Index('column_UNIQUE', ['column'], 'UNIQUE');

        $this->assertSame('column_UNIQUE', $index->getName());
        $this->assertSame(['column'], $index->getColumns());
        $this->assertSame('UNIQUE', $index->getType());

        $index = new Index(
            'idx_hidden',
            [
                'columns'   => ['col1'],
                'type'      => '',
                'invisible' => true,
            ]
        );

        $this->assertSame('idx_hidden', $index->getName());
        $this->assertSame(['col1'], $index->getColumns());
        $this->assertSame('', $index->getType());
        $this->assertTrue($index->isInvisible());
    }
}
