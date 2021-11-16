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

namespace Phalcon\Tests\Integration\Validation\Validator\StringLength\Max;

use IntegrationTester;
use Phalcon\Validation\Validator\StringLength\Max;

class HasOptionCest
{
    /**
     * Tests Phalcon\Validation\Validator\StringLength\Max :: hasOption()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-05-23
     */
    public function validationValidatorStringLengthMaxHasOption(IntegrationTester $I)
    {
        $I->wantToTest('Validation\Validator\StringLength\Max - hasOption()');

        $validator = new Max();

        $I->assertFalse($validator->hasOption('max'), 'Max option does not exists');

        $validator->setOption('max', 1234);
        $I->assertTrue($validator->hasOption('max'), 'Max option does exists');
    }
}
