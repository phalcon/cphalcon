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

namespace Phalcon\Test\Unit\Validation\Validator\Url;

use UnitTester;

class HasOptionCest
{
    /**
     * Tests Phalcon\Validation\Validator\Url :: hasOption()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-05-07
     */
    public function validationValidatorUrlHasOption(UnitTester $I)
    {
        $I->wantToTest('Validation\Validator\Url - hasOption()');

        $I->skipTest('Need implementation');
    }
}
