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

namespace Phalcon\Tests\Integration\Validation\Validator\StringLength\Min;

use IntegrationTester;
use Phalcon\Validation\Validator\StringLength\Min;

class GetOptionCest
{
    /**
     * Tests Phalcon\Validation\Validator\StringLength\Min :: getOption()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-05-23
     */
    public function validationValidatorStringLengthMinGetOption(IntegrationTester $I)
    {
        $I->wantToTest('Validation\Validator\StringLength\Min - getOption()');

        $validator = new Min();

        $I->assertEquals(null, $validator->getOption('min'), 'Min option is null by default');

        $expected = 1234;
        $validator->setOption('min', $expected);
        $I->assertSame($expected, $validator->getOption('min'), 'Min option is 1234');

        $expected = '1234';
        $validator->setOption('min', $expected);
        $I->assertEquals($expected, $validator->getOption('min'), 'Min option is "1234"');
    }
}
