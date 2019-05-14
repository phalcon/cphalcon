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
 * Class GetValueCest
 */
class GetValueCest
{
    /**
     * Tests Phalcon\Db\RawValue :: getValue()
     *
     * @author Sid Roberts <sid@sidroberts.co.uk>
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
