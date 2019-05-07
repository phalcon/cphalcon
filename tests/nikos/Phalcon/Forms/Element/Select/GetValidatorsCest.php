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

namespace Phalcon\Test\Unit\Forms\Element\Select;

use UnitTester;

class GetValidatorsCest
{
    /**
     * Tests Phalcon\Forms\Element\Select :: getValidators()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-05-07
     */
    public function formsElementSelectGetValidators(UnitTester $I)
    {
        $I->wantToTest('Forms\Element\Select - getValidators()');

        $I->skipTest('Need implementation');
    }
}
