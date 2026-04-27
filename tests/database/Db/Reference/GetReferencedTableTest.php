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

final class GetReferencedTableTest extends AbstractDatabaseTestCase
{
    use DialectTrait;

    /**
     * Tests Phalcon\Db\Reference :: getReferencedTable()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     * @group mysql
     * @group pgsql
     * @group sqlite
     */
    public function testDbReferenceGetReferencedTable(): void
    {
        $references = $this->getReferences();

        $reference1 = $references['fk1'];
        $this->assertEquals('ref_table', $reference1->getReferencedTable());

        $reference2 = $references['fk2'];
        $this->assertEquals('ref_table', $reference2->getReferencedTable());

        $reference3 = $references['fk3'];
        $this->assertEquals('ref_table', $reference3->getReferencedTable());

        $reference4 = $references['fk4'];
        $this->assertEquals('ref_table', $reference4->getReferencedTable());

        $reference5 = $references['fk5'];
        $this->assertEquals('ref_table', $reference5->getReferencedTable());
    }
}
