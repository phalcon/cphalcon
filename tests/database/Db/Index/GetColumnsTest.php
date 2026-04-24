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

use Phalcon\Tests\AbstractDatabaseTestCase;
use Phalcon\Tests\Database\Db\Fake\DialectTrait;

final class GetColumnsTest extends AbstractDatabaseTestCase
{
    use DialectTrait;

    /**
     * Tests Phalcon\Db\Index :: getColumns()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     * @group  mysql
     * @group sqlite
     */
    public function testDbIndexGetColumns(): void
    {
        $indexes = $this->getIndexes();

        $index1 = $indexes['index1'];
        $this->assertEquals(['column1'], $index1->getColumns());

        $index2 = $indexes['index2'];
        $this->assertEquals(['column1', 'column2'], $index2->getColumns());

        $index3 = $indexes['PRIMARY'];
        $this->assertEquals(['column3'], $index3->getColumns());

        $index4 = $indexes['index4'];
        $this->assertEquals(['column4'], $index4->getColumns());

        $index5 = $indexes['index5'];
        $this->assertEquals(['column7'], $index5->getColumns());
    }
}
