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

final class GetColumnsTest extends AbstractDatabaseTestCase
{
    use DialectTrait;

    /**
     * Tests Phalcon\Db\Reference :: getColumns()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     * @group  mysql
     * @group sqlite
     */
    public function testDbReferenceGetColumns(): void
    {
        $references = $this->getReferences();

        $reference1 = $references['fk1'];
        $this->assertEquals(['column1'], $reference1->getColumns());

        $reference2 = $references['fk2'];
        $this->assertEquals(['column3', 'column4'], $reference2->getColumns());

        $reference3 = $references['fk3'];
        $this->assertEquals(['column1'], $reference3->getColumns());

        $reference4 = $references['fk4'];
        $this->assertEquals(['column1'], $reference4->getColumns());

        $reference5 = $references['fk5'];
        $this->assertEquals(['column1'], $reference5->getColumns());
    }
}
