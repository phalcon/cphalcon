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

final class GetNameTest extends AbstractDatabaseTestCase
{
    use DialectTrait;

    /**
     * Tests Phalcon\Db\Index :: getName()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     * @group  mysql
     * @group sqlite
     */
    public function testDbIndexGetName(): void
    {
        $indexes = $this->getIndexes();

        $index1 = $indexes['index1'];
        $this->assertEquals('index1', $index1->getName());

        $index2 = $indexes['index2'];
        $this->assertEquals('index2', $index2->getName());

        $index3 = $indexes['PRIMARY'];
        $this->assertEquals('PRIMARY', $index3->getName());

        $index4 = $indexes['index4'];
        $this->assertEquals('index4', $index4->getName());

        $index5 = $indexes['index5'];
        $this->assertEquals('index5', $index5->getName());
    }
}
