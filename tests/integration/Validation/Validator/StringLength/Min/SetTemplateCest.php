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

namespace Phalcon\Test\Integration\Validation\Validator\StringLength\Min;

use IntegrationTester;
use Phalcon\Validation\Validator\StringLength\Min;

class SetTemplateCest
{
    /**
     * Tests Phalcon\Validation\Validator\StringLength\Min :: setTemplate()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-05-23
     */
    public function validationValidatorStringLengthMinSetTemplate(IntegrationTester $I)
    {
        $I->wantToTest('Validation\Validator\StringLength\Min - setTemplate()');

        $validator = new Min();

        $expected = 'New custom template message';

        $actual = $validator->setTemplate($expected);

        $I->assertInstanceOf(Min::class, $actual, 'Instance of Min');

        $I->assertEquals(
            $expected,
            $validator->getTemplate(),
            'Get equals template message'
        );
    }
}
