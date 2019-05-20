<?php
declare(strict_types=1);

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Integration\Db\RawValue;

use IntegrationTester;
use Phalcon\Db\RawValue;

/**
 * Class ToStringCest
 */
class ToStringCest
{
    /**
     * Tests Phalcon\Db\RawValue :: __toString()
     *
     * @author Sid Roberts <https://github.com/SidRoberts>
     * @since  2019-04-17
     */
    public function dbRawvalueToString(IntegrationTester $I)
    {
        $I->wantToTest('Db\RawValue - __toString()');

        $rawValue = new RawValue('example string');

        $I->assertEquals(
            'example string',
            (string) $rawValue
        );
    }
}
