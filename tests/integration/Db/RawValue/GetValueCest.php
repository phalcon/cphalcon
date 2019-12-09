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

namespace Phalcon\Test\Integration\Db\RawValue;

use IntegrationTester;
use Phalcon\Db\RawValue;

class GetValueCest
{
    /**
     * Tests Phalcon\Db\RawValue :: getValue()
     *
     * @author Sid Roberts <https://github.com/SidRoberts>
     * @since  2019-04-17
     */
    public function dbRawvalueGetValue(IntegrationTester $I)
    {
        $I->wantToTest('Db\RawValue - getValue()');

        $rawValue = new RawValue('example string');

        $I->assertEquals(
            'example string',
            $rawValue->getValue()
        );
    }
}
