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

namespace Phalcon\Test\Integration\Validation\Validator\StringLength\Max;

use IntegrationTester;
use Phalcon\Validation\Validator\StringLength\Max;

class GetOptionCest
{
    /**
     * Tests Phalcon\Validation\Validator\StringLength\Max :: getOption()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-05-23
     */
    public function validationValidatorStringLengthMaxGetOption(IntegrationTester $I)
    {
        $I->wantToTest('Validation\Validator\StringLength\Max - getOption()');

        $validator = new Max();

        $I->assertEquals(null, $validator->getOption('max'), 'Max option is null by default');

        $expected = 1234;
        $validator->setOption('max', $expected);
        $I->assertSame($expected, $validator->getOption('max'), 'Max option is 1234');

        $expected = '1234';
        $validator->setOption('max', $expected);
        $I->assertEquals($expected, $validator->getOption('max'), 'Max option is "1234"');
    }
}
