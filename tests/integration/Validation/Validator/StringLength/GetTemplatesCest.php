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

namespace Phalcon\Test\Unit\Validation\Validator\StringLength;

use Phalcon\Validation\Validator\StringLength;
use UnitTester;

class GetTemplatesCest
{
    /**
     * Tests Phalcon\Validation\Validator\StringLength :: getTemplates()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-05-23
     */
    public function validationValidatorStringLengthGetTemplates(UnitTester $I)
    {
        $I->wantToTest('Validation\Validator\StringLength - getTemplates()');

        $validator = new StringLength();

        $I->assertTrue(
            is_array($validator->getTemplates()),
            'Templates have to be a array'
        );

        $I->assertCount(
            0,
            $validator->getTemplates(),
            'Empty templates'
        );
    }
}
