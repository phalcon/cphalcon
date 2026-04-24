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

final class GetNameTest extends AbstractDatabaseTestCase
{
    use DialectTrait;

    /**
     * Tests Phalcon\Db\Reference :: getName()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     * @group  mysql
     * @group sqlite
     */
    public function testDbReferenceGetName(): void
    {
        $references = $this->getReferences();

        $reference1 = $references['fk1'];
        $this->assertEquals('fk1', $reference1->getName());

        $reference2 = $references['fk2'];
        $this->assertEquals('fk2', $reference2->getName());

        $reference3 = $references['fk3'];
        $this->assertEquals('fk3', $reference3->getName());

        $reference4 = $references['fk4'];
        $this->assertEquals('fk4', $reference4->getName());

        $reference5 = $references['fk5'];
        $this->assertEquals('fk5', $reference5->getName());
    }
}
