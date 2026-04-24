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

final class GetTypeTest extends AbstractDatabaseTestCase
{
    use DialectTrait;

    /**
     * Tests Phalcon\Db\Index :: getType()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     * @group  mysql
     * @group sqlite
     */
    public function testDbIndexGetType(): void
    {
        $indexes = $this->getIndexes();

        $index4 = $indexes['index4'];
        $this->assertEquals('UNIQUE', $index4->getType());

        $index5 = $indexes['index5'];
        $this->assertEquals('FULLTEXT', $index5->getType());
    }
}
