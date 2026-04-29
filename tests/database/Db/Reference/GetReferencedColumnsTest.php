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

namespace Phalcon\Tests\Database\Db\Reference;

use Phalcon\Tests\AbstractDatabaseTestCase;
use Phalcon\Tests\Database\Db\Fake\DialectTrait;

final class GetReferencedColumnsTest extends AbstractDatabaseTestCase
{
    use DialectTrait;

    /**
     * Tests Phalcon\Db\Reference :: getReferencedColumns()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     * @group mysql
     * @group pgsql
     * @group sqlite
     */
    public function testDbReferenceGetReferencedColumns(): void
    {
        $references = $this->getReferences();

        $reference1 = $references['fk1'];
        $this->assertEquals(['column2'], $reference1->getReferencedColumns());

        $reference2 = $references['fk2'];
        $this->assertEquals(['column5', 'column6'], $reference2->getReferencedColumns());

        $reference3 = $references['fk3'];
        $this->assertEquals(['column2'], $reference3->getReferencedColumns());

        $reference4 = $references['fk4'];
        $this->assertEquals(['column2'], $reference4->getReferencedColumns());

        $reference5 = $references['fk5'];
        $this->assertEquals(['column2'], $reference5->getReferencedColumns());
    }
}
