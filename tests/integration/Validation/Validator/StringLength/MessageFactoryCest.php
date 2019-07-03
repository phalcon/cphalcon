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

use UnitTester;

class MessageFactoryCest
{
    /**
     * Tests Phalcon\Validation\Validator\StringLength :: messageFactory()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-05-23
     */
    public function validationValidatorStringLengthMessageFactory(UnitTester $I)
    {
        $I->wantToTest('Validation\Validator\StringLength - messageFactory()');

        $I->skipTest('Need implementation');
    }
}
