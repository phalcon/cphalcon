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

namespace Phalcon\Test\Unit\Validation\Validator\StringLength\Min;

use IntegrationTester;
use Phalcon\Validation\Validator\StringLength\Min;

class HasOptionCest
{
    /**
     * Tests Phalcon\Validation\Validator\StringLength\Min :: hasOption()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-05-23
     */
    public function validationValidatorStringLengthMinHasOption(IntegrationTester $I)
    {
        $I->wantToTest('Validation\Validator\StringLength\Min - hasOption()');

        $validator = new Min();

        $I->assertFalse($validator->hasOption('min'), 'Min option does not exists');

        $validator->setOption('min', 1234);
        $I->assertTrue($validator->hasOption('min'), 'Min option does exists');
    }
}
