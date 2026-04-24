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

final class GetOnDeleteTest extends AbstractDatabaseTestCase
{
    use DialectTrait;

    /**
     * Tests Phalcon\Db\Reference :: getOnDelete()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     * @group  mysql
     * @group sqlite
     */
    public function testDbReferenceGetOnDelete(): void
    {
        $references = $this->getReferences();

        $reference1 = $references['fk1'];
        $this->assertNull($reference1->getOnDelete());

        $reference2 = $references['fk2'];
        $this->assertNull($reference2->getOnDelete());

        $reference3 = $references['fk3'];
        $this->assertEquals('CASCADE', $reference3->getOnDelete());

        $reference4 = $references['fk4'];
        $this->assertNull($reference4->getOnDelete());

        $reference5 = $references['fk5'];
        $this->assertEquals('CASCADE', $reference5->getOnDelete());
    }
}
