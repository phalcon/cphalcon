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

namespace Phalcon\Test\Integration\Validation\Validator\StringLength\Max;

use IntegrationTester;
use Phalcon\Validation\Validator\StringLength\Max;

class SetAdviceCest
{
    /**
     * Tests Phalcon\Validation\Validator\StringLength\Max :: setAdvice()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-05-23
     */
    public function validationValidatorStringLengthMaxSetAdvice(IntegrationTester $I)
    {
        $I->wantToTest('Validation\Validator\StringLength\Max - setAdvice()');

        $validator = new Max();

        $expected = 'New custom advice message';

        $actual = $validator->setAdvice($expected);

        $I->assertInstanceOf(Max::class, $actual, 'Instance of Max');

        $I->assertEquals(
            $expected,
            $validator->getAdvice(),
            'Get equals advice message'
        );
    }
}
