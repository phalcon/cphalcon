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
 * Class ConstructCest
 */
class ConstructCest
{
    /**
     * Tests Phalcon\Db\RawValue :: __construct()
     *
     * @param IntegrationTester $I
     *
     * @author Sid Roberts <sid@sidroberts.co.uk>
     * @since  2019-04-17
     */
    public function dbRawvalueConstruct(IntegrationTester $I)
    {
        $I->wantToTest('Db\RawValue - __construct()');



        $rawValue = new RawValue('hello');

        $I->assertEquals(
            'hello',
            $rawValue->getValue()
        );



        $rawValue = new RawValue(null);

        $I->assertEquals(
            'NULL',
            $rawValue->getValue()
        );



        $rawValue = new RawValue(123);

        $I->assertEquals(
            '123',
            $rawValue->getValue()
        );



        $rawValue = new RawValue('');

        $I->assertEquals(
            "''",
            $rawValue->getValue()
        );
    }
}
