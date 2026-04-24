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

namespace Phalcon\Tests\Database\Db\RawValue;

use Phalcon\Db\RawValue;
use Phalcon\Tests\AbstractDatabaseTestCase;

final class ToStringTest extends AbstractDatabaseTestCase
{
    /**
     * Tests Phalcon\Db\RawValue :: __toString()
     *
     * @author Sid Roberts <https://github.com/SidRoberts>
     * @since  2019-04-17
     *
     * @group mysql
     * @group sqlite
     */
    public function testDbRawvalueToString(): void
    {
        $rawValue = new RawValue('example string');

        $this->assertEquals(
            'example string',
            (string)$rawValue
        );
    }
}
