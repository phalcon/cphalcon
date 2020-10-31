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

namespace Phalcon\Test\Integration\Validation\Validator\StringLength;

use Phalcon\Validation\Validator\StringLength;
use IntegrationTester;

class SetTemplateCest
{
    /**
     * Tests Phalcon\Validation\Validator\StringLength :: setTemplate()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-05-23
     */
    public function validationValidatorStringLengthSetTemplate(IntegrationTester $I)
    {
        $I->wantToTest('Validation\Validator\StringLength - setTemplate()');

        $validator = new StringLength();

        $expected = 'New custom template message';

        $actual = $validator->setTemplate($expected);

        $I->assertInstanceOf(StringLength::class, $actual, 'Instance of StringLenght');

        $I->assertEquals(
            $expected,
            $validator->getTemplate(),
            'Get equals template message'
        );
    }
}
