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

final class GetOnUpdateTest extends AbstractDatabaseTestCase
{
    use DialectTrait;

    /**
     * Tests Phalcon\Db\Reference :: getOnUpdate()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     * @group mysql
     * @group pgsql
     * @group sqlite
     */
    public function testDbReferenceGetOnUpdate(): void
    {
        $references = $this->getReferences();

        $reference1 = $references['fk1'];
        $this->assertNull($reference1->getOnUpdate());

        $reference2 = $references['fk2'];
        $this->assertNull($reference2->getOnUpdate());

        $reference3 = $references['fk3'];
        $this->assertNull($reference3->getOnUpdate());

        $reference4 = $references['fk4'];
        $this->assertEquals('SET NULL', $reference4->getOnUpdate());

        $reference5 = $references['fk5'];
        $this->assertEquals('NO ACTION', $reference5->getOnUpdate());
    }
}
