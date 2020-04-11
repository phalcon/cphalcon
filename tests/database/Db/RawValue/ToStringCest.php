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

namespace Phalcon\Test\Database\Db\RawValue;

use DatabaseTester;
use Phalcon\Db\RawValue;

class ToStringCest
{
    /**
     * Tests Phalcon\Db\RawValue :: __toString()
     *
     * @author Sid Roberts <https://github.com/SidRoberts>
     * @since  2019-04-17
     *
     * @group  common
     */
    public function dbRawvalueToString(DatabaseTester $I)
    {
        $I->wantToTest('Db\RawValue - __toString()');

        $rawValue = new RawValue('example string');

        $I->assertEquals(
            'example string',
            (string) $rawValue
        );
    }
}
