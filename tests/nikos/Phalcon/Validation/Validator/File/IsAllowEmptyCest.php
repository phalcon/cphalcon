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

namespace Phalcon\Test\Unit\Validation\Validator\File;

use UnitTester;

/**
 * Class IsAllowEmptyCest
 */
class IsAllowEmptyCest
{
    /**
     * Tests Phalcon\Validation\Validator\File :: isAllowEmpty()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-02-10
     */
    public function validationValidatorFileIsAllowEmpty(UnitTester $I)
    {
        $I->wantToTest('Validation\Validator\File - isAllowEmpty()');
        $I->skipTest('Need implementation');
    }
}
